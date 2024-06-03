#ifndef BANCODAO_HPP
#define BANCODAO_HPP

#include <iostream>
#include <vector>
#include <fstream>

#include "professor.hpp"
#include "tecnicoADM.hpp"

class BancoDao : public Professor, public TecnicoADM{
    private:
        std::vector<Professor> professores;
        std::vector<TecnicoADM> tecnicosADM;
    public:
        BancoDao();
        void menuBancoDao();
        void lerArquivo(std::string nomeArquivo);
        void atualizarArquivo(std::string nomeArquivo);
        void cadastrarProfessor();
        void cadastrarTecnicoADM();
        void listarProfessores();
        void listarTecnicosADM();
        void deletarProfessor();
        void deletarTecnicoADM();
        void buscarProfessor();
        void buscarTecnicoADM();
};

#endif