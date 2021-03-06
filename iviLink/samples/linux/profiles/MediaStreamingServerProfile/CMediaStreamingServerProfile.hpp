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


#ifndef CMEDIASTREAMINGSERVERPROFILE_HPP_
#define CMEDIASTREAMINGSERVERPROFILE_HPP_

#include <iostream>
#include <queue>
#include <vector>

#include "Logger.hpp"
#include "ProfileLibCommon.hpp"
#include "IMediaStreamingServerProfileAPI.hpp"
#include "ISender.hpp"
#include "MediaProfilesCommon.hpp"


using iviLink::Buffer;
using iviLink::Channel::tChannelId;

class CSenderThread;
class CMutex;
class CSignalSemaphore;

IVILINK_PROFILE_BEGIN

class CMediaStreamingServerProfile   : public iviLink::Channel::ChannelHandler
                                  , public IMediaStreamingServerProfile_API
                                  , public ISender
{
   IVILINK_PROFILE_DECLARE
   IVILINK_PROFILE_NAME(MediaStreamingServerProfile)
   IVILINK_PROFILE_VERSION(1)
   IVILINK_PROFILE_UID(MediaStreamingServerProfile_UID)
   IVILINK_PROFILE_API_UID(MediaStreamingServerProfile_API_UID)

   struct info
   {
       //std::vector<std::string> audioForm;
       //std::vector<std::string> videoForm;
       std::string auForm;
       std::string viForm;
   };


   // from IMediaStreamingServerProfile_API
 
   virtual void sendStreamingInfo();	
   virtual void onEnable();
   virtual void onDisable();

   //from CChannelHandler
   virtual void onBufferReceived(const iviLink::Channel::tChannelId channel, Buffer const& buffer);
   virtual void onChannelDeleted(const UInt32 channel_id);
   virtual void onConnectionLost();

   //from ISender
   virtual void senderLoop();

   bool hasRequests();
   void handleRequest();

   CMediaStreamingServerProfile(iviLink::Profile::IProfileCallbackProxy* pCbProxy);
   virtual ~CMediaStreamingServerProfile();

   typedef std::queue<std::string>                  tReqQueue;

   iviLink::Channel::tChannelId                 mChannelID;

   IMediaStreamingServerProfile_API::Callbacks * mpAppCallbacks;
   CSenderThread *                              mpSenderThread;
   CMutex *                                     mpReqMutex;
   CSignalSemaphore *                           mpReqSemaphore;
   bool                                         mBe;
   tReqQueue                                    mReqQueue;
   static Logger                                msLogger;
   info                                         mStreamingInfo;
};

IVILINK_PROFILE_END(CMediaStreamingServerProfile)

#endif /* CMEDIASTREAMINGSERVERPROFILE_HPP_ */
