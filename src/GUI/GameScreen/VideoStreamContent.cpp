#include "VideoStreamContent.h"
#include <QPainter>
#include <QCamera>
#include <QCameraImageCapture>

VideoStreamContent::VideoStreamContent(QQuickItem* parent)
    : QQuickPaintedItem(parent)
{
    QCamera* camera = new QCamera();
    camera->start();
    QCameraImageCapture* imageCapture = new QCameraImageCapture(camera);

    connect(imageCapture, &QCameraImageCapture::imageCaptured, [=](int id, const QImage& preview) {
        m_img = preview;
        this->update();
    });

    imageCapture->capture();
}

void VideoStreamContent::paint(QPainter* painter)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawRect(0, 0, this->width(), this->height());

    painter->drawImage(QPoint(0, 0), m_img);
}