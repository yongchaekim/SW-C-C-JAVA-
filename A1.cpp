#include <iostream>
using namespace std;

#define MAXN ((int)1e4)

int N;
int cmd[MAXN+ 10];
int a[MAXN+10];

int stk[MAXN+10];
int sp;

void push(int d) {
    stk[++sp] = d;
}

int top() {
    return stk[sp];
}

bool empty() {
    
    return sp == 0;
}

int size() {
    return sp;
}

void pop() {
    sp--;
}

void Solve() {
    sp = 0;
    for(int i=0; i< N; i++) {
        switch(cmd[i]) {
            case 0:
                if(empty()) {
                    cout << "E" << "\n";
                }
                else {
                    cout << top() << "\n";
                    pop();
                }
                break;
            case 1:
            	push(a[i]);
            	break;
            
            default:
                cout << size() << "\n";
        }
    }
    
}

void InputData() {
    cin >> N;
    for(int i=0; i<N; i++) {
            cin >> cmd[i];
            if(cmd[i] == 1) {
                cin >> a[i];
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();
    Solve();
    return 0;
}
