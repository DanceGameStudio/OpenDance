#include "VideoStreamContent.h"
#include <QPainter>
#include <QCamera>
#include <QTimer>

VideoStreamContent::VideoStreamContent(QQuickItem* parent) : QQuickPaintedItem(parent) {}

void VideoStreamContent::paint(QPainter* painter)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawRect(0, 0, this->width(), this->height());

    QRectF target(10.0, 20.0, 80.0, 60.0);
    QRectF source(0.0, 0.0, 70.0, 40.0);

    if (m_src) {
        painter->drawImage(QRect(0, 0, this->width(), this->height()), *m_src.get());
    }
    // painter->drawPixmap(0, 0, this->width(), this->height(), *m_streamSource);
}

void VideoStreamContent::imageUpdated()
{
    this->update();
}