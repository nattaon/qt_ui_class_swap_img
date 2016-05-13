#include "webcam.h"
#include <qDebug>
#include <QWidget>


WebCam::WebCam(QObject *parent) : QObject(parent)
{
    isInitCamera=false;
}

void WebCam::initCamera()
{
    capture = cvCaptureFromCAM(0);

    int width = 640;
    int height = 480;

    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, width);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, height);



    isInitCamera=true;
}
void WebCam::startCapture()
{
    qDebug() << "WebCam::startCapture";
    //if(!isInitCamera) initCamera();
    QPixmap pixmap("E:/Dropbox/animal/chowchow.jpg");


    emit getImageFromCamera(pixmap);
}
void WebCam::stopCapture()
{
    qDebug() << "WebCam::stopCapture";
    //cvReleaseCapture(&capture);


    QPixmap pixmap("E:/Dropbox/animal/snowpanda.jpg");

    emit getImageFromCamera(pixmap);
}


// Convert OpenCV's IplImage to QImage.
QImage WebCam::IplImage2QImage(const IplImage *iplImage)
{
    int height = iplImage->height;
    int width = iplImage->width;
    if(iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 3) // colour image
    {
        const uchar *qImageBuffer = (const uchar*) iplImage->imageData;
        QImage img(qImageBuffer, width, height,
        QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else if(iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 1) // gray image
    {
        const uchar *qImageBuffer = (const uchar*) iplImage->imageData;
        QImage img(qImageBuffer, width, height,
        QImage::Format_Indexed8);
        QVector<QRgb> colorTable; // set up colour table
        for (int i = 0; i < 256; i++)
            colorTable.append(qRgb(i, i, i));
        img.setColorTable(colorTable);
        return img;
    }
    else
    {
        qWarning() << "Image cannot be converted.";
        return QImage();
    }
}
