#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace itertools{

	template<typename T, typename R> class filterfalse{
		private:
			int start, finish;
			
		public:
			filterfalse(T, R){cout<<"Cnstcr - FILTERFALSE"<<endl;}
			~filterfalse(){cout<<"Dstcr - FILTERFALSE"<<endl;}
		
		class iterator{   
			private:
				int index;

			public:
				iterator(int i): index(i){}
				~iterator(){}

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
				
				bool operator==(const iterator& equal) const{
					return index == equal.index;
				}
				bool operator!=(const iterator& equal) const{
					return index != equal.index;
				}
		};

		iterator begin(){
			return iterator{start};
		}
		iterator end(){
			return iterator{finish};
		}

	};
}