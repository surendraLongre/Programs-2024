#include<bits/stdc++.h>

void TOH(int n, char A, char B, char C){
	if(n!=0){
		TOH(n-1,A,C,B);
		std::cout<<"Move disk from "<<A<<" to "<<C<<std::endl;
		TOH(n-1,B,A,C);
	}
}

int main()
{
	TOH(1,'A','B','C'); //move all disks from tower A --> C
			    //using tower B
}
