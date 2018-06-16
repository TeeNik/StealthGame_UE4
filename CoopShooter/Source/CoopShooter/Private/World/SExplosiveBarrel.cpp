// Fill out your copyright notice in the Description page of Project Settings.

#include "SExplosiveBarrel.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{

	HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComp"));
	HealthComp->OnHealthChanged.AddDynamic(this, &ASExplosiveBarrel::OnHealthChanged);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionObjectType(ECC_PhysicsBody);
	RootComponent = MeshComp;

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
	RadialForceComp->SetupAttachment(MeshComp);
	RadialForceComp->Radius = 250;
	RadialForceComp->bImpulseVelChange = true;
	RadialForceComp->bAutoActivate = false;
	RadialForceComp->bIgnoreOwningActor = true;

	ExplosionImpulse = 400;
}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASExplosiveBarrel::OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (isExploded) return;
	
	if (Health <= 0)
	{
		isExploded = true;
		FVector BoostIntensity = FVector::UpVector*ExplosionImpulse;
		MeshComp->AddImpulse(BoostIntensity, NAME_None, true);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
		MeshComp->SetMaterial(0, ExplodeMaterial);
		RadialForceComp->FireImpulse();
		UGameplayStatics::ApplyRadialDamage(GetWorld(), 100, GetActorLocation(), 400, NULL, TArray<AActor*>(), DamageCauser, InstigatedBy, true, ECC_WorldDynamic);
	}
}

