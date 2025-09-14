#ifndef TEL_H_INCLUDED
#define TEL_H_INCLUDED
#include "string.h"
#include <iostream>

/// A Tel osztály tárolja és kezeli egy személy telefonszámadatait, beleértve a munkahelyi és a privát telefonszámot.
/// Az osztály különböző konstruktorokat tartalmaz, lehetővé téve a telefonszámok kezelését, beolvasását és kiírását.

class Tel {
private:
    String mszam; ///< Munkahelyi szám
    String pszam; ///< Privát szám

public:
    // Konstruktorok
    /// Alapértelmezett konstruktor.
    Tel();

    /// Konstruktor két telefonszám paraméterrel (munkahelyi, privát).
    /// @param mszam A munkahelyi telefonszám.
    /// @param pszam A privát telefonszám.
    Tel(const String& mszam, const String& pszam);

    // Getterek

    /// Visszaadja a munkahelyi telefonszámot.
    /// @return A munkahelyi telefonszám.
    String getMszam() const;

    /// Visszaadja a privát telefonszámot.
    /// @return A privát telefonszám.
    String getPszam() const;


    // Telefonszám beolvasása
    /// Beolvassa a telefonszámokat a felhasználótól.
    /// @return A beolvasott Tel objektum.
    Tel beolvas_tel();


};

    // Túlterheljük az << operátort
    /// Az << operátor túlterhelése, amely kiírja a telefonszámokat.
    /// @param os A kimeneti stream, amelyre a telefonszámok ki lesznek írva.
    /// @param rhs A kiírandó Tel objektum.
    /// @return A módosított kimeneti stream.
    std::ostream& operator<<(std::ostream& os, const Tel& rhs);


#endif // TEL_H_INCLUDED
