/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "../../AddonBase.h"
#include "pvr/pvr_channel_groups.h"
#include "pvr/pvr_channels.h"
#include "pvr/pvr_defines.h"
#include "pvr/pvr_edl.h"
#include "pvr/pvr_epg.h"
#include "pvr/pvr_general.h"
#include "pvr/pvr_menu_hook.h"
#include "pvr/pvr_recordings.h"
#include "pvr/pvr_stream.h"
#include "pvr/pvr_timers.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

  /*!
   * @brief Structure to define typical standard values
   */
  typedef struct AddonProperties_PVR
  {
    const char* strUserPath;
    const char* strClientPath;
    int iEpgMaxDays;
  } AddonProperties_PVR;

  /*!
   * @brief Structure to transfer the methods from Kodi to addon
   */
  typedef struct AddonToKodiFuncTable_PVR
  {
    // Pointer inside Kodi where used from him to find his class
    KODI_HANDLE kodiInstance;

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // General callback functions
    void (*AddMenuHook)(void* kodiInstance, struct PVR_MENUHOOK* hook);
    void (*Recording)(void* kodiInstance, const char* Name, const char* FileName, bool On);
    void (*ConnectionStateChange)(void* kodiInstance,
                                  const char* strConnectionString,
                                  enum PVR_CONNECTION_STATE newState,
                                  const char* strMessage);
    void (*EpgEventStateChange)(void* kodiInstance,
                                struct EPG_TAG* tag,
                                enum EPG_EVENT_STATE newState);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Transfer functions where give data back to Kodi, e.g. GetChannels calls TransferChannelEntry
    void (*TransferChannelEntry)(void* kodiInstance,
                                 const ADDON_HANDLE handle,
                                 const struct PVR_CHANNEL* chan);
    void (*TransferChannelGroup)(void* kodiInstance,
                                 const ADDON_HANDLE handle,
                                 const struct PVR_CHANNEL_GROUP* group);
    void (*TransferChannelGroupMember)(void* kodiInstance,
                                       const ADDON_HANDLE handle,
                                       const struct PVR_CHANNEL_GROUP_MEMBER* member);
    void (*TransferEpgEntry)(void* kodiInstance,
                             const ADDON_HANDLE handle,
                             const struct EPG_TAG* epgentry);
    void (*TransferRecordingEntry)(void* kodiInstance,
                                   const ADDON_HANDLE handle,
                                   const struct PVR_RECORDING* recording);
    void (*TransferTimerEntry)(void* kodiInstance,
                               const ADDON_HANDLE handle,
                               const struct PVR_TIMER* timer);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Kodi inform interface functions
    void (*TriggerChannelUpdate)(void* kodiInstance);
    void (*TriggerChannelGroupsUpdate)(void* kodiInstance);
    void (*TriggerEpgUpdate)(void* kodiInstance, unsigned int iChannelUid);
    void (*TriggerRecordingUpdate)(void* kodiInstance);
    void (*TriggerTimerUpdate)(void* kodiInstance);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Stream demux interface functions
    void (*FreeDemuxPacket)(void* kodiInstance, struct DemuxPacket* pPacket);
    struct DemuxPacket* (*AllocateDemuxPacket)(void* kodiInstance, int iDataSize);
    struct PVR_CODEC (*GetCodecByName)(const void* kodiInstance, const char* strCodecName);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // New functions becomes added below and can be on another API change (where
    // breaks min API version) moved up.
  } AddonToKodiFuncTable_PVR;

  /*!
   * @brief Structure to transfer the methods from addon to Kodi
   */
  typedef struct KodiToAddonFuncTable_PVR
  {
    // Pointer inside addon where used on them to find his instance class (currently unused!)
    KODI_HANDLE addonInstance;

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // General interface functions
    enum PVR_ERROR(__cdecl* GetCapabilities)(const struct AddonInstance_PVR*,
                                             struct PVR_ADDON_CAPABILITIES*);
    const char*(__cdecl* GetBackendName)(const struct AddonInstance_PVR*);
    const char*(__cdecl* GetBackendVersion)(const struct AddonInstance_PVR*);
    const char*(__cdecl* GetBackendHostname)(const struct AddonInstance_PVR*);
    const char*(__cdecl* GetConnectionString)(const struct AddonInstance_PVR*);
    enum PVR_ERROR(__cdecl* GetDriveSpace)(const struct AddonInstance_PVR*, uint64_t*, uint64_t*);
    enum PVR_ERROR(__cdecl* CallSettingsMenuHook)(const struct AddonInstance_PVR*,
                                                  const struct PVR_MENUHOOK*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Channel interface functions

    int(__cdecl* GetChannelsAmount)(const struct AddonInstance_PVR*);
    enum PVR_ERROR(__cdecl* GetChannels)(const struct AddonInstance_PVR*, ADDON_HANDLE, bool);
    enum PVR_ERROR(__cdecl* GetChannelStreamProperties)(const struct AddonInstance_PVR*,
                                                        const struct PVR_CHANNEL*,
                                                        struct PVR_NAMED_VALUE*,
                                                        unsigned int*);
    enum PVR_ERROR(__cdecl* GetSignalStatus)(const struct AddonInstance_PVR*,
                                             int,
                                             struct PVR_SIGNAL_STATUS*);
    enum PVR_ERROR(__cdecl* GetDescrambleInfo)(const struct AddonInstance_PVR*,
                                               int,
                                               struct PVR_DESCRAMBLE_INFO*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Channel group interface functions
    int(__cdecl* GetChannelGroupsAmount)(const struct AddonInstance_PVR*);
    enum PVR_ERROR(__cdecl* GetChannelGroups)(const struct AddonInstance_PVR*, ADDON_HANDLE, bool);
    enum PVR_ERROR(__cdecl* GetChannelGroupMembers)(const struct AddonInstance_PVR*,
                                                    ADDON_HANDLE,
                                                    const struct PVR_CHANNEL_GROUP*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Channel edit interface functions
    enum PVR_ERROR(__cdecl* DeleteChannel)(const struct AddonInstance_PVR*,
                                           const struct PVR_CHANNEL*);
    enum PVR_ERROR(__cdecl* RenameChannel)(const struct AddonInstance_PVR*,
                                           const struct PVR_CHANNEL*);
    enum PVR_ERROR(__cdecl* OpenDialogChannelSettings)(const struct AddonInstance_PVR*,
                                                       const struct PVR_CHANNEL*);
    enum PVR_ERROR(__cdecl* OpenDialogChannelAdd)(const struct AddonInstance_PVR*,
                                                  const struct PVR_CHANNEL*);
    enum PVR_ERROR(__cdecl* OpenDialogChannelScan)(const struct AddonInstance_PVR*);
    enum PVR_ERROR(__cdecl* CallChannelMenuHook)(const struct AddonInstance_PVR*,
                                                 const PVR_MENUHOOK*,
                                                 const PVR_CHANNEL*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // EPG interface functions
    enum PVR_ERROR(__cdecl* GetEPGForChannel)(
        const struct AddonInstance_PVR*, ADDON_HANDLE, int, time_t, time_t);
    enum PVR_ERROR(__cdecl* IsEPGTagRecordable)(const struct AddonInstance_PVR*,
                                                const struct EPG_TAG*,
                                                bool*);
    enum PVR_ERROR(__cdecl* IsEPGTagPlayable)(const struct AddonInstance_PVR*,
                                              const struct EPG_TAG*,
                                              bool*);
    enum PVR_ERROR(__cdecl* GetEPGTagEdl)(const struct AddonInstance_PVR*,
                                          const struct EPG_TAG*,
                                          struct PVR_EDL_ENTRY[],
                                          int*);
    enum PVR_ERROR(__cdecl* GetEPGTagStreamProperties)(const struct AddonInstance_PVR*,
                                                       const struct EPG_TAG*,
                                                       struct PVR_NAMED_VALUE*,
                                                       unsigned int*);
    enum PVR_ERROR(__cdecl* SetEPGTimeFrame)(const struct AddonInstance_PVR*, int);
    enum PVR_ERROR(__cdecl* CallEPGMenuHook)(const struct AddonInstance_PVR*,
                                             const struct PVR_MENUHOOK*,
                                             const struct EPG_TAG*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Recording interface functions
    int(__cdecl* GetRecordingsAmount)(const struct AddonInstance_PVR*, bool);
    enum PVR_ERROR(__cdecl* GetRecordings)(const struct AddonInstance_PVR*, ADDON_HANDLE, bool);
    enum PVR_ERROR(__cdecl* DeleteRecording)(const struct AddonInstance_PVR*,
                                             const struct PVR_RECORDING*);
    enum PVR_ERROR(__cdecl* UndeleteRecording)(const struct AddonInstance_PVR*,
                                               const struct PVR_RECORDING*);
    enum PVR_ERROR(__cdecl* DeleteAllRecordingsFromTrash)(const struct AddonInstance_PVR*);
    enum PVR_ERROR(__cdecl* RenameRecording)(const struct AddonInstance_PVR*,
                                             const struct PVR_RECORDING*);
    enum PVR_ERROR(__cdecl* SetRecordingLifetime)(const struct AddonInstance_PVR*,
                                                  const struct PVR_RECORDING*);
    enum PVR_ERROR(__cdecl* SetRecordingPlayCount)(const struct AddonInstance_PVR*,
                                                   const struct PVR_RECORDING*,
                                                   int);
    enum PVR_ERROR(__cdecl* SetRecordingLastPlayedPosition)(const struct AddonInstance_PVR*,
                                                            const struct PVR_RECORDING*,
                                                            int);
    int(__cdecl* GetRecordingLastPlayedPosition)(const struct AddonInstance_PVR*,
                                                 const struct PVR_RECORDING*);
    enum PVR_ERROR(__cdecl* GetRecordingEdl)(const struct AddonInstance_PVR*,
                                             const struct PVR_RECORDING*,
                                             struct PVR_EDL_ENTRY[],
                                             int*);
    enum PVR_ERROR(__cdecl* GetRecordingSize)(const struct AddonInstance_PVR*,
                                              const PVR_RECORDING*,
                                              int64_t*);
    enum PVR_ERROR(__cdecl* GetRecordingStreamProperties)(const struct AddonInstance_PVR*,
                                                          const struct PVR_RECORDING*,
                                                          struct PVR_NAMED_VALUE*,
                                                          unsigned int*);
    enum PVR_ERROR(__cdecl* CallRecordingMenuHook)(const struct AddonInstance_PVR*,
                                                   const struct PVR_MENUHOOK*,
                                                   const struct PVR_RECORDING*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Timer interface functions
    enum PVR_ERROR(__cdecl* GetTimerTypes)(const struct AddonInstance_PVR*,
                                           struct PVR_TIMER_TYPE[],
                                           int*);
    int(__cdecl* GetTimersAmount)(const struct AddonInstance_PVR*);
    enum PVR_ERROR(__cdecl* GetTimers)(const struct AddonInstance_PVR*, ADDON_HANDLE);
    enum PVR_ERROR(__cdecl* AddTimer)(const struct AddonInstance_PVR*, const struct PVR_TIMER*);
    enum PVR_ERROR(__cdecl* DeleteTimer)(const struct AddonInstance_PVR*,
                                         const struct PVR_TIMER*,
                                         bool);
    enum PVR_ERROR(__cdecl* UpdateTimer)(const struct AddonInstance_PVR*, const struct PVR_TIMER*);
    enum PVR_ERROR(__cdecl* CallTimerMenuHook)(const struct AddonInstance_PVR*,
                                               const struct PVR_MENUHOOK*,
                                               const struct PVR_TIMER*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Powersaving interface functions
    void(__cdecl* OnSystemSleep)(const struct AddonInstance_PVR*);
    void(__cdecl* OnSystemWake)(const struct AddonInstance_PVR*);
    void(__cdecl* OnPowerSavingActivated)(const struct AddonInstance_PVR*);
    void(__cdecl* OnPowerSavingDeactivated)(const struct AddonInstance_PVR*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Live stream read interface functions
    bool(__cdecl* OpenLiveStream)(const struct AddonInstance_PVR*, const struct PVR_CHANNEL*);
    void(__cdecl* CloseLiveStream)(const struct AddonInstance_PVR*);
    int(__cdecl* ReadLiveStream)(const struct AddonInstance_PVR*, unsigned char*, unsigned int);
    int64_t(__cdecl* SeekLiveStream)(const struct AddonInstance_PVR*, int64_t, int);
    int64_t(__cdecl* LengthLiveStream)(const struct AddonInstance_PVR*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Recording stream read interface functions
    bool(__cdecl* OpenRecordedStream)(const struct AddonInstance_PVR*, const struct PVR_RECORDING*);
    void(__cdecl* CloseRecordedStream)(const struct AddonInstance_PVR*);
    int(__cdecl* ReadRecordedStream)(const struct AddonInstance_PVR*, unsigned char*, unsigned int);
    int64_t(__cdecl* SeekRecordedStream)(const struct AddonInstance_PVR*, int64_t, int);
    int64_t(__cdecl* LengthRecordedStream)(const struct AddonInstance_PVR*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // Stream demux interface functions
    enum PVR_ERROR(__cdecl* GetStreamProperties)(const struct AddonInstance_PVR*,
                                                 struct PVR_STREAM_PROPERTIES*);
    struct DemuxPacket*(__cdecl* DemuxRead)(const struct AddonInstance_PVR*);
    void(__cdecl* DemuxReset)(const struct AddonInstance_PVR*);
    void(__cdecl* DemuxAbort)(const struct AddonInstance_PVR*);
    void(__cdecl* DemuxFlush)(const struct AddonInstance_PVR*);
    void(__cdecl* SetSpeed)(const struct AddonInstance_PVR*, int);
    void(__cdecl* FillBuffer)(const struct AddonInstance_PVR*, bool);
    bool(__cdecl* SeekTime)(const struct AddonInstance_PVR*, double, bool, double*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // General stream interface functions
    bool(__cdecl* CanPauseStream)(const struct AddonInstance_PVR*);
    void(__cdecl* PauseStream)(const struct AddonInstance_PVR*, bool);
    bool(__cdecl* CanSeekStream)(const struct AddonInstance_PVR*);
    bool(__cdecl* IsRealTimeStream)(const struct AddonInstance_PVR*);
    enum PVR_ERROR(__cdecl* GetStreamTimes)(const struct AddonInstance_PVR*,
                                            struct PVR_STREAM_TIMES*);
    enum PVR_ERROR(__cdecl* GetStreamReadChunkSize)(const struct AddonInstance_PVR*, int*);

    //--==----==----==----==----==----==----==----==----==----==----==----==----==
    // New functions becomes added below and can be on another API change (where
    // breaks min API version) moved up.
  } KodiToAddonFuncTable_PVR;

  typedef struct AddonInstance_PVR
  {
    struct AddonProperties_PVR* props;
    struct AddonToKodiFuncTable_PVR* toKodi;
    struct KodiToAddonFuncTable_PVR* toAddon;
  } AddonInstance_PVR;

#ifdef __cplusplus
}
#endif /* __cplusplus */
