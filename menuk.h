#ifndef MENUK_H_INCLUDED
#define MENUK_H_INCLUDED
/**
 * @brief Tesztelési menü
 *
 * Ez a függvény a tesztelési menüt jeleníti meg a felhasználónak, lehetővé teszi számára,
 * hogy különbözó teszteket futtasson, például profilok hozzáadása, törlése, keresése.
 * A tesztelési funkciók közé tartozik:
 * - Adatok felvétele kódból
 * - Adatok felvétele szabványos bemenetről
 * - Profilok keresése név, cím, vagy telefonszám alapján.
 */
void tesztek();

/**
 * @brief Profil hozzáadása a telefonkönyvhöz
 *
 * Ez a függvény lehetõvé teszi egy új profil hozzáadását a telefonkönyvhöz. A profil
 * hozzáadása elõtt a felhasználónak meg kell adnia a szükséges adatokat, mint például
 * a nevet, címet és telefonszámot. Ha a felhasználó folytatni szeretné, akkor a program
 * elvégzi a szükséges adatbeolvasásokat és hozzáadja az új profilt a telefonkönyvhöz.
 *
 * @param t1 A Telefonkonyv objektum, amelyhez a profilokat hozzáadjuk.
 */

void elso_menu(Telefonkonyv& t1);

/**
 * @brief Profil törlése a telefonkönyvbõl
 *
 * Ez a függvény lehetővé teszi a profilok törlését a telefonkönyvből. A felhasználó
 * megad egy nevet, és a program törli a hozzá tartozó profilt a telefonkönyvből.
 *
 * @param t1 A Telefonkonyv objektum, amelyből a profilokat töröljük.
 */

void harmadik_menu(Telefonkonyv& t1);

/**
 * @brief Keresés a telefonkönyvben
 *
 * Ez a függvény a telefonkönyvben történő keresést valósítja meg. A felhasználó
 * megadhatja a keresett adatot (például nevet, címet, telefonszámot), és a program visszaadja
 * a megfelelõ profilokat a telefonkönyvbõl.
 *
 * @param t1 A Telefonkonyv objektum, amelyben keresünk.
 */

void negyedik_menu(Telefonkonyv& t1);

#endif // MENUK_H_INCLUDED
