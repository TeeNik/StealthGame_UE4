// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SHealthComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "SExplosiveBarrel.generated.h"

UCLASS()
class COOPSHOOTER_API ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USHealthComponent* HealthComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* RadialForceComp;

	UFUNCTION()
	void OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	
	UPROPERTY(ReplicatedUsing=OnRep_Exploded)
	bool IsExploded;

	UFUNCTION()
	void OnRep_Exploded();

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	float ExplosionImpulse;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UParticleSystem* ExplosionEffect;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UMaterialInterface* ExplodeMaterial ;
	
};
