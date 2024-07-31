#pragma once

#include "Modules/ModuleInterface.h"
#include "SeqLog.h"

class FSeqLogModule : public IModuleInterface
{
  FSeqLog* SeqLogSingelton;

  virtual void StartupModule() override;

  virtual void ShutdownModule() override;
};
