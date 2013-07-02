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
#include "StackStartTimeoutWatcher.hpp"

#define THREAD_NAME "StackStartTimeoutWatcherThread"

namespace iviLink
{

namespace SystemController
{

Logger StackStartTimeoutWatcher::mLogger =
                Logger::getInstance("SystemControllerWatchdog.StackStartTimeoutWatcher");

StackStartTimeoutWatcher::StackStartTimeoutWatcher(IStackStartTimeoutWatcherCallback * callback) :
    CThread(THREAD_NAME), mCallback(callback)
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
}

void StackStartTimeoutWatcher::startWait()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    CThread::start();
}

void StackStartTimeoutWatcher::stopWait()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    mSemaphore.signal();
}

void StackStartTimeoutWatcher::threadFunc()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    int waitResult = mSemaphore.waitTimeout(IVILINK_START_TIMEOUT_SECONDS * 1000);
    if (waitResult == -1)
    {
        LOG4CPLUS_FATAL(mLogger, "Stack did not start in time, aborting!");
        mCallback->onTimeout();
    }
}

}
}
