#Autor:	Rafael Romão
#Data:	22/02/2015
CC=gcc
CFLAGS=-c -Wall
Install=cp 3TReloaded /usr/bin
all: 
	@echo "*******************"
	@echo "*3TReloaded Source*"
	@echo "*******************"
	@echo "Compiling 3TReloaded..."
	@$(CC) $(CFLAGS) 3TReloaded.c
	@$(CC) 3TReloaded.o -o 3TReloaded
	@echo "Successfully compiled"
install:
	@echo "Installing 3TReloaded..."
	@$(Install)
clean:
	@rm -f *.o
execute:
	@./3TReloaded
