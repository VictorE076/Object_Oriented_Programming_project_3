#include "Persoana.h"

Persoana::Persoana(const int id, const std::string& nume, const std::string& cnp)
	:id(id), nume(nume), cnp(cnp)
{}
Persoana::Persoana(const Persoana& Pers)
{
	*this = Pers;
}
Persoana::~Persoana()
{
	/// std::cout << "PERSOANA Destroyed\n\n\n";
}
//////
void Persoana::Print()
{
	std::cout << this->id << " " << this->nume << " " << this->cnp << "\n";
}


//// Supraincarcari de operatori:

Persoana& Persoana::operator=(const Persoana& Pers)
{
	this->id = Pers.id;
	this->nume = Pers.nume;
	this->cnp = Pers.cnp;
	return *this;
}

std::istream& operator>>(std::istream& in, Persoana& Pers)
{
	std::cout << "ID-ul persoanei: ";
	in >> Pers.id;
	std::cout << "Numele persoanei: ";
	in >> Pers.nume;
	std::cout << "CNP-ul persoanei: ";
	in >> Pers.cnp;
	std::cout << "\n\n";
	return in;
}

std::ostream& operator<<(std::ostream& out, const Persoana& Pers)
{
	out << "Persoana:\n";
	out << "ID: " << Pers.id << ", Nume: " << Pers.nume << ", CNP: " << Pers.cnp << "\n\n";
	return out;
}