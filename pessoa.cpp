#include <iostream>
#include "pessoa.hpp"

using namespace std;

Pessoa::Pessoa(){ }

Pessoa::Pessoa(string nome, string cpf, string dataNascimento, string genero,
            string rua, int numero, string bairro, string cidade, string cep){
    this->nome = nome;
    this->cpf  = cpf;
    this->dataNascimento = dataNascimento;
    this->genero = genero;
    this->endereco = new Endereco(rua, numero, bairro, cidade, cep);
}

string Pessoa::getNome(){
    return this->nome;
}
string Pessoa::getCpf(){
    return this->cpf;
}
string Pessoa::getDataNascimento(){
    return this->dataNascimento;
}
string Pessoa::getGenero(){
    return this->genero;
}
Endereco* Pessoa::getEndereco(){
    return this->endereco;
}
void Pessoa::setNome(string nome){
    this->nome = nome;
}
void Pessoa::setCpf(string cpf){
    this->cpf = cpf;
}
void Pessoa::setDataNascimento(string dataNascimento){
    this->dataNascimento = dataNascimento;
}
void Pessoa::setGenero(string genero){
    this->genero = genero;
}
void Pessoa::setEndereco(string rua, int numero, string bairro, string cidade, string cep){
    this->endereco->setRua(rua);
    this->endereco->setNumero(numero);
    this->endereco->setBairro(bairro);
    this->endereco->setCidade(cidade);
    this->endereco->setCep(cep);
}

