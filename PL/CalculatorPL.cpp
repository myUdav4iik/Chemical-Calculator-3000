#include <iostream>
using namespace std;

// Funkcja do obliczania NWD (GCD) za pomoca algorytmu Euklidesa
int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Funkcja do obliczania stosunkow i procentow dla dwoch elementow
void processTwoElements(int masa1, int liczba1, int masa2, int liczba2) {
    int totalMasa = (masa1 * liczba1) + (masa2 * liczba2);
    cout << endl << "Masa atomowa: " << totalMasa << "g" << endl;

    if (liczba2 != 0) {
        int nwd = gcd(liczba1, liczba2);
        liczba1 /= nwd;
        liczba2 /= nwd;
        cout << "Uproszczony stosunek molowy: " << liczba1 << ":" << liczba2 << endl;

        int masa1_1 = masa1 * liczba1;
        int masa2_2 = masa2 * liczba2;
        int masanwd = gcd(masa1_1, masa2_2);
        masa1_1 /= masanwd;
        masa2_2 /= masanwd;
        cout << "Uproszczony stosunek mas atomowych: " << masa1_1 << "g:" << masa2_2 << "g" << endl;

        int procent1 = (masa1 * liczba1 * 100) / totalMasa;
        cout << "Procent 1 elementu = " << procent1 << "%" << endl;
        cout << "Procent 2 elementu = " << 100 - procent1 << "%" << endl;
    }
    else {
        cout << "Blad: Nie mozna dzielic przez zero!" << endl;
    }
}

// Funkcja do obliczania stosunkow i procentow dla trzech elementow
void processThreeElements(int masa1, int liczba1, int masa2, int liczba2, int masa3, int liczba3) {
    int totalMasa = (masa1 * liczba1) + (masa2 * liczba2) + (masa3 * liczba3);
    cout << endl << "Masa atomowa: " << totalMasa << "g" << endl;

    int nwd = gcd(gcd(liczba1, liczba2), liczba3);
    liczba1 /= nwd;
    liczba2 /= nwd;
    liczba3 /= nwd;
    cout << "Uproszczony stosunek molowy: " << liczba1 << ":" << liczba2 << ":" << liczba3 << endl;

    int masa1_1 = masa1 * liczba1;
    int masa2_2 = masa2 * liczba2;
    int masa3_3 = masa3 * liczba3;

    int masanwd = gcd(gcd(masa1_1, masa2_2), masa3_3);
    masa1_1 /= masanwd;
    masa2_2 /= masanwd;
    masa3_3 /= masanwd;
    cout << "Uproszczony stosunek mas atomowych: " << masa1_1 << "g:" << masa2_2 << "g:" << masa3_3 << "g" << endl;

    int procent1 = (masa1 * liczba1 * 100) / totalMasa;
    int procent2 = (masa2 * liczba2 * 100) / totalMasa;
    cout << "Procent 1 elementu: " << procent1 << "%" << endl;
    cout << "Procent 2 elementu: " << procent2 << "%" << endl;
    cout << "Procent 3 elementu: " << 100 - (procent1 + procent2) << "%" << endl;
}

int main() {
    cout << "KALKULATOR 3000" << endl << "2 - 2 elementy" << endl << "3 - 3 elementy" << endl;
    int ile;
    cin >> ile;

    if (ile == 2) {
        int masa1, liczba1, masa2, liczba2;
		cout << "Podaj tylko liczby calkowite" << endl;
        cout << "Podaj mase atomowa 1 elementu: ";
        cin >> masa1;
        cout << "Podaj ilosc 1 elementu: ";
        cin >> liczba1;
        cout << "Podaj mase atomowa 2 elementu: ";
        cin >> masa2;
        cout << "Podaj ilosc 2 elementu: ";
        cin >> liczba2;
        processTwoElements(masa1, liczba1, masa2, liczba2);
    }
    else if (ile == 3) {
        int masa1, liczba1, masa2, liczba2, masa3, liczba3;
		cout << "Podaj tylko liczby calkowite" << endl;
        cout << "Podaj mase atomowa 1 elementu: ";
        cin >> masa1;
        cout << "Podaj ilosc 1 elementu: ";
        cin >> liczba1;
        cout << "Podaj mase atomowa 2 elementu: ";
        cin >> masa2;
        cout << "Podaj ilosc 2 elementu: ";
        cin >> liczba2;
        cout << "Podaj mase atomowa 3 elementu: ";
        cin >> masa3;
        cout << "Podaj ilosc 3 elementu: ";
        cin >> liczba3;
        processThreeElements(masa1, liczba1, masa2, liczba2, masa3, liczba3);
    }
    else {
        cout << "Nuh uh!" << endl;
    }
}
