#include "Abonament_Premium.h"

Abonament_Premium::Abonament_Premium(const std::string& nume_abonament, const float pret, const int perioada, const int reducere)
	:Abonament(nume_abonament, pret, perioada), reducere(reducere)
{
	if (this->reducere >= (float)this->pret)
	{
		std::cout << "\n\nThe program STOPPED because an INVALID DISCOUNT was introduced!\n\n";
		exit(-123456789);
	}
}
Abonament_Premium::Abonament_Premium(const Abonament& Ab, const int reducere)
	:Abonament(Ab), reducere(reducere)
{
	if (this->reducere >= (float)this->pret)
	{
		std::cout << "\n\nThe program STOPPED because an INVALID DISCOUNT was introduced!\n\n";
		exit(-123456789);
	}
}
Abonament_Premium::Abonament_Premium(const Abonament_Premium& Abp)
{
	*this = Abp;
}
Abonament_Premium::~Abonament_Premium()
{
	/// std::cout << "ABONAMENT_PREMIUM Destroyed\n\n\n";
}
//////
void Abonament_Premium::Print()
{
	Abonament::Print();
	std::cout << reducere << "\n\n";
}

float Abonament_Premium::get_total_sum()
{
	return (float)(this->perioada * (float)(this->pret - this->reducere));
}

float Abonament_Premium::get_pret()
{
	return (float)(this->pret - this->reducere);
}

//// Supraincarcari de operatori:

Abonament_Premium& Abonament_Premium::operator=(const Abonament_Premium& Abp)
{
	this->nume_abonament = Abp.nume_abonament;
	this->pret = Abp.pret;
	this->perioada = Abp.perioada;
	this->reducere = Abp.reducere;
	return *this;
}

std::istream& operator>>(std::istream& in, Abonament_Premium& Abp)
{
	std::cout << "Numele Abonamentului_Premium: ";
	in >> Abp.nume_abonament;
	std::cout << "Pretul: ";
	in >> Abp.pret;
	std::cout << "Perioada: ";
	in >> Abp.perioada;
	std::cout << "Reducere: ";
	in >> Abp.reducere;
	if (Abp.reducere >= (float)Abp.pret)
	{
		throw InvalidDiscount();
	}
	std::cout << "\n\n";
	return in;
}

std::ostream& operator<<(std::ostream& out, const Abonament_Premium& Abp)
{
	out << "Abonamentul_Premium: " << Abp.nume_abonament << ", " << Abp.pret << " euro, " << Abp.perioada << " luni\n";
	out << "Reducere de: " << Abp.reducere << " euro\n\n";
	return out;
}