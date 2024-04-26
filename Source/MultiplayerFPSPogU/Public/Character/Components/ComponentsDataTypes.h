// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentsDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FFpsCharacterGroundInfo
{
    GENERATED_BODY()

    FFpsCharacterGroundInfo()
        : LastUpdateFrame(0)
        , GroundDistance(0.0f)
    {}

    uint64 LastUpdateFrame;

    UPROPERTY(BlueprintReadOnly)
    FHitResult GroundHitResult;

    UPROPERTY(BlueprintReadOnly)
    float GroundDistance;
};