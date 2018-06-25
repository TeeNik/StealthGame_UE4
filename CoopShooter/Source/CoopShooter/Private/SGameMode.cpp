// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameMode.h"
#include "SHealthComponent.h"
#include "TimerManager.h"


ASGameMode::ASGameMode()
{
	TimeBetweenWaves = 2;
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1;
	WaveCount = 0;

	GameStateClass = ASGameState::StaticClass();
}

void ASGameMode::StartPlay()
{
	Super::StartPlay();
	PrepareForNextWave();
}

void ASGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CheckWaveState();
	CheckAnyPlayerAlive();
}

void ASGameMode::StartWave()
{
	++WaveCount;
	NumOfBotsToSpawn = 2 * WaveCount;
	GetWorldTimerManager().SetTimer(BotSpawnTimer, this, &ASGameMode::SpawnBotTimerElapsed, 1, true, 0);
	SetWaveState(WaveState::WaveInProgress);
}

void ASGameMode::EndWave()
{
	GetWorldTimerManager().ClearTimer(BotSpawnTimer);
	SetWaveState(WaveState::WaitingToComplete);
}

void ASGameMode::PrepareForNextWave()
{
	GetWorldTimerManager().SetTimer(NextWaveTimer, this, &ASGameMode::StartWave, TimeBetweenWaves, false);
	SetWaveState(WaveState::WatingToStart);
}

void ASGameMode::SpawnBotTimerElapsed()
{
	SpawnNewBot();
	--NumOfBotsToSpawn;
	GLog->Log(NumOfBotsToSpawn+"");
	if (NumOfBotsToSpawn <= 0)
		EndWave();
}

void ASGameMode::CheckWaveState()
{
	bool bIsPreparingForWave = GetWorldTimerManager().IsTimerActive(NextWaveTimer);

	if (NumOfBotsToSpawn > 0 || bIsPreparingForWave)
	{
		return;
	}

	bool bIsAnyBotAlive = false;

	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
	{
		APawn* TestPawn = It->Get();
		if (TestPawn == nullptr || TestPawn->IsPlayerControlled())
		{
			continue;
		}

		USHealthComponent* HealthComp = Cast<USHealthComponent>(TestPawn->GetComponentByClass(USHealthComponent::StaticClass()));
		if (HealthComp && HealthComp->GetHealth() > 0.0f)
		{
			bIsAnyBotAlive = true;
			break;
		}
	}

	if (!bIsAnyBotAlive)
	{
		SetWaveState(WaveState::WaveComplete);
		PrepareForNextWave();
	}

}

void ASGameMode::CheckAnyPlayerAlive()
{
	for(FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		APlayerController* PC = It->Get();
		if(PC && PC->GetPawn())
		{
			APawn* Pawn = PC->GetPawn();
			USHealthComponent* HealthComp = Cast<USHealthComponent>(Pawn->GetComponentByClass(USHealthComponent::StaticClass()));
			if (ensure((HealthComp)) && HealthComp->GetHealth() > 0)
				return;
		}
	}

	GameOver();
}

void ASGameMode::GameOver()
{
	EndWave();
	UE_LOG(LogTemp, Log, TEXT("Game Over!!"));
	SetWaveState(WaveState::GameOver);
}

void ASGameMode::SetWaveState(WaveState NewState)
{
	ASGameState* GS = GetGameState<ASGameState>();
	if(ensureAlways(GS))
	{
		GS->SetWaveState(NewState);
	}
}

