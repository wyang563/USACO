
/*
ID: blueacorntech
TASK:
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>
#include <array>


using namespace std;

int main() {
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");
    int N, output;
    bool fail = false;
    string mailbox, sub1, sub2;
    fin >> N;
    fin >> mailbox;
    for (int i=1; i<=N; i++){
        for (int j=0; j<=N-i; j++){
            sub1 = mailbox.substr(j, i);
            for (int k=0; k<=N-i; k++){
                sub2 = mailbox.substr(k, i);
                if (sub1 == sub2 && j != k){
                    fail = true;
                    break;
                }
            }
            if (fail){
                break;
            }
        }
        if (fail){
            fail = false;
            continue;
        }
        output = i;
        break;
    }
    fout << output << endl;
    return 0;
}
