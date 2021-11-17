all: work16.o
	gcc -o work16m work16.o

work16.o: work16.c
	gcc -c work16.c

run:
	./work16m

clean:
	rm *.o
	rm work16m
