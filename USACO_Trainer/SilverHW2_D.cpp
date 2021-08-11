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

using namespace std;

int main() {
	int n, start, end;
	map<int, vector<int> > travel;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> start >> end;
		travel.insert(pair<int, vector<int> >(start, vector<int>()));
		travel[start].push_back(end);
	}

	return 0;
}
