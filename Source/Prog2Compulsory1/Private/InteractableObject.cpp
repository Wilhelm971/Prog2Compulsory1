// Copyright W.V. Koren. All Rights Reserved.


#include "InteractableObject.h"


// Sets default values
AInteractableObject::AInteractableObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInteractableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractableObject::OnInteract_Implementation()

	// Calls the Destroy Object function
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Interacting");
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AInteractableObject::DestroyObject, Duration, false);
}

void AInteractableObject::DestroyObject()
{
	Destroy();
}

