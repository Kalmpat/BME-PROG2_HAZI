
#include "cim.h"
#include "string.h"
#include "memtrace.h"
#include <cstring>    // A C-sztringek kezeléséhez
#include <algorithm>  // Az std::all_of használatához

/// Alapértelmezett konstruktor
Cim::Cim() : orszag(""), iranyitoszam(""), varos(""), utca("") {}

/// Paraméterezett konstruktor
Cim::Cim(const String& orszag, const String& iranyitoszam, const String& varos, const String& utca)
    : orszag(orszag), iranyitoszam(iranyitoszam), varos(varos), utca(utca) {}

/// Getterek
String Cim::getOrszag() const { return orszag; }
String Cim::getIranyito() const { return iranyitoszam; }
String Cim::getVaros() const { return varos; }
String Cim::getUtca() const { return utca; }

///Cím olvasása
Cim Cim::beolvas_cim() {
    String orsz, irsz, var, utc;

    /// Ország beolvasása
    while (true) {
        std::cout << "Orszag: ";
        std::cin >> orsz;
        /// Ellenőrizzük, hogy a bemenet legalább 1 karakter hosszú és nem tartalmaz számokat és szóközöket
        if (orsz.size() > 0 && std::all_of(orsz.c_str(), orsz.c_str() + orsz.size(), ::isalpha)) {
            break;
        } else {
            std::cout << "Hiba: Az orszag neve nem lehet ures, es nem tartalmazhat szamokat, szokozoket." << std::endl;
        }
    }

    /// Irányítószám beolvasása
    while (true) {
        std::cout << "Iranyitoszam (4 karakter, csak szamok): ";
        std::cin >> irsz;
        /// Ellenőrizzük, hogy a bemenet legalább 4 karakter hosszú és csak számokat tartalmaz
        if (irsz.size() == 4 && std::all_of(irsz.c_str(), irsz.c_str() + 4, ::isdigit)) {
            break;
        } else {
            std::cout << "Hiba: Az iranyitoszamnak 4 szamjegybol kell allnia." << std::endl;
        }
    }

    /// Város beolvasása
    while (true) {
        std::cout << "Varos: ";
        std::cin >> var;
        /// Ellenőrizzük, hogy a bemenet legalább 1 karakter hosszú és nem tartalmaz számokat és szóközöket
        if (var.size() > 0 && std::all_of(var.c_str(), var.c_str() + var.size(), ::isalpha)) {
            break;
        } else {
            std::cout << "Hiba: A varos neve nem lehet ures, es nem tartalmazhat szamokat, szokozoket." << std::endl;
        }
    }

    /// Utca beolvasása
    while (true) {
        std::cout << "Utca: ";
        std::cin >> utc;
        /// Ellenőrizzük, hogy a bemenet legalább 1 karakter hosszú
        if (utc.size() > 0) {
            break;
        } else {
            std::cout << "Hiba: Az utca neve nem lehet ures" << std::endl;
        }
    }

    return Cim(orsz, irsz, var, utc);
}


/// Túlterheljük az << operátort
std::ostream& operator<<(std::ostream& os, const Cim& rhs) {
    os << "Cim: " << rhs.getIranyito() << " " << rhs.getVaros() << ", " << rhs.getUtca() << ", " << rhs.getOrszag();
    return os;
}
