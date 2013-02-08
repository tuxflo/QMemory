#include "memory_widget.h"
Memory_Widget::Memory_Widget(Game_Interface *game) :
    _game(game), _first_turn(this), _second_turn(this)
{
    _first_card = 0;
    _second_card = 0;
    if(!set_cards())
        //QDialog "Adding Cards failed!"
        qDebug() << "Adding Cards falied!";

    _state = &_first_turn;
    _turnable = true;
}

Memory_Widget::~Memory_Widget()
{
    delete _view;
}

void Memory_Widget::update()
{
    QString str("Actual Player ");
    str.append(_game->get_actual_player_name().c_str());
    str.append( " Scrore: ");
    str.append(QString::number(_game->get_actual_player_score()));
    emit update_StatusBar_points(str);
}

void Memory_Widget::turn(int row, int column)
{
    _game->turn(row, column);
}

bool Memory_Widget::set_cards()
{
    int rows = _game->get_rows();
    int columns = _game->get_columns();

    _cards = new MemoryCard**[rows];
    for(int r = 0; r < rows; r++)
        _cards[r] = new MemoryCard*[columns];

    for(int i = 0; i <  _game->get_rows(); i++)
    {
        for(int j = 0; j < _game->get_columns(); j++)
        {
            _cards[i][j] = new MemoryCard(i, j, _game->get_picture_path(i, j), _game->get_cover_path(), this);
            connect(_cards[i][j], SIGNAL(clicked(int,int)), this, SLOT(turn_card(int,int)));
            connect(_cards[i][j], SIGNAL(selected_change(int,int,bool)), this ,SLOT(selection_change(int,int, bool)));
            _grid.addItem(_cards[i][j], i, j);
        }
    }
    //setMinimumHeight(rows * _cards[0][0]->get_size().width() + rows*40);
    //setMinimumWidth(columns * _cards[0][0]->get_size().height() + columns*40);

    return true;
}

void Memory_Widget::view_board()
{
}

void Memory_Widget::play()
{
    update();
    _layout = new QHBoxLayout();
    _view = new QGraphicsView();
    _scene = new QGraphicsScene();
    _scene->installEventFilter(this);

    _scene->setBackgroundBrush(QBrush(Qt::darkCyan));
    _graphics_widget = new QGraphicsWidget();
    _graphics_widget->setLayout(&_grid);

    _scene->addItem(_graphics_widget);
    _view->setScene(_scene);
    _layout->addWidget(_view);
    setLayout(_layout);
    _view->grabKeyboard();
}

void Memory_Widget::game_over()
{
    qDebug() << "Game over!";
    _first_card = 0;
    _second_card = 0;

    QTimer t;
    connect(&t, SIGNAL(timeout()), this, SLOT(game_over_animation()));
    t.start(500);
    QString winner_name;
    int winner_score = 0;
    int tmp_score;
    //Ask if you want to start a new game show highscore...
    for(unsigned int i=0; i<_game->get_num_of_players(); i++)
    {
        tmp_score = _game->get_player_score(i);
        winner_name = _game->get_player_name(i).c_str();
        qDebug() << winner_name << "has " << tmp_score << " points";
        if(tmp_score > winner_score)
        {
            winner_score = tmp_score;
            winner_name = _game->get_player_name(i).c_str();
        }
    }

    qDebug() << "Player " << winner_name << " wins with " << tmp_score << " points!";


}

bool Memory_Widget::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key = static_cast<QKeyEvent *>(event);
        if(_scene->selectedItems().isEmpty())
        {
            selection_change(0, 0, true);
            return true;
        }
        QGraphicsItem *selected_item = _scene->selectedItems().first();
        MemoryCard *selected_card = qgraphicsitem_cast<MemoryCard *>(selected_item);
        switch(key->key())
        {
            case Qt::Key_Space:
            qDebug() << "Space";
            turn_card(selected_card->get_row(), selected_card->get_column());
            break;
        case Qt::Key_Left:
            if(selected_card->get_column() > 0)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row(), selected_card->get_column()-1, true);
            }

            break;
        case Qt::Key_Right:
            if(selected_card->get_column() < _game->get_columns()-1)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row(), selected_card->get_column()+1, true);
            }
            break;
        case Qt::Key_Up:
            if(selected_card->get_row() > 0)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row()-1, selected_card->get_column(), true);
            }
            break;
        case Qt::Key_Down:
            if(selected_card->get_row() < _game->get_columns()-1)
            {
            selection_change(selected_card->get_row(), selected_card->get_column(), false);
            selection_change(selected_card->get_row()+1, selected_card->get_column(), true);
            }
            break;
        }
        return true;
    }
    return false;
}

void Memory_Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resizeEvent!" << "new size = " << size();
    for(int i=0; i< _game->get_rows();i++)
    {
        for(int j=0; j< _game->get_columns(); j++)
        {
            _cards[i][j]->_size.setWidth(size().width()/6);
            _cards[i][j]->_size.setHeight(size().height()/5);
        }
    }
}

void Memory_Widget::set_players()
{
    QMap<QString, QColor> players_map;
    for(int i=0; i < _game->get_num_of_players(); i++)
    {
        ;
    }
}

void Memory_Widget::turn_card(int row, int column)
{
    if(_turnable)
    {
        _state->turn(row, column);
        _cards[row][column]->turn();
    }
}

void Memory_Widget::hover_card(QRectF rect)
{
    QPen pen(Qt::green);
    pen.setWidth(4);
    _hover = _scene->addRect(rect, pen);
}

void Memory_Widget::hover_leave()
{
    if(_hover != 0)
        _scene->removeItem(_hover);
    _hover = 0;
}

void Memory_Widget::selection_change(int row, int column, bool selected)
{
    if(!_scene->selectedItems().isEmpty())
    {
    QGraphicsItem *selected_item = _scene->selectedItems().first();
    MemoryCard *selected_card = qgraphicsitem_cast<MemoryCard *>(selected_item);
    selected_card->set_selected(false);
    }
    _cards[row][column]->set_selected(selected);
}

void Memory_Widget::game_over_animation()
{
    QGraphicsItem *selected_item = _scene->selectedItems().first();
    MemoryCard *selected_card = qgraphicsitem_cast<MemoryCard *>(selected_item);
    selected_card->set_selected(false);
    int r = qrand() % _game->get_rows();
    int c = qrand() % _game->get_columns();
    _cards[r][c]->set_selected(true);
}
