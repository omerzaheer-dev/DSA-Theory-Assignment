#include <iostream>
#include <string>
using namespace std;

class Passenger {
public:
    string name;
    Passenger* next;

    Passenger(string name) {
        this->name = name;
        next = nullptr;
    }
};

class Flight {
public:
    string flightName;
    Passenger* passengers;
    Flight* nextFlight;

    Flight(string flightName) {
        this->flightName = flightName;
        passengers = nullptr;
        nextFlight = nullptr;
    }

    void reserveTicket(string name) {
        Passenger* newPassenger = new Passenger(name);
        if (!passengers || passengers->name > name) {
            newPassenger->next = passengers;
            passengers = newPassenger;
            return;
        }

        Passenger* current = passengers;
        while (current->next && current->next->name < name) {
            current = current->next;
        }

        newPassenger->next = current->next;
        current->next = newPassenger;
    }

    void cancelTicket(string name) {
        if (!passengers) {
            cout << "No passengers to cancel.\n";
            return;
        }

        if (passengers->name == name) {
            Passenger* temp = passengers;
            passengers = passengers->next;
            delete temp;
            return;
        }

        Passenger* current = passengers;
        while (current->next && current->next->name != name) {
            current = current->next;
        }

        if (current->next) {
            Passenger* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            cout << "No reservation found for " << name << ".\n";
        }
    }

    bool checkReservation(string name) {
        Passenger* current = passengers;
        while (current) {
            if (current->name == name) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void displayPassengers() {
        if (!passengers) {
            cout << "No passengers reserved.\n";
            return;
        }

        cout << "Passengers for flight " << flightName << ":\n";
        Passenger* current = passengers;
        while (current) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

class AirlineSystem {
private:
    Flight* flights;

public:
    AirlineSystem() {
        flights = nullptr;
    }

    Flight* getFlight(string flightName) {
        Flight* current = flights;
        while (current) {
            if (current->flightName == flightName) {
                return current;
            }
            current = current->nextFlight;
        }
        return nullptr;
    }

    void addFlight(string flightName) {
        Flight* newFlight = new Flight(flightName);
        newFlight->nextFlight = flights;
        flights = newFlight;
    }

    void reserveTicket(string flightName, string name) {
        Flight* flight = getFlight(flightName);
        if (!flight) {
            cout << "Flight not found.\n";
            return;
        }
        flight->reserveTicket(name);
        cout << "Ticket reserved for " << name << " on " << flightName << ".\n";
    }

    void cancelTicket(string flightName, string name) {
        Flight* flight = getFlight(flightName);
        if (!flight) {
            cout << "Flight not found.\n";
            return;
        }
        flight->cancelTicket(name);
    }

    void checkReservation(string flightName, string name) {
        Flight* flight = getFlight(flightName);
        if (!flight) {
            cout << "Flight not found.\n";
            return;
        }
        if (flight->checkReservation(name)) {
            cout << "Reservation found for " << name << " on " << flightName << ".\n";
        } else {
            cout << "No reservation found for " << name << ".\n";
        }
    }

    void displayAllFlights() {
        Flight* current = flights;
        while (current) {
            current->displayPassengers();
            current = current->nextFlight;
        }
    }
};

int main() {
    AirlineSystem system;
    system.addFlight("Flight 101");
    system.addFlight("Flight 102");

    while (true) {
        cout << "\n--- Airline Reservation System ---\n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check reservation for a passenger\n";
        cout << "4. Display all passengers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        string flightName, name;
        switch (choice) {
            case 1:
                cout << "Enter flight name: ";
                getline(cin, flightName);
                cout << "Enter passenger name: ";
                getline(cin, name);
                system.reserveTicket(flightName, name);
                break;

            case 2:
                cout << "Enter flight name: ";
                getline(cin, flightName);
                cout << "Enter passenger name: ";
                getline(cin, name);
                system.cancelTicket(flightName, name);
                break;

            case 3:
                cout << "Enter flight name: ";
                getline(cin, flightName);
                cout << "Enter passenger name: ";
                getline(cin, name);
                system.checkReservation(flightName, name);
                break;

            case 4:
                system.displayAllFlights();
                break;

            case 5:
                cout << "Exiting the system.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
