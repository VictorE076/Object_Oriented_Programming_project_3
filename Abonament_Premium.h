#pragma once
#include "Abonament.h"

class Abonament_Premium : public Abonament
{
private:
	int reducere;
public:
	Abonament_Premium() = default;
	Abonament_Premium(const std::string& nume_abonament, const float pret, const int perioada, const int reducere);
	Abonament_Premium(const Abonament& Ab, const int reducere);
	Abonament_Premium(const Abonament_Premium& Abp);
	~Abonament_Premium();
	//////
	void Print() override;
	float get_total_sum() override;
	float get_pret() override;


	//// Supraincarcari de operatori:
	Abonament_Premium& operator=(const Abonament_Premium& Abp);
	friend std::istream& operator>>(std::istream& in, Abonament_Premium& Abp);
	friend std::ostream& operator<<(std::ostream& out, const Abonament_Premium& Abp);
};