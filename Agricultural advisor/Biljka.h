#pragma once
#include "includes.h"

class Biljka
{
protected:
	
	std::string ime;
	std::string tipZemljista;
	double potrebnaVoda; //u litrima
	std::pair<int, int> optimalnaTemperatura; //min,max stepeni
	std::string potrebnaSvetlost; //Niska,Srednja,Visoka
	std::string sezonaSadnje;
	std::string sezonaBerbe;

public:
	//Konstruktori
	Biljka();
	Biljka(std::string ime, std::string zemljiste, double voda,
		std::pair<int, int> temperatura, std::string svetlost,
		std::string sadnja, std::string berba);

	//Inspektori
	std::string getIme() const;
	std::string getZemljiste() const;
	std::string getSadnja() const;
	std::string getBerba() const;
	std::string getSvetlost() const;
	double getVoda() const;
	std::pair<int, int> getTemperatura() const;

	//Mutatori
	void setIme(const std::string& ime);
	void setZemljiste(const std::string& zemljiste);
	void setSadnja(const std::string& sadnja);
	void setBerba(const std::string& berba);
	void setSvetlost(const std::string& svetlost);
	void setVoda(double voda);
	void setTemperatura(const std::pair<int, int>& temperatura);
	
	virtual std::string opis() const = 0;
	
};
