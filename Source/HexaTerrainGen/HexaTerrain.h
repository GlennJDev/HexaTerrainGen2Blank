// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexaTerrain.generated.h"

class UInstancedStaticMeshComponent;

UCLASS()
class HEXATERRAINGEN_API AHexaTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexaTerrain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintNativeEvent, Category = "TerrainGeneration")
	void BuildTerrain();
	virtual void BuildTerrain_Implementation();

	// Length of the hexagon terrain in x direction
	UPROPERTY(BlueprintReadonly, EditAnywhere, Category = "Dimensions")
	int32 MaxX = 32;
	// Length of the hexagon terrain in y direction
	UPROPERTY(BlueprintReadonly, EditAnywhere, Category = "Dimensions")
	int32 MaxY = 32;
	// Radius of the hexagon tile
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Dimensions")
	float TileRadius = 10;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, Category = "Tiles")
	UInstancedStaticMeshComponent* Floor;
public:
	UFUNCTION(BlueprintPure, Category = "Tiles")
	FORCEINLINE UInstancedStaticMeshComponent* GetFloor() const { return this->Floor; }
};
