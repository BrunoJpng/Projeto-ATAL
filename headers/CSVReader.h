#ifndef CSVREADER_H
#define CSVREADER_H

#include <Professor.h>
#include <Disciplina.h>
#include <string>
#include <vector>

using namespace std;

class CSVReader {
  vector<vector<int>> matrizAptidao;
  vector<Professor> professores;
  vector<Disciplina> disciplinas;

  public:
    CSVReader(string arquivo);
    
    vector<vector<int>> getMatriz();
    vector<Professor> getProfessores();
    vector<Disciplina> getDisciplinas();
};

#endif /*CSVREADER_H*/