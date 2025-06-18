#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string path = "/sys/class/power_supply/BAT0/capacity";
    std::ifstream file(path);
    
    if (!file) {
        std::cout << R"({"text": "⚠️", "tooltip": "Bateria não encontrada"})" << std::endl;
        return 1;
    }

    std::string battery_level;
    std::getline(file, battery_level);

    std::cout << R"({"text": ")" << battery_level << R"(%", "tooltip": "Bateria: )" << battery_level << R"(%"})" << std::endl;
    return 0;
}
