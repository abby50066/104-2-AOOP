#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__

#include "Trace.h"

using std::cout;
static int cnt = 1;

template<class T>class vector {		// general vector type
	T* v;
	int sz;
public:;
	vector()
	{
		v = new T[1];
		sz = 1;
		TRACE(dummy, "vector<T>::vector(int)");
		cout << "  count = " << cnt << endl;
		
		return ;
	}
	vector(int i)
	{
		v = new T[i];
		sz = i;
		TRACE(dummy, "vector<T>::vector(int)");
		cout << "  count = " << cnt << endl;
		
		return ;
	}
	~vector()
	{
		delete [] v;
		TRACE(dummy, "vector<T>::~vector");
		cout << "  count = " << cnt << endl;
		
		return ;
	}

	T& elem(int i) { return v[i]; }
	T& operator[] (int i) { return v[i]; }
};

template<>class vector<void*> {
	void** p;
	int sz;
public:
	vector()
	{
		p = new void*[1];
		sz = 1;
		TRACE(dummy, "vector<void*>::vector(int)");
		cout << "  count = " << cnt << endl;
		cnt++;

		return ;
	}
	vector(int i)
	{
		p = new void*[i];
		sz = i;
		TRACE(dummy, "vector<void*>::vector(int)");
		cout << "  count = " << cnt << endl;
		cnt++;

		return ;
	}
	~vector()
	{
		delete [] p;
		TRACE(dummy, "vector<void*>::~vector");
		cnt--;
		cout << "  count = " << cnt << endl;

		return ;
	}
	void*& elem(int i) { return p[i]; }
	void*& operator[] (int i) { return p[i]; }
};

template<class T>class vector<T*> : private vector<void*> {
public:
	typedef vector<void*> Base;

	vector() : Base()
	{
		TRACE(dummy, "vector<T*>::vector(int)");

		return ;
	}
	explicit vector(int i) : Base(i)
	{
		TRACE(dummy, "vector<T*>::vector(int)");

		return ;
	}
	~vector()
	{
		TRACE(dummy, "vector<T*>::~vector");

		return ;
	}

	T*& elem(int i) { return reinterpret_cast<T*&>(Base::elem(i)); }
	T*& operator[] (int i) { return reinterpret_cast<T*&>(Base::operator[](i)); }
};

#endif
