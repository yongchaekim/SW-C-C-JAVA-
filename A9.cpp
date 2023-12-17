#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
#define IMP (1<<30)

int N, M;
int S[MAXN+2][MAXN+2]; // [s][e] = 시간
int VISITED[MAXN+2];
int PATH[MAXN+2];

queue <int> que;

void InputData() {
    cin >> N >> M;
    for(int s=1; s<=N; s++) {
        for(int e=1; e<=N; e++) {
            cin >> S[s][e];
        }
    }
}

int Solve() {
    
    for(int i=1; i<=N; i++) {
        VISITED[i]=IMP;
        PATH[i]=0;
    }
    
    VISITED[1]=0;
    PATH[1]=0;
    que={};
    que.push(1);
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(int e=2; e<=N; e++) {
            int ntime=VISITED[cur]+S[cur][e];
            if(VISITED[e] <= ntime) continue;
                que.push(e);
                VISITED[e] = ntime;
                PATH[e]=cur;
        }
    }
    return VISITED[M];
}

void Prt(int m) {
    if(m == 0) return;
    Prt(PATH[m]);
    cout << m << " ";
}

void Output() {
    Prt(M);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans=-1;
    InputData();
    ans=Solve();
    cout << ans << "\n";
    Output();
    return 0;
}
