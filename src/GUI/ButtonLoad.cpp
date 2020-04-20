#include "ButtonLoad.h"
#include "Recorder.h"
#include <fstream>
#include <iostream>
ButtonLoad::ButtonLoad() : Button(){};
ButtonLoad::ButtonLoad(sf::Texture &t, sf::Texture &t_pressed) : Button(t, t_pressed)
{
    sprite.setPosition(190, 210);
}

void ButtonLoad::press(bool value)
{
    if (value == true)
    {
        //TODO set pressed texture
        char filename[1024];
        FILE *f = popen("zenity --file-selection --file-filter=*.sng", "r");
        fgets(filename, 1024, f);
        std::string file(filename);
        if (file.size() > 0)
            file.pop_back();
        if (file[0] == '/') // if is path
            Recorder::load(file);
    }
}