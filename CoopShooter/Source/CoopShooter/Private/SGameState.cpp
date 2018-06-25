// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameState.h"
#include "Net/UnrealNetwork.h"



void ASGameState::OnRep_WaveState(WaveState OldState)
{
	WaveStateChange(State, OldState);
}

void ASGameState::SetWaveState(WaveState NewState)
{
	if(Role == ROLE_Authority)
	{
		WaveState OldState = State;
		State = NewState;
		OnRep_WaveState(OldState);
	}
}

void ASGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASGameState, State);
}
