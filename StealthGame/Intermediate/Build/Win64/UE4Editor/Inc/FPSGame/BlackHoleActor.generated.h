// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef FPSGAME_BlackHoleActor_generated_h
#error "BlackHoleActor.generated.h already included, missing '#pragma once' in BlackHoleActor.h"
#endif
#define FPSGAME_BlackHoleActor_generated_h

#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOverlapInnerSphere) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OverlapInnerSphere(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOverlapInnerSphere) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OverlapInnerSphere(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlackHoleActor(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_ABlackHoleActor(); \
public: \
	DECLARE_CLASS(ABlackHoleActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(ABlackHoleActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_INCLASS \
private: \
	static void StaticRegisterNativesABlackHoleActor(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_ABlackHoleActor(); \
public: \
	DECLARE_CLASS(ABlackHoleActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(ABlackHoleActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABlackHoleActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABlackHoleActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlackHoleActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlackHoleActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlackHoleActor(ABlackHoleActor&&); \
	NO_API ABlackHoleActor(const ABlackHoleActor&); \
public:


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlackHoleActor(ABlackHoleActor&&); \
	NO_API ABlackHoleActor(const ABlackHoleActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlackHoleActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlackHoleActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlackHoleActor)


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshComp() { return STRUCT_OFFSET(ABlackHoleActor, MeshComp); } \
	FORCEINLINE static uint32 __PPO__OuterSphereComp() { return STRUCT_OFFSET(ABlackHoleActor, OuterSphereComp); } \
	FORCEINLINE static uint32 __PPO__InnerSphereComp() { return STRUCT_OFFSET(ABlackHoleActor, InnerSphereComp); }


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_12_PROLOG
#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_RPC_WRAPPERS \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_INCLASS \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_INCLASS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_BlackHoleActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StealthGame_Source_FPSGame_Public_BlackHoleActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
