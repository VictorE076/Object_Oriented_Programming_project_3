#pragma once
#include "Abonat.h"

class Clienti
{
private:
	std::vector<std::shared_ptr<Abonat>> abonati;
public:
	Clienti() = default;
	Clienti(const Clienti& cli);
	Clienti(const std::vector<std::shared_ptr<Abonat>>& abonati);
	virtual ~Clienti();
	//////
	//
	unsigned get_nr_Ab();
	unsigned get_nr_Ab_Premium();
	float total_sum_ab();
	//
	void Push_Abonat(std::shared_ptr<Abonat> Abt);
	virtual void Print() const;

	//// Supraincarcari de operatori:
	Clienti& operator=(const Clienti& Cl);
	friend std::istream& operator>>(std::istream& in, Clienti& Cl);
	friend std::ostream& operator<<(std::ostream& out, const Clienti& Cl);
};