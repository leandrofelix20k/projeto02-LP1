#include <iostream>
#include <vector>
#include <fstream>

#include "bancodao.hpp"

using namespace std;

BancoDao::BancoDao(){}

void BancoDao::menuBancoDao(){ // Menu do sistema
    cout << "1- Cadastrar Professor" << endl;
    cout << "2- Cadastrar Tecnico Administrativo" << endl;
    cout << "3- Listar Professores" << endl;
    cout << "4- Listar Tecnicos Administrativos" << endl;
    cout << "5- Remover Professor" << endl;
    cout << "6- Remover Tecnico Administrativo" << endl;
    cout << "7- Buscar Professor" << endl;
    cout << "8- Buscar Tecnico Administrativo" << endl;
    cout << "9- Sair" << endl;
    cout << "Opcao: ";
}

void BancoDao::lerArquivo(string nomeArquivo){ // Ler os arquivos dos funcionarios, professores e armazena os dados em um vetor de objetos
    string nome, cpf, dataNascimento, genero, rua, bairro, cidade, cep, matricula, funcaoDesempenhada, departamento, dataIngresso, disciplina;
    int numero, cargaHoraria, nivelProfessor, formacaoProfessor;
    float salario;
    vector<string> linhas; // Vetor de strings para armazenar as linhas do arquivo
    fstream arquivo;

    arquivo.open(nomeArquivo + ".txt", ios::in | ios::app);

    if(arquivo.is_open()){ // Se o arquivo estiver aberto, armazena as linhas do arquivo no vetor de strings
        string linha;

        while(getline(arquivo, linha)){
            linhas.push_back(linha);
        }

        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }

    for(int i=0; i<linhas.size(); i+=15){ // Percorre o vetor de strings e armazena os dados nas variaveis, ao terminar, armazena os dados no vetor de objetos
        nome = linhas[i];
        cpf = linhas[i+1];
        dataNascimento = linhas[i+2];
        genero = linhas[i+3];
        rua = linhas[i+4];
        numero = (stoi(linhas[i+5]));
        bairro = linhas[i+6];
        cidade = linhas[i+7];
        cep = linhas[i+8];
        matricula = linhas[i+9];
        salario = stof(linhas[i+10]);
        departamento = linhas[i+11];
        cargaHoraria = stoi(linhas[i+12]);
        dataIngresso = linhas[i+13];
        if(nomeArquivo == "professores"){ // Se o nome do arquivo for professores, armazena os dados em um vetor de objetos do tipo Professor. Além de ler os dados que correspondem a classe Professor, lê os dados que correspondem a classe Funcionario e Pessoa
            nivelProfessor = stoi(linhas[i+14]);
            formacaoProfessor = stoi(linhas[i+15]);
            disciplina = linhas[i+16];
            professores.push_back(Professor(formacaoProfessor, nivelProfessor, disciplina, matricula, salario, departamento, cargaHoraria, dataIngresso, nome, cpf, dataNascimento, genero, rua, numero, bairro, cidade, cep));
            i+=3;
        }else if(nomeArquivo == "tecnicos"){ // Se o nome do arquivo for tecnicos, armazena os dados em um vetor de objetos do tipo TecnicoADM. Além de ler os dados que correspondem a classe TecnicoADM, lê os dados que correspondem a classe Funcionario e Pessoa
            funcaoDesempenhada = linhas[i+14];
            tecnicosADM.push_back(TecnicoADM(funcaoDesempenhada, matricula, salario, departamento, cargaHoraria, dataIngresso, nome, cpf, dataNascimento, genero, rua, numero, bairro, cidade, cep));
            i++;
        }
    }
}

void BancoDao::atualizarArquivo(string nomeArquivo){ // Atualiza os arquivos dos funcionarios, professores e tecnicos
    fstream arquivo;

    arquivo.open(nomeArquivo + ".txt", ios::out);

    if(arquivo.is_open()){
        if(nomeArquivo == "professores"){ //Armazena os dados do vetor de acordo com o nome do arquivo
            for(int i=0; i<professores.size(); i++){
                arquivo << professores[i].getNome() << endl;
                arquivo << professores[i].getCpf() << endl;
                arquivo << professores[i].getDataNascimento() << endl;
                arquivo << professores[i].getGenero() << endl;
                arquivo << professores[i].getEndereco()->getRua() << endl;
                arquivo << professores[i].getEndereco()->getNumero() << endl;
                arquivo << professores[i].getEndereco()->getBairro() << endl;
                arquivo << professores[i].getEndereco()->getCidade() << endl;
                arquivo << professores[i].getEndereco()->getCep() << endl;
                arquivo << professores[i].getMatricula() << endl;
                arquivo << professores[i].getSalario() << endl;
                arquivo << professores[i].getDepartamento() << endl;
                arquivo << professores[i].getCargaHoraria() << endl;
                arquivo << professores[i].getDataIngresso() << endl;
                arquivo << professores[i].getNivelProfessor() << endl;
                arquivo << professores[i].getFormacaoProfessor() << endl;
                arquivo << professores[i].getDisciplina() << endl;
                arquivo << endl;
            }
        } else if(nomeArquivo == "tecnicos"){
            for(int i=0; i<tecnicosADM.size(); i++){
                arquivo << tecnicosADM[i].getNome() << endl;
                arquivo << tecnicosADM[i].getCpf() << endl;
                arquivo << tecnicosADM[i].getDataNascimento() << endl;
                arquivo << tecnicosADM[i].getGenero() << endl;
                arquivo << tecnicosADM[i].getEndereco()->getRua() << endl;
                arquivo << tecnicosADM[i].getEndereco()->getNumero() << endl;
                arquivo << tecnicosADM[i].getEndereco()->getBairro() << endl;
                arquivo << tecnicosADM[i].getEndereco()->getCidade() << endl;
                arquivo << tecnicosADM[i].getEndereco()->getCep() << endl;
                arquivo << tecnicosADM[i].getMatricula() << endl;
                arquivo << tecnicosADM[i].getSalario() << endl;
                arquivo << tecnicosADM[i].getDepartamento() << endl;
                arquivo << tecnicosADM[i].getCargaHoraria() << endl;
                arquivo << tecnicosADM[i].getDataIngresso() << endl;
                arquivo << tecnicosADM[i].getFuncaoDesempenhada() << endl;
                arquivo << endl;
            }
        } else if(nomeArquivo == "funcionarios"){ // Faz a junção dos dados dos vetores de objetos do tipo Professor e TecnicoADM
            arquivo << "-----------------------" << endl;
            arquivo << "-----Funcionarios------" << endl;
            arquivo << "-----------------------" << endl;
            arquivo << "---Professores---" << endl;
            for(int i=0; i<professores.size(); i++){
                arquivo << "Professor N°" << i+1 << endl;
                arquivo << "Nome: " << professores[i].getNome() << endl;
                arquivo << "CPF: " << professores[i].getCpf() << endl;
                arquivo << "Data de Nascimento: " << professores[i].getDataNascimento() << endl;
                arquivo << "Genero: " << professores[i].getGenero() << endl;
                arquivo << "Rua: " << professores[i].getEndereco()->getRua() << endl;
                arquivo << "Numero: " << professores[i].getEndereco()->getNumero() << endl;
                arquivo << "Bairro: " << professores[i].getEndereco()->getBairro() << endl;
                arquivo << "Cidade: " << professores[i].getEndereco()->getCidade() << endl;
                arquivo << "CEP: " << professores[i].getEndereco()->getCep() << endl;
                arquivo << "Matricula: " << professores[i].getMatricula() << endl;
                arquivo << "Salario: " << professores[i].getSalario() << endl;
                arquivo << "Departamento: " << professores[i].getDepartamento() << endl;
                arquivo << "Carga Horaria: " << professores[i].getCargaHoraria() << endl;
                arquivo << "Data de Ingresso: " << professores[i].getDataIngresso() << endl;
                arquivo << "Nivel: " << professores[i].getNivelProfessor() << endl;
                arquivo << "Formacao: " << professores[i].getFormacaoProfessor() << endl;
                arquivo << "Disciplina: " << professores[i].getDisciplina() << endl;
                arquivo << "--------------------------------------------------------" << endl;
                arquivo << endl;
            }
            arquivo << "---Tecnicos Administrativos---" << endl;
            for(int i=0; i<tecnicosADM.size(); i++){
                arquivo << "Tecnico N°" << i+1 << endl;
                arquivo << "Nome: " << tecnicosADM[i].getNome() << endl;
                arquivo << "CPF: " << tecnicosADM[i].getCpf() << endl;
                arquivo << "Data de Nascimento: " << tecnicosADM[i].getDataNascimento() << endl;
                arquivo << "Genero: " << tecnicosADM[i].getGenero() << endl;
                arquivo << "Rua: " << tecnicosADM[i].getEndereco()->getRua() << endl;
                arquivo << "Numero: " << tecnicosADM[i].getEndereco()->getNumero() << endl;
                arquivo << "Bairro: " << tecnicosADM[i].getEndereco()->getBairro() << endl;
                arquivo << "Cidade: " << tecnicosADM[i].getEndereco()->getCidade() << endl;
                arquivo << "CEP: " << tecnicosADM[i].getEndereco()->getCep() << endl;
                arquivo << "Matricula: " << tecnicosADM[i].getMatricula() << endl;
                arquivo << "Salario: " << tecnicosADM[i].getSalario() << endl;
                arquivo << "Funcao Desempenhada: " << tecnicosADM[i].getFuncaoDesempenhada() << endl;
                arquivo << "Departamento: " << tecnicosADM[i].getDepartamento() << endl;
                arquivo << "Carga Horaria: " << tecnicosADM[i].getCargaHoraria() << endl;
                arquivo << "Data de Ingresso: " << tecnicosADM[i].getDataIngresso() << endl;
                arquivo << "--------------------------------------------------------" << endl;
                arquivo << endl;
            }
        }
        arquivo.close();

    } else {
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }
}

void BancoDao::cadastrarProfessor(){
    string nome, cpf, dataNascimento, genero, rua, bairro, cidade, cep, matricula, departamento, dataIngresso, disciplina;
    int numero, cargaHoraria, nivelProfessor, formacaoProfessor;
    float salario;

    // Lê todos os dados correspondentes a classe Professor
    system("clear || cls");
    cout << "---Cadastro de Professor---" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Data de Nascimento: ";
    getline(cin, dataNascimento);
    cout << "Genero: ";
    getline(cin, genero);
    cout << "Rua: ";
    getline(cin, rua);
    cout << "Numero: ";
    cin >> numero;
    cout << "Bairro: ";
    cin.ignore();
    getline(cin, bairro);
    cout << "Cidade: ";
    getline(cin, cidade);
    cout << "CEP: ";
    getline(cin, cep);
    cout << "Matricula: ";
    getline(cin, matricula);
    cout << "Salario: ";
    cin >> salario;
    cout << "Departamento: ";
    cin.ignore();
    getline(cin, departamento);
    cout << "Carga Horaria: ";
    cin >> cargaHoraria;
    cout << "Data de Ingresso: ";
    cin.ignore();
    getline(cin, dataIngresso);
    cout << "Nivel (0, 1, 2, 3, 4, 5, 6, 7): ";
    cin >> nivelProfessor;
    cout << "Formacao (0, 1, 2): ";
    cin >> formacaoProfessor;
    cout << "Disciplina: ";
    cin.ignore();
    getline(cin, disciplina);

    // Cria um objeto do tipo Professor e armazena no vetor de objetos
    Professor novoProfessor(formacaoProfessor, nivelProfessor, disciplina, matricula, salario, departamento, cargaHoraria, dataIngresso, nome, cpf, dataNascimento, genero, rua, numero, bairro, cidade, cep);
    professores.push_back(novoProfessor);

    system("clear || cls");
    cout << "---Professor N°" << professores.size() << " Cadastrado com sucesso!---\n" << endl;
}

void BancoDao::cadastrarTecnicoADM(){
    string nome, cpf, dataNascimento, genero, rua, bairro, cidade, cep, matricula, funcaoDesempenhada, departamento, dataIngresso;
    int numero, cargaHoraria;
    float salario;

    system("clear || cls");
    cout << "---Cadastro de Tecnico Administrativo---" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Data de Nascimento: ";
    getline(cin, dataNascimento);
    cout << "Genero: ";
    getline(cin, genero);
    cout << "Rua: ";
    getline(cin, rua);
    cout << "Numero: ";
    cin >> numero;
    cout << "Bairro: ";
    cin.ignore();
    getline(cin, bairro);
    cout << "Cidade: ";
    getline(cin, cidade);
    cout << "CEP: ";
    getline(cin, cep);
    cout << "Matricula: ";
    getline(cin, matricula);
    cout << "Salario: ";
    cin >> salario;
    getline(cin, departamento);
    cout << "Carga Horaria: ";
    cin >> cargaHoraria;
    cout << "Data de Ingresso: ";
    cin.ignore();
    getline(cin, dataIngresso);
    cout << "Funcao Desempenhada: ";
    getline(cin, funcaoDesempenhada);
    cout << "Departamento: ";
    getline(cin, departamento);

    TecnicoADM novoTecnicoADM(funcaoDesempenhada, matricula, salario, departamento, cargaHoraria, dataIngresso, nome, cpf, dataNascimento, genero, rua, numero, bairro, cidade, cep);
    tecnicosADM.push_back(novoTecnicoADM);

    system("clear || cls");
    cout << "---Tecnico N°" << tecnicosADM.size() << " Cadastrado com sucesso!---\n" << endl;
}

void BancoDao::listarProfessores(){
    system("clear || cls");

    if(professores.size() == 0){ // Se o vetor de objetos estiver vazio, imprime uma mensagem
        cout << "---Nao há professores cadastrados---\n" << endl;
    } else{
        cout << "-----------------" << endl;
        cout << "---Professores---" << endl;
        cout << "-----------------" << endl;
        for(int i=0; i<professores.size(); i++){ // Percorre o vetor de objetos e imprime os dados
            cout << "---Professor N°" << i+1 << endl;
            cout << "Nome: " << professores[i].getNome() << endl;
            cout << "CPF: " << professores[i].getCpf() << endl;
            cout << "Data de Nascimento: " << professores[i].getDataNascimento() << endl;
            cout << "Genero: " << professores[i].getGenero() << endl;
            cout << "Rua: " << professores[i].getEndereco()->getRua() << endl;
            cout << "Numero: " << professores[i].getEndereco()->getNumero() << endl;
            cout << "Bairro: " << professores[i].getEndereco()->getBairro() << endl;
            cout << "Cidade: " << professores[i].getEndereco()->getCidade() << endl;
            cout << "CEP: " << professores[i].getEndereco()->getCep() << endl;
            cout << "Matricula: " << professores[i].getMatricula() << endl;
            cout << "Salario: " << professores[i].getSalario() << endl;
            cout << "Departamento: " << professores[i].getDepartamento() << endl;
            cout << "Carga Horaria: " << professores[i].getCargaHoraria() << endl;
            cout << "Data de Ingresso: " << professores[i].getDataIngresso() << endl;
            cout << "Nivel: " << professores[i].getNivelProfessor() << endl;
            cout << "Formacao: " << professores[i].getFormacaoProfessor() << endl;
            cout << "Disciplina: " << professores[i].getDisciplina() << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << endl;
        }
    }


}

void BancoDao::listarTecnicosADM(){
    system("clear || cls");

    if(tecnicosADM.size() == 0){
        cout << "---Nao há tecnicos administrativos cadastrados---\n" << endl;
    } else{
        cout << "------------------------------" << endl;
        cout << "---Tecnicos Administrativos---" << endl;
        cout << "------------------------------" << endl;

        for(int i=0; i<tecnicosADM.size(); i++){
            cout << "---Tecnico N°" << i+1 << endl;
            cout << "Nome: " << tecnicosADM[i].getNome() << endl;
            cout << "CPF: " << tecnicosADM[i].getCpf() << endl;
            cout << "Data de Nascimento: " << tecnicosADM[i].getDataNascimento() << endl;
            cout << "Genero: " << tecnicosADM[i].getGenero() << endl;
            cout << "Rua: " << tecnicosADM[i].getEndereco()->getRua() << endl;
            cout << "Numero: " << tecnicosADM[i].getEndereco()->getNumero() << endl;
            cout << "Bairro: " << tecnicosADM[i].getEndereco()->getBairro() << endl;
            cout << "Cidade: " << tecnicosADM[i].getEndereco()->getCidade() << endl;
            cout << "CEP: " << tecnicosADM[i].getEndereco()->getCep() << endl;
            cout << "Matricula: " << tecnicosADM[i].getMatricula() << endl;
            cout << "Salario: " << tecnicosADM[i].getSalario() << endl;
            cout << "Funcao Desempenhada: " << tecnicosADM[i].getFuncaoDesempenhada() << endl;
            cout << "Departamento: " << tecnicosADM[i].getDepartamento() << endl;
            cout << "Carga Horaria: " << tecnicosADM[i].getCargaHoraria() << endl;
            cout << "Data de Ingresso: " << tecnicosADM[i].getDataIngresso() << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << endl;
        }
    }
}

void BancoDao::deletarProfessor(){
    string opcao;
    bool encontrou = false; // Variavel para verificar se o professor foi encontrado

    system("clear || cls");
    for(int i=0; i<professores.size(); i++){ // Percorre o vetor de objetos e imprime o nome e a matricula de cada professor
        cout << "---Professor N°" << i+1 << endl;
        cout << "Nome: " << professores[i].getNome() << endl;
        cout << "Matricula: " << professores[i].getMatricula() << endl;
        cout << "--------------------------" << endl;
    }
    cout << "Digite o numero da matrícula do professor que deseja deletar: ";
    cin.ignore();
    getline(cin, opcao);

    for(int i=0; i<professores.size(); i++){
        if(professores[i].getMatricula() == opcao){ // Se a matricula digitada for igual a matricula de algum professor, deleta o professor
            professores.erase(professores.begin() + i);
            cout << "---Professor deletado com sucesso!---\n" << endl;
            encontrou = true;
            break;
        }
    }

    if(!encontrou){ // Se não encontrou o professor, imprime uma mensagem
        cout << "\n---Professor não encontrado---\n" << endl;
    }
}

void BancoDao::deletarTecnicoADM(){
    string opcao;
    bool encontrou = false;

    system("clear || cls");
    for(int i=0; i<tecnicosADM.size(); i++){
        cout << "---Tecnico N°" << i+1 << endl;
        cout << "Nome: " << tecnicosADM[i].getNome() << endl;
        cout << "Matricula: " << tecnicosADM[i].getMatricula() << endl;
        cout << "--------------------------" << endl;
    }
    cout << "Digite o numero da matricula do tecnico administrativo que deseja deletar: ";
    cin.ignore();
    getline(cin, opcao);

    for(int i=0; i<tecnicosADM.size(); i++){
        if(tecnicosADM[i].getMatricula() == opcao){
            tecnicosADM.erase(tecnicosADM.begin() + i);
            cout << "---Tecnico Administrativo deletado com sucesso!---\n" << endl;
            encontrou = true;
            break;
        }
    }

    if(!encontrou){
        cout << "\n---Tecnico Administrativo não encontrado---\n" << endl;
    }
}

void BancoDao::buscarProfessor(){
    string opcao;
    bool encontrou = false;

    system("clear || cls");
    cout << "Digite o numero da matricula do professor que deseja buscar: ";
    cin.ignore();
    getline(cin, opcao);

    for(int i=0; i < professores.size(); i++){
        if(professores[i].getMatricula() == opcao){ // Busca o professor pelo numero da matricula
            system("clear || cls");
            cout << "---Professor N°" << i+1 << endl;
            cout << "Nome: " << professores[i].getNome() << endl;
            cout << "CPF: " << professores[i].getCpf() << endl;
            cout << "Data de Nascimento: " << professores[i].getDataNascimento() << endl;
            cout << "Genero: " << professores[i].getGenero() << endl;
            cout << "Rua: " << professores[i].getEndereco()->getRua() << endl;
            cout << "Numero: " << professores[i].getEndereco()->getNumero() << endl;
            cout << "Bairro: " << professores[i].getEndereco()->getBairro() << endl;
            cout << "Cidade: " << professores[i].getEndereco()->getCidade() << endl;
            cout << "CEP: " << professores[i].getEndereco()->getCep() << endl;
            cout << "Matricula: " << professores[i].getMatricula() << endl;
            cout << "Salario: " << professores[i].getSalario() << endl;
            cout << "Departamento: " << professores[i].getDepartamento() << endl;
            cout << "Carga Horaria: " << professores[i].getCargaHoraria() << endl;
            cout << "Data de Ingresso: " << professores[i].getDataIngresso() << endl;
            cout << "Nivel: " << professores[i].getNivelProfessor() << endl;
            cout << "Formacao: " << professores[i].getFormacaoProfessor() << endl;
            cout << "Disciplina: " << professores[i].getDisciplina() << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << endl;
            encontrou = true;
            break;
        }
    }
    if(!encontrou){
        cout << "\n---Professor não encontrado---\n" << endl;
    }
}

void BancoDao::buscarTecnicoADM(){
    string opcao;
    bool encontrou = false;

    system("clear || cls");
    cout << "Digite o numero da matricula do tecnico administrativo que deseja buscar: ";
    cin.ignore();
    getline(cin, opcao);

    for(int i=0; i < tecnicosADM.size(); i++){
        if(tecnicosADM[i].getMatricula() == opcao){
            system("clear || cls");
            cout << "---Tecnico N°" << i+1 << endl;
            cout << "Nome: " << tecnicosADM[i].getNome() << endl;
            cout << "CPF: " << tecnicosADM[i].getCpf() << endl;
            cout << "Data de Nascimento: " << tecnicosADM[i].getDataNascimento() << endl;
            cout << "Genero: " << tecnicosADM[i].getGenero() << endl;
            cout << "Rua: " << tecnicosADM[i].getEndereco()->getRua() << endl;
            cout << "Numero: " << tecnicosADM[i].getEndereco()->getNumero() << endl;
            cout << "Bairro: " << tecnicosADM[i].getEndereco()->getBairro() << endl;
            cout << "Cidade: " << tecnicosADM[i].getEndereco()->getCidade() << endl;
            cout << "CEP: " << tecnicosADM[i].getEndereco()->getCep() << endl;
            cout << "Matricula: " << tecnicosADM[i].getMatricula() << endl;
            cout << "Salario: " << tecnicosADM[i].getSalario() << endl;
            cout << "Funcao Desempenhada: " << tecnicosADM[i].getFuncaoDesempenhada() << endl;
            cout << "Departamento: " << tecnicosADM[i].getDepartamento() << endl;
            cout << "Carga Horaria: " << tecnicosADM[i].getCargaHoraria() << endl;
            cout << "Data de Ingresso: " << tecnicosADM[i].getDataIngresso() << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << endl;
            encontrou = true;
            break;
        }
    }
    if(!encontrou){
        cout << "\n---Tecnico Administrativo não encontrado---\n" << endl;
    }
}
