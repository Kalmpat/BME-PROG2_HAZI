
#include "profil.h"
#include "memtrace.h"

/// Alapértelmezett konstruktor
Profil::Profil() : nev(), cim(), tel() {}

/// Paraméterezett konstruktor
Profil::Profil(const Nev& nev, const Cim& cim, const Tel& tel)
    : nev(nev), cim(cim), tel(tel) {}


/// Getterek
Nev Profil::getNev() const { return nev; }
Cim Profil::getCim() const { return cim; }
Tel Profil::getTel() const { return tel; }


/// Túlterheljük az << operátort
std::ostream& operator<<(std::ostream& os, const Profil& rhs) {
    os << rhs.getNev() << "\n" << rhs.getCim() << "\n" << rhs.getTel() << std::endl;
    return os;
}
