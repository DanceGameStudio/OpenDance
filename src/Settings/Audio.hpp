#pragma once

namespace Settings {

class Audio {
    Audio();

    void set_gain();
    void get_gain();

private:
    double gain_;
};
}