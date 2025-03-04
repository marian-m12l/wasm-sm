// Enemy AI - Crocomire
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "enemy_types.h"
#include "sm_a4.h"




static const uint16 g_word_A48692 = 8;
static const uint16 g_word_A48694 = 8;
static const uint16 g_word_A48696 = 0;
static const uint16 g_word_A48698 = 2;
static const uint16 g_word_A4869A = 1;
static const uint16 g_word_A4869C = 3;
static const uint16 g_word_A4869E = 3;
static const uint16 g_word_A486A0 = 8;
static const uint16 g_word_A486A2 = 0x300;
static const uint16 g_word_A486A4 = 0x640;

void Enemy_GrappleReact_SamusLatchesOn_A4(void) {  // 0xA48005
  SamusLatchesOnWithGrapple();
}

void Enemy_NormalTouchAI_A4(void) {  // 0xA48023
  NormalEnemyTouchAi();
}

void Enemy_NormalShotAI_A4(void) {  // 0xA4802D
  NormalEnemyShotAi();
}

void Enemy_NormalFrozenAI_A4(void) {  // 0xA48041
  NormalEnemyFrozenAI();
}

void Crocomire_Hurt(void) {  // 0xA48687
  Crocomire_Func_27(cur_enemy_index);
  Crocomire_Func_31();
}

typedef const uint16 *CrocomireFunc(uint16 k, const uint16 *jp);

static CrocomireFunc *const off_A486B3[21] = {  // 0xA486A6
  Crocomire_Func_2,  Crocomire_Func_3,  Crocomire_Func_4,  Crocomire_Func_5,
  Crocomire_Func_7,  Crocomire_Func_8,  Crocomire_Func_9, Crocomire_Func_10,
  Crocomire_Func_11, Crocomire_Func_13, Crocomire_Func_14, Crocomire_Func_15,
  Crocomire_Func_16, Crocomire_Func_17, Crocomire_Func_18, Crocomire_Func_21,
  Crocomire_Func_22, Crocomire_Func_23, Crocomire_Func_24, Crocomire_Func_25,
  Crocomire_Func_26,
};

const uint16 *Crocomire_Instr_1(uint16 k, const uint16 *jp) {
  uint16 crocom_var_C = Get_Crocomire(cur_enemy_index)->crocom_var_C;
  return off_A486B3[crocom_var_C >> 1](crocom_var_C, jp);
}

const uint16 *Crocomire_Func_2(uint16 k, const uint16 *jp) {  // 0xA486DE
  Get_Crocomire(k)->base.instruction_timer = 1;
  return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BADE);
}

const uint16 *Crocomire_Func_3(uint16 k, const uint16 *jp) {  // 0xA486E8
  Get_Crocomire(0)->crocom_var_C = 4;
  return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BBCE);
}

const uint16 *Crocomire_Func_4(uint16 k, const uint16 *jp) {  // 0xA486F2
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 v1 = abs16(E->base.x_pos - samus_x_pos);
  if (sign16(v1 - 224)) {
    E->crocom_var_B |= 0x8000;
    E->crocom_var_C = 18;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC56);
  }
  return jp;
}

const uint16 *Crocomire_Func_5(uint16 k, const uint16 *jp) {  // 0xA48717
  Enemy_Crocomire *E = Get_Crocomire(0);
  if ((E->crocom_var_B & 0x800) != 0 && (E->crocom_var_B &= ~0x800, E->crocom_var_D)) {
    jp = INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC30);
    E->crocom_var_C = 12;
  } else if ((int16)(E->base.x_pos - g_word_A486A2) < 0) {
    jp = INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BE7E);
    E->crocom_var_C = 10;
  } else if ((int16)(INSTR_ADDR_TO_PTR(0, jp) - addr_kCrocomire_Ilist_BC34) >= 0) {
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BBCE);
  }
  return jp;
}

const uint16 *Crocomire_Instr_14(uint16 k, const uint16 *jp) {  // 0xA48752
  if (sign16((random_number & 0xFFF) - 1024)) {
    Enemy_Crocomire *E = Get_Crocomire(0);
    E->crocom_var_C = 8;
    E->crocom_var_F = 0;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BB36);
  }
  return jp;
}

const uint16 *Crocomire_Func_7(uint16 k, const uint16 *jp) {  // 0xA4876C
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_B = E->crocom_var_B;
  if ((crocom_var_B & 0x800) != 0) {
    E->crocom_var_B = crocom_var_B & 0xF7FF;
    jp = INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC30);
    E->crocom_var_C = 12;
  } else {
    uint16 crocom_var_F = E->crocom_var_F;
    if (sign16(crocom_var_F - 18)) {
      E->crocom_var_F += 2;
      SpawnEprojWithGfx(crocom_var_F, cur_enemy_index, addr_kEproj_CrocomireProjectile);
      QueueSfx3_Max6(kSfx3_CrocomireSpit);
    } else {
      jp = INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BBCA);
      E->crocom_var_C = 6;
    }
  }
  return jp;
}

const uint16 *Crocomire_Func_8(uint16 k, const uint16 *jp) {  // 0xA487B2
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_B = E->crocom_var_B;
  if ((crocom_var_B & 0x800) != 0) {
    E->crocom_var_B = crocom_var_B & 0xF7FF;
    jp = INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC30);
    E->crocom_var_C = 12;
  }
  return jp;
}

const uint16 *Crocomire_Func_9(uint16 k, const uint16 *jp) {  // 0xA487CA
  uint16 v2;

  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_D = E->crocom_var_D;
  if (crocom_var_D && (v2 = crocom_var_D - 1, (E->crocom_var_D = v2) != 0)) {
    E->crocom_var_C = 12;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC34);
  } else {
    E->crocom_var_C = 6;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BBCE);
  }
}

const uint16 *Crocomire_Func_10(uint16 k, const uint16 *jp) {  // 0xA487E9
  Enemy_Crocomire *E = Get_Crocomire(0);
  if ((int16)(E->base.x_pos - g_word_A486A2) >= 0) {
    E->crocom_var_C = 6;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BBCE);
  }
  return jp;
}

const uint16 *Crocomire_Func_11(uint16 k, const uint16 *jp) {  // 0xA487FB
  Get_Crocomire(0)->crocom_var_C = 6;
  return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BD2A);
}

const uint16 *Crocomire_Func_12(uint16 k, const uint16 *jp) {  // 0xA48805
  Enemy_Crocomire *E = Get_Crocomire(0);
  E->crocom_var_B &= ~0x400;
  return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BCD8);
}

const uint16 *Crocomire_Func_13(uint16 k, const uint16 *jp) {  // 0xA48812
  Enemy_Crocomire *E = Get_Crocomire(0);
  if ((E->crocom_var_B & 0x800) != 0) {
    E->crocom_var_B &= ~0x800;
    E->crocom_var_C = 20;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC30);
  } else if ((int16)(INSTR_ADDR_TO_PTR(0, jp) - addr_kCrocomire_Ilist_BDA2) >= 0) {
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BD2A);
  }
  return jp;
}

const uint16 *Crocomire_Func_14(uint16 k, const uint16 *jp) {  // 0xA48836
  Enemy_Crocomire *E = Get_Crocomire(0);
  if ((E->crocom_var_B & 0x800) != 0) {
    E->crocom_var_B &= ~0x800;
    E->crocom_var_C = 12;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC30);
  } else if ((int16)(INSTR_ADDR_TO_PTR(0, jp) - addr_kCrocomire_Ilist_BDA2) >= 0) {
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BD2A);
  }
  return jp;
}

const uint16 *Crocomire_Func_15(uint16 k, const uint16 *jp) {  // 0xA4885A
  Enemy_Crocomire *E = Get_Crocomire(0);
  if ((E->crocom_var_B & 0x800) != 0) {
    E->crocom_var_B &= ~0x800;
    E->crocom_var_C = 12;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BC30);
  } else if ((int16)(INSTR_ADDR_TO_PTR(0, jp) - addr_kCrocomire_Ilist_BDA2) >= 0) {
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BD2A);
  }
  return jp;
}

const uint16 *Crocomire_Func_16(uint16 k, const uint16 *jp) {  // 0xA4887E
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 v1 = E->crocom_var_D - 1;
  E->crocom_var_D = v1;
  if (sign16(v1 - 2)) {
    E->crocom_var_D = 0;
    E->crocom_var_C = 6;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BBCE);
  }
  return jp;
}

const uint16 *Crocomire_Func_17(uint16 k, const uint16 *jp) {  // 0xA4889A
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_B = E->crocom_var_B;
  if ((crocom_var_B & 0x800) != 0) {
    E->crocom_var_B = crocom_var_B & 0x1F00 | 0xA000;
    E->crocom_var_D = 1;
    E->crocom_var_E = 10;
    E->crocom_var_C = 12;
    QueueSfx2_Max6(kSfx2_CrocomireRelated_SeeminglyUnused_HighPriority);
  } else {
    Get_Crocomire(cur_enemy_index)->crocom_var_C = 10;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BD8E);
  }
  return jp;
}

const uint16 *Crocomire_Func_18(uint16 k, const uint16 *jp) {  // 0xA488D2
  const uint16 *result = Crocomire_Func_2(cur_enemy_index, jp);
  Enemy_Crocomire *E = Get_Crocomire(0);
  E->crocom_var_B |= 0x200;
  E->crocom_var_D = 32;
  E->crocom_var_C = 30;
  return result;
}

const uint16 *Crocomire_Func_19(uint16 k, const uint16 *jp) {  // 0xA488EE
  bool v2; // zf

  jp = Crocomire_Func_2(cur_enemy_index, jp);
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (!E->crocom_var_D || (v2 = E->crocom_var_D == 1, --E->crocom_var_D, v2)) {
    jp = Crocomire_Func_20(cur_enemy_index);
    E->crocom_var_C = 32;
  }
  return jp;
}

const uint16 *Crocomire_Func_20(uint16 k) {  // 0xA4890B
  Get_Crocomire(k)->crocom_var_C = 20;
  Enemy_Crocomire *E = Get_Crocomire(0);
  E->crocom_var_B = E->crocom_var_B;
  return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BAEA);
}

const uint16 *Crocomire_Func_21(uint16 k, const uint16 *jp) {  // 0xA4891B
  Enemy_Crocomire *E = Get_Crocomire(0);
  if ((E->crocom_var_B & 0x100) != 0) {
    jp = Crocomire_Func_2(cur_enemy_index, jp);
    E->crocom_var_D = 16;
    E->crocom_var_C = 34;
  } else {
    jp = Crocomire_Func_20(cur_enemy_index);
    E->crocom_var_C = 32;
  }
  return jp;
}

const uint16 *Crocomire_Func_22(uint16 k, const uint16 *jp) {  // 0xA48940
  k = cur_enemy_index;
  jp = Crocomire_Func_2(k, jp);
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (!E->crocom_var_D) {
    E->crocom_var_B |= 0x2000;
    jp = Crocomire_Func_3(k, jp);
    E->crocom_var_C = 36;
  }
  return jp;
}

const uint16 *Crocomire_Func_23(uint16 k, const uint16 *jp) {  // 0xA4895E
  k = cur_enemy_index;

  Enemy_Crocomire *E = Get_Crocomire(0);
  if (sign16(E->base.x_pos - 672)) {
    jp = Crocomire_Func_3(k, jp);
    E->crocom_var_C = 36;
    E->crocom_var_D = 3;
  } else {
    if ((E->crocom_var_B & 0x4000) == 0) {
      E->crocom_var_C = 38;
      jp = Crocomire_Func_12(k, jp);
    }
    if ((E->crocom_var_B & 0x4000) != 0) {
      E->crocom_var_D = 5;
      jp = INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BCD8);
      E->crocom_var_F = E->crocom_var_C;
      E->crocom_var_C = 42;
    }
  }
  return jp;
}

const uint16 *Crocomire_Func_24(uint16 k, const uint16 *jp) {  // 0xA489A8
  bool v2; // zf

  k = cur_enemy_index;
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (!E->crocom_var_D || (v2 = E->crocom_var_D == 1, --E->crocom_var_D, v2)) {
    jp = Crocomire_Func_3(k, jp);
    E->crocom_var_C = 40;
    E->crocom_var_B &= ~0x400;
  } else {
    E->crocom_var_C = 36;
    Get_Crocomire(0x40)->crocom_var_D = 0;
    E->crocom_var_B |= 0x400;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BCD8);
  }
  return jp;
}

const uint16 *Crocomire_Func_25(uint16 k, const uint16 *jp) {  // 0xA489DE
  k = cur_enemy_index;
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_B = E->crocom_var_B;
  if ((crocom_var_B & 0x2000) == 0)
    E->crocom_var_B = crocom_var_B & 0xFCFF;
  jp = Crocomire_Func_3(k, jp);
  E->crocom_var_C = 40;
  return jp;
}

const uint16 *Crocomire_Func_26(uint16 k, const uint16 *jp) {  // 0xA489F9
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (E->crocom_var_D) {
    uint16 crocom_var_B = E->crocom_var_B;
    if ((crocom_var_B & 0x4000) != 0) {
      --E->crocom_var_D;
      QueueSfx2_Max6(kSfx2_DachoraShinespark);
      return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BCD8);
    } else {
      E->crocom_var_B = crocom_var_B & 0xBFFF;
      E->crocom_var_C = 12;
    }
  } else {
    E->crocom_var_B &= ~0x4000;
    E->base.instruction_timer = 1;
    E->crocom_var_C = E->crocom_var_F;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BCD8);
  }
  return jp;
}

void Crocomire_Init(void) {  // 0xA48A5A
  VramWriteEntry *v7;

  boss_id = kBossId_6_Crocomire;
  uint16 v0 = 0;
  do {
    tilemap_stuff[v0 >> 1] = 824;
    v0 += 2;
  } while ((int16)(v0 - 4096) < 0);
  if ((*(uint16 *)&boss_bits_for_area[area_index] & kBossBit_AreaMiniBoss) != 0) {
    *(uint16 *)scrolls = (kScroll_Blue << 8) | kScroll_Blue;
    *(uint16 *)&scrolls[2] = (kScroll_Blue << 8) | kScroll_Blue;
    croco_target_0688 = 0;
    Enemy_Crocomire *E = Get_Crocomire(0);
    E->base.properties = E->base.properties & 0x7BFF | 0x400;
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x20, 0x03, 0xb753 });
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x1e, 0x03, 0xb753 });
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x61, 0x0b, 0xb747 });
    E->crocom_var_A = 84;
    E->base.current_instruction = addr_kCrocomire_Ilist_E1CC;
    E->base.instruction_timer = 1;
    E->base.x_pos = 576;
    E->base.y_pos = 144;
    E->base.y_height = 28;
    E->base.x_width = 40;
    uint16 v6 = vram_write_queue_tail;
    v7 = gVramWriteEntry(vram_write_queue_tail);
    v7->size = 2048;
    v7->src.addr = 0x2000;
    *(uint16 *)&v7->src.bank = 126;
    v7->vram_dst = (reg_BG2SC & 0xFC) << 8;
    vram_write_queue_tail = v6 + 7;
  } else {
    DisableMinimapAndMarkBossRoomAsExplored();
    croco_word_7E069A = 0;
    Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
    E->crocom_var_A = 0;
    E->crocom_var_E = 0;
    *(uint16 *)scrolls = kScroll_Red;
    for (int i = 32; i >= 0; i -= 2) {
      int v3 = i >> 1;
      target_palettes[v3 + 160] = kEnemyInit_Crocomire_Palette2[v3];
      target_palettes[v3 + 208] = kEnemyInit_Crocomire_Palette5[v3];
    }
    E->crocom_var_C = 4;
    UNUSED_word_7E179E = 16;
    camera_distance_index = 2;
    enemy_bg2_tilemap_size = 1024;
    E->base.current_instruction = addr_kCrocomire_Ilist_BADE;
    E->base.extra_properties |= 4;
    E->base.instruction_timer = 1;
  }
}

void Crocomire_Func_27(uint16 k) {  // 0xA48B5B
  reg_BG2VOFS = 67 - Get_Crocomire(k)->base.y_pos;
  uint16 v1 = 32;
  uint16 spritemap_pointer;
  while (1) {
    spritemap_pointer = Get_Crocomire(0)->base.spritemap_pointer;
    if (spritemap_pointer == kCrocomire_SpritemapPtrs[v1 >> 1])
      break;
    v1 -= 2;
    if ((v1 & 0x8000) != 0) {
      Crocomire_8BA4();
      return;
    }
  }
  reg_BG2VOFS += *((uint16 *)RomPtr_A4(spritemap_pointer) + 14);
  Crocomire_8BA4();
}

void Crocomire_8BA4(void) {  // 0xA48BA4
  Enemy_Crocomire *E0 = Get_Crocomire(cur_enemy_index);
  Enemy_Crocomire *E1 = Get_Crocomire(cur_enemy_index + 64);
  E1->base.x_pos = E1->crocom_var_A + E0->base.x_pos;
  E1->base.y_pos = E0->base.y_pos;
  uint16 x_pos = E0->base.x_pos;
  if ((int16)(x_pos - layer1_x_pos) >= 0) {
    if (sign16(E0->base.x_pos - 128 - (layer1_x_pos + 256)))
      goto LABEL_3;
LABEL_6:
    reg_BG2HOFS = 256;
    return;
  }
  if ((int16)(x_pos + 128 - layer1_x_pos) < 0)
    goto LABEL_6;
LABEL_3:;
  uint16 v6 = layer1_x_pos - E0->base.x_pos + 51;
  uint16 v4 = abs16(v6);
  if (!sign16(v4 - 284))
    v6 = 256;
  reg_BG2HOFS = v6;
}

void nullsub_305(void) {}

static Func_V *const off_A48C14[45] = {  // 0xA48C04
  Crocomire_Func_28, Crocomire_Func_52, Crocomire_Func_36,    Crocomire_92CE, Crocomire_Func_54, Crocomire_Func_36,    Crocomire_92CE, Crocomire_Func_54,
  Crocomire_Func_57, Crocomire_Func_60, Crocomire_Func_62,    Crocomire_929E, Crocomire_Func_64, Crocomire_Func_65, Crocomire_Func_66, Crocomire_Func_51,
     Crocomire_8D47,    Crocomire_929E, Crocomire_Func_51,    Crocomire_8D47,    Crocomire_929E, Crocomire_Func_51, Crocomire_Func_59, Crocomire_Func_60,
  Crocomire_Func_62, Crocomire_Func_63, Crocomire_Func_56,    Crocomire_9506, Crocomire_Func_65, Crocomire_Func_66, Crocomire_Func_49, Crocomire_Func_68,
  Crocomire_Func_70, Crocomire_Func_71, Crocomire_Func_72, Crocomire_Func_73, Crocomire_Func_88,    Crocomire_9B65, Crocomire_Func_90, Crocomire_Func_89,
     Crocomire_9B86,       nullsub_305, Crocomire_Func_91, Crocomire_Func_29, Crocomire_Func_69,
};

void Crocomire_Main(void) {

  int v0 = Get_Crocomire(0)->crocom_var_A >> 1;
  off_A48C14[v0]();
  Crocomire_Func_30();
  Crocomire_Func_31();
}

void Crocomire_Func_28(void) {  // 0xA48C6E
  Crocomire_Func_37();
  *(uint16 *)&scrolls[4] = (kScroll_Blue << 8) | kScroll_Blue;
  if (!sign16(samus_x_pos - 1312))
    *(uint16 *)&scrolls[4] = kScroll_Blue << 8;
  Crocomire_Func_27(cur_enemy_index);
}

void Crocomire_Func_29(void) {  // 0xA48C90
  reg_BG2HOFS = 0;
  reg_BG2VOFS = 0;
}

void Crocomire_Func_30(void) {  // 0xA48C95
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (!E->crocom_var_A && (int16)(E->base.x_pos - E->base.x_width - samus_x_radius - samus_x_pos) < 0) {
    NormalEnemyTouchAi();
    samus_x_pos = E->base.x_pos - E->base.x_width - samus_x_radius;
    samus_prev_x_pos = samus_x_pos;
    extra_samus_x_displacement = -4;
    extra_samus_y_displacement = -1;
  }
}

void Crocomire_Func_31(void) {  // 0xA48CCB
  uint16 j;

  if (!door_transition_flag_enemies) {
    if (Get_Crocomire(0)->base.flash_timer && (random_enemy_counter & 2) != 0) {
      for (int i = 14; i >= 0; i -= 2)
        palette_buffer[(i >> 1) + 112] = 0x7FFF;
    } else {
      for (j = 14; (j & 0x8000) == 0; j -= 2)
        palette_buffer[(j >> 1) + 112] = kCrocomire_Bg1AndBg2Palette7[j >> 1];
    }
  }
}

const uint16 *Crocomire_Instr_11(uint16 k, const uint16 *jp) {  // 0xA48CFB
  QueueSfx2_Max6(kSfx2_CrocomiresCry_HighPriority);
  return jp;
}

const uint16 *Crocomire_Instr_7(uint16 k, const uint16 *jp) {  // 0xA48D07
  QueueSfx2_Max6(kSfx2_BigExplosion);
  return jp;
}

const uint16 *Crocomire_Instr_19(uint16 k, const uint16 *jp) {  // 0xA48D13
  QueueSfx2_Max6(kSfx2_CrocomiresSkeletonCollapses_HighPriority);
  return jp;
}

void Crocomire_Func_35(void) {  // 0xA48D1F
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_20 = E->crocom_var_20;
  if (crocom_var_20) {
    uint16 v2 = crocom_var_20 - 1;
    E->crocom_var_20 = v2;
    if (!v2) {
      E->crocom_var_20 = 32;
      QueueSfx3_Max6(kSfx3_CrocomireAcidDamage);
    }
  }
}

void Crocomire_Func_36(void) {  // 0xA48D3F
  Crocomire_Func_35();
  Crocomire_8BA4();
  Crocomire_8D47();
}

void Crocomire_8D47(void) {  // 0xA48D47
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_D = E->crocom_var_D;
  if (crocom_var_D) {
    E->crocom_var_D = crocom_var_D - 1;
  } else {
    ++E->crocom_var_A;
    ++E->crocom_var_A;
    E->crocom_var_E = 768;
  }
}

void Crocomire_Func_37(void) {  // 0xA48D5E

  Enemy_Crocomire *E0 = Get_Crocomire(0);
  if (sign16(E0->base.x_pos - 1536)) {
    kraid_unk9000 = 0;
    g_word_7E9002 = 0;
    g_word_7E9006 = 0;
    g_word_7E900A = 0;
  } else if (sign16(E0->base.x_pos - 1552)) {
    if (!kraid_unk9000) {
      kraid_unk9000 = 1;
      eproj_spawn_pt = (Point16U){ 1536, 176 };
      SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
    }
  } else if (sign16(E0->base.x_pos - 1552)) {
    g_word_7E9002 = 0;
    g_word_7E9006 = 0;
    g_word_7E900A = 0;
  } else if (sign16(E0->base.x_pos - 1568)) {
    if (!g_word_7E9002) {
      g_word_7E9002 = 1;
      SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x61, 0x0b, 0xb74b });
      eproj_spawn_pt = (Point16U){ 1568, 176 };
      SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
    }
  } else {
    uint16 x_pos = E0->base.x_pos;
    if (sign16(x_pos - 1568)) {
      g_word_7E9006 = 0;
      g_word_7E900A = 0;
    } else if (sign16(x_pos - 1584)) {
      if (!g_word_7E9006) {
        g_word_7E9006 = 1;
        SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x62, 0x0b, 0xb74b });
        SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x63, 0x0b, 0xb74b });
        eproj_spawn_pt = (Point16U){ 1584, 176 };
        SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
      }
    } else if ((int16)(x_pos - g_word_A486A4) >= 0) {
      Crocomire_8EE5();
      E0->crocom_var_20 = 1;
      g_word_7E9018 = 1;
      uint16 v3 = cur_enemy_index;
      Enemy_Crocomire *EK = Get_Crocomire(cur_enemy_index);
      EK->crocom_var_A += 2;
      Get_Crocomire(0)->crocom_var_00 = 2;
      Get_Crocomire(0x40)->crocom_var_00 = 2;
      Get_Crocomire(0x80)->crocom_var_00 = 2;
      Get_Crocomire(0xC0)->crocom_var_00 = 2;
      Get_Crocomire(0x100)->crocom_var_00 = 2;
      Get_Crocomire(0x140)->crocom_var_00 = 2;
      Get_Crocomire(0)->crocom_var_01 = 0;
      Get_Crocomire(0x40)->crocom_var_01 = 0;
      Get_Crocomire(0x80)->crocom_var_01 = 0;
      Get_Crocomire(0xC0)->crocom_var_01 = 0;
      Get_Crocomire(0x100)->crocom_var_01 = 0;
      Get_Crocomire(0x140)->crocom_var_01 = 0;
      QueueSfx2_Max6(kSfx2_DachoraShinespark);
      *(uint16 *)((uint8 *)&g_word_7E9015 + 1) = 0;
      SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x4e, 0x03, 0xb757 });
      EK->base.current_instruction = addr_kCrocomire_Ilist_BFB0;
      EK->base.instruction_timer = 1;
      EK->base.properties |= kEnemyProps_Tangible;
      Enemy_Crocomire *E1 = Get_Crocomire(cur_enemy_index + 64);
      E1->base.instruction_timer = 0x7FFF;
      E1->base.current_instruction = addr_kCrocomire_Ilist_BF62;
      Get_Crocomire(0x40)->base.properties |= 0x100;
      EK->crocom_var_E = 0;
      EK->crocom_var_F = 0;
      EK->crocom_var_D = 2048;
      Get_Crocomire(0)->base.y_height = 16;
    }
  }
}

void Crocomire_8EE5(void) {  // 0xA48EE5
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x61, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x62, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x63, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x64, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x65, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x66, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x67, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x68, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x69, 0x0b, 0xb74f });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x6a, 0x0b, 0xb74f });
  eproj_spawn_pt = (Point16U){ 1536, 176 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
  eproj_spawn_pt = (Point16U){ 1552, 192 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
  eproj_spawn_pt = (Point16U){ 1568, 176 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
  eproj_spawn_pt = (Point16U){ 1584, 192 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
  eproj_spawn_pt = (Point16U){ 1600, 192 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
  eproj_spawn_pt = (Point16U){ 1616, 192 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
  eproj_spawn_pt = (Point16U){ 1632, 192 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
}

const uint16 *Crocomire_Instr_2(uint16 k, const uint16 *jp) {  // 0xA48FC7
  earthquake_type = 4;
  earthquake_timer = 5;
  QueueSfx2_Max6(kSfx2_Quake);
  return jp;
}

const uint16 *Crocomire_Instr_4(uint16 k, const uint16 *jp) {  // 0xA48FDF
  if ((Get_Crocomire(0)->crocom_var_B & 0x800) == 0)
    Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, INT16_SHL16(-4));
  return jp;
}

const uint16 *Crocomire_Instr_3(uint16 k, const uint16 *jp) {  // 0xA48FFA
  Crocomire_Func_43();
  return Crocomire_Instr_4(k, jp);
}

const uint16 *Crocomire_Instr_15(uint16 k, const uint16 *jp) {  // 0xA48FFF
  Crocomire_Func_43();
  return Crocomire_Instr_4(k, jp);
}

void Crocomire_Func_43(void) {  // 0xA49004
  uint16 v1 = random_number & 0x1F;
  if ((int16)(random_number - 4096) >= 0)
    v1 = -v1;
  Crocomire_Func_87(0, v1);
}

const uint16 *Crocomire_Instr_16(uint16 k, const uint16 *jp) {  // 0xA4901D
  if (Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, INT16_SHL16(-4))) {
    Get_Crocomire(0)->crocom_var_C = 14;
    return INSTR_RETURN_ADDR(addr_kCrocomire_Ilist_BF3C);
  } else {
    uint16 v2 = 32;
    if (!sign16(random_number - 2048))
      v2 = -32;
    return Crocomire_Func_87(jp, v2 + (random_number & 0xF));
  }
}

const uint16 *Crocomire_Instr_13(uint16 k, const uint16 *jp) {  // 0xA4905B
  Enemy_Crocomire *E = Get_Crocomire(0);
  if ((int16)(E->base.x_pos - E->base.x_width - 260 - layer1_x_pos) < 0)
    Enemy_MoveRight_IgnoreSlopes(cur_enemy_index, INT16_SHL16(4));
  return jp;
}

const uint16 *Crocomire_Instr_18(uint16 k, const uint16 *jp) {  // 0xA4907F
  Enemy_MoveRight_IgnoreSlopes(k, INT16_SHL16(4));
  return jp;
}

const uint16 *Crocomire_Instr_12(uint16 k, const uint16 *jp) {  // 0xA4908F
  Crocomire_Func_43();
  return Crocomire_Instr_13(k, jp);
}

const uint16 *Crocomire_Instr_17(uint16 k, const uint16 *jp) {  // 0xA49094
  Crocomire_Func_43();
  return Crocomire_Instr_18(k, jp);
}

void Crocomire_Func_49(void) {  // 0xA49099
  Crocomire_Func_50();
  Crocomire_Func_53();
  Crocomire_Func_55();
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (E->crocom_var_A == 62) {
    QueueMusic_Delayed8(kMusic_Song1);
    E->crocom_var_A = 88;
    E->base.current_instruction = addr_kCrocomire_Ilist_E1D2;
    *(uint16 *)&scrolls[4] = (kScroll_Blue << 8) | kScroll_Blue;
    debug_disable_minimap = 0;
    Get_Crocomire(0x40)->base.properties |= 0x200;
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x4e, 0x03, 0xb753 });
    camera_distance_index = 0;
    croco_target_0688 = 0;
  }
}

void Crocomire_Func_50(void) {  // 0xA490DF
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 y_pos = E->base.y_pos;
  uint16 v2 = addr_kCrocomire_Ilist_BF7E;
  if (sign16(y_pos - 280)) {
    v2 = addr_kCrocomire_Ilist_BF86;
    if (sign16(y_pos - 264)) {
      v2 = addr_kCrocomire_Ilist_BF8C;
      if (sign16(y_pos - 248))
        v2 = addr_kCrocomire_Ilist_BF92;
    }
  }
  E->base.current_instruction = v2;
  E->base.instruction_timer = 1;
}

void Crocomire_Func_51(void) {  // 0xA49108
  Crocomire_Func_53();
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 y_pos = E->base.y_pos;
  uint16 v2 = addr_kCrocomire_Ilist_BF64;
  if (sign16(y_pos - 280)) {
    v2 = addr_kCrocomire_Ilist_BF6C;
    if (sign16(y_pos - 264)) {
      v2 = addr_kCrocomire_Ilist_BF72;
      if (sign16(y_pos - 248))
        v2 = addr_kCrocomire_Ilist_BF78;
    }
  }
  E->base.current_instruction = v2;
  E->base.instruction_timer = 1;
  Crocomire_Func_55();
}

void Crocomire_Func_52(void) {  // 0xA49136
  uint16 v0 = *(uint16 *)((uint8 *)&g_word_7E9015 + 1);
  if (sign16(*(uint16 *)((uint8 *)&g_word_7E9015 + 1) - 22)) {
    uint16 v1 = *(uint16 *)((uint8 *)&g_word_7E9015 + 1);
    *(uint16 *)((uint8 *)&g_word_7E9015 + 1) += 2;
    SpawnEprojWithGfx(kCrocomire_BridgeCrumbleTab0[v0 >> 1], v1, addr_kEproj_CrocomireBridgeCrumbling);
  }
  Crocomire_Func_54();
}

void Crocomire_Func_53(void) {  // 0xA4916C
  if (!--g_word_7E9018) {
    g_word_7E9018 = 6;
    uint16 v0 = random_number & 0x3F;
    if ((random_number & 2) == 0)
      v0 = ~v0;
    uint16 x = Get_Crocomire(0)->base.x_pos + v0;
    uint16 y = lava_acid_y_pos + 16 - ((uint16)(random_number & 0x1F00) >> 8);
    CreateSpriteAtPos(x, y, 21, 0);
  }
}

void Crocomire_Func_54(void) {  // 0xA491BA
  Crocomire_Func_35();
  Crocomire_Func_53();
  Crocomire_Func_55();
}

void Crocomire_Func_55(void) {  // 0xA491C1
  int8 crocom_var_D;
  int8 v7;
  int8 v9;
  int8 crocom_var_E;
  int8 crocom_var_E_high;
  int8 v12;

  Crocomire_Func_58();
  Enemy_Crocomire *E0 = Get_Crocomire(0);
  E0->crocom_var_B &= ~0x800;
  Crocomire_Func_27(cur_enemy_index);
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  if (sign16(E->base.y_pos - 280)) {
    uint16 v3 = 8 * ((reg_BG2VOFS + 288) & 0xFFF8);
    int m = 32;
    do {
      tilemap_stuff[v3 >> 1] = 824;
      v3 += 2;
    } while (--m);
    nmi_flag_bg2_enemy_vram_transfer = 1;
    E0->base.extra_properties &= ~0x8000;
    crocom_var_D = E->crocom_var_D;
    LOBYTE(E->crocom_var_D) = crocom_var_D + 0x80;
    v7 = __CFADD__uint8(crocom_var_D, 0x80) + HIBYTE(E->crocom_var_D) + 3;
    if (!sign8(v7 - 48))
      v7 = 48;
    HIBYTE(E->crocom_var_D) = v7;
    bool v8 = __CFADD__uint8(LOBYTE(E->crocom_var_E), v7);
    LOBYTE(E->crocom_var_E) += v7;
    v9 = v8 + HIBYTE(E->crocom_var_E);
    if (!sign8(v9 - 3))
      v9 = 3;
    HIBYTE(E->crocom_var_E) = v9;
    crocom_var_E = E->crocom_var_E;
    v8 = __CFADD__uint8(HIBYTE(E->crocom_var_F), crocom_var_E);
    HIBYTE(E->crocom_var_F) += crocom_var_E;
    crocom_var_E_high = HIBYTE(E->crocom_var_E);
    bool v13 = v8;
    v8 = __CFADD__uint8(v8, crocom_var_E_high);
    v12 = v13 + crocom_var_E_high;
    v8 |= __CFADD__uint8(LOBYTE(E->base.y_pos), v12);
    LOBYTE(E->base.y_pos) += v12;
    HIBYTE(E->base.y_pos) += v8;
  } else {
    ++E->crocom_var_A;
    ++E->crocom_var_A;
    E0->crocom_var_D = 48;
  }
}

void Crocomire_Func_56(void) {  // 0xA4926E
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  uint16 y_pos = E->base.y_pos;
  uint16 v2 = addr_kCrocomire_Ilist_BF7E;
  if (sign16(y_pos - 280)) {
    v2 = addr_kCrocomire_Ilist_BF86;
    if (sign16(y_pos - 264)) {
      v2 = addr_kCrocomire_Ilist_BF8C;
      if (sign16(y_pos - 248))
        v2 = addr_kCrocomire_Ilist_BF92;
    }
  }
  E->base.current_instruction = v2;
  E->base.instruction_timer = 1;
  Crocomire_Func_53();
  Crocomire_92D8();
}

void Crocomire_929E(void) {  // 0xA4929E
  Crocomire_Func_53();
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  uint16 y_pos = E->base.y_pos;
  uint16 v2 = addr_kCrocomire_Ilist_BF64;
  if (sign16(y_pos - 280)) {
    v2 = addr_kCrocomire_Ilist_BF6C;
    if (sign16(y_pos - 264)) {
      v2 = addr_kCrocomire_Ilist_BF72;
      if (sign16(y_pos - 248))
        v2 = addr_kCrocomire_Ilist_BF78;
    }
  }
  E->base.current_instruction = v2;
  E->base.instruction_timer = 1;
  Crocomire_92D8();
}

void Crocomire_92CE(void) {  // 0xA492CE
  Crocomire_Func_35();
  Crocomire_Func_53();
  Crocomire_92D8();
}

void Crocomire_92D8(void) {  // 0xA492D8
  int16 v3;
  int8 v6;

  Crocomire_Func_58();
  Enemy_Crocomire *EK = Get_Crocomire(cur_enemy_index);
  if (sign16(EK->base.y_pos - 218)) {
    ++EK->crocom_var_A;
    ++EK->crocom_var_A;
  } else {
    Crocomire_Func_27(cur_enemy_index);
    Enemy_Crocomire *E0 = Get_Crocomire(0);
    v3 = E0->crocom_var_D + 256;
    if (!sign16(E0->crocom_var_D - 7680))
      v3 = 7936;
    E0->crocom_var_D = v3;
    uint8 crocom_var_E = E0->crocom_var_E;
    bool v5 = crocom_var_E < HIBYTE(E0->crocom_var_D);
    LOBYTE(E0->crocom_var_E) = crocom_var_E - HIBYTE(E0->crocom_var_D);
    v6 = HIBYTE(E0->crocom_var_E) - v5;
    if (v6 < 0) {
      LOBYTE(E0->crocom_var_E) = -1;
      v6 = 0;
    }
    HIBYTE(E0->crocom_var_E) = v6;
    uint8 crocom_var_F_high = HIBYTE(E0->crocom_var_F);
    v5 = crocom_var_F_high < LOBYTE(E0->crocom_var_E);
    HIBYTE(E0->crocom_var_F) = crocom_var_F_high - LOBYTE(E0->crocom_var_E);
    uint8 y_pos = E0->base.y_pos;
    uint8 v9 = v5 + HIBYTE(E0->crocom_var_E);
    LOBYTE(E0->base.y_pos) = y_pos - v9;
    HIBYTE(E0->base.y_pos) -= y_pos < v9;
  }
}

void Crocomire_Func_57(void) {  // 0xA49341
  int i;

  croco_word_068C = 48;
  croco_target_0688 = 48;
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  ++E->crocom_var_A;
  ++E->crocom_var_A;
  E->base.current_instruction = addr_kCrocomire_Ilist_BF64;
  E->base.instruction_timer = 1;
  nmi_flag_bg2_enemy_vram_transfer = 1;
  Enemy_Crocomire *E1 = Get_Crocomire(cur_enemy_index + 64);
  E1->base.current_instruction = addr_kCrocomire_Ilist_BF98;
  E1->base.instruction_timer = 1;
  E1->base.properties = E1->base.properties & 0xD2FF | 0x2C00;
  E1->base.x_pos = E->base.x_pos;
  E1->base.y_pos = E->base.y_pos + 16;
  uint16 v3 = 0;
  do {
    int v4 = v3 >> 1;
    tilemap_stuff[v4] = 824;
    tilemap_stuff[v4 + 1] = 824;
    v3 += 4;
  } while ((int16)(v3 - 1024) < 0);
  for (i = 0; ; i += 2) {
    int v6 = i >> 1;
    if (kCrocomire_Bg2TilemapIndices0[v6] == 0xFFFF)
      break;
    tilemap_stuff[v6 + 32] = kCrocomire_Bg2TilemapIndices0[v6];
  }
  Crocomire_93BE(i + 1024);
}

void Crocomire_93BE(uint16 k) {  // 0xA493BE
  VramWriteEntry *v3;

  uint16 v2 = vram_write_queue_tail;
  v3 = gVramWriteEntry(vram_write_queue_tail);
  v3->size = k;
  v3->src.addr = 0x2000;
  *(uint16 *)&v3->src.bank = 126;
  v3->vram_dst = (reg_BG2SC & 0xFC) << 8;
  vram_write_queue_tail = v2 + 7;
}

void Crocomire_Func_58(void) {  // 0xA493DF
  uint16 v0 = reg_BG2VOFS;
  for (int i = 510; i >= 0; i -= 2)
    crocomire_bg2_scroll_hdma_data[i >> 1] = v0;
}

void Crocomire_Func_59(void) {  // 0xA493ED
  int i;

  Crocomire_Func_58();
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  ++E->crocom_var_A;
  ++E->crocom_var_A;
  E->base.instruction_timer = 1;
  croco_word_068C = 48;
  croco_target_0688 = 48;
  E->base.current_instruction = addr_kCrocomire_Ilist_BF7E;
  uint16 v1 = 0;
  do {
    tilemap_stuff[v1 >> 1] = 824;
    v1 += 2;
  } while ((int16)(v1 - 2048) < 0);
  for (i = 0; ; i += 2) {
    int v3 = i >> 1;
    if (kCrocomire_Bg2TilemapIndices1[v3] == 0xFFFF)
      break;
    tilemap_stuff[v3 + 32] = kCrocomire_Bg2TilemapIndices1[v3];
  }
  Crocomire_93BE(i + 1024);
}

void Crocomire_Func_60(void) {  // 0xA4943D
  int i;

  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  E->crocom_var_A += 2;
  g_word_7E0692 = 256;
  croco_cur_vline_idx = 0;
  g_word_7E0698 = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab0 + croco_word_7E069A);
  g_word_7E0694 = g_word_7E0698;
  g_word_7E0696 = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab1 + croco_word_7E069A);
  g_word_7E068E = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab2 + croco_word_7E069A);
  uint8 bank = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab3 + croco_word_7E069A);
  uint16 v6;
  for (i = croco_word_7E069A + 8; ; i = v6 + 4) {
    uint16 v2 = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab0 + i);
    if (v2 == 0xFFFF)
      break;
    v6 = i;
    uint16 v3 = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab1 + i);
    int n = g_word_7E068E;
    do {
      *(uint16 *)&g_ram[v3] = GET_WORD(RomPtrWithBank(bank, v2));
      v3 += 2, v2 += 2;
    } while (--n >= 0);
  }
  croco_word_7E069A = i + 2;
  g_word_7E068A = i + 2;
  for (int j = 128; j >= 0; j -= 2)
    *(uint16 *)&croco_vline_height[(uint16)j] = 0;
}

void Crocomire_Func_61(void) {  // 0xA494B2
  Crocomire_Func_62();
}

void Crocomire_Func_62(void) {  // 0xA494B6
  VramWriteEntry *v2;

  uint16 v0 = g_word_7E068A;
  uint16 v1 = vram_write_queue_tail;
  if (*(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab0 + g_word_7E068A) == 0xFFFF) {
    Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
    ++E->crocom_var_A;
    ++E->crocom_var_A;
    g_word_7E068A = 0;
  } else {
    v2 = gVramWriteEntry(vram_write_queue_tail);
    v2->size = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab0 + g_word_7E068A);
    v2->src.addr = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab3 + v0);
    *(uint16 *)&v2->src.bank = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab2 + v0);
    v2->vram_dst = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab1 + v0);
    g_word_7E068A = v0 + 8;
    vram_write_queue_tail = v1 + 7;
  }
}

void Crocomire_Func_64(void) {  // 0xA494FB
  QueueSfx2_Max6(kSfx2_CrocomireMeltingCry_HighPriority);
  Crocomire_950F();
}

void Crocomire_9506(void) {  // 0xA49506
  QueueSfx2_Max6(kSfx2_KraidsRoar_CrocomireDyingCry_HighPriority);
  Crocomire_950F();
}

void Crocomire_950F(void) {  // 0xA4950F
  static const SpawnHdmaObject_Args unk_A49559 = { 0x42, 0x10, 0x9563 };
  Enemy_Crocomire *v4; // r10

  uint16 v1 = 2 * (Get_Crocomire(0x40)->base.y_pos - 72);
  uint16 v2 = reg_BG2VOFS;
  do {
    crocomire_bg2_scroll_hdma_data[v1 >> 1] = v2;
    v1 -= 2;
  } while ((v1 & 0x8000) == 0);
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  ++E->crocom_var_A;
  ++E->crocom_var_A;
  v4 = Get_Crocomire(0);
  Get_Crocomire(0x80)->crocom_var_D = v4->base.x_pos;
  *(uint16 *)crocomire_bg2_scroll_hdma_indirect = 255;
  *(uint16 *)&crocomire_bg2_scroll_hdma_indirect[1] = -13584;
  *(uint16 *)&crocomire_bg2_scroll_hdma_indirect[3] = 225;
  *(uint16 *)&crocomire_bg2_scroll_hdma_indirect[4] = -13330;
  *(uint16 *)&crocomire_bg2_scroll_hdma_indirect[6] = 0;
  v4->crocom_var_1F = SpawnHdmaObject(0xa4, &unk_A49559);
}

void Crocomire_Func_63(void) {  // 0xA49576
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  E->crocom_var_A += 2;
}

void Crocomire_Func_65(void) {  // 0xA49580
  int i;

  Crocomire_Func_53();
  Enemy_Crocomire *E0 = Get_Crocomire(0);
  Enemy_Crocomire *E1 = Get_Crocomire(0x40);
  Enemy_Crocomire *E2 = Get_Crocomire(0x80);
  uint16 crocom_var_D = E2->crocom_var_D;
  --E1->crocom_var_D;
  if ((E1->crocom_var_D & 2) != 0)
    crocom_var_D += 4;
  E0->base.x_pos = crocom_var_D;
  if (!Crocomire_Func_67())
    goto LABEL_4;
  Crocomire_Func_27(cur_enemy_index);
  uint16 v4;
  v4 = g_word_7E0694 - 3;
  if (sign16(g_word_7E0694 - 19)) {
    if ((int16)(g_word_7E0692 - 20480) >= 0) {
LABEL_4:;
      Enemy_Crocomire *EK = Get_Crocomire(cur_enemy_index);
      EK->crocom_var_A += 2;
      for (i = croco_word_7E069A; *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab0 + i) != 0xFFFF; i += 8)
        ;
      croco_word_7E069A = i + 2;
      hdma_object_channels_bitmask[E0->crocom_var_1F >> 1] = 0;
      return;
    }
    v4 = 16;
  }
  g_word_7E0694 = v4;
  uint16 v5 = g_word_7E0692 + 384;
  if (!sign16(g_word_7E0692 - 20096))
    v5 = 20480;
  g_word_7E0692 = v5;
  uint16 r18 = 0;
  uint16 v6 = 2 * (E1->base.y_pos - 72);
  uint16 v7 = g_word_7E0694;
  message_box_animation_y1_bottom_half = g_word_7E0694;
  do {
    crocomire_bg2_scroll_hdma_data[v6 >> 1] = reg_BG2VOFS + v7 - message_box_animation_y1_bottom_half;
    bool v8 = __CFADD__uint16(g_word_7E0692, r18);
    r18 += g_word_7E0692;
    if (!v8)
      ++v7;
    message_box_animation_y1_bottom_half++;
    v6 += 2;
  } while ((int16)(v7 - g_word_7E0698) < 0);
  if ((int16)(v6 - 512) < 0) {
    uint16 v9 = reg_BG2VOFS;
    do {
      crocomire_bg2_scroll_hdma_data[v6 >> 1] = v9;
      v6 += 2;
    } while ((int16)(v6 - 512) < 0);
  }
}

void Crocomire_Func_66(void) {  // 0xA49653
  VramWriteEntry *v3;

  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  E->crocom_var_E = 0;
  E->crocom_var_F = 0;
  E->crocom_var_D = 2048;
  for (int i = 4094; i >= 0; i -= 2)
    tilemap_stuff[i >> 1] = 824;
  uint16 v2 = vram_write_queue_tail;
  v3 = gVramWriteEntry(vram_write_queue_tail);
  v3->size = 2048;
  v3->src.addr = 0x2000;
  *(uint16 *)&v3->src.bank = 126;
  v3->vram_dst = (reg_BG2SC & 0xFE) << 8;
  vram_write_queue_tail = v2 + 7;
  Crocomire_9BB3();
}


static const uint8 kCrocoEraseLineMasks[8] = { 0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe };

//  Used when dissolving the crocomire thing
uint16 Crocomire_Func_67(void) {  // 0xA496C8
  int n = croco_word_068C;
//  R20 = 0;
  //R22_ = 0;
  while (1) {
    if (croco_cur_vline_idx > 48) // bugfix
      return 1;
    int rr = kCrocoVlineRandomPos[croco_cur_vline_idx];
    if ((int8)(croco_vline_height[rr] - croco_target_0688) < 0)
      break;
    if (++croco_cur_vline_idx >= 128) {
      croco_cur_vline_idx = 0;
      return 0;
    }
  }
  assert(croco_cur_vline_idx <= 48);
  int vline_idx = kCrocoVlineRandomPos[croco_cur_vline_idx];
  uint8 mask = kCrocoEraseLineMasks[vline_idx & 7];
  do {
    int q = croco_vline_height[vline_idx];
    int j = 2 * (q & 7) + ((q & ~7) << 6) + 4 * (vline_idx & ~7);
    ram4000.backups.field_0[j + 0] &= mask;
    ram4000.backups.field_0[j + 1] &= mask;
    ram4000.backups.field_0[j + 16] &= mask;
    ram4000.backups.field_0[j + 17] &= mask;

    if (croco_vline_height[vline_idx] == 48)
      break;
    croco_vline_height[vline_idx]++;
  } while (--n);

  uint16 v7, v8;
  while (1) {
    v7 = g_word_7E068A + croco_word_7E069A;
    v8 = vram_write_queue_tail;
    if (*(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab0 + v7) != 0xFFFF)
      break;
    g_word_7E068A = 0;
  }
  VramWriteEntry *v9 = gVramWriteEntry(vram_write_queue_tail);
  v9->size = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab0 + v7);
  v9->src.addr = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab3 + v7);
  *(uint16 *)&v9->src.bank = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab2 + v7);
  v9->vram_dst = *(uint16 *)((uint8 *)&kCrocomire_MeltingTilesTab1 + v7);
  vram_write_queue_tail = v8 + 7;
  g_word_7E068A += 8;
  return 1;
}

void Crocomire_Func_68(void) {  // 0xA497D3
  if (sign16(samus_x_pos - 640)) {
    QueueMusic_Delayed8(kMusic_Song0);
    *(uint16 *)&scrolls[3] = kScroll_Blue << 8;
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x30, 0x03, 0xb757 });
    camera_distance_index = 6;
    Enemy_Crocomire *E0 = Get_Crocomire(0);
    E0->base.properties = E0->base.properties & 0x7BFF | kEnemyProps_Tangible;
    Enemy_Crocomire *E1 = Get_Crocomire(0x40);
    E1->base.properties |= 0x500;
    E0->crocom_var_D = 4;
    E1->crocom_var_D = 0;
    Get_Crocomire(0x80)->crocom_var_D = 10;
    Get_Crocomire(0xC0)->crocom_var_D = 1;
    E0->crocom_var_B = 0;
    E0->base.y_height = 56;
    Crocomire_9BB3();
  }
}

void Crocomire_Func_69(void) {  // 0xA49830
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 v1 = E->base.x_pos - 2;
  E->base.x_pos = v1;
  if (sign16(v1 - 480)) {
    E->base.x_pos = 480;
    E->base.y_pos = 54;
    E->crocom_var_A = 62;
  } else {
    E->base.y_pos = 220;
  }
}

void Crocomire_Func_70(void) {  // 0xA49859
  Enemy_Crocomire *E0 = Get_Crocomire(0);
  Enemy_Crocomire *E1 = Get_Crocomire(0x40);
  Enemy_Crocomire *E2 = Get_Crocomire(0x80);
  Enemy_Crocomire *E3 = Get_Crocomire(0xc0);
  if (kCrocomire_Tab0[E0->crocom_var_D >> 1] == 0x8080) {
    E1->crocom_var_D = -32640;
    E0->crocom_var_D = 128;
    for (int i = 30; i >= 0; i -= 2)
      palette_buffer[(i >> 1) + 176] = kCrocomire_Palette3[i >> 1];
    Crocomire_9BB3();
  } else {
    uint16 crocom_var_D = E0->crocom_var_D;
    uint16 v3 = E1->crocom_var_D;
    int v4 = crocom_var_D >> 1;
    if (v3 == kCrocomire_Tab0[v4]) {
      if ((kCrocomire_Tab0[crocom_var_D >> 1] & 0x8000) != 0) {
        uint16 v7 = E2->crocom_var_D;
        if (v7) {
          E2->crocom_var_D = v7 - 1;
          E0->crocom_var_D = crocom_var_D - 2;
          QueueSfx2_Max6(kSfx2_RidleysFireballHitSurface_CrocomirePostDeathRumble_PhantoonExploding);
          return;
        }
        uint16 v8 = crocom_var_D + 2;
        E2->crocom_var_D = kCrocomire_Tab0[v8 >> 1];
        crocom_var_D = v8 + 2;
        E3->crocom_var_D = kCrocomire_Tab0[crocom_var_D >> 1];
      }
      E0->crocom_var_D = crocom_var_D + 2;
    } else {
      uint16 v5;
      if ((int16)(v3 - kCrocomire_Tab0[v4]) >= 0)
        v5 = v3 - E3->crocom_var_D;
      else
        v5 = E3->crocom_var_D + v3;
      E1->crocom_var_D = v5;
    }
  }
}

void Crocomire_Func_71(void) {  // 0xA4990A
  int16 v3;
  VramWriteEntry *v6;

  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 crocom_var_D = E->crocom_var_D;
  if (crocom_var_D) {
    E->crocom_var_D = crocom_var_D - 1;
    v3 = croco_target_0688;
    int v4 = croco_target_0688 >> 1;
    if (kCrocomire_TilesDestinationAddresses[v4] != 0xFFFF) {
      uint16 v5 = vram_write_queue_tail;
      v6 = gVramWriteEntry(vram_write_queue_tail);
      v6->size = 512;
      v6->src.addr = kCrocomire_TilesSourceAddresses[v4];
      *(uint16 *)&v6->src.bank = 173;
      v6->vram_dst = kCrocomire_TilesDestinationAddresses[v4] + ((reg_OBSEL & 7) << 13);
      vram_write_queue_tail = v5 + 7;
      croco_target_0688 = v3 + 2;
    }
  } else {
    E->base.x_pos = 480;
    E->base.y_pos = 54;
    Get_Crocomire(0x80)->crocom_var_D = 80;
    E->crocom_var_E = 0;
    E->crocom_var_F = 0;
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x20, 0x03, 0xb753 });
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x1e, 0x03, 0xb757 });
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x70, 0x0b, 0xb747 });
    QueueSfx2_Max6(kSfx2_MotherBrainRisingIntoPhase2_CrocomiresWallExplodes_SporeSpawnGetsHard);
    E->base.current_instruction = addr_kCrocomire_Ilist_E158;
    E->base.instruction_timer = 1;
    E->base.palette_index = 0;
    for (int i = 30; i >= 0; i -= 2)
      palette_buffer[(i >> 1) + 144] = kCrocomire_Palette1[i >> 1];
    ClearEprojs();
    uint16 v8 = 8;
    int n = 8;
    do {
      SpawnEprojWithGfx(v8, cur_enemy_index, addr_kEproj_CrocomireSpikeWallPieces);
    } while (--n);
    QueueSfx2_Max6(kSfx2_ShotSuperDesgeega_CrocomireDestroysWall);
    Crocomire_9BB3();
  }
}

void Crocomire_Func_72(void) {  // 0xA499E5
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (sign16(E->base.x_pos - 224)) {
    uint32 t = __PAIR32__(E->crocom_var_F, E->crocom_var_E) + 0x8000;
    if (!sign16((t >> 16) - 2))
      t = (t & 0xffff) | (2 << 16);
    SetHiLo(&E->crocom_var_F, &E->crocom_var_E, t);
    AddToHiLo(&E->base.x_pos, &E->base.x_subpos, t);
  }
  Enemy_Crocomire *E2 = Get_Crocomire(0x80);
  if (E2->crocom_var_D && E2->crocom_var_D-- == 1) {
    E->crocom_var_E = 0;
    E->base.current_instruction = addr_kCrocomire_Ilist_E14A;
    E->base.instruction_timer = 1;
    Crocomire_9BB3();
  }
}

void Crocomire_Func_73(void) {  // 0xA49A38
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint32 t = __PAIR32__(E->crocom_var_F, E->crocom_var_E) + 2048;
  if (!sign16((t >> 16) - 5))
    t = (t & 0xffff) | (5 << 16);
  SetHiLo(&E->crocom_var_F, &E->crocom_var_E, t);
  AddToHiLo(&E->base.y_pos, &E->base.y_subpos, 0xe000);
  AddToHiLo(&E->base.x_pos, &E->base.x_subpos, t);
  if (!sign16(E->base.x_pos - 576)) {
    QueueSfx2_Max6(kSfx2_BigExplosion);
    Get_Crocomire(0x40)->base.palette_index = E->base.palette_index;
    E->base.current_instruction = addr_kCrocomire_Ilist_E158;
    E->base.instruction_timer = 1;
    Crocomire_9BB3();
  }
}

const uint16 *Crocomire_Instr_8(uint16 k, const uint16 *jp) {  // 0xA49A9B
  return Crocomire_Func_87(jp, 0xFFE0);
}

const uint16 *Crocomire_Instr_6(uint16 k, const uint16 *jp) {  // 0xA49AA0
  return Crocomire_Func_87(jp, 0);
}

const uint16 *Crocomire_Instr_9(uint16 k, const uint16 *jp) {  // 0xA49AA5
  return Crocomire_Func_87(jp, 0xFFF0);
}

const uint16 *Crocomire_Instr_5(uint16 k, const uint16 *jp) {  // 0xA49AAA
  return Crocomire_Func_87(jp, 0x10);
}

const uint16 *Crocomire_Instr_20(uint16 k, const uint16 *jp) {  // 0xA49AAF
  return Crocomire_Func_87(jp, 0);
}

const uint16 *Crocomire_Instr_21(uint16 k, const uint16 *jp) {  // 0xA49AB4
  return Crocomire_Func_87(jp, 8);
}

const uint16 *Crocomire_Instr_22(uint16 k, const uint16 *jp) {  // 0xA49AB9
  return Crocomire_Func_87(jp, 0x10);
}

const uint16 *Crocomire_Instr_23(uint16 k, const uint16 *jp) {  // 0xA49ABE
  return Crocomire_Func_87(jp, 0x18);
}

const uint16 *Crocomire_Instr_24(uint16 k, const uint16 *jp) {  // 0xA49AC3
  return Crocomire_Func_87(jp, 0x20);
}

const uint16 *Crocomire_Instr_10(uint16 k, const uint16 *jp) {  // 0xA49AC8
  return Crocomire_Func_87(jp, 0x28);
}

const uint16 *Crocomire_Instr_25(uint16 k, const uint16 *jp) {  // 0xA49ACD
  return Crocomire_Func_87(jp, 0x30);
}

const uint16 *Crocomire_Instr_26(uint16 k, const uint16 *jp) {  // 0xA49AD2
  return Crocomire_Func_87(jp, 0x38);
}

const uint16 *Crocomire_Instr_27(uint16 k, const uint16 *jp) {  // 0xA49AD7
  return Crocomire_Func_87(jp, 0x40);
}

const uint16 *Crocomire_Func_87(const uint16 *jp, uint16 a) {  // 0xA49ADA
  Enemy_Crocomire *E = Get_Crocomire(0);
  eproj_spawn_pt = (Point16U){ a + E->base.x_pos + (random_number & 7), E->base.y_height + E->base.y_pos - 16 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 0x15);
  return jp;
}

void Crocomire_Func_88(void) {  // 0xA49B06
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (sign16(E->base.current_instruction + 0x1E3A)) {
    uint32 t = __PAIR32__(E->crocom_var_F, E->crocom_var_E) + 4096;
    if (!sign16((t >> 16) - 6))
      t = (t & 0xffff) | (6 << 16);
    SetHiLo(&E->crocom_var_F, &E->crocom_var_E, t);
  } else {
    E->base.current_instruction = addr_kCrocomire_Ilist_E1CC;
    E->base.instruction_timer = 1;
    E->base.x_pos += 64;
    E->base.y_pos += 21;
    E->base.y_height = 28;
    E->base.x_width = 40;
    SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x30, 0x03, 0xb753 });
    Enemy_ItemDrop_Crocomire(0);
    Crocomire_9BB3();
  }
}

void Crocomire_9B65(void) {  // 0xA49B65
  *(uint16 *)scrolls = (kScroll_Blue << 8) | kScroll_Blue;
  *(uint16 *)&scrolls[2] = (kScroll_Blue << 8) | kScroll_Blue;
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { 0x1e, 0x03, 0xb753 });
  Crocomire_9BB3();
}

void Crocomire_Func_89(void) {  // 0xA49B7B
  Crocomire_9BB3();
}

void Crocomire_Func_90(void) {  // 0xA49B7D
  Enemy_Crocomire *E = Get_Crocomire(0);
  if (!sign16(E->base.current_instruction + 0x1E3A))
    Crocomire_9BB3();
}

void Crocomire_9B86(void) {  // 0xA49B86
  QueueMusic_Delayed8(kMusic_Song1);
  camera_distance_index = 0;
  *(uint16 *)&boss_bits_for_area[area_index] |= kBossBit_AreaMiniBoss;
  QueueMusic_Delayed8(kMusic_Song1);
  Crocomire_Func_87(0, 0xFFF0);
  Crocomire_Func_87(0, 0x10);
  Crocomire_9BB3();
}

void Crocomire_9BB3(void) {  // 0xA49BB3
  Enemy_Crocomire *E = Get_Crocomire(0);
  ++E->crocom_var_A;
  ++E->crocom_var_A;
}

void Crocomire_Func_91(void) {  // 0xA49BBA
  Crocomire_9BB3();
}

void Crocomire_Func_92(void) {  // 0xA4B93D
  NormalEnemyTouchAi();
  Enemy_Crocomire *E = Get_Crocomire(0);
  E->crocom_var_B |= 0x4000;
  extra_samus_x_displacement = -4;
}

void Crocomire_Func_93(void) {  // 0xA4B951
  Enemy_Crocomire *E = Get_Crocomire(0);
  uint16 v1 = E->crocom_var_B & 0xF;
  if (sign16(v1 - 15))
    ++v1;
  E->crocom_var_B |= v1;
}

void Crocomire_Func_94(void) {  // 0xA4B968
  int v0 = collision_detection_index;
  eproj_spawn_pt = (Point16U){ projectile_x_pos[v0], projectile_y_pos[v0] };
  uint16 v1 = ((projectile_type[v0] & kProjectileType_SuperMissile) == 0) ? 6 : 29;
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, v1);
}

void Crocomire_Powerbomb(void) {  // 0xA4B992
  uint16 v2;

  Enemy_Crocomire *E = Get_Crocomire(0);
  if (!E->crocom_var_A) {
    if (g_word_A4869E) {
      E->crocom_var_D = g_word_A4869E;
      if (E->crocom_var_C != 24) {
        E->crocom_var_B = E->crocom_var_B & 0x3FF0 | 0x8000;
        E->crocom_var_E = 10;
        E->base.flash_timer += 4;
        E->base.ai_handler_bits |= 2;
        E->crocom_var_C = 24;
        uint16 spritemap_pointer = E->base.spritemap_pointer;
        uint16 v3;
        int n = *(uint16 *)RomPtr_A4(spritemap_pointer);
        while (1) {
          v2 = *((uint16 *)RomPtr_A4(spritemap_pointer) + 3);
          v3 = addr_kCrocomire_Ilist_BDAE;
          if (v2 == addr_kCrocomire_BigSprmap_D600)
            break;
          v3 = addr_kCrocomire_Ilist_BDB2;
          if (v2 == addr_kCrocomire_BigSprmap_D51C)
            break;
          spritemap_pointer += 8;
          if (!--n) {
            v3 = addr_kCrocomire_Ilist_BDB6;
            break;
          }
        }
        Enemy_Crocomire *E0 = Get_Crocomire(0);
        E0->base.current_instruction = v3;
        E0->base.instruction_timer = 1;
      }
    }
  }
}

void Crocomire_Func_95(void) {  // 0xA4BA05
  int16 v3;

  Enemy_Crocomire *E = Get_Crocomire(0);
  E->base.invincibility_timer = 0;
  if ((int16)(E->base.x_pos - E->base.x_width - 256 - layer1_x_pos) >= 0)
    goto LABEL_10;
  uint16 v1, v2;
  v1 = projectile_type[collision_detection_index];
  if ((v1 & kProjectileType_TypeMask) != 0) {
    v3 = v1 & kProjectileType_TypeMask;
    v2 = g_word_A4869A;
    if (v3 != kProjectileType_Missile) {
      v2 = g_word_A4869C;
      if (v3 != kProjectileType_SuperMissile)
        v2 = 0;
    }
  } else {
    v2 = g_word_A48698;
    if ((v1 & kProjectileType_Charged) == 0) {
      E->base.instruction_timer = g_word_A486A0;
      Crocomire_Func_1();
      return;
    }
  }
  if (v2) {
    E->crocom_var_D += v2;
LABEL_10:;
    uint16 v4 = E->crocom_var_B & 0xF;
    if (sign16(v4 - 15))
      ++v4;
    if ((E->crocom_var_B & 0x800) == 0) {
      uint16 v5 = g_word_A48692;
      if (E->crocom_var_C == 8)
        v5 = g_word_A48694;
      E->base.instruction_timer += v5;
    }
    E->crocom_var_B = v4 | E->crocom_var_B & 0xB7F0 | 0x800;
    E->crocom_var_E = 10;
  }
  E->base.flash_timer += 14;
  E->base.ai_handler_bits |= 2;
}

void Crocomire_Func_1(void) {  // 0xA4BAB4
  int v0 = collision_detection_index;
  eproj_spawn_pt = (Point16U){ projectile_x_pos[v0], projectile_y_pos[v0] };
  uint16 v1 = ((projectile_type[v0] & kProjectileType_SuperMissile) == 0) ? 6 : 29;
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, v1);
}

void CrocomireTongue_Init(void) {  // 0xA4F67A
  Enemy_Crocomire *E = Get_Crocomire(cur_enemy_index);
  if ((*(uint16 *)&boss_bits_for_area[area_index] & kBossBit_AreaMiniBoss) != 0) {
    E->base.properties = E->base.properties & 0xDCFF | 0x300;
  } else {
    E->base.current_instruction = addr_kCrocomire_Ilist_BE56;
    E->base.extra_properties |= 0x404;
    E->base.instruction_timer = 1;
    E->crocom_var_A = 23;
    E->base.palette_index = 3584;
  }
}

void CrocomireTongue_Main(void) {  // 0xA4F6BB
  ;
}
