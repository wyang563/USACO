/*
ID: blueacorntech
TASK: transform
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(int n, string sqStart[][11], string sqEnd[][11]){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (sqStart[i][j] != sqEnd[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

void reset(int n, string target[][11], string sq[][11]){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			sq[i][j] = target[i][j];
		}
	}
}

void rotation(int num, int n, string sq[][11]){
	string fixed[n][n];
	while (num > 0){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				fixed[i][j] = sq[i][j];
			}
		}
		for (int k=0; k<n; k++){
			for (int m=0; m<n; m++){
				sq[k][m] = fixed[n-1-m][k];
			}
		}
		num--;
	}
}

void reflection(int n, string sq[][11]){
	string fixed[n][n];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			fixed[i][j] = sq[i][j];
		}
	}
	for (int k=0; k<n; k++){
		for (int m=0; m<n; m++){
			sq[k][m] = fixed[k][n-1-m];
		}
	}
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n, transform, running;
    running = 1;
    transform = 7;
    fin >> n;
    string start[11], end[11], sqStart[11][11], sqEnd[11][11], fixed[11][11];
    for (int i=0; i<n; i++){
    	fin >> start[i];
    }
    for (int j=0; j<n; j++){
    	fin >> end[j];
    }
    for (int k=0; k<n; k++){
    	for (int m=0; m<n; m++){
    		sqStart[k][m] = (start[k])[m];
    		sqEnd[k][m] = (end[k])[m];
    	}
    }
    for (int o=0; o<n; o++){
    	for (int p=0; p<n; p++){
    		fixed[o][p] = sqStart[o][p];
    	}
    }
    for (int q=1; q<4; q++){
    	rotation(q, n, sqStart);
    	if (check(n, sqStart, sqEnd) == 1){
    		transform = q;
    		running = 0;
    		break;
    	}
    	reset(n, fixed, sqStart);
    }
    if (running == 1){
		for (int r=0; r<4; r++){
			reflection(n, sqStart);
			rotation(r, n, sqStart);
			if (check(n, sqStart, sqEnd) == 1){
				if (r == 0){
					transform = 4;
				}
				else{
					transform = 5;
				}
				running = 0;
				break;
			}
			reset(n, fixed, sqStart);
		}
    }
    reset(n, fixed, sqStart);
    if (running == 1){
		if (check(n, sqStart, sqEnd) == 1){
			transform = 6;
		}
    }
    fout << transform << endl;
    return 0;
}
