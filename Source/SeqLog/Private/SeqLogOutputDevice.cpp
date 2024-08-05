#include "SeqLogOutputDevice.h"
#include "SeqLog.h"

FSeqLogOutputDevice::FSeqLogOutputDevice() {}

void FSeqLogOutputDevice::Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const class FName& Category) {
  if (Category == TEXT("SeqLog")) {
    FString LogMessage = FString::Printf(TEXT("%s: %s"), *Category.ToString(), V);
    USeqLog::Get()->SendRequest(LogMessage);
  }
}
