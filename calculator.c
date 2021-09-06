//Bobby Love
//4 August 2021
//Calculator
//A command-line calculator application.

//TODO
//Don't allow division by 0!!!!!!!!!!
//use gets() to read in a string of a certain size. BADDDD gets is insecure and not included in libraries anymore
//Change datatypes (eg, all functions should use doubles)
////Add a manual option and explain limitations of each mode (addition can only add positive numbers, for ex.) along with how to enter values "*number* *space* *enterkey*" for example.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "calculator.h" //Holds custom function declarations.

#define MAX 15 //Calculator will accept at most 15 digit inputs to prevent overflow.

int main(void){
	//Begin main
	puts("Welcome to Calculator!");
	puts("Which operation would you like perform?");
	printf("(1) Instructions\n(2) Exponent\n(3) Multiplication\n(4) Division\n(5) Addition\n(6) Subtraction\n(7) Exit\n>");
	operationChoice(); //Calculation type is chosen and values are computed.
	return(0); //Program successfully exits.
}

void operationChoice(void){
	//Variable Declarations
	int operation = 0;
	int continueLoop = 1;

	//Begin operationChoice
	while(continueLoop == 1){
		fscanf(stdin, "%2d", &operation); //Scan in user choice. The "2" will means fscanf() will only accept up to 2 characters (prevents buffer overflow attacks).
		switch(operation){
			case 1 :
				printInstructions();
				printf(">");
				break;
			case 2 :
				exponent();
				continueLoop = 0;
				break;
			case 3 :
				multiplication();
				continueLoop = 0;
				break;
			case 4 :
				division();
				continueLoop = 0;
				break;
			case 5 :
				addition();
				continueLoop = 0;
				break;
			case 6 :
				subtraction();
				continueLoop = 0;
				break;
			case 7 : //Exit program case.
				puts("See you soon!");
				continueLoop = 0;
				break;
			default : //Error check case.
				puts("Sorry, but that isn't a vaild choice.");
				while((getchar()) != '\n'); //Clears input buffer of stray characters, preventing infinite loop in case scanf() fails.
				printf(">");
				break;
		}
	}
}

void printInstructions(void){
	//print the user manual
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
	int continueOneLoop = 1;
	int continueTwoLoop = 1;
	int addendOneError = 1;
	int addendTwoError = 1;
	char addendOneString[MAX] = {0};
	char addendTwoString[MAX] = {0};
	int addendOne = 0;
	int addendTwo = 0;
	int sum = 0;
	
	//Begin addition
	while(continueOneLoop == 1){
		printf("Type addend one below.\n>");
		while((getchar()) != '\n'); //Clears input buffer of stray characters (in case user inputted more than 15 characters in previous iteration of while loop).
		fscanf(stdin, "%15s", addendOneString); //fscanf() will consume a string up to 15 characters long.
		for(int i = 0; i < strlen(addendOneString); i++){ //Error check (looking for non-digit characters in input string).
			addendOneError = isdigit(addendOneString[i]);
			if(addendOneError == 0){
				break;
			}
		}
		if(addendOneError == 0){
			puts("Sorry, but that isn't a valid choice.");
			for(int i = 0; i < strlen(addendOneString); i++){ //Empty the contents of addendOneString for safe reuse.
				addendOneString[i] = 0;
			}
			addendOneError = 1;
		}
		else{
			for(int i = 0; i < strlen(addendOneString); i++){
				addendOne = addendOne + (addendOneString[i] - '0') * pow(10, strlen(addendOneString) - i - 1);
			}
			while(continueTwoLoop == 1){
				printf("Type addend two below.\n>");
				while((getchar()) != '\n'); //Clears input buffer of stray characters (in case user inputted more than 15 characters in previous iteration of while loop).
				fscanf(stdin, "%15s", addendTwoString); //fscanf() will consume a string up to 15 characters long.
				for(int i = 0; i < strlen(addendTwoString); i++){ //Error check (looking for non-digit characters in input string).
					addendTwoError = isdigit(addendTwoString[i]);
					if(addendTwoError == 0){
						break;
					}
				}
				if(addendTwoError == 0){
					puts("Sorry, but that isn't a valid choice.");
					for(int i = 0; i < strlen(addendTwoString); i++){ //Empty the contents of addendTwoString for safe reuse.
						addendTwoString[i] = 0;
					}
					addendTwoError = 1;
				}		
				else{
					for(int i = 0; i < strlen(addendTwoString); i++){
						addendTwo = addendTwo + (addendTwoString[i] - '0') * pow(10, strlen(addendTwoString) - i - 1);
					}
					continueTwoLoop = 0;
				}		
			}
			continueOneLoop = 0;
		}
	}
	sum = addendOne + addendTwo;
	printf("Sum lies below.\n>%d\n", sum);	
}

void subtraction(void){
//float minuend, float subtrahend, float* difference

}	
