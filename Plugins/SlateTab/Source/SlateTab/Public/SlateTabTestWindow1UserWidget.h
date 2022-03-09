// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SSlateTabTestWindow1Widget.h"
#include "SlateTabTestWindow1UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SLATETAB_API USlateTabTestWindow1UserWidget : public UUserWidget
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
	TSharedPtr<SSlateTabTestWindow1Widget> MyWidget;
};
