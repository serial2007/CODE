#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class tree{
public:
	int num;
	tree* left, *right;

	tree(int a)
	{
		num = a;
		left = right = nullptr;
	}
};

int a[10001], n, t;
vector<tree*> vec, newvec;
tree* tree_inf = new tree(0x3fffffff);

int get_len(tree* a, int dep)
{
	if(!a) return -1;
	if(a->left && a->right)
	{
		return get_len(a->left, dep+1) + get_len(a->right, dep+1);
	}
	else return dep * a->num;
}


int main() 
{
	tree* root;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> t;
		vec.push_back(new tree(t));
	}
	while(vec.size() > 1)
	{
		tree * min1 = tree_inf;
		tree * min2 = tree_inf;
		for(auto& it : vec)
		{
			if(it->num < min1->num)
			{
				min2 = min1;
				min1 = it;
			}
			else if(it->num < min2->num)
			{
				min2 = it;
			}
		}
		newvec.clear();
		for(auto& it : vec)
		{
			if(it != min1 && it != min2)
			{
				newvec.push_back(it);
			}
		}
		tree* node = new tree(min1->num + min2->num);
		node->left = min1;
		node->right = min2;
		newvec.push_back(node);
		vec = newvec;
	}
	root = vec[0];
	cout << get_len(root, 0);
}