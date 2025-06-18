#include <iostream>
#include <ctime>
#include <memory>
#include <array>
#include <sstream>

using namespace std;

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
    
    return 0;
}
