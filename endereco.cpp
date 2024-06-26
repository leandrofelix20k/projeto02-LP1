#include <iostream>

#include "endereco.hpp"

using namespace std;

Endereco::Endereco(){}

Endereco::Endereco(std::string rua, int numero, std::string bairro,
                std::string cidade, std::string cep){
    this->rua = rua;
    this->numero = numero;
    this->bairro = bairro;
    this->cidade = cidade;
    this->cep = cep;
}

string Endereco::getRua(){
    return rua;
}

int Endereco::getNumero(){
    return numero;
}

string Endereco::getBairro(){
    return bairro;
}

string Endereco::getCidade(){
    return cidade;
}

string Endereco::getCep(){
    return cep;
}

void Endereco::setRua(string rua){
    this->rua = rua;
}

void Endereco::setNumero(int numero){
    this->numero = numero;
}

void Endereco::setBairro(string bairro){
    this->bairro = bairro;
}

void Endereco::setCidade(string cidade){
    this->cidade = cidade;
}

void Endereco::setCep(string cep){
    this->cep = cep;
}
