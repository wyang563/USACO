/*
ID: blueacorntech
TASK: mixmilk
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

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    ofstream fout ("mixmilk.out");
    ifstream fin ("mixmilk.in");
    int buckets[3], capacity[3], turn, next;
    for (int i=0; i<3; i++){
    	fin >> capacity[i] >> buckets[i];
    }
    for (int j=0; j<100; j++){
    	turn = j%3;
    	next = (turn+1)%3;
    	buckets[next] += buckets[turn];
    	buckets[turn] = 0;
    	if (buckets[next] > capacity[next]){
    		buckets[turn] = buckets[next] - capacity[next];
    		buckets[next] = capacity[next];
    	}
    }
    for (int k=0; k<3; k++){
    	fout << buckets[k] << "\n";
    }
    return 0;
}
