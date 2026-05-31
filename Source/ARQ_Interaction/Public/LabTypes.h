#pragma once

#include "CoreMinimal.h"
#include "LabTypes.generated.h"

UENUM(BlueprintType)
enum class ESpinAxis : uint8
{
    Yaw    UMETA(DisplayName = "Yaw (horizontal)"),
    Pitch  UMETA(DisplayName = "Pitch (cabeceo)"),
    Roll   UMETA(DisplayName = "Roll (balanceo)")
};

USTRUCT(BlueprintType)
struct FSpinSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lab")
    float RotationSpeed = 90.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lab")
    ESpinAxis Axis = ESpinAxis::Yaw;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lab")
    bool bIsSpinning = true;
};