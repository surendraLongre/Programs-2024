#include<iostream>
//code for finding duplicate alphabates in a string
//

void swap(char &ch1, char &ch2){
	char ch3=ch1;
	ch1=ch2;
	ch2=ch3;
}

void perm(std::string str, int l, int h){
	int i{};
	if(l==h){
		std::cout<<str<<std::endl;
	}
	for(i=l; str[i]!='\0'; i++){
		swap(str[i], str[l]);
		perm(str,l+1,h);
		swap(str[i],str[l]);
	}
}


int main()
{
	std::string str="ABC";
	perm(str,0,2);
}
