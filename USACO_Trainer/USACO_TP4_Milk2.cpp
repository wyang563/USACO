/*
ID: blueacorntech
TASK: milk2
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n, start, end, stop;
    fin >> n;
    pair <int, int> times[n];
    for (int i=0; i<n; i++){
    	fin >> start >> end;
    	times[i] = make_pair(start, end);
    }
    sort(times, times+n);
    int currstart = 1;
    int minstart = 0;
    int maxMilk = times[0].second - times[0].first;
    int maxstop = 0;
    int endMilk = times[minstart].second;
    while (currstart < n){
    	if (times[currstart].first <= endMilk){
    		endMilk = max(times[currstart].second, endMilk);
    	}
    	else{
    		stop = times[currstart].first - endMilk;
    		if (stop > maxstop){
    			maxstop = stop;
    		}
    		if (endMilk - times[minstart].first > maxMilk){
    			maxMilk = endMilk - times[minstart].first;
    		}
    		minstart = currstart;
    		endMilk = times[minstart].second;
    		}
    	currstart++;
    	}
    fout << maxMilk << " " << maxstop << endl;
    return 0;
}
