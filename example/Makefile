CC = gcc
OBJECTS = ../llist.c example.c
CFLAGS = -Wall -Wextra -O2
NAME = example

example: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)

clean:
	rm $(NAME)
