#include <bits/stdc++.h>
#define N 300005

using namespace std;
struct edge {
	int to,w;
};

vector<edge> e[N];
int n,m;
int t1[N],t2[N];

int maxl, maxk;

int dfs(int k, int fa) {
	int d1 = 0, d2 = 0;
	for(auto l : e[k])
	{
		if(l.to == fa) continue;
		int t = dfs(l.to, k) + l.w;
		if (t>d1) d2=d1,t2[k]=t1[k],d1=t,t1[k]=l.to;
		else if(t>d2) d2=t, t2[k]=l.to;
	}
	if(d1+d2 > maxl) {
		maxl = d1+d2;
		maxk = k;
	}
	return d1;
}

int diameter[N], ln=0;
void get_diameter() {
	dfs(1,0); 
	for(int u=maxk; u; u=t1[u]) {
		diameter[ln++] = u;
	}
	reverse(diameter, diameter+ln);
	for(int u=t2[maxk]; u; u=t1[u]) {
		diameter[ln++] = u;
	}
}

int main() 
{
	cin>>n>>m;
	for(int i=1; i<n; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back(edge{y,z});
		e[y].push_back(edge{x,z});
	}
	get_diameter();
	for (int i=0; i<ln; i++)
		cout<<diameter[i]<<' ';
}