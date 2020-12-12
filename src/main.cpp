#include <iostream>
#include <vector>
#include <math.h>
#include <Professor.h>
#include <Disciplina.h>
#include <CSVReader.h>

using namespace std;

vector<Professor> professores;
vector<Disciplina> disciplinas;
int combinacoes = 0;

double desvioPadrao(vector<Professor> A) {
  double somatorio = 0, media, variancia = 0;

  for(auto a : A) 
    somatorio += a.getCargaHoraria();

  media = somatorio / A.size();

  for(auto a : A) {
    // cout << a.getCargaHoraria() << " ";
    double v = a.getCargaHoraria() - media;
    variancia += v*v;
  }

  variancia = variancia / A.size();

  return sqrt(variancia);
}

int getAptidao(vector<Professor> A, vector<vector<int>> matrizAptidao) {
  int somatorio = 0, cont = 0;

  for(auto a : A) {
    cout << a.getNome() << " ";
    somatorio += matrizAptidao[stoi(a.getNome())-1][cont];
    cont++;
  }
  cout << endl;

  return somatorio;
}

void BackTracking(vector<Professor> A, int k, vector<vector<int>> matrizAptidao) {
  if (k == disciplinas.size()){
    cout << "Aptidao: " << getAptidao(A, matrizAptidao) << endl;
    cout << "Desvio Padrao: " << desvioPadrao(A) << endl << endl;
    combinacoes++;
  } else {
    vector<Professor> candidatos;

    for(int i=0; i<professores.size(); i++)
      if (professores[i].getCargaHoraria() >= disciplinas[k].getCargaHoraria() && matrizAptidao[i][k] > 2) {
        professores[i].setCargaHoraria(professores[i].getCargaHoraria() - disciplinas[k].getCargaHoraria());
        A.push_back(professores[i]);
        
        BackTracking(A, k+1, matrizAptidao);
        
        A.pop_back();
        professores[i].setCargaHoraria(professores[i].getCargaHoraria() + disciplinas[k].getCargaHoraria());
      }
  }
}

int main(){
  vector<Professor> aux;
  CSVReader a("levantamento.csv");

  professores = a.getProfessores();
  disciplinas = a.getDisciplinas();

  BackTracking(aux,0,a.getMatriz());

  cout << combinacoes << " combinacoes" << endl;

  return 0;
}