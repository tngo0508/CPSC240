#include <iostream>

using namespace std;

int score = 0,
	average = 0,
	counts = 0;

void readData();

int main()
{
	cout << "Let's computer your score's average:\n";

	_asm
	{
		mov		ebx, 0;				//ebx = 0
	else1:
		call	readData;      
		mov		eax, score;			//eax = score
		add		ebx, eax;			//ebx = ebx + score
		inc		counts;				//counts++
		cmp		score, -1;			//score == -1?
		Jne		else1;				//jump back to else1 if score is not equal -1
		Je		true1;
	true1:
		dec		counts;				//keep track of counts
		add		ebx, 1;				//keep track of total
		mov		eax, ebx;			//eax = ebx = total
		cdq;						//edx:eax = total
		idiv	counts;				//eax = total/counts, edx = total%counts
		mov		average, eax;		//average = total/counts
	}

	cout << "\t   Your average is " << average << endl;

	cout << endl;
	system("pause");
	return 0;
}

void readData()
{
	cout << "\tEnter your score(-1 to stop): ";
	cin >> score;
}