/*
ID: blueacorntech
TASK: palsquare
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
	char digit[20] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int b;
    vector <string> nums;
    vector <string> palindromes;
    fin >> b;
    for (int i=1; i<301; i++){
    	if (check(convert(i*i, b))){
    		nums.push_back(convert(i, b));
    		palindromes.push_back(convert(i*i, b));
    	}
    }
    for (int j=0; j<palindromes.size(); j++){
    	fout << nums[j] << " " << palindromes[j] << endl;
    }
    return 0;
}
