CC = gcc
vpath %.h include
vpath %.c src
CFLAGS = -I include
TARGETS = bin\main
SOURCES = \
	main.c \
	str.c \
	utils.c \
	error.c \
	list.c
  
OBJECTS = $(subst .c,.o,$(SOURCES))
main: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGETS)
	rm -rf *.o
  
.PHONY: clean
clean:
	rm -rf *.exe *.o *.d
  