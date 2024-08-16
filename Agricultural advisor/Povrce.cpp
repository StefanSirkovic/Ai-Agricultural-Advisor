#include "Povrce.h"

Povrce::Povrce(std::string ime, std::string zemljiste, 
    double voda, std::pair<int, int> temperatura, 
    std::string svetlost, std::string sadnja, 
    std::string berba, bool jeKorensko, 
    bool jeLisnato) : Biljka(ime,zemljiste,voda,temperatura,svetlost,sadnja,
        berba), jeKorensko(jeKorensko), jeLisnato(jeLisnato) {}



bool Povrce::getKorensko() const { return this->jeKorensko; }
bool Povrce::getLisnato() const { return this->jeLisnato; }

void Povrce::setKorensko(bool korensko) { this->jeKorensko = korensko; }
void Povrce::setLisnato(bool lisnato) { this->jeLisnato = lisnato; }

std::string Povrce::opis() const
{
    std::stringstream buffer;
     buffer<< "Ime: " << ime << "\nTip Zemljista: " << tipZemljista << "\nPotrebna Voda: " << potrebnaVoda
        << "\nOptimalna Temperatura: " << optimalnaTemperatura.first << "-" << optimalnaTemperatura.second
        << "C\nPotrebna Svetlost: " << potrebnaSvetlost << "\nSezona Sadnje: " << sezonaSadnje
        << "\nSezona Berbe: " << sezonaBerbe  << "\nKorensko povrce: " << (jeKorensko ? "Da" : "Ne")
        << "\nLisnato povrce: " << (jeLisnato ? "Da" : "Ne") << std::endl;

     return buffer.str();
}
