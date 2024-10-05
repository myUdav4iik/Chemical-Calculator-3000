#include <iostream>
using namespace std;

// Function to calculate GCD using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Function to calculate ratios and percentages for two elements
void processTwoElements(int mass1, int count1, int mass2, int count2) {
    int totalMass = (mass1 * count1) + (mass2 * count2);
    cout << endl << "Atomic mass: " << totalMass << "g" << endl;

    if (count2 != 0) {
        int nwd = gcd(count1, count2);
        count1 /= nwd;
        count2 /= nwd;
        cout << "Simplified molar ratio: " << count1 << ":" << count2 << endl;

        int mass1_1 = mass1 * count1;
        int mass2_2 = mass2 * count2;
        int massGcd = gcd(mass1_1, mass2_2);
        mass1_1 /= massGcd;
        mass2_2 /= massGcd;
        cout << "Simplified atomic mass ratio: " << mass1_1 << "g:" << mass2_2 << "g" << endl;

        int percent1 = (mass1 * count1 * 100) / totalMass;
        cout << "Percentage of element 1 = " << percent1 << "%" << endl;
        cout << "Percentage of element 2 = " << 100 - percent1 << "%" << endl;
    }
    else {
        cout << "Error: Division by zero is not allowed!" << endl;
    }
}

// Function to calculate ratios and percentages for three elements
void processThreeElements(int mass1, int count1, int mass2, int count2, int mass3, int count3) {
    int totalMass = (mass1 * count1) + (mass2 * count2) + (mass3 * count3);
    cout << endl << "Atomic mass: " << totalMass << "g" << endl;

    int nwd = gcd(gcd(count1, count2), count3);
    count1 /= nwd;
    count2 /= nwd;
    count3 /= nwd;
    cout << "Simplified molar ratio: " << count1 << ":" << count2 << ":" << count3 << endl;

    int mass1_1 = mass1 * count1;
    int mass2_2 = mass2 * count2;
    int mass3_3 = mass3 * count3;

    int massGcd = gcd(gcd(mass1_1, mass2_2), mass3_3);
    mass1_1 /= massGcd;
    mass2_2 /= massGcd;
    mass3_3 /= massGcd;
    cout << "Simplified atomic mass ratio: " << mass1_1 << "g:" << mass2_2 << "g:" << mass3_3 << "g" << endl;

    int percent1 = (mass1 * count1 * 100) / totalMass;
    int percent2 = (mass2 * count2 * 100) / totalMass;
    cout << "Percentage of element 1: " << percent1 << "%" << endl;
    cout << "Percentage of element 2: " << percent2 << "%" << endl;
    cout << "Percentage of element 3: " << 100 - (percent1 + percent2) << "%" << endl;
}

int main() {
    cout << "CALCULATOR 3000" << endl << "2 - 2 elements" << endl << "3 - 3 elements" << endl;
    int count;
    cin >> count;

    if (count == 2) {
        int mass1, count1, mass2, count2;
        cout << "Enter only integer numbers" << endl;
        cout << "Enter atomic mass of element 1: ";
        cin >> mass1;
        cout << "Enter amount of element 1: ";
        cin >> count1;
        cout << "Enter atomic mass of element 2: ";
        cin >> mass2;
        cout << "Enter amount of element 2: ";
        cin >> count2;
        processTwoElements(mass1, count1, mass2, count2);
    }
    else if (count == 3) {
        cout << "Enter only integer numbers" << endl;
        int mass1, count1, mass2, count2, mass3, count3;
        cout << "Enter atomic mass of element 1: ";
        cin >> mass1;
        cout << "Enter amount of element 1: ";
        cin >> count1;
        cout << "Enter atomic mass of element 2: ";
        cin >> mass2;
        cout << "Enter amount of element 2: ";
        cin >> count2;
        cout << "Enter atomic mass of element 3: ";
        cin >> mass3;
        cout << "Enter amount of element 3: ";
        cin >> count3;
        processThreeElements(mass1, count1, mass2, count2, mass3, count3);
    }
    else {
        cout << "Invalid input!" << endl;
    }
}
