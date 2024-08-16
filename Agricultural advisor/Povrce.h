#pragma once
#include "Biljka.h"
class Povrce: public Biljka
{
private:
	bool jeKorensko;
	bool jeLisnato;
public:
	Povrce(std::string ime, std::string zemljiste, double voda,
		std::pair<int, int> temperatura, std::string svetlost,
		std::string sadnja, std::string berba, bool jeKorensko,
		bool jeLisnato);
	bool getKorensko() const;
	bool getLisnato() const;
	void setKorensko(bool korensko);
	void setLisnato(bool lisnato);
	
	std::string opis() const override;
};

