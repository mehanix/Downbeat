#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Button.h"
/* ViewWindow: class that creates and renders the main GUI window */
class MainWindow : public sf::RenderWindow{
    ///////////////////////
    ///       GUI       ///
    ///////////////////////
    Button b = Button();
    sf::Texture bkgTexture;
    sf::Sprite bkg;

    sf::Texture panelTexture;
    sf::Sprite panel;

    sf::Texture logoTexture;
    sf::Sprite logo;

    public:
       MainWindow(sf::VideoMode v, std::string title);
        void loadLayout();
        void render();
        void drawGUI();
       
};

#endif