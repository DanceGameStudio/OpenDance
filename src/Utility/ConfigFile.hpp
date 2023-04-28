#pragma once
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace Utility {

class ConfigFile {
public:
    // ConfigIndex is a key value pair of "Category" and "Key" in that Category
    typedef std::pair<std::string, std::string> ConfigIndex;

    ConfigFile();
    ~ConfigFile();

    void read_config();
    void write_config();

    bool has_value(ConfigIndex config_index);

    bool get_value(ConfigIndex config_index, bool default_value = false);
    double get_value(ConfigIndex config_index, double default_value = 0.0);
    float get_value(ConfigIndex config_index, float default_value = 0.f);
    std::string get_value(ConfigIndex config_index, std::string default_value = "");

    void set_value(ConfigIndex config_index, bool value);
    void set_value(ConfigIndex config_index, double value);
    void set_value(ConfigIndex config_index, float value);
    void set_value(ConfigIndex config_index, std::string value);

    void set_path(std::string path);

private:
    std::map<ConfigIndex, std::string> config_values_;
    std::string config_path_ = "config.ini";
};

}
