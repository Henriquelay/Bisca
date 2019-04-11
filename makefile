CC=gcc
CFLAGS=-I. -Wall  -lm
DEPS = cards.h deck.h
OBJ = cards.o deck.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f *.o
	mv main bisca


clean:
	rm -f *.o
	rm -f bisca
