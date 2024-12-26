// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultAttack.h"

#include "AIController.h"

UDefaultAttack::UDefaultAttack()
{
	NodeName = TEXT("Default Attack");
}

EBTNodeResult::Type UDefaultAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BehaviorTreeComponent = &OwnerComp;
	
	USkeletalMeshComponent* mesh =
		Cast<USkeletalMeshComponent>(OwnerComp.GetAIOwner()->GetPawn()
			->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
	
	if (mesh)
	{
		FOnMontageEnded MontageEndedDelegate;
		MontageEndedDelegate.BindUObject(this, &UDefaultAttack::OnMontageEnded);
		
		mesh->GetAnimInstance()->Montage_Play(DefaultAttackMontage, 1.0f);
		mesh->GetAnimInstance()->Montage_SetEndDelegate(MontageEndedDelegate, DefaultAttackMontage);

		return EBTNodeResult::InProgress;
	}
	
	UE_LOG(LogTemp, Error, TEXT("Mesh is empty or has no skeletal mesh assigned"));

	return EBTNodeResult::Failed;
}

void UDefaultAttack::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage == DefaultAttackMontage)
	{
		FinishLatentTask(*BehaviorTreeComponent, EBTNodeResult::Succeeded);
	}
}
