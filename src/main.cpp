#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include <Professor.h>
#include <Disciplina.h>

using namespace std;

int main(){
  vector<Professor> professores;
  vector<string> disciplinas;

  ifstream arquivo;
  arquivo.open("src/tabela.csv");

  if(arquivo.fail())
    cout << "erro ao abrir o arquivo!" << endl;

  string linha, coluna;

  if (arquivo.good()) {
    getline(arquivo, linha);
    stringstream ss(linha);

    while(getline(ss, coluna, ',')) 
      disciplinas.push_back(coluna);
  }

  while(getline(arquivo, linha)) {
    stringstream ss(linha);
    string data;

    int colunaId = 0;

    Professor p;

    while (getline(ss, data, ',')) {
      if (!colunaId) {
        p.setNome(data.c_str());
      } else {
        cout << disciplinas[colunaId] << ", " << endl;
        p.setAptidao(disciplinas[colunaId], atoi(data.c_str()));
      }
      colunaId++;
    }

    professores.push_back(p);
  }

  disciplinas.erase(disciplinas.begin());

  for(auto d : disciplinas) {
    cout << d << endl;
    for(auto p : professores) {
      cout << p.getNome() << ", " << p.getAptidao(d) << endl;
    }
    cout << endl;
  }

  return 0;
}