// SUNDER: Ascension II — a Keeper's animation loop as rigid parts.
#include "SunderKeeperAnim.h"

FTransform USunderKeeperAnim::Sample(int32 Part, float Time) const
{
	if (!Parts.IsValidIndex(Part) || Parts[Part].Frames.Num() == 0) { return FTransform::Identity; }
	const TArray<FTransform>& Frames = Parts[Part].Frames;
	const int32 Span = FMath::Max(Frames.Num() - 1, 1);         // the last frame is the first again
	const float At = FMath::Fmod(FMath::Max(Time, 0.f) * FramesPerSecond, (float)Span);
	const int32 A = FMath::Clamp(FMath::FloorToInt(At), 0, Frames.Num() - 1), B = FMath::Min(A + 1, Frames.Num() - 1);
	const float T = At - A;
	FTransform Out;
	Out.SetLocation(FMath::Lerp(Frames[A].GetLocation(), Frames[B].GetLocation(), T));
	Out.SetRotation(FQuat::Slerp(Frames[A].GetRotation(), Frames[B].GetRotation(), T).GetNormalized());
	Out.SetScale3D(FMath::Lerp(Frames[A].GetScale3D(), Frames[B].GetScale3D(), T));
	return Out;
}
