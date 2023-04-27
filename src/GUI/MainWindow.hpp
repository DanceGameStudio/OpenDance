#pragma once

#include <QGuiApplication>
#include "../Interfaces/GuiInterface.hpp"

class GUI {

public:
    GUI(std::shared_ptr<Interface::GuiInterface> intf)
        : m_intf(intf) {};

    void run(int argc, char** argv);

private:
    std::shared_ptr<Interface::GuiInterface> m_intf;

};