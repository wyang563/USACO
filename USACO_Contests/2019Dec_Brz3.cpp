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

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool order(string a, string b){
    for (int i=0; i<a.size(); i++){
        char m = a[i];
        char n = b[i];
        if (int(m) < int(n)){
            return true;
        }
        else if (int(m) == int(n)){
            continue;
        }
        return false;
    }
}
int find(string a, vector<string> list){
    for (int i=0; i<list.size(); i++){
        if (a == list[i]){
            return i;
        }
    }
    return -1;
}

bool check(vector<string> constraints, vector<string> list){
    for (int i=0; i<constraints.size(); i+=2){
        if (abs(find(constraints[i], list)-find(constraints[i+1], list)) > 1){
            return false;
        }
    }
    return true;
}

bool checker2(vector<string> constraints, string m, string n){
    for (int i=0; i<constraints.size(); i+=2){
        if (constraints[i] == m && constraints[i+1] == n){
            return true;
        }
        else if (constraints[i] == n && constraints[i+1] == m){
            return true;
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");
    int N, index;
    cin >> N;
    vector<string> constraints;
    vector<string> final;
    vector<string> temp;
    string array[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Buttercup", "Blue", "Sue"};
    string line;
    for (int i=0; i<6*N; i++){
        cin >> line;
        if (i%6 == 0 || i%6 == 5){
            constraints.push_back(line);
        }
    }
    for (int k=0; k<constraints.size(); k++){
        if (k%2 == 0){
            sort(constraints.begin()+k, constraints.begin()+k+2);
        }
    }
    for (int x=0; x<8; x++){
        if (find(array[x], constraints) != -1){
            if ()
        }
        for (int a=0; a<=final.size(); a++){
            if (a == final.size()){ //error here
                final.push_back(array[x]);
                break;
            }
            temp = final;
            if (order(array[x], final[a])){
                temp.insert(temp.begin()+a, array[x]);
                if (check(constraints, temp)){
                    final.insert(final.begin()+a, array[x]);
                    break;
                }
            }
        }
    }
    for (int z=0; z<8; z++){
        if (find(array[z], final) == -1){
            for (int a=0; a<=final.size(); a++){
                if (a == final.size()){ //error here
                    final.push_back(array[z]);
                    break;
                }
                temp = final;
                if (order(array[z], final[a])){
                    temp.insert(temp.begin()+a, array[z]);
                    if (check(constraints, temp)){
                        final.insert(final.begin()+a, array[z]);
                        break;
                    }
                }
            }
        }
    }
    for (int m=0; m<8; m++){
        cout << final[m] << endl;
    }



    return 0;
}


