#include <stdio.h>
#define MAXN (100)
int N;
int sol[MAXN + 10];

struct Node {
	int d;
};

struct Node queue[100 * 100];

void InputData(void) {
	scanf("%d", &N);
}

void OutputData(void) {
	for(int i=0; i<N; i++) {
		printf("%d ", sol[i]);
	}
}

void Solve(void) {
	int rear=0;
	int front=0;
	int back;
	int k;
	
	for(int i=1; i<=N; i++) {  
		struct Node elem = {i};
		queue[rear] = elem;
		rear = (rear+1) % (100 * 100);
	}
	
	for(int i=0; i < N-1; i++) {
		struct Node data = queue[rear-1];
		back = (data.d)/2;
		for(int j=0; j < back; j++) {
			struct Node ele = queue[front];
			front = (front+1) % (100 * 100);
			queue[rear] = ele;
			rear = (rear+1) % (100 * 100);
		}
		struct Node dat = queue[front];
		sol[k++] = dat.d;
		front = (front+1) % (100 * 100);
	}
	struct Node info = queue[front];
	sol[k++] = info.d;
	front = (front+1) % (100 * 100);
	
}

int main(void) {
	InputData();
	Solve();
	OutputData();
	return 0;
}
