#pragma once 
#include <SFML/Audio.hpp>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
class Recorder {
    static json songData;
    static sf::Clock clock;
    static bool recording;
    public:
    Recorder();
    static void start();
    static void stop();
    static void save();
    static void log(std::string type, int noteId);
    static void play();
    static bool isRecording();
};