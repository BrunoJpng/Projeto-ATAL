#include <Professor.h>

Professor::Professor(string Nome, int CargaHoraria) {
  this -> Nome = Nome;
  this -> CargaHoraria = CargaHoraria;
}

// Professor::~Professor() {}

// void Professor::setId(int id) {
//   this -> id = id;
// }

string Professor::getNome() {
  return this -> Nome;
}

void Professor::setCargaHoraria(int CargaHoraria) {
  this -> CargaHoraria = CargaHoraria;
}

int Professor::getCargaHoraria() {
  return this -> CargaHoraria;
}

// void Professor::setCargoGestao(bool CargoGestao) {
//   if (this -> CargoDirecao)
//     setCargoDirecao(false);

//   if (CargoGestao)
//     setCargaHoraria(12);

//   this -> CargoGestao = CargoGestao;
// }

// bool Professor::getCargoGestao() {
//   return this -> CargoGestao;
// }

// void Professor::setCargoDirecao(bool CargoDirecao) {
//   if (this -> CargoGestao)
//     setCargoGestao(false);

//   if (CargoDirecao)
//     setCargaHoraria(0);

//   this -> CargoDirecao = CargoDirecao;
// }

// bool Professor::getCargoDirecao() {
//   return this -> CargoDirecao;
// }

// void Professor::setAptidao(string disciplina, int peso) {
//   this -> aptidao[disciplina] = peso;
// }

// int Professor::getAptidao(string disciplina) {
//   return this -> aptidao[disciplina];
// }