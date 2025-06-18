// #include <iostream>
// #include <ctime>
// #include <map>

// int main() {
//     std::map<int, std::string> dias = {
//         {0, "Domingo"},
//         {1, "Segunda"},
//         {2, "Terça"},
//         {3, "Quarta"},
//         {4, "Quinta"},
//         {5, "Sexta"},
//         {6, "Sábado"}
//     };

//     std::time_t t = std::time(nullptr);
//     std::tm* now = std::localtime(&t);
//     int dia_semana = now->tm_wday;

//     std::string dia = dias[dia_semana];

//     std::cout << "{\"text\": \"" << dia << "\", \"tooltip\": \"Dia da semana: " << dia << "\"}" << std::endl;
//     return 0;
// }


#include <iostream>
#include <ctime>
#include <map>
#include <sstream>
#include <array>
#include <memory>

std::string get_calendario() {
    std::array<char, 128> buffer;
    std::string resultado;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("cal", "r"), pclose);
    if (!pipe) return "Erro ao obter calendário";

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        resultado += buffer.data();
    }
    return resultado;
}

int main() {
    std::map<int, std::string> dias = {
        {0, "Domingo"},
        {1, "Segunda"},
        {2, "Terça"},
        {3, "Quarta"},
        {4, "Quinta"},
        {5, "Sexta"},
        {6, "Sábado"}
    };

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int dia_semana = now->tm_wday;

    std::string dia = dias[dia_semana];
    std::string calendario = get_calendario();

    std::cout << "{\"text\": \"" << dia << "\", \"tooltip\": \"" << calendario << "\"}" << std::endl;
    return 0;
}
