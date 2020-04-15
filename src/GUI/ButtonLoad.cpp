#include "ButtonLoad.h"
#include "Recorder.h"
#include <fstream>
void ButtonLoad::press(bool value)
{
    if (value == true)
    {
        //TODO set pressed texture
        char filename[1024];
        FILE *f = popen("zenity --file-selection --file-filter=*.sng", "r");
        fgets(filename, 1024, f);
        Recorder::load(filename);
        
        
    }
}