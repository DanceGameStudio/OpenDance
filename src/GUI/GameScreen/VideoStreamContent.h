#include <QQuickPaintedItem>
#include <QPixmap>

class VideoStreamContent : public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT

public:
    VideoStreamContent(QQuickItem* parent = nullptr);
    void paint(QPainter* painter) override;

private:
    QPixmap m_pixmap;

};