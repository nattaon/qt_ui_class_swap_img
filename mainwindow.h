#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "webcam.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    WebCam *webcam;


private slots:
    void startButtonPressed();
    void stopButtonPressed();
    void updateVideoWidget();

};

#endif // MAINWINDOW_H
