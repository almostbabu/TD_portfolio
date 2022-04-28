// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGridManager.h"
#include "HexTile.h"

// Sets default values
AHexGridManager::AHexGridManager()
{

}

void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();
	
	HexGrid2DArray.SetNumZeroed(GridWidth);
	for (int32 i = 0; i < HexGrid2DArray.Num(); i++)
	{
		HexGrid2DArray[i].SetNumZeroed(GridHeight);
	}

	for (int32 y = 0; y < GridHeight; y++)
	{
		for (int32 x = 0; x < GridWidth; x++)
		{
			const bool oddRow = y % 2 == 1;
			const float xPos = x * TileHorizontalOffset;
			const float yPos = y * TileVerticalOffset;

			TSubclassOf<AHexTile> tileToSpawn = GrassHexTile;

			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, FVector(FIntPoint(xPos, yPos)), FRotator::ZeroRotator);
			newTile->TileIndex = FIntPoint(x, y);
			newTile->SetActorLabel(FString::Printf(TEXT("Tile_%d-%d"), x, y));
			HexGrid2DArray[x][y] = newTile;
		}
	}
}
