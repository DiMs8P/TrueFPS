// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectSpawner.h"
#include "Equipment/Weapons/WeaponDataTypes.h"
#include "WeaponSpawner.generated.h"

UCLASS()
class MULTIPLAYERFPSPOGU_API AWeaponSpawner : public AObjectSpawner
{
    GENERATED_BODY()

public:
    AWeaponSpawner();

protected:
    virtual void BeginPlay() override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TArray<TObjectPtr<UWeaponPickupDefinition>> WeaponPool;
};