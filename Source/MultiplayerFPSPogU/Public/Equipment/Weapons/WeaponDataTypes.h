// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "WeaponDataTypes.generated.h"

UCLASS(Blueprintable, BlueprintType, Const)
class MULTIPLAYERFPSPOGU_API UWeaponPickupDefinition : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<ABaseWeapon> BaseWeaponClass;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FTransform LocalOffset;
};
