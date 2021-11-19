#include <bits/stdc++.h>
#include<fstream> 
using namespace std;


// Defining Node for Linked List
class Node1
{
	string data; 
	Node1 *next, *prev;
	public:
		friend class linkedlist;
};


// Defining Linked List
class linkedlist
{
	Node1 *head;
	public:
		linkedlist();
		Node1* getNode(string);
		void push1(Node1**, Node1*);
		void printList();
		Node1* Reverse(Node1*);
		void insert(string);
		void rev();
		bool search(string);
		void replace(string,string);
		void recreate(string);    
};


// Constructor - Initializing Linked List 
linkedlist::linkedlist()
{
	 head = NULL; 
} 

// Retreiving Node with matched string
Node1* linkedlist::getNode(string data) 
{  
	Node1* new_node = new Node1; 
	new_node->data = data; 
	new_node->next = new_node->prev = NULL; 
	return new_node; 
} 


// Inserting new Node in the List
void linkedlist::push1(Node1** head_ref, Node1* new_node) 
{ 
	new_node->prev = NULL;  
	new_node->next = (*head_ref);  
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 
	(*head_ref) = new_node; 
} 

// Printing the Nodes of the List
void linkedlist::printList() 
{ 
	Node1* temp;
	temp=head;
	while (temp != NULL) { 
		cout << temp->data << " "; 
		temp = temp->next; 
	} 
}

// Replacing a String with a String for Inserting a Word in Editing Mode
void linkedlist::replace(string str,string str1)
{
	// First Traversing through the list to find which Node has our data
	Node1* temp;
	temp=head;
	while(temp!=NULL)
	{
		if(str.compare(temp->data)==0)
		{
			temp->data=str1;
			break;
		}
		temp=temp->next;
	}
}

// 
void linkedlist::recreate(string fileName)
{
	fstream file;
	Node1* temp;
	temp=head;
	file.open(fileName.c_str(),ios::in);
	remove(fileName.c_str());
	file.open(fileName.c_str(),ios::in);
	file.close();
	file.open(fileName.c_str(),ios::out);
	while(temp!=NULL)
	{
		file<<temp->data+" ";
		temp=temp->next;
	}
	file.close();
	return;
}

// Checking if the Word is available in our List
bool linkedlist::search(string str)
{
	Node1* temp;
	rev();
	temp=head;
	while(temp!=NULL)
	{
		if(str.compare(temp->data)==0)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}

// Reversing our List
Node1* linkedlist::Reverse(Node1* node) 
{  
    if (!node) 
        return NULL; 
	Node1* temp = node->next; 
    node->next = node->prev; 
    node->prev = temp; 
    if (!node->prev) 
        return node; 
    return Reverse(node->prev); 
}

// Inserting a String to be used in insertNode()
void linkedlist::insert(string s)
{  
	push1(&head, getNode(s)); 
} 

// Reversing head to be used in Reverse()
void linkedlist::rev()
{
	head = Reverse(head); 
} 
