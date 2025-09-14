#include "telefonkonyv.h"
#include "memtrace.h"

/// Konstruktor és lefoglalás
Telefonkonyv::Telefonkonyv() : profilSzam(0), kapacitas(1) {
    profiltar = new Profil[kapacitas];
}

/// Destruktor
Telefonkonyv::~Telefonkonyv() {
    delete[] profiltar;
}

/// Kapacitás növelése
void Telefonkonyv::noveldKapacitas() {
    kapacitas++;
    Profil* ujTar = new Profil[kapacitas];
    /// Átmásoljuk a régi profilokat az új tömbbe
    for (size_t i = 0; i < profilSzam; i++) {
        ujTar[i] = profiltar[i];
    }

    delete[] profiltar;
    profiltar = ujTar;
}

/// Adatok felvétele
void Telefonkonyv::addProfil(const Profil& profil) {
    if (profilSzam >= kapacitas) {
        noveldKapacitas();
    }
    profiltar[profilSzam] = profil; /// Profil hozzáadása
    profilSzam++; /// Profilok számának növelése
}

/// Listázás
void Telefonkonyv::listaz() const {
    for (size_t i = 0; i < profilSzam; i++) {
        std::cout << profiltar[i] << std::endl;
    }
}

/// Adatok törlése
void Telefonkonyv::torol(const String& vnev, const String& knev) {
    bool talalt = false;
    for (size_t i = 0; i < profilSzam; i++) {
        if (profiltar[i].getNev().getVnev() == vnev && profiltar[i].getNev().getKnev() == knev) {
            /// Profil törlése
            for (size_t j = i; j < profilSzam - 1; j++) {
                profiltar[j] = profiltar[j + 1];
            }
            profilSzam--;
            std::cout << "Profil torolve: " << vnev << " " << knev << std::endl;
            talalt = true;
        }
    }
     if (!talalt){
        std::cout << "Profil nem talalhato: " << vnev << " " << knev << std::endl;
     }
}

/// Egyszerű keresés (név alapján)
bool Telefonkonyv::keresNev(const String& nev) const {
    bool talalat = false;
    for (size_t i = 0; i < profilSzam; i++) {
        if (profiltar[i].getNev().getVnev() == nev ||
            profiltar[i].getNev().getKnev() == nev ||
            profiltar[i].getNev().getTeljesNev() == nev ||
            profiltar[i].getNev().getBnev() == nev) {
            std::cout << profiltar[i] << std::endl;
            talalat = true;
        }
    }
    if (!talalat) {
        std::cout << "Nincs talalat a(z) " << nev << " nevre." << std::endl;
    }
    return talalat;
}

/// Keresés cím alapján
bool Telefonkonyv::keresCim(const String& cim) const {
    bool talalat = false;
    for (size_t i = 0; i < profilSzam; i++) {
        if (profiltar[i].getCim().getUtca() == cim ||
            profiltar[i].getCim().getVaros() == cim ||
            profiltar[i].getCim().getOrszag() == cim  ||
            profiltar[i].getCim().getIranyito() == cim) {
            std::cout << profiltar[i] << std::endl;
            talalat = true;
        }
    }
    if (!talalat) {
        std::cout << "Nincs talalat a(z) " << cim << " cimre." << std::endl;
    }
    return talalat;
}

/// Keresés telefonszám alapján
bool Telefonkonyv::keresTel(const String& tel) const {
    bool talalat = false;
    for (size_t i = 0; i < profilSzam; i++) {
        if (profiltar[i].getTel().getMszam() == tel ||
            profiltar[i].getTel().getPszam() == tel) {
            std::cout << profiltar[i] << std::endl;
            talalat = true;
        }
    }
    if (!talalat) {
        std::cout << "Nincs talalat a(z) " << tel << " telefonszamra." << std::endl;
    }
    return talalat;
}

/// Profilok számának lekérdezése
size_t Telefonkonyv::getProfilSzam() const {
    return profilSzam;
}
