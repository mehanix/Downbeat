#include "ButtonRecord.h"
#include "Recorder.h"
#include <iostream>

ButtonRecord::ButtonRecord() : Button()
{
    spriteState = "record";
};
ButtonRecord::ButtonRecord(sf::Texture &t_rec, sf::Texture &t_save) : Button()
{
    t_Record = &t_rec;
    t_Save = &t_save;
    getSprite().setTexture(*t_Record);
    getSprite().setPosition(70, 210);
    spriteState = "record";
};

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
        char filename[1024];
        FILE *f = popen("zenity --file-selection --filename=my_song.sng --save --confirm-overwrite --file-filter=*.sng", "r");
        fgets(filename, 1024, f);
        std::string file(filename);
        if (file.size() > 0)
            file.pop_back();
        if (file[0] == '/') // if is path
        {
            bool status = Recorder::save(file);

            if (status == true)
            {
                getSprite().setTexture(*t_Record);
                spriteState = "record";
                popen("zenity --info --no-wrap --text=\"Save succesful!\"", "r");
            }
        }
        else
            popen("zenity --error --text=\"Save failed!\"", "r");
    }
};