#include <cstdlib>
#include <iostream>
#include <bitset> //library used for converting int to byte
using namespace std;
bitset<8> ASR(bitset<8> in);
bitset<16> BoothsMult(int in1, int in2);
bitset<8> PrimeProduct(bitset<16> product);
bitset<8> Invert(bitset<8> out);

int main()
{
	//variable inputs 
	int in1 = 0;
	int in2 = 0;

	cout << "Enter first value[0]: ";
	cin >> in1;
	cout << "Enter second value[1]: ";
	cin >> in2;

	bitset<8> out;
	bitset<16> p = BoothsMult(in1, in2);

	//convert 16 bit bitset 'p' to 8 bit bitset 'out'
	for (int i = 0; i < 8; i++)
	{
		out[i] = p[i];
	}

	//flip output if it is negative
	if (out[7] == 1)
	{
			
		cout << "Product: -" << Invert(out).to_ulong() << endl;

	}

	//if output is positive
	else
	{
			cout << "Product: " << out.to_ulong() << endl;	
	}
}

bitset<8> Invert(bitset<8> out)
{
	out.flip();

	if (out[0] == 0)
	{
		out[0] = 1;
		return out;

	}
	else if (out[0] == 1)
	{
		out[0] = 0;
		for (int j = 1; j < 7; j++)
		{
			if (out[j] == 1)
			{
				out[j] = 0;
				continue;
			}
			else
			{
				out[j] = 1;
				break;
			}
		}
		return out;

	}
}


//Arithmetic Shift Right function
bitset<17> ASR(bitset<17> in)
{
	
	 if (in[16] == 1) //if there is a 1 at the end of the bitset them put a 1 at the end and right shift
	{
		in = in >> 1;
		in[16] = 1;
	}
	else //right shift will automatically put 0 at the left of the bitset
	{
		in = in >> 1;
	}
	return in;
}

bitset<8> PrimeProduct(bitset<17> product)
{
	bitset<8> pp; //initialize prime product

	for (int i = 9; i < 17; i++) //starting with the product[8] count up to product[15]
	{
		pp[i-9] = product[i]; //assign primeproduct the last 8 bits of product
		
	}
	return pp; //return prime product
}

bitset<16> BoothsMult(int in1, int in2)
{
	bitset<8> mCand{ _ULonglong(in1) }; //bitset representation of in1 in 8 bit format **Multicant**
	bitset<8> t{ _ULonglong(in2) };
	bitset<16> product; //bitset represenation of in2 in 16 bit format **Product**
	for (int i = 0; i < 8; i++)
	{
		product[i] = t[i];
	}
	
	//Step 1. Place the multipler at the lower
	// half of the product
	cout << "  iterations |  steps   |    MCand    |  Product" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "      0      |  Init.   |  " << mCand << "   | " << product << endl;
	cout << "             |          |             |                      " << endl;
	cout << "-------------------------------------------------------------" << endl;
	
	//step 2 
	//add zero to the end of the product
	bitset<17> p{ product.to_ulong() }; //convert product back to int to convert bitset<16> to bitset<17>
	p = p << 1; //left shift p to add 0
	
	//repeat steps 3 and 4 n-bits long(8-bits)
	for (int i = 1; i <= 8; i++)
	{
		//step 3
		//Depending on the last two bits of the product
		//Perform the operation

		//if 01: P = P + Mcand
		if (p[1] == 0 && p[0] == 1)
		{
			//primeproduct + mCand
			bitset<8> prime { _ULonglong( (PrimeProduct(p)).to_ulong() + (mCand).to_ulong() )};
			for (int j = 9; j < 17; j++)
			{
				p[j] = prime[j - 9];
			}
			cout << "      "<<i<<"      |   p=p+1  |  " << mCand << "   | " << p << endl;

		}

		//if 10: P = P - MCand
		else if (p[1] == 1 && p[0] == 0)
		{
			//primeproduct + mCand
			bitset<8> prime{ _ULonglong((PrimeProduct(p)).to_ulong() - mCand.to_ulong() ) };
			for (int j = 9; j < 17; j++)
			{
				p[j] = prime[j - 9];
			}
			cout << "      " << i << "      |   p=p-1  |  " << mCand << "   | " << p << endl;

		}

		//if 11: no operation
		//if 00: no operation
		else
		{
			cout << "      "<<i<<"      |  no op   |  " << mCand << "   | " << p << endl;

		}
		p = ASR(p);
		cout << "             |  ASR>>1  |  " << mCand << "   | " << p << endl;
		cout << "-------------------------------------------------------------" << endl;

	}
	for (int i = 15; i >= 0; i--)
	{
		product[i] = p[i + 1];
	}
	return product;
}