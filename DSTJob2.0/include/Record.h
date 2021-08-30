#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <string>

using namespace std;

class Record
{
    public:
        Record() = default;
        Record(string job, int hours, int minutes): m_job(job), m_hours(hours), m_minutes(minutes){}
        Record(const Record& obj)
        {
            m_job = obj.m_job;
            m_hours = obj.m_hours;
            m_minutes = obj.m_minutes;

        }
        string getJob() const;
        int getHours() const;
        int getMinutes() const;
        bool operator==(const Record& rhs);

    private:
        string m_job;
        int m_hours;
        int m_minutes;
};

#endif // RECORD_H
