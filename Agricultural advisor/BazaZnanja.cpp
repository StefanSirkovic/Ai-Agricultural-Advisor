#include "BazaZnanja.h"

int BazaZnanja::ukupnoBiljaka = 0;

void BazaZnanja::unosOpstihPodataka(std::string& ime, std::string& tipZemljista, double& potrebnaVoda, std::pair<int, int>& optimalnaTemperatura, std::string& potrebnaSvetlost, std::string& sezonaSadnje, std::string& sezonaBerbe)
{
    std::cout << "Unesite ime biljke: "; std::cin >> ime;
    std::cout << "Unesite tip zemljista: "; std::cin >> tipZemljista;
    std::cout << "Unesite potrebnu kolicinu vode (u litrima po danu): "; std::cin >> potrebnaVoda;
    std::cout << "Unesite optimalnu minimalnu temperaturu (C): "; std::cin >> optimalnaTemperatura.first;
    std::cout << "Unesite optimalnu maksimalnu temperaturu (C): "; std::cin >> optimalnaTemperatura.second;
    std::cout << "Unesite potrebnu svetlost (Niska/Srednja/Visoka): "; std::cin >> potrebnaSvetlost;
    std::cout << "Unesite sezonu sadnje: "; std::cin >> sezonaSadnje;
    std::cout << "Unesite sezonu berbe: "; std::cin >> sezonaBerbe;
}

std::unique_ptr<Povrce> BazaZnanja::unosPovrca()
{
    std::string ime, tipZemljista, potrebnaSvetlost, sezonaSadnje, sezonaBerbe;
    double potrebnaVoda;
    std::pair<int, int> optimalnaTemperatura;
    bool jeKorensko, jeLisnato;

    unosOpstihPodataka(ime, tipZemljista, potrebnaVoda, optimalnaTemperatura, potrebnaSvetlost, sezonaSadnje, sezonaBerbe);

    std::cout << "Da li je korensko povrce (1 za Da, 0 za Ne): ";
    std::cin >> jeKorensko;
    std::cout << "Da li je lisnato povrce (1 za Da, 0 za Ne): ";
    std::cin >> jeLisnato;

    return std::make_unique<Povrce>(ime, tipZemljista, potrebnaVoda, optimalnaTemperatura, potrebnaSvetlost, sezonaSadnje, sezonaBerbe, jeKorensko, jeLisnato);
}

std::unique_ptr<Voce> BazaZnanja::unosVoca()
{
    std::string ime, tipZemljista, potrebnaSvetlost, sezonaSadnje, sezonaBerbe;
    double potrebnaVoda;
    std::pair<int, int> optimalnaTemperatura;
    bool jeTropsko, jeJagodasto;

    unosOpstihPodataka(ime, tipZemljista, potrebnaVoda, optimalnaTemperatura, potrebnaSvetlost, sezonaSadnje, sezonaBerbe);

    std::cout << "Da li je tropsko voce (1 za Da, 0 za Ne): ";
    std::cin >> jeTropsko;
    std::cout << "Da li je jagodasto voce (1 za Da, 0 za Ne): ";
    std::cin >> jeJagodasto;

    return std::make_unique<Voce>(ime, tipZemljista, potrebnaVoda, optimalnaTemperatura, potrebnaSvetlost, sezonaSadnje, sezonaBerbe, jeTropsko, jeJagodasto);
}

void BazaZnanja::dodajBiljku(std::unique_ptr<Biljka> biljka)
{
    biljke.push_back(move(biljka));
    std::ofstream myFile("biljke.txt",std::ios::app);
    for (const auto& i : biljke)
        myFile << i->opis() << std::string(50, '-') << std::endl; //Preklopljen operator <<
    myFile.close();
}

void BazaZnanja::prikaziSveBiljke() const
{
    std::vector<std::string> lines;
    std::string line;
    
    std::ifstream myFile("biljke.txt");
    if (!myFile.is_open())
        std::cout << "Nije moguce otvoriti fajl." << std::endl;
   
    while (std::getline(myFile, line)) 
        lines.push_back(line);
    for (const auto& i : lines) {
        std::cout << i << std::endl;
    }
    
    myFile.close();
}

void BazaZnanja::prikaziUkupnoBiljaka() const { 
    ukupnoBiljaka = 0;
    std::string rec;
    std::ifstream myFile("biljke.txt");
    if (!myFile.is_open())
        std::cout << "Nije moguce otvoriti fajl." << std::endl;

    while (myFile >> rec)
        if (rec == "Ime:")
            ukupnoBiljaka++;
    
    std::cout << this->ukupnoBiljaka << std::endl << std::string(50, '-') << std::endl; 

    myFile.close();
}

void BazaZnanja::pretraziFajl(int izbor) const
{
    std::ifstream myFile("biljke.txt");
    if (!myFile.is_open())
        std::cout << "Nije moguce otvoriti fajl." << std::endl;

    std::string linija;
    std::streampos pozicija = std::ifstream::pos_type(0);
    bool pronadjeno = false;

    if (izbor == 1) {
        std::string pretragaIme;
        std::cout << "\nUnesite zeljeno ime biljke za pretragu: ";
        std::cin >> pretragaIme;
        std::cout << std::endl;
    
        while (std::getline(myFile, linija))
            if (linija.data() == ("Ime: "+pretragaIme))
            if ((linija.find(pretragaIme) != std::string::npos)){
                    pozicija = myFile.tellg(); // Zapamti poziciju nakon pronalaska
                    pronadjeno = true;
                    break;
            }
         
        if (pronadjeno) {
            myFile.clear();
            myFile.seekg(pozicija); // Podesi poziciju fajla
            std::cout << "Ime: " << pretragaIme << std::endl;
            while (std::getline(myFile, linija)) //Ispis
                if (linija[0] != '-')
                     std::cout << linija << std::endl;
                else
                    break;
        }
        else
            std::cout << "Nema biljaka pod tim imenom u bazi." << std::endl;
    }

    else {
        std::string pretragaZemljiste;
        std::cout << "\nUnesite zeljeni tip zemljista za pretragu: ";
        std::cin >> pretragaZemljiste;
        std::cout << std::endl;

        while (std::getline(myFile, linija)) {
            std::string imeBiljke = linija;

            if (std::getline(myFile, linija) && linija == "Tip Zemljista: " + pretragaZemljiste) {
                pronadjeno = true;
                std::cout << imeBiljke << std::endl;
                std::cout << linija << std::endl;

                while (std::getline(myFile, linija) && linija[0] != '-') {
                    std::cout << linija << std::endl;
                }
                std::cout << std::string(50, '-') << std::endl;
            }
        }
        if (!pronadjeno)
            std::cout << "Ne postoji tip zemljista pod tim imenom u bazi." << std::endl;
    }

        myFile.close();
}

void BazaZnanja::ispisiNaslov(const std::string& naslov) const
{
    int sirina = 50;
    int levo = (sirina - naslov.size()) / 2;
    int desno = sirina - levo - naslov.size();
    std::cout << std::string(levo, ' ') << naslov << std::string(desno, ' ') << std::endl;
    std::cout << std::string(sirina, '=') << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Biljka& biljka) {
    os << biljka.opis();
    return os;
}

