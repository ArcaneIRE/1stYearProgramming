/* Assignment 1: ATM Machine

This program will allow users to manage their PIN as if using an ATM.
Users must be able to:
	1. Verify if their PIN is correct.
	2. Change their PIN.
	3. Display the number of times the PIN was entered correctly and incorrectly.
	4. Exit the program.

It should re-display the menu after each option has completed and only terminate when
the command is given. It must also have responses to input error.

Author: David Corcoran
Compiler: GCC
Date: 04/11/18
*/

#include <stdio.h>
#define PINLENGTH 4

int main() {

	int endCheck;
	char menuChoice;
	char pin[PINLENGTH]; //The user's actual pin
	char verifyPinArr[PINLENGTH]; //Used in option 1 when checking if the entered pin is correct
	char changePinArr1[PINLENGTH]; //Used when changing the pin
	char changePinArr2[PINLENGTH]; //Used when changing the pin
	int correctEntries; //counts the number of correct entries
	int incorrectEntries; //counts the number of incorrect entries
	int i; //used in for loops
	int invalidCheck; //Used when checking for invalid characters in an entry
	int incorrectCheck; //Used when checking for a match in option 1

	pin[0] = '1'; //These lines set the default PIN
	pin[1] = '2';
	pin[2] = '3';
	pin[3] = '4';
	endCheck = 0;//Changes to 1 when option 4 is chosen.
	correctEntries = 0;//No correct entries have been counted when program
	incorrectEntries = 0;//No incorrect entries have been counted when program begins

	printf("ATM PIN Management System\n");

	do {
		//Displays menu
		printf("\n\nWelcome. Please select an option from the menu below by typing a number then pressing enter.\n\n");
		printf("1. Verify PIN.\n");
		printf("2. Change PIN.\n");
		printf("3. View number of correct and incorrect PIN entries.\n");
		printf("4. End Program.\n\n");
		fflush(stdin);
		menuChoice = getchar();//Inputs the user's choice

		switch(menuChoice) { //Proceeds based on input
			case '1': //When user selects verify PIN1
				incorrectCheck = 0;
				invalidCheck = 0;
				printf("\nOption 1: Verify PIN.\n");
				printf("Please enter your PIN followed by the enter key.\n");
				fflush(stdin);
				scanf("%s", &verifyPinArr);
//
for (i = 0; i < PINLENGTH; i++) {
	printf("%c", pin[i]);
}
//
				for (i = 0; i < PINLENGTH; i++) { //Checks if each
					if (invalidCheck == 0) {
						switch (verifyPinArr[i]) {
							case '0':
							case '1':
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':
							case '9':
								break;

							default:
								invalidCheck = 1;
								break;
						}//End switch
					}//End if
				}//End for loop

				if (invalidCheck == 0) {//Proceeds with different outcomes depending on whether an invalid character was discovered earlier
					for (i = 0; i < PINLENGTH; i++) {
						if (verifyPinArr[i] != pin[i]) {
							incorrectCheck = 1;
						}//End if
					}//End for
					if (incorrectCheck == 0) {
						printf("You have entered your PIN correctly.");
						correctEntries++;
					} else {
						printf("\nThe digits you entered did not match your PIN");
						incorrectEntries++;
					}//End else
				} else {
					printf("You entered an invalid character! Please only use digits between 0 and 9. This is counted as an incorrect entry.");
					incorrectEntries++;
				}//End if else
				break;//End case 1

			case '2': //When user selects change PIN
				invalidCheck = 0;
				incorrectCheck = 0;
				printf("\nOption 2: Change PIN.\n");
				printf("Please enter your new PIN.\n");
				scanf("%s", &changePinArr1);
				for (i = 0; i < PINLENGTH; i++) { //Checks if each digit is valid
					if (invalidCheck == 0) {
						switch (changePinArr1[i]) {
							case '0':
							case '1':
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':
							case '9':
								break;

							default:
								invalidCheck = 1;
								break;
						}//End switch
					}//End if
				}//End for loop
				printf("\nPlease re-enter your new PIN for verification\n");
				scanf("%s", &changePinArr2);
				for (i = 0; i < PINLENGTH; i++) { //Checks if each digit is valid
					if (invalidCheck == 0) {
						switch (changePinArr2[i]) {
							case '0':
							case '1':
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':
							case '9':
								break;

							default:
								invalidCheck = 1;
								break;
						}//End switch
					}//End if
				}//End for loop
				if (invalidCheck == 0) {//Proceeds with different outcomes depending on whether an invalid character was discovered earlier
					for (i = 0; i < PINLENGTH; i++) {
						if (changePinArr1[i] != changePinArr2[i]) { //checks if both new pins match
							incorrectCheck = 1;
						}//End if
					}//End for
					if (incorrectCheck == 0) {
						printf("\nYou have successfully changed your PIN.");
						for (i = 0; i < PINLENGTH; i++) { //Changes the PIN to the new one
							pin[i] = changePinArr1[i];
						}
					} else { //in the even that the two new entries do not match
						printf("\nYour two entries did not match. This PIN change attempt has failed.");
					}//End if else inner
				} else {
					printf("\nYou entered an invalid character! Please only use digits between 0 and 9. This PIN change attempt has failed.");
				}//End if else outer
				break;//End case 1

				break;//End case 2

			case '3': //when user selects view PIN entry count
				printf("\nOption 3: View number of correct and incorrect PIN entries.\n");
				printf("Correct Entries: %d\n", correctEntries);
				printf("Incorrect Entries: %d\n", incorrectEntries);
				break;

			case '4': //When user selects End Program
				endCheck = 1;//Changes loop condition to false
				break;

			default: //When input does not match menu options
				printf("\nNone of these inputs match a menu choice. Please try again.\n");
				break; //Restarts menu loop
		}//End switch
	} while ( endCheck != 1); //End do while

	printf("\nProgram has Ended.\n");

	return 0;
}//end main
