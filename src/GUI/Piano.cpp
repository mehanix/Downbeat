#include "Piano.h"
#include "MainWindow.h"
#include "WhiteKey.h"
#include "BlackKey.h"

struct ObjException : public std::exception
{
    const char *what() const throw()
    {
        return "bad object in piano array";
    }
};

Piano::Piano()
{
    tKeyWhite.loadFromFile("res/piano/key_white.png");
    tKeyWhitePressed.loadFromFile("res/piano/key_white_pressed.png");
    tKeyBlack.loadFromFile("res/piano/key_black.png");
    tKeyBlackPressed.loadFromFile("res/piano/key_black_pressed.png");
    int pos = 64;
    /// Adauga clape albe
    for (int i = 0; i < 14; i++)
    {
        pianoKeys.push_back(std::shared_ptr<WhiteKey>(new WhiteKey(tKeyWhite, tKeyWhitePressed,i,std::to_string(i)+".ogg")));
    }
    /// Adauga clape negre
    for (int i = 0; i < 10; i++)
    {
        pianoKeys.push_back(std::shared_ptr<BlackKey>(new BlackKey(tKeyBlack, tKeyBlackPressed,14+i,std::to_string(14+i) + ".ogg")));
    }

    setPositions();
}


std::vector<std::shared_ptr<Key>> &Piano::getKeys()
{
    return pianoKeys;
}

/* calculeaza si seteaza pozitiile clapelor pe ecran */
void Piano::setPositions()
{

    int whiteX = 64;
    int blackX = 94;
    int blackCount = 0;
    int Y = 280;

    // iteram prin clape
    for (auto &key : pianoKeys)
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
                throw ObjException();
        }
        catch (ObjException& e)
        {
            std::cerr<<e.what();
        }
    }
}

std::shared_ptr<Key> Piano::findKeyClicked(sf::Vector2f mouse) {

    //std::cout<<mouse.x<<" "<<mouse.y<<'\n';
    for(int i = pianoKeys.size()-1; i>=0;i--) {
        sf::FloatRect bounds = pianoKeys[i]->getSprite().getGlobalBounds();
        if (bounds.contains(mouse))
        {
            return pianoKeys[i];
        }
    }
    return nullptr;
    
}

std::shared_ptr<Key>Piano::findKeyPressed(int keyIndex) {
    return pianoKeys[keyIndex];
}



std::shared_ptr<Piano> Piano::instance = nullptr;

// Operator care acceseaza direct elementele vectorului pianoKeys, din clasa Piano
std::shared_ptr<Key> Piano::operator[](int i) {
    return pianoKeys[i];
}


std::ostream& operator<<(std::ostream& out, std::shared_ptr<Piano> piano) {
    out << "Pian cu "<< piano->getKeys().size() <<" clape.\n";
    for(auto &i : piano->getKeys()) {
        if (dynamic_cast<WhiteKey*>(i.get()))
            out<<i.get()->getId()<<" Clapa alba\n";
        else if (dynamic_cast<BlackKey*>(i.get()))
            out<<i.get()->getId()<<" Clapa neagra\n";
    }
    return out;
 }
