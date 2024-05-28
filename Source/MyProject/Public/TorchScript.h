// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TorchScript.generated.h"

UCLASS()
class MYPROJECT_API ATorchScript : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorchScript();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UBoxComponent* BoxComp;
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UStaticMeshComponent* BaseMesh;
	UPROPERTY(EditInstanceOnly) class ULightComponent* LightSource;
	UFUNCTION() void OnOverLapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};

