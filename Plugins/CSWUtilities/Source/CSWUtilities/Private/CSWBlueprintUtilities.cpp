// Fill out your copyright notice in the Description page of Project Settings.

#include "CSWBlueprintUtilities.h"
#include "Engine/Engine.h"	///world
#include "EngineUtils.h"	///actoriterator

void UCSWBlueprintUtilities::GetAllActorsWithComponent(const UObject* WorldContextObject, const TSubclassOf<UActorComponent> Component, TArray<AActor*>& OutActors, TArray<UActorComponent*>& OutActorComponents)
{
	if (!Component || !WorldContextObject) return;

	OutActors.Empty();
	OutActorComponents.Empty();

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	/// We do nothing if not class provided, rather than giving ALL actors!
	if (Component && World)
	{
		for (FActorIterator It(World); It; ++It)
		{
			AActor* Actor = *It;
			UActorComponent* ActorComponent = Actor->GetComponentByClass(Component);
			if (Actor && !Actor->IsPendingKill() && ActorComponent)
			{
				OutActors.Add(Actor);
				OutActorComponents.Add(ActorComponent);
			}
		}
	}
}

AActor* UCSWBlueprintUtilities::GetActorByIDNameAndClass(const UObject* WorldContextObject, const FName IDName, const TSubclassOf<AActor> ActorClass)
{
	if (!WorldContextObject || !ActorClass) return nullptr;

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	// We do nothing if not class provided, rather than giving ALL actors!
	if (ActorClass && World)
	{
		for (TActorIterator<AActor> It(World, ActorClass); It; ++It)
		{
			AActor* Actor = *It;
			if (!Actor->IsPendingKill() && Actor->GetFName() == IDName)
			{
				return Actor;
			}
		}
	}
	return nullptr;
}

int32 UCSWBlueprintUtilities::GetActorByIDNameFromAnArrayOfActors(const FName IDName, const TArray<AActor*>& ArrayOfActors, AActor*& Actor)
{
	if (ArrayOfActors.Num() <= 0) return -1;

	int32 Index = 0;
	for (AActor* actor : ArrayOfActors)
	{
		if (!actor->IsPendingKill() && actor->GetFName() == IDName)
		{
			Actor = actor;
			return Index;
		}
		Index++;
	}
	Index = -1;
	return Index;
}

class AActor* UCSWBlueprintUtilities::GetUniqueActorOfClass(const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass)
{
	if (!WorldContextObject || !ActorClass) return nullptr;
	///GetWorld
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	///Iterate Actors of Class
	AActor* Actor = nullptr;
	uint8 ActorCounter = 0;
	if (ActorClass && World)
	{
		for (TActorIterator<AActor> It(World, ActorClass); It; ++It)
		{
			if (ActorCounter <= 1)
			{
				Actor = *It;
				if (!Actor->IsPendingKill())
				{
					ActorCounter++;
				}
			}
			else
			{
				break;
			}
		}
	}
	///If there's only one actor in the world
	if (ActorCounter == 1)
	{
		return Actor;
	}
	else
	{
		if (ActorCounter == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("CGD: GetUniqueActorOfClass() No Actor Found"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("CGD: GetUniqueActorOfClass() There are more than 1 actor of this class in the world"));
		}
		return nullptr;
	}
}

ULevel* UCSWBlueprintUtilities::GetActorLevel(AActor* Actor)
{
	if (!Actor) return nullptr;

	return Actor->GetLevel();
}
