#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "endereco.hpp"

class Pessoa{
    private:
        std::string nome;
        std::string cpf;
        std::string dataNascimento;
        std::string genero;
        Endereco *endereco;
    public:
        Pessoa();
        Pessoa(std::string nome, std::string cpf, std::string dataNascimento,
                std::string genero, std::string rua, int numero, std::string bairro,
                std::string cidade, std::string cep);
        std::string getNome();
        std::string getCpf();
        std::string getDataNascimento();
        std::string getGenero();
        Endereco* getEndereco();
        void setNome(std::string nome);
        void setCpf(std::string cpf);
        void setDataNascimento(std::string dataNascimento);
        void setGenero(std::string genero);
        void setEndereco(std::string rua, int numero, std::string bairro,
                    std::string cidade, std::string cep);

};



#endif