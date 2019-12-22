#include "FlowNodeLog.h"
#include "FlowModule.h"

#include "Engine/Engine.h"

UFlowNodeLog::UFlowNodeLog(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bPrintToScreen(true)
{
}

void UFlowNodeLog::ExecuteInput(const FName& PinName)
{
	UE_LOG(LogFlow, Warning, TEXT("%s"), *Message);

	if (bPrintToScreen)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Message);
	}

	TriggerDefaultOutput(true);
}

#if WITH_EDITOR
FString UFlowNodeLog::GetShortDescription() const
{
	return Message;
}
#endif