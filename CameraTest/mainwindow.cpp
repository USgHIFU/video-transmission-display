#include "mainwindow.h"
#include <QCameraInfo>
#include <QVideoEncoderSettings>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras)
    {
        if (cameraInfo.description() == "FJ Camera")
        {
            camera = new QCamera(cameraInfo);
//            ciCapture = new QCameraImageCapture(camera);
            viewfinder = new QCameraViewfinder(this);
            viewfinder->show();
            camera->setCaptureMode(QCamera::CaptureVideo);
            camera->setViewfinder(viewfinder);
            QVideoEncoderSettings videoSettings;
            videoSettings.setCodec("video/mpeg2");
            recorder = new QMediaRecorder(camera);
            recorder->setVideoSettings(videoSettings);
            recorder->setOutputLocation(QUrl::fromLocalFile("D://a.mpg"));
        }
    }
    setCentralWidget(viewfinder);
    camera->start();
    recorder->record();
}

MainWindow::~MainWindow()
{

}
