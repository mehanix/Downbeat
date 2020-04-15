#include "Piano.h"
#include "MainWindow.h"
#include "WhiteKey.h"
#include "BlackKey.h"
Piano::Piano()
{
    tKeyWhite.loadFromFile("res/piano/key_white.png");
    tKeyWhitePressed.loadFromFile("res/piano/key_white_pressed.png");
    tKeyBlack.loadFromFile("res/piano/key_black.png");
    tKeyBlackPressed.loadFromFile("res/piano/key_black_pressed.png");
    int pos = 64;
    std::cout << "sunt un pian" << std::endl;
    /// Adauga clape albe
    for (int i = 0; i < 14; i++)
    {
        piano.push_back(std::shared_ptr<WhiteKey>(new WhiteKey(tKeyWhite, tKeyWhitePressed,i,std::to_string(i)+".ogg")));
    }
    /// Adauga clape negre
    for (int i = 0; i < 10; i++)
    {
        piano.push_back(std::shared_ptr<BlackKey>(new BlackKey(tKeyBlack, tKeyBlackPressed,14+i,std::to_string(14+i) + ".ogg")));
    }

    setPositions();
}

std::vector<std::shared_ptr<Key>> &Piano::getKeys()
{
    return piano;
}

/* calculeaza si seteaza pozitiile clapelor pe ecran */
void Piano::setPositions()
{

    int whiteX = 64;
    int blackX = 94;
    int blackCount = 0;
    int Y = 280;

    // iteram prin clape
    for (auto &key : piano)
    {

        // daca e clapa alba
        try
        {
            if (dynamic_cast<WhiteKey*>(key.get()))
            {
                key->setPosition(whiteX, Y);
                whiteX += 48;
            }
            else if (dynamic_cast<BlackKey*>(key.get()))
            {
                blackCount++;
                if (blackCount == 3 || blackCount == 6 || blackCount == 8)
                    blackX += 48;
                key->setPosition(blackX, Y);
                blackX += 48;
            }
            else
                throw 1438;
        }
        catch (int errCode)
        {
            if (errCode == 1438)
            {
                std::cout << "Bad object in piano array" << '\n';
            }
        }
    }
}

std::shared_ptr<Key> Piano::findKeyClicked(sf::Vector2f mouse) {

    //std::cout<<mouse.x<<" "<<mouse.y<<'\n';
    for(int i = piano.size()-1; i>=0;i--) {
        sf::FloatRect bounds = piano[i]->getSprite().getGlobalBounds();
        if (bounds.contains(mouse))
        {
            return piano[i];
        }
    }
    return nullptr;
    
}

std::shared_ptr<Key>Piano::findKeyPressed(int keyIndex) {
    return piano[keyIndex];
}



std::shared_ptr<Piano> Piano::instance = nullptr;
