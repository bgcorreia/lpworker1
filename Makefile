all: agenda.o

agenda.o: agenda.cpp
	@echo "Compilando arquivo objeto: agenda.o"
	@g++ -o agenda.o agenda.cpp

install: agenda.o
	@echo "Instalando no Sistema."
	@sudo cp agenda.o /usr/local/bin/agenda

clean:
	@echo "Limpando arquivos"
	-@rm -f agenda.o
