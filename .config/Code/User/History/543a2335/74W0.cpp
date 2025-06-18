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
        emoji = "";
    } else if (capacity <= 10) {
        emoji = "󰁺";
    } else if (capacity <= 20) {
        emoji = "󰁻";
    } else if (capacity <= 30) {
        emoji = "󰁼";
    } else if (capacity <= 40) {
        emoji = "󰁽";
    } else if (capacity <= 50) {
        emoji = "󰁾";
    } else if (capacity <= 60) {
        emoji = "󰁿";
    } else if (capacity <= 70) {
        emoji = "󰂀";
    } else if (capacity <= 80) {
        emoji = "󰂁";
    } else if (capacity <= 90) {
        emoji = "󰂂";
    } else {
        emoji = "󰁹";
    }

    std::cout << R"({"text": ")" << emoji << " " << capacity << R"(%", "tooltip": "Bateria: )" << capacity << R"(%"})" << std::endl;

    return 0;
}
