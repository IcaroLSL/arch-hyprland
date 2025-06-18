#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    const std::string path = "/sys/class/power_supply/BAT0/capacity";
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cout << R"({"text": "⚠️", "tooltip": "Bateria não encontrada"})" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line);
    int capacity = std::stoi(line);

    std::string emoji;

    if (capacity <= 10) {
        emoji = "muito baixa ";
    } else if (capacity <= 30) {
        emoji = "baixa";
    } else if (capacity <= 60) {
        emoji = "media";
    } else if (capacity <= 99) {
        emoji = "bateria alta";
    } else {
        emoji = "cheia";
    }

    std::cout << R"({"text": ")" << emoji << " " << capacity << R"(%", "tooltip": "Bateria: )" << capacity << R"(%"})" << std::endl;

    return 0;
}
