// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryHubActor.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGemoetryHub, All, All);

// Sets default values
AGeometryHubActor::AGeometryHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();


 
	
	UWorld* World = GetWorld();
	if (World) {
		//for (int32 i = 0; i < 10; ++i) {
		//	const FTransform GemetryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 300.0f));
		//	ABaseGeometryActor* Geometry = World->SpawnActor<ABaseGeometryActor>(GeometryClass, GemetryTransform);
		//	

		//	if (Geometry) {
		//		FGeometryData Data;
		//		Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
		//		Geometry->SetGeometryData(Data);
		//	}

		//	
		//}

		//for (int32 i = 0; i < 10; ++i) {
		//	const FTransform GemetryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 700.0f));
		//	ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(GeometryClass, GemetryTransform); // ��� ������� beginPlay


		//	if (Geometry) {
		//		FGeometryData Data;
		//		Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
		//		Data.color = FLinearColor::MakeRandomColor();

		//		Geometry->SetGeometryData(Data);
		//		Geometry->FinishSpawning(GemetryTransform);
		//	}


		//}

		for (const FGeometeryPayload payload : GeometryPayloads) {
			ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(payload.GeometryClass, payload.InitialTransform); // ��� ������� beginPlay
			if (Geometry) {
				Geometry->SetGeometryData(payload.Data);
				
				Geometry->OnColorChanged.AddDynamic(this, &AGeometryHubActor::OnColorChanged);
				Geometry->OnTimerFinished.AddUObject(this, &AGeometryHubActor::OnTimerFinished);
				
				Geometry->FinishSpawning(payload.InitialTransform);
			}
		}
	}

}

// Called every frame
void AGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGeometryHubActor::OnColorChanged(const FLinearColor& Color, const FString& Name)
{
	UE_LOG(LogBaseGemoetryHub, Warning, TEXT("Actor name %s Color %s"), *Name, *Color.ToString());
}

void AGeometryHubActor::OnTimerFinished(AActor* Actor)
{
	if (Actor) {
		UE_LOG(LogBaseGemoetryHub, Error, TEXT("Timer is stoped actor -> %s "), *Actor->GetName());

		ABaseGeometryActor* Geometry = Cast<ABaseGeometryActor>(Actor);


		if (!Geometry) {
			UE_LOG(LogBaseGemoetryHub, Error, TEXT("--- EXIT ---"));
			return;
		}
		 
		UE_LOG(LogBaseGemoetryHub, Display, TEXT("Cust is SUCCESS %f"), Geometry->GetGeometryData().Amplitude);

		Geometry->Destroy();
	}

}

