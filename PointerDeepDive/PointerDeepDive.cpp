// PointerDeepDive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;
struct Employee
{
public :
	int ID;
	string Name;
	Employee() {

	}
	Employee(int id, string name) {
		ID = id;
		Name = name;
	}
	void print() {
		cout << ID <<" , " << Name;
	}
};
int main()
{

	Employee e1(10, "aya");
	e1.print();
	cout << endl<<"--------" << endl;

	Employee* e2{ new Employee(1, "dsf") };
	e2->print();
	Employee* e3 = new Employee();
	e3->ID;// null
	cout << endl << "--------" << endl;
	(*e3).print();//-842150451
	Employee* e4 = e2; // pointer=address 
	                   // ref = val
	cout << endl << "--------" << endl;
	e4->print();
	Employee* e5 = { &e1 };// pointer assing to ref 
	e5->print();
	cout << endl << "--------" << endl;
	Employee& e6 = *e2;
	e2->ID = 55;
	e6.print();// 55 , dsf
	cout << endl << "--------" << endl;
	cout << endl << "--------" << endl;

	vector<Employee*>vec;
	/*vec.push_back(e2);
	e3 = vec[0];*/
	//e3->print();

	vec.push_back(e5);
	e3 = vec[0]; 
		e3->print();
	/*int counter = 0;
	Employee* temp=vec[0];
	while (!vec.empty())
	{
		temp = vec[counter];
		cout << temp->print();
		counter++;
		vec.pop_back();
		
	}*/

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
