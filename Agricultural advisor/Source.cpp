#include "includes.h"
#include "Biljka.h"
#include "Voce.h"
#include "Povrce.h"
#include "BazaZnanja.h"
#include "Preporuke.h"

int main() {

    BazaZnanja *baza = new BazaZnanja;
	int izbor = 0;
    std::string apiKey = "d37c8fc24b0e417a99db682b625b7bd3"; // api Key
    std::string endpoint = "https://api.aimlapi.com/v1/chat/completions";

    Preporuke gpt(apiKey, endpoint);

	baza->ispisiNaslov("Virtuelni Poljoprivredni Savetnik");
	while (true) {
        bool validInput = false;
        while (!validInput) {
            std::cout << "\nOdaberite opciju:\n1. Preporuka biljke na osnovu mog tipa zemljista\n2. Preporuka uslova za sadnju na osnovu unete biljke\n3. Dodaj novo povrce u bazu\n4. Dodaj novo voce u bazu\n5. Prikazi sve biljke u bazi\n6. Prikazi broj biljaka\n7. Pretrazi po imenu\n8. Pretrazi po tipu zemljista\n9. Izlaz\nVas izbor: ";
            std::cin >> izbor;
            if (std::cin.fail()) { // Proverava da li unos nije broj
                std::cin.clear(); // Brise gresku
                std::cin.ignore(std::streamsize(10000), '\n'); // Ignoriše ostatak linije
                std::cout << "Nepoznat unos. Molimo unesite broj od 1 do 9.\n";
            }
            else 
                validInput = true;
        }
        
        std::string prompt = "";
        std::string response = "";
        std::string answer = "";
        std::string tipZemljista = "";
        std::string nazivBiljke = "";

        switch (izbor) {
        case 1: system("cls");
            baza->ispisiNaslov("Preporuka biljke na osnovu mog tipa zemljista");
            std::cout << "Unesite Vas tip zemljista: ";
            std::cin >> tipZemljista;
            std::cout << std::endl;
            prompt = "Dacu ti svoj tip zemljista a ti mi na osnovu njega na srpskom bez š,ć,č,ž,đ, koristeci samo unicode karaktere preporuci biljke koje su najbolje za sadnju u njemu. Tip zemljista je: " + tipZemljista;
            response = gpt.sendRequest(prompt);
            answer = gpt.extractResponse(response);

            std::cout << "AI odgovor: " << answer << std::endl;
            break;
        case 2: system("cls");
            baza->ispisiNaslov("Preporuka uslova za sadnju na osnovu unete biljke");
            std::cout << "Unesite Vasu biljku: ";
            std::cin >> nazivBiljke;
            std::cout << std::endl;
            prompt = "Dacu ti svoju biljku a ti mi na osnovu nje na srpskom bez š,ć,č,ž,đ, koristeci samo unicode karaktere preporuci uslove za sadnju koji su najbolji za biljku koju sam ti dao. Naziv biljke je: " + nazivBiljke;
            response = gpt.sendRequest(prompt);
            answer = gpt.extractResponse(response);

            std::cout << "AI odgovor: " << answer << std::endl;
            break;
        case 3: system("cls"); baza->ispisiNaslov("Dodavanje povrca"); baza->dodajBiljku(baza->unosPovrca()); break;
        case 4: system("cls"); baza->ispisiNaslov("Dodavanje voca"); baza->dodajBiljku(baza->unosVoca()); break;
        case 5: system("cls"); baza->ispisiNaslov("Biljke u bazi");  baza->prikaziSveBiljke(); break;
        case 6: system("cls"); baza->ispisiNaslov("Ukupno biljaka u bazi"); baza->prikaziUkupnoBiljaka(); break;
        case 7: system("cls"); baza->ispisiNaslov("Pretraga po imenu"); baza->pretraziFajl(1); break;
        case 8: system("cls"); baza->ispisiNaslov("Pretraga po tipu zemljista"); baza->pretraziFajl(2); break;
        case 9: exit(0); //IZLAZ
        default: std::cout << "Nepoznata opcija. Molimo pokusajte ponovo.\n" << std::endl;
        }
    }

    delete baza;
	system("pause"); return 0;
}