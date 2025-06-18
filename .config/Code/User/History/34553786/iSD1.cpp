#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string path_capacity = "/sys/class/power_supply/BAT0/capacity";
    std::ifstream file(path_capacity);

    if (!file) {
        // Se não achou a bateria, pode retornar um caminho padrão ou um aviso
        std::cout << "/home/yoku/.config/waybar/icons/batria_0.png" << std::endl;
        return 1;
    }

    std::string battery_level_str;
    std::getline(file, battery_level_str);

    int battery_level = std::stoi(battery_level_str);

    // Decide qual imagem mostrar conforme bateria (0, 20, 40, 60, 80, 100)
    std::string image_path = "/home/yoku/.config/waybar/icons/batria_0.png";

    if (battery_level >= 90)
        image_path = "/home/yoku/.config/waybar/icons/batria_100.png";
    else if (battery_level >= 70)
        image_path = "/home/yoku/.config/waybar/icons/batria_80.png";
    else if (battery_level >= 50)
        image_path = "/home/yoku/.config/waybar/icons/batria_60.png";
    else if (battery_level >= 30)
        image_path = "/home/yoku/.config/waybar/icons/batria_40.png";
    else if (battery_level >= 10)
        image_path = "/home/yoku/.config/waybar/icons/batria_20.png";
    else
        image_path = "/home/yoku/.config/waybar/icons/batria_0.png";

    std::cout << image_path << std::endl;

    return 0;
}
