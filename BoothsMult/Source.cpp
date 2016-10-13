#include <cstdlib>
#include <iostream>
#include <bitset> //library used for converting int to byte

using namespace std;
int main()
{
	//variables hold inputs 
	//keep unsigned
	short in1 = 0;
	short in2 = 0;

	cout << "Enter first value[0]: ";
	cin >> in1;
	cout << "Enter second value[1]: ";
	cin >> in2;

	//convert variables into bits with 16 bit length
	bitset<16> bitset1{ _ULonglong(in1) }; //the bitset representation of in1 in 16 bits
	bitset<16> bitset2{ _ULonglong(in2) }; //the bitset representation of in2 in 16 bits
	
	cout << bitset1 << endl;
}
