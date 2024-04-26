// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/UFPSAnimInstance.h"

#include "AbilitySystemGlobals.h"
#include "Character/Components/FpsCharacterMovementComponent.h"
#include "Misc/DataValidation.h"
#include "Player/FPSBaseCharacter.h"

void UUFPSAnimInstance::InitializeWithAbilitySystem(UAbilitySystemComponent* ASC)
{
    check(ASC);

    GameplayTagPropertyMap.Initialize(this, ASC);
}

#if WITH_EDITOR
EDataValidationResult UUFPSAnimInstance::IsDataValid(FDataValidationContext& Context) const
{
    Super::IsDataValid(Context);

    GameplayTagPropertyMap.IsDataValid(this, Context);

    return ((Context.GetNumErrors() > 0) ? EDataValidationResult::Invalid : EDataValidationResult::Valid);
}
#endif // WITH_EDITOR

void UUFPSAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    if (const AActor* OwningActor = GetOwningActor())
    {
        if (UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwningActor))
        {
            InitializeWithAbilitySystem(ASC);
        }
    }
}

void UUFPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    const AFPSBaseCharacter* Character = Cast<AFPSBaseCharacter>(GetOwningActor());
    if (!Character)
    {
        return;
    }

    UFpsCharacterMovementComponent* CharMoveComp = CastChecked<UFpsCharacterMovementComponent>(Character->GetCharacterMovement());
    const FFpsCharacterGroundInfo& GroundInfo = CharMoveComp->GetGroundInfo();
    GroundDistance = GroundInfo.GroundDistance;
}
