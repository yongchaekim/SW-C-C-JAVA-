#include <stdio.h>
#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];
int stk[MAX + 10];
int sp;

void InputData(void) {
	scanf("%d", &N);
	scanf("%d", &M[0]);
	for (int i = 1; i < N; i++) {
		scanf(" %c %d", &op[i], &M[i]);
	}
}

int top(void) {
	return stk[sp];
}

void push(int d) {
	stk[++sp] = d;
}

void pop(void) {
	sp--;
}

int empty(void) {
	if(sp == 0) {
		return 1;
	}
	return 0;
}

int Solve(void){
	
	int sol=0;
	int d=0;
	push(M[0]);
	for(int i = 1; i < N; i++) {
		
		switch(op[i]) {
			case '-':
				push(-M[i]);
				break;
			case '+':
				push(M[i]);
				break;
			case '*':
				d = top() * M[i];
				pop();
				push(d);
				break;
			case '/':
				d = top() / M[i];
				pop();
				push(d);
			
		}
	}
	while(!empty()) {
			sol += top();
			pop();
		}
	return sol;
}

int main(void){
	int ans = -1;
	InputData();
	ans = Solve();
	printf("%d\n", ans);
	return 0;
}
