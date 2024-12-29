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
	bool bHasEquippedWeapon;
	AActor* WeaponActor;

public:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> WeaponBPActor;

	UPROPERTY(EditAnywhere, Category = "Spline")
	ASplineController* SplineController;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	FName WeaponSocketName;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	bool bEquipWeaponAtBeginPlay;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	AEnemyBase();

	UFUNCTION(BlueprintCallable, Category="Custom")
	virtual ASplineController* GetPatrolRoute() override;

	UFUNCTION(BlueprintCallable, Category="Custom")
	virtual void SetMoveSpeed(float speed) override;

	UFUNCTION(BlueprintCallable, Category="Custom")
	virtual float GetAttackRange() const override;

	UFUNCTION(BlueprintCallable, Category="Custom")
	virtual float GetDefendRange() const override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UFUNCTION(BlueprintCallable, Category="Custom")
	// UPROPERTY(Blueprintable, EditAnywhere)
	// UAnimMontage* WieldSwordMontage;

	// UFUNCTION(BlueprintCallable)
	// void WieldSword();
	// void SpawnSword();

	// UPROPERTY(Blueprintable, EditAnywhere)
	// UAnimMontage* SheathSwordMontage;

	// UFUNCTION(BlueprintCallable)
	// void SheathSword();
	// void DespawnSword();

	UFUNCTION(BlueprintCallable)
	virtual void EquipWeapon() override;

	UFUNCTION(BlueprintCallable)
	virtual void UnequipWeapon() override;

	UFUNCTION(BlueprintCallable)
	virtual void Attack() override;

	UFUNCTION(BlueprintCallable)
	bool GetHasEquippedWeapon() const { return bHasEquippedWeapon; }
};
