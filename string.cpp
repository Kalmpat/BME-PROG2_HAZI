#include <iostream>
#include <cstring>
#include "memtrace.h"
#include "string.h"

/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)

String::String(const char* str) {
    len = strlen(str);
    pData = new char[len + 1];
    strcpy(pData, str);
    pData[len]=0;
}

/// Másoló konstruktor: String-ből készít (createString)

String::String(const String& rhs) {
    if (rhs.pData) {
        len = rhs.len;
        pData = new char[len + 1];
        strcpy(pData, rhs.pData);
    } else {
        len = 0;
        pData = nullptr;
    }
}


/// Destruktor (disposeString)

String::~String() {
    delete[] pData;
}

/// operator=
String& String::operator=(const String& rhs) {
    if (this != &rhs) {
        delete[] pData;

        if (rhs.pData) {
            len = rhs.len;
            pData = new char[len + 1];
            strcpy(pData, rhs.pData);
        } else {
            len = 0;
            pData = nullptr;
        }
    }
    return *this;
}


/// + operátorok:
///                 String-hez String-et ad (addString)

String String::operator+(const String& rhs) const {
    size_t ujLen = len + rhs.len;
    char* ujData = new char[ujLen + 1];
    strcpy(ujData, pData);
    strcat(ujData, rhs.pData);
    String eredmeny(ujData);
    delete[] ujData;
    return eredmeny;
}


/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.c_str();
    return os;
}

/// Egyenlőség operátor
bool String::operator==(const String& other) const {
    if (len != other.len) return false;
    return strcmp(pData, other.pData) == 0;
}

/// >> operator, kiíratás
std::istream& operator>>(std::istream& is, String& str) {
    delete[] str.pData;
    str.pData = nullptr;
    str.len = 0;

    char* temp = nullptr;
    char ch;
    size_t index = 0;

    while (is.get(ch) && ch != '\n') {
        char* newTemp = new char[index + 2];
        if (temp) {
            memcpy(newTemp, temp, index);
            delete[] temp;
        }
        newTemp[index] = ch;
        newTemp[index + 1] = '\0';
        temp = newTemp;
        index++;
    }
    str.len = index;
    str.pData = temp;
    return is;
}



