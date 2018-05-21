// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHoleActor.generated.h"
#include "Components/SphereComponent.h"

UCLASS()
class FPSGAME_API ABlackHoleActor : public AActor
{
GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHoleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Catehory = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Catehory = "Components")
	USphereComponent* OuterSphereComp;

	UPROPERTY(VisibleAnywhere, Catehory = "Components")
	USphereComponent* InnerSphereComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
