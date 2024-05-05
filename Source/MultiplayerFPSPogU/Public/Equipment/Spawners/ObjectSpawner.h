// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectSpawner.generated.h"

UCLASS(Abstract)
class MULTIPLAYERFPSPOGU_API AObjectSpawner : public AActor
{
    GENERATED_BODY()

public:
    AObjectSpawner();

protected:
    virtual void BeginPlay() override;
};