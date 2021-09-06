#Bobby Love
#6 September 2021
#Calculator
#A simple calculator application.

CFLAGS := -std=c11 -ggdb -O0

calculator : calculator.c calculator.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^

.PHONY : clean
clean :
	-rm -f calculator
