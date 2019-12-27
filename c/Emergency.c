#include <stdio.h>
#define maxint 1<<28
int main(void) {
	int n, m, c1, c2;	// n:城市数量；m:道路数量; c1: 当前城市；c2：目标城市
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	int i, j;
	int t[510], a[510] = { 0 };
	int d[510], w[510] = { 0 }, v[510] = { 0 };
	for (i = 0; i<n; i++) {
		scanf("%d", &t[i]);	// t为每个城市的救援队数量
		d[i] = maxint;	// d存放c1到i的最短距离
	}
	int r[500][500];	// 存放道路长度
	int x, y;
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			r[i][j] = -1;
		}
	}
	for (i = 0; i<m; i++) {
		scanf("%d%d", &x, &y);
		scanf("%d", &r[x][y]);
		r[y][x] = r[x][y];
	}

	d[c1] = 0;
	a[c1] = t[c1];	// a存放能带的救援队数量
	w[c1] = 1;	// w存放最短路径个数

	for (i = 0; i<n; i++) {
		int minn = maxint, min;	// minn表示c1到各个城市的最短路径；min表示离c1最近的城市
		for (j = 0; j<n; j++) {	// 找到可以确定最短路径的结点
			if ((d[j]<minn) && (v[j] == 0)) {
				min = j;
				minn = d[j];
			}
		}
		if (minn == maxint) break;
		v[min] = 1;	// 1表示已经确定了最短路径的城市

		for (j = 0; j<n; j++)	// 更新后续结点
			if ((v[j] == 0) && (r[j][min] != -1)) {
				if (d[j]>d[min] + r[j][min]) {
					d[j] = d[min] + r[j][min];
					w[j] = w[min];
					a[j] = a[min] + t[j];
				}
				else if (d[j] == d[min] + r[j][min]) {
					w[j] += w[min];
					if (a[j]<a[min] + t[j]) a[j] = a[min] + t[j];
				}

			}
		if (min == c2) break;
	}

	printf("%d %d\n", w[c2], a[c2]);
}