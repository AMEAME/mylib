CC = gcc
TARGET = ./bin/main
SRCDIR = ./src

CFLAGS = -Wall
OBJDIR = ./lib
ifeq "$(strip $(OBJDIR))" ""
  OBJDIR  = .
endif
SOURCES   = $(wildcard $(SRCDIR)/*.c)
INCLUDE = -I./include

LIBDIR = ./lib
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))

$(TARGET): $(OBJECTS) $(LIBS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf bin/* lib/*.o
