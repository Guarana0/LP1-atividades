#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib> // para atoi, atof
using namespace std;

class Pet {
private:
    int id;
    string nome;
    string tipo;
    string raca;
    char genero;
    double valor;

public:
    Pet(int id, string nome, string tipo, string raca, char genero, double valor)
        : id(id), nome(nome), tipo(tipo), raca(raca), genero(genero), valor(valor) {}

    void imprimir() const {
        cout << id << ";" << nome << ";" << tipo << ";" << raca << ";" << genero << ";" << valor << endl;
    }

    string getTipo() const {
        return tipo;
    }

    char getGenero() const {
        return genero;
    }

    double getValor() const {
        return valor;
    }
};

vector<Pet> carregarPets(const char* nomeArquivo) {
    vector<Pet> pets;
    ifstream arquivo(nomeArquivo);
    string linha;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string campo;
        string campos[6];
        int i = 0;

        while (getline(ss, campo, ';') && i < 6) {
            campos[i++] = campo;
        }

        if (i == 6) {
            int id = atoi(campos[0].c_str());
            string nome = campos[1];
            string tipo = campos[2];
            string raca = campos[3];
            char genero = campos[4][0];
            double valor = atof(campos[5].c_str());

            Pet pet(id, nome, tipo, raca, genero, valor);
            pets.push_back(pet);
        }
    }

    return pets;
}

double somaValor(const vector<Pet>& pets, const string& tipoDesejado) {
    double soma = 0;
    for (size_t i = 0; i < pets.size(); i++) {
        if (pets[i].getTipo() == tipoDesejado) {
            soma += pets[i].getValor();
        }
    }
    return soma;
}

int calculaPares(const vector<Pet>& pets) {
    int machosCao = 0, femeasCao = 0;
    int machosGato = 0, femeasGato = 0;

    for (size_t i = 0; i < pets.size(); i++) {
        if (pets[i].getTipo() == "cao") {
            if (pets[i].getGenero() == 'M') machosCao++;
            else if (pets[i].getGenero() == 'F') femeasCao++;
        } else if (pets[i].getTipo() == "gato") {
            if (pets[i].getGenero() == 'M') machosGato++;
            else if (pets[i].getGenero() == 'F') femeasGato++;
        }
    }

    int paresCao = (machosCao < femeasCao) ? machosCao : femeasCao;
    int paresGato = (machosGato < femeasGato) ? machosGato : femeasGato;

    return paresCao + paresGato;
}

int main() {
    vector<Pet> pets = carregarPets("pets.csv");

    for (size_t i = 0; i < pets.size(); i++) {
        pets[i].imprimir();
    }

    cout << "Soma vgatos: " << somaValor(pets, "gato") << endl;
    cout << "Soma caes: " << somaValor(pets, "cao") << endl;
    cout << "Numero de pares: " << calculaPares(pets) << endl;

    return 0;
}
