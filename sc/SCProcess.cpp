/*
 * Adapted from https://github.com/chriskiefer/OpenFrameworks-Supercollider-Host
 * Created by Chris on 10/09/2011.
 * Copyright 2011 Goldsmiths Creative Computing. All rights reserved.
 *
*/

#include <scsynth/SC_PortAudio.cpp>

#include "SCProcess.hpp"

#define scprintf printf

void* scThreadFunc(void* arg)
{
  World* world  = (World*)arg;
  World_WaitForQuit(world);
  return 0;
}

//void null_reply_func(struct ReplyAddress* /*addr*/, char* /*msg*/, int /*size*/)
//{
//}

SCProcess::SCProcess()
{
}

void SCProcess::startUp(WorldOptions options,
                        const char* pluginsPath,
                        const char* synthdefsPath,
                        int preferredPort)
{
  pthread_t scThread;
//  char stringBuffer[PATH_MAX] ;
//  OSCMessages messages;

//  CFStringGetCString(pluginsPath, stringBuffer, sizeof(stringBuffer), kCFStringEncodingUTF8);
//  setenv("SC_PLUGIN_PATH", stringBuffer, 1);
//  CFStringGetCString(synthdefsPath, stringBuffer, sizeof(stringBuffer), kCFStringEncodingUTF8);
//  setenv("SC_SYNTHDEF_PATH", stringBuffer, 1);
  this->portNum = preferredPort;
  world = World_New(&options);
  world->mVerbosity = true;
  //world->mDumpOSC=2;
  if (world)  {
    if (this->portNum >= 0) World_OpenUDP(world, bindTo.c_str(), this->portNum);
    pthread_create (&scThread, NULL, scThreadFunc, (void*)world);
  }
//  if (world->mRunning){
//    small_scpacket packet = messages.initTreeMessage();
//    World_SendPacket(world, 16, (char*)packet.buf, null_reply_func);
//  }
}

void SCProcess::run(const float* in,
                    float* out,
                    unsigned long frameCount,
                    const PaStreamCallbackTimeInfo* timeInfo,
                    PaStreamCallbackFlags statusFlags)
{
  if (world->mRunning){
    SC_PortAudioDriver* driver = (SC_PortAudioDriver*)this->world->hw->mAudioDriver;
//    AUCallback(driver,(AudioBufferList*)in, out, &inTimeStamp, inFramesToProcess, sampleRate, oscTime );
    driver->PortAudioCallback(in, out, frameCount, timeInfo, statusFlags);
  }
}

void SCProcess::quit()
{
//  OSCMessages messages;
//  if (world && world->mRunning){
//    small_scpacket packet = messages.quitMessage();
//    World_SendPacket(world, 8,(char*)packet.buf, null_reply_func);
//  }
}
