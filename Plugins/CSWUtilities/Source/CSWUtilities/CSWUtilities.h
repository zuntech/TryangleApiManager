// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

/*USE THIS IF DEVELOPING A PLUGIN*/
 #pragma once

 #include "CoreMinimal.h"

 class FCSWUtilitiesModule : public IModuleInterface
 {
 public:

	 /** IModuleInterface implementation */
	 virtual void StartupModule() override;
	 virtual void ShutdownModule() override;
 };

/*USE THIS IF DEVELOPING A GAME MODULE*/

//#pragma once
//
//#include "ModuleManager.h"