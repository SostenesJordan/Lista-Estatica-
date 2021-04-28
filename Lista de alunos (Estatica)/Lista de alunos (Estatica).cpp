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
		printf("\n           MENU - Lista de informacao      ");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n-->  [1] = Matriculas (total)\n   ");
		printf("\n-->  [2] = Adicionar novo aluno\n ");
		printf("\n-->  [3] = Remover aluno\n ");
		printf("\n-->  [4] = Buscar\n  ");
		printf("\n-->  [5] = Situacao do estudante\n ");
		printf("\n-->  [6] = Imprimir lista de alunos\n ");
		printf("\n-->  [7] = calcular a media de todos os alunos\n ");
		printf("\n");
		printf("\n           --> [0] PARA SAIR DO PROGRAMA!\n ");
		printf("\n");
		printf("\n#############################################");
		printf("\n\n\n>> "); cin >> menu;

		

		menu = toupper(menu);

		switch (menu)
		{
			case '0':
				cout << "Programa finalizado...\n";
				i = 0;
				break;



			case '1': // Mostrar a quantidade de alunos matriculados
				aux = tamanhoDaLista(ListaAlunos);
				cout << "Tem : " << aux <<" na lista"<< endl;
				system("pause");
				break;

			case '2': // Add novo aluno
				cout << "Informe o nome :"; cin >> p.nome ;
				cout << "Informe a matricula :"; cin >> p.matricula ;
				cout << "Informe a idade :"; cin >> p.idade;
				aux = inserirAlunoNovo(ListaAlunos, p);
				if (aux == 0) {
					cout << "ERROR" << endl;
				}
				system("pause");
				break;

			case '3': // Remove aluno
				cout << "Informe a matricula do aluno :"; cin >> p.matricula;
				aux = removeAluno(ListaAlunos, p.matricula);
				if (aux == 0) {
					cout << "ERROR" << endl;
				}
				system("pause");
				break;

				//buscar aluno lista
			case '4':
				cout << "Informe a posicao que deseja acessar :"; cin >> aux;



				aux = buscarAlunoNaLista(ListaAlunos, aux, Alunop);

				if (aux == 0) {
					cout << "ERROR" << endl;
				}
					//----



				

					cout << " Aluno solicitado em : " << endl << " Nome - " << p.nome << endl << " Matricula - " << p.matricula << endl << " Idade - " << p.idade << endl;
					if (p.n1 == 0 && p.n2 == 0) {
						cout << "Situacao - " << "Cursando..." << endl << endl;
					}

					cout << "Deseja adicionar notas do aluno ?\n [1] para SIM || [2] para NAO" << endl;
					int mudarNotas;
					cin >> mudarNotas;
					
					if (mudarNotas == 1) {
						cout << "Digite a nota 1: "; cin >> p.n1;
						cout << "Digite a nota 2: "; cin >> p.n2;

						cout << "Nota adicionada !" << endl<<endl;

						if ((p.n1 * 0.4) + (p.n2 * 0.6) >= 6) {

							cout << "Aluno APROVADO !\n";
						}
						else
						{
							cout << "Aluno REPROVADO\n";
						}

					}
				
				
				









					/*
					cout << " Aluno solicitado em : " << endl << " Nome - " << p.nome << endl << " Matricula - " << p.matricula << endl << " Idade - " << p.idade << endl;
					cout << "Situacao : " << "" << endl << endl;
					if (p.n1 * 0.4 && p.n2 * 0.6 >= 6) {

						cout << "Aluno APROVADO !\n";
					}
					else
					{
						cout << "Aluno REPROVADO\n";
					}
					*/



					//cout << " Aluno solicitado em : " << endl << " Nome - " << p.nome << endl << " Matricula - " << p.matricula << endl << " Idade - " << p.idade << endl<<"Nota 1 - "<<p.n1<<endl<<"Nota 2 - "<<p.n2<<endl;
				

				//" Nota 1 - " << p.n1 << endl << " Nota 2 - " << p.n2 <<
				//cout << " Aluno solicitado em : " << endl << " Nome - " << p.nome << endl << " Matricula - " << p.matricula << endl << " Idade - " << p.idade << endl;

				

				/*cout << "Para 'sim' digite -> '1' | Para 'não' digite -> '0' " << endl;
				int mudarNotas;
				cin >> mudarNotas;

				if (mudarNotas == 1) {
					cout << "Digite a nota 1: "; cin >> p.n1;
					cout << "Digite a nota 2: "; cin >> p.n2;

					cout << "Nota adicionada !" << endl<<endl;
				}
				else
				{
					cout << " "<<endl<<endl;
				}
				*/
				//-----------------------------------------
				system("pause");
				break;

				// Consultar situação do aluno
			case '5':

				cout << "Informe a posicao do aluno desejado :"; cin >> aux;

				aux = buscarAlunoNaLista(ListaAlunos, aux, Alunop);

				if (aux == 0) {
					cout << "ERROR" << endl;
				}

				if (p.n1 == 0 && p.n2 == 0)
				{
					cout << "Aluno cursando..." << endl;
				}
				else {
					cout << " Notas do aluno : " << endl << " Nota 1 - " << p.n1 << endl << "Nota 2 - " << p.n2 << endl;
					cout << " ";

					if ((p.n1 * 0.4) + (p.n2 * 0.6) >= 6) {

						cout << "Aluno APROVADO !\n";
					}
					else
					{
						cout << "Aluno REPROVADO\n";
					}
				}
				system("pause");
				break;

				// Exibir toda a lista de alunos
			case '6':

				imprimirLista(ListaAlunos);

				system("pause");
				break;

				
				//calcular a media da turma inteira
			case '7':
				aux = tamanhoDaLista(ListaAlunos);

				float nota1, nota2, somanota, mediaaluno, somaclasse = 0;
				float mediaclasse = 0;
				int i, aprovado = 0, reprovado = 0, exame = 0;

				for (i = 1; i <= aux; i++)
				{
					cout << "\n Digite a primeira nota: ";
					cin >> nota1;

					cout << "\n Digite a segunda nota: ";
					cin >> nota2;

					somanota = nota1 + nota2;
					mediaaluno = somanota / 2;

					if (mediaaluno >= 7)
					{
						cout << "\n Aprovado";
						exame++;
					}

					else

					{
						cout << "\n Reprovado";
						reprovado++;
					}

					somaclasse = somaclasse + somanota;
				}

				mediaclasse = somaclasse / (aux*2);
				cout << "\n A media da classe  foi : " << mediaclasse;
				system("pause");
				break;

			

		}


    }
}

