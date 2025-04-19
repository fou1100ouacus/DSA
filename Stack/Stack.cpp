#include<bits/stdc++.h>
using namespace std;
class Stack
{
private:
	
	int size{};
	int top{};
	int* array{};

public:
	    Stack(int size) :// constructor
		size(size), top(-1) //default initilization
		{
			array = new int[size];
		}
	
	~Stack()//Deconstructor
	{
		delete[] array;

	}

	int pop() {
		assert(!isEmpty());
		return array[top--];
	}

	int peek() 
	{
		assert(!isEmpty());
		return array[top];
	}
	void push(int val)
	{
	//	assert(!isFull);
		array[++top] = val;
	}
	int isFull() 
	{
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() 
	{
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}
};

int main()
{
	Stack s(3);
	cout << s.isEmpty() << endl;
	cout << "___________________" << endl;
	s.push(0);
	s.push(1);
	s.push(2);
	cout << "___________________" << endl;
	s.pop();
cout<<	s.peek();
	cout << s.isFull() << endl;

	s.display();



}