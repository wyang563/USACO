
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
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int,int> ii;

bool connected(vector<ii> adj[]){
    bool checked[100000] = {false};
    int count = 0;
    return false;
}

int main() {
    ofstream fout ("wormsort.out");
    ifstream fin ("wormsort.in");
    int N, M;
    int a, b, w;
    pi val;
    int p[100000];
    vector<pi> adj[100000];
    vector<tuple<int, int, int> edges;
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        cin >> p[i];
    }
    for (int i=0; i<=M; i++){
        cin >> a >> b >> w;
        val = MP(b, w);
        adj[a] = val;
        val = MP(a, w);
        adj[b] = val;
        edges.PB(make_tuple(w, a, b));
        edges.PB(make_tuple(w, b, a));
    }

    return 0;
}