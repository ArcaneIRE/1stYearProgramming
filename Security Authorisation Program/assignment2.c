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

void inputCode(int[]);
void encryptCode(int[]);
void verifyCode(int[]);
void decryptCode(int[]);
void displayVerificationTotals();

int main () {
	int accessCode[CODE_SIZE] = {4, 5, 2, 3}; //The initial code
	int userCode[CODE_SIZE] = {}; //Stores the user's entered code.
	char menuChoice = '0'; //0 represents no choice.

	printf("//// Security Authorisation Program \\\\\\\\\n");

	do {
		//Menu Section
		printf(	"### MENU ###\n\n"
					"1. Enter a code.\n"
					"2. Encrypt and attempt to verify your code.\n"
					"3. Decrypt your code.\n"
					"4. View number of successful and unsuccesful entries.\n"
					"5. Exit Program.\n"
					"\nPlease enter your choice followed by enter.\n");
		menuChoice = getchar();
		fflush(stdin); //Clears newline from input buffer

		switch (menuChoice) {
			case '1':
				inputCode(userCode);
				break;
		}

	} while (menuChoice != '5');

	return 0;
}

void inputCode(int[]) {
	return;
}
