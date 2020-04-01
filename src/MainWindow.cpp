#include "MainWindow.h"
#include <string>

 /* Constructor: Loads GUI and starts render loop*/
        MainWindow::MainWindow(sf::VideoMode v, std::string title): sf::RenderWindow(v,title) { 
                loadLayout(); // initialise all GUI controls
                render(); //render loop               
        }


        void MainWindow::loadLayout() {
                shape = new sf::CircleShape(100.f);
                shape->setFillColor(sf::Color::Green); //ar fi in buton.
        }

        void MainWindow::render() {
            while (sf::RenderWindow::isOpen())
            {
                sf::Event event;
                while (sf::RenderWindow::pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        sf::RenderWindow::close();
                }

                sf::RenderWindow::clear();
                drawGUI();
                sf::RenderWindow::display();
            }
        }
        void MainWindow::drawGUI() {
             sf::RenderWindow::draw(*shape);
        }