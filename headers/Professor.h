#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <unordered_map>

using namespace std;

class Professor {
  private:
    string Nome;
    int CargaHoraria;
    // bool CargoGestao;
    // bool CargoDirecao;
    // unordered_map<string, int> aptidao;

  public:
    Professor(string Nome, int CargaHoraria);
    // ~Professor();

    // void setId(int id);
    string getNome();

    void setCargaHoraria(int CargaHoraria);
    int getCargaHoraria();

    // void setCargoGestao(bool CargoGestao);
    // bool getCargoGestao();

    // void setCargoDirecao(bool CargoDirecao);
    // bool getCargoDirecao();

    // void setAptidao(string disciplina, int peso);
    // int getAptidao(string disciplina);
};

#endif /* PROFESSOR_H */