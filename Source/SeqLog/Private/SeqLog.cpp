#include "SeqLog.h"

USeqLog* USeqLog::SeqLogSingelton = nullptr;
USeqLog::USeqLog() {
  settings = GetDefault<USeqLogSettings>();
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> USeqLog::CreateHttpRequest() {
  FString SeqServerURL = settings->ServerUrl;
  FString SeqApiKey = settings->ApiKey;

  TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
  HttpRequest->SetVerb(TEXT("POST"));
  HttpRequest->SetURL(SeqServerURL);
  HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
  HttpRequest->SetHeader(TEXT("Connection"), TEXT("keep-alive"));
  if (!SeqApiKey.IsEmpty()) {
    HttpRequest->SetHeader(TEXT("X-Seq-ApiKey"), SeqApiKey);
  }
  return HttpRequest;
}

void USeqLog::SendRequest(const FString& Message) {
  // UE_LOG(LogTemp, Log, TEXT("%s"), *Message);

  TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = CreateHttpRequest();
  HttpRequest->SetContentAsString(Message);

  HttpRequest->ProcessRequest();
}

void USeqLog::Send(const TSharedPtr<FJsonObject>& JsonObject) {
  FString OutputString;
  FString MessageString;
  TSharedRef<TJsonWriter<>> OutputWriter = TJsonWriterFactory<>::Create(&OutputString);
  TSharedRef<TJsonWriter<>> MessageWriter = TJsonWriterFactory<>::Create(&MessageString);

  TSharedPtr<FJsonObject> JsonLog = MakeShareable(new FJsonObject());
  FJsonSerializer::Serialize(JsonObject.ToSharedRef(), MessageWriter);
  MessageString.ReplaceInline(TEXT("\n"), TEXT(""));
  MessageString.ReplaceInline(TEXT("\r"), TEXT(""));
  MessageString.ReplaceInline(TEXT("\t"), TEXT(""));
  JsonLog->SetStringField(TEXT("@m"), MessageString);
  JsonLog->SetStringField(TEXT("@t"), FDateTime::Now().ToIso8601());

  FJsonSerializer::Serialize(JsonLog.ToSharedRef(), OutputWriter);
  OutputString.ReplaceInline(TEXT("\n"), TEXT(""));
  OutputString.ReplaceInline(TEXT("\r"), TEXT(""));
  OutputString.ReplaceInline(TEXT("\t"), TEXT(""));
  SendRequest(OutputString);
}

USeqLog* USeqLog::Get()
{
  if (!SeqLogSingelton)
  {
    SeqLogSingelton = NewObject<USeqLog>();
    SeqLogSingelton->AddToRoot(); // Prevent garbage collection
  }
  return SeqLogSingelton;
}
