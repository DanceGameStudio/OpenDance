#pragma once

#include "../Interfaces/GuiInterface.hpp"
#include "InterfaceStructs.hpp"
#include <QCamera>
#include <QTimer>
#include <QCameraImageCapture>

namespace Interface {

class InterfaceWrapper : public QObject {
    Q_OBJECT

public:
    InterfaceWrapper(GuiInterface& intf) : m_interface(intf), m_streamSource() {
        QCamera* camera = new QCamera();
        camera->start();

        m_imgCap = new QCameraImageCapture(camera);
        connect(m_imgCap, &QCameraImageCapture::imageCaptured, [&](int id, const QImage& preview) {
            m_streamSource.convertFromImage(preview);

            emit videoStreamUpdated();
            emit cameraStreamUpdated();

            QTimer::singleShot(10, [&]() { m_imgCap->capture(); });
        });
        m_imgCap->capture();
    }

    GuiInterface& getInterface() { return m_interface; }

    Q_INVOKABLE void connectCamera(VideoStreamContent* stream)
    {
        stream->setStreamSource(&m_streamSource);
        connect(this, &InterfaceWrapper::cameraStreamUpdated, stream, &VideoStreamContent::imageUpdated);
    }

    Q_INVOKABLE void connectVideo(VideoStreamContent* stream)
    {
        stream->setStreamSource(&m_streamSource);
        connect(this, &InterfaceWrapper::videoStreamUpdated, stream, &VideoStreamContent::imageUpdated);
    }

signals:
    void cameraStreamUpdated();
    void videoStreamUpdated();

private:
    GuiInterface& m_interface;
    QPixmap m_streamSource;
    QCameraImageCapture* m_imgCap;

};

}