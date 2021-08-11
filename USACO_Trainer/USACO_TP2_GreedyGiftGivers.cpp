
/*
ID: blueacorntech
TASK: gift1
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int findPosition(string names[], string element, int numPeople){
	for (int o=0; o<numPeople; o++){
		if (element == names[o]){
			return o;
			break;
		}
		else{
			continue;
		}
	}
	return 0;
}

int main() {
	int numPeople;
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> numPeople;
    string names[numPeople];
    int balance[numPeople];
    int giftMoney, divide;
    string giver, receiver;
    for (int m=0; m<numPeople; m++){
        	balance[m] = 0;
        }
    for (int i=0; i<numPeople; i++){
    	fin >> names[i];
    }
    int counter = 0;
    while (counter < numPeople){
    	fin >> giver;
    	fin >> giftMoney >> divide;
    	if (divide == 0){
    		counter += 1;
    		continue;
    	}
    	else{
    	balance[findPosition(names, giver, numPeople)] -= giftMoney/divide*divide;
    	for (int j=0; j<divide; j++){
    		fin >> receiver;
    		balance[findPosition(names, receiver, numPeople)] += giftMoney/divide;
    	}
    	counter += 1;
    	}
    }
    for (int n=0; n<numPeople; n++){
        fout << names[n] << " " << balance[n] << endl;
    }

    return 0;
}

















