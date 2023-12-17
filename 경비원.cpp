include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN (100)
int W, H;
int N;
int Dir[MAXN+10];
int Len[MAXN+10];

struct node {
	int x;
	int y;
};


void InputData(void) {
	scanf("%d %d", &W, &H);
	scanf("%d", &N);
	for(int i=0; i<=N; i++) {
		scanf("%d %d", &Dir[i], &Len[i]);
	}
} 

int DynamicProgram(struct node start, struct node end) {
	int sumClockwise = 0;
    int sumAntiClockwise = 0;
    struct node start1 = start, start2 = start;
    
    while (1) {
        //Fill the border with clockwise direction
        if (start1.y > 0 && start1.x == H) { // go LEFT  5, 3
            start1.y --;
            sumClockwise += 1;
        }
        if (start1.y == 0 && start1.x > 0) { // go UP
            start1.x--;
            sumClockwise += 1;
        }
        if (start1.y < W && start1.x == 0) { // go RIGHT
            start1.y++;
            sumClockwise += 1;
        }
        if (start1.y == W && start1.x < H) { // go DOWN
            start1.x++;
            sumClockwise += 1;
        }
        if (start1.x == end.x && start1.y == end.y) {
            break;
        }
        if ((start1.x == start.x && start1.y == start.y) ) {
        	sumClockwise = -1;
            break;
        } 
    }
    while(1) {

        //Fill the border with anti-clockwise direction
        if (start2.y > 0 && start2.x == 0) { // go LEFT
            start2.y --;
            sumAntiClockwise += 1;
        }
        if (start2.y == W && start2.x > 0) { // go UP
            start2.x--;
            sumAntiClockwise += 1;
        }
        if (start2.y < W && start2.x == H) { // go RIGHT
            start2.y++;
            sumAntiClockwise += 1;
        }
        if (start2.y == 0 && start2.x < H) { // go DOWN
            start2.x++;
            sumAntiClockwise += 1;
        }
        
        if (start2.x == end.x && start2.y == end.y) {
            break;
        }
        if((start2.x == start.x && start2.y == start.y)) {
        	sumAntiClockwise=-1;
        	break;
		}
    }

    if(sumAntiClockwise < sumClockwise) return sumAntiClockwise;
    return sumClockwise;
}


struct node convertToPoint(int dir, int len) {
    struct node result = {0, 0};
    switch (dir) {
    case 1:
        result.x = 0;
        result.y = len;
        break;
    case 2:
        result.x = H;
        result.y = len;
        break;
    case 3:
        result.x = len;
        result.y = 0;
        break;
    case 4:
        result.x = len;
        result.y = W;
        break;
    default:
        break;
    }
    return result;
}



int Solve(void) {
	struct node startPoint = convertToPoint(Dir[N], Len[N]);
	int sol = 0;
    for (int i = 0; i < N; i++) {
        struct node p = convertToPoint(Dir[i], Len[i]);
        int shortestpath = DynamicProgram(startPoint, p);
    //   if(shortestpath != -1) {
        	sol += shortestpath;
	/*	} else {
			sol = -1;
			break;
		}*/
    }
    return sol;
}


int main(void) {
	int ans=-1;
	InputData();
	ans = Solve();
	printf("%d\n", ans);
	return 0;
}
