#include "mainwindow.h"
#include "build/ui_mainwindow.h"
#include <qDebug>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webcam = new WebCam();

    connect(ui->startButton,SIGNAL(pressed()),this,SLOT(startButtonPressed()));
    connect(ui->stopButton,SIGNAL(pressed()),this,SLOT(stopButtonPressed()));

    //connect(webcam, SIGNAL(getImageFromCamera()), this, SLOT(updateVideoWidget()));
    connect(webcam, SIGNAL(getImageFromCamera(QPixmap)), ui->videoWidget, SLOT(setPixmap(QPixmap)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void WebCam::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent";

    QRectF rect = QRectF(QPoint(), size());
    QPainter painter(this);
    painter.drawPixmap(rect, pixmap, rect);


}*/


/*
* SLOT FUNCTION
*/
void MainWindow::startButtonPressed()
{
    qDebug() << "MainWindow::startButtonPressed";
	webcam->startCapture();
}
void MainWindow::stopButtonPressed()
{
    qDebug() << "MainWindow::stopButtonPressed";
	webcam->stopCapture();
}
void MainWindow::updateVideoWidget()
{
    qDebug() << "MainWindow::updateVideoWidget";




    //ui->videoWidget->setPixmap(pixmap);





    //pixmap.fill(Qt::white);
    //repaint(); // immediate repaint
}
