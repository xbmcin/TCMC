/*
 *      Copyright (C) 2016 Garrett Brown
 *      Copyright (C) 2016 Team Kodi
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "buttonmapper/ButtonMapTypes.h"

class TiXmlElement;

namespace JOYSTICK
{
  class CJoystickFamiliesXml
  {
  public:
    static bool LoadFamilies(const std::string& path, JoystickFamilyMap& result);

  private:
    static bool Deserialize(const TiXmlElement* pFamily, JoystickFamilyMap& result);
    static bool DeserializeJoysticks(const TiXmlElement* pJoystick, std::set<std::string>& family);
  };
}
