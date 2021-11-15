#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void operationChoice(void); //Scans in value 1 to 7, and performs the given choice.

void printInstructions(void); //Prints instruction manual. Use q to quit.

void exponent(void); //Scans in base and exponent, calculates power (1 digit max per scan).

void multiplication(void); //Scans in factors, calculates product (15 digit max per scan).

void division(void); //Scans in divisor and dividend, calculates quotient and remainder (15 digit max per scan).

void addition(void); //Scans in two addends, calculates  sum (15 digit max per scan).

void subtraction(void); //Scans in minuend and subtrahend, calculates  difference (15 digit max per scan).

void emptyString(char*); //Overwrites 0 to each index of given string.

int convertInteger(char*); //Converts string to integer.

void invalid(void); //Prints error message.

int integerTest(char*); //Looks for non-digit characters in string.

void numberScan(char*); //Scans up to 15 characters into string.

int lengthTest(char*); //Checks length of string.
