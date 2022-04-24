//
// Created by sajith on 4/24/22.
//
#include "base.h"

// start ------------------------------------ > end
// t1 --------------------------------------- > t2


class UndergroundSystem
{
    unordered_map<int, pair<string, int>> checkin;
    unordered_map<string, pair<double, int>> distance;

public:
    UndergroundSystem()
    {

    }

    void checkIn(int id, string stationName, int t)
    {
        checkin[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto[start_station, tme] = checkin[id];
        string key = start_station + "->" + stationName;
        double tdiff = t - tme;
        distance[key].first += tdiff;
        distance[key].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string key = startStation + "->" + endStation;
        return distance[key].first / distance[key].second;
    }
};
