#include "teszt.h"
#include <iostream>
#include "telefonkonyv.h"

void tesztek() {
    int teszt;
    do {
        kiir(50, '=');
        std::cout << "Valassz egy tesztet:\n \n";
        std::cout << "(1) Adatok felvetele kodban\n";
        std::cout << "(2) Adatok felvetele szabvanyos bemenetrol\n";
        std::cout << "(3) Kereses nev alapjan\n";
        std::cout << "(4) Kereses cim alapjan\n";
        std::cout << "(5) Kereses telefonszam alapjan\n";
        std::cout << "(0) Vissza a fomenube\n\n";
        kiir(50, '=');
        std::cout << "Valasztas: ";
        std::cin >> teszt;
        clearScreen();  /// Képernyõ törlése
        switch (teszt) {
            case 1:
                teszt_1();
                break;
            case 2:
                teszt_2();
                break;
            case 3:
                teszt_3();
                break;
            case 4:
                teszt_4();
                break;
            case 5:
                teszt_5();
                break;
            case 0:
                return;
            default:
                std::cout << "Ervenytelen valasz, probald ujra.\n";
                break;
        }
    } while (teszt!= 0);
}

void elso_menu(Telefonkonyv& t1) {


    /// Kérünk egy megerősítést a felhasználótól
    char megerosites;
    do {
        std::cout << "Biztosan folytatni szeretned a profil hozzaadasat? (Igen = 'y', Kilepes = '0'): ";
        std::cin >> megerosites;

        /// Ha '0', akkor kilépünk
        if (megerosites == '0') {
            clearScreen();  /// Képernyő törlése
            return;  /// Kilépés, nem történik semmilyen beolvasás
        }

        /// Ha nem 'y' válasz, akkor újra kérdezünk
        if (megerosites != 'y') {
            std::cout << "Ervenytelen valasz, kerlek probald ujra!\n";
        }

    } while (megerosites != 'y' && megerosites != '0');

    std::cin.ignore();
    Nev n = n.beolvas_nev();
    Cim c = c.beolvas_cim();
    Tel t = t.beolvas_tel();
    Profil p(n, c, t);
    t1.addProfil(p);
    clearScreen(); /// Képernyõ törlése
    std::cout << "Profil hozzaadva!" << std::endl;
}

void harmadik_menu(Telefonkonyv& t1) {
    std::cin.ignore();
    String v,k;
    t1.listaz();
    kiir(50, '=');
    std::cout << "Add meg a torolni kivant profil vezeteknevet es keresztnevet (ugyanolyan formaban):\n";
    std::cout << "(Kilepes = 0) Vezeteknev: ";
    std::cin >> v;
    if (v == "0") {
        clearScreen(); /// Képernyõ törlése
        return;
    }
    std::cout << "Keresztnev: ";
    std::cin >> k;
    clearScreen(); /// Képernyõ törlése
    t1.torol(v, k);
}

void negyedik_menu(Telefonkonyv& t1) {
    int valasz;

    String keresett;
    do{
        kiir(50, '=');
        std::cout << "Kereses alapjan:\n\n";
        std::cout << "(1) Nev\n";
        std::cout << "(2) Cim\n";
        std::cout << "(3) Telefonszam\n";
        std::cout << "(0) Kilepes\n\n";
        kiir(50, '=');
        std::cout << "Valasztas: ";
        std::cin >> valasz;
        std::cin.ignore();
        clearScreen();  /// Képernyõ törlése

        switch (valasz) {
            case 1:  /// Név alapú keresés
                std::cout << "Add meg a keresett nevet: ";
                std::cin >> keresett;
                t1.keresNev(keresett);  /// Keresés név alapján
                break;
            case 2:  /// Cím alapú keresés
                std::cout << "Add meg a keresett cimet: ";
                std::cin >> keresett;
                t1.keresCim(keresett);
                break;
            case 3:  /// Telefonszám alapú keresés
                std::cout << "Add meg a keresett telefonszamot: ";
                std::cin >> keresett;
                t1.keresTel(keresett);
                break;
            case 0:
                return;
            default:
                std::cout << "Ervenytelen valasz, kerlek probald ujra.\n";
                break;
        }
    }while (valasz != 0);
}
