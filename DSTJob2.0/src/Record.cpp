#include "Record.h"

string Record::getJob() const
{
    return m_job;
}

int Record::getHours() const
{
    return m_hours;
}

int Record::getMinutes() const
{
    return m_minutes;
}

bool Record::operator==(const Record& rhs)
{
    return ((this->m_hours == rhs.m_hours) && (this->m_job == rhs.m_job) && (this->m_minutes == rhs.m_minutes));
}
