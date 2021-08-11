
/*
ID: blueacorntech
TASK: friday
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int typeYear(int year){
	if (year%4 == 0 && year%100 != 0){
		return 1;
	}
	if (year%100 == 0){
		if ((year/100)%4 == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    int startDay = 2;
    int freq[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    fin >> n;
    for (int i=1900; i<1900+n; i++){
    	for (int j=0; j<12; j++){
    		freq[(startDay+12)%7] += 1;
    		if (j==1){
    			startDay += (typeYear(i)+monthDays[j])%7;
    		}
    		else{
    			startDay += monthDays[j]%7;
    		}
    	}
    }
    for (int n=0; n<7; n++){
    	if (n==6){
    		fout << freq[n] << endl;
    	}
    	else{
		fout << freq[n] << " ";
	}
    }
    return 0;
}
