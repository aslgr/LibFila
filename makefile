CFLAGS = -Wall -g
LDFLAGS = -lm

CC = gcc

objects = testa_fila.o LibFila.o

all: testa_fila

testa_fila: $(objects)
	$(CC) $^ -o $@ $(LDFLAGS)

testa_fila.o: testa_fila.c LibFila.h
	$(CC) -c $< $(CFLAGS)

LibFila.o: LibFila.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(objects)

purge:
	rm -f $(objects) testa_fila
