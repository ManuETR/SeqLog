#include "SeqLog.h"

FSeqLog::FSeqLog() {
  settings = GetDefault<USeqLogSettings>();
}

void FSeqLog::Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const class FName& Category) {
  if (settings->Enable && Category == TEXT("SeqLog")) {
    FString LogMessage = FString::Printf(TEXT("%s: %s"), *Category.ToString(), V);
    Send(LogMessage);
  }
}

void FSeqLog::Send(const FString& Message) {
  // Customize this part to send the log message to your Seq server using HTTP or your preferred method
  FString SeqServerURL = settings->ServerUrl;
  FString SeqApiKey = settings->ApiKey;

  // Construct the HTTP request
  TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
  HttpRequest->SetVerb(TEXT("POST"));
  HttpRequest->SetURL(SeqServerURL);
  HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
  if (!SeqApiKey.IsEmpty()) {
    HttpRequest->SetHeader(TEXT("X-Seq-ApiKey"), SeqApiKey);
  }
  HttpRequest->SetContentAsString(Message);

  // Send the HTTP request
  HttpRequest->ProcessRequest();
}

void FSeqLog::Send(const TSharedPtr<FJsonObject>& JsonObject) {
  FString OutputString;
  TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
  FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
  Send(OutputString);
}