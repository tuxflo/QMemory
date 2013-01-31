#include "memory_widget.h"
#include <QGraphicsBlurEffect>
#include <QMap>
Memory_Widget::Memory_Widget(Game_Interface *game) :
    _game(game), _grid(this), _first_turn(this), _second_turn(this)
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

    _cards = new Doubleside_Card**[rows];
    for(int r = 0; r < rows; r++)
        _cards[r] = new Doubleside_Card*[columns];

    for(int i = 0; i <  _game->get_rows(); i++)
    {
        for(int j = 0; j < _game->get_columns(); j++)
        {
            _cards[i][j] = new Doubleside_Card(_game->get_picture_path(i, j), _game->get_cover_path(), i, j, this);
            connect(_cards[i][j], SIGNAL(card_clicked(int,int)), this, SLOT(turn_card(int,int)));
            connect(_cards[i][j], SIGNAL(hover_event(QRectF)), this, SLOT(hover_card(QRectF)));
            connect(_cards[i][j], SIGNAL(hover_leave_event()), this, SLOT(hover_leave()));
            _grid.addCard(_cards[i][j], i, j);
        }
    }
    setMinimumHeight(rows * _cards[0][0]->get_size().width() + rows*40);
    setMinimumWidth(columns * _cards[0][0]->get_size().height() + columns*40);

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

    _graphics_widget = new QGraphicsWidget();
    _graphics_widget->setLayout(&_grid);

    _scene->addItem(_graphics_widget);
    _view->setScene(_scene);
    _layout->addWidget(_view);
    setLayout(_layout);
}

void Memory_Widget::game_over()
{
    qDebug() << "Game over!";
    _first_card = 0;
    _second_card = 0;
    //Ask if you want to start a new game show highscore...
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
        _cards[row][column]->turn_card();
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
