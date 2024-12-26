// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearFocus.h"

#include "AIController.h"

UClearFocus::UClearFocus()
{
	NodeName = TEXT("Clear Focus");
}

EBTNodeResult::Type UClearFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetAIOwner()->ClearFocus(EAIFocusPriority::Gameplay);
	
	return EBTNodeResult::Succeeded;
}
