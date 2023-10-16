// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" // ������ ���� ��������� ��� ����������� 
#include "GameFramework/Actor.h" // ������������ ���� �� �������� ���������� 
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h" // �������������� ��������������� ���� ��� ���������� 

UENUM(BlueprintType)
enum class EMovementType : uint8 {
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	
	UPROPERTY(EditAnywhere, Category = "Movment")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Movment")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movment")
	EMovementType MoveType = EMovementType::Static;

	UPROPERTY(EditAnywhere, Category = "Collor")
	FLinearColor color = FLinearColor::Black;


	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	float TimerRate = 3.0f;
};

UCLASS()
class GEMETRYSANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
 
public:
	// Sets default values for this actor's properties
	ABaseGeometryActor(); // ���������� ��� ���������� 
	
	UPROPERTY(VisibleAnywhere, Category = "Main")
	UStaticMeshComponent* BaseMesh;

	void SetGeometryData(const FGeometryData& Data) { GeometryData = Data; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; // ���������� ���� ��� ����� �������� ���� ��� ����� ����� ��������� 
	
	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsNum = 44;

	UPROPERTY(EditAnywhere, Category = "Geometry Data")
	FGeometryData GeometryData;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 killsNum = 23;
	
	UPROPERTY(EditInstanceOnly, Category = "helth")
	float HEatlth = 34.323323f;
	
	UPROPERTY(EditAnywhere, Category = "helth")
	bool isDead = false;
	
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool hasWeapon = false;	



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; // ������ ��� ���������� 

private: 
	FVector InitionLocation;
	FTimerHandle TimerHandle; 

	const int32 MaxTimerCount = 2;
	int32 TimerCoutn = 0;

	void printTypes();
	void printStringTypes();
	void printTransform();
	void HandleMovment();
	void SetColor(const FLinearColor& color);
	void OnTimeFired();
};
