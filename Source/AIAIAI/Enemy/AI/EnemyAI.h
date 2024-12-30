// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIAIAI/Spline/SplineController.h"
#include "UObject/Interface.h"
#include "EnemyAI.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UEnemyAI : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AIAIAI_API IEnemyAI
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual ASplineController* GetPatrolRoute() = 0;

	virtual void SetMoveSpeed(float speed) = 0;

	virtual float GetAttackRange() const = 0;

	virtual float GetDefendRange() const = 0;

	virtual void EquipWeapon() = 0;

	virtual void UnequipWeapon() = 0;

	virtual void Attack() = 0;

	virtual float GetCurHealth() const = 0;

	virtual float GetMaxHealth() const = 0;
};
