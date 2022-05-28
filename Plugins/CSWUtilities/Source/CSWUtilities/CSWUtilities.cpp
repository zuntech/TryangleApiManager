// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

/*USE THIS IF DEVELOPING A PLUGIN*/

 #include "CSWUtilities.h"

 #define LOCTEXT_NAMESPACE "FCSWUtilitiesModule"

 void FCSWUtilitiesModule::StartupModule()
 {
//	This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
 }

 void FCSWUtilitiesModule::ShutdownModule()
 {
// 	This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
// 	we call this function before unloading the module.
 }

 #undef LOCTEXT_NAMESPACE
	
 IMPLEMENT_MODULE(FCSWUtilitiesModule, CSWUtilities)

/*USE THIS IF DEVELOPING A GAME MODULE*/

//#include "CSWUtilities.h"
//
//IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, CSWUtilities, "CSWUtilities");