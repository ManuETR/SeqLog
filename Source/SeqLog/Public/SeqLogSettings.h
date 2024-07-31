// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DeveloperSettings.h"
#include "SeqLogSettings.generated.h"

/**
 *
 */
UCLASS(config = SeqLog, DefaultConfig)
class SEQLOG_API USeqLogSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	USeqLogSettings();

	UPROPERTY(Config, EditAnywhere)
	FString ServerUrl = "https://localhost:5341/api/events/raw";

	UPROPERTY(Config, EditAnywhere)
	FString ApiKey = "";

	UPROPERTY(Config, EditAnywhere)
	bool Enable = false;
};