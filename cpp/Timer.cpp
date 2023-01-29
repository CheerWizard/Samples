#include "../include/Timer.h"

Timer::Timer(const char *name) : m_Name(name) {
    m_Begin = clock();
}

Timer::~Timer() {
    clock_t end = clock();
    auto dt = (float)(end - m_Begin);
    cout << m_Name << " took " << dt << " ms." << endl;
}