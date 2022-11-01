// add to cmd.cpp -- below include section.
#ifdef TUGBERK_ENTRY_ITEMS
ACMD(tugberk_entry_item_and_attr);
#endif

// Search 
	{ "\n",		NULL,			0,			POS_DEAD,	GM_IMPLEMENTOR	}  /* 반드시 이 것이 마지막이어야 한다. */
// Add above.
#ifdef TUGBERK_ENTRY_ITEMS
	{ "tugberk_entry_item_and_attr",				tugberk_entry_item_and_attr,				0,	POS_DEAD,	GM_PLAYER	},
#endif
