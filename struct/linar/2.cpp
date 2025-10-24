#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
struct Node
{
	float a; 
	int k;
	Node* next;
};

Node* input()
{
	string line;
	getline(cin, line);
	istringstream iss(line);
	float a; int k;	
	Node *first = nullptr, *last = nullptr, *prev = nullptr;
	while(iss >> a >> k)
	{
		last = new Node;
		last->a = a; last->k = k;
		if(!first) first = last;
		else prev->next = last;
		prev = last;
	}
	if(last) last->next = nullptr;
	return first;
}
constexpr float eps=1e-6f;
void join(Node* &first, Node t)
{
	if(!first)
	{
		first = new Node(t);
		return;
	}
	Node* prev = first;
	for(Node* it=first; it; it=it->next)
	{
		// 加到同样的 rank
		if(it->k == t.k) {
			it->a += t.a; 
			if(it->a < eps && -it->a < eps)
			{
				if(prev) prev->next = it->next;
				if(it==first) first = it->next;
				delete it;
			}
			return;
		}
		// 插入到多项式
		if(t.k > it->k) {
			if(it==first) {
				first = new Node(t);
				first->next = it;
			}else
			{
				prev->next = new Node(t);
				prev->next->next = it;
			}
			return;
		}
		prev = it;
	}
	prev->next = new Node(t);
}

Node* add(Node* a, Node* b)
{
	Node* c = nullptr;
	for(Node* i=a; i; i=i->next) join(c, *i);
	for(Node* j=b; j; j=j->next) join(c, *j);
	return c;
}

int main()
{
	Node* a = input(), *b = input(), *c, *it;
	c = add(a, b); it=c;
	int w; cin>>w;
	for(int i=0; i<w-1; i++) it=it->next;
	cout << fixed << setprecision(1) << it->a <<
		' ' << it->k << endl;
}