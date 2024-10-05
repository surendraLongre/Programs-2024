#include<iostream>
//code for finding duplicate alphabates in a string
//

void duplicate(std::string str)
{
	int bit{};
	int bit_offset{};
	int perform_and=1;
	for(auto c:str){
		perform_and=1;
		bit_offset=int(c)-97;
		perform_and<<=bit_offset;
		if(perform_and&bit)
			std::cout<<c<<" ";
		else
			bit=(bit|perform_and);
	}
}

int main()
{
	std::string name="future";
	duplicate(name);
}
