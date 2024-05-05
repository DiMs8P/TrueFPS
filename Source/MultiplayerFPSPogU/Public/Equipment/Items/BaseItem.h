// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UCLASS(Abstract)
class MULTIPLAYERFPSPOGU_API ABaseItem : public AActor
{
    GENERATED_BODY()

public:
    ABaseItem();

protected:
    virtual void BeginPlay() override;
};