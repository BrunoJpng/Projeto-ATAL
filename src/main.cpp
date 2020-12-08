#include <iostream>
#include <vector>

#include <Professor.h>
#include <Disciplina.h>

using namespace std;

void alocaProfessor(vector<Professor> professores, vector<Disciplina> disciplinas, int k) {
  if (k == professores.size())
    return;

  cout << disciplinas[k].getNome() << endl;

  for(auto professor : professores) 
    cout << professor.getNome() << " " << professor.getAptidao(disciplinas[k].getNome()) << endl;

  cout << endl;

  alocaProfessor(professores, disciplinas, k+1);
}

int main(){
  vector<Professor> professores;
  vector<Disciplina> disciplinas;

  Disciplina d1("POO", 6), 
             d2("Falar merda", 4), 
             d3("ATAL", 6);

  disciplinas.push_back(d1);
  disciplinas.push_back(d2);
  disciplinas.push_back(d3);

  Professor p1, p2, p3;
  p1.setNome("Ruan");
  p1.setAptidao(d1.getNome(), 3);
  p1.setAptidao(d2.getNome(), 0);
  p1.setAptidao(d3.getNome(), 5);

  p2.setNome("Katy");
  p2.setAptidao(d1.getNome(), 5);
  p2.setAptidao(d2.getNome(), 2);
  p2.setAptidao(d3.getNome(), 2);

  p3.setNome("George");
  p3.setAptidao(d1.getNome(), 0);
  p3.setAptidao(d2.getNome(), 5);
  p3.setAptidao(d3.getNome(), 0);

  professores.push_back(p1);
  professores.push_back(p2);
  professores.push_back(p3);

  alocaProfessor(professores, disciplinas, 0);

  return 0;
}