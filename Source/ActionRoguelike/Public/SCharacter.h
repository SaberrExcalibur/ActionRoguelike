// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class UAnimMontage;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:

	// 设置全局可见，就是可以在细节面板里看到，UPROPEPTY是宏的意思
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	// 这个组件是（SpringArm)组件
	UPROPERTY(visibleAnywhere)
	USpringArmComponent* SpringArmComp;

	// 这个是相机组件
	UPROPERTY(visibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(visibleAnywhere)
	USInteractionComponent* InteractionComp;

	//动画组件
	UPROPERTY(EditAnywhere,Category = "Attack")
	UAnimMontage* AttackAnim;

	//TimeHandle
	FTimerHandle TimerHandle_PrimaryAttack;



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void PrimaryAttack();

	void PrimaryInteract();

	void PrimaryAttack_TimeElapsed();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
