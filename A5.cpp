#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN ((int)5e3)
int N;
int A[MAXN+10];
vector<int> data;

bool comp(int &a, int &b)
{
	return a > b;
}

void InputData() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> A[i];
		data.push_back(A[i]);
	}
}

void OutputData() {
	
	
	for(int i=0; i<N; i++) {
		cout << data.at(i) << " ";
	}
	
	
	/*
	vector<int>::iterator iter;
	for(iter = data.begin(); iter != data.end(); iter++ ) {
		cout << *iter << " ";
	}
	*/

	cout << "\n";
}

void Solve() {
	sort(data.begin(), data.end(), comp);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();
	Solve();
	OutputData();
	return 0;
}
