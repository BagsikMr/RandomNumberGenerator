#include <iostream>
#include <math.h>
using namespace std;

struct Global {
	long long Xc = 15;
	long long X = 15;
	int a = 69069;
	int c = 1;
	long long M = 0;
	int number_of_drawn_items = 100000;
	int line_gen_table[10] = {};
	bool binary_number[31] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1 };
	int shift_reg_gen_table[10] = {};
	int p = 7, q = 3;
} myGlobal;

void lineGenerator(Global* myGlobal);
void print_binary(Global* myGlobal);
void roll(bool* binary_number, bool element);
void shiftRegisterGenerator(Global* myGlobal);

int main()
{
	myGlobal.M = pow(2, 31);

	lineGenerator(&myGlobal);

	cout << "Line generator: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myGlobal.line_gen_table[i] << endl;
	}

	shiftRegisterGenerator(&myGlobal);

	cout << "Generators based on shift registers: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myGlobal.shift_reg_gen_table[i] << endl;
	}
}

void lineGenerator(Global* myGlobal)
{
	int temp;
	for (int i = 0; i < myGlobal->number_of_drawn_items; i++)
	{
		myGlobal->X = (myGlobal->a * myGlobal->X + myGlobal->c) % myGlobal->M;
		temp = 10 * myGlobal->X / myGlobal->M;
		myGlobal->line_gen_table[temp]++;
	}
};
void print_binary(Global* myGlobal)
{
	int number = 0;
	for (int i = 0; i < 31; i++)
	{
		number += pow(2, i) * myGlobal->binary_number[30 - i];

	}
	myGlobal->Xc = number;
};
void roll(bool* binary_number, bool element)
{
	for (int i = 0; i < 31; i++)
	{
		binary_number[i] = binary_number[i + 1];
	}
	binary_number[30] = element;
};
void shiftRegisterGenerator(Global* myGlobal)
{
	long long temp = 0;
	bool bi_temp = 0;

	for (int i = 0; i < myGlobal->number_of_drawn_items; i++)
	{
		bi_temp = myGlobal->binary_number[31 - myGlobal->p] ^ myGlobal->binary_number[31 - myGlobal->q];
		roll(myGlobal->binary_number, bi_temp);
		print_binary(myGlobal);
		temp = 10 * myGlobal->Xc / myGlobal->M;
		myGlobal->shift_reg_gen_table[temp]++;
	}
};
