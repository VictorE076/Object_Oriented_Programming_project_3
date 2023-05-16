#pragma once
#include "Clienti.h"

class Firma
{
private:
	std::shared_ptr<Clienti> clienti;
	unsigned numar_angajati;
	std::string locatie;
	std::string tip;
public:
	Firma();
	Firma(const Firma& fi);
	Firma(std::shared_ptr<Clienti> clienti, const unsigned numar_angajati, const std::string& locatie, const std::string& tip);
	~Firma();

	// friend class
	friend class Firma_Builder;
	
	//// Supraincarcari de operatori:
	Firma& operator=(const Firma& fi);
	friend std::ostream& operator<<(std::ostream& out, const Firma& f);
};

// BUILDER Design Pattern
class Firma_Builder
{
private:
	Firma firma;
public:
	Firma_Builder() = default;
	Firma_Builder& clients(std::shared_ptr<Clienti> cl);
	Firma_Builder& employees_count(const unsigned num);
	Firma_Builder& location(const std::string& loc);
	Firma_Builder& cod_firma(const std::string& tip);

	//Build
	Firma create();
	//
	~Firma_Builder();
};

// FACTORY Design Pattern
class Firma_Factory
{
public:
	Firma_Factory() = default;
	//
	static std::shared_ptr<Firma> firma_fara_info();
	static std::shared_ptr<Firma> firma_II_Bucuresti(std::shared_ptr<Clienti> cl);
	static std::shared_ptr<Firma> firma_II_Cluj(std::shared_ptr<Clienti> cl);
	static std::shared_ptr<Firma> firma_SRL_Bucuresti(std::shared_ptr<Clienti> cl);
	static std::shared_ptr<Firma> firma_SRL_Cluj(std::shared_ptr<Clienti> cl);
	static Firma firma_II_Bucuresti_no_clients();
	static Firma firma_II_Cluj_no_clients();
	//
	~Firma_Factory();
};