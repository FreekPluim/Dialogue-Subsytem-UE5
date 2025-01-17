// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "SubtitleWidget.h"
#include "DialogueEntry.h"
#include "DialogueSubsystem.generated.h"


UCLASS()
class DIALOGUESUBSYSTEMUE5_API UDialogueSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	bool playing = false;

protected:
	FScriptDelegate AudioFinishedPlay;


public:
	//Array of dialogue that has been played before in this playsession.
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue Subsystem")
	TArray<UDialogueEntry*> playedDialogue;

	/// <summary>
	/// Widget Variables
	/// </summary>
	UPROPERTY(BlueprintReadWrite, Category = "Dialogue Subsystem")
	TSubclassOf<UUserWidget> widgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Dialogue Subsystem")
	class USubtitleWidget* subtitleWidget;


	/// <summary>
	/// Dialogue Variables
	/// </summary>
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue Subsystem")
	TArray<UDialogueEntry*> dialogueQueue;
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue Subsystem")
	TArray<UAudioComponent*> audioSources;

	/// <summary>
	/// Callable Functions
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Dialogue Subsystem")
	void PlayDialogue(UDialogueEntry* dialogueEntry, UAudioComponent* audioComponent);


	/// <summary>
	/// Non callable functions
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Dialogue Subsystem")
	void CreateSubtitleWidget(UDialogueEntry* dialogueEntry);

	UFUNCTION(BlueprintCallable, Category = "Dialogue Subsystem")
	void OnDialogueEnd();
	
};
