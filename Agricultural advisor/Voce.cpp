#include "Voce.h"

Voce::Voce(std::string ime, std::string zemljiste,
    double voda, std::pair<int, int> temperatura,
    std::string svetlost, std::string sadnja,
    std::string berba, bool jeTropsko,
    bool jeJagodasto) : Biljka(ime, zemljiste, voda, temperatura, svetlost, sadnja,
        berba), jeTropsko(jeTropsko), jeJagodasto(jeJagodasto) {}

bool Voce::getTropsko() const { return this->jeTropsko; }
bool Voce::getJagodasto() const { return this->jeJagodasto; }

void Voce::setTropsko(bool tropsko) { this->jeTropsko = tropsko; }
void Voce::setJagodasto(bool jagodasto){ this->jeJagodasto = jagodasto; }

std::string Voce::opis() const
{
    std::stringstream buffer;
    buffer << "Ime: " << ime << "\nTip Zemljista: " << tipZemljista << "\nPotrebna Voda: " << potrebnaVoda
        << "\nOptimalna Temperatura: " << optimalnaTemperatura.first << "-" << optimalnaTemperatura.second
        << "C\nPotrebna Svetlost: " << potrebnaSvetlost << "\nSezona Sadnje: " << sezonaSadnje
        << "\nSezona Berbe: " << sezonaBerbe << "\nTropsko voce: " << (jeTropsko ? "Da" : "Ne")
        << "\nJagodasto voce: " << (jeJagodasto ? "Da" : "Ne") << std::endl;

    return buffer.str();
}
