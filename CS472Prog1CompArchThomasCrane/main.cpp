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
	//Check opp code and assign name to string
	int oppCode = bitShift(instruction_f, 6, 0);
	string oppCode_s = " ";
	if (oppCode == 0x20)
		oppCode_s = "Add";
	else if (oppCode == 0x22)
		oppCode_s = "Sub";
	else if (oppCode == 0x25)
		oppCode_s = "Or";
	else if (oppCode == 0x2A)
		oppCode_s = "Slt";
	else if (oppCode == 0x24)
		oppCode_s = "And";
	else
	{
		cout << "Opp Code not recognized." << endl;
		exit(0);
	}

	int firstVar = bitShift(instruction_f, 3, 11);
	int secondVar = bitShift(instruction_f, 3, 21);
	int thirdVar = bitShift(instruction_f, 3, 16);

	//Instruction printout
	cout << "the oppCode is: " << oppCode_s << endl;
	cout << "First variable is $" << hex << firstVar << endl;
	cout << "Second variable is $" << hex << secondVar << endl;
	cout << "Third variable is $" << hex << thirdVar << endl;
	cout << "Complete Instruction: " << oppCode_s << " $" << hex << firstVar << " $" << hex << secondVar << " $" << hex << thirdVar << endl;

}
//I format
void iFormatf(int instruction_f) 
{
	//Check opp code and assign name to string
	int oppCode = bitShift(instruction_f, 6, 26);
	string oppCode_s = " ";
	if (oppCode == 0x23)
		oppCode_s = "Lw";
	else if (oppCode == 0x2B)
		oppCode_s = "Sw";
	else if (oppCode == 0x4)
		oppCode_s = "Beq";
	else if (oppCode == 0x5)
		oppCode_s = "Bne";
	else
	{
		cout << "Opp Code not recognized." << endl;
		exit(0);
	}
	
	int offset = bitShift(instruction_f, 16, 0);
	int firstVar = bitShift(instruction_f, 4, 16);
	int secondVar = bitShift(instruction_f, 4, 21);
	
	//Instruction printout
	//I print this in the format that was described by the instructions but I am aware that some print the offset after the values, just sayin'
	cout << "First variable is $" << hex << firstVar << endl;
	cout << "Offset = 0x" << hex << offset << endl;
	cout << "Second variable is $" << hex << secondVar << endl;
	cout << "Complete Instruction: " << oppCode_s << " $" << hex << firstVar << " 0x" << hex << offset << " $" << hex << secondVar << endl;
}
//main
int main()
{
	int instruction = 0;
	cout << "Enter the hex 32bit MIPS instruction: ";
	cin >> hex >> instruction;

	//the isntruction can also be placed here
	//int instruction = 0x158FFFF6;

	cout << "The hex instruction entered was: " << hex << instruction << endl;
	//Check offset for 000000 and if return is true then the instruction is R format.
	if (rCheck(instruction))
		rFormatf(instruction);
	iFormatf(instruction);

	return 0;
}