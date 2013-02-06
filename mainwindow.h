#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QDebug>
#include "memory_widget.h"
#include "./include/field_implementation.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionNew_Game_triggered();

private:
    Ui::MainWindow *ui;
    void create_new_game();
    QLabel *_points;
    Memory_Widget *qmemory;
    Game_Interface *game;

};


#endif // MAINWINDOW_H
