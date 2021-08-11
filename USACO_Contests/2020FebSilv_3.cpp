#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <iterator>
#include <set>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <list>
#include <deque>
#include <tuple>

using namespace std;

map<int, vector<int>*> connMap;
int roomClock[2500];
int origRoomClock[2500];
bool roomDone[2500];
int N;

void edge(int room1, int room2) {
    vector<int>* v = connMap[room1];
    v->push_back(room2);
}

void traverseRoom(int room, int fromRoom) {
    roomClock[room]++;
    if(roomClock[room] > 12) {
        roomClock[room] -= 12;
    }

    bool allEdgesDone = true;
    vector<int>* edges = connMap[room];
    while(true) {
        allEdgesDone = true;
        for (int i = 0; i < edges->size(); i++) {
            if (edges->at(i) == fromRoom || roomDone[edges->at(i)]) {
                continue;
            } else {
                allEdgesDone = false;
                traverseRoom(edges->at(i), room);
                roomClock[room]++;
            }
        }
        if(allEdgesDone) {
            break;
        }
    }
    if(roomClock[room] == 12) {
        roomDone[room] = true;
    }
}

bool testRoom(int room) {
    int edgesDone = 0;
    while(true) {
        vector<int>* edges = connMap[room];
        for(int i=0; i<edges->size(); i++) {
            if(roomDone[edges->at(i)]) {
                edgesDone++;
            }
            else {
                traverseRoom(edges->at(i), room);
                if(roomDone[edges->at(i)]) {
                    edgesDone++;
                }
                if(edgesDone == edges->size()) {
                    break;
                }
                else {
                    roomClock[room] = (roomClock[room] + 1);
                    if(roomClock[room] > 12) {
                        roomClock[room] -= 12;
                    }
                }
            }
        }
        if(edgesDone) {
            break;
        }
    }
    return roomClock[room] == 11 || roomClock[room] == 12;
}

void reset() {
    for(int i=0; i<N; i++) {
        roomClock[i] = origRoomClock[i];
        roomDone[i] = false;
    }
}

int main() {
    ifstream fin ("clocktree.in");
    ofstream fout ("clocktree.out");

    fin >> N;

    for(int i=0; i<N; i++) {
        fin >> roomClock[i];
        origRoomClock[i] = roomClock[i];
        roomDone[i] = false;
        vector<int>* v = new vector<int>();
        connMap.insert(make_pair(i, v));
    }

    int room1, room2;
    for(int i=0; i<N-1; i++) {
        fin >> room1 >> room2;
        edge(room1-1, room2-1);
        edge(room2-1, room1-1);
    }

    int count = 0;
    for(int i=0; i<N; i++) {
        if(testRoom(i)) {
            count++;
        }
        reset();
    }
    fout << count << endl;
    return 0;
}