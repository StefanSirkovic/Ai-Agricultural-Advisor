#include "Biljka.h"


Biljka::Biljka() : ime("No name"), tipZemljista("Unknown"), potrebnaVoda(0.0),
				optimalnaTemperatura(0, 0), potrebnaSvetlost("Unknown"),
				sezonaSadnje("Unknown"),sezonaBerbe("Unknown") {}

Biljka::Biljka(std::string ime, std::string zemljiste, 
	double voda, std::pair<int, int> temperatura, 
	std::string svetlost, 
	std::string sadnja, std::string berba) :ime(ime), tipZemljista(zemljiste),
	potrebnaVoda(voda), optimalnaTemperatura(temperatura), potrebnaSvetlost(svetlost),
	sezonaSadnje(sadnja), sezonaBerbe(berba) {}

std::string Biljka::getIme() const { return this->ime; }
std::string Biljka::getZemljiste() const { return this->tipZemljista; }
std::string Biljka::getSadnja() const { return this->sezonaSadnje; }
std::string Biljka::getBerba() const { return this->sezonaBerbe; }
std::string Biljka::getSvetlost() const { return this->potrebnaSvetlost; }
double Biljka::getVoda() const { return this->potrebnaVoda; }
std::pair<int, int> Biljka::getTemperatura() const { return this->optimalnaTemperatura; }

void Biljka::setIme(const std::string& ime) { this->ime = ime; }
void Biljka::setZemljiste(const std::string& zemljiste) { this->tipZemljista = zemljiste; }
void Biljka::setSadnja(const std::string& sadnja) { this->sezonaSadnje = sadnja; }
void Biljka::setBerba(const std::string& berba) { this->sezonaBerbe = berba; }
void Biljka::setSvetlost(const std::string& svetlost) { this->potrebnaSvetlost = svetlost; }
void Biljka::setVoda(double voda) { this->potrebnaVoda = voda; }
void Biljka::setTemperatura(const std::pair<int, int>& temperatura) { this->optimalnaTemperatura = temperatura; }





