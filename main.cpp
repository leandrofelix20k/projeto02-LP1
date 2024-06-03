#include <iostream>

#include "bancodao.hpp"

using namespace std;

int main(){

    BancoDao bancoDao;
    int opcao;

    // Ler os arquivos dos professores e tecnicos
    bancoDao.lerArquivo("professores");
    bancoDao.lerArquivo("tecnicos");

    cout << "-------------------------" << endl;
    cout << "-----Sistema IMDCorp-----" << endl;
    cout << "-------------------------" << endl;

    do{
        bancoDao.menuBancoDao(); // Menu do sistema
        cin >> opcao;


        switch(opcao){
            case 1:
                bancoDao.cadastrarProfessor();
                break;
            case 2:
                bancoDao.cadastrarTecnicoADM();
                break;
            case 3:
                bancoDao.listarProfessores();
                break;
            case 4:
                bancoDao.listarTecnicosADM();
                break;
            case 5:
                bancoDao.deletarProfessor();
                break;
            case 6:
                bancoDao.deletarTecnicoADM();
                break;
            case 7:
                bancoDao.buscarProfessor();
                break;
            case 8:
                bancoDao.buscarTecnicoADM();
                break;
            case 9:
                cout << "\n---Encerrando Sistema---" << endl;
                bancoDao.atualizarArquivo("funcionarios");
                bancoDao.atualizarArquivo("professores");
                bancoDao.atualizarArquivo("tecnicos");
                break;
            default:
                cout << "\n---Opcao invalida!---\n" << endl;
                break;
        }
    }while(opcao != 9); // Enquanto a opção for diferente de 9, o sistema continua rodando

    return 0;
}