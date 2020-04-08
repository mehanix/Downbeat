![logo](https://i.imgur.com/MJmaTHC.png)
---
Small playable virtual piano, written in C++ (POO, anul I, sem II)

**Cerințe obligatorii:**\
🎹 Interfața grafica (în SDL, SFML, Qt, etc) cu API pentru C++ 🗹\
🎹 RTTI\
🎹 Abstract Classes\
🎹 Operatori (minim 4 * numărul oamenilor din echipa)\
🎹 Heap Memory Allocation 🗹
```cpp
piano.push_back(new WhiteKey(tKeyWhite, tKeyWhitePressed, sf::Vector2f(pos, 280), "a"));
```
🎹 Exceptions\
🎹 STL 🗹
```cpp
#include <string>
#include <vector>
```
🎹 Lambda expressions\
🎹 Templates\
🎹 Smart pointers - minim 1 tip / proiect\
🎹 Design patterns - minim 2

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

#### Facade?
```cpp
// Coming soon!
```
🎹 Features of C++17/20 (constexpr, consteval, constinit, fold expressions, init statement for if/switch, etc) (minim 1 / proiect)

**Opțional => Bonus:**\
🎹 Move semantics\
🎹 Multithreading (la echipe de 3-4 oameni)\
🎹 Computer Network / Socket Programming (la echipe de 2-4 oameni)\
🎹 BD
