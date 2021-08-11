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

int main() {
    ofstream fout ("swap.out");
    ifstream fin ("swap.in");
    vector<int> order;
    int position;
    int N, K;
    int A1, A2, B1, B2;
    int A, B;
    cin >> N >> K;
    cin >> A1 >> A2;
    cin >> B1 >> B2;
    double a, b;
    a = (A1+0.0+A2+0.0)/2;
    b = (B1+0.0+B2+0.0)/2;
    for (int k=1; k<=N; k++){
        order.push_back(k);
    }
    for (int i=1; i<=N; i++){
        position = i;
        if (i < A1 && i < B1){
            position = i-1;
            order[position] = i;
            continue;
        }
        else if (i > A2 && i > B2){
            position = i-1;
            order[position] = i;
            continue;
        }
        else if (i > A2 && i < B1){
            position = i-1;
            order[position] = i;
            continue;
        }
        else{
            for (int m=0; m<n; m++){
                if (position >= A1 && position<= A2){
                    position = (a-position)*2+position;
                }
                if (position >= B1 && position<= B2){
                    position = (b-position)*2+position;
                }
            }
            position--;
            order[position] = i;
        }
    }
    for (int j=0; j<N; j++){
        cout << order[j] << endl;
    }
    return 0;
}