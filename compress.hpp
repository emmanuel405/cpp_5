#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace itertools{

	template<typename C> class compress{
		private:
			C _container;
			vector<bool> _vb;

		public:
			compress(C c, vector<bool> vb): _container(c), _vb(vb){cout<<"Cnstcr - COMPRESS"<<endl;}
			~compress(){cout<<"Dstcr - COMPRESS"<<endl;}
		
		class iterator{
			private:
				typename C::iterator _current;
				typename C::iterator _fin;
				vector<bool> _vector;
				int _index = 0;
				const decltype(*(_current)) _organ = *(_current);

			public:
				iterator(typename C::iterator current, typename C::iterator fin,  vector<bool> vector)
				: _current(current), _fin(fin), _vector(vector){}
				~iterator(){}
				iterator(const iterator& other): _current(other._current), _fin(other._fin), _vector(other._vector), _organ(other._organ), _index(other._index){}

				const auto operator*() const {
					return this->_organ;
				}

				iterator& operator++(){
					_current++; _organ = *(_current);
					_index++;
					while ( (_current != _fin) && !_vector[_index]){
						_current++; _organ = *(_current);
						_index++;
					}			
					return *this;
				}
				const iterator operator++(int){
					iterator tmp = *this;
					_current++; _organ = *(_current);
					_index++;
					while( (_current != _fin) && !_vector.at(_index)){
						iterator tmp = *this;
						_current++; _organ = *(_current);
						_index++;
					}
					return tmp;
				}

				bool operator!=(const iterator& equal) const{
					return this->_current != equal._current;
				}
		};

		iterator begin(){
			return iterator {_container.begin(), _container.end(), _vb};
		}
		iterator end(){
			return iterator {_container.end(), _container.end(), _vb};
		}

	};
}
