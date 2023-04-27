#include "GuiInterface.hpp"

namespace Interface {

void GuiInterface::set_graphics(Graphics& graphics)
{
    graphics_ = graphics;
}

Graphics& GuiInterface::get_graphics()
{
    return graphics_;
}

}