// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SSlateTabTestWindow2Widget.h"
#include "SlateTabTestWindow2UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SLATETAB_API USlateTabTestWindow2UserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UWidget Interface

#if WITH_ACCESSIBILITY
	virtual TSharedPtr<SWidget> GetAccessibleWidget() const override;
#endif

protected:
	TSharedPtr<SSlateTabTestWindow2Widget> MyWidget;
};
