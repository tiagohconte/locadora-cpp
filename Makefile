# Makefile

# define as flags
CC = g++
CFLAGS = -Wall -std=c++17
LFLAGS =

OBJS =
PROG = main

# regra default
all: $(PROG)

# regras de ligacao
$(PROG) : % :  $(OBJS) %.o
	$(CC) $^ -o $@ $(LFLAGS)

# regras de compilação
%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

# compila com flags de depuração
debug: CFLAGS += -DDEBUG -g
debug: all

# remove arquivos temporários
clean:
	-rm -f *.o

# remove tudo o que não for o código-fonte
purge: clean
	-rm -f $(PROG)