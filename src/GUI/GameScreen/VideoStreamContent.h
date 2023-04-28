#pragma once

#include <QQuickPaintedItem>
#include <QImage>

class VideoStreamContent : public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT

public:
    VideoStreamContent(QQuickItem* parent = nullptr);
    void paint(QPainter* painter) override;

    void setSrc(std::shared_ptr<QImage> src) { m_src = src; }


public slots:
    void imageUpdated();

private:
    std::shared_ptr<QImage> m_src;

};