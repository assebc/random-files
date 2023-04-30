CC = gcc
CFLAGS = -Wall -o0 -g -o
TARGET = aed
FILES = src/llist.c src/manager.c src/medic.c src/queue.c src/ui.c src/user.c src/utils.c

main:
	@echo "Compiling"
	cc $(FILES) src/main.c $(CFLAGS) $(TARGET)

clean:
	rm -r $(TARGET)