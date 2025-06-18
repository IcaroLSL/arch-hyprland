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
