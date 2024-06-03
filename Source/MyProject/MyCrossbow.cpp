// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCrossbow.h"
#include "MyProjectCharacter.h"
#include "MyProjectProjectile.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

UMyCrossbow::UMyCrossbow()
{
	FirePointOffset = FVector(100, 0, 10);
}


//void UMyCrossbow::Fire()
//{
//	
//}