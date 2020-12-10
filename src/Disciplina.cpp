#include <Disciplina.h>
#include <string>

using namespace std;

Disciplina::Disciplina(string nome, int CHsala, int CHpreparacao, int CHacompanhamento) {
  this -> Nome = nome;
  this -> CargaHoraria = CHsala + CHpreparacao + CHacompanhamento;
}

string Disciplina::getNome() {
  return this -> Nome;
}

int Disciplina::getCargaHoraria() {
  return this -> CargaHoraria;
}