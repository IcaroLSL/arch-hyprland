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
#include <memory>
#include <array>
#include <sstream>

std::string get_dia_semana() {
    const char* dias[] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    time_t agora = time(0);
    tm* local = localtime(&agora);
    return dias[local->tm_wday];
}

std::string get_calendario() {
    std::array<char, 128> buffer;
    std::string resultado;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("cal", "r"), pclose);
    if (!pipe) return "Erro ao executar cal";

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        resultado += buffer.data();
    }

    // Escapa \n para ser compatível com JSON
    size_t pos = 0;
    while ((pos = resultado.find('\n', pos)) != std::string::npos) {
        resultado.replace(pos, 1, "\\n");
        pos += 2;
    }

    return resultado;
}

int main() {
    std::string dia = get_dia_semana();
    std::string calendario = get_calendario();

    std::cout << "{\"text\": \"" << dia << "\", \"tooltip\": \"" << calendario << "\"}" << std::endl;
    std::cout << R"({"text": ")" << dia << " " << calendario << R"(%", "tooltip": "Bateria: )" << capacity << R"(%"})" << std::endl;
    return 0;
}
