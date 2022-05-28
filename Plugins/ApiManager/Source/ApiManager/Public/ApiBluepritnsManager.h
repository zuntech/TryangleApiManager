// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Interfaces/IHttpRequest.h"
#include "Json.h"
#include "JsonObjectConverter.h"
#include "Dom/JsonObject.h"
#include "ApiBluepritnsManager.generated.h"
/**
 * 
 */
UCLASS(Config = Game)
class APIMANAGER_API UApiBluepritnsManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		
	UPROPERTY(Config)
	FString GetGameInfoUrlPath;
	
public: 
	
	FHttpModule* Http;
	FTimerHandle TimerHandle;
	
	UApiBluepritnsManager();
	
	// Defining local url paths//
	
	//UPROPERTY(BlueprintPure, VisibileAnywhere, Category = "CSW|Utilities::BlueprintLibrary", meta = (DisplayName = "CSW::Get All Actors With Component", WorldContext = "WorldContextObject", DeterminesOutputType = "Component", DynamicOutputParam = "OutActorComponents"))
	//UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Object From Class", CompactNodeTitle = "New", Keywords = "new create blueprint"), Category = Game))
	
	// Functional Apis //
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString GetGameInfo(int gameId);
	
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString GetLength();

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString GetERC721BalanceByOwner(int gameId, FString ownerAddressString);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString GetERC721TokenByOwner(FString ERC721Token, int startIndex, int endIndex, FString ownerAddressString);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString GetERC20AllowedByOwner(int gameId, FString ownerAddressString);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString GetERC20BalanceByOwner(int gameId, FString ownerAddressString);

	// Authentication  Apis //
	//UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "Custom Utilities")
	static FString GetConnectionUrl(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString AddConnection(FString connectionToken, FString address);

	//UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static void GetAuthentication(FString connectionToken);

	// Transfer Apis //
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString TransferERC721(int gameId, FString ERC721Token, int tokenId, FString ownerAddressString, FString recipientAddressString);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString TransferERC721Batch(int gameId, FString ERC721Token, int tokenId, FString ownerAddressString, FString recipientAddressString);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString TransferERC20(int gameId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString TransferERC20Batch(int gameId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString);

	// MultiTranser //
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString MultiTransfer(int gameId, FString ERC721Token, int tokenId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString
	);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject"), Category = "Custom Utilities")
	static FString MultiTransferBatch(int gameId, FString ERC721Token, int tokenId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString
	);

	
	// Return a Responce value
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	void OnGetConnectionResponce(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	void ConnectionFunction();
};
 