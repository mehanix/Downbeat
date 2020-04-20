#include "Recorder.h"
#include <iostream>
#include <fstream>
#include "Piano.h"
#include <cstdlib>
Recorder::Recorder()
{
    recording = false;
    playing = false;
    songData.clear();
}

void Recorder::log(std::string type, int noteId)
{
    if (recording && !playing)
    {
        float time = clock.getElapsedTime().asMicroseconds();
        std::string str = std::to_string((int)time);
        songData[str] = {type, noteId};
        lastVal = str;
        notePressed = type == "down" ? true : false;
    }
}

void Recorder::start()
{
    if (!recording && !playing)
    {
        songData.clear();
        songData = json();
        recording = true;
        clock.restart();
        popen("zenity --notification --text=\"Downbeat 🎵\nRecording...\"", "r");
    }
    else
        popen("zenity --error --no-wrap  --text=\"Downbeat 🎵\nCannot record, busy...\"", "r");
}

bool Recorder::save(std::string path)
{
    if (recording && !playing && !notePressed)
    {
        recording = false;
        std::ofstream file(path, std::ios::out | std::ios::trunc);

        songData["lastVal"] = std::stoi(lastVal);
        file << songData.dump();
        songData.clear();
        file.close();
        popen("zenity --notification --text=\"Downbeat 🎵\nSaved!\"", "r");
        return true;
    }
    else
        popen("zenity --error --no-wrap --title=\"Downbeat 🎵\" --text=\"Cannot save, busy...\"", "r");
    return false;
}

void Recorder::play()
{
    if (!recording && !playing && !songData.empty())
    {
        playing = true;
        std::cout << "playing..." << std::endl;
        std::shared_ptr<Piano> piano = piano->getInstance();
        int last = songData.value("lastVal", -1);
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
        popen("zenity --notification --text=\"Downbeat 🎵\nSong finished.\"", "r");
        playing = false;
    }
    else
    {
        popen("zenity --error --no-wrap --title=\"Downbeat 🎵\n\" --text=\"Cannot play song!\"", "r");
    }
}

void Recorder::load(std::string path)
{
    if (!recording && !playing)
    {
        songData.clear();
        std::ifstream inputFile(path);
        songData = json::parse(inputFile);
        popen("zenity --notification --text=\"Downbeat 🎵\nSong loaded.\"", "r");
        inputFile.close();
    }
    else
        popen("zenity --error --no-wrap --title=\"Downbeat 🎵\n\" --text=\"Cannot load!\"", "r");
}

bool Recorder::isRecording()
{
    return recording;
}

bool Recorder::isPlaying()
{
    return playing;
}

// initializari variabile statice
json Recorder::songData = json();
sf::Clock Recorder::clock = sf::Clock();
bool Recorder::recording = false;
bool Recorder::playing = false;
bool Recorder::notePressed = false;
std::string Recorder::lastVal = "0";