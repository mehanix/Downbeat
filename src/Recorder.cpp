#include "Recorder.h"
#include <iostream>
#include <fstream>
#include "Piano.h"
Recorder::Recorder()
{
}

std::string lastVal;
void Recorder::log(std::string type, int noteId)
{
    float time = clock.getElapsedTime().asMicroseconds();
    std::string str = std::to_string((int)time);
    std::cout << str << std::endl;
    songData[str] = {type, noteId};
    std::cout << time << songData[str] << "\r\n";
    lastVal = str;
}
void Recorder::start()
{
    clock.restart();
    std::cout << "recording..." << std::endl;
}

void Recorder::save()
{
    std::ofstream file("filename.sng");
    songData["lastVal"] = std::stoi(lastVal);
    file << songData.dump();
    std::cout << "saved..." << std::endl;
    play();
}

void Recorder::play()
{
    //plays loaded songData TODO load songdata from file :)
    std::cout<<"playing..."<<std::endl;
    Piano *piano = piano->getInstance();
    int last = songData.value("lastVal",-1);
    std::cout<<last<<std::endl;
    int counter = 0;
    std::string counterKey;
    clock.restart();
    do
    {
        counter = clock.getElapsedTime().asMicroseconds();
        counterKey = std::to_string(counter);
        if(songData.contains(counterKey)) {
           if(songData[counterKey][0] == "down") {
               piano->findKeyPressed(songData[counterKey][1])->setPressed(true);
           }
           else
           {
                piano->findKeyPressed(songData[counterKey][1])->setPressed(false);

           }
           
        }

    } while (counter < last);
    std::cout<<"am evadat"<<std::endl;
}