void sort(int s, int e) {
	if(s>=e) return;
	int i=s; int k=s; int m=(s+e)/2; int j=m+1;
	sort(s, m); sort(j, e);
	while((i<=m) && (j <= e)) {
		if(A[i] >= A[j]) tmp[k++] = A[j++];
		else tmp[k++] = A[i++]; 
	}
	while(i<=m) tmp[k++] = A[i++];
	while(j<=e) tmp[k++] = A[j++];
	for(int i=s; i<=e; i++) A[i] = tmp[i];
}
