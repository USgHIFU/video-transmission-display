#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QMediaRecorder>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QCamera* camera;
//    QCameraImageCapture* ciCapture;
    QCameraViewfinder* viewfinder;
    QMediaRecorder* recorder;
};

#endif // MAINWINDOW_H
