//
// Created by sajith on 7/11/21.
//

#include <thread>
#include <mutex>
#include <chrono>


using namespace std;

char WEEKDAYS[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Saturday"};

int today = 0;
mutex marker;