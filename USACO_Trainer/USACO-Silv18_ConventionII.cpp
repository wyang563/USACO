/*
ID: blueacorntech
TASK:
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

int N;
pair<pair<int, int>, int> cows[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    ofstream fout ("convention2.out");
    ifstream fin ("convention2.in");
    int A, B;
    fin >> N;
    for (int i=0; i<N; i++){
    	fin >> A >> B;
    	cows[i].first = make_pair(A, B);
    	cows[i].second = i;
    }
    sort(cows, cows+N);
    fout << << "\n";
    return 0;
}


