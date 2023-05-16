#include "Business.h"
template<typename T>
Business<T>::~Business()
{
	/// std::cout << "\n\nBUSINESS class Destroyed!!!\n\n";
}

template<typename T>
void Business<T>::add_part(const T& ob)
{
	this->parts.push_back(ob);
}

template<typename T>
Business<T>& Business<T>::operator=(const Business<T>& b)
{
	this->parts = b.parts;
	return *this;
}

template<typename T>
Business<T>::Business(const std::vector<T>& vp) : parts(vp)
{}

template<typename T>
Business<T>::Business(const Business<T>& vp)
{
	*this = vp;
}
