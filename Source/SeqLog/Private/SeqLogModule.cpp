#pragma once

#include "SeqLogModule.h"

void FSeqLogModule::StartupModule() 
{
  // Register the custom logger
  if (!SeqLogOutputDeviceSingelton) {
    SeqLogOutputDeviceSingelton = new FSeqLogOutputDevice();
  }

  GLog->AddOutputDevice(SeqLogOutputDeviceSingelton);
}

void FSeqLogModule::ShutdownModule()
{
  // Remove the custom logger
  GLog->RemoveOutputDevice(SeqLogOutputDeviceSingelton);
}

IMPLEMENT_MODULE(FSeqLogModule, SeqLog); //Replace with your plugin name
