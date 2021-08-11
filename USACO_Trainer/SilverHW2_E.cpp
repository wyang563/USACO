
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
	string x, end;
	int size, n;
	vector<string> words;
	vector<string> solutions;
	map<string, string> compounds;
	while (cin >> x){
		words.push_back(x);
	}
	n = words.size();
	for (int i=0; i<n; i++){
		size = words[i].length();
		for (int j=0; j<n; j++){
			if (words[j].substr(0, size) == words[i]){
				end = words[j].substr(size, n+1);
				if (count(words.begin(), words.end(), end)){
					solutions.push_back(words[j]);
				}
			}
		}
	}
	for (int k=0; k<solutions.size(); k++){
		cout << solutions[k] << endl;
	}
	return 0;
}
