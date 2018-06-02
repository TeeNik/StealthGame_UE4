// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAIGuard.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "FPSGameMode.h"
#include "Net/UnrealNetwork.h"
#include "AI/Navigation/NavigationSystem.h"


// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AFPSAIGuard::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AFPSAIGuard::OnNoiseHeard);

	GuardState = EAIState::Idle;

}

// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	
	OriginalRotation = GetActorRotation();

	if(bPatrol)	MoveToNextPatrolPont();

}

void AFPSAIGuard::StopMoving()
{
	AController* Controller = GetController();
	if (Controller) Controller->StopMovement();
}

void AFPSAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn == nullptr) return;

	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32, 12, FColor::Red, false, 10);
	AFPSGameMode* GM = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
	if (GM)
	{
		GM->CompleteMission(SeenPawn, false);
	}

	SetGuardState(EAIState::Alerted);

	StopMoving();
}

void AFPSAIGuard::OnNoiseHeard(APawn* NoiseInstigator, const FVector& Location, float Volume)
{
	if(GuardState == EAIState::Alerted) return;

	DrawDebugSphere(GetWorld(), Location, 32, 12, FColor::Green, false, 10);

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();

	FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
	NewLookAt.Pitch = 0;
	NewLookAt.Roll = 0;

	SetActorRotation(NewLookAt);

	GetWorldTimerManager().ClearTimer(ResetRotationTimer);
	GetWorldTimerManager().SetTimer(ResetRotationTimer, this, &AFPSAIGuard::ResetOrientation, 3);

	SetGuardState(EAIState::Suspicious);

	StopMoving();
}

void AFPSAIGuard::ResetOrientation()
{
	if (GuardState == EAIState::Alerted) return;
	SetActorRotation(OriginalRotation);
	SetGuardState(EAIState::Idle);

	if (bPatrol) MoveToNextPatrolPont();
}

void AFPSAIGuard::OnRep_GuardState()
{
	OnStateChanged(GuardState);
}

void AFPSAIGuard::SetGuardState(EAIState NewState)
{
	if(GuardState == NewState) return;

	GuardState = NewState;
	OnRep_GuardState();
}

void AFPSAIGuard::MoveToNextPatrolPont()
{
	if(CurrentPatrolPoint == nullptr || CurrentPatrolPoint == SecondPatrolPoint)
	{
		CurrentPatrolPoint = FirstPatrolPoint;
	}
	else
	{
		CurrentPatrolPoint = SecondPatrolPoint;
	}

	UNavigationSystem::SimpleMoveToActor(GetController(), CurrentPatrolPoint);
}

// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(CurrentPatrolPoint)
	{
		FVector Delta = GetActorLocation() - CurrentPatrolPoint->GetActorLocation();
		float DistanceToGoal = Delta.Size();
		if(DistanceToGoal < 50)
		{
			MoveToNextPatrolPont();
		}
	}
}

void AFPSAIGuard::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFPSAIGuard, GuardState);
}

