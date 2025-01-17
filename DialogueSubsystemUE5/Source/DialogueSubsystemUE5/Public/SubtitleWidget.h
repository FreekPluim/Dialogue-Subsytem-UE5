// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SubtitleWidget.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUESUBSYSTEMUE5_API USubtitleWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Dialogue Subsystem")
	FText text;
};
