#include <stdio.h>
#define MAXN (100)

int W, H;
char map[MAXN+10][MAXN+10];
int data[MAXN+10][MAXN+10];
int sw, sh;
int soltime, sozergling;
int dr[]={-1, 1, 0, 0};
int dc[]={0, 0, -1, 1};
int valid=0;

void InputData(void) {
	scanf("%d %d", &W, &H);
	for(int i=1; i<=H; i++) {
		scanf("%s", &map[i][1]);
	}
	scanf("%d %d", &sw, &sh);
	
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			data[i][j] = map[i][j]-'0';
		}
	}
}

int check_boundary(int r, int c) {
	if((r > 0 && r <= H) && (c > 0 && c <= W))
		return 1;
	return 0;
}

int Clean(void) {	
	int cnt=0;
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			if(data[i][j] == 2) {
				data[i][j] = 3;
			} else if(data[i][j] == 1) {
				cnt++;
			}
		}
	}
	return cnt;	
}

void FloodFill(int r, int c) {

	if(!check_boundary(r, c)) return;
	if(data[r][c]==1) {
		data[r][c] =2;
		valid=1;
		return;
	}
	if(data[r][c] != 3) return;
	data[r][c]= 2;
	for(int i=0; i<4; i++) {
		FloodFill(r+dr[i], c+dc[i]);
	}
}
/*
void print(void) {
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
}
*/
void Solve(void) {
	sozergling=0;
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			if(data[i][j] == 1) 
				sozergling++; //Count the number of StarCraft 
		}
	}
	data[sh][sw] = 3;
//	print();
	soltime=3;
	for(; ;) {
		//print();
		FloodFill(sh, sw);
		int ret = Clean();
		sozergling = ret;
		
		if(valid == 0) break;
		soltime++;
		if(ret == 0) break;
		valid=0;
		
	}
	//print();
}


int main(void) {
	InputData();
	Solve();
	printf("%d\n%d\n", soltime, sozergling);
	return 0;
}
