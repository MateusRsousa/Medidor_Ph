#include "Clock.h"

void Clock::init() {}

void Clock::setDateTime(int year, int month, int day, int hour, int minute, int second) {
    struct tm t;
    t.tm_year = year - 1900; 
    t.tm_mon = month - 1;    
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = second;

    time_t timeSinceEpoch = mktime(&t);
    struct timeval now = { .tv_sec = timeSinceEpoch };
    settimeofday(&now, nullptr);
}

String Clock::getDateTime() {
    time_t now = time(nullptr);
    struct tm* t = localtime(&now);

    char buffer[20];
    // Exibe apenas dia, mês, hora, minuto e segundo
    snprintf(buffer, sizeof(buffer), "%02d/%02d %02d:%02d:%02d", 
             t->tm_mday, t->tm_mon + 1,
             t->tm_hour, t->tm_min, t->tm_sec);

    return String(buffer);
}




