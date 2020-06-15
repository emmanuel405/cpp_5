#include <iostream>
#include <vector>

#include "range.hpp"
#include "accumulate.hpp"



// using namespace itertools;
using namespace std;

int main() {
    
    // vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(2);
    // cout<<vec.size()<<endl;
    // cout<<vec.capacity()<<endl;


    // cout << "####  range:  ####";
	// for (int i: range(5,9))
	// 	cout << i << " "<<endl;      // 5 6 7 8
    vector<int> vecInt = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};

    cout << "####  accumulate:  ####";
    cout << endl << "accumulate of range: " << endl;
	for (int i: accumulate(range(5,9)))
		cout << i << " ";      // 5 11 18 26

    cout << endl << "accumulate of vector<string>: " << endl;
    for (auto i: accumulate(vecString) )
        cout << i << " ";  // Hello HelloBye HelloByeAdam
    cout << endl << endl;

    // cout << endl << "accumulate of range with binary operator: " << endl;
	// for (int i: accumulate(range(5,9), [](int x, int y){return x*y;}))
	// 	cout << i << " ";      // 5 30 210 1680

    return 0;
}