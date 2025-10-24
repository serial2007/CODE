#include <iostream>
using namespace std;

int stack[100], ptr;

int main()
{
	int op, num;
	while(cin >> op)
	{
		if(op == -1) return 0;
		if(op == 1) 
		{
			cin >> num;
			if(ptr < 100)
				stack[ptr++] = num;
			else cout<<"error ";
		}
		else
		{
			if(ptr) cout << stack[--ptr] << ' ';
			else cout << "error ";
		}
	}
}