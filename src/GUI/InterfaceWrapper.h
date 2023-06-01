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
    InterfaceWrapper(std::shared_ptr<Interface::GuiInterface> intf)
        : m_interface(intf)
    {
        QTimer* timer = new QTimer();
        timer->setInterval(33);
        QObject::connect(timer, &QTimer::timeout, [&]() {
            cv::Mat mat = m_interface->get_graphics()->camera_image;
            QImage img(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_BGR888);
            cam->setSrc(img);
            emit cameraStreamUpdated();
            
            mat = m_interface->get_graphics()->video_image;
            img = QImage(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_BGR888);
            vid->setSrc(img);
            emit videoStreamUpdated();
        });
        timer->start();
    }

    std::shared_ptr<Interface::GuiInterface> getInterface() { return m_interface; }

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

    Q_INVOKABLE int get_score() { return m_interface->get_score(); }
    
    Q_INVOKABLE void set_game_status(int status) {
        m_interface->set_game_status((GameStatus)status);
    };
    Q_INVOKABLE int get_game_status() const
    {
        return m_interface->get_game_status();
    };

signals:
    void cameraStreamUpdated();
    void videoStreamUpdated();

private:
    std::shared_ptr<Interface::GuiInterface> m_interface;
    VideoStreamContent* cam;
    VideoStreamContent* vid;
};

}