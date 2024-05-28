// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTorchScript.h"

// Sets default values for this component's properties
UMyTorchScript::UMyTorchScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyTorchScript::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyTorchScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyTorchScript::OnOverLapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{

}

