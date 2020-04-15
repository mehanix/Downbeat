#include "ButtonLoad.h"
#include "Recorder.h"
#include <fstream>
#include <cstring>
#include <iostream>
void ButtonLoad::press(bool value)
{
    if (value == true)
    {
        //TODO set pressed texture
        char filename[1024];
        FILE *f = popen("zenity --file-selection --file-filter=*.sng", "r");
        fgets(filename, 1024, f);
        filename[strlen(filename)-1] = NULL; // damn you fgets
        std::cout<<filename<<std::endl;
        if(filename[0] == '/') // if is path
            Recorder::load(filename);
        
        
    }
}