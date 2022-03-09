// Copyright Epic Games, Inc. All Rights Reserved.

#include "SSlateTabTestWindow1Widget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlateTabTestWindow1Widget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(STextBlock).Text(FText::FromName("Test1"))
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
