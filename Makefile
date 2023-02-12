# Makefile

# define as flags
CC = g++
CPPFLAGS = -Wall -std=c++17

OBJS = Carro.o Catalogo.o Cliente.o Console.o Contrato.o ContratoSegurado.o CPF.o CPFInvalidoException.o Interface.o Marca.o Motocicleta.o Placa.o PlacaInvalidaException.o Veiculo.o
PROG = main

# regra default
all: $(PROG)

# regras de ligacao
$(PROG) : % :  $(OBJS) %.o
	$(CC) $^ -o $@

# compila com flags de depuração
debug: CPPFLAGS += -DDEBUG -g
debug: all

# remove arquivos temporários
clean:
	-rm -f *.o

# remove tudo o que não for o código-fonte
purge: clean
	-rm -f $(PROG)