#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    player = new QMediaPlayer(this);
    QGraphicsVideoItem* item = new QGraphicsVideoItem;
    player->setVideoOutput(item);
    player->setMedia(QUrl::fromLocalFile("E:/Movie/Archive/SILVER LININGS DVDRIP EDAW2013/SILVER_LININGS_PLAYBOOK.avi"));
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addItem(item);

    view = new QGraphicsView(this);
    view->setScene(scene);

    player->play();




    setCentralWidget(view);

}

MainWindow::~MainWindow()
{

}
