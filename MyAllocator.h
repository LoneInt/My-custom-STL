#pragma once
#include<new>

#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H

namespace MySTL {
	template<class T>
	//operator new(): Only allocate memory but do not initilize it	(No constructor is called.)
	inline T* _allocate(ptrdiff_t size, T*) {
		set_new_handler(0); //If memory cannot be allocated, the function called will be removed
		T* temp = (T*)(::operator new((size_t)(size * sizeof(T))));	//Call the function "new" to allocate memory for "T"
		if (temp == nullptr) {
			std::cerr << "Out of memory" << std::endl;
			exit(-1);
		}
		return temp;
	}

	template<class T>
	inline void _deallocate(T* buffer) {
		::operator delete(buffer);
	}

	template<class T1, class T2>
	inline void _construct(T1* p, const T2& val) {
		new(p) T1(val);	//Create an object located at p by calling the constructor T1. 
	}

	template<class T>
	inline void _destroy(T* p) {
		p->~T();	//Destroy the object.
	}

	template<class T>
	class allocator {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef const T* const_pointer;
		typedef const T& const_reference;
		//Rebind allocator to type U.
		template<class U>
		struct rebind {
			typedef allocator<U> other;
		};

		pointer allocate(size_t n, const void* hint = 0) {
			return _allocate((ptrdiff_t)n, (pointer) hint);
		}

		void deallocate(pointer p, size_t n) { _deallocate(p); }
	
		void construct(pointer p, const T& value) { _construct(p, value); }

		void destroy(pointer p) {
			_destroy(p);
		}

		pointer address(reference x) {
			return (pointer)&x;
		}

		const_pointer const_address(const_reference x) {
			return (const_pointer)&x;
		}

		size_t max_size() {
			return size_t(UINT_MAX / sizeof(T));
		}
	};
}	//End of namespace MySTL


#endif

