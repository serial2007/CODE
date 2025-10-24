#include <bits/stdc++.h>
using namespace std;
#define maxn 50010
#define ll long long

struct Node{
	int to,next;
} edge[maxn<<2];
int head[maxn],num,d[maxn];
int n,m;

void add(int x, int y){
	edge[++num].to=y;
	edge[num].next=head[x]; // 链表
	head[x]=num;
}

void getdp(int u, int root){
	d[u] = d[root]+1;
	
}

int main() {
	cin>>n>>m;
	int x,y;
	for(int i=0; i<n-1; i++)
	{
		cin>>x>>y;
		add(x,y);add(y,x);
	}

}