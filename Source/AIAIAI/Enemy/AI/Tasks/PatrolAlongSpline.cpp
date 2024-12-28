// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolAlongSpline.h"

#include "AIController.h"
#include "AIAIAI/Enemy/AI/EnemyAI.h"
#include "Navigation/PathFollowingComponent.h"

UPatrolAlongSpline::UPatrolAlongSpline()
{
	NodeName = TEXT("Patrol Along Spline");
}

// void UPatrolAlongSpline::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
// {
// 	if (Result.Code == EPathFollowingResult::Success)
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("Move completed successfully"));
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("Move failed"));
// 	}
// 	
// 	// Unbind the delegate to avoid multiple bindings
// 	if (AAIController* AIController = Cast<AAIController>(OwnerComp->GetAIOwner()))
// 	{
// 		AIController->ReceiveMoveCompleted.RemoveDynamic(this, &UPatrolAlongSpline::OnMoveCompleted);
// 	}
// 	
// 	// Finish the task
// 	FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
// }

EBTNodeResult::Type UPatrolAlongSpline::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// this->OwnerComp = &OwnerComp;

	AAIController* AIController = OwnerComp.GetAIOwner();
	ASplineController* SplineController =
		Cast<IEnemyAI>(AIController->GetPawn())->GetPatrolRoute();

	// AIController->ReceiveMoveCompleted.AddDynamic(this, &UPatrolAlongSpline::OnMoveCompleted);

	if (SplineController && AIController)
	{
		FAIMoveRequest MoveRequest;
		MoveRequest.SetGoalLocation(SplineController->GetSplineLocationAtCurIdx());
		MoveRequest.SetAcceptanceRadius(5.0f);

		if (AIController->MoveTo(MoveRequest) == EPathFollowingRequestResult::RequestSuccessful)
		{
			SplineController->IncrementSplineIndex();
			return EBTNodeResult::Succeeded;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No SplineController found"));
	}

	return EBTNodeResult::InProgress;
}
