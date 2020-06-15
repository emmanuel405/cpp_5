#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename R> class accumulate{
    private:
		int start, finish;

    public:
        accumulate(T mehal){
            cout<<"Cstcr [1] - ACCUMULATE"<<endl;
            R result;
            for(R toSum: mehal){
                result += toSum;
            }
        }
		accumulate(T mehal, [](int x, int y)){
            cout<<"Cstcr [2] - ACCUMULATE"<<endl;
		}
        ~accumulate(){cout<<"Dstcr - ACCUMULATE"<<endl;}
    
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
				index += 1;
				return *this;
			}
			const iterator operator++(int){
				iterator tmp = *this;
				index += 1;
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