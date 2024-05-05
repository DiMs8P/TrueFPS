// Fill out your copyright notice in the Description page of Project Settings.


#include "Equipment/Spawners/WeaponSpawner.h"


AWeaponSpawner::AWeaponSpawner()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AWeaponSpawner::BeginPlay()
{
    Super::BeginPlay();

    /*check(WeaponPool.IsEmpty())
    TObjectPtr<UWeaponPickupDefinition> WeaponPickupDefinition = WeaponPool[0];
    check(WeaponPickupDefinition)
    AActor* NewWeapon = NewObject<ABaseWeapon>(this, WeaponPickupDefinition->BaseWeaponClass);
    NewWeapon->SetActorLocation(GetActorTransform().GetLocation() + WeaponPickupDefinition->LocalOffset.GetLocation());
    NewWeapon->SetActorRotation(WeaponPickupDefinition->LocalOffset.GetRotation());
    NewWeapon->SetActorScale3D(WeaponPickupDefinition->LocalOffset.GetScale3D());*/
}

