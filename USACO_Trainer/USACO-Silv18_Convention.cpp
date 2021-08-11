/*
ID: blueacorntech
TASK: convention
LANG: C++
*/
/*/*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <iterator>
#include <set>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <list>
#include <deque>
#include <tuple>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define F first
#define S second
#define PB push_back
#define MP make_pair

vi arrivals;
int M, N, C;

bool check(int max, int M, int C){
	int start = 0;
	int firstArrival = arrivals[0];
	int bus = 1;
	for (int i=0; i<N; i++){
		if (arrivals[i]-firstArrival > max || i+1-start > C){
			bus++;
			firstArrival = arrivals[i];
			start = i;
		}
	}
	return (bus <= M);
}

int binSearch(int high, int low, int M, int C){
	int mid;
	if (high == low){
		return low;
	}
	if (high == low+1){
		if(check(low, M, C)) return low;
		return high;
	}
	mid = (low+high)/2;
	if (check(mid, M, C)) return binSearch(mid, low, M, C);
	else return (binSearch(high, mid+1, M, C));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    ofstream fout ("convention.out");
    ifstream fin ("convention.in");
    int A;
    fin >> N >> M >> C;
    for (int i=0; i<N; i++){
    	fin >> A;
    	arrivals.push_back(A);
    }
    sort(arrivals.begin(), arrivals.end());
    int value = binSearch(arrivals[N-1]-arrivals[0], 0, M, C);
    fout << value << "\n";
    return 0;
}


