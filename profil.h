#ifndef PROFIL_H_INCLUDED
#define PROFIL_H_INCLUDED
#include "nev.h"
#include "cim.h"
#include "tel.h"
#include <iostream>

/// A Profil osztály tárolja és kezeli egy személy adatprofilját, beleértve a nevét, címét és telefonszámát.
/// Az osztály különböző konstruktorokat tartalmaz, lehetővé téve az adatok kezelését, beolvasását és kiírását.


class Profil {
private:
    Nev nev; ///< Név
    Cim cim; ///< Cím
    Tel tel; ///< Telefonszám

public:
    // Konstruktorok
    /// Alapértelmezett konstruktor.
    Profil();

    /// Konstruktor három paraméterrel (név, cím, telefonszám).
    /// @param nev A személy neve.
    /// @param cim A személy címe.
    /// @param tel A személy telefonszáma.
    Profil(const Nev& nev, const Cim& cim, const Tel& tel);


    // Getterek

    /// Visszaadja a személy nevét.
    /// @return A személy neve (Nev típusú objektum).
    Nev getNev() const;

    /// Visszaadja a személy címét.
    /// @return A személy címe (Cim típusú objektum).
    Cim getCim() const;

    /// Visszaadja a személy telefonszámát.
    /// @return A személy telefonszáma (Tel típusú objektum).
    Tel getTel() const;


};

    // Túlterheljük az << operátort
    /// Az << operátor túlterhelése, amely kiírja a személy adatprofilját.
    /// @param os A kimeneti stream, amelyre az adatprofil ki lesz írva.
    /// @param rhs A kiírandó Profil objektum.
    /// @return A módosított kimeneti stream.
    std::ostream& operator<<(std::ostream& os, const Profil& rhs);

#endif // PROFIL_H_INCLUDED
