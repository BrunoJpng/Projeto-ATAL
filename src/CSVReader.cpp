#include <CSVReader.h>
#include <Professor.h>
#include <Disciplina.h>

#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;

CSVReader::CSVReader(string arquivo) {
  vector<Professor> professores;
  vector<Disciplina> disciplinas;
  vector<vector<int>> matrizAptidao;

  ifstream file, chDisciplina, chProfessor;
  file.open("src/tabelas/" + arquivo);
  chDisciplina.open("src/tabelas/chDisciplinas.csv");
  chProfessor.open("src/tabelas/chProfessores.csv");

  if(file.fail() || chDisciplina.fail() || chProfessor.fail())
    cout << "erro ao abrir o arquivo!" << endl;

  string linha, coluna;

  while(getline(chDisciplina, linha)) {
    stringstream ss(linha);

    getline(ss, coluna, ';');
    string nome = coluna;
    
    getline(ss, coluna, ';');
    int chSala = stoi(coluna);

    getline(ss, coluna, ';');
    int chPreparacao = stoi(coluna);

    getline(ss, coluna, ';');
    int chAcompanhamento = stoi(coluna);

    disciplinas.push_back(Disciplina(nome, chSala, chPreparacao, chAcompanhamento));
  }

  while(getline(chProfessor, linha)) {
    stringstream ss(linha);

    getline(ss, coluna, ';');
    string nome = coluna;

    getline(ss, coluna, ';');
    int ch = stoi(coluna);

    professores.push_back(Professor(nome, ch));
  }

  getline(file, linha);

  while(getline(file, linha)) {
    stringstream ss(linha);
    string coluna;
    vector<int> aptidoes;

    bool primeiraColuna = true;

    while (getline(ss, coluna, ';')) {
      if (primeiraColuna) {
        primeiraColuna = false;
      } else {
        aptidoes.push_back(stoi(coluna));
      }
    }

    matrizAptidao.push_back(aptidoes);
  }

  this -> matrizAptidao = matrizAptidao;
  this -> professores = professores;
  this -> disciplinas = disciplinas;

  file.close();
  chDisciplina.close();
  chProfessor.close();
}

vector<vector<int>> CSVReader::getMatriz() {
  return this -> matrizAptidao;
}

vector<Professor> CSVReader::getProfessores() {
  return this -> professores;
}

vector<Disciplina> CSVReader::getDisciplinas() {
  return this -> disciplinas;
}