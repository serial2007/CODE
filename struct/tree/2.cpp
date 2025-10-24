#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string st;
int tree[100001], n;

int dfs(int a)
{
	if(a >= n || tree[a] == -1) return 0;
	return max(dfs(a*2+1), dfs(a*2+2)) + 1;
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
	cout << dfs(0);
}