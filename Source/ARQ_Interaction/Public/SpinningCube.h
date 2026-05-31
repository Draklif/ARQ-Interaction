// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LabTypes.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinningCube.generated.h"

UCLASS()
class ARQ_INTERACTION_API ASpinningCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinningCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Función llamable desde Blueprint: enciende/apaga el giro
	UFUNCTION(BlueprintCallable, Category = "Lab")
	void ToggleSpin();

	// C++ DISPARA esto; el cuerpo lo escribe el Blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = "Lab")
	void OnFullRotation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lab")
	FSpinSettings SpinSettings;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	float AccumulatedYaw = 0.f;
};
