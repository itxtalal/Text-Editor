#include<iostream>
#include<string>
#include<fstream>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
using namespace std;

// Defining our Trie 
class Trie
{
	// each node has 26 childs
	Trie *child[26];
	bool isend;			// represents the End of Word

	public:
		Trie* getnode();
		void insert(Trie*,string);
		bool search(Trie*,string);
		bool islast(Trie*);
		int printauto(Trie*,string);
		void suggest(Trie*,string);
		int create(string);
		void read_record();
};

// getNode() function - returns a trie
Trie* Trie::getnode()
{
	Trie* pnode =new Trie;
	pnode->isend=false;
	int i;
	for(i=0;i<26;i++)
	pnode->child[i]=NULL;
	return pnode;
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void Trie::insert(Trie* root,string key1)
{
	string key=key1;
	Trie *pcrawl=root;
	int level;
	for(level=0;level<key.length();level++)
	{
			int index=CHAR_TO_INDEX(key[level]);
		if(!pcrawl->child[index])
			pcrawl->child[index]=getnode();
		pcrawl=pcrawl->child[index];
	}
	pcrawl->isend=true;
}

// Returns true if key presents in trie, else 
// false 
bool Trie::search(Trie* root,string key)
{
	int len=key.length();
	Trie* pcrawl=root;
	int level;
	for(level=0;level<len;level++)
	{
		int index=CHAR_TO_INDEX(key[level]);
		if(!pcrawl->child[index])
		return false;
		pcrawl=pcrawl->child[index];
	}
	return (pcrawl!=NULL && pcrawl->isend);
}

bool Trie::islast(Trie* root)
{
	int i;
	for(i=0;i<26;i++)
	{
	if(root->child[i])
	return false;
	}
	return true;
}
void Trie::suggest(Trie *root,string curr)
{
	int i;
	if(root->isend)
	{
		cout<<curr<<endl;
	}
	if(islast(root))
	return;
	for(i=0;i<26;i++)
	{
		if(root->child[i])
		{
			curr.push_back(97+i);
			suggest(root->child[i],curr);
			if (!curr.empty())
 		 	curr.erase (curr.size()-1);
		}
	}
}

int Trie::printauto(Trie* root,string query)
{
	Trie* pcrawl=root;
	int level;
	int n=query.length();
	for(level=0;level<n;level++)
	{
		int index=CHAR_TO_INDEX(query[level]);
		if(!pcrawl->child[index])
		return 0;
		pcrawl=pcrawl->child[index];	
	}
	bool isword=(pcrawl->isend==true);
	bool islast1=islast(pcrawl);
	if(isword&&islast1)
	{
		cout<<query<<endl;
		return -1;
	}
	if(!islast1)
	{
		string prefix=query;
		suggest(pcrawl,prefix);	
	}	
}

// Creating a Trie Node with data - string s
int Trie::create(string s)
{
	Trie *root=getnode();  
	fstream fin;  
	fin.open("20k.txt", ios::in); 
	string word;
	while (fin >> word) 
    {  
		insert(root,word); 
    } 
	int comp = printauto(root,s); 

	if (comp == -1) 
		cout << "No other strings found with this prefix\n"; 

	else if (comp == 0) 
		cout << "No string found with this prefix\n"; 

	return 0; 
}
