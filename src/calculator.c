// TODO
// Don't allow division by 0!!!!!!!!!!
// use gets() to read in a string of a certain size. BADDDD gets is insecure and not included in libraries anymore
// Change datatypes (eg, all functions should use doubles)
// Add a manual option and explain limitations of each mode (addition can only add positive numbers, for ex.) along with how to enter values "*number* *space* *enterkey*" for example.

#include "calculator.h"

#define MAX 16 //Calculator accepts at most (MAX - 1) digit inputs to prevent buffer overflow.
//WARNING: if MAX is changed, width modifier for scanf() inside numberScan() must be changed too.

int main(void) {
	puts(">Welcome to Calculator!");
	operationChoice(); //Calculation type chosen and values computed.
	return 0;		   //Program successfully exits.
}

void operationChoice(void) { //Scans in value 1 to 7, and performs the given choice.
	char choiceInput[MAX] = {0};
	int choiceCheck = 0;
	int choice;
	int continueLoop = 1;

	while(continueLoop == 1) {
		puts(">Which operation would you like perform?");
		printf("(1) Instructions\n(2) Exponent\n(3) Multiplication\n(4) Division\n(5) Addition\n(6) Subtraction\n(7) Exit\n>");
		numberScan(choiceInput);				//Scan in choice for above menu.
		choiceCheck = integerTest(choiceInput); //Check whether choice is integer.
		if(choiceCheck == 1) {					//choice is not integer.
			choice = 8;
		} else { //choice is integer.
			choice = convertInteger(choiceInput);
		}
		switch(choice) {
			case 1:
				printInstructions();
				break;
			case 2:
				exponent();
				continueLoop = 0;
				break;
			case 3:
				multiplication();
				continueLoop = 0;
				break;
			case 4:
				division();
				continueLoop = 0;
				break;
			case 5:
				addition();
				continueLoop = 0;
				break;
			case 6:
				subtraction();
				continueLoop = 0;
				break;
			case 7: //Exit program case.
				puts(">See you soon!");
				continueLoop = 0;
				break;
			default:	   //Error check case.
				invalid(); //Prints error message.
				while((getchar()) != '\n')
					; //Clears input buffer of stray characters, preventing erroneous loop iterations in case choiceInput runs out of room for characters.
				break;
		}
	}
}

void printInstructions(void) { //Prints instruction manual. Use q to quit.
							   //print the user manual
}

void exponent(void) { //Scans in base and exponent, calculates power (1 digit max per scan).
					  //base, exponent, power
}

void multiplication(void) { //Scans in factors, calculates product (15 digit max per scan).
							//factorOne, factorTwo, product
}

void division(void) { //Scans in divisor and dividend, calculates quotient and remainder (15 digit max per scan).
	//float divisor, dividend, float* quotient, float* remainder
}

void addition(void) { //Scans in two addends, calculates  sum (15 digit max per scan).
	int continueOneLoop = 1;
	int continueTwoLoop = 1;
	int addendOneError = 1; //1 = no error, 0 = error.
	int addendTwoError = 1; //1 = no error, 0 = error.
	char addendOneString[MAX] = {0};
	char addendTwoString[MAX] = {0};
	int addendOne = 0;
	int addendTwo = 0;
	int sum = 0;

	while(continueOneLoop == 1) { //Get addendOne.
		printf(">Type addend one below.\n>");
		while((getchar()) != '\n')
			;										   //Clears input buffer of stray characters in case user inputted more than 15 characters in previous iteration of while loop.
		numberScan(addendOneString);				   //Scans input string into addendOneString.
		addendOneError = integerTest(addendOneString); //Looks for non-digit characters in AddendOneString.
		if(addendOneError == 0) {
			invalid();					  //Prints error message.
			emptyString(addendOneString); //Empty the contents of addendOneString for reuse.
			addendOneError = 1;
		} else if(lengthTest(addendOneString) == 0) {	 //Checks length of string inside addendOneString.
			addendOne = convertInteger(addendOneString); //Convert "char* addendOneString" to "int addendOne".
			continueOneLoop = 0;						 //Exit addendOne's while loop.
		}
	}
	while(continueTwoLoop == 1) { //Get addendTwo.
		printf(">Type addend two below.\n>");
		while((getchar()) != '\n')
			;										   //Clears input buffer of stray characters in case user inputted more than 15 characters in previous iteration of while loop.
		numberScan(addendTwoString);				   //Scans input string into addendTwoString.
		addendTwoError = integerTest(addendTwoString); //Looks for non-digit character in addendTwoString.
		if(addendTwoError == 0) {
			invalid();					  //Prints error message.
			emptyString(addendTwoString); //Empty the contents of addendTwoString for reuse.
			addendTwoError = 1;
		} else if(lengthTest(addendTwoString) == 0) {	 //Checks length of string inside addendTwoString.
			addendTwo = convertInteger(addendTwoString); //Convert "char* addendTwoString" to "int addendTwo".
			continueTwoLoop = 0;						 //Exit addendTwo's while loop.
		}
	}
	sum = addendOne + addendTwo;
	printf(">Sum lies below.\n>%d\n", sum);
}

void subtraction(void) { //Scans in minuend and subtrahend, calculates  difference (15 digit max per scan).
	//float minuend, float subtrahend, float* difference
}

void emptyString(char *string) {			  //Overwrites 0 to each index of given string.
	for(int i = 0; i < strlen(string); i++) { //Overwrites 0 to each index of string.
		string[i] = 0;
	}
}

int convertInteger(char *string) { //Converts string to integer.
	int integer = 0;

	for(int i = 0; i < strlen(string); i++) {
		integer = integer + (string[i] - '0') * pow(10, strlen(string) - i - 1);
	}
	return (integer);
}

void invalid(void) { //Prints error message.
	puts(">Sorry, but that's not a valid choice.");
}

int integerTest(char *string) { //Looks for non-digit characters in string.
	int error = 1;				//1 = no error, 0 = error.

	for(int i = 0; i < strlen(string); i++) { //Looks for non-digit characters in string.
		error = isdigit(string[i]);
		if(error == 0) {
			break;
		}
	}
	return (error);
}

void numberScan(char *string) { //Scans up to 16 characters into string.
	scanf("%16s", string);		//fscanf() will consume a string up to 16 characters long.
}

int lengthTest(char *string) { //Checks length of string.
	int error = 0;			   //0 = no error, 1 = error.

	if(strlen(string) > MAX - 1) {
		puts("Sorry, but that string is too long.");
		emptyString(string); //Empty the contents of string for reuse.
		error = 1;
	}
	return (error);
}
