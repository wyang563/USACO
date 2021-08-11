/*
ID: blueacorntech
TASK: beads
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// point => the break point is between point - 1, point on the necklace
int counter(int length, int point, int direction, string necklace, string letter){
	int counterPoint = 0;
	string fragment;
	if (letter == "w"){
		int counterA, counterB;
		counterA = counter(length, point, direction, necklace, "r");
		counterB = counter(length, point, direction, necklace, "b");
		if (counterA > counterB){
			return counterA;
		}
		else{
			return counterB;
		}
	}
	else{
		do{
			counterPoint += direction;
			if ((counterPoint+point) < 0){
				fragment = necklace[(counterPoint+point)%length+length];
			}
			else{
				fragment = necklace[(counterPoint+point)%length];
			}
			if (abs(counterPoint) == length-1){
				return length;
			}
		}while(fragment == letter || fragment == "w");
	}
	return abs(counterPoint);
}

int countBreakPoint(int length, int point, string necklace){
	string minusPosition, plusPosition;
	if ((point-1)%length < 0){
		minusPosition[length-1];
		return counter(length, point, 1, necklace, plusPosition) + counter(length, length-1, -1, necklace, minusPosition);
	}
	else{
		minusPosition = necklace[(point-1)%length];
	}
	plusPosition = necklace[point];
	return counter(length, point, 1, necklace, plusPosition) + counter(length, point-1, -1, necklace, minusPosition);
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int length;
    string necklace;
    fin >> length;
    fin >> necklace;
    int max = 0;
    for (int i=0; i<length; i++){
    	int j = countBreakPoint(length, i, necklace);
    	if (j > max){
    		max = j;
    	}
    }
    if (max > length){
    	max = length;
    }
    fout << max << endl;
    return 0;
}
