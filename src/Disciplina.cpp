#include <Disciplina.h>
#include <string>

using namespace std;

Disciplina::Disciplina(string nome, int cargaHoraria) {
  this -> Nome = nome;
  this -> CargaHoraria = cargaHoraria;
}

string Disciplina::getNome() {
  return this -> Nome;
}

int Disciplina::getCargaHoraria() {
  return this -> CargaHoraria;
}