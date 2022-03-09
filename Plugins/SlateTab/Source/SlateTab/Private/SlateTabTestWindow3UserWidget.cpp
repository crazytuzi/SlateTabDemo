// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateTabTestWindow3UserWidget.h"

TSharedRef<SWidget> USlateTabTestWindow3UserWidget::RebuildWidget()
{
	MyWidget = SNew(SSlateTabTestWindow3Widget);

	return MyWidget.ToSharedRef();
}

TSharedPtr<SWidget> USlateTabTestWindow3UserWidget::GetAccessibleWidget() const
{
	return MyWidget;
}
