<p align="center">
  <br>
  <img  src="https://i.imgur.com/MJmaTHC.png">
</p>
<p align="center">
     Small playable virtual piano, written in C++ - (POO, an I, sem. II)
</p>

![pic](https://i.imgur.com/Xc2ZsXy.png)

## Features
* Play notes using mouse clicks/keyboard
* Press 1 or more notes at the same time
* Record and save your songs
* Load and play saved songs
* Intuitive interface
* Runs on Linux/Mac
<br/>

## Installation
Please install Zenity (dialog boxes) and SFML (GUI):
```bash
sudo apt install zenity libsfml-dev
```
Then, in the root project folder, run `make` to compile the code.

Run using `make run`.
<br/><br/><br/>

## Course tasks
**Cerințe obligatorii:**\
🎹 Interfața grafica (în SDL, SFML, Qt, etc) cu API pentru C++ ☑️\
🎹 RTTI ☑️
```cpp
piano.cpp

if (dynamic_cast<WhiteKey *>(key)) {

    key->setPosition(whiteX, Y);
    whiteX += 48;
}
```
🎹 Abstract Classes  ☑️
```cpp
Key.h

class Key {

    // ...
    
    virtual sf::Sprite& getSprite() = 0;
    virtual void playSound() = 0;
    virtual void setPosition(int x, int y) = 0;
};
```
🎹 Operatori (minim 4 * numărul oamenilor din echipa) ☑️
```cpp
Settings.cpp

// Populates json with default settings, if empty :)
Settings& Settings::operator++(int) {
    if(std::ifstream f("config.txt"); f.peek() == std::ifstream::traits_type::eof())
        generateConfig();
    return *this;
}
```

```cpp
Piano.cpp

// Shows piano data.
std::ostream& operator<<(std::ostream& out, std::shared_ptr<Piano> piano) {
    out << "Pian cu "<< piano->getKeys().size() <<" clape.\n";
    for(auto &i : piano->getKeys()) {
        // ...
    }
    return out;
 }
```

```cpp
Piano.cpp

// Operator care acceseaza direct elementele vectorului vector<Key>piano, din clasa Piano
std::shared_ptr<Key> Piano::operator[](int i) {
    return piano[i];
}
```

```cpp
Key.cpp

// operator care returneaza id-ul notei.
int& Key::operator[](std::string s)
{
    if (s == "noteId")
        return noteId;
    
}
```
🎹 Heap Memory Allocation ☑️
```cpp
piano.cpp

pianoKeys.push_back(std::shared_ptr<WhiteKey>(new WhiteKey(tKeyWhite, tKeyWhitePressed,i,std::to_string(i)+".ogg")));
```
🎹 Exceptions ☑️
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
🎹 STL ☑️
```cpp
#include <string>
#include <vector>
#include <exception>
#include <unordered_set>
#include <memory>
```
🎹 Lambda expressions ☑️
```cpp
MainWindow.cpp

auto getKeyPressed = [=]() {
    return piano->findKeyPressed(settings.getKbKeys()[std::to_string(event.key.code)]);
};

// usage
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
🎹 Templates ☑️
```cpp
MainWindow.cpp

//// Definiton ////
template <class T>
void MainWindow::checkPressed(T &obj)
{
    if (obj.getSprite().getGlobalBounds().contains(mapPixelToCoords(sf::Mouse::getPosition((*this)))))
        obj.press(true);
}
```
🎹 Smart pointers - minim 1 tip / proiect ☑️
```cpp
Piano.cpp

static std::shared_ptr<Piano> instance;
std::vector<std::shared_ptr<Key>> piano;

... and many more!
```
🎹 Design patterns - minim 2 ☑️

#### Singleton ☑️
```cpp
/**
 * Piano: Singleton class that holds array of piano keys
 * Calculates black/white key positions.
 * Holds key textures.
 */
class Piano
{
  // ...
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

#### Facade ☑️
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
🎹 Features of C++17/20 (constexpr, consteval, constinit, fold expressions, init statement for if/switch, etc) ☑️
```cpp
WhiteKey.cpp

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
