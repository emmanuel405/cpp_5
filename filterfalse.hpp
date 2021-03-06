#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace itertools{

	template<typename D, typename C> class filterfalse{
		private:
			D _depend;
			C _container;
			
		public:
			filterfalse(D d, C c): _depend(d), _container(c){cout << "Cnstcr - FILTERFALSE" << endl;}
		
		class iterator{   
			private:
				D _the_depend;
				typename C::iterator _current;
				typename C::iterator _fin;
				decltype(*(_current)) _organ = *(_current); 

			public:
				iterator(D depend, typename C::iterator current, typename C::iterator fin)
				:_the_depend(depend), _current(current), _fin(fin) {}
				iterator(const iterator& other): _the_depend(other._the_depend), _current(other._current), _fin(other._fin), _organ(other._organ){}

				const auto operator*() const {
					return *(_current);
				}

				iterator& operator++(){
					_current++;
					while ( ( _current != _fin ) && ( _the_depend(*(_current)) ) )
						_current++;
					
					return *this;
				}
				const iterator operator++(int){
					iterator tmp = *this;
					_current++;
					while ( ( _current != _fin ) && ( _the_depend(*(_current)) ) ){
						_current++;
					}
					return tmp;
				}

				bool operator!=(const iterator& equal) const{
					return this->_current != equal._current;
				}
		};

		iterator begin(){
			iterator _begin(_depend, _container.begin(), _container.end());
			while( _begin != end() && _depend(*_begin) )
				_begin++;
			return _begin;
		}
		iterator end(){
			return iterator {_depend, _container.end(), _container.end()};
		}

	};
}
