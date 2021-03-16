#pragma once
//стек
#include <iostream>
#include <vector>
using namespace std;
template <typename t>
class Node
{
public:
	t value;
	Node* next;
	Node(t Value, Node *Next)
	{
		value = Value;
		next = Next;
	}
};
template <typename t>
class Stack
{
	Node<t>* _head; // head of stack
	int _size; // stack size
public:
	Stack(const Stack& list) //copy constructor
	{
		vector<t> listofvalues;
		Node<t>* tmp = list._head;
		while (tmp != nullptr) 
		{
			listofvalues.push_back(tmp->value);
			tmp = tmp->next;
		}
		_head = nullptr;
		_size = 0;
		while (!listofvalues.empty()) 
		{
			push(listofvalues[listofvalues.size() - 1]);
			listofvalues.pop_back();
		}
	}
	Stack() //stock constructor
	{
		_head = nullptr;
		_size = 0;
	}
	int size() { return _size; } //return stack size
	void push(t Value) //add element in stack
	{
		_size++;
		Node<t>* newel = new Node<t>(Value, _head);
		_head = newel;
	}
	bool empty() { return _head == nullptr; } //check stack size
	void pop() //deleted _head of stack
	{
		if (empty()) 
		{
			return;
		}
		Node<t>* tmp = _head;
		_head = tmp->next;
		delete tmp;
		tmp = nullptr;
		_size--;
	}
	t top() //access to _head
	{
		if (empty())
		{
			return nullptr;
		}
		return _head->value;
	}
	~Stack() //destructor
	{
		while (!empty())
			pop();
	}
};
