// SPDX-License-Identifier: AGPL-3.0-or-later
#include "../rcat/rcat.h"

extern s32 D_pspeu_0927B978;
extern u16 g_EInitParticle;

void EntitySpikesDust(Entity* self) {
    s16 angle;

    if (!self->step) {
        InitializeEntity(&g_EInitParticle);
        self->zPriority = 160;
        self->animSet = 8;
        self->animCurFrame = 1;
        self->palette = PAL_FLAG(PAL_SPIKES_DUST);
        angle = GetAngleBetweenEntitiesShifted(self, &PLAYER);
        SetEntityVelocityFromAngle(angle, 40);
        return;
    }
    MoveEntity();
    if (AnimateEntity(&D_pspeu_0927B978, self) == 0) {
        DestroyEntity(self);
    }
}
INCLUDE_ASM("st/rcat_psp/nonmatchings/rcat_psp/e_spikes", EntitySpikesParts);

INCLUDE_ASM("st/rcat_psp/nonmatchings/rcat_psp/e_spikes", SpikesBreak);

INCLUDE_ASM("st/rcat_psp/nonmatchings/rcat_psp/e_spikes", SpikesApplyDamage);

INCLUDE_ASM("st/rcat_psp/nonmatchings/rcat_psp/e_spikes", EntitySpikes);

INCLUDE_ASM("st/rcat_psp/nonmatchings/rcat_psp/e_spikes", EntitySpikesDamage);
