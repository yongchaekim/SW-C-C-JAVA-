#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN ((int)5e3)
int N;
struct DATA {
	int d;
};

DATA A[MAXN+10];
vector<DATA> data;

bool comp(DATA &a, DATA &b)
{
	return a.d < b.d;
}

void InputData() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> A[i].d;
		data.push_back(A[i]);
	}
}

void OutputData() {
	for(int i=0; i<N; i++) {
		cout << data.at(i).d << " ";
	}
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
