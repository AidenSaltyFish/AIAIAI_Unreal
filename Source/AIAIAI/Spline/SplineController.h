// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "SplineController.generated.h"

UCLASS()
class AIAIAI_API ASplineController : public AActor
{
	GENERATED_BODY()

private:
	int curIdx;
	bool bIsMovingForward;

public:
	UPROPERTY(Blueprintable, EditAnywhere, Category = "Spline")
	USplineComponent* SplineComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ASplineController();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spline")
	void IncrementSplineIndex();
	
	UFUNCTION(BlueprintCallable, Category = "Spline")
	FVector GetSplineLocationAtIdx(int idx) const;
	
	UFUNCTION(BlueprintCallable, Category = "Spline")
	FVector GetSplineLocationAtCurIdx() const;
};
