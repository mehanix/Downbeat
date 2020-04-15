#include "ButtonRecord.h"
#include "Recorder.h"
#include <iostream>
void ButtonRecord::press(bool value)
{
    std::cout<<spriteState<<" "<<Recorder::isRecording()<<std::endl;
    if (spriteState == "record")
    {
        if (Recorder::isRecording() == false)
        {
            Recorder::start(); // :)
            getSprite().setTexture(*t_Save);
            spriteState = "save";
                std::cout<<spriteState<<" "<<Recorder::isRecording()<<std::endl;

        }
    }
    else if (spriteState == "save")
    {
        Recorder::save();
        getSprite().setTexture(*t_Record);
        spriteState = "record";
    }
};