#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

using namespace std;

class Disciplina {
  private:
    string Nome;
    int CargaHoraria;

  public:
    Disciplina(string nome, int Chsala, int CHpreparacao, int CHacompanhamento);
    string getNome();
    int getCargaHoraria();
};

#endif /*DISCIPLINA_H*/