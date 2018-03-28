// Fill out your copyright notice in the Description page of Project Settings.

#include "HexaTerrain.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/InstancedStaticMeshComponent.h"


// Sets default values
AHexaTerrain::AHexaTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->Floor = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Floor"));
	this->RootComponent = Floor;

	this->BuildTerrain();
}

// Called when the game starts or when spawned
void AHexaTerrain::BeginPlay()
{
	Super::BeginPlay();
	
	BuildTerrain();
}

// Called every frame
void AHexaTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHexaTerrain::BuildTerrain_Implementation() {
	float sine30, cosine30;
	FMath::SinCos(&sine30, &cosine30, GlobalVectorConstants::Pi[0]/6.f);
	float xCorrection = cosine30 * this->TileRadius / 2.f;
	float yCorrection = (1 -sine30) * this->TileRadius / 2.f;
	for( int i=0; i<this->MaxX; ++i ) {
		for( int j=0; j<this->MaxY; ++j ) {
			float x = cosine30 * this->TileRadius * i;
			int yCorrectionFactor = j;
			float y = TileRadius * j - ( yCorrection * yCorrectionFactor );
			if (j%2 != 0) {
				x += xCorrection;
			}
				 
			FVector v { x, y, 0.f };
			this->Floor->AddInstance(FTransform(v));
		}
	}
}