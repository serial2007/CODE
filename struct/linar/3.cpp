#include <iostream>
typedef int datatype;
struct node{
	datatype data;
	node *link;
};
void func(node* &first)
{
	node* max=nullptr, *prev = nullptr, *max_prev=nullptr;
	//定位最大的那个元素
	for(node* it=first; it; it=it->link)
	{
		if(!max || it->data > max->data)
		{
			max = it;
			max_prev = prev;
		}
		prev = it;
	}
	// 如果已经在最后了，那就不管
	if(max == prev) return;
	if(max_prev)
	{
		max_prev->link = max->link;
	}else
	{
		first = first->link;
	}
	prev->link = max;
	max->link = nullptr;
}
using namespace std;
int main()
{
	node* first=nullptr, *last=nullptr;
	datatype a;
	while(cin>>a)
	{
		if(!first){
			first = new node;
			first->data = a;
			first->link = nullptr;
			last = first;
		}
		else
		{
			last->link = new node;
			last->link->data = a;
			last->link->link = nullptr;
			last = last->link;
		}
	}
	func(first);
	for(node* it=first; it; it=it->link)
		cout << it->data << ' ';
	cout << endl;
	return 0;
}