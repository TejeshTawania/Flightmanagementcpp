#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Flight {
private:
    string flightNo, departure, destination;
    int capacity, reserved;

public:
    Flight(string flight, string dep, string des, int cap) {
        flightNo = flight;
        departure = dep;
        destination = des;
        capacity = cap;
        reserved = 0;
    }

    // Public getters to allow ReservationSystem to read data safely
    string getFlightNo() const { return flightNo; }
    string getDeparture() const { return departure; }
    string getDestination() const { return destination; }
    int getAvailableSeats() const { return capacity - reserved; }

    bool reservation() {
        if (reserved < capacity) {
            reserved++;
            return true;
        }
        return false;
    }
};

class ReservationSystem {
public:
    vector<Flight> ve;

    void add(string flight, string dep, string des, int cap) {
        Flight newflight(flight, dep, des, cap);
        ve.push_back(newflight);
    }

    void reserveSeat() {
        cout << "<<<<< Available Flights >>>>>" << endl << endl;

        for (size_t i = 0; i < ve.size(); i++) {
            cout << "Flight: " << ve[i].getFlightNo() << endl;
            cout << "Departure: " << ve[i].getDeparture() << endl;
            cout << "Destination: " << ve[i].getDestination() << endl;
            cout << "Available Seats: " << ve[i].getAvailableSeats() << endl << endl;
        }

        string fn;
        cout << "Enter Flight No: ";
        cin >> fn;

        bool found = false;

        for (size_t i = 0; i < ve.size(); i++) {
            if (fn == ve[i].getFlightNo()) {
                found = true;

                if (ve[i].reservation()) {
                    cout << "Seat reserved on flight: " << ve[i].getFlightNo() << endl;
                } else {
                    cout << "Sorry! Seats not available." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Invalid Flight Number!" << endl;
        }
    }
};

int main() {
    ReservationSystem rs;

    rs.add("F101", "UAE", "USA", 2);
    rs.add("F202", "UK", "Canada", 150);
    rs.add("F303", "UK", "UAE", 100);

    cout << "<<<<< ABC Airline >>>>>" << endl << endl;

    while (true) {
        int choice;

        cout << "Enter 1 for reserve seat" << endl;
        cout << "Enter 0 for exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        // Check if the user entered something that isn't an integer
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(1000, '\n'); // Discard the bad input buffer
            cout << "Invalid Choice! Please enter a number." << endl << endl;
            continue;
        }

        if (choice == 1) {
            #ifdef _WIN32
                system("cls"); 
            #else
                system("clear"); // Works seamlessly on Mac/Linux too!
            #endif
            rs.reserveSeat();
            cout << endl;
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Invalid Choice!" << endl << endl;
        }
    }

    return 0;
}