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
    //font
    font.loadFromFile("res/gui/BellotaText.ttf");

    //background image/pattern
    bkgTexture.loadFromFile("res/gui/piano.png");
    bkgTexture.setRepeated(true);
    bkg = sf::Sprite(bkgTexture,sf::IntRect(0,0,getSize().x,getSize().y));
    bkg.setColor(sf::Color(0,0,0,35));

    //main panel
    panelTexture.loadFromFile("res/gui/panel2.png");
    panel = sf::Sprite(panelTexture,sf::IntRect(0,0,718,518));
    panel.setPosition(41,41);

    //app logo
    logoTexture.loadFromFile("res/gui/logo.png");
    logoTexture.setSmooth(true);
    logo = sf::Sprite(logoTexture);
    logo.setPosition(70,67);
    logo.setScale(0.5f,0.5f);

    //app label
    adLabel.setFont(font);
    adLabel.setString("easy to use virtual piano");
    adLabel.setCharacterSize(20);
    adLabel.setFillColor(sf::Color(26,26,26));
    adLabel.setPosition(515,70);

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
            
            if (event.type == sf::Event::MouseButtonPressed)
{
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        auto key = piano->findKeyClicked((*this).mapPixelToCoords(sf::Mouse::getPosition((*this))));
    }
}
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
        sf::RenderWindow::draw(adLabel);
        for(auto &k:piano->getKeys()) {
            sf::RenderWindow::draw(k->getSprite());
        }
}