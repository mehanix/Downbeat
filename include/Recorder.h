#pragma once 
#include <SFML/Audio.hpp>
class Recorder {
    sf::SoundBufferRecorder recorder;
        sf::Sound s;

    public:
    Recorder();
    void start();
    void stop();
    void save();
};