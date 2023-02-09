# Makefile

# define as flags
CC = g++
CPPFLAGS = -Wall -std=c++17

OBJS = Carro.o Cliente.o Console.o Contrato.o CPF.o CPFInvalidoException.o Marca.o Placa.o PlacaInvalidaException.o Veiculo.o
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