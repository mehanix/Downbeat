#include "ButtonPlay.h"
#include "Recorder.h"
#include <fstream>
#include <cstring>
#include <iostream>
void ButtonPlay::press(bool value)
{
    if (value == true)
    {
       //TODO set texture
        Recorder::play();
    }
}