#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string floors;
short a, counter, floorNum, bin;
char x;
int y;

void displayBin()
{
	cout << "\nAx= ";
	short x = 1;
	x = x << 15; //x = 1000 0000 0000 0000
	short t;
	for (int i = 1; i < 17; i++)
	{
		t = bin & x;
		if (t == 0) cout << 0;
		else cout << 1;
		if (i % 4 == 0) cout << " ";
		bin = bin << 1;
	}
}

void generateX()
{
	x = rand() % 15 + 2;
	cout << int(x) << " ";
}

void displayFloors()
{
	floors += to_string(floorNum) + " ";
}

int main()
{
	srand((unsigned int)time(NULL));	//initialize random number generator	
	cout << "random floor's number: ";
	_asm
	{
	//get 10 random numbers and represent them on each bits of AX register
		mov		counter, 1;				//counter = 1
		mov		ax, 0;					//ax = 0
	forLoop1:
 		cmp		counter, 10;			//compare if counter == 10?
		Jg		done1;					//counter = 11 jump to done1
		mov		bx, ax;
		call	generateX;				//generate random number
		mov		cl, x;					//cl = random number
		sub		cl, 1;					//keep track of the number of shift
		mov		ax, bx;
		mov		bx, 0x0001;				//bx = 1000 0000 0000 0000
		shl		bx, cl;					//shift left bx by the randomized number
		or		ax, bx;					//ax = ax | bx
		inc		counter;				//counter++
		Jmp		forLoop1;				//jump back to forLoop1
	done1:
		mov		a, ax;					//assign a = ax to display the content of AX
		mov		bin, ax;
		mov		bx, ax;
		call	displayBin;

	//check the floor that elevator will stop
		mov		ax, bx;					
		mov		counter, 1;				//counter = 1
		mov		floorNum, 16;			//floorNum = 16
	forLoop2:
		cmp		counter, 16;			//compare if counter == 16?
		Jg		done2;					//counter = 16 jump to done2
		mov		bx, ax;					//reassign bx = ax for comparison
		and		bx, 0x8000;				//bx = bx & 0x8000
		cmp		bx, 0;					//compare if bx == 0?
		Jne		Elevator;				//if bx is not equal to 0, jump to Elevator
		dec		floorNum;				//floorNum--
		shl		ax, 1;					//shift left ax by 1
		inc		counter;				//counter++
		Jmp		forLoop2;				//jump back to forLoop2

	Elevator:
		mov		bx, ax;					//keep information in ax before calling a function		
		call	displayFloors;			//get the floor number 
		mov		ax, bx;					//get back the information for ax
		dec		floorNum;				//floorNum--
		shl		ax, 1;					//shift left ax by 1
		inc		counter;				//counter++
		Jmp		forLoop2;				//jump back to forLoop2
	done2:
	}

	cout << endl;
	cout << "Ax= ";
	cout << hex << a << endl;
	cout << "Elevator will stop at floors no. " << floors << endl;

	cout << endl;
	system("pause");
	return 0;
}



