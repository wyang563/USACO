/*
ID: blueacorntech
TASK: beads
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  pair <int, int> larry[4];
  for (int i=0; i<4; i++){
	  larry[i] = make_pair(i, 2*i);
  }
  cout << larry[0].first << endl;
  return 0;
} // main
