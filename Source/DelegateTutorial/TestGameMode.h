// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestGameMode.generated.h"

DECLARE_MULTICAST_DELEGATE(ScoreUpdateDelegate);

/**
 * 
 */
UCLASS()
class DELEGATETUTORIAL_API ATestGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	ATestGameMode();

	UFUNCTION(BlueprintCallable)
		void SetScorePoints(int32 value);

	UFUNCTION()
		int32 GetScorePoints();

	ScoreUpdateDelegate OnScoreUpdated;

protected:

	UFUNCTION()
		void ScoreUpdated();

private:

	UPROPERTY()
		int32 Score;
};
