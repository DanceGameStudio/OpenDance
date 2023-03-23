#pragma once

namespace Settings {

class Audio {

    void set_gain();
    double get_gain();

private:
    double gain_;
};
}