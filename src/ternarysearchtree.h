#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<string.h>
#include<queue>

using namespace std;
class Node
{
	char data;
	unsigned isend:1;
	Node *left,*eq,*right;
	public:
		friend class TST;
};
class TST
{
	queue<string>in;
	public:
		Node* newnode(char);
		void insert(Node**,char*);
		void traverse(Node*,char*,int);
		void traverseTST(Node*);
		void insert1(const char *);
		int searchTST(Node*,const char*);
		bool queueval();
};
Node* TST::newnode(char data)
{
	Node* temp=new Node;
	temp->data=data;
	temp->isend=0;
	temp->left=temp->eq=temp->right=NULL;
	return temp;
}
void TST::insert(Node** root,char *word)
{
	if(!(*root)) 
        *root=newnode(*word); 
    if((*word)<(*root)->data) 
        insert(&((*root)->left),word); 
    else if((*word)>(*root)->data) 
        insert(&((*root)->right),word); 
    else
    { 
        if(*(word+1)) 
            insert(&((*root)->eq),word+1); 
        else
            (*root)->isend = 1; 
    } 
}
void TST::traverse(Node* root,char* buffer,int depth) 
{ 
    if (root) 
    { 
        traverse(root->left, buffer, depth); 
        buffer[depth] = root->data; 
        if (root->isend) 
        { 
            buffer[depth+1] = '\0'; 
            cout<<buffer<<endl; 
        } 
        traverse(root->eq, buffer, depth + 1); 
        traverse(root->right, buffer, depth); 
    } 
} 
void TST::traverseTST(Node* root) 
{ 
    char buffer[50]; 
    traverse(root,buffer,0); 
}
void TST::insert1(const char *str)
{
	Node *root=NULL;  
	fstream fin;  
	fin.open("20k.txt", ios::in); 
	string word;
	while (fin >> word) 
    {  
    	char *cstr = new char[word.length() + 1];
		strcpy(cstr, word.c_str());
		insert(&root,cstr); 
    }
    int a;
    searchTST(root,str)?a=1:a=0;
    if(a==0)
    {
    	in.push(str);
	}
	fin.close();
}
int TST::searchTST(Node *root,const char *word) 
{ 
    if(!root) 
    return 0; 
    if(*word<(root)->data) 
        return searchTST(root->left,word); 
    else if (*word>(root)->data) 
        return searchTST(root->right,word); 
    else
    { 
        if (*(word+1)=='\0') 
            return root->isend; 
        return searchTST(root->eq, word+1); 
    } 
}
bool TST::queueval()
{
	int i=0;
	bool mistake=false;
	while (!in.empty()) 
    { 
		cout << "\t\t" << in.front()<<"\t\t"; 
		mistake=true;
       	in.pop(); 
       	if (i==2)
       	{
       		i=0;
       		cout<<"\n\n";
		}
	}  
	if(in.empty())
	{
		return mistake;
	}
}
