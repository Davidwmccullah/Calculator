//Bobby Love
//4 August 2021
//A simple calculator application.


///TODO Create error handling for scanning in numbers (what if someone types in "a" instead of an actual number???
//Use "isdigit" for this but, the POS function wouldnt return 1 when it was actually true, so figure that out...
//Don't allow division by 0!!!!!!!!!!
//use gets() to read in a string of a certain size.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "calculator.h" //Holds function declarations.

#define MAX 50

int main(void){

	//Begin main
	puts("Welcome to Calculator!");
	puts("Which operation would you like perform?");
	printf("(1) Exponent\n(2) Multiplication\n(3) Division\n(4) Addition\n(5) Subtraction\n(6) Exit\n>");
	operationChoice();
	
	return(0); //Program successfully exits;
}

void operationChoice(void){

	//Variable Declarations
	char* operation = malloc(sizeof(char));

	//Begin operationChoice
	scanf("%c", operation); //Scan in user choice.

	switch(*operation){

		case '1' :
			
			exponent();
			break;

		case '2' :

			multiplication();
			break;

		case '3' :

			division();
			break;

		case '4' :

			addition();
			break;

		case '5':

			subtraction();
			break;

		case '6' :

			puts("See you soon!");
			break;

		default :

			puts("Sorry, but that wasn't a vaild choice.");
			break;
	}

	free(operation);
	operation = NULL;
}

void exponent(void){
	//base, exponent, power
}

void multiplication(void){
	//factorOne, factorTwo, product
}

void division(void){
//float divisor, dividend, float* quotient, float* remainder
}


void addition(void){

	//Variable Declarations
	char addendOneString[MAX] = {0};
	//char addendTwoString[MAX] = {0};
	int addendOne = 0;
	//int addendTwo = 0;
	
	//Begin addition
	printf("Type addend one\n>");
	scanf("%s", addendOneString);
	printf("strlen is %d\n", strlen(addendOneString));
	//printf("string is %s\n", addendOneString);
	//printf("addendOne is %d\n", addendOne);
	
	if(strlen(addendOneString) == 1){ //In case of 1 digit number.
			
		addendOne = (addendOneString[0] - '0');
	}

	if(strlen(addendOneString) == 2){ //In case of 2 digit number.
	
		addendOne = 10 * (addendOneString[0] - '0');
		addendOne = addendOne + (addendOneString[1] - '0');
	}

	else{ //In case of >2 digit number.
		for(int i = 0; i < strlen(addendOneString); i++){
			
			printf("addendOneString[i] -'0'= %d and i = %d\n", addendOneString[i]-'0', i);	
			printf("pre run addendOne is %d (addenOneString[i] - '0') is %d and 10^(strlen(addendOneString)) is %d\n", addendOne, (addendOneString[i] - '0'), 10^(strlen(addendOneString)));
			addendOne = addendOne + (addendOneString[i] - '0') * pow(10, strlen(addendOneString));
			//addendOne = addendOne + (addendOneString[i] - '0') * 10^(strlen(addendOneString));
			printf("post run addendOne %d\n", addendOne);
		}
	}
	
	printf("%d\n", addendOne);
}

void subtraction(void){
//float minuend, float subtrahend, float* difference

}	
