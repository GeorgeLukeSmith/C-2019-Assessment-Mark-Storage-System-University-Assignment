/***********************************************************************
 * AMSS Version Level 3-43.c
 * Assessment Mark Storage System
 * George L Smith
 * Version Level 3
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 75
#define MIN 1
#define NAME_LEN 25
#define COURSEWORK 3

void printIntro(void);
bool vNum(int low, int high, int num);
void printMainMenu(void);
int retakeNum(int low, int high);
void printEntMarksMenu(void);
void printSupMenu(void);
void printSupEntMarksMenu(void);
void formatArray(int array[][MAX], int formatNum);
int getNum(int min, int max);
void getNames(int num, char array[NAME_LEN][MAX]);
int startUp(char sName[][MAX], int coursework[][MAX]);
int mainMenuF(void);
int enterMarksF(char sName[][MAX], int coursework[][MAX], int sNum);
void enterContinue(void);
void inMarks(char sName[][MAX], int work[][MAX], int sNum, int cNum);
void markFull(char name[][MAX], int wrk[][MAX], int sNum, int itr);
void entMarks(char name[][MAX], int wrk[][MAX], int sN, int cN, int it);
void dispMarksF(char sName[][MAX], int coursework[][MAX], int sNum);
void printAllNames(char sName[][MAX], int sNum);
bool verifyPin(int pin);
int changePin(void);
void printNamesMarks(char name[][MAX], int wrk[][MAX], int num);
void sChangeMark(char name[][MAX], int wrk[][MAX], int num);
int addStudent(char name[][MAX], int num);
void changeName(char name[][MAX], int num);

int main(void)
{
	int studNum, input, pin = 1996;
	char studName[NAME_LEN][MAX];
	int crswrk[COURSEWORK][MAX];
	
	studNum = startup(studName, crswrk);
	
	while(true)
	{
		input = mainMenuF();
		switch(input)
		{
			case 1:				
				enterMarksF(studName, crswrk, studNum);
				break;	
			case 2:
				dispMarksF(studName, crswrk, studNum);
				break;
			case 3:
				if(verifyPin(pin) == 0)
				{
					break;
				}
				else
				{
					system("cls");
					printSupMenu();
					input = getNum(0,6);
					switch(input)
					{
						case 1:
							pin = changePin();
							break;
						case 2:
							sChangeMark(studName, crswrk, studNum);
							break;
						case 3:
							studNum = addStudent(studName, studNum);
							break;
						case 4:
							changeName(studName, studNum);
							break;
					}
					break;
				}
				break;
			case 4:
				system("cls");
				printf("Thank you for using A.M.S.S!\n");
				return 0;
		}
	}
}

	


/*prints intro screen*/
void printIntro(void)
{
	printf("\n       d8888         888b     d888          .d8888b.   ");
	printf("        .d8888b.\n");
	printf("      d88888         8888b   d8888         d88P  Y88b    ");
	printf("     d88P  Y88b\n");
	printf("     d88P888         88888b.d88888         Y88b.         ");
	printf("     Y88b.\n");
	printf("    d88P 888         888Y88888P888          \"Y888b.     ");
	printf("       \"Y888b.\n");
	printf("   d88P  888         888 Y888P 888             \"Y88b.   ");
	printf("          \"Y88b.\n");
	printf("  d88P   888         888  Y8P  888               \"888   ");
	printf("            \"888\n");
	printf(" d8888888888   d8b   888   \"   888   d8b   Y88b  d88P  d");
	printf(" 8b   Y88b  d88P\n");
	printf("d88P     888   Y8P   888       888   Y8P    \"Y8888P\"   ");
	printf(" Y8P    \"Y8888P\"\n");
	printf("\nWelcome to A.M.S.S. Assessment Mark Storage System\n");
	printf("Copyright © 2019, All Rights Reserved\n");
	enterContinue();	
}

/*checks that number inputted by the user is in the correct range*/
bool vNum(int low, int high, int num)
{
	if(low <= num&&num <= high)
	{
		return 0;
	}	
	else
	{
		return 1;
	}
}
/*prints main menu to the console*/
void printMainMenu(void)
{
	printf("Please Choose an Option (type option number");
	printf(" and press ENTER)\n\n");
	printf("1. Enter Marks\n\n");
	printf("2. Display Student Marks\n\n");
	printf("3. Supervisor Mode\n\n");
	printf("4. Exit Program\n\n");
	printf("\nOption: ");	
}

/*retakes the number from the user after it fails initial verification*/
int retakeNum(int low, int high)
{
	int option;
	
	printf("\nERROR, Please only enter ");
	printf("NUMBERS between %d and %d", low, high);
	printf("\n\nInput: ");
	scanf("%d", &option);
	return option;
}
/*prints the text of the enter marks menu*/
void printEntMarksMenu(void)
{
	printf("Enter marks for Coursework... ");
	printf("(type option number and press ENTER)\n\n");
	printf("1. Coursework 1\n\n");
	printf("2. Coursework 2\n\n");
	printf("3. Coursework 3\n\n");
	printf("4. Return to Main Menu\n\n");
	printf("option: ");
}
/*prints the text of the supervisor menu*/
void printSupMenu(void)
{
	printf("Please enter option number (Type number and press ");
	printf("ENTER)\n\n");
	printf("1. Change PIN\n");
	printf("2. Change Student Mark\n");
	printf("3. Add Student\n");
	printf("4. Change Student Name\n");
	printf("5. Return to Main Menu\n\n");
	printf("Option: ");
	
}
/*sets the entire array to a number specified by  the user*/
void formatArray(int array[][MAX], int formatNum)
{
	int num, count;
	
	for(num = 0; num < COURSEWORK; num++)
	{
		for(count = 0; count < MAX; count++)
		{
			array[num][count] = formatNum;
		}
	}
}

/*gets a number from the user and verifies that it is in
the required range, asking the user to reinput if not*/
int getNum(int min, int max)
{
	int num;
	
	while(scanf("%d", &num) !=1)
	{
		num = retakeNum(min, max);
		getchar();
	}
	while(vNum(min, num, max) == 0)
	{
		num = retakeNum(min, max);
		getchar();
	}
	return num;

}

/*takes a name inputed by the user and stores it in an array*/
void getNames(int num, char array[NAME_LEN][MAX])
{
	int count;
	
	for(count = 0; count < num; count++)
	{
		printf("Student %.2d/%.2d: ", count +1, num);
		scanf("%25[^\n]", array[count]);
	}
}

/*runs when the program is opened, prints intro screen and takes 
paramaters student numbers and names*/
int startup(char sName[][MAX], int coursework[][MAX])
{
	int sNum;
	formatArray(coursework, -1);
	printIntro();
	printf("Please enter the number of students: ");
	sNum = getNum(MIN, MAX);
	printf("\nPlease Enter Student names\n\n");
	getNames(sNum, sName);
	return sNum;
}

/*prints the main menu and takes the users option number*/
int mainMenuF()
{
	int num;
	
	system("cls");
	printMainMenu();
	num = getNum(1,5);
	
	return num;
}
/*function for option 1: Enter mark*/
enterMarksF(char sName[][MAX], int coursework[][MAX], int sNum)
{
	int crswrkNum, input, itr;
	
	while(true)	
	{
		system("cls");
		printEntMarksMenu();
		input = getNum(1,5);
		if(input < 4)
		{
			crswrkNum = input -1;
			system("cls");
			
			inMarks(sName, coursework, sNum, crswrkNum);
			enterContinue();
		}
	break;
	}
}
/*pauses the program until the user presses enter*/
void enterContinue(void)
{
	printf("\npress ENTER to continue");
	getchar();
	system("cls");
}
/*gets the number of the coursework and checks whether a grade has
already been entered*/
void inMarks(char sName[][MAX], int work[][MAX], int sNum, int cNum)
{
	int itr, input;
	for(itr = 0; itr < sNum; itr++)
	{
		if(work[cNum][itr] != -1)
		{
			markFull(sName, work, sNum, itr);
		}
		else
		{
			entMarks(sName, work, sNum, cNum, itr);								
		}		
	}
}	
/*informs the user that a mark has already been entered*/
void markFull(char name[][MAX], int wrk[][MAX], int sN, int it)
{
	printf("Student %.2d: %s\n", it + 1, name[it]);
	printf("Mark: Already entered\n\n");	
}

/*Takes the mark the enters and sends it to the array*/
void entMarks(char name[][MAX], int wrk[][MAX], int sN, int cN, int it)
{
	int input;
	
	printf("Student %.2d: ", it + 1);
	printf("%s\n", name[it]);
	printf("Mark: ");
	scanf("%d", &input);
	printf("\n");
	while(vNum(0, input, 101) == 0)
	{
		input = retakeNum(0, 100);
	}
		wrk[cN][it] = input;
}
/*displays the mark of the requested student*/
void dispMarksF(char sName[][MAX], int crswrk[][MAX], int sNum)
{
	int itr, input, ovrlGrade;
	while(true)
	{
		system("cls");
		printf("Students:\n\n");
		printAllNames(sName, sNum);
		printf("\nType Student Number and press ENTER\n");
		printf("input: ");
		input = getNum(0, sNum+1) -1;
		ovrlGrade = crswrk[0][input]*0.2 + 
		crswrk[1][input]*0.3 + crswrk[2][input]*0.5;
		printf("\n%.2d: %s\n\n", input + 1, sName[input]);
		printf("Coursework 1: \t%3d\nCoursework 2: \t%3d\nCoursework 3:"
				" \t%3d\n", 
				crswrk[0][input], crswrk[1][input], crswrk[2][input]);
		printf("\nOverall Grade: \t%3d\n", ovrlGrade);
		enterContinue();
		break;
	}
}
/*prints all names in the array to the console*/
void printAllNames(char sName[][MAX], int sNum)
{
	int itr;
	for(itr = 0; itr < sNum; itr++)
		{
			printf("%.2d: %s\n", itr+1, sName[itr]);	
		}
}
/*checks if pin number is correct and returns true or false*/
bool verifyPin(int pin)
{
	int pinAttempt;
	
	system("cls");
	printf("Please enter PIN Number and press Enter:\n\n");
	printf("PIN: ");
	pinAttempt = getNum(1000, 9999);
	if(pinAttempt != pin)
	{
		printf("Incorrect PIN!\n\n");
		enterContinue();
		return 0;
	}
	else
	{
		return 1;
	}
}

/*change the supervisor mode pin*/
int changePin(void)
{
	int newPin;
	
	printf("\nPlease enter new PIN: ");
	newPin = getNum(1000, 1996);
	printf("PIN updated\n");
	enterContinue();
	return newPin;
}

/*prints all student names and marks to the console*/
void printNamesMarks(char name[][MAX], int wrk[][MAX], int num)
{
	int itr;
	
	printf("Students:\n\n");
	for(itr = 0; itr < num; itr++)
	{
		printf("%.2d: ", itr+1);
		printf("%s\n", name[itr]);
		printf("Coursework 1: ");
		printf("%d\n", wrk[0][itr]);
		printf("Coursework 2: ");
		printf("%d\n", wrk[1][itr]);
		printf("Coursework 3: ");
		printf("%d\n\n", wrk[2][itr]);
	}
}

/*allows the user to change a students mark for any of the
courseworks*/
void sChangeMark(char name[][MAX], int wrk[][MAX], int num)
{
	int input, student, wrkNum;
	system("cls");
	printNamesMarks(name, wrk, num);
	printf("\nType Student Number ");
	printf("and press ENTER\n");
	input = getNum(0, num+1);
	student = input -1;							
	printf("%.2d: ", input);
	printf("%s\n", name[student]);
	printf("Coursework 1: ");
	printf("%d\n", wrk[0][student]);
	printf("Coursework 2: ");
	printf("%d\n", wrk[1][student]);
	printf("Coursework 3: ");
	printf("%d\n\n", wrk[2][student]);
	printf("Select grade you wish to change\n");
	printf("\nOption: ");
	wrkNum = getNum(1, 4) -1;
	printf("Please enter new grade: ");
	input = getNum(0, 101);
	wrk[wrkNum][student] = input;
}

/*allows the user to add a student*/
int addStudent(char name[][MAX], int num)
{
	system("cls");
	if(num < MAX)
	{
		num++;
		printf("Please enter name of new Student: ");
		scanf("%25[^\n]", name[num-1]);
		printf("\nNew student entered!\n");
		enterContinue();
		return num;
	}
	else
	{
		printf("Maximum students reached\n");
		enterContinue();
	}
}

/*allows the user to change the name of a student*/
void changeName(char name[][MAX], int num)
{
	int input;
	
	system("cls");
	printAllNames(name, num);
	printf("Please type number of student ");
	printf("who's name you wish to change\n\n");
	input = getNum(0, 5);
	input = input - 1;
	printf("%s\n", name[input]);
	printf("Please enter new name: ");
	scanf("%25[^\n]", name[input]);
	printf("Name change confirmed\n");
	enterContinue();
}
