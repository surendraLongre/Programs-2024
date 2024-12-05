#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
	class Term
	{
		public:
			int coeff{}, exp{};
	};
	int degree{};
	Term *arr;
	public:
	Polynomial();
	friend std::ostream & operator<<(std::ostream &, Polynomial &);
	int eval(int);
};

int Polynomial::eval(int x)
{
	int sum{};
	for(int i=0; i!=degree+1; i++)
	{
		sum+=arr[i].coeff*pow(x,arr[i].exp);
	}
	return sum;
}

Polynomial::Polynomial()
{
	std::cout<<"Enter the degree of the polynomial: ";
	std::cin>>degree;
	std::cout<<std::endl;
	arr=new Term[degree+1];

	for(int i=0; i!=degree+1; i++)
	{
		std::cout<<"Enter "<<degree-i<<"th term's coefficient and power: ";
		std::cin>>arr[i].coeff>>arr[i].exp;
		std::cout<<std::endl;
	}
}

std::ostream & operator<<(std::ostream &ost, Polynomial &p)
{
	for(int i=0; i!=p.degree+1; i++)
	{
		ost<<p.arr[i].coeff<<"x^"<<p.arr[i].exp;
		if(i!=p.degree)
			std::cout<<" + ";
	}
	return ost;
}

#endif
