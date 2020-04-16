#include "Recorder.h"
#include <iostream>
#include <fstream>
#include "Piano.h"
#include <cstdlib>
#include <chrono>
Recorder::Recorder()
{
    recording = false;
    songData.clear();
}

std::string lastVal;
void Recorder::log(std::string type, int noteId)
{
    if (recording)
    {
        float time = clock.getElapsedTime().asMicroseconds();
        std::string str = std::to_string((int)time);
        std::cout << str << std::endl;
        songData[str] = {type, noteId};
        std::cout << time << songData[str] << "\r\n";
        lastVal = str;
    }
}

void Recorder::start()
{
    if (!recording)
    {
        songData.clear();
        songData = json();
        recording = true;
        clock.restart();
        std::cout << "recording..." << std::endl;
    }
}

void Recorder::save()
{
    const auto p1 = std::chrono::system_clock::now();
    if (recording)
    {
        recording = false;
        std::ofstream file("songs/song_"+std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
            p1.time_since_epoch()).count())+".sng",  std::ios::out | std::ios::trunc);
        //TODO handle empty case
        songData["lastVal"] = std::stoi(lastVal);
        file << songData.dump();
        songData.clear();
        file.close();
        std::cout << "saved..." << std::endl;
    }
}

void Recorder::play()
{
    if(!recording && !songData.empty()) {
    std::cout << "playing..." << std::endl;
    std::shared_ptr<Piano> piano = piano->getInstance();
    int last = songData.value("lastVal", -1);
    std::cout << last << std::endl;
    int counter = 0;
    std::string counterKey;
    clock.restart();
    do
    {
        counter = clock.getElapsedTime().asMicroseconds();
        counterKey = std::to_string(counter);
        if (songData.contains(counterKey))
        {
            if (songData[counterKey][0] == "down")
            {
                piano->findKeyPressed(songData[counterKey][1])->setPressed(true);
            }
            else
            {
                piano->findKeyPressed(songData[counterKey][1])->setPressed(false);
            }
        }

    } while (counter < last);
    std::cout << "song done." << std::endl;  

    } else {
        std::cout<<"cannot play..."<<std::endl;
    }
    
}

void Recorder::load(std::string path) {
    songData.clear();
    std::cout<<path;
    std::ifstream inputFile(path);
    songData = json::parse(inputFile);
    std::cout<<" loaded..."<<std::endl;
    inputFile.close();
}


bool Recorder::isRecording() {
    return recording;
}

json Recorder::songData = json();
sf::Clock Recorder::clock = sf::Clock();
bool Recorder::recording = false;
