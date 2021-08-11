/*
ID: blueacorntech
TASK: crypt1
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

using namespace std;

bool check(int number, vector<int> digs){
	int n;
	while (number > 0){
		n = number%10;
		if (binary_search(digs.begin(), digs.end(), n)){
			number = (number-n)/10;
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}


int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int num, topNum, par1, par2, counter;
    vector<int> digs;
    fin >> num;
    int b;
    for (int i=0; i<num; i++){
    	fin >> b;
    	digs.push_back(b);
    }
    sort(digs.begin(), digs.end());
    counter = 0;
    for (int j=0; j<num; j++){
    	for (int k=0; k<num; k++){
    		for (int m=0; m<num; m++){
    			for (int n=0; n<num; n++){
    				// main loop where things happen
    				// Calculate the partial product numbers and see whether or not they are correct
    				for (int x=0; x<num; x++){
    					topNum = digs[j]*100+digs[k]*10+digs[m];
    					par1 = digs[x]*topNum;
    					par2 = digs[n]*topNum;
    					if (par1 < 1000 && par2 < 1000){
    						if (check(par1, digs) && check(par2, digs) && check(par1+par2*10, digs)){
    							counter++;
    						}
    						else{
    							continue;
    						}
    					}
    					else{
    						continue;
    					}
    				}
    			}
    		}
    	}
    }
    fout << counter << endl;
    return 0;
}
