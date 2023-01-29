#pragma once

#include <ctime>
#include <iostream>

using namespace std;

class Timer final {

public:
    explicit Timer(const char* name);
    ~Timer();

private:
    const char* m_Name;
    clock_t m_Begin;
};


#define MEASURE_CODE(name, ...) Timer timer##__LINE__(name);
#define MEASURE_FUNC() MEASURE_CODE(__FUNCSIG__)