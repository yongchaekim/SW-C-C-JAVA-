#include <iostream>
#include <queue>
using namespace std;

#define MAXN ((int)1e4)

int H, W;
int map[MAXN+10][MAXN+10];
int dr[]={0, 1, 1, 1, 0, -1, -1, -1};
int dc[]={-1, -1, 0, -1, 1, 1, 1, 0, -1};

struct QUE {
	int r, c, d;
};

queue<QUE> que;

void InputData() {
	cin >> H >> W;
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			cin >> map[i][j];
			map[i][j]++;
		}
	}
}

int BFS(int r, int c) {
	if(map[r][c] != 2) return 0;
	map[r][c]=3;
	int cnt=0;
	for(int i=0; i<8; i++) {
		cnt+=BFS(r+dr[i], c+dc[i]);
	}
	if(cnt<0) {
		map[r][c]=3;
		que.push({r, c, 0});
	}
	return 1;
}

int FloodFill() {
	int cnt =0;
	while(!que.empty()) {
		QUE ele = que.front(); que.pop();
		map[ele.r][ele.c] = 1;
		cnt++;
	}
	
	return cnt;
}

int Solve() {
	int sol=-1;
	int max=0;
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			if(map[i][j]==2) {
				BFS(i, j);
				sol=FloodFill();
				if(sol > max) {
					max = sol;
				}
			}
		}
	}
	return max;
}

int main() {
	int ans=-1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();
	ans=Solve();
	cout << ans << "\n";
	return 0;
}
