/* 
 * iviLINK SDK, version 1.2
 * http://www.ivilink.net
 * Cross Platform Application Communication Stack for In-Vehicle Applications
 * 
 * Copyright (C) 2012-2013, Luxoft Professional Corp., member of IBS group
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; version 2.1.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * 
 */ 


#ifndef IPIMTOIPC_HPP_
#define IPIMTOIPC_HPP_

/// @todo temporary include
#include "UID.hpp"

namespace AXIS {
namespace PMAL {

class IPIMToIpc
{
public:

   virtual void incomingProfile(AXIS::CUid const& profileUid,
         AXIS::Profile::IUid const& piuid,
         AXIS::Service::Uid const& serviceUID) = 0;

protected:

   virtual ~IPIMToIpc() {}
};


}  // namespace ProfileManager
}  // namespace AXIS


#endif /* IPIMTOIPC_HPP_ */
