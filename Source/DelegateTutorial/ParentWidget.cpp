// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentWidget.h"
#include "TestGameMode.h"
#include "Components/TextBlock.h"

void UParentWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UWorld* World = GetWorld();

	if (World != nullptr)
	{
		ATestGameMode* TestGameMode = Cast<ATestGameMode>(World->GetAuthGameMode());

		if (TestGameMode)
		{
			TestGameMode->OnScoreUpdated.AddUObject(this, &UParentWidget::SetDataValueDelegate);
		}
	}
}

bool UParentWidget::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString("Score Text has been initialised"));
	}

	return true;
}

void UParentWidget::SetDataValueDelegate()
{
	UE_LOG(LogTemp, Warning, TEXT("The Score has been updated"));

	if (ScoreText)
	{
		UWorld* World = GetWorld();

		if (World != nullptr)
		{
			ATestGameMode* TestGameMode = Cast<ATestGameMode>(World->GetAuthGameMode());

			FString dataString = TEXT("The Score value is: ");

			if (TestGameMode)
			{
				dataString.AppendInt(TestGameMode->GetScorePoints());

				ScoreText->SetText(FText::FromString(dataString));
			}
		}
	}
}

//FText UParentWidget::SetScoreField()
//{
//	UWorld* World = GetWorld();
//
//	if (World != nullptr)
//	{
//		ATestGameMode* TestGameMode = Cast<ATestGameMode>(World->GetAuthGameMode());
//
//		if (TestGameMode)
//		{	
//			return FText::FromString(FString::FromInt(TestGameMode->GetScorePoints()));
//		}
//
//		else
//		{
//			return FText::FromString("NULL");
//		}
//	}
//
//	return FText::FromString("NULL");
//}
