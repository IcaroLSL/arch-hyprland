#include <iostream>
#include <cstdlib>
#include <string>
#include <array>

std::string get_day_of_week() {
    std::array<char, 64> buffer;
    FILE* pipe = popen("date +%A", "r");
    if (!pipe) return "Desconhecido";
    std::string result;
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    // Remove o \n
    result.erase(result.find_last_not_of("\n") + 1);
    return result;
}

std::string get_calendar() {
    std::array<char, 512> buffer;
    FILE* pipe = popen("cal", "r");
    if (!pipe) return "Erro ao obter calendário";
    std::string result;
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

int main() {
    std::string day = get_day_of_week();
    std::string calendar = get_calendar();

    std::cout << "{"
              << "\"text\": \"" << day << "\", "
              << "\"tooltip\": \"" << calendar << "\""
              << "}" << std::endl;

    return 0;
}
