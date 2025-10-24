#include <iostream>
#include <algorithm>
using namespace std;

int n, t;
class tree
{
public:
	int num;
	tree* left, *right;
	tree(int a)
	{
		num = a;
		left = right = nullptr;
	}
	void insert(tree* node)
	{
		if(node->num < this->num)
		{
			if(this->left) this->left->insert(node);
			else this->left = node;
		}
		else
		{
			if(this->right) this->right->insert(node);
			else this->right = node;
		}
	}
	int dep(int a)
	{
		int t=0;
		if(this->left) t=max(t, this->left->dep(a+1));
		if(this->right) t=max(t, this->right->dep(a+1));
		return t+1;
	}
	void zhongxu()
	{
		if(this->left) left->zhongxu();
		cout << num << ' ';
		if(this->right) right->zhongxu();
	}
};

tree* root, *node;

int main()
{
	cin >> n;
	while(n--) 
	{
		cin >> t;
		node = new tree(t);
		if(!root) root = node;
		else root->insert(node);
	}
	cout << root->dep(1) << endl;
	root->zhongxu();
}