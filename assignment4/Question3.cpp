#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

char YesNo, choice, done;
int x, y, ans, numCorrect, numWrong;

void generateXY();
void displayCorrect() { cout << "             CORRECT\n"; }
void displayWrong() { cout << "             WRONG\n"; }
void continueTN();
void displayQuesAd();
void displayQuesSub();
void displayMenu();
void getChoice();
void isDone();
void displayNumAns();

int main()
{
	displayMenu();

	_asm
	{
	//do-while loop
	doLoop:
		call	getChoice;

	//inner while loop
	innerLoop:
		call	generateXY;
		cmp		choice, 'a';            //comopare choice == 'a'?
		Jne		Subtraction;            //if choice is not equal 'a', jump to Subtraction
		call	displayQuesAd;
	
		mov		eax, x;                 //eax = x
		add		eax, y;                 //eax = x + y
		Jmp		check;                  //jump to check

	Subtraction:
		call	displayQuesSub;
		mov		eax, x;                 //eax = x
		sub		eax, y;                 //eax = x - y

	check:
		cmp		eax, ans;               //compare eax == ans?
		Je		showCorrect;            // if eax = ans, jump to showCorrect

		call	displayWrong;
		inc		numWrong;               //numWrong++
		Jmp		continueLoop;           //jump to continueLoop

	showCorrect:
		call	displayCorrect;
		inc		numCorrect;             //numCorrect++
		Jmp		continueLoop;           //jump to continueLoop
	
	continueLoop:
		call	continueTN;
		cmp		YesNo, 'y';             //compare YesNo == 'y'?
		Je		innerLoop;              //jump to innerLoop if YesNo = 'y'
		cmp		YesNo, 'Y';             //compare YesNo == 'Y'?
		Je		innerLoop;              //jump to innerLoop if YesNo = 'Y'
		
		call	displayNumAns;

		mov		numCorrect, 0;          //numCorrect = 0
		mov		numWrong, 0;            //numWrong = 0

		call	isDone;
		cmp		done, 'n';              //compare done == 'n'?
		Je		doLoop;                 //if done = 'n', jump back to doLoop
		cmp		done, 'N';              //compare done == 'N'?
		Je		doLoop;                 //if done = 'N', jump back to doLoop
	}

	cout << "       Have a nice day\n";

	cout << endl;
	system("pause");
	return 0;
}

void displayMenu()
{
	cout << "--------Practice Addition & Subtraction-----------------\n"
		<< "a.   Practice Addition\n"
		<< "b.   Practice Subtraction\n";
}

void getChoice()
{
	cout << "       Enter your choice(a/b): ";
	cin >> choice;
}

void isDone()
{
	cout << "     Are you done(y/n)? ";
	cin >> done;
}

void generateXY()
{
	srand((unsigned int)time(NULL));
	x = rand() % 99 + 1;
	y = rand() % 99 + 1;
}

void continueTN()
{
	cout << "             Continue(y/n) ";
	cin >> YesNo;
}

void displayQuesAd()
{
	cout << "          " << x << " + " << y << " = ? ";
	cin >> ans;
}

void displayQuesSub()
{
	cout << "          " << x << " - " << y << " = ? ";
	cin >> ans;
}

void displayNumAns()
{
	cout << "       No. of CORRECT answer = " << numCorrect << endl;
	cout << "       No. of WRONG answer = " << numWrong << endl;
}