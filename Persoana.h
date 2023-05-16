#pragma once
#include "Abonament_Premium.h"


class Persoana
{
protected:
	int id;
	std::string nume;
	std::string cnp;
public:
	Persoana() = default;
	Persoana(const int id, const std::string& nume, const std::string& cnp);
	Persoana(const Persoana& Pers);
	virtual ~Persoana();
	//////
	virtual void Print();

	//// Supraincarcari de operatori:
	Persoana& operator=(const Persoana& Pers);
	friend std::istream& operator>>(std::istream& in, Persoana& Pers);
	friend std::ostream& operator<<(std::ostream& out, const Persoana& Pers);
};