#pragma once

#include "Animation/AnimSequence.h"
#include "AnimDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FCardinalDirections
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    TObjectPtr<UAnimSequence> Forward;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    TObjectPtr<UAnimSequence> Backward;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    TObjectPtr<UAnimSequence> Left;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    TObjectPtr<UAnimSequence> Right;
};

UENUM(BlueprintType)
enum class ECardinalDirection : uint8
{
    Forward = 0,
    Backward,
    Right,
    Left
};

UENUM(BlueprintType)
enum class ERootYawOffsetModeType : uint8
{
    BlendOut = 0,
    Hold,
    Accumulate
};

