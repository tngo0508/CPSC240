#include <iostream>

using namespace std;

int main()
{
	int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 
		9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
	int numOfShirts = 0, 
		medShirts = 0, 
		shortSleeves = 0, 
		redShirts = 0, 
		i = 0;
	_asm
	{
		mov		eax, 0;
		mov		ebx, 0; 
		mov		i, 0;
	forLoop1:
		cmp		i, 18;
		Je		done1;
		add		eax, [a + ebx];
		add		ebx, 4;
		inc		i;
		Jmp		forLoop1;
	done1:
		mov		numOfShirts, eax;

		mov		eax, 0;
		mov		ebx, 8;
		mov		i, 0;
	forLoop2:
		cmp		i, 3;
		Je		done2;
		add		eax, [a + ebx];
		inc		i;
		add		ebx, 24;
		Jmp		forLoop2;
	done2:
		mov		medShirts, eax;

		mov		eax, 0;
		mov		ebx, 12;
		mov		i, 0;
	forLoop3:
		cmp		i, 3;
		Je		done4;
		add		eax, [a + ebx];
		inc		i;
		add		ebx, 24;
		Jmp		forLoop3;
	done4:
		add		medShirts, eax;

		mov		eax, 0;
		mov		ebx, 0;
		mov		i, 0;
	forLoop4:
		cmp		i, 9;
		Je		done5;
		add		eax, [a + ebx];
		inc		i;
		add		ebx, 8;
		Jmp		forLoop4;
	done5:
		mov		shortSleeves, eax;

		mov		eax, 0;
		mov		ebx, 0;
		mov		i, 0;
	forLoop5:
		cmp		i, 6;
		Je		done6;
		add		eax, [a + ebx];
		inc		i;
		add		ebx, 4;
		Jmp		forLoop5;
	done6:
		mov		redShirts, eax;
	}
	
	cout << "Total number of all shirts: " << numOfShirts << endl;
	cout << "Total number of medium size shirts: " << medShirts << endl;
	cout << "Total number of short sleeves shirts: " << shortSleeves << endl;
	cout << "Total number of RED shirts: " << redShirts << endl;

	cout << endl;
	system("pause");
	return 0;
}