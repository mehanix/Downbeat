#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Button.h"
#include "Key.h"
#include "Piano.h"
#include "Settings.h"
#include <unordered_set>
#include "Recorder.h"
#include "ButtonRecord.h"
#include "ButtonLoad.h"
#include "ButtonPlay.h"

/* ViewWindow: class that creates and renders the main GUI window */
class MainWindow : public sf::RenderWindow
{
    ///////////////////////
    ///       GUI       ///
    ///////////////////////
    sf::Font font;
    sf::Texture bkgTexture;
    sf::Sprite bkg;

    sf::Texture panelTexture;
    sf::Sprite panel;

    sf::Texture logoTexture;
    sf::Sprite logo;

    sf::Text adLabel;

    sf::Texture t_buttonRecord;
    sf::Texture t_buttonSave;
    sf::Texture t_buttonLoad;
    sf::Texture t_buttonPlay;
    ButtonRecord buttonRecord;
    ButtonLoad buttonLoad;
    ButtonPlay buttonPlay;
    ////////////////////////
    ///      Settings    ///
    ////////////////////////
    Settings settings;
    std::shared_ptr<Piano> piano = piano->getInstance();
    std::unordered_set<std::shared_ptr<Key>> activeKeys;

public:
    MainWindow(sf::VideoMode v, std::string title);
    void loadLayout();
    void render();
    void drawGUI();
    template <class T>
    void checkPressed(T &obj);
   
};

#endif