#include <iostream>
using namespace std;

#define MAXN ((int)1e4)
int N;
int cmd[MAXN+10];
int a[MAXN+10];

int que[MAXN+10];
int frt, rer;

void push(int d) {
	que[rer] = d;
	rer = (rer+1)%(MAXN+10);
}

void pop() {
	frt=(frt+1)%(MAXN+10);
}

int front() {
	return que[frt];
}

bool empty() {
	return frt == rer;
}

int size() {
	return rer-frt;
}

void Solve() {
	frt = rer = 0;
	for(int i=0; i<N; i++) {
		switch(cmd[i]) {
			case 0:
				if(empty()) {
					cout << "E" << "\n";
				}
				else {
					cout << front() << "\n";
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
		if(cmd[i] == 1){
			cin >> a[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();
	Solve();
	return 0;
}
