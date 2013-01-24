#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qmemory = 0;
    game =0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    //Start new game
    create_new_game();

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::create_new_game()
{
    if(qmemory != 0)
    {
        delete qmemory;
        delete game;
    }
    game = new Field_Implementation(4, 4);
    game->add_player("tuxflo");
    game->add_player("anne");
    game->set_picture_path("./Pictures/");
    game->set_cover_path("./Pictures/cover.png");
    qmemory = new Memory_Widget(game);
    //View *view = qmemory;
    game->set_view(qmemory);
    qmemory->play();
    setCentralWidget(qmemory);
    qDebug() << "min width: " << qmemory->minimumWidth();
    resize(qmemory->minimumWidth(), qmemory->minimumHeight());

    _points = new QLabel(this);
    QDockWidget *dock = new QDockWidget(this);
    dock->setWidget(_points);
    addDockWidget(Qt::TopDockWidgetArea, dock);
    connect(qmemory, SIGNAL(update_StatusBar_points(QString)), _points, SLOT(setText(QString)));
}

void MainWindow::on_actionNew_Game_triggered()
{
    create_new_game();
}
