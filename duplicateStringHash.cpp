#include<iostream>
//code for finding duplicate alphabates in a string
//

void duplicate(std::string str)
{
	int *H=new int[26]{};
	for(auto c:str){
		H[int(c)-97]++;
		if(H[int(c)-97]==2)
			std::cout<<c<<" ";
	}
}

int main()
{
	std::string name="apple";
	duplicate(name);
}
