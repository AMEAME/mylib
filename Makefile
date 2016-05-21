# Makefile for main.c

bin\main: bin\main.o bin\list.o bin\error.o bin\utils.o
	gcc -o bin\main bin\main.o bin\list.o bin\error.o bin\utils.o

bin\main.o: source\main.c bin\utils.o
	gcc -c source\main.c -o bin\main.o bin\utils.o -Iheader
	
bin\list.o: source\list.c
	gcc -c source\list.c -o bin\list.o -Iheader

bin\error.o: source\error.c
	gcc -c source\error.c -o bin\error.o -Iheader

bin\utils.o: source\utils.c
	gcc -c source\utils.c -o bin\utils.o -Iheader

clean:
	rm -rf bin
