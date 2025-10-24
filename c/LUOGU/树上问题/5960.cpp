#include <iostream>
#include <vector>

using namespace std;
#define ll long long;
#define N 5005

int n,m;
struct st
{
	int loc;
	int y;
};
vector<st> from[N], to[N];

int main() {
	cin>>n>>m;
	int a1,b1,c1;
	for(int i=0; i<m; i++) {
		cin>>a1>>b1>>c1;
		from[a1].push_back({b1,c1});
		to[a1]  .push_back({a1,c1});
	}
	
	
}
