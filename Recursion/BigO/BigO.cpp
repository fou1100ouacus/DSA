#include <bits/stdc++.h>
#include <cassert>
using namespace std;

void f1(int n = 2) { 	// O(n^3)
	int cnt = 0;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				cnt++;

			}
		}
	}
	cout << cnt << endl;
}

void f2(int n = 2) { 	// O(n^3)
	int cnt = 0;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = i; j < n; ++j) 
		{

			for (int k = j; k < n; ++k) 
			{
				cnt++;

			}
		}
    }

	cout << cnt << endl;
	// cnt 167,167000
}

int main() {
	f1();
	f2();

	return 0;
}
