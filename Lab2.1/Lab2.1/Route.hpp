#pragma once
#include "helper.h"
#include "Marray.h"
#include <ctime>
using namespace std;

class Route
{
private:
    string startPoint, midPoint, endPoint;
    int number;
public:
    Route();
    Route(string startPoint, string midPoint, string endPoint, int number);
    Route(const Route& route);
    ~Route();

    void inputFromConsole();
    void printToConsole();
    void change();

    string getStartPoint() { return startPoint; }
    void setStartPoint(string startPoint) { this->startPoint = startPoint; }

    string getEndPoint() { return endPoint; }
    void setEndPoint(string endPoint) { this->endPoint = endPoint; }

    string getMidPoint() { return midPoint; }
    void setMidPoint(string midPoint) { this->midPoint = midPoint; }

    int getNumber() { return number; }
    void setNumber(int number) { this->number = number; }

    Route& operator=(const Route& route);
    bool operator>(Route& route);

    bool checkIntersecting(const Route& route, string& intersectingPoint);
};

