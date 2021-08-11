

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

int main() {
    ofstream fout ("socdist.out");
    ifstream fin ("socdist.in");
    int N, M;
    ll a, b, avg, sum = 0;
    fin >> N >> M;
    vector<pair<ll, ll>> intvs;
    vector<ll> diffs;
    for (int i=0; i<M; i++){
        fin >> a >> b;
        intvs.PB(make_pair(a, b));
        sum += b-a+1;
    }
    avg = sum/N+1;
    sort(intvs.begin(), intvs.end());  //may remove later

    fout << avg << endl;
    return 0;
}