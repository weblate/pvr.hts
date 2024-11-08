/*
 *  Copyright (C) 2024 Team Kodi (https://kodi.tv)
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#include "SeriesRecordingBase.h"

using namespace tvheadend::entity;

SeriesRecordingBase::SeriesRecordingBase(const std::string& id /*= ""*/) : m_sid(id)
{
  m_id = GetNextIntId();
}

// static
unsigned int SeriesRecordingBase::GetNextIntId()
{
  static unsigned int intId = 0;
  return ++intId;
}
