#include "DialogueSubsystem.h"

void UDialogueSubsystem::CreateSubtitleWidget(UDialogueEntry* dialogueEntry)
{
	if (IsValid(widgetClass)) {
		subtitleWidget = Cast<USubtitleWidget>(CreateWidget(GetWorld(), widgetClass));

		if (subtitleWidget != nullptr) {
			subtitleWidget->text = dialogueEntry->text;
			subtitleWidget->AddToViewport();
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("NOT VALID"));
	}
}

void UDialogueSubsystem::PlayDialogue(UDialogueEntry* dialogueEntry, UAudioComponent* audioComponent)
{
	//Check for returns
	if (!playedDialogue.Contains(dialogueEntry))
	{
		if (!dialogueQueue.Contains(dialogueEntry)) {
			dialogueQueue.Add(dialogueEntry);
			audioSources.Add(audioComponent);
		}
	}
	if (dialogueQueue.Num() == 0) {
		return;
	}
	if (playing) {
		return;
	}

	audioSources[0]->SetSound(dialogueQueue[0]->DialogueAudio);
	audioSources[0]->Play();
	playing = true;

	CreateSubtitleWidget(dialogueQueue[0]);

	AudioFinishedPlay.BindUFunction(this, "OnDialogueEnd");
	audioSources[0]->OnAudioFinished.Add(AudioFinishedPlay);
}

void UDialogueSubsystem::OnDialogueEnd()
{
	audioSources[0]->OnAudioFinished.Remove(AudioFinishedPlay);
	playedDialogue.Add(dialogueQueue[0]);
	dialogueQueue.RemoveAt(0);
	audioSources.RemoveAt(0);
	playing = false;
	subtitleWidget->RemoveFromParent();

	if (dialogueQueue.Num() != 0) 
	{
		PlayDialogue(dialogueQueue[0], audioSources[0]);
	}
}


