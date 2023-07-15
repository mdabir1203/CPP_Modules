CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: main

main: main.o bureaucrat.o
	$(CC) $(CFLAGS) -o main main.o bureaucrat.o

main.o: main.cpp bureaucrat.h
	$(CC) $(CFLAGS) -c main.cpp

bureaucrat.o: bureaucrat.cpp bureaucrat.h
	$(CC) $(CFLAGS) -c bureaucrat.cpp

clean:
	rm -f *.o main
