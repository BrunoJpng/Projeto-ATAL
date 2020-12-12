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

  ifstream file;
  file.open("src/tabelas/"+arquivo);

  if(file.fail())
    cout << "erro ao abrir o arquivo!" << endl;

  string linha, coluna;

  if (file.good()) {
    getline(file, linha);
    stringstream ss(linha);

    while(getline(ss, coluna, ';')) 
      disciplinas.push_back(Disciplina(coluna,2,2,0));
  }

  while(getline(file, linha)) {
    stringstream ss(linha);
    string coluna;
    vector<int> aptidoes;

    bool primeiraColuna = true;

    while (getline(ss, coluna, ';')) {
      if (primeiraColuna) {
        professores.push_back(Professor(coluna, 20));
        primeiraColuna = false;
      } else {
        aptidoes.push_back(stoi(coluna));
      }
    }

    matrizAptidao.push_back(aptidoes);
  }

  disciplinas.erase(disciplinas.begin());

  this -> matrizAptidao = matrizAptidao;
  this -> professores = professores;
  this -> disciplinas = disciplinas;
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