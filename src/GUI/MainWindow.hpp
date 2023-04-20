#pragma once

#include "Interface.hpp"
#include <QGuiApplication>
#include "Interface.hpp"

class GUI {

public:
    GUI(Interface::Interface* intf)
        : m_intf(intf) {};

    void run(int argc, char** argv);

private:
    Interface::Interface* m_intf;

};