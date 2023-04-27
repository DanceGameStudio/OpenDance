#include "ConfigFile.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace Utility {

ConfigFile::ConfigFile()
{
}

ConfigFile::~ConfigFile()
{
    // For safety reasons write the config cache on destruction
    write_config();
}

void ConfigFile::read_config()
{
    // Open the file for reading
    std::ifstream file(config_path_);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + config_path_);
    }

    // Parse the file line by line
    std::string line;
    std::string current_category;
    while (std::getline(file, line)) {
        // Trim whitespace from the beginning and end of the line
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

        // Skip empty and comment lines
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Check if the line is a category
        if (line[0] == '[' && line[line.size() - 1] == ']') {
            current_category = line.substr(1, line.size() - 2);
            continue;
        }

        // Split the line into key-value pair
        std::stringstream ss(line);
        std::string key, value;
        std::getline(ss, key, '=');
        std::getline(ss, value);

        // Add the key-value pair to the map
        ConfigIndex config_index = std::make_pair(current_category, key);
        config_values_[config_index] = value;
    }

    // Close the file
    file.close();
}

void ConfigFile::write_config()
{
    // Open the file for writing
    std::ofstream file(config_path_);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + config_path_);
    }

    // Write each category and key-value pair to the file
    std::string current_category;
    for (auto const& config_pair : config_values_) {
        ConfigIndex config_index = config_pair.first;
        std::string category = config_index.first;
        std::string key = config_index.second;
        std::string value = config_pair.second;

        // Write category header if it has changed
        if (category != current_category) {
            file << "[" << category << "]" << std::endl;
            current_category = category;
        }

        // Write the key-value pair
        file << key << " = " << value << std::endl;
    }

    // Close the file
    file.close();
}

bool ConfigFile::has_value(ConfigIndex config_index)
{
    return config_values_.count(config_index) > 0;
}

bool ConfigFile::get_value(ConfigIndex config_index, bool default_value)
{
    if (has_value(config_index)) {
        std::string value_str = config_values_[config_index];
        std::transform(value_str.begin(), value_str.end(), value_str.begin(), ::tolower);
        if (value_str == "true" || value_str == "yes" || value_str == "1") {
            return true;
        } else if (value_str == "false" || value_str == "no" || value_str == "0") {
            return false;
        } else {
            throw std::runtime_error("Invalid boolean value for key: " + config_index.first + " in category: " + config_index.second);
        }
        return default_value;
    }
}

double ConfigFile::get_value(ConfigIndex config_index, double default_value)
{
    if (has_value(config_index)) {
        std::string value_str = config_values_[config_index];
        try {
            return std::stod(value_str);
        } catch (std::exception& e) {
            throw std::runtime_error("Invalid double value for key: " + config_index.second + " in category: " + config_index.first);
        }
    }
    return default_value;
}

float ConfigFile::get_value(ConfigIndex config_index, float default_value)
{
    if (has_value(config_index)) {
        std::string value_str = config_values_[config_index];
        try {
            return std::stof(value_str);
        } catch (std::exception& e) {
            throw std::runtime_error("Invalid float value for key: " + config_index.second + " in category: " + config_index.first);
        }
    }
    return default_value;
}

std::string ConfigFile::get_value(ConfigIndex config_index, std::string default_value)
{
    if (has_value(config_index)) {
        return config_values_[config_index];
    }
    return default_value;
}

void ConfigFile::set_value(ConfigIndex config_index, bool value)
{
    std::string value_str = value ? "true" : "false";
    config_values_[config_index] = value_str;
}

void ConfigFile::set_value(ConfigIndex config_index, double value)
{
    std::stringstream ss;
    ss << value;
    config_values_[config_index] = ss.str();
}

void ConfigFile::set_value(ConfigIndex config_index, float value)
{
    std::stringstream ss;
    ss << value;
    config_values_[config_index] = ss.str();
}

void ConfigFile::set_value(ConfigIndex config_index, std::string value)
{
    config_values_[config_index] = value;
}

void ConfigFile::set_path(std::string path)
{
    config_path_ = path;
}

}
