// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "FPSBaseCharacter.generated.h"

class UFpsPawnExtensionComponent;

UCLASS()
class MULTIPLAYERFPSPOGU_API AFPSBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSBaseCharacter(const FObjectInitializer& ObjInit);

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fps|Character", Meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UFpsPawnExtensionComponent> PawnExtComponent;
};
