// VectorDeepDive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
class Vector
{
private:
	int* arr = nullptr;
	int size = 0;
public:

	Vector(int size) : // for intiliz
    size(size) 
	{
		if (size<0)
		{
			size = 1;
			arr = new int[size] {};
		}
	}

	int get(int index)
	{
		assert(0 <= index && index < size);
		return arr[index];
	}
	void set(int index, int val)
	{
		assert(0 <= index && index < size);
		arr[index] = val;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}
	int find(int val)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == val) { return i; }
		}
		return -1;
	}

	int getFront()
	{
		return arr[0];
	}
	int getBack()
	{
		return arr[size - 1];
	}
	void pushback(int val)
	{//new array ,duplicate ,addnew,remove old 
		int* arr2 = new int[size + 1];//new
		for (int i = 0; i < size; i++)
		{
			arr2[i] = arr[i];// copy
			arr2[size++] = val;// add

			swap(arr, arr2);//delete[] arr;  arr = arr2;

			// swap betwen 2 pointers of arraies 
		
			
			delete []arr2;// 
		}
	}





	~Vector() {
		delete[]arr;
		arr = nullptr;
	}


};

int main()
{
	Vector v(10);
	for (int i = 0; i < 10; i++)
	{
		v.set(i, i);

	}
	//v.pushback(3);
	//v.pushback(44);
	//
	v.print();
	





}
