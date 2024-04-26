// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/FpsCharacterMovementComponent.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"

const FFpsCharacterGroundInfo& UFpsCharacterMovementComponent::GetGroundInfo()
{
    if (!CharacterOwner || (GFrameCounter == CachedGroundInfo.LastUpdateFrame))
    {
        return CachedGroundInfo;
    }

    if (MovementMode == MOVE_Walking)
    {
        CachedGroundInfo.GroundHitResult = CurrentFloor.HitResult;
        CachedGroundInfo.GroundDistance = 0.0f;
    }
    else
    {
        const UCapsuleComponent* CapsuleComp = CharacterOwner->GetCapsuleComponent();
        check(CapsuleComp);

        const float CapsuleHalfHeight = CapsuleComp->GetUnscaledCapsuleHalfHeight();
        const ECollisionChannel CollisionChannel = (UpdatedComponent ? UpdatedComponent->GetCollisionObjectType() : ECC_Pawn);
        const FVector TraceStart(GetActorLocation());
        const FVector TraceEnd(TraceStart.X, TraceStart.Y, (TraceStart.Z - GroundTraceDistance - CapsuleHalfHeight));

        FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(LyraCharacterMovementComponent_GetGroundInfo), false, CharacterOwner);
        FCollisionResponseParams ResponseParam;
        InitCollisionParams(QueryParams, ResponseParam);

        FHitResult HitResult;
        GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, CollisionChannel, QueryParams, ResponseParam);

        CachedGroundInfo.GroundHitResult = HitResult;
        CachedGroundInfo.GroundDistance = GroundTraceDistance;

        if (MovementMode == MOVE_NavWalking)
        {
            CachedGroundInfo.GroundDistance = 0.0f;
        }
        else if (HitResult.bBlockingHit)
        {
            CachedGroundInfo.GroundDistance = FMath::Max((HitResult.Distance - CapsuleHalfHeight), 0.0f);
        }
    }

    CachedGroundInfo.LastUpdateFrame = GFrameCounter;

    return CachedGroundInfo;
}
