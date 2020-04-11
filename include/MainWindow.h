#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Button.h"
#include "Key.h"
#include "Piano.h"
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

    //TODO remove
    /*sf::Sprite key;
    sf::Sprite key2;
    sf::Texture keyTexture2;
    sf::Sprite key3;*/

    Piano *piano = piano->getInstance();
    public:
       MainWindow(sf::VideoMode v, std::string title);
        void loadLayout();
        void render();
        void drawGUI();
       
};

#endif