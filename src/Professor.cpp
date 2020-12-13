#include <Professor.h>

Professor::Professor(string Nome, int CargaHoraria) {
  this -> Nome = Nome;
  this -> CargaHoraria = CargaHoraria;
}

string Professor::getNome() {
  return this -> Nome;
}

void Professor::setCargaHoraria(int CargaHoraria) {
  this -> CargaHoraria = CargaHoraria;
}

int Professor::getCargaHoraria() {
  return this -> CargaHoraria;
}