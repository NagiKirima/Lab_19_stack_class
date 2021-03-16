#pragma once
//стек
#include <iostream>
#include <stdexcept>
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
	Node<t>* _head;
	int _size;
public:
	Stack(const Stack &list) 
	{
	}
	Stack() 
	{
		_head = nullptr;
		_size = 0;
	}
	int size() { return _size; }
	void push(t Value) 
	{
		_size++;
		Node<t>* newel = new Node<t>(Value, _head);
		_head = newel;
	}
	bool empty() { return _head == nullptr; }
	void pop() 
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
	t top()
	{
		if (empty())
		{
			return nullptr;
		}
		return _head->value;
	}
	~Stack() 
	{
		while (!empty())
			pop();
	}
};
