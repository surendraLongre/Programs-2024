#include<iostream>
//code for finding duplicate alphabates in a string
//

void perm(std::string str, int k){
	static char res[4]{};
	static int A[4]{};
	int i{};
	if(str[k]=='\0'){
		res[k]='\0';
		std::cout<<res<<std::endl;
	}
	for(i=0; str[i]!='\0'; i++){
		if(A[i]==0){
			res[k]=str[i];
			A[i]=1;
			perm(str,k+1);
			A[i]=0;
		}
	}
}


int main()
{
	std::string str="ABC";
	perm(str,0);
}
