// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DelegateWidget.generated.h"

/**
 * 
 */
UCLASS()
class DELEGATETUTORIAL_API UDelegateWidget : public UUserWidget
{
	GENERATED_BODY()

protected: 
	
	bool Initialize() override;
	

private:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* ScoreTextField;

	UFUNCTION()
		FText SetScoreField();
};
