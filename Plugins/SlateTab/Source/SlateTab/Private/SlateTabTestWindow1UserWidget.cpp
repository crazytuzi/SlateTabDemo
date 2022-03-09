// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateTabTestWindow1UserWidget.h"

TSharedRef<SWidget> USlateTabTestWindow1UserWidget::RebuildWidget()
{
	MyWidget = SNew(SSlateTabTestWindow1Widget);

	return MyWidget.ToSharedRef();
}

TSharedPtr<SWidget> USlateTabTestWindow1UserWidget::GetAccessibleWidget() const
{
	return MyWidget;
}
