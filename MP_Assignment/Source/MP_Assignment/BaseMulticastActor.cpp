// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMulticastActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABaseMulticastActor::ABaseMulticastActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bAlwaysRelevant = true; // Ensure all clients are aware of this actor
	ReplicatedCounter = 0;

}

// Called when the game starts or when spawned
void ABaseMulticastActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseMulticastActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseMulticastActor::Server_HandleButtonPress_Implementation()
{
	ReplicatedCounter++; // Update a replicated variable
	UE_LOG(LogTemp, Warning, TEXT("Server received the button press! Counter: %d"), ReplicatedCounter);
}

bool ABaseMulticastActor::Server_HandleButtonPress_Validate()
{
	
	return true;
}

void ABaseMulticastActor::ClientButtonPress()
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("This is the Server!"));
	}
	else
	{
		// Call the server function
		UE_LOG(LogTemp, Warning, TEXT("This is the Client!"));
		Server_HandleButtonPress();
	}
}

void ABaseMulticastActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABaseMulticastActor, ReplicatedCounter);
}


