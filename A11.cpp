#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN (25)
int N;
char map[MAXN+10][MAXN+10];
vector<int> sol;

int dh[]={-1, 1, 0, 0};
int dw[]={0, 0, -1, 1};

struct QUE{
	int h, w;
};

queue<QUE> que;

bool comp(int a, int b) {
	return a<b;
}

void InputData() {
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> &map[i][1];
	}
}


int FloodFill(int h, int w) {
	int cnt =0;
	que={};
	que.push({h, w});
	map[h][w]='2';
	cnt++;
	while(!que.empty()) {
		QUE cur = que.front(); que.pop();
		for(int i=0; i<4; i++) {
			int nh=cur.h+dh[i];
			int nw=cur.w+dw[i];
			if(map[nh][nw] != '1') continue;
			que.push({nh, nw});
			map[nh][nw]='2';
			cnt++;
		}
	}
	return cnt;
}

int Solve() {
	sol={};
	for(int h=1; h<=N; h++) {
		for(int w=1; w<=N; w++) {
			if(map[h][w] != '1') continue;
			sol.push_back(FloodFill(h, w));
		}
	}
	return sol.size();
}

void OutputData(int ans) {
	cout << ans << "\n";
	sort(sol.begin(), sol.end(), comp);
	for(int i=0; i<ans; i++) {
		cout << sol[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();
	int ans=Solve();
	OutputData(ans);
	return 0;
}
