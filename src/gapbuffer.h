#include<iostream>
#include<string>
using namespace std;


// Defining our class of GapBuffer
// Char Array Implementation
class Gapbuffer
{
	char *buffer;
	int size;
	int gapsize;
	int gapl,gapr;
	public:
		Gapbuffer();
		Gapbuffer(int);
		void grow(int,int=10);
		void left(int);
		void right(int);
		void cursor(int);
		void insert(string,int=0);
		string input(string);         
};

// Empty Constructor
Gapbuffer::Gapbuffer()
{
	buffer=new char[50];
	size=10;
	gapsize=10;
	gapl=0;
	gapr=9;
}

// Parametrized Constructor
Gapbuffer::Gapbuffer(int s)
{
	buffer=new char[s];
	size=s;
	gapsize=10;
	gapl=0;
	gapr=gapsize-gapl-1;
}

// Resizing the Array by inserting a gap at desired position, When our gap size has become 0
void Gapbuffer::grow(int pos,int x)
{
	char arr[size];
	int i;
	
    // Copy characters of buffer to a[]  
    // after position  
	for(i=pos;i<size;i++)
	{
		arr[i-pos]=buffer[i];
	}

	// Insert a gap of k from index position  
    // gap is being represented by '-'  
	for(i=0;i<x;i++)
	{
		buffer[i+pos]='_';
	}

	// Reinsert the remaining array  
	for(i=0;i<pos+x;i++)
	{
		buffer[pos+x+i]=arr[i];
	}
	gapr+=x;
	size+=x;
}

// Function that is used to move the gap  
// left in the array
void Gapbuffer::left(int pos)
{
	 while (pos<gapl)
	 {  
        gapl--;  
        gapr--;  
        buffer[gapr+1]=buffer[gapl]; 
        buffer[gapl]='_'; 
    }  
}

// Function that is used to move the gap  
// right in the array 
void Gapbuffer::right(int pos)  
{    
    while (pos>gapl)
	{  
        gapl++;  
        gapr++;  
        buffer[gapl-1] = buffer[gapr];  
        buffer[gapr]='_'; 
    }  
} 

// Function to control the movement of gap  
// by checking its position to the point of  
// insertion  
void Gapbuffer::cursor(int pos)  
{  
    if (pos<gapl)
	{  
        left(pos);  
    }  
    else
	{  
        right(pos);  
    }  
}  

// Function to insert the string to the buffer  
// at point position 
void Gapbuffer::insert(string str,int pos)
{
	int len=str.length();
	int i=0;

	// If the point is not the gap check  
    // and move the cursor to that point 
	if(pos!=gapl)
	{
		cursor(pos);
	}
	// Insert characters one by one
	while(i<len)
	{
		// If the gap is empty grow the size
		if(gapl==gapr)
		{
			grow(pos);
		}
		 // Insert the character in the gap and  
        // move the gap 
		buffer[gapl] = str[i];  
        gapl++;  
        i++;  
        pos++; 
	}
}

// Function for Inserting a word in Editing Mode of Text File
string Gapbuffer::input(string str)
{
	int i;
	for (i = 0; i<str.length(); i++)
	 {  
        buffer[i] = '_';  
     }
     insert(str);
     string str1;
     int pos1;
     cout<<"enter the position:"<<" ";
     cin>>pos1;
     cout<<"enter the string to insert:"<<" ";
     cin>>str1;
     insert(str1,pos1);
       string a="";
    for (int i = 0; i <size; i++) {
		if(buffer[i]!='_')
		{  
        a+=buffer[i];
		}
 }
	return a;  
}

