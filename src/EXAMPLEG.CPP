#include <stdio.h>
#include <conio.h>

#include <dos.h>

typedef unsigned char byte;

void PutPix(int x, int y, int color)
{
	union REGS regs;

	byte far *VGA = (byte far*)0xA0000000L;
	unsigned short offset;

	offset = 320*y + x;
	VGA[offset] = color;
}

int main()
{
	union REGS regs;

	regs.h.ah = 0x00;
	regs.h.al = 0x13;
	int86(0x10, &regs, &regs);

	/*
	byte far *VGA = (byte far*)0xA0000000L;
	unsigned short offset;

	offset = 320*5 + 10;
	VGA[offset] = 15;
	*/

	PutPix(0, 0, 15);
	PutPix(10, 5, 10);

	getchar();

	regs.h.ah = 0x00;
	regs.h.al = 0x03;
	int86(0x10, &regs, &regs);

	printf("PRESS ANY KEY TO EXIT DOSRT ENGINE. THANKS FOR PLAYING.\n");
	getchar();

	return 0;
}