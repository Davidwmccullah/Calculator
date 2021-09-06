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

#define MAX 15 //Calculator accepts at most 15 digit inputs to prevent buffer overflow.

int main(void){
	puts(">Welcome to Calculator!");
	operationChoice(); //Calculation type chosen and values computed.
	return(0); //Program successfully exits.
}

void operationChoice(void){
	char choiceInput[MAX] = {0};
	int choiceCheck = 0;
	int choice;
	int continueLoop = 1;

	while(continueLoop == 1){
		puts(">Which operation would you like perform?");
		printf("(1) Instructions\n(2) Exponent\n(3) Multiplication\n(4) Division\n(5) Addition\n(6) Subtraction\n(7) Exit\n>");
		numberScan(choiceInput); //Scan in choice for above menu.
		choiceCheck = integerTest(choiceInput); //Check whether choice is integer.
		if(choiceCheck == 1){ //choice is not integer.
			choice = 8;
		}
		else{ //choice is integer.
			choice = convertInteger(choiceInput);
		}
		switch(choice){
			case 1 :
				printInstructions();
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
				puts(">See you soon!");
				continueLoop = 0;
				break;
			default : //Error check case.
				invalid(); //Prints error message.
				while((getchar()) != '\n'); //Clears input buffer of stray characters, preventing erroneous loop iterations in case choiceInput runs out of room for characters.
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
	int continueOneLoop = 1;
	int continueTwoLoop = 1;
	int addendOneError = 1; //1 = no error, 0 = error.
	int addendTwoError = 1; //1 = no error, 0 = error.
	char addendOneString[MAX] = {0};
	char addendTwoString[MAX] = {0};
	int addendOne = 0;
	int addendTwo = 0;
	int sum = 0;

	while(continueOneLoop == 1){
		printf(">Type addend one below.\n>");
		while((getchar()) != '\n'); //Clears input buffer of stray characters in case user inputted more than 15 characters in previous iteration of while loop.
		numberScan(addendOneString); //Scans input string into addendOneString.
		addendOneError = integerTest(addendOneString); //Looks for non-digit characters in AddendOneString.
		if(addendOneError == 0){
			invalid(); //Prints error message.
			emptyString(addendOneString); //Empty the contents of addendOneString for safe reuse.
			addendOneError = 1;
		}
		else{
			addendOne = convertInteger(addendOneString); //Convert "char* addendOneString" to "int addendOne".
			/*while(continueTwoLoop == 1){
				printf(">Type addend two below.\n>");
				while((getchar()) != '\n'); //Clears input buffer of stray characters in case user inputted more than 15 characters in previous iteration of while loop.
				numberScan(addendTwoString); //Scans input string into addendTwoString.
				addendTwoError = integerTest(addendTwoString); //Looks for non-digit character in addendTwoString.
				if(addendTwoError == 0){
					invalid(); //Prints error message.
					emptyString(addendTwoString); //Empty the contents of addendTwoString for safe reuse.
					addendTwoError = 1;
				}		
				else{
					addendTwo = convertInteger(addendTwoString); //Convert "char* addendTwoString" to "int addendTwo".
					continueTwoLoop = 0; //Exit addendTwo's while loop.
				}
		
			}*/
			continueOneLoop = 0; //Exit addendOne's while loop.
		}
	}
	while(continueTwoLoop == 1){
		printf(">Type addend two below.\n>");
		while((getchar()) != '\n'); //Clears input buffer of stray characters in case user inputted more than 15 characters in previous iteration of while loop.
		numberScan(addendTwoString); //Scans input string into addendTwoString.
		addendTwoError = integerTest(addendTwoString); //Looks for non-digit character in addendTwoString.
		if(addendTwoError == 0){
			invalid(); //Prints error message.
			emptyString(addendTwoString); //Empty the contents of addendTwoString for safe reuse.
			addendTwoError = 1;
		}		
		else{
			addendTwo = convertInteger(addendTwoString); //Convert "char* addendTwoString" to "int addendTwo".
			continueTwoLoop = 0; //Exit addendTwo's while loop.
		}	
	}
	sum = addendOne + addendTwo;
	printf(">Sum lies below.\n>%d\n", sum);	
}

void subtraction(void){
//float minuend, float subtrahend, float* difference

}

void emptyString(char* string){
	for(int i = 0; i < strlen(string); i++){ //Overwrites 0 to each index of string.
		string[i] = 0;
	}
}

int convertInteger(char* string){
	int integer = 0;

	for(int i = 0; i < strlen(string); i++){
		integer = integer + (string[i] - '0') * pow(10, strlen(string) - i - 1);
	}
	return(integer);
}

void invalid(void){
	puts(">Sorry, but that's not a valid choice.");
}

int integerTest(char* string){
	int error = 1; //1 = no error, 0 = error.

	for(int i = 0; i < strlen(string); i++){ //Looks for non-digit characters in string.
		error = isdigit(string[i]);
		if(error == 0){
			break;
		}
	}
	return(error);
}

void numberScan(char* string){
	fscanf(stdin, "%15s", string); //fscanf() will consume a string up to 15 characters long.
}
