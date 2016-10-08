///////////////////////////////////////////////////////////////////////////////
/*
Programmer: Thomas Crane
Class: Computer Architecture 
Project 1: MIPS Disassembler

Summary: This program takes a MIPS instruction command and breaks it down
to it's basic function. It recognizes only I and R format, not J, and only
accepts opp codes: add, sub, or, slt, and, lw, sw, beq, bne
An opp code outside of this range will terminate the program.
*/
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <bitset>
using namespace std;

//Global Variable of program counter
int progCounter = 0x7A060;
//Return true if bits 32-25 bits are 0
bool rCheck(int instruction_f)
{
	int value = instruction_f & 0xFC000000;
	if (value == 0x000000)
		return true;
}
//take in the entire instruction, range of bits, and length of bitshift
int bitShift(int instruction_f, int range, int shift)
{
	//This isn't the most professional but if the scope of the project was large then I would create a dedicated and better function
	if (range == 4)
		range = 0xf;
	else if (range== 3)
		range = 0x7;
	else if (range == 16)
		range = 0xffff;
	else if (range == 5)
		range = 0x1f;
	else if (range == 6)
		range = 0x3f;	
	else
	{
		cout << "range is outside of range" << endl;
		return 0;
	}
	instruction_f = instruction_f >> shift;
	int value = instruction_f & range;
	return value;
}
//R format
void rFormatf(int instruction_f)
{
	//decompress program counter
	progCounter = progCounter << 2;

	//Check opp code and assign name to string
	int oppCode = bitShift(instruction_f, 6, 0);
	string oppCode_s = " ";
	if (oppCode == 0x20)
		oppCode_s = "add";
	else if (oppCode == 0x22)
		oppCode_s = "sub";
	else if (oppCode == 0x25)
		oppCode_s = "or";
	else if (oppCode == 0x2A)
		oppCode_s = "slt";
	else if (oppCode == 0x24)
		oppCode_s = "and";
	else
	{
		cout << "Opp Code not recognized." << endl;
		exit(0);
	}

	int firstVar = bitShift(instruction_f, 4, 11);
	int secondVar = bitShift(instruction_f, 4, 21);
	int thirdVar = bitShift(instruction_f, 5, 16);

	//Instruction printout
	//cout << "the oppCode is: " << oppCode_s << endl;
	//cout << "First variable is $" << dec << firstVar << endl;
	//cout << "Second variable is $" << dec << secondVar << endl;
	//cout << "Third variable is $" << dec << thirdVar << endl;
	cout << "Complete Instruction: " << hex << progCounter << " " << oppCode_s << " $" << hex << firstVar << " $" << hex << secondVar << " $" << hex << thirdVar << endl << endl;
	//cout << "Program counter at: " << hex << progCounter << endl << endl;
	//increment the program counter
	progCounter = progCounter + 0x4;
	//compress program counter
	progCounter = progCounter >> 2;
	int main();
}
//I format
void iFormatf(int instruction_f) 
{
	//decompress program counter
	progCounter = progCounter << 2;
	string oppCode_s = " ";

	int firstVar = bitShift(instruction_f, 4, 16);
	int secondVar = bitShift(instruction_f, 4, 21);
	int offset = bitShift(instruction_f, 16, 0);

	//Check opp code and assign name to string
	int oppCode = bitShift(instruction_f, 6, 26);

	if (oppCode == 0x23) {
		oppCode_s = "lw";
		cout << "Complete Instruction: " << hex << progCounter << " " << oppCode_s << " $" << hex << firstVar << " " << hex << offset << " ($" << hex << secondVar << ")" << endl << endl;
	}
	else if (oppCode == 0x2B){
		oppCode_s = "sw";
		cout << "Complete Instruction: " << hex << progCounter << " " << oppCode_s << " $" << hex << firstVar << " " << hex << offset << " ($" << hex << secondVar << ")" << endl << endl;
	}
	else if (oppCode == 0x4) {
		oppCode_s = "beq";
		cout << "Complete Instruction: " << hex << progCounter << " " << oppCode_s << " $" << hex << firstVar   << " $" << hex << secondVar << " " << hex << offset << endl << endl;
	}
	else if (oppCode == 0x5) {
		oppCode_s = "bne";
		cout << "Complete Instruction: " << hex << progCounter << " " << oppCode_s << " $" << hex << firstVar << " $" << hex << secondVar<< " " << hex << offset << endl << endl;
	}
	else
	{
		cout << "Opp Code not recognized." << endl;
		exit(0);
	}
	//increment the program counter
	progCounter = progCounter + 0x4;

	//compress program counter
	progCounter = progCounter >> 2;
	int main();
}

void code(unsigned int instruction)
{
	//cout << "Enter the hex 32bit MIPS instruction: ";
	//cin >> hex >> instruction;

	//cout << "The hex instruction input is: " << hex << instruction << endl;
	//Check offset for 000000 and if return is true then the instruction is R format.
	if (rCheck(instruction))
		rFormatf(instruction);
	else 
		iFormatf(instruction);
}

//main
int main()
{
	const int numValues = 11;
	unsigned int hexValuesArr[numValues]{ 0x022DA822, 0x8EF30018, 0x12A70004, 0x02689820, 0xAD930018, 0x02697824, 0xAD8FFFF4,
		0x018C6020, 0x02A4A825, 0x158FFFF6, 0x8E59FFF0 };
	progCounter = progCounter >> 2;
	for (int i = 11; i != 0; --i)
	{
		unsigned int test = hexValuesArr[numValues - i];
		code(test);
	}
/*
	code();
	bool again = 1;
	cout << "Would you like to continue? 1 = yes 0 = no" << endl;
	cin >> again;
	while (again)
	{
		code();
		cout << "Would you like to continue? 1 = yes 0 = no" << endl;
		cin >> again;
	}*/
}