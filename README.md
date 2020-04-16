

![logo](https://i.imgur.com/MJmaTHC.png)
---
Small playable virtual piano, written in C++ (POO, anul I, sem II)

**Cerințe obligatorii:**\
🎹 Interfața grafica (în SDL, SFML, Qt, etc) cu API pentru C++ 🗹\
🎹 RTTI 🗹
```cpp
if (dynamic_cast<WhiteKey *>(key)) {

    key->setPosition(whiteX, Y);
    whiteX += 48;
}
```
🎹 Abstract Classes  🗹
```cpp
class Key {

    /*
       ...
    */
    virtual sf::Sprite& getSprite() = 0;
    virtual void playSound() = 0;
    virtual void setPosition(int x, int y) = 0;
};
```
🎹 Operatori (minim 4 * numărul oamenilor din echipa)\
🎹 Heap Memory Allocation 🗹
```cpp
piano.cpp

piano.push_back(new WhiteKey(tKeyWhite, tKeyWhitePressed));
```
🎹 Exceptions 🗹
```cpp
piano.cpp

try {
    if (...) {
    // ...
    }
    else
        throw 1438;
}
catch (int errCode) {
    if (errCode == 1438)
    {
        std::cout << "Bad object in piano array" << '\n';
    }
}

```
🎹 STL 🗹
```cpp
#include <string>
#include <vector>
```
🎹 Lambda expressions 🗹
```cpp
// MainWindow.cpp
auto getKeyPressed = [=]() {
    return piano->findKeyPressed(settings.getKbKeys()[std::to_string(event.key.code)]);
};

//usage
if (event.type == sf::Event::KeyPressed)
{
    if (settings.getKbKeys().contains(std::to_string(event.key.code)))
    {

        activeKey = getKeyPressed();
        Recorder::log("down", activeKey->getId());
        // ...
    }
}
```
🎹 Templates 🗹
```cpp
// MainWindow.cpp

//// Definiton ////
template <class T>
void MainWindow::checkPressed(T &obj)
{
    if (obj.getSprite().getGlobalBounds().contains(mapPixelToCoords(sf::Mouse::getPosition((*this)))))
        obj.press(true);
}
```
🎹 Smart pointers - minim 1 tip / proiect
```cpp
// Piano.cpp

static std::shared_ptr<Piano> instance;
std::vector<std::shared_ptr<Key>> piano;

... and many more!
```
🎹 Design patterns - minim 2 🗹

#### Singleton 🗹
```cpp
/**
 * Piano: Singleton class that holds array of piano keys
 * Calculates black/white key positions.
 * Holds key textures.
 */
class Piano
{
/// ...
public:
    static Piano *getInstance()
    {
        if (!instance){
            instance = new Piano;
            std::cout<<"pianul a fost creat"<<std::endl;
        }
        else{
            std::cout<<"pianul a fost invocat"<<std::endl;
        }
        return instance;
    }
```

#### Facade 🗹
```cpp
// Recorder.h - facade that hides all recording logic.
class Recorder {
    static json songData;
    static sf::Clock clock;
    static bool recording;
    public:
    Recorder();
    static void start();
    static void stop();
    static void save();
    static void log(std::string type, int noteId);
    static void play();
    static void load(std::string path);
    static bool isRecording();
};
```
🎹 Features of C++17/20 (constexpr, consteval, constinit, fold expressions, init statement for if/switch, etc) 🗹
```cpp
//// Init statement for if (C++17) ////
if (double seconds = clock.getElapsedTime().asMilliseconds(); seconds < 100)
{
    //Atenuare sunet :) onKeyReleased
    c = std::lerp(100, 0, seconds / 100.0);
    //std::cout << seconds << " " << c << std::endl;
    sound.setVolume(c);
    if (c <= 5.0)
        break;
}
```
**Opțional => Bonus:**\
🎹 Move semantics\
🎹 Multithreading (la echipe de 3-4 oameni)\
🎹 Computer Network / Socket Programming (la echipe de 2-4 oameni)\
🎹 BD
