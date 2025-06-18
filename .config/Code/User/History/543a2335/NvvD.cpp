#include <iostream>
#include <fstream>
#include <string>

using namespace std

int main() {
    const std::string path = "/sys/class/power_supply/BAT0/capacity";
    ifstream file(path);
    
    if (!file) {
        cout << R"({"text": "⚠️", "tooltip": "Bateria não encontrada"})" << std::endl;
        return 1;
    }

    string battery_level;
    getline(file, battery_level);

    std::cout << R"({"text": ")" << battery_level << R"(%", "tooltip": "Bateria: )" << battery_level << R"(%"})" << std::endl;
    return 0;
}
