#include<iostream>
using namespace std;

const int inf = 0x7fffff - 1;
int e[10][10];
int n, m;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)e[i][j] = 0;
			else e[i][j] = inf;
		}
	}
	int src, dst, val;
	for (int i = 0; i < m; i++) {
		cin >> src >> dst >> val;
		e[src][dst] = val;
	}

	//Floyd-Warshall算法核心语句
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (e[i][k] + e[k][j] < e[i][j]) {
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", e[i][j]);
		}
		cout << endl;
	}

	return 0;
}

/*
4 8
0 1 2
0 2 6
0 3 4
1 2 3
2 0 7
2 3 1
3 0 5
3 2 12
 */
