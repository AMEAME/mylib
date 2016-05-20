# Makefile for main.c

bin\main: bin\main.o bin\list.o
	gcc -o bin\main bin\main.o bin\list.o

bin\main.o: source\main.c
	gcc -c source\main.c -o bin\main.o -Iheader
	
bin\list.o: source\list.c
	gcc -c source\list.c -o bin\list.o -Iheader

clean:
	rm -rf bin
