#include <bits/stdc++.h>
const int N = 1e5+5;

using namespace std;
struct edge {
	int to;
};

vector<edge> e[N];
int n;
int t1[N],t2[N], dep[N];
bool flg[N];

int maxl, maxk;

int dfs(int k, int fa) {
	int d1 = 0, d2 = 0;
	for(auto l : e[k])
	{
		if(l.to == fa) continue;
		int t = dfs(l.to, k) + 1;
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

int k;

int build_tree(int k, int fa) {
	for(auto l : e[k]) {
		if(l.to == fa) continue;
		dep[k] = max(dep[k], build_tree(l.to, k)+1);
	}
	return dep[k];
}

void find_nxt(int k, int fa) {
	if(dep[k]==0) return;
	for(auto l : e[k]) {
		if(l.to == fa) continue;
		if(flg[l.to]) {
			find_nxt(l.to, k);
		}else{
			int t = dep[l.to]+1;
			if (t > maxl) {
				maxl = t;
				maxk = l.to;
			}
		}
	}
}


int main() 
{
	cin>>n>>k;
	for(int i=1; i<n; i++) {
		int x,y,z;
		cin>>x>>y;
		e[x].push_back(edge{y});
		e[y].push_back(edge{x});
	}
	get_diameter();

	if(k<=1) {
		cout<<((ln%2) ? (ln/2) : ((ln-1)/2));
		return 0;
	}
	int root=diameter[(ln+1)/2 - 1];
	build_tree(root, 0);
	flg[root] = 1;
	k--;
	// for(int i=1; i<=n; i++)
	// 	cout<<dep[i]<<' ';
	// cout<<endl;

	// cout<<root<<' ';
	while(k--) {
		maxl=0;
		find_nxt(root, 0);
		flg[maxk] = 1;
		// cout<<maxk<<' ';
	}
	find_nxt(root, 0);
	cout<<maxl;
}