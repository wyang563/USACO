/*
ID: blueacorntech
TASK: combo
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

using namespace std;

bool check(int tempCombo[], int combo[], int n){
	for (int i=0; i<3; i++){
		if (abs(tempCombo[i]-combo[i]) < 3 || abs(tempCombo[i]-combo[i]) > n-3){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int n, valid;
    int johnCombo[3], masterCombo[3], tempCombo[3];
    fin >> n;
    fin >> johnCombo[0] >> johnCombo[1] >> johnCombo[2];
    fin >> masterCombo[0] >> masterCombo[1] >> masterCombo[2];
    valid = 0;
    for (int i=1; i<=n; i++){
    	tempCombo[0] = i;
    	for (int j=1; j<=n; j++){
    		tempCombo[1] = j;
    		// Below is where function stuff happens
    		for (int k=1; k<=n; k++){
    			tempCombo[2] = k;
    			if (check(tempCombo, johnCombo, n)){
    				valid++;
    				cout << tempCombo[0] << " " << tempCombo[1] << " " << tempCombo[2] << endl;
    				continue;
    			}
    			else if (check(tempCombo, masterCombo, n)){
					valid++;
					cout << tempCombo[0] << " " << tempCombo[1] << " " << tempCombo[2] << endl;
				}
    		}
    	}
    }
    fout << valid << endl;
    return 0;
}
