// Copyright W.V. Koren. All Rights Reserved.


//#include "PlayerCharacterCPP.h"
#include "Prog2Compulsory1/Public/PlayerCharacterCPP.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacterCPP::APlayerCharacterCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creates the spring arm and attaches it to the Character root component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	//Creates the camera and attaches it to the spring arm
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCharacterMovement()->MaxWalkSpeed = 500.f;

}

// Called when the game starts or when spawned
void APlayerCharacterCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacterCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacterCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacterCPP::Move);
		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacterCPP::Look);
		Input->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APlayerCharacterCPP::JumpEvent);
		Input->BindAction(InteractAction, ETriggerEvent::Started, this, &APlayerCharacterCPP::Interact);
	}

}

void APlayerCharacterCPP::Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		//Get forward and right direction of character
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0,Rotation.Yaw, 0);

		const FVector ForwardRotation = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		//Sets the movement values
		AddMovementInput(ForwardRotation, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}

void APlayerCharacterCPP::Look(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void APlayerCharacterCPP::JumpEvent()
{
	ACharacter::Jump();
}

void APlayerCharacterCPP::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Pressed E");
}



