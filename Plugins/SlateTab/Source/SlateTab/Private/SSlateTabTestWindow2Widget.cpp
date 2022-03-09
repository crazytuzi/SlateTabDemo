// Copyright Epic Games, Inc. All Rights Reserved.

#include "SSlateTabTestWindow2Widget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlateTabTestWindow2Widget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(STextBlock).Text(FText::FromName("Test2"))
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
