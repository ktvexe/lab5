#ifndef HugeInt_H
#define HugeInt_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<climits>

using namespace std;

class HugeInt
{
	public:
		HugeInt();
		HugeInt(int in);
		HugeInt(string in);
		
		const HugeInt& operator =(const HugeInt &right);
		friend istream& operator >>(istream &in, HugeInt &Hint);
		friend ostream& operator <<(ostream &out,const HugeInt &Hint);
		friend HugeInt operator + (const HugeInt & A, const HugeInt& B);
		friend HugeInt operator - (const HugeInt & A, const HugeInt& B);
	private:
		string strnum;
};

#endif
