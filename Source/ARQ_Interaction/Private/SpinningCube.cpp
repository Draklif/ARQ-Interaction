// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinningCube.h"

// Sets default values
ASpinningCube::ASpinningCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    RootComponent = MeshComp;

    // Carga el cubo básico del motor para ver algo de inmediato
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(
        TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeAsset.Succeeded())
    {
        MeshComp->SetStaticMesh(CubeAsset.Object);
    }
}

void ASpinningCube::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("SpinningCube listo. Velocidad = %f"), SpinSettings.RotationSpeed);
}

void ASpinningCube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!SpinSettings.bIsSpinning) return;

    const float Delta = SpinSettings.RotationSpeed * DeltaTime;
    FRotator Rot = FRotator::ZeroRotator;
    switch (SpinSettings.Axis)
    {
        case ESpinAxis::Yaw:   Rot.Yaw = Delta; break;
        case ESpinAxis::Pitch: Rot.Pitch = Delta; break;
        case ESpinAxis::Roll:  Rot.Roll = Delta; break;
    }
    AddActorLocalRotation(Rot);

    AccumulatedYaw += Delta;
    if (AccumulatedYaw >= 360.f)
    {
        AccumulatedYaw -= 360.f;
        OnFullRotation();
    }
}

void ASpinningCube::ToggleSpin()
{
    SpinSettings.bIsSpinning = !SpinSettings.bIsSpinning;
    UE_LOG(LogTemp, Warning, TEXT("ToggleSpin llamado. Ahora girando = %s"),
        SpinSettings.bIsSpinning ? TEXT("true") : TEXT("false"));
}