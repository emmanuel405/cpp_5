#include <iostream>
#include <vector>

#include "range.hpp"


// using namespace itertools;
using namespace std;

int main() {
    
    // vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(2);
    // cout<<vec.size()<<endl;
    // cout<<vec.capacity()<<endl;


    cout << "####  range:  ####";
	for (int i: range(5,9))
		cout << i << " "<<endl;      // 5 6 7 8

    return 0;
}