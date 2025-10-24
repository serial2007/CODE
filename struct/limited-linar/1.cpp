#include <iostream>
#include <string>
// ( - 1
// [ - 2
// { - 3

using namespace std;
int stack[1001], ptr=0;

int main()
{
	string st;
	getline(cin, st);
	int ret=1;
	for(int i=0; i<st.size(); i++)
	{
		if(st[i]=='(') stack[ptr++] = 1;
		else if(st[i]=='[') stack[ptr++] = 2;
		else if(st[i]=='{') stack[ptr++] = 3;
		else if(st[i]==')') {if(!ptr || stack[--ptr] != 1) {ret=0; break;}} 
		else if(st[i]==']') {if(!ptr || stack[--ptr] != 2) {ret=0; break;}} 
		else if(st[i]=='}') {if(!ptr || stack[--ptr] != 3) {ret=0; break;}} 
	}
	if(ptr) ret=0;
	cout << ret << endl;
}