#ifndef CIM_H_INCLUDED
#define CIM_H_INCLUDED
#include <iostream>
#include "string.h"
#include <iostream>

/// A Cim osztály tárolja és kezeli egy cím adatait, beleértve az országot, irányítószámot, várost és utcát.
/// Az osztály különböző konstruktorokat tartalmaz, és lehetővé teszi a címek különböző formájú beolvasását és kiírását.

class Cim {
private:
    String orszag;        ///< Ország
    String iranyitoszam; ///< Irányítószám
    String varos;        ///< Város
    String utca;        ///< Utca

public:
    // Konstruktorok
    /// Alapértelmezett konstruktor.
    Cim();

    /// Konstruktor a cím négy paraméterével (ország, irányítószám, város, utca).
    /// @param orszag Az ország neve.
    /// @param iranyitoszam Az irányítószám.
    /// @param varos A város neve.
    /// @param utca Az utca neve.
    Cim(const String& orszag, const String& iranyitoszam, const String& varos, const String& utca);

    // Getterek

    /// Visszaadja az országot.
    /// @return Az ország neve.
    String getOrszag() const;

    /// Visszaadja az irányítószámot.
    /// @return Az irányítószám.
    String getIranyito() const;

    /// Visszaadja a várost.
    /// @return A város neve.
    String getVaros() const;

    /// Visszaadja az utcát.
    /// @return Az utca neve.
    String getUtca() const;

    // Cím beolvasása
    /// Beolvassa a címet a felhasználótól.
    /// @return A beolvasott Cim objektum.
    Cim beolvas_cim();


};

    // Túlterheljük az << operátort
    /// Az << operátor túlterhelése, amely kiírja a cím adatait.
    /// @param os A kimeneti stream, amelyre a cím ki lesz írva.
    /// @param rhs A kiírandó Cim objektum.
    /// @return A módosított kimeneti stream.
    std::ostream& operator<<(std::ostream& os, const Cim& rhs);

#endif // CIM_H_INCLUDED
