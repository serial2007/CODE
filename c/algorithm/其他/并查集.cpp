#include <cstdio>

int n, m, fa[10010], size[10010];//size数组记录各集合的秩

int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);//路径压缩
}

void merge(int x, int y) {
	int X = get(x), Y = get(y);
	if (size[X] > size[Y]) {//比较两集合秩的大小，然后按秩合并
		fa[Y] = X;
		size[X] += size[Y];
	} else {
		fa[X] = Y;
		size[Y] += size[X];
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		size[i] = 1;//最开始每个集合的秩都是1
	}
	for (int i = 1; i <= m; i++) {
		int z, x, y;
		scanf("%d %d %d", &z, &x, &y);
		if (z == 1) merge(x, y);
		if (z == 2) {
			if (get(x) == get(y)) puts("Y");
			else puts("N");
		}
	}
	return 0;
}