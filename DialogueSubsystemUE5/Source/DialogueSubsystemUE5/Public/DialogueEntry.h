// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DialogueEntry.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUESUBSYSTEMUE5_API UDialogueEntry : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (MultiLine = true))
	FText text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* DialogueAudio;
};
