#include "VideoStreamContent.h"
#include <QPainter>
#include <QCamera>
#include <QTimer>

VideoStreamContent::VideoStreamContent(QQuickItem* parent) : QQuickPaintedItem(parent) {}

void VideoStreamContent::paint(QPainter* painter)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, this->width(), this->height());
    painter->drawImage(QRect(0, 0, this->width(), this->height()), m_src);
}

void VideoStreamContent::imageUpdated()
{
    this->update();
}