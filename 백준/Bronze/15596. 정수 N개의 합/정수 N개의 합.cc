#include<iostream>
#include<vector>
using namespace std;
long long sum(vector<int> &a) {
	int i;
	long long sum=0;
	for (i = 0;i < a.size();i++) {
		sum += (long long)a[i];
	}
	return sum;
}