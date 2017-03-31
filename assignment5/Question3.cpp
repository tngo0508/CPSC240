#include <iostream>
#include <string>

using namespace std;

short x, counter, sprinkerOn, four = 4, defectNum;
string displayReg, defect;

void displayOn()
{
	displayReg += "1";
}

void displayOff()
{
	displayReg += "0";
}

void fourDigits()
{
	displayReg += " ";
}

void displayDefect()
{
	defect = defect + to_string(defectNum) + " ";
}
int main()
{
	_asm
	{
		mov		ax, 0x6A2F;			//ax = 0x6A2F
		mov		counter, 1;			//counter = 1
		mov		defectNum, 16;		//defectNum = 16

	//do the for loop from 1 to 16
	forLoop:
		cmp		counter, 16;		//compare counter == 16?
		Jg		done;				//Jump to done if counter = 16
	
		mov		bx, ax;				//bx = 0x6A2F
		and		bx, 0x8000;			//bx = bx & 0x8000
		cmp		bx, 0;				//compare bx == 0?
		Jne		On;					//if bx is not equal 0, jump to On
		
	//Off:
		mov		bx, ax;				//reassign bx to keep value of AX for later usage
		call	displayOff;			//cout << 0
		call	displayDefect;		//print defective sprinkler number
		dec		defectNum;			//keep track of defective sprinkler

	//separate with a space every 4 digits
		mov		ax, counter;		//ax = counter, reassign ax for division
		cwd;						//ax:dx = counter
		idiv	four;				//ax = counter/4, dx = counter%4
		cmp		dx, 0;				//check if counter%4 = 0
		Je		displaySpace;		//jump to the displaceSpace every 4 digits

		mov		ax, bx;				//reassign ax for shifting left
		shl		ax, 1;				//shift left ax 1 digits
		inc		counter;			//counter++
		Jmp		forLoop;			//jump back to forLoop

	On:
		mov		bx, ax;				//reassign bx to keep value of AX for later usage
		call	displayOn;			//cout << 1
		dec		defectNum;			//keep track of defective sprinkler
		inc		sprinkerOn;			//keep track of sprinklers are ON

	//separate with a space every 4 digits
		mov		ax, counter;      
		cwd;
		idiv	four;
		cmp		dx, 0;
		Je		displaySpace;		//jump to the displaceSpace every 4 digits

		mov		ax, bx;
		shl		ax, 1;
		inc		counter;
		Jmp		forLoop;

	//add a space every 4 digits
	displaySpace:
		call	fourDigits;
		mov		ax, bx;
		shl		ax, 1;
		inc		counter;
		Jmp		forLoop;
	done:
	}

	cout << "AX=" << displayReg << endl;
	cout << sprinkerOn << " sprinklers are ON\n";
	cout << "Defective sprinklers: " << defect << endl;

	cout << endl;
	system("pause");
	return 0;
}