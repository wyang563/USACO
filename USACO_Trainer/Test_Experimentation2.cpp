

#include <iostream>
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
				cout << coordinates[0] << " " << coordinates[1] << endl;
			}
			counter = 0;
		}
	}
	return max;
}

int main(){
	int max, stalls, cows, index, stall[200], boards[200][2], covered, most, hole, coordinates[2];
	cin >> max >> stalls >> cows;
	for (int j=0; j<200; j++){
		stall[j] = 0;
	}
	for (int i=0; i<cows; i++){
		cin >> index;
		stall[index-1] = 1;
	}
	cout << gap(boards[0][0], boards[0][1], stall, stalls, coordinates) << endl;
	return 0;
}
