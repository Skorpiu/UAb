//============================================================================
// Name        : AF2.cpp
// Author      : Elizabeth (editado por Leonel Morgado)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

struct Conjunto {
		string nome;
		int nMatr;
		string curso;
		float notaM;
};

// Inserção de alunos no conjunto
void insereAlunos(struct Conjunto *a, int n){

	for (int i = 0; i < n; ++i){
		cout << "Introduza o nome do aluno:" << endl;
		cin >> a[i].nome;
		cout << "Introduza o nome do curso:" << endl;
		cin >> a[i].curso;
		cout << "Introduza o número de matrícula:" << endl;
		cin >> a[i].nMatr;
		cout << "Introduza a nota média: " << endl;
		cin >> a[i].notaM;
	}
}

// Apresenta os nomes dos alunos que frequentam o curso indicado
void apresentaAlunos(Conjunto *a, int n, string curso) {
	for (int i = 0; i < n; ++i){
		if (!curso.compare(a[i].curso)) {
			cout << "NOME: " << a[i].nome << endl;
			cout << "CURSO: " << a[i].curso << endl;
			cout << "MATRÍCULA: " << a[i].nMatr << endl;
			cout << "NOTA MÉDIA: " << a[i].notaM << endl;
		}
	}
}

// Apresenta todos os alunos
void apresentaAlunos(struct Conjunto *a, int n) {
	for (int i = 0; i < n; ++i){
		cout << "NOME: " << a[i].nome << endl;
		cout << "CURSO: " << a[i].curso << endl;
		cout << "MATRICULA: " << a[i].nMatr << endl;
		cout << "NOTA MÉDIA: " << a[i].notaM << endl;
	}
}

// Ordena os alunos pelo número de matrícula segundo o algoritmo Bubble Sort
void ordenaAlunos (struct Conjunto *a, int n) {
	int i, j;
	struct Conjunto swap;

	for (i = 0 ; i < ( n - 1 ); i++)
	  {
	    for (j = 0 ; j < n - i - 1; j++)
	    {
	      if ((a+j)->nMatr > (a+j+1)->nMatr)
	      {
	        swap = *(a+j);
	        *(a+j) = *(a+j+1);
	        *(a+j+1) = swap;
	      }
	    }
	  }
}

// Apresenta as notas máxima e mínima do conjunto de alunos
void apresentaMaxMin(Conjunto *a, int n) {
	float maior = 0, menor = 20;

	for (int i = 0; i < n; ++i) {
		if (a[i].notaM < menor) menor = a[i].notaM;
		if (a[i].notaM > maior) maior = a[i].notaM;
	}

	cout << "MAIOR NOTA: " << maior << endl;
	cout << "MENOR NOTA: " << menor << endl;
}
// Calcula a média global do conjunto de alunos
float calculaMediaGlobal(struct Conjunto *a, int n){
	float media = 0;

	for (int i = 0; i < n; ++i)	media = media + a[i].notaM;

	return (media/n);
}

int main() {

	int n;

	cout << "               **AF2**" << endl;
	cout << "Quantos alunos vai introduzir no conjunto? " << endl;
	cin >> n;
	struct Conjunto alunos[n];
	cout << "//////////////////////////////////////" << endl;
	insereAlunos(alunos, n);
	ordenaAlunos(alunos, n);
	cout << "//////////////////////////////////////" << endl;
	apresentaAlunos(alunos, n);
	cout << "//////////////////////////////////////" << endl;
	apresentaAlunos(alunos, n, "medicina");
	cout << "//////////////////////////////////////" << endl;
	cout << "Média Global: " << calculaMediaGlobal(alunos, n) << endl;
	cout << "//////////////////////////////////////" << endl;
	apresentaMaxMin(alunos, n);

	return 0;
}
