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
int taken(vector<ii> favs, int from){
    int take[100000] = {0};
    int counter = 0;
    for (int i=from; i<favs.size(); i++){
        int a = favs[i].F;
        int b = favs[i].S;
        if (take[a] == 0){
            take[a] = 1;
            counter++;
        }
        else if (take[b] == 0){
            take[b] = 1;
            counter++;
        }
    }
    return counter;
}
int main() {
    ofstream fout ("cereal.out");
    ifstream fin ("cereal.in");
    set<int> vals;
    vector<ii> favs;
    int c[100000] = {0};
    int M, N, a , b;
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> a >> b;
        c[a]++;
        c[b]++;
        vals.insert(a);
        vals.insert(b);
        favs.PB(make_pair(a,b));
    }
    for (int i=0; i<N; i++){
        cout << taken(favs, i) << endl;
    }
    return 0;
}