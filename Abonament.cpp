#include "Abonament.h"

unsigned Contract::nr_total_Contracte = 0;

Contract::Contract()
{
	nr_total_Contracte++;
	/// std::cout << "CONTRACTUL poate cuprinde mai multe tipuri de abonamente(SIMPLE sau PREMIUM)\n\n";
}
Contract::~Contract()
{
	if (nr_total_Contracte > 0)
		nr_total_Contracte--;
	/// std::cout << "CONTRACT Destroyed\n\n\n";
}

// static functions:
void Contract::set_nr_total_Contracte_to_zero()
{
	nr_total_Contracte = 0;
}
unsigned Contract::get_nr_total_Contracte()
{
	return nr_total_Contracte;
}

/////

Abonament::Abonament(const std::string& nume_abonament, const float pret, const int perioada)
	:nume_abonament(nume_abonament), pret(pret), perioada(perioada) // pseudo-constructori;
{

}
Abonament::Abonament(const Abonament& Ab)
{
	*this = Ab;
}
Abonament::~Abonament()
{
	/// std::cout << "ABONAMENT Destroyed\n\n\n";
}
//////
void Abonament::Print()
{
	std::cout << this->nume_abonament << " " << this->pret << " " << this->perioada;
	std::cout << "\nNumarul total de contracte la acest moment este: " << nr_total_Contracte << " !!!\n\n";
}

float Abonament::get_total_sum()
{
	return (float)(this->pret * this->perioada);
}

float Abonament::get_pret()
{
	return this->pret;
}

//// Supraincarcari de operatori:
Abonament& Abonament::operator=(const Abonament& Ab)
{
	this->nume_abonament = Ab.nume_abonament;
	this->pret = Ab.pret;
	this->perioada = Ab.perioada;
	return *this;
}

std::istream& operator>>(std::istream& in, Abonament& Ab)
{
	std::cout << "Numele Abonamentului: ";
	in >> Ab.nume_abonament;
	std::cout << "Pretul: ";
	in >> Ab.pret;
	std::cout << "Perioada: ";
	in >> Ab.perioada;
	std::cout << "\n\n";
	return in;
}

std::ostream& operator<<(std::ostream& out, const Abonament& Ab)
{
	out << "Abonamentul: " << Ab.nume_abonament << ", " << Ab.pret << " euro, " << Ab.perioada << " luni\n\n";
	return out;
}

//std::exception
const char* InvalidChoice::what() const throw()
{
	return "ERROR1: NOT A VALID CHOICE (THE PROGRAM STOPPED)!\n\n";
}

const char* InvalidDiscount::what() const throw()
{
	return "\n\nThe program STOPPED because an INVALID DISCOUNT1 was introduced!\n\n";
}
