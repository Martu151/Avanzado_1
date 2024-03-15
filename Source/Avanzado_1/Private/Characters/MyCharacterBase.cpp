// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MyCharacterBase.h"
#include "Components/InputComponent.h"
#include "Enemigos/EnemigoBase.h"
#include "IDamagable.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ReglasBase.h"

// Sets default values
AMyCharacterBase::AMyCharacterBase()
{
	movSpeed = 500;
	rotSpeed = 180;

	characterLife = 100;

	maxDamage = 50;
	damageDecrement = 10;

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cam = CreateDefaultSubobject<UCameraComponent>("Camera");
	cam->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	//GMode = Cast<AReglasBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AMyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Animacion del Movimiento
	GVS = GetVelocity().Size();
	if (GVS > 0 && GVS < 100)
	{
		//Camina
		movimientoAnim = 1;
	}
	else if(GVS > 100)
	{
		//Corre
		movimientoAnim = 2;
	}
	else {
		//Idle
		movimientoAnim = 0;
	}

	//Animacion del Salto
	FVector verticalVelocity = GetVelocity();
	verticalVelocity.X = 0;
	verticalVelocity.Y = 0;
	if (verticalVelocity.Size() > 0) 
	{
		jumping = true;
	}
	else
	{
		jumping = false;
	}
}

// Called to bind functionality to input
void AMyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("VerticalMov", this, &AMyCharacterBase::VerticalAxis);
	PlayerInputComponent->BindAxis("HorizontalMov", this, &AMyCharacterBase::HorizontalAxis);
	PlayerInputComponent->BindAxis("HorizontalLook", this, &AMyCharacterBase::HorizontalLookAxis);
	PlayerInputComponent->BindAxis("VerticalLook", this, &AMyCharacterBase::VerticalLookAxis);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacterBase::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacterBase::EndJump);
	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &AMyCharacterBase::StartAim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &AMyCharacterBase::EndAim);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMyCharacterBase::Shoot);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AMyCharacterBase::Reload);
}

void AMyCharacterBase::VerticalAxis(float valor) 
{
	float deltaSeconds = GetWorld()->GetDeltaSeconds();
	FVector movement = GetActorForwardVector() * movSpeed * deltaSeconds * valor;
	AddMovementInput(movement);
}

void AMyCharacterBase::HorizontalAxis(float valor)
{
	float deltaSeconds = GetWorld()->GetDeltaSeconds();
	FVector movement = GetActorRightVector() * movSpeed * deltaSeconds * valor;
	AddMovementInput(movement);
}

void AMyCharacterBase::HorizontalLookAxis(float valor)
{
	float deltaSeconds = GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(rotSpeed *deltaSeconds * valor);
}

void AMyCharacterBase::VerticalLookAxis(float valor)
{
	float deltaSeconds = GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(rotSpeed * deltaSeconds * valor);
}

void AMyCharacterBase::StartJump()
{
	Jump();
}

void AMyCharacterBase::EndJump()
{
	StopJumping();
}

void AMyCharacterBase::StartAim()
{
	aiming = true;
}

void AMyCharacterBase::EndAim()
{
	aiming = false;
}

void AMyCharacterBase::Shoot()
{
	//UE_LOG(LogTemp, Warning, TEXT("BALAS: %s"), actualBullets);

	if (aiming && actualWeapon != nullptr && actualBullets > 0)
	{
		TArray<FHitResult> hits;
		FVector lineOrigin = GetActorLocation();
		FVector lineEnd = lineOrigin + GetActorForwardVector()*1000;
		bool hit = GetWorld()->LineTraceMultiByChannel(hits, lineOrigin, lineEnd, ECC_GameTraceChannel1);

		float currentDamage = maxDamage;

		//DrawDashedLine(GetWorld(), lineOrigin, lineEnd, FColor::Red, false, 3);

		for (int i = 0; i < hits.Num(); i++)
		{
			FHitResult hitInfo = hits[i];
			IIDamagable* damageable = Cast<IIDamagable>(hitInfo.GetActor());

			if (damageable != nullptr && boneDamages.Contains(hitInfo.BoneName))
			{
				float damagePercentage = boneDamages[hitInfo.BoneName];
				damageable->TakeDamage(currentDamage * damagePercentage);
			}

			currentDamage -= damageDecrement;

			if (currentDamage <= 0) 
			{
				break;
			}

		}

		FVector expPos = FVector(actualWeapon->GetActorLocation().X, actualWeapon->GetActorLocation().Y, actualWeapon->GetActorLocation().Z); //FVector(GetActorLocation().X+200, GetActorLocation().Y+80, GetActorLocation().Z +40);
		GetWorld()->SpawnActor<AActor>(ExplotionPart, expPos, GetActorRotation());

		actualBullets--;

		/*if (hit)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit"));
			IIDamagable* damagable = Cast<IIDamagable>(hitInfo.GetActor());
			if (damagable != nullptr)
			{
				damagable->TakeDamage(50);
			}
		}*/
	}
	else if(aiming && actualBullets <= 0)
	{
		if (noAmmoSound != nullptr)
		{
			UGameplayStatics::PlaySound2D(this, noAmmoSound);
		}
		UE_LOG(LogTemp, Warning, TEXT("RECARGAAA"));
	}
	//ShootGUI();
}

void AMyCharacterBase::Reload()
{
	if(reloadSound != nullptr)
	{
		UGameplayStatics::PlaySound2D(this, reloadSound);
	}
	actualBullets = cartridgeCapacity;
}