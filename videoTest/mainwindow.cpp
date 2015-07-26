#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QUrl>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    buttonRecord = new QPushButton;
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(buttonRecord);

    player = new QMediaPlayer(this);
    QGraphicsVideoItem* item = new QGraphicsVideoItem;
    player->setVideoOutput(item);
    QString fileName = "C://Users/FU/Documents/Youcam/Capture_20150726.wmv";
    player->setMedia(QUrl::fromLocalFile(fileName));
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addItem(item);

    view = new QGraphicsView(this);
    view->setScene(scene);

    player->play();

    layout->addWidget(view);
    QWidget* widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);

    connect(buttonRecord,SIGNAL(clicked(bool)),this,SLOT(record()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::record()
{
    recorder = new QMediaRecorder(player);
    QVideoEncoderSettings settings = recorder->videoSettings();
    settings.setResolution(640,480);
    settings.setFrameRate(30);
    recorder->setVideoSettings(settings);
    QString fileName = "C://Users/FU/Documents/Youcam/record.wmv";
    bool ok = recorder->setOutputLocation(QUrl::fromLocalFile(fileName));
    if (ok)
    {
        qDebug() << "sucessfully recorded." << endl;
    }else
    {
        qDebug() << "failed to record." << endl;
    }
    recorder->record();

    QUrl actualFile = recorder->outputLocation();
    qDebug() << actualFile << endl;
}
