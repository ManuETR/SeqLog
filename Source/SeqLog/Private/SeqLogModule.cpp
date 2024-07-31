#pragma once

#include "SeqLogModule.h"

void FSeqLogModule::StartupModule() 
{
  // Register the custom logger
  SeqLogSingelton = new FSeqLog();

  GLog->AddOutputDevice(SeqLogSingelton);
}

void FSeqLogModule::ShutdownModule()
{
  // Remove the custom logger
  GLog->RemoveOutputDevice(SeqLogSingelton);
}

IMPLEMENT_MODULE(FSeqLogModule, SeqLog); //Replace with your plugin name
