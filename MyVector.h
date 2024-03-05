#include<new>
#include "MyAllocator.h"
#ifndef MYVECTOR_H
#define MYVECTOR_H

namespace MySTL {
// 	template<class T>
// 	class allocator {
// 		using value_type = T;
// 		using reference = T&;
// 		using pointer = T*;
// 		using iterator = T*;
// 		using const_reference = const T&;
// 		using const_pointer = const T*;
// 
// 		inline pointer allocate(size_t n) {
// 			return ::operator new T;
// 		}
// 	};


	template<class T, class Alloc = allocator<T>>
	class MyVector {
	public:
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using iterator = T*;
		using const_reference = const T&;
		using const_pointer = const T*;

	private:
		iterator _first;
		iterator _last;	//The memory used for now
		iterator end_of_storage;	//The end of the memory which can be used.
	public:
		inline iterator begin() { return _first; }
		inline iterator end() { return _last; }
		reference operator[](size_t n) { return *(_first + n); }

		MyVector() : _first(nullptr), _last(nullptr), end_of_storage(0) {};
		explicit MyVector(size_t n): _last(nullptr) {
			_first = Alloc::allocate(n);
			end_of_storage = Alloc::fill_init(_first, n);
		}
		MyVector(T[] T_array) {
			_first = Alloc::allocate(T_array.size())
			iterator p = _first;
			for (T e : T_array) {
				*(p++) = e;
			}
			_last = --p;
			end_of_storage = _last;
		}

		~MyVector()
		{
			Alloc::destroy(_first, end_of_storage);
		}

		void push(T elem) {

		}
	};
}


#endif