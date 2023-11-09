#include "BaseGeometryActor.h" // Fill out your copyright notice in the Description page of Project Settings.
#include "BaseGeometryActor.h"
#include "Engine/Engine.h"
#include "Materials/Materialinstance.h"
#include "TimerManager.h"
 
DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)



// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; // Тик вызвывается каждый фрейм

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitionLocation = GetActorLocation();
	


	// printTransform();
	// printStringTypes();
	// printTypes();

	SetColor(GeometryData.color);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseGeometryActor::OnTimeFired, GeometryData.TimerRate, true);
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HandleMovment();
}

void ABaseGeometryActor::printTypes()
{
   
	UE_LOG(LogTemp, Error, TEXT("Weapons num %d , kills num : %i"), WeaponsNum, killsNum);
	UE_LOG(LogTemp, Error, TEXT("Weapons num %f"), HEatlth);
	UE_LOG(LogTemp, Error, TEXT("Weapons num %d"), isDead);
	UE_LOG(LogTemp, Error, TEXT("hasWeapon num %d "), static_cast<int>(hasWeapon));
}

void ABaseGeometryActor::printStringTypes()
{
	FString Name = "JHON CONOR";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	FString weaponsNumStr = "Weapons num = " + FString::FromInt(12);
	FString healthString = "health num = " + FString::FromInt(12);
	FString isDeadStr = "is dead = " + FString(true ? "true" : "false");


	FString stat = FString::Printf(TEXT("\n=== All stats ===\n%s \n%s \n%s"), *weaponsNumStr, *healthString, *isDeadStr);

	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *stat);

	GEngine->AddOnScreenDebugMessage(-1, INFINITY, FColor::Red, *stat);
}

void ABaseGeometryActor::printTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FVector Scale = Transform.GetScale3D();
	FRotator Rotation = Transform.Rotator();

	UE_LOG(LogTemp, Error, TEXT("Weapons num %s"), *Transform.ToString());
	UE_LOG(LogTemp, Error, TEXT("Weapons num %s"), *Location.ToString());
	UE_LOG(LogTemp, Error, TEXT("Weapon	s num %s"), *Rotation.ToString());
	UE_LOG(LogTemp, Error, TEXT("Weapon	s num %s"), *Scale.ToString()); 
}

 
void ABaseGeometryActor::HandleMovment() {
	switch (GeometryData.MoveType)
	{
	case EMovementType::Sin:
		FVector curentLocation = GetActorLocation();
		float time = GetWorld()->GetTimeSeconds();
		curentLocation.Z = InitionLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * time);
		SetActorLocation(curentLocation);

		break;
	}
}

void ABaseGeometryActor::OnTimeFired()
{
	if (++TimerCoutn <= MaxTimerCount) {
		const FLinearColor color = FLinearColor::MakeRandomColor();
		SetColor(color);
	}
	else {
		GetWorldTimerManager().ClearTimer(TimerHandle);
		UE_LOG(LogTemp, Display, TEXT("TIMER -> DONE"));
	}
}

void ABaseGeometryActor::SetColor(const FLinearColor& color) {
	UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynMaterial) {
		DynMaterial->SetVectorParameterValue("Color", color);
	}
}