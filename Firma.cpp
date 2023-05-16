#include "Firma.h"

Firma::Firma() : clienti(nullptr), numar_angajati(0), locatie(""), tip("")
{}

Firma::Firma(const Firma& fi)
{
	*this = fi;
}

Firma::Firma(std::shared_ptr<Clienti> clienti, const unsigned numar_angajati, const std::string& locatie, const std::string& tip) : clienti(clienti), numar_angajati(numar_angajati), locatie(locatie), tip(tip)
{}

Firma::~Firma()
{
	/// std::cout << "\n\nFIRMA Destroyed!!!\n\n";
}

Firma& Firma::operator=(const Firma& fi)
{
	this->clienti = fi.clienti;
	this->numar_angajati = fi.numar_angajati;
	this->locatie = fi.locatie;
	this->tip = fi.tip;
	return *this;
}

//
// BUILDER Design Pattern
Firma_Builder& Firma_Builder::clients(std::shared_ptr<Clienti> cl)
{
	this->firma.clienti = cl;
	return *this;
}
Firma_Builder& Firma_Builder::employees_count(const unsigned num)
{
	this->firma.numar_angajati = num;
	return *this;
}
Firma_Builder& Firma_Builder::location(const std::string& loc)
{
	this->firma.locatie = loc;
	return *this;
}
Firma_Builder& Firma_Builder::cod_firma(const std::string& tip)
{
	this->firma.tip = tip;
	return *this;
}
//
Firma Firma_Builder::create()
{
	return this->firma;
}
/////
Firma_Builder::~Firma_Builder()
{
	/// std::cout << "\n\nFIRMA_BUILDER Destroyed!!!\n\n";
}

std::ostream& operator<<(std::ostream& out, const Firma& f)
{
	out << "FIRMA curenta detine informatii despre:\n\n";
	if (f.clienti == nullptr)
		out << "FIRMA nu are niciun CLIENT momentan!!!\n";
	else
		out << *f.clienti;
	//
	if (f.numar_angajati == 0)
		out << "FIRMA nu are niciun ANGAJAT momentan!!!\n";
	else
		out << "Numarul ANGAJATILOR din firma: " << f.numar_angajati << "\n";
	//
	if (f.locatie == "")
		out << "Nu s-a specificat LOCATIA firmei momentan!!!\n";
	else
		out << "LOCATIA firmei: " << f.locatie << "\n";
	//
	if (f.tip == "")
		out << "Nu s-a specificat codul FIRMEI momentan!!!\n";
	else
		out << "Codul FIRMEI: " << f.tip << "\n";
	//
	out << "\n\n";
	return out;
}

//
// FACTORY Design Pattern
std::shared_ptr<Firma> Firma_Factory::firma_fara_info()
{
	return std::make_shared<Firma>(nullptr, 0, "", "");
}

std::shared_ptr<Firma> Firma_Factory::firma_II_Bucuresti(std::shared_ptr<Clienti> cl)
{
	return std::make_shared<Firma>(cl, 8, "Bucuresti", "01");
}

std::shared_ptr<Firma> Firma_Factory::firma_II_Cluj(std::shared_ptr<Clienti> cl)
{
	return std::make_shared<Firma>(cl, 8, "Cluj", "01");
}

std::shared_ptr<Firma> Firma_Factory::firma_SRL_Bucuresti(std::shared_ptr<Clienti> cl)
{
	return std::make_shared<Firma>(cl, 10000, "Bucuresti", "02");
}

std::shared_ptr<Firma> Firma_Factory::firma_SRL_Cluj(std::shared_ptr<Clienti> cl)
{
	return std::make_shared<Firma>(cl, 10000, "Cluj", "02");
}

Firma Firma_Factory::firma_II_Bucuresti_no_clients()
{
	return Firma(nullptr, 8, "Bucuresti", "01");
}

Firma Firma_Factory::firma_II_Cluj_no_clients()
{
	return Firma(nullptr, 8, "Cluj", "01");
}

Firma_Factory::~Firma_Factory()
{
	/// std::cout << "\n\nFIRMA_FACTORY Destroyed!!!\n\n";
}

