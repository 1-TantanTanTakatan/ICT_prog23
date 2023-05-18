CC = gcc
APP = ex

test:
	$(CC) -g $(APP)$(NUM).c -Wall
	./a.exe
	rm a.exe