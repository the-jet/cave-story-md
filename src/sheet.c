#include "sheet.h"

#include <genesis.h>
#include "stage.h"
#include "resources.h"
#include "tables.h"

#ifndef KDB_SHEET
#define puts(x) /**/
#define printf(...) /**/
#endif

void sheets_init() {
	// Polar star
	sheets[0] = (Sheet){ SHEET_PSTAR, 2*4, TILE_SHEETINDEX };
	// Machine Gun
	sheets[1] = (Sheet){ SHEET_MGUN, 2*4, sheets[0].index + sheets[0].size };
	// Fireball
	sheets[2] = (Sheet){ SHEET_FBALL, 3*4, sheets[1].index + sheets[1].size };
	// Heart
	sheets[3] = (Sheet){ SHEET_HEART, 4*4, sheets[2].index + sheets[2].size };
	// Missile
	sheets[4] = (Sheet){ SHEET_MISSILE, 4*4, sheets[3].index + sheets[3].size };
	// Small Energy
	sheets[5] = (Sheet){ SHEET_ENERGY, 6*1, sheets[4].index + sheets[4].size };
	// The rest are blank
	for(u8 i = 6; i < 10; i++) sheets[i] = (Sheet) {};
	// Actually load the tiles - assume the VDP is disabled
	// TODO: Move these to player_init
	sheets_refresh_polarstar(1);
	sheets_refresh_machinegun(1);
	sheets_refresh_fireball(1);
	
}

void sheets_refresh_polarstar(u8 level) {
	const SpriteDefinition *def;
	if(level == 1) def = &SPR_PolarB1;
	else if(level == 2) def = &SPR_PolarB2;
	else if(level == 3) def = &SPR_PolarB3;
	else {
		printf("Polar Star has no level %hu", level);
		return;
	}
	VDP_loadTileData(SPR_TILESET(def, 0, 0)->tiles, sheets[0].index, 4, true);
	VDP_loadTileData(SPR_TILESET(def, 1, 0)->tiles, sheets[0].index + 4, 4, true);
}

void sheets_refresh_machinegun(u8 level) {
	const SpriteDefinition *def;
	if(level == 1) def = &SPR_MGunB1;
	else if(level == 2) def = &SPR_MGunB2;
	else if(level == 3) def = &SPR_MGunB3;
	else {
		printf("Machine Gun has no level %hu", level);
		return;
	}
	VDP_loadTileData(SPR_TILESET(def, 0, 0)->tiles, sheets[1].index, 4, true);
	VDP_loadTileData(SPR_TILESET(def, 1, 0)->tiles, sheets[1].index + 4, 4, true);
}

void sheets_refresh_fireball(u8 level) {
	const SpriteDefinition *def;
	if(level == 1) def = &SPR_FirebB1;
	else if(level == 2) def = &SPR_FirebB1;
	else if(level == 3) def = &SPR_FirebB3;
	else {
		printf("Fireball has no level %hu", level);
		return;
	}
	VDP_loadTileData(SPR_TILESET(def, 0, 0)->tiles, sheets[2].index, 4, true);
	VDP_loadTileData(SPR_TILESET(def, 0, 1)->tiles, sheets[2].index + 4, 4, true);
	VDP_loadTileData(SPR_TILESET(def, 0, 2)->tiles, sheets[2].index + 8, 4, true);
}

void sheets_set_stage(u16 sid) {
	switch(sid) {
		
		default:
		printf("Stage %hu has no sheet set", sid);
	}
}