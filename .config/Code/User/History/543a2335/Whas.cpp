#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    const string path = "/sys/class/power_supply/BAT0/capacity";
    const string status_path = "/sys/class/power_supply/BAT0/status";

    ifstream file(path);
    ifstream status_file(status_path);

    if (!file.is_open()) {
        cout << R"({"text": "⚠️", "tooltip": "Bateria não encontrada"})" << endl;
        return 1;
    }

    string line;
    getline(file, line);
    int capacity = stoi(line);

    string status;
    getline(status_file, status);

    string emoji;

    if (status == "Not charging") {
        emoji = "󰂄";
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
