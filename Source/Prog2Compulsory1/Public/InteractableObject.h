// Copyright W.V. Koren. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interact_Interface.h"
#include "InteractableObject.generated.h"

UCLASS(Blueprintable)
class PROG2COMPULSORY1_API AInteractableObject : public AActor, public IInteract_Interface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnInteract_Implementation() override;
};
