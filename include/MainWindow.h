#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
/* ViewWindow: class that creates and renders the main GUI window */
class MainWindow : public sf::RenderWindow{
    ///////////////////////
    ///  GUI controls   ///
    ///////////////////////
    sf::CircleShape* shape;




    public:
       MainWindow(sf::VideoMode v, std::string title);
        void loadLayout();
        void render();
        void drawGUI();
       
};

#endif