#include<bits/stdc++.h>
#include "Problem2 Reverse subwords.h"
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
	/*It takes a string of spaces, e.g.  "abc d efg xy"
		? Then reverse each subword ? “cba d gfe yx“*/

	string reverse_subwords(string line) 
	{
		string result;
		Stack s(line.size());
		line += " ";
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] ==' ')
			{
				while (!s.isEmpty())
				{
					result += s.pop();
			    }
				result += ' ';
			}
			else
			{
				s.push(line[i]);
			}

		}
		return result;
	}
	



};

int main()
{
	Stack s(100);
	cout << s.reverse_subwords("abc d efg xy");
	//stk.push()
	////= new stack();
	//stack s = new stack(20);





	/*Stack ss(100);
	string s="abc d efg xy";

	ss.stackpushline(s);*/
	/*cout << s.length()<<endl;

	cout << s.empty() << endl;
*/


	/*Stack s(3);
	cout << s.isEmpty() << endl;
	cout << "___________________" << endl;
	s.push(0);
	s.push(1);
	s.push(2);
	cout << "___________________" << endl;
	s.pop();
	cout << s.peek();
	cout << s.isFull() << endl;

	s.display();*/



}