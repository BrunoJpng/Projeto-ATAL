#include <Disciplina.h>

Disciplina::Disciplina(string nome, int chSala, int chPreparacao, int chAcompanhamento) {
  this -> Nome = nome;
  this -> CargaHoraria = chSala + chPreparacao + chAcompanhamento;
}

string Disciplina::getNome() {
  return this -> Nome;
}

int Disciplina::getCargaHoraria() {
  return this -> CargaHoraria;
}