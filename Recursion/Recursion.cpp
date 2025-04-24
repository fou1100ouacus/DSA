// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
void fun(int n) {
	if (n>0)
	{
		cout << n;
		fun(n - 1);

	}
	return;
}
void fun2(int n) {
	if (n > 0)
	{
		fun2(n - 1);

		cout << n;// returning time;

	}
	return;
}
int main()
{
	fun(5);
	fun2(5);



}

