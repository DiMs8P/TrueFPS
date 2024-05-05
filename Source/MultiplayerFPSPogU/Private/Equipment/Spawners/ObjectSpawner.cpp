// Fill out your copyright notice in the Description page of Project Settings.


#include "Equipment/Spawners/ObjectSpawner.h"

AObjectSpawner::AObjectSpawner()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AObjectSpawner::BeginPlay()
{
    Super::BeginPlay();
}
