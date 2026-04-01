#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/wild_encounter.h"

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *hiddenMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
};

enum WildArea
{
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

extern const struct WildPokemonHeader gWildMonHeaders[];
extern bool8 gIsFishingEncounter;
extern bool8 gIsSurfingEncounter;
extern u8 gChainFishingDexNavStreak;

// Buffers for filtered encounter tables (mono-generation mode)
extern struct WildPokemon sFilteredLandMons[];
extern struct WildPokemon sFilteredWaterMons[];
extern struct WildPokemon sFilteredRockMons[];
extern struct WildPokemon sFilteredFishMons[];
extern struct WildPokemonInfo sFilteredLandInfo;
extern struct WildPokemonInfo sFilteredWaterInfo;
extern struct WildPokemonInfo sFilteredRockInfo;
extern struct WildPokemonInfo sFilteredFishInfo;

void DisableWildEncounters(bool8 disabled);
u8 PickWildMonNature(void);
bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
bool8 DoesRodHaveFishingMonsInGeneration(u8 rod);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
bool8 TryDoDoubleWildBattle(void);
bool8 StandardWildEncounter_Debug(void);
void CreateWildMon(u16 species, u8 level);
u16 GetCurrentMapWildMonHeaderId(void);
u8 ChooseWildMonIndex_Land(void);
u8 ChooseWildMonIndex_WaterRock(void);
u8 ChooseHiddenMonIndex(void);
bool32 MapHasNoEncounterData(void);
const struct WildPokemonInfo *FilterEncounterTableByGeneration(
    const struct WildPokemonInfo *originalInfo,
    struct WildPokemon *buffer,
    struct WildPokemonInfo *filteredInfo,
    u8 encounterCount);
u32 CalculateChainFishingShinyRolls(void);

#endif // GUARD_WILD_ENCOUNTER_H
