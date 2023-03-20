#pragma once

namespace Settings {

class Audio {
    Audio();

    void set_gain();
    double get_gain();

private:
    double gain_;
};
}