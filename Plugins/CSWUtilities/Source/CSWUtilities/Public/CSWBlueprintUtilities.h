// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSWBlueprintUtilities.generated.h"

/**
 * 
 */
UCLASS()
class CSWUTILITIES_API UCSWBlueprintUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	*	Find all Actors in the world with the specified component.
	*	This is a slow operation, use with caution e.g. do not use every frame.
	*	@param	Component			Component to find. Must be specified or result array will be empty.
	*	@param	OutActors			Output array of Actors that have specified component.
	*	@param	OutActorComponents	Output array of Actor Components that belongs to the array of actors.
	*/
	UFUNCTION(BlueprintPure, Category = "CSW|Utilities::BlueprintLibrary", meta = (DisplayName = "CSW::Get All Actors With Component", WorldContext = "WorldContextObject", DeterminesOutputType = "Component", DynamicOutputParam = "OutActorComponents"))
		static void GetAllActorsWithComponent(const UObject* WorldContextObject, const TSubclassOf<UActorComponent> Component, TArray<AActor*>& OutActors, TArray<UActorComponent*>& OutActorComponents);
	
	/**
	*	Get an actor by IDName and Class in the world (hover the mouse in the world out liner to see the actor ID Name).
	*	This is a slow operation, use with caution e.g. do not use every frame.
	*	@param	IDName				ID Name to find. Must be specified or the result will be nullptr.
	*	@param	ActorClass			Class Filter of the actor, determines the OutputType.
	*	@return						The Actor found.
	*/
	UFUNCTION(BlueprintPure, Category = "CSW|Utilities::BlueprintLibrary", meta = (DisplayName = "CSW::Get Actor By ID Name and Class", WorldContext = "WorldContextObject", DeterminesOutputType = "ActorClass"))
		static AActor* GetActorByIDNameAndClass(const UObject* WorldContextObject, const FName IDName, const TSubclassOf<AActor> ActorClass);

	/**
	*	Get an actor by IDName from a given Array of Actors.
	*	@param	IDName				ID Name to find. Must be specified or the result will be nullptr.
	*	@param	ArrayOfActors		The Array of Actors in which the search will be performed.
	*	@param	Actor				The Actor found.
	*	@return						The Index of the array where the Actor was found (it's -1 if no actor was found).
	*/
	UFUNCTION(BlueprintPure, Category = "CSW|Utilities::BlueprintLibrary", meta = (DisplayName = "CSW::Get Actor By ID Name From Array Of Actors"))
		static int32 GetActorByIDNameFromAnArrayOfActors(const FName IDName, const TArray<AActor*>& ArrayOfActors, AActor*& Actor);

	/**
	* Get an actor of this class, only if there's only one actor of this class in the world.
	* @param ActorClass		Class of the actor to return
	* @return				The reference of the actor, can be nullptr if there are none or two+ actors in the world.
	*/
	UFUNCTION(BlueprintPure, Category = "CSW|Utilities::BlueprintLibrary", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true", DisplayName = "CSW::Get Unique Actor Of Class", DeterminesOutputType = "ActorClass"))
		static class AActor* GetUniqueActorOfClass(const UObject* WorldContextObject, const TSubclassOf<AActor> ActorClass);

	/**
	*	Get the Level reference where the actor is loaded (supports level streaming).
	*	@param Actor	The actor reference.
	*	@return			The Level reference where the actor belongs (supports level streaming).
	*/
	UFUNCTION(BlueprintPure, Category = "CSW|Utilities::BlueprintLibrary", meta = (DisplayName = "CSW::Get Level Owner From Actor"))
		static ULevel* GetActorLevel(AActor* Actor);
};
