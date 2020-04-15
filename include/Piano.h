#ifndef PIANO_H_INCLUDED
#define PIANO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Key.h"
/**
 * Piano: Singleton class that holds array of piano keys
 * Calculates black/white key positions.
 * Holds key textures.
 */
class Piano
{
private:
    static std::shared_ptr<Piano> instance;
    std::vector<std::shared_ptr<Key>> piano;
    sf::Texture tKeyWhite;
    sf::Texture tKeyBlack;
    sf::Texture tKeyWhitePressed;
    sf::Texture tKeyBlackPressed;
    Piano();
    Piano(Piano const &){};            // copy constructor is private
    Piano &operator=(Piano const &){}; // assignment operator is private

public:
    static std::shared_ptr<Piano> getInstance()
    {
        if (!instance){
            instance.reset(new Piano);
            std::cout<<"pianul a fost creat"<<std::endl;
        }
        else{
            std::cout<<"pianul a fost invocat"<<std::endl;
        }
        return instance;
    }
    ~Piano()
    {
        std::cout << "papa pian" << std::endl;
    }

    void setPositions();
    std::vector<std::shared_ptr<Key>> &getKeys();
    std::shared_ptr<Key> findKeyClicked(sf::Vector2f mouse);
    std::shared_ptr<Key> findKeyPressed(int keyIndex);
};

#endif