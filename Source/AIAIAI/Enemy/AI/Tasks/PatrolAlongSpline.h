// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Navigation/PathFollowingComponent.h"
#include "PatrolAlongSpline.generated.h"

/**
 * 
 */
UCLASS()
class AIAIAI_API UPatrolAlongSpline : public UBTTaskNode
{
	GENERATED_BODY()

private:
	// UBehaviorTreeComponent* OwnerComp;
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UPatrolAlongSpline();
};
