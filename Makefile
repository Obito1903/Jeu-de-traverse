OBJS	= main.o jeuBase.o affichage.o initJeu.o deplacement.o saut.o samIO.o
SOURCE	= main.c src/jeuBase.c src/affichage.c src/initJeu.c src/deplacement.c src/saut.c src/lib/samIO.c
HEADER	= main.h src/jeuBase.h src/affichage.h src/initJeu.h src/deplacement.h src/saut.h src/lib/samIO.h
OUT	= jeu
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -pedantic
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

jeuBase.o: src/jeuBase.c
	$(CC) $(FLAGS) src/jeuBase.c 

affichage.o: src/affichage.c
	$(CC) $(FLAGS) src/affichage.c 

initJeu.o: src/initJeu.c
	$(CC) $(FLAGS) src/initJeu.c 

deplacement.o: src/deplacement.c
	$(CC) $(FLAGS) src/deplacement.c 

saut.o: src/saut.c
	$(CC) $(FLAGS) src/saut.c 

samIO.o: src/lib/samIO.c
	$(CC) $(FLAGS) src/lib/samIO.c 


clean:
	rm -f $(OBJS) $(OUT)