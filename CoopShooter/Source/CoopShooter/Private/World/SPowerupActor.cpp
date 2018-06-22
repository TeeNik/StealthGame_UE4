// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerupActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ASPowerupActor::ASPowerupActor()
{
	PowerUpInterval = 0;
	NumOfTicks = 0;

	IsPowerUpActive = false;

	SetReplicates(true);
}

// Called when the game starts or when spawned
void ASPowerupActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASPowerupActor::OnTickPowerup()
{
	++TicksProcessed;
	OnPowerupTicked();
	if (TicksProcessed >= NumOfTicks) {
		OnExpired();
		IsPowerUpActive = false;
		OnRep_PowerUpActive();
		GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
	}
}

void ASPowerupActor::OnRep_PowerUpActive()
{
	OnPowerUpStateChanged(IsPowerUpActive);
}

void ASPowerupActor::ActivatePowerup()
{
	OnActivated();
	IsPowerUpActive = true;
	OnRep_PowerUpActive();

	if (PowerUpInterval > 0)
		GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerup, PowerUpInterval, true);
	else
		OnTickPowerup();
}

void ASPowerupActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASPowerupActor, IsPowerUpActive);
}

