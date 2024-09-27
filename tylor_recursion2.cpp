#include<bits/stdc++.h>

float exp(int x, int n){
	static double sum=1;
	if(n==0)
		return sum;
	sum*=double(x)/n;
	sum+=1;
	return exp(x,n-1);
}

int main()
{
	std::cout<<exp(2,5);
}
