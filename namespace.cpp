#include<bits/stdc++.h>

namespace pigeon{
	class Identity{
		std::string name{};
		int age{};
		std::string color{};
		public:
		Identity(){};
		Identity(std::string, int, std::string);
		void verify(){
			std::cout<<"name: "<<name<<std::endl
				<<"age: "<<age<<std::endl
				<<"color: "<<color<<std::endl;
		}
	};
}

pigeon::Identity::Identity(std::string name, int age, std::string color){
	this->name=name;
	this->age=age;
	this->color=color;
}

int main()
{
	pigeon::Identity p1("Falcon", 5, "White");
	pigeon::Identity p2("Zeus", 3, "Grey");
	p1.verify();
	p2.verify();
}
