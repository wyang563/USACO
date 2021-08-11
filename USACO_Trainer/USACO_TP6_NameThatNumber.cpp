/*
ID: blueacorntech
TASK: namenum
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

long long convert(string name){
	int n = name.length();
	long long sum = 0;
	for (int i=0; i<n; i++){
		if (int(name[i] > 81)){
			sum += (int(name[i]-60)/3)*pow(10, n-i-1);
		}
		else{
			sum += (int(name[i])-59)/3*pow(10, n-i-1);
		}
	}
	return sum;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    string x;
    long long n, counter;
    pair <string, long long> names[4617];
    string worked[1000];
    worked[0] = "NONE";
    counter = 0;
    fin >> n;
    ifstream inFile;
    inFile.open("dict.txt");
    while (inFile >> x){
    	names[counter].first = x;
    	counter++;
    }
    inFile.close();
    for (int i=0; i<4617; i++){
    	names[i].second = convert(names[i].first);
    }
    counter = 0;
    for (int j=0; j<4617; j++){
    	if (names[j].second == n){
    		worked[counter] = names[j].first;
    		counter++;
    	}
    }
    if (counter == 0){
    	fout << worked[0] << endl;
    }
    else{
		for (int k=0; k<counter; k++){
			fout << worked[k] << endl;
		}
    }
    return 0;
}
