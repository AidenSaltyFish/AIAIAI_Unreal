// Fill out your copyright notice in the Description page of Project Settings.


#include "SheathSwordAnimNotify.h"

#include "AIAIAI/Enemy/EnemyBase.h"

void USheathSwordAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                    const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	// Cast<AEnemyBase>(MeshComp->GetOwner())->DespawnSword();
	UE_LOG(LogTemp, Warning, TEXT("Sheath sword anim notify"));
}
