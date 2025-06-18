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
#include <string>

std::string json_escape(const std::string& input) {
    std::string output;
    for (char c : input) {
        switch (c) {
            case '\"': output += "\\\""; break;
            case '\\': output += "\\\\"; break;
            case '\n': output += "\\n"; break;
            case '\r': /* ignore carriage return */ break;
            default: output += c; break;
        }
    }
    return output;
}

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

    return resultado;
}

int main() {
    std::string dia = get_dia_semana();
    std::string calendario = get_calendario();
    std::string calendario_esc = json_escape(calendario);

    std::cout << "{\"text\": \"" << dia << "\", \"tooltip\": \"" << calendario_esc << "\"}" << std::endl;
    return 0;
}
