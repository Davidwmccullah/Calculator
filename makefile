#Bobby Love
#6 September 2021
#Calculator
#A command-line calculator application.

#Variable Declarations
CC := gcc
CFLAGS := -std=c11 -Wall -ggdb -O0 -lm
SOURCES := calculator.c calculator.h

calculator : $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

#calculator : calculator.c calculator.h
#	gcc -std=c11 -Wall -ggdb -O0 -lm calculator.c -o calculator

.PHONY : clean
clean :
	-rm -f calculator
