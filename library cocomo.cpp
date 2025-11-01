// cocomo_estimation.cpp
// COCOMO Estimation for Library Management System
// Author: Egzai Nayak
// Model: Basic COCOMO (Organic / Semi-Detached / Embedded)

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double kloc;             // Kilo Lines of Code (in thousands)
    string mode;             // Project mode
    double a, b, c, d;       // COCOMO coefficients

    cout << "=== Library Management System - COCOMO Estimation ===" << endl;
    cout << "Enter estimated KLOC (e.g., 10 for 10,000 lines): ";
    cin >> kloc;

    cout << "Enter project mode (organic / semi-detached / embedded): ";
    cin >> mode;

    // Convert mode to lowercase
    for (auto &ch : mode) ch = tolower(ch);

    // Assign parameters based on mode
    if (mode == "organic") {
        a = 2.4; b = 1.05; c = 2.5; d = 0.38;
    } 
    else if (mode == "semi-detached") {
        a = 3.0; b = 1.12; c = 2.5; d = 0.35;
    } 
    else if (mode == "embedded") {
        a = 3.6; b = 1.20; c = 2.5; d = 0.32;
    } 
    else {
        cout << "Invalid mode entered! Please choose from: organic, semi-detached, embedded." << endl;
        return 0;
    }

    // Calculate Effort, Development Time, and People
    double effort = a * pow(kloc, b);         // Person-Months
    double dev_time = c * pow(effort, d);     // Months
    double people = effort / dev_time;        // Average number of persons

    // Display Results
    cout << fixed << setprecision(2);
    cout << "\nCOCOMO Estimation for " << mode << " Mode\n";
    cout << "--------------------------------------------------" << endl;
    cout << "KLOC (Thousands of lines of code): " << kloc << endl;
    cout << "Effort Required (Person-Months):   " << effort << endl;
    cout << "Development Time (Months):         " << dev_time << endl;
    cout << "Average Team Size (Persons):       " << people << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "\nInterpretation:" << endl;
    cout << "Effort  -> Total manpower required for project (in person-months)" << endl;
    cout << "Time    -> Estimated development duration (in months)" << endl;
    cout << "Team    -> Average number of people needed" << endl;

    return 0;
}
