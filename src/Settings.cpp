#include "Settings.h"
#include<iostream>
#include<string>
using json = nlohmann::json;
Settings::Settings() {
    settingsPath = std::ifstream ("config.txt",std::ifstream::in);
    settingsPath >> settingsJson;
    std::cout << settingsJson["25"];
    std::cout<<"set"<<std::endl;
};

json& Settings::getKbKeys() {
    return settingsJson;
}





bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

/// Genereaza fisierul de configurare cu setarile default
/// Din pacate, Key Code-urile difera de la platforma la platforma
/// Not much i can do :( bout this
void Settings::generateConfig() {
    json j;
    j[std::to_string(sf::Keyboard::Z)] = 0;
    j[std::to_string(sf::Keyboard::X)] = 1;
    j[std::to_string(sf::Keyboard::C)] = 2;
    j[std::to_string(sf::Keyboard::V)] = 3;
    j[std::to_string(sf::Keyboard::B)] = 4;
    j[std::to_string(sf::Keyboard::N)] = 5;
    j[std::to_string(sf::Keyboard::M)] = 6;
    j[std::to_string(sf::Keyboard::Q)] = 7;
    j[std::to_string(sf::Keyboard::W)] = 8;
    j[std::to_string(sf::Keyboard::E)] = 9;
    j[std::to_string(sf::Keyboard::R)] = 10;
    j[std::to_string(sf::Keyboard::T)] = 11;
    j[std::to_string(sf::Keyboard::Y)] = 12;
    j[std::to_string(sf::Keyboard::U)] = 13;
    j[std::to_string(sf::Keyboard::S)] = 14;
    j[std::to_string(sf::Keyboard::D)] = 15;
    j[std::to_string(sf::Keyboard::G)] = 16;
    j[std::to_string(sf::Keyboard::H)] = 17;
    j[std::to_string(sf::Keyboard::J)] = 18;
    j[std::to_string(sf::Keyboard::Num2)] = 19;
    j[std::to_string(sf::Keyboard::Num3)] = 20;
    j[std::to_string(sf::Keyboard::Num5)] = 21;
    j[std::to_string(sf::Keyboard::Num6)] = 22;
    j[std::to_string(sf::Keyboard::Num7)] = 23;

    std::ofstream out("config.txt");
    out << j.dump(4);

}