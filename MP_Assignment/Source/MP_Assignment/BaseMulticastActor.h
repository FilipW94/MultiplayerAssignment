// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseMulticastActor.generated.h"

UCLASS()
class MP_ASSIGNMENT_API ABaseMulticastActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ABaseMulticastActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMesh* Mesh;

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void Server_HandleButtonPress();

	// Function to trigger from the client
	UFUNCTION(BlueprintCallable)
	void ClientButtonPress();

	// For testing: replicated variable
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Test")
	int32 ReplicatedCounter;

	// Override to enable replication
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
