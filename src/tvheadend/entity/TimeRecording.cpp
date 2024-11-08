/*
 *  Copyright (C) 2005-2021 Team Kodi (https://kodi.tv)
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#include "TimeRecording.h"

#include <ctime>

using namespace tvheadend::entity;

namespace
{
time_t LocaltimeToUTC(int32_t lctime)
{
  /* Note: lctime contains minutes from midnight (up to 24*60) as local time. */

  /* complete lctime with current year, month, day, ... */
  time_t t = std::time(nullptr);
  struct tm* tm_time = std::localtime(&t);

  tm_time->tm_hour = lctime / 60;
  tm_time->tm_min = lctime % 60;
  tm_time->tm_sec = 0;

  return std::mktime(tm_time);
}
} // unnamed namespace

TimeRecording::TimeRecording(const std::string& id /*= ""*/) : SeriesRecordingBase(id)
{
}

bool TimeRecording::operator==(const TimeRecording& right)
{
  return SeriesRecordingBase::operator==(right) && m_start == right.m_start &&
         m_stop == right.m_stop;
}

bool TimeRecording::operator!=(const TimeRecording& right)
{
  return !(*this == right);
}

time_t TimeRecording::GetStart() const
{
  if (m_start == int32_t(-1)) // "any time"
    return 0;

  return LocaltimeToUTC(m_start);
}

void TimeRecording::SetStart(int32_t start)
{
  m_start = start;
}

time_t TimeRecording::GetStop() const
{
  if (m_stop == int32_t(-1)) // "any time"
    return 0;

  return LocaltimeToUTC(m_stop);
}

void TimeRecording::SetStop(int32_t stop)
{
  m_stop = stop;
}
