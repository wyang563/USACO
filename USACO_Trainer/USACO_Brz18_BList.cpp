/*
ID: blueacorntech
TASK: blist
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
    ofstream fout ("blist.out");
    ifstream fin ("blist.in");
    int n, a, b, c, start, count;
    vi needs;
    vector<vector<int> > times;
    vi temp;
    fin >> n;
    for (int i=0; i<n; i++){
    	fin >> a >> b >> c;
    	temp.push_back(a);
    	temp.push_back(b);
    	temp.push_back(c);
    	times.push_back(temp);
    	temp.clear();
    }
    sort(times.begin(), times.end());
    for (int j=1; j<n; j++){
    	count = times[j][2];
    	start = times[j][0];
    	for (int k=0; k<j; k++){
    		if (times[k][1] > start){
    			count += times[k][2];
    		}
    	}
    	needs.push_back(count);
    }
    sort(needs.begin(), needs.end());
    fout << needs[n-2] << endl;
    return 0;
}
