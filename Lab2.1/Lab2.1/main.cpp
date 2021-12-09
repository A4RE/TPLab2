#include "Route.hpp"
#include <iostream>
#include <fstream>


using namespace std;

void printMenu();
void addObject(Marray<Route>& routes);
void changeObject(Marray<Route>& routes);
void deleteObject(Marray<Route>& routes);
void print(Marray<Route>& routes);
void searchObjects(Marray<Route>& routes);
void searchIntersecting(Marray<Route>& routes);


int main() {
   

    Marray<Route> routes;

    bool isExit = false;
    while (!isExit) {
        printMenu();
        int method = safeInput(0, 6);
        switch (method)
        {
        case 1:
            addObject(routes);
            break;
        case 2:
            changeObject(routes);
            break;
        case 3:
            deleteObject(routes);
            break;
        case 4:
            print(routes);
            break;
        case 5:
            searchObjects(routes);
            break;
        case 6:
            searchIntersecting(routes);
            break;
        case 0:
            isExit = true;
            break;
        }
    }

}

void printMenu() {
    cout << "1. Добавить объект" << endl;
    cout << "2. Изменить объект" << endl;
    cout << "3. Удалить объект" << endl;
    cout << "4. Вывести данные" << endl;
    cout << "5. Вывести маршруты, номер которого введен с клавиатуры" << endl;
    cout << "6. Вывести пересекающиеся маршруты" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберете пункт меню: ";
}

void addObject(Marray<Route>& routes) {
    Route route;
    route.inputFromConsole();
    routes += route;
    routes.sort();
}

void changeObject(Marray<Route>& routes) {
    if (routes.getSize() > 0) {
        print(routes);
        cout << "Введите номер маршрута для изменения: ";
        routes[safeInput(1, routes.getSize()) - 1].change();
    }
    else
        cout << "Список маршрутов пуст. Нечего изменять\n";
    routes.sort();
}

void deleteObject(Marray<Route>& routes) {
    if (routes.getSize() > 0) {
        print(routes);
        cout << "Введите номер маршрута для удаления: ";
        routes -= safeInput(1, routes.getSize()) - 1;
    }
    else
        cout << "Список маршрутов пуст. Нечего удалять\n";
    routes.sort();
}

void print(Marray<Route>& routes) {
    if (routes.getSize() == 0)
        cout << "Список маршрутов пуст.\n";
    else {
        cout << "Список маршрутов\n";
        for (int i = 0; i < routes.getSize(); i++) {
            cout << i + 1 << ". Маршрут\n";
            routes[i].printToConsole();
        }
    }
}

void searchObjects(Marray<Route>& routes) {
    if (routes.getSize() == 0)
        cout << "Список маршрутов пуст\n";
    else {
        bool isPrint = false;
        cout << "Введите номер маршрута: ";
        int number = safeInput(1, INT32_MAX);
        for (int i = 0; i < routes.getSize(); i++) {
            if (routes[i].getNumber() == number) {
                isPrint = true;
                routes[i].printToConsole();
            }
        }
            
        if (!isPrint)
            cout << "Таких маршрутов нет\n";
    }
}

void searchIntersecting(Marray<Route>& routes) {
    if (routes.getSize() < 2)
        cout << "Список маршрутов слишком мал для поиска пересечений\n";
    else {
        bool isPrint = false;
        for (int i = 0; i < routes.getSize(); i++)
            for (int j = i + 1; j < routes.getSize(); j++) {
                string intersectingpPoint;
                if (routes[i].checkIntersecting(routes[j], intersectingpPoint)) {
                    isPrint = true;
                    cout << "Маршруты №" << routes[i].getNumber() << " и №" << routes[j].getNumber() <<
                        " пересекаются в пункте: " << intersectingpPoint << endl;
                }
            }
        if (!isPrint)
            cout << "Пересекающихся маршрутов нет\n";
    }
}
