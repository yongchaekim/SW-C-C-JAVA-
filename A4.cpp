#include <stdio.h>
#define MAXN ((int)1e4)
int N;
int cmd[MAXN + 10];
int a[MAXN + 10];
int que[MAXN + 10];
int wp, rp;

void enque(int d) {
	que[wp++] = d;
}

void deque(void) {
	rp++;
}

int front(void) {
	return que[rp];
}

int empty(void) {
	return wp == rp;	
}

int size(void) {
	return wp - rp;
}

void Solve(void) {
	wp = rp = 0;
	for (int i=0; i < N; i++) {
		switch(cmd[i]) {
			case 0:
				if (empty()) {
					printf("E\n");
				} else {
					printf("%d\n", front());
					deque();
				}
				break;
			case 1:
				enque(a[i]);
				break;
			default:
				printf("%d\n", size());
		}
	}
}

void InputData(void) {
	scanf("%d", &N);
	for(int i=0; i < N; i++) {
		scanf("%d", &cmd[i]);
		if(cmd[i] == 1) {
			scanf("%d", &a[i]);
		}
	}
}

int main(void) {
	InputData();
	Solve();
	return 0;
}
