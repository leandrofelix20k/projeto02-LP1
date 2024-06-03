#ifndef Professor_HPP
#define Professor_HPP
#include <iostream>
#include "funcionario.hpp"
#include "pessoa.hpp"

class Professor : public Funcionario, public Pessoa{
    private:
        enum Nivel{I, II, III, IV, V, VI, VII, VIII};
        enum Formacao{ESPECIALIZACAO, MESTRADO, DOUTORADO};
        Nivel nivelProfessor;
        Formacao formacaoProfessor;
        std::string disciplina;
    public:
        Professor();
        Professor(int formacaoProfessor, int nivelProfessor, std::string disciplina,
                std::string matricula, float salario, std::string departamento,
                int cargaHoraria, std::string dataIngresso, std::string nome,
                std::string cpf, std::string dataNascimento, std::string genero,
                std::string rua, int numero, std::string bairro, std::string cidade,
                std::string cep);
        Nivel getNivelProfessor();
        Formacao getFormacaoProfessor();
        std::string getDisciplina();
        void setFormacaoProfessor(Formacao formacaoProfessor);
        void setNivelProfessor(Nivel nivelProfessor);
        void setDisciplina(std::string disciplina);
};




#endif