#include <iostream>
#include <string>

using namespace std;

//Задача:
//Создать базовый класс Транспорт и его дочерние классы
//Автомобиль, Такси, Трамвай, Троллейбус, Маршрутка, Электрсамокат,
//Поезд, Самолет, Велосипед.
//Создать методы для расчета времени и стоимости их Одессы в Киев

//Решение:
//Класс Transport содержит методы для расчета времени и стоимости поездки между Одессой и Киевом. 
//Метод Time() запрашивает у пользователя время отправления и прибытия, затем вычисляет и выводит общее время в пути. 
//Метод Coast() использует цену за километр и общее расстояние между городами для определения общей стоимости поездки.

class Transport 
{
protected:
    double pricePerKm;
    double distance;

public:
    Transport(double price, double dist) : pricePerKm(price), distance(dist) {}

    void Time() 
    {
        int time;
        string departureTime, arrivalTime;
        cout << "Enter departure time (HH:MM): ";
        cin >> departureTime;
        cout << "Enter arrival time (HH:MM): ";
        cin >> arrivalTime;

        int departureHour = stoi(departureTime.substr(0, 2));
        int departureMin = stoi(departureTime.substr(3, 2));
        int arrivalHour = stoi(arrivalTime.substr(0, 2));
        int arrivalMin = stoi(arrivalTime.substr(3, 2));

        int totalDepartureMinutes = departureHour * 60 + departureMin;
        int totalArrivalMinutes = arrivalHour * 60 + arrivalMin;

        time = totalArrivalMinutes - totalDepartureMinutes;

        cout << "Time in the trip: " << time / 60 << " hours " << time % 60 << " minutes" << "\n";
    }

    void Coast() 
    {
        double totalPrice = pricePerKm * distance;
        cout << "Cost of the trip: " << totalPrice << " UAH" << "\n";
    }
};

class Car : public Transport 
{
public:
    Car() : Transport(0.3, 550) {}
};

class Taxi : public Transport 
{
public:
    Taxi() : Transport(5.0, 550) {}
};

class Tramway : public Transport 
{
public:
    Tramway() : Transport(0.2, 550) {}
};

class Trolleybus : public Transport
{
public:
    Trolleybus() : Transport(0.15, 550) {}
};

class Bus : public Transport
{
public:
    Bus() : Transport(1.5, 550) {}
};

class ElectricScooter : public Transport
{
public:
    ElectricScooter() : Transport(0.03, 550) {}
};

class Train : public Transport
{
public:
    Train() : Transport(0.8, 550) {}
};

class Airplane : public Transport
{
public:
    Airplane() : Transport(2.5, 550) {}
};

class Bicycle : public Transport
{
public:
    Bicycle() : Transport(0.02, 550) {}
};


int main() {
    Car car;
    cout << "Car:" << "\n";
    car.Time();
    car.Coast();

    Taxi taxi;
    cout << "Taxi:" << "\n";
    taxi.Time();
    taxi.Coast();

    Tramway tramway;
    cout << "Tramway:" << "\n";
    tramway.Time();
    tramway.Coast();

    Trolleybus trolleybus;
    cout << "Trolleybus:" << "\n";
    trolleybus.Time();
    trolleybus.Coast();

    Bus bus;
    cout << "Bus:" << "\n";
    bus.Time();
    bus.Coast();

    ElectricScooter electricScooter;
    cout << "Electric Scooter:" << "\n";
    electricScooter.Time();
    electricScooter.Coast();

    Train train;
    cout << "Train:" << "\n";
    train.Time();
    train.Coast();
    
    Airplane airplane;
    cout << "Airplane:" << "\n";
    airplane.Time();
    airplane.Coast();
    
    Bicycle bicycle;
    cout << "Bicycle:" << "\n";
    bicycle.Time();
    bicycle.Coast();
}
