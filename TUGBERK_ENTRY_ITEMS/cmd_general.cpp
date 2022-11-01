#include "service.h" // add top if not included. 

// In cmd_general.cpp add to anyplace you want.

// If you want to change start items or bonusses just check code you will figure it out.

#ifdef TUGBERK_ENTRY_ITEMS
ACMD(tugberk_entry_item_and_attr)
{
	BYTE job = ch->GetJob();
	LPITEM item;

	for (int i = 0; i < 6; i++)
	{
		item = ch->GetWear(i);
		if (item != NULL)
			ch->UnequipItem(item);
	}


	//item = ch->GetWear(WEAR_SHIELD);

	if (item != NULL)
		ch->UnequipItem(item);

	switch(job)
	{
	case JOB_WARRIOR:
	{
		std::vector<int> warrior_items{ 469, 20009, 17109, 14209, 16209, 15419, 13149, 12269 }; // warrior items
		for (int i = 0; i <= 7; i++)
		{
			item = ITEM_MANAGER::instance().CreateItem(warrior_items[i]);
			if(!item || !item->EquipTo(ch, item->FindEquipCell(ch)))
				M2_DESTROY_ITEM(item);
		}
		
	}
	break;
	case JOB_ASSASSIN:
	{
		std::vector<int> assassin_items{ 1349, 20259, 17109, 14209, 16209, 15419, 13149, 12399 }; // ninja items
		for (int i = 0; i <= 7; i++)
		{
			item = ITEM_MANAGER::instance().CreateItem(assassin_items[i]);
			if(!item || !item->EquipTo(ch, item->FindEquipCell(ch)))
				M2_DESTROY_ITEM(item);
		}
	}
	break;
	case JOB_SURA:
	{
		std::vector<int> sura_items{ 479, 20509, 17209, 14209, 16209, 15419, 13149, 12539 }; // sura items
		for (int i = 0; i <= 7; i++)
		{
			item = ITEM_MANAGER::instance().CreateItem(sura_items[i]);
			if(!item || !item->EquipTo(ch, item->FindEquipCell(ch)))
				M2_DESTROY_ITEM(item);
		}
	}
	break;
		case JOB_SHAMAN:
	{
		std::vector<int> shaman_items{ 5349, 20759, 17209, 14209, 16209, 15419, 13149, 12679 }; // shaman items 
		for (int i = 0; i <= 7; i++)
		{
			item = ITEM_MANAGER::instance().CreateItem(shaman_items[i]);
			if(!item || !item->EquipTo(ch, item->FindEquipCell(ch)))
				M2_DESTROY_ITEM(item);
		}
	}
	break;
	}
	
	item = ch->GetWear(WEAR_HEAD);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_ATT_SPEED, 8);
		item->SetForceAttribute( 1, APPLY_HP_REGEN, 30);
		item->SetForceAttribute( 2, APPLY_SP_REGEN, 30);
		item->SetForceAttribute( 3, APPLY_DODGE, 15);
		item->SetForceAttribute( 4, APPLY_STEAL_SP, 10);
	}

	item = ch->GetWear(WEAR_WEAPON);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_CAST_SPEED, 20);
		item->SetForceAttribute( 1, APPLY_CRITICAL_PCT, 10);
		item->SetForceAttribute( 2, APPLY_PENETRATE_PCT, 10);
		item->SetForceAttribute( 3, APPLY_ATTBONUS_DEVIL, 20);
		item->SetForceAttribute( 4, APPLY_STR, 12);
	}

	item = ch->GetWear(WEAR_SHIELD);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_CON, 12);
		item->SetForceAttribute( 1, APPLY_BLOCK, 15);
		item->SetForceAttribute( 2, APPLY_REFLECT_MELEE, 10);
		item->SetForceAttribute( 3, APPLY_IMMUNE_STUN, 1);
		item->SetForceAttribute( 4, APPLY_IMMUNE_SLOW, 1);
	}

	item = ch->GetWear(WEAR_BODY);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_MAX_HP, 2000);
		item->SetForceAttribute( 1, APPLY_CAST_SPEED, 20);
		item->SetForceAttribute( 2, APPLY_STEAL_HP, 10);
		item->SetForceAttribute( 3, APPLY_REFLECT_MELEE, 10);
		item->SetForceAttribute( 4, APPLY_ATT_GRADE_BONUS, 50);
	}

	item = ch->GetWear(WEAR_FOOTS);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_MAX_HP, 2000);
		item->SetForceAttribute( 1, APPLY_MAX_SP, 80);
		item->SetForceAttribute( 2, APPLY_MOV_SPEED, 8);
		item->SetForceAttribute( 3, APPLY_ATT_SPEED, 8);
		item->SetForceAttribute( 4, APPLY_CRITICAL_PCT, 10);
	}

	item = ch->GetWear(WEAR_WRIST);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_MAX_HP, 2000);
		item->SetForceAttribute( 1, APPLY_MAX_SP, 80);
		item->SetForceAttribute( 2, APPLY_PENETRATE_PCT, 10);
		item->SetForceAttribute( 3, APPLY_STEAL_HP, 10);
		item->SetForceAttribute( 4, APPLY_MANA_BURN_PCT, 10);
	}
	item = ch->GetWear(WEAR_NECK);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_MAX_HP, 2000);
		item->SetForceAttribute( 1, APPLY_MAX_SP, 80);
		item->SetForceAttribute( 2, APPLY_CRITICAL_PCT, 10);
		item->SetForceAttribute( 3, APPLY_PENETRATE_PCT, 10);
		item->SetForceAttribute( 4, APPLY_STEAL_SP, 10);
	}
	item = ch->GetWear(WEAR_EAR);
	if (item != NULL)
	{
		item->ClearAttribute();
		item->SetForceAttribute( 0, APPLY_MOV_SPEED, 20);
		item->SetForceAttribute( 1, APPLY_MANA_BURN_PCT, 10);
		item->SetForceAttribute( 2, APPLY_POISON_REDUCE, 5);
		item->SetForceAttribute( 3, APPLY_ATTBONUS_DEVIL, 20);
		item->SetForceAttribute( 4, APPLY_ATTBONUS_UNDEAD, 20);
	}
}
#endif