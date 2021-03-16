#include <iostream>
#include "Header.h"
using namespace std;
template <typename t>
void Show(Stack<t> &list) 
{
	int i = 0;
	while (!list.empty()) 
	{
		cout << i + 1 << "-ый элемент стека:" << list.top() << endl;
		list.pop();
		i++;
	}
}
int main() 
{
	setlocale(LC_ALL,"rus");
	Stack<string> list;
	cout << "Раземер стека:\t" << list.size() << endl;
	list.push("1");
	list.push("2");
	list.push("3");
	list.push("4");
	cout << "Раземер стека:\t" << list.size() << endl;
	Show(list);
	list.pop();
	if (!list.empty())
		cout << list.top();
	else 
		cout << "Список пуст!" << endl;

	return 0;
}
