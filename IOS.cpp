#include<iostream>
#include<fstream>
//class templates
//

class Student
{
	public:
		std::string name{};
		std::string roll{};
		std::string branch{};

		Student(){}
		Student(std::string, std::string, std::string);
		friend std::ofstream & operator<<(std::ofstream &, Student &);
		friend std::ifstream & operator>>(std::ifstream &, Student &);
		friend std::ostream & operator<<(std::ostream &, Student&);
};

std::ostream & operator<<(std::ostream &ost, Student &st1)
{
	ost<<"Name: "<<st1.name<<std::endl
		<<"Roll: "<<st1.roll<<std::endl
		<<"Branch: "<<st1.branch<<std::endl;
	return ost;
}

std::ofstream& operator<<(std::ofstream &ofs, Student &st1){
	ofs<<st1.name<<std::endl
		<<st1.roll<<std::endl
		<<st1.branch<<std::endl;
	return ofs;
}

std::ifstream & operator>>(std::ifstream &ifs, Student &st1){
	ifs>>st1.name>>st1.roll>>st1.branch;
	return ifs;
}

Student::Student(std::string name, std::string roll, std::string branch){
	this->name=name;
	this->roll=roll;
	this->branch=branch;
}

int main()
{
	Student st1;
	Student st2;
	std::ifstream ifs("myfile.txt");
	ifs>>st1;
	ifs>>st2;
	std::cout<<st2;
	ifs.close();
}
