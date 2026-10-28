a.out: main.o apc.o add.o sub.o mul.o div.o
	gcc main.o apc.o add.o sub.o mul.o div.o -o a.out

main.o: main.c apc.h
	gcc -c main.c

apc.o: apc.c apc.h
	gcc -c apc.c

add.o: add.c apc.h
	gcc -c add.c

sub.o: sub.c apc.h
	gcc -c sub.c

mul.o: mul.c apc.h
	gcc -c mul.c

div.o: div.c apc.h
	gcc -c div.c

clean:
	rm -f *.o a.out
