#pragma once

#include "Modules/ModuleInterface.h"
#include "SeqLogOutputDevice.h"

class FSeqLogModule : public IModuleInterface
{
  FSeqLogOutputDevice * SeqLogOutputDeviceSingelton;

  virtual void StartupModule() override;

  virtual void ShutdownModule() override;
};
