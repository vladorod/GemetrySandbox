// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" // Базоые типы константы для логирования 
#include "GameFramework/Actor.h" // Заголовочный файл от которого логируемся 
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h" // Автоматический сгенерированный файл для заголовков 
 

 

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnColorChanged, const FLinearColor&, Color, const FString&, Name);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTimerFinished, AActor*);

UENUM(BlueprintType)
enum class EMovementType : uint8 {
	Sin,
	Static
};


USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movment")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movment")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movment")
	EMovementType MoveType = EMovementType::Static;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collor")
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
	ABaseGeometryActor(); // Коструктор для переменных 
	
	UPROPERTY(VisibleAnywhere, Category = "Main")
	UStaticMeshComponent* BaseMesh;

	void SetGeometryData(const FGeometryData& Data) { GeometryData = Data; }

	UFUNCTION(BlueprintCallable)
	FGeometryData GetGeometryData() const { return GeometryData; }

	UPROPERTY(BlueprintAssignable)
	FOnColorChanged OnColorChanged;

	FOnTimerFinished OnTimerFinished;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; // Вызывается один раз когда началась игра или когда актор заспавнен 
	
	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsNum = 44;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry Data")
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
	virtual void Tick(float DeltaTime) override; // Каждый тик вызывается 

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
