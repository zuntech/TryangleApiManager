// Fill out your copyright notice in the Description page of Project Settings.


#include "ApiBluepritnsManager.h"
#include "Json.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IHttpResponse.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GenericPlatform/GenericPlatformProcess.h"

UApiBluepritnsManager* thisObjRef;
FString PrintResponse = "";
FJsonObject ReturnValue;
FTimerHandle TimerHandle;
const UObject* WorldContextObjectRef;
FString ConnectionToken;

// generic url for all //
FString basicUrl = "https://AnguishedAgedNagware.dmitriikravtsov.repl.co" ;

// Constructor for initializing values //
UApiBluepritnsManager::UApiBluepritnsManager() {
	thisObjRef = this;
}

// Functional Apis //
FString UApiBluepritnsManager::GetGameInfo(int gameId)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);

	basicUrl.Append("/GetGameInfo");

	Request->SetURL(*basicUrl);
	Request->SetVerb("POST");

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString(JsonString);
	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello ya ma hun "));
	return PrintResponse;
}

FString UApiBluepritnsManager::GetLength()
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	
	basicUrl.Append("/GetLength");

	Request->SetURL(*basicUrl);
	Request->SetVerb("POST");

	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine"));
	return PrintResponse;
}

FString UApiBluepritnsManager::GetERC721BalanceByOwner(int gameId, FString ownerAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("owner", ownerAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/GetERC721BalanceByOwner");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived); 
	Request->SetURL(*basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

FString UApiBluepritnsManager::GetERC721TokenByOwner(FString ERC721Token, int startIndex, int endIndex, FString ownerAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetStringField("ERC721", ERC721Token);
	RequestObject->SetNumberField("startIndex", startIndex);
	RequestObject->SetNumberField("endIndex", endIndex);
	RequestObject->SetStringField("owner", ownerAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/GetERC721TokenByOwner");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

FString UApiBluepritnsManager::GetERC20AllowedByOwner(int gameId, FString ownerAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("owner", ownerAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/GetERC20AllowedByOwner");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

FString UApiBluepritnsManager::GetERC20BalanceByOwner(int gameId, FString ownerAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("owner", ownerAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/GetERC20BalanceByOwner");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}
// Functional Apis //

// Authentication  Apis //
FString UApiBluepritnsManager::GetConnectionUrl(const UObject* WorldContextObject)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnGetConnectionResponce);

	WorldContextObjectRef = WorldContextObject;

	basicUrl.Append("/GetConnectionUrl");

	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->GetResponse();
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine"));
	return PrintResponse;
}

FString UApiBluepritnsManager::AddConnection(FString connectionToken, FString address)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetStringField("connectionToken", connectionToken);
	RequestObject->SetStringField("address", address);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/AddConnection");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

void UApiBluepritnsManager::GetAuthentication(FString connectionToken)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I am here in GetAuthentication %s"), *connectionToken);
	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetStringField("connectionToken", connectionToken);
	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/GetAuth");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
}
// Authentication  Apis //

// Transfer Apis //
FString UApiBluepritnsManager::TransferERC721(int gameId, FString ERC721Token, int tokenId, FString ownerAddressString, FString recipientAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("ERC721", ERC721Token);
	RequestObject->SetNumberField("tokenId", tokenId);
	RequestObject->SetStringField("owner", ownerAddressString);
	RequestObject->SetStringField("recipient", recipientAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/TransferERC721");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

FString UApiBluepritnsManager::TransferERC721Batch(int gameId, FString ERC721Token, int tokenId, FString ownerAddressString, FString recipientAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("ERC721", ERC721Token);
	RequestObject->SetNumberField("tokenId", tokenId);
	RequestObject->SetStringField("owner", ownerAddressString);
	RequestObject->SetStringField("recipient", recipientAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/TransferERC721Batch");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

FString UApiBluepritnsManager::TransferERC20(int gameId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("ERC20", ERC20Token);
	RequestObject->SetNumberField("amount", amount);
	RequestObject->SetStringField("owner", ownerAddressString);
	RequestObject->SetStringField("recipient", recipientAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/TransferERC20");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

FString UApiBluepritnsManager::TransferERC20Batch(int gameId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("ERC20", ERC20Token);
	RequestObject->SetNumberField("amount", amount);
	RequestObject->SetStringField("owner", ownerAddressString);
	RequestObject->SetStringField("recipient", recipientAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/TransferERC20Batch");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}
// Transfer Apis //

// MultiTranser //
FString UApiBluepritnsManager::MultiTransfer(int gameId, FString ERC721Token, int tokenId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("ERC721", ERC721Token);
	RequestObject->SetNumberField("tokenId", tokenId);
	RequestObject->SetStringField("ERC20", ERC20Token);
	RequestObject->SetNumberField("amount", amount);
	RequestObject->SetStringField("owner", ownerAddressString);
	RequestObject->SetStringField("recipient", recipientAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/MultiTransfer");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}

FString UApiBluepritnsManager::MultiTransferBatch(int gameId, FString ERC721Token, int tokenId, FString ERC20Token, int amount, FString ownerAddressString, FString recipientAddressString)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	// creating a body to send //
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetNumberField("gameId", gameId);
	RequestObject->SetStringField("ERC721", ERC721Token);
	RequestObject->SetNumberField("tokenId", tokenId);
	RequestObject->SetStringField("ERC20", ERC20Token);
	RequestObject->SetNumberField("amount", amount);
	RequestObject->SetStringField("owner", ownerAddressString);
	RequestObject->SetStringField("recipient", recipientAddressString);

	// sending data in the body //
	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(RequestObject, Writer);
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(JsonString);

	basicUrl.Append("/MultiTransferBatch");

	Request->OnProcessRequestComplete().BindUObject(thisObjRef, &UApiBluepritnsManager::OnResponseReceived);
	Request->SetURL(basicUrl);
	Request->SetVerb("POST");

	Request->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Hello I worked fine "));
	return PrintResponse;
}
// MultiTranser //

// Return a Responce value
/*Assigned function on successfull http call*/
void UApiBluepritnsManager::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	basicUrl = "https://AnguishedAgedNagware.dmitriikravtsov.repl.co";
	UE_LOG(LogTemp, Log, TEXT("Responce is %s"), *Response->GetContentAsString());
	PrintResponse = *Response->GetContentAsString();
	if (Response->GetResponseCode() == 200) {
		//Create a pointer to hold the json serialized data
		TSharedPtr<FJsonObject> JsonObject;

		//Create a reader pointer to read the json data
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

		//Deserialize the json data given Reader and the actual object to deserialize
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			ReturnValue.SetObjectField("Values", JsonObject);
			//Get the value of the json object by field name
			int32 recievedInt = JsonObject->GetIntegerField("customInt");

			//Output it to the engine
			GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));	
		}
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Responce from api is %s"), *Response->GetContentAsString());
	}
}

void UApiBluepritnsManager::OnGetConnectionResponce(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	TSharedPtr<FJsonObject> JsonObject;
	basicUrl = "https://AnguishedAgedNagware.dmitriikravtsov.repl.co";
	if (Response->GetResponseCode() == 200) {
		
		const FString ResponseBody = Response->GetContentAsString();
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			FString url;

			url = JsonObject->GetStringField("url");
			ConnectionToken = JsonObject->GetStringField("connectionToken");
			if (!url.IsEmpty()) {
				UE_LOG(LogTemp, Log, TEXT("Responce is url %s"), *url);
				FPlatformProcess::LaunchURL(*url, NULL, NULL);
				if (!ConnectionToken.IsEmpty()) {
					WorldContextObjectRef->GetWorld()->GetTimerManager().SetTimer(TimerHandle, thisObjRef, &UApiBluepritnsManager::ConnectionFunction, 5.0f, true);
				}}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Something went wrong"));
			}

		}
	}
	else
	{
		// TODO: trigger error
		UE_LOG(LogTemp, Log, TEXT("Responce is %s"), *Response->GetContentAsString());
	}
}

void UApiBluepritnsManager::ConnectionFunction()
{
	GetAuthentication(ConnectionToken);
	WorldContextObjectRef->GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}
