#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
/* 
    Key: Abstract class.
*/
class Key {

    sf::Texture texture;
    sf::Texture texturePressed;
    sf::Sprite sprite;
    sf::Text label;
    sf::Vector2f pos;
    std::string kbKeyCode;    
    public:
    Key();
    Key(sf::Texture& t, sf::Texture& t_Pressed, sf::Vector2f pos, std::string kcode);
    virtual sf::Sprite& getSprite();
    virtual void playSound() = 0;

    
    ~Key() {
        std::cout<<"papa clapa"<<std::endl;
    }
};
#endif