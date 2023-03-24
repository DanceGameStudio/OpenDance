#include "VideoStreamContent.h"
#include <QPainter>

VideoStreamContent::VideoStreamContent(QQuickItem* parent)
    : QQuickPaintedItem(parent)
    , m_pixmap(1024, 1024)
{
    m_pixmap.fill(Qt::red);
}

void VideoStreamContent::paint(QPainter* painter)
{
    painter->drawPixmap(0, 0, m_pixmap);
}