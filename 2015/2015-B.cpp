#include <iostream>
#include <vector>
#include <string>
#include <cmath>
//#include<bits/stdc++.h>
using namespace std;

class Ship
{
public: 
     string name;
     int x;
     int y;
     int speed;

    Ship(string name, int x, int y, int speed)
    {
        this->name = name;
        this->x = x;
        this->y = y;
        this->speed = speed;
    }
};

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int xcor, ycor;
        cin >> xcor >> ycor;

        int ship_count;
        cin >> ship_count;

        vector<Ship *> ships;

        while (ship_count--)
        {
            string name;
            int xcord, ycord, speed;

            cin >> name >> xcord >> ycord >> speed;

            Ship* ship = new Ship(name, xcord, ycord, speed);

            ships.push_back(ship);
        }

        string last_name = ships[0]->name;

        double first_distance = calculateDistance(xcor, ycor, ships[0]->x, ships[0]->y);

        double last_time = first_distance / ships[0]->speed;

        for (const auto& ship : ships) 
        {
            double distance = calculateDistance(xcor, ycor, ship->x, ship->y);

            double time = distance / ship->speed;

            if (time < last_time)
            {
                last_time = time;
                last_name = ship->name;
            }
        }

        cout << last_name << endl;
    }

    return 0;
}