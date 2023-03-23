#include <QQuickPaintedItem>
#include <QPixmap>
#include <QImage>

class VideoStreamContent : public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT

public:
    VideoStreamContent(QQuickItem* parent = nullptr);
    void paint(QPainter* painter) override;

private:
    //QPixmap m_pixmap;
    QImage m_img;

};