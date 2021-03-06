// Copyright (c) 2012. Los Alamos National Security, LLC. 

// This material was produced under U.S. Government contract DE-AC52-06NA25396
// for Los Alamos National Laboratory (LANL), which is operated by Los Alamos 
// National Security, LLC for the U.S. Department of Energy. The U.S. Government 
// has rights to use, reproduce, and distribute this software.  

// NEITHER THE GOVERNMENT NOR LOS ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, 
// EXPRESS OR IMPLIED, OR ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  
// If software is modified to produce derivative works, such modified software should
// be clearly marked, so as not to confuse it with the version available from LANL.

// Additionally, this library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License v 2.1 as published by the 
// Free Software Foundation. Accordingly, this library is distributed in the hope that 
// it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See LICENSE.txt for more details.

//--------------------------------------------------------------------------
// $Id: DassfEvent.C,v 1.6 2010/02/28 05:01:39 kroc Exp $
//--------------------------------------------------------------------------
// File:    DassfEvent.C
// Module:  simx
// Author:  K. Bisset, Sunil Thulasidasan
// Created: June 25 2004
//
// @@
//
//--------------------------------------------------------------------------
#ifdef SIMX_USE_PRIME
#include "simx/DassfEvent.h"
#include "simx/DassfEventInfo.h"
#include "simx/DassfEventInfoManager.h"
#include "simx/DassfPyEventInfoManager.h"
#include "simx/logger.h"



#include "Common/Assert.h"
#include "Common/backtrace.h"

using namespace std;

namespace simx {

  /// register all derived DassfEvent classes:
  SSF_REGISTER_EVENT(DassfEventInfo, DassfEventInfo::unpack);
  SSF_REGISTER_EVENT(DassfEventInfoManager, DassfEventInfoManager::unpack);
  SSF_REGISTER_EVENT(DassfPyEventInfoManager, DassfPyEventInfoManager::unpack);

  DassfEvent::DassfEvent()
    : minissf::Event()
  {
  }

  DassfEvent::DassfEvent(const DassfEvent& e)
    : minissf::Event(e)
  {
  }

  DassfEvent::DassfEvent(minissf::CompactDataType* dp)
  {
  }

  DassfEvent::~DassfEvent()
  {
  }

  minissf::CompactDataType* DassfEvent::pack()
  {
    minissf::CompactDataType* dp = new minissf::CompactDataType;
    return pack(dp);
  }

  minissf::CompactDataType* DassfEvent::pack(minissf::CompactDataType* dp)
  {
    SMART_ASSERT( dp );
    return dp;
  }

  int DassfEvent::pack(char* buf, int bufsize)
  {
    SMART_ASSERT(false)("DassfEvent can only be used as a base class; pack should never be called");

  }

  //minissf::Event* DassfEvent::unpack(minissf::CompactDataType*)
  minissf::Event* DassfEvent::unpack(char* buf, int bufsize)
  {
    SMART_VERIFY(0)("DassfEvent can only be used as a base class, therefore unpack should never get called");
    return NULL;
  }

  void DassfEvent::print(ostream& os) const
  {
    os << "DassfEvent";
  }

} // namespace

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#endif // SIMX_USE_PRIME
