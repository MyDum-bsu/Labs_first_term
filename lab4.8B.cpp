#include <iostream>
#include "lab4.8B.h"

using namespace std;

void CinString(char *string, int size) {
    cout << "Enter your string" << endl;
    cin.getline(string, size + 1);
    cin.getline(string, size + 1);
}

bool UniqueWordDeterminant(char *begin, const char *end) {
    for (char *i = begin; i <= end; ++i) {
        for (char *j = begin; j < i; ++j) {
            if (*i == *j)
                return false;
        }
    }
    return true;
}

bool SearchWord(char *string, int n) {
    char *t_end;
    char *t_begin = string;
    char *end = string;
    char *begin = string + 1;
    for (int i = 0; i < n; ++i) {
        if (string[i] == ' ' || string[i] == '\0') {
            t_end = string + i - 1;
            if ((t_end >= t_begin) && (UniqueWordDeterminant(t_begin, t_end))) {
                end = t_end;
                begin = t_begin;
                break;
            }
            t_begin = string + i + 1;
        }
    }

    if (end >= begin) {
        for (char *i = begin; i <= end; ++i) {
            cout << *i;
        }
    } else {
        cout << "NO UNIQUE WORDS" << endl;
        return false;
    }
    return true;
}

int mainB() {
    int n;
    cout << "Enter the length of the string" << endl;
    cin >> n;
    char *string = new char[n + 1];
    CinString(string, n);
    SearchWord(string, n + 1);
    delete[] string;
    return 0;
}