//
//  Demo for itertools exercise.
//
//  Version 1 by Adam Lev-Ari on 02/2020. Copyright © 2020 Adam Lev-Ari. All rights reserved.
//  Version 2 by Erel Segal-Halevi on 06/2020.
//

#include <iostream>
#include <vector>

#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"


using namespace itertools;
using namespace std;


struct lessThan3 {
    bool operator()(int i) const { return i < 3; }
};

int main(int argc, const char * argv[]) {

    vector<int> vecInt = {0,3,4,2,6,1};
    vector<string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};

    cout << "####  range:  ####";

	for (int i: range(5,9))
		cout << i << " ";      // 5 6 7 8
    

    cout << "####  accumulate:  ####";

    cout << endl << "accumulate of range: " << endl;
	for (int i: accumulate<vector<int> >(vecInt))
		cout << i << " ";      // 1 3 6 10

    cout << endl << "accumulate of vector<string>: " << endl;
    for (auto i: accumulate(vecString) )
        cout << i << " ";  // Hello HelloBye HelloByeAdam
    cout << endl << endl;

    cout << endl << "accumulate of range with binary operator: " << endl;
	for (int i: accumulate(range(5,9), [](int x, int y){return x*y;}))
		cout << i << " ";      // 5 30 210 1680


    cout << "####  Filter False:  ####";

    cout << endl << "Filter out all numbers less than 3 in vector{1,2,3,4}: " << endl;
    for (auto i: filterfalse<struct lessThan3, vector<int> >(lessThan3{}, vecInt) )
        cout << i << " ";   // 3 4
    
    cout << endl << "Filter out all even numbers in range(5,9): " << endl;
    for (auto i: filterfalse([](int i){return i%2==0;}, range(5,9)) )
        cout << i << " ";   // 5 7
    cout << endl << endl;


    cout << "####  compress:  ####";

    cout << endl << "compress a string" << endl;
    for (auto i: compress<string>(string("abcd"), vector<bool>({true,true,false,true})) )
        cout << i << " ";  // a b d

    cout << endl << "compress a range" << endl;
    for (auto i: compress<itertools::range>(range(5,9), vector<bool>({true,true,false,true})) )
        cout << i << " ";  // 5 6 8
    cout << endl << endl;

    cout << endl;
    return 0;
}
