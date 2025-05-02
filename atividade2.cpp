#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
	string nome;
	int idade;
	int matricula;
	float peso;
	void imprime() {

		cout << "Nome: " <<  nome.c_str() << "\t" << "Idade: " << idade << "\t" << "Matricula: " << matricula << "\t" "Peso: " << peso << endl;
	}
};

int main(int argc, char **argv) {
	cout << "Atividade de laboratório" << endl;
	Pessoa alisson;
	alisson.nome = "Alison";
	alisson.idade = 10;
	alisson.matricula = 1225;
	alisson.peso = 180.5f;
	alisson.imprime();

	// Parte 2
	Pessoa lucas;
	lucas.nome = "Lucas";
	lucas.idade = 17;
	lucas.matricula = 2024;
	lucas.peso = 120.6f;
	lucas.imprime();

	Pessoa ramon;
	ramon.nome = "Dinobronha";
	ramon.idade = 35;
	ramon.matricula = 199089;
	ramon.peso = 300.5f;
	ramon.imprime();

	// Parte 3
	Pessoa array[5];
	array[0].nome = "Taveira";
	array[0].idade = 17;
	array[0].matricula = 199028;
	array[0].peso = 70.1f;
	array[0].imprime();

	array[1].nome = "Marquim";
	array[1].idade = 178;
	array[1].matricula = 199008;
	array[1].peso = 60.1f;
	array[1].imprime();

	array[2].nome = "Gustavo";
	array[2].idade = 17;
	array[2].matricula = 199628;
	array[2].peso = 90.1f;
	array[2].imprime();

	array[3].nome = "Mendes";
	array[3].idade = 17;
	array[3].matricula = 198678028;
	array[3].peso = 80.1f;
	array[3].imprime();

	array[4].nome = "Bernardo";
	array[4].idade = 17;
	array[4].matricula = 198767899028;
	array[4].peso = 60.1f;
	array[4].imprime();

	for (int i = 0; i < array[i], i++) {

	}

	return 0;
}
