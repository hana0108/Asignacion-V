/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Class to store date and temperature
class WeatherDay {
public:
    string date;
    double temperature;

    WeatherDay(string d, double t) {
        date = d;
        temperature = t;
    }
};

// Recursive function to calculate the sum of temperatures
double recursiveSum(const vector<WeatherDay>& days, int index) {
    if (index >= days.size()) {
        return 0.0;
    }

    return days[index].temperature + recursiveSum(days, index + 1);
}

// Recursive average calculation
double recursiveAverage(const vector<WeatherDay>& days) {
    if (days.empty()) {
        return 0.0;
    }

    return recursiveSum(days, 0) / days.size();
}

int main() {
    vector<WeatherDay> weatherHistory;

    int n;

    cout << "How many days do you want to store? ";
    cin >> n;

    // Input data
    for (int i = 0; i < n; i++) {
        string date;
        double temperature;

        cout << "\nEnter date (YYYY-MM-DD): ";
        cin >> date;

        cout << "Enter temperature: ";
        cin >> temperature;

        weatherHistory.push_back(WeatherDay(date, temperature));
    }

    // Sort by temperature
    sort(weatherHistory.begin(), weatherHistory.end(),
         [](const WeatherDay& a, const WeatherDay& b) {
             return a.temperature < b.temperature;
         });

    cout << "\n--- Days Sorted by Temperature ---\n";

    for (const auto& day : weatherHistory) {
        cout << day.date << " -> "
             << day.temperature << " C" << endl;
    }

    // Search temperature by date
    string searchDate;

    cout << "\nEnter a date to search: ";
    cin >> searchDate;

    bool found = false;

    for (const auto& day : weatherHistory) {
        if (day.date == searchDate) {
            cout << "\nTemperature on "
                 << searchDate
                 << " is "
                 << day.temperature
                 << " C" << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nDate not found." << endl;
    }

    // Recursive average
    double average = recursiveAverage(weatherHistory);

    cout << fixed << setprecision(2);

    cout << "\nAverage Temperature (Recursive): "
         << average
         << " C" << endl;

    return 0;
}
