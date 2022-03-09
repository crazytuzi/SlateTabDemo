// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SLATETAB_API SSlateTabTestWindow3Widget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlateTabTestWindow3Widget)
		{
		}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
