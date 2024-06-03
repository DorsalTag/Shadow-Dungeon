// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerRespawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"

// Sets default values
APlayerRespawn::APlayerRespawn()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DetectionRadius = 200.0f; // Adjust this value as needed
}

// Called when the game starts or when spawned
void APlayerRespawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerRespawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckPlayerProximity();
}

// Called to bind functionality to input
void APlayerRespawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerRespawn::CheckPlayerProximity()
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        float DistanceToPlayer = FVector::Dist(GetActorLocation(), PlayerPawn->GetActorLocation());
        if (DistanceToPlayer <= DetectionRadius)
        {
            // Reset the level when the AI guard is close to the player
            UGameplayStatics::OpenLevel(GetWorld(), FName(*GetWorld()->GetName()), false);
        }
    }
}

