#include <iostream>
#include <string>

using namespace std;

short bin, printers, floppies, ramSize;

int main()
{
	_asm
	{
	//bit 14, 15: number of printers installed
		mov		ax, 1100111010011100b;     //ax = binary number
		mov		bx, ax;                    //reassign bx, keep value of ax for later usage
		and		bx, 1100000000000000b;     //check values at bit 14 and 15 if they are 1 or 0
		shr		bx, 14;                    //bx = 0000 0000 0000 0011
		mov		printers, bx;              //printers = 3

	//bit 6,7: number of floppy drives plus one
		mov		bx, ax;
		and		bx, 0000000011000000b;     //check values at bit 6,7
		shr		bx, 6;
		mov		floppies, bx;

	//bit 2,3: 00=16K RAM, 01=32K RAM, 10=48K RAM, 11=64K RAM
		mov		bx, ax;
		and		bx, 0000000000001100b;
		shr		bx, 2;
		cmp		bx, 0;                     //check if bx = 0...00
		Je		ram1;
		cmp		bx, 1;                     //check if bx = 0...01
		Je		ram2;
		cmp		bx, 2;                     //check if bx = 0...10
		Je		ram3;
		mov		ramSize, 64;               //else bx = 0...11
		Jmp		done;

	ram1:
		mov		ramSize, 16;
		Jmp		done;
	ram2:
		mov		ramSize, 32;
		Jmp		done;
	ram3:
		mov		ramSize, 48;
	done:
	}

	cout << "The number of printers connected to the computer: " << printers << endl;
	cout << "The number of floppy drives: " << floppies + 1<< endl;
	cout << "The size of the RAM: " << ramSize << "K RAM" << endl;

	cout << endl;
	system("pause");
	return 0;
}