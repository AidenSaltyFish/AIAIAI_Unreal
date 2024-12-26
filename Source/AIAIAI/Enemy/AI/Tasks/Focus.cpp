// Fill out your copyright notice in the Description page of Project Settings.


#include "Focus.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UFocus::UFocus()
{
	NodeName = TEXT("Focus Node");
}

EBTNodeResult::Type UFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Implement your custom logic here

	FName FocusKey(TEXT("AttackTarget"));
	FBlackboard::FKey FocusKeyID = OwnerComp.GetBlackboardComponent()->GetKeyID(FocusKey);
	AActor* focusActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FocusKey));
	OwnerComp.GetAIOwner()->SetFocus(focusActor);

	return EBTNodeResult::Succeeded;
}
