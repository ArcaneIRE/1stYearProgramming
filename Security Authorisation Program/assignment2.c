/* Assignment 2: Security Authorisation Program

This is an encryption and decryption based program. It displays a menu to the
user, which they can choose an option from that lets them do one of 5 things;

	1. Enter a code.
	2. Encrypt this code and verify if it matches the authorised access code.
	3. Decrypt the code.
	4. Display the number of times the code has been entered successfully,
	and incorrectly.
	5. Exit the program.

Each menu option is implemented in it's own function. All parameters are
passed by reference. All writing involving arrays uses pointer notation(Arr+2)
and not subscript notation (Arr[2]).

Author: David Corcoran
Date Last Modified: 09/03/2019
Version: N/A
*/

#include <stdio.h>

#define CODE_SIZE 4

void inputCode(int userCode[]);
void encryptCode(int userCode[]);
int verifyCode(int userCode[]);
void decryptCode(int userCode[]);
void displayVerificationTotals();

int main () {
	int accessCode[CODE_SIZE] = {4, 5, 2, 3}; //The initial code
	int userCode[CODE_SIZE] = {}; //Stores the user's entered code.
	char menuChoice = '0'; //0 represents no choice.

	printf("//// Security Authorisation Program \\\\\\\\");

	do {
		//Menu Section
		printf(	"\n### MENU ###\n\n"
					"1. Enter a code.\n"
					"2. Encrypt and attempt to verify your code.\n"
					"3. Decrypt your code.\n"
					"4. View number of successful and unsuccesful entries.\n"
					"5. Exit Program.\n"
					"\nPlease enter your choice followed by enter.\n");
		menuChoice = getchar();
		fflush(stdin); //Clears newline from input buffer

		switch (menuChoice) {
			case '1': //Enter a code
				inputCode(userCode);
				break;
			case '2': //Encrypt and attempt verification
				encryptCode(userCode);
				verifyCode(userCode);
				break;
			case '3': //Decrypt code
				decryptCode(userCode);
				break;
			case '4': //View No. of tries
				inputCode(userCode);
				break;
			default:
				break;
		}

	} while (menuChoice != '5');

	printf("Program wil now Exit");

	return 0;
}

/* Input Code
Takes the inputted numbers and places them into a string.
*/
void inputCode(int userCode[]) {
	printf(	"\nPlease enter a 4 digit passcode followed by an enter.\n"
				"Only numbers 0-9 are accepted.\n");
	scanf("%s", &userCode);
	fflush(stdin); //Clears newline from input buffer

	return;
}

/* Encrypt Code
Swaps the 1st and 3rd numbers. Swaps the 2nd and 4th numbers.
Adds 1 to every number. Numbers are treated as Mod 10(0-9).
*/
void encryptCode(int userCode[]){
	int temp;
	int i;
	for (i = 0; i < CODE_SIZE; i++) {
		printf("%d", userCode[i]);
	}
	temp = userCode[1];
	userCode[1] = userCode[3];
	userCode[3] = userCode[1];

	temp = userCode[2];
	userCode[2] = userCode[4];
	userCode[4] = userCode[2];

	for (i = 0; i < CODE_SIZE; i++) {
		userCode[i] = (userCode[i] + 1) % 10;
	}

	for (i = 0; i < CODE_SIZE; i++) {
		printf("%d", userCode[i]);
	}
}
int verifyCode(int userCode[]){}
void decryptCode(int userCode[]){}
