// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "FpsGameplayStatics.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERFPSPOGU_API UFpsGameplayStatics : public UGameplayStatics
{
    GENERATED_BODY()

public:
    template <typename TSubsystemType>
    static typename TEnableIf<TIsDerivedFrom<TSubsystemType, UEngineSubsystem>::IsDerived, TSubsystemType*>::Type GetSubsystem(UObject* WorldContextObject)
    {
        return GEngine->GetEngineSubsystem<TSubsystemType>();
    }

    template <typename TSubsystemType>
    static typename TEnableIf<TIsDerivedFrom<TSubsystemType, ULocalPlayerSubsystem>::IsDerived, TSubsystemType*>::Type GetSubsystem(UObject* WorldContextObject)
    {
        return GetGameInstance(WorldContextObject)->GetLocalPlayerByIndex(0)->GetSubsystem<TSubsystemType>();
    }

    template <typename TSubsystemType>
    static typename TEnableIf<TIsDerivedFrom<TSubsystemType, UGameInstanceSubsystem>::IsDerived, TSubsystemType*>::Type GetSubsystem(UObject* WorldContextObject)
    {
        return GetGameInstance(WorldContextObject)->GetSubsystem<TSubsystemType>();
    }

    template <typename TSubsystemType>
    static typename TEnableIf<TIsDerivedFrom<TSubsystemType, UWorldSubsystem>::IsDerived, TSubsystemType*>::Type GetSubsystem(UObject* WorldContextObject)
    {
        return WorldContextObject->GetWorld()->GetSubsystem<TSubsystemType>();
    }
};

#define SUBSYSTEM_GET(SubsystemType, WorldContextObject) \
UFpsGameplayStatics::GetSubsystem()

