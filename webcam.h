#ifndef WEBCAM_H
#define WEBCAM_H
#include <QtCore>
#include <QObject>
#include <QWidget>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class WebCam : public QObject
{
    Q_OBJECT
public:
    WebCam(QObject *parent=0);
    void initCamera();
    void startCapture();
    void stopCapture();

signals:
    void getImageFromCamera(QPixmap pixmap);


private:
    bool isInitCamera;
    CvCapture* capture;
    QPixmap pixmap;
    QImage IplImage2QImage(const IplImage *iplImage);

};

#endif // WEBCAM_H
