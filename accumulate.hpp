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
			T _mehal;
			O _operate;

		public:
			accumulate(T m, O o = plus()): _mehal(m), _operate(o){
				cout << "Cstcr - ACCUMULATE" << endl;
			}
			~accumulate(){cout << "Dstcr - ACCUMULATE" << endl;}
		
		class iterator{
			private:
				typename T::iterator _current;
				typename T::iterator _fin;
				O _operat;
				decltype(*(_current)) _sum = *(_current);

			public:
				iterator(typename T::iterator start, typename T::iterator end, O& op)
				:_current(start), _fin(end), _operat(op){}
				~iterator(){}
				// copy cstr
				iterator(const iterator& other):_current(other._current),_fin(other._fin),_operat(other._operat),_sum((other._sum)){}

				const auto operator*() const {
					return this->_sum;
				}

				iterator& operator++(){
					if(this->_current != this->_fin) {
						_current++;
						this->_sum = _operat(this->_sum, *(_current));
						return *this;
					}
				}
				const iterator operator++(int){
						iterator tmp = *this;
						_current++;
					if(_current != _fin){
						this->_sum = _operat(this->_sum, *(_current));
						return tmp;
					}
				}

				bool operator!=(const iterator& equal) const{
					return this->_current != equal._current;
				}
		};

		iterator begin(){
			return iterator {_mehal.begin(), _mehal.end(), _operate};
		}
		iterator end(){
			return iterator {_mehal.end(), _mehal.end(), _operate};
		}

	};
}
