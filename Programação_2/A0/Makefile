# Nome do programa final
TARGET = jukebox

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -g

# Arquivos fonte
SRC = main.c jukefila.c pedido.c

# Dependências e como compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Limpeza dos arquivos gerados
clean:
	rm -f $(TARGET) *.o

