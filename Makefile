# Makefile

# define as flags
CC = g++
CPPFLAGS = -Wall -std=c++17

OBJS = Placa.o PlacaInvalidaException.o
PROG = main

# regra default
all: $(PROG)

# regras de ligacao
$(PROG) : % :  $(OBJS) %.o
	$(CC) $^ -o $@

# regras de compilação
%.o: %.c %.h
	$(CC) -c -o $@ $<

# compila com flags de depuração
debug: CFLAGS += -DDEBUG -g
debug: all

# remove arquivos temporários
clean:
	-rm -f *.o

# remove tudo o que não for o código-fonte
purge: clean
	-rm -f $(PROG)