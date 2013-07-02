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


#include <stdlib.h>
#include <cstring>
#include <cassert>

#include "CBasicSampleProfileImpl.hpp"

//namespace required for working with receiving and sending data
using namespace iviLink::Channel;

Logger CBasicSampleProfileImpl::msLogger = Logger::getInstance(LOG4CPLUS_TEXT("samples.Profiles.CBasicSampleProfileImpl"));

/**
 * Sending the summands
 */
void CBasicSampleProfileImpl::sendOperands(std::string a, std::string b)
{
  LOG4CPLUS_INFO(msLogger, "CBasicSampleProfileImpl::sendOperands(" + convertIntegerToString(a) + ", " + convertIntegerToString(b) + ")");
  //LOG4CPLUS_INFO(msLogger, "CBasicSampleProfileImpl::sendOperands(" + a + ", " + b + ")");

  /*out going data was changed from 3 to 30, because we work with string
and char**/

  UInt8 outgoingData[30];//change for save string, was 3
  Buffer buf(outgoingData, 30);

  //convert string to unsigned char
  unsigned char* aa = (unsigned char*) strcpy ( (char*) outgoingData, a.c_str());
  unsigned char* bb = (unsigned char*) strcpy ( (char*) outgoingData, b.c_str());

  //sending the name of procedure and summands
  bool res = true;
  res = res && buf.write(static_cast<UInt8>(SEND_OPERANDS_PROCEDURE));


  /*this magic for work with write method. if look at Buffer.hpp and use
 function from 215 line will be error*/
  char* a1 = (char*)(aa);
  char* b1 = (char*)(bb);
  res = res && buf.write(a1, strlen(a1));
  res = res && buf.write(b1, strlen(b1));

  /*  res = res && buf.write(dynamic_cast<UInt8>(SEND_OPERANDS_PROCEDURE));
  res = res && buf.write(dynamic_cast<UInt8>(a));
  res = res && buf.write(dynamic_cast<UInt8>(b));*/
  
  if (res)
    {
      iviLink::Error err = iviLink::Channel::sendBuffer(mChannelID, buf);
      if (!err.isNoError())
	LOG4CPLUS_WARN(msLogger, "Unable to sendBuffer: " + static_cast<std::string>(err));
      //LOG4CPLUS_WARN(msLogger, "Unable to sendBuffer: " + dynamic_cast<std::string>(err));
   }
   else
   {
      LOG4CPLUS_WARN(msLogger, "Unable to write data into buffer");
   }
}

/**
 * Sending the obtained result
 */
void CBasicSampleProfileImpl::sendResult(std::string a)
{
   LOG4CPLUS_INFO(msLogger, "CBasicSampleProfileImpl::sendResult(" + a + ")");

   UInt8 outgoingData[30]; //2
   Buffer buf(outgoingData, 30); //2

   //sending the name of procedure and result of operation
   bool res = true;
   res = res && buf.write(static_cast<UInt8>(SEND_RESULT_PROCEDURE));

   /*this for work with array, because programm was writed to work with simple int */
   char* a1 = (char*)(a.c_str());
   res = res && buf.write(a1, strlen(a1));
   //res = res && buf.write(static_cast<UInt8>(a));

   /*   res = res && buf.write(dynamic_cast<UInt8>(SEND_RESULT_PROCEDURE));
   res = res && buf.write(dynamic_cast<UInt8>(a));*/

   if (res)
   {
      iviLink::Error err = iviLink::Channel::sendBuffer(mChannelID, buf);
      if (!err.isNoError())
	LOG4CPLUS_WARN(msLogger, "Unable to sendBuffer: " + static_cast<std::string>(err));

	//         LOG4CPLUS_WARN(msLogger, "Unable to sendBuffer: " + dynamic_cast<std::string>(err));
   }
   else
   {
      LOG4CPLUS_WARN(msLogger, "Unable to write data into buffer");
   }
}

CBasicSampleProfileImpl::CBasicSampleProfileImpl(iviLink::Profile::IProfileCallbackProxy* pCbProxy)
   : mChannelID(0)
     , mpAppCallbacks(static_cast<IBasicSampleProfile_API::Callbacks*>(pCbProxy))
     //, mpAppCallbacks(dynamic_cast<IBasicSampleProfile_API::Callbacks*>(pCbProxy))
{
   Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("samples.BasicSample"));

   PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log4cplus.properties"));

   LOG4CPLUS_INFO(msLogger, "CBasicSampleProfileImpl::CBasicSampleProfileImpl");
}

CBasicSampleProfileImpl::~CBasicSampleProfileImpl()
{
   if (mChannelID != 0)
   {
      //deallocating channel after deleting instance 
      deallocateChannel(mChannelID);
      mChannelID = 0;
   }
}


/**
 * Allocating channel
 */
void CBasicSampleProfileImpl::onEnable()
{
   //Allocating channel
   iviLink::Error err =  allocateChannel("CBasicSampleProfileImpl", this, mChannelID, eRealTime);
   if(mChannelID != 0)
   {
      LOG4CPLUS_INFO(msLogger, "CBasicSampleProfileImpl::CBasicSampleProfileImpl(): Channel allocated, starting the communication...");
   }
   else
   {
      LOG4CPLUS_INFO(msLogger, "CBasicSampleProfileImpl::CBasicSampleProfileImpl(): allocate Channel failed");
   }
}

/**
 * Deallocating channel
 */
void CBasicSampleProfileImpl::onDisable()
{
   {
      //Deallocating channel
      deallocateChannel(mChannelID);
   }
}

/**
 * Callback that should be invoked when the data is received
 */
void CBasicSampleProfileImpl::onBufferReceived(const tChannelId channel, Buffer const& buffer)
{
   assert (channel == mChannelID);
   UInt8 procedure;

   bool res = buffer.read(procedure);
   if (!res)
   {
      LOG4CPLUS_WARN(msLogger, "Unable to read procedure from buffer");
      return;
   }

   switch (procedure)
   {
   case SEND_OPERANDS_PROCEDURE:
      {
         UInt8 a, b;
         res = res && buffer.read(a);
         res = res && buffer.read(b);

         if (res)
         {
            LOG4CPLUS_INFO(msLogger, "Operands for edition received");

            LOG4CPLUS_INFO(msLogger, "First operand = " + convertIntegerToString(a));
	    LOG4CPLUS_INFO(msLogger, "Second operand = " + convertIntegerToString(b));
	    /*LOG4CPLUS_INFO(msLogger, "First operand = " + a);
	      LOG4CPLUS_INFO(msLogger, "Second operand = " + b);*/
	    //char buf[100];
            //itoa(buf,a,10);

	    sendResult(a + b);
	    mpAppCallbacks->operandsReceived(a,b);
         }
         else
         {
            LOG4CPLUS_WARN(msLogger, "Unable to read operands from buffer");
            mpAppCallbacks->operandsReceived(a,b);
            return;
         }
      }
      break;
   case SEND_RESULT_PROCEDURE:
      {
         UInt8 result;
         res = res && buffer.read(result);

         if (res)
         {
            LOG4CPLUS_INFO(msLogger, "Result of edition received");
            LOG4CPLUS_INFO(msLogger, "Result = " + convertIntegerToString(result));
            mpAppCallbacks->resultReceived(result);
         }
         else
         {
            LOG4CPLUS_WARN(msLogger, "Unable to read operands from buffer");
            mpAppCallbacks->resultReceived(result);
            return;  
         }
      }
      break;
   default:
      LOG4CPLUS_WARN(msLogger, "Unknown procedure code");
   }

}

/**
 * Callback that should be invoked when the channel is deleted
 */
void CBasicSampleProfileImpl::onChannelDeleted(const UInt32 channel_id)
{
   LOG4CPLUS_INFO(msLogger, "CBasicSampleProfileImpl::channelDeletedCallback() - " +
         convertIntegerToString(channel_id) + " channel deleted!");
   //Deallocating channel
   deallocateChannel(mChannelID);
   mChannelID = 0;
}

/**
 * Callback that should be invoked when the connection is lost
 */
void CBasicSampleProfileImpl::onConnectionLost()
{
   LOG4CPLUS_TRACE_METHOD(msLogger, __PRETTY_FUNCTION__ );
}

