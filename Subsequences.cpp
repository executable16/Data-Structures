/*
Huh!
Tough day right....
It took so long to really understand this topic finding all subsequences 
It really needed a lot of effort...
So let's start------------

Nothing special 
              ---abc---
                /  \   
               /    \
              a      b
             /  \     / \
            /    \   /   \
           ab    ac  bc   c
          / \    /\    /\  /\
         /   \  /  \  /  \ /\
       abc   ab ac  a bc b c {}
*/
#include<bits/stdc++.h>
using namespace std;
void go(auto &s , auto &temp, int i,int j)
{
	if(s[i]=='\0')
	{	
		temp[j]='\0';
		cout<<temp<<" ";
		return;
	}
	temp[j]=s[i];
	go(s,temp,i+1,j+1); // including
	go(s,temp,i+1,j);	// excluding
}
int main()
{
	
	system("clear");
	cout<<"Ran successfully\n";
	char s[10],temp[10];
	cin>>s;
	//temp="";
	go(s,temp,0,0);
}
