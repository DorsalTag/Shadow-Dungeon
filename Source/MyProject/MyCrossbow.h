// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "MyCrossbow.generated.h"

class AMyProjectCharacter;

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_API UMyCrossbow : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<class AMyProjectProjectile> currentArrowClass;


	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<class AMyProjectProjectile> FireArrowClass;

	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<class AMyProjectProjectile> WaterProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector FirePointOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* FireMappingContext;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SwapArrowAction;

	UMyCrossbow();

	//UFUNCTION(BlueprintCallable, Category = "Weapon")
	//void AttachWeapon(AMyProjectCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

	//UFUNCTION(BlueprintCallable, Category = "Weapon")
	//void SwapArrow();



protected:

	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:

	AMyProjectCharacter* Character;
};
