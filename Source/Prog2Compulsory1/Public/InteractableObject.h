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

	FTimerHandle DestroyTimerHandle;
	float Duration = 0.01f;
	
	

public:
	// Sets default values for this actor's properties
	AInteractableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnInteract_Implementation() override;

	void DestroyObject();
};
