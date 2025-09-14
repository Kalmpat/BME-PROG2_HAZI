#include <iostream>
#include "nev.h"
#include "cim.h"
#include "tel.h"
#include "profil.h"
#include "telefonkonyv.h"
#include "string.h"
#include "memtrace.h"
#include "gtest_lite.h"


void kiir(int hossz, char c) {
    for (int i = 0; i < hossz; i++) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void clearScreen() {
#ifdef _WIN32
    system("cls"); /// Windows rendszeren
#else
    system("clear"); /// Linux/Mac rendszeren
#endif
}

void waitForEnter() {
    std::cout << "Nyomj meg egy ENTER-t a folytatashoz..." << std::endl;

    fflush(stdin);  /// Kiürítjük a bemeneti puffert
    getchar();

}

///Gtest

void teszt_1() {
    TEST(Telefonkonyv, AdatokFelvetele) {
        kiir(50, '=');
        std::cout << "\n1. teszt - Adatok felvetele kodban " << std::endl;

        Telefonkonyv t1;

        /// Profilok létrehozása
        Profil p1(Nev("Kiss", "Kata", "KisKata"), Cim("Magyarorszag", "4400", "Nyiregyhaza", "Kiss Pal utca 6"), Tel("12345678910", "10987654321"));
        Profil p2(Nev("Nagy", "Noemi", "Noe"), Cim("Magyarorszag", "4025", "Debrecen", "Kossuth Lajos utca 2"), Tel("89123848510", "53566464610"));
        Profil p3(Nev("Kolos", "Vera", "Vera"), Cim("Magyarorszag", "2234", "Mogyorod", "Tep utca 4"), Tel("06295760940", "06448599209"));

        /// Profilok hozzáadása
        t1.addProfil(p1);
        t1.addProfil(p2);
        t1.addProfil(p3);

        /// Profilok számának ellenőrzése
        EXPECT_EQ(static_cast<size_t>(3), t1.getProfilSzam()) << "A profilok szama nem megfelelo!" << std::endl;

        /// Profilok listázása
        std::cout << "\nProfilok listazasa:\n";
        t1.listaz();

        kiir(50, '=');
        waitForEnter();
        clearScreen();

        kiir(50, '=');
        std::cout << "\nProfil torlese (Kiss Kata):\n";
        t1.torol("Kiss", "Kata");

        /// Profilok számának ellenőrzése törlés után
        EXPECT_EQ(static_cast<size_t>(2), t1.getProfilSzam()) << "A profilok szama nem megfelelo!" << std::endl;

        /// Profilok listázása törlés után
        std::cout << "\nProfilok listazasa:\n";
        t1.listaz();


        kiir(50, '=');
        std::cout << "Kilepes az elso tesztbol! (ENTER) \n";
        waitForEnter();
        clearScreen();
    } END
}

void teszt_2() {
    TEST(Telefonkonyv, Adatok_Felvetele_Szabvanyos_Bemenetrol) {
        kiir(50, '=');
        std::cout << "\n2. teszt - Adatok felvetele szabvanyos bemenetrol" << std::endl;

        Telefonkonyv t1;
        int profilSzam;

        /// Kérjük a felhasználót, hogy adja meg a profilok számát
        do {
            std::cout << "Hany profilt szeretnel felvenni? ";
            std::cin >> profilSzam;

            if (profilSzam <= 0) {
                std::cout << "Kerlek, adj meg egy pozitiv szamot!" << std::endl;
            }
            std::cin.ignore();
        } while (profilSzam <= 0); /// Ismételjük, amíg a szám nem pozitív

        for (int i = 0; i < profilSzam; i++) {
            std::cout << "\nProfil " << (i + 1) << ". felvetele: " << std::endl;

            /// Név beolvasása
            Nev n = n.beolvas_nev();

            /// Cím beolvasása
            Cim c = c.beolvas_cim();

            /// Telefonszám beolvasása
            Tel t = t.beolvas_tel();

            /// Profil létrehozása közvetlenül a beolvasott adatokból
            Profil profil(n, c, t);

            /// Profil hozzáadása a telefonkönyvhöz
            t1.addProfil(profil);
        }

        /// Profilok számának ellenõrzése
        EXPECT_EQ(static_cast<size_t>(profilSzam), t1.getProfilSzam()) << "A profilok szama nem megfelelo!" << std::endl;

        /// Profilok listázása
        std::cout << "\nProfilok listazasa:\n";
        t1.listaz();

        kiir(50, '=');
        std::cout << "Kilepes a masodik tesztbol! (ENTER)\n";
        waitForEnter();
        clearScreen();
    } END
}

void teszt_3() {
    TEST(Telefonkonyv, Kereses_Nev_Alapjan) {
        kiir(50, '=');
        std::cout << "\n3. teszt - Kereses (nev)" << std::endl;

        Telefonkonyv t1;
        /// Profilok hozzáadása
        Profil p1(Nev("Kiss", "Kata", "KisKata"), Cim("Magyarorszag", "4400", "Nyiregyhaza", "Kiss Pal utca 6"), Tel("12345678910", "98765432110"));
        Profil p2(Nev("Nagy", "Noemi", "Noe"), Cim("Nemetorszag", "4025", "Debrecen", "Kossuth Lajos utca 2"), Tel("89123848510", "53566464610"));
        Profil p3(Nev("Kolos", "Vera", "Vera"), Cim("Magyarorszag", "2234", "Mogyorod", "Tep utca 4"), Tel("06295760940", "06448599209"));

        t1.addProfil(p1);
        t1.addProfil(p2);
        t1.addProfil(p3);

        /// Keresés név alapján

        /// Teljes név alapján
        std::cout << "Kereses teljes nev alapjan (Kiss Kata):\n";
        EXPECT_TRUE(t1.keresNev("Kiss Kata")) << "A kereses nem talalta meg a teljes nevet!";

        /// Vezetéknév alapján
        std::cout << "Kereses vezeteknev alapjan (Kiss):\n";
        EXPECT_TRUE(t1.keresNev("Kiss")) << "A kereses nem talalta meg a vezeteknevet!";

        /// Keresztnév alapján
        std::cout << "Kereses keresztnev alapjan (Noemi):\n";
        EXPECT_TRUE(t1.keresNev("Noemi")) << "A kereses nem talalta meg a keresztnevet!";

        /// Becenév alapján
        std::cout << "Kereses becenev alapjan (Vera):\n";
        EXPECT_TRUE(t1.keresNev("Vera")) << "A kereses nem talalta meg a becenevet!";

        /// Keresés nem létezõ név alapján
        std::cout << "Kereses nem letezo nev alapjan (Nem letezo Nev):\n";
        EXPECT_FALSE(t1.keresNev("Anna")) << "A kereses nem vart talalatot adott a nem letezo nev alapjan!";

        ///Keresés a törölt profil alapján
        ///Profil törlése
        std::cout << "\nProfil torlese (Kiss Kata):\n";
        t1.torol("Kiss", "Kata");
        std::cout << "Kereses nev alapjan (Kiss) torles utan:\n";
        EXPECT_FALSE(t1.keresNev("Kiss")) << "A kereses nem vart talalatot adott a torles utan!";

        kiir(50, '=');
        std::cout << "Kilepes a harmadik tesztbol! (ENTER)\n";
        waitForEnter();
        clearScreen();
    } END
}

void teszt_4() {
    TEST(Telefonkonyv, Kereses_Cim_Alapjan) {
        kiir(50, '=');
        std::cout << "\n4. teszt - Kereses (cim)" << std::endl;

        Telefonkonyv t1;
        /// Profilok hozzáadása
        Profil p1(Nev("Kiss", "Kata", "KisKata"), Cim("Magyarorszag", "4400", "Nyiregyhaza", "Kiss Pal utca 6"), Tel("12345678910", "98765432110"));
        Profil p2(Nev("Nagy", "Noemi", "Noe"), Cim("Nemetorszag", "4025", "Debrecen", "Kossuth Lajos utca 2"), Tel("89123848510", "53566464610"));
        Profil p3(Nev("Kolos", "Vera", "Vera"), Cim("Magyarorszag", "2234", "Mogyorod", "Tep utca 4"), Tel("06295760940", "06448599209"));

        t1.addProfil(p1);
        t1.addProfil(p2);
        t1.addProfil(p3);

        /// Keresés cím alapján

        /// Utca alapján
        std::cout << "Kereses utca alapjan (Kossuth Lajos utca 2):\n";
        EXPECT_TRUE(t1.keresCim("Kossuth Lajos utca 2")) << "A kereses nem talalta meg a cimet!";

        /// Irányítószám alapján
        std::cout << "Kereses iranyitoszam alapjan (4400):\n";
        EXPECT_TRUE(t1.keresCim("4400")) << "A kereses nem talalta meg az iranyitoszamot!";

        /// Ország alapján
        std::cout << "Kereses orszag alapjan (Nemetorszag):\n";
        EXPECT_TRUE(t1.keresCim("Nemetorszag")) << "A kereses nem talalta meg az orszagot!";

        /// Város alapján
        std::cout << "Kereses varos alapjan (Mogyorod):\n";
        EXPECT_TRUE(t1.keresCim("Mogyorod")) << "A kereses nem talalta meg a varost!";

        /// Keresés nem létezõ cím alapján
        std::cout << "Kereses nem letezo cim alapjan (Koranthy Frigyes utca 8):\n";
        EXPECT_FALSE(t1.keresCim("Koranthy Frigyes utca 8")) << "A kereses nem vart talalatot adott a nem letezo cim alapjan!";

        kiir(50, '=');
        std::cout << "Kilepes a negyedik tesztbol! (ENTER)\n";
        waitForEnter();
        clearScreen();
    } END
}

void teszt_5() {
    TEST(Telefonkonyv, Kereses_Tel_Alapjan) {
        kiir(50, '=');
        std::cout << "\n5. teszt - Kereses (tel)" << std::endl;

        Telefonkonyv t1;
        /// Profilok hozzáadása
        Profil p1(Nev("Kiss", "Kata", "KisKata"), Cim("Magyarorszag", "4400", "Nyiregyhaza", "Kiss Pal utca 6"), Tel("12345678910", "98765432110"));
        Profil p2(Nev("Nagy", "Noemi", "Noe"), Cim("Nemetorszag", "4025", "Debrecen", "Kossuth Lajos utca 2"), Tel("89123848510", "53566464610"));
        Profil p3(Nev("Kolos", "Vera", "Vera"), Cim("Magyarorszag", "2234", "Mogyorod", "Tep utca 4"), Tel("06295760940", "06448599209"));

        t1.addProfil(p1);
        t1.addProfil(p2);
        t1.addProfil(p3);

        /// Keresés telefonszám alapján

        /// Munkahelyi telefonszám alapján
        std::cout << "Kereses munkahelyi telefonszam alapjan (12345678910):\n";
        EXPECT_TRUE(t1.keresTel("12345678910")) << "A kereses nem talalta meg a munkahelyi telefonszamot!";

        /// Privát telefonszám alapján
        std::cout << "Kereses privat telefonszam alapjan (06448599209):\n";
        EXPECT_TRUE(t1.keresTel("06448599209")) << "A kereses nem talalta meg a privat telefonszamot!";

        /// Keresés nem létezõ telefonszám alapján
        std::cout << "Kereses nem letezo telefonszam alapjan (00000000000):\n";
        EXPECT_FALSE(t1.keresTel("00000000000")) << "A kereses nem vart talalatot adott a nem letezo telefonszam alapjan!";

        kiir(50, '=');

        std::cout << "Kilepes az otodik tesztbol! (ENTER)\n";
        waitForEnter();
        clearScreen();
    } END
}
