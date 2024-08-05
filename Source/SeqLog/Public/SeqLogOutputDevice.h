#pragma once

#include "Core.h"
#include "SeqLogSettings.h"
#include "Misc/OutputDeviceHelper.h"
#include "Misc/App.h"
#include "HttpModule.h" // You'll need this for making HTTP requests
#include "Json.h"
#include "JsonUtilities.h"

/**
 * Custom logging sink class for sending log messages to Seq.
 */
class FSeqLogOutputDevice : public FOutputDevice
{

private:
  virtual void Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const class FName& Category) override;

public:
  FSeqLogOutputDevice();

};