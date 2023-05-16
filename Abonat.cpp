#include "Abonat.h"

Abonat::Abonat(const int id, const std::string& nume, const std::string& cnp, const std::string& nr_telefon, std::shared_ptr<Abonament> Ab)
	:Persoana(id, nume, cnp), nr_telefon(nr_telefon), x(Ab)
{
}
Abonat::Abonat(const Persoana& Pers, const std::string& nr_telefon, std::shared_ptr<Abonament> Ab)
	:Persoana(Pers), nr_telefon(nr_telefon), x(Ab)
{
}
Abonat::Abonat(const Abonat& At)
{
	*this = At;
}
Abonat::~Abonat()
{
	/// std::cout << "ABONAT Destroyed\n\n\n";
}
//////

void Abonat::Print()
{
	Persoana::Print();
	std::cout << nr_telefon << "\n";
	x->Print();
}

float Abonat::get_sum_abonat()
{
	return (float)(this->x->get_total_sum());
}

const std::type_info& Abonat::get_type_Abonament() const
{
	return typeid(*x); // Returnam "typeid" pt. valoarea POINTERULUI "x" de tip "Abonament"
}

float Abonat::get_pret_Abonament() const
{
	return this->x->get_pret();
}


//// Supraincarcari de operatori:
Abonat& Abonat::operator=(const Abonat& Abt)
{
	this->id = Abt.id;
	this->nume = Abt.nume;
	this->cnp = Abt.cnp;
	this->nr_telefon = Abt.nr_telefon;
	if (typeid(*(Abt.x)) == typeid(Abonament))
		this->x = Abt.x;
	else
		if (std::dynamic_pointer_cast<Abonament_Premium>(Abt.x) != nullptr)
			this->x = std::static_pointer_cast<Abonament_Premium>(Abt.x);
		else
			std::cout << "CANNOT perform CAST!\n";
	return *this;
}

std::istream& operator>>(std::istream& in, Abonat& Abt)
{
	std::cout << "ID-ul abonatului: ";
	in >> Abt.id;
	std::cout << "Numele abonatului: ";
	in >> Abt.nume;
	std::cout << "CNP-ul abonatului: ";
	in >> Abt.cnp;
	std::cout << "Telefon abonat: ";
	in >> Abt.nr_telefon;
	unsigned short choice;
	std::cout << "\n\nDATI INFO DESPRE TIPUL DE ABONAMENT ALES\n";
	std::cout << "APASATI 1 pentru un abonat cu abonament(normal), respectiv 2 pentru un abonat cu abonament(premium): ";
	in >> choice;
	std::cout << "\n";
	if (choice == 1)
	{
		Abt.x = std::make_shared<Abonament>();
		in >> *Abt.x;
		std::cout << "\n\n";
		return in;
	}
	else if (choice == 2)
	{
		Abt.x = std::make_shared<Abonament_Premium>();
		if (std::dynamic_pointer_cast<Abonament_Premium>(Abt.x) != nullptr)
		{
			try
			{
				in >> *std::static_pointer_cast<Abonament_Premium>(Abt.x);
			}
			catch (InvalidDiscount& ex2)
			{
				std::cout << ex2.what();
				exit(-1234);
			}
			catch (...)
			{
				std::cout << "\n\nThe program STOPPED because an INVALID DISCOUNT2 was introduced!\n\n";
				exit(-123456789);
			}
		}	
		std::cout << "CANNOT perform CAST!\n";
		std::cout << "\n\n";
		return in;
	}
	else
	{
		std::cout << "INVALID INPUT\n";
		throw InvalidChoice();
	}
}

std::ostream& operator<<(std::ostream& out, const Abonat& Abt)
{
	out << "Abonatul:\n";
	out << "ID: " << Abt.id << ", Nume: " << Abt.nume << ", CNP: " << Abt.cnp << ", Telefon: " << Abt.nr_telefon;
	std::cout << "\n\nINFORMATII DESPRE TIPUL DE ABONAMENT ALES:\n";
	if (typeid(*(Abt.x)) == typeid(Abonament))
		out << *(Abt.x);
	else
		if (std::dynamic_pointer_cast<Abonament_Premium>(Abt.x) != nullptr)
			out << *std::static_pointer_cast<Abonament_Premium>(Abt.x);
		else
			out << "CANNOT perform CAST!\n";
	return out;
}