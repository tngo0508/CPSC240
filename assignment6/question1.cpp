#include <iostream>

using namespace std;

int main()
{
	int i;
	int numOfshirts, numOfLarge, numOfBlack;
	int a[4][4] =
	{
		{ 10, 20, 30, 40 },
		{ 20, 10, 40, 30 },
		{ 5, 15, 20, 25 },
		{ 30, 25, 20, 15 },
	};

	_asm
	{
		mov		eax, 0;
		mov		ebx, 0;				//always use ebx for byte offset
		mov		i, 0;
	loop1:
		cmp		i, 16;
		Je		done1;
		add		eax, [a + ebx];
		inc		i;
		add		ebx, 4;
		Jmp		loop1;
	done1:
		mov		numOfshirts, eax;

		mov		eax, 0;
		mov		ebx, 8;
		mov		i, 0;
	loop2:
		cmp		i, 4;
		Je		done2;
		add		eax, [a + ebx];
		inc		i;
		add		ebx, 16;
		Jmp		loop2;
	done2:
		mov		numOfLarge, eax;

		mov		eax, 0;
		mov		ebx, 48;
		mov		i, 0;
	loop3:
		cmp		i, 4;
		Je		done3;
		add		eax, [a + ebx];
		inc		i;
		add		ebx, 4;
		Jmp		loop3;
	done3:
		mov		numOfBlack, eax;
	}

	cout << "The total number of shirts: " << numOfshirts << endl;
	cout << "The total number of Large shirts: " << numOfLarge << endl;
	cout << "The total number of Black shirts: " << numOfBlack << endl;
	cout << endl;
	system("pause");
	return 0;
}