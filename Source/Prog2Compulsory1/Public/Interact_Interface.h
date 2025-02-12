// Copyright W.V. Koren. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interact_Interface.generated.h"

/**
 * 
 */

UINTERFACE(MinimalAPI, Blueprintable)
class UInteract_Interface : public UInterface
{
	GENERATED_BODY()
};

class IInteract_Interface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteract();
	
};
