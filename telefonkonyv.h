#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED
#include "profil.h"
#include <iostream>

/// A Telefonkonyv osztály tárolja és kezeli a profilok listáját egy telefonkönyvben.
/// Az osztály lehetővé teszi a profilok hozzáadását, törlését, keresését és listázását.
/// Az adatok dinamikusan tárolódnak, és az osztály automatikusan kezeli a kapacitás növelését.

class Telefonkonyv {
private:
    Profil* profiltar; ///< Dinamikusan allokált profilok
    size_t profilSzam; ///< Jelenlegi profilok száma
    size_t kapacitas; ///< Jelenlegi kapacitás

    // Kapacitás növelése
    /// Növeli a telefonkönyv kapacitását, ha szükséges.
    /// Ha a telefonkönyv eléri a maximális kapacitást, egy új, nagyobb méretű tárolót hoz létre.
    void noveldKapacitas();

public:
    /// Alapértelmezett konstruktor, amely inicializálja a telefonkönyvet alapértelmezett értékekkel.
    Telefonkonyv(); // Konstruktor

    //Destruktor
    /// Destruktor, amely felszabadítja a dinamikusan allokált memóriát.
    ~Telefonkonyv();

    // Adatok felvétele
    void addProfil(const Profil& profil);

    // Listázás
    /// A telefonkönyvben tárolt profilok listázása a kimenetre.
    void listaz() const;

    // Adatok törlése
    /// Profil törlése a telefonkönyvből a név alapján.
    /// @param vnev A keresett személy vezetéknév része.
    /// @param knev A keresett személy keresztnév része.
    void torol(const String& vnev, const String& knev);

    // Egyszerű keresés
    /// Keresés név alapján.
    /// @param nev A keresett személy vezetéknév része.
    /// @return Igaz, ha a név megtalálható, egyébként hamis.
    bool keresNev(const String& nev) const;

    // Keresés cím alapján
    /// Keresés cím alapján.
    /// @param cim A keresett cím.
    /// @return Igaz, ha a cím megtalálható, egyébként hamis.
    bool keresCim(const String& cim) const;

    // Keresés telefonszám alapján
    /// Keresés telefonszám alapján.
    /// @param tel A keresett telefonszám.
    /// @return Igaz, ha a telefonszám megtalálható, egyébként hamis.
    bool keresTel(const String& tel) const;

    // Profilok számának lekérdezése
    /// A telefonkönyvben tárolt profilok számának lekérdezése.
    /// @return A telefonkönyvben tárolt profilok száma.
    size_t getProfilSzam() const;

};


#endif // TELEFONKONYV_H_INCLUDED
