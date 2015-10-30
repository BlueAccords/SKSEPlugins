#include "HUDExtension.h"
#include "skse/NiObjects.h"

#include "skse/GameRTTI.h"
#include "skse/GameReferences.h"
#include "skse/GameData.h"

#include <algorithm>


double ObjectWidget::GetProperty(UInt32 type)
{
	switch(type)
	{
	case kPropertyType_Flags:
		return (double)flags;
		break;
		// Health Properties
	case kPropertyType_HealthPrimaryColor:
		return params[kProperty_HealthPrimaryColor].GetNumber();
		break;
	case kPropertyType_HealthSecondaryColor:
		return params[kProperty_HealthSecondaryColor].GetNumber();
		break;
	case kPropertyType_HealthFlashColor:
		return params[kProperty_HealthFlashColor].GetNumber();
		break;
	case kPropertyType_HealthPrimaryFriendlyColor:
		return params[kProperty_HealthPrimaryFriendlyColor].GetNumber();
		break;
	case kPropertyType_HealthSecondaryFriendlyColor:
		return params[kProperty_HealthSecondaryFriendlyColor].GetNumber();
		break;
	case kPropertyType_HealthFlashFriendlyColor:
		return params[kProperty_HealthFlashFriendlyColor].GetNumber();
		break;
	case kPropertyType_HealthFillMode:
		return params[kProperty_HealthFillMode].GetNumber();
		break;
	case kPropertyType_HealthCurrentValue:
		return params[kProperty_HealthCurrentValue].GetNumber();
		break;
	case kPropertyType_HealthMaximumValue:
		return params[kProperty_HealthMaximumValue].GetNumber();
		break;
		// Magicka Properties
	case kPropertyType_MagickaPrimaryColor:
		return params[kProperty_MagickaPrimaryColor].GetNumber();
		break;
	case kPropertyType_MagickaSecondaryColor:
		return params[kProperty_MagickaSecondaryColor].GetNumber();
		break;
	case kPropertyType_MagickaFlashColor:
		return params[kProperty_MagickaFlashColor].GetNumber();
		break;
	case kPropertyType_MagickaPrimaryFriendlyColor:
		return params[kProperty_MagickaPrimaryFriendlyColor].GetNumber();
		break;
	case kPropertyType_MagickaSecondaryFriendlyColor:
		return params[kProperty_MagickaSecondaryFriendlyColor].GetNumber();
		break;
	case kPropertyType_MagickaFlashFriendlyColor:
		return params[kProperty_MagickaFlashFriendlyColor].GetNumber();
		break;
	case kPropertyType_MagickaFillMode:
		return params[kProperty_MagickaFillMode].GetNumber();
		break;
	case kPropertyType_MagickaCurrentValue:
		return params[kProperty_MagickaCurrentValue].GetNumber();
		break;
	case kPropertyType_MagickaMaximumValue:
		return params[kProperty_MagickaMaximumValue].GetNumber();
		break;
		// Stamina Properties
	case kPropertyType_StaminaPrimaryColor:
		return params[kProperty_StaminaPrimaryColor].GetNumber();
		break;
	case kPropertyType_StaminaSecondaryColor:
		return params[kProperty_StaminaSecondaryColor].GetNumber();
		break;
	case kPropertyType_StaminaFlashColor:
		return params[kProperty_StaminaFlashColor].GetNumber();
		break;
	case kPropertyType_StaminaPrimaryFriendlyColor:
		return params[kProperty_StaminaPrimaryFriendlyColor].GetNumber();
		break;
	case kPropertyType_StaminaSecondaryFriendlyColor:
		return params[kProperty_StaminaSecondaryFriendlyColor].GetNumber();
		break;
	case kPropertyType_StaminaFlashFriendlyColor:
		return params[kProperty_StaminaFlashFriendlyColor].GetNumber();
		break;
	case kPropertyType_StaminaFillMode:
		return params[kProperty_StaminaFillMode].GetNumber();
		break;
	case kPropertyType_StaminaCurrentValue:
		return params[kProperty_StaminaCurrentValue].GetNumber();
		break;
	case kPropertyType_StaminaMaximumValue:
		return params[kProperty_StaminaMaximumValue].GetNumber();
		break;
	}

	return 0;
}
void ObjectWidget::SetProperty(UInt32 type, double value)
{
	switch(type)
	{
	case kPropertyType_Flags:
		flags = (UInt32)value;
		break;
		// Health Properties
	case kPropertyType_HealthCurrentValue:
		params[kProperty_HealthCurrentValue].SetNumber(value);
		break;
	case kPropertyType_HealthMaximumValue:
		params[kProperty_HealthMaximumValue].SetNumber(value);
		break;
	case kPropertyType_HealthPrimaryColor:
		params[kProperty_HealthPrimaryColor].SetNumber(value);
		break;
	case kPropertyType_HealthSecondaryColor:
		params[kProperty_HealthSecondaryColor].SetNumber(value);
		break;
	case kPropertyType_HealthFlashColor:
		params[kProperty_HealthFlashColor].SetNumber(value);
		break;
	case kPropertyType_HealthPrimaryFriendlyColor:
		params[kProperty_HealthPrimaryFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_HealthSecondaryFriendlyColor:
		params[kProperty_HealthSecondaryFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_HealthFlashFriendlyColor:
		params[kProperty_HealthFlashFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_HealthFillMode:
		params[kProperty_HealthFillMode].SetNumber(value);
		break;
		// Magicka Properties
	case kPropertyType_MagickaCurrentValue:
		params[kProperty_MagickaCurrentValue].SetNumber(value);
		break;
	case kPropertyType_MagickaMaximumValue:
		params[kProperty_MagickaMaximumValue].SetNumber(value);
		break;
	case kPropertyType_MagickaPrimaryColor:
		params[kProperty_MagickaPrimaryColor].SetNumber(value);
		break;
	case kPropertyType_MagickaSecondaryColor:
		params[kProperty_MagickaSecondaryColor].SetNumber(value);
		break;
	case kPropertyType_MagickaFlashColor:
		params[kProperty_MagickaFlashColor].SetNumber(value);
		break;
	case kPropertyType_MagickaPrimaryFriendlyColor:
		params[kProperty_MagickaPrimaryFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_MagickaSecondaryFriendlyColor:
		params[kProperty_MagickaSecondaryFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_MagickaFlashFriendlyColor:
		params[kProperty_MagickaFlashFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_MagickaFillMode:
		params[kProperty_MagickaFillMode].SetNumber(value);
		break;
		// Stamina Properties
	case kPropertyType_StaminaCurrentValue:
		params[kProperty_StaminaCurrentValue].SetNumber(value);
		break;
	case kPropertyType_StaminaMaximumValue:
		params[kProperty_StaminaMaximumValue].SetNumber(value);
		break;
	case kPropertyType_StaminaPrimaryColor:
		params[kProperty_StaminaPrimaryColor].SetNumber(value);
		break;
	case kPropertyType_StaminaSecondaryColor:
		params[kProperty_StaminaSecondaryColor].SetNumber(value);
		break;
	case kPropertyType_StaminaFlashColor:
		params[kProperty_StaminaFlashColor].SetNumber(value);
		break;
	case kPropertyType_StaminaPrimaryFriendlyColor:
		params[kProperty_StaminaPrimaryFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_StaminaSecondaryFriendlyColor:
		params[kProperty_StaminaSecondaryFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_StaminaFlashFriendlyColor:
		params[kProperty_StaminaFlashFriendlyColor].SetNumber(value);
		break;
	case kPropertyType_StaminaFillMode:
		params[kProperty_StaminaFillMode].SetNumber(value);
		break;
	}
}

void ObjectWidget::UpdateProperty(UInt32 type)
{
	switch(type)
	{
	// I'm not sure if you need each data type needs their own separate set of flags or not.
	// I'm assuming the show in combat/hide on death/Line of Sight checks are important but I don't know how
	// I'd apply it to magicka and stamina as well.
	case kPropertyType_Flags:
		{
			// Update visibility if necessary
			if((flags & kFlag_ShowInCombat) == kFlag_ShowInCombat || 
				(flags & kFlag_HideOutOfCombat) == kFlag_HideOutOfCombat || 
				(flags & kFlag_HideOnDeath) == kFlag_HideOnDeath) {
				TESForm * form = LookupFormByID(formId);
				if(form) {
					TESObjectREFR * reference = DYNAMIC_CAST(form, TESForm, TESObjectREFR);
					if(reference) {
						bool isVisible = false;
						bool isFriendly = false;
						QueryState(reference, &isVisible, &isFriendly);
						if(object.IsDisplayObject()) {
							GFxValue::DisplayInfo dInfo;
							dInfo.SetVisible(isVisible);
							object.SetDisplayInfo(&dInfo);
						}
					}
				}
			}
		}
		break;
	// Case fall through so it will keep going through the cases
	// until the break; statement is reached.
	case kPropertyType_HealthCurrentValue:
	case kPropertyType_HealthMaximumValue:
	case kPropertyType_MagickaCurrentValue:
	case kPropertyType_MagickaMaximumValue:
	case kPropertyType_StaminaCurrentValue:
	case kPropertyType_StaminaMaximumValue:
		UpdateValues();
		break;
	// Health Cases
	case kPropertyType_HealthPrimaryColor:
	case kPropertyType_HealthSecondaryColor:
	case kPropertyType_HealthFlashColor:
	case kPropertyType_HealthPrimaryFriendlyColor:
	case kPropertyType_HealthSecondaryFriendlyColor:
	case kPropertyType_HealthFlashFriendlyColor:
	// Magicka Cases
	case kPropertyType_MagickaPrimaryColor:
	case kPropertyType_MagickaSecondaryColor:
	case kPropertyType_MagickaFlashColor:
	case kPropertyType_MagickaPrimaryFriendlyColor:
	case kPropertyType_MagickaSecondaryFriendlyColor:
	case kPropertyType_MagickaFlashFriendlyColor:
	// Stamina Cases
	case kPropertyType_StaminaPrimaryColor:
	case kPropertyType_StaminaSecondaryColor:
	case kPropertyType_StaminaFlashColor:
	case kPropertyType_StaminaPrimaryFriendlyColor:
	case kPropertyType_StaminaSecondaryFriendlyColor:
	case kPropertyType_StaminaFlashFriendlyColor:
		UpdateColors();
		break;
	case kPropertyType_HealthFillMode:
	case kPropertyType_MagickaFillMode:
	case kPropertyType_StaminaFillMode:
		UpdateFillMode();
		break;
	case kPropertyType_StartFlash:
		UpdateFlash();
		break;
	case kPropertyType_Name:
		UpdateText();
		break;
	}
}

bool ObjectWidget::IsFriendly() const
{
	return (flags & ObjectWidget::kFlag_Friendly) == ObjectWidget::kFlag_Friendly;
}

void ObjectWidget::UpdateText()
{
	GFxValue textField;
	object.GetMember("nameField", &textField);
	textField.SetText(params[kProperty_Name].GetString(), false);
}

void ObjectWidget::UpdateValues()
{
	GFxValue update[6]; // original size of 2
	update[0] = params[kProperty_HealthCurrentValue];
	update[1] = params[kProperty_HealthMaximumValue];
	update[2] = params[kProperty_MagickaCurrentValue];
	update[3] = params[kProperty_MagickaMaximumValue];
	update[4] = params[kProperty_StaminaCurrentValue];
	update[5] = params[kProperty_StaminaMaximumValue];

	object.Invoke("setValues", NULL, update, 6);
}

void ObjectWidget::UpdateColors()
{
	GFxValue update[18]; // original size of 3
	if (!IsFriendly()) {
		update[0] = params[kProperty_HealthPrimaryColor];
		update[1] = params[kProperty_HealthSecondaryColor];
		update[2] = params[kProperty_HealthFlashColor];
		update[3] = params[kProperty_MagickaPrimaryColor];
		update[4] = params[kProperty_MagickaSecondaryColor];
		update[5] = params[kProperty_MagickaFlashColor];
		update[6] = params[kProperty_StaminaPrimaryColor];
		update[7] = params[kProperty_StaminaSecondaryColor];
		update[8] = params[kProperty_StaminaFlashColor];
	}
	else {
		update[0] = params[kProperty_HealthPrimaryFriendlyColor];
		update[1] = params[kProperty_HealthSecondaryFriendlyColor];
		update[2] = params[kProperty_HealthFlashFriendlyColor];
		update[3] = params[kProperty_MagickaPrimaryFriendlyColor];
		update[4] = params[kProperty_MagickaSecondaryFriendlyColor];
		update[5] = params[kProperty_MagickaFlashFriendlyColor];
		update[6] = params[kProperty_StaminaPrimaryFriendlyColor];
		update[7] = params[kProperty_StaminaSecondaryFriendlyColor];
		update[8] = params[kProperty_StaminaFlashFriendlyColor];
	}
	object.Invoke("setColors", NULL, update, 18);
}

void ObjectWidget::UpdateFlags()
{
	if (object.HasMember("flags")) {
		GFxValue mFlags;
		object.GetMember("flags", &mFlags);
		mFlags.SetNumber(flags);
		object.SetMember("flags", &mFlags);
	}
}

// *************** Important ******************************************************************************************************
// Need to adjust this for magicka and stamina as well. 
void ObjectWidget::UpdateFillMode()
{
	object.Invoke("setFillDirection", NULL, &params[kProperty_FillMode], 1);
}

void ObjectWidget::UpdateFlash()
{
	GFxValue update;
	update.SetBool(false);
	object.Invoke("startFlash", NULL, &update, 1);
}

void ObjectWidget::QueryState(TESObjectREFR * reference, bool * isVisible, bool * isFriendly)
{
	bool isHidden = false;
	bool isHostileToActor = false;
	bool isHostile = false;
	UInt8 unk1 = 0;
	if((flags & kFlag_UseLineOfSight) == kFlag_UseLineOfSight)
		isHidden = !HasLOS((*g_thePlayer), reference, &unk1);
	Actor * actor = DYNAMIC_CAST(reference, TESObjectREFR, Actor);
	if(actor) {
		if ((flags & kFlag_UpdatePercent) == kFlag_UpdatePercent) {
			// Get values from Tes5Mod Actor Value Indices.
			// http://www.uesp.net/wiki/Tes5Mod:Actor_Value_Indices
			params[kProperty_HealthCurrentValue].SetNumber(actor->actorValueOwner.GetCurrent(24));
			params[kProperty_HealthMaximumValue].SetNumber(actor->actorValueOwner.GetMaximum(24));
			params[kProperty_MagickaCurrentValue].SetNumber(actor->actorValueOwner.GetCurrent(25));
			params[kProperty_MagickaMaximumValue].SetNumber(actor->actorValueOwner.GetMaximum(25));
			params[kProperty_StaminaCurrentValue].SetNumber(actor->actorValueOwner.GetCurrent(26));
			params[kProperty_StaminaMaximumValue].SetNumber(actor->actorValueOwner.GetMaximum(26));

			// Checks if at health is at 100%+ and hides if true.
			double percent = params[kProperty_HealthCurrentValue].GetNumber() / params[kProperty_HealthMaximumValue].GetNumber();
			if (percent >= 1.0 && (g_hudExtension->hudFlags & HUDExtension::kFlags_HideAtFull) == HUDExtension::kFlags_HideAtFull)
				isHidden = true;
		}
		if((flags & kFlag_ShowInCombat) == kFlag_ShowInCombat)
			if(actor->IsInCombat())
				isHidden = !isHidden;
		if((flags & kFlag_HideOutOfCombat) == kFlag_HideOutOfCombat) // When these are not flagged, hide instead
			if(!actor->IsInCombat())
				isHidden = true;
		if((flags & kFlag_HideOnDeath) == kFlag_HideOnDeath)
			if(actor->IsDead(1))
				isHidden = true;
		if ((flags & kFlag_HideOnInvisibility) == kFlag_HideOnInvisibility)
			if (actor->actorValueOwner.GetCurrent(54) > 0)
				isHidden = true;
		if ((flags & kFlag_UseHostility) == kFlag_UseHostility || g_hudExtension->hudFlags != HUDExtension::kFlags_None) {
			isHostileToActor = CALL_MEMBER_FN(*g_thePlayer, IsHostileToActor)(actor);
			if ((flags & kFlag_UseHostility) == kFlag_UseHostility)
				isHostile = isHostileToActor;
		}

		if (g_hudExtension->hudFlags != HUDExtension::kFlags_None) {
			if (isHostileToActor && (g_hudExtension->hudFlags & HUDExtension::kFlags_HideEnemies) == HUDExtension::kFlags_HideEnemies)
				isHidden = true;
			else if (!isHostileToActor) {
				SInt32 relationshipRank = RelationshipRanks::GetRelationshipRank(actor->baseForm, (*g_thePlayer)->baseForm);
				if ((g_hudExtension->hudFlags & HUDExtension::kFlags_HideAllies) == HUDExtension::kFlags_HideAllies && relationshipRank >= 3)
					isHidden = true;
				if ((g_hudExtension->hudFlags & HUDExtension::kFlags_HideFriendly) == HUDExtension::kFlags_HideFriendly && relationshipRank >= 1 && relationshipRank < 3)
					isHidden = true;
				if ((g_hudExtension->hudFlags & HUDExtension::kFlags_HideNonHostile) == HUDExtension::kFlags_HideNonHostile && relationshipRank < 1)
					isHidden = true;
			}
		}
	}

	*isVisible = !isHidden;
	*isFriendly = !isHostile;
}

// this involves positioning of the hud elements so i'm assuming magicka and stamina
// will need separate positions below the health bar.
void ObjectWidget::UpdateComponent(GFxMovieView * view, float * depth)
{
	TESForm * form = LookupFormByID(formId);
	if(form) {
		TESObjectREFR * reference = DYNAMIC_CAST(form, TESForm, TESObjectREFR);
		if(reference) {
			NiPoint3 markerPos;
			reference->GetMarkerPosition(&markerPos);
			markerPos.z += 25;

			float x_out = 0.0;
			float y_out = 0.0;
			float z_out = 0.0;

			GRectF rect = view->GetVisibleFrameRect();

			WorldPtToScreenPt3_Internal(g_worldToCamMatrix, g_viewPort, &markerPos, &x_out, &y_out, &z_out, 1e-5);

			// Move component, update component stats
			y_out = 1.0 - y_out; // Flip y for Flash coordinate system
			y_out = rect.top + (rect.bottom - rect.top) * y_out;
			x_out = rect.left + (rect.right - rect.left) * x_out;

			*depth = z_out;

			bool isVisible = false;
			bool isFriendly = false;
			QueryState(reference, &isVisible, &isFriendly);

			if ((g_hudExtension->hudFlags & HUDExtension::kFlags_HideName) == HUDExtension::kFlags_HideName || (flags & ObjectWidget::kFlag_HideName) == ObjectWidget::kFlag_HideName) {
				params[kProperty_Name].SetString("");
				UpdateText();
			} else {
				const char * text = CALL_MEMBER_FN(reference, GetReferenceName)();
				if (params[kProperty_Name].GetString() != text) {
					params[kProperty_Name].SetString(text);
					UpdateText();
				}
			}

			if ((flags & ObjectWidget::kFlag_UseHostility) == ObjectWidget::kFlag_UseHostility) {
				bool nowFriendly = IsFriendly();
				if (nowFriendly && !isFriendly) { // Turned hostile
					flags &= ~ObjectWidget::kFlag_Friendly;
					UpdateFlags();
					UpdateColors();
				}
				else if (!nowFriendly && isFriendly) { // Turned friendly
					flags |= ObjectWidget::kFlag_Friendly;
					UpdateFlags();
					UpdateColors();
				}
			}

			double scale = min(((100 - z_out * 100) * 10), 50);//(1.0 - z_out) * 100;//min(((100 - z_out * 100) * 10), 50);
			if(object.IsDisplayObject()) {
				GFxValue::DisplayInfo dInfo;
				dInfo.SetPosition(x_out, y_out);
				dInfo.SetScale(scale, scale);
				dInfo.SetVisible(isVisible);
				object.SetDisplayInfo(&dInfo);

				if((flags & kFlag_UpdatePercent) == kFlag_UpdatePercent)
					UpdateValues();
			}
		}
	}
}

// Assigns properties to the objectMeter object.
// Unsure if fillmode is reusable for all three bars or not.
// Need to find out what GFxMoviewView actually is.
void ObjectWidgets::AddGFXMeter(GFxMovieView * view, ObjectWidget * objectMeter, float current, float max, UInt32 flags, UInt32 fillMode, UInt32 colors[])
{
	GFxValue update[29]; // original value is 11.
	update[0].SetNumber(objectMeter->formId);
	update[1].SetNumber(objectMeter->flags);

	// Health Values
	if(current != -1)
		update[2] = objectMeter->params[ObjectWidget::kProperty_HealthCurrentValue];
	else
		update[2].SetUndefined();

	if (max != -1)
		update[3] = objectMeter->params[ObjectWidget::kProperty_HealthMaximumValue];
	else
		update[3].SetUndefined();

	if (colors[0] != -1)
		update[4] = objectMeter->params[ObjectWidget::kProperty_HealthPrimaryColor];
	else
		update[4].SetUndefined();

	if (colors[1] != -1)
		update[5] = objectMeter->params[ObjectWidget::kProperty_HealthSecondaryColor];
	else
		update[5].SetUndefined();

	if (colors[2] != -1)
		update[6] = objectMeter->params[ObjectWidget::kProperty_HealthFlashColor];
	else
		update[6].SetUndefined();

	if (colors[3] != -1)
		update[7] = objectMeter->params[ObjectWidget::kProperty_HealthPrimaryFriendlyColor];
	else
		update[7].SetUndefined();

	if (colors[4] != -1)
		update[8] = objectMeter->params[ObjectWidget::kProperty_HealthSecondaryFriendlyColor];
	else
		update[8].SetUndefined();

	if (colors[5] != -1)
		update[9] = objectMeter->params[ObjectWidget::kProperty_HealthFlashFriendlyColor];
	else
		update[9].SetUndefined();

	if(fillMode != -1)
		update[10] = objectMeter->params[ObjectWidget::kProperty_HealthFillMode];
	else
		update[10].SetUndefined();

	// Magicka Values
	if(current != -1)
		update[11] = objectMeter->params[ObjectWidget::kProperty_MagickaCurrentValue];
	else
		update[11].SetUndefined();

	if (max != -1)
		update[12] = objectMeter->params[ObjectWidget::kProperty_MagickaMaximumValue];
	else
		update[12].SetUndefined();

	if (colors[0] != -1)
		update[13] = objectMeter->params[ObjectWidget::kProperty_MagickaPrimaryColor];
	else
		update[13].SetUndefined();

	if (colors[1] != -1)
		update[14] = objectMeter->params[ObjectWidget::kProperty_MagickaSecondaryColor];
	else
		update[14].SetUndefined();

	if (colors[2] != -1)
		update[15] = objectMeter->params[ObjectWidget::kProperty_MagickaFlashColor];
	else
		update[15].SetUndefined();

	if (colors[3] != -1)
		update[16] = objectMeter->params[ObjectWidget::kProperty_MagickaPrimaryFriendlyColor];
	else
		update[16].SetUndefined();

	if (colors[4] != -1)
		update[17] = objectMeter->params[ObjectWidget::kProperty_MagickaSecondaryFriendlyColor];
	else
		update[17].SetUndefined();

	if (colors[5] != -1)
		update[18] = objectMeter->params[ObjectWidget::kProperty_MagickaFlashFriendlyColor];
	else
		update[18].SetUndefined();

	if(fillMode != -1)
		update[19] = objectMeter->params[ObjectWidget::kProperty_MagickaFillMode];
	else
		update[19].SetUndefined();	

	// Stamina Values
	if(current != -1)
		update[20] = objectMeter->params[ObjectWidget::kProperty_StaminaCurrentValue];
	else
		update[20].SetUndefined();

	if (max != -1)
		update[21] = objectMeter->params[ObjectWidget::kProperty_StaminaMaximumValue];
	else
		update[21].SetUndefined();

	if (colors[0] != -1)
		update[22] = objectMeter->params[ObjectWidget::kProperty_StaminaPrimaryColor];
	else
		update[22].SetUndefined();

	if (colors[1] != -1)
		update[23] = objectMeter->params[ObjectWidget::kProperty_StaminaSecondaryColor];
	else
		update[23].SetUndefined();

	if (colors[2] != -1)
		update[24] = objectMeter->params[ObjectWidget::kProperty_StaminaFlashColor];
	else
		update[24].SetUndefined();

	if (colors[3] != -1)
		update[25] = objectMeter->params[ObjectWidget::kProperty_StaminaPrimaryFriendlyColor];
	else
		update[25].SetUndefined();

	if (colors[4] != -1)
		update[26] = objectMeter->params[ObjectWidget::kProperty_StaminaSecondaryFriendlyColor];
	else
		update[26].SetUndefined();

	if (colors[5] != -1)
		update[27] = objectMeter->params[ObjectWidget::kProperty_StaminaFlashFriendlyColor];
	else
		update[27].SetUndefined();

	if(fillMode != -1)
		update[28] = objectMeter->params[ObjectWidget::kProperty_StaminaFillMode];
	else
		update[28].SetUndefined();	

	view->Invoke("_root.hudExtension.floatingWidgets.loadWidget", &objectMeter->object, update, 29);
	objectMeter->object.AddManaged();
}

void ObjectWidgets::RemoveGFXMeter(GFxMovieView * view, ObjectWidget * objectMeter)
{
	if(objectMeter->object.IsManaged()) {
		GFxValue arg;
		arg.SetNumber(objectMeter->formId);
		view->Invoke("_root.hudExtension.floatingWidgets.unloadWidget", NULL, &arg, 1);
		objectMeter->object.CleanManaged();
	}
}

bool ObjectWidgets::AddMeter(GFxMovieView * view, UInt32 formId, float current, float max, UInt32 flags, UInt32 fillMode, UInt32 colors[])
{
	bool added = false;
	ObjectWidget objectMeter;
	objectMeter.formId = formId;
	Lock();
	HealthbarSet::iterator it = m_data.find(objectMeter);
	if(it == m_data.end()) {
		objectMeter.flags = flags;
		if(current != -1)
			objectMeter.params[ObjectWidget::kProperty_CurrentValue].SetNumber(current);
		if (max != -1)
			objectMeter.params[ObjectWidget::kProperty_MaximumValue].SetNumber(max);
		if(colors[0] != -1)
			objectMeter.params[ObjectWidget::kProperty_PrimaryColor].SetNumber(colors[0]);
		if(colors[1] != -1)
			objectMeter.params[ObjectWidget::kProperty_SecondaryColor].SetNumber(colors[1]);
		if(colors[2] != -1)
			objectMeter.params[ObjectWidget::kProperty_FlashColor].SetNumber(colors[2]);
		if (colors[3] != -1)
			objectMeter.params[ObjectWidget::kProperty_PrimaryFriendlyColor].SetNumber(colors[3]);
		if (colors[4] != -1)
			objectMeter.params[ObjectWidget::kProperty_SecondaryFriendlyColor].SetNumber(colors[4]);
		if (colors[5] != -1)
			objectMeter.params[ObjectWidget::kProperty_FlashFriendlyColor].SetNumber(colors[5]);
		if(fillMode != -1)
			objectMeter.params[ObjectWidget::kProperty_FillMode].SetNumber(fillMode);

		AddGFXMeter(view, &objectMeter, current, max, flags, fillMode, colors);
		m_data.insert(objectMeter);
		added = true;
	}
	Release();
	return added;
}

bool ObjectWidgets::RemoveMeter(GFxMovieView * view, UInt32 formId, UInt32 context)
{
	bool removed = false;

	ObjectWidget foundBar;
	foundBar.formId = formId;
		
	Lock();
	HealthbarSet::iterator it = m_data.find(foundBar);
	if(it != m_data.end()) {
		if ((((it->flags & ObjectWidget::kFlag_RemoveOnDeath) == ObjectWidget::kFlag_RemoveOnDeath && (context & ObjectWidget::kContext_Death) == ObjectWidget::kContext_Death)) ||
			(((it->flags & ObjectWidget::kFlag_RemoveOutOfCombat) == ObjectWidget::kFlag_RemoveOutOfCombat && (context & ObjectWidget::kContext_LeaveCombat) == ObjectWidget::kContext_LeaveCombat)) ||
			context == ObjectWidget::kContext_None) {
			RemoveGFXMeter(view, const_cast<ObjectWidget*>(&(*it)));
			m_data.erase(it);
			removed = true;
		}
	}
	Release();

	return removed;
}

void ObjectWidgets::RemoveAllHealthbars(GFxMovieView * view)
{
	Lock();
	HealthbarSet::iterator it = m_data.begin();
	while(it != m_data.end()) {
		RemoveGFXMeter(view, const_cast<ObjectWidget*>(&(*it)));
		m_data.erase(it++);
	}
	Release();
}

double ObjectWidgets::GetMeterProperty(UInt32 formId, UInt32 type)
{
	ObjectWidget objectMeter;
	objectMeter.formId = formId;
	double value = 0;
	Lock();
	HealthbarSet::iterator it = m_data.find(objectMeter);
	if(it != m_data.end()) {
		value = const_cast<ObjectWidget*>(&(*it))->GetProperty(type);
	}
	Release();
	return value;
}

void ObjectWidgets::UpdateMeterProperty(UInt32 formId, UInt32 type)
{
	ObjectWidget objectMeter;
	objectMeter.formId = formId;
	Lock();
	HealthbarSet::iterator it = m_data.find(objectMeter);
	if(it != m_data.end()) {
		const_cast<ObjectWidget*>(&(*it))->UpdateProperty(type);
	}
	Release();
}

void ObjectWidgets::SetMeterProperty(UInt32 formId, UInt32 type, double value)
{
	ObjectWidget objectMeter;
	objectMeter.formId = formId;

	Lock();
	HealthbarSet::iterator it = m_data.find(objectMeter);
	if(it != m_data.end()) {
		const_cast<ObjectWidget*>(&(*it))->SetProperty(type, value);
	}
	Release();
}

void ObjectWidgets::UpdateComponents(GFxMovieView * view)
{
	Lock();

	GFxValue handleArray;
	view->CreateArray(&handleArray);

	for(HealthbarSet::iterator it = m_data.begin(); it != m_data.end(); ++it) {
		float zPos = 0.0;
		const_cast<ObjectWidget*>(&(*it))->UpdateComponent(view, &zPos);

		GFxValue meterData;
		view->CreateObject(&meterData);
		GFxValue meterId;
		meterId.SetNumber(it->formId);
		GFxValue meterzPos;
		meterzPos.SetNumber(zPos);

		meterData.SetMember("id", &meterId);
		meterData.SetMember("zIndex", &meterzPos);

		handleArray.PushBack(&meterData);
	}
	view->Invoke("_root.hudExtension.floatingWidgets.sortWidgetDepths", NULL, &handleArray, 1);

	Release();
}

HUDExtension::HUDExtension(GFxMovieView* movie) : HUDObject(movie)
{
	hudFlags = 0;
}

HUDExtension::~HUDExtension()
{
	RemoveAllHealthbars();
};

void HUDExtension::RemoveAllHealthbars()
{
	if(view)
		m_components.RemoveAllHealthbars(view);
}

bool HUDExtension::AddMeter(UInt32 formId, float current, float max, UInt32 flags, UInt32 fillMode, UInt32 colors[])
{
	if(view)
		return m_components.AddMeter(view, formId, current, max, flags, fillMode, colors);

	return false;
}

bool HUDExtension::RemoveMeter(UInt32 formId, UInt32 context)
{
	if(view)
		return m_components.RemoveMeter(view, formId, context);

	return false;
}

void HUDExtension::Update()
{
	m_components.UpdateComponents(view);
}

void HUDExtension::UpdateMeterProperty(UInt32 formId, UInt32 type)
{
	m_components.UpdateMeterProperty(formId, type);
}

double HUDExtension::GetMeterProperty(UInt32 formId, UInt32 type)
{
	return m_components.GetMeterProperty(formId, type);
}

void HUDExtension::SetMeterProperty(UInt32 formId, UInt32 type, double value)
{
	m_components.SetMeterProperty(formId, type, value);
}

// UInt32 flags and UInt32 colors are defined in this function.
// To change the number of colors used change the color array here.
void AddRemoveWidgetTask::Run()
{
	if(g_hudExtension) {
		switch(m_state) {
			case 0:
				g_hudExtension->RemoveMeter(m_formId, m_context);
				break;
			case 1:
				{
					UInt32 flags = ObjectWidget::kFlag_RemoveOnDeath | ObjectWidget::kFlag_RemoveOutOfCombat | ObjectWidget::kFlag_UpdatePercent | ObjectWidget::kFlag_UseLineOfSight | ObjectWidget::kFlag_UseHostility | ObjectWidget::kFlag_HideOnInvisibility;
					if((m_context & ObjectWidget::kContext_Friendly) == ObjectWidget::kContext_Friendly)
						flags |= ObjectWidget::kFlag_Friendly;
					UInt32 colors[] = {-1, -1, -1, -1, -1, -1};
					g_hudExtension->AddMeter(m_formId, m_current, m_max, flags, -1, colors);
				}
				break;
			default:
				g_hudExtension->RemoveMeter(m_formId, m_context);
				break;
		}
	}
}

SetWidgetPropertyTask::SetWidgetPropertyTask(UInt32 formId, UInt32 type, double value) : m_formId(formId), m_type(type), m_value(value)
{
	if(g_hudExtension) {
		g_hudExtension->SetMeterProperty(formId, type, value);
	}
}

void SetWidgetPropertyTask::Run()
{
	if(g_hudExtension) {
		g_hudExtension->UpdateMeterProperty(m_formId, m_type);
	}
}
