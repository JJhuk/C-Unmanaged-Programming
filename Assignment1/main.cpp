#include "MyString.h"
#include <iostream>
#include <string>
using namespace std;
using namespace assignment1;

int main()
{
	MyString s("Hello");
	bool b1 = s.RemoveAt(0); // s�� "ello", b1�� true
	cout << s.GetCString() << endl;
	bool b2 = s.RemoveAt(2); // s�� "elo", b2�� true
	cout << s.GetCString() << endl;
	bool b3 = s.RemoveAt(4); // s�� "elo", b3�� false
	cout << s.GetCString() << endl;

	
	system("pause");
	return 0;
}