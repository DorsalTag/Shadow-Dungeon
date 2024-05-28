// Fill out your copyright notice in the Description page of Project Settings.


#include "TorchScript.h"
#include "Components/BoxComponent.h"
#include "Components/LightComponent.h"
#include "MyProject/MyProjectProjectile.h"

// Sets default values
ATorchScript::ATorchScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = BoxComp;
}

// Called when the game starts or when spawned
void ATorchScript::BeginPlay()
{
	Super::BeginPlay();
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ATorchScript::OnOverLapStart);
}

// Called every frame
void ATorchScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ATorchScript::OnOverLapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyProjectProjectile* projectile = Cast<AMyProjectProjectile>(OtherActor);

	if (projectile != nullptr)
	{
		if (projectile->FireArrow)
		{
			//enable torch
			Destroy(projectile);
		}
	}
}

