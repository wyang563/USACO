/*
ID: blueacorntech
TASK: barn1
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

int gap(int start, int end, int stall[], int stalls, int coordinates[]){
	int counter = 0;
	int max = 0;
	for (int i=start; i<=end; i++){
		if (stall[i] == 0){
			counter++;
		}
		else{
			if (counter > max){
				max = counter;
				coordinates[0] = i-counter-1;
				coordinates[1] = i;
			}
			counter = 0;
		}
	}
	return max;
}

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int max, stalls, cows, index, stall[200], boards[200][2], covered, most, hole, coordinates[2], counter, c1, c2, boardNum;
    fin >> max >> stalls >> cows;
    for (int j=0; j<200; j++){
    	stall[j] = 0;
    }
    for (int i=0; i<cows; i++){
    	fin >> index;
    	stall[index-1] = 1;
    }
    boards[0][0] = 0;
    boards[0][1] = stalls-1;
    counter = 0;
    for (int x=0; x<stalls; x++){
    	if (stall[x] != 0){
    		break;
    	}
    	boards[0][0] = x+1;
    }
    for (int y=stalls-1; y>=0; y--){
    	if (stall[y] != 0){
    		break;
    	}
    	boards[0][1] = y-1;
    }
    for (int k=1; k<max; k++){
    	most = 0;
    	for (int m=0; m<k; m++){
    		hole = gap(boards[m][0], boards[m][1], stall, stalls, coordinates);
    		if (hole > most){
    			boardNum = m;
    			c1 = coordinates[0];
    			c2 = coordinates[1];
    			most = hole;
    		}
    	}
    	boards[k][1] = boards[boardNum][1];
		boards[boardNum][1] = c1;
		boards[k][0] = c2;
    }
    covered = 0;
    if (max >= cows){
    	for (int n=0; n<cows; n++){
    	    	covered += boards[n][1]-boards[n][0]+1;
    	    }
    }
    else{
		for (int n=0; n<max; n++){
			covered += boards[n][1]-boards[n][0]+1;
		}
    }
    fout << covered << endl;
    return 0;
}
