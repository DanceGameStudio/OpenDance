#include "GuiInterface.hpp"

namespace Interface {

std::shared_ptr<Graphics> GuiInterface::get_graphics()
{
    return graphics_;
}

}