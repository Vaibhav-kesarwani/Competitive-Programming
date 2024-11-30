#include<iostream>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n = 0, m = 0, k = 0;
bool st[501][501] = { 0 };
char map[501][501] = { 0 };
bool dfs(int x, int y) {
	st[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if (!st[x1][y1] && map[x1][y1] == '.')
		{
			dfs(x1, y1);
		}
	}
	if (k > 0) {
		map[x][y] = 'X';
		k--;
	}
	return false;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%s",map[i]);
	int ti = 0, tj = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (map[i][j] == '.')
			{
				dfs(i, j);
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j)
						printf("%c", map[i][j]);
					printf("\n");
				}
				return 0;
			}
	}
	return 0;
}