/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "pvr_defines.h"

#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

  typedef enum EPG_EVENT_CONTENTMASK
  {
    EPG_EVENT_CONTENTMASK_UNDEFINED = 0x00,
    EPG_EVENT_CONTENTMASK_MOVIEDRAMA = 0x10,
    EPG_EVENT_CONTENTMASK_NEWSCURRENTAFFAIRS = 0x20,
    EPG_EVENT_CONTENTMASK_SHOW = 0x30,
    EPG_EVENT_CONTENTMASK_SPORTS = 0x40,
    EPG_EVENT_CONTENTMASK_CHILDRENYOUTH = 0x50,
    EPG_EVENT_CONTENTMASK_MUSICBALLETDANCE = 0x60,
    EPG_EVENT_CONTENTMASK_ARTSCULTURE = 0x70,
    EPG_EVENT_CONTENTMASK_SOCIALPOLITICALECONOMICS = 0x80,
    EPG_EVENT_CONTENTMASK_EDUCATIONALSCIENCE = 0x90,
    EPG_EVENT_CONTENTMASK_LEISUREHOBBIES = 0xA0,
    EPG_EVENT_CONTENTMASK_SPECIAL = 0xB0,
    EPG_EVENT_CONTENTMASK_USERDEFINED = 0xF0,
    EPG_GENRE_USE_STRING = 0x100
  } EPG_EVENT_CONTENTMASK;

  typedef enum EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA
  {
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_DETECTIVE_THRILLER = 0x1,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_ADVENTURE_WESTERN_WAR = 0x2,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_SCIENCEFICTION_FANTASY_HORROR = 0x3,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_COMEDY = 0x4,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_SOAP_MELODRAMA_FOLKLORIC = 0x5,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_ROMANCE = 0x6,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_SERIOUS_CLASSICAL_RELIGIOUS_HISTORICAL = 0x7,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_ADULT = 0x8,
    EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_MOVIEDRAMA;

  typedef enum EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS
  {
    EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS_WEATHER = 0x1,
    EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS_MAGAZINE = 0x2,
    EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS_DOCUMENTARY = 0x3,
    EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS_DISCUSSION_INTERVIEW_DEBATE = 0x4,
    EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_NEWSCURRENTAFFAIRS;

  typedef enum EPG_EVENT_CONTENTSUBMASK_SHOW
  {
    EPG_EVENT_CONTENTSUBMASK_SHOW_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_SHOW_GAMESHOW_QUIZ_CONTEST = 0x1,
    EPG_EVENT_CONTENTSUBMASK_SHOW_VARIETY_SHOW = 0x2,
    EPG_EVENT_CONTENTSUBMASK_SHOW_TALK_SHOW = 0x3,
    EPG_EVENT_CONTENTSUBMASK_SHOW_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_SHOW;

  typedef enum EPG_EVENT_CONTENTSUBMASK_SPORTS
  {
    EPG_EVENT_CONTENTSUBMASK_SPORTS_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_OLYMPICGAMES_WORLDCUP = 0x1,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_SPORTS_MAGAZINES = 0x2,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_FOOTBALL_SOCCER = 0x3,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_TENNIS_SQUASH = 0x4,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_TEAMSPORTS = 0x5,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_ATHLETICS = 0x6,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_MOTORSPORT = 0x7,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_WATERSPORT = 0x8,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_WINTERSPORTS = 0x9,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_EQUESTRIAN = 0xA,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_MARTIALSPORTS = 0xB,
    EPG_EVENT_CONTENTSUBMASK_SPORTS_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_SPORTS;

  typedef enum EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH
  {
    EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH_PRESCHOOL_CHILDREN = 0x1,
    EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH_ENTERTAIN_6TO14 = 0x2,
    EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH_ENTERTAIN_10TO16 = 0x3,
    EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH_INFORMATIONAL_EDUCATIONAL_SCHOOL = 0x4,
    EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH_CARTOONS_PUPPETS = 0x5,
    EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_CHILDRENYOUTH;

  typedef enum EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE
  {
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_ROCKPOP = 0x1,
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_SERIOUSMUSIC_CLASSICALMUSIC = 0x2,
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_FOLK_TRADITIONAL_MUSIC = 0x3,
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_JAZZ = 0x4,
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_MUSICAL_OPERA = 0x5,
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_BALLET = 0x6,
    EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_MUSICBALLETDANCE;

  typedef enum EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE
  {
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_PERFORMINGARTS = 0x1,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_FINEARTS = 0x2,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_RELIGION = 0x3,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_POPULARCULTURE_TRADITIONALARTS = 0x4,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_LITERATURE = 0x5,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_FILM_CINEMA = 0x6,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_EXPERIMENTALFILM_VIDEO = 0x7,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_BROADCASTING_PRESS = 0x8,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_NEWMEDIA = 0x9,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_ARTS_CULTUREMAGAZINES = 0xA,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_FASHION = 0xB,
    EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_ARTSCULTURE;

  typedef enum EPG_EVENT_CONTENTSUBMASK_SOCIALPOLITICALECONOMICS
  {
    EPG_EVENT_CONTENTSUBMASK_SOCIALPOLITICALECONOMICS_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_SOCIALPOLITICALECONOMICS_MAGAZINES_REPORTS_DOCUMENTARY = 0x1,
    EPG_EVENT_CONTENTSUBMASK_SOCIALPOLITICALECONOMICS_ECONOMICS_SOCIALADVISORY = 0x2,
    EPG_EVENT_CONTENTSUBMASK_SOCIALPOLITICALECONOMICS_REMARKABLEPEOPLE = 0x3,
    EPG_EVENT_CONTENTSUBMASK_SOCIALPOLITICALECONOMICS_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_SOCIALPOLITICALECONOMICS;

  typedef enum EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE
  {
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_NATURE_ANIMALS_ENVIRONMENT = 0x1,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_TECHNOLOGY_NATURALSCIENCES = 0x2,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_MEDICINE_PHYSIOLOGY_PSYCHOLOGY = 0x3,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_FOREIGNCOUNTRIES_EXPEDITIONS = 0x4,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_SOCIAL_SPIRITUALSCIENCES = 0x5,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_FURTHEREDUCATION = 0x6,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_LANGUAGES = 0x7,
    EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_EDUCATIONALSCIENCE;

  typedef enum EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES
  {
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_TOURISM_TRAVEL = 0x1,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_HANDICRAFT = 0x2,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_MOTORING = 0x3,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_FITNESSANDHEALTH = 0x4,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_COOKING = 0x5,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_ADVERTISEMENT_SHOPPING = 0x6,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_GARDENING = 0x7,
    EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_LEISUREHOBBIES;

  typedef enum EPG_EVENT_CONTENTSUBMASK_SPECIAL
  {
    EPG_EVENT_CONTENTSUBMASK_SPECIAL_GENERAL = 0x0,
    EPG_EVENT_CONTENTSUBMASK_SPECIAL_BLACKANDWHITE = 0x1,
    EPG_EVENT_CONTENTSUBMASK_SPECIAL_UNPUBLISHED = 0x2,
    EPG_EVENT_CONTENTSUBMASK_SPECIAL_LIVEBROADCAST = 0x3,
    EPG_EVENT_CONTENTSUBMASK_SPECIAL_PLANOSTEREOSCOPIC = 0x4,
    EPG_EVENT_CONTENTSUBMASK_SPECIAL_LOCALORREGIONAL = 0x5,
    EPG_EVENT_CONTENTSUBMASK_SPECIAL_USERDEFINED = 0xF
  } EPG_EVENT_CONTENTSUBMASK_SPECIAL;

  #define EPG_STRING_TOKEN_SEPARATOR ","

  typedef enum EPG_TAG_FLAG
  {
    EPG_TAG_FLAG_UNDEFINED = 0,
    EPG_TAG_FLAG_IS_SERIES = (1 << 0),
    EPG_TAG_FLAG_IS_NEW = (1 << 1),
    EPG_TAG_FLAG_IS_PREMIERE = (1 << 2),
    EPG_TAG_FLAG_IS_FINALE = (1 << 3),
    EPG_TAG_FLAG_IS_LIVE = (1 << 4),
  } EPG_TAG_FLAG;

  #define EPG_TAG_INVALID_UID 0
  #define EPG_TAG_INVALID_SERIES_EPISODE -1
  #define EPG_TIMEFRAME_UNLIMITED -1

  typedef enum EPG_EVENT_STATE
  {
    EPG_EVENT_CREATED = 0,
    EPG_EVENT_UPDATED = 1,
    EPG_EVENT_DELETED = 2,
  } EPG_EVENT_STATE;

  typedef struct EPG_TAG
  {
    unsigned int iUniqueBroadcastId;
    unsigned int iUniqueChannelId;
    const char* strTitle;
    time_t startTime;
    time_t endTime;
    const char* strPlotOutline;
    const char* strPlot;
    const char* strOriginalTitle;
    const char* strCast;
    const char* strDirector;
    const char* strWriter;
    int iYear;
    const char* strIMDBNumber;
    const char* strIconPath;
    int iGenreType;
    int iGenreSubType;
    const char* strGenreDescription;
    const char* strFirstAired;
    int iParentalRating;
    int iStarRating;
    int iSeriesNumber;
    int iEpisodeNumber;
    int iEpisodePartNumber;
    const char* strEpisodeName;
    unsigned int iFlags;
    const char* strSeriesLink;
  } EPG_TAG;

#ifdef __cplusplus
}
#endif /* __cplusplus */
