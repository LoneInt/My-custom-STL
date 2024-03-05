### I. Allocator

​	Allocator allocates memory for your container. In this procedure, the allocation of memory and initialization are two separate operation. Inside allocator, the allocation of memory is finished by calling the function "operator new(...)", and there is a function named "construct(...)" which is used for initializing memory.

### II. Sequential Containers

	#### Vector

Vector is like a dynamic array. It allows you to put elements in it regardless of bound within maximum size(pre-defined). To implement a custom vector container, you need to define some methods in your vector class. 

- **iterator begin()**: This method returns the pointer which points at your first element.

- **iterator end()**: Omitted

- **size_t size()**: Omitted.

- **reference operator[](size_t index)**: This is crucial cause it provide an access to elements by index.

- operation on your elements: add, remove, insert, e.t.c. Remember that all the operation needs to coordinate with the data structure used in your container.

  