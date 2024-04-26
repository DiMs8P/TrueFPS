// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/FpsPawnExtensionComponent.h"

#include "AbilitySystemComponent.h"


// Sets default values for this component's properties
UFpsPawnExtensionComponent::UFpsPawnExtensionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    //TODO move creation logic to player state
    AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<UAbilitySystemComponent>(this, TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
    
    PrimaryComponentTick.bStartWithTickEnabled = false;
    PrimaryComponentTick.bCanEverTick = false;

    SetIsReplicatedByDefault(true);

    // TODO when logic moved uncomment it
    //AbilitySystemComponent = nullptr;
}


// Called when the game starts
void UFpsPawnExtensionComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...
    
}


// Called every frame
void UFpsPawnExtensionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

