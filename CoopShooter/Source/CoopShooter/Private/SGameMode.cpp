// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameMode.h"
#include "TimerManager.h"



ASGameMode::ASGameMode()
{
	TimeBetweenWaves = 2;
}

void ASGameMode::StartPlay()
{
	Super::StartPlay();
	PrepareForNextWave();
}

void ASGameMode::StartWave()
{
	++WaveCount;
	NumOfBotsToSpawn = 2 * WaveCount;
	GetWorldTimerManager().SetTimer(BotSpawnTimer, this, &ASGameMode::SpawnNewBot, 1, true, 0);
}

void ASGameMode::EndWave()
{
	GetWorldTimerManager().ClearTimer(BotSpawnTimer);
	PrepareForNextWave();
}

void ASGameMode::PrepareForNextWave()
{
	FTimerHandle NextWaveTimer;
	GetWorldTimerManager().SetTimer(NextWaveTimer, this, &ASGameMode::StartWave, TimeBetweenWaves, false);
}

void ASGameMode::SpawnBotTimerElapsed()
{
	SpawnNewBot();
	--NumOfBotsToSpawn;
	if (NumOfBotsToSpawn == 0)
		EndWave();
}


