// Fill out your copyright notice in the Description page of Project Settings.


#include "WieldSword.h"

#include "AIController.h"
#include "AIAIAI/Enemy/EnemyBase.h"

UWieldSword::UWieldSword()
{
	NodeName = TEXT("Wield Sword Node");
}

EBTNodeResult::Type UWieldSword::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyBase* enemy = Cast<AEnemyBase>(OwnerComp.GetAIOwner()->GetPawn());
	enemy->WieldSword();

	return EBTNodeResult::Succeeded;
}
