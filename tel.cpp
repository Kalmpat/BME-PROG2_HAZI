#include "tel.h"
#include "string.h"
#include "memtrace.h"
#include <iostream>
#include <algorithm>
#include <cctype>


/// Alapértelmezett konstruktor
Tel::Tel() : mszam(""), pszam("") {}

/// Paraméterezett konstruktor
Tel::Tel(const String& mszam, const String& pszam)
    : mszam(mszam), pszam(pszam) {}

/// Getterek
String Tel::getMszam() const { return mszam; }
String Tel::getPszam() const { return pszam; }


/// Telefonszám beolvasása
Tel Tel::beolvas_tel() {
    String msz, psz;

    /// Munkahelyi szám beolvasása
    while (true) {
        std::cout << "Munkahelyi szam (11 karakter, csak szamok): ";
        std::cin >> msz;

        /// Ellenőrizzük, hogy a bemenet 11 karakter hosszú és csak számokat tartalmaz
        if (msz.size() == 11 && std::all_of(msz.c_str(), msz.c_str() + 11, ::isdigit)) {
            break; /// Ha érvényes, kilépünk a ciklusból
        } else {
            std::cout << "Hiba: A munkahelyi szamnak 11 szamjegybol kell allnia." << std::endl;
        }
    }

    /// Privát szám beolvasása
    while (true) {
        std::cout << "Privat szam (11 karakter, csak szamok): ";
        std::cin >> psz;

        /// Ellenőrizzük, hogy a bemenet 11 karakter hosszú és csak számokat tartalmaz
        if (psz.size() == 11 && std::all_of(psz.c_str(), psz.c_str() + 11, ::isdigit)) {
            break; /// Ha érvényes, kilépünk a ciklusból
        } else {
            std::cout << "Hiba: A privat szamnak 11 szamjegybol kell allnia." << std::endl;
        }
    }

    return Tel(msz, psz);
}


/// Túlterheljük az << operátort
std::ostream& operator<<(std::ostream& os, const Tel& rhs) {
    os << "Munkahelyi es Privat: " << rhs.getMszam() << " / " << rhs.getPszam();
    return os;
}
