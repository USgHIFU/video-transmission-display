#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QGraphicsView>
#include <QMediaRecorder>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void record();

private:
    QMediaPlayer* player;
    QMediaRecorder* recorder;
    QGraphicsView* view;
    QPushButton* buttonRecord;
};

#endif // MAINWINDOW_H
