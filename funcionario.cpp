#include <iostream>

#include "funcionario.hpp"

using namespace std;

Funcionario::Funcionario(){}

Funcionario::Funcionario(string matricula, float salario, string departamento,
                    int cargaHoraria, string dataIngresso){
    this->matricula = matricula;
    this->salario = salario;
    this->departamento = departamento;
    this->cargaHoraria = cargaHoraria;
    this->dataIngresso = dataIngresso;
}

string Funcionario::getMatricula(){
    return matricula;
}

float Funcionario::getSalario(){
    return salario;
}

string Funcionario::getDepartamento(){
    return departamento;
}

int Funcionario::getCargaHoraria(){
    return cargaHoraria;
}

string Funcionario::getDataIngresso(){
    return dataIngresso;
}

void Funcionario::setMatricula(string matricula){
    this->matricula = matricula;
}

void Funcionario::setSalario(float salario){
    this->salario = salario;
}

void Funcionario::setDepartamento(string departamento){
    this->departamento = departamento;
}

void Funcionario::setCargaHoraria(int cargaHoraria){
    this->cargaHoraria = cargaHoraria;
}

void Funcionario::setDataIngresso(string dataIngresso){
    this->dataIngresso = dataIngresso;
}
