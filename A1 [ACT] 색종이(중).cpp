#include <iostream>
using namespace std;

#define MAXN (100)

int N;

int dr[]={-1, 1, 0, 0};
int dc[]={0, 0, -1, 1};

int paper[MAXN+10][MAXN+10];

void FillPaper(int sr, int sc, int er, int ec) {
	for(int i=sr; i<er; i++) {
		for(int j=sc; j<ec; j++) {
			paper[i][j]=1;
		}
	}
}

void InputData() {
	int sc, sr;
	cin >> N;
	
	for(int i=0; i<N; i++) {
		cin >> sc >> sr;
		FillPaper(sr, sc, sr+10, sc+10);
	}
}

int Check(int r, int c) {
	int cnt=0;
	for(int i=0; i<4; i++) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if((nr<0) || (nr>=MAXN) || (nc<0) || (nc>=MAXN) || (paper[nr][nc] == 0)) 
		cnt++;
	}
	
	return cnt;
}
int Solve() {
	
	int area=0;
	for(int i=0; i<MAXN; i++) {
		for(int j=0; j<MAXN; j++) {
			if(paper[i][j] == 0) continue;
			area+=Check(i, j);
		}
	}
	return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int ans=-1;
	InputData();
	ans=Solve();
	cout << ans << endl;
	return 0;
}
