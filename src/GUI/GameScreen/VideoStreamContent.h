#include <QQuickPaintedItem>
#include <QPixmap>
#include <QImage>

class VideoStreamContent : public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT

public:
    VideoStreamContent(QQuickItem* parent = nullptr);
    void paint(QPainter* painter) override;
    void setStreamSource(QPixmap* src) {
        m_streamSource = src;
    }
        
public slots:
    void imageUpdated();

private:
    QPixmap* m_streamSource;
    //QImage m_img;

};