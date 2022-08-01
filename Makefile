all:main

main: Sources/main.cpp
	g++ -o Executable/main Sources/main.cpp Sources/Candidat.cpp Sources/Evaluation.cpp Sources/Matiere.cpp
	./Executable/main
