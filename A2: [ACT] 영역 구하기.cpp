#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN (100)
int M, N, K;
int sx[MAXN+10];
int sy[MAXN+10];
int ex[MAXN+10];
int ey[MAXN+10];
int dr[]= {0, 0, -1, 1};
int dc[]= {-1, 1, 0, 0};

int Map[MAXN+10][MAXN+10];
int sol[MAXN * MAXN];

struct QUE {
	int r, c;
};

queue<QUE>que;

bool comp(int a, int b) {
	return a<b;
}

void InputData() {
	cin >> M >> N >> K; // 세로크기, 가로크기, 직사각형 개 
	for(int i=0; i<K; i++) {
		cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
	}
}

void OutputData(int ans) {
	cout << ans << "\n";
	sort(sol, sol+ans, comp);
	for(int i=0; i<ans; i++) {
		cout << sol[i] << " ";
	}
	cout << "\n";
}

void Restruct() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			Map[i][j] = 2;
		}
	}
} 

int FloodFill(int r, int c) {
	if(Map[r][c] !=2 ) return 0;
	Map[r][c]=3;
	int cnt=0;
	for(int i=0; i<4; i++) {
		cnt+=FloodFill(r+dr[i], c+dc[i]);
	}
	if(cnt < 4) {
		Map[r][c]=3;
		que.push({r, c});
	}
	return 1;
}

int Find() {
	int sum=0;
	while(!que.empty()) {
		que.pop();
		sum++;
	}
	return sum;
}

int Solve() {
	int total=0;
	int cnt=0;
	
	Restruct();
	
	for(int i=0; i<K; i++) {
		for(int j=sx[i]; j<ex[i]; j++) {
			for(int k=sy[i]; k<ey[i]; k++) {
				Map[j][k] = 1;
			}
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(Map[i][j]==2) {
				FloodFill(i, j);
				sol[cnt++]=Find();
				total++;
			}
		}	
	}
	
	return total;
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans=-1;
	InputData();
	ans=Solve();
	OutputData(ans);
	return 0;
}
