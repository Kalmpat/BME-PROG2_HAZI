#ifndef TESZT_H_INCLUDED
#define TESZT_H_INCLUDED

/**
 * @brief Sor kiírása a képernyőre
 *
 * Ez a függvény a megadott karakterből és hosszúsággal kiír egy sort a képernyőre.
 * A függvény addig ismétli a karakter kiírását, amíg el nem éri a kívánt hosszúságot.
 *
 * @param hossz A kiírandó sor hossza.
 * @param c A kiírandó karakter.
 */

void kiir(int hossz, char c);

/**
 * @brief Képernyő törlése a megfelelő operációs rendszeren
 *
 * Ez a függvény a képernyőt törli a rendszertől függõen. Ha Windows rendszeren fut a program,
 * akkor a `cls` parancsot használja a képernyő törlésére. Ha Linux vagy Mac rendszer alatt fut,
 * akkor a `clear` parancsot hívja meg.
 *
 */

void clearScreen();

/**
 * @brief Várakozás az ENTER gomb lenyomására
 *
 * Ez a függvény üzenetet ír ki, amely felkéri a felhasználót, hogy nyomja meg az ENTER gombot
 * a folytatáshoz. Miután a felhasználó megnyomja az ENTER-t, a program folytatódik.
 *
 */

void waitForEnter();


/**
 * @brief Teszt 1: Adatok felvitele kódban
 *
 * Ez a teszt a telefonkönyv adatainak programkódból történő felvételét és törlését vizsgálja.
 * Létrehozunk néhány profil adatot, amelyeket hozzáadunk a telefonkönyvhöz, majd ellenőrizzük
 * a profilok számát. Ezután törlünk egy profilt, és ismét ellenőrizzük a profilok számát.
 *
 */

void teszt_1();

/**
 * @brief Teszt 2: Adatok felvétele szabványos bemenetről (felhasználói input)
 *
 * Ez a teszt azt vizsgálja, hogyan lehet adatokat felvenni a telefonkönyvbe a felhasználói bemenet
 * segítségével. A felhasználó meghatározza, hány profilt szeretne hozzáadni, majd a program
 * bekéri a szükséges adatokat (név, cím, telefon). A teszt végén ellenőrizzük, hogy a profilok száma
 * megfelelően megnövekedett.
 *
 */

void teszt_2();

/**
 * @brief Teszt 3: Keresés név alapján
 *
 * Ebben a tesztben a telefonkönyvben keresünk egy adott név alapján. A teszt biztosítja, hogy a
 * keresési funkció megfelelõen működjön, és a keresett profilt visszaadja. A teszt során több profilt
 * adunk hozzá, majd a keresés eredményét ellenőrizzük.
 *
 */

void teszt_3();

/**
 * @brief Teszt 4: Keresés cím alapján
 *
 * Ez a teszt a telefonkönyvben való keresést vizsgálja egy adott cím alapján.
 * A teszt során különböző címekkel rendelkezõ profilokat adunk hozzá a telefonkönyvhöz,
 * majd megpróbálunk keresni egy adott címet. A keresett profil(ok) helyességét ellenőrizzük.
 *
 */

void teszt_4();

/**
 * @brief Teszt 5: Profil keresése telefonszám alapján
 *
* Ez a teszt a telefonkönyvben való keresést vizsgálja egy adott telefonszám alapján.
 * A teszt során különböző telefonszámokkal rendelkező profilokat adunk hozzá a telefonkönyvhöz,
 * majd megpróbálunk keresni egy adott számot (munkahelyi és privát).
 * A keresett profil(ok) helyességét ellenőrizzük.
 *
 */

void teszt_5();


#endif // TESZT_H_INCLUDED
