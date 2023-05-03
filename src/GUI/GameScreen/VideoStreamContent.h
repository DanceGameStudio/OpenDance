#pragma once

#include <QQuickPaintedItem>
#include <QImage>
#include <QSize>

class VideoStreamContent : public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT

public:
    VideoStreamContent(QQuickItem* parent = nullptr);

    void paint(QPainter* painter) override;

    void setSrc(QImage& src)
    {
        m_src = src.copy();
    }

public slots:
    void imageUpdated();

private:
    QImage m_src;

};