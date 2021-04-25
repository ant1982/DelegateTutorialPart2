// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameMode.h"

ATestGameMode::ATestGameMode()
{
	Score = 0;
}

void ATestGameMode::SetScorePoints(int32 value)
{
	Score += value;
	UE_LOG(LogTemp, Warning, TEXT("Score: %d"),Score);
	ScoreUpdated();
}

int32 ATestGameMode::GetScorePoints()
{
	return Score;
}

void ATestGameMode::ScoreUpdated()
{
	OnScoreUpdated.Broadcast();
}
