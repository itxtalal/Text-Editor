#include<iostream>
using namespace std;

class Stack
{
	string *d;
	int top;
	int size;
	public:
		Stack();
		string pop();
		Stack(int);
		int push(string);
		string topp();
};

Stack::Stack()
{
	top=-1;
	d=new string[0]();
}

Stack::Stack(int n)
{
	top=-1;
	size=n;
	d=new string[size]();
}

int Stack::push(string data)
{
	if(top==size)
		return 0;		
	else
	{
		top++;
		d[top]=data;
	}
}

string Stack::pop()
{
	string element;
	if(top==-1)
		return "NULL";
	else
	{
		element=d[top];
		top--;
	}
	return element;
}

string Stack::topp()
{
	string element;
	if (top==-1)
		return "NULL";
	else
	{
		element=d[top];
	}
	return element;
}
