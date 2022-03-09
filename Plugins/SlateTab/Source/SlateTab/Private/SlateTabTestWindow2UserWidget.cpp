// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateTabTestWindow2UserWidget.h"

TSharedRef<SWidget> USlateTabTestWindow2UserWidget::RebuildWidget()
{
	MyWidget = SNew(SSlateTabTestWindow2Widget);

	return MyWidget.ToSharedRef();
}

TSharedPtr<SWidget> USlateTabTestWindow2UserWidget::GetAccessibleWidget() const
{
	return MyWidget;
}
