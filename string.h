#ifndef STRING_H
#define STRING_H
#include <iostream>

//Felhasználtam a laboron alkotott részeket (forrásban megjelölöm)
/// A String osztály egy egyszerű implementációja a C-sztringek (nullával lezárt karakterláncok) kezelésére.
/// Az osztály támogatja a dinamikus memória kezelést, másoló konstruktort, operátorokat és egyéb fontos műveleteket.


class String {
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
public:
/// Kiírunk egy Stringet (debug célokra)
/// Ezt a tagfüggvényt elkészítettük, hogy használja a hibák felderítéséhez.
/// Igény szerint módosítható
/// @param txt - nullával lezárt szövegre mutató pointer.
///              Ezt a szöveget írjuk ki a debug információ előtt.
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

    /// Paraméter nélküli konstruktor:
    String() :pData(0), len(0) {}

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    ///const char* c_str() const { return pData;}
     const char* c_str() const { return pData ? pData : ""; }

    /// Destruktor
    /// @brief Felszabadítja az allokált memóriát.
    ~String();

   /// C-sztringből konstruktor
   /// @param str A bemeneti C-sztring, amely alapján az objektum inicializálásra kerül.
    String(const char* str);

    /// Másoló konstruktor
    /// @param rhs A másolandó String objektum
    String(const String& rhs);

    /// Másoló operátor
    /// @param rhs A másolandó String objektum.
    /// @return A hivatkozott String objektum.
    String& operator=(const String& rhs);

    /// Összefűző operátor
    /// @param rhs A másik String objektum, amellyel össze lesz fűzve.
    /// @return Az új összefűzött String objektum.
    String operator+(const String& rhs) const;



    /// Egyenlőség operátor
    /// @param other A másik String objektum, amivel az egyenlőséget vizsgáljuk.
    /// @return Igaz, ha a két String objektum egyenlő, egyébként hamis.
    bool operator==(const String& other) const;


    /// Beolvasás
    /// @param is A bemeneti stream, amelyből beolvassuk az adatokat.
    /// @param str Az a String objektum, amelybe beírjuk a beolvasott adatokat.
    /// @return A bemeneti stream, lehetővé téve a láncolt beolvasást.
    friend std::istream& operator>>(std::istream& is, String& str);

}; /// Itt az osztály deklarációjának vége

    /// Kiíratás
    /// @param os A kimeneti stream, ahova a String kiírásra kerül.
    /// @param str A String objektum, amelyet kiírunk.
    /// @return A módosított kimeneti stream.
    std::ostream& operator<<(std::ostream& os, const String& str);

#endif
