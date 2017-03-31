#include <iostream>
#include <string>

using namespace std;

char ans;
int number, a = 1000, b = 100, c = 10, s = 2;

void askForPin()
{
	cout << "Enter a four digit int PIN number: ";
	cin >> number;
}

void displayValid()
{
	cout << number << " is a valid PIN number\n";
}

void displayInValid()
{
	cout << number << " is not a valid PIN number\n";
}

void continueTN()
{
	cout << "Do you want to try again(y/n)? ";
	cin >> ans;
}

int main()
{
	_asm
	{
	whileLoop:
		call	askForPin;

	//calculation for sum of 4 digits in the number
		mov		eax, number;		//eax = number
		cdq;						//eax:edx = number
		idiv	a;					//eax = number/1000, edx = number%1000
		mov		ebx, eax;			//ebx = first digit
		mov		eax, edx;			//eax = number%1000(last 3 digits), reassign eax for division
		cdq;                
		idiv	b;					//eax = last 3 digits/100
									//eax = second digit, edx = the rest
		add		ebx, eax;			//ebx = first + second
		mov		eax, edx;			//eax = (last 2 digits), reassign eax for division
		cdq;
		idiv	c;					//eax = last 2 digits/10
									//eax = third, edx = fourth
		add		ebx, eax;			//ebx = first + second + third
		add		ebx, edx;			//ebx = total of digits
	
	//determine if total of digits is even or odd
		mov		eax, ebx;			//reassign eax for division, eax = total of digits
		cdq;						//eax:edx = total of digits
		idiv	s;					//eax = total/2, edx = total % 2
		cmp		edx, 0;				//check if total is even or odd
		Je		evenNumber;
	
	//result and continue display
		call	displayInValid;
		call	continueTN;
		cmp		ans, 'y';
		Je		whileLoop;
		cmp		ans, 'Y';
		Je		whileLoop;
		Jmp		done;
	evenNumber:
		call	displayValid;
		call	continueTN;
		cmp		ans, 'y';
		Je		whileLoop;
		cmp		ans, 'Y';
		Je		whileLoop;
		Jmp		done;
	done:
	}

	cout << endl;
	system("pause");
	return 0;
}