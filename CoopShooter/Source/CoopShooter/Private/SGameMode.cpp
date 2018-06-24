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
}

void ASGameMode::StartWave()
{
	++WaveCount;
	NumOfBotsToSpawn = 2 * WaveCount;
	GetWorldTimerManager().SetTimer(BotSpawnTimer, this, &ASGameMode::SpawnBotTimerElapsed, 1, true, 0);
}

void ASGameMode::EndWave()
{
	GetWorldTimerManager().ClearTimer(BotSpawnTimer);
}

void ASGameMode::PrepareForNextWave()
{
	GetWorldTimerManager().SetTimer(NextWaveTimer, this, &ASGameMode::StartWave, TimeBetweenWaves, false);
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
		PrepareForNextWave();
	}

}

