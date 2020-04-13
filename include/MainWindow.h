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
/* ViewWindow: class that creates and renders the main GUI window */
class MainWindow : public sf::RenderWindow{
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

    ////////////////////////
    ///      Settings    ///
    ////////////////////////
    Settings settings;

    Recorder recorder;

    Piano *piano = piano->getInstance();
    std::unordered_set<Key*> activeKeys;
    public:
       MainWindow(sf::VideoMode v, std::string title);
        void loadLayout();
        void render();
        void drawGUI();
       
};

#endif