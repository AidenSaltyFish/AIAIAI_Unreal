// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// bHasWieldedSword = false;
	WeaponActor = nullptr;

	// WeaponSocketName = FName(TEXT("hand_r_socket_sword"));
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	if (bEquipWeaponAtBeginPlay)
	{
		EquipWeapon();
	}
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyBase::EquipWeapon()
{
	if (bHasEquippedWeapon || WeaponActor)
	{
		return;
	}

	USkeletalMeshComponent* SkeletalMeshComponent =
		Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

	if (UWorld* world = GetWorld())
	{
		WeaponActor =
			world->SpawnActor<AActor>(WeaponBPActor, GetActorLocation(), GetActorRotation());

		if (WeaponActor)
		{
			if (SkeletalMeshComponent)
			{
				// FName socketName(TEXT("hand_r_socket_sword"));
				WeaponActor->AttachToComponent(
					SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponSocketName);
			}
		}
	}

	bHasEquippedWeapon = true;
}

void AEnemyBase::UnequipWeapon()
{
	if (!bHasEquippedWeapon || !WeaponActor)
		return;
	
	USkeletalMeshComponent* SkeletalMeshComponent =
		Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

	if (SkeletalMeshComponent)
	{
		WeaponActor->Destroy();
		WeaponActor = nullptr;
	}
	
	bHasEquippedWeapon = false;
}

void AEnemyBase::Attack()
{
}

ASplineController* AEnemyBase::GetPatrolRoute()
{
	return SplineController;
}

void AEnemyBase::SetMoveSpeed(float speed)
{
	GetCharacterMovement()->MaxWalkSpeed = speed;
}

float AEnemyBase::GetAttackRange() const
{
	return 150;
}

float AEnemyBase::GetDefendRange() const
{
	return 350;
}

// // Custom event implementation
// void AEnemyBase::WieldSword()
// {
// 	// Implement your custom logic here
// 	UE_LOG(LogTemp, Warning, TEXT("WieldSword event called"));
//
// 	if (UWorld* World = GetWorld())
// 	{
// 		// Replace AMyActor with the class of the actor you want to spawn
// 		AActor* SpawnedActor =
// 			World->SpawnActor<AActor>(BlueprintActor, GetActorLocation(), GetActorRotation());
// 		if (SpawnedActor)
// 		{
// 			UE_LOG(LogTemp, Warning, TEXT("Actor spawned successfully"));
//
// 			USkeletalMeshComponent* SkeletalMeshComponent =
// 				Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
// 			if (SkeletalMeshComponent)
// 			{
// 				FName SocketName(TEXT("Hand_r_socket_sword"));
// 				SpawnedActor->AttachToComponent(
// 					SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, SocketName);
// 				
// 				UE_LOG(LogTemp, Warning, TEXT("Actor attached successfully"));
// 			}
// 		}
// 	}
// }

// Custom event implementation
// void AEnemyBase::WieldSword()
// {
// 	if (bHasWieldedSword || WeaponActor)
// 	{
// 		return;
// 	}
// 	
// 	// AAIController* aiController = Cast<AAIController>(this->GetController());
// 	// if (aiController)
// 	// {
// 	// 	UE_LOG(LogTemp, Warning, TEXT("ai controller found"));
// 	// }
// 	// else
// 	// {
// 	// 	UE_LOG(LogTemp, Warning, TEXT("ai controller not found"));
// 	// }
//
// 	USkeletalMeshComponent* SkeletalMeshComponent =
// 		Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
// 	
// 	// if (SkeletalMeshComponent)
// 	// {
// 	// 	UAnimInstance* AnimInstance = SkeletalMeshComponent->GetAnimInstance();
// 	// 	
// 	// 	if (AnimInstance)
// 	// 		AnimInstance->Montage_Play(WieldSwordMontage);
// 	// }
// 	//
// 	// // Set a timer to check the montage's position
// 	// GetWorld()->GetTimerManager()
// 	// 	.SetTimer(MontageTimerHandle, this, &AEnemyBase::SpawnSword, 0.1f, true);
//
// 	if (UWorld* world = GetWorld())
// 	{
// 		WeaponActor =
// 			world->SpawnActor<AActor>(WeaponBPActor, GetActorLocation(), GetActorRotation());
//
// 		// TSharedPtr<AActor> spawnedActorShared = MakeShareable(spawnedActor);
// 		
// 		if (WeaponActor)
// 		{
// 			if (SkeletalMeshComponent)
// 			{
// 				FName socketName(TEXT("hand_r_socket_sword"));
// 				WeaponActor->AttachToComponent(
// 					SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, socketName);
// 			}
// 		}
// 	}
//
// 	bHasWieldedSword = true;
// }

// void AEnemyBase::SpawnSword()
// {
	// if (bHasWieldedSword)
	// 	return;
	//
	// USkeletalMeshComponent* SkeletalMeshComponent =
	// 	Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
	//
	// if (SkeletalMeshComponent)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Skeletal mesh component found"));
	// 	
	// 	UAnimInstance* AnimInstance = SkeletalMeshComponent->GetAnimInstance();
	//
	// 	if (AnimInstance)
	// 	{
	// 		if (AnimInstance->Montage_IsPlaying(WieldSwordMontage))
	// 		{
	// 			float progress =
	// 				AnimInstance->Montage_GetPosition(WieldSwordMontage) / WieldSwordMontage->GetPlayLength();
	//
	// 			UE_LOG(LogTemp, Warning, TEXT("Progress: %f"), progress);
	// 			
	// 			if (progress >= 0.25f)
	// 			{
	// 				if (UWorld* world = GetWorld())
	// 				{
	// 					AActor* spawnedActor =
	// 						world->SpawnActor<AActor>(BlueprintActor, GetActorLocation(), GetActorRotation());
	//
	// 					// TSharedPtr<AActor> spawnedActorShared = MakeShareable(spawnedActor);
	// 	
	// 					if (spawnedActor)
	// 					{
	// 						if (SkeletalMeshComponent)
	// 						{
	// 							FName socketName(TEXT("hand_r_socket_sword"));
	// 							spawnedActor->AttachToComponent(
	// 								SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, socketName);
	// 						}
	// 					}
	// 				}
	//
	// 				bHasWieldedSword = true;
	// 				GetWorld()->GetTimerManager().ClearTimer(MontageTimerHandle);
	// 			}
	// 		}
	// 		else
	// 		{
	// 			// Clear the timer if the montage is no longer playing
	// 			GetWorld()->GetTimerManager().ClearTimer(MontageTimerHandle);
	// 		}
	// 	}
	// }
// }

// void AEnemyBase::SheathSword()
// {
// 	if (!bHasWieldedSword || !WeaponActor)
// 		return;
// 	
// 	USkeletalMeshComponent* SkeletalMeshComponent =
// 		Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
//
// 	if (SkeletalMeshComponent)
// 	{
// 		// UAnimInstance* AnimInstance = SkeletalMeshComponent->GetAnimInstance();
// 		//
// 		// if (AnimInstance)
// 		// 	AnimInstance->Montage_Play(SheathSwordMontage);
// 		
// 		WeaponActor->Destroy();
// 		WeaponActor = nullptr;
// 	}
// 	
// 	bHasWieldedSword = false;
// }
//
// void AEnemyBase::DespawnSword()
// {
// 	// if (!bHasWieldedSword)
// 	// 	return;
// 	//
// 	// USkeletalMeshComponent* SkeletalMeshComponent =
// 	// 	Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
//
// 	// GetComponentByClass(BlueprintActor->GetClass())->DestroyComponent();
// }
