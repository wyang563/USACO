/*
ID: blueacorntech
TASK: backforth
LANG: C++
*/
/*/*/

// There are some problems with erasing and reinsterting things in the secondbarn vector make sure you reset it every time it needs to be
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
    ofstream fout ("backforth.out");
    ifstream fin ("backforth.in");
    vi firstbarn, s1firstbarn, s2firstbarn, s3firstbarn;
    vi secondbarn, s1secondbarn, s2secondbarn, s3secondbarn;
    set<int> tankone;
    int x, tues, wed, thurs, fri;
    for (int i=0; i<10; i++){
    	fin >> x;
    	firstbarn.push_back(x);
    }
    for (int j=0; j<10; j++){
    	fin >> x;
    	secondbarn.push_back(x);
    }

    for (int a=0; a<10; a++){
    	s1firstbarn = firstbarn;
    	s1secondbarn = secondbarn;
    	tues = firstbarn[a];
    	s1firstbarn.erase(s1firstbarn.begin()+a);
    	s1secondbarn.push_back(tues);
    	for (int b=0; b<11; b++){
    		wed = s1secondbarn[b];
    		s2secondbarn = s1secondbarn;
    		s2firstbarn = s1firstbarn;
    		s2secondbarn.erase(s2secondbarn.begin()+b);
    		s2firstbarn.push_back(wed);
    		for (int c=0; c<10; c++){
    			thurs = s2firstbarn[c];
    			s3secondbarn = s2secondbarn;
    			s3firstbarn = s2firstbarn;
    			s3firstbarn.erase(s3firstbarn.begin()+c);
    			s3secondbarn.push_back(thurs);
    			for (int d=0; d<11; d++){
    				fri = s3secondbarn[d];
    				tankone.insert(1000-tues+wed-thurs+fri);
    			}
    		}
    	}
    }
    int y = tankone.size();
    fout << y << "\n";
    return 0;
}
