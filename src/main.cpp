#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <Professor.h>
#include <Disciplina.h>
#include <CSVReader.h>

using namespace std;

struct resultado {
  vector<Professor> alocacao;
  double desvioPadrao, aptidaoMedia;
};

vector<Professor> professores;
vector<Disciplina> disciplinas;
vector<resultado> resultados;

int combinacoes = 0;
Professor nulo("Vazio",-1);

bool cmpAptidao(const resultado &a, const resultado &b) {
  return (b.aptidaoMedia/b.desvioPadrao) < (a.aptidaoMedia/a.desvioPadrao);
}

double desvioPadrao() {
  double somatorio = 0, media, variancia = 0;

  for(auto p : professores) 
    somatorio += p.getCargaHoraria();

  media = somatorio / professores.size();

  for(auto p : professores) {
    double v = p.getCargaHoraria() - media;
    variancia += v*v;
  }

  variancia = variancia / professores.size();

  return sqrt(variancia);
}

double aptidaoMedia(vector<Professor> A, vector<vector<int>> matrizAptidao) {
  double somatorio = 0, cont = 0;

  for(auto a : A) {
    if(a.getNome() != "Vazio") {
      somatorio += matrizAptidao[stoi(a.getNome())-1][cont];
      cont++;
    }
  }

  return somatorio / A.size();
}

void BackTracking(vector<Professor> A, int k, vector<vector<int>> matrizAptidao) {
  if (k == disciplinas.size()){
    resultado tmp;
    tmp.alocacao = A;
    tmp.aptidaoMedia = aptidaoMedia(A, matrizAptidao);
    tmp.desvioPadrao = desvioPadrao();

    resultados.push_back(tmp);

    combinacoes++;
  } else {
    int cont = 0;

    for(int i=0; i<professores.size(); i++)
      if (professores[i].getCargaHoraria() >= disciplinas[k].getCargaHoraria() && matrizAptidao[i][k] > 2) {
        cont++;

        professores[i].setCargaHoraria(professores[i].getCargaHoraria() - disciplinas[k].getCargaHoraria());
        A.push_back(professores[i]);
        
        BackTracking(A, k+1, matrizAptidao);
        
        A.pop_back();
        professores[i].setCargaHoraria(professores[i].getCargaHoraria() + disciplinas[k].getCargaHoraria());
      }

    if(cont == 0) {
      A.push_back(nulo);
      BackTracking(A, k+1, matrizAptidao);
    }
  }
}

int main(){
  vector<Professor> aux;
  CSVReader a("teste.csv");

  professores = a.getProfessores();
  disciplinas = a.getDisciplinas();

  BackTracking(aux,0,a.getMatriz());

  cout << combinacoes << " combinacoes" << endl;

  sort(resultados.begin(), resultados.end(), cmpAptidao);

  for(int i=0; i < 10 && i < resultados.size(); i++) {
    cout << "Aptidao: " << resultados[i].aptidaoMedia << " Desvio padrao: " << resultados[i].desvioPadrao << endl;
    
    for(int j=0; j < resultados[i].alocacao.size(); j++) {
      cout << disciplinas[j].getNome();
      
      if (resultados[i].alocacao[j].getNome() == "Vazio")
        cout << " Sem professor." << endl;
      else 
        cout << " Professor: " << resultados[i].alocacao[j].getNome() << endl;
    }

    cout << endl;
  }

  return 0;
}