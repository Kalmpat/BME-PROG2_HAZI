#ifndef NEV_H_INCLUDED
#define NEV_H_INCLUDED
#include <iostream>
#include "string.h"

/// A Nev osztály tárolja és kezeli egy személy nevét (vezetéknév, keresztnév, becenév).
/// A név különböző formáit (pl. teljes név) visszaadhatjuk, és az osztály
/// tartalmaz konstruktorokat, hogy a nevet különböző módokon inicializáljuk.

class Nev {
private:
    String vnev; ///< Vezetéknév
    String knev; ///< Keresztnév
    String bnev; ///< Becenév

public:
    // Konstruktorok
    /// Alapértelmezett konstruktor.
    Nev();
    ///Konstruktor három név paraméterrel (vezeték, kereszt, becenév).
    ///@param vnev A vezetéknév.
    ///@param knev A keresztnév.
    ///@param bnev A becenév.

    Nev(const String& vnev, const String& knev, const String& bnev);

    /// Konstruktor két név paraméterrel (vezeték, kereszt).
    /// @param vnev A vezetéknév.
    /// @param knev A keresztnév.
    Nev(const String& vnev, const String& knev);

    // Getterek
    /// Visszaadja a vezetéknév értékét.
    /// @return A vezetéknév.
    String getVnev() const;

    /// Visszaadja a keresztnév értékét.
    /// @return A keresztnév.
    String getKnev() const;

    /// Visszaadja a becenév értékét.
    /// @return A becenév.
    String getBnev() const;

    /// Visszaadja a teljes nevet (vezeték + keresztnév).
    /// @return A teljes név.
    String getTeljesNev() const;

    /// Név beolvasása a felhasználótól.
    /// @return A beolvasott Nev objektum.
    Nev beolvas_nev();
};

    // Túlterheljük az << operátort
    /// Az << operátor túlterhelése, amely kiírja a nevét.
    /// @param os A kimeneti stream.
    /// @param rhs A kiírandó Nev objektum.
    /// @return A módosított kimeneti stream.
    std::ostream& operator<<(std::ostream& os, const Nev& rhs);


#endif // NEV_H_INCLUDED
