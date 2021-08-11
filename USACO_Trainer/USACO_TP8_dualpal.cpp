/*
ID: blueacorntech
TASK: dualpal
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string convert(int N, int b){
	char digit[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	string num = "";
	while (N >= b){
		int remainder = N%b;
		num = digit[remainder] + num;
		N = N/b;
	}
	num = digit[N] + num;
	return num;
}

bool check(string n){
	int len = n.length();
	for (int i=0; i<len/2; i++){
		if (n[i] != n[len-1-i]){
			return false;
		}
	}
	return true;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n, s, counter, mcount, index;
    counter = 0;
    mcount = 0;
    index = 1;
    vector<int> nums;
    fin >> n >> s;
    while (counter < n){
    	for (int i=2; i<11; i++){
    		if (check(convert(s+index, i))){
    			mcount++;
    		}
    	}
    	if (mcount >= 2){
    		nums.push_back(s+index);
    		counter++;
    	}
		mcount = 0;
    	index++;
    }
    for (int j=0; j<nums.size(); j++){
    	fout << nums[j] << endl;
    }
    return 0;
}
