#include <iostream>
#include "lab4.8A.h"

using namespace std;

void CinString(char *string) {
    int n;
    cout << "Enter the length of the string" << endl;
    cin >> n;
    cout << "Enter your string" << endl;
    for (int i = 0; i < n; ++i)
        cin >> string[i];
}

char *strrchr1(char *string, int symbol) {
    int i;
    for (i = 0; string[i] != '\0'; i++) {}
    for (int j = i - 1; j >= 0; j--) {
        if (string[j] == symbol) {
            return (string + j);
        }
        if (string[j] != symbol && j == 0) return nullptr;
    }

}

int mainA() {
    char *string;
    CinString(string);
    char symbol;
    cout << "Enter the symbol to search for" << endl;
    cin >> symbol;
    cout << strrchr1(string, symbol)[0];
    return 0;
}