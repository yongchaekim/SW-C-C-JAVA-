#include <stdio.h>
#define MAXN (100)


int N, M;
int P[MAXN + 10];


void InputData(void) {
	scanf("%d %d", &N, &M);
	for(int i=0; i < N; i ++) {
		scanf("%d", &P[i]);
	}
}

struct Node {
	int n;
	int p;
};

struct Node queue[100*100];

int Solve(void) {
	int front=0;
	int rear=0;
	int seq=0;
	int cnt[10] = {0};
	
	
	for(int i = 0; i < N; i++) {
		cnt[P[i]]++;	
		struct Node ele = {i, P[i]};
		queue[rear]= ele;
		rear = (rear+1) % (100*100);
	}
	
	for(int j = 9; j >= 1; j--) {
		
		while(cnt[j]) {
			struct Node cur = queue[front];
			front = (front+1) % (100*100);
			if(cur.p == j) {
				seq++;
			
				if(cur.n == M)
					return seq;
					
			 cnt[j]--;		
			
			} else {
				queue[rear] = cur;
				rear = (rear+1) % (100*100);
			}
		}
	}
	return -1;
}

int main(void) {
	int ans = -1;
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		InputData();
		ans = Solve();
		printf("%d\n", ans); 
	}
	return 0;
}
