#include"HugeInt.h"

using namespace std;

const HugeInt& HugeInt::operator =(const HugeInt &right)
{
	strnum=right.strnum;
	return *this;
}

istream& operator >>(istream &in, HugeInt &Hint)
{
	in>>Hint.strnum;
	return in;
}

ostream& operator <<(ostream &out, const HugeInt &Hint)
{
	out<<Hint.strnum;
	return out;
}

HugeInt operator + (const HugeInt& A, const HugeInt& B)
{
	HugeInt tmpt;
	int i=A.strnum.length()-1;
	int j=B.strnum.length()-1 ;
	bool add=false;
	for( ; ( (i>=0) && (j>=0)) ;--i,--j )
	{
		tmpt.strnum=static_cast<char>(A.strnum[i]+B.strnum[j]+add-48)+tmpt.strnum;
		if( tmpt.strnum[0] > 57 )
		{
			tmpt.strnum[0]-=10;
			add=true;
		}
		else
		{
			add=false;
		}
	}
	if( i >= 0 )
	{
		tmpt.strnum.insert(0,A.strnum.substr(0,i+1));
		tmpt.strnum[i]+=add;
	}
	else if( j>= 0)
	{
		tmpt.strnum.insert(0,B.strnum.substr(0,j+1));
		tmpt.strnum[i]+=add;
	}
	else if( add )
	{
		tmpt.strnum="1"+tmpt.strnum;
	}
	return tmpt;
}

HugeInt operator - (const HugeInt & A, const HugeInt & B)
{
	HugeInt tmpt;
	tmpt.strnum=A.strnum;

	int k;
	for(int i=tmpt.strnum.length()-1, j=B.strnum.length()-1;( (i>=0) && (j>=0));--i,--j)
	{
		if( tmpt.strnum[i] < B.strnum[j] )
		{
			k=1;
			while( tmpt.strnum[i-k] == 48 )
			{
				tmpt.strnum[i-k]+=9;
				k++;
			}
			tmpt.strnum[i-k]-=1;
			tmpt.strnum[i]=tmpt.strnum[i]-B.strnum[j]+58;
		}
		else
			tmpt.strnum[i]=tmpt.strnum[i]-B.strnum[j]+48;
	}
	while((tmpt.strnum[0] == 48)&&(tmpt.strnum.length() > 1))
	{	
		tmpt.strnum.erase(0,1);
	}
	return tmpt;
}


HugeInt::HugeInt()
{
	strnum="";
}

HugeInt::HugeInt(int in)
{
	strnum = to_string(in);
}

HugeInt::HugeInt(string in)
{
	strnum = in;
}
