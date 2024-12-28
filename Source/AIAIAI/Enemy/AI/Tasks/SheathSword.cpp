// Fill out your copyright notice in the Description page of Project Settings.


#include "SheathSword.h"

#include "AIController.h"
#include "AIAIAI/Enemy/EnemyBase.h"

class AEnemyBase;

USheathSword::USheathSword()
{
	NodeName = TEXT("Sheath Sword Node");
}

EBTNodeResult::Type USheathSword::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyBase* enemy = Cast<AEnemyBase>(OwnerComp.GetAIOwner()->GetPawn());
	enemy->SheathSword();

	return EBTNodeResult::Succeeded;
}
