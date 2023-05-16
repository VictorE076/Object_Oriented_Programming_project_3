#pragma once
#include "Firma.h"

template<typename T>
class Business
{
private:
	std::vector<T> parts;
	const std::type_info* components[5] = { &typeid(Abonament), &typeid(Abonament_Premium), &typeid(Abonat), &typeid(Clienti), &typeid(Firma) };
public:
	Business() = default;
	Business(const Business<T>& b);
	Business(const std::vector<T>& vp);
	~Business();
	//
	void add_part(const T& ob);

	// Supraincarcare de operatori:
	Business<T>& operator=(const Business<T>& b);
	friend std::ostream& operator<<(std::ostream& out, const Business<T>& b)
	{
		bool checked_T = false;
		for (int i = 0; i < 5; i++)
		{
			if (typeid(T) == *b.components[i])
			{
				checked_T = true;
				break;
			}
		}
		if (!checked_T)
		{
			out << "\n\nInefficient BUSINESS Work!\n\n";
		}
		else
		{
			int* count = new int;
			*count = 1;
			for (T object : b.parts)
			{
				out << "OBIECTUL cu numarul: " << *count << "\n";
				out << object << "\n\n";
				(*count)++;
			}
			out << std::endl;
			delete count;
		}
		return out;
	}
};

#include "Business.cpp.h"