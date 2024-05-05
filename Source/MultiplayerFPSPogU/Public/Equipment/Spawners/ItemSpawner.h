// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectSpawner.h"
#include "ItemSpawner.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERFPSPOGU_API AItemSpawner : public AObjectSpawner
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;
};
