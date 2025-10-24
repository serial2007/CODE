#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string st;
int tree[100001], n;
int dep;

bool dfs(int a, int &dep = dep)
{
	if(a >= n || tree[a] == -1) 
	{
		dep = 0;
		return true;
	}
	int left_dep, right_dep;
	if(!dfs(a*2+1, left_dep) || !dfs(a*2+2, right_dep))
	{
		return false;
	}else
	{
		dep = max(left_dep, right_dep) + 1;
		return abs(left_dep)-abs(right_dep)<=1;
	}
}
int main()
{
	while(cin >> st)
	{
		while(n>0 && tree[(n-1)/2] < 0)
		{
			tree[n++] = -1;
		}
		if(st[0] >= '0' && st[0] <= '9')
		{
			tree[n++] = stoi(st);
		}
		else
		{
			tree[n++] = -1;
		}
	}
	cout << ((dfs(0)) ? "True" : "False");
}