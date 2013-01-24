#include "mainwindow.h"
#include <QApplication>
#include "memory_widget.h"
#include "./include/field_implementation.h"

int main(int argc, char *argv[])
{
    //Set up the API
    //Game_Interface *game = new Field_Implementation(2, 2);
    //game->add_player("tuxflo");
    //game->set_picture_path("./Pictures/");
    //game->set_cover_path("./Pictures/cover.png");
    QApplication a(argc, argv);
    MainWindow w;
    //Memory_Widget *qmemory = new Memory_Widget(game);
    //View *view = qmemory;
    //game->set_view(qmemory);
    //w.setCentralWidget(qmemory);
    w.show();
    //qmemory->play();

    return a.exec();
    //delete qmemory;
}
