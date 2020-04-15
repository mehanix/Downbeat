#include "MainWindow.h"
#include <string>
/* Constructor: Loads GUI and starts render loop*/
MainWindow::MainWindow(sf::VideoMode v, std::string title) : sf::RenderWindow(v, title)
{
    setKeyRepeatEnabled(false); // pentru cantat la clape
    settings = Settings();
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
    bkg = sf::Sprite(bkgTexture, sf::IntRect(0, 0, getSize().x, getSize().y));
    bkg.setColor(sf::Color(0, 0, 0, 35));

    //main panel
    panelTexture.loadFromFile("res/gui/panel2.png");
    panel = sf::Sprite(panelTexture, sf::IntRect(0, 0, 718, 518));
    panel.setPosition(41, 41);

    //app logo
    logoTexture.loadFromFile("res/gui/logo.png");
    logoTexture.setSmooth(true);
    logo = sf::Sprite(logoTexture);
    logo.setPosition(70, 67);
    logo.setScale(0.5f, 0.5f);

    //app label
    adLabel.setFont(font);
    adLabel.setString("easy to use virtual piano");
    adLabel.setCharacterSize(20);
    adLabel.setFillColor(sf::Color(26, 26, 26));
    adLabel.setPosition(515, 70);

    //button textures
    t_buttonRecord.loadFromFile("res/gui/btn_record.png");
    t_buttonSave.loadFromFile("res/gui/btn_save.png");
    t_buttonLoad.loadFromFile("res/gui/btn_load.png");
    t_buttonPlay.loadFromFile("res/gui/btn_play.png");
    //buttons
    buttonRecord = ButtonRecord(t_buttonRecord, t_buttonSave);
    buttonLoad = ButtonLoad(t_buttonLoad, t_buttonLoad);
    buttonPlay = ButtonPlay(t_buttonPlay,t_buttonPlay);
}
void MainWindow::render()
{
    while (sf::RenderWindow::isOpen())
    {
        Key *activeKey;
        sf::Event event;
        while (sf::RenderWindow::pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sf::RenderWindow::close();

            /////////////////////////////
            ////       Mouse         ////
            ////////////////////////////
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //recorder.stop();
                //recorder.save();
                std::cout << "prr" << std::endl;

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    activeKey = piano->findKeyClicked(mapPixelToCoords(sf::Mouse::getPosition((*this))));
                    activeKeys.insert(activeKey);
                    if (activeKey == nullptr)
                    {
                        // Button click logic :D
                        if (buttonRecord.getSprite().getGlobalBounds().contains(mapPixelToCoords(sf::Mouse::getPosition((*this)))))
                        {
                            buttonRecord.press(true);
                        }
                        if (buttonLoad.getSprite().getGlobalBounds().contains(mapPixelToCoords(sf::Mouse::getPosition((*this)))))
                        {
                            buttonLoad.press(true);
                        }
                        if (buttonPlay.getSprite().getGlobalBounds().contains(mapPixelToCoords(sf::Mouse::getPosition((*this)))))
                        {
                            buttonPlay.press(true);
                        }
                        
                    }
                    else
                    {
                        activeKey->setPressed(true);
                        recorder.log("down", activeKey->getId());
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (activeKey != nullptr)
                    {
                        recorder.log("up", activeKey->getId());
                        activeKey->setPressed(false);
                        activeKeys.erase(activeKey);
                    }
                }
            }

            ////////////////////////////
            ////      Keyboard      ////
            ////////////////////////////

            if (event.type == sf::Event::KeyPressed)
            {
                if (settings.getKbKeys().contains(std::to_string(event.key.code)))
                {
                    activeKey = piano->findKeyPressed(settings.getKbKeys()[std::to_string(event.key.code)]);
                    recorder.log("down", activeKey->getId());

                    activeKeys.insert(activeKey);
                    if (activeKey != nullptr)
                        activeKey->setPressed(true);
                }

                if (event.key.code == sf::Keyboard::Dash)
                {
                    recorder.save();
                }
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (settings.getKbKeys().contains(std::to_string(event.key.code)))
                {
                    Key *toBeDeleted = piano->findKeyPressed(settings.getKbKeys()[std::to_string(event.key.code)]);
                    recorder.log("up", toBeDeleted->getId());

                    toBeDeleted->setPressed(false);
                    activeKeys.erase(toBeDeleted);
                }
            }
        }

        sf::RenderWindow::clear(sf::Color(223, 219, 229, 255));
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
    sf::RenderWindow::draw(buttonRecord.getSprite());
    sf::RenderWindow::draw(buttonLoad.getSprite());
    sf::RenderWindow::draw(buttonPlay.getSprite());
    for (auto &k : piano->getKeys())
    {
        sf::RenderWindow::draw(k->getSprite());
    }
}