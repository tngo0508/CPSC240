#include <iostream>

using namespace std;

int main()
{
	int a[5] = { 9, 3, 22, 8, 1 };
	int i, j, temp;

	cout << "Array before sort: ";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	_asm
	{
		mov		eax, 0;
		mov		ebx, 0;
		mov		i, 0;
		mov		j, 0;
	forLoop:
		cmp		i, 4;
		Je		done;

	innerLoop:
		mov		ecx, 4;
		sub		ecx, i;
		cmp		j, ecx;
		Je		done2;
		 
	//compare between a[j] and a[j+1]
		mov		eax, [a + ebx];
		mov		temp, eax;
		add		ebx, 4;
		mov		eax, [a + ebx];
		cmp		temp, eax;
		Jg		true1;
		inc		j;
		Jmp		innerLoop;
	true1:
		sub		ebx, 4;
		mov		[a + ebx], eax;
		add		ebx, 4;
		mov		eax, temp;
		mov		[a + ebx], eax;
		inc		j;
		Jmp		innerLoop;
	done2:
	//reset i, ebx for the next innerLoop
		mov		ebx, 0;
		mov		eax, 0;
		mov		j, 0;
		inc		i;						//i++
		Jmp		forLoop;
	done:
	}

	cout << endl;
	cout << "Array after sorted: ";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}


	cout << endl;

	system("pause");
	return 0;
}