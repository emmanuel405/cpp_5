#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename R> class accumulate{
    private:
        static vector<T> _va;
    public:
        accumulate(T){
            cout<<"Cstcr - ACCUMULATE"<<endl;
            R result;
            for(R toSum: T){
                result += toSum;
            }
        }
        ~accumulate(T){cout<<"Dstcr - ACCUMULATE"<<endl;}
    
    class iterator{
		private:
		    R* r_pointer;

		public:
			iterator(R* init = nullptr): r_pointer(init) {}
			~iterator(){}

			int& operator*() const {
				return *r_pointer;
			}

			// iterator& operator++(){
			// 	r_pointer = &(accumulate::_va[+1]);
			// 	return *this;
			// }
			// const iterator operator++(int){
			// 	iterator tmp = *this;
			// 	r_pointer = &(accumulate::_va[+1]);
			// 	return tmp;
			// }
			
			bool operator==(const iterator& equal) const{
				return *r_pointer == *(equal.r_pointer);
			}
			bool operator!=(const iterator& equal) const{
				return *r_pointer != *(equal.r_pointer);
			}
	};

	iterator begin(){
		return iterator{_va[0]};
	}
	iterator end(){
		return iterator{_va[_va.size()]};
	}


};