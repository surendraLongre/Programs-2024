#include<bits/stdc++.h>

float exp(int x, int n){
	static unsigned int num=1, fact=1;
	if(n==0)
		return 1;
	float sum=exp(x, n-1);		//+float(num)/fact;
	num*=x;
	fact*=n;
	return sum+float(num)/fact;

}

int main()
{
	std::cout<<exp(3,15);
}
