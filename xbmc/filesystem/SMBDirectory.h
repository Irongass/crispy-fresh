#pragma once
/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
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
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "IDirectory.h"
#include "SMBFile.h"
#include "MediaSource.h"

namespace XFILE
{
class CSMBDirectory : public IDirectory
{
public:
  CSMBDirectory(void);
  ~CSMBDirectory(void) override;
  bool GetDirectory(const CURL& url, CFileItemList &items) override;
  DIR_CACHE_TYPE GetCacheType(const CURL& url) const override { return DIR_CACHE_ONCE; };
  bool Create(const CURL& url) override;
  bool Exists(const CURL& url) override;
  bool Remove(const CURL& url) override;

  int Open(const CURL &url);

private:
  int OpenDir(const CURL &url, std::string& strAuth);
};
}
