#include <iostream>
using namespace std;
#define MAXN ((int)5e4)
#define MAXT ((int)1e4)
int N;
int A[MAXN+10];
int T;
int B[MAXN+10];

void InputData() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> B[i];
    }
}

int BinarySearch(int s, int e, int d) {
    int sol = 0;
    while(s<=e) {
        int m = (s+e)/2;
        if(A[m] == d) {
            sol = m;
            return sol;
        } else if (A[m] > d) {
            e=m-1;
        } else {
            s=m+1;
        }
    }
    return 0;
}

void Solve() {
    
    for(int i=0; i<T; i++) {
     B[i] = BinarySearch(1, N, B[i]);   
    }
}

void OutputData() {
    for(int i=0; i<T; i++) {
        cout << B[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();
    Solve();
    OutputData();
    return 0;
}
