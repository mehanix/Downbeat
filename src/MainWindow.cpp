#include "MainWindow.h"
#include <string>

/* Constructor: Loads GUI and starts render loop*/
MainWindow::MainWindow(sf::VideoMode v, std::string title) : sf::RenderWindow(v, title)
{
    loadLayout(); // initialise all GUI controls
    render();     //render loop
}

void MainWindow::loadLayout()
{
    //background image/pattern
    bkgTexture.loadFromFile("res/piano.png");
    bkgTexture.setRepeated(true);
    bkg = sf::Sprite(bkgTexture,sf::IntRect(0,0,getSize().x,getSize().y));
    bkg.setColor(sf::Color(0,0,0,35));
    //main panel
    panelTexture.loadFromFile("res/panel2.png");
    panel = sf::Sprite(panelTexture,sf::IntRect(0,0,718,518));
    panel.setPosition(41,41);
    //app logo
    logoTexture.loadFromFile("res/logo.png");
    logoTexture.setSmooth(true);
    logo = sf::Sprite(logoTexture);
    logo.setPosition(70,70);
    logo.setScale(0.5f,0.5f);

}
void MainWindow::render()
{

    while (sf::RenderWindow::isOpen())
    {
        sf::Event event;
        while (sf::RenderWindow::pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sf::RenderWindow::close();
        }

        sf::RenderWindow::clear(sf::Color(223,219,229,255));
        drawGUI();
        sf::RenderWindow::display();
    }
}
void MainWindow::drawGUI()
{
   // sf::RenderWindow::draw(b.getSprite());
        sf::RenderWindow::draw(bkg);
        sf::RenderWindow::draw(panel);
        sf::RenderWindow::draw(logo);
}