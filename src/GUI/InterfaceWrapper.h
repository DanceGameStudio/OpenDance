#pragma once

#include <QCamera>
#include <QTimer>
#include <QCameraImageCapture>
#include "GuiInterface.hpp"
#include "GameScreen/VideoStreamContent.h"

namespace Interface {

class InterfaceWrapper : public QObject {
    Q_OBJECT

public:
    InterfaceWrapper(GuiInterface& intf) : m_interface(intf) {
        QTimer* timer = new QTimer();
        timer->setInterval(100);
        QObject::connect(timer, &QTimer::timeout, [&]() {
            cv::Mat& mat = m_interface.get_graphics().camera_image;

            qDebug() << "Update!";
            auto src = std::make_shared<QImage>((unsigned char*)mat.data, mat.cols, mat.rows, QImage::Format_BGR888);

            cam->setSrc(src);
            vid->setSrc(src);

            emit cameraStreamUpdated();
            emit videoStreamUpdated();
        });
        timer->start();
    }

    GuiInterface& getInterface() { return m_interface; }

    Q_INVOKABLE void connectCamera(VideoStreamContent* stream)
    {
        cam = stream;
        //stream->setInterface(this);
        connect(this, &InterfaceWrapper::cameraStreamUpdated, stream, &VideoStreamContent::imageUpdated);
    }

    Q_INVOKABLE void connectVideo(VideoStreamContent* stream)
    {
        vid = stream;
        //stream->setInterface(this);
        connect(this, &InterfaceWrapper::videoStreamUpdated, stream, &VideoStreamContent::imageUpdated);
    }

signals:
    void cameraStreamUpdated();
    void videoStreamUpdated();

private:
    GuiInterface& m_interface;
    VideoStreamContent* cam;
    VideoStreamContent* vid;
};

}