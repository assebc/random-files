CC = gcc
CFLAGS = -Wall -g -o
MODULES_PATH = src/includes/modules/
MODULES_1 = $(MODULES_PATH)avioes.c $(MODULES_PATH)aeroporto.c $(MODULES_PATH)voo.c $(MODULES_PATH)ticket.c
FILES = $(MODULES_1) src/includes/btree.c src/includes/grafos.c src/includes/parser.c src/includes/parsing.c src/includes/define.h
TARGET = aeroport

main:
	@echo "Compiling"
	cc $(FILES) src/main.c $(CFLAGS) $(TARGET) 

clean:
	rm -r $(TARGET)