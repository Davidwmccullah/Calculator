#Bobby Love
#6 September 2021
#Calculator
#A command-line calculator application.

CFLAGS := -std=c11 -ggdb -O0

calculator : calculator.c calculator.h
	gcc -o -lm calculator.c calculator

.PHONY : clean
clean :
	-rm -f calculator
