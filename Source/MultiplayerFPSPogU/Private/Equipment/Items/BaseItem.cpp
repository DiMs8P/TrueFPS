// Fill out your copyright notice in the Description page of Project Settings.


#include "Equipment/Items/BaseItem.h"

ABaseItem::ABaseItem()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ABaseItem::BeginPlay()
{
    Super::BeginPlay();
}
