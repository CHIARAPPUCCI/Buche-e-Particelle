compila: main.o funzioni.o
	g++ main.o funzioni.o -o exe.x

main.o: main.cpp
	g++ -c main.cpp

funzioni.o: funzioni.cpp
	g++ -c funzioni.cpp

esegui: exe.x
	./exe.x

pulisci: exe.x
	rm exe.x
