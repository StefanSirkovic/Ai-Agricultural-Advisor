#pragma once
#include "includes.h"
#include "Biljka.h"
#include "Povrce.h"
#include "Voce.h"
#include "Preporuke.h"
class BazaZnanja
{
private:
	std::vector<std::unique_ptr<Biljka>> biljke;
	static int ukupnoBiljaka;
public:
	void unosOpstihPodataka(std::string& ime, std::string& tipZemljista, double& potrebnaVoda,
		std::pair<int, int>& optimalnaTemperatura, std::string& potrebnaSvetlost,
		std::string& sezonaSadnje, std::string& sezonaBerbe);
	std::unique_ptr<Povrce> unosPovrca();
	std::unique_ptr<Voce> unosVoca();
	void dodajBiljku(std::unique_ptr<Biljka> biljka);
	
	void prikaziSveBiljke() const;
	void prikaziUkupnoBiljaka() const;
	void pretraziFajl(int izbor) const;
	void ispisiNaslov(const std::string& naslov) const;
	friend std::ostream& operator<<(std::ostream& os, const Biljka& biljka);
};




