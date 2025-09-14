#include "nev.h"
#include "string.h"
#include <iostream>
#include <algorithm> // std::all_of
#include <cctype>    // ::isalpha
#include "memtrace.h"
#include <cstring>

///Konstruktorok
Nev::Nev() : vnev(""), knev(""), bnev("") {}
Nev::Nev(const String& vnev, const String& knev, const String& bnev) : vnev(vnev), knev(knev), bnev(bnev) {}
Nev::Nev(const String& vnev, const String& knev) : vnev(vnev), knev(knev), bnev("") {}

///Getterek
String Nev::getVnev() const { return vnev; }
String Nev::getKnev() const { return knev; }
String Nev::getBnev() const { return bnev; }
String Nev::getTeljesNev() const { return vnev + " " + knev; }


///Beolvasás
Nev Nev::beolvas_nev() {
    String v, k, b;
     std::cin.clear();
    /// Vezetéknév beolvasása
    while (true) {
        std::cout << "Vezeteknev: ";
        std::cin >> v;
        if (v.size() > 0 && std::all_of(v.c_str(), v.c_str() + v.size(), ::isalpha)) {
            break; /// Érvényes keresztnév, ha legalább egy karakter és csak betűket tartalmaz
        } else {
            std::cout << "Hiba: A vezeteknevnek legalabb 1 betubol kell allnia, es csak betu lehet!" << std::endl;
        }
    }

    /// Keresztnév beolvasása
    while (true) {
        std::cout << "Keresztnev: ";
        std::cin >> k;
        if (k.size() > 0 && std::all_of(k.c_str(), k.c_str() + k.size(), ::isalpha)) {
            break; /// Érvényes keresztnév, ha legalább egy karakter és csak betűket tartalmaz
        } else {
            std::cout << "Hiba: A keresztnevnek legalabb 1 betubol kell allnia, es csak betu lehet!" << std::endl;
        }
    }

    /// Becenév beolvasása (opcionális, lehet üres)
    std::cout << "Becenev: ";
    std::cin >> b;

    return Nev(v, k, b);
}



std::ostream& operator<<(std::ostream& os, const Nev& rhs) {
    os << "Nev: " << rhs.getTeljesNev();

    /// Ha van becenév, akkor zárójelben kiírjuk
    if (strlen(rhs.getBnev().c_str()) > 0) {
        os << " (" << rhs.getBnev() << ")";
    }

    return os;
}
