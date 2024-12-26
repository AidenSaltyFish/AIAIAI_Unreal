// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"


// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bHasWieldedSword = false;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	WieldSword();
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Custom event implementation
void AEnemyBase::WieldSword()
{
	if (bHasWieldedSword)
	{
		return;
	}
	
	UWorld* world = GetWorld();

	if (world)
	{
		AActor* spawnedActor =
			world->SpawnActor<AActor>(BlueprintActor, GetActorLocation(), GetActorRotation());

		if (spawnedActor)
		{
			USkeletalMeshComponent* skeletalMeshComponent =
				Cast<USkeletalMeshComponent>(this->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

			if (skeletalMeshComponent)
			{
				FName socketName(TEXT("hand_r_socket_sword"));
				spawnedActor->AttachToComponent(
					skeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, socketName);
			}
		}
	}

	bHasWieldedSword = true;
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
