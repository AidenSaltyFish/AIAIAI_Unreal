// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UCLASS()
class AIAIAI_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

private:
	bool bHasWieldedSword;

public:
	// Sets default values for this character's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UFUNCTION(BlueprintCallable, Category="Custom")
	void WieldSword();

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> BlueprintActor;

	bool GetHasWieldedSword() const { return bHasWieldedSword; }
};
