#include <iostream>
#include <sstream>
#include <string>
struct Node
{
	int a;
	Node* next;
};
using namespace std;
Node* input()
{
	string line;
	getline(cin, line);
	istringstream iss(line);
	int t;
	Node* first=nullptr, *last=nullptr;
	while(iss >> t)
	{
		if(!first) {
			first = new Node;
			first->a = t;
			first->next = nullptr;
			last = first;
		}
		else{
			last->next = new Node;
			last->next->a = t;
			last->next->next = nullptr;
			last = last->next;
		}
	}
	return first;
}
Node* combine(Node* a, Node* b)
{
	Node* first = nullptr, *last = nullptr;
	Node* i=a, *j=b, *t;
	while(i || j)
	{
		while(i && i->next && i->a == i->next->a)
			i = i->next;
		while(j && j->next && j->a == j->next->a)
			j = j->next;

		if(i && (!j || i->a <= j->a))
		{
			if(j && i->a == j->a) j=j->next;
			if(!first) {
				first = new Node;
				first->a = i->a;
				first->next = nullptr;
				last = first;
			}
			else{
				last->next = new Node;
				last->next->a = i->a;
				last->next->next = nullptr;
				last = last->next;
			}
			i=i->next;
		}else
		{
			if(!first) {
				first = new Node;
				first->a = j->a;
				first->next = nullptr;
				last = first;
			}
			else{
				last->next = new Node;
				last->next->a = j->a;
				last->next->next = nullptr;
				last = last->next;
			}
			j=j->next;
		}
	}
	return first;
}

int main()
{
	Node* a = input(), *b=input();
	Node* c = combine(a, b);
	for(Node* it = c; it; it=it->next)
	{
		cout << it->a << ' ';
	}
	cout << endl;
	return 0;
}