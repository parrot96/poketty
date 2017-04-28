CC = gcc
OBJ_NAME = poketty
OBJS = main.c poketty.c ant/ant.c upkm/upkm.c
FLAGS = -std=c99

all:
	$(CC) $(FLAGS) $(OBJS) -o $(OBJ_NAME)
clean:
	rm $(OBJ_NAME)
