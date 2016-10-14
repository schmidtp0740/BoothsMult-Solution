#include <cstdlib>
#include <iostream>
#include <bitset> //library used for converting int to byte
using namespace std;
bitset<8> ARS(bitset<8> in);
bitset<16> BoothsMult(int in1, int in2);
bitset<8> PrimeProduct(bitset<16> product);

int main()
{
	//variable inputs 
	int in1 = 0;
	int in2 = 0;

	cout << "Enter first value[0]: ";
	cin >> in1;
	cout << "Enter second value[1]: ";
	cin >> in2;

	BoothsMult(in1, in2);
}

//Arithmetic Right Shift function
bitset<16> ARS(bitset<16> in)
{
	
	 if (in[15] == 1)
	{
		in = in >> 1;
		in[15] = 1;
	}
	else
	{
		in = in >> 1;
	}
	return in;
}

bitset<8> PrimeProduct(bitset<16> product)
{
	bitset<8> pp;
	int j = 0;
	for (int i = 8; i < 16; i++)
	{
		pp[j] = product[i];
		j++;
	}
	cout << pp << endl;
	return pp;
}

bitset<16> BoothsMult(int in1, int in2)
{
	bitset<8> mCand{ _ULonglong(in1) }; //bitset representation of in1 in 8 bit format **Multicant**
	bitset<16> product{ _ULonglong(in2) }; //bitset represenation of in2 in 16 bit format **Product**
	
	//Printing out header
	cout << "   steps   |    MCand    |            Product" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "     0     |   " << mCand << "  |" << product << endl;
	cout << "           |             |                                   " << endl;
	cout << "-------------------------------------------------------------" << endl;
	PrimeProduct(product);
	//step 2 
	//add zero to the end of the product
	bitset<17> p{ product.to_ulong() }; //convert product back to int to convert bitset<16> to bitset<17>
	p = p << 1; //left shift p to add 0
	
	return product;
}