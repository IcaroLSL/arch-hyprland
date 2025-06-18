#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    const std::string path = "/sys/class/power_supply/BAT0/capacity";
    std::ifstream file(path);

    if (!file) {
        std::cout << R"({"text": "⚠️", "tooltip": "Bateria não encontrada"})" << std::endl;
        return 1;
    }

    std::string battery_level;
    std::getline(file, battery_level);
    int level = std::stoi(battery_level);

    std::string image_path;
    if (level >= 90)
        image_path = "/home/yoku/.config/waybar/icons/batria_100.png";
    else if (level >= 70)
        image_path = "/home/yoku/.config/waybar/icons/batria_80.png";
    else if (level >= 50)
        image_path = "/home/yoku/.config/waybar/icons/batria_60.png";
    else if (level >= 30)
        image_path = "/home/yoku/.config/waybar/icons/batria_40.png";
    else if (level >= 10)
        image_path = "/home/yoku/.config/waybar/icons/batria_20.png";
    else
        image_path = "/home/yoku/.config/waybar/icons/batria_0.png";

    // Exibe o valor na barra
    std::cout << R"({"text": ")" << battery_level 
              << R"(%", "tooltip": "Bateria: )" << battery_level 
              << R"(%"})" << std::endl;

    // Exibe notificação com imagem da bateria
    std::string cmd = "notify-send 'Bateria: " + std::to_string(level) +
                      "%' --icon=" + image_path + " --app-name=Bateria";
    system(cmd.c_str());

    return 0;
}
