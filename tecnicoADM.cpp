#include <iostream>
#include "tecnicoADM.hpp"

using namespace std;

TecnicoADM::TecnicoADM(){}

TecnicoADM::TecnicoADM(string funcaoDesempenhada, string matricula, float salario,
            string departamento, int cargaHoraria, string dataIngresso, string nome,
            string cpf, string dataNascimento, string genero, string rua, int numero,
            string bairro, string cidade, string cep) :
            Funcionario(matricula, salario, departamento, cargaHoraria, dataIngresso),
            Pessoa(nome, cpf, dataNascimento, genero, rua, numero, bairro, cidade, cep){

    this->adicionalProdutividade = adicionalProdutividade;
    this->funcaoDesempenhada = funcaoDesempenhada;
}

float TecnicoADM::getAdicionalProdutividade(){
    return adicionalProdutividade;
}

string TecnicoADM::getFuncaoDesempenhada(){
    return funcaoDesempenhada;
}

void TecnicoADM::setAdicionalProdutividade(float adicionalProdutividade){
    this->adicionalProdutividade = adicionalProdutividade;
}

void TecnicoADM::setFuncaoDesempenhada(string funcaoDesempenhada){
    this->funcaoDesempenhada = funcaoDesempenhada;
}
