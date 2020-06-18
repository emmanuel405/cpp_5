#pragma once

#include <iostream>
#include <vector>

using namespace std;


namespace itertools{

	typedef struct{
		template<typename E> E operator()(E x, E y) {return x+y;}
	} plus;

	template<typename T, typename O = plus> class accumulate{
		private:
			T mehal;
			O operate;
			// static vector<O> _vector;

		public:
			accumulate(T m, O o = plus()): mehal(m), operate(o){
				cout << "Cstcr - ACCUMULATE" << endl;
				//
				// O result;
				// for(O val: mehal){
				// 	result = o(result, val);
				// 	_vec.push_back(result);
				// }
			}
			~accumulate(){cout << "Dstcr - ACCUMULATE" << endl;}
		
		class iterator{
			private:
				int index;

			public:
				iterator(int i): index(i){}
				~iterator(){}

				const auto operator*() const {
					return this->index;
				}

				iterator& operator++(){
					// index += 1;
					return *this;
				}
				const iterator operator++(int){
					iterator tmp = *this;
					// index += 1;
					return tmp;
				}

				bool operator!=(const iterator& equal) const{
					return this->index != equal.index;
				}
		};

		iterator begin(){
			return iterator {0};
		}
		iterator end(){
			return iterator {5};
		}


	};
}
