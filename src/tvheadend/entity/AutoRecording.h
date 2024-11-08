/*
 *  Copyright (C) 2005-2021 Team Kodi (https://kodi.tv)
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "SeriesRecordingBase.h"

#include <cstdint>
#include <map>
#include <string>
#include <utility>

namespace tvheadend
{
namespace entity
{

static constexpr int AUTOREC_START_ANYTIME{-1};

class AutoRecording : public SeriesRecordingBase
{
public:
  AutoRecording(const std::string& id = "");

  bool operator==(const AutoRecording& right);
  bool operator!=(const AutoRecording& right);

  int GetStartWindowBegin() const;
  void SetStartWindowBegin(int32_t begin);

  int GetStartWindowEnd() const;
  void SetStartWindowEnd(int32_t end);

  int64_t GetMarginStart() const;
  void SetMarginStart(int64_t startExtra);

  int64_t GetMarginEnd() const;
  void SetMarginEnd(int64_t stopExtra);

  uint32_t GetDupDetect() const;
  void SetDupDetect(uint32_t dupDetect);

  bool GetFulltext() const;
  void SetFulltext(uint32_t fulltext);

  uint32_t GetBroadcastType() const;
  void SetBroadcastType(uint32_t broadcastType);

  const std::string& GetSeriesLink() const;
  void SetSeriesLink(const std::string& seriesLink);

private:
  int32_t m_startWindowBegin{
      AUTOREC_START_ANYTIME}; // Minutes from midnight (up to 24*60) for the start of the time window (including).
  int32_t m_startWindowEnd{
      AUTOREC_START_ANYTIME}; // Minutes from midnight (up to 24*60) for the end of the time window (including, cross-noon allowed)
  int64_t m_startExtra{0}; // Extra start minutes (pre-time).
  int64_t m_stopExtra{0}; // Extra stop minutes (post-time).
  uint32_t m_dupDetect{0}; // duplicate episode detect (numeric values: see dvr_autorec_dedup_t).
  uint32_t m_fulltext{0}; // Fulltext epg search.
  uint32_t m_broadcastType{0}; // Broadcast type (numeric values: see dvr_autorec_btype_t).
  std::string m_seriesLink; // Series link.
};

typedef std::map<std::string, AutoRecording> AutoRecordingsMap;
typedef std::pair<std::string, AutoRecording> AutoRecordingMapEntry;

} // namespace entity
} // namespace tvheadend
