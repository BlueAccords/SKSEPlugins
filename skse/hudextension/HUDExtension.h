#pragma once

#include "skse/GameMenus.h"
#include "skse/Hooks_UI.h"

#include <set>

class ObjectWidget
{
public:
	bool operator<(const ObjectWidget & rhs) const	{ return formId < rhs.formId; }

	enum Flags
	{
		kFlag_None					= 0,
		kFlag_UpdatePercent			= (1 << 0),
		kFlag_UseLineOfSight		= (1 << 1),
		kFlag_RemoveOnDeath			= (1 << 2),
		kFlag_RemoveOutOfCombat		= (1 << 3),
		kFlag_HideOnDeath			= (1 << 4),
		kFlag_HideOutOfCombat		= (1 << 5),
		kFlag_ShowInCombat			= (1 << 6),
		kFlag_Friendly				= (1 << 7),
		kFlag_UseHostility			= (1 << 8),
		kFlag_HideOnInvisibility	= (1 << 9),
		kFlag_HideName				= (1 << 10)
	};

	enum FillModes
	{
		kFillMode_Left = 0,
		kFillMode_Right,
		kFillMode_Both
	};

	enum PropertyTypes
	{
		// Health 
		kPropertyType_Flags,
		kPropertyType_HealthCurrentValue,
		kPropertyType_HealthMaximumValue,
		kPropertyType_HealthPrimaryColor,
		kPropertyType_HealthSecondaryColor,
		kPropertyType_HealthFlashColor,
		kPropertyType_HealthPrimaryFriendlyColor,
		kPropertyType_HealthSecondaryFriendlyColor,
		kPropertyType_HealthFlashFriendlyColor,
		kPropertyType_HealthFillMode,
		// Not adding magicka/stamina variants yet.
		kPropertyType_StartFlash,
		kPropertyType_Name,
		kPropertyType_NumProperties,
		// Magicka
		kPropertyType_MagickaCurrentValue,
		kPropertyType_MagickaMaximumValue,
		kPropertyType_MagickaPrimaryColor,
		kPropertyType_MagickaSecondaryColor,
		kPropertyType_MagickaFlashColor,
		kPropertyType_MagickaPrimaryFriendlyColor,
		kPropertyType_MagickaSecondaryFriendlyColor,
		kPropertyType_MagickaFlashFriendlyColor,
		kPropertyType_MagickaFillMode,
		// Stamina
		kPropertyType_StaminaCurrentValue,
		kPropertyType_StaminaMaximumValue,
		kPropertyType_StaminaPrimaryColor,
		kPropertyType_StaminaSecondaryColor,
		kPropertyType_StaminaFlashColor,
		kPropertyType_StaminaPrimaryFriendlyColor,
		kPropertyType_StaminaSecondaryFriendlyColor,
		kPropertyType_StaminaFlashFriendlyColor,
		kPropertyType_StaminaFillMode,
	};


	enum Properties
	{
		// Health
		kProperty_HealthCurrentValue = 0,
		kProperty_HealthMaximumValue,
		kProperty_HealthPrimaryColor,
		kProperty_HealthSecondaryColor,
		kProperty_HealthFlashColor,
		kProperty_HealthPrimaryFriendlyColor,
		kProperty_HealthSecondaryFriendlyColor,
		kProperty_HealthFlashFriendlyColor,
		kProperty_HealthFillMode,
		kProperty_Name,
		kProperty_NumProperties,
		// Magicka
		kProperty_MagickaCurrentValue = 0,
		kProperty_MagickaMaximumValue,
		kProperty_MagickaPrimaryColor,
		kProperty_MagickaSecondaryColor,
		kProperty_MagickaFlashColor,
		kProperty_MagickaPrimaryFriendlyColor,
		kProperty_MagickaSecondaryFriendlyColor,
		kProperty_MagickaFlashFriendlyColor,
		kProperty_MagickaFillMode,
		// Stamina
		kProperty_StaminaCurrentValue = 0,
		kProperty_StaminaMaximumValue,
		kProperty_StaminaPrimaryColor,
		kProperty_StaminaSecondaryColor,
		kProperty_StaminaFlashColor,
		kProperty_StaminaPrimaryFriendlyColor,
		kProperty_StaminaSecondaryFriendlyColor,
		kProperty_StaminaFlashFriendlyColor,
		kProperty_StaminaFillMode,
	};

	enum StateContext
	{
		kContext_None = 0,
		kContext_LeaveCombat = 1,
		kContext_Death = 2,
		kContext_Friendly = 4
	};

	ObjectWidget::ObjectWidget()
	{
		flags |= kFlag_RemoveOnDeath | kFlag_RemoveOutOfCombat | kFlag_UpdatePercent | kFlag_UseLineOfSight;
		for(UInt32 i = 0; i < kProperty_NumProperties; i++)
			params[i].SetUndefined();
	}

	UInt32		formId;
	UInt32		flags;
	GFxValue	params[kProperty_NumProperties];
	GFxValue	object;

	double GetProperty(UInt32 type);
	void SetProperty(UInt32 type, double value);
	void UpdateProperty(UInt32 type);

	void QueryState(TESObjectREFR * reference, bool * visible, bool * hostile);
	bool IsFriendly() const;

	void UpdateFlags();
	void UpdateValues();
	void UpdateColors();
	void UpdateFillMode();
	void UpdateFlash();
	void UpdateText();
	void UpdateComponent(GFxMovieView * view, float * depth);
};

class ObjectWidgets : public SafeDataHolder<std::set<ObjectWidget>>
{
	typedef std::set<ObjectWidget> HealthbarSet;
public:
	void AddGFXMeter(GFxMovieView * view, ObjectWidget * objectMeter, float current, float max, UInt32 flags, UInt32 fillMode, UInt32 colors[]);
	void RemoveGFXMeter(GFxMovieView * view, ObjectWidget * objectMeter);

	bool AddMeter(GFxMovieView * view, UInt32 formId, float current, float max, UInt32 flags, UInt32 fillMode, UInt32 colors[]);
	bool RemoveMeter(GFxMovieView * view, UInt32 formId, UInt32 context);

	void UpdateMeterProperty(UInt32 formId, UInt32 type);
	double GetMeterProperty(UInt32 formId, UInt32 type);
	void SetMeterProperty(UInt32 formId, UInt32 type, double value);

	void RemoveAllHealthbars(GFxMovieView * view);
	void UpdateComponents(GFxMovieView * view);
};

class HUDExtension : public HUDObject
{
public:
	HUDExtension(GFxMovieView* view);
	virtual ~HUDExtension();

	bool AddMeter(UInt32 formId, float current, float max, UInt32 flags, UInt32 fillMode, UInt32 colors[]);
	bool RemoveMeter(UInt32 formId, UInt32 context);

	void UpdateMeterProperty(UInt32 formId, UInt32 type);
	double GetMeterProperty(UInt32 formId, UInt32 type);
	void SetMeterProperty(UInt32 formId, UInt32 type, double value);

	void RemoveAllHealthbars();

	virtual void Update();

	enum
	{
		kFlags_None				= 0,
		kFlags_HideEnemies		= (1 << 0),
		kFlags_HideAllies		= (1 << 1),
		kFlags_HideFriendly		= (1 << 2),
		kFlags_HideNonHostile	= (1 << 3),
		kFlags_HideAtFull		= (1 << 4),
		kFlags_HideName			= (1 << 5),
	};

	UInt32 hudFlags;

private:
	ObjectWidgets	m_components;
};


class AddRemoveWidgetTask : public UIDelegate_v1
{
public:
	AddRemoveWidgetTask::AddRemoveWidgetTask(UInt32 formId, float current, float max, UInt32 state, UInt32 context) : m_formId(formId), m_current(current), m_max(max), m_state(state), m_context(context){}
	virtual void Run();
	virtual void Dispose()
	{
		delete this;
	}

private:
	UInt32			m_formId;
	float			m_current;
	float			m_max;
	UInt32			m_state;
	UInt32			m_context;
};

class SetWidgetPropertyTask : public UIDelegate_v1
{
public:
	SetWidgetPropertyTask(UInt32 formId, UInt32 type, double value);

	virtual void Run();
	virtual void Dispose()
	{
		delete this;	
	};

private:
	UInt32			m_formId;
	UInt32			m_type;
	double			m_value;
};

extern HUDExtension * g_hudExtension;