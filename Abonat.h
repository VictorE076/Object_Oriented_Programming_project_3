#pragma once
#include "Persoana.h"

class Abonat : public Persoana
{
private:
	std::string nr_telefon;
	std::shared_ptr<Abonament> x;
public:
	Abonat() = default;
	Abonat(const int id, const std::string& nume, const std::string& cnp, const std::string& nr_telefon, std::shared_ptr<Abonament> Ab);
	Abonat(const Persoana& Pers, const std::string& nr_telefon, std::shared_ptr<Abonament> Ab);
	Abonat(const Abonat& At);
	~Abonat();
	//////
	void Print() override;
	float get_sum_abonat();
	const std::type_info& get_type_Abonament() const;
	float get_pret_Abonament() const;

	//// Supraincarcari de operatori:
	Abonat& operator=(const Abonat& Abt);
	friend std::istream& operator>>(std::istream& in, Abonat& Abt);
	friend std::ostream& operator<<(std::ostream& out, const Abonat& Abt);
};