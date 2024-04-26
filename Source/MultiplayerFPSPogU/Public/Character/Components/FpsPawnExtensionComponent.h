// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "Components/PawnComponent.h"

#include "FpsPawnExtensionComponent.generated.h"


class UAbilitySystemComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MULTIPLAYERFPSPOGU_API UFpsPawnExtensionComponent : public UPawnComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UFpsPawnExtensionComponent(const FObjectInitializer& ObjectInitializer);

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /** Gets the current ability system component, which may be owned by a different actor */
    UFUNCTION(BlueprintPure, Category = "Lyra|Pawn")
    UAbilitySystemComponent* GetLyraAbilitySystemComponent() const { return AbilitySystemComponent; }

    /** Pointer to the ability system component that is cached for convenience. */
    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
