#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string path = "/sys/class/power_supply/BAT0/capacity";
    std::ifstream file(path);

    if (!file) {
        std::cerr << "/home/yoku/.config/waybar/icons/bateria_0.png" << std::endl;
        return 1;
    }

    int level;
    file >> level;

    std::string image_path = "/home/yoku/.config/waybar/icons/";

    if (level >= 90)
        image_path += "batria_100.png";
    else if (level >= 70)
        image_path += "batria_80.png";
    else if (level >= 50)
        image_path += "batria_60.png";
    else if (level >= 30)
        image_path += "batria_40.png";
    else if (level >= 10)
        image_path += "batria_20.png";
    else
        image_path += "batria_0.png";

    std::cout << image_path << std::endl;
    return 0;
}
