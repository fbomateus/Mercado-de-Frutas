CC = gcc
CFLAGS = -Wall
SRC = src/main.c src/frutas.c src/lista.c src/vendas.c
OBJ = $(SRC:.c=.o)
EXEC = mercado_frutas

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

clean:
	rm -f src/*.o $(EXEC)

run: all
	./$(EXEC)
