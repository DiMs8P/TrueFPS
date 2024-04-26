// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSBaseCharacter.h"

#include "Character/Components/FpsCharacterMovementComponent.h"
#include "Character/Components/FpsPawnExtensionComponent.h"

// Sets default values
AFPSBaseCharacter::AFPSBaseCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit.SetDefaultSubobjectClass<UFpsCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;

    PawnExtComponent = CreateDefaultSubobject<UFpsPawnExtensionComponent>(TEXT("PawnExtensionComponent"));
}

UAbilitySystemComponent* AFPSBaseCharacter::GetAbilitySystemComponent() const
{
    if (PawnExtComponent == nullptr)
    {
        return nullptr;
    }

    return PawnExtComponent->GetLyraAbilitySystemComponent();
}

// Called when the game starts or when spawned
void AFPSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AFPSBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

