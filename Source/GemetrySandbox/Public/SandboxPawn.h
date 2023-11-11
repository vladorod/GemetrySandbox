// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SandboxPawn.generated.h"

class UCameraComponent;

UCLASS()
class GEMETRYSANDBOX_API ASandboxPawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere)
	float Velocity = 300.0f;

public:
	// Sets default values for this pawn's properties
	ASandboxPawn();

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private: 
	FVector VelocityVector = FVector::ZeroVector;

	void MoveForward(float Amount);
	void MoveRight(float Amount);
};
