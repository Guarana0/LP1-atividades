#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Registro {
    std::string subturma;
    std::string nomeAluno;
    double nota;
};

std::vector<Registro> carregarDados(const std::string& nomeArquivo) {
    std::vector<Registro> registros;
    std::ifstream arquivo("alunos.csv");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return registros;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string subturma, nomeAluno;
        double nota;
        std::getline(ss, subturma, ',');
        std::getline(ss, nomeAluno, ',');
        ss >> nota;

        registros.push_back({subturma, nomeAluno, nota});
    }

    arquivo.close();
    return registros;
}

void calcularMediaPorSubturma(const std::vector<Registro>& registros) {
    std::vector<std::string> subturmasCalculadas;

    for (const auto& registro : registros) {
        if (std::find(subturmasCalculadas.begin(), subturmasCalculadas.end(), registro.subturma) == subturmasCalculadas.end()) {
            subturmasCalculadas.push_back(registro.subturma);
            double soma = 0.0;
            int contador = 0;

            for (const auto& r : registros) {
                if (r.subturma == registro.subturma) {
                    soma += r.nota;
                    contador++;
                }
            }

            double media = soma / contador;
            std::cout << "Subturma: " << registro.subturma << ", Média das notas: " << media << std::endl;
        }
    }
}

int main() {
    std::string nomeArquivo;
    std::cout << "Digite o nome do arquivo CSV para carregar: ";
    std::cin >> nomeArquivo; // Usuário fornece o nome do arquivo no console.

    auto registros = carregarDados(nomeArquivo);
    calcularMediaPorSubturma(registros);

    return 0;
}

