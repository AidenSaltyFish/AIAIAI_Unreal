// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/EnemyAI.h"
#include "AIAIAI/Spline/SplineController.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UCLASS()
class AIAIAI_API AEnemyBase : public ACharacter, public IEnemyAI
{
	GENERATED_BODY()

private:
	bool bHasWieldedSword;
	FTimerHandle MontageTimerHandle;

public:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> BlueprintActor;

	UPROPERTY(EditAnywhere, Category = "Spline")
	ASplineController* SplineController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	AEnemyBase();

	UFUNCTION(BlueprintCallable, Category="Custom")
	virtual ASplineController* GetPatrolRoute() override;

	UFUNCTION(BlueprintCallable, Category="Custom")
	virtual void SetMoveSpeed(float speed) override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UFUNCTION(BlueprintCallable, Category="Custom")
	UPROPERTY(Blueprintable, EditAnywhere)
	UAnimMontage* WieldSwordMontage;
	
	void WieldSword();
	void SpawnSword();

	UPROPERTY(Blueprintable, EditAnywhere)
	UAnimMontage* SheathSwordMontage;
	
	void SheathSword();
	void DespawnSword();

	bool GetHasWieldedSword() const { return bHasWieldedSword; }
};
