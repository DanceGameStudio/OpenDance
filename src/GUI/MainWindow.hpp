#pragma once

#include "GuiInterface.hpp"
#include <QGuiApplication>
#include "GuiInterface.hpp"

class GUI {

public:
    GUI(Interface::GuiInterface* intf)
        : m_intf(intf) {};

    void run(int argc, char** argv);

private:
    Interface::GuiInterface* m_intf;

};