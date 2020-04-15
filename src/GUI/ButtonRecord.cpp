#include "ButtonRecord.h"
#include "Recorder.h"
void ButtonRecord::press(bool value)
{
    if (spriteState == "record")
    {
        if (Recorder::isRecording() == false)
        {
            Recorder::start(); // :)
            getSprite().setTexture(*t_Save);
            spriteState = "save";
        }
    }
    else if (spriteState == "save")
    {
        Recorder::save();
        getSprite().setTexture(*t_Record);
        spriteState = "record";
    }
};