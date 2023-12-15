#include <iostream>
using namespace std;

#define MAX ((int)2e5)

int N;
int A[MAX+10];
int M;
int B[MAX+10];

void InputData() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> A[i];
	}
	cin >> M;
	for(int i=0; i<M; i++) {
		cin >> B[i];
	}
}

int UpperBinarySearch(int s, int e, int d) {
	int sol = -1;
	while(s<=e) {
		int m = (s+e)/2;
		if(A[m] == d) {
			sol = m;
			s=m+1;
		} else if(A[m] > d) {
			e=m-1;
		} else {
			s=m+1;
		}
	}
	return sol;
}

int LowerBinarySearch(int s, int e, int d) {
	int sol = -1;
	while(s<=e) {
		int m = (s+e)/2;
		if(A[m] == d) {
			sol=m;
			e=m-1;
		} else if(A[m] > d) {
			e=m-1;
		} else {
			s=m+1;
		}
	}
	return sol;
}

void Solve() {
	for(int i=0; i<M; i++) {
		int lower = LowerBinarySearch(0, N-1, B[i]);
		if(lower != -1) {
			int upper = UpperBinarySearch(0, N-1, B[i]);
			B[i] = upper-lower+1;
		}else {
			B[i] = 0;
		}
	}
}

void OutputData() {
	for(int i=0; i<M; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();
	Solve();
	OutputData();
	return 0;
}
