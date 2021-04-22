#define Limite 8

struct Aluno
{
	char nome[30];
	int matricula;
	int idade;
	float n1, n2;
	float media;
	char situacao;
};

struct List;

List* criaLista();

int listaCheia(List* Pont);

int listaVazia(List* Pont);

int inserirAlunoNovo(List *Pont, Aluno aluno);

int removeAluno(List* Pont, float matAluno);

int buscarAlunoNaLista(List* Pont, int al, Aluno *aluno);

void liberarLista(List* Pont);

int tamanhoDaLista(List* Pont);

int situacaoDoAluno(List* Pont, int al, Aluno* aluno);

//int MediaDaTurma(List* Pont, int al, Aluno* aluno);