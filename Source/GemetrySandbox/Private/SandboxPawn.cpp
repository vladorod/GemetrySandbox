// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxPawn.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"


DEFINE_LOG_CATEGORY_STATIC(LogSandboxPawn, All, All)

// Sets default values
ASandboxPawn::ASandboxPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());


	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());
}

void ASandboxPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	UE_LOG(LogSandboxPawn, Display, TEXT("Possessed"));
	
}

void ASandboxPawn::UnPossessed()
{
	Super::UnPossessed();
	UE_LOG(LogSandboxPawn, Display, TEXT("UnPossessed"));
}

// Called when the game starts or when spawned
void ASandboxPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASandboxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogSandboxPawn, Display, TEXT("VelocityVector X : %f"), VelocityVector.X);

	
	// isControlled || isPlayerControlled

	if (!VelocityVector.IsZero()) {
		const FVector NewLocation = GetActorLocation() + Velocity * DeltaTime * VelocityVector;

		UE_LOG(LogSandboxPawn, Display, TEXT("bool : %d"), !VelocityVector.IsZero() ? 1 : 0);
		SetActorLocation(NewLocation);
		VelocityVector = FVector::ZeroVector;
	}
}

// Called to bind functionality to input
void ASandboxPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASandboxPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASandboxPawn::MoveRight);
}

void ASandboxPawn::MoveForward(float Amount)
{
 
	VelocityVector.X = Amount;
}

void ASandboxPawn::MoveRight(float Amount)
{
 
	VelocityVector.Y = Amount;
}

