#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace itertools{

	template<typename T, typename R> class filterfalse{
		private:
			T t;
			R r;
			
		public:
			filterfalse(T t1, R r1): t(t1), r(r1){cout<<"Cnstcr - FILTERFALSE"<<endl;}
			// ~filterfalse(){cout<<"Dstcr - FILTERFALSE"<<endl;}
		
		class iterator{   
			private:
				int index;

			public:
				iterator(int i): index(i){}
// 				~iterator(){}

				const int operator*() const {
					return this->index;
				}

				iterator& operator++(){
					index += 1;
					return *this;
				}
				const iterator operator++(int){
					iterator tmp = *this;
					index += 1;
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
