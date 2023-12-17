#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (10)
int H, W;
int map[MAXN+10][MAXN+10];
int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dc[8] = {-1, -1, 0, -1, 1, 1, 0, -1};
int rear=0;
int front=0;

struct node {
	int r;
	int c;
	int d;
};

struct node queue[(MAXN+10)*(MAXN+10)];


void InputData(void) {
	scanf("%d", &H);
	scanf("%d", &W);
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			scanf("%d", &map[i][j]);
			map[i][j]++;
		}
	}
}

int DFS(int r, int c) {
	if(map[r][c] != 2) return 0;
	map[r][c] = 3;
	int cnt=0;
	for(int i=0; i<8; i++) {
		cnt+= DFS(r+dr[i], c+dc[i]);
	}
	if(cnt<8) {
		map[r][c] = 3;
		struct node ele = {r, c, 0};
		queue[rear] = ele;
		rear=(rear+1)%((MAXN+10)*(MAXN+10));
	}
	return 1;
}

int check_boundary(int r, int c) {
	if((r>=0) && (r<H) && (c>=0) && (c<W)) return 1;
	return 0;
}

int BFS(void) {
	int cnt=0;
	while(rear != front) {
		struct node elem = queue[front];
		front=(front+1)%((MAXN+10)*(MAXN+10));
		map[elem.r][elem.c] = 1;
		cnt++;
	}
	return cnt;
}


int Solve(void) {
	int sol=0;
	int max=0;
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			if(map[i][j] == 2) {
				DFS(i, j);
				sol = BFS();
				if(sol > max) {
					max = sol;
				}
			}
		}
	}
	return max;
}


int main(void) {
	int ans=-1;
	InputData();
	ans = Solve(); 
	printf("%d\n", ans);
	return 0;
}
