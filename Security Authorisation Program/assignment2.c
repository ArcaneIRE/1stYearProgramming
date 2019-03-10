/* Assignment 2: Security Authorisation Program

This is an encryption and decryption based program. It displays a menu to the
user, which they can choose an option from that lets them do one of 5 things;

	1. Enter a code.
	2. Encrypts their code and verifies if it matches the authorised access code.
	3. Decrypt the code.
	4. Display the number of times the code has been entered successfully,
	and incorrectly.
	5. Exit the program.

Each menu option is implemented in it's own function. All parameters are
passed by reference.

Author: David Corcoran
Date Last Modified: 09/03/2019
Compiler: GCC
Version: N/A
*/

#include <stdio.h>

#define CODE_SIZE 4
#define MIN_VALUE 0
#define MAX_VALUE 9
#define ENCRYPTION_INCREASE 1

void inputCode(int userCode[]);
void encryptCode(int userCode[]);
int verifyCode(int accessCode[], int userCode[]);
void decryptCode(int userCode[]);
void displayVerificationTotals(int *successfulAttempts, int *failedAttempts);

int main () {
	int accessCode[CODE_SIZE] = {4, 5, 2, 3}; //The initial code
	int userCode[CODE_SIZE] = {}; //Stores the user's entered code.
	char menuChoice = '0'; //0 represents no choice.
	char codeState = 'n'; //n = New, u = Unenencrypted, e = Encrypted.
	char *codeStatePointer = &codeState;
	int successfulAttempts = 0;
	int *successfulAttemptsPointer = &successfulAttempts;
	int failedAttempts = 0;
	int *failedAttemptsPointer = &failedAttempts;

	printf("//// Security Authorisation Program \\\\\\\\");
	do {
		//Menu Section
		printf(	"\n\n################################\n"
					"###           MENU           ###"
					"\n################################\n\n"
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
				*codeStatePointer = 'u'; //Code is marked as inputted, but unencrypted.
				break;
			case '2': //Encrypt and attempt verification.
				if ( *codeStatePointer == 'u') {
					encryptCode(userCode);
					*codeStatePointer = 'e'; //Code is marked as encrypted.
					if (verifyCode(accessCode, userCode) == 1) {
						successfulAttempts++;
					} else {
						failedAttempts++;
					} //End inner if else
				} else {
					printf("\nCancelled. You must have an unencrypted code entered to do this.");
				} //End outer if else
				break;
			case '3': //Decrypt code
				if ( *codeStatePointer == 'e') {
					decryptCode(userCode);
					*codeStatePointer = 'u'; //Code is marked as unencrypted.
				} else {
					printf("\nCancelled. You must have an encrypted code to do this.");
				}
				break;
			case '4': //View No. of tries
				displayVerificationTotals(successfulAttemptsPointer, failedAttemptsPointer);
				break;

			default:
				if (menuChoice != '5') {
					printf(	"\nPlease only enter single digits between 1-5 (inclusive) "
								"and try again.");
				} //End if

				break;
		} //End Switch

	} while (menuChoice != '5'); //End do while

	printf("\nProgram wil now Exit.\n");

	return 0;
} //End main

/* Input Code
Inputs 4 integers into an array, validates them, displays the array to
the user then returns to main.
*/
void inputCode(int userCode[]) {
	int i; //iterator
	char validated = 'n'; //n for no, y for yes.

	while (validated != 'y') {
		//Input numbers
		printf(	"\nPlease enter a 4 digit passcode with each digit followed by enter.\n"
					"Only numbers %d-%d are accepted. Letters are treated as 0.\n", MIN_VALUE, MAX_VALUE);
		for (i=0; i < CODE_SIZE; i++) {
			scanf("%d", (userCode+i));
			fflush(stdin); //Clears newline from input buffer
		} //End for

		/*Validation
		Checks if anything entered is a*/
		validated = 'y'; //Changes to 'n' if an error is found.
		for (i=0; i < CODE_SIZE; i++) {
			if ( (userCode[i] > MAX_VALUE) || (userCode[i] < MIN_VALUE) ) {
				printf("\nCancelled. Please only enter single digits between %d-%d (inclusive).\n", MIN_VALUE, MAX_VALUE);
				validated = 'n';
				break;
			} //End if
		} //End for
	} //end while

	//Displays new code
	printf("\nSuccess. Your new code is ");
	for (i=0; i < CODE_SIZE; i++) {
		printf("%d", *(userCode+i));
	} //End for
	printf(".");

	return;
} //End inputCode

/* Encrypt Code
Swaps the 1st and 3rd numbers. Swaps the 2nd and 4th numbers.
Adds 1 to every number. Numbers are treated as Mod 10(0-9).
*/
void encryptCode(int userCode[]){
	int i; //Iterator.
	int temp; //Used as holder variable for swaps.

	//Swaps first and third digits.
	temp = *(userCode+0);
	*(userCode+0) = *(userCode+2);
	*(userCode+2) = temp;

	//Swaps second and fourth digits.
	temp = *(userCode+1);
	*(userCode+1) =*(userCode+3);
	*(userCode+3) = temp;

	//Adds 1 to each digit and changes any values of 10 to 0.
	for (i=0; i < CODE_SIZE; i++) {
		userCode[i] = (*(userCode+i) + ENCRYPTION_INCREASE) % 10;
	} //End for

	//Displays encrypted code.
	printf("\nEncryption successful. Your encrypted code is ");
	for (i=0; i < CODE_SIZE; i++) {
		printf("%d", *(userCode+i));
	} //End for
	printf(".");

	return;
} //End encryptCode

/* Verify code
Compares user's encrypted code against the access code one digit at a time.
Returns succcess or fail.
*/
int verifyCode(int accessCode[], int userCode[]){
	int i; //iterator
	char verified = 'y'; // y = verified, n = not verified.

	for (i=0; i < CODE_SIZE; i++) {
		if (*(userCode+i) != *(accessCode+i)) {
			verified = 'n'; //Only changes if a pair does not match.
			printf("\n\nVerification failed. Your code does not match the access code.");

			return -1;
		} //End if
	} //End for

	printf("\n\nVerification successful. Your code matches the access code.");

	return 1;
} //End verifyCode

/* Decrypt Code
Runs the encryption algorithm in reverse.
Subracts 1 from each digit, amking
*/
void decryptCode(int userCode[]){
	int i; //Iterator.
	int temp; //Used as holder variable for swaps.

	//Subtract 1 from every number.
	for (i=0; i < CODE_SIZE; i++) {
		*(userCode+i) = (*(userCode+i) - ENCRYPTION_INCREASE);
		if (*(userCode+i) == -1){
			*(userCode+i) = 9;
		} //End if
	} //End for

	//Swaps the second and fourth digits back.
	temp = *(userCode+1);
	*(userCode+1) = *(userCode+3);
	*(userCode+3) = temp;

	//Swaps first and third digits back.
	temp = *(userCode+0);
	*(userCode+0) = *(userCode+2);
	*(userCode+2) = temp;

	//Displays unencrypted code.
	printf("\nDecryption successful. Your unencrypted code is ");
	for (i=0; i < CODE_SIZE; i++) {
		printf("%d", *(userCode+i));
	} //End for
	printf(".");

	return;
} //End decryptCode

void displayVerificationTotals(int *successfulAttemptsPointer, int *failedAttemptsPointer) {
	printf("\n\nSuccessful attempts: %d", *successfulAttemptsPointer);
	printf("\nFailed attemps: %d", *failedAttemptsPointer);

	return;
} //End displayVerificationTotals
