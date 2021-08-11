
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

bool testValue(long long X, long long N, long long K, long long M){
    long long Y;
    long long G = 0;
    long long days = 0;
    int badcounter = 0;
    int goodcounter = 0;
    while (days <= K) {
        days++;
        Y = (N - G) / X;
        if (M < N/K && Y < N/K){
            goodcounter = 0;
            badcounter++;
            if (badcounter >= 100000){
                return false;
            }
        }
        if (M > N/K && Y > N/K){
            badcounter = 0;
            goodcounter++;
            if (goodcounter >= 100000){
                return true;
            }
        }
        if (Y >= M) {
            G += Y;
        }
        if (Y < M){
            G += M;
        }
        if (G >= N){
            return true;
        }
        if (days == K && G < N){
            return false;
        }
    }
    return true;
}

int main() {
    ofstream fout ("loan.out");
    ifstream fin ("loan.in");
    long long N, K, M, middle;
    long long G = 0;
    long long days = 0;
    long long X = 1;
    fin >> N >> K >> M;
    long long start = 1;
    long long end = N/2;
    bool test = true;
    while (start <= end){
        middle = (start+end)/2;
        test = testValue(middle, N, K, M);
        if (end-start <= 1){
            break;
        }
        if (test){
            start = middle;
        }
        else{
            end = middle;
        }
    }
    if (testValue(start, N, K, M)){
        X = start;
    }
    else{
        X = end;
    }
    fout << X << endl;
    return 0;
}
