// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "DefaultAttack.generated.h"

/**
 * 
 */
UCLASS()
class AIAIAI_API UDefaultAttack : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UBehaviorTreeComponent* BehaviorTreeComponent;
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
public:
	UDefaultAttack();

	UPROPERTY(Blueprintable, EditAnywhere)
	UAnimMontage* DefaultAttackMontage;
};
