#include <stdio.h>
#define maxint 1<<28
int main(void) {
	int n, m, c1, c2;	// n:����������m:��·����; c1: ��ǰ���У�c2��Ŀ�����
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	int i, j;
	int t[510], a[510] = { 0 };
	int d[510], w[510] = { 0 }, v[510] = { 0 };
	for (i = 0; i<n; i++) {
		scanf("%d", &t[i]);	// tΪÿ�����еľ�Ԯ������
		d[i] = maxint;	// d���c1��i����̾���
	}
	int r[500][500];	// ��ŵ�·����
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
	a[c1] = t[c1];	// a����ܴ��ľ�Ԯ������
	w[c1] = 1;	// w������·������

	for (i = 0; i<n; i++) {
		int minn = maxint, min;	// minn��ʾc1���������е����·����min��ʾ��c1����ĳ���
		for (j = 0; j<n; j++) {	// �ҵ�����ȷ�����·���Ľ��
			if ((d[j]<minn) && (v[j] == 0)) {
				min = j;
				minn = d[j];
			}
		}
		if (minn == maxint) break;
		v[min] = 1;	// 1��ʾ�Ѿ�ȷ�������·���ĳ���

		for (j = 0; j<n; j++)	// ���º������
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