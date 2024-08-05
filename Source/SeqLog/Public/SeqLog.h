#pragma once

#include "Core.h"
#include "SeqLogSettings.h"
#include "Misc/OutputDeviceHelper.h"
#include "Misc/App.h"
#include "HttpModule.h" // You'll need this for making HTTP requests
#include "Json.h"
#include "JsonUtilities.h"
#include "SeqLog.generated.h"

DEFINE_LOG_CATEGORY_STATIC(SeqLog, VeryVerbose, All);

/**
 * Custom logging sink class for sending log messages to Seq.
 */
UCLASS()
class SEQLOG_API USeqLog : public UObject
{
  GENERATED_BODY()

private:
  const USeqLogSettings* settings;
  static USeqLog* SeqLogSingelton;
  TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateHttpRequest();

public:
  USeqLog();
  /**
   * Function to send log messages to Seq.
   *
   * @param Message   The log message.
   */
  void SendRequest(const FString& Message);
  void Send(const TSharedPtr<FJsonObject>& JsonObject);
  static USeqLog* Get();
};