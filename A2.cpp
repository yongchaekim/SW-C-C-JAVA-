#include <iostream>
using namespace std;

#define MAXN ((int)1e5) 

int N;
int H[MAXN+10];
int sol[MAXN+10];
int stk[MAXN+10];
int sp;

void push(int d) {
    stk[++sp] = d;
}

bool empty() {
    return sp == 0;
}

int top() {
   return stk[sp]; 
}

void pop() {
    sp--;
}

int size() {
    return sp;
}

void InputData() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> H[i];
    }
}

void OutputData() {
    for(int i=1; i <= N; i++) {
        cout << sol[i] << "\n";
    }
}

void Solve() {
    
    sp=0;
    for(int i=1; i<=N; i++){
        while(!empty() && (H[top()]< H[i])) {
            
                sol[top()] = i;
                pop();
            }
            push(i);
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
