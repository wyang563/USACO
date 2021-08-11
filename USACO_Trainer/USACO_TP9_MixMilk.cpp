/*
ID: blueacorntech
TASK: milk
LANG: C++
*/
/*/*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    pair <int, int> prices[5000];
    for (int z=0; z<5000; z++){
    	prices[z].first = 1001;
    }
    int amountMilk, num, minPrice, price, quota, counter;
    fin >> amountMilk >> num;
    for (int i=0; i<num; i++){
    	fin >> price >> quota;
    	prices[i] = make_pair(price, quota);
    }
    sort(prices, prices+num);
    counter = 0;
    minPrice = 0;
    quota = prices[0].second;
    price = prices[0].first;
    for (int k=0; k<amountMilk; k++){
    	if (quota == 0){
    		counter++;
    		quota = prices[counter].second;
    		price = prices[counter].first;
    	}
    	minPrice += price;
    	quota--;

    }
    fout << minPrice << endl;
    return 0;
}
