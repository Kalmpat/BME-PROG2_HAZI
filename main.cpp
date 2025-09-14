/**
 * \mainpage
 *
 * # Telefonkönyv!
 *
 * Tervezze meg egy telefonkönyv alkalmazás egyszerűsített objektummodelljét, majd valósítsa azt meg! A telefonkönyvben az alábbi adatokat akarjuk tárolni:
 *
 * - név (vezetéknév, keresztnév)
 * - becenév
 * - cím
 * - munkahelyi szám
 * - privát szám
 *
 * Az alkalmazással minimum a következő műveleteket kívánjuk elvégezni:
 *
 * - adatok felvétele
 * - listázás
 * - adatok törlése
 * - egyszerű keresés
 *
 * A rendszer lehet bővebb funkcionalitású, ezért nagyon fontos, hogy jól határozom meg az objektumokat. Demonstrálom a működést külön modulként tesztprogrammal! A megoldáshoz nem használok STL tárolót!
 *
 * ## Feladatspecifikáció
 *
 * A feladat egy egyszerű elektronikus telefonkönyv alkalmazás megtervezése és megvalósítása objektumorientált rendszer alapján. Mivel a telefonkönyvben tetszőleges számú
 * bejegyzést kívánunk tárolni, az adatokat dinamikus memóriakezeléssel kezeljük.
 *
 * Az adatok szöveg és szám formátumúak. Az alkalmazás lehetővé teszi a felhasználó számára, hogy korlátlan mennyiségű adatot rögzítsen.
 *
 * Az alkalmazás lehetővé teszi a felhasználó számára az adatok felvételét, listázását, törlését, valamint a meglévő adatok keresését is. Az alkalmazás program megoldása további bővítésre is alkalmas, ezért a fejlesztés során kiemelt figyelmet fordítunk az objektumok megfelelő struktúrájára.
 *
 * A program kezeli a hibákat. Amennyiben egy művelet sikertelen, a rendszer megfelelő visszajelzést ad a felhasználó számára.
 *
 * A program tesztelésére egy külön modult készítek, amely ellenőrzi a funkciók helyes működését a közölt adatokkal, valamint a tetszőleges más által adott adatokkal is.
 *
 * ## Források
 *
 * - [Raw string literals - cppreference](https://en.cppreference.com/w/cpp/language/string_literal#Raw_string_literals) - Grafika
 * - [ASCII Art Generator](https://www.asciiart.eu/text-to-ascii-art) - Grafika
 * - [IIT BME C++ tananyag](https://infocpp.iit.bme.hu/tananyag) - C++ programozási alapok
 * - [IIT BME házi feladatok](https://infocpp.iit.bme.hu/hf_hez) - C++ házi feladatok
 * - [C++ operátorok - cppreference](https://en.cppreference.com/w/cpp/language/operators) - Operátorok ismertetése
 * - [std::all_of - cppreference](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of) - Az `all_of` algoritmus használata
 * - [std::isdigit - cppreference](https://en.cppreference.com/w/cpp/string/byte/isdigit) - Az `isdigit` függvény használata
 * - [Conio.h Wikipedia](https://en.wikipedia.org/wiki/Conio.h) - A `conio.h` könyvtár ismertetése
 * - [Cplusplus.com Reference](https://cplusplus.com/reference/) - A C++ referencia oldal
 * - [BME Aut - Snippets Doxygen Documentation](https://bmeaut.github.io/snippets/snippets/0105_Doxygen/) - Doxygen dokumentáció
 *
 * Fejlesztette: Kálmán Patrik XG5YQ1
 *
 */


#include <iostream>
#include "nev.h"
#include "cim.h"
#include "tel.h"
#include "profil.h"
#include "telefonkonyv.h"
#include "string.h"
#include "memtrace.h"
#include "gtest_lite.h"
#include "teszt.h"
#include "menuk.h"

//Források
//https://en.cppreference.com/w/cpp/language/string_literal#Raw_string_literals -->Grafika
//https://www.asciiart.eu/text-to-ascii-art --->Grafika
//https://infocpp.iit.bme.hu/tananyag
//https://infocpp.iit.bme.hu/hf_hez
//https://en.cppreference.com/w/cpp/language/operators
//https://en.cppreference.com/w/cpp/algorithm/all_any_none_of --> std::all_of
//https://en.cppreference.com/w/cpp/string/byte/isdigit  -->std::isdigit
//https://en.wikipedia.org/wiki/Conio.h
//https://cplusplus.com/reference/
//Felhasznált elemek: memtrace.h, memtrace.cpp, gtest_lite.h, string.h, string.cpp
//https://bmeaut.github.io/snippets/snippets/0105_Doxygen/




int main() {
    GTINIT(std::cin); ///< Inicializálja a tesztkörnyezetet
       std::cout << R"(
         _____    _       __             _    _   _
        |_   _|__| | ___ / _| ___  _ __ | | _(_)_(_)_ __  _   ___   __
          | |/ _ \ |/ _ \ |_ / _ \| '_ \| |/ // _ \| '_ \| | | \ \ / /
          | |  __/ |  __/  _| (_) | | | |   <| (_) | | | | |_| |\ V /
          |_|\___|_|\___|_|  \___/|_| |_|_|\_\\___/|_| |_|\__, | \_/
                                                          |___/)"
        << std::endl;
    //Memóriaszivárgás
    //int* egy = new int[12];
    //egy[0] = 1;
    Telefonkonyv t1;

    Profil p1(Nev("Kiss", "Kata", "KisKata"), Cim("Magyarorszag", "4400", "Nyiregyhaza", "Kiss Pal utca 6"), Tel("12345678910", "10987654321"));
    Profil p2(Nev("Nagy", "Noemi", "Noe"), Cim("Magyarorszag", "4025", "Debrecen", "Kossuth Lajos utca 2"), Tel("89123848510", "53566464610"));
    Profil p3(Nev("Kolos", "Vera", "Vera"), Cim("Magyarorszag", "2234", "Mogyorod", "Tep utca 4"), Tel("06295760940", "06448599209"));

    t1.addProfil(p1);
    t1.addProfil(p2);
    t1.addProfil(p3);

    int valasz;
    do {
        kiir(50, '=');
        std::cout << "Fomenu\n \n";
        std::cout << "(1) Profil hozzaadasa\n";
        std::cout << "(2) Profil listazasa\n";
        std::cout << "(3) Profil torlese\n";
        std::cout << "(4) Profil keresese\n";
        std::cout << "(5) Profilok tesztelese\n";
        std::cout << "(0) Kilepes\n\n";
        kiir(50, '=');
        std::cout << "Valasztas: ";
        if (!(std::cin >> valasz)) {
             clearScreen();
            /// Hiba esetén kilépünk a programból
            std::cout << "Bemeneti hiba vagy EOF. Kilepes...\n";
            break;
        }
        clearScreen(); /// Képernyő törlése
        switch (valasz) {
            case 1:
                elso_menu(t1);
                break;
            case 2:
                t1.listaz();
                break;
            case 3:
                harmadik_menu(t1);
                break;
            case 4:
                negyedik_menu(t1);
                break;
            case 5:
                tesztek();
                break;
            case 0:
                std::cout << "Kilepes...\n";
                break;
            default:
                std::cout << "Ervenytelen valasz, probald ujra.\n";
                break;
        }
    } while (valasz != 0);
    GTEND(std::cerr);  ///< Tesztkörnyezet befejezése
    return 0;
}


