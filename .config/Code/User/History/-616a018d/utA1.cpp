#include <iostream>
#include <ctime>
#include <memory>
#include <array>
#include <sstream>

using namespace std;

string get_dia_semana() {
    const char* dias[] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    time_t agora = time(0);
    tm* local = localtime(&agora);
    return dias[local->tm_wday];
}

string get_calendario() {
    array<char, 128> buffer;
    string resultado;
    // unique_ptr<FILE, decltype(&pclose)> pipe(popen("cal", "r"), pclose);
    auto pipe_deleter = [](FILE* f) { if (f) pclose(f); };
    unique_ptr<FILE, decltype(pipe_deleter)> pipe(popen("cal", "r"), pipe_deleter);
    if (!pipe) return "Erro ao executar cal";

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        resultado += buffer.data();
    }

    size_t pos = 0;
    while ((pos = resultado.find('\n', pos)) != string::npos) {
        resultado.replace(pos, 1, "\\n");
        pos += 2;
    }

    return resultado;
}

int main() {
    string dia = get_dia_semana();
    string calendario = get_calendario();

    cout << "{'text\": "" << dia << endl;
    
    return 0;
}
