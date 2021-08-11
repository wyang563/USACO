/*
ID: blueacorntech
TASK: skidesign
LANG: C++

Tomorrow's idea, bash every case where n is the median, move every number within range of n, and then choose the cheapest n
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


int cost(vector<int> heights, int num, int low){
	int money = 0;
	for (int i=0; i<num; i++){
		if (heights[i] < low){
			money += (low-heights[i])*(low-heights[i]);
		}
		else if (heights[i] > low+17){
			money += (heights[i]-low-17)*(heights[i]-low-17);
		}
		else{
			continue;
		}
	}
	return money;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int num, van;
    fin >> num;
    vi values;
    vi heights;
    for (int i=0; i<num; i++){
    	fin >> van;
    	heights.push_back(van);
    }
    sort(heights.begin(), heights.end());
    for (int j=0; j<=heights[num-1]; j++){
    	values.push_back(cost(heights, num, j));
    }
    sort(values.begin(), values.end());
    fout << values[0] << endl;
    return 0;
}



