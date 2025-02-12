// Copyright W.V. Koren. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interact_Interface.h"
#include "InputActionValue.h"
#include "PlayerCharacterCPP.generated.h"

UCLASS()
class PROG2COMPULSORY1_API APlayerCharacterCPP : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "True"))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "True"))
	class USpringArmComponent* SpringArm;

protected:
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* SprintAction;

public:
	// Sets default values for this character's properties
	APlayerCharacterCPP();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HUD")
	int CurrentCount = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	// Input functions
	void Move(const FInputActionValue& InputValue);
	void Look(const FInputActionValue& InputValue);
	void JumpEvent();
	void Interact();

	 // Sprinting
	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RunSpeed;
	void StartSprint();
	void EndSprint();



};
