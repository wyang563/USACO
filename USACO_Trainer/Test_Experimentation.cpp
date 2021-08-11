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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    pair<pair<int, int>, int> names[10];
    names[0].first = make_pair(3, 4);
    names[1].first = make_pair(9, 2);
    names[2].first = make_pair(6, 1);
    names[0].second = 1;
    names[1].second = 3;
    names[2].second = 9;
    sort(names, names+3);
    for (int i=0; i<3; i++){
    	cout << names[i].first.first << endl;
    }

    return 0;
}


