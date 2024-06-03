#include <iostream>
#include "professor.hpp"

using namespace std;

Professor::Professor(){}

Professor::Professor(int formacaoProfessor, int nivelProfessor, string disciplina,
            string matricula, float salario, string departamento, int cargaHoraria,
            string dataIngresso, string nome, string cpf, string dataNascimento,
            string genero, string rua, int numero, string bairro, string cidade,
            string cep) : Funcionario(matricula, salario, departamento, cargaHoraria, dataIngresso),
            Pessoa(nome, cpf, dataNascimento, genero, rua, numero, bairro, cidade, cep){

    if(nivelProfessor == 0){
        this->nivelProfessor = I;
    }else if(nivelProfessor == 1){
        this->nivelProfessor = II;
    }else if(nivelProfessor == 2){
        this->nivelProfessor = III;
    }else if(nivelProfessor == 3){
        this->nivelProfessor = IV;
    }else if(nivelProfessor == 4){
        this->nivelProfessor = V;
    }else if(nivelProfessor == 5){
        this->nivelProfessor = VI;
    }else if(nivelProfessor == 6){
        this->nivelProfessor = VII;
    }else if(nivelProfessor == 7){
        this->nivelProfessor = VIII;
    }

    if(formacaoProfessor == 0){
        this->formacaoProfessor = ESPECIALIZACAO;
    }else if(formacaoProfessor == 1){
        this->formacaoProfessor = MESTRADO;
    }else if(formacaoProfessor == 2){
        this->formacaoProfessor = DOUTORADO;
    }

    this->disciplina = disciplina;
}

Professor::Nivel Professor::getNivelProfessor(){
    return nivelProfessor;
}

Professor::Formacao Professor::getFormacaoProfessor(){
    return formacaoProfessor;
}

string Professor::getDisciplina(){
    return disciplina;
}

void Professor::setFormacaoProfessor(Formacao formacaoProfessor){
    this->formacaoProfessor = formacaoProfessor;
}

void Professor::setNivelProfessor(Nivel nivelProfessor){
    this->nivelProfessor = nivelProfessor;
}

void Professor::setDisciplina(string disciplina){
    this->disciplina = disciplina;
}