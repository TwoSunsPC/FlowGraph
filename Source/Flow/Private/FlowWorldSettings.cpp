#include "FlowWorldSettings.h"
#include "FlowSubsystem.h"

AFlowWorldSettings::AFlowWorldSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, FlowAsset(nullptr)
{
}

void AFlowWorldSettings::BeginPlay()
{
	Super::BeginPlay();

	if (FlowAsset)
	{
		if (UFlowSubsystem* FlowSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>())
		{
			FlowSubsystem->StartFlow(FlowAsset);
		}
	}
}

void AFlowWorldSettings::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (FlowAsset)
	{
		if (UFlowSubsystem* FlowSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>())
		{
			FlowSubsystem->EndFlow(FlowAsset);
		}
	}

	Super::EndPlay(EndPlayReason);
}
