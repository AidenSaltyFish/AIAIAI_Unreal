// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineController.h"

#include "Components/SplineComponent.h"


// Sets default values
ASplineController::ASplineController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	curIdx = 0;
	bIsMovingForward = true;
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
}

// Called when the game starts or when spawned
void ASplineController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASplineController::IncrementSplineIndex()
{
	int numPoints = SplineComponent->GetNumberOfSplinePoints();
	curIdx = (curIdx + 1) % numPoints;
}

FVector ASplineController::GetSplineLocationAtCurIdx() const
{
	return GetSplineLocationAtIdx(curIdx);
}

FVector ASplineController::GetSplineLocationAtIdx(int idx) const
{
	return SplineComponent->GetLocationAtSplinePoint(idx, ESplineCoordinateSpace::World);
}
