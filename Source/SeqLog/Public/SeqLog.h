#pragma once

#include "Core.h"
#include "SeqLogSettings.h"
#include "Misc/OutputDeviceHelper.h"
#include "Misc/App.h"
#include "HttpModule.h" // You'll need this for making HTTP requests
#include "Json.h"
#include "JsonUtilities.h"


DEFINE_LOG_CATEGORY_STATIC(SeqLog, VeryVerbose, All);

/**
 * Custom logging sink class for sending log messages to Seq.
 */
class FSeqLog : public FOutputDevice
{
private:
  const USeqLogSettings* settings;
  virtual void Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const class FName& Category) override;

public:
  FSeqLog();
  /**
   * Function to send log messages to Seq.
   *
   * @param Message   The log message.
   */
  void Send(const FString& Message);
  void Send(const TSharedPtr<FJsonObject>& JsonObject);
};