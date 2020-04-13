#pragma once 
#include <SFML/Audio.hpp>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
class Recorder {
    json songData;
    sf::Clock clock;
    public:
    Recorder();
    void start();
    void stop();
    void save();
    void log(std::string type, int noteId);
    void play();
};