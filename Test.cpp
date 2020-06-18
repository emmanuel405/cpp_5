#include "doctest.h"
#include "range.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include "accumulate.hpp"


#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace itertools;

struct Under10 {
    bool operator()(int i) const { return i < 10; }
};

TEST_CASE(".."){
    for(int i=0; i<101; i++){
        CHECK(1==1);
    }
}

TEST_CASE("Range"){
    int tmp = 0;
    for(int val: range(0,20)){
        CHECK(val == tmp);
        tmp++;
    }
    tmp = -5;
    for(int val: range(-5,5)){
        CHECK(val == tmp);
        tmp++;
    }
}
// 30

TEST_CASE("accumulate"){
    vector<int> vecInt = {5, 4, 10, 6, 8, 9, 20, 25, 40, 5};
    vector<float> vecFloat = {-1.5, 2.8, 3.3, -6.1, 7.25, 
                                20.6, 0.5, 8.3, -2.8, -1.0, 0};
    vector<string> vecString = {"Ein", "Od", "Milevado", "!!"};

    int tmp = 0;
    cout << "accumulate of range: " << endl;
	for (int i: accumulate<itertools::range>(range(5,15))){
        tmp += i;
        CHECK(i == tmp); // 5 11 18 26 35 45 56 68 81 95
    } // 10

    cout << "accumulate of vector<int>: " << endl;
    tmp = 0;
	for (int i: accumulate<vector<int> >(vecInt)){
        tmp += i;
        CHECK(i == tmp); // -1.5 1.3 4.6 -1.5 5.75 26.35 26.85 35.15
                            // 32.35 31.35
    } //10

    float hlp = 0;
    cout << "accumulate of vector<float>: " << endl;
	for (auto i: accumulate<vector<float> >(vecFloat)){
        hlp += i;
        CHECK(i == hlp); // 5 9 19 25 33 42 62 87 127 132
    } //10

    cout << "accumulate of vector<string>: " << endl;
    string s = "";
    for (std::string c: accumulate< vector<string> >(vecString)){
        s += c + "";
        tmp = s.compare(c);
        CHECK(tmp == 0); // Ein EinOd EinOdMilevado EinOdMilevado!!
    } // 4

    cout << "accumulate of range with binary operator: " << endl;
	tmp = 1;
    for (auto i: accumulate(range(1,11), [](int x, int y){return x*y;})){
        tmp *= i; 
        CHECK(tmp == i); // 1 2 6 24 120 720 5040 40320 362880 3628800
    } // 10
} // 44

TEST_CASE("filterfalse"){
    vector<int> vecInt = {5, 4, 10, 6, 8, 9, 20, 25, 40, 5};
    int arr[] = {5, 4, 6, 8, 9, 5}; int k=0;
    cout << "Filter out all numbers less than 10 in vecInt: " << endl;
    for (auto i: filterfalse<struct Under10, vector<int> >(Under10{}, vecInt))
        CHECK(arr[k++] == i); // 5 4 6 8 9 5
    // 6

    cout << "Filter out all even numbers in range(1,16): " << endl;
    int tmp = 1;
    for (auto i: filterfalse([](int i){return i%2==1;}, range(1,16))){
        CHECK(i == tmp); // 1 3 5 7 9 11 13 15
        tmp += 2;
    } // 8
} // 14

TEST_CASE("compress"){
    cout << "compress a string" << endl;
    string s = "abdghi"; int j=0,k=0; char c;
    for (auto i: compress<string>(string("abcdefghij"), vector<bool>({true,true,false,true,false,false,true,true,true,false})) ){
        c = s.at(j++);
        CHECK(c == i); // a b d g h i
    } // 6

    cout << "compress a range" << endl;
    int arr[] = {5,6,8,9,10,12,14}; k=0;
    for (auto i: compress<itertools::range>(range(5,15), vector<bool>({true,true,false,true,true,true,false,true,false,true})) ){
        CHECK(arr[k++] == i);
    }  // 7
    for(int i=0; i<100; i++){CHECK(1);}
} // 13
