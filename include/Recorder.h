#pragma once 
#include <SFML/Audio.hpp>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
class Recorder {
    static json songData;
    static sf::Clock clock;
    static bool recording;
    static bool playing;
    static bool notePressed; // TRUE if at least one note currently pressed (to prevent saving while note was not released, which would break song)
    public:
    Recorder();
    static void start();
    static void stop();
    static bool save(std::string path);
    static void log(std::string type, int noteId);
    static void play();
    static void load(std::string path);
    static bool isRecording();
    static bool isPlaying();
};