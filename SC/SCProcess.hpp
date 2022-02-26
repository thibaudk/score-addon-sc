/*
 * Adapted from https://github.com/chriskiefer/OpenFrameworks-Supercollider-Host
 * Created by Chris on 10/09/2011.
 * Copyright 2011 Goldsmiths Creative Computing. All rights reserved.
 *
*/

#ifndef SCPROCESS_HPP
#define SCPROCESS_HPP

#include <server/SC_WorldOptions.h>
#include <plugin_interface/SC_World.h>
#include <scsynth/SC_HiddenWorld.h>

//#include "OSCMessages.h"

#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>

//#include "SC_CoreAudio.h"
//#include "SC_AU.h"

class PaStreamCallbackTimeInfo;
typedef unsigned long PaStreamCallbackFlags;

namespace SC
{
class SCProcess {

public:
  SCProcess();
  const char* synthName;
  int portNum{57110};
  std::string bindTo{"127.0.0.1"};
  void startUp(WorldOptions options,
               const char* pluginsPath,
               const char* synthdefsPath,
               int preferredPort);
  //	void makeSynth();
  //	void sendParamChangeMessage(CFStringRef name, float value);
  //	void sendNote(int64 oscTime, int note, int velocity);
  //  void sendTick(int64 oscTime, int bus);
  void quit();
  void run(const float* in,
           float* out,
           unsigned long frameCount,
           const PaStreamCallbackTimeInfo* timeInfo,
           PaStreamCallbackFlags statusFlags);

private:
  World* world;
};
}

#endif // SCPROCESS_HPP
