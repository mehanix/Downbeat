#include <map>
#include "Key.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;
class Settings {
    private:
        std::map<char,Key*> controls;
        std::ifstream settingsPath;
        json settingsJson;
    public:
        Settings();
        void generateConfig();
        json& getKbKeys();
};