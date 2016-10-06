#include <iostream>
#include <bitset>
using namespace std;



//if statements for all of the registers with return functions in each
// or
//have two different if statements that return an array of the different registers, opcodes, func, or offset
int bitmask() 
{
	return 0;
}

//to be called in each of the bitmask for loops
int bitToHex(int) 
{
	return 0;
}

//gotta remember to do that thing of making the offset 18 bits
//you don't need the last two bits as they're always zero, it increments in 4
//only i format
int offsetFunc() 
{
	short offset = 0;
	return 0;
}

//R format
void rFormatf()
{

	cout << "I made it!" << endl;


}


//I format

void iFormatf() 
{




}

bitset<32> bitReturn(int start, int finish, bitset<32> bits)
{
	bitset<32> rValue;

	int len = start - finish;
	while (len != 0)
	{
		rValue[len] = bits[finish];
		finish--;
		len--;
	}

	return rValue;
}

bitset<6> oppf(bitset<32> instruction) 
{
	int cnt = 5;
	//bitset<6> rValue;
	
	bitset<32> oppCode = bitReturn(32, 26, instruction);
	return 0;
}


int main()
{
	//initializing values
	bitset<32> instruction (string("10101010101010101010101010101010101")) ;
	//bin 0000... 1101
	//dec 13 asdf


	bitset<6> rFormatOpp[5]{ 0 ,100010 ,100101 ,101010 };
	bitset<6> iFormatOpp[5]{ 100011 ,101011 ,000100 ,000101 ,100100 };
	//cout << test << endl;

	//User prompt
	//cout << "hello world" << endl;
	//cout << dec << instruction << endl;

	for (int i = 0; i < 4; i++)
		if (instruction == NULL)
		{
			cout << "No input, restart." << endl;
			return 0;
		}
		else if (oppf(instruction) == iFormatOpp[i])
		{


		}
		else if (oppf(instruction) == rFormatOpp[i])
		{
			rFormatf;
		}

	//output - must include address and instruction
	//cout << "Address - " << "Instruction - " << endl;
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