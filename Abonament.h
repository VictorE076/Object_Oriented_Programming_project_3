#pragma once
#include <iostream>
#include <memory> // smart pointers
#include <vector>
#include <string>
#include <typeinfo> // typeid
#include <stdlib.h>
#include <algorithm>

class Contract
{
protected:
	static unsigned nr_total_Contracte;
public:
	Contract();
	virtual void Print() = 0;
	virtual float get_total_sum() = 0;
	virtual ~Contract();

	// static functions:
	static void set_nr_total_Contracte_to_zero();
	static unsigned get_nr_total_Contracte();
};
class Abonament : public Contract
{
protected:
	std::string nume_abonament;
	float pret;
	int perioada;
public:
	Abonament() = default;
	Abonament(const std::string& nume_Abonament, const float Pret, const int Perioada);
	Abonament(const Abonament& Ab);
	~Abonament();
	//////
	void Print() override;
	float get_total_sum() override;
	virtual float get_pret();


	//// Supraincarcari de operatori:
	Abonament& operator=(const Abonament& Ab);
	friend std::istream& operator>>(std::istream& in, Abonament& Ab);
	friend std::ostream& operator<<(std::ostream& out, const Abonament& Ab);
};

// std::exception
class InvalidChoice : public std::exception
{
public:
	const char* what() const throw();
};

class InvalidDiscount : public std::exception
{
public:
	const char* what() const throw();
};
