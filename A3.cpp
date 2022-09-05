#include <stdio.h>
#define MAXN ((int)1e5)
int N;
int H[MAXN+10];
int sol[MAXN+10];
int stk[MAXN + 10];
int sp;

void InputData(void) {
	scanf("%d", &N);
	for(int i=1; i <= N; i++) {
		scanf("%d", &H[i]);
	}
}

void push(int d) {
	stk[++sp] = d;
}

void pop(void) {
	sp--;
}

int empty(void) {
	if(sp <= 0) {
		return 1;
	}
	return 0;
}


void OutputData(void) {
	for(int i=1; i <= N; i++) {
		printf("%d\n", sol[i]);
	}
}

int top(void) {
	return stk[sp];
}

void Solve(void) {
	sp = 0;
	for(int i=1; i <= N; i++) {
		while(!empty() && H[top()] < H[i]) {
			sol[top()] = i;
			pop();
		}
		push(i);
	}
}

int main(void) {
	InputData();
	Solve();
	OutputData();
	return 0;
}
