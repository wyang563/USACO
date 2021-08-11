
/*
ID: blueacorntech
TASK: ride
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string groupString, cometString, output;
    fin >> groupString;
    fin >> cometString;
    int lenGroup = groupString.size();
    int lenComet = cometString.size();
    int groupProd, cometProd;
    groupProd = 1;
    cometProd = 1;
    for (int i=0; i<lenGroup; i++){
    	groupProd = groupProd*(int(groupString[i])-64);
    }
    for (int j=0; j<lenComet; j++){
    	cometProd = cometProd*(int(cometString[j])-64);
    }
    if (groupProd%47 == cometProd%47){
    	output = "GO";
    }
    else{
    	output = "STAY";
    }
    fout << output << endl;
    return 0;
}
