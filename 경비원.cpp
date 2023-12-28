#include <iostream>
#include <string>
using namespace std;

#define MAXN (100)
int W, H;
int N;
int Dir[MAXN+10];
int Len[MAXN+10];

struct NODE {
	int x, y;
};

void InputData() {
	cin >> W >> H;
	cin >> N;
	for(int i=0; i=N; i++) {
		cin >> Dir[i] >> Len[i];
	}
}

int DynamicProgram(NODE s, NODE e) {
	int sumClockwise=0;
	int sumAntiClockwise=0;
	NODE start1=s;
	NODE start2=s;
	for(; ;) {
		
		// Fill the border with Clockwise direction
		if(start1.y>0 && start1.x == H) {
			start1.y--;
			sumClockwise+=1;
		}
		if(start1.y==0 && start1.x>0) {
			start1.x--;
			sumClockwise+=1;
		}
		if(start1.y<W && start1.x==0) {
			start1.y++;
			sumClockwise+=1;
		}
		if(start1.y==W && start1.x < H) {
			start1.x++;
			sumClockwise+=1;
		}
		if(start1.x==e.x && start1.y==e.y) {
			break;
		}
		if(start1.x==s.x && start1.y==s.y) {
			sumClockwise=-1;
			break;
		}
		
	}
	
	for(; ;) {
		// Fill the border with Anti-Clockwise direction
		if(start2.y>0 && start2.x==0) {
			start2.y--;
			sumAntiClockwise+=1;
		}
		if(start2.y==W && start2.x>0) {
			start2.x--;
			sumAntiClockwise+=1;
		}
		if(start2.y<W && start2.x == H) {
			start2.y++;
			sumAntiClockwise+=1;
		}
		if(start2.y==0 && start2.x < H) {
			start2.x++;
			sumAntiClockwise+=1;
		}
		if(start2.x==e.x && start2.y == e.y) {
			break;
		}
		if(start2.x==s.x && start2.y == s.y) {
			sumAntiClockwise=-1;
			break;
		}
		
	}
	
	if(sumAntiClockwise < sumClockwise) return sumAntiClockwise;
	return sumClockwise;
	
	return sumClockwise;
}

NODE convertToPoint(int dir, int len) {
	NODE result = {0,0};
	switch(dir) {
		case 1:
			result.x=0;
			result.y=len;
			break;
		case 2:
			result.x=H;
			result.y=len;
			break;
		case 3:
			result.x=len;
			result.y=0;
			break;
		case 4:
			result.x=len;
			result.y=W;
			break;
		default:
			break;
	}
	return result;
}

int Solve() {
	NODE startPoint = convertToPoint(Dir[N], Len[N]);
	int sol=0;
	for(int i=0; i<N; i++) {
		NODE p = convertToPoint(Dir[i], Len[i]);
		int shortestpath = DynamicProgram(startPoint, p);
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans=-1;
	InputData();
	ans=Solve();
	cout << ans << "\n";
}
