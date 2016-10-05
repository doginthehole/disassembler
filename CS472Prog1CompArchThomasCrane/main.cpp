#include <iostream>
using namespace std;



//if statements for all of the registers with return functions in each
// or
//have two different if statements that return an array of the different registers, opcodes, func, or offset
int bitmask() {
	return 0;
}

//to be called in each of the bitmask for loops
int bitToHex(int) {
	return 0;
}

//gotta remember to do that thing of making the offset 18 bits
//you don't need the last two bits as they're always zero, it increments in 4
//only i format
int offsetFunc() {
	short offset = 0;
	return 0;
}

//R format



//I format

int main() {
	//initializing values
	int instruction = 0x8E59FFF0;

	int rFormat[5] = { 100000 ,100010 ,100101 ,101010 };
	int iFormat[5] = { 100011 ,101011 ,000100 ,000101 ,100100 };

	//User prompt
	cout << "hello world" << endl;
	cout << "Input the MIPS 32bit instruction, without the 0x" << endl;
	
	for(int i = 0; i < 4; i++)
		if (instruction == NULL)
		{
			cout << "No input, restart." << endl;
			return 0;
		}
		else if (instruction == rFormat[i])
		{
			//goto r format function
		}
		else if (instruction == iFormat[i])
		{
			//goto i format function
		}

	//output - must include address and instruction
	cout << "Address - " << "Instruction - " << endl;
}

/*Notes
Op codes
add 100000 R
sub 100010 R
or 100101 R
slt 101010 R
lw 100011 I	
sw 101011 I
beq 000100 I
bne 000101 I
andi 100100 I









*/