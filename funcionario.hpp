#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>

class Funcionario{
    private:
        std::string matricula;
        float salario;
        std::string departamento;
        int cargaHoraria;
        std::string dataIngresso;
    public:
        Funcionario();
        Funcionario(std::string matricula, float salario, std::string departamento,
                int cargaHoraria, std::string dataIngresso);
        std::string getMatricula();
        float getSalario();
        std::string getDepartamento();
        int getCargaHoraria();
        std::string getDataIngresso();
        void setMatricula(std::string matricula);
        void setSalario(float salario);
        void setDepartamento(std::string departamento);
        void setCargaHoraria(int cargaHoraria);
        void setDataIngresso(std::string dataIngresso);
};



#endif