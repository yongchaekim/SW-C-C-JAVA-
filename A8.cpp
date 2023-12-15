#include <iostream>
#include <queue>
using namespace std;

#define MAXN (1000)
int W, H;
int sw, sh, ew, eh;
char map[MAXN+10][MAXN+10];
bool visited[MAXN+10][MAXN+10];
int dh[] = {-1, 0, 1, 0};
int dw[] = {0, 1, 0, -1};

struct QUE {
	int h, w, t;
};

queue <QUE> que;

void InputData(){
    cin >> W >> H;
    cin >> sw >> sh >> ew >> eh;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
}

int Solve() {
	
	fill(&visited[0][0], &visited[MAXN+10-1][MAXN+10], 0);
	que = {};
	que.push({sh, sw, 0});
	visited[sh][sw] = true;
	while(!que.empty()) {
		QUE node = que.front();
		que.pop();
		if((node.h == eh) && (node.w == ew)) {
			return node.t;
		}
		for(int i=0; i<4; i++) {
			int nh = node.h + dh[i];
			int nw = node.w + dw[i];
			if(map[nh][nw] != '0') continue;
			if(visited[nh][nw]) continue;
			que.push({nh, nw, node.t+1});
			visited[nh][nw] = true;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();
	ans = Solve();
	cout << ans << "\n";
	return 0;
}
