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
/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_luxoft_ivilink_samples_media_Bridge */

#ifndef _Included_com_luxoft_ivilink_samples_media_Bridge
#define _Included_com_luxoft_ivilink_samples_media_Bridge
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    storeObjects
 * Signature: (Lcom/luxoft/ivilink/samples/media/interfaces/MediaGui;Lcom/luxoft/ivilink/samples/media/interfaces/JniPlayerWrapper;Lcom/luxoft/ivilink/samples/media/helpers/MediaSource;)V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_storeObjects
(JNIEnv *, jobject, jobject, jobject, jobject);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    startApp
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_startApp
(JNIEnv *, jobject, jstring, jstring, jstring, jstring);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    playClicked
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_playClicked
(JNIEnv *, jobject);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    pauseClicked
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_pauseClicked
(JNIEnv *, jobject);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    stopClicked
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_stopClicked
(JNIEnv *, jobject);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    nextClicked
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_nextClicked
(JNIEnv *, jobject);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    prevClicked
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_prevClicked
(JNIEnv *, jobject);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    posClicked
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_posClicked
(JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    completed
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_completed
(JNIEnv *, jobject);
/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    completed
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_syncClicked
(JNIEnv *, jobject);
/*
 * Class:     com_luxoft_ivilink_samples_media_Bridge
 * Method:    completed
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_toggleClicked
(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_luxoft_ivilink_samples_media_Bridge_playbackStarted
(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
