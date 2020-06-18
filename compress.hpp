#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace itertools{

	template<typename T> class compress{
		private:
			T temp;

		public:
			compress(T t, vector<bool> vb): temp(t){cout<<"Cnstcr - COMPRESS"<<endl;}
			// ~compress(){cout<<"Dstcr - COMPRESS"<<endl;}
		
		class iterator{
			private:
				int index;

			public:
				iterator(int i): index(i){}
// 				~/iterator(){}

				const int operator*() const {
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
					return index != equal.index;
				}
		};

		iterator begin(){
			return iterator{0};
		}
		iterator end(){
			return iterator{5};
		}

	};
}
