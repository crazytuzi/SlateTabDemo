// Copyright Epic Games, Inc. All Rights Reserved.

#include "SSlateTabTestWindow3Widget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlateTabTestWindow3Widget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(STextBlock).Text(FText::FromName("Test3"))
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
