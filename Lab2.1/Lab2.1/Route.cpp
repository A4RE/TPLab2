#include "Route.hpp"

Route::Route() : startPoint("Не задано"), midPoint("Не задано"), endPoint("Не задано"), number(0)
{
    cout << "Вызван конструктор Route" << endl;
}

Route::Route(string startPoint, string midPoint, string endPoint, int number) :
    startPoint(startPoint), midPoint(midPoint), endPoint(endPoint), number(number)
{
    cout << "Вызван конструктор Route" << endl;
}

Route::Route(const Route& route) : startPoint(route.startPoint), midPoint(route.midPoint), endPoint(route.endPoint), number(route.number)
{
    cout << "Вызван конструктор копирования Route" << endl;
}

Route::~Route()
{
    cout << "Вызван деструктор Route" << endl;
}

void Route::inputFromConsole()
{
    cout << "Введите начальный пункт маршрута: ";
    getline(cin, startPoint);
    cout << "Введите промежуточный пункт маршрута: ";
    getline(cin, midPoint);
    cout << "Введите коенчый пункт маршрута: ";
    getline(cin, endPoint);
    cout << "Введите номер маршрута: ";
    number = safeInput(1, INT32_MAX);
}

void Route::printToConsole()
{
    cout << "Начальный пункт маршрута: " << startPoint << endl;
    cout << "Конечный пункт маршрута: " << endPoint << endl;
    cout << "Номер маршрута: " << number << endl;
}

void Route::change()
{
    cout << "Введите новый начальный пункт маршрута: ";
    getline(cin, startPoint);
    cout << "Введите новый промежуточный пункт маршрута: ";
    getline(cin, midPoint);
    cout << "Введите новый коенчый пункт маршрута: ";
    getline(cin, endPoint);
    cout << "Введите новый номер маршрута: ";
    number = safeInput(1, INT32_MAX);
}

Route& Route::operator=(const Route& route) {
    if (this == &route)
        return *this;
    startPoint = route.startPoint;
    midPoint = route.midPoint;
    endPoint = route.endPoint;
    number = route.number;
    return *this;
}

bool Route::operator>(Route& route) {
    return number > route.number;
}

bool Route::checkIntersecting(const Route& route, string& intersectingPoint) {
    if (startPoint == route.startPoint || startPoint == route.midPoint || startPoint == route.endPoint) {
        intersectingPoint = startPoint;
        return true;
    }
    else if (midPoint == route.startPoint || midPoint == route.midPoint || midPoint == route.endPoint) {
        intersectingPoint = midPoint;
        return true;
    }
    else if (endPoint == route.startPoint || endPoint == route.midPoint || endPoint == route.endPoint) {
        intersectingPoint = endPoint;
        return true;
    }
    return false;
}

