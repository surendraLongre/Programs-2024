#include<iostream>

class Array{
	int *A;
	int length{}, size{};
public:
	Array(){};
	Array(int, int, int *);
	void display();
	void append(int);
	void insert(int, int);
	int Delete(int);
	int search(int);
	bool isPresent(int);	//uses binary serch algorithm //must be sorted array
	int get(int);
	void set(int, int);
	int max();
	int min();
	int sum();
	int average();
	void reverse();
	void merge(Array);
};

Array::Array(int size=0, int num_count=0, int *arr={}){
	this->size=size;
	A=new int[size];
	for(int i=0; i!=num_count; i++){
		A[i]=arr[i];
		length++;
	}
}

void Array::display(){
	for(int i=0; i!=length; i++)
		std::cout<<A[i]<<" ";
	std::cout<<std::endl;
}

void Array::append(int num){
	if(size==length){
		std::cout<<"Array is full\n";
		return;
	}

	A[length++]=num;
}

void Array::insert(int index, int num){
	if(index>=size){
		std::cout<<"the index is out of reach\n";
		return;
	}
	if(length==size){
		std::cout<<"array is full";
		return;
	}

	int to_loop=length;
	while(to_loop!=index){
		A[to_loop--]=A[to_loop-1];
	}
	A[index]=num;
	length++;
}

int Array::Delete(int index){
	if(index>=length || index<0){
		std::cout<<"index out of range\n";
		return -1;
	}
	int to_return=A[index];
	for(index; index!=length-1; index++){
		A[index]=A[index+1];
	}
	length--;
	A[length]=0;
	return to_return;
}

int Array::search(int num){
	for(int i=0; i!=length; i++){
		if(A[i]==num)
			return i;
	}
	return -1;
}

bool Array::isPresent(int num){
	int low=0, high=length;
	while(high>low){
		int mid=(low+high)/2;
		if(A[mid]==num)
			return true;
		if(A[mid]>num)
			high=mid-1;
		else
			low=mid+1;
	}
	return false;
}

int Array::get(int index){
	if(index>=length || length<0)
		return -1;
	return A[index];
}

void Array::set(int index, int num){
	if(index>=length || length<0)
		return;
	A[index]=num;
}

int Array::max(){
	int to_return=A[0];
	for(int i=1; i!=length; i++)
		to_return=std::max(to_return,A[i]);
	return to_return;
}

int Array::min(){
	int to_return=A[0];
	for(int i=1; i!=length; i++)
		to_return=std::min(to_return,A[i]);
	return to_return;
}

int Array::sum(){
	int to_return{};
	for(int i=0; i!=length; i++)
		to_return+=A[i];
	return to_return;
}

int Array::average(){
	return sum()/length;
}

void swap(int &num1, int &num2){
	num1+=num2;
	num2=num1-num2;
	num1-=num2;
}

void Array::reverse(){
	for(int i=0; i!=length/2; i++){
		swap(A[i],A[length-i-1]);
	}
}

void Array::merge(Array arr2){
	Array B(size+arr2.size);
	int i{}, j{};
	while(i<length && j<arr2.length){
		if(A[i]<arr2.A[j])
			B.append(A[i++]);
		else
			B.append(arr2.A[j++]);
	}
	for(i; i!=length; i++)
		B.append(A[i]);
	for(j; j!=arr2.length; j++)
		B.append(arr2.A[j]);
	delete []A;
	length=B.length;
	A=B.A;
}

int main()
{
	int arr[]={5,10,15,20,25};
	int arr2[]={2,4,6,8,10};
	Array arr1(6,5,arr);
	Array to_merge(7,5,arr2);
	arr1.merge(to_merge);
	std::cout<<arr1.isPresent(0);
}
