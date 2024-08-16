#pragma once
#include "Biljka.h"
class Voce : public Biljka
{
private:
	bool jeTropsko;
	bool jeJagodasto;
public:
	Voce(std::string ime, std::string zemljiste, double voda,
		std::pair<int, int> temperatura, std::string svetlost,
		std::string sadnja, std::string berba, bool jeTropsko,
		bool jeJagodasto);

	bool getTropsko() const;
	bool getJagodasto() const;

	void setTropsko(bool tropsko);
	void setJagodasto(bool jagodasto);

	std::string opis() const override;
};

