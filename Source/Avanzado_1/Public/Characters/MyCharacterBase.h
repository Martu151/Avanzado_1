// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReglasBase.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacterBase.generated.h"

UCLASS()
class AVANZADO_1_API AMyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterBase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* cam;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite) AReglasBase* GMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int characterLife;

	UPROPERTY(EditAnywhere) float movSpeed;
	UPROPERTY(EditAnywhere) float rotSpeed;

	//Datos del arma
	//UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> actualWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AActor* actualWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int maxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int damageDecrement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString weaponName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int cartridgeCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int actualBullets;

	void VerticalAxis(float valor);
	void HorizontalAxis(float valor);
	void HorizontalLookAxis(float valor);
	void VerticalLookAxis(float valor);
	void StartJump();
	void EndJump();
	void StartAim();
	void EndAim();
	void Shoot();
	void Reload();


	float GVS;

	UPROPERTY(BlueprintReadWrite) int movimientoAnim;
	UPROPERTY(BlueprintReadWrite) bool jumping;
	UPROPERTY(BlueprintReadWrite) bool aiming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FName, float> boneDamages;

	UPROPERTY(EditAnywhere) TSubclassOf<AActor> ExplotionPart;

	//Sonidos
	UPROPERTY(EditAnywhere) USoundBase* noAmmoSound;
	UPROPERTY(EditAnywhere) USoundBase* reloadSound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
