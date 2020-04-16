#ifndef PIANO_H_INCLUDED
#define PIANO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Key.h"
#include <iostream>
/**
 * Piano: Singleton class that holds array of piano keys
 * Calculates black/white key positions.
 * Holds key textures.
 */
class Piano
{
private:
    static std::shared_ptr<Piano> instance;
    std::vector<std::shared_ptr<Key>> pianoKeys;
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
        auto f = [=]() {
            if (!instance)
                instance.reset(new Piano);
            return instance;
        };
        return f();
    }


    void setPositions();
    std::vector<std::shared_ptr<Key>> &getKeys();
    std::shared_ptr<Key> findKeyClicked(sf::Vector2f mouse);
    std::shared_ptr<Key> findKeyPressed(int keyIndex);

    friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<Piano> piano);
    std::shared_ptr<Key> operator[](int i);
};




#endif