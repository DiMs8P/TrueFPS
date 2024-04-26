// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentsDataTypes.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FpsCharacterMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MULTIPLAYERFPSPOGU_API UFpsCharacterMovementComponent : public UCharacterMovementComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Fps|CharacterMovement")
    const FFpsCharacterGroundInfo& GetGroundInfo();

protected:

    // Cached ground info for the character.  Do not access this directly!  It's only updated when accessed via GetGroundInfo().
    FFpsCharacterGroundInfo CachedGroundInfo;

private:
    const float GroundTraceDistance = 100000.0f;
};
