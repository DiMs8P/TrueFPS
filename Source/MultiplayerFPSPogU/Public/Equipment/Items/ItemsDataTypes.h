// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "ItemsDataTypes.generated.h"

UCLASS(Blueprintable, BlueprintType, Const)
class MULTIPLAYERFPSPOGU_API UItemPickupDefinition : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<ABaseItem> BaseWeaponClass;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FTransform LocalOffset;
};
