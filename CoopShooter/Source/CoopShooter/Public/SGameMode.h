// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COOPSHOOTER_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	FTimerHandle BotSpawnTimer;
	int32 NumOfBotsToSpawn;
	int32 WaveCount;

	UPROPERTY(EditDefaultsOnly, Category="GameMode")
	int32 TimeBetweenWaves;

	UFUNCTION(BlueprintImplementableEvent, Category="GameMode")
	void SpawnNewBot();
	
	void StartWave();
	void EndWave();
	void PrepareForNextWave();
	void SpawnBotTimerElapsed();

public:

	ASGameMode();
	virtual void StartPlay() override;
	
	
};
