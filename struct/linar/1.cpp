#include <iostream>
#include <iomanip>
struct Node
{
	int id;
	Node* next;
};

void init(int num, Node* &first, Node* &last)
{
	Node* prev = nullptr;
	for(int i=0; i<num; i++)
	{
		last = new Node;
		last->id = i+1;
		if(i==0) first = last;
		else prev->next = last;
		prev = last;
	}
	last->next = first;
}

void update(Node* &node, Node* &prev, int m, int n)
{
	Node* first = nullptr; // 新的链表首
	Node* last = nullptr; // 新的链表尾
	for(int i=0; i<m; i++)
	{
		for(int j=1; j<n; j++)
		{
			prev = node;
			node = node->next;
		}
		if(first==nullptr) first = node;
		prev->next = node->next;
		
		if(last!=nullptr) last->next = node;
		last = node;

		prev = node;
		node = node->next;
	}
	last->next = first;
	node = first;
}

int main()
{
	int m, n;
	std::cin >> m;
	Node *first, *last;
	init(m, first, last);
	while(std::cin >> n)
	{
		update(first, last, m, n);
	}
	Node* it = first;
	for(int i=0; i<m; i++)
	{
		std::cout << std::setw(4) << it->id;
		it = it->next;
	}
	std::cout << std::endl;
	return 0;
}