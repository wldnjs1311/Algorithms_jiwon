#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define X first
#define Y second

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	int count = 0, maxWidth = 0, width;
	cin >> n >> m;

	//배열 정보 입력
	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;
			vis[i][j] = 1;
			Q.push({ i, j});
			width = 1;
			count++;
			

			while (!Q.empty()) { //하나의 그림을 찾는 방법
				pair<int, int> cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
					width++;
				}
			}
			if (width > maxWidth) maxWidth = width;
		}
	}

	cout << count << "\n" << maxWidth;
}