int BinarySearch(int s, int e, int d) {
	while(s<=e) {
		int m=(s+e)/2;
		if(A[m] == d){
			return m;
		}
		else if(A[m]> d) {
			e=m-1;
		}
		else {
			s=m+1;
		}
	}
	return -1;
}


int BinarySearchLower(int s, int e, int d) {
	int sol=-1;
	while(s<=e) {
		int m=(s+e)/2;
		if(A[m]==d) {
			sol=m;
			e=m-1;
		}
		else if(A[m]>d) {
			e=m-1;
		}
		else {
			s=m+1;
		}
	}
	return sol;
}


int BinarySearchUpper(int s, int e, int d) {
	int sol=-1;
	while(s<=e) {
		int m=(s+e)/2;
		if(A[m]==d) {
			sol=m;
			s=m+1;
		}
		else if(A[m]>d) {
			e=m-1;
		}
		else {
			s=m+1;
		}
	}
	return sol;
}
