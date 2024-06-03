compilar:
	g++ -o main main.cpp endereco.cpp pessoa.cpp funcionario.cpp professor.cpp tecnicoADM.cpp bancodao.cpp

exec:
	./main
clear:
	rm -f main