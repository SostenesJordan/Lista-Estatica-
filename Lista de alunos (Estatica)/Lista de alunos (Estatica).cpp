#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"


int main()
{
    using namespace std;

    setlocale(LC_ALL, "Portuguese");


	List* ListaAlunos;
	Aluno p;
	Aluno *Alunop;

	Alunop = &p;

    int i = 1;
	int aux = 0;
	char menu;

	ListaAlunos = criaLista();

    while (i != 0)
    {
		printf("\n#############################################");
		printf("\n           MENU - Lista de informação       ");
		printf("\n                                            ");
		printf("\n	                                           ");
		printf("\n                                            ");
		printf("\n	 1 = Matriculas                            ");
		printf("\n	 2 = Adicionar aluno                       ");
		printf("\n	 3 = Remover aluno                         ");
		printf("\n	 4 = Buscar                                ");
		printf("\n   5 = Situação do estudante                 ");
		printf("\n   6 = Calcular a media da turma             ");
		printf("\n	 Qualquer outra tecla  irá sair            ");
		printf("\n                                            ");
		printf("\n#############################################");
		printf("\n\n");

		cin >> menu;

		menu = toupper(menu);

		switch (menu)
		{
			case '1': // Mostrar a quantidade de alunos matriculados
				aux = tamanhoDaLista(ListaAlunos);
				cout << "Elementos na Lista :" << aux << endl;
				break;

			case '2': // Add novo aluno
				cout << "Informe o nome :"; cin >> p.nome ;
				cout << "Informe a matricula :"; cin >> p.matricula ;
				cout << "Informe a idade :"; cin >> p.idade;
				aux = inserirAlunoNovo(ListaAlunos, p);
				if (aux == 0) {
					cout << "ERROR" << endl;
				}
				break;

			case '3': // Remove aluno
				cout << "Informe a matricula do aluno :"; cin >> p.matricula;
				aux = removeAluno(ListaAlunos, p.matricula);
				if (aux == 0) {
					cout << "ERROR" << endl;
				}
				break;

				//buscar aluno lista
			case '4':
				cout << "Informe a posição que deseja acessar :"; cin >> aux;

				aux = buscarAlunoNaLista(ListaAlunos, aux, Alunop);

				if (aux == 0) {
					cout << "ERROR" << endl;
				}

				//" Nota 1 - " << p.n1 << endl << " Nota 2 - " << p.n2 <<
				cout << " Aluno solicitado em : " << endl << " Nome - " << p.nome << endl << " Matricula - " << p.matricula << endl << " Idade - " << p.idade << endl;

				cout << " "; cout << " ";

				cout << "Para 'sim' digite -> '1' | Para 'não' digite -> '0' " << endl;
				int mudarNotas;
				cin >> mudarNotas;

				if (mudarNotas == 1) {
					cout << "Digite a nota 1: "; cin >> p.n1;
					cout << "Digite a nota 2: "; cin >> p.n2;

					cout << "Nota adicionada !" << endl;
				}
				else
				{
					cout << " ";
				}
				break;

				// Consultar situação do aluno
			case '5':

				cout << "Informe a posição que deseja acessar :"; cin >> aux;

				aux = buscarAlunoNaLista(ListaAlunos, aux, Alunop);

				if (aux == 0) {
					cout << "ERROR" << endl;
				}

				if (p.n1 && p.n2 < 0)
				{
					cout << "Aluno cursando..." << endl;
				}
				else {
					cout << " Notas do aluno : " << endl << " Nota 1 - " << p.n1 << endl << "Nota 2 - " << p.n2 << endl;
					cout << " ";

					if (p.n1 * 0.4 && p.n2 * 0.6 >= 6) {

						cout << "Aluno APROVADO !";
					}
					else
					{
						cout << "Aluno REPROVADO";
					}
				}
				break;

				//calcular a media da turma intereira

			case '6':
				aux = buscarAlunoNaLista(ListaAlunos, aux, Alunop);

				if (aux == 0) {
					cout << "ERROR" << endl;
				}
				else 
				{
					float mediaTurma;
				}

				break;


			default:
				cout << "saindo..." << endl;
				liberarLista(ListaAlunos);
				exit(0);
				break;


		}


    }
}

