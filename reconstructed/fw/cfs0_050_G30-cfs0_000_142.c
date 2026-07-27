/* Ghidra decompilation of cfs0_050_G30-cfs0_000_142.bin */


undefined4 FUN_000001e4(uint *param_1,int param_2,uint **param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_2 != 100) {
    if (param_2 != 0x78) {
      if (param_2 == 99) {
        puVar3 = param_1 + 9;
        *(byte *)puVar3 = *(byte *)param_3;
        *(byte *)((int)param_1 + 0x25) = 0;
        uVar5 = 1;
      }
      else {
        if (param_2 != 0x73) {
          return 0;
        }
        puVar3 = *param_3;
        uVar5 = 0xffffffff;
      }
      if (param_1[5] == 0) {
        FUN_00023336(param_1,puVar3,uVar5);
      }
      return 1;
    }
    puVar3 = *param_3;
    if ((int)((uint)*(ushort *)param_1 << 0x14) < 0) {
      iVar4 = DAT_00023454 + 0x2341a;
    }
    else {
      iVar4 = DAT_00023454 + 0x2342e;
    }
    iVar2 = 0;
    for (; puVar3 != (uint *)0x0; puVar3 = (uint *)((uint)puVar3 >> 4)) {
      *(byte *)((int)param_1 + iVar2 + 0x24) = *(byte *)(iVar4 + ((uint)puVar3 & 0xf));
      iVar2 = iVar2 + 1;
    }
    iVar6 = 0;
    if (((int)((uint)*(byte *)param_1 << 0x1c) < 0) && (iVar2 != 0)) {
      iVar6 = 2;
      iVar4 = iVar4 + 0x11;
    }
    goto LAB_00023aba;
  }
  iVar6 = 0;
  puVar3 = *param_3;
  iVar4 = 0x233f0;
  if ((int)puVar3 < 0) {
    puVar3 = (uint *)-(int)puVar3;
    iVar4 = 0x233f4;
LAB_000233b8:
    iVar6 = 1;
  }
  else {
    if ((int)(*param_1 << 0x1e) < 0) {
      iVar4 = 0x233f8;
      goto LAB_000233b8;
    }
    if ((int)(*param_1 << 0x1d) < 0) {
      iVar4 = 0x233fc;
      goto LAB_000233b8;
    }
  }
  iVar2 = 0;
  for (; puVar3 != (uint *)0x0; puVar3 = (uint *)((uint)puVar3 / 10)) {
    *(byte *)((int)param_1 + iVar2 + 0x24) = (char)puVar3 + (char)((uint)puVar3 / 10) * -10 + 0x30;
    iVar2 = iVar2 + 1;
  }
LAB_00023aba:
  if ((int)(*param_1 << 0x1a) < 0) {
    uVar1 = param_1[7];
    *param_1 = *param_1 & 0xffffffef;
  }
  else {
    uVar1 = 1;
  }
  if (iVar2 < (int)uVar1) {
    iVar8 = uVar1 - iVar2;
  }
  else {
    iVar8 = 0;
  }
  param_1[6] = param_1[6] - (iVar8 + iVar2 + iVar6);
  if (-1 < (int)((uint)*(byte *)param_1 << 0x1b)) {
    FUN_000232e8(param_1);
  }
  for (iVar7 = 0; iVar7 < iVar6; iVar7 = iVar7 + 1) {
    (*(code *)param_1[1])(*(undefined *)(iVar4 + iVar7),param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  if ((int)((uint)*(byte *)param_1 << 0x1b) < 0) {
    FUN_000232e8(param_1);
  }
  while (0 < iVar8) {
    (*(code *)param_1[1])(0x30,param_1[2]);
    param_1[8] = param_1[8] + 1;
    iVar8 = iVar8 + -1;
  }
  while (0 < iVar2) {
    (*(code *)param_1[1])(*(byte *)((int)param_1 + iVar2 + 0x23),param_1[2]);
    param_1[8] = param_1[8] + 1;
    iVar2 = iVar2 + -1;
  }
  FUN_00023314(param_1);
  if ((int)((uint)*(byte *)param_1 << 0x18) < 0) {
    uVar5 = 2;
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}




void FUN_0000024c(void)

{
  FUN_00023f5a();
  return;
}




uint FUN_00000274(void)

{
  int **ppiVar1;
  uint uVar2;
  uint *puVar3;
  int **ppiVar4;
  int **ppiVar5;
  
  ppiVar1 = DAT_000002a4;
  puVar3 = (uint *)DAT_000002a4[1];
  ppiVar5 = (int **)(*DAT_000002a4 + 1);
  uVar2 = *puVar3 + **DAT_000002a4;
  ppiVar4 = (int **)(puVar3 + 1);
  *puVar3 = uVar2;
  if (ppiVar1 <= ppiVar5) {
    ppiVar5 = ppiVar1 + -0x37;
  }
  if (ppiVar1 <= ppiVar4) {
    ppiVar4 = ppiVar1 + -0x37;
  }
  *ppiVar1 = (int *)ppiVar5;
  ppiVar1[1] = (int *)ppiVar4;
  return uVar2 & 0x7fffffff;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000002a8(void)

{
  undefined *puVar1;
  undefined uVar2;
  int iVar3;
  
  FUN_00015b9c(0x3a,3);
  FUN_00015b9c(0x3b,3);
  iVar3 = FUN_00015bec(0x3a);
  puVar1 = _DAT_00000454;
  if ((iVar3 == 0) && (iVar3 = FUN_00015bec(0x3b), iVar3 == 0)) {
    FUN_0001cd4c(0x48c);
    uVar2 = 0;
  }
  else {
    FUN_0001cd4c(0x458);
    uVar2 = 1;
  }
  *puVar1 = uVar2;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined FUN_000002e2(void)

{
  return *_DAT_00000454;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000002e8(void)

{
  undefined uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  FUN_00000d62();
  FUN_0000eb92();
  FUN_0000d302();
  FUN_00009fe8();
  iVar3 = FUN_00009de8();
  if (iVar3 != 0) {
    *(undefined *)(_DAT_000004bc + 1) = 1;
  }
  FUN_0001cd4c(0x4c0);
  FUN_000002a8();
  if (*_DAT_00000454 == '\0') {
    FUN_00008d78();
  }
  else {
    FUN_00011296();
  }
  FUN_00007eda();
  uVar2 = _DAT_000004cc;
  FUN_00023966(_DAT_000004cc,0x13);
  FUN_00007cc6(0,uVar2,0x13);
  FUN_0001cd4c(0x4d0,uVar2);
  FUN_0001e48a(DAT_000004f8,0x4ec,DAT_000004e8,0,DAT_000004e4,0x200,0xb,10);
  FUN_0001e54c(DAT_000004f8);
  FUN_0001e48a(DAT_000004f8 + 0x8c,0x504,DAT_00000500,0,DAT_000004fc,0x1000,8,10);
  FUN_0001e54c(DAT_000004f8 + 0x8c);
  FUN_0001e48a(DAT_0000051c,0x514,DAT_00000510,0,DAT_0000050c,0xc00,8,10);
  FUN_0001e54c(DAT_0000051c);
  FUN_0001e48a(DAT_00000520 + 0xa00,0x528,DAT_00000524,0,DAT_00000520,0x400,0xb,10);
  FUN_0001e54c(DAT_0000051c + -0x8c);
  FUN_0001e48a(DAT_0000052c + 0x718,0x534,DAT_00000530,0,DAT_0000052c,0x200,0xb,10);
  FUN_0001e54c(DAT_000004f8 + -0x8c);
  FUN_0001e48a(_DAT_0000054c,0x540,DAT_0000053c,0,DAT_00000538,0x400,0xc,10);
  FUN_0001e54c(_DAT_0000054c);
  puVar4 = (undefined *)FUN_0000ea5a(6);
  uVar1 = *puVar4;
  FUN_0001cd4c(0x550,uVar1);
  FUN_000064ce(uVar1);
  FUN_000021ae();
  do {
    FUN_0001eb00(1000);
  } while( true );
}




void FUN_000005b0(void)

{
  FUN_0001cd4c(0x974,1,4,2,0x968,0x95c);
  return;
}




void FUN_000005c8(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_00000994;
  *DAT_00000994 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[6] = 0;
  return;
}




void FUN_000005ea(undefined4 param_1,int param_2)

{
  FUN_0000df64();
  if (param_2 == 1) {
    FUN_0000a07e();
    return;
  }
  if (param_2 == 0) {
    FUN_0000a052(param_1);
    return;
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00000610(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int iVar8;
  
  FUN_0001cd4c(0x998);
  FUN_0001cd4c(0x9ac,param_1);
  FUN_0001cd4c(0x9d0);
  iVar2 = FUN_0000dfa8();
  iVar3 = FUN_0000dfb0();
  iVar1 = _DAT_00000948;
  *(undefined *)(_DAT_00000948 + -0x16) = 1;
  FUN_0000df64();
  pcVar7 = DAT_000009dc;
  if (iVar2 != 0) {
    pcVar7 = DAT_000009d8;
  }
  (*pcVar7)(0xff);
  FUN_0001eb00(0x3c);
  uVar4 = FUN_00012db4();
  iVar5 = FUN_0000dfb8();
  iVar8 = 0xff;
  if (iVar5 == 0xff) {
    iVar2 = FUN_0000dfa8();
    iVar3 = FUN_0000dfb0();
    FUN_0001cd4c(0x998);
    if (iVar2 == 0) {
      uVar6 = 0x9e4;
    }
    else {
      uVar6 = 0x9e0;
    }
    FUN_0001cd4c(0x9e8,uVar6,iVar3);
    FUN_0001cd4c(0x9d0);
    iVar8 = iVar3;
  }
  FUN_00012dbc(uVar4);
  FUN_0000df64();
  FUN_0001cd4c(0x998);
  FUN_0001cd4c(0xa10);
  FUN_0001cd4c(0x9d0);
  FUN_0000a02a(param_1,iVar2 != 0);
  uVar4 = FUN_00012db4();
  iVar5 = FUN_0000dfb8();
  if (iVar5 != iVar8) {
    iVar2 = FUN_0000dfa8();
    iVar3 = FUN_0000dfb0();
    FUN_0001cd4c(0x998);
    if (iVar2 == 0) {
      uVar6 = 0x9e4;
    }
    else {
      uVar6 = 0x9e0;
    }
    FUN_0001cd4c(0xa30,uVar6,iVar3);
    FUN_0001cd4c(0x9d0);
  }
  FUN_00012dbc(uVar4);
  pcVar7 = DAT_000009d8;
  if (iVar2 != 0) {
    pcVar7 = DAT_000009dc;
  }
  (*pcVar7)(iVar3);
  *(undefined *)(iVar1 + -0x16) = 0;
  return;
}




byte FUN_00000708(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  do {
    iVar1 = FUN_0000b5a0(bVar2);
    if (iVar1 == 0) {
      return bVar2;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 4);
  return 4;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00000726(byte *param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  FUN_0001cd4c(0xa54);
  FUN_0001cd4c(0xa7c);
  if ((*param_1 & 1) == 0) {
    uVar2 = 0xa94;
  }
  else {
    uVar2 = 0xa8c;
  }
  FUN_0001cd4c(0xa9c,uVar2);
  if ((int)((uint)*param_1 << 0x1e) < 0) {
    uVar2 = 0xa8c;
  }
  else {
    uVar2 = 0xa94;
  }
  FUN_0001cd4c(0xaa8,uVar2);
  if ((int)((uint)*param_1 << 0x1d) < 0) {
    uVar2 = 0xa8c;
  }
  else {
    uVar2 = 0xa94;
  }
  FUN_0001cd4c(0xab4,uVar2);
  if ((int)((uint)*param_1 << 0x1c) < 0) {
    uVar2 = 0xa8c;
  }
  else {
    uVar2 = 0xa94;
  }
  FUN_0001cd4c(0xac0,uVar2);
  if ((int)((uint)*param_1 << 0x1b) < 0) {
    uVar2 = 0xa8c;
  }
  else {
    uVar2 = 0xa94;
  }
  FUN_0001cd4c(0xacc,uVar2);
  FUN_0001cd4c(0xad4,param_1[4]);
  fVar1 = _DAT_00000ae0;
  FUN_0001cd4c(0xae4,(int)*(float *)(param_1 + 8),
               (int)(*(float *)(param_1 + 8) * _DAT_00000ae0) % 100);
  FUN_0001cd4c(0xb04,(int)*(float *)(param_1 + 0x10),(int)(*(float *)(param_1 + 0x10) * fVar1) % 100
              );
  FUN_0001cd4c(0xb24,(int)*(float *)(param_1 + 0x14),(int)(*(float *)(param_1 + 0x14) * fVar1) % 100
              );
  FUN_0001cd4c(0xb48,param_1[0x18]);
  FUN_0001cd4c(0xb60,(int)*(short *)(param_1 + 0x1a));
  if (param_1[0x1c] == 0) {
    uVar2 = 0x9e0;
  }
  else {
    uVar2 = 0x9e4;
  }
  FUN_0001cd4c(0xb78,uVar2);
  FUN_0001cd4c(0xb88,(int)*(float *)(param_1 + 0x20),(int)(*(float *)(param_1 + 0x20) * fVar1) % 100
              );
  FUN_0001cd4c(0xba8,(int)*(float *)(param_1 + 0x24),(int)(*(float *)(param_1 + 0x24) * fVar1) % 100
              );
  FUN_0001cd4c(0xbc4,param_1[0x28]);
  if (param_1[0x29] == 0) {
    uVar2 = 0x9e4;
  }
  else {
    uVar2 = 0x9e0;
  }
  FUN_0001cd4c(0xbd8,uVar2);
  FUN_0001cd4c(0x958);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000008aa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  undefined4 extraout_r1;
  int iVar10;
  bool bVar11;
  undefined8 uVar12;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  uVar4 = FUN_0000df76();
  iVar10 = 3;
  do {
    uVar5 = FUN_0000d09e((int)(char)iVar10);
    iVar3 = DAT_00000994;
    iVar2 = _DAT_00000948;
    uVar5 = uVar5 | uVar4 << 1;
    uVar4 = uVar5 & 0xff;
    iVar10 = iVar10 + -1;
  } while (-1 < iVar10);
  uVar1 = (undefined)uVar5;
  *(undefined *)(DAT_00000994 + 4) = uVar1;
  local_30 = param_3;
  uStack_2c = param_4;
  if (uVar4 == 0) {
    *(undefined4 *)(iVar2 + -4) = 0;
  }
  else {
    iVar10 = *(int *)(iVar2 + -4) + 1;
    *(int *)(iVar2 + -4) = iVar10;
    *(undefined *)(iVar3 + 5) = uVar1;
    uVar4 = iVar10 * 100;
    bVar11 = *(char *)(iVar2 + -0x18) == '\0';
    do {
      if ((bVar11) || (uVar4 < 0x3e9)) goto LAB_00000c60;
      bVar11 = *(char *)(iVar3 + -0x132) == '\x02';
    } while (bVar11);
    FUN_0001cd4c(0x998);
    FUN_0001cd4c(0xbe4,uVar4);
    FUN_0001cd4c(0x9d0);
    if (*(char *)(iVar2 + -0x17) == '\0') {
      FUN_0001cd4c(0x998);
      FUN_0001cd4c(0xc04);
      FUN_0001cd4c(0x9d0);
      *(undefined *)(iVar2 + -0x17) = 1;
      iVar10 = FUN_0000df76();
      if (iVar10 != 0) {
        FUN_0001cd4c(0x998);
        FUN_0001cd4c(0xff8);
        FUN_0001cd4c(0x9d0);
        uVar5 = FUN_00000708();
        if (uVar5 < 4) {
          FUN_0001cd4c(0x998);
          FUN_0001cd4c(0xc04);
          FUN_0001cd4c(0x9d0);
          *(undefined *)(iVar2 + -0x17) = 1;
          iVar10 = FUN_0000a0b4(uVar5);
          if (iVar10 != 0) {
            FUN_00000610(uVar5);
          }
        }
      }
      FUN_0001ee68(DAT_0000100c);
    }
LAB_00000c60:
    if (10000 < uVar4) {
      *(undefined *)(iVar3 + 3) = uVar1;
      uStack_2c = FUN_0000d09e(3);
      local_30 = FUN_0000d09e(2);
      uVar6 = FUN_0000d09e(1);
      uVar7 = FUN_0000d09e(0);
      uVar8 = FUN_0000df76();
      FUN_0001cd4c(DAT_00001010,uVar8,uVar7,uVar6);
      puVar9 = (undefined *)(DAT_0000100c + 0x2c);
      *puVar9 = uVar1;
      FUN_00007d82(0x80,puVar9,0x2c);
      FUN_00000726(DAT_0000100c + 0x2c);
      FUN_000005ea(0,1);
    }
  }
  iVar10 = FUN_0000df8e();
  if (iVar10 == 0) {
    return;
  }
  if (*(char *)(iVar2 + -0x18) == '\0') {
    *(undefined *)(iVar3 + 6) = 1;
    FUN_0001cd4c(0x998);
    FUN_0001cd4c(s_MS3791_is_overload_00001028);
    FUN_0001cd4c(0x9d0);
  }
  else {
    FUN_0001cd4c(0x998);
    FUN_0001cd4c(s_MS3791_is_overload_00001014);
    FUN_0001cd4c(0x9d0);
    if (*(char *)(iVar2 + -0x17) == '\0') {
      uVar12 = FUN_00000708();
      uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
      uVar4 = (uint)uVar12;
      if (uVar4 < 4) {
        FUN_0001cd4c(0x998);
        FUN_0001cd4c(0xc04);
        FUN_0001cd4c(0x9d0);
        *(undefined *)(iVar2 + -0x17) = 1;
        uVar12 = FUN_0000a0b4(uVar4);
        uVar6 = (undefined4)((ulonglong)uVar12 >> 0x20);
        if ((int)uVar12 != 0) {
          FUN_00000610(uVar4);
          FUN_0000df96();
          uVar6 = extraout_r1;
        }
      }
      FUN_0001ee68(DAT_0000100c,uVar6,local_30,uStack_2c);
      return;
    }
    *(undefined *)(iVar3 + 6) = 1;
  }
  uVar12 = FUN_000005ea(0,1);
  FUN_0000df96((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),local_30,uStack_2c);
  return;
}




void FUN_00000d62(void)

{
  uint uVar1;
  undefined uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = DAT_0000100c;
  iVar5 = DAT_0000100c + 0x84;
  *(undefined *)(DAT_0000100c + 0x97) = 0xff;
  *(undefined *)(iVar3 + 0x98) = 100;
  *(undefined *)(iVar3 + 0x99) = 200;
  *(undefined *)(iVar3 + 0x9b) = 0x9b;
  *(undefined *)(iVar3 + 0x9a) = 0x96;
  *(undefined *)(iVar3 + 0x9c) = 0xff;
  *(undefined *)(iVar3 + 0x9d) = 0x50;
  uVar2 = 0;
  *(undefined *)(iVar3 + 0x89) = 0;
  *(undefined *)(iVar3 + 0x86) = 0;
  *(undefined *)(iVar3 + 0x8a) = 0;
  *(undefined *)(iVar3 + 0x8b) = 0;
  *(undefined *)(iVar3 + 0x8c) = 0;
  FUN_000005c8();
  *(undefined *)(iVar3 + 0x1c2) = uVar2;
  FUN_000005b0();
  iVar3 = DAT_0000103c;
  uVar6 = 0;
  do {
    uVar2 = FUN_0000b590(uVar6 & 0xff);
    iVar7 = iVar5 + uVar6;
    *(undefined *)(iVar7 + 9) = uVar2;
    uVar2 = FUN_0000b5a0(uVar6 & 0xff);
    *(undefined *)(iVar7 + 0xd) = uVar2;
    uVar1 = uVar6 & 0xff;
    uVar6 = uVar6 + 1;
    *(byte *)(iVar3 + 3) = (byte)(1 - (uint)*(byte *)(iVar7 + 9) << uVar1) | *(byte *)(iVar3 + 3);
  } while ((int)uVar6 < 4);
  iVar3 = FUN_0001de70(DAT_0000100c + 0x58);
  if (iVar3 == 10) {
    FUN_0001ed48(DAT_0000100c + 0x58);
  }
  uVar4 = FUN_0001a20e(100);
  FUN_0001ecec(DAT_0000100c + 0x58,s_motor_blocked_detect_timer_00001044,DAT_00001040,0,uVar4,6);
  FUN_0001ee68(DAT_0000100c + 0x58);
  iVar3 = FUN_0001de70(DAT_0000100c);
  if (iVar3 == 10) {
    FUN_0001ed48(DAT_0000100c);
  }
  uVar4 = FUN_0001a20e(&DAT_00002b5c);
  FUN_0001ecec(DAT_0000100c,s_feeder_reverse_detooth_reenable__00001064,DAT_00001060,0,uVar4,4);
  return;
}




void FUN_00000e2c(void)

{
  int iVar1;
  
  iVar1 = DAT_0000100c;
  *(undefined *)(DAT_0000100c + 0x87) = 0;
  *(undefined *)(iVar1 + 0x86) = 0;
  FUN_0000da2c();
  return;
}




void FUN_00000e3a(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0000100c;
  if ((param_1 != 1) && (param_1 != 3)) {
    *(char *)(DAT_0000100c + 0x87) = (char)param_1;
    *(undefined *)(iVar1 + 0x86) = 4;
    FUN_0000da56(*DAT_0000108c,param_1);
    return;
  }
  *DAT_00001094 = *DAT_00001090;
  return;
}




void FUN_00000e60(int param_1)

{
  if (param_1 != 0) {
    FUN_00000e3a();
    return;
  }
  FUN_00000e2c();
  return;
}




char FUN_00000e66(uint param_1)

{
  char cVar1;
  
  if (param_1 < 3) {
    cVar1 = (char)param_1 + '\x01';
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00000e74(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  uVar3 = 0;
  FUN_0000df30(*(undefined *)(*(int *)(DAT_0000103c + 0x10) + 3));
  fVar5 = (float)FUN_0000840a();
  FUN_0000da56(*DAT_0000108c,0);
  iVar2 = _DAT_0000109c;
  iVar1 = DAT_00001098;
  uVar4 = 0;
  fVar7 = fVar5;
  do {
    FUN_0001eb00(0x14);
    fVar6 = (float)FUN_0000840a();
    if (iVar1 < (int)(fVar5 - fVar6)) {
      FUN_0000df64();
      return 0xb;
    }
    if ((int)(fVar7 - fVar6) < iVar2) {
      uVar3 = uVar3 + 1;
      if (0x18 < uVar3) break;
    }
    else {
      uVar3 = 0;
    }
    uVar4 = uVar4 + 1;
    fVar7 = fVar6;
  } while (uVar4 < 0x4e2);
  FUN_0001cd4c(s__<feeding_stop,_odometer_not_cha_0000109e + 2);
  FUN_0000df64();
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00000efa(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  byte bVar5;
  bool bVar6;
  float fVar7;
  float fVar8;
  
  bVar5 = 0;
  FUN_0000da56(*DAT_0000108c,0);
  fVar7 = (float)FUN_0000840a();
  iVar2 = _DAT_000010c4;
  iVar1 = DAT_0000103c;
  if (param_1 == 1) {
    do {
      FUN_0001cd4c(s_Retry_attempt___d_000010f0,bVar5);
      FUN_0000df4a(*(undefined *)(*(int *)(iVar1 + 0x10) + 7));
      FUN_0001eb00(500);
      FUN_0000df30(*(undefined *)(*(int *)(iVar1 + 0x10) + 2));
      cVar4 = '\x02';
      do {
        FUN_0001cd4c(s__Judge_attempt___d_000010c7 + 1,cVar4);
        FUN_0001eb00(1000);
        fVar8 = (float)FUN_0000840a();
        if (iVar2 <= (int)(fVar7 - fVar8)) break;
        bVar6 = cVar4 != '\0';
        cVar4 = cVar4 + -1;
      } while (bVar6);
      if (cVar4 != '\0') {
        FUN_0001cd4c(s_sec_remaining___d_000010dc,cVar4);
        break;
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < 3);
    if (bVar5 == 3) goto LAB_00000fcc;
  }
  else {
    FUN_0000df30(*(undefined *)(*(int *)(DAT_0000103c + 0x10) + 2));
    cVar4 = '\x02';
    do {
      FUN_0001cd4c(s__Judge_attempt___d_000010c7 + 1,cVar4);
      FUN_0001eb00(1000);
      fVar8 = (float)FUN_0000840a();
      if (iVar2 <= (int)(fVar7 - fVar8)) break;
      bVar6 = cVar4 != '\0';
      cVar4 = cVar4 + -1;
    } while (bVar6);
    if (cVar4 == '\0') {
LAB_00000fcc:
      FUN_0000df64();
      return 10;
    }
    FUN_0001cd4c(s_sec_remaining___d_000010dc,cVar4);
  }
  uVar3 = FUN_00000e74();
  return uVar3;
}




char FUN_00000fec(void)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_0000103c + 2);
  if (cVar1 != '\x01') {
    cVar1 = '\0';
  }
  return cVar1;
}




void FUN_00001104(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_0000df30(*(undefined *)(*(int *)(DAT_00001500 + 0x10) + 3));
  FUN_0000df86(1);
  uVar1 = 0xc80;
  while( true ) {
    FUN_0001eb00(uVar1);
    iVar2 = FUN_00000fec();
    if (iVar2 == 0) break;
    uVar1 = 10;
  }
  FUN_0000df96();
  FUN_0000df86(0);
  FUN_0000df64();
  return;
}




undefined4 FUN_00001144(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined *)(DAT_00001504 + 3) = 0;
  FUN_00009ffc(param_1,0,param_2);
  FUN_0000df30(param_3);
  return 0;
}




undefined4 FUN_00001160(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined *)(DAT_00001504 + 3) = 0;
  FUN_0000a02a(param_1,1);
  FUN_0000df4a(param_2);
  FUN_0001eb00(200);
  FUN_00009ffc(param_1,1,param_3);
  return 0;
}




undefined4 FUN_00001190(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  
  bVar4 = 0;
  bVar3 = 0;
  fVar5 = (float)FUN_0000840a();
  fVar1 = DAT_00001508;
  iVar6 = (int)(fVar5 * DAT_00001508);
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  FUN_0001cd4c(s__s__last_odom____d__02dmm_00001510,DAT_0000150c,(int)fVar5,iVar6 % 100);
  fVar2 = DAT_0000152c;
  if (param_2 == 1) {
    do {
      bVar4 = 0;
      do {
        fVar7 = (float)FUN_0000840a();
        fVar7 = fVar7 - fVar5;
        if ((uint)fVar2 <= (uint)fVar7) {
          if (bVar4 < 200) goto LAB_0000123c;
          break;
        }
        FUN_0001eb00(0x14);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 200);
      iVar6 = DAT_00001500;
      FUN_00001160(param_1,*(undefined *)(*(int *)(DAT_00001500 + 0x10) + 7),
                   *(undefined *)(*(int *)(DAT_00001500 + 0x10) + 6));
      FUN_0001eb00(200);
      FUN_00001144(param_1,*(undefined *)(*(int *)(iVar6 + 0x10) + 1),
                   *(undefined *)(*(int *)(iVar6 + 0x10) + 2));
      fVar5 = (float)FUN_0000840a();
      bVar3 = bVar3 + 1;
    } while (bVar3 < 3);
LAB_0000123c:
    if (bVar3 != 3) {
LAB_0000129c:
      FUN_000005ea(param_1,0);
      return 0;
    }
  }
  else {
    do {
      fVar7 = (float)FUN_0000840a();
      fVar7 = fVar7 - fVar5;
      if ((uint)fVar2 <= (uint)fVar7) break;
      FUN_0001eb00(0x14);
      bVar4 = bVar4 + 1;
    } while (bVar4 < 100);
    if (bVar4 != 100) goto LAB_0000129c;
  }
  FUN_000005ea(param_1,1);
  iVar6 = (int)(fVar7 * fVar1);
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  FUN_0001cd4c(s__s__odom___last_odom____d__02dmm_00001530,DAT_0000150c,(int)fVar7,iVar6 % 100);
  return 9;
}




int FUN_000012a8(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  
  iVar1 = DAT_00001500;
  bVar3 = 0;
  FUN_00001144(param_1,*(undefined *)(*(int *)(DAT_00001500 + 0x10) + 1),
               *(undefined *)(*(int *)(DAT_00001500 + 0x10) + 5));
  if (param_2 == 1) {
    do {
      iVar2 = FUN_0000b65e(param_1,300,0,10);
      if (iVar2 == 0) break;
      FUN_00009ffc(param_1,1,*(undefined *)(*(int *)(iVar1 + 0x10) + 6));
      FUN_0001eb00(0x32);
      FUN_00009ffc(param_1,0,*(undefined *)(*(int *)(iVar1 + 0x10) + 1));
      bVar3 = bVar3 + 1;
    } while (bVar3 < 3);
    if (bVar3 != 3) {
      return iVar2;
    }
  }
  else {
    iVar1 = FUN_0000b65e(param_1,700,0,10);
    if (iVar1 == 0) {
      return 0;
    }
  }
  FUN_000005ea(param_1,1);
  return 5;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00001326(undefined4 param_1)

{
  int iVar1;
  
  FUN_0001cd4c(s__s___d__00001554,DAT_0000150c + 0x1f,param_1);
  if (*(char *)(_DAT_00001560 + 5) != '\0') {
    FUN_0000da56(param_1,0);
  }
  iVar1 = FUN_000012a8(param_1,0);
  if (iVar1 == 0) {
    iVar1 = FUN_00001190(param_1,0);
  }
  FUN_0001cd4c(s__s___d_end_00001563 + 1,DAT_0000150c + 0x1f,param_1);
  return iVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000136a(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00001500;
  iVar3 = _DAT_00001560 + -0xb4;
  if (param_2 == 1) {
    uVar1 = 0;
    do {
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_00001500 + 8)) && (*(ushort *)(DAT_00001500 + 8) != 0)) {
      uVar1 = 0;
      do {
        *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
    }
    *(short *)(iVar2 + 8) = (short)param_3;
    iVar2 = FUN_0000b590(param_1);
    if (iVar2 == 0) {
      uVar1 = *(int *)(iVar3 + param_1 * 4) + 1;
      *(uint *)(iVar3 + param_1 * 4) = uVar1;
      if (param_3 <= uVar1) {
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
        return 1;
      }
    }
    else {
      *(undefined4 *)(iVar3 + param_1 * 4) = 0;
    }
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000013cc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00001500;
  iVar3 = _DAT_00001560 + -0xa4;
  if (param_2 == 1) {
    uVar1 = 0;
    do {
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_00001500 + 10)) && (*(ushort *)(DAT_00001500 + 10) != 0)) {
      uVar1 = 0;
      do {
        *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
    }
    *(short *)(iVar2 + 10) = (short)param_3;
    iVar2 = FUN_0000b5a0(param_1);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar3 + param_1 * 4) = 0;
    }
    else {
      uVar1 = *(int *)(iVar3 + param_1 * 4) + 1;
      *(uint *)(iVar3 + param_1 * 4) = uVar1;
      if (param_3 <= uVar1) {
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
        return 1;
      }
    }
  }
  return 0;
}




/* WARNING: Removing unreachable block (ram,0x00001edc) */
/* WARNING: Removing unreachable block (ram,0x00001ee4) */
/* WARNING: Removing unreachable block (ram,0x00001ee6) */
/* WARNING: Removing unreachable block (ram,0x00001ee8) */
/* WARNING: Removing unreachable block (ram,0x00001ef4) */
/* WARNING: Removing unreachable block (ram,0x00001f16) */
/* WARNING: Removing unreachable block (ram,0x000020f8) */
/* WARNING: Removing unreachable block (ram,0x00001efe) */

undefined4 FUN_00001432(void)

{
  uint uVar1;
  int iVar2;
  
  FUN_00002100(0,1,10);
  FUN_0000136a(0,1,10);
  FUN_000013cc(0,1,10);
  iVar2 = DAT_00001f1c + -0x94;
  uVar1 = 0;
  do {
    *(undefined4 *)(iVar2 + uVar1 * 4) = 0;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 4);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001460(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
  iVar2 = _DAT_00001560;
  bVar4 = 0;
  if (*(char *)(_DAT_00001560 + 2) == '\0') {
    iVar1 = FUN_000021e0();
    if (iVar1 == 0) {
      *(undefined *)(iVar2 + 2) = 3;
      FUN_00001432();
      do {
        FUN_0001eb00(1);
        iVar2 = FUN_0000136a(param_1,0,5);
        if (iVar2 != 0) break;
        bVar4 = bVar4 + 1;
      } while (bVar4 < 0x1e);
      if (bVar4 != 0x1e) {
        uVar3 = FUN_0000b5b2(param_1);
        return uVar3;
      }
      return 8;
    }
    FUN_0001cd4c(&DAT_00001570);
    FUN_0001cd4c(s_pretension_now__not_allow_feedin_00001590);
  }
  else {
    FUN_0001cd4c(&DAT_00001570);
    FUN_0001cd4c(s_err_status___d_00001580,*(undefined *)(iVar2 + 2));
  }
  FUN_0001cd4c(0x9d0);
  return 3;
}




int FUN_000014ce(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = FUN_00001460();
  if ((iVar2 == 0) && (iVar2 = FUN_00001326(param_1), puVar1 = DAT_00001500, iVar2 == 0)) {
    *DAT_00001500 = 1;
    FUN_00001104(param_1);
    *puVar1 = 0;
  }
  FUN_0001cd4c(&DAT_00001570);
  FUN_0001cd4c(s__s_end_00001998,DAT_0000150c + 0x45);
  FUN_0001cd4c(0x9d0);
  return iVar2;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000015c6(undefined4 param_1,int param_2,float param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 extraout_r1;
  int iVar7;
  int iVar8;
  float local_28;
  undefined4 uStack_24;
  
  local_28 = param_3;
  uStack_24 = param_4;
  FUN_0001cd4c(&DAT_00001570);
  FUN_0001cd4c(s_cmd_feed_process_2_mode___d_000019a0,param_2 + 1);
  FUN_0001cd4c(0x9d0);
  iVar7 = _DAT_000019c8;
  puVar1 = DAT_000019c4;
  iVar8 = DAT_000019c0;
  switch(param_2) {
  case 0:
    uVar4 = FUN_000014ce(param_1);
    FUN_00000e60();
    iVar7 = 1;
    iVar8 = iVar8 + 2;
    goto LAB_00001620;
  case 1:
    *(undefined *)(DAT_000019c0 + 2) = 3;
    uVar5 = FUN_00000e74();
    uVar4 = uVar5;
    break;
  case 2:
    *(undefined *)(DAT_000019c0 + 2) = 3;
    uVar5 = FUN_00000efa(0);
    uVar4 = uVar5;
    break;
  case 3:
    FUN_00000e60(0);
    iVar7 = 0;
    iVar8 = 0;
    uVar4 = 0;
    goto LAB_00001620;
  case 4:
    *(undefined *)(DAT_000019c0 + 2) = 3;
    FUN_0000b8f6(0x10,0,0);
    FUN_0000da56(*puVar1,0);
    uVar2 = FUN_00022926();
    *(undefined *)(iVar7 + 4) = uVar2;
    FUN_00000e60();
    goto LAB_000016d8;
  case 5:
    local_28 = (float)FUN_0000840a();
    uVar3 = 0;
    do {
      puVar1 = (undefined *)((int)&local_28 + uVar3);
      iVar8 = 3 - uVar3;
      uVar3 = uVar3 + 1 & 0xff;
      *(undefined *)((int)&uStack_24 + iVar8) = *puVar1;
    } while (uVar3 < 4);
    FUN_0000b8f6(0x10,*(undefined *)(iVar7 + 4),&uStack_24,4);
    if (*(char *)(iVar7 + 4) != '\0') {
      *(undefined *)(iVar7 + 4) = 0;
    }
    FUN_0001cd4c(&DAT_00001570);
    iVar8 = (int)(local_28 * DAT_00001508);
    if (iVar8 < 0) {
      iVar8 = -iVar8;
    }
    FUN_0001cd4c(s_stage6___d__02dmm_000019cb + 1,(int)local_28,iVar8 % 100);
    pcVar6 = (char *)0x9d0;
    goto LAB_000016d4;
  case 6:
    *(undefined *)(DAT_000019c0 + 2) = 3;
    FUN_0000da56(*puVar1,0);
    uVar5 = FUN_00022a6e();
    uVar4 = uVar5;
    break;
  case 7:
    *(undefined *)(DAT_000019c0 + 2) = 3;
    FUN_0000da56(*puVar1,0);
    uVar4 = FUN_00022ac2(param_3);
    uVar5 = 0;
    break;
  default:
    pcVar6 = s_illegal_data_00001a04;
LAB_000016d4:
    FUN_0001cd4c(pcVar6);
    goto LAB_000016d8;
  }
  FUN_00000e60(uVar5);
  iVar8 = 0;
  iVar7 = iVar8;
LAB_00001620:
  FUN_0000b8f6(0x10,uVar4,iVar8,iVar7);
LAB_000016d8:
  FUN_0001cd4c(&DAT_00001570);
  FUN_0001cd4c(s_cmd_feed_process_2_mode___d_end_000019e0,param_2 + 1);
  FUN_0001cd4c(0x9d0,extraout_r1,local_28,uStack_24);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000172c(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = 0;
  iVar1 = FUN_0000b5a0();
  iVar2 = _DAT_000019c8;
  if (iVar1 == 0) {
LAB_00001762:
    if (param_2 == 1) {
      do {
        iVar1 = FUN_0000b65e(param_1,300,1,10);
        if (iVar1 == 0) break;
        FUN_0001cd4c(s_pull_back_hub_PE_retry__d_00001a4c,uVar5 + 1);
        FUN_00009ffc(param_1,0,*(undefined *)(*(int *)(iVar2 + 0x10) + 1));
        FUN_00001190(param_1,0);
        FUN_00001160(param_1,*(undefined *)(*(int *)(iVar2 + 0x10) + 7),
                     *(undefined *)(*(int *)(iVar2 + 0x10) + 6));
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < 3);
      if (uVar5 != 3) goto LAB_000017de;
      pcVar3 = s_pull_back_hub_PE_timeout__retry_t_00001a68;
    }
    else {
      iVar2 = FUN_0000b65e(param_1,700,1,10);
      if (iVar2 == 0) {
LAB_000017de:
        FUN_0001cd4c(s_already_pull_back_hub_PE_00001a30);
        FUN_0001eb00(300);
        FUN_000005ea(param_1,0);
        goto LAB_000012e4;
      }
      pcVar3 = s_pull_back_hub_PE_timeout_00001a14;
    }
    FUN_0001cd4c(pcVar3);
    FUN_000005ea(param_1,1);
    uVar4 = 0x14;
  }
  else {
    FUN_000005ea(param_1,0);
    iVar1 = FUN_0000b65e(param_1,0x32,1,10);
    if (iVar1 != 0) {
      FUN_00001160(param_1,*(undefined *)(*(int *)(iVar2 + 0x10) + 7),
                   *(undefined *)(*(int *)(iVar2 + 0x10) + 6));
      goto LAB_00001762;
    }
    FUN_0001cd4c(s_already_pull_back_hub_PE_00001a30);
LAB_000012e4:
    uVar4 = 0;
  }
  return uVar4;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000017f6(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  int iVar10;
  float fVar11;
  ulonglong unaff_d8;
  uint local_40;
  
  uVar5 = 0;
  uVar6 = 0;
  uVar8 = 0;
  uVar7 = 0;
  local_40 = 2;
  FUN_00001432();
  iVar10 = _DAT_000019c8;
  FUN_00001160(param_1,*(undefined *)(*(int *)(_DAT_000019c8 + 0x10) + 7),
               *(undefined *)(*(int *)(_DAT_000019c8 + 0x10) + 6));
  iVar2 = DAT_00001a9c;
  fVar1 = DAT_00001508;
  do {
    iVar3 = FUN_000013cc(param_1,0,5);
    if (iVar3 != 0) break;
    fVar9 = (float)FUN_0000840a();
    fVar11 = fVar9 - (float)(unaff_d8 >> 0x20);
    unaff_d8 = (ulonglong)(uint)fVar11;
    if ((int)fVar11 < _DAT_00001aa0) {
      uVar6 = uVar6 + 1;
      if (*(char *)(iVar2 + 3) != '\0') {
        FUN_0001cd4c(0x998);
        FUN_0001cd4c(s__<pull_back_hub_motor_block,_sta_00001aa2 + 2,*(undefined *)(iVar2 + 3));
        FUN_0001cd4c(0x9d0);
        FUN_000005ea(param_1,1);
        return 0x19;
      }
      if ((int)((uint)*(byte *)(iVar2 + 4) << 0x1b) < 0) {
        uVar8 = uVar8 + 1;
        uVar7 = 0;
      }
      else {
        uVar8 = 0;
        uVar7 = uVar7 + 1;
      }
      if (0x95 < uVar6) {
        if (0x95 < uVar7) break;
        if (((0x95 < uVar8) && (param_2 == 1)) && (local_40 != 0)) {
          iVar3 = (int)(fVar11 * fVar1);
          if (iVar3 < 0) {
            iVar3 = -iVar3;
          }
          FUN_0001cd4c(s__s__odom___last_odom____d__02dmm_00001530,DAT_00001acc,(int)fVar11,
                       iVar3 % 100);
          FUN_0001cd4c(s_pull_back_odometer_retry__d_00001ad0,5 - local_40);
          uVar6 = 0;
          local_40 = local_40 - 1 & 0xff;
          uVar8 = 0;
          uVar7 = 0;
          FUN_0000a052(param_1);
          FUN_0000df30(*(undefined *)(*(int *)(iVar10 + 0x10) + 2));
          FUN_0001eb00(0x32);
          FUN_0000df64();
          FUN_0001eb00(200);
          iVar3 = *(int *)(iVar10 + 0x10);
          FUN_00001160(param_1,*(undefined *)(iVar3 + 7),*(undefined *)(iVar3 + 6));
          fVar9 = (float)FUN_0000840a();
        }
      }
    }
    else {
      uVar6 = 0;
    }
    unaff_d8 = CONCAT44(fVar9,fVar11);
    FUN_0001eb00(0x14);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 2000);
  if (uVar5 == 2000) {
    iVar10 = (int)((float)unaff_d8 * fVar1);
    if (iVar10 < 0) {
      iVar10 = -iVar10;
    }
    FUN_0001cd4c(s__s__odom___last_odom____d__02dmm_00001530,DAT_00001acc,(int)(float)unaff_d8,
                 iVar10 % 100);
    FUN_0001cd4c(s_pull_back_odometer_timeout_00001af0);
    FUN_000005ea(param_1,1);
    uVar4 = 0x1a;
  }
  else {
    FUN_0001cd4c(s_already_pull_back_odometer_00001b0c);
    uVar4 = 0;
  }
  return uVar4;
}




int FUN_00001b28(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0000b590();
  if (iVar1 == 0) {
    FUN_0001cd4c(s__s___d__00001554,DAT_00001f18,param_1);
    if (*(char *)(DAT_00001f1c + 5) != '\0') {
      FUN_0000da56(param_1,0);
    }
    iVar1 = FUN_000017f6(param_1,0);
    if (iVar1 == 0) {
      iVar1 = FUN_0000172c(param_1,0);
      return iVar1;
    }
  }
  else {
    iVar1 = 0x17;
  }
  return iVar1;
}




undefined4 FUN_00001b66(undefined4 param_1)

{
  int iVar1;
  
  FUN_0000da56(param_1,0);
  FUN_0000a02a(param_1,1);
  FUN_0000df4a(*(undefined *)(*(int *)(DAT_00001f20 + 0x10) + 7));
  iVar1 = FUN_0000e46c(0,5000);
  FUN_0000df64();
  if (iVar1 != 0) {
    return 0x13;
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00001b9c(uint param_1,int param_2,byte *param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  *param_3 = 0;
  puVar1 = _DAT_00001f24;
  if (param_1 < 4) {
    *param_3 = (byte)(1 << (param_1 & 0xff));
    if (param_2 == 0) {
      iVar2 = FUN_00001b66();
    }
    else if (param_2 == 1) {
      iVar2 = FUN_00001b28();
    }
    else {
LAB_00001bee:
      iVar2 = 1;
      FUN_0001cd4c(s_illegal_data_00001a04);
    }
  }
  else {
    uVar3 = 0;
    do {
      iVar2 = FUN_0000b5a0(uVar3 & 0xff);
      if (iVar2 == 0) {
        *param_3 = *param_3 | (byte)(1 << (uVar3 & 0xff));
        *puVar1 = (char)uVar3;
        if (param_2 == 0) {
          iVar2 = FUN_00001b66();
        }
        else {
          if (param_2 != 1) goto LAB_00001bee;
          iVar2 = FUN_00001b28();
        }
        if (iVar2 != 0) {
          return iVar2;
        }
        FUN_0000da2c();
      }
      iVar2 = 0;
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 4);
  }
  return iVar2;
}




int FUN_00001c16(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00001f1c;
  if ((*(char *)(DAT_00001f1c + 2) == '\0') || (*(char *)(DAT_00001f1c + 2) == '\x01')) {
    iVar2 = FUN_0000b61e(param_1);
    if (iVar2 != 0) {
      FUN_0000da56(param_1,iVar2);
      *(undefined *)(iVar1 + 3) = 0x16;
      *(undefined *)(iVar1 + 2) = 4;
      return 0x16;
    }
  }
  else {
    FUN_0001cd4c(&DAT_00001570);
    FUN_0001cd4c(s_err_status_1___d_00001f27 + 1,*(undefined *)(iVar1 + 2));
    FUN_0001cd4c(DAT_00001f3c);
    iVar2 = 3;
  }
  return iVar2;
}




void FUN_00001c5a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  iVar1 = FUN_00001c16();
  if (iVar1 == 0) {
    *(undefined *)(DAT_00001f1c + 2) = 3;
    iVar1 = FUN_00001b9c(param_1,param_2,&uStack_18);
    FUN_00000e60();
  }
  FUN_0000b8f6(0x11,iVar1,0);
  return;
}




void FUN_00001c8c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00001460();
  if ((iVar1 == 0) && (iVar1 = FUN_00001326(param_1), iVar1 == 0)) {
    iVar1 = FUN_00000e74();
  }
  FUN_00000e60();
  FUN_0000b8f6(0x13,iVar1,0);
  return;
}




int FUN_00001cbc(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_0001cd4c(s_cmd_parse_out__d__00001f40,param_1);
  iVar2 = DAT_00001f20;
  FUN_00009ffc(param_1,0,*(undefined *)(*(int *)(DAT_00001f20 + 0x10) + 1));
  iVar1 = FUN_0000b65e(param_1,1000,0,10);
  FUN_0001cd4c(s_____________________out_ret____d_00001f54,iVar1);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      FUN_0000a07e();
      iVar1 = 0;
    }
    else if (param_2 == 1) {
      iVar1 = FUN_00001190(param_1,0);
      if (iVar1 == 0) {
        FUN_0000df30(*(undefined *)(*(int *)(iVar2 + 0x10) + 2));
        iVar2 = FUN_0000e46c(1,&DAT_00007530);
        if (iVar2 == 0) {
          FUN_0000df64();
          iVar1 = 0;
        }
        else {
          FUN_0000df64();
          FUN_0001cd4c(s_buffer_fill_timeout_00001f78);
          iVar1 = 6;
        }
      }
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    FUN_0000df64();
    FUN_0000a07e();
    iVar1 = 5;
  }
  return iVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00001d4a(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  FUN_0001cd4c(s_forced_preloading__d_00001f90,param_1);
  *(undefined *)(_DAT_00001fa8 + param_1) = 1;
  FUN_0000217c(param_1,param_2);
  FUN_0001eb00(5000);
  iVar2 = 0xb4;
  while ((bVar3 = iVar2 != 0, iVar2 = iVar2 + -1, bVar3 && (iVar1 = FUN_0000216c(), iVar1 != 0))) {
    FUN_0001eb00(1000);
  }
  FUN_00002198();
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00001d90(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined4 uStack_20;
  
  uStack_20 = param_4;
  FUN_0001cd4c(s_forced_preloading__00001fab + 1);
  uVar5 = 0xff;
  iVar2 = FUN_00001c16(4);
  if (iVar2 == 0) {
    if (*(char *)(DAT_00001f1c + 2) == '\x01') {
      iVar2 = 0xb3;
      uVar5 = (uint)*(byte *)(_DAT_00001fc0 + 1);
      do {
        iVar3 = FUN_0000216c();
        if (iVar3 == 0) break;
        FUN_0001eb00(1000);
        bVar6 = iVar2 != 0;
        iVar2 = iVar2 + -1;
      } while (bVar6);
    }
    else if ((*(char *)(DAT_00001f1c + 2) == '\0') &&
            (iVar2 = FUN_00001b9c(4,1,&uStack_20), iVar2 != 0)) {
      return iVar2;
    }
    puVar1 = _DAT_00001f24;
    uVar4 = 0;
    do {
      if ((((1 << uVar4 & param_1) != 0) && (*puVar1 = (char)uVar4, uVar5 != uVar4)) &&
         (iVar2 = FUN_0000b694(uVar4,1), iVar2 != 0)) {
        FUN_00001d4a(*puVar1,param_2);
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 4);
    iVar2 = 0;
  }
  return iVar2;
}




void FUN_00001e1a(int param_1,int param_2)

{
  undefined *puVar1;
  undefined uVar2;
  
  puVar1 = DAT_00001f20;
  if (param_1 != 2) {
    FUN_0001cd4c(s_reverse_detooth_set__en__00001fc3 + 1);
    return;
  }
  FUN_0001cd4c(0x1fe0,*DAT_00001f20);
  uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 4));
  *puVar1 = uVar2;
  FUN_0001cd4c(0x2000);
  return;
}




undefined4 FUN_00001e4a(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined auStack_38 [48];
  
  puVar2 = auStack_38;
  if (param_1 < 2) {
LAB_00001e68:
    FUN_0001cd4c(s_Usage__00002034);
    FUN_0001cd4c(DAT_00002040);
    FUN_0001cd4c(DAT_00002044);
  }
  else {
    iVar1 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_realtime_00002020);
    if (iVar1 == 0) {
      puVar2 = (undefined *)(DAT_00001f1c + -0x58);
    }
    else {
      iVar1 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_eeprom_0000202c);
      if (iVar1 != 0) goto LAB_00001e68;
      FUN_00007cc6(0x80,auStack_38,0x2c);
    }
    FUN_00000726(puVar2);
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001e98(void)

{
  undefined *puVar1;
  
  puVar1 = _DAT_00002048;
  FUN_0001cd4c(s_eeprom_init_flag___d_0000204b + 1,*_DAT_00002048);
  FUN_0001cd4c(s_AHTxx_init_flag___d_00002064,puVar1[1]);
  FUN_0001cd4c(s_odometer_magnetic_init_flag___d_0000207c,puVar1[2]);
  FUN_0001cd4c(s_Buffer_init_flag___d_000020a0,puVar1[3]);
  FUN_0001cd4c(s_rfid_init_flag_0____d__rfid_init_000020b8,puVar1[4],puVar1[5]);
  return 0;
}




undefined4 FUN_00002100(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_00002168;
  iVar1 = DAT_00002164;
  if (param_2 == 1) {
    uVar2 = 0;
    do {
      *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_00002168 + 6)) && (*(ushort *)(DAT_00002168 + 6) != 0)) {
      uVar2 = 0;
      do {
        *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 4);
    }
    *(short *)(iVar3 + 6) = (short)param_3;
    iVar3 = FUN_0000b590(param_1);
    if (iVar3 == 0) {
      *(undefined4 *)(iVar1 + param_1 * 4) = 0;
    }
    else {
      uVar2 = *(int *)(iVar1 + param_1 * 4) + 1;
      *(uint *)(iVar1 + param_1 * 4) = uVar2;
      if (param_3 <= uVar2) {
        *(undefined4 *)(iVar1 + param_1 * 4) = 0;
        return 1;
      }
    }
  }
  return 0;
}




undefined4 FUN_0000216c(void)

{
  if (*DAT_00002568 != '\x01') {
    return 1;
  }
  return 0;
}




void FUN_0000217c(undefined param_1)

{
  int iVar1;
  int iVar2;
  undefined extraout_r1;
  
  iVar2 = FUN_0000216c();
  iVar1 = DAT_0000256c;
  if (iVar2 == 0) {
    *DAT_00002568 = 0;
    *(undefined *)(iVar1 + 3) = param_1;
  }
  *(undefined *)(iVar1 + 2) = *(undefined *)(iVar1 + 1);
  *(undefined *)(iVar1 + 1) = extraout_r1;
  return;
}




void FUN_00002198(void)

{
  int iVar1;
  
  iVar1 = FUN_0000216c();
  if (iVar1 == 0) {
    *DAT_00002568 = 1;
  }
  *(undefined *)(DAT_0000256c + 1) = *(undefined *)(DAT_0000256c + 2);
  return;
}




void FUN_000021ae(void)

{
  *(undefined *)(DAT_0000256c + 1) = 1;
  return;
}




void FUN_000021b6(void)

{
  int iVar1;
  
  iVar1 = FUN_0000216c();
  if (iVar1 == 0) {
    *DAT_00002568 = 1;
  }
  *(undefined *)(DAT_0000256c + 1) = 0;
  return;
}




void FUN_000021cc(void)

{
  *DAT_00002568 = 5;
  return;
}




void FUN_000021d4(void)

{
  *DAT_00002568 = 1;
  *(undefined *)(DAT_0000256c + 1) = 1;
  return;
}




undefined4 FUN_000021e0(void)

{
  if (*DAT_00002568 != '\x03') {
    return 0;
  }
  return 1;
}




undefined FUN_00002206(int param_1)

{
  return *(undefined *)(param_1 + DAT_00002568 + 2);
}




uint FUN_0000220e(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00002206();
  if (uVar1 != 0) {
    uVar1 = (uint)*(char *)(DAT_00002568 + param_1 + 0x58);
  }
  return uVar1 & 0xff;
}




void FUN_00002224(int param_1,undefined param_2)

{
  *(undefined *)(param_1 + DAT_00002568 + 0x58) = param_2;
  return;
}




undefined4 FUN_0000222e(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_00002206();
  if (iVar1 == 0) {
    return 0;
  }
  if (3 < param_1) {
    return 5;
  }
  iVar1 = DAT_0000aa0c + param_1 * 100;
  if (((*(char *)(iVar1 + 0x17) != '\0') && (*(char *)(iVar1 + 99) == '\a')) &&
     (*(int *)(iVar1 + 0x28) == 0)) {
    return 1;
  }
  return 0;
}




int FUN_00002246(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (uint)*(byte *)(DAT_00002568 + param_1 * 0x28 + 0x5c);
  if (((uVar1 - 0x31 < 9) || (uVar1 - 0x61 < 3)) || (uVar1 - 0x41 < 3)) {
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  iVar2 = FUN_00002206(param_1,param_1,iVar3);
  if (iVar2 != 0) {
    iVar2 = iVar3;
  }
  return iVar2;
}




void FUN_00002280(int param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_000237a0(DAT_00002568 + param_1 * 0x28 + 0x5c,param_2,0x28);
    return;
  }
  return;
}




int FUN_00002298(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00002206();
  if ((iVar1 != 0) && (iVar1 = FUN_00002246(param_1), iVar1 != 0)) {
    return DAT_00002568 + param_1 * 0x28 + 0x5c;
  }
  return 0;
}




void FUN_000022bc(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = DAT_00002568 + param_1 * 8;
    uVar2 = param_2[1];
    *(undefined4 *)(iVar1 + 0xfc) = *param_2;
    *(undefined4 *)(iVar1 + 0x100) = uVar2;
  }
  return;
}




int FUN_000022d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00002206();
  if ((iVar1 != 0) && (iVar1 = FUN_00002246(param_1), iVar1 != 0)) {
    return DAT_00002568 + param_1 * 8 + 0xfc;
  }
  return 0;
}




undefined4 FUN_000022f0(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  while ((iVar1 = FUN_00003948(bVar2), iVar1 == 0 || (iVar1 = FUN_0000b782(bVar2), iVar1 == 0))) {
    bVar2 = bVar2 + 1;
    if (3 < bVar2) {
      return 0;
    }
  }
  return 1;
}




char FUN_00002314(void)

{
  char *pcVar1;
  char cVar2;
  short sVar3;
  bool bVar4;
  
  pcVar1 = DAT_00002568;
  sVar3 = 0x25d;
  cVar2 = *(char *)(DAT_00002570 + 2);
  if (cVar2 != '\x01') {
    if (cVar2 == '\0') {
      cVar2 = *DAT_00002568;
      while( true ) {
        if (cVar2 != '\x03') {
          return '\0';
        }
        FUN_0001eb00(100);
        bVar4 = sVar3 == 0;
        sVar3 = sVar3 + -1;
        if (bVar4) break;
        cVar2 = *pcVar1;
      }
      if (sVar3 != 0) {
        return '\0';
      }
      return '\x01';
    }
    cVar2 = '\x02';
  }
  return cVar2;
}




undefined4 FUN_0000234e(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0001a1aa();
  iVar2 = FUN_0001a20e(10000);
  iVar5 = param_1 * 3 + DAT_00002568;
  do {
    uVar3 = FUN_00003948(param_1);
    iVar4 = FUN_00003be2(iVar5 + 0x12,uVar3);
    if (iVar4 == 0) {
      return 0;
    }
    FUN_0001eb00(1);
    iVar4 = FUN_0001a1aa();
  } while (iVar4 - (iVar1 + iVar2) < 0);
  return 1;
}




undefined4 FUN_00002394(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0001a1aa();
  iVar2 = FUN_0001a20e(10000);
  iVar5 = param_1 * 3 + DAT_00002568;
  do {
    uVar3 = FUN_00003948(param_1);
    iVar4 = FUN_00003be2(iVar5 + 0x12,uVar3);
    if (iVar4 != 0) {
      return 0;
    }
    FUN_0001eb00(1);
    iVar4 = FUN_0001a1aa();
  } while (iVar4 - (iVar1 + iVar2) < 0);
  return 1;
}




void FUN_000023dc(undefined4 param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  while( true ) {
    iVar1 = FUN_00009ffc(param_1,0,0xff);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = FUN_00002394(param_1);
    if (iVar1 != 0) {
      FUN_0001cd4c(&DAT_00002574);
      FUN_0001cd4c(s_pretension_hub_insert_fil_detect_0000258c);
      FUN_0001cd4c(&DAT_000025b8);
    }
    FUN_0000a052(param_1);
    iVar1 = FUN_00009ffc(param_1,1,0xff);
    if (iVar1 != 0) break;
    iVar1 = FUN_0000234e(param_1);
    if (iVar1 != 0) {
      FUN_0001cd4c(&DAT_00002574);
      FUN_0001cd4c(s_pretension_hub_pullout_fil_detec_000025c0);
      FUN_0001cd4c(&DAT_000025b8);
    }
    FUN_0000a052(param_1);
    bVar2 = bVar2 + 1;
    if (2 < bVar2) {
      return;
    }
  }
  return;
}




void FUN_00002448(int param_1)

{
  undefined *puVar1;
  
  puVar1 = DAT_0000256c;
  DAT_0000256c[param_1 + 4] = 1;
  if (puVar1[param_1 + 0xc] != '\0') {
    puVar1[param_1 + 8] = 0;
    return;
  }
  puVar1[param_1 + 8] = 1;
  *DAT_0000256c = 1;
  FUN_0001cd4c(&DAT_000025ec);
  FUN_0001cd4c(s__d_realtime_insert_00002600,param_1);
  FUN_0001cd4c(&DAT_000025b8);
  return;
}




void FUN_00002480(int param_1)

{
  undefined *puVar1;
  
  puVar1 = DAT_0000256c;
  DAT_0000256c[param_1 + 4] = 0;
  puVar1[param_1 + 8] = 2;
  *puVar1 = 1;
  FUN_0001cd4c(&DAT_000025ec);
  FUN_0001cd4c(s__d_realtime_pullout_00002614,param_1);
  FUN_0001cd4c(&DAT_000025b8);
  return;
}




void FUN_000024b0(int param_1)

{
  undefined *puVar1;
  undefined uVar2;
  
  puVar1 = DAT_0000256c;
  if (DAT_0000256c[param_1 + 0xc] != '\0') {
    DAT_0000256c[param_1 + 8] = 0;
    puVar1[param_1 + 0xc] = 0;
    return;
  }
  if (DAT_0000256c[param_1 + 4] == '\x01') {
    uVar2 = 3;
  }
  else {
    uVar2 = 2;
  }
  DAT_0000256c[param_1 + 8] = uVar2;
  *DAT_0000256c = 1;
  FUN_0001cd4c(&DAT_000025ec);
  FUN_0001cd4c(s__d_finish_action_00002628,param_1);
  FUN_0001cd4c(&DAT_000025b8);
  return;
}




void FUN_000024f6(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_00002568;
  *DAT_00002568 = 1;
  FUN_000024b0(puVar1[1]);
  *(undefined *)(DAT_00002570 + 2) = 0;
  FUN_0001eb00(300);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00002516(int param_1)

{
  undefined uVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  char cVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  bool bVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  float fVar22;
  float fVar23;
  undefined auStack_5c [8];
  undefined auStack_54 [12];
  uint local_48;
  
  uVar21 = DAT_00002568;
  uVar12 = 3;
  bVar2 = false;
  uVar4 = (uint)*(byte *)(DAT_0000263c + param_1);
  uVar5 = (uint)*(byte *)(DAT_0000263c + 4 + param_1);
  local_48 = 1;
  uVar1 = *(undefined *)(DAT_0000263c + 8 + param_1);
  iVar6 = DAT_00002568 + param_1 * 0x28 + 0x5c;
  FUN_00023966(iVar6,0x28);
  iVar7 = uVar21 + param_1 * 8;
  uVar15 = 0;
  *(undefined4 *)(iVar7 + 0xfc) = 0;
  *(undefined4 *)(iVar7 + 0x100) = 0;
  iVar7 = DAT_00002a3c;
  iVar16 = uVar21 + param_1;
  *(undefined *)(iVar16 + 0x58) = 100;
  uVar14 = uVar21;
  fVar3 = _DAT_00002a40;
  if (*(char *)(iVar7 + 5) != '\0') {
    FUN_0000da56(param_1,0);
    fVar3 = _DAT_00002a40;
  }
LAB_0000265e:
  *(undefined *)(uVar21 + 0x50) = 0;
  FUN_0000b23a(uVar4);
  iVar7 = FUN_0000a40c(uVar4,uVar5);
  if (iVar7 != 0) goto LAB_0000279c;
  FUN_0001cd4c(&DAT_000025ec);
  FUN_0001cd4c(s_B___first_detect_a_card_00002a43 + 1);
  FUN_0001cd4c(&DAT_000025b8);
  FUN_0001cd4c(&DAT_000025ec);
  FUN_0001cd4c(s_other_slot_id_FEEDER_DIR_IN_00002a5c);
  FUN_0001cd4c(&DAT_000025b8);
  iVar7 = FUN_00003958(uVar1);
  if (iVar7 == 0) goto LAB_00002710;
  iVar7 = FUN_00009ffc(uVar1,0,0xff);
  bVar17 = iVar7 == 0;
LAB_000026b8:
  do {
    if (!bVar17) {
      return;
    }
    FUN_00002394(uVar1);
    FUN_0000a07e();
    FUN_0001cd4c(&DAT_000025ec);
    FUN_0001cd4c(s_other_slot_id_FEEDER_DIR_OUT_00002a78);
    FUN_0001cd4c(&DAT_000025b8);
    iVar7 = FUN_00009ffc(uVar1,1,0xff);
    bVar17 = iVar7 == 0;
LAB_000026e6:
  } while (!bVar17);
  iVar7 = FUN_0000234e(uVar1);
  if (iVar7 != 0) {
    FUN_0001cd4c(&DAT_00002574);
    FUN_0001cd4c(s__rfid_move_hub_pullout_fil_detec_00002a98);
    FUN_0001cd4c(&DAT_000025b8);
  }
  FUN_0000a07e();
  FUN_0001eb00(200);
LAB_00002710:
  iVar7 = FUN_0000a40c(uVar4,uVar5);
  if (iVar7 != 0) goto LAB_0000279c;
  FUN_0001cd4c(&DAT_000025ec);
  FUN_0001cd4c(s_rfid_has_a_card_00002ac4);
  FUN_0001cd4c(&DAT_000025b8);
  uVar14 = 0;
  uVar15 = 400;
LAB_00002798:
  if (uVar14 < uVar12) {
    FUN_0001cd4c(&DAT_000025ec);
    FUN_0001cd4c(s_move_count__d_00002ad4,uVar14);
    FUN_0001cd4c(&DAT_000025b8);
    iVar7 = FUN_00009ffc(uVar1,1,0xff);
    bVar17 = iVar7 == 0;
    goto LAB_0000275e;
  }
LAB_0000279c:
  do {
    iVar7 = FUN_0000a40c(uVar4,uVar5);
    if (iVar7 != 2) {
LAB_0000286a:
      iVar7 = FUN_00001326(param_1);
      if (iVar7 != 0) {
        FUN_0001cd4c(&DAT_00002574);
        FUN_0001cd4c(s_margin_estimation_and_read_rfid_f_00002b14);
        FUN_0001cd4c(&DAT_000025b8);
      }
      FUN_0001eb00(400);
      FUN_0000b23a(uVar4);
      iVar7 = FUN_0000a40c(uVar4,uVar5);
      if (iVar7 != 0) goto LAB_000028e6;
      uVar15 = 0;
      break;
    }
    FUN_0001cd4c(&DAT_000025ec);
    FUN_0001cd4c(s___detect_multi_cards_00002afc);
    FUN_0001cd4c(&DAT_000025b8);
    iVar7 = FUN_00003958(uVar1);
    if (iVar7 == 0) {
LAB_00002818:
      uVar14 = 0;
      uVar15 = 800;
      while( true ) {
        if (uVar12 <= uVar14) goto LAB_0000286a;
        FUN_0001cd4c(&DAT_000025ec);
        FUN_0001cd4c(s_move_count__d_00002ad4,uVar14);
        FUN_0001cd4c(&DAT_000025b8);
        iVar7 = FUN_0000a40c(uVar4,uVar5);
        if (iVar7 != 2) goto LAB_0000286a;
        iVar7 = FUN_00009ffc(uVar1,1,0xff);
        bVar17 = iVar7 == 0;
        if (!bVar17) break;
        FUN_0001eb00(400);
        FUN_0000a07e();
        FUN_0001eb00(800);
        uVar14 = uVar14 + 1;
      }
    }
    else {
      iVar7 = FUN_00009ffc(uVar1,0,0xff);
      bVar17 = iVar7 == 0;
      if (!bVar17) goto LAB_000026e6;
      FUN_00002394(uVar1);
      FUN_0000a07e();
      iVar7 = FUN_00009ffc(uVar1,1,0xff);
      bVar17 = iVar7 == 0;
      if (bVar17) {
        iVar7 = FUN_0000234e(uVar1);
        if (iVar7 != 0) {
          FUN_0001cd4c(&DAT_00002574);
          FUN_0001cd4c(s__rfid_move_hub_pullout_fil_detec_00002a98);
          FUN_0001cd4c(&DAT_000025b8);
        }
        FUN_0000a07e();
        FUN_0001eb00(200);
        goto LAB_00002818;
      }
    }
LAB_0000275e:
    if (!bVar17) goto LAB_000026b8;
    FUN_0001eb00(uVar15);
    FUN_0000a07e();
    FUN_0001eb00(200);
    iVar7 = FUN_0000a40c(uVar4,uVar5);
    if (iVar7 == 0) goto LAB_00002796;
    FUN_0001cd4c(&DAT_000025ec);
    FUN_0001cd4c(s_first_detect_success_00002ae4);
    FUN_0001cd4c(&DAT_000025b8);
  } while( true );
  while( true ) {
    FUN_0000df30(0xa0);
    FUN_0001eb00(800);
    FUN_0000df64();
    FUN_0001eb00(200);
    uVar15 = uVar15 + 1;
    if (2 < uVar15) break;
    FUN_0001cd4c(&DAT_000025ec);
    FUN_0001cd4c(s_hub_move_count__d_00002b48,uVar15);
    FUN_0001cd4c(&DAT_000025b8);
    iVar7 = FUN_0000a40c(uVar4,uVar5);
    if (iVar7 != 0) break;
  }
LAB_000028e6:
  FUN_0000a094();
  FUN_0000df30(0x78);
  cVar13 = '\0';
  fVar18 = (float)FUN_0000840a();
  fVar22 = DAT_00002b5c;
  iVar7 = FUN_0001a1aa();
  iVar8 = FUN_0001a20e(s_____________gpio_test____________00004e00 + 0x20);
  iVar9 = FUN_0001a1aa();
  iVar10 = FUN_0001a20e(1000);
  uVar15 = iVar9 + iVar10;
  fVar23 = fVar22;
  do {
    iVar9 = FUN_0000a40c(uVar4,uVar5);
    if (iVar9 == 0) {
      FUN_0001eb00(2);
      iVar9 = FUN_0000a40c(uVar4,uVar5);
      if (iVar9 == 0) {
        if (cVar13 == '\0') {
          FUN_0001cd4c(&DAT_00002bb4);
          FUN_0001cd4c(s_detect_rfid__d_00002bcc,*(undefined *)(uVar21 + 0x50));
          FUN_0001cd4c(&DAT_000025b8);
          if (*(char *)(uVar21 + 0x50) == '\0') {
            FUN_0000a510(uVar4,uVar5,auStack_5c);
            fVar22 = (float)FUN_0000840a();
            FUN_0001cd4c(&DAT_000025ec);
            FUN_0001cd4c(s_start_rfid_fil_len__d_00002bdc,(int)fVar22);
            FUN_0001cd4c(&DAT_000025b8);
            fVar23 = fVar22;
          }
          if (*(char *)(uVar21 + 0x50) != '\x01') {
            *(char *)(uVar21 + 0x50) = *(char *)(uVar21 + 0x50) + '\x01';
            goto LAB_000029e0;
          }
          uVar11 = FUN_0000a510(uVar4,uVar5,auStack_54);
          iVar7 = FUN_00023614(auStack_5c,auStack_54,uVar11);
          if (iVar7 == 0) {
            fVar22 = (float)FUN_0000840a();
            FUN_0001cd4c(&DAT_000025ec);
            FUN_0001cd4c(s_end_rfid_fil_len__d_00003038,(int)fVar22);
            FUN_0001cd4c(&DAT_000025b8);
            FUN_0001cd4c(s__________________________________00003050);
            cVar13 = '\x05';
            goto LAB_00002c76;
          }
          if (local_48 != 0) {
            iVar7 = FUN_000017f6(param_1,0);
            if (iVar7 == 0) {
              FUN_0000172c(param_1,0);
            }
            local_48 = local_48 - 1 & 0xff;
            FUN_0001cd4c(&DAT_00002b60);
            FUN_0001cd4c(s_different_rfid_uid_detected__ret_00003010);
            FUN_0001cd4c(&DAT_000025b8);
            uVar14 = uVar21;
            goto LAB_0000265e;
          }
        }
        else {
LAB_000029e0:
          cVar13 = '\x10';
          iVar9 = FUN_0001a1aa();
          if ((int)(iVar9 - uVar15) < 0) goto LAB_00002944;
          fVar19 = (float)FUN_0000840a();
          fVar18 = ABS(fVar19 - fVar18);
          if ((int)fVar18 < 0x3f800000) {
            FUN_0001cd4c(&DAT_00002b60);
            FUN_0001cd4c(DAT_00002bf4,(int)fVar18,(int)(fVar18 * fVar3) % 100);
            FUN_0001cd4c(&DAT_000025b8);
            uVar14 = 4;
            goto LAB_00002dc0;
          }
          FUN_0001cd4c(&DAT_00002b60);
          FUN_0001cd4c(s_rfid_continuous_detect_timeout__p_000030bb + 1);
          FUN_0001cd4c(&DAT_000025b8);
        }
        uVar14 = 3;
        goto LAB_00002dc0;
      }
    }
    else {
      iVar9 = FUN_0001a1aa();
      iVar10 = FUN_0001a20e(1000);
      uVar15 = iVar9 + iVar10;
      if (cVar13 != '\0') {
        cVar13 = cVar13 + -1;
      }
    }
LAB_00002944:
    FUN_0001eb00(5);
    iVar9 = FUN_0001a1aa();
    if (-1 < iVar9 - (iVar7 + iVar8)) {
      FUN_0001cd4c(&DAT_00002b60);
      FUN_0001cd4c(s_margin_estimation_timeout__plese_00002b78);
      FUN_0001cd4c(&DAT_000025b8);
      uVar14 = 2;
      goto LAB_00002dc0;
    }
    fVar19 = (float)FUN_0000840a();
    fVar19 = fVar19 - fVar18;
  } while ((((uint)fVar19 <= (uint)DAT_000030f8) && ((int)fVar19 <= DAT_000030fc)) ||
          (*(char *)(uVar21 + 0x50) != '\0'));
  FUN_0001cd4c(&DAT_00002b60);
  fVar20 = (float)FUN_0000840a();
  FUN_0001cd4c(DAT_00003100,(int)fVar18,(int)fVar20,(int)fVar19);
  FUN_0001cd4c(&DAT_000025b8);
  uVar14 = 5;
  goto LAB_00002dc0;
LAB_00002796:
  uVar14 = uVar14 + 1;
  goto LAB_00002798;
  while (uVar15 != 0) {
LAB_00002c76:
    FUN_0001eb00(10);
    FUN_0000df64();
    FUN_0001eb00(500);
    uVar15 = FUN_0000a474(uVar4,uVar5,3);
    if (uVar15 != 0) {
      FUN_00001160(param_1,0xff);
      FUN_0001eb00(1000);
      FUN_0000a07e();
      FUN_0001eb00(10);
      FUN_0000df30(100);
      iVar7 = 0;
      do {
        iVar8 = FUN_0000a40c(uVar4,uVar5);
        if (iVar8 == 0) break;
        FUN_0001eb00(1);
        bVar17 = iVar7 != 2999;
        iVar7 = iVar7 + 1;
      } while (bVar17);
      FUN_0000df64();
    }
    cVar13 = cVar13 + -1;
    if (cVar13 == '\0') {
      if (uVar15 != 0) {
        FUN_0001cd4c(&DAT_00002b60);
        FUN_0001cd4c(s_the_number_of_RFID_retries_read_m_00003080);
        FUN_0001cd4c(&DAT_000025b8);
        uVar14 = 1;
        goto LAB_00002dc0;
      }
      break;
    }
  }
  FUN_0000af54(uVar4,uVar5);
  FUN_0000b138(uVar4,uVar5);
  iVar7 = _DAT_000030b8;
  FUN_00002280(param_1,_DAT_000030b8 + uVar4 * 0x50 + uVar5 * 0x28 + 0x1d);
  FUN_000022bc(param_1,iVar7 + uVar4 * 0x10 + uVar5 * 8 + 0xc0);
  uVar14 = 0;
  bVar2 = true;
LAB_00002dc0:
  FUN_0000df64();
  FUN_0000a07e();
  FUN_00001b28(*(undefined *)(uVar21 + 1));
  if (fVar22 == fVar23 || fVar22 < fVar23 != (NAN(fVar22) || NAN(fVar23))) {
    fVar22 = fVar23 - fVar22;
  }
  else {
    fVar22 = fVar22 - fVar23;
  }
  if (uVar14 == 0) {
    if (_DAT_00003104 < (int)fVar22) goto LAB_00002f3e;
  }
  else if (uVar14 != 3) goto LAB_00002f3e;
  FUN_0001cd4c(&DAT_00002b60);
  FUN_0001cd4c(s_Crfid_detected_next_to_it__move_i_00003107 + 1);
  FUN_0001cd4c(&DAT_000025b8);
  iVar7 = FUN_00003958(uVar1);
  if (iVar7 == 0) goto LAB_00002e64;
  iVar7 = FUN_00009ffc(uVar1,0,0xff);
  bVar17 = iVar7 == 0;
LAB_00002e20:
  do {
    do {
      do {
        if (!bVar17) {
          return;
        }
        FUN_00002394(uVar1);
        FUN_0000a07e();
        iVar7 = FUN_00009ffc(uVar1,1,0xff);
        bVar17 = iVar7 == 0;
      } while (!bVar17);
      iVar7 = FUN_0000234e(uVar1);
      if (iVar7 != 0) {
        FUN_0001cd4c(&DAT_00002574);
        FUN_0001cd4c(s__rfid_move_hub_pullout_fil_detec_00002a98);
        FUN_0001cd4c(&DAT_000025b8);
      }
      FUN_0000a07e();
      FUN_0001eb00(200);
LAB_00002e64:
      FUN_0000b23a(uVar4);
      iVar7 = FUN_0000a40c(uVar4,uVar5);
      if (iVar7 != 0) goto LAB_00002f1c;
      uVar15 = 0;
      do {
        FUN_0000b23a(uVar4);
        iVar7 = FUN_0000a40c(uVar4,uVar5);
        if (iVar7 == 0) {
          iVar7 = FUN_00009ffc(uVar1,1,0xff);
          bVar17 = iVar7 == 0;
          if (!bVar17) goto LAB_00002e20;
          FUN_0001eb00(400);
          FUN_0000a07e();
          FUN_0001eb00(100);
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < 3);
      if (uVar15 != 3) goto LAB_00002f1c;
      FUN_0000b23a(uVar4);
      iVar7 = FUN_0000a40c(uVar4,uVar5);
      if (((iVar7 != 0) && (1 < uVar12)) || (iVar7 = FUN_00003958(uVar1), iVar7 == 0))
      goto LAB_00002f1c;
      iVar7 = FUN_00009ffc(uVar1,0,0xff);
      bVar17 = iVar7 == 0;
    } while (!bVar17);
    FUN_00002394(uVar1);
    FUN_0000a07e();
    iVar7 = FUN_00009ffc(uVar1,1,0xff);
    bVar17 = iVar7 == 0;
  } while (!bVar17);
  iVar7 = FUN_0000234e(uVar1);
  if (iVar7 != 0) {
    FUN_0001cd4c(&DAT_00002574);
    FUN_0001cd4c(s__rfid_move_hub_pullout_fil_detec_00002a98);
    FUN_0001cd4c(&DAT_000025b8);
  }
  FUN_0000a07e();
LAB_00002f1c:
  if (uVar12 != 0) {
    uVar12 = uVar12 - 1 & 0xff;
    goto LAB_0000265e;
  }
  FUN_0001cd4c(&DAT_00002b60);
  FUN_0001cd4c(s_the_number_of_RFID_retries_next_t_0000312c);
  FUN_0001cd4c(&DAT_000025b8);
  bVar2 = false;
LAB_00002f3e:
  fVar23 = _DAT_0000316c;
  if ((int)fVar22 < DAT_00003168) {
    FUN_0001cd4c(&DAT_00002b60);
    FUN_0001cd4c(s_Cfil_len_per_rotation__d_____0000316f + 1,(int)fVar22);
    FUN_0001cd4c(&DAT_000025b8);
    bVar2 = false;
    fVar22 = fVar23;
  }
  if (fVar22 < 0.0) {
LAB_00002fa6:
    uVar15 = 100;
  }
  else {
    uVar15 = VectorFloatToUnsigned(((fVar22 - fVar23) / DAT_0000318c) * fVar3 + 0.5,3);
    uVar15 = uVar15 & 0xff;
    if (100 < uVar15) goto LAB_00002fa6;
    if (uVar15 == 0) {
      uVar15 = 1;
    }
  }
  if (0.0 <= fVar22) {
    uVar21 = VectorFloatToUnsigned
                       ((((fVar22 / DAT_00003190) * DAT_00003194 * (fVar22 / DAT_00003190) -
                         DAT_00003198) / DAT_0000319c) * fVar3 + 0.5,3);
    uVar21 = uVar21 & 0xff;
    if (uVar21 < 0x65) {
      if (uVar21 == 0) {
        uVar21 = 1;
      }
      goto LAB_00002ffa;
    }
  }
  uVar21 = 100;
LAB_00002ffa:
  if (uVar14 == 0) {
    *(char *)(iVar16 + 0x58) = (char)uVar21;
    iVar7 = FUN_000002e2();
    if (iVar7 == 1) {
      if (!bVar2) {
        uVar21 = 100;
      }
      FUN_0000a818(param_1,uVar21);
    }
  }
  else {
    *(undefined *)(iVar16 + 0x58) = 100;
    iVar7 = FUN_000002e2();
    if (iVar7 == 1) {
      FUN_00023966(iVar6,0x28);
      FUN_0000aa74(param_1);
    }
  }
  FUN_0001cd4c(&DAT_000025ec);
  FUN_0001cd4c(DAT_000035c8,(int)fVar22,uVar15,uVar21);
  FUN_0001cd4c(&DAT_000025b8);
  return;
}




undefined4 FUN_00003948(void)

{
  int iVar1;
  
  iVar1 = FUN_0000b5a0();
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}




undefined4 FUN_00003958(void)

{
  int iVar1;
  
  iVar1 = FUN_0000b590();
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}




void FUN_00003ac0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00003bc4;
  *param_1 = DAT_00003bc4;
  param_1[1] = uVar1;
  param_1[2] = DAT_00003bc8;
  param_1[3] = uVar1;
  param_1[4] = uVar1;
  param_1[5] = uVar1;
  param_1[6] = DAT_00003bcc;
  param_1[7] = DAT_00003bd0;
  param_1[8] = DAT_00003bd4;
  return;
}




void FUN_00003afa(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00003bc4;
  *param_1 = DAT_00003bc4;
  param_1[3] = uVar1;
  param_1[4] = uVar1;
  param_1[5] = uVar1;
  return;
}




void FUN_00003b10(undefined4 param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_3 + 4) = param_1;
  *(undefined4 *)(param_3 + 8) = param_2;
  return;
}




void FUN_00003b1a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(param_4 + 0x18) = param_1;
  *(undefined4 *)(param_4 + 0x1c) = param_2;
  *(undefined4 *)(param_4 + 0x20) = param_3;
  return;
}




float FUN_00003b44(float param_1,float param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  
  param_1 = param_1 - param_2;
  param_3[3] = param_1;
  fVar1 = param_3[4];
  fVar2 = param_3[5];
  param_3[5] = fVar1;
  param_3[4] = param_1;
  fVar2 = *param_3 +
          (param_1 - fVar1) * param_3[6] + param_3[7] * param_1 +
          param_3[8] * ((param_1 - fVar1 * 2.0) + fVar2);
  *param_3 = fVar2;
  fVar1 = param_3[2];
  if (fVar2 != fVar1 && fVar2 < fVar1 == (NAN(fVar2) || NAN(fVar1))) {
    *param_3 = fVar1;
  }
  fVar1 = param_3[1];
  if (fVar1 <= *param_3) {
    return *param_3;
  }
  *param_3 = fVar1;
  return fVar1;
}




byte FUN_00003be2(byte *param_1,uint param_2)

{
  byte bVar1;
  
  if (*param_1 == param_2) {
    param_1[2] = 0;
  }
  else {
    bVar1 = param_1[2];
    if (bVar1 < param_1[1]) {
      bVar1 = bVar1 + 1;
      param_1[2] = bVar1;
    }
    if (param_1[1] <= bVar1) {
      *param_1 = (byte)param_2;
    }
  }
  return *param_1;
}




void FUN_00003c08(int *param_1,code **param_2,int param_3)

{
  undefined uVar1;
  
  *param_1 = (int)param_2;
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else if (param_3 == 1) {
    uVar1 = 1;
  }
  else if (param_3 == 2) {
    uVar1 = 2;
  }
  else {
    uVar1 = 3;
  }
  *(undefined *)(param_1 + 1) = uVar1;
  (**param_2)(0,1);
  (**(code **)*param_1)(1);
  (**(code **)*param_1)(2,0);
                    /* WARNING: Could not recover jumptable at 0x00003c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 4))(0,((uint)*(byte *)(param_1 + 1) << 0x1e) >> 0x1f);
  return;
}




void FUN_00003c56(int *param_1,int param_2,int param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  for (uVar4 = 0; uVar4 < param_4; uVar4 = uVar4 + 1) {
    if (param_2 == 0) {
      uVar3 = 0xff;
    }
    else {
      uVar3 = (uint)*(byte *)(param_2 + uVar4);
    }
    cVar1 = *(char *)(param_1 + 1);
    if (cVar1 == '\0') {
      bVar5 = 0;
      do {
        (**(code **)(*param_1 + 4))(1,uVar3 >> 7);
        (**(code **)(*param_1 + 4))(0,1);
        uVar2 = (**(code **)(*param_1 + 8))(2);
        uVar3 = uVar2 | (uVar3 << 0x19) >> 0x18;
        (**(code **)(*param_1 + 4))(0);
        bVar5 = bVar5 + 1;
      } while (bVar5 < 8);
    }
    else if (cVar1 == '\x01') {
      bVar5 = 0;
      do {
        (**(code **)(*param_1 + 4))(0,1);
        (**(code **)(*param_1 + 4))(1,uVar3 >> 7);
        (**(code **)(*param_1 + 4))(0);
        uVar2 = (**(code **)(*param_1 + 8))(2);
        bVar5 = bVar5 + 1;
        uVar3 = uVar2 | (uVar3 << 0x19) >> 0x18;
      } while (bVar5 < 8);
    }
    else if (cVar1 == '\x02') {
      bVar5 = 0;
      do {
        (**(code **)(*param_1 + 4))(1,uVar3 >> 7);
        (**(code **)(*param_1 + 4))(0);
        uVar2 = (**(code **)(*param_1 + 8))(2);
        uVar3 = uVar2 | (uVar3 << 0x19) >> 0x18;
        (**(code **)(*param_1 + 4))(0,1);
        bVar5 = bVar5 + 1;
      } while (bVar5 < 8);
    }
    else if (cVar1 == '\x03') {
      bVar5 = 0;
      do {
        (**(code **)(*param_1 + 4))(0);
        (**(code **)(*param_1 + 4))(1,uVar3 >> 7);
        (**(code **)(*param_1 + 4))(0,1);
        uVar2 = (**(code **)(*param_1 + 8))(2);
        bVar5 = bVar5 + 1;
        uVar3 = uVar2 | (uVar3 << 0x19) >> 0x18;
      } while (bVar5 < 8);
    }
    if (param_3 != 0) {
      *(char *)(param_3 + uVar4) = (char)uVar3;
    }
  }
  return;
}




undefined4 FUN_00003d8c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_0000417c;
  iVar1 = DAT_00004178;
  if (param_2 == 1) {
    uVar2 = 0;
    do {
      *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_0000417c + 8)) && (*(ushort *)(DAT_0000417c + 8) != 0)) {
      uVar2 = 0;
      do {
        *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 4);
    }
    *(short *)(iVar3 + 8) = (short)param_3;
    iVar3 = FUN_0000b5a0(param_1);
    if (iVar3 == 0) {
      uVar2 = *(int *)(iVar1 + param_1 * 4) + 1;
      *(uint *)(iVar1 + param_1 * 4) = uVar2;
      if (param_3 <= uVar2) {
        *(undefined4 *)(iVar1 + param_1 * 4) = 0;
        return 1;
      }
    }
    else {
      *(undefined4 *)(iVar1 + param_1 * 4) = 0;
    }
  }
  return 0;
}




undefined4 FUN_00003df0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0000417c;
  iVar3 = DAT_00004178 + -0x10;
  if (param_2 == 1) {
    uVar1 = 0;
    do {
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_0000417c + 6)) && (*(ushort *)(DAT_0000417c + 6) != 0)) {
      uVar1 = 0;
      do {
        *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
    }
    *(short *)(iVar2 + 6) = (short)param_3;
    iVar2 = FUN_0000b5a0(param_1);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar3 + param_1 * 4) = 0;
    }
    else {
      uVar1 = *(int *)(iVar3 + param_1 * 4) + 1;
      *(uint *)(iVar3 + param_1 * 4) = uVar1;
      if (param_3 <= uVar1) {
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
        return 1;
      }
    }
  }
  return 0;
}




undefined4 FUN_00003e56(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0000417c;
  iVar3 = DAT_00004178 + -0x20;
  if (param_2 == 1) {
    uVar1 = 0;
    do {
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_0000417c + 4)) && (*(ushort *)(DAT_0000417c + 4) != 0)) {
      uVar1 = 0;
      do {
        *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
    }
    *(short *)(iVar2 + 4) = (short)param_3;
    iVar2 = FUN_0000b590(param_1);
    if (iVar2 == 0) {
      uVar1 = *(int *)(iVar3 + param_1 * 4) + 1;
      *(uint *)(iVar3 + param_1 * 4) = uVar1;
      if (param_3 <= uVar1) {
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
        return 1;
      }
    }
    else {
      *(undefined4 *)(iVar3 + param_1 * 4) = 0;
    }
  }
  return 0;
}




undefined4 FUN_00003eb8(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0000417c;
  iVar3 = DAT_00004178 + -0x30;
  if (param_2 == 1) {
    uVar1 = 0;
    do {
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_0000417c + 2)) && (*(ushort *)(DAT_0000417c + 2) != 0)) {
      uVar1 = 0;
      do {
        *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
    }
    *(short *)(iVar2 + 2) = (short)param_3;
    iVar2 = FUN_0000b590(param_1);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar3 + param_1 * 4) = 0;
    }
    else {
      uVar1 = *(int *)(iVar3 + param_1 * 4) + 1;
      *(uint *)(iVar3 + param_1 * 4) = uVar1;
      if (param_3 <= uVar1) {
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
        return 1;
      }
    }
  }
  return 0;
}




void FUN_00003f4a(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 unaff_r4;
  undefined4 in_lr;
  
  iVar1 = DAT_00004180;
  *(undefined *)(DAT_00004180 + 6) = 0;
  *(undefined *)(iVar1 + 2) = 0;
  FUN_000021ae();
  FUN_0000d450(0);
  FUN_0000733a();
  FUN_00003eb8(0,1,10,in_r3,unaff_r4,in_lr);
  FUN_00003e56(0,1,10);
  FUN_00003df0(0,1,10);
  FUN_00003d8c(0,1,10);
  return;
}




void FUN_00003f6a(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 unaff_r4;
  undefined4 in_lr;
  
  iVar1 = DAT_00004180;
  *(undefined *)(DAT_00004180 + 6) = 1;
  *(undefined *)(iVar1 + 2) = 5;
  FUN_000021cc();
  FUN_0000d450(9,0);
  FUN_0000733a();
  FUN_00003eb8(0,1,10,in_r3,unaff_r4,in_lr);
  FUN_00003e56(0,1,10);
  FUN_00003df0(0,1,10);
  FUN_00003d8c(0,1,10);
  return;
}




void FUN_00003f8c(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined auStack_38 [36];
  
  uVar3 = *DAT_00004184;
  uVar4 = DAT_00004184[1];
  uVar2 = DAT_00004184[2];
  FUN_000232c0(auStack_38,s__02x_02x_02x_02x_02x_02x_02x_02x_00004188,uVar3 & 0xff,
               (uVar3 << 0x10) >> 0x18,(uVar3 << 8) >> 0x18,uVar3 >> 0x18,uVar4 & 0xff,
               (uVar4 << 0x10) >> 0x18,(uVar4 << 8) >> 0x18,uVar4 >> 0x18,uVar2 & 0xff,
               (uVar2 << 0x10) >> 0x18,(uVar2 << 8) >> 0x18,uVar2 >> 0x18);
  puVar1 = DAT_000041bc;
  *DAT_000041bc = 1;
  FUN_0001cd4c(&DAT_000041c0);
  FUN_000232a8(&DAT_000041c0);
  uVar2 = 0;
  iVar5 = DAT_00004178 + -0x48;
  iVar6 = DAT_0000417c + 0x20;
  do {
    FUN_0001cd4c(s___s____d__000041c4,*(undefined4 *)(iVar6 + uVar2 * 4),
                 *(undefined *)(iVar5 + uVar2));
    FUN_000232a8(s___s____d__000041c4,*(undefined4 *)(iVar6 + uVar2 * 4),
                 *(undefined *)(iVar5 + uVar2));
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x18);
  FUN_0001cd4c(s__uuid_____s__000041d0,auStack_38);
  FUN_000232a8(s__uuid_____s__000041d0,auStack_38);
  FUN_0001cd4c(&DAT_000041e0);
  FUN_000232a8(&DAT_000041e0);
  *puVar1 = 0;
  return;
}




void FUN_0000403c(int param_1)

{
  if (param_1 != 0) {
    FUN_0001cd4c(s_NG______ret__d_000041e4,param_1);
    return;
  }
  FUN_0001cd4c(&DAT_000041f4);
  return;
}




undefined4 FUN_0000404c(undefined4 param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  do {
    FUN_0001eb00(0x14);
    iVar1 = FUN_0000a40c(param_1,0);
    if (iVar1 == 0) {
      iVar1 = FUN_0000a474(param_1,0,5);
      if (iVar1 == 0) {
        return 0;
      }
      return 2;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 5);
  FUN_0001cd4c(s_ID__d__no_card_detected__000041f8,param_1);
  return 1;
}




int FUN_00004088(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_00015b9c(param_1,1);
  FUN_00015b9c(param_2,0);
  FUN_00015bc4(param_2,1);
  FUN_0001eb00(10);
  iVar1 = FUN_00015bec(param_1);
  if (iVar1 == 1) {
    FUN_00015bc4(param_2,0);
    FUN_0001eb00(10);
    iVar1 = FUN_00015bec(param_1);
    if (iVar1 != 0) {
      return 2;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}




uint FUN_000040d4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00004088();
  if ((uVar1 == 0) && (uVar1 = FUN_00004088(param_2,param_1), uVar1 != 0)) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  return uVar1;
}




undefined4 FUN_000040f4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_00015b9c(param_1,2);
  FUN_00015b9c(param_2,0);
  FUN_00015bc4(param_2,1);
  FUN_0001eb00(10);
  iVar1 = FUN_00015bec(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  FUN_00015bc4(param_2,0);
  FUN_0001eb00(10);
  iVar1 = FUN_00015bec(param_1);
  if (iVar1 != 1) {
    return 2;
  }
  return 0;
}




void FUN_00004142(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  char *pcVar16;
  
  FUN_0001cd4c(s____________GPIO_TEST____________00004214);
  FUN_0001cd4c(s_PIN_LIMIT_1_in__PIN_RED1_CTL_out_00004238);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x37,0x26);
  iVar2 = FUN_000040f4(0x37,0x26);
  FUN_0000403c();
  iVar1 = DAT_00004178;
  *(bool *)(DAT_00004178 + -0x42) = iVar2 == 0;
  FUN_0001cd4c(s_PIN_LIMIT_2_in__PIN_RED2_CTL_out_00004648);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x36,0x27);
  iVar3 = FUN_000040f4(0x36,0x27);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x41) = iVar3 == 0;
  FUN_0001cd4c(s_PIN_LIMIT_3_in__PIN_RED3_CTL_out_00004678);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x35,0x28);
  iVar4 = FUN_000040f4(0x35,0x28);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x40) = iVar4 == 0;
  FUN_0001cd4c(s_PIN_LIMIT_4_in__PIN_RED4_CTL_out_000046a8);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x34,0x29);
  iVar5 = FUN_000040f4(0x34,0x29);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x3f) = iVar5 == 0;
  FUN_0001cd4c(s_PIN_LIMIT_5_in__PIN_BLUE1_CTL_ou_000046d8);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x47,0x17);
  iVar6 = FUN_000040f4(0x47,0x17);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x3e) = iVar6 == 0;
  FUN_0001cd4c(s_PIN_LIMIT_6_in__PIN_BLUE2_CTL_ou_00004708);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x48,0x14);
  iVar7 = FUN_000040f4(0x48,0x14);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x3d) = iVar7 == 0;
  FUN_0001cd4c(s_PIN_LIMIT_7_in__PIN_BLUE3_CTL_ou_00004738);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x49,0x15);
  iVar8 = FUN_000040f4(0x49,0x15);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x3c) = iVar8 == 0;
  FUN_0001cd4c(s_PIN_LIMIT_8_in__PIN_BLUE4_CTL_ou_00004768);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x4a,0x16);
  iVar9 = FUN_000040f4(0x4a,0x16);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x3b) = iVar9 == 0;
  FUN_0001cd4c(s_BUF_LIMIT_1_in_out__BUF_LIMIT_2__00004798);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x38,0x39);
  iVar10 = FUN_000040d4(0x38,0x39);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x3a) = iVar10 == 0;
  FUN_0001cd4c(s_PIN_CS_in_out__PIN_RD_in_out___T_000047d0);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x21,0x22);
  iVar11 = FUN_000040d4(0x21,0x22);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x39) = iVar11 == 0;
  FUN_0001cd4c(s_PIN_WR_in_out__PIN_DAT_in_out___T_000047fc);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0x23,0x24);
  iVar12 = FUN_000040d4(0x23,0x24);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x38) = iVar12 == 0;
  FUN_0001cd4c(s_PIN_ADDRESS_A_in__PIN_BG_CTL_out_00004828);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0xb,0x10);
  iVar13 = FUN_000040f4(0xb,0x10);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x37) = iVar13 == 0;
  FUN_0001cd4c(s_PIN_ADDRESS_B_in_out__PIN_IO_POW_00004858);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,0xc,6);
  iVar14 = FUN_000040d4(0xc,6);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x36) = iVar14 == 0;
  FUN_0001cd4c(s_PIN_HUM_in_out__PIN_TEM_in_out___00004890);
  FUN_0001cd4c(s_pin_d__pin_d__00004268,7,4);
  iVar15 = FUN_000040d4(7,4);
  FUN_0000403c();
  *(bool *)(iVar1 + -0x38) = iVar15 == 0;
  if ((((((((((((((iVar2 + iVar3 & 0xffU) + iVar4 & 0xff) + iVar5 & 0xff) + iVar6 & 0xff) + iVar7 &
              0xff) + iVar8 & 0xff) + iVar9 & 0xff) + iVar10 & 0xff) + iVar11 & 0xff) + iVar12 &
         0xff) + iVar13 & 0xff) + iVar14 & 0xff) + iVar15 & 0xff) == 0) {
    pcVar16 = &DAT_000048f0;
  }
  else {
    pcVar16 = s_NG____000048c0;
  }
  FUN_0001cd4c(s____________GPIO_TEST___s_________000048c8,pcVar16);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000451c(void)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  undefined4 uVar7;
  float fVar8;
  int iVar9;
  undefined4 local_28;
  
  bVar6 = 0;
  local_28 = 0;
LAB_00004536:
  uVar7 = 0;
  do {
    bVar4 = 0;
    do {
      FUN_00009ffc(bVar4,uVar7,0xff);
      bVar4 = bVar4 + 1;
    } while (bVar4 < 4);
    FUN_0001cd4c(s________bdc_detect_________000048f4);
    FUN_0001eb00(500);
    iVar2 = _DAT_00004914;
    fVar1 = DAT_00004910;
    uVar5 = 0;
    do {
      fVar8 = (float)FUN_0000ca4c((int)(char)uVar5);
      iVar9 = (int)(fVar8 * fVar1);
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      FUN_0001cd4c(s__d_vol__d__03dV_00004917 + 1,uVar5,(int)fVar8,iVar9 % 1000);
      if (((*(char *)(iVar2 + uVar5 + 9) != '\0') || ((int)fVar8 < DAT_0000492c)) &&
         (*(char *)((int)&local_28 + uVar5) == '\0')) {
        *(undefined *)((int)&local_28 + uVar5) = 1;
        *(undefined *)(_DAT_00004930 + uVar5 + 2) = 0;
        FUN_0001cd4c(s_________ERROR_________00004933 + 1);
        if (uVar5 == 0) {
          FUN_0001cd4c(s_IDETA_ADC_MCU_PC5_0000494c);
          FUN_0001cd4c(s_YA_PWM_1_PD2_00004960);
          pcVar3 = s_YA_PWM_2_PD3_00004970;
        }
        else if (uVar5 == 1) {
          FUN_0001cd4c(s_IDETB_ADC_MCU_PC1_00004980);
          FUN_0001cd4c(s_YB_PWM_1_PD0_00004994);
          pcVar3 = s_YB_PWM_2_PD1_000049a4;
        }
        else if (uVar5 == 2) {
          FUN_0001cd4c(s_IDETC_ADC_MCU_PA1_000049b4);
          FUN_0001cd4c(s_YC_PWM_1_PD14_000049c8);
          pcVar3 = s_YC_PWM_2_PD15_000049d8;
        }
        else {
          if (uVar5 != 3) goto LAB_00004618;
          FUN_0001cd4c(s_IDETD_ADC_MCU_PA0_000049e8);
          FUN_0001cd4c(s_YD_PWM_1_PD12_000049fc);
          pcVar3 = s_YD_PWM_2_PD13_00004a0c;
        }
        FUN_0001cd4c(pcVar3);
      }
LAB_00004618:
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 4);
    FUN_0001cd4c(s____________GPIO_TEST___s_________000048c8 + 0x24);
    bVar6 = bVar6 + 1;
    if (1 < bVar6) {
      FUN_0001cd4c(s_bdc_stop_00004a1c);
      bVar6 = 0;
      do {
        FUN_0000ce20((int)(char)bVar6,0);
        bVar6 = bVar6 + 1;
      } while (bVar6 < 4);
      return;
    }
    if (bVar6 == 0) goto LAB_00004536;
    uVar7 = 1;
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004a32(void)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  FUN_0001cd4c(s__s_v1_3_00004d24,DAT_00004d20);
  FUN_00003f6a();
  FUN_00023912(_DAT_00004d30,0x18,1);
  FUN_0001cd4c(s_____________EEPROM_test__________00004d33 + 1);
  pcVar3 = _DAT_00004d5c;
  puVar1 = _DAT_00004d30;
  if (*_DAT_00004d5c != '\0') {
    *_DAT_00004d30 = 0;
    FUN_0001cd4c(s_________ERROR_________00004933 + 1);
    FUN_0001cd4c(s_EEPROM_SCL_PE5_00004d5f + 1);
    FUN_0001cd4c(s_EEPROM_SDA_PE6_00004d70);
  }
  FUN_0001cd4c(s_____________BLDC_test____________00004d80);
  FUN_0001cd4c(s_Look_at_the_BLDC_00004da4);
  bVar5 = 0;
  do {
    iVar2 = FUN_0000e13a(bVar5,1000);
    if (iVar2 != 0) {
      FUN_0001cd4c(s_________ERROR_________00004933 + 1);
      FUN_0001cd4c(s_FG1_PE11_00004db8);
      FUN_0001cd4c(s_PWM_PE13_00004dc4);
      puVar1[1] = 0;
    }
    iVar2 = FUN_0000e164();
    if (iVar2 != 0) {
      FUN_0001cd4c(s_________ERROR_________00004933 + 1);
      FUN_0001cd4c(s_BRAK_PE4_00004dd0);
      puVar1[1] = 0;
    }
    bVar5 = bVar5 + 1;
  } while (bVar5 < 2);
  FUN_0000df64();
  FUN_0001cd4c(s_____________BDC_test_____________00004ddc);
  FUN_0000451c();
  FUN_0001cd4c(s_____________gpio_test____________00004e00);
  FUN_00004142();
  FUN_0001cd4c(s_____________Temp_Hum_test________00004e24);
  if (pcVar3[1] != '\0') {
    FUN_0001cd4c(s_________ERROR_________00004933 + 1);
    FUN_0001cd4c(s_AHT30_SCL_3V_PC11_00004e4c);
    FUN_0001cd4c(s_AHT30_SDA_3V_PC12_00004e60);
    puVar1[0x14] = 0;
  }
  FUN_0001cd4c(s_____________Odometer_Magnetic_te_00004e74);
  if (pcVar3[2] != '\0') {
    FUN_0001cd4c(s_________ERROR_________00004933 + 1);
    FUN_0001cd4c(s_SPI_CS_PB12_00004ea4);
    FUN_0001cd4c(s_SPI_CK_PB13_00004eb4);
    FUN_0001cd4c(s_SPI_MISO_PB14_00004ec4);
    FUN_0001cd4c(s_SPI_MOSI_PB15_00004ed4);
    puVar1[0x15] = 0;
  }
  FUN_0001cd4c(s____________RFID_TEST____________00004ee4);
  uVar6 = 0;
  uVar4 = 0;
  do {
    FUN_0001cd4c(s_rfid__d__00004f08,uVar4);
    iVar2 = FUN_0000404c(uVar4);
    FUN_0000403c();
    puVar1[uVar4 + 0x16] = iVar2 == 0;
    uVar4 = uVar4 + 1 & 0xff;
    uVar6 = uVar6 + iVar2 & 0xff;
  } while (uVar4 < 2);
  if (uVar6 == 0) {
    pcVar3 = &DAT_000048f0;
  }
  else {
    pcVar3 = s_NG_____00004f14;
  }
  FUN_0001cd4c(s____________RFID_TEST___s_________00004f1c,pcVar3);
  FUN_0001cd4c(s______________________FINISH_TEST_00004f44);
  bVar5 = 0;
  do {
    FUN_00003f8c();
    FUN_0001eb00(500);
    bVar5 = bVar5 + 1;
  } while (bVar5 < 3);
  return;
}




void FUN_00004b90(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  
  do {
    cVar2 = '\0';
    bVar4 = 0;
    do {
      iVar3 = FUN_0000b5a0(bVar4);
      bVar4 = bVar4 + 1;
      cVar2 = (iVar3 == 0) + cVar2;
    } while (bVar4 < 4);
    if (cVar2 == '\x01') {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      iVar3 = FUN_0000dfc0();
      if (iVar3 != 0) {
        FUN_0000df64();
      }
    }
    iVar3 = FUN_0000e44e();
    if (iVar3 == 0) {
      FUN_0000df64();
    }
    else if (iVar3 == 1) {
      if (bVar1) {
        FUN_0000df30(0xff);
      }
    }
    else if ((iVar3 == 2) && (bVar1)) {
      FUN_0000df4a(0xff);
    }
    FUN_0001eb00(0x14);
  } while( true );
}




undefined4 FUN_00004bf2(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0000a40c(param_1,0);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = thunk_FUN_0000a474(param_1,0,1);
  if (iVar1 != 0) {
    return 2;
  }
  return 1;
}




void FUN_00004c16(int param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int local_24 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_24[2] = 0;
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[3] = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  while (bVar3 = param_1 != 0, param_1 = param_1 + -1, bVar3) {
    uVar2 = 0;
    do {
      iVar1 = FUN_0000a40c(uVar2,0);
      if (iVar1 == 0) {
        iVar1 = FUN_00004bf2(uVar2);
        if (iVar1 == 1) {
          local_24[uVar2] = local_24[uVar2] + 1;
          local_24[uVar2 + 4] = local_24[uVar2 + 4] + 1;
        }
        else if (iVar1 == 2) {
          local_24[uVar2] = local_24[uVar2] + 1;
          local_24[uVar2 + 6] = local_24[uVar2 + 6] + 1;
        }
        local_24[uVar2 + 2] = local_24[uVar2 + 2] + 1;
        FUN_0001eb00(0x14);
      }
      iVar1 = FUN_0000c5ca();
      if (iVar1 == 0) {
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_0001cd4c(s_RFID_reader_id___d_00004f7c,uVar2);
        FUN_0001cd4c(s_test_count___d__00004f94,local_24[uVar2 + 2]);
        FUN_0001cd4c(s_card_found_count___d__00004fa8,local_24[uVar2]);
        FUN_0001cd4c(s_card_found_fail___d_00004fc0,local_24[uVar2 + 2] - local_24[uVar2]);
        FUN_0001cd4c(s_read_pass_count___d__00004fd8,local_24[uVar2 + 4]);
        FUN_0001cd4c(s_read_fail_count___d_000053d8,local_24[uVar2 + 6]);
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
      }
      else {
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_000232a8(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_0001cd4c(s_RFID_reader_id___d_00004f7c,uVar2);
        FUN_000232a8(s_RFID_reader_id___d_00004f7c,uVar2);
        FUN_0001cd4c(s_test_count___d__00004f94,local_24[uVar2 + 2]);
        FUN_000232a8(s_test_count___d__00004f94,local_24[uVar2 + 2]);
        FUN_0001cd4c(s_card_found_count___d__00004fa8,local_24[uVar2]);
        FUN_000232a8(s_card_found_count___d__00004fa8,local_24[uVar2]);
        FUN_0001cd4c(s_card_found_fail___d_00004fc0,local_24[uVar2 + 2] - local_24[uVar2]);
        FUN_000232a8(s_card_found_fail___d_00004fc0,local_24[uVar2 + 2] - local_24[uVar2]);
        FUN_0001cd4c(s_read_pass_count___d__00004fd8,local_24[uVar2 + 4]);
        FUN_000232a8(s_read_pass_count___d__00004fd8,local_24[uVar2 + 4]);
        FUN_0001cd4c(s_read_fail_count___d_000053d8,local_24[uVar2 + 6]);
        FUN_000232a8(s_read_fail_count___d_000053d8,local_24[uVar2 + 6]);
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_000232a8(s______________________FINISH_TEST_00004f44 + 0x20);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 2);
  }
  do {
    uVar2 = 0;
    do {
      iVar1 = FUN_0000c5ca();
      if (iVar1 == 0) {
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_0001cd4c(s_RFID_reader_id___d_00004f7c,uVar2);
        FUN_0001cd4c(s_test_count___d__00004f94,local_24[uVar2 + 2]);
        FUN_0001cd4c(s_card_found_count___d__00004fa8,local_24[uVar2]);
        FUN_0001cd4c(s_card_found_fail___d_00004fc0,local_24[uVar2 + 2] - local_24[uVar2]);
        FUN_0001cd4c(s_read_pass_count___d__00004fd8,local_24[uVar2 + 4]);
        FUN_0001cd4c(s_read_fail_count___d_000053d8,local_24[uVar2 + 6]);
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
      }
      else {
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_000232a8(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_0001cd4c(s_RFID_reader_id___d_00004f7c,uVar2);
        FUN_000232a8(s_RFID_reader_id___d_00004f7c,uVar2);
        FUN_0001cd4c(s_test_count___d__00004f94,local_24[uVar2 + 2]);
        FUN_000232a8(s_test_count___d__00004f94,local_24[uVar2 + 2]);
        FUN_0001cd4c(s_card_found_count___d__00004fa8,local_24[uVar2]);
        FUN_000232a8(s_card_found_count___d__00004fa8,local_24[uVar2]);
        FUN_0001cd4c(s_card_found_fail___d_00004fc0,local_24[uVar2 + 2] - local_24[uVar2]);
        FUN_000232a8(s_card_found_fail___d_00004fc0,local_24[uVar2 + 2] - local_24[uVar2]);
        FUN_0001cd4c(s_read_pass_count___d__00004fd8,local_24[uVar2 + 4]);
        FUN_000232a8(s_read_pass_count___d__00004fd8,local_24[uVar2 + 4]);
        FUN_0001cd4c(s_read_fail_count___d_000053d8,local_24[uVar2 + 6]);
        FUN_000232a8(s_read_fail_count___d_000053d8,local_24[uVar2 + 6]);
        FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
        FUN_000232a8(s______________________FINISH_TEST_00004f44 + 0x20);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 2);
    FUN_0001eb00(2000);
  } while( true );
}




void FUN_000051ac(void)

{
  do {
    FUN_0000df30(0xff);
    FUN_0001eb00(10000);
    FUN_0000df4a(0xff);
    FUN_0001eb00(10000);
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000051ca(void)

{
  char *pcVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  float local_20;
  float local_1c;
  
  iVar4 = 0;
  local_20 = DAT_000053f0;
  local_1c = DAT_000053f0;
  uVar5 = 0;
  FUN_00007174(4,0,1);
  if (*(char *)(_DAT_000053f4 + 1) == '\0') {
    FUN_0001eb00(0x9c4);
    pcVar1 = _DAT_0000540c;
    while ((*pcVar1 == '\0' || (pcVar1[1] == '\0'))) {
      FUN_0000bfb4();
      FUN_0001eb00(100);
    }
    bVar3 = 0;
    do {
      FUN_00009cd4(&local_20,&local_1c);
      iVar4 = (int)(char)(int)local_20;
      uVar5 = VectorFloatToUnsigned(local_1c,3);
      uVar5 = uVar5 & 0xff;
      FUN_0001cd4c(s_host_temp____d__slave_temp____d_0000540f + 1,iVar4,(int)*pcVar1);
      FUN_0001cd4c(s_host_hum____d__slave_hum____d_00005434,uVar5,pcVar1[1]);
      if (((*pcVar1 - iVar4) + 2U < 5) && (((byte)pcVar1[1] - uVar5) + 5 < 0xb)) break;
      bVar3 = bVar3 + 1;
    } while (bVar3 < 3);
    if (bVar3 != 3) goto LAB_0000528a;
    pcVar1 = s_sensor_test_fail__00005454;
  }
  else {
    pcVar1 = s_sensor_init_fail__000053f7 + 1;
  }
  FUN_0001cd4c(pcVar1);
  uVar2 = FUN_00007304(0x45);
  FUN_00007174(4,uVar2,1);
LAB_0000528a:
  FUN_00007202(iVar4);
  FUN_000071c2(uVar5);
  return;
}




void FUN_0000529a(void)

{
  byte bVar1;
  
  do {
    bVar1 = 0;
    do {
      FUN_00009ffc(bVar1,0,0xff);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
    FUN_0001eb00(3000);
    bVar1 = 0;
    do {
      FUN_0000ce20((int)(char)bVar1,0);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
    FUN_0001eb00(7000);
    bVar1 = 0;
    do {
      FUN_00009ffc(bVar1,1,0xff);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
    FUN_0001eb00(10000);
  } while( true );
}




void FUN_000052f4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  do {
    bVar4 = 4;
LAB_000052f8:
    FUN_0001eb00(10);
    bVar3 = 0;
    do {
      iVar1 = FUN_0000b590(bVar3);
      bVar5 = bVar3;
      if (iVar1 == 0) break;
      bVar3 = bVar3 + 1;
      bVar5 = bVar4;
    } while (bVar3 < 4);
  } while (bVar3 == 4);
  bVar4 = bVar5;
  if (bVar5 < 4) {
    iVar1 = FUN_0000b5a0(bVar5);
    if (iVar1 != 0) {
      FUN_00001326(bVar5);
    }
    iVar1 = FUN_0000e44e();
    if (iVar1 == 0) {
      if (param_1 != 1) {
        FUN_0000df4a(0xff);
      }
      uVar2 = 1;
    }
    else {
      if (iVar1 != 1) {
        if (iVar1 == 2) {
          if (param_1 != 1) {
            FUN_0000df64();
          }
          FUN_0000a052(bVar5);
        }
        goto LAB_000052f8;
      }
      if (param_1 != 1) {
        FUN_0000a052(bVar5);
        FUN_0000df30(0xff);
        goto LAB_000052f8;
      }
      uVar2 = 0;
    }
    FUN_00009ffc(bVar5,uVar2,0xff);
  }
  goto LAB_000052f8;
}




void FUN_0000537a(void)

{
  FUN_00009ffc(0,1,0xff);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




void FUN_00005386(void)

{
  FUN_00009ffc(0,0,0xff);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




void FUN_00005392(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  
  if ((param_3 == 0) || (param_3 == 1)) {
    bVar1 = 0;
    do {
      FUN_00009ffc(bVar1,param_1,0xff);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
    if (param_3 == 0) goto LAB_000053bc;
  }
  if (param_3 != 2) {
    return;
  }
LAB_000053bc:
  if (param_2 != 0) {
    FUN_0000df4a();
    return;
  }
  FUN_0000df30(0xff);
  return;
}




void FUN_00005468(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = FUN_00003e56(0,0,10);
    if (iVar1 != 0) {
      uVar2 = 1;
    }
    iVar1 = FUN_00003eb8(0,0,10);
    if (iVar1 != 0) {
      uVar2 = 0;
    }
    FUN_0000ed4e(uVar2);
    FUN_0001eb00(1);
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005494(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  *(undefined *)(_DAT_00005880 + 2) = 3;
  iVar4 = 0xff;
  do {
    iVar1 = FUN_0000e44e();
    if (iVar1 != iVar4) {
      if (iVar1 == 0) {
        uVar3 = 0;
LAB_000054ba:
        uVar2 = 10;
      }
      else {
        if (iVar1 == 1) {
          uVar3 = 1;
          goto LAB_000054ba;
        }
        if (iVar1 != 2) {
          uVar3 = 3;
          goto LAB_000054ba;
        }
        uVar3 = 2;
        uVar2 = 9;
      }
      FUN_0000d450(uVar2,uVar3);
    }
    FUN_0001eb00(100);
    iVar4 = iVar1;
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000054d0(float param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  float fVar6;
  
  bVar4 = 0;
LAB_000054dc:
  do {
    do {
      bVar3 = 0;
      do {
        iVar1 = FUN_00003d8c(bVar3,0,5);
        if (iVar1 != 0) break;
        FUN_0001eb00(10);
        bVar3 = bVar3 + 1;
      } while (bVar3 < 4);
    } while (bVar3 == 4);
    FUN_0001cd4c(s_current_channel____d_00005883 + 1,bVar3);
    FUN_00008598();
    FUN_0000df30(0xff);
    iVar1 = _DAT_0000589c;
    while (fVar5 = (float)FUN_0000840a(), iVar2 = _DAT_000058b8, (int)ABS(fVar5) < iVar1) {
      iVar2 = FUN_00003df0(bVar3,0,5);
      if (iVar2 != 0) {
        FUN_0001cd4c(s_AT_d_pull_out__restart_0000589e + 2,bVar3);
        FUN_0000df64();
        goto LAB_000054dc;
      }
      FUN_0001eb00(10);
    }
    while (fVar5 = (float)FUN_0000840a(), iVar2 <= (int)(fVar5 + param_1)) {
      FUN_0001eb00(0x14);
    }
    FUN_0001cd4c(s_8T_d_feed_finish__start_pull_bac_000058bb + 1,bVar3);
    FUN_0000df4a(0xff);
    do {
      iVar1 = FUN_00003df0(bVar3,0,5);
    } while (iVar1 == 0);
    FUN_0001eb00(0x14);
    fVar6 = (float)FUN_0000840a();
    if ((fVar6 == fVar5) && (bVar4 = bVar4 + 1, 4 < bVar4)) {
      FUN_0001cd4c(s_T_d_pull_back_finish__wait_for_p_000058e0,bVar3);
      return;
    }
    FUN_0000df64();
    while (iVar1 = FUN_00003df0(bVar3,0,5), iVar1 == 0) {
      FUN_0001eb00(10);
    }
    FUN_0001cd4c(s_finish_test_0000590c);
  } while( true );
}




void FUN_000055ca(void)

{
  int iVar1;
  uint uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  FUN_000021cc();
  do {
    uVar2 = 0;
    local_8 = 0;
    do {
      iVar1 = FUN_0000b590(uVar2);
      if (iVar1 == 0) {
        *(undefined *)((int)&local_8 + uVar2) = 1;
        FUN_00009ffc(uVar2,0,0xff);
        FUN_0001eb00(300);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
    FUN_0001eb00(3000);
    FUN_0000a07e();
    uVar2 = 0;
    do {
      if (*(char *)((int)&local_8 + uVar2) != '\0') {
        FUN_00009ffc(uVar2,1,0xff);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
    FUN_0001eb00(0x5dc);
    FUN_0000a07e();
  } while( true );
}




void FUN_0000563c(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar5 = 0;
  uVar3 = 0;
  iVar7 = 0;
  uVar6 = 0;
  FUN_0001eb00(500);
  FUN_0000b23a(0);
  FUN_0000b23a(1);
  FUN_0000d450(0);
  do {
    bVar4 = 0;
    do {
      iVar2 = FUN_0000a40c(bVar4,0);
      if (iVar2 == 0) goto LAB_00005676;
      bVar4 = bVar4 + 1;
    } while (bVar4 < 2);
  } while( true );
LAB_00005676:
  iVar2 = FUN_00004bf2(bVar4);
  if (iVar2 == 1) {
    iVar7 = iVar7 + 1;
    uVar3 = uVar3 + 1;
  }
  else if (iVar2 == 2) {
    uVar3 = uVar3 + 1;
    uVar6 = uVar6 + 1;
  }
  iVar5 = iVar5 + 1;
  FUN_0001eb00(0x14);
  if (2 < iVar5 - uVar3) goto LAB_000056ac;
  if (99 < uVar3) {
    if (uVar6 < 3) {
      bVar1 = true;
    }
    else {
LAB_000056ac:
      bVar1 = false;
    }
    FUN_0001cd4c(s_test_count___d__00004f94,iVar5);
    FUN_000232a8(s_test_count___d__00004f94,iVar5);
    FUN_0001cd4c(s_card_found_count___d__00004fa8,uVar3);
    FUN_000232a8(s_card_found_count___d__00004fa8,uVar3);
    FUN_0001cd4c(s_read_pass_count___d__00004fd8,iVar7);
    FUN_000232a8(s_read_pass_count___d__00004fd8,iVar7);
    FUN_0001cd4c(s_read_fail_count___d_000053d8,uVar6);
    FUN_000232a8(s_read_fail_count___d_000053d8,uVar6);
    if (bVar1) {
      FUN_0000d450(0,0);
      bVar4 = 0;
      do {
        FUN_0001cd4c(&DAT_0000591c);
        FUN_000232a8(&DAT_0000591c);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 5);
    }
    else {
      FUN_0000d450(0xd,0);
      bVar4 = 0;
      do {
        FUN_0001cd4c(&DAT_00005964);
        FUN_000232a8(&DAT_00005964);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 5);
    }
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
  FUN_0001cd4c(s_all_count___d_00005924,iVar5);
  FUN_0001cd4c(s_card_found_count___d_00005934,uVar3);
  FUN_0001cd4c(s_read_pass_count___d_0000594c,iVar7);
  FUN_0001cd4c(s_read_fail_count___d_000053d8,uVar6);
  FUN_0001cd4c(s______________________FINISH_TEST_00004f44 + 0x20);
  goto LAB_00005676;
}




void FUN_00005776(void)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  undefined4 in_r3;
  undefined4 unaff_r4;
  uint uVar4;
  uint uVar5;
  undefined4 in_lr;
  
  uVar4 = 0;
  uVar5 = uVar4;
LAB_00005786:
  uVar5 = uVar5 & 0xff;
  FUN_0000d47a(uVar5,uVar4 < 4,1);
  FUN_000175d2(200);
  if (uVar4 < 4) {
    iVar2 = FUN_0000b590(uVar4);
    if (iVar2 != 0) {
      FUN_0001cd4c(s_________ERROR_________00004933 + 1);
      FUN_000232a8(s_________ERROR_________00004933 + 1);
      FUN_0001cd4c(s_RED_d_CTL_0000596c,uVar4 + 1);
      pcVar3 = s_RED_d_CTL_0000596c;
      uVar5 = uVar4;
LAB_000057f6:
      FUN_000232a8(pcVar3,uVar5 + 1);
      FUN_0001cd4c(s_LIMIT__d_00005984,uVar4 + 1);
      FUN_000232a8(s_LIMIT__d_00005984,uVar4 + 1);
    }
  }
  else {
    iVar2 = FUN_0000b590(0xb - uVar4 & 0xff);
    if (iVar2 != 0) {
      FUN_0001cd4c(s_________ERROR_________00004933 + 1);
      FUN_000232a8(s_________ERROR_________00004933 + 1);
      FUN_0001cd4c(s_BLUE_d_CTL_00005978,uVar5 + 1);
      pcVar3 = s_BLUE_d_CTL_00005978;
      goto LAB_000057f6;
    }
  }
  uVar4 = uVar4 + 1 & 0xff;
  if (uVar4 < 8) {
    uVar5 = uVar4;
    if (3 < uVar4) {
      uVar5 = uVar4 - 4;
    }
    goto LAB_00005786;
  }
  FUN_00015b9c(0x38,0);
  bVar1 = FUN_00015bec(0x38);
  uVar5 = (uint)bVar1;
  bVar1 = FUN_00015bec(0x39);
  if (uVar5 == bVar1) {
    FUN_00015bc4(0x38,uVar5 == 0);
    FUN_000175d2(200);
    uVar4 = FUN_00015bec(0x39);
    if (uVar4 != uVar5) goto LAB_00005872;
  }
  FUN_0001cd4c(s_________ERROR_________00004933 + 1);
  FUN_000232a8(s_________ERROR_________00004933 + 1);
  FUN_0001cd4c(s_BUF_LIMIT_1__PD8_00005990);
  FUN_000232a8(s_BUF_LIMIT_1__PD8_00005990);
  FUN_0001cd4c(s_BUF_LIMIT_2__PD9_000059a4);
  FUN_000232a8(s_BUF_LIMIT_2__PD9_000059a4);
LAB_00005872:
  bVar1 = 0;
  do {
    FUN_0000d47a(bVar1,0,0,in_r3,unaff_r4,in_lr);
    FUN_0000d47a(bVar1,1,0);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000059b8(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  undefined4 uVar7;
  float fVar8;
  int iVar9;
  undefined4 local_30;
  
  fVar1 = DAT_00005dc0;
  bVar6 = 0;
  local_30 = 0;
LAB_000059d8:
  uVar7 = 0;
  do {
    bVar4 = 0;
    do {
      FUN_00009ffc(bVar4,uVar7,0xff);
      bVar4 = bVar4 + 1;
    } while (bVar4 < 4);
    FUN_0001eb00(500);
    iVar2 = DAT_00005dc4;
    uVar5 = 0;
    do {
      fVar8 = (float)FUN_0000ca4c((int)(char)uVar5);
      iVar9 = (int)(fVar8 * fVar1);
      iVar3 = iVar9;
      if (iVar9 < 0) {
        iVar3 = -iVar9;
      }
      FUN_0001cd4c(DAT_00005dc8,uVar5,(int)fVar8,iVar3 % 1000);
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      FUN_000232a8(DAT_00005dc8,uVar5,(int)fVar8,iVar9 % 1000);
      if (((*(char *)(iVar2 + uVar5 + 9) != '\0') || ((int)fVar8 < _DAT_00005dcc)) &&
         (*(char *)((int)&local_30 + uVar5) == '\0')) {
        *(undefined *)((int)&local_30 + uVar5) = 1;
        FUN_0001cd4c(DAT_00005dc8 + 0x1c);
        FUN_000232a8(DAT_00005dc8 + 0x1c);
        if (uVar5 == 0) {
          FUN_0001cd4c(DAT_00005dc8 + 0x34);
          FUN_000232a8(DAT_00005dc8 + 0x34);
          FUN_0001cd4c(DAT_00005dc8 + 0x48);
          FUN_000232a8(DAT_00005dc8 + 0x48);
          FUN_0001cd4c(DAT_00005dc8 + 0x58);
          iVar3 = DAT_00005dc8 + 0x58;
        }
        else if (uVar5 == 1) {
          FUN_0001cd4c(DAT_00005dc8 + 0x68);
          FUN_000232a8(DAT_00005dc8 + 0x68);
          FUN_0001cd4c(DAT_00005dc8 + 0x7c);
          FUN_000232a8(DAT_00005dc8 + 0x7c);
          FUN_0001cd4c(DAT_00005dc8 + 0x8c);
          iVar3 = DAT_00005dc8 + 0x8c;
        }
        else if (uVar5 == 2) {
          FUN_0001cd4c(DAT_00005dc8 + 0x9c);
          FUN_000232a8(DAT_00005dc8 + 0x9c);
          FUN_0001cd4c(DAT_00005dc8 + 0xb0);
          FUN_000232a8(DAT_00005dc8 + 0xb0);
          FUN_0001cd4c(DAT_00005dc8 + 0xc0);
          iVar3 = DAT_00005dc8 + 0xc0;
        }
        else {
          if (uVar5 != 3) goto LAB_00005b44;
          FUN_0001cd4c(DAT_00005dc8 + 0xd0);
          FUN_000232a8(DAT_00005dc8 + 0xd0);
          FUN_0001cd4c(DAT_00005dc8 + 0xe4);
          FUN_000232a8(DAT_00005dc8 + 0xe4);
          FUN_0001cd4c(DAT_00005dc8 + 0xf4);
          iVar3 = DAT_00005dc8 + 0xf4;
        }
        FUN_000232a8(iVar3);
      }
LAB_00005b44:
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 4);
    FUN_0001cd4c(s_current_channel____d_00005883 + 0x15);
    FUN_000232a8(s_current_channel____d_00005883 + 0x15);
    bVar6 = bVar6 + 1;
    if (1 < bVar6) {
      FUN_0000a07e();
      return;
    }
    if (bVar6 == 0) goto LAB_000059d8;
    uVar7 = 1;
  } while( true );
}




void FUN_00005b74(void)

{
  char *pcVar1;
  int iVar2;
  byte bVar3;
  
  FUN_0001cd4c(s_<__________________MOTHER_BOARD_t_00005dcf + 1);
  FUN_000232a8(s_<__________________MOTHER_BOARD_t_00005dcf + 1);
  pcVar1 = DAT_00005dc4;
  if (*DAT_00005dc4 != '\0') {
    FUN_0001cd4c(DAT_00005dc8 + 0x1c);
    FUN_000232a8(DAT_00005dc8 + 0x1c);
    FUN_0001cd4c(s_EEPROM_SCL_PE5_00004d5f + 1);
    FUN_000232a8(s_EEPROM_SCL_PE5_00004d5f + 1);
    FUN_0001cd4c(s_EEPROM_SDA_PE6_00004d70);
    FUN_000232a8(s_EEPROM_SDA_PE6_00004d70);
  }
  if (pcVar1[4] != '\0') {
    FUN_0001cd4c(DAT_00005dc8 + 0x1c);
    FUN_000232a8(DAT_00005dc8 + 0x1c);
    FUN_0001cd4c(s_SCL2_PB8_00005e08);
    FUN_000232a8(s_SCL2_PB8_00005e08);
    FUN_0001cd4c(s_SDA2_PB9_00005e14);
    FUN_000232a8(s_SDA2_PB9_00005e14);
  }
  if (pcVar1[5] != '\0') {
    FUN_0001cd4c(DAT_00005dc8 + 0x1c);
    FUN_000232a8(DAT_00005dc8 + 0x1c);
    FUN_0001cd4c(s_SCL1_PB10_00005e20);
    FUN_000232a8(s_SCL1_PB10_00005e20);
    FUN_0001cd4c(s_SDA1_PB11_00005e2c);
    FUN_000232a8(s_SDA1_PB11_00005e2c);
  }
  FUN_000059b8();
  FUN_0001cd4c(s_Look_at_the_BLDC_00004da4);
  FUN_000232a8(s_Look_at_the_BLDC_00004da4);
  bVar3 = 0;
  do {
    iVar2 = FUN_0000e13a(bVar3,1000);
    if (iVar2 != 0) {
      FUN_0001cd4c(DAT_00005dc8 + 0x1c);
      FUN_000232a8(DAT_00005dc8 + 0x1c);
      FUN_0001cd4c(s_FG1_PE11_00004db8);
      FUN_000232a8(s_FG1_PE11_00004db8);
      FUN_0001cd4c(s_PWM_PE13_00004dc4);
      FUN_000232a8(s_PWM_PE13_00004dc4);
    }
    iVar2 = FUN_0000e164();
    if (iVar2 != 0) {
      FUN_0001cd4c(DAT_00005dc8 + 0x1c);
      FUN_000232a8(DAT_00005dc8 + 0x1c);
      FUN_0001cd4c(s_BRAK_PE4_00004dd0);
      FUN_000232a8(s_BRAK_PE4_00004dd0);
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 2);
  FUN_0000df64();
  FUN_00005776();
  if (pcVar1[1] != '\0') {
    FUN_0001cd4c(DAT_00005dc8 + 0x1c);
    FUN_000232a8(DAT_00005dc8 + 0x1c);
    FUN_0001cd4c(s_AHT30_SCL_3V_PC11_00004e4c);
    FUN_000232a8(s_AHT30_SCL_3V_PC11_00004e4c);
    FUN_0001cd4c(s_AHT30_SDA_3V_PC12_00004e60);
    FUN_000232a8(s_AHT30_SDA_3V_PC12_00004e60);
  }
  if (pcVar1[2] != '\0') {
    FUN_0001cd4c(DAT_00005dc8 + 0x1c);
    FUN_000232a8(DAT_00005dc8 + 0x1c);
    FUN_0001cd4c(s_SPI_CS_PB12_00004ea4);
    FUN_000232a8(s_SPI_CS_PB12_00004ea4);
    FUN_0001cd4c(s_SPI_CK_PB13_00004eb4);
    FUN_000232a8(s_SPI_CK_PB13_00004eb4);
    FUN_0001cd4c(s_SPI_MISO_PB14_00004ec4);
    FUN_000232a8(s_SPI_MISO_PB14_00004ec4);
    FUN_0001cd4c(s_SPI_MOSI_PB15_00004ed4);
    FUN_000232a8(s_SPI_MOSI_PB15_00004ed4);
  }
  FUN_0001cd4c(s______________________FINISH_TEST_00004f44);
  FUN_000232a8(s______________________FINISH_TEST_00004f44);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005d40(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_8;
  
  iVar1 = _DAT_00005e38;
  local_8 = 0;
  uVar4 = param_1;
  do {
    while (param_2 < uVar4) {
      FUN_0001eb00(2);
      uVar4 = param_1;
    }
    if ((*(char *)((int)&local_8 + uVar4) != '\0') &&
       (iVar2 = FUN_00003eb8(uVar4,0,0x14), iVar2 != 0)) {
      *(undefined *)((int)&local_8 + uVar4) = 0;
      *(int *)(iVar1 + uVar4 * 4) = *(int *)(iVar1 + uVar4 * 4) + 1;
      iVar2 = FUN_0000c5ca();
      uVar3 = *(undefined4 *)(iVar1 + uVar4 * 4);
      if (iVar2 == 0) {
        FUN_0001cd4c(s_slot_d_trigger_success__d_00005e3b + 1,uVar4 + 1,uVar3);
      }
      else {
        FUN_0001cd4c(s_slot_d_trigger_success__d_00005e3b + 1,uVar4 + 1,uVar3);
        FUN_000232a8(s_slot_d_trigger_success__d_00005e3b + 1,uVar4 + 1,
                     *(undefined4 *)(iVar1 + uVar4 * 4));
      }
    }
    iVar2 = FUN_00003e56(uVar4,0,0x14);
    if (iVar2 != 0) {
      *(undefined *)((int)&local_8 + uVar4) = 1;
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while( true );
}




/* WARNING: Removing unreachable block (ram,0x00005ebe) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005e58(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_2c;
  
  iVar10 = 0;
  iVar11 = 0;
  iVar8 = 0;
  iVar9 = 0;
  iVar7 = 0;
  bVar1 = false;
  local_2c = 0;
  iVar2 = FUN_0000e44e();
  iVar4 = iVar2;
  do {
    while( true ) {
      while( true ) {
        do {
          iVar6 = iVar2;
          FUN_0001eb00(10);
          iVar3 = FUN_0000e44e();
          iVar2 = iVar6;
        } while (iVar3 == iVar6);
        iVar5 = iVar7;
        if ((iVar7 == 0) && (!bVar1)) {
          iVar10 = FUN_0001a1aa();
        }
        iVar2 = _DAT_000062a4;
        if (iVar3 != 1) break;
        *(int *)(_DAT_000062a4 + 0x14) = *(int *)(_DAT_000062a4 + 0x14) + 1;
        if ((iVar4 == 2) || (!bVar1)) {
          iVar8 = FUN_0001a1aa();
          iVar8 = iVar8 - iVar10;
          local_2c = iVar8 - iVar11;
        }
        else {
          iVar4 = FUN_0001a1aa();
          local_2c = (iVar4 - iVar8) - iVar10;
          iVar8 = FUN_0001a1aa();
          iVar8 = iVar8 - iVar10;
        }
        FUN_0001cd4c(s_free_count__d__full_count__d__to_000062c8,*(undefined4 *)(iVar2 + 0x10),
                     *(undefined4 *)(iVar2 + 0x14),local_2c,iVar9);
        bVar1 = true;
        iVar2 = 1;
        iVar4 = iVar6;
      }
      if (iVar3 != 2) break;
      *(int *)(_DAT_000062a4 + 0x10) = *(int *)(_DAT_000062a4 + 0x10) + 1;
      if ((iVar4 == 1) || (iVar5 == 0)) {
        iVar11 = FUN_0001a1aa();
        iVar11 = iVar11 - iVar10;
        iVar9 = iVar11 - iVar8;
      }
      else {
        iVar2 = FUN_0001a1aa();
        iVar9 = (iVar2 - iVar11) - iVar10;
        iVar11 = FUN_0001a1aa();
        iVar11 = iVar11 - iVar10;
      }
      iVar2 = _DAT_000062a4;
      iVar5 = *(int *)(_DAT_000062a4 + 0x10) - *(int *)(_DAT_000062a4 + 0x14);
      iVar4 = *(int *)(_DAT_000062a4 + 0x18);
      iVar7 = *(int *)(_DAT_000062a4 + 0x1c);
      if (iVar5 < iVar4 - iVar7) {
        iVar7 = iVar7 + 1;
        *(int *)(_DAT_000062a4 + 0x1c) = iVar7;
      }
      else if (iVar4 - iVar7 < iVar5) {
        iVar4 = iVar4 + 1;
        *(int *)(_DAT_000062a4 + 0x18) = iVar4;
      }
      FUN_0001cd4c(s_error_full__d__error_empty__d_000062a7 + 1,iVar4,iVar7);
      FUN_0001cd4c(s_free_count__d__full_count__d__to_000062c8,*(undefined4 *)(iVar2 + 0x10),
                   *(undefined4 *)(iVar2 + 0x14),local_2c,iVar9);
      iVar7 = 1;
      iVar2 = iVar3;
      iVar4 = iVar6;
    }
    iVar2 = iVar3;
    iVar4 = iVar6;
  } while (iVar3 != 3);
  FUN_0001cd4c(s_buffer_error_please_check_connec_00006274,iVar5,local_2c,0);
  return;
}




void FUN_00005f8c(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_0000df30(1);
  }
  else {
    FUN_0000df4a();
  }
  while (iVar1 = FUN_0000e44e(), iVar1 != 0) {
    FUN_0001eb00(1);
  }
  FUN_0000df64();
  FUN_0001eb00(2000);
  return;
}




void FUN_00005fc0(int param_1)

{
  ushort uVar1;
  
  if (param_1 == 0) {
    FUN_0000df30(0xff);
  }
  else {
    FUN_0000df4a();
  }
  FUN_0001eb00(0x17d4);
  uVar1 = 0;
  do {
    if (param_1 == 0) {
      FUN_0000df30(uVar1 * -5 + 0xff);
    }
    else {
      FUN_0000df4a();
    }
    FUN_0001eb00(0x14);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x28);
  FUN_0000df64();
  FUN_0001eb00(1000);
  return;
}




void FUN_0000601a(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = 0;
  iVar5 = 0;
  iVar4 = 0;
  while (iVar1 = FUN_0000e44e(), iVar1 == 3) {
    FUN_0001cd4c(s_buffer_component_error___00006304);
    FUN_0001eb00(2000);
  }
  iVar1 = FUN_0000e44e();
  if ((iVar1 != 0) && (iVar1 != 1)) goto LAB_000060a2;
  do {
    iVar1 = FUN_0001a1aa();
    FUN_00005fc0(0);
    iVar2 = FUN_0001a1aa();
    FUN_0001cd4c(s_dir___out__up__time____d_ms__cou_00006320,iVar2 - iVar1,uVar3);
    iVar1 = FUN_0001a1aa();
    FUN_00005f8c(1,iVar4);
    iVar4 = FUN_0001a1aa();
    iVar4 = iVar4 - iVar1;
    FUN_0001cd4c(s_dir___back__up__time____d_ms__co_0000634c,iVar4,uVar3);
    FUN_0001eb00(0x5dc);
    iVar1 = FUN_0001a1aa();
    FUN_00005fc0(1);
    iVar2 = FUN_0001a1aa();
    FUN_0001cd4c(s_dir___out__down__time____d_ms__c_00006378,iVar2 - iVar1,uVar3);
LAB_000060a2:
    iVar1 = FUN_0001a1aa();
    FUN_00005f8c(0,iVar5);
    iVar5 = FUN_0001a1aa();
    iVar5 = iVar5 - iVar1;
    FUN_0001cd4c(s_dir___out__down__time____d_ms_000063a4);
    FUN_0001eb00(0x5dc);
    uVar3 = uVar3 + 1;
    FUN_0001cd4c(s______________________________000063c4);
    FUN_0001cd4c(s_BLDC_gravity_aging_mode_count_____000063e4,uVar3);
    FUN_0001cd4c(s______________________________000063c4);
  } while (uVar3 < param_1);
  do {
    FUN_0001cd4c(s_BLDC_aging_test_finished__count___00006408,uVar3);
    FUN_0001eb00(3000);
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000060f2(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  
  bVar2 = false;
  fVar7 = DAT_00006430;
  do {
    uVar4 = 0xffffffff;
    uVar5 = 0;
    do {
      uVar4 = (uint)(char)((char)uVar4 + '\x01');
      uVar5 = uVar5 + 1;
      if (3 < (int)uVar4) {
        uVar4 = 0;
      }
      iVar3 = FUN_0000b5a0(uVar4 & 0xff);
      FUN_0001eb00(1);
      if (9999 < uVar5) {
        uVar5 = 0;
        bVar2 = true;
        FUN_0000df4a(0xff);
      }
    } while (iVar3 != 0);
    if (bVar2) {
      do {
        FUN_0001eb00(0x14);
        fVar6 = (float)FUN_0000840a();
        bVar1 = fVar7 != fVar6;
        fVar7 = fVar6;
      } while (bVar1);
      FUN_0000df64();
    }
    FUN_0001cd4c(s_filament_in_channel_d_00006434,uVar4 & 0xff);
    FUN_0000df30(0xff);
    do {
      iVar3 = FUN_0000b5a0(uVar4 & 0xff);
      FUN_0001eb00(1);
    } while (iVar3 == 0);
    FUN_0001cd4c(s_out_ok_0000644c);
    FUN_00008598();
    FUN_0000df4a(0xff);
    iVar3 = _DAT_000062a4;
    do {
      FUN_0001eb00(0x14);
      fVar7 = (float)FUN_0000840a();
    } while (fVar7 + 30.0 <= *(float *)(iVar3 + 0xc));
    FUN_0001cd4c(s_back_ok_00006454);
    FUN_0000df64();
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000061bc(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = DAT_00006430;
  uVar3 = 0xffffffff;
  do {
    uVar3 = (uint)(char)((char)uVar3 + '\x01');
    if (3 < (int)uVar3) {
      uVar3 = 0;
    }
    FUN_0001eb00(1);
    iVar2 = FUN_0000b5a0(uVar3 & 0xff);
  } while (iVar2 != 0);
  FUN_0000df30(0xff);
  do {
    FUN_0001eb00(1);
    iVar2 = FUN_0000b5a0(uVar3 & 0xff);
  } while (iVar2 == 0);
  FUN_0000df64();
  FUN_00008598();
  FUN_0000df4a(0xff);
  do {
    FUN_0001eb00(0x14);
    fVar4 = (float)FUN_0000840a();
    bVar1 = fVar5 != fVar4;
    fVar5 = fVar4;
  } while (bVar1);
  FUN_0000df64();
  *(float *)(_DAT_000062a4 + 0xc) = fVar4;
  return;
}




void FUN_00006234(void)

{
  byte bVar1;
  
  *(undefined *)(DAT_00006460 + 6) = 0;
  do {
    bVar1 = 0;
    do {
      FUN_00009ffc(bVar1,0,0xff);
      FUN_0000df30(0xff);
      FUN_0001eb00(6000);
      FUN_0000df64();
      FUN_0000a094();
      FUN_0001eb00(100);
      FUN_00009ffc(bVar1,1,0xff);
      FUN_0000df4a(0xff);
      FUN_0001eb00(6000);
      FUN_0000df64();
      FUN_0000a07e();
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000064a4(void)

{
  FUN_0001e48a(_DAT_00006684 + -0x8c,s_RFID_authentication_00006687 + 1,&LAB_00006482_1,0,
               _DAT_00006684,0x800,8,10);
  FUN_0001e54c(_DAT_00006684 + -0x8c);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000064ce(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(char *)(_DAT_0000669c + 7) = (char)param_1;
  if (param_1 == 0) {
    FUN_0001cd4c(s_switch_standard_mode__000066b0);
    return 0;
  }
  FUN_0001cd4c(s_switch_mode__d_0000669f + 1,param_1);
  FUN_00003f6a();
  switch(param_1) {
  case 1:
    FUN_0000f8b0(99,0,3);
    break;
  case 2:
    FUN_00006cc8(99);
    break;
  default:
    FUN_0001cd4c(s_Cillegal_mode__000066cb + 1);
    return 1;
  case 6:
    FUN_000064a4();
    break;
  case 7:
    FUN_00006234();
  case 0xb:
    FUN_00006cc8();
  case 0xc:
    FUN_000061bc();
    FUN_000060f2();
  case 0xd:
    FUN_0000601a(0x1194);
  case 0xe:
    FUN_00005e58();
    break;
  case 0xf:
    FUN_00005d40(0,3);
  case 0x10:
    FUN_00005b74();
    break;
  case 0x11:
    FUN_0000563c();
  case 0x12:
    FUN_000055ca();
  case 0x13:
    FUN_000054d0(_DAT_000066c8);
    break;
  case 0x14:
    FUN_00005494();
  case 0x15:
    FUN_00005468();
  case 0x16:
    uVar3 = 0;
    goto LAB_0000658a;
  case 0x17:
    uVar3 = 0;
    goto LAB_00006592;
  case 0x18:
    uVar3 = 1;
    goto LAB_0000658a;
  case 0x19:
    uVar3 = 1;
    goto LAB_00006592;
  case 0x1a:
    uVar3 = 2;
LAB_0000658a:
    uVar2 = 0;
    uVar1 = 0;
LAB_00006596:
    FUN_00005392(uVar1,uVar2,uVar3);
    break;
  case 0x1b:
    uVar3 = 2;
LAB_00006592:
    uVar2 = 1;
    uVar1 = 1;
    goto LAB_00006596;
  case 0x1c:
    FUN_00005386();
  case 0x1d:
    FUN_0000537a();
  case 0x1e:
    FUN_000052f4(0);
  case 0x1f:
    FUN_0000529a();
  case 0x20:
    FUN_000051ca();
    break;
  case 0x21:
    FUN_000051ac();
  case 0x25:
    FUN_00003f4a();
    FUN_00006d30();
    break;
  case 0x22:
    FUN_00004c16();
  case 0x23:
    FUN_00004b90();
  case 0x24:
    FUN_0000f91a(99,0);
    break;
  case 0x26:
    FUN_00004a32(25000);
  }
  return 0;
}




void FUN_000065f2(int param_1,int param_2)

{
  undefined uVar1;
  
  if (param_1 != 2) {
    FUN_0001cd4c(s_switch_mode__mode__000066dc);
    return;
  }
  uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 4));
  FUN_000064ce(uVar1);
  return;
}




undefined4 FUN_00006768(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0000a40c(*(undefined *)(DAT_00006b14 + param_1),
                       *(undefined *)(DAT_00006b14 + 4 + param_1));
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}




undefined4 FUN_00006782(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00009ffc(param_3,1,100);
  iVar1 = FUN_0001a1aa();
  iVar2 = FUN_0001a20e(param_4);
  do {
    iVar3 = FUN_0001a1aa();
    if (-1 < iVar3 - (iVar1 + iVar2)) {
      FUN_0000a052();
      return 0;
    }
    iVar3 = FUN_00006768(param_3);
  } while (iVar3 != param_2);
  FUN_00009ffc(param_3,0,0xff);
  FUN_0001eb00(0x14);
  FUN_0000a052(param_3);
  return 1;
}




int FUN_000067de(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((param_2 & 1) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = -1;
  }
  uVar3 = iVar1 + param_2 & 0xff;
  if (*(char *)(param_1 + param_2) != '\x05') {
    iVar1 = FUN_00006768(param_2);
    iVar1 = FUN_00006782(param_1,iVar1 == 0,param_2,6000);
    if (iVar1 == 0) {
      *(undefined *)(param_1 + param_2) = 3;
      return 3;
    }
    iVar1 = FUN_00006768(param_2);
    if (iVar1 == 0) {
      iVar1 = FUN_00006782(param_1,1,param_2,2000);
      if (iVar1 == 0) goto LAB_00006862;
    }
    else {
      iVar1 = FUN_00006782(param_1,0,param_2,2000);
      if (iVar1 != 0) goto LAB_00006862;
    }
    FUN_00009ffc(uVar3,1,100);
    FUN_0001eb00(800);
    FUN_0000a052(uVar3);
    *(undefined *)(param_1 + uVar3) = 5;
  }
LAB_00006862:
  iVar1 = FUN_00006768(param_2);
  if (iVar1 == 0) {
    FUN_00006782(param_1,1,param_2,6000);
  }
  iVar1 = FUN_00006d70(param_1,param_2,800);
  if (iVar1 != 0) {
    *(undefined *)(param_1 + param_2) = 4;
    uVar2 = FUN_0001a1aa();
    FUN_0001cd4c(s___d___s__ch___d_ready___00006b18,uVar2,DAT_00006b14 + 0x16,param_2);
    iVar1 = 1;
  }
  return iVar1;
}




undefined4 FUN_0000689e(int param_1)

{
  int iVar1;
  
  iVar1 = thunk_FUN_0000a474(*(undefined *)(DAT_00006b14 + param_1),
                             *(undefined *)(DAT_00006b14 + 4 + param_1),5);
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}




void FUN_000068ba(int param_1)

{
  FUN_0000af54(*(undefined *)(DAT_00006b14 + param_1),*(undefined *)(DAT_00006b14 + 4 + param_1));
  return;
}




void FUN_000068c8(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  if (param_1 < 0) {
    if (param_1 < -9) {
      param_1 = -9;
    }
    param_1 = -param_1;
    uVar1 = FUN_000071fe();
  }
  else {
    if (99 < param_1) {
      param_1 = param_1 % 100;
    }
    uVar1 = FUN_00007194(param_1 / 10 & 0xff);
  }
  uVar2 = FUN_00007194(param_1 % 10 & 0xff);
  FUN_00007174(2,uVar1,0);
  FUN_00007174(3,uVar2,0);
  return;
}




void FUN_00006936(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  if (param_1 < 0) {
    if (param_1 < -9) {
      param_1 = -9;
    }
    param_1 = -param_1;
    uVar1 = FUN_000071fe();
  }
  else {
    if (99 < param_1) {
      param_1 = param_1 % 100;
    }
    uVar1 = FUN_00007194(param_1 / 10 & 0xff);
  }
  uVar2 = FUN_00007194(param_1 % 10 & 0xff);
  FUN_00007174(0,uVar1);
  FUN_00007174(1,uVar2,0);
  return;
}




void FUN_000069a4(int param_1)

{
  int iVar1;
  undefined auStack_108 [256];
  
  FUN_00023966(auStack_108,0x100);
  iVar1 = FUN_0000c5ca();
  if (iVar1 == 0) {
    FUN_0001cd4c(s________________________________00006b34);
    FUN_0001d122(auStack_108,DAT_00006b54,*(undefined4 *)(param_1 + 4),
                 *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0xc),
                 *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x2c),
                 *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x20),
                 *(undefined4 *)(param_1 + 0x30));
    FUN_0001cd4c(auStack_108);
    FUN_0001cd4c(s________________________________00006b34);
  }
  else {
    FUN_0001cd4c(s________________________________00006b34);
    FUN_000232a8(s________________________________00006b34);
    FUN_0001d122(auStack_108,DAT_00006b54,*(undefined4 *)(param_1 + 4),
                 *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0xc),
                 *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x2c),
                 *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x20),
                 *(undefined4 *)(param_1 + 0x30));
    FUN_0001cd4c(auStack_108);
    FUN_000232a8(auStack_108);
    FUN_0001cd4c(s________________________________00006b34);
    FUN_000232a8(s________________________________00006b34);
  }
  return;
}




int FUN_00006a5e(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = FUN_0001a1aa();
  iVar2 = FUN_00006d9c(param_1,1,param_2,6000);
  if (iVar2 == 0) {
    iVar4 = FUN_0000c5ca();
    if (iVar4 == 0) {
      FUN_0001cd4c(s_try_to_move_into_reader_timeout_00006b58);
    }
    else {
      FUN_0001cd4c(s_try_to_move_into_reader_timeout_00006b58);
      FUN_000232a8(s_try_to_move_into_reader_timeout_00006b58);
    }
    iVar4 = 1;
  }
  else {
    iVar2 = FUN_0000689e(param_2);
    if (iVar2 == 0) {
      iVar4 = FUN_0000c5ca();
      if (iVar4 == 0) {
        FUN_0001cd4c(s_read_RFID_message_failed_00006b7c);
      }
      else {
        FUN_0001cd4c(s_read_RFID_message_failed_00006b7c);
        FUN_000232a8(s_read_RFID_message_failed_00006b7c);
      }
      iVar4 = 2;
    }
    FUN_000068ba(param_2);
    iVar2 = FUN_0001a1aa();
    iVar3 = FUN_00006782(param_1,0,param_2,2000);
    if (iVar3 == 0) {
      iVar3 = FUN_0000c5ca();
      if (iVar3 == 0) {
        FUN_0001cd4c(s_try_to_move_out_reader_timeout_00006b98);
      }
      else {
        FUN_0001cd4c(s_try_to_move_out_reader_timeout_00006b98);
        FUN_000232a8(s_try_to_move_out_reader_timeout_00006b98);
      }
    }
    iVar3 = FUN_0001a1aa();
    iVar3 = iVar3 - iVar2;
    if (iVar4 == 0) {
      iVar2 = FUN_0001a1aa();
      iVar2 = iVar2 - iVar1;
    }
    else {
      iVar2 = 0;
    }
    iVar1 = FUN_0000c5ca();
    if (iVar1 == 0) {
      FUN_0001cd4c(s_ch____d__in_reader_area_time_____00006eec,param_2,iVar3,iVar2);
    }
    else {
      FUN_0001cd4c(s_ch____d__in_reader_area_time_____00006eec,param_2,iVar3,iVar2);
      FUN_000232a8(s_ch____d__in_reader_area_time_____00006eec,param_2,iVar3,iVar2);
    }
    FUN_00006d70(param_1,param_2,0xfa);
  }
  return iVar4;
}




void FUN_00006be8(void)

{
  FUN_0000b23a(0);
  FUN_0000b23a(1);
  FUN_00006e14(0);
  FUN_000068c8(0);
  FUN_00006936(0);
  return;
}




void FUN_00006c0c(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  
  *(undefined *)(param_1 + 0x34) = 1;
  uVar3 = 0;
  do {
    bVar4 = 0;
    do {
      iVar2 = FUN_00006a5e(param_1,uVar3);
      bVar1 = true;
      if (iVar2 == 0) goto LAB_00006c38;
      bVar4 = bVar4 + 1;
    } while (bVar4 < 2);
    bVar1 = false;
LAB_00006c38:
    iVar2 = param_1 + uVar3 * 4;
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
    if (bVar1) {
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
    }
    else {
      *(int *)(iVar2 + 0x24) = *(int *)(iVar2 + 0x24) + 1;
    }
    bVar4 = (char)uVar3 + 1;
    FUN_00006e14(bVar4,0);
    FUN_000068c8(*(uint *)(iVar2 + 0x14) % 100);
    FUN_00006936(*(uint *)(iVar2 + 0x24) % 100);
    uVar3 = (uint)bVar4;
    if (3 < uVar3) {
      FUN_000069a4(param_1);
      if (param_2 <= *(uint *)(param_1 + 0x10)) {
        uVar3 = 0;
        do {
          iVar2 = uVar3 * 4;
          uVar3 = uVar3 + 1 & 0xff;
          *(byte *)(param_1 + 0x34) =
               *(byte *)(param_1 + 0x34) & *(uint *)(param_1 + iVar2 + 0x24) < 3;
        } while (uVar3 < 4);
        do {
          FUN_00006e2a();
          FUN_00006e7e(param_1);
        } while( true );
      }
      return;
    }
  } while( true );
}




void FUN_00006cc8(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  FUN_00006be8();
  iVar2 = DAT_00006f28;
  do {
    uVar5 = 0;
    do {
      if (*(char *)(iVar2 + uVar5) != '\x04') {
        FUN_000067de(iVar2,uVar5);
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 4);
    bVar1 = true;
    uVar5 = 0;
    do {
      if ((*(char *)(iVar2 + uVar5) == '\x04') || (*(char *)(iVar2 + uVar5) == '\x03')) {
        bVar4 = 1;
      }
      else {
        bVar4 = 0;
      }
      bVar1 = (bool)(bVar1 & bVar4);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 4);
  } while (!bVar1);
  do {
    FUN_00006c0c(DAT_00006f28,param_1);
    iVar2 = DAT_00006f28;
    bVar4 = 0;
    do {
      iVar3 = FUN_00006768(bVar4);
      if (iVar3 != 0) {
        FUN_000067de(iVar2,bVar4);
      }
      bVar4 = bVar4 + 1;
    } while (bVar4 < 4);
  } while( true );
}




void FUN_00006d30(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  FUN_000021d4();
  puVar1 = DAT_00006f2c;
  *DAT_00006f2c = 1;
  while (((uVar2 = FUN_0000ae38(), 3 < uVar2 || (iVar3 = FUN_0000b5b2(), iVar3 != 0)) ||
         (iVar3 = FUN_00001326(uVar2), iVar3 != 0))) {
    FUN_0001eb00(0x14);
  }
  *DAT_00006f30 = (char)uVar2;
  FUN_0000be18(0);
  *puVar1 = 1;
  do {
    FUN_0001eb00(0x14);
  } while( true );
}




undefined4 FUN_00006d70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  FUN_00009ffc(param_2,1,100);
  FUN_0001eb00(param_3);
  FUN_0000a052(param_2);
  iVar1 = FUN_00006768(param_2);
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}




undefined4 FUN_00006d9c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_00009ffc(param_3,1,100);
  iVar1 = FUN_0001a1aa();
  iVar2 = FUN_0001a20e(param_4);
  iVar3 = FUN_0001a1aa();
  while( true ) {
    do {
      iVar4 = FUN_0001a1aa();
      if (-1 < iVar4 - (iVar1 + iVar2)) {
        FUN_0000a052();
        return 0;
      }
      iVar4 = FUN_00006768(param_3);
    } while (iVar4 != param_2);
    FUN_0000a052(param_3);
    FUN_0001eb00(10);
    iVar4 = FUN_00006768(param_3);
    if (iVar4 == param_2) break;
    FUN_00009ffc(param_3,1,100);
  }
  iVar1 = FUN_0001a1aa();
  FUN_0001cd4c(s__s_use_tick__d_00006f38,DAT_00006f34,iVar1 - iVar3);
  return 1;
}




void FUN_00006e14(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00007194();
  FUN_00007174(4,uVar1,param_2);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00006e2a(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  uint in_r3;
  uint local_10;
  
  local_10 = in_r3;
  iVar3 = FUN_0001a1aa();
  pbVar2 = _DAT_00006f48;
  if (0x32 < (uint)(iVar3 - *(int *)(_DAT_00006f48 + 4))) {
    uVar4 = FUN_0001a1aa();
    *(undefined4 *)(pbVar2 + 4) = uVar4;
    iVar3 = FUN_0000e44e();
    if (iVar3 == 1) {
      bVar1 = *pbVar2;
      *pbVar2 = bVar1 + 1;
      if (0x3b < (byte)(bVar1 + 1)) {
        FUN_0001cd4c(s_switch_to_STANDARD_MODE_00006f4b + 1);
        local_10 = local_10 & 0xffffff00;
        FUN_0000ea8c(6,&local_10,1);
        FUN_0000eac8();
        FUN_0001eb00(10);
        FUN_00013060();
        return;
      }
    }
    else {
      *pbVar2 = 0;
    }
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00006e7e(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_0001a1aa();
  iVar1 = _DAT_00006f48;
  if (2000 < (uint)(iVar3 - *(int *)(_DAT_00006f48 + 8))) {
    uVar4 = FUN_0001a1aa();
    *(undefined4 *)(iVar1 + 8) = uVar4;
    bVar2 = *(char *)(iVar1 + 1) + 1;
    *(byte *)(iVar1 + 1) = bVar2;
    if (3 < bVar2) {
      bVar2 = 0;
      *(undefined *)(iVar1 + 1) = 0;
    }
    FUN_00006e14(bVar2 + 1,*(undefined *)(param_1 + 0x34));
    FUN_000068c8(*(uint *)(param_1 + (uint)*(byte *)(iVar1 + 1) * 4 + 0x14) % 100);
    FUN_00006936(*(uint *)(param_1 + (uint)*(byte *)(iVar1 + 1) * 4 + 0x24) % 100);
    FUN_000069a4(param_1);
    return;
  }
  return;
}




void FUN_00006fbe(uint param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    FUN_00015bc4(0x24,(int)(param_1 << 0x18) < 0);
    param_1 = (param_1 << 0x19) >> 0x18;
    FUN_00015bc4(0x23,0);
    FUN_000175d2(3);
    FUN_00015bc4(0x23,1);
  }
  return;
}




void FUN_00006ffc(uint param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    FUN_00015bc4(0x24,(param_1 & 1) != 0);
    param_1 = param_1 >> 1;
    FUN_00015bc4(0x23,0);
    FUN_000175d2(3);
    FUN_00015bc4(0x23,1);
  }
  return;
}




void FUN_00007038(int param_1,undefined4 param_2)

{
  FUN_00015bc4(0x21,0);
  FUN_00006fbe(0xa0,3);
  FUN_00006fbe((uint)(param_1 << 0x1a) >> 0x18,6);
  FUN_00006ffc(param_2,0x10);
  FUN_00015bc4(0x21,1);
  return;
}




void FUN_0000706c(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  FUN_00015bc4(0x21,0);
  FUN_00006fbe(0xa0,3);
  FUN_00006fbe((uint)(param_1 << 0x1a) >> 0x18,6);
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    FUN_00006ffc(*(undefined2 *)(param_2 + uVar1 * 2),0x10);
  }
  FUN_00015bc4(0x21,1);
  return;
}




void FUN_000070b2(undefined4 param_1)

{
  FUN_00015bc4(0x21,0);
  FUN_00006fbe(0x80,4);
  FUN_00006fbe(param_1,8);
  FUN_00015bc4(0x21,1);
  return;
}




uint FUN_000070da(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    FUN_00015bc4(0x22,0);
    FUN_000175d2(3);
    iVar1 = FUN_00015bec(0x24);
    uVar3 = iVar1 << uVar2 & 0xffU | uVar3;
    FUN_00015bc4(0x22,1);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 8);
  return uVar3;
}




void FUN_0000710e(int param_1,int param_2,uint param_3)

{
  undefined uVar1;
  uint uVar2;
  
  FUN_00015b9c(0x24,2);
  FUN_00015bc4(0x21,0);
  FUN_00006fbe(0xc0,3);
  FUN_00006fbe((uint)(param_1 << 0x1a) >> 0x18,6);
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = FUN_000070da();
    *(undefined *)(param_2 + uVar2) = uVar1;
  }
  FUN_00015bc4(0x21,1);
  FUN_00015b9c(0x24,0);
  return;
}




void FUN_0000715e(int param_1)

{
  FUN_00015bc4(0x10,param_1 == 1);
  return;
}




void FUN_00007174(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 local_c;
  int iStack_8;
  
  local_c._0_2_ = (ushort)param_2;
  if (param_3 == 1) {
    local_c._0_2_ = (ushort)local_c | 0x2000;
  }
  iStack_8 = param_3;
  FUN_0000706c((uint)(param_1 << 0x1a) >> 0x18,&local_c,1,param_4,param_1);
  return;
}




undefined2 FUN_00007194(uint param_1)

{
  if (9 < param_1) {
    param_1 = param_1 % 10;
  }
  return *(undefined2 *)(DAT_0000753c + param_1 * 2);
}




void FUN_000071aa(uint param_1)

{
  undefined4 uVar1;
  
  if (4 < param_1) {
    param_1 = 0;
  }
  uVar1 = FUN_00007194(param_1);
  FUN_00007174(4,uVar1,1);
  return;
}




void FUN_000071c2(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (99 < param_1) {
    param_1 = 99;
  }
  uVar1 = FUN_00007194(param_1 / 10);
  uVar2 = FUN_00007194(param_1 % 10);
  FUN_00007174(0,uVar1,1);
  FUN_00007174(1,uVar2);
  return;
}




undefined4 FUN_000071fe(void)

{
  return 0x10;
}




void FUN_00007202(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 < 0) {
    if (param_1 < -9) {
      param_1 = -9;
    }
    uVar4 = -param_1 % 10 & 0xff;
    uVar1 = 0x10;
  }
  else {
    if (99 < param_1) {
      param_1 = 99;
    }
    uVar3 = param_1 / 10 & 0xff;
    uVar4 = param_1 % 10 & 0xff;
    uVar1 = FUN_00007194(uVar3,10,uVar3,uVar4);
  }
  uVar2 = FUN_00007194(uVar4);
  FUN_00007174(2,uVar1,1);
  FUN_00007174(3,uVar2,1);
  return;
}




undefined2 FUN_00007304(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 0x41) {
    uVar1 = 0;
  }
  else if (param_1 < 0x5b) {
    uVar1 = param_1 - 0x41 & 0xff;
  }
  else {
    uVar1 = 0x19;
  }
  return *(undefined2 *)(DAT_0000753c + 0x14 + uVar1 * 2);
}




void FUN_0000733a(void)

{
  byte bVar1;
  undefined4 uStack_10;
  
  uStack_10 = 0;
  bVar1 = 0;
  do {
    FUN_0000706c(bVar1,&uStack_10,1);
    bVar1 = bVar1 + 4;
  } while (bVar1 < 0x14);
  return;
}




void FUN_000076ce(int param_1)

{
  undefined local_110;
  undefined local_10f;
  undefined local_10e;
  undefined auStack_10d [261];
  
  local_110 = *(undefined *)(param_1 + 2);
  local_10f = *(undefined *)(param_1 + 3);
  local_10e = *(undefined *)(param_1 + 4);
  FUN_000237a0(auStack_10d,param_1 + 5,*(byte *)(param_1 + 2) - 3);
  FUN_0000b7f0(&local_110,*(undefined *)(param_1 + 2));
  return;
}




undefined4 FUN_00007700(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(DAT_00007a94 + iVar1 * 0x34 + 4) == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return 0;
}




undefined4 FUN_00007730(char *param_1,uint param_2)

{
  uint uVar1;
  
  if (*param_1 == -9) {
    uVar1 = (uint)(byte)param_1[1];
    if ((((uVar1 == 0xff) || (uVar1 == 0xfe)) || (uVar1 == param_2)) &&
       ((byte)param_1[2] - 3 < 0x62)) {
      return 1;
    }
  }
  else {
    FUN_0001cd4c(&DAT_00007a98);
    FUN_0001cd4c(s_error_package_>head_is__02X_00007ab4,*param_1);
    FUN_0001cd4c(&DAT_00007ad4);
  }
  return 0;
}




void FUN_000077d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while (*(uint *)(DAT_00007a94 + iVar1 * 0x34 + 4) != (uint)*(byte *)(param_1 + 4)) {
    iVar1 = iVar1 + 1;
    if (3 < iVar1) {
      return;
    }
  }
  iVar1 = DAT_00007a94 + iVar1 * 0x34;
  if (*(int *)(iVar1 + 0x14) == 0) {
    return;
  }
  *(undefined4 *)(iVar1 + 0x14) = 0;
  if (*(int *)(iVar1 + 0xc) == 0) {
    return;
  }
  iVar2 = *(int *)(iVar1 + 0x10);
  if ((int)(*(byte *)(param_1 + 2) - 3) <= iVar2) {
    iVar2 = *(byte *)(param_1 + 2) - 3;
  }
  FUN_000237a0(*(int *)(iVar1 + 0xc),param_1 + 5,iVar2);
  return;
}




void FUN_0000782c(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *DAT_00007b04;
    param_1[1] = DAT_00007b04[1];
    param_1[2] = DAT_00007b04[2];
  }
  return;
}




void FUN_00007848(undefined *param_1,undefined param_2,undefined param_3,undefined4 param_4,
                 char param_5)

{
  undefined uVar1;
  
  *param_1 = 0xf7;
  param_1[1] = param_2;
  param_1[2] = param_5 + '\x03';
  param_1[3] = 0;
  param_1[4] = param_3;
  FUN_000237a0(param_1 + 5,param_4);
  uVar1 = FUN_000076ce(param_1);
  param_1[0x69] = uVar1;
  return;
}




void FUN_00007874(undefined4 param_1,undefined *param_2)

{
  char cVar1;
  uint uVar2;
  undefined local_88;
  undefined local_87;
  undefined local_86;
  undefined local_85;
  undefined local_84;
  undefined auStack_83 [107];
  
  cVar1 = param_2[2];
  local_88 = *param_2;
  local_87 = param_2[1];
  local_86 = param_2[2];
  local_85 = param_2[3];
  uVar2 = (uint)(byte)(cVar1 - 3);
  local_84 = param_2[4];
  FUN_000237a0(auStack_83,param_2 + 5,uVar2);
  auStack_83[uVar2] = param_2[0x69];
  FUN_00013708(param_1,0,&local_88,cVar1 + '\x03');
  return;
}




void FUN_000078cc(int param_1,char *param_2)

{
  undefined uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined auStack_9c [108];
  undefined local_30;
  undefined local_2f;
  undefined local_2e [14];
  undefined local_20 [12];
  
  uVar1 = *(undefined *)(param_1 + 4);
  iVar7 = *(int *)(param_1 + 0x18);
  pcVar5 = *(char **)(param_1 + 0xc);
  *(undefined *)(DAT_00007b08 + 1) = 1;
  if (pcVar5 != (char *)0x0) {
    if (((*param_2 == -2) && (*pcVar5 != -1)) && (0xfd < (byte)pcVar5[1])) {
      FUN_0000782c(local_20,pcVar5[1],uVar1);
      local_30 = 1;
      local_2f = 0;
      uVar3 = 0;
      do {
        uVar4 = uVar3 + 1;
        local_2e[uVar3] = local_20[uVar3];
        uVar3 = uVar4;
      } while (uVar4 < 0xc);
      FUN_00007848(auStack_9c,*param_2);
      puVar2 = DAT_00007b0c;
      for (iVar6 = 0; iVar6 < iVar7; iVar6 = iVar6 + 1) {
        FUN_00007874(*puVar2,auStack_9c);
      }
    }
  }
  return;
}




void FUN_00007938(int param_1,undefined *param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined auStack_9c [108];
  undefined local_30;
  undefined local_2f;
  undefined local_2e [14];
  undefined local_20 [12];
  
  FUN_0000782c(local_20);
  puVar4 = *(undefined **)(param_1 + 0xc);
  uVar1 = *(undefined *)(param_1 + 4);
  iVar8 = *(int *)(param_1 + 0x18);
  if (puVar4 != (undefined *)0x0) {
    uVar2 = *puVar4;
    iVar5 = FUN_00023614(puVar4 + 1,local_20,0xc);
    if (iVar5 == 0) {
      *param_2 = uVar2;
      local_30 = 1;
      local_2f = 0;
      uVar6 = 0;
      do {
        uVar7 = uVar6 + 1;
        local_2e[uVar6] = local_20[uVar6];
        uVar6 = uVar7;
      } while (uVar7 < 0xc);
      FUN_00007848(auStack_9c,*param_2,uVar1,&local_30,0xe);
      puVar3 = DAT_00007b0c;
      for (iVar5 = 0; iVar5 < iVar8; iVar5 = iVar5 + 1) {
        FUN_00007874(*puVar3,auStack_9c);
      }
    }
  }
  return;
}




void FUN_000079a4(int param_1,undefined *param_2)

{
  undefined uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined local_a4;
  undefined local_a3;
  undefined local_a2 [14];
  undefined auStack_94 [116];
  undefined local_20 [12];
  
  FUN_0000782c(local_20);
  uVar1 = *(undefined *)(param_1 + 4);
  iVar6 = *(int *)(param_1 + 0x18);
  *(undefined *)(DAT_00007b08 + 1) = 1;
  local_a4 = 1;
  local_a3 = 0;
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1;
    local_a2[uVar3] = local_20[uVar3];
    uVar3 = uVar4;
  } while (uVar4 < 0xc);
  FUN_00007848(auStack_94,*param_2,uVar1,&local_a4,0xe);
  puVar2 = DAT_00007b0c;
  for (iVar5 = 0; iVar5 < iVar6; iVar5 = iVar5 + 1) {
    FUN_00007874(*puVar2,auStack_94);
  }
  return;
}




undefined4 FUN_000079fa(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = DAT_00007a94;
  iVar8 = 0;
  do {
    iVar7 = iVar1 + iVar8 * 0x34;
    if (*(int *)(iVar7 + 0x14) == 0) {
      if (*(int *)(iVar7 + 0x1c) == 0) {
        pcVar6 = *(code **)(iVar7 + 8);
LAB_00007a70:
        (*pcVar6)(iVar7,param_1);
        *(undefined4 *)(iVar7 + 0x14) = 1;
      }
      else if (*(int *)(iVar7 + 0x28) == 0) {
        uVar2 = FUN_0001a240();
        *(undefined4 *)(iVar7 + 0x2c) = uVar2;
        FUN_0001a1aa();
        iVar5 = *(int *)(iVar7 + 0x20);
        iVar9 = *(int *)(iVar7 + 0x24);
        FUN_000235c4();
        uVar3 = FUN_00000274();
        uVar4 = (iVar9 - iVar5) + 1;
        *(uint *)(iVar7 + 0x30) = (uVar3 - uVar4 * (uVar3 / uVar4)) + iVar5;
        *(int *)(iVar7 + 0x28) = *(int *)(iVar7 + 0x28) + 1;
      }
      else if ((*(int *)(iVar7 + 0x28) == 1) &&
              (iVar5 = FUN_0001a240(),
              *(uint *)(iVar7 + 0x30) < (uint)(iVar5 - *(int *)(iVar7 + 0x2c)))) {
        *(undefined4 *)(iVar7 + 0x28) = 0;
        pcVar6 = *(code **)(iVar7 + 8);
        goto LAB_00007a70;
      }
    }
    iVar8 = iVar8 + 1;
    if (3 < iVar8) {
      return 0;
    }
  } while( true );
}




void FUN_00007b4e(void)

{
  FUN_00015b9c(0x46,4);
  FUN_00015bc4(0x45,0);
  FUN_00015bc4(0x46,0);
  FUN_000175d2(1);
  FUN_00015bc4(0x45,1);
  FUN_00015bc4(0x46,1);
  FUN_000175d2(1);
  return;
}




void FUN_00007b88(void)

{
  FUN_00015bc4(0x45,0);
  FUN_00015b9c(0x46,4);
  FUN_00015bc4(0x46,1);
  FUN_000175d2(1);
  FUN_00015bc4(0x45,1);
  FUN_000175d2(1);
  FUN_00015bc4(0x45,0);
  return;
}




void FUN_00007bc2(void)

{
  FUN_00015bc4(0x45,0);
  FUN_00015b9c(0x46,4);
  FUN_00015bc4(0x46,0);
  FUN_000175d2(1);
  FUN_00015bc4(0x45,1);
  FUN_000175d2(1);
  FUN_00015bc4(0x45,0);
  return;
}




undefined4 FUN_00007bfc(void)

{
  int iVar1;
  ushort uVar2;
  
  uVar2 = 0;
  FUN_00015b9c(0x46,1);
  FUN_00015bc4(0x45,1);
  do {
    FUN_000175d2(1);
    iVar1 = FUN_00015bec(0x46);
    if (iVar1 == 0) {
      FUN_00015bc4(0x45,0);
      return 0;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xfb);
  FUN_00007b4e();
  return 1;
}




void FUN_00007c3e(uint param_1)

{
  uint uVar1;
  
  FUN_00015b9c(0x46,4);
  FUN_00015bc4(0x45,0);
  uVar1 = 0;
  do {
    FUN_00015bc4(0x46,(int)(param_1 << 0x18) < 0);
    param_1 = (param_1 << 0x19) >> 0x18;
    FUN_00015bc4(0x45,1);
    FUN_000175d2(1);
    FUN_00015bc4(0x45,0);
    FUN_000175d2(1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return;
}




void FUN_00007c8c(void)

{
  FUN_00015b9c(0x46,4);
  FUN_00015bc4(0x46,1);
  FUN_00015bc4(0x45,1);
  FUN_000175d2(1);
  FUN_00015bc4(0x46,0);
  FUN_000175d2(1);
  FUN_00015bc4(0x45,0);
  return;
}




undefined4 FUN_00007cc6(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_00007c8c();
  FUN_00007c3e(((param_1 << 0x15) >> 0x1d) << 1 | 0xa0);
  iVar1 = FUN_00007bfc();
  if (iVar1 == 0) {
    FUN_00007c3e(param_1 & 0xff);
    iVar1 = FUN_00007bfc();
    if (iVar1 == 0) {
      FUN_00007c8c();
      FUN_00007c3e(0xa1);
      iVar1 = FUN_00007bfc();
      if (iVar1 == 0) {
        for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1 & 0xffff) {
          uVar2 = 0;
          FUN_00015b9c(0x46,1);
          uVar4 = 0;
          do {
            FUN_00015bc4(0x45,0);
            FUN_000175d2(1);
            FUN_00015bc4(0x45,1);
            uVar2 = (uVar2 << 0x19) >> 0x18;
            iVar1 = FUN_00015bec(0x46);
            if (iVar1 != 0) {
              uVar2 = uVar2 + 1 & 0xff;
            }
            FUN_000175d2(1);
            uVar4 = uVar4 + 1;
          } while (uVar4 < 8);
          if (uVar3 == param_3 - 1) {
            FUN_00007b88();
          }
          else {
            FUN_00007bc2();
          }
          *(char *)(param_2 + uVar3) = (char)uVar2;
        }
        FUN_00007b4e();
        return 0;
      }
    }
  }
  FUN_00007b4e();
  return 1;
}




undefined8 FUN_00007d82(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar3 = param_1;
  for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1 & 0xffff) {
    if ((uVar4 == 0) || ((uVar3 & 0xf) == 0)) {
      FUN_00007b4e();
      uVar5 = 0;
      do {
        FUN_00007c8c();
        FUN_00007c3e(((uVar3 << 0x15) >> 0x1d) << 1 | 0xa0);
        iVar1 = FUN_00007bfc();
        if (iVar1 == 0) break;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 1000);
      if (uVar5 == 1000) goto LAB_00007e26;
      FUN_00007c3e(uVar3 & 0xff);
      iVar1 = FUN_00007bfc();
      if (iVar1 != 0) goto LAB_00007e26;
    }
    FUN_00007c3e(*(undefined *)(param_2 + uVar4));
    iVar1 = FUN_00007bfc();
    if (iVar1 != 0) goto LAB_00007e26;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  FUN_00007b4e();
  uVar5 = 0;
  do {
    FUN_00007c8c();
    FUN_00007c3e(((param_1 << 0x15) >> 0x1d) << 1 | 0xa0);
    iVar1 = FUN_00007bfc();
    if (iVar1 == 0) break;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 1000);
  if (uVar5 == 1000) {
LAB_00007e26:
    FUN_00007b4e();
    uVar2 = 1;
  }
  else {
    FUN_00007b4e();
    uVar2 = 0;
  }
  return CONCAT44(param_1,uVar2);
}




undefined4 FUN_00007e2e(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  FUN_00015b9c(0x46,1);
  FUN_00015b9c(0x45,1);
  cVar1 = FUN_00015bec(0x46);
  cVar2 = FUN_00015bec(0x45);
  FUN_00015b9c(0x46,4);
  FUN_00015b9c(0x45,4);
  FUN_0001cd4c(s_sda__d__scl__d_0000813c,cVar1,cVar2);
  if ((cVar1 != '\0') && (cVar2 != '\0')) {
    FUN_00007c8c();
    FUN_00007c3e(0xa0);
    iVar3 = FUN_00007bfc();
    FUN_00007b4e();
    if (iVar3 == 0) {
      return 1;
    }
  }
  return 0;
}




undefined4 FUN_00007e8c(void)

{
  int iVar1;
  int in_r3;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_c = in_r3;
  iVar1 = FUN_00007e2e();
  if (iVar1 == 0) {
    return 1;
  }
  FUN_00007cc6(0x7f0,&local_10,4);
  local_c = DAT_0000814c;
  if (local_10 == DAT_0000814c) {
    local_c = DAT_00008150;
  }
  FUN_00007d82(0x7f0,&local_c,4);
  FUN_00007cc6(0x7f0,&local_10,4);
  if (local_10 == local_c) {
    return 0;
  }
  return 2;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00007eda(void)

{
  int iVar1;
  byte bVar2;
  
  FUN_00015b9c(0x46,4);
  FUN_00015b9c(0x45,4);
  FUN_00015bc4(0x45,1);
  FUN_00015bc4(0x46,1);
  FUN_0001eb00(1);
  bVar2 = 0;
  do {
    iVar1 = FUN_00007e8c();
    if (iVar1 == 0) break;
    FUN_00015b9c(0x46,4);
    FUN_00015b9c(0x45,4);
    FUN_00015bc4(0x45,1);
    FUN_00015bc4(0x46,1);
    FUN_0001eb00(1);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 3);
  *_DAT_00008154 = (char)iVar1;
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00007f48(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined uVar1;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  undefined4 local_18;
  
  local_18 = param_4;
  if (1 < param_1) {
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_init_00008157 + 1);
    pcVar4 = _DAT_00008160;
    if (iVar3 == 0) {
      *_DAT_00008160 = '\x01';
      uVar5 = FUN_00007eda();
      return uVar5;
    }
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_ready_00008163 + 1);
    if (iVar3 == 0) {
      uVar5 = FUN_00007e2e();
      pcVar4 = s_bl24cxx_is_ready__d_000081a0;
LAB_00007fdc:
      uVar5 = FUN_0001cd4c(pcVar4,uVar5);
      return uVar5;
    }
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_undeadlock_0000816c);
    if (iVar3 == 0) {
      FUN_00015b9c(0x46,1);
      FUN_00015b9c(0x45,4);
      FUN_00015bc4(0x45,1);
      bVar6 = 0;
      do {
        iVar3 = FUN_00015bec(0x46);
        if (iVar3 != 0) {
          FUN_00015b9c(0x46,4);
          FUN_00007b4e();
          return 0;
        }
        FUN_00015bc4(0x45,0);
        FUN_000175d2(1);
        FUN_00015bc4(0x45,1);
        FUN_000175d2(1);
        bVar6 = bVar6 + 1;
      } while (bVar6 < 10);
      return 1;
    }
    if (*pcVar4 == '\0') {
      pcVar4 = s_Please_using__bl24cxx_init__firs_000081b8;
      goto LAB_00008064;
    }
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_deadlock_00008178);
    if (iVar3 == 0) {
      if (param_1 < 3) {
        return 0;
      }
      uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 8));
      FUN_00007c8c();
      FUN_00007c3e(0xa0);
      FUN_00007bfc();
      FUN_00007c3e(uVar1);
      FUN_00007bfc();
      FUN_00007c8c();
      FUN_00007c3e(0xa1);
      FUN_00007bfc();
      FUN_00015b9c(0x46,1);
      uVar7 = 0;
      do {
        FUN_00015bc4(0x45,0);
        FUN_000175d2(1);
        FUN_00015bc4(0x45,1);
        iVar3 = FUN_00015bec(0x46);
        if (iVar3 == 0) {
          FUN_00013060();
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        FUN_000175d2(1);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 8);
      FUN_00007b88();
      FUN_00007b4e();
      return 0;
    }
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_capacity_00008184);
    if (iVar3 == 0) {
      uVar5 = 0x800;
      pcVar4 = s_bl24cxx_get_capacity__d_000081dc;
      goto LAB_00007fdc;
    }
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_write_00008190);
    if (iVar3 == 0) {
      if (3 < param_1) {
        uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
        uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 0xc));
        local_18 = CONCAT31(local_18._1_3_,uVar1);
        FUN_00007d82(uVar2,&local_18,1);
        pcVar4 = s_bl24cxx_write_bytes_address__d__d_000081f8;
        goto LAB_00008032;
      }
    }
    else {
      iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_00008198);
      if ((iVar3 == 0) && (2 < param_1)) {
        uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
        local_18 = local_18 & 0xffffff00;
        FUN_00007cc6(uVar2,&local_18,1);
        pcVar4 = s_bl24cxx_read_bytes_address__d__d_00008224;
LAB_00008032:
        uVar5 = FUN_0001cd4c(pcVar4,uVar2,(undefined)local_18);
        return uVar5;
      }
    }
  }
  FUN_0001cd4c(s_Usage__0000824c);
  FUN_0001cd4c(s_bl24cxx_init___init_bl24cxx_00008258);
  FUN_0001cd4c(s_bl24cxx_capacity___bl24cxx_get_c_00008290);
  FUN_0001cd4c(s_bl24cxx_ready___bl24cxx_is_ready_000082d0);
  FUN_0001cd4c(s_bl24cxx_deadlock_<address>___bl2_00008310);
  FUN_0001cd4c(s_bl24cxx_undeadlock___bl24cxx_und_0000834c);
  FUN_0001cd4c(DAT_0000838c);
  pcVar4 = DAT_00008390;
LAB_00008064:
  uVar5 = FUN_0001cd4c(pcVar4);
  return uVar5;
}




float FUN_0000840a(void)

{
  return *(float *)(DAT_000086b8 + 0x11) * DAT_000086bc;
}




undefined4 FUN_0000841c(void)

{
  undefined4 uVar1;
  uint in_fpscr;
  undefined4 uVar2;
  
  FUN_0001e1fe();
  uVar1 = FUN_00009bc2(DAT_000086c0);
  uVar2 = VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x15) & 3);
  *(undefined4 *)(DAT_000086b8 + 0x11) = uVar2;
  FUN_0001e214();
  return uVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008442(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  FUN_0000841c();
  iVar3 = DAT_000086b8;
  if ((*(char *)(DAT_000086b8 + -3) != '\0') &&
     (iVar1 = *(int *)(DAT_000086b8 + 9) + 1, *(int *)(DAT_000086b8 + 9) = iVar1, iVar1 == 10)) {
    *(undefined4 *)(iVar3 + 9) = 0;
    if (*(float *)(iVar3 + 0x11) != *(float *)(iVar3 + 5)) {
      *(float *)(iVar3 + 5) = *(float *)(iVar3 + 0x11);
      fVar2 = (float)FUN_0000840a();
      iVar3 = (int)(fVar2 * _DAT_000086c4);
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      FUN_0001cd4c(s_Bodometer_magnetic_current_posit_000086c7 + 1,(int)fVar2,iVar3 % 100);
      return;
    }
  }
  return;
}




undefined4 FUN_000084ae(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  char *pcVar1;
  uint local_10;
  undefined4 local_c;
  
  local_c = CONCAT31((int3)((uint)param_4 >> 8),0x7e);
  local_10 = param_3 & 0xffffff00;
  FUN_00009a24(DAT_000086c0,1,&local_10,1);
  if ((local_c & 0xff) != (local_10 & 0xff)) {
    FUN_00009a6a(DAT_000086c0,1,&local_c,1);
    FUN_00009a24(DAT_000086c0,1,&local_10,1);
  }
  FUN_0001cd4c(&DAT_000086f8);
  if ((local_c & 0xff) == (local_10 & 0xff)) {
    pcVar1 = s_success_00008714;
  }
  else {
    pcVar1 = &DAT_0000871c;
  }
  FUN_0001cd4c(s_read_userid__s__id_0x_02x_00008724,pcVar1);
  FUN_0001cd4c(&DAT_00008740);
  if ((local_c & 0xff) == (local_10 & 0xff)) {
    return 1;
  }
  return 0;
}




void FUN_00008526(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 in_r3;
  
  iVar1 = DAT_000086b8;
  if (*(char *)(DAT_000086b8 + -2) == '\x01') {
    return;
  }
  *(undefined *)(DAT_000086b8 + -2) = 1;
  FUN_00009c16(DAT_000086c0,iVar1 + 0x15,iVar1 + 0xd,in_r3,in_r3);
  FUN_00009cb2(DAT_000086c0);
  uVar2 = FUN_0001a20e(0x14);
  iVar3 = FUN_0001edae(&DAT_0000874c,DAT_00008748,0,uVar2);
  iVar1 = DAT_00008750;
  if (iVar3 == 0) {
    *(undefined *)(DAT_00008750 + 2) = 1;
    FUN_0001cd4c(&DAT_00008754);
    pcVar4 = s_odometer_magnetic_init_mt6826_ti_0000879c;
  }
  else {
    FUN_0001ee68();
    iVar3 = FUN_000084ae();
    if (iVar3 != 0) {
      return;
    }
    *(undefined *)(iVar1 + 2) = 1;
    FUN_0001cd4c(&DAT_00008754);
    pcVar4 = s_odometer_magnetic_init_communica_00008770;
  }
  FUN_0001cd4c(pcVar4);
  FUN_0001cd4c(&DAT_00008740);
  return;
}




void FUN_00008598(void)

{
  FUN_00009cb2(DAT_000086c0);
  *(undefined4 *)(DAT_000086b8 + 0x11) = DAT_000087cc;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000085ae(int param_1,int param_2)

{
  undefined uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined *puVar5;
  float fVar6;
  undefined8 uVar7;
  
  if (1 < param_1) {
    iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_000087d0);
    puVar5 = (undefined *)(DAT_000086b8 + -3);
    if (iVar2 == 0) {
      *(undefined *)(DAT_000086b8 + -1) = 1;
      FUN_00008526();
      return 0;
    }
    if (*(char *)(DAT_000086b8 + -1) == '\0') {
      pcVar3 = s_Please_using__odo_mag_init__firs_000087f8;
      goto LAB_0000866c;
    }
    iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_reset_000087d8);
    if (iVar2 == 0) {
      FUN_00008598();
      return 0;
    }
    iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_000087e0);
    if (iVar2 == 0) {
      iVar2 = FUN_000084ae();
      if (iVar2 == 0) {
        pcVar3 = &DAT_0000871c;
      }
      else {
        pcVar3 = s_success_00008714;
      }
      pcVar4 = s_odo_mag_communication__s_0000881c;
LAB_0000867c:
      FUN_0001cd4c(pcVar4,pcVar3);
      return 0;
    }
    iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_monitor_000087e8);
    if (iVar2 == 0) {
      uVar7 = FUN_00025738(*(undefined4 *)(param_2 + 8));
      uVar1 = FUN_00025fc0((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      *puVar5 = uVar1;
      return 0;
    }
    iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_000087f0);
    if (iVar2 != 0) {
      return 0;
    }
    if (2 < param_1) {
      iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 8),&DAT_00008838);
      if (iVar2 == 0) {
        pcVar3 = (char *)FUN_0000841c();
        pcVar4 = s_odometer_magnetic_current_step___000089b4;
        goto LAB_0000867c;
      }
      iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 8),&DAT_00008840);
      if (iVar2 == 0) {
        fVar6 = (float)FUN_0000840a();
        iVar2 = (int)(fVar6 * _DAT_000086c4);
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        FUN_0001cd4c(s_Bodometer_magnetic_current_posit_000086c7 + 1,(int)fVar6,iVar2 % 100);
        return 0;
      }
    }
  }
  FUN_0001cd4c(s_Usage__00008844);
  FUN_0001cd4c(s_odo_mag_init___init_magnetic_odo_00008850);
  FUN_0001cd4c(s_odo_mag_test___test_magnetic_odo_00008884);
  FUN_0001cd4c(s_odo_mag_monitor__en____print_mag_000088c4);
  FUN_0001cd4c(s_odo_mag_reset___reset_magnetic_o_00008900);
  FUN_0001cd4c(s_odo_mag_read_step___read_raw_val_00008934);
  pcVar3 = s_odo_mag_read_mm___read_position_o_00008974;
LAB_0000866c:
  FUN_0001cd4c(pcVar3);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000089d8(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0001fb24(0x603);
  iVar1 = _DAT_00008dc8;
  FUN_00015b9c(*(undefined2 *)(_DAT_00008dc8 + param_1 * 4),0);
  iVar2 = iVar1 + param_1 * 4;
  FUN_00015b9c(*(undefined2 *)(iVar2 + 2),0);
  FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),1);
  FUN_00015bc4(*(undefined2 *)(iVar2 + 2),1);
  return;
}




void FUN_00008a12(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    FUN_000089d8(uVar1 & 0xff);
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 2);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008a24(int param_1)

{
  FUN_00015b9c(*(undefined2 *)(_DAT_00008dc8 + param_1 * 4 + 2),0);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008a32(int param_1)

{
  FUN_00015b9c(*(undefined2 *)(_DAT_00008dc8 + param_1 * 4 + 2),1);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008a40(uint param_1)

{
  int iVar1;
  
  if (param_1 < 2) {
    FUN_000175d2(1);
    iVar1 = _DAT_00008dc8;
    FUN_00015bc4(*(undefined2 *)(_DAT_00008dc8 + param_1 * 4 + 2),0);
    FUN_000175d2(1);
    FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),0);
    FUN_000175d2(1);
    return;
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008a78(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_00008dc8;
  if (param_1 < 2) {
    iVar2 = _DAT_00008dc8 + param_1 * 4;
    FUN_00015bc4(*(undefined2 *)(iVar2 + 2),0);
    FUN_000175d2(1);
    FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),1);
    FUN_000175d2(1);
    FUN_00015bc4(*(undefined2 *)(iVar2 + 2),1);
    return;
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008ab2(int param_1,uint param_2,undefined *param_3)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  byte bVar4;
  
  FUN_00008a24();
  iVar1 = _DAT_00008dc8;
  bVar4 = 0;
  iVar3 = _DAT_00008dc8 + param_1 * 4;
  do {
    FUN_00015bc4(*(undefined2 *)(iVar3 + 2),(int)(param_2 << 0x18) < 0);
    FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),1);
    FUN_000175d2(1);
    FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),0);
    FUN_00015bc4(*(undefined2 *)(iVar3 + 2),0);
    param_2 = (param_2 << 0x19) >> 0x18;
    FUN_000175d2(1);
    bVar4 = bVar4 + 1;
  } while (bVar4 < 8);
  FUN_00008a32(param_1);
  FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),1);
  FUN_000175d2(1);
  uVar2 = FUN_00015bec(*(undefined2 *)(iVar3 + 2));
  *param_3 = uVar2;
  FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),0);
  FUN_00008a24(param_1);
  FUN_00015bc4(*(undefined2 *)(iVar3 + 2),0);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008b4c(int param_1,undefined *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  FUN_00008a32();
  iVar1 = _DAT_00008dc8;
  bVar3 = 0;
  iVar5 = _DAT_00008dc8 + param_1 * 4;
  do {
    FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),1);
    FUN_000175d2(1);
    uVar2 = FUN_00015bec(*(undefined2 *)(iVar5 + 2));
    uVar2 = uVar2 | uVar4 << 1;
    uVar4 = uVar2 & 0xff;
    FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),0);
    FUN_000175d2(10);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 8);
  *param_2 = (char)uVar2;
  FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),param_3 != 0);
  FUN_00008a24(param_1);
  FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),1);
  FUN_000175d2(1);
  FUN_00015bc4(*(undefined2 *)(iVar1 + param_1 * 4),0);
  return;
}




undefined4 FUN_00008bd8(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  
  local_18 = param_4;
  FUN_00008a40();
  FUN_00008ab2(param_1,0x50,&local_18);
  if ((char)local_18 != '\0') {
    FUN_0001cd4c(s_SetReg__send_RFID_ADDR_failed__00008dcb + 1);
    return 1;
  }
  FUN_00008ab2(param_1,param_2 & 0x3f,&local_18);
  if ((char)local_18 != '\0') {
    FUN_0001cd4c(s_SetReg__send_reg_addr_failed__00008dec);
    return 2;
  }
  FUN_00008ab2(param_1,param_3,&local_18);
  if ((char)local_18 != '\0') {
    FUN_0001cd4c(s_SetReg__send_data_failed__00008e0c);
    return 3;
  }
  FUN_00008a78(param_1);
  return 0;
}




undefined4 FUN_00008c3e(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  
  local_18 = param_4;
  FUN_00008a40();
  FUN_00008ab2(param_1,0x50,&local_18);
  if ((char)local_18 != '\0') {
    FUN_0001cd4c(s_GetReg__send_RFID_ADDR_failed__00008e28);
    return 1;
  }
  FUN_00008ab2(param_1,param_2 & 0x3f,&local_18);
  if ((char)local_18 != '\0') {
    FUN_0001cd4c(s_GetReg__send_reg_addr_failed__00008e48);
    return 2;
  }
  FUN_00008a78(param_1);
  FUN_00008a40(param_1);
  FUN_00008ab2(param_1,0x51,&local_18);
  if ((char)local_18 != '\0') {
    FUN_0001cd4c(s_GetReg__RFID_ADDR_read_failed__00008e68);
    return 3;
  }
  FUN_00008b4c(param_1,param_3,1);
  FUN_00008a78(param_1);
  return 0;
}




uint FUN_00008cba(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint local_8 [2];
  
  local_8[0] = param_4;
  FUN_00008c3e(param_1,param_2,local_8);
  return local_8[0] & 0xff;
}




void FUN_00008cc8(undefined4 param_1,undefined4 param_2,byte param_3,int param_4)

{
  undefined4 local_18;
  
  local_18 = param_4;
  FUN_00008c3e(param_1,param_2,&local_18);
  if (param_4 == 0) {
    param_3 = (byte)local_18 & ~param_3;
  }
  else {
    param_3 = (byte)local_18 | param_3;
  }
  local_18 = CONCAT31(local_18._1_3_,param_3);
  FUN_00008bd8(param_1,param_2,param_3);
  return;
}




void FUN_00008cf4(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = FUN_00008cba();
  FUN_00008bd8(param_1,param_2,uVar1 | param_3);
  return;
}




undefined4 FUN_00008d0e(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint local_10;
  
  local_10 = param_4;
  FUN_00008bd8(param_1,1,0xf);
  FUN_0001eb00(2);
  FUN_00008c3e(param_1,1,&local_10);
  if ((local_10 & 0xff) != 0x20) {
    FUN_0001cd4c(s_rfid__d__softReset_failed__reg_d_00008e8c,param_1);
    return 1;
  }
  return 0;
}




undefined4 FUN_00008d42(undefined4 param_1,char param_2,char param_3)

{
  FUN_00008bd8(param_1,0xf,param_2 + '@');
  FUN_00008bd8(param_1,0xf,param_3 + -0x40);
  return 0;
}




int FUN_00008d62(undefined4 param_1)

{
  int iVar1;
  
  FUN_000089d8();
  iVar1 = FUN_00008d0e(param_1);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}




void FUN_00008d78(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  
  iVar1 = DAT_00008eb8;
  uVar3 = 0;
  do {
    bVar4 = 0;
    do {
      iVar2 = FUN_00008d62(uVar3);
      if (iVar2 == 0) break;
      bVar4 = bVar4 + 1;
      *(undefined *)(iVar1 + uVar3 + 4) = 1;
    } while (bVar4 < 3);
    uVar3 = uVar3 + 1 & 0xff;
    if (1 < uVar3) {
      return;
    }
  } while( true );
}




undefined4 FUN_00008da8(undefined4 param_1,char param_2,undefined4 param_3)

{
  FUN_00008bd8(param_1,0xf,param_2 + -0x80);
  FUN_00008c3e(param_1,0xf,param_3);
  return 0;
}




void FUN_00008ee8(undefined4 param_1)

{
  FUN_00008cf4(param_1,0xc,0x10);
  FUN_00008cf4(param_1,0x15,0x40);
  FUN_00008bd8(param_1,0x12,0);
  FUN_00008bd8(param_1,0x13,0);
  FUN_00008bd8(param_1,0x27,0xf1);
  FUN_00008bd8(param_1,0x28,0x3f);
  FUN_00008bd8(param_1,0x29,1);
  FUN_00008bd8(param_1,0x26,0x58);
  FUN_00008bd8(param_1,0x18,0x84);
  FUN_00008bd8(param_1,0x36,0x40);
  return;
}




void FUN_00008f50(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
LAB_00008f98:
    uVar1 = 3;
  }
  else {
    if (param_2 == 1) {
      FUN_00008cc8(param_1,0x14,1);
      uVar2 = 0;
    }
    else {
      if (param_2 != 2) {
        if (param_2 != 3) goto LAB_00008f8c;
        uVar2 = 1;
        goto LAB_00008f98;
      }
      FUN_00008cc8(param_1,0x14,1,0);
      uVar2 = 1;
    }
    uVar1 = 2;
  }
  FUN_00008cc8(param_1,0x14,uVar1,uVar2);
LAB_00008f8c:
  FUN_0001eb00(10);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00008f9e(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_10;
  
  local_10 = param_4;
  FUN_00008bd8(param_1,0x12,0);
  FUN_00008bd8(param_1,0x13,0);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x52);
  FUN_00008bd8(param_1,1,0xc);
  FUN_00008bd8(param_1,0xd,0x87);
  FUN_0001eb00(1);
  FUN_00008c3e(param_1,10,&local_10);
  if (((local_10 & 0xff) != 0) && ((local_10 & 0xff) == 2)) {
    iVar1 = _DAT_00009400 + param_1 * 0x20 + param_2 * 0x10;
    FUN_00008c3e(param_1,9,iVar1);
    FUN_00008c3e(param_1,9,iVar1 + 1);
    return 0;
  }
  return 1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00009028(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = param_4;
  FUN_00008bd8(param_1,0x12,0);
  FUN_00008bd8(param_1,0x13,0);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x93);
  FUN_00008bd8(param_1,9,0x20);
  FUN_00008bd8(param_1,1,0xc);
  FUN_00008bd8(param_1,0xd,0x80);
  FUN_0001eb00(2);
  FUN_00008c3e(param_1,10,&local_10);
  if ((char)local_10 == '\x05') {
    iVar1 = _DAT_00009400 + param_1 * 0x20 + param_2 * 0x10;
    FUN_00008c3e(param_1,9,iVar1 + 2);
    FUN_00008c3e(param_1,9,iVar1 + 3);
    FUN_00008c3e(param_1,9,iVar1 + 4);
    FUN_00008c3e(param_1,9,iVar1 + 5);
    FUN_00008c3e(param_1,9,iVar1 + 0xd);
    if ((byte)(*(byte *)(iVar1 + 2) ^ *(byte *)(iVar1 + 3) ^
              *(byte *)(iVar1 + 4) ^ *(byte *)(iVar1 + 5)) == *(byte *)(iVar1 + 0xd)) {
      return 0;
    }
  }
  return 0xf4;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000090ee(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = param_4;
  FUN_00008bd8(param_1,0x12,0);
  FUN_00008bd8(param_1,0x13,0);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x95);
  FUN_00008bd8(param_1,9,0x20);
  FUN_00008bd8(param_1,1,0xc);
  FUN_00008bd8(param_1,0xd,0x80);
  FUN_0001eb00(10);
  FUN_00008c3e(param_1,10,&local_10);
  if ((char)local_10 == '\x05') {
    iVar1 = _DAT_00009400 + param_1 * 0x20 + param_2 * 0x10;
    FUN_00008c3e(param_1,9,iVar1 + 6);
    FUN_00008c3e(param_1,9,iVar1 + 7);
    FUN_00008c3e(param_1,9,iVar1 + 8);
    FUN_00008c3e(param_1,9,iVar1 + 9);
    FUN_00008c3e(param_1,9,iVar1 + 0xd);
    if ((byte)(*(byte *)(iVar1 + 6) ^ *(byte *)(iVar1 + 7) ^
              *(byte *)(iVar1 + 8) ^ *(byte *)(iVar1 + 9)) == *(byte *)(iVar1 + 0xd)) {
      return 0;
    }
  }
  return 0xf4;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000091b8(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_10;
  
  local_10 = param_4;
  FUN_00008bd8(param_1,0x12,0x80);
  FUN_00008bd8(param_1,0x13,0x80);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x93);
  FUN_00008bd8(param_1,9,0x70);
  iVar1 = _DAT_00009400 + param_1 * 0x20 + param_2 * 0x10;
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 2));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 3));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 4));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 5));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 0xd));
  FUN_00008bd8(param_1,1,0xc);
  FUN_00008bd8(param_1,0xd,0x80);
  FUN_0001eb00(2);
  FUN_00008c3e(param_1,10,&local_10);
  if ((local_10 & 0xff) != 1) {
    FUN_0001cd4c(s_ReaderA_Select__rfid__d__reg_dat_00009403 + 1,param_1);
    return 0xf4;
  }
  FUN_00008c3e(param_1,9,iVar1 + 0xe);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000927c(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_10;
  
  local_10 = param_4;
  FUN_00008bd8(param_1,0x12,0x80);
  FUN_00008bd8(param_1,0x13,0x80);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x95);
  FUN_00008bd8(param_1,9,0x70);
  iVar1 = _DAT_00009400 + param_1 * 0x20 + param_2 * 0x10;
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 6));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 7));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 8));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 9));
  FUN_00008bd8(param_1,9,*(undefined *)(iVar1 + 0xd));
  FUN_00008bd8(param_1,1,0xc);
  FUN_00008bd8(param_1,0xd,0x80);
  FUN_0001eb00(2);
  FUN_00008c3e(param_1,10,&local_10);
  if ((local_10 & 0xff) != 1) {
    FUN_0001cd4c(s_ReaderA_Select__rfid__d__reg_dat_00009403 + 1,param_1);
    return 0xf4;
  }
  FUN_00008c3e(param_1,9,iVar1 + 0xe);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00009340(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = FUN_00008f9e();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_00009028(param_1,param_2);
  if (iVar1 != 0) {
    return 2;
  }
  pcVar2 = (char *)(_DAT_00009400 + param_1 * 0x20 + param_2 * 0x10);
  if ((*pcVar2 == '\x04') && (pcVar2[1] == '\0')) {
    iVar1 = FUN_000091b8(param_1,param_2);
  }
  else {
    iVar1 = FUN_000091b8(param_1,param_2);
    if (iVar1 != 0) {
      return 3;
    }
    iVar1 = FUN_000090ee(param_1,param_2);
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = FUN_0000927c(param_1,param_2);
  }
  if (iVar1 != 0) {
    return 3;
  }
  return 0;
}




int FUN_000093a2(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_00008d0e();
  FUN_00008ee8(param_1);
  FUN_00008f50(param_1,3);
  iVar1 = FUN_00009340(param_1,param_2);
  if (iVar1 == 0) {
    *DAT_0000942c = 0x40;
    iVar1 = 0;
  }
  else {
    FUN_00008f50(param_1,0);
  }
  return iVar1;
}




bool FUN_000093dc(undefined4 param_1,undefined4 param_2,undefined *param_3,undefined *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined *local_20;
  
  piVar1 = DAT_00009430;
  local_20 = param_4;
  if (*DAT_00009430 != 0) {
    FUN_00008bd8(param_1,8,0);
  }
  *piVar1 = 0;
  FUN_00008bd8(param_1,0x12,0x80);
  FUN_00008bd8(param_1,0x13,0x80);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x60);
  FUN_00008bd8(param_1,9,param_2);
  FUN_00008bd8(param_1,9,*param_3);
  FUN_00008bd8(param_1,9,param_3[1]);
  FUN_00008bd8(param_1,9,param_3[2]);
  FUN_00008bd8(param_1,9,param_3[3]);
  FUN_00008bd8(param_1,9,param_3[4]);
  FUN_00008bd8(param_1,9,param_3[5]);
  FUN_00008bd8(param_1,9,*param_4);
  FUN_00008bd8(param_1,9,param_4[1]);
  FUN_00008bd8(param_1,9,param_4[2]);
  FUN_00008bd8(param_1,9,param_4[3]);
  FUN_00008bd8(param_1,1,0xe);
  FUN_00008bd8(param_1,0xd,0x80);
  FUN_0001eb00(10);
  FUN_00008c3e(param_1,8,&local_20);
  bVar2 = -1 < (int)local_20 << 0x1c;
  if (bVar2) {
    FUN_0001cd4c(s_card__d_auth_block__d_failed__re_0000978c,param_1,param_2);
  }
  return bVar2;
}




undefined4 FUN_00009512(undefined4 param_1,uint param_2,int param_3,uint param_4)

{
  char *pcVar1;
  uint uVar2;
  uint local_18;
  
  local_18 = param_4;
  if (((param_2 < 0x40) && (param_2 != 0)) && ((~param_2 & 3) != 0)) {
    FUN_00008bd8(param_1,0x12,0x80);
    FUN_00008bd8(param_1,0x13,0);
    FUN_00008bd8(param_1,1,0);
    FUN_00008bd8(param_1,10,0x80);
    FUN_00008bd8(param_1,9,0xa0);
    FUN_00008bd8(param_1,9,param_2);
    FUN_00008bd8(param_1,1,0xc);
    FUN_00008bd8(param_1,0xd,0x80);
    FUN_0001eb00(10);
    FUN_00008c3e(param_1,10,&local_18);
    if ((local_18 & 0xff) == 1) {
      FUN_00008c3e(param_1,9,&local_18);
      if ((char)local_18 != '\n') {
        return 1;
      }
    }
    else {
      FUN_0001cd4c(s_card__d_card_write_JREG_FIFOLEVE_000097bc,param_1);
    }
    FUN_00008bd8(param_1,10,0x80);
    uVar2 = 0;
    do {
      FUN_00008bd8(param_1,9,*(undefined *)(param_3 + uVar2));
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 0x10);
    FUN_00008bd8(param_1,1,0xc);
    FUN_00008bd8(param_1,0xd,0x80);
    FUN_0001eb00(10);
    FUN_00008c3e(param_1,10,&local_18);
    if ((local_18 & 0xff) == 1) {
      FUN_00008c3e(param_1,9,&local_18);
      if ((local_18 & 0xff) == 10) {
        return 0;
      }
      pcVar1 = s_card__d_card_write_2_JREG_FIFODA_00009848;
    }
    else {
      pcVar1 = s_card__d_card_write_2_JREG_FIFOLE_000097f0;
    }
    FUN_0001cd4c(pcVar1,param_1);
    return 1;
  }
  FUN_0001cd4c(s_card_write__block_num__d_is_erro_00009824);
  return 2;
}




undefined4 FUN_00009628(undefined4 param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint local_18;
  
  local_18 = param_4;
  if (0x3f < param_2) {
    FUN_0001cd4c(s_card_read__block_num__d_is_error_0000987c);
    return 2;
  }
  FUN_00008bd8(param_1,0x12,0x80);
  FUN_00008bd8(param_1,0x13,0x80);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x30);
  FUN_00008bd8(param_1,9,param_2);
  FUN_00008bd8(param_1,1,0xc);
  FUN_00008bd8(param_1,0xd,0x80);
  FUN_0001eb00(10);
  FUN_00008c3e(param_1,10,&local_18);
  if ((local_18 & 0xff) != 0x10) {
    FUN_0001cd4c(s_card__d_card_read__reg_data____d_000098a0,param_1);
    return 1;
  }
  uVar1 = 0;
  do {
    FUN_00008c3e(param_1,9,param_3 + uVar1);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x10);
  return 0;
}




undefined4 FUN_000096c8(int param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(DAT_000098c4 + param_1 * 0x20 + param_2 * 0x10);
  if (((*pcVar1 == '\x04') && (pcVar1[1] == '\0')) && (pcVar1[0xe] == '\b')) {
    return 0;
  }
  return 1;
}




undefined4 FUN_000096ea(undefined4 param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint local_18;
  
  local_18 = param_4;
  if (0x3f < param_2) {
    FUN_0001cd4c(s_card_read__block_num__d_is_error_0000987c);
    return 2;
  }
  FUN_00008bd8(param_1,0x12,0x80);
  FUN_00008bd8(param_1,0x13,0x80);
  FUN_00008bd8(param_1,1,0);
  FUN_00008bd8(param_1,10,0x80);
  FUN_00008bd8(param_1,9,0x30);
  FUN_00008bd8(param_1,9,param_2);
  FUN_00008bd8(param_1,1,0xc);
  FUN_00008bd8(param_1,0xd,0x80);
  FUN_0001eb00(10);
  FUN_00008c3e(param_1,10,&local_18);
  if ((local_18 & 0xff) != 0x10) {
    FUN_0001cd4c(s_card__d_card_read__reg_data____d_000098a0,param_1);
    return 1;
  }
  uVar1 = 0;
  do {
    FUN_00008c3e(param_1,9,param_3 + uVar1);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x10);
  return 0;
}




undefined4 FUN_0000998c(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + 0xe);
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    return 0xffffffff;
  }
  if ((bVar1 & 1) != 0) {
    return 0xffffffff;
  }
  if ((int)((uint)bVar1 << 0x1d) < 0) {
    return 0xffffffff;
  }
  *(byte *)(param_1 + 0xe) = bVar1 | 4;
  uVar2 = (uint)*(ushort *)(param_1 + 10);
  if (param_2 < uVar2) {
    FUN_0002382a(*(int *)(param_1 + 4) + (uVar2 - param_2),*(int *)(param_1 + 4) + uVar2,
                 *(ushort *)(param_1 + 0xc) - uVar2 & 0xffff);
    *(short *)(param_1 + 10) = *(short *)(param_1 + 10) - (short)param_2;
  }
  else {
    if (*(ushort *)(param_1 + 0xc) < param_2) {
      *(undefined2 *)(param_1 + 10) = 0;
      *(undefined2 *)(param_1 + 0xc) = 0;
      goto LAB_000099f8;
    }
    FUN_0002382a(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + param_2,
                 *(ushort *)(param_1 + 0xc) - param_2 & 0xffff);
    *(undefined2 *)(param_1 + 10) = 0;
  }
  *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) - (short)param_2;
LAB_000099f8:
  *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) & 0xfb;
  return 0;
}




bool FUN_00009a24(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (param_4 < 5) {
    local_20 = (uint)(ushort)(CONCAT11((char)param_2,(char)((uint)param_2 >> 8)) | 0x30);
    (**(code **)(*param_1 + 4))(&local_20,&local_18,param_4 + 2,100);
    FUN_000237a0(param_3,(int)&local_18 + 2,param_4);
  }
  return param_4 < 5;
}




undefined4 FUN_00009a6a(int *param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (param_4 < 5) {
    local_20 = (uint)(ushort)(CONCAT11((char)param_2,(char)((uint)param_2 >> 8)) | 0x60);
    for (uVar2 = 0; uVar2 < param_4; uVar2 = uVar2 + 1) {
      *(undefined *)((int)&local_20 + uVar2 + 2) = *(undefined *)(param_3 + uVar2);
    }
    (**(code **)(*param_1 + 4))(&local_20,&local_18,param_4 + 2,100);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




int FUN_00009ad2(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0xc) < 0) {
    iVar1 = *(int *)(param_1 + 8) - iVar1;
  }
  *(int *)(param_1 + 0x24) = iVar1;
  return iVar1;
}




void FUN_00009ae8(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x50))();
  *(int *)(param_1 + 0x1c) = iVar1;
  *(int *)(param_1 + 0x20) = iVar1 - *(int *)(param_1 + 8) * (iVar1 / *(int *)(param_1 + 8));
  return;
}




uint FUN_00009b00(int *param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  float fVar6;
  undefined4 local_18;
  
  iVar1 = param_1[0xf];
  local_18 = *(undefined4 *)(DAT_00009cc8 + 8);
  if (*(short *)((int)param_1 + 0x12) == 0) {
    (**(code **)(*param_1 + 4))(&local_18,iVar1,4,100);
    uVar4 = (*(ushort *)(iVar1 + 2) & 0xff) << 8 | (uint)(*(ushort *)(iVar1 + 2) >> 8);
  }
  else {
    fVar6 = (float)param_1[6];
    uVar5 = VectorSignedToFloat(param_1[2],(byte)(in_fpscr >> 0x15) & 3);
    fVar2 = (float)FUN_00025770(fVar6 + (float)param_1[5],uVar5);
    param_1[6] = (int)fVar2;
    iVar3 = (int)fVar2;
    if (iVar3 == (int)fVar6) {
      fVar2 = (float)param_1[6];
    }
    else {
      fVar2 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x15) & 3);
      in_fpscr = in_fpscr & 0xfffffff |
                 (uint)(ABS((float)param_1[5] * DAT_00009ccc) <= ABS(fVar2 - fVar6)) << 0x1d;
      fVar2 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x15) & 3);
      if ((byte)(in_fpscr >> 0x1d) == 0) {
        fVar2 = fVar2 + (float)param_1[5];
      }
      param_1[6] = (int)fVar2;
    }
    uVar4 = in_fpscr & 0xfffffff | (uint)(fVar2 < 0.0) << 0x1f;
    if (SUB41(uVar4 >> 0x1f,0) != NAN(fVar2)) {
      fVar6 = (float)VectorSignedToFloat(param_1[2],(byte)(uVar4 >> 0x15) & 3);
      fVar2 = fVar6 + fVar2;
    }
    uVar4 = VectorFloatToUnsigned(fVar2,3);
    uVar4 = uVar4 & 0xffff;
    *(char *)(iVar1 + 2) = (char)(uVar4 >> 8);
    *(char *)(iVar1 + 3) = (char)uVar4;
  }
  return uVar4 >> 1;
}




int FUN_00009bc2(int param_1)

{
  (**(code **)(param_1 + 0x54))();
  (**(code **)(param_1 + 0x58))(param_1);
  (**(code **)(param_1 + 0x48))(param_1);
  return *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x34);
}




int FUN_00009bde(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x28);
  iVar1 = *(int *)(param_1 + 8) >> 1;
  iVar2 = *(int *)(param_1 + 0x30);
  if (-iVar3 == iVar1 || -iVar1 < iVar3) {
    if (iVar3 <= iVar1) goto LAB_00009c00;
    iVar2 = iVar2 + -1;
  }
  else {
    iVar2 = iVar2 + 1;
  }
  *(int *)(param_1 + 0x30) = iVar2;
LAB_00009c00:
  iVar1 = (uint)(*(short *)(param_1 + 0x10) == 0) * *(int *)(param_1 + 8) * iVar2 +
          *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x2c) = iVar1;
  return iVar1;
}




undefined4 FUN_00009c16(undefined4 *param_1,code **param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_00023966(param_1,0x6c);
  param_1[0x10] = DAT_00009cd0;
  param_1[0x12] = 0x9bdf;
  param_1[0x13] = 0x9bc3;
  param_1[0x14] = 0x9b01;
  param_1[0x15] = 0x9ae9;
  param_1[0x16] = 0x9ad3;
  param_1[0x17] = &LAB_00009ab2_1;
  param_1[0x18] = 0x9a6b;
  param_1[0x19] = 0x9a25;
  param_1[0xf] = param_3;
  *param_1 = param_2;
  param_1[0x1a] = &LAB_00009a04_1;
  (**param_2)();
  FUN_00009c8a(param_1);
  (*(code *)param_1[0x15])(param_1);
  (*(code *)param_1[0x16])(param_1);
  (*(code *)param_1[0x16])(param_1);
  uVar1 = (*(code *)param_1[0x13])(param_1);
  param_1[0xd] = uVar1;
  return 1;
}




void FUN_00009c8a(int param_1)

{
  *(undefined4 *)(param_1 + 0x40) = DAT_00009cd0;
  *(undefined4 *)(param_1 + 0x44) = 0x9c17;
  *(undefined4 *)(param_1 + 0xc) = 1;
  *(undefined4 *)(param_1 + 4) = 0xf;
  *(undefined4 *)(param_1 + 8) = 0x8000;
  *(undefined2 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xbf800000;
  return;
}




void FUN_00009cb2(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  uVar1 = (**(code **)(param_1 + 0x4c))(param_1);
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  return;
}




undefined4 FUN_00009cd4(undefined4 *param_1,undefined4 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint in_fpscr;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined uStack_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined *local_28;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  
  pcVar1 = DAT_00009f0c;
  local_24 = 0xac;
  local_23 = (undefined)DAT_00009f08;
  local_22 = (undefined)((ushort)DAT_00009f08 >> 8);
  local_30 = 0x38;
  local_2e = 0;
  local_28 = &local_24;
  local_2c = 3;
  iVar2 = FUN_00014328(*(undefined4 *)(DAT_00009f0c + 4),&local_30,1);
  if (iVar2 == 1) {
    FUN_0001eb00(200);
    local_30 = 0x38;
    local_2c = 6;
    local_2e = 1;
    local_28 = &uStack_38;
    iVar2 = FUN_00014328(*(undefined4 *)(pcVar1 + 4),&local_30,1);
    if (iVar2 == 1) {
      if (*pcVar1 == '\0') {
        uVar6 = FUN_00026048((uint)local_37 << 0xc | (uint)local_36 << 4 | (uint)(local_35 >> 4));
        uVar6 = FUN_000260e8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)DAT_00009f10,
                             (int)((ulonglong)DAT_00009f10 >> 0x20));
        uVar3 = (undefined4)((ulonglong)DAT_00009f18 >> 0x20);
        uVar5 = (undefined4)DAT_00009f18;
        FUN_000260e8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar5,uVar3);
        uVar4 = FUN_00025a5c();
        *param_2 = uVar4;
        uVar6 = FUN_00026048(((uint)local_35 << 0x1c) >> 0xc | (uint)local_34 << 8 | (uint)local_33)
        ;
        uVar6 = FUN_000260e8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)DAT_00009f20,
                             (int)((ulonglong)DAT_00009f20 >> 0x20));
        uVar6 = FUN_000260e8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar5,uVar3);
        FUN_00026350((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)DAT_00009f28,
                     (int)((ulonglong)DAT_00009f28 >> 0x20));
        uVar4 = FUN_00025a5c();
        *param_1 = uVar4;
      }
      else {
        uVar4 = VectorSignedToFloat(*(undefined4 *)(pcVar1 + 0x10),(byte)(in_fpscr >> 0x15) & 3);
        *param_2 = uVar4;
        uVar4 = VectorSignedToFloat(*(undefined4 *)(pcVar1 + 0xc),(byte)(in_fpscr >> 0x15) & 3);
        *param_1 = uVar4;
      }
      return 0;
    }
  }
  return 1;
}




undefined4 FUN_00009de8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = param_3;
  uStack_14 = param_4;
  iVar2 = FUN_0001344c(&DAT_00009f30);
  iVar1 = DAT_00009f0c;
  *(int *)(DAT_00009f0c + 4) = iVar2;
  if (iVar2 == 0) {
    FUN_0001cd4c(s_can_t_find__s_device__00009f38,&DAT_00009f30);
    return 1;
  }
  bVar3 = 0;
  do {
    iVar2 = FUN_00009cd4(&uStack_18,&uStack_14);
    if (iVar2 == 0) goto LAB_00009e0e;
    bVar3 = bVar3 + 1;
  } while (bVar3 < 3);
  if (iVar2 == 1) {
    return 2;
  }
LAB_00009e0e:
  *(undefined4 *)(iVar1 + 8) = 1;
  return 0;
}




void FUN_00009e26(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  float fVar3;
  float local_20;
  float local_1c;
  undefined auStack_18 [8];
  
  local_20 = DAT_00009f50;
  local_1c = DAT_00009f50;
  if (param_1 == 2) {
    puVar2 = *(undefined **)(param_2 + 4);
  }
  else {
    puVar2 = &DAT_00009f30;
  }
  FUN_0001cff8(auStack_18,puVar2,8);
  iVar1 = DAT_00009f0c;
  if ((*(int *)(DAT_00009f0c + 8) == 0) && (FUN_00009de8(), *(int *)(iVar1 + 8) == 0)) {
    FUN_0001cd4c(s_initialize_sensor_failed__00009fac);
  }
  else {
    FUN_00009cd4(&local_1c,&local_20);
    FUN_0001cd4c(s_read_aht10_sensor_humidity____d__00009f54,(int)local_20,
                 (int)(local_20 * 10.0) % 10);
    if (local_1c < 0.0 == NAN(local_1c)) {
      fVar3 = local_1c * 10.0;
    }
    else {
      fVar3 = local_1c * -10.0;
    }
    FUN_0001cd4c(&DAT_00009f80,(int)local_1c,(int)fVar3 % 10);
  }
  return;
}




void FUN_00009ede(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_00009f0c;
  *DAT_00009f0c = 1;
  uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 4));
  *(undefined4 *)(puVar1 + 0xc) = uVar2;
  uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
  *(undefined4 *)(puVar1 + 0x10) = uVar2;
  FUN_0001cd4c(s_dbg_temp____d__dbg_humi____d_00009fc8,*(undefined4 *)(puVar1 + 0xc),uVar2);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00009fe8(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _DAT_0000a100;
  uVar2 = 0;
  do {
    *(undefined *)(iVar1 + uVar2) = 0xff;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00009ffc(int param_1,int param_2,int param_3)

{
  FUN_0000d078((int)(char)param_1,param_2 != 0);
  FUN_0000ce20((int)(char)param_1,param_3);
  if (param_3 != 0) {
    *(char *)(_DAT_0000a100 + param_1) = (char)param_2;
  }
  return 0;
}




void FUN_0000a02a(undefined4 param_1,undefined4 param_2)

{
  FUN_0001eb00(200);
  FUN_00009ffc(param_1,param_2,0xff);
  FUN_0001eb00(0x1e);
  FUN_0000ce20((int)(char)param_1,0);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000a052(int param_1)

{
  int iVar1;
  
  FUN_0000ce20((int)(char)param_1,0);
  iVar1 = _DAT_0000a100;
  if (*(char *)(_DAT_0000a100 + param_1) != -1) {
    FUN_0000a02a(param_1,*(char *)(_DAT_0000a100 + param_1) != '\x01');
    *(undefined *)(iVar1 + param_1) = 0xff;
  }
  return 0;
}




undefined4 FUN_0000a07e(void)

{
  byte bVar1;
  
  bVar1 = 0;
  do {
    FUN_0000a052(bVar1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return 0;
}




undefined4 FUN_0000a094(void)

{
  FUN_0000a07e();
  return 0;
}




int FUN_0000a09e(char param_1)

{
  int iVar1;
  
  iVar1 = FUN_0000d0b0((int)param_1);
  if (iVar1 != 1) {
    iVar1 = 0;
  }
  return iVar1;
}




undefined FUN_0000a0ae(char param_1)

{
  return *(undefined *)(DAT_0000d328 + (short)param_1 * 0xac + 0xa8);
}




undefined4 FUN_0000a0b4(void)

{
  int iVar1;
  
  iVar1 = FUN_0000a0ae();
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}




void FUN_0000a0c4(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  char *pcVar3;
  
  if (param_1 == 3) {
    bVar1 = FUN_00023590(*(undefined4 *)(param_2 + 4));
    if (bVar1 < 4) {
      bVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
      if (bVar2 < 2) {
        FUN_0000a02a(bVar1);
        return;
      }
      pcVar3 = s_dir_illegal_0000a138;
    }
    else {
      pcVar3 = s_id_is_between_0_to_3_0000a120;
    }
  }
  else {
    pcVar3 = s_detooth_test__id___dir__0000a103 + 1;
  }
  FUN_0001cd4c(pcVar3);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a18a(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = 0;
  puVar2 = (undefined2 *)(_DAT_0000a544 + -0x1e);
  do {
    *(undefined *)((int)puVar2 + iVar1) = *(undefined *)(param_1 + iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  *param_2 = *puVar2;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000a1a2(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)(_DAT_0000a544 + -0x24);
  uVar2 = param_4 & 0xfffffffc;
  if ((uVar2 != *pbVar3) && (iVar1 = FUN_000093dc(param_1,uVar2,param_3,param_2), iVar1 == 0)) {
    *pbVar3 = (byte)uVar2;
  }
  iVar1 = FUN_00009628(param_1,param_4,param_5);
  if (iVar1 != 0) {
    FUN_0001cd4c(s_card_read_failed__0000a547 + 1);
    iVar1 = 1;
  }
  return iVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000a1e2(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  undefined uVar6;
  byte bVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined auStack_4c [8];
  byte local_44 [9];
  undefined2 local_3b;
  undefined4 local_39;
  undefined local_35;
  undefined auStack_34 [20];
  
  iVar13 = DAT_0000a55c + (param_2 + param_1 * 2 & 0xffU) * 0x4c;
  FUN_0001cd4c(&DAT_0000a560);
  FUN_0001cd4c(s__s__d___d_0000a574,DAT_0000a570,param_1,param_2);
  FUN_0001cd4c(&DAT_0000a580);
  iVar2 = FUN_000096c8(param_1,param_2);
  iVar9 = _DAT_0000a588 + param_1 * 0x50 + param_2 * 0x28;
  iVar10 = iVar9 + 0x1d;
  if (iVar2 == 0) {
    iVar11 = _DAT_0000a5c4 + param_1 * 0x20 + param_2 * 0x10;
    FUN_00022d7e(iVar11 + 2,auStack_4c);
    iVar2 = _DAT_0000a544;
    puVar12 = (undefined *)(_DAT_0000a544 + -0x1c);
    iVar5 = FUN_0000a1a2(param_1,iVar11 + 2,auStack_4c,*puVar12,local_44);
    if (iVar5 == 0) {
      FUN_00022e0e(local_44,&local_64);
      local_44[0] = (byte)local_64;
      local_44[1] = (byte)((uint)local_64 >> 8);
      local_44[2] = (byte)((uint)local_64 >> 0x10);
      local_44[3] = (byte)((uint)local_64 >> 0x18);
      local_44[4] = (byte)uStack_60;
      local_44[5] = (byte)((uint)uStack_60 >> 8);
      local_44[6] = (byte)((uint)uStack_60 >> 0x10);
      local_44[7] = (byte)((uint)uStack_60 >> 0x18);
      local_44[8] = (byte)uStack_5c;
      local_3b = (undefined2)((uint)uStack_5c >> 8);
      local_39._1_3_ = (undefined3)uStack_58;
      local_39 = CONCAT31(local_39._1_3_,(char)((uint)uStack_5c >> 0x18));
      local_35 = (undefined)((uint)uStack_58 >> 0x18);
      *(byte *)(iVar9 + 0x1d) = local_44[0];
      *(short *)(iVar9 + 0x1e) = (short)((uint)local_64 >> 8);
      *(ushort *)(iVar9 + 0x20) = CONCAT11(local_44[4],local_44[3]);
      *(uint *)(iVar9 + 0x22) = CONCAT13(local_44[8],(int3)((uint)uStack_60 >> 8));
      *(undefined2 *)(iVar9 + 0x26) = local_3b;
      *(undefined4 *)(iVar9 + 0x28) = local_39;
      *(undefined *)(iVar9 + 0x2c) = local_35;
      iVar5 = FUN_0000a1a2(param_1,iVar11 + 2,auStack_4c,*(undefined *)(iVar2 + -0x1b),local_44);
      if (iVar5 == 0) {
        FUN_00022e0e(local_44,&local_64);
        local_44[0] = (byte)local_64;
        local_44[1] = (byte)((uint)local_64 >> 8);
        local_44[2] = (byte)((uint)local_64 >> 0x10);
        local_44[3] = (byte)((uint)local_64 >> 0x18);
        local_44[4] = (byte)uStack_60;
        local_44[5] = (byte)((uint)uStack_60 >> 8);
        local_44[6] = (byte)((uint)uStack_60 >> 0x10);
        local_44[7] = (byte)((uint)uStack_60 >> 0x18);
        local_44[8] = (byte)uStack_5c;
        local_3b = (undefined2)((uint)uStack_5c >> 8);
        local_39._1_3_ = (undefined3)uStack_58;
        local_39 = CONCAT31(local_39._1_3_,(char)((uint)uStack_5c >> 0x18));
        local_35 = (undefined)((uint)uStack_58 >> 0x18);
        *(byte *)(iVar9 + 0x2d) = local_44[0];
        *(uint *)(iVar9 + 0x2e) = CONCAT13(local_44[4],(int3)((uint)local_64 >> 8));
        *(short *)(iVar9 + 0x32) = (short)((uint)uStack_60 >> 8);
        *(byte *)(iVar9 + 0x34) = local_44[7];
        *(undefined4 *)(iVar9 + 0x35) = uStack_5c;
        *(undefined4 *)(iVar9 + 0x39) = uStack_58;
        iVar5 = FUN_0000a1a2(param_1,iVar11 + 2,auStack_4c,*(undefined *)(iVar2 + -0x1a),local_44);
        if (iVar5 == 0) {
          FUN_00022e0e(local_44,&local_64);
          local_44[0] = (byte)local_64;
          local_44[1] = (byte)((uint)local_64 >> 8);
          local_44[2] = (byte)((uint)local_64 >> 0x10);
          local_44[3] = (byte)((uint)local_64 >> 0x18);
          local_44[4] = (byte)uStack_60;
          local_44[5] = (byte)((uint)uStack_60 >> 8);
          local_44[6] = (byte)((uint)uStack_60 >> 0x10);
          local_44[7] = (byte)((uint)uStack_60 >> 0x18);
          local_44[8] = (byte)uStack_5c;
          local_3b = (undefined2)((uint)uStack_5c >> 8);
          local_39._1_3_ = (undefined3)uStack_58;
          local_39 = CONCAT31(local_39._1_3_,(char)((uint)uStack_5c >> 0x18));
          local_35 = (undefined)((uint)uStack_58 >> 0x18);
          *(short *)(iVar9 + 0x3d) = (short)local_64;
          *(uint *)(iVar9 + 0x3f) =
               CONCAT13(local_44[5],CONCAT12(local_44[4],(short)((uint)local_64 >> 0x10)));
          *(short *)(iVar9 + 0x43) = (short)((uint)uStack_60 >> 0x10);
          goto LAB_0000a296;
        }
        FUN_00023922(iVar10,0x28);
        uVar6 = *(undefined *)(iVar2 + -0x1a);
      }
      else {
        FUN_00023922(iVar10,0x28);
        uVar6 = *(undefined *)(iVar2 + -0x1b);
      }
    }
    else {
      uVar6 = *puVar12;
    }
    FUN_0001cd4c(s_read_vector__d_is_failed__0000a5c7 + 1,uVar6);
  }
  else {
    iVar2 = FUN_000096ea(param_1,4,local_44);
    if (iVar2 == 0) {
      iVar2 = FUN_000096ea(param_1,8,auStack_34);
      if (iVar2 == 0) {
        uVar4 = 0;
        do {
          bVar7 = local_44[uVar4];
          bVar1 = bVar7 >> 4;
          bVar7 = bVar7 & 0xf;
          if (bVar1 < 10) {
            cVar8 = '0';
          }
          else {
            cVar8 = '7';
          }
          *(byte *)(iVar10 + uVar4 * 2) = bVar1 + cVar8;
          if (bVar7 < 10) {
            cVar8 = bVar7 + 0x30;
          }
          else {
            cVar8 = bVar7 + 0x37;
          }
          iVar2 = uVar4 * 2;
          uVar4 = uVar4 + 1 & 0xff;
          *(char *)(iVar10 + iVar2 + 1) = cVar8;
        } while (uVar4 < 0x14);
LAB_0000a296:
        FUN_000237a0(iVar13 + 0x14,iVar10,0x28);
        return 0;
      }
      pcVar3 = s_read_vector_8_is_failed__0000a5a8;
    }
    else {
      pcVar3 = s_read_vector_4_is_failed__0000a58b + 1;
    }
    FUN_0001cd4c(pcVar3);
  }
  return 1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000a40c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0000a55c + (param_2 + param_1 * 2 & 0xffU) * 0x4c;
  iVar1 = FUN_000002e2();
  if (iVar1 != 0) {
    iVar1 = FUN_00012104(iVar2);
    return iVar1;
  }
  iVar1 = FUN_000093a2(param_1,param_2);
  if (iVar1 == 0) {
    FUN_000237a0(iVar2 + 0x3c,_DAT_0000a5c4 + param_1 * 0x20 + param_2 * 0x10,0x10);
  }
  return iVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000a474(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_0000a55c + (param_2 + param_1 * 2 & 0xffU) * 0x4c;
  uVar2 = 0;
  do {
    if (param_3 <= uVar2) {
      return 1;
    }
    iVar1 = FUN_000002e2();
    if (iVar1 == 0) {
      if (uVar2 != 0) {
        FUN_000093a2(param_1,param_2);
      }
      iVar1 = FUN_0000a1e2(param_1,param_2,1);
      FUN_00008f50(param_1,0);
      if (iVar1 == 0) {
        return 0;
      }
LAB_0000a4d8:
      FUN_0001eb00(10);
    }
    else if ((uVar2 == 0) || (iVar1 = FUN_00012104(iVar3), iVar1 == 0)) {
      iVar1 = FUN_0001220a(iVar3);
      if (iVar1 == 0) {
        FUN_000237a0(_DAT_0000a588 + param_1 * 0x50 + param_2 * 0x28 + 0x1d,iVar3 + 0x14,0x28);
        return 0;
      }
      goto LAB_0000a4d8;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 thunk_FUN_0000a474(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_0000a55c + (param_2 + param_1 * 2 & 0xffU) * 0x4c;
  uVar2 = 0;
  do {
    if (param_3 <= uVar2) {
      return 1;
    }
    iVar1 = FUN_000002e2();
    if (iVar1 == 0) {
      if (uVar2 != 0) {
        FUN_000093a2(param_1,param_2);
      }
      iVar1 = FUN_0000a1e2(param_1,param_2,1);
      FUN_00008f50(param_1,0);
      if (iVar1 == 0) {
        return 0;
      }
LAB_0000a4d8:
      FUN_0001eb00(10);
    }
    else if ((uVar2 == 0) || (iVar1 = FUN_00012104(iVar3), iVar1 == 0)) {
      iVar1 = FUN_0001220a(iVar3);
      if (iVar1 == 0) {
        FUN_000237a0(_DAT_0000a588 + param_1 * 0x50 + param_2 * 0x28 + 0x1d,iVar3 + 0x14,0x28);
        return 0;
      }
      goto LAB_0000a4d8;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 thunk_FUN_0000a474(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_0000a55c + (param_2 + param_1 * 2 & 0xffU) * 0x4c;
  uVar2 = 0;
  do {
    if (param_3 <= uVar2) {
      return 1;
    }
    iVar1 = FUN_000002e2();
    if (iVar1 == 0) {
      if (uVar2 != 0) {
        FUN_000093a2(param_1,param_2);
      }
      iVar1 = FUN_0000a1e2(param_1,param_2,1);
      FUN_00008f50(param_1,0);
      if (iVar1 == 0) {
        return 0;
      }
LAB_0000a4d8:
      FUN_0001eb00(10);
    }
    else if ((uVar2 == 0) || (iVar1 = FUN_00012104(iVar3), iVar1 == 0)) {
      iVar1 = FUN_0001220a(iVar3);
      if (iVar1 == 0) {
        FUN_000237a0(_DAT_0000a588 + param_1 * 0x50 + param_2 * 0x28 + 0x1d,iVar3 + 0x14,0x28);
        return 0;
      }
      goto LAB_0000a4d8;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}




undefined FUN_0000a510(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 + param_1 * 2 & 0xff;
  if ((uVar1 < 4) && (iVar2 = DAT_0000a55c + uVar1 * 0x4c, 3 < *(byte *)(iVar2 + 0x4b))) {
    FUN_000237a0(param_3,iVar2 + 0x3e);
    return *(undefined *)(iVar2 + 0x4b);
  }
  return 0;
}




void FUN_0000a5e8(undefined4 param_1)

{
  FUN_00007d82(0x60,param_1,0x10);
  *(undefined *)(DAT_0000a9d0 + 1) = 0;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000a5fc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0000a9d0;
  if ((*(char *)(DAT_0000a9d0 + 1) == '\0') &&
     (iVar2 = FUN_00007cc6(0x60,_DAT_0000a9d4,0x10), iVar2 == 0)) {
    FUN_0001cd4c(&DAT_0000a560);
    FUN_0001cd4c(s_rfid_key_read_ok__0x_02x_0x_02x_0000a9d7 + 1,*_DAT_0000a9d4,_DAT_0000a9d4[1]);
    FUN_0001cd4c(&DAT_0000a580);
    *(undefined *)(iVar1 + 1) = 1;
  }
  if (param_1 != 0) {
    FUN_000237a0(param_1,_DAT_0000a9d4,0x10);
  }
  return 0x10;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000a642(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 4) {
    iVar2 = _DAT_0000a9d4 + 0x10 + param_1 * 0x4c;
    *(undefined *)(iVar2 + 0x4b) = 0;
    while (iVar1 = FUN_00012104(iVar2), iVar1 == 1) {
      if ((param_2 == 0) || (param_2 = param_2 - 1 & 0xff, param_2 == 0)) {
        return 1;
      }
    }
  }
  else {
    iVar1 = 5;
  }
  return iVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000a67c(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 4) {
    iVar2 = _DAT_0000a9d4 + 0x10;
    while (iVar1 = FUN_0001220a(iVar2 + param_1 * 0x4c), iVar1 != 0) {
      if ((param_2 == 0) || (param_2 = param_2 - 1 & 0xff, param_2 == 0)) {
        return 3;
      }
    }
  }
  else {
    iVar1 = 5;
  }
  return iVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000a6b0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_0001cd4c(&DAT_0000a560);
  FUN_0001cd4c(s__s_ch__d_0000aa00,DAT_0000a9fc,param_1);
  FUN_0001cd4c(&DAT_0000a580);
  if (3 < param_1) {
    return 5;
  }
  iVar1 = DAT_0000aa0c + param_1 * 100;
  uVar2 = FUN_0000b534(param_1);
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  *(undefined *)(iVar1 + 0x16) = 1;
  iVar3 = DAT_0000a9d0;
  *(undefined *)(iVar1 + 0x15) = 0;
  *(char *)(iVar3 + 2) = (char)param_1;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  FUN_0001cd4c(&DAT_0000a560);
  iVar3 = (int)(*(float *)(iVar1 + 0xc) * _DAT_0000aa10);
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  FUN_0001cd4c(s_B_s___d__02dmm_0000aa13 + 1,DAT_0000a9fc,(int)*(float *)(iVar1 + 0xc),iVar3 % 100);
  FUN_0001cd4c(&DAT_0000a580);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000a744(uint param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  FUN_0001cd4c(&DAT_0000a560);
  FUN_0001cd4c(s__s_ch__d_0000aa00,DAT_0000a9fc + 0x14,param_1);
  FUN_0001cd4c(&DAT_0000a580);
  if (3 < param_1) {
    return 5;
  }
  piVar1 = (int *)(DAT_0000aa0c + param_1 * 100);
  fVar2 = (float)FUN_0000b534(param_1);
  fVar4 = (float)piVar1[3];
  piVar1[3] = (int)fVar2;
  fVar2 = fVar2 - fVar4;
  *(undefined *)((int)piVar1 + 0x16) = 0;
  if ((fVar2 != 0.0 && fVar2 < 0.0 == NAN(fVar2)) && ((int)fVar2 < _DAT_0000aa24)) {
    iVar3 = VectorFloatToUnsigned(fVar2,3);
    *piVar1 = iVar3 + *piVar1;
  }
  *(undefined *)(DAT_0000a9d0 + 2) = 4;
  return 0;
}




undefined4 FUN_0000a7bc(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_0001cd4c(&DAT_0000a560);
  FUN_0001cd4c(s__s_ch__d_0000aa00,DAT_0000a9fc + 0x27,param_1);
  FUN_0001cd4c(&DAT_0000a580);
  if (3 < param_1) {
    return 5;
  }
  piVar1 = (int *)(DAT_0000aa0c + param_1 * 100);
  iVar2 = FUN_0000b534(param_1);
  piVar1[3] = iVar2;
  *(undefined *)((int)piVar1 + 0x16) = 2;
  *(undefined *)((int)piVar1 + 0x15) = 1;
  *piVar1 = *piVar1 + 0xf;
  iVar2 = FUN_0001a1aa();
  piVar1[2] = iVar2;
  *(char *)(DAT_0000a9d0 + 2) = (char)param_1;
  return 0;
}




undefined4 FUN_0000a818(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  
  FUN_0001cd4c(&DAT_0000a560);
  FUN_0001cd4c(s_C_s_ch__d__percent__d_0000aa27 + 1,DAT_0000a9fc + 0x3a,param_1,param_2);
  FUN_0001cd4c(&DAT_0000a580);
  if (param_1 < 4) {
    piVar5 = (int *)(DAT_0000aa0c + param_1 * 100);
    FUN_000238ae(piVar5 + 6,DAT_0000aa0c + -0x130 + param_1 * 0x4c,0x4c);
    *(char *)(piVar5 + 5) = (char)param_2;
    iVar2 = 0;
    *piVar5 = 0;
    *(undefined *)((int)piVar5 + 0x17) = 1;
    if (*(byte *)((int)piVar5 + 0x45) - 0x30 < 10) {
      iVar2 = (uint)*(byte *)((int)piVar5 + 0x45) * 100 + -0x12c0;
    }
    if (*(byte *)((int)piVar5 + 0x46) - 0x30 < 10) {
      iVar2 = iVar2 + (uint)*(byte *)((int)piVar5 + 0x46) * 10 + -0x1e0;
    }
    if (*(byte *)((int)piVar5 + 0x47) - 0x30 < 10) {
      iVar2 = iVar2 + -0x30 + (uint)*(byte *)((int)piVar5 + 0x47);
    }
    uVar3 = iVar2 * 1000;
    uVar4 = uVar3;
    if ((*(char *)((int)piVar5 + 99) != '\x04') && (uVar4 = piVar5[7], uVar4 < 10000)) {
      piVar5[7] = uVar3;
      uVar4 = uVar3;
    }
    piVar5[1] = uVar4;
    FUN_0001cd4c(&DAT_0000a560);
    FUN_0001cd4c(s__s_total_mm__d_0000aa40,DAT_0000a9fc + 0x3a,piVar5[1]);
    FUN_0001cd4c(&DAT_0000a580);
    if (*(char *)((int)piVar5 + 99) == '\a') {
      uVar3 = (uint)(piVar5[1] * 0x67) / 100;
      uVar4 = piVar5[9];
      if (uVar4 < uVar3) {
        uVar3 = ((uVar3 - uVar4) * 100) / uVar3;
      }
      else {
        uVar3 = 0;
      }
      if ((param_2 < 0x5a) && (param_2 + 10 < uVar3)) {
        uVar3 = param_2 + 5;
        uVar6 = (piVar5[1] * (100 - uVar3)) / 100;
        if (uVar4 < uVar6) {
          *piVar5 = uVar6 - uVar4;
        }
        FUN_0001cd4c(&DAT_0000a560);
        FUN_0001cd4c(s__s_used_mm__dmm_used_inc__dmm_0000aa50,DAT_0000a9fc + 0x3a,uVar6,*piVar5);
        FUN_0001cd4c(&DAT_0000a580);
        *(undefined *)((int)piVar5 + 0x15) = 1;
      }
      FUN_00002224(param_1,uVar3 & 0xff);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}




undefined4 FUN_0000aa74(uint param_1)

{
  undefined4 *puVar1;
  
  if (3 < param_1) {
    return 5;
  }
  puVar1 = (undefined4 *)(DAT_0000ae64 + param_1 * 100);
  *(undefined *)((int)puVar1 + 0x17) = 0;
  *puVar1 = 0;
  *(undefined *)((int)puVar1 + 0x15) = 0;
  *(undefined *)((int)puVar1 + 0x16) = 0;
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000aa98(void)

{
  bool bVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint in_fpscr;
  float fVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  
  iVar6 = DAT_0000ae68;
  bVar1 = false;
  uVar9 = (uint)*(byte *)(DAT_0000ae68 + 2);
  if (uVar9 < 4) {
    piVar7 = (int *)(DAT_0000ae64 + uVar9 * 100);
    iVar8 = DAT_0000ae6c + uVar9 * 0x4c;
    fVar10 = (float)FUN_0000b534(uVar9);
    if (*(char *)((int)piVar7 + 0x16) != '\0') {
      if (*(char *)((int)piVar7 + 0x16) == '\x02') {
        iVar11 = FUN_0001a1aa();
        if (&DAT_00007530 < (undefined *)(iVar11 - piVar7[2])) {
          FUN_0000a744(uVar9);
          return;
        }
        if (((*(char *)((int)piVar7 + 0x17) != '\0') && (*(char *)((int)piVar7 + 99) == '\a')) &&
           (*piVar7 != 0)) {
          *(undefined *)((int)piVar7 + 0x15) = 1;
        }
        piVar7[4] = 0;
      }
      else {
        fVar13 = fVar10 - (float)piVar7[3];
        if ((*(char *)((int)piVar7 + 0x15) == '\0') && ((int)fVar13 < DAT_0000ae70)) {
          return;
        }
        if (DAT_0000ae70 <= (int)fVar13) {
          FUN_0001cd4c(&DAT_0000a560);
          fVar2 = _DAT_0000aa10;
          iVar11 = (int)(fVar10 * _DAT_0000aa10);
          if (iVar11 < 0) {
            iVar11 = -iVar11;
          }
          FUN_0001cd4c(s__s_pos___d__02dmm_0000ae78,DAT_0000ae74,(int)fVar10,iVar11 % 100);
          FUN_0001cd4c(&DAT_0000a580);
          iVar12 = VectorFloatToUnsigned(fVar13,3);
          fVar10 = (float)VectorUnsignedToFloat(iVar12,(byte)(in_fpscr >> 0x15) & 3);
          piVar7[3] = (int)((float)piVar7[3] + fVar10);
          *piVar7 = *piVar7 + iVar12;
          *(undefined *)((int)piVar7 + 0x15) = 1;
          bVar1 = true;
          *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + iVar12;
          FUN_0001cd4c(&DAT_0000a560);
          iVar11 = (int)((float)piVar7[3] * fVar2);
          if (iVar11 < 0) {
            iVar11 = -iVar11;
          }
          FUN_0001cd4c(s__s___d__02dmm_used__dmm_total__d_0000ae8c,DAT_0000ae74,
                       (int)(float)piVar7[3],iVar11 % 100,iVar12,*(undefined4 *)(iVar6 + 0x1c));
          FUN_0001cd4c(&DAT_0000a580);
        }
        if ((*(char *)((int)piVar7 + 0x17) != '\0') && (*(char *)((int)piVar7 + 99) == '\x04')) {
          *(undefined *)((int)piVar7 + 0x15) = 0;
          if (piVar7[1] == 0) {
            return;
          }
          uVar4 = (uint)(*piVar7 * 100) / (uint)piVar7[1] & 0xff;
          uVar3 = (uint)*(byte *)(piVar7 + 5);
          if (100 < uVar3) {
            return;
          }
          if (uVar4 < uVar3) {
            uVar3 = uVar3 - uVar4 & 0xff;
          }
          else {
            uVar3 = 0;
          }
          if (*(byte *)(iVar6 + 3) == uVar3) {
            return;
          }
          *(char *)(iVar6 + 3) = (char)uVar3;
          FUN_00002224(uVar9,uVar3);
          FUN_0001cd4c(&DAT_0000a560);
          FUN_0001cd4c(s__s_old_percent__d_0000aeb0,DAT_0000ae74,uVar3);
          FUN_0001cd4c(&DAT_0000a580);
        }
      }
      if (*(char *)((int)piVar7 + 0x15) != '\0') {
        if (*(char *)((int)piVar7 + 0x16) == '\x01') {
          *(undefined *)((int)piVar7 + 0x15) = 0;
          uVar5 = 2;
        }
        else {
          uVar5 = 1;
        }
        iVar11 = FUN_0000a642(uVar9,uVar5);
        if (iVar11 == 0) {
          if (*(char *)((int)piVar7 + 0x17) == '\0') {
            if (0x14 < (uint)piVar7[4]) {
              FUN_0001cd4c(&DAT_0000a560);
              FUN_0001cd4c(s_not_tag_cnt__d_0000af00,piVar7[4]);
              FUN_0001cd4c(&DAT_0000a580);
              iVar6 = DAT_0000ae64 + (uint)*(byte *)(DAT_0000ae68 + 0x20 + uVar9) * 100;
              if (((*(char *)(iVar6 + 0x17) == '\0') ||
                  (*(char *)(iVar8 + 0x4b) != *(char *)(iVar6 + 99))) ||
                 (iVar6 = FUN_00023614(iVar8 + 0x3e,iVar6 + 0x56), iVar6 != 0)) {
                iVar6 = (int)(uVar9 << 0x1e) >> 0x1f;
                iVar11 = FUN_0000a474(-iVar6,uVar9 & 1,3);
                if (iVar11 == 0) {
                  FUN_0001cd4c(&DAT_0000af10);
                  FUN_0001cd4c(s_fila_save_CH_d_NUM__d_ID__02X__0_0000af20,uVar9 + 1,
                               *(undefined *)(iVar8 + 0x4b),*(undefined *)(iVar8 + 0x3e),
                               *(undefined *)(iVar8 + 0x3f),*(undefined *)(iVar8 + 0x40),
                               *(undefined *)(iVar8 + 0x41));
                  FUN_0001cd4c(&DAT_0000a580);
                  FUN_00002280(uVar9,DAT_0000af50 + iVar6 * -0x50 + (uVar9 & 1) * 0x28 + 0x1d);
                  FUN_0000a818(uVar9,100);
                }
              }
            }
            piVar7[4] = 0;
          }
          else if (*(char *)(iVar8 + 0x4b) == '\a') {
            iVar8 = FUN_00023614(iVar8 + 0x3e,(int)piVar7 + 0x56,7);
            if (iVar8 == 0) {
              iVar11 = piVar7[9];
              iVar12 = iVar11 + *piVar7;
              iVar8 = FUN_0001271a(piVar7 + 6,iVar12);
              if (iVar8 == 0) {
                *piVar7 = 0;
                *(undefined *)((int)piVar7 + 0x15) = 0;
                if (0x117 < (uint)(iVar12 - *(int *)(iVar6 + 0x18))) {
                  *(int *)(iVar6 + 0x18) = iVar12;
                  *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
                  *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
                  iVar8 = FUN_0000c5ca();
                  if (iVar8 != 0) {
                    FUN_0001cd4c(s_rfid_write_used__dmm_percent__d__0000aec4,piVar7[9],piVar7[8],
                                 *(undefined4 *)(iVar6 + 0xc),*(undefined4 *)(iVar6 + 0x10),
                                 *(undefined4 *)(iVar6 + 0x14));
                    FUN_000232a8(s_rfid_write_used__dmm_percent__d__0000aec4,piVar7[9],piVar7[8],
                                 *(undefined4 *)(iVar6 + 0xc),*(undefined4 *)(iVar6 + 0x10),
                                 *(undefined4 *)(iVar6 + 0x14));
                  }
                }
                FUN_00002224(uVar9,*(undefined *)(piVar7 + 8));
                return;
              }
              piVar7[9] = iVar11;
              if (0x117 < (uint)(iVar12 - *(int *)(iVar6 + 0x18))) {
                *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + 1;
                *(int *)(iVar6 + 0x18) = iVar12;
                *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
                iVar8 = FUN_0000c5ca();
                if (iVar8 != 0) {
                  FUN_0001cd4c(s_rfid_write_used__dmm_percent__d__0000aec4,piVar7[9],piVar7[8],
                               *(undefined4 *)(iVar6 + 0xc),*(undefined4 *)(iVar6 + 0x10),
                               *(undefined4 *)(iVar6 + 0x14));
                  FUN_000232a8(s_rfid_write_used__dmm_percent__d__0000aec4,piVar7[9],piVar7[8],
                               *(undefined4 *)(iVar6 + 0xc),*(undefined4 *)(iVar6 + 0x10),
                               *(undefined4 *)(iVar6 + 0x14));
                }
              }
            }
          }
          else {
            *(undefined *)((int)piVar7 + 0x15) = 0;
          }
        }
        else if ((iVar11 == 1) && (bVar1)) {
          piVar7[4] = piVar7[4] + 1;
        }
      }
    }
  }
  return;
}




uint FUN_0000ae38(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  do {
    iVar3 = DAT_0000ae64 + uVar2 * 100;
    if (*(char *)(iVar3 + 0x17) != '\0') {
      cVar1 = *(char *)(iVar3 + 99);
      if (cVar1 == '\a') {
        return uVar2;
      }
      if (cVar1 == '\x04') {
        return uVar2;
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
    if (3 < uVar2) {
      return 0xff;
    }
  } while( true );
}




void FUN_0000af54(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_78 [10];
  undefined4 local_50 [10];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  FUN_000238ae(local_50,DAT_0000b354,0x28);
  local_78[9] = DAT_0000b358 + param_1 * 0x50 + param_2 * 0x28;
  local_78[0] = local_78[9] + 0x20;
  local_78[1] = local_78[9] + 0x1d;
  local_78[2] = local_78[9] + 0x1e;
  local_78[3] = local_78[9] + 0x22;
  local_78[4] = local_78[9] + 0x26;
  local_78[5] = local_78[9] + 0x28;
  local_78[6] = local_78[9] + 0x2e;
  local_78[7] = local_78[9] + 0x35;
  local_78[8] = local_78[9] + 0x39;
  local_78[9] = local_78[9] + 0x3f;
  local_28 = DAT_0000b35c;
  uStack_24 = DAT_0000b360;
  uStack_20 = DAT_0000b364;
  iVar1 = FUN_0000c5ca();
  if (iVar1 == 0) {
    FUN_0001cd4c(s_____________base__d_info_________0000b368,param_1);
    uVar2 = 0;
    do {
      FUN_0001cd4c(s__s_is_0000b390,local_50[uVar2]);
      for (uVar3 = 0; uVar3 < *(byte *)((int)&local_28 + uVar2); uVar3 = uVar3 + 1 & 0xff) {
        FUN_0001cd4c(&DAT_0000b398,*(undefined *)(local_78[uVar2] + uVar3));
      }
      FUN_0001cd4c(&DAT_0000a584);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 10);
  }
  else {
    FUN_0001cd4c(s_____________base__d_info_________0000b368,param_1);
    FUN_000232a8(s_____________base__d_info_________0000b368,param_1);
    uVar2 = 0;
    do {
      FUN_0001cd4c(s__s_is_0000b390,local_50[uVar2]);
      FUN_000232a8(s__s_is_0000b390,local_50[uVar2]);
      for (uVar3 = 0; uVar3 < *(byte *)((int)&local_28 + uVar2); uVar3 = uVar3 + 1 & 0xff) {
        FUN_0001cd4c(&DAT_0000b398,*(undefined *)(local_78[uVar2] + uVar3));
        FUN_000232a8(&DAT_0000b398,*(undefined *)(local_78[uVar2] + uVar3));
      }
      FUN_0001cd4c(&DAT_0000a584);
      FUN_000232a8(&DAT_0000a584);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 10);
  }
  return;
}




void FUN_0000b06c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int local_78 [10];
  undefined4 local_50 [10];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  FUN_000238ae(local_50,DAT_0000b354 + 0x28,0x28);
  local_78[9] = DAT_0000b358 + param_1 * 0x50 + param_2 * 0x28;
  local_78[0] = local_78[9] + 0x20;
  local_78[1] = local_78[9] + 0x1d;
  local_78[2] = local_78[9] + 0x1e;
  local_78[3] = local_78[9] + 0x22;
  local_78[4] = local_78[9] + 0x26;
  local_78[5] = local_78[9] + 0x28;
  local_78[6] = local_78[9] + 0x2e;
  local_78[7] = local_78[9] + 0x35;
  local_78[8] = local_78[9] + 0x39;
  local_78[9] = local_78[9] + 0x3f;
  local_28 = DAT_0000b35c;
  uStack_24 = DAT_0000b360;
  uStack_20 = DAT_0000b364;
  FUN_0001cd4c(s_____________base__d_info_________0000b368,param_1);
  FUN_000232a8(s_____________base__d_info_________0000b368,param_1);
  uVar1 = 0;
  do {
    FUN_0001cd4c(s__s_is_0000b390,local_50[uVar1]);
    FUN_000232a8(s__s_is_0000b390,local_50[uVar1]);
    for (uVar2 = 0; uVar2 < *(byte *)((int)&local_28 + uVar1); uVar2 = uVar2 + 1 & 0xff) {
      FUN_0001cd4c(&DAT_0000b398,*(undefined *)(local_78[uVar1] + uVar2));
      FUN_000232a8(&DAT_0000b398,*(undefined *)(local_78[uVar1] + uVar2));
    }
    FUN_0001cd4c(&DAT_0000a584);
    FUN_000232a8(&DAT_0000a584);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  return;
}




void FUN_0000b138(int param_1,int param_2)

{
  FUN_0001cd4c(s_____________high__d_info_________0000b39c,param_1);
  FUN_0001cd4c(s_now_length____d_0000b3c4,
               (int)*(float *)(DAT_0000b358 + param_1 * 0x10 + param_2 * 8 + 0xc0));
  return;
}




undefined4 FUN_0000b166(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  iVar1 = FUN_0000216c();
  if ((iVar1 == 0) || (*(byte *)(DAT_0000b3d8 + 1) != param_2)) {
    puVar3 = (undefined *)FUN_00002298(param_2);
    if (puVar3 != (undefined *)0x0) {
      *(undefined *)param_1 = *puVar3;
      *(undefined2 *)((int)param_1 + 1) = *(undefined2 *)(puVar3 + 1);
      *(undefined2 *)((int)param_1 + 3) = *(undefined2 *)(puVar3 + 3);
      *(undefined4 *)((int)param_1 + 5) = *(undefined4 *)(puVar3 + 5);
      *(undefined2 *)((int)param_1 + 9) = *(undefined2 *)(puVar3 + 9);
      *(undefined4 *)((int)param_1 + 0xb) = *(undefined4 *)(puVar3 + 0xb);
      *(undefined2 *)((int)param_1 + 0xf) = *(undefined2 *)(puVar3 + 0xf);
      *(undefined4 *)((int)param_1 + 0x11) = *(undefined4 *)(puVar3 + 0x11);
      *(undefined2 *)((int)param_1 + 0x15) = *(undefined2 *)(puVar3 + 0x15);
      *(undefined *)((int)param_1 + 0x17) = puVar3[0x17];
      param_1[6] = *(undefined4 *)(puVar3 + 0x18);
      param_1[7] = *(undefined4 *)(puVar3 + 0x1c);
      *(undefined2 *)(param_1 + 8) = *(undefined2 *)(puVar3 + 0x20);
      *(undefined4 *)((int)param_1 + 0x22) = *(undefined4 *)(puVar3 + 0x22);
      *(undefined2 *)((int)param_1 + 0x26) = *(undefined2 *)(puVar3 + 0x26);
      return 0x28;
    }
    iVar1 = FUN_0000b694(param_2,0);
    if (iVar1 == 0) {
      *param_1 = s_unknown_0000b3ec._0_4_;
      *(undefined2 *)(param_1 + 1) = s_unknown_0000b3ec._4_2_;
      *(undefined *)((int)param_1 + 6) = 0x6e;
      return 7;
    }
    puVar2 = &DAT_0000b3e4;
  }
  else {
    puVar2 = &DAT_0000b3dc;
  }
  *param_1 = *puVar2;
  return 4;
}




void FUN_0000b23a(undefined4 param_1)

{
  int iVar1;
  
  FUN_000002a8();
  iVar1 = FUN_000002e2();
  if (iVar1 != 1) {
    FUN_000089d8(param_1);
    return;
  }
  FUN_000110e0();
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000b25c(int param_1,int param_2)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_1 < 2) {
LAB_0000b2aa:
    FUN_0001cd4c(s_Usage__0000b41c);
    FUN_0001cd4c(s_rfid_init_<card_id>__rfid_connec_0000b428);
    FUN_0001cd4c(DAT_0000b464);
  }
  else {
    iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_0000b3f4);
    iVar3 = _DAT_0000b3fc;
    if (iVar2 == 0) {
      if (param_1 == 3) {
        iVar2 = FUN_000002e2();
        if (iVar2 == 0) {
          FUN_0001cd4c(s_fm176xx_0000b540);
        }
        uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 8));
        FUN_0000a40c(uVar1,0);
        *(undefined *)(iVar3 + 4) = 1;
        return 0;
      }
      pcVar4 = s_rfid_init_<card_id>__rfid_connec_0000b428;
      goto LAB_0000b50c;
    }
    if (*(char *)(_DAT_0000b3fc + 4) == '\0') {
      FUN_0001cd4c(s_Please_using__rfid_init_<card_id_0000b468);
      return 0xffffff01;
    }
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_write_0000b3ff + 1);
    if (iVar3 == 0) {
      pcVar4 = DAT_0000b464;
      if (3 < param_1) {
        iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 0xc),&DAT_0000b494);
        bVar6 = iVar3 == 0;
        do {
          if (bVar6) {
            return 0;
          }
          iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 0xc),&DAT_0000b49c);
          bVar6 = iVar3 == 0;
          pcVar4 = DAT_0000b464;
        } while (bVar6);
      }
      goto LAB_0000b50c;
    }
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_0000b408);
    if (iVar3 != 0) {
      iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_0000b410);
      if (iVar3 == 0) {
        FUN_0001cd4c(&DAT_0000b4f0);
        iVar3 = DAT_0000b4f8;
        uVar5 = 0;
        do {
          FUN_0001cd4c(s__02X_0000b4fc,*(undefined *)(iVar3 + uVar5));
          uVar5 = uVar5 + 1 & 0xff;
        } while (uVar5 < 0x10);
        pcVar4 = s_rfid_init_<card_id>__rfid_connec_0000b428 + 0x38;
        goto LAB_0000b50c;
      }
      iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_0000b414);
      if (iVar3 == 0) {
LAB_0000b322:
        uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 8));
        FUN_0000af54(uVar1,0);
        return 0;
      }
      goto LAB_0000b2aa;
    }
    if (param_1 == 4) {
      iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 0xc),&DAT_0000b494);
      if (iVar3 == 0) {
        uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 8));
        iVar3 = FUN_0000a474(uVar1,0,2);
        if (iVar3 == 0) goto LAB_0000b322;
        pcVar4 = s_read_failed__0000b4e0;
        goto LAB_0000b50c;
      }
      iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 0xc),&DAT_0000b49c);
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  pcVar4 = s_rfid_read_<card_id>_<base_high>___0000b4a4;
LAB_0000b50c:
  FUN_0001cd4c(pcVar4);
  return 0;
}




float FUN_0000b534(void)

{
  float fVar1;
  
  fVar1 = (float)FUN_0000840a();
  return -fVar1;
}




undefined FUN_0000b590(int param_1)

{
  undefined uVar1;
  
  uVar1 = FUN_00015bec(*(undefined4 *)(DAT_0000b7d8 + param_1 * 4));
  return uVar1;
}




undefined FUN_0000b5a0(int param_1)

{
  undefined uVar1;
  
  uVar1 = FUN_00015bec(*(undefined4 *)(DAT_0000b7d8 + param_1 * 4 + 0x10));
  return uVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0000b5b2(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (uVar2 != param_1) {
      iVar1 = FUN_0000b5a0(uVar2 & 0xff);
      if (iVar1 == 0) {
        iVar1 = FUN_00001b28(uVar2 & 0xff);
        if (iVar1 != 0) {
          *_DAT_0000b7dc = (char)uVar2;
          return iVar1;
        }
        FUN_0000da2c();
      }
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 4);
  return 0;
}




undefined4 FUN_0000b5e0(uint param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = 0;
  if (param_1 < 4) {
    *param_2 = (char)param_1;
    iVar1 = FUN_0000b5a0();
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    uVar2 = 0;
    do {
      iVar1 = FUN_0000b5a0(uVar2 & 0xff);
      if (iVar1 == 0) {
        bVar3 = bVar3 + 1;
        *param_2 = (char)uVar2;
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 4);
    if (bVar3 != 0) {
      if (1 < bVar3) {
        return 0x15;
      }
      return 0;
    }
  }
  return 0x16;
}




undefined4 FUN_0000b61e(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    iVar1 = FUN_0000b590(uVar2);
    if (iVar1 == 0) {
      uVar3 = 1 << uVar2 & 0xffU | uVar3;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  if (param_1 < 4) {
    if ((uVar3 & 1 << (param_1 & 0xff) & 0xffU) == 0) {
      return 0x16;
    }
  }
  else if (uVar3 == 0) {
    return 0x18;
  }
  return 0;
}




undefined4 FUN_0000b65e(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = param_4;
  while( true ) {
    bVar4 = param_2 == 0;
    param_2 = param_2 + -1;
    if (bVar4) {
      return 1;
    }
    iVar1 = FUN_0000b5a0(param_1);
    uVar2 = param_4;
    if (iVar1 == param_3) {
      uVar2 = uVar3 - 1 & 0xff;
    }
    if (uVar2 == 0) break;
    FUN_0001eb00(10);
    uVar3 = uVar2;
  }
  return 0;
}




undefined4 FUN_0000b694(undefined4 param_1,int param_2)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  
  cVar2 = '\x14';
  while( true ) {
    bVar3 = cVar2 == '\0';
    cVar2 = cVar2 + -1;
    if (bVar3) {
      return 1;
    }
    iVar1 = FUN_0000b590(param_1);
    if (iVar1 == param_2) break;
    FUN_0001eb00(1);
  }
  return 0;
}




undefined4 FUN_0000b6bc(undefined4 param_1,int param_2)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  
  cVar2 = '\x14';
  while( true ) {
    bVar3 = cVar2 == '\0';
    cVar2 = cVar2 + -1;
    if (bVar3) {
      return 1;
    }
    iVar1 = FUN_0000b5a0(param_1);
    if (iVar1 == param_2) break;
    FUN_0001eb00(1);
  }
  return 0;
}




uint FUN_0000b6e4(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0000b694(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_0000b694(param_1,0);
  }
  uVar2 = FUN_0000b6bc(param_1,0);
  if (uVar2 == 1) {
    uVar2 = FUN_0000b6bc(param_1,0);
  }
  return (uVar2 | iVar1 << 1) & 0xff;
}




uint FUN_0000b71a(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    if ((uVar2 != param_1) && (iVar1 = FUN_0000b5a0(uVar2), iVar1 == 0)) {
      uVar3 = 1 << uVar2 & 0xffU | uVar3;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return uVar3;
}




undefined4 FUN_0000b746(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = 0;
  iVar1 = FUN_0001a1aa();
  iVar2 = FUN_0001a20e(0x32);
  while( true ) {
    iVar3 = FUN_0000b590(param_1);
    if (iVar3 == 0) {
      bVar4 = 0;
    }
    else {
      bVar4 = bVar4 + 1;
    }
    iVar3 = FUN_0001a1aa();
    if (-1 < iVar3 - (iVar1 + iVar2)) break;
    FUN_0001eb00(1);
    if (1 < bVar4) {
      return 0;
    }
  }
  return 1;
}




undefined4 FUN_0000b782(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = 0;
  iVar1 = FUN_0001a1aa();
  iVar2 = FUN_0001a20e(0x32);
  while( true ) {
    iVar3 = FUN_0000b5a0(param_1);
    if (iVar3 == 0) {
      bVar4 = 0;
    }
    else {
      bVar4 = bVar4 + 1;
    }
    iVar3 = FUN_0001a1aa();
    if (-1 < iVar3 - (iVar1 + iVar2)) break;
    FUN_0001eb00(1);
    if (1 < bVar4) {
      return 0;
    }
  }
  return 1;
}




undefined4 FUN_0000b7be(undefined4 param_1,int param_2)

{
  undefined uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 4));
  uVar2 = FUN_0000b590(uVar1);
  FUN_0001cd4c(s_status____d_0000b7df + 1,uVar2);
  return 0;
}




void FUN_0000b7f0(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 1) {
    uVar2 = uVar2 ^ *(byte *)(param_1 + uVar3);
    uVar4 = 0;
    do {
      if ((int)(uVar2 << 0x18) < 0) {
        bVar1 = (byte)(uVar2 << 1) ^ 7;
      }
      else {
        bVar1 = (byte)(uVar2 << 1);
      }
      uVar4 = uVar4 + 1;
      uVar2 = (uint)bVar1;
    } while (uVar4 < 8);
  }
  return;
}




void FUN_0000b81e(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = DAT_0000bbf0;
  iVar2 = FUN_0001344c(*(undefined4 *)(DAT_0000bbf0 + 0x10));
  *(int *)(iVar1 + 0x14) = iVar2;
  if (iVar2 == 0) {
    FUN_0001cd4c(&DAT_0000bc20);
    pcVar3 = s_find__s_failed__0000bc6c;
    uVar4 = *(undefined4 *)(iVar1 + 0x10);
  }
  else {
    FUN_0001cd4c(&DAT_0000bbf4);
    FUN_0001cd4c(s_find__s_success__0000bc04,*(undefined4 *)(iVar1 + 0x10));
    FUN_0001cd4c(&DAT_0000bc18);
    iVar2 = FUN_00013532(*(undefined4 *)(iVar1 + 0x14));
    if (iVar2 != 0) {
      FUN_0001cd4c(&DAT_0000bc20);
      FUN_0001cd4c(s_init__s_failed__0000bc30,*(undefined4 *)(iVar1 + 0x10));
      FUN_0001cd4c(&DAT_0000bc18);
    }
    FUN_0001cd4c(&DAT_0000bbf4);
    FUN_0001cd4c(s_init__s_success__0000bc44,*(undefined4 *)(iVar1 + 0x10));
    FUN_0001cd4c(&DAT_0000bc18);
    iVar2 = FUN_0001357e(*(undefined4 *)(iVar1 + 0x14),0x600);
    if (iVar2 == 0) {
      return;
    }
    FUN_0001cd4c(&DAT_0000bc20);
    pcVar3 = s_open__s_failed__0000bc58;
    uVar4 = *(undefined4 *)(iVar1 + 0x10);
  }
  FUN_0001cd4c(pcVar3,uVar4);
  FUN_0001cd4c(&DAT_0000bc18);
  return;
}




bool FUN_0000b8a8(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 1);
  puVar2 = (undefined *)thunk_FUN_0001d084();
  *puVar2 = *(undefined *)(param_1 + 1);
  puVar2[1] = *(undefined *)(param_1 + 2);
  puVar2[2] = *(undefined *)(param_1 + 3);
  for (iVar4 = 0; iVar4 < (int)(bVar1 - 3); iVar4 = iVar4 + 1) {
    puVar2[iVar4 + 3] = *(undefined *)(param_1 + iVar4 + 4);
  }
  uVar3 = FUN_0000b7f0(puVar2,(uint)bVar1);
  bVar1 = *(byte *)(param_1 + 0x68);
  thunk_FUN_0001d330(puVar2);
  return uVar3 == bVar1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b8f6(undefined param_1,undefined param_2,int param_3,int param_4)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)(_DAT_0000bc80 + 2) != '\0') {
    *(undefined *)(_DAT_0000bc80 + 2) = 0;
    return;
  }
  puVar2 = (undefined *)thunk_FUN_0001d084(param_4 + 6);
  iVar4 = DAT_0000bbf0;
  *puVar2 = 0xf7;
  puVar2[1] = **(undefined **)(iVar4 + 8);
  puVar2[2] = (char)param_4 + '\x03';
  puVar2[3] = param_2;
  puVar2[4] = param_1;
  for (iVar3 = 0; iVar3 < param_4; iVar3 = iVar3 + 1) {
    puVar2[iVar3 + 5] = *(undefined *)(param_3 + iVar3);
  }
  uVar1 = FUN_0000b7f0(puVar2 + 2,param_4 + 3);
  puVar2[param_4 + 5] = uVar1;
  FUN_00013708(*(undefined4 *)(iVar4 + 0x14),0,puVar2,param_4 + 6);
  thunk_FUN_0001d330(puVar2);
  return;
}




undefined4 FUN_0000b966(void)

{
  FUN_0000b81e();
  **(undefined **)(DAT_0000bbf0 + 8) = 0xfe;
  FUN_0001cd4c(s_uid____d_0000bc83 + 1);
  return 0;
}




int FUN_0000b97e(void)

{
  int iVar1;
  
  iVar1 = FUN_0000b6e4();
  if (iVar1 != 0) {
    iVar1 = 0x50;
  }
  return iVar1;
}




undefined4 FUN_0000b98c(undefined4 param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  
  switch(param_1) {
  case 0:
    if (param_3 != 0) {
      return 1;
    }
    uVar1 = 4;
    break;
  case 1:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 1;
    break;
  default:
    return 1;
  case 4:
    uVar1 = 2;
    break;
  case 8:
    uVar1 = 3;
  }
  *param_2 = uVar1;
  DAT_0000bbf0[2] = *DAT_0000bbf0;
  return 0;
}




undefined4 FUN_0000b9c6(undefined4 param_1,int param_2,int param_3)

{
  if (param_2 != param_3) {
    FUN_0000b8f6(param_1,1,0);
    return 1;
  }
  return 0;
}




void FUN_0000bd6a(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_20;
  
  uVar3 = 0;
  local_20 = param_4;
  do {
    *(undefined *)((int)&local_20 + uVar3) = 0xff;
    if (((1 << (uVar3 & 0xff) & param_1) != 0) &&
       ((iVar2 = FUN_0000216c(), iVar2 == 0 || (*(byte *)(DAT_0000c0e4 + 1) != uVar3)))) {
      iVar2 = FUN_0000b694(uVar3 & 0xff,0);
      if (iVar2 == 0) {
        iVar2 = FUN_00002298(uVar3 & 0xff);
        if (iVar2 == 0) {
          uVar1 = 100;
        }
        else {
          uVar1 = FUN_0000220e(uVar3 & 0xff);
        }
      }
      else {
        uVar1 = 0;
      }
      *(undefined *)((int)&local_20 + uVar3) = uVar1;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 4);
  FUN_0000b8f6(3,0,&local_20,4);
  return;
}




void FUN_0000bdca(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_3;
  uStack_c = param_4;
  if (param_1 == 0) {
    FUN_00008598();
    uVar3 = 0;
  }
  else {
    if (param_1 == 1) {
      local_10 = FUN_0000840a();
      uVar2 = 0;
      do {
        puVar1 = (undefined *)((int)&local_10 + uVar2);
        iVar4 = 3 - uVar2;
        uVar2 = uVar2 + 1;
        *(undefined *)((int)&uStack_c + iVar4) = *puVar1;
      } while (uVar2 < 4);
      FUN_0000b8f6(0xe,0,&uStack_c,4);
      return;
    }
    uVar3 = 1;
  }
  FUN_0000b8f6(0xe,uVar3,0);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000be18(int param_1)

{
  byte *pbVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = _DAT_0000c0ec;
  iVar3 = DAT_0000c0e8;
  pbVar1 = DAT_0000c0e0;
  uVar4 = 0;
  if ((*(char *)(DAT_0000c0e8 + 2) == '\x03') || (*(char *)(DAT_0000c0e8 + 2) == '\x01')) {
    FUN_00000e3a(3);
    uVar4 = 3;
  }
  else {
    if (param_1 == 0) {
      if (*DAT_0000c0e0 < 4) {
        FUN_0001cd4c(s_enable_buffer__0000c0ef + 1);
        *(undefined *)(iVar3 + 2) = 2;
        FUN_0000da56(pbVar1[2],0);
        FUN_0000e650();
        iVar3 = FUN_0000e44e();
        if (iVar3 == 2) {
          FUN_0000df30(*(undefined *)(*(int *)(pbVar1 + 0xc) + 2));
          *puVar2 = 1;
        }
        else if (iVar3 == 1) {
          FUN_0000df64();
        }
        FUN_0000a6b0(*pbVar1);
        goto LAB_0000bebe;
      }
    }
    else if (param_1 == 1) {
      if (3 < *DAT_0000c0e0) {
        *DAT_0000c0e0 = DAT_0000c0e0[1];
      }
      FUN_0001cd4c(s_disable_buffer__0000c100);
      *puVar2 = 0;
      FUN_0000e4e2();
      FUN_0000df64();
      FUN_00000e2c();
      FUN_0000a744(*pbVar1);
      goto LAB_0000bebe;
    }
    uVar4 = 1;
    FUN_00000e3a(1);
  }
LAB_0000bebe:
  FUN_0000b8f6(4,uVar4,0);
  return;
}




void FUN_0000bf4e(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 local_8 [2];
  
  if (param_1 < 0xff) {
    cVar1 = (char)param_1 + '\x01';
  }
  else {
    cVar1 = '\0';
  }
  local_8[0] = CONCAT31((int3)((uint)param_4 >> 8),cVar1);
  FUN_0000b8f6(0x55,0,local_8,1);
  return;
}




undefined8 FUN_0000bf72(void)

{
  uint uVar1;
  undefined4 local_18 [4];
  
  uVar1 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  do {
    *(byte *)((int)local_18 + uVar1) =
         (char)uVar1 * '\x10' + 0x10U | *(byte *)(DAT_0000c114 + uVar1);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 6);
  FUN_0000b8f6(0x15,0,local_18,0x10);
  return CONCAT44(local_18[1],local_18[0]);
}




void FUN_0000bfa0(void)

{
  FUN_0000715e();
  FUN_0000b8f6(0x30,0,0);
  return;
}




void FUN_0000bfb4(void)

{
  FUN_0000b8f6(0x52,0xff,0);
  return;
}




void FUN_0000bfbe(void)

{
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  local_10 = *DAT_0000c118;
  local_8 = DAT_0000c118[2];
  local_c = DAT_0000c118[1] & local_8;
  FUN_0000b8f6(0x5b,0,&local_10,8);
  return;
}




undefined8 FUN_0000bfec(void)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  FUN_0000a5e8();
  FUN_0000a5fc(&local_18);
  FUN_0000b8f6(0x5c,0,&local_18,0x10);
  return CONCAT44(local_14,local_18);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c080(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  bool bVar11;
  undefined4 local_18;
  
  puVar9 = &local_18;
  *(char *)(DAT_0000c128 + -0x69) = param_1[3];
  puVar6 = DAT_0000c0e8;
  *_DAT_0000c12c = 1;
  puVar6[5] = 1;
  local_18 = param_4;
  FUN_0001a7ec(DAT_0000c128);
  FUN_0001cd4c(s_get_cmd_0x_x_0000c14c,param_1[3]);
  pcVar3 = DAT_0000c0e0;
  uVar4 = (uint)(byte)param_1[3];
  if (uVar4 == 0x10) {
    iVar5 = FUN_0000b9c6(0x10,param_1[1],6);
    if (iVar5 != 0) {
      return;
    }
    iVar5 = FUN_0000b98c(param_1[4],DAT_0000c5f8,1);
    if (iVar5 != 0) {
      uVar8 = 0x10;
      goto LAB_0000c42a;
    }
    FUN_000015c6(*pcVar3,param_1[5],param_1[6]);
    goto LAB_0000c5be;
  }
  if (uVar4 < 0x11) {
    bVar11 = 0xf < uVar4;
switchD_0000c172_caseD_b:
    if (!bVar11) {
                    /* WARNING: Could not recover jumptable at 0x0000c0b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&DAT_0000c0b6 + (uint)(byte)(&DAT_0000c0b6)[uVar4] * 2))();
      return;
    }
    goto LAB_0000c5ae;
  }
  if (uVar4 == 0x52) {
    local_18 = 0;
    iVar5 = FUN_0000b9c6(0x52,param_1[1],3);
    if (iVar5 != 0) {
      return;
    }
    uVar10 = 2;
    uVar8 = 0;
    uVar4 = 0x53;
  }
  else {
    if (0x52 < uVar4) {
      bVar11 = 10 < uVar4 - 0x53;
      switch(uVar4) {
      case 0x53:
        iVar5 = FUN_0000b9c6(0x52,param_1[1],5);
        if (iVar5 != 0) {
          return;
        }
        *DAT_0000c5fc = param_1[4];
        *DAT_0000c600 = param_1[5];
        break;
      case 0x54:
      case 0x57:
      case 0x58:
      case 0x59:
      case 0x5a:
        goto LAB_0000c5ae;
      case 0x55:
        iVar5 = FUN_0000b9c6(0x55,param_1[1],4);
        if (iVar5 != 0) {
          return;
        }
        FUN_0000bf4e(param_1[4]);
        break;
      case 0x56:
        iVar5 = FUN_0000b9c6(0x56,param_1[1],3);
        if (iVar5 != 0) {
          return;
        }
        FUN_0000b8f6(0x56,0,0);
LAB_0000c4c0:
        FUN_0001eb00(100);
        FUN_00013060();
        break;
      case 0x5b:
        iVar5 = FUN_0000b9c6(0x5b,param_1[1],3);
        if (iVar5 != 0) {
          return;
        }
        FUN_0000bfbe();
        break;
      case 0x5c:
        iVar5 = FUN_0000b9c6(0x5c,param_1[1],0x13);
        if (iVar5 != 0) {
          return;
        }
        FUN_0000bfec(param_1 + 4);
        break;
      case 0x5d:
        iVar5 = FUN_0000b9c6(0x5d,param_1[1],3);
        if (iVar5 != 0) {
          return;
        }
        FUN_00004a32();
        break;
      default:
        goto switchD_0000c172_caseD_b;
      }
      goto LAB_0000c5be;
    }
    if (uVar4 == 0x15) {
      iVar5 = FUN_0000b9c6(0x15,param_1[1],3);
      if (iVar5 != 0) {
        return;
      }
      FUN_0000bf72();
      goto LAB_0000c5be;
    }
    if (uVar4 < 0x16) {
      if (uVar4 == 0x11) {
        iVar5 = FUN_0000b9c6(0x11,param_1[1],5);
        if (iVar5 != 0) {
          return;
        }
        iVar5 = FUN_0000b98c(param_1[4],DAT_0000c5f8,0);
        if (iVar5 != 0) {
          uVar8 = 0x11;
LAB_0000c42a:
          FUN_0000b8f6(uVar8,1,0);
          return;
        }
        cVar1 = param_1[5];
        if (cVar1 == '\x01') {
          FUN_0000a7bc(*pcVar3);
        }
        FUN_00001c5a(*pcVar3,cVar1);
        goto LAB_0000c5be;
      }
      if (uVar4 == 0x13) {
        iVar5 = FUN_0000b9c6(0x13,param_1[1],4);
        if (iVar5 != 0) {
          return;
        }
        iVar5 = FUN_0000b98c(param_1[4],DAT_0000c5f8,1);
        if (iVar5 != 0) {
          uVar8 = 0x13;
          goto LAB_0000c42a;
        }
        FUN_00001c8c(*pcVar3);
        goto LAB_0000c5be;
      }
      bVar11 = uVar4 == 0x14;
    }
    else {
      if (uVar4 == 0x30) {
        iVar5 = FUN_0000b9c6(0x30,param_1[1],4);
        if (iVar5 != 0) {
          return;
        }
        FUN_0000bfa0(param_1[4]);
        goto LAB_0000c5be;
      }
      if (uVar4 == 0x50) {
        iVar5 = FUN_0000b9c6(0x50,param_1[1],4);
        if (iVar5 != 0) {
          return;
        }
        pcVar7 = (char *)FUN_0000ea5a(6);
        uVar2 = **(undefined **)(pcVar3 + 8);
        if (param_1[4] == *pcVar7) {
          if (*param_1 != -0x16) {
            if (*param_1 == -0x15) {
              **(undefined **)(pcVar3 + 8) = 0xeb;
            }
            FUN_0000b8f6(0x50,3,0);
            **(undefined **)(pcVar3 + 8) = uVar2;
          }
          goto LAB_0000c5be;
        }
        FUN_0000ea8c(6,param_1 + 4,1);
        FUN_0000eac8();
        if (*param_1 != -0x16) {
          if (*param_1 == -0x15) {
            **(undefined **)(pcVar3 + 8) = 0xeb;
          }
          FUN_0000b8f6(0x50,0,0);
          **(undefined **)(pcVar3 + 8) = uVar2;
        }
        goto LAB_0000c4c0;
      }
      bVar11 = uVar4 == 0x51;
      if (bVar11) {
        iVar5 = FUN_0000b9c6(0x51,param_1[1],4);
        if (iVar5 != 0) {
          return;
        }
        if (*param_1 == -0x15) {
          pcVar3[3] = param_1[4];
        }
        goto LAB_0000c5be;
      }
    }
    if (bVar11) {
      iVar5 = FUN_0000b9c6(0x14,param_1[1],3);
      if (iVar5 != 0) {
        return;
      }
      puVar6 = (undefined *)thunk_FUN_0001d084(0x16);
      *puVar6 = 0x31;
      puVar6[1] = 0x34;
      puVar6[2] = 0x32;
      FUN_000237a0(puVar6 + 3,DAT_0000c5f4,0x13);
      FUN_0000b8f6(0x14,0,puVar6,0x16);
      thunk_FUN_0001d330(puVar6);
      goto LAB_0000c5be;
    }
LAB_0000c5ae:
    if (*param_1 == -0x16) goto LAB_0000c5be;
    uVar10 = 0;
    puVar9 = (undefined4 *)0x0;
    uVar8 = 1;
  }
  FUN_0000b8f6(uVar4,uVar8,puVar9,uVar10);
LAB_0000c5be:
  if (pcVar3[1] != *pcVar3) {
    pcVar3[1] = *pcVar3;
  }
  return;
}




undefined FUN_0000c5ca(void)

{
  return *(undefined *)(DAT_0000c5f8 + 3);
}




void FUN_0000c5d0(undefined *param_1)

{
  int iVar1;
  
  FUN_00023966(param_1,0x70);
  *param_1 = 0;
  iVar1 = DAT_0000c604;
  *(char **)(DAT_0000c604 + 0x108) = s_rs485_lb_0000c608;
  *(int *)(iVar1 + 0x10c) = iVar1;
  *(undefined2 *)(iVar1 + 0x110) = 0x105;
  *(undefined2 *)(iVar1 + 0x112) = 0;
  *(undefined2 *)(iVar1 + 0x114) = 0;
  *(undefined *)(iVar1 + 0x116) = 0;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c658(char *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  byte *pbVar8;
  uint local_28;
  
  iVar1 = _DAT_0000c94c;
  local_28 = param_4;
LAB_0000c66a:
  do {
    iVar3 = FUN_000136a6(param_2,0,&local_28,1);
    if (iVar3 == 0) {
      if ((*param_1 != '\0') && (iVar4 = FUN_0001a1aa(), -1 < iVar4 - *(int *)(param_1 + 0x6c))) {
        FUN_0001cd4c(s_rs485_timeout___d_0000c94f + 1,*param_1);
        *param_1 = '\0';
      }
    }
    else {
      iVar4 = FUN_0001a1aa();
      iVar5 = FUN_0001a20e(0x78);
      *(int *)(param_1 + 0x6c) = iVar5 + iVar4;
    }
    switch(*param_1) {
    case '\0':
      if ((iVar3 == 1) && ((byte)local_28 == 0xf7)) {
        param_1[1] = '\0';
        *param_1 = '\x01';
      }
      break;
    case '\x01':
      if (iVar3 == 1) {
        pbVar8 = *(byte **)(iVar1 + 8);
        uVar6 = local_28 & 0xff;
        if (((*pbVar8 != uVar6) && (uVar6 != 0xea)) && (uVar6 != 0xeb))
        goto switchD_0000c6ac_caseD_7;
        param_1[2] = (byte)local_28;
        *param_1 = '\x02';
LAB_0000c7de:
        FUN_000079fa(pbVar8);
        goto LAB_0000c66a;
      }
      break;
    case '\x02':
      if (iVar3 == 1) {
        if (2 < (byte)local_28) {
          param_1[3] = (byte)local_28;
          param_1[1] = (byte)local_28 - 3;
          cVar2 = '\x03';
          goto LAB_0000c7da;
        }
        *param_1 = '\0';
LAB_0000c7dc:
        pbVar8 = *(byte **)(iVar1 + 8);
        goto LAB_0000c7de;
      }
      break;
    case '\x03':
      if (iVar3 == 1) {
        param_1[4] = (byte)local_28;
        cVar2 = '\x04';
LAB_0000c7da:
        *param_1 = cVar2;
        goto LAB_0000c7dc;
      }
      break;
    case '\x04':
      if (iVar3 == 1) {
        param_1[5] = (byte)local_28;
        if (param_1[1] == '\0') {
          *param_1 = '\x06';
          goto LAB_0000c7dc;
        }
        cVar2 = '\x05';
        goto LAB_0000c7da;
      }
      break;
    case '\x05':
      if (iVar3 == 1) {
        param_1[((uint)(byte)param_1[3] - (uint)(byte)param_1[1]) + 3] = (byte)local_28;
        param_1[1] = param_1[1] + -1;
      }
      if (param_1[1] == '\0') {
        *param_1 = '\x06';
      }
      break;
    case '\x06':
      if (iVar3 == 1) {
        param_1[0x6a] = (byte)local_28;
        iVar3 = FUN_0000b8a8(param_1 + 2);
        if (iVar3 == 0) {
          if (param_1[2] != -0x16) {
            FUN_0000b8f6(param_1[5],2,0);
          }
        }
        else {
          iVar3 = FUN_00007700(param_1[5]);
          if (iVar3 == 0) {
            FUN_0000c080(param_1 + 2);
          }
          else {
            FUN_00023966(DAT_0000c964,0x105);
            puVar7 = DAT_0000c964 + 1;
            *DAT_0000c964 = 0xf7;
            FUN_000237a0(puVar7,param_1 + 2,0x69);
            FUN_000077d0(DAT_0000c964);
            for (iVar3 = 0; iVar3 < (int)((byte)param_1[3] - 3); iVar3 = iVar3 + 1) {
            }
          }
        }
        puVar7 = DAT_0000c968;
        cVar2 = '\0';
        *DAT_0000c968 = 0;
        puVar7[2] = 0;
        goto LAB_0000c7da;
      }
      break;
    default:
switchD_0000c6ac_caseD_7:
      *param_1 = '\0';
    }
    FUN_000079fa(*(undefined4 *)(iVar1 + 8));
    if (iVar3 == 0) {
      return;
    }
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c7e4(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = _DAT_0000c96c;
  iVar1 = _DAT_0000c94c;
  if (*(char *)(_DAT_0000c96c + 2) != *(char *)(_DAT_0000c94c + 4)) {
    if (*(char *)(_DAT_0000c94c + 4) == '\x02') {
      *(undefined *)(DAT_0000c968 + 8) = 0;
      FUN_0000e4e2();
    }
    FUN_0001cd4c(s_box_status__0000c96f + 1);
    switch(*(undefined *)(iVar2 + 2)) {
    case 0:
      pcVar3 = s_STATE_IDLE_0000c97c;
      break;
    case 1:
      pcVar3 = s_STATE_PRELOAD_0000c988;
      break;
    case 2:
      pcVar3 = s_STATE_PRINT_0000c998;
      break;
    case 3:
      pcVar3 = s_STATE_RELOAD_0000c9a8;
      break;
    case 4:
      pcVar3 = s_STATE_ERROR_0000c9b8;
      break;
    case 5:
      pcVar3 = s_STATE_TEST_0000c9c8;
      break;
    default:
      pcVar3 = s_unknown_0000c9d4;
    }
    FUN_0001cd4c(pcVar3);
  }
  *(undefined *)(iVar1 + 4) = *(undefined *)(iVar2 + 2);
  return;
}




float FUN_0000ca4c(short param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  
  FUN_0001e1fe();
  iVar3 = DAT_0000ce58 + param_1 * 0xac;
  puVar1 = (undefined4 *)(iVar3 + 0x1c);
  FUN_000154f4(*puVar1,(int)*(char *)(iVar3 + 0x24));
  uVar2 = FUN_000154d0(*puVar1,(int)*(char *)(iVar3 + 0x24));
  FUN_00015520(*puVar1,(int)*(char *)(iVar3 + 0x24));
  FUN_0001e214();
  fVar4 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
  return fVar4 * DAT_0000ce5c * DAT_0000ce60;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000caa8(char param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  uVar6 = FUN_0000ca4c((int)param_1);
  iVar5 = DAT_0000ce58 + (short)param_1 * 0xac;
  *(undefined4 *)(iVar5 + (uint)*(byte *)(iVar5 + 0x68) * 4 + 0x54) = uVar6;
  bVar1 = *(char *)(iVar5 + 0x68) + 1;
  *(byte *)(iVar5 + 0x68) = bVar1;
  fVar10 = DAT_0000ce64;
  fVar9 = DAT_0000ce5c;
  if (4 < bVar1) {
    *(undefined *)(iVar5 + 0x68) = 0;
    uVar3 = 0;
    fVar7 = fVar10;
    fVar8 = fVar9;
    do {
      fVar11 = *(float *)(iVar5 + uVar3 * 4 + 0x54);
      if (fVar11 < fVar8) {
        fVar8 = fVar11;
      }
      if (fVar11 != fVar7 && fVar11 < fVar7 == (NAN(fVar11) || NAN(fVar7))) {
        fVar7 = fVar11;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 5);
    if ((int)(fVar7 - fVar8) < DAT_0000ce68) {
      *(undefined *)(iVar5 + 0xa4) = 1;
    }
    else {
      *(undefined *)(iVar5 + 0xa4) = 0;
    }
  }
  cVar2 = *(char *)(iVar5 + 0x69) + '\x01';
  *(char *)(iVar5 + 0x69) = cVar2;
  if (cVar2 < '\x05') {
    return;
  }
  *(undefined *)(iVar5 + 0x69) = 5;
  uVar3 = 0;
  fVar7 = fVar10;
  do {
    iVar4 = uVar3 * 4;
    uVar3 = uVar3 + 1;
    fVar7 = *(float *)(iVar5 + iVar4 + 0x54) + fVar7;
  } while (uVar3 < 5);
  fVar7 = fVar7 / 5.0;
  if (*(char *)(iVar5 + 0x7e) == '\0') {
    *(undefined *)(iVar5 + 0x7e) = 1;
    *(float *)(iVar5 + 0x70) = fVar7;
    iVar4 = DAT_0000ce70;
    fVar8 = fVar7 + DAT_0000ce6c;
    *(float *)(iVar5 + 0x74) = fVar8;
    if (iVar4 < (int)fVar8) {
      *(float *)(iVar5 + 0x74) = fVar9;
    }
    fVar9 = fVar7 - DAT_0000ce74;
    *(float *)(iVar5 + 0x78) = fVar9;
    if (fVar9 < 0.0) {
      *(float *)(iVar5 + 0x78) = fVar10;
    }
  }
  if (fVar7 < *(float *)(iVar5 + 0x74)) {
    if (*(float *)(iVar5 + 0x78) < fVar7 == (NAN(*(float *)(iVar5 + 0x78)) || NAN(fVar7))) {
      *(undefined *)(iVar5 + 0x7c) = 2;
    }
  }
  else {
    *(undefined *)(iVar5 + 0x7c) = 1;
  }
  cVar2 = '\0';
  if ((*(char *)(iVar5 + 0x7c) == '\x01') ||
     ((*(char *)(iVar5 + 0x7c) != '\x02' && (*(float *)(iVar5 + 0x70) <= fVar7)))) {
    cVar2 = '\x01';
  }
  if (*(char *)(iVar5 + 0x7d) != cVar2) {
    *(char *)(iVar5 + 0x7d) = cVar2;
    FUN_00003afa(iVar5 + 0x80);
  }
  if (cVar2 == '\0') {
    FUN_00003b1a(*(undefined4 *)(DAT_0000ce58 + -0xc),*(undefined4 *)(DAT_0000ce58 + -8),
                 *(undefined4 *)(DAT_0000ce58 + -4));
    fVar9 = (float)FUN_00003b44(*(undefined4 *)(iVar5 + 0x78),fVar7,iVar5 + 0x80);
    fVar9 = -fVar9;
    if (fVar9 == 0.0 || fVar9 < 0.0 != NAN(fVar9)) goto LAB_0000cc72;
  }
  else {
    FUN_00003b1a(*(undefined4 *)(DAT_0000ce58 + -0x18),*(undefined4 *)(DAT_0000ce58 + -0x14),
                 *(undefined4 *)(DAT_0000ce58 + -0x10));
    fVar9 = (float)FUN_00003b44(*(undefined4 *)(iVar5 + 0x74),fVar7,iVar5 + 0x80);
    fVar9 = -fVar9;
    if (0.0 <= fVar9) goto LAB_0000cc72;
  }
  fVar9 = fVar10;
LAB_0000cc72:
  if (*(code **)(iVar5 + 0x6c) != (code *)0x0) {
    (**(code **)(iVar5 + 0x6c))((int)fVar9);
  }
  iVar4 = DAT_0000ce78;
  *(char *)(DAT_0000ce78 + 4) = param_1;
  *(float *)(iVar4 + 8) = fVar7;
  fVar10 = *(float *)(iVar4 + 0xc);
  if (fVar7 != fVar10 && fVar7 < fVar10 == (NAN(fVar7) || NAN(fVar10))) {
    *(float *)(iVar4 + 0xc) = fVar7;
  }
  *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar5 + 0x78);
  *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar5 + 0x74);
  *(undefined *)(iVar4 + 0x18) = *(undefined *)(iVar5 + 0xa8);
  *(short *)(iVar4 + 0x1a) = (short)(int)fVar9;
  iVar4 = FUN_0000c5ca();
  if ((iVar4 != 0) && (*(char *)(DAT_0000ce7c + 7) == '\x01')) {
    FUN_000232a8(s_Bmotor_d__average_vol__d__02d__s_0000ce83 + 1,(int)param_1,(int)fVar7,
                 (int)(fVar7 * _DAT_0000ce80) % 100,(int)*(float *)(iVar5 + 0x70),
                 (int)(*(float *)(iVar5 + 0x70) * _DAT_0000ce80) % 100);
  }
  return;
}




void FUN_0000cd22(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar5;
  
  iVar2 = DAT_0000ceb8;
  iVar5 = DAT_0000ce58 + (short)param_1 * 0xac;
  if (*(char *)(DAT_0000ce58 + (short)param_1 * 0xac) == '\0') {
    FUN_00015b9c(*(undefined *)(iVar5 + 4),0);
    FUN_00015b9c(*(undefined *)(iVar5 + 5),0);
LAB_0000cdac:
    iVar1 = FUN_0001344c(*(undefined4 *)(iVar5 + 0x20));
    *(int *)(iVar5 + 0x1c) = iVar1;
    if (iVar1 != 0) {
      iVar1 = iVar5 + 0x28;
      *(undefined4 *)(iVar5 + 0x6c) = DAT_0000cf28;
      iVar2 = FUN_0001de70(iVar1);
      if (iVar2 == 10) {
        FUN_0001ed48(iVar1);
      }
      uVar4 = FUN_0001a20e(0x14);
      FUN_0001ecec(iVar1,&DAT_0000cf58,DAT_0000cf54,param_1);
      FUN_00003ac0();
      FUN_00003b10(DAT_0000cf64,DAT_0000cf60,iVar5 + 0x80,extraout_r1_00,uVar4,6);
      return;
    }
    *(undefined *)(iVar2 + param_1 + 9) = 1;
    FUN_0001cd4c(&DAT_0000ceec);
    pcVar3 = s_adc_run_failed__can_t_find__s_de_0000cf2c;
    uVar4 = *(undefined4 *)(iVar5 + 0x20);
  }
  else {
    iVar1 = FUN_0001344c(*(undefined4 *)(iVar5 + 8));
    *(int *)(iVar5 + 4) = iVar1;
    if (iVar1 == 0) {
      *(undefined *)(iVar2 + 7) = 1;
      FUN_0001cd4c(&DAT_0000ceec);
      uVar4 = *(undefined4 *)(iVar5 + 8);
    }
    else {
      FUN_0001cd4c(&DAT_0000cebc);
      FUN_0001cd4c(s_find__s_device__0000ced0,*(undefined4 *)(iVar5 + 8));
      FUN_0001cd4c(&DAT_0000cee4);
      iVar1 = FUN_0001344c(*(undefined4 *)(iVar5 + 0x14));
      *(int *)(iVar5 + 0x10) = iVar1;
      if (iVar1 != 0) {
        FUN_0001cd4c(&DAT_0000cebc);
        FUN_0001cd4c(s_find__s_device__0000ced0,*(undefined4 *)(iVar5 + 0x14));
        FUN_0001cd4c(&DAT_0000cee4);
        goto LAB_0000cdac;
      }
      *(undefined *)(iVar2 + 8) = 1;
      FUN_0001cd4c(&DAT_0000ceec);
      uVar4 = *(undefined4 *)(iVar5 + 0x14);
    }
    pcVar3 = s_pwm_run_failed__can_t_find__s_de_0000cf00;
  }
  FUN_0001cd4c(pcVar3,uVar4);
  FUN_0001cd4c(&DAT_0000cee4,extraout_r1,param_3,param_4);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ce20(int param_1,uint param_2)

{
  undefined uVar1;
  undefined2 uVar2;
  char cVar3;
  short sVar4;
  byte *pbVar5;
  undefined4 uVar6;
  bool bVar7;
  int iVar8;
  char *pcVar9;
  
  pcVar9 = s_____________gpio_test____________00004e00 +
           (0x20 - (uint)((short)param_2 * 20000) / 0xff);
  sVar4 = (short)param_1;
  iVar8 = DAT_0000ce58 + sVar4 * 0xac;
  cVar3 = *(char *)(DAT_0000ce58 + sVar4 * 0xac);
  if (*(short *)(iVar8 + 0xaa) == 0) {
    if (cVar3 == '\0') {
      FUN_00015bc4(*(undefined *)(iVar8 + 4),1);
      bVar7 = param_2 == 0;
      uVar1 = *(undefined *)(iVar8 + 5);
      goto LAB_0000cfda;
    }
    FUN_000161ee(*(undefined4 *)(iVar8 + 4),*(undefined2 *)(iVar8 + 0xc),
                 s_____________gpio_test____________00004e00 + 0x20);
    FUN_00016160(*(undefined4 *)(iVar8 + 4),*(undefined2 *)(iVar8 + 0xc));
    uVar2 = *(undefined2 *)(iVar8 + 0x18);
    uVar6 = *(undefined4 *)(iVar8 + 0x10);
  }
  else {
    if (cVar3 == '\0') {
      FUN_00015bc4(*(undefined *)(iVar8 + 4),param_2 == 0);
      uVar1 = *(undefined *)(iVar8 + 5);
      bVar7 = true;
LAB_0000cfda:
      FUN_00015bc4(uVar1,bVar7);
      goto LAB_0000cfde;
    }
    FUN_000161ee(*(undefined4 *)(iVar8 + 4),*(undefined2 *)(iVar8 + 0xc),
                 s_____________gpio_test____________00004e00 + 0x20,pcVar9);
    FUN_00016160(*(undefined4 *)(iVar8 + 4),*(undefined2 *)(iVar8 + 0xc));
    pcVar9 = s_____________gpio_test____________00004e00 + 0x20;
    uVar2 = *(undefined2 *)(iVar8 + 0x18);
    uVar6 = *(undefined4 *)(iVar8 + 0x10);
  }
  FUN_000161ee(uVar6,uVar2,s_____________gpio_test____________00004e00 + 0x20,pcVar9);
  FUN_00016160(*(undefined4 *)(iVar8 + 0x10),*(undefined2 *)(iVar8 + 0x18));
LAB_0000cfde:
  pbVar5 = _DAT_0000d32c;
  if ((param_2 == 0) || (*(ushort *)(iVar8 + 0xa8) == param_2)) {
    FUN_0001ef48(DAT_0000d328 + sVar4 * 0xac + 0x28);
    if (*(code **)(iVar8 + 0x6c) != (code *)0x0) {
      (**(code **)(iVar8 + 0x6c))(0);
    }
    FUN_00003afa(iVar8 + 0x80);
    uVar6 = DAT_0000ce64;
    *(undefined4 *)(pbVar5 + 8) = DAT_0000ce64;
    *(undefined4 *)(pbVar5 + 0xc) = uVar6;
    *(undefined4 *)(pbVar5 + 0x10) = uVar6;
    *(undefined4 *)(pbVar5 + 0x14) = uVar6;
    pbVar5[0x18] = 0;
    *(undefined2 *)(pbVar5 + 0x1a) = 0;
    *(undefined *)(iVar8 + 0xa4) = 0;
  }
  else {
    *_DAT_0000d32c = *_DAT_0000d32c & (1 << (param_1 + 1U & 0xff) & 0xffU) == 0;
    pbVar5[0x1c] = *(byte *)(iVar8 + 0xaa);
    *(undefined *)(iVar8 + 0x68) = 0;
    *(undefined *)(iVar8 + 0x69) = 0xfb;
    *(undefined *)(iVar8 + 0x7e) = 0;
    *(undefined *)(iVar8 + 0x7c) = 0;
    *(undefined *)(iVar8 + 0x7d) = 0;
    FUN_0001ee68();
  }
  *(short *)(iVar8 + 0xa8) = (short)param_2;
  return;
}




void FUN_0000d078(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = DAT_0000d328 + (short)param_1 * 0xac;
  *(undefined2 *)(iVar1 + 0xaa) = param_2;
  FUN_0000ce20(param_1,*(undefined *)(iVar1 + 0xa8));
  return;
}




undefined FUN_0000d09e(short param_1)

{
  return *(undefined *)(DAT_0000d328 + param_1 * 0xac + 0xa4);
}




undefined FUN_0000d0b0(short param_1)

{
  return *(undefined *)(DAT_0000d328 + param_1 * 0xac + 0xaa);
}




undefined4 FUN_0000d0d4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0x80;
  uVar1 = 0;
  if (3 < param_1) {
    uVar3 = FUN_00023590(*(undefined4 *)(param_2 + 4));
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
    uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 0xc));
  }
  FUN_0001cd4c(s_at8236_test_id__d_speed__d_dir___0000d32f + 1,uVar3,uVar2,uVar1);
  FUN_0000cd22();
  FUN_0000d078((int)(char)uVar3,uVar1 & 0xff);
  FUN_0000ce20((int)(char)uVar3,uVar2 & 0xff);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000d1e8(void)

{
  return *(undefined4 *)(_DAT_0000d32c + 0xc);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000d1f0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = _DAT_0000d32c;
  uVar1 = DAT_0000ce64;
  *(undefined4 *)(_DAT_0000d32c + 8) = DAT_0000ce64;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000d200(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0001a20e(200);
  FUN_0001ecec(_DAT_0000d3a8,&DAT_0000d3a0,DAT_0000d39c,0,uVar1,6);
  FUN_0001ee68(_DAT_0000d3a8);
  FUN_0000cd22(0);
  FUN_0000cd22(1);
  FUN_0001cd4c(s_at8236_adc_timer_ok_0000d3ab + 1);
  return 0;
}




longlong FUN_0000d236(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  float *pfVar3;
  uint in_fpscr;
  float fVar4;
  uint uVar5;
  
  iVar1 = DAT_0000d328;
  pfVar3 = (float *)(DAT_0000d328 + -0x18);
  if (param_1 < 7) {
    fVar4 = *(float *)(DAT_0000d328 + -0x10);
  }
  else {
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 4));
    uVar2 = VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
    *(undefined4 *)(iVar1 + -0xc) = uVar2;
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
    uVar2 = VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
    *(undefined4 *)(iVar1 + -8) = uVar2;
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 0xc));
    uVar2 = VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
    *(undefined4 *)(iVar1 + -4) = uVar2;
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 0x10));
    fVar4 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
    *pfVar3 = fVar4;
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 0x14));
    uVar2 = VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
    *(undefined4 *)(iVar1 + -0x14) = uVar2;
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 0x18));
    fVar4 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
    *(float *)(iVar1 + -0x10) = fVar4;
  }
  uVar5 = (uint)*pfVar3;
  FUN_0001cd4c(s_at8236_pid_set_outkp__d_outki__d_0000d3c4,(int)*(float *)(iVar1 + -0xc),
               (int)*(float *)(iVar1 + -8),(int)*(float *)(iVar1 + -4),uVar5,
               (int)*(float *)(iVar1 + -0x14),(int)fVar4);
  return (ulonglong)uVar5 << 0x20;
}




undefined4 FUN_0000d302(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_0000cd22();
    FUN_0000d078((int)(char)iVar1,0);
    FUN_0000ce20((int)(char)iVar1,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return 0;
}




void FUN_0000d404(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  FUN_00020524(DAT_0000d804,1);
  iVar1 = DAT_0000d808;
  uVar2 = 0;
  do {
    FUN_00015b9c(*(undefined4 *)(iVar1 + uVar2 * 8),0);
    iVar3 = iVar1 + uVar2 * 8;
    FUN_00015b9c(*(undefined4 *)(iVar3 + 4),0);
    FUN_00015bc4(*(undefined4 *)(iVar1 + uVar2 * 8),0);
    FUN_00015bc4(*(undefined4 *)(iVar3 + 4),0);
    iVar3 = DAT_0000d808;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  *(undefined *)(DAT_0000d808 + -6) = 0;
  *(undefined *)(iVar3 + -4) = 0;
  return;
}




void FUN_0000d450(int param_1,undefined param_2)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = DAT_0000d808;
  puVar2 = (undefined *)(DAT_0000d808 + -6);
  if (param_1 != 0) {
    *(char *)(DAT_0000d80c + 4) = (char)param_1;
    *(undefined *)(iVar1 + -5) = param_2;
  }
  *puVar2 = (char)param_1;
  *(undefined *)(DAT_0000d808 + -8) = 0;
  return;
}




undefined4 FUN_0000d468(void)

{
  FUN_0000d404();
  FUN_0000d450(0);
  return 0;
}




void FUN_0000d47a(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = DAT_0000d808 + param_1 * 8;
  if (param_3 == 1) {
    if (param_2 == 0) {
      uVar1 = *(undefined4 *)(DAT_0000d808 + param_1 * 8);
    }
    else {
      uVar1 = *(undefined4 *)(iVar3 + 4);
    }
    uVar2 = 1;
  }
  else {
    if (param_2 == 0) {
      uVar1 = *(undefined4 *)(DAT_0000d808 + param_1 * 8);
    }
    else {
      uVar1 = *(undefined4 *)(iVar3 + 4);
    }
    uVar2 = 0;
  }
  FUN_00015bc4(uVar1,uVar2);
  return;
}




void FUN_0000d4a6(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = 0;
  do {
    FUN_0000d47a(bVar1,param_1,param_2);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 4);
  return;
}




void FUN_0000d4c2(undefined4 param_1,undefined4 param_2)

{
  FUN_0000d47a(0,param_1,1);
  FUN_0000d47a(3,param_1,0);
  FUN_0001eb00(param_2);
  FUN_0000d47a(1,param_1);
  FUN_0000d47a(0,param_1);
  FUN_0001eb00(param_2);
  FUN_0000d47a(2,param_1,1);
  FUN_0000d47a(1,param_1,0);
  FUN_0001eb00(param_2);
  FUN_0000d47a(3,param_1,1);
  FUN_0000d47a(2,param_1,0);
  FUN_0001eb00(param_2);
  return;
}




void FUN_0000d556(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (uVar2 != param_1) {
      iVar1 = FUN_0000b590(uVar2);
      FUN_0000d47a(uVar2,0,iVar1 == 0);
      FUN_0000d47a(uVar2,1,0);
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return;
}




void FUN_0000d58a(void)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  
  cVar3 = '\0';
  bVar2 = 0;
  do {
    FUN_0000d47a(bVar2,1,0);
    iVar1 = FUN_0000b590(bVar2);
    if (iVar1 == 0) {
      FUN_0000d47a(bVar2,0,1);
    }
    else {
      FUN_0000d47a(bVar2,0);
      cVar3 = cVar3 + '\x01';
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 4);
  if (cVar3 == '\x04') {
    FUN_0000d450(1,0);
    return;
  }
  return;
}




void FUN_0000d606(undefined4 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 10;
  iVar3 = 0;
  bVar1 = 0;
  do {
    for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1 & 0xff) {
      if (iVar2 != 0) {
        FUN_0000d47a(param_1,param_2,1);
        FUN_0001eb00(iVar2);
      }
      if (iVar3 != 0) {
        FUN_0000d47a(param_1,param_2,0);
        FUN_0001eb00(iVar3);
      }
    }
    if (iVar2 != 0) {
      iVar2 = iVar2 + -1;
    }
    bVar1 = bVar1 + 1;
    iVar3 = iVar3 + 1;
  } while (bVar1 < 10);
  bVar1 = 0;
  do {
    for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1 & 0xff) {
      if (iVar2 != 0) {
        FUN_0000d47a(param_1,param_2,1);
        FUN_0001eb00(iVar2);
      }
      FUN_0000d47a(param_1,param_2,0);
      FUN_0001eb00(iVar3);
    }
    iVar2 = iVar2 + 1;
    if (iVar3 != 0) {
      iVar3 = iVar3 + -1;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 10);
  return;
}




void FUN_0000d6a4(undefined4 param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  iVar3 = 10;
  iVar2 = 0;
  bVar1 = 0;
  do {
    for (uVar5 = 0; uVar5 < param_2; uVar5 = uVar5 + 1 & 0xff) {
      bVar4 = 0;
      do {
        FUN_0000d47a(bVar4,param_1,1);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 4);
      FUN_0001eb00(iVar3);
      if (iVar2 != 0) {
        bVar4 = 0;
        do {
          FUN_0000d47a(bVar4,param_1,0);
          bVar4 = bVar4 + 1;
        } while (bVar4 < 4);
        FUN_0001eb00(iVar2);
      }
    }
    if (iVar3 != 0) {
      iVar3 = iVar3 + -1;
    }
    bVar1 = bVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (bVar1 < 10);
  bVar1 = 0;
  do {
    for (uVar5 = 0; uVar5 < param_2; uVar5 = uVar5 + 1 & 0xff) {
      if (iVar3 != 0) {
        bVar4 = 0;
        do {
          FUN_0000d47a(bVar4,param_1,1);
          bVar4 = bVar4 + 1;
        } while (bVar4 < 4);
        FUN_0001eb00(iVar3);
      }
      bVar4 = 0;
      do {
        FUN_0000d47a(bVar4,param_1,0);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 4);
      FUN_0001eb00(iVar2);
    }
    iVar3 = iVar3 + 1;
    if (iVar2 != 0) {
      iVar2 = iVar2 + -1;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 10);
  return;
}




void FUN_0000d764(undefined4 param_1)

{
  FUN_0000d4a6(1,0);
  FUN_0000d4a6(0,1);
  FUN_0001eb00(param_1);
  FUN_0000d4a6(0);
  FUN_0000d4a6(1);
  FUN_0001eb00(param_1);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000da2c(void)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  bVar3 = 0;
  *(undefined *)(_DAT_0000dbe4 + 2) = 0;
  do {
    iVar1 = FUN_0000b590(bVar3);
    if (iVar1 == 0) {
      uVar2 = 2;
      goto LAB_0000da50;
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 4);
  bVar3 = 0;
  uVar2 = 1;
LAB_0000da50:
  FUN_0000d450(uVar2,bVar3);
  return;
}




void FUN_0000da56(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  FUN_0001cd4c(s_motor_id____d__led_set_err__x_0000dbe7 + 1,param_1,param_2);
  if (param_2 == 0x14) {
LAB_0000d5d4:
    iVar1 = FUN_0000b590();
    uVar2 = FUN_0000b5a0(param_1);
    uVar2 = (uVar2 | iVar1 << 1) & 0xff;
    if (uVar2 == 0) {
      uVar3 = 6;
    }
    else if (uVar2 == 1) {
      uVar3 = 4;
    }
    else {
      uVar3 = 5;
    }
    FUN_0000d450(uVar3,param_1);
    return;
  }
  if (0x14 < param_2) {
    if (param_2 == 0x20) goto LAB_0000d5d4;
    if (param_2 < 0x21) {
      switch(param_2) {
      case 0x16:
        goto switchD_0000da70_caseD_8;
      case 0x17:
switchD_0000da96_caseD_17:
        uVar3 = 5;
        goto LAB_0000daec;
      case 0x18:
        param_1 = 0;
        uVar3 = 8;
        goto LAB_0000daec;
      case 0x19:
      case 0x1a:
        goto switchD_0000da70_caseD_a;
      default:
        goto switchD_0000da70_caseD_1;
      }
    }
    if (param_2 != 0x51) {
      if (param_2 < 0x52) {
        if (param_2 != 0x22) {
          if (param_2 != 0x50) {
            return;
          }
          goto switchD_0000da70_caseD_8;
        }
      }
      else if (param_2 != 0x52) {
        if (param_2 != 0x53) {
          return;
        }
        goto switchD_0000da96_caseD_17;
      }
    }
    goto switchD_0000da70_caseD_a;
  }
  switch(param_2) {
  case 0:
    uVar3 = 3;
    break;
  default:
switchD_0000da70_caseD_1:
    return;
  case 5:
  case 9:
    uVar3 = 4;
    break;
  case 6:
    iVar1 = FUN_0000b590(param_1);
    if (iVar1 == 1) goto switchD_0000da96_caseD_17;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x13:
switchD_0000da70_caseD_a:
    uVar3 = 6;
    break;
  case 8:
switchD_0000da70_caseD_8:
    uVar3 = 7;
  }
LAB_0000daec:
  FUN_0000d450(uVar3,param_1);
  return;
}




void FUN_0000dc2c(void)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint in_fpscr;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char local_28 [4];
  
  iVar2 = DAT_0000e010;
  uVar7 = *(uint *)(DAT_0000e010 + 0x30);
  uVar4 = *(uint *)(DAT_0000e010 + 0x34);
  if (uVar7 < uVar4) {
    iVar5 = ~uVar4 + uVar7 + 1;
  }
  else {
    iVar5 = uVar7 - uVar4;
  }
  fVar9 = (float)VectorUnsignedToFloat(iVar5,(byte)(in_fpscr >> 0x15) & 3);
  fVar9 = ((fVar9 * DAT_0000e014) / DAT_0000e018) / 6.0;
  *(float *)(DAT_0000e010 + 0x2c) = fVar9;
  iVar5 = DAT_0000e010;
  puVar8 = (undefined4 *)(DAT_0000e010 + 0xb4);
  uVar1 = *(ushort *)(DAT_0000e010 + 0xba);
  uVar10 = DAT_0000e01c;
  if (uVar1 == 0) goto LAB_0000dd10;
  if ((int)ABS(fVar9) < DAT_0000e020) {
    *(undefined4 *)(iVar2 + 0x38) = 2;
    if (*(char *)(iVar2 + 0x3c) != '\0') {
      cVar3 = *(char *)(iVar2 + 0x3c) + -1;
LAB_0000dca0:
      *(char *)(iVar2 + 0x3c) = cVar3;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x38) == 0) {
      cVar3 = '\x14';
      goto LAB_0000dca0;
    }
    *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + -1;
  }
  uVar11 = VectorSignedToFloat((int)(((int)*(short *)(iVar5 + 0xbe) + (uint)uVar1) * 0x32) / 0xff,
                               (byte)(in_fpscr >> 0x15) & 3);
  uVar10 = FUN_00003b44(uVar11,DAT_0000e010 + 0x90);
  uVar4 = VectorFloatToUnsigned(uVar10,3);
  FUN_000161ee(*puVar8,2,&DAT_0000c350,(int)((0xff - (uVar4 & 0xffff)) * 50000) / 0xff);
  FUN_00016160(*puVar8,2);
  iVar5 = DAT_0000e024;
  *(undefined4 *)(DAT_0000e024 + 0x20) = uVar11;
  *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(iVar2 + 0x2c);
  *(char *)(iVar5 + 0x28) = (char)uVar4;
LAB_0000dd10:
  *(uint *)(iVar2 + 0x34) = uVar7;
  if ((*(char *)(iVar2 + 0x8e) != '\0') &&
     (cVar3 = *(char *)(iVar2 + 0x8c) + '\x01', *(char *)(iVar2 + 0x8c) = cVar3, cVar3 == '\x01')) {
    iVar5 = DAT_0000e010 + 0x78;
    *(undefined *)(iVar2 + 0x8c) = 0;
    iVar6 = FUN_0001502e();
    if (iVar6 == 0x38) {
      if (0xf87 < (uint)(*(int *)(iVar2 + 0x88) * 100)) {
        *(undefined *)(iVar2 + 0x8d) = 1;
        *(undefined *)(iVar2 + 0x8e) = 0;
      }
      FUN_000152ea(iVar5,local_28);
      if (local_28[0] == -1) {
        *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + -1;
      }
    }
    uVar4 = VectorFloatToUnsigned(uVar10,3);
    FUN_00015240(iVar5,uVar4 & 0xff);
    if ((~uVar4 & 0xff) == 0) {
      *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + 1;
    }
  }
  return;
}




void FUN_0000ddb2(void)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 extraout_r1;
  int *piVar4;
  
  iVar2 = DAT_0000e010;
  piVar4 = (int *)(DAT_0000e010 + 0xb4);
  *piVar4 = 0;
  FUN_0001fb24(0x606);
  FUN_00015b9c(0x43,0);
  FUN_00015bc4(0x43,0);
  FUN_00015b9c(0x44,4);
  FUN_00015bc4(0x44,1);
  FUN_00015b9c(0x4b,2);
  FUN_00015b06(0x4b,1,DAT_0000e028,0);
  FUN_00015b6c(0x4b,1);
  FUN_00003ac0(iVar2 + 0x90);
  FUN_00003b10(DAT_0000e030,DAT_0000e02c,iVar2 + 0x90);
  FUN_00003b1a(*DAT_0000e034,DAT_0000e034[1],DAT_0000e034[2],iVar2 + 0x90);
  FUN_00014fe8(iVar2 + 0x78,iVar2 + 0x3d,0x38);
  uVar1 = FUN_0001a20e(0x28);
  FUN_0001ecec(DAT_0000e010,s_tim_rotational_speed_detect_0000e03c,DAT_0000e038,0);
  iVar2 = FUN_0001344c(&DAT_0000e058);
  *piVar4 = iVar2;
  if (iVar2 == 0) {
    *(undefined *)(DAT_0000e098 + 0xd) = 1;
    FUN_0001cd4c(&DAT_0000e09c);
    pcVar3 = s_pwm_run_failed__can_t_find_MS379_0000e0b0;
  }
  else {
    FUN_0001cd4c(&DAT_0000e060);
    pcVar3 = s_find_MS3791_enable_device__0000e074;
  }
  FUN_0001cd4c(pcVar3);
  FUN_0001cd4c(&DAT_0000e090,extraout_r1,uVar1,6);
  return;
}




void FUN_0000de7e(int param_1)

{
  FUN_00015bc4(0x43,param_1 == 0);
  *(char *)(DAT_0000e010 + 0xb8) = (char)param_1;
  return;
}




void FUN_0000de98(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar1 = DAT_0000e010;
  if (0xff < param_1) {
    param_1 = 0xff;
  }
  puVar5 = (undefined4 *)(DAT_0000e010 + 0xb4);
  *(undefined2 *)(DAT_0000e010 + 0xbc) = *(undefined2 *)(DAT_0000e010 + 0xba);
  uVar4 = param_1;
  if (param_1 != 0) {
    uVar4 = (int)*(short *)(iVar1 + 0xbe) + param_1;
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
  }
  FUN_000161ee(*puVar5,2,&DAT_0000c350,(int)((0xff - uVar4) * 50000) / 0xff);
  FUN_00016160(*puVar5,2);
  puVar3 = DAT_0000e024;
  *(short *)(iVar1 + 0xba) = (short)param_1;
  if (param_1 != 0) {
    *puVar3 = 0;
    puVar3[0x29] = *(undefined *)(iVar1 + 0xb8);
    FUN_0001ee68(DAT_0000e010);
    return;
  }
  FUN_0001ef48(DAT_0000e010);
  FUN_00003afa(DAT_0000e010 + 0x90);
  *(undefined *)(iVar1 + 0x3c) = 0x14;
  uVar2 = DAT_0000e01c;
  *(undefined4 *)(puVar3 + 0x20) = DAT_0000e01c;
  *(undefined4 *)(puVar3 + 0x24) = uVar2;
  puVar3[0x28] = 0;
  return;
}




void FUN_0000df30(undefined4 param_1)

{
  FUN_00015bc4(0x44,0);
  FUN_0000de7e(0);
  FUN_0000de98(param_1);
  return;
}




void FUN_0000df4a(undefined4 param_1)

{
  FUN_00015bc4(0x44,0);
  FUN_0000de7e(1);
  FUN_0000de98(param_1);
  return;
}




void FUN_0000df64(void)

{
  FUN_00015bc4(0x44,1);
  FUN_0000de98(0);
  return;
}




undefined4 FUN_0000df76(void)

{
  if (*(char *)(DAT_0000e010 + 0x3c) != '\0') {
    return 0;
  }
  return 1;
}




void FUN_0000df86(undefined param_1)

{
  *(undefined *)(DAT_0000e010 + 0x8e) = param_1;
  return;
}




undefined FUN_0000df8e(void)

{
  return *(undefined *)(DAT_0000e010 + 0x8d);
}




void FUN_0000df96(void)

{
  int iVar1;
  
  iVar1 = DAT_0000e010;
  *(undefined *)(DAT_0000e010 + 0x8d) = 0;
  *(undefined4 *)(iVar1 + 0x88) = 0;
  if (iVar1 == -0x78) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0xaa,0x197);
  }
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  return;
}




undefined FUN_0000dfa8(void)

{
  return *(undefined *)(DAT_0000e010 + 0xb8);
}




undefined FUN_0000dfb0(void)

{
  return *(undefined *)(DAT_0000e010 + 0xba);
}




undefined FUN_0000dfb8(void)

{
  return *(undefined *)(DAT_0000e010 + 0xbc);
}




int FUN_0000dfc0(void)

{
  return (int)ABS(*(float *)(DAT_0000e010 + 0x2c));
}




void FUN_0000dfd4(int param_1)

{
  uint uVar1;
  byte bVar2;
  undefined2 uVar3;
  char cVar4;
  uint in_fpscr;
  int iVar5;
  undefined8 uVar6;
  
  uVar1 = DAT_0000e010;
  cVar4 = 0xffffff4b < DAT_0000e010;
  uVar3 = 0;
  uVar6 = FUN_0002601a();
  FUN_000262e4((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)DAT_0000e0e0,
               (int)((ulonglong)DAT_0000e0e0 >> 0x20));
  if ((cVar4 != '\0') ||
     (iVar5 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x15) & 3), DAT_0000e020 <= iVar5)) {
    if (param_1 < 1) {
      bVar2 = *(byte *)(uVar1 + 0xba);
    }
    else {
      bVar2 = -(char)*(undefined2 *)(uVar1 + 0xba) - 1;
    }
    uVar3 = (undefined2)((int)((uint)bVar2 * param_1) / 0xff);
  }
  *(undefined2 *)(uVar1 + 0xbe) = uVar3;
  return;
}




undefined4 FUN_0000e0fc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0x80;
  uVar1 = 0;
  if (2 < param_1) {
    uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
    uVar1 = FUN_00023590(*(undefined4 *)(param_2 + 4));
  }
  FUN_0001cd4c(s_MS3791_test_speed__d_dir__d_0000e314,uVar2,uVar1);
  FUN_00015bc4(0x44,0);
  FUN_0000de7e(uVar1 & 0xff);
  FUN_0000de98(uVar2 & 0xffff);
  return 0;
}




undefined4 FUN_0000e13a(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_0000df30(0x50);
  }
  else {
    FUN_0000df4a();
  }
  FUN_0001eb00(param_2);
  iVar1 = FUN_0000dfc0();
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}




undefined4 FUN_0000e164(void)

{
  int iVar1;
  
  FUN_00015bc4(0x44,1);
  FUN_0001eb00(300);
  iVar1 = FUN_0000dfc0();
  if (0 < iVar1) {
    return 1;
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000e186(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  char *pcVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  
  if (param_1 == 4) {
    bVar1 = FUN_00023590(*(undefined4 *)(param_2 + 4));
    if (bVar1 < 2) {
      uVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
      if (uVar2 < 0x100) {
        uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 0xc));
        FUN_0001cd4c(s_MS3791_time_test_dir____d_speed___0000e38c,bVar1,uVar2,uVar4);
        fVar5 = (float)FUN_0000840a();
        if (bVar1 == 0) {
          FUN_0000df30(uVar2);
        }
        else {
          FUN_0000df4a();
        }
        FUN_0001eb00(uVar4);
        FUN_0000df64();
        fVar6 = (float)FUN_0000840a();
        FUN_0001cd4c(s_Bmove_position____d__02dmm_0000e3c3 + 1,(int)ABS(fVar5 - fVar6),
                     (int)(ABS(fVar5 - fVar6) * _DAT_0000e3c0) % 100);
        return;
      }
      pcVar3 = s_speed_is_between_0_to_255_0000e370;
    }
    else {
      pcVar3 = s_dir_is_0_or_1_0000e360;
    }
  }
  else {
    pcVar3 = s_MS3791_time_test__dir___speed____0000e334;
  }
  FUN_0001cd4c(pcVar3);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000e230(void)

{
  FUN_0001cd4c(s_MS3791_read_fg_pluse__d_0000e3e3 + 1,*(undefined4 *)(_DAT_0000e3e0 + 0x30));
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_0000e240(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  uint uVar3;
  undefined8 uVar4;
  
  pfVar1 = _DAT_0000e400;
  if (3 < param_1) {
    uVar4 = FUN_00025738(*(undefined4 *)(param_2 + 4));
    fVar2 = (float)FUN_00025a5c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    *pfVar1 = fVar2;
    uVar4 = FUN_00025738(*(undefined4 *)(param_2 + 8));
    fVar2 = (float)FUN_00025a5c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    pfVar1[1] = fVar2;
    uVar4 = FUN_00025738(*(undefined4 *)(param_2 + 0xc));
    fVar2 = (float)FUN_00025a5c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    pfVar1[2] = fVar2;
  }
  FUN_00003b1a(*pfVar1,pfVar1[1],pfVar1[2],_DAT_0000e3e0 + 0x90);
  uVar3 = (int)(pfVar1[1] * _DAT_0000e3c0) % 100;
  FUN_0001cd4c(s_ms3791_pid_set_kp__d__02d_ki__d__0000e403 + 1,(int)*pfVar1,
               (int)(*pfVar1 * _DAT_0000e3c0) % 100,(int)pfVar1[1],uVar3,(int)pfVar1[2],
               (int)(pfVar1[2] * _DAT_0000e3c0) % 100);
  return (ulonglong)uVar3 << 0x20;
}




undefined4 FUN_0000e2fa(void)

{
  FUN_0000ddb2();
  FUN_0000de98(0);
  FUN_00015bc4(0x44,1);
  return 0;
}




byte FUN_0000e44e(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = FUN_00015bec(0x39);
  cVar2 = FUN_00015bec(0x38);
  return 1U - cVar2 | ('\x01' - cVar1) * '\x02';
}




undefined4 FUN_0000e46c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  
  iVar1 = DAT_0000e698;
  cVar3 = '\n';
  do {
    bVar4 = param_2 == 0;
    param_2 = param_2 + -1;
    if (bVar4) {
      return 1;
    }
    uVar2 = FUN_0000e44e();
    if (*(byte *)(iVar1 + param_1) == uVar2) {
      cVar3 = cVar3 + -1;
      if (cVar3 == '\0') {
        return 0;
      }
    }
    else {
      cVar3 = '\n';
    }
    FUN_0001eb00(1);
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000e4a6(void)

{
  int iVar1;
  
  FUN_0000df30(*(undefined *)(_DAT_0000e69c + 0x14));
  FUN_0001cd4c(s_buffer_free__0000e69f + 1);
  iVar1 = DAT_0000e698;
  *(undefined *)(DAT_0000e698 + -4) = 1;
  *(undefined *)(iVar1 + -3) = 1;
  *(short *)(iVar1 + -2) = *(short *)(iVar1 + -2) + 1;
  return;
}




void FUN_0000e4c8(void)

{
  int iVar1;
  
  iVar1 = DAT_0000e698;
  *(undefined *)(DAT_0000e698 + -4) = 0;
  *(undefined2 *)(iVar1 + -2) = 0;
  FUN_0001cd4c(s_buffer_full__0000e6b0);
  FUN_0000df64();
  return;
}




void FUN_0000e4e2(void)

{
  int iVar1;
  
  FUN_00015b6c(0x39,0);
  FUN_00015b6c(0x38,0);
  iVar1 = DAT_0000e698;
  *(undefined *)(DAT_0000e698 + -4) = 0;
  *(undefined2 *)(iVar1 + -2) = 0;
  return;
}




void FUN_0000e61a(void)

{
  FUN_0001cd4c(s_init_buffer_irq_0000e720);
  FUN_00015b06(0x39,1,0xe4a7,0);
  FUN_00015b6c(0x39,0);
  FUN_00015b06(0x38,1,DAT_0000e734,0);
  FUN_00015b6c(0x38,0);
  return;
}




void FUN_0000e650(void)

{
  FUN_00015b6c(0x39,1);
  FUN_00015b6c(0x38,1);
  *(undefined2 *)(DAT_0000e698 + -2) = 0;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000e66c(void)

{
  int iVar1;
  
  FUN_0000e61a();
  iVar1 = FUN_0000e44e();
  if (iVar1 == 3) {
    *(undefined *)(_DAT_0000e738 + 3) = 1;
  }
  return 0;
}




void FUN_0000e684(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0000e44e();
  FUN_0001cd4c(s_buffer_status____d_0000e73b + 1,uVar1);
  return;
}




void FUN_0000e750(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_00021342();
  iVar1 = FUN_00021596(param_1,param_2);
  if (iVar1 != 0) {
    FUN_0001cd4c(s_fmc_word_program_fail__ret____d__0000e8ec,iVar1,param_2);
  }
  iVar1 = DAT_00021730;
  *(uint *)(DAT_00021730 + 0x10) = *(uint *)(DAT_00021730 + 0x10) | 0x80;
  if (0x200 < *DAT_0002173c) {
    *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 0x80;
  }
  return;
}




void FUN_0000e77a(int **param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = param_3 << 0x15;
  if (iVar3 != 0) {
    iVar3 = 1;
  }
  uVar4 = iVar3 + (param_3 >> 0xb) & 0xffff;
  uVar2 = (uint)*(ushort *)(*param_1 + 1);
  if (uVar2 < uVar4) {
    uVar4 = uVar2;
  }
  iVar5 = **param_1;
  FUN_00021342();
  FUN_00021938(0x305);
  FUN_00021938(0x304);
  FUN_00021938(0x302);
  for (iVar3 = 0; iVar1 = DAT_00021730, iVar3 < (int)uVar4; iVar3 = (int)(short)((short)iVar3 + 1))
  {
    FUN_00021432(iVar5 + iVar3 * 0x800);
    FUN_00021938(0x305);
    FUN_00021938(0x304);
    FUN_00021938(0x302);
  }
  *(uint *)(DAT_00021730 + 0x10) = *(uint *)(DAT_00021730 + 0x10) | 0x80;
  if (0x200 < *DAT_0002173c) {
    *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 0x80;
  }
  return;
}




void FUN_0000e7ea(int **param_1,uint param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 & 3;
  puVar1 = (uint *)(**param_1 + (param_2 & 0xfffffffc));
  if (uVar4 != 0) {
    uVar3 = *puVar1;
    for (uVar2 = 0; uVar2 < 4 - uVar4; uVar2 = uVar2 + 1) {
      *(char *)param_3 = (char)((uVar3 >> (uVar4 << 3)) >> ((uVar2 & 0x1f) << 3));
      param_4 = param_4 - 1;
      param_3 = (uint *)((int)param_3 + 1);
    }
    puVar1 = puVar1 + 1;
  }
  if (3 < param_4) {
    uVar2 = param_4 >> 2;
    for (uVar4 = 0; uVar4 < uVar2; uVar4 = uVar4 + 1) {
      uVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      *param_3 = uVar3;
      param_4 = param_4 - 4;
      param_3 = param_3 + 1;
    }
  }
  if (param_4 != 0) {
    uVar2 = *puVar1;
    for (uVar4 = 0; uVar4 < param_4; uVar4 = uVar4 + 1) {
      *(char *)param_3 = (char)(uVar2 >> ((uVar4 & 0x1f) << 3));
      param_3 = (uint *)((int)param_3 + 1);
    }
  }
  return;
}




void FUN_0000e852(int **param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = **param_1 + (param_2 & 0xfffffffc);
  if ((param_2 & 3) != 0) {
    uVar2 = 0xffffffff;
    for (uVar1 = 0; uVar1 < 4 - (param_2 & 3); uVar1 = uVar1 + 1) {
      uVar2 = uVar2 >> 8 | (uint)*(byte *)param_3 << 0x18;
      param_4 = param_4 - 1;
      param_3 = (undefined4 *)((int)param_3 + 1);
    }
    FUN_0000e750(iVar4,uVar2);
    iVar4 = iVar4 + 4;
  }
  if (3 < param_4) {
    uVar2 = param_4 >> 2;
    for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1) {
      FUN_0000e750(iVar4,*param_3);
      param_4 = param_4 - 4;
      param_3 = param_3 + 1;
      iVar4 = iVar4 + 4;
    }
  }
  if (param_4 != 0) {
    pbVar3 = (byte *)((int)param_3 + param_4);
    uVar2 = 0xffffffff;
    for (uVar1 = 0; uVar1 < param_4; uVar1 = uVar1 + 1) {
      pbVar3 = pbVar3 + -1;
      uVar2 = (uint)*pbVar3 | uVar2 << 8;
    }
    FUN_0000e750(iVar4,uVar2);
    return;
  }
  return;
}




undefined4 FUN_0000e8da(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_0000e920;
  iVar1 = DAT_0000e91c;
  *DAT_0000e920 = DAT_0000e91c;
  FUN_0000e924(piVar2 + 1,iVar1 + 8);
  return 0;
}




void FUN_0000e924(int *param_1,int param_2)

{
  int iVar1;
  int **ppiVar2;
  
  param_1[2] = param_2;
  iVar1 = DAT_0000e9b8;
  ppiVar2 = *(int ***)(DAT_0000e9b8 + 4);
  *(int **)(DAT_0000e9b8 + 4) = param_1;
  *param_1 = iVar1;
  param_1[1] = (int)ppiVar2;
  *ppiVar2 = param_1;
  return;
}




undefined4 * FUN_0000e94a(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_0000e9b8;
  puVar3 = (undefined4 *)*DAT_0000e9b8;
  while( true ) {
    if (puVar3 == puVar1) {
      return (undefined4 *)0x0;
    }
    iVar2 = FUN_00023a0c(param_1,*(undefined4 *)puVar3[2]);
    if (iVar2 == 0) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  return puVar3;
}




void FUN_0000e97c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0000e98a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 8),0,*(undefined4 *)(iVar1 + 4));
    return;
  }
  return;
}




void FUN_0000e98e(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 8) + 0x10);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0000e99e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(*(int *)(param_1 + 8) + 8));
    return;
  }
  return;
}




void FUN_0000e9a4(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 8) + 0x14);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0000e9b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(*(int *)(param_1 + 8) + 8));
    return;
  }
  return;
}




undefined4 FUN_0000e9c0(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  char cVar4;
  int iVar5;
  uint *puVar6;
  
  puVar6 = *(uint **)*param_1;
  uVar1 = 0;
  iVar5 = param_1[3] + -8;
  pbVar3 = (byte *)(param_1[2] + 8);
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    pbVar2 = pbVar3 + 1;
    uVar1 = uVar1 ^ (uint)*pbVar3 << 8;
    cVar4 = '\b';
    do {
      if ((int)(uVar1 << 0x10) < 0) {
        uVar1 = uVar1 << 1 ^ 0x1021;
      }
      else {
        uVar1 = uVar1 << 1;
      }
      uVar1 = uVar1 & 0xffff;
      cVar4 = cVar4 + -1;
      pbVar3 = pbVar2;
    } while (cVar4 != '\0');
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar1;
  }
  if (*puVar6 == uVar1) {
    return 1;
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_0000ea18(int param_1)

{
  int **ppiVar1;
  int *piVar2;
  int iVar3;
  
  ppiVar1 = _DAT_0000eb48;
  *_DAT_0000eb48 = DAT_0000eb44;
  piVar2 = (int *)FUN_0000e94a(ppiVar1[param_1 + -1]);
  ppiVar1[param_1 + 1] = piVar2;
  if (piVar2 != (int *)0x0) {
    iVar3 = **ppiVar1 + param_1 * 0x10;
    FUN_0000e98e(piVar2,0,*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc));
    iVar3 = FUN_0000e9c0(iVar3,0);
    if (iVar3 == 0) {
      return (int *)0x2;
    }
    piVar2 = (int *)0x1;
  }
  return piVar2;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000ea5a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_10;
  
  local_10 = param_4;
  iVar1 = FUN_0000eb20(param_1,&local_10);
  if (iVar1 < 0) {
    FUN_0001cd4c(s__s__can_t_find_the_key___d_0000eb4b + 1,DAT_0000eb44 + 8,param_1);
    return 0;
  }
  return *(undefined4 *)(*(int *)(**_DAT_0000eb48 + iVar1 * 0x10) + local_10 * 8);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ea8c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_18;
  
  local_18 = param_4;
  iVar1 = FUN_0000eb20(param_1,&local_18);
  if (iVar1 < 0) {
    FUN_0001cd4c(s__s__can_t_find_the_key___d_0000eb4b + 1,DAT_0000eb44 + 0x1b,param_1);
    return;
  }
  FUN_000237a0(*(undefined4 *)(*(int *)(**_DAT_0000eb48 + iVar1 * 0x10) + local_18 * 8),param_2,
               param_3);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000eac8(void)

{
  int **ppiVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 in_r3;
  uint uVar4;
  int **ppiVar5;
  int *piVar6;
  undefined4 local_20;
  
  ppiVar1 = _DAT_0000eb48;
  uVar4 = 0;
  local_20 = in_r3;
  do {
    ppiVar5 = (int **)(**ppiVar1 + uVar4 * 0x10);
    iVar2 = FUN_0000e9c0(ppiVar5,&local_20);
    if (iVar2 == 0) {
      piVar6 = ppiVar5[2];
      puVar3 = (undefined4 *)**ppiVar5;
      *puVar3 = local_20;
      puVar3[1] = ppiVar5[3] + -2;
      FUN_0000e97c(ppiVar1[uVar4 + 1]);
      FUN_0000e9a4(ppiVar1[uVar4 + 1],0,piVar6,ppiVar5[3]);
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 == 0);
  return;
}




undefined4 FUN_0000eb20(int param_1,int *param_2)

{
  if (param_1 - 5U < 0xc3) {
    *param_2 = param_1 + -4;
    return 0;
  }
  if (param_1 - 200U < 200) {
    *param_2 = param_1 + -199;
    return 1;
  }
  return 0xffffffff;
}




void FUN_0000eb92(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint in_r3;
  int local_10;
  uint local_c;
  
  iVar2 = FUN_0000ea18(0);
  if (iVar2 != 1) {
    FUN_0001cd4c(&DAT_0000ebe0);
    FUN_0001cd4c(s_database_checksum_error__load_de_0000ebfc);
    FUN_0001cd4c(&DAT_0000ec30);
    local_10 = DAT_0000ebdc;
    local_c = in_r3;
    FUN_0000ea8c(5,&local_10,4);
    local_c = local_c & 0xffffff00;
    FUN_0000ea8c(6,&local_c,1);
    FUN_0000eac8();
    return;
  }
  piVar3 = (int *)FUN_0000ea5a(5);
  piVar1 = DAT_0000ec38;
  *DAT_0000ec38 = *piVar3;
  if (DAT_0000ebdc != *piVar1) {
    FUN_0000ea8c(5,&stack0xfffffff8,4);
    FUN_0000eac8();
  }
  return;
}




void FUN_0000ec3c(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_0000f038;
  *DAT_0000f038 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[5] = 1;
  puVar1[6] = 0;
  return;
}




void FUN_0000ec50(uint param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = *(byte *)(DAT_0000f038 + 6);
  uVar2 = FUN_00007194(param_1 / 10);
  uVar3 = FUN_00007194(param_1 % 10);
  FUN_00007174(2,uVar2,1);
  FUN_00007174(3,uVar3,1 < bVar1);
  return;
}




void FUN_0000ec96(undefined4 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = *(byte *)(DAT_0000f038 + 6);
  uVar2 = FUN_00007304(0x45);
  uVar3 = FUN_00007194(param_1);
  FUN_00007174(2,uVar2,1);
  FUN_00007174(3,uVar3,1 < bVar1);
  return;
}




void FUN_0000ecd0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_000071fe();
  uVar2 = FUN_00007194(param_1);
  FUN_00007174(2,uVar1,1);
  FUN_00007174(3,uVar2,0);
  return;
}




void FUN_0000ecfa(uint param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = *(byte *)(DAT_0000f038 + 6);
  uVar2 = FUN_00007194(param_1 / 10 & 0xff);
  uVar3 = FUN_00007194(param_1 % 10);
  FUN_00007174(0,uVar2,2 < bVar1);
  FUN_00007174(1,uVar3,3 < bVar1);
  return;
}




void FUN_0000ed4e(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(DAT_0000f038 + 6);
  if (4 < param_1) {
    param_1 = 4;
  }
  uVar2 = FUN_00007194(param_1);
  FUN_00007174(4,uVar2,cVar1 != '\0');
  return;
}




undefined4 FUN_0000ed74(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 >> (param_1 & 0xff) & 1) == 0) {
    if ((int)(param_2 << 0x1b) < 0) {
      return 2;
    }
  }
  else {
    if ((int)(param_2 << 0x1b) < 0) {
      return 3;
    }
    uVar1 = 1;
  }
  return uVar1;
}




void FUN_0000edfc(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0000c5ca();
  iVar1 = DAT_0000f038;
  if (iVar2 != 0) {
    FUN_0001cd4c(s__times__d_T_d_test_fixture__d_ok_0000f047 + 1,*(undefined *)(DAT_0000f038 + 5),
                 *(undefined *)(DAT_0000f038 + 3),*(undefined *)(DAT_0000f038 + 1));
    FUN_000232a8(s__times__d_T_d_test_fixture__d_ok_0000f047 + 1,*(undefined *)(iVar1 + 5),
                 *(undefined *)(iVar1 + 3),*(undefined *)(iVar1 + 1));
    return;
  }
  FUN_0001cd4c(s__times__d_T_d_test_fixture__d_ok_0000f047 + 1,*(undefined *)(DAT_0000f038 + 5),
               *(undefined *)(DAT_0000f038 + 3),*(undefined *)(DAT_0000f038 + 1));
  return;
}




void FUN_0000ee2c(void)

{
  *DAT_0000f038 = DAT_0000f038[1];
  FUN_0000ec96();
  return;
}




undefined4 FUN_0000ee34(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_0000f06c;
  iVar3 = DAT_0000f038;
  if (param_2 == 1) {
    uVar2 = 0;
    do {
      *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_0000f038 + -8)) && (*(ushort *)(DAT_0000f038 + -8) != 0)) {
      uVar2 = 0;
      do {
        *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 4);
    }
    *(short *)(iVar3 + -8) = (short)param_3;
    iVar3 = FUN_0000b590(param_1);
    if (iVar3 == 0) {
      *(undefined4 *)(iVar1 + param_1 * 4) = 0;
    }
    else {
      uVar2 = *(int *)(iVar1 + param_1 * 4) + 1;
      *(uint *)(iVar1 + param_1 * 4) = uVar2;
      if (param_3 <= uVar2) {
        *(undefined4 *)(iVar1 + param_1 * 4) = 0;
        return 1;
      }
    }
  }
  return 0;
}




undefined4 FUN_0000ee9a(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0000f038;
  iVar3 = DAT_0000f06c + 0x20;
  if (param_2 == 1) {
    uVar1 = 0;
    do {
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_0000f038 + -4)) && (*(ushort *)(DAT_0000f038 + -4) != 0)) {
      uVar1 = 0;
      do {
        *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
    }
    *(short *)(iVar2 + -4) = (short)param_3;
    iVar2 = FUN_0000b5a0(param_1);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar3 + param_1 * 4) = 0;
    }
    else {
      uVar1 = *(int *)(iVar3 + param_1 * 4) + 1;
      *(uint *)(iVar3 + param_1 * 4) = uVar1;
      if (param_3 <= uVar1) {
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
        return 1;
      }
    }
  }
  return 0;
}




undefined4 FUN_0000ef02(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0000f038;
  iVar3 = DAT_0000f06c + 0x10;
  if (param_2 == 1) {
    uVar1 = 0;
    do {
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_0000f038 + -6)) && (*(ushort *)(DAT_0000f038 + -6) != 0)) {
      uVar1 = 0;
      do {
        *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
    }
    *(short *)(iVar2 + -6) = (short)param_3;
    iVar2 = FUN_0000b590(param_1);
    if (iVar2 == 0) {
      uVar1 = *(int *)(iVar3 + param_1 * 4) + 1;
      *(uint *)(iVar3 + param_1 * 4) = uVar1;
      if (param_3 <= uVar1) {
        *(undefined4 *)(iVar3 + param_1 * 4) = 0;
        return 1;
      }
    }
    else {
      *(undefined4 *)(iVar3 + param_1 * 4) = 0;
    }
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0000ef68(uint param_1,undefined param_2,int param_3)

{
  undefined *puVar1;
  float fVar2;
  undefined uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined uVar9;
  undefined uVar10;
  byte bVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int iVar16;
  int local_4c;
  
  fVar15 = DAT_0000f070;
  puVar1 = DAT_0000f038;
  if (*(char *)(DAT_0000f074 + 1) == '\0') {
    DAT_0000f038[3] = param_2;
    FUN_0000ec50(puVar1[1]);
    FUN_0000ed4e(puVar1[3] + '\x01');
    fVar2 = DAT_0000f07c;
    iVar16 = DAT_0000f078;
    uVar5 = (uint)(byte)puVar1[5];
    if (param_1 < (byte)puVar1[5]) {
      uVar5 = param_1;
    }
    FUN_0000ecfa(uVar5);
    while ((uint)(byte)puVar1[5] < param_1 + 1) {
      puVar1[6] = (byte)puVar1[5] / 100;
      FUN_0000ecfa();
      puVar1[3] = param_2;
      while ((uint)(byte)puVar1[3] < param_3 + 1U) {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        FUN_0000ed4e((byte)puVar1[3] + 1 & 0xff);
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        while (iVar4 = FUN_0000ef02(puVar1[3],0,5), iVar4 == 0) {
          FUN_0000ee2c();
          FUN_0001eb00(10);
        }
        *puVar1 = 0;
        FUN_0000ec50(puVar1[1]);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        iVar4 = FUN_0000b5b2(puVar1[3]);
        if (iVar4 != 0) {
          uVar3 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar16 + 4));
          puVar1[2] = uVar3;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar3 = puVar1[3];
          uVar10 = *puVar1;
          uVar9 = puVar1[5];
          pcVar8 = s_times__d___d_error__pull_back_ot_0000f45c;
LAB_0000f0ea:
          FUN_0001cd4c(pcVar8,uVar9,uVar10,uVar3);
          goto LAB_0000f648;
        }
        FUN_0000edfc();
        FUN_0000d450(9,0);
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0001cd4c(s_T_d_out_start_0000f494,puVar1[3]);
        FUN_00001144(puVar1[3],0xff,0x9b);
        iVar4 = FUN_0000b65e(puVar1[3],500,0,10);
        if (iVar4 != 0) {
          uVar3 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar16 + 4));
          puVar1[2] = uVar3;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar3 = puVar1[3];
          uVar10 = *puVar1;
          uVar9 = puVar1[5];
          pcVar8 = s_times__d___d_error_T_d_out_timeo_0000f4a4;
          goto LAB_0000f0ea;
        }
        FUN_0000edfc();
        fVar12 = (float)FUN_0000d1e8();
        iVar4 = FUN_0000c5ca();
        if (iVar4 == 0) {
          FUN_0001cd4c(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar12,
                       (int)(fVar12 * fVar2) % 100);
        }
        else {
          iVar4 = (int)(fVar12 * fVar2);
          FUN_0001cd4c(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar12,iVar4 % 100
                      );
          FUN_000232a8(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar12,iVar4 % 100
                      );
        }
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        fVar12 = (float)FUN_0000840a();
        iVar4 = (int)(fVar12 * fVar2);
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        FUN_0001cd4c(s_last_odom____d__02dmm_0000f4fc,(int)fVar12,iVar4 % 100);
        fVar14 = DAT_0000f514;
        iVar4 = 0;
        do {
          fVar13 = (float)FUN_0000840a();
          if ((uint)fVar14 <= (uint)(fVar13 - fVar12)) break;
          FUN_0001eb00(0x14);
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0xfa);
        if (iVar4 == 0xfa) {
          uVar3 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar16 + 4));
          puVar1[2] = uVar3;
          FUN_000005ea(puVar1[3],1);
          iVar16 = (int)((fVar13 - fVar12) * fVar2);
          if (iVar16 < 0) {
            iVar16 = -iVar16;
          }
          FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)(fVar13 - fVar12),iVar16 % 100);
          FUN_0000ee2c();
          uVar3 = puVar1[3];
          uVar10 = *puVar1;
          uVar9 = puVar1[5];
          pcVar8 = s_times__d___d_error_T_d_AT8236_an_0000f538;
          goto LAB_0000f0ea;
        }
        FUN_000005ea(puVar1[3],0);
        FUN_0001eb00(100);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0000df30(200);
        fVar12 = (float)FUN_0000840a();
        iVar4 = (int)(fVar12 * fVar2);
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        FUN_0001cd4c(s_last_odom____d__02dmm_0000f4fc,(int)fVar12,iVar4 % 100);
        bVar11 = 0;
LAB_0000f222:
        iVar4 = FUN_0000e46c(1,s_cmd_parse_out__d__00001f40);
        if (iVar4 != 0) {
          uVar5 = (uint)(byte)puVar1[2];
          if (uVar5 != 0) goto LAB_0000f2aa;
          uVar5 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar16 + 4));
          puVar1[2] = (char)uVar5;
          if (uVar5 == 0) goto LAB_0000f2aa;
          goto LAB_0000f2b2;
        }
        fVar14 = (float)FUN_0000840a();
        if ((int)ABS(fVar12 - fVar14) < DAT_0000f578) {
          uVar3 = 7;
LAB_0000f2c0:
          puVar1[2] = uVar3;
LAB_0000f2c2:
          FUN_000005ea(puVar1[3],1);
          fVar15 = (float)FUN_0000840a();
          iVar16 = (int)((fVar15 - fVar12) * fVar2);
          if (iVar16 < 0) {
            iVar16 = -iVar16;
          }
          FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)(fVar15 - fVar12),iVar16 % 100);
          FUN_0000ee2c();
          uVar3 = puVar1[3];
          uVar10 = *puVar1;
          uVar9 = puVar1[5];
          pcVar8 = DAT_0000f57c;
          goto LAB_0000f0ea;
        }
        fVar14 = (float)FUN_0000840a();
        FUN_0000df64();
        iVar4 = (int)((fVar14 - fVar12) * fVar2);
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)(fVar14 - fVar12),iVar4 % 100);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0001eb00(500);
        FUN_00001160(puVar1[3],0x50,0xff);
        bVar11 = 0;
        local_4c = 0;
        iVar4 = 0;
        uVar5 = 0;
        fVar12 = fVar15;
        do {
          iVar6 = FUN_0000ee9a(puVar1[3],0,5);
          if (iVar6 != 0) {
            FUN_0000d1f0();
            goto LAB_0000f6b8;
          }
          fVar14 = (float)FUN_0000840a();
          fVar13 = fVar14 - fVar12;
          if ((int)fVar13 < _DAT_0000f580) {
            bVar11 = bVar11 + 1;
            if (*(char *)(iVar16 + 3) != '\0') {
              uVar3 = FUN_0000ed74(puVar1[3],*(char *)(iVar16 + 3));
              puVar1[2] = uVar3;
              FUN_000005ea(puVar1[3],1);
              FUN_0000ee2c();
              FUN_0001cd4c(s__<times:_d,__d_error,T_d_pull_ba_0000f582 + 2,puVar1[5],*puVar1,
                           puVar1[3],*(undefined *)(iVar16 + 3));
              goto LAB_0000f648;
            }
            if ((int)((uint)*(byte *)(iVar16 + 4) << 0x1b) < 0) {
              local_4c = local_4c + 1;
              uVar5 = 0;
            }
            else {
              local_4c = 0;
              uVar5 = uVar5 + 1;
            }
            if (bVar11 == 3) {
              if (local_4c == 0) {
                FUN_0000d1f0();
                iVar6 = FUN_0000c5ca();
                if (iVar6 == 0) {
                  FUN_0001cd4c(s_perhaps_pull_back_odometer_0000f5c4);
                }
                else {
                  FUN_0001cd4c(s_perhaps_pull_back_odometer_0000f5c4);
                  FUN_000232a8(s_perhaps_pull_back_odometer_0000f5c4);
                }
              }
            }
            else if ((0x95 < bVar11) && (0x95 < uVar5)) break;
          }
          else {
            bVar11 = 0;
          }
          FUN_0001eb00(0x14);
          iVar4 = iVar4 + 1;
          fVar12 = fVar14;
        } while (iVar4 < 2000);
        if (iVar4 == 2000) {
          uVar3 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar16 + 4));
          puVar1[2] = uVar3;
          iVar16 = (int)(fVar13 * fVar2);
          if (iVar16 < 0) {
            iVar16 = -iVar16;
          }
          FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)fVar13,iVar16 % 100);
          FUN_0000ee2c();
          FUN_0001cd4c(s_times__d___d_error_T_d_pull_back_0000fa34,puVar1[5],*puVar1,puVar1[3]);
          FUN_000005ea(puVar1[3],1);
          goto LAB_0000f648;
        }
        iVar4 = FUN_0000c5ca();
        if (iVar4 == 0) {
          FUN_0001cd4c(s_already_pull_back_odometer_0000f5e0);
        }
        else {
          FUN_0001cd4c(s_already_pull_back_odometer_0000f5e0);
          FUN_000232a8(s_already_pull_back_odometer_0000f5e0);
        }
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        iVar4 = FUN_0000b5a0(puVar1[3]);
        if (((iVar4 == 0) || (iVar4 = FUN_0000b65e(puVar1[3],0x32,1,10), iVar4 != 0)) &&
           (iVar4 = FUN_0000b65e(puVar1[3],300,1,10), iVar4 != 0)) {
          uVar3 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar16 + 4));
          puVar1[2] = uVar3;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar3 = puVar1[3];
          uVar10 = *puVar1;
          uVar9 = puVar1[5];
          pcVar8 = s_times__d___d_error_T_d_back_time_0000fa64;
          goto LAB_0000f0ea;
        }
LAB_0000f6b8:
        FUN_0001eb00(100);
        fVar12 = (float)FUN_0000d1e8();
        FUN_000005ea(puVar1[3],1);
        iVar4 = FUN_0000c5ca();
        if (iVar4 == 0) {
          FUN_0001cd4c(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar12,
                       (int)(fVar12 * fVar2) % 100);
        }
        else {
          iVar4 = (int)(fVar12 * fVar2);
          FUN_0001cd4c(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar12,iVar4 % 100
                      );
          FUN_000232a8(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar12,iVar4 % 100
                      );
        }
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        while (iVar4 = FUN_0000ee34(puVar1[3],0,5), iVar4 != 0) {
          FUN_0000ee2c();
          FUN_0001eb00(10);
        }
        FUN_0000edfc();
        puVar1[3] = puVar1[3] + '\x01';
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      FUN_0000ec50();
      puVar1[5] = puVar1[5] + '\x01';
    }
    FUN_0001cd4c(s_box_aging_finish_all_channel_0000fabc);
    uVar7 = 0;
  }
  else {
    DAT_0000f038[2] = 6;
LAB_0000f648:
    uVar7 = 1;
  }
  return CONCAT44(param_1,uVar7);
LAB_0000f2aa:
  bVar11 = bVar11 + 1;
  if (3 < bVar11) {
LAB_0000f2b2:
    if ((uVar5 & 0xff) == 7) goto LAB_0000f2c2;
    uVar3 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar16 + 4));
    goto LAB_0000f2c0;
  }
  goto LAB_0000f222;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000f7a2(void)

{
  undefined *puVar1;
  undefined uVar2;
  int iVar3;
  char *pcVar4;
  
  puVar1 = _DAT_0000fadc;
  uVar2 = FUN_00000e66(_DAT_0000fadc[3]);
  puVar1[4] = uVar2;
  pcVar4 = puVar1 + -10;
  do {
    if (puVar1[2] != '\0') {
      if (*pcVar4 == '\0') {
        FUN_0000ec96(*puVar1);
      }
      else {
        FUN_0000ecd0();
      }
      *pcVar4 = *pcVar4 == '\0';
      FUN_0001eb00(400);
    }
    FUN_0001eb00(10);
    iVar3 = FUN_0000b590(puVar1[4]);
  } while (iVar3 == 0);
  return;
}




void FUN_0000f7ee(void)

{
  int iVar1;
  undefined4 in_r3;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  undefined4 local_10;
  undefined4 local_c;
  
  bVar3 = 0;
  local_10 = 0;
  local_c = in_r3;
  FUN_0000ee34(0,1,10);
  FUN_0000ef02(0,1,10);
  FUN_0000ee9a(0,1,10);
  FUN_00010016(0,1,10);
  FUN_0001eb00(1);
  do {
    uVar4 = 0;
    uVar2 = 0;
    do {
      iVar1 = FUN_0000ee34(uVar2,0,10);
      if (iVar1 != 0) {
        *(undefined *)((int)&local_10 + uVar2) = 1;
      }
      iVar1 = FUN_0000ef02(uVar2,0,10);
      if (iVar1 == 0) {
        if (*(char *)((int)&local_10 + uVar2) == '\0') goto LAB_0000f870;
        if (bVar3 < 4) {
          bVar3 = bVar3 + 1;
        }
      }
      else {
        *(undefined *)((int)&local_10 + uVar2) = 0;
LAB_0000f870:
        bVar3 = 0;
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
    while (FUN_0001eb00(1), 3 < bVar3) {
      iVar1 = FUN_0000e44e();
      if (iVar1 == 1) {
        uVar4 = uVar4 + 1;
        if (2999 < uVar4) {
          local_c = CONCAT31(local_c._1_3_,2);
          FUN_0000ea8c(6,&local_c,1);
          FUN_0000eac8();
          FUN_0001eb00(100);
          FUN_00013060();
        }
      }
      else {
        uVar4 = 0;
      }
    }
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0000f8b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  byte bVar5;
  undefined uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  undefined extraout_r1;
  undefined uVar13;
  undefined uVar14;
  uint uVar15;
  code *UNRECOVERED_JUMPTABLE_00;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined8 uVar19;
  uint uVar20;
  int iStack_5c;
  
  FUN_0000ec3c();
  while (iVar7 = FUN_0000ef68(param_1,param_2,param_3), iVar7 != 0) {
    FUN_0000f7a2();
  }
  UNRECOVERED_JUMPTABLE_00 = (code *)0xf8d1;
  uVar19 = FUN_0000f7ee();
  iVar7 = (int)((ulonglong)uVar19 >> 0x20);
  if ((int)uVar19 != 4) {
    FUN_0001cd4c(s_box_aging_mode_test__first_chann_0000fadf + 1);
                    /* WARNING: Could not recover jumptable at 0x0000f8e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar19 = (*UNRECOVERED_JUMPTABLE_00)(0);
    return uVar19;
  }
  bVar4 = FUN_00023590(*(undefined4 *)(iVar7 + 4));
  bVar5 = FUN_00023590(*(undefined4 *)(iVar7 + 8));
  uVar15 = (uint)bVar5;
  if ((3 < bVar4) || (3 < uVar15)) {
    FUN_0001cd4c(s_channel_ranges_from_0_to_3_0000fb1c);
                    /* WARNING: Could not recover jumptable at 0x0000f902. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar19 = (*UNRECOVERED_JUMPTABLE_00)(1);
    return uVar19;
  }
  uVar6 = FUN_00023590(*(undefined4 *)(iVar7 + 0xc));
  FUN_00003f6a();
  uVar8 = FUN_0000f8b0(uVar6,bVar4);
  fVar2 = DAT_0000fb38;
  puVar1 = _DAT_0000fadc;
  if (*(char *)(DAT_0000fb3c + 1) == '\0') {
    _DAT_0000fadc[3] = extraout_r1;
    FUN_0000ec50(puVar1[1]);
    FUN_0000ed4e(puVar1[3] + '\x01');
    fVar3 = DAT_0000fb44;
    iVar7 = DAT_0000fb40;
    uVar20 = (uint)(byte)puVar1[5];
    if (uVar8 < (byte)puVar1[5]) {
      uVar20 = uVar8;
    }
    FUN_0000ecfa(uVar20);
    while ((uint)(byte)puVar1[5] < uVar8 + 1) {
      puVar1[6] = (byte)puVar1[5] / 100;
      FUN_0000ecfa();
      puVar1[3] = extraout_r1;
      while ((uint)(byte)puVar1[3] < uVar15 + 1) {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        FUN_0000ed4e((byte)puVar1[3] + 1 & 0xff);
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        while (iVar9 = FUN_0000ef02(puVar1[3],0,5), iVar9 == 0) {
          FUN_0000ee2c();
          FUN_0001eb00(10);
        }
        *puVar1 = 0;
        FUN_0000ec50(puVar1[1]);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        iVar9 = FUN_0000b5b2(puVar1[3]);
        if (iVar9 != 0) {
          uVar6 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar7 + 4));
          puVar1[2] = uVar6;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar6 = puVar1[3];
          uVar14 = *puVar1;
          uVar13 = puVar1[5];
          pcVar10 = s_times__d___d_error__pull_back_ot_0000f45c;
LAB_0000fb6a:
          FUN_0001cd4c(pcVar10,uVar13,uVar14,uVar6);
          goto LAB_0000feb2;
        }
        FUN_0000edfc();
        FUN_0000d450(9,0);
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0001cd4c(s_T_d_out_start_0000f494,puVar1[3]);
        FUN_00001144(puVar1[3],0xff,0x9b);
        iVar9 = FUN_0000b65e(puVar1[3],500,0,10);
        if (iVar9 != 0) {
          uVar6 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar7 + 4));
          puVar1[2] = uVar6;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar6 = puVar1[3];
          uVar14 = *puVar1;
          uVar13 = puVar1[5];
          pcVar10 = s_times__d___d_error_T_d_out_timeo_0000f4a4;
          goto LAB_0000fb6a;
        }
        FUN_0000edfc();
        fVar16 = (float)FUN_0000d1e8();
        iVar9 = FUN_0000c5ca();
        if (iVar9 == 0) {
          FUN_0001cd4c(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar16,
                       (int)(fVar16 * fVar3) % 100);
        }
        else {
          iVar9 = (int)(fVar16 * fVar3);
          FUN_0001cd4c(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar16,iVar9 % 100
                      );
          FUN_000232a8(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar16,iVar9 % 100
                      );
        }
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        fVar16 = (float)FUN_0000840a();
        iVar9 = (int)(fVar16 * fVar3);
        if (iVar9 < 0) {
          iVar9 = -iVar9;
        }
        FUN_0001cd4c(s_last_odom____d__02dmm_0000f4fc,(int)fVar16,iVar9 % 100);
        fVar18 = DAT_0001007c;
        iVar9 = 0;
        do {
          fVar17 = (float)FUN_0000840a();
          if ((uint)fVar18 <= (uint)(fVar17 - fVar16)) break;
          FUN_0001eb00(0x14);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 0xfa);
        if (iVar9 == 0xfa) {
          uVar6 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar7 + 4));
          puVar1[2] = uVar6;
          FUN_000005ea(puVar1[3],1);
          iVar7 = (int)((fVar17 - fVar16) * fVar3);
          if (iVar7 < 0) {
            iVar7 = -iVar7;
          }
          FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)(fVar17 - fVar16),iVar7 % 100);
          FUN_0000ee2c();
          uVar6 = puVar1[3];
          uVar14 = *puVar1;
          uVar13 = puVar1[5];
          pcVar10 = s_times__d___d_error_T_d_AT8236_an_0000f538;
          goto LAB_0000fb6a;
        }
        FUN_000005ea(puVar1[3],0);
        FUN_0001eb00(100);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0000df30(0x9b);
        fVar16 = (float)FUN_0000840a();
        iVar9 = (int)(fVar16 * fVar3);
        if (iVar9 < 0) {
          iVar9 = -iVar9;
        }
        FUN_0001cd4c(s_last_odom____d__02dmm_0000f4fc,(int)fVar16,iVar9 % 100);
        FUN_0001eb00(4000);
        FUN_0000df64();
        iVar9 = (int)((fVar17 - fVar16) * fVar3);
        if (iVar9 < 0) {
          iVar9 = -iVar9;
        }
        FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)(fVar17 - fVar16),iVar9 % 100);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0001eb00(500);
        FUN_00001160(puVar1[3],0x50,0xff);
        bVar4 = 0;
        iStack_5c = 0;
        iVar9 = 0;
        uVar20 = 0;
        fVar16 = fVar2;
        do {
          iVar11 = FUN_0000ee9a(puVar1[3],0,5);
          if (iVar11 != 0) {
            FUN_0000d1f0();
            goto LAB_0000ff1c;
          }
          fVar18 = (float)FUN_0000840a();
          fVar17 = fVar18 - fVar16;
          if ((int)fVar17 < _DAT_00010080) {
            bVar4 = bVar4 + 1;
            if (*(char *)(iVar7 + 3) != '\0') {
              uVar6 = FUN_0000ed74(puVar1[3],*(char *)(iVar7 + 3));
              puVar1[2] = uVar6;
              FUN_000005ea(puVar1[3],1);
              FUN_0000ee2c();
              FUN_0001cd4c(s__<times:_d,__d_error,T_d_pull_ba_0000f582 + 2,puVar1[5],*puVar1,
                           puVar1[3],*(undefined *)(iVar7 + 3));
              goto LAB_0000feb2;
            }
            if ((int)((uint)*(byte *)(iVar7 + 4) << 0x1b) < 0) {
              iStack_5c = iStack_5c + 1;
              uVar20 = 0;
            }
            else {
              iStack_5c = 0;
              uVar20 = uVar20 + 1;
            }
            if (bVar4 == 3) {
              if (iStack_5c == 0) {
                FUN_0000d1f0();
                iVar11 = FUN_0000c5ca();
                if (iVar11 == 0) {
                  FUN_0001cd4c(s_perhaps_pull_back_odometer_0000f5c4);
                }
                else {
                  FUN_0001cd4c(s_perhaps_pull_back_odometer_0000f5c4);
                  FUN_000232a8(s_perhaps_pull_back_odometer_0000f5c4);
                }
              }
            }
            else if ((0x95 < bVar4) && (0x95 < uVar20)) break;
          }
          else {
            bVar4 = 0;
          }
          FUN_0001eb00(0x14);
          iVar9 = iVar9 + 1;
          fVar16 = fVar18;
        } while (iVar9 < 2000);
        if (iVar9 == 2000) {
          uVar6 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar7 + 4));
          puVar1[2] = uVar6;
          iVar7 = (int)(fVar17 * fVar3);
          if (iVar7 < 0) {
            iVar7 = -iVar7;
          }
          FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)fVar17,iVar7 % 100);
          FUN_0000ee2c();
          FUN_0001cd4c(s_times__d___d_error_T_d_pull_back_0000fa34,puVar1[5],*puVar1,puVar1[3]);
          FUN_000005ea(puVar1[3],1);
          goto LAB_0000feb2;
        }
        iVar9 = FUN_0000c5ca();
        if (iVar9 == 0) {
          FUN_0001cd4c(s_already_pull_back_odometer_0000f5e0);
        }
        else {
          FUN_0001cd4c(s_already_pull_back_odometer_0000f5e0);
          FUN_000232a8(s_already_pull_back_odometer_0000f5e0);
        }
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        iVar9 = FUN_0000b5a0(puVar1[3]);
        if (((iVar9 == 0) || (iVar9 = FUN_0000b65e(puVar1[3],0x32,1,10), iVar9 != 0)) &&
           (iVar9 = FUN_0000b65e(puVar1[3],300,1,10), iVar9 != 0)) {
          uVar6 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar7 + 4));
          puVar1[2] = uVar6;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar6 = puVar1[3];
          uVar14 = *puVar1;
          uVar13 = puVar1[5];
          pcVar10 = s_times__d___d_error_T_d_back_time_0000fa64;
          goto LAB_0000fb6a;
        }
LAB_0000ff1c:
        FUN_0001eb00(100);
        fVar16 = (float)FUN_0000d1e8();
        FUN_000005ea(puVar1[3],1);
        iVar9 = FUN_0000c5ca();
        if (iVar9 == 0) {
          FUN_0001cd4c(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar16,
                       (int)(fVar16 * fVar3) % 100);
        }
        else {
          iVar9 = (int)(fVar16 * fVar3);
          FUN_0001cd4c(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar16,iVar9 % 100
                      );
          FUN_000232a8(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar16,iVar9 % 100
                      );
        }
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        while (iVar9 = FUN_0000ee34(puVar1[3],0,5), iVar9 != 0) {
          FUN_0000ee2c();
          FUN_0001eb00(10);
        }
        FUN_0000edfc();
        puVar1[3] = puVar1[3] + '\x01';
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      FUN_0000ec50();
      FUN_0001eb00(6000);
      puVar1[5] = puVar1[5] + '\x01';
    }
    FUN_0001cd4c(s__<feeder_aging_finish_all_channe_00010082 + 2);
    uVar12 = 0;
  }
  else {
    _DAT_0000fadc[2] = 6;
LAB_0000feb2:
    uVar12 = 1;
  }
  return CONCAT44(uVar8,uVar12);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0000f91a(uint param_1,undefined param_2,int param_3)

{
  undefined *puVar1;
  float fVar2;
  float fVar3;
  undefined uVar4;
  byte bVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  undefined uVar10;
  undefined uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int iVar15;
  uint uVar16;
  int local_4c;
  
  fVar2 = DAT_0000fb38;
  puVar1 = _DAT_0000fadc;
  if (*(char *)(DAT_0000fb3c + 1) == '\0') {
    _DAT_0000fadc[3] = param_2;
    FUN_0000ec50(puVar1[1]);
    FUN_0000ed4e(puVar1[3] + '\x01');
    fVar3 = DAT_0000fb44;
    iVar15 = DAT_0000fb40;
    uVar16 = (uint)(byte)puVar1[5];
    if (param_1 < (byte)puVar1[5]) {
      uVar16 = param_1;
    }
    FUN_0000ecfa(uVar16);
    while ((uint)(byte)puVar1[5] < param_1 + 1) {
      puVar1[6] = (byte)puVar1[5] / 100;
      FUN_0000ecfa();
      puVar1[3] = param_2;
      while ((uint)(byte)puVar1[3] < param_3 + 1U) {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        FUN_0000ed4e((byte)puVar1[3] + 1 & 0xff);
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        while (iVar6 = FUN_0000ef02(puVar1[3],0,5), iVar6 == 0) {
          FUN_0000ee2c();
          FUN_0001eb00(10);
        }
        *puVar1 = 0;
        FUN_0000ec50(puVar1[1]);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        iVar6 = FUN_0000b5b2(puVar1[3]);
        if (iVar6 != 0) {
          uVar4 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar15 + 4));
          puVar1[2] = uVar4;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar4 = puVar1[3];
          uVar11 = *puVar1;
          uVar10 = puVar1[5];
          pcVar7 = s_times__d___d_error__pull_back_ot_0000f45c;
LAB_0000fb6a:
          FUN_0001cd4c(pcVar7,uVar10,uVar11,uVar4);
          goto LAB_0000feb2;
        }
        FUN_0000edfc();
        FUN_0000d450(9,0);
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0001cd4c(s_T_d_out_start_0000f494,puVar1[3]);
        FUN_00001144(puVar1[3],0xff,0x9b);
        iVar6 = FUN_0000b65e(puVar1[3],500,0,10);
        if (iVar6 != 0) {
          uVar4 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar15 + 4));
          puVar1[2] = uVar4;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar4 = puVar1[3];
          uVar11 = *puVar1;
          uVar10 = puVar1[5];
          pcVar7 = s_times__d___d_error_T_d_out_timeo_0000f4a4;
          goto LAB_0000fb6a;
        }
        FUN_0000edfc();
        fVar12 = (float)FUN_0000d1e8();
        iVar6 = FUN_0000c5ca();
        if (iVar6 == 0) {
          FUN_0001cd4c(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar12,
                       (int)(fVar12 * fVar3) % 100);
        }
        else {
          iVar6 = (int)(fVar12 * fVar3);
          FUN_0001cd4c(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar12,iVar6 % 100
                      );
          FUN_000232a8(s_feed__ch____d__motor_max_voltage_0000f4cc,puVar1[3],(int)fVar12,iVar6 % 100
                      );
        }
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        fVar12 = (float)FUN_0000840a();
        iVar6 = (int)(fVar12 * fVar3);
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        FUN_0001cd4c(s_last_odom____d__02dmm_0000f4fc,(int)fVar12,iVar6 % 100);
        fVar14 = DAT_0001007c;
        iVar6 = 0;
        do {
          fVar13 = (float)FUN_0000840a();
          if ((uint)fVar14 <= (uint)(fVar13 - fVar12)) break;
          FUN_0001eb00(0x14);
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0xfa);
        if (iVar6 == 0xfa) {
          uVar4 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar15 + 4));
          puVar1[2] = uVar4;
          FUN_000005ea(puVar1[3],1);
          iVar15 = (int)((fVar13 - fVar12) * fVar3);
          if (iVar15 < 0) {
            iVar15 = -iVar15;
          }
          FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)(fVar13 - fVar12),iVar15 % 100);
          FUN_0000ee2c();
          uVar4 = puVar1[3];
          uVar11 = *puVar1;
          uVar10 = puVar1[5];
          pcVar7 = s_times__d___d_error_T_d_AT8236_an_0000f538;
          goto LAB_0000fb6a;
        }
        FUN_000005ea(puVar1[3],0);
        FUN_0001eb00(100);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0000df30(0x9b);
        fVar12 = (float)FUN_0000840a();
        iVar6 = (int)(fVar12 * fVar3);
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        FUN_0001cd4c(s_last_odom____d__02dmm_0000f4fc,(int)fVar12,iVar6 % 100);
        FUN_0001eb00(4000);
        FUN_0000df64();
        iVar6 = (int)((fVar13 - fVar12) * fVar3);
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)(fVar13 - fVar12),iVar6 % 100);
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        FUN_0001eb00(500);
        FUN_00001160(puVar1[3],0x50,0xff);
        bVar5 = 0;
        local_4c = 0;
        iVar6 = 0;
        uVar16 = 0;
        fVar12 = fVar2;
        do {
          iVar8 = FUN_0000ee9a(puVar1[3],0,5);
          if (iVar8 != 0) {
            FUN_0000d1f0();
            goto LAB_0000ff1c;
          }
          fVar14 = (float)FUN_0000840a();
          fVar13 = fVar14 - fVar12;
          if ((int)fVar13 < _DAT_00010080) {
            bVar5 = bVar5 + 1;
            if (*(char *)(iVar15 + 3) != '\0') {
              uVar4 = FUN_0000ed74(puVar1[3],*(char *)(iVar15 + 3));
              puVar1[2] = uVar4;
              FUN_000005ea(puVar1[3],1);
              FUN_0000ee2c();
              FUN_0001cd4c(s__<times:_d,__d_error,T_d_pull_ba_0000f582 + 2,puVar1[5],*puVar1,
                           puVar1[3],*(undefined *)(iVar15 + 3));
              goto LAB_0000feb2;
            }
            if ((int)((uint)*(byte *)(iVar15 + 4) << 0x1b) < 0) {
              local_4c = local_4c + 1;
              uVar16 = 0;
            }
            else {
              local_4c = 0;
              uVar16 = uVar16 + 1;
            }
            if (bVar5 == 3) {
              if (local_4c == 0) {
                FUN_0000d1f0();
                iVar8 = FUN_0000c5ca();
                if (iVar8 == 0) {
                  FUN_0001cd4c(s_perhaps_pull_back_odometer_0000f5c4);
                }
                else {
                  FUN_0001cd4c(s_perhaps_pull_back_odometer_0000f5c4);
                  FUN_000232a8(s_perhaps_pull_back_odometer_0000f5c4);
                }
              }
            }
            else if ((0x95 < bVar5) && (0x95 < uVar16)) break;
          }
          else {
            bVar5 = 0;
          }
          FUN_0001eb00(0x14);
          iVar6 = iVar6 + 1;
          fVar12 = fVar14;
        } while (iVar6 < 2000);
        if (iVar6 == 2000) {
          uVar4 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar15 + 4));
          puVar1[2] = uVar4;
          iVar15 = (int)(fVar13 * fVar3);
          if (iVar15 < 0) {
            iVar15 = -iVar15;
          }
          FUN_0001cd4c(s_odom___last_odom____d__02dmm_0000f518,(int)fVar13,iVar15 % 100);
          FUN_0000ee2c();
          FUN_0001cd4c(s_times__d___d_error_T_d_pull_back_0000fa34,puVar1[5],*puVar1,puVar1[3]);
          FUN_000005ea(puVar1[3],1);
          goto LAB_0000feb2;
        }
        iVar6 = FUN_0000c5ca();
        if (iVar6 == 0) {
          FUN_0001cd4c(s_already_pull_back_odometer_0000f5e0);
        }
        else {
          FUN_0001cd4c(s_already_pull_back_odometer_0000f5e0);
          FUN_000232a8(s_already_pull_back_odometer_0000f5e0);
        }
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        iVar6 = FUN_0000b5a0(puVar1[3]);
        if (((iVar6 == 0) || (iVar6 = FUN_0000b65e(puVar1[3],0x32,1,10), iVar6 != 0)) &&
           (iVar6 = FUN_0000b65e(puVar1[3],300,1,10), iVar6 != 0)) {
          uVar4 = FUN_0000ed74(puVar1[3],*(undefined *)(iVar15 + 4));
          puVar1[2] = uVar4;
          FUN_000005ea(puVar1[3],1);
          FUN_0000ee2c();
          uVar4 = puVar1[3];
          uVar11 = *puVar1;
          uVar10 = puVar1[5];
          pcVar7 = s_times__d___d_error_T_d_back_time_0000fa64;
          goto LAB_0000fb6a;
        }
LAB_0000ff1c:
        FUN_0001eb00(100);
        fVar12 = (float)FUN_0000d1e8();
        FUN_000005ea(puVar1[3],1);
        iVar6 = FUN_0000c5ca();
        if (iVar6 == 0) {
          FUN_0001cd4c(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar12,
                       (int)(fVar12 * fVar3) % 100);
        }
        else {
          iVar6 = (int)(fVar12 * fVar3);
          FUN_0001cd4c(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar12,iVar6 % 100
                      );
          FUN_000232a8(s_back__ch____d__motor_max_voltage_0000fa8c,puVar1[3],(int)fVar12,iVar6 % 100
                      );
        }
        FUN_0000edfc();
        puVar1[1] = puVar1[1] + '\x01';
        FUN_0000ec50();
        while (iVar6 = FUN_0000ee34(puVar1[3],0,5), iVar6 != 0) {
          FUN_0000ee2c();
          FUN_0001eb00(10);
        }
        FUN_0000edfc();
        puVar1[3] = puVar1[3] + '\x01';
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      FUN_0000ec50();
      FUN_0001eb00(6000);
      puVar1[5] = puVar1[5] + '\x01';
    }
    FUN_0001cd4c(s__<feeder_aging_finish_all_channe_00010082 + 2);
    uVar9 = 0;
  }
  else {
    _DAT_0000fadc[2] = 6;
LAB_0000feb2:
    uVar9 = 1;
  }
  return CONCAT44(param_1,uVar9);
}




undefined4 FUN_00010016(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_000100ac;
  iVar1 = DAT_000100a8;
  if (param_2 == 1) {
    uVar2 = 0;
    do {
      *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
  }
  else {
    if ((param_3 != *(ushort *)(DAT_000100ac + 8)) && (*(ushort *)(DAT_000100ac + 8) != 0)) {
      uVar2 = 0;
      do {
        *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 4);
    }
    *(short *)(iVar3 + 8) = (short)param_3;
    iVar3 = FUN_0000b5a0(param_1);
    if (iVar3 == 0) {
      uVar2 = *(int *)(iVar1 + param_1 * 4) + 1;
      *(uint *)(iVar1 + param_1 * 4) = uVar2;
      if (param_3 <= uVar2) {
        *(undefined4 *)(iVar1 + param_1 * 4) = 0;
        return 1;
      }
    }
    else {
      *(undefined4 *)(iVar1 + param_1 * 4) = 0;
    }
  }
  return 0;
}




void FUN_000100b6(int param_1)

{
  if (param_1 != 0) {
    FUN_00010fe4(param_1,0x80);
    return;
  }
  return;
}




void FUN_000100ca(int param_1)

{
  if (param_1 != 0) {
    FUN_00010fe4(param_1,0x180);
    return;
  }
  return;
}




undefined4 FUN_000100d8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_000104cc;
  iVar3 = 0;
  do {
    iVar2 = FUN_00023614(iVar1 + iVar3 * 8,param_1,8);
    if (iVar2 == 0) {
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return 0;
}




void FUN_000100fc(uint *param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = ((*param_2 & 0xff) << 8 | (uint)(*param_2 >> 8)) << 0x10;
  uVar3 = uVar2 | (uint)*(byte *)(param_2 + 1) << 8 | (uint)*(byte *)((int)param_2 + 3);
  uVar5 = ((param_2[2] & 0xff) << 8 | (uint)(param_2[2] >> 8)) << 0x10 |
          (uint)*(byte *)(param_2 + 3) << 8 | (uint)*(byte *)((int)param_2 + 7);
  uVar1 = (uVar3 ^ uVar5 >> 4) & 0xf0f0f0f;
  uVar3 = uVar3 ^ uVar1;
  uVar5 = uVar5 ^ uVar1 << 4;
  uVar5 = uVar5 ^ (uVar5 ^ uVar3) & 0x10101010;
  iVar6 = DAT_000104cc + -0x80;
  iVar4 = DAT_000104cc + -0x40;
  uVar1 = (*(uint *)(iVar6 + ((uVar3 << 4) >> 0x1c) * 4) | *(int *)(iVar6 + (uVar3 & 0xf) * 4) << 3
           | *(int *)(iVar6 + ((uVar3 << 0x14) >> 0x1c) * 4) << 2 |
             *(int *)(iVar6 + ((uVar3 << 0xc) >> 0x1c) * 4) << 1 |
           *(int *)(iVar6 + ((uVar3 << 0x17) >> 0x1c) * 4) << 7 |
           *(int *)(iVar6 + ((uVar3 << 0xf) >> 0x1c) * 4) << 6 |
           *(int *)(iVar6 + ((uVar3 << 7) >> 0x1c) * 4) << 5 |
          *(int *)(iVar6 + (uVar2 >> 0x1d) * 4) << 4) & 0xfffffff;
  uVar5 = (*(uint *)(iVar4 + ((uVar5 << 3) >> 0x1c) * 4) |
           *(int *)(iVar4 + ((uVar5 << 0x1b) >> 0x1c) * 4) << 3 |
           *(int *)(iVar4 + ((uVar5 << 0x13) >> 0x1c) * 4) << 2 |
           *(int *)(iVar4 + ((uVar5 << 0xb) >> 0x1c) * 4) << 1 |
           *(int *)(iVar4 + ((uVar5 << 0x18) >> 0x1c) * 4) << 7 |
           *(int *)(iVar4 + ((uVar5 << 0x10) >> 0x1c) * 4) << 6 |
           *(int *)(iVar4 + ((uVar5 << 8) >> 0x1c) * 4) << 5 |
          *(int *)(iVar4 + (uVar5 >> 0x1c) * 4) << 4) & 0xfffffff;
  iVar4 = 0;
  do {
    uVar1 = (uVar1 & 0x7ffffff) << 1 | uVar1 >> 0x1b;
    uVar5 = (uVar5 & 0x7ffffff) << 1 | uVar5 >> 0x1b;
    while( true ) {
      *param_1 = (uVar1 & 0x2400000) << 4 | (uVar1 & 1) << 0x1c | (uVar1 & 0x2000) << 0xe |
                 (uVar1 & 0x82) << 0x12 | (uVar1 & 0x40000) << 6 | (uVar1 & 0x1000) << 9 |
                 uVar1 >> 1 & 0x100000 | (uVar1 & 0x100) << 10 | (uVar1 & 0x8000) << 2 |
                 uVar1 >> 10 & 0x10000 | uVar5 >> 0xd & 0x2000 | uVar5 >> 4 & 0x1000 |
                 (uVar5 & 0x20) << 6 | uVar5 >> 1 & 0x400 | uVar5 >> 0xe & 0x200 | uVar5 & 0x100 |
                 uVar5 >> 5 & 0x20 | uVar5 >> 10 & 0x10 | uVar5 >> 3 & 8 | uVar5 >> 0x12 & 4 |
                 uVar5 >> 0x1a & 2 | (uVar5 << 7) >> 0x1f;
      param_1[1] = (uVar1 & 0x4000) << 0xf | (uVar1 & 0x800) << 0x11 | (uVar1 & 0x20000) << 10 |
                   (uVar1 & 0x10) << 0x16 | uVar1 >> 2 & 0x2000000 | (uVar1 & 0x800000) << 1 |
                   (uVar1 & 0x20) << 0x10 | (uVar1 & 0x200) << 0xb | (uVar1 & 0x10000) << 3 |
                   uVar1 >> 6 & 0x40000 | (uVar1 & 4) << 0xf | uVar1 >> 4 & 0x10000 |
                   uVar5 >> 2 & 0x2000 | (uVar5 & 0x10) << 8 | uVar5 >> 0xe & 0x808 |
                   uVar5 >> 9 & 0x400 | uVar5 & 0x200 | (uVar5 & 2) << 7 | uVar5 >> 7 & 0x20 |
                   uVar5 >> 3 & 0x11 | (uVar5 & 1) << 2 | uVar5 >> 0x15 & 2;
      param_1 = param_1 + 2;
      iVar4 = iVar4 + 1;
      if (0xf < iVar4) {
        return;
      }
      if (((iVar4 < 2) || (iVar4 == 8)) || (iVar4 == 0xf)) break;
      uVar1 = (uVar1 & 0x3ffffff) << 2 | uVar1 >> 0x1a;
      uVar5 = (uVar5 & 0x3ffffff) << 2 | uVar5 >> 0x1a;
    }
  } while( true );
}




undefined4 FUN_000103f0(void)

{
  FUN_000100fc();
  return 0;
}




undefined4 FUN_000103fa(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  FUN_000100fc();
  iVar1 = 0;
  do {
    uVar2 = *(undefined4 *)(param_1 + iVar1 * 4);
    *(undefined4 *)(param_1 + iVar1 * 4) = *(undefined4 *)(param_1 + (0x1e - iVar1) * 4);
    *(undefined4 *)(param_1 + (0x1e - iVar1) * 4) = uVar2;
    iVar3 = param_1 + iVar1 * 4;
    iVar4 = 0x1f - iVar1;
    uVar2 = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(param_1 + iVar4 * 4);
    iVar1 = iVar1 + 2;
    *(undefined4 *)(param_1 + iVar4 * 4) = uVar2;
  } while (iVar1 < 0x10);
  return 0;
}




void FUN_00010436(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_000100fc(param_1,param_3);
  FUN_000100fc(param_2 + 0x80,param_3 + 8);
  iVar2 = 0;
  do {
    iVar3 = param_2 + iVar2 * 4;
    *(undefined4 *)(param_2 + iVar2 * 4) = *(undefined4 *)(param_1 + (0x1e - iVar2) * 4);
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(param_1 + (0x1f - iVar2) * 4);
    iVar1 = param_1 + iVar2 * 4;
    *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(param_2 + (0x3e - iVar2) * 4);
    *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(param_2 + (0x3f - iVar2) * 4);
    *(undefined4 *)(iVar1 + 0x100) = *(undefined4 *)(param_1 + iVar2 * 4);
    *(undefined4 *)(iVar1 + 0x104) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(iVar3 + 0x100) = *(undefined4 *)(param_2 + iVar2 * 4);
    iVar2 = iVar2 + 2;
    *(undefined4 *)(iVar3 + 0x104) = *(undefined4 *)(iVar3 + 4);
  } while (iVar2 < 0x20);
  return;
}




undefined4 FUN_000104ae(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_188 [392];
  
  FUN_00010436(param_1,auStack_188,param_2);
  FUN_00010fe4(auStack_188,0x180);
  return 0;
}




undefined4 FUN_000104d0(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_188 [392];
  
  FUN_00010436(auStack_188,param_1,param_2);
  FUN_00010fe4(auStack_188,0x180);
  return 0;
}




void FUN_000104ec(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_000100fc(param_1,param_3);
  FUN_000100fc(param_2 + 0x80,param_3 + 8);
  FUN_000100fc(param_1 + 0x100,param_3 + 0x10);
  iVar1 = 0;
  do {
    *(undefined4 *)(param_2 + iVar1 * 4) = *(undefined4 *)(param_1 + (0x5e - iVar1) * 4);
    iVar2 = param_2 + iVar1 * 4;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + (0x5f - iVar1) * 4);
    iVar3 = param_1 + iVar1 * 4;
    *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(param_2 + (0x3e - iVar1) * 4);
    *(undefined4 *)(iVar3 + 0x84) = *(undefined4 *)(param_2 + (0x3f - iVar1) * 4);
    *(undefined4 *)(iVar2 + 0x100) = *(undefined4 *)(param_1 + (0x1e - iVar1) * 4);
    iVar3 = 0x1f - iVar1;
    iVar1 = iVar1 + 2;
    *(undefined4 *)(iVar2 + 0x104) = *(undefined4 *)(param_1 + iVar3 * 4);
  } while (iVar1 < 0x20);
  return;
}




undefined4 FUN_00010568(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_188 [392];
  
  FUN_000104ec(param_1,auStack_188,param_2);
  FUN_00010fe4(auStack_188,0x180);
  return 0;
}




undefined4 FUN_00010582(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_188 [392];
  
  FUN_000104ec(auStack_188,param_1,param_2);
  FUN_00010fe4(auStack_188,0x180);
  return 0;
}




undefined4 FUN_0001059e(uint *param_1,ushort *param_2,undefined *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = ((*param_2 & 0xff) << 8 | (uint)(*param_2 >> 8)) << 0x10 |
          (uint)*(byte *)(param_2 + 1) << 8 | (uint)*(byte *)((int)param_2 + 3);
  uVar2 = ((param_2[2] & 0xff) << 8 | (uint)(param_2[2] >> 8)) << 0x10 |
          (uint)*(byte *)(param_2 + 3) << 8 | (uint)*(byte *)((int)param_2 + 7);
  uVar1 = (uVar2 ^ uVar3 >> 4) & 0xf0f0f0f;
  uVar2 = uVar2 ^ uVar1;
  uVar3 = uVar3 ^ uVar1 << 4;
  uVar1 = (uVar2 ^ uVar3 >> 0x10) & 0xffff;
  uVar2 = uVar2 ^ uVar1;
  uVar3 = uVar3 ^ uVar1 << 0x10;
  uVar1 = (uVar3 ^ uVar2 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar1;
  uVar2 = uVar2 ^ uVar1 << 2;
  uVar1 = (uVar3 ^ uVar2 >> 8) & 0xff00ff;
  uVar2 = uVar2 ^ uVar1 << 8;
  uVar3 = uVar3 ^ uVar1;
  uVar1 = uVar2 >> 0x1f | uVar2 << 1;
  uVar2 = (uVar3 ^ uVar1) & 0xaaaaaaaa;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar3 >> 0x1f | uVar3 << 1;
  iVar5 = 0;
  do {
    iVar5 = iVar5 + 1;
    uVar2 = *param_1 ^ uVar1;
    uVar4 = param_1[1] ^ (uVar1 >> 4 | uVar1 << 0x1c);
    uVar3 = *(uint *)(DAT_00010a08 + -0x100 + (uVar4 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a0c + ((uVar4 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a10 + ((uVar4 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a14 + ((uVar4 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + (uVar2 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a08 + -0x200 + ((uVar2 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + -0x400 + ((uVar2 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + -0x600 + ((uVar2 << 2) >> 0x1a) * 4) ^ uVar3;
    uVar2 = param_1[2] ^ uVar3;
    uVar4 = param_1[3] ^ (uVar3 >> 4 | uVar3 << 0x1c);
    uVar1 = *(uint *)(DAT_00010a08 + -0x100 + (uVar4 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a0c + ((uVar4 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a10 + ((uVar4 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a14 + ((uVar4 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + (uVar2 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a08 + -0x200 + ((uVar2 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + -0x400 + ((uVar2 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + -0x600 + ((uVar2 << 2) >> 0x1a) * 4) ^ uVar1;
    param_1 = param_1 + 4;
  } while (iVar5 < 8);
  uVar1 = uVar1 >> 1 | uVar1 << 0x1f;
  uVar2 = (uVar1 ^ uVar3) & 0xaaaaaaaa;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = (uVar3 ^ uVar2) >> 1 | uVar3 << 0x1f;
  uVar2 = (uVar1 ^ uVar3 >> 8) & 0xff00ff;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar3 ^ uVar2 << 8;
  uVar2 = (uVar1 ^ uVar3 >> 2) & 0x33333333;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar3 ^ uVar2 << 2;
  uVar2 = (uVar3 ^ uVar1 >> 0x10) & 0xffff;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar1 ^ uVar2 << 0x10;
  uVar2 = (uVar3 ^ uVar1 >> 4) & 0xf0f0f0f;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar1 ^ uVar2 << 4;
  *param_3 = (char)(uVar1 >> 0x18);
  param_3[1] = (char)(uVar1 >> 0x10);
  param_3[2] = (char)(uVar1 >> 8);
  param_3[3] = (char)uVar1;
  param_3[4] = (char)(uVar3 >> 0x18);
  param_3[5] = (char)(uVar3 >> 0x10);
  param_3[6] = (char)(uVar3 >> 8);
  param_3[7] = (char)uVar3;
  return 0;
}




undefined4
FUN_00010778(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if ((param_3 & 7) == 0) {
    if (param_2 == 1) {
      for (; param_3 != 0; param_3 = param_3 - 8) {
        iVar2 = 0;
        do {
          *(byte *)((int)param_6 + iVar2) =
               *(byte *)((int)param_5 + iVar2) ^ *(byte *)((int)param_4 + iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 8);
        FUN_0001059e(param_1,param_6);
        puVar3 = param_6 + 1;
        *param_4 = *param_6;
        param_6 = param_6 + 2;
        param_4[1] = *puVar3;
        param_5 = param_5 + 2;
      }
    }
    else {
      for (; param_3 != 0; param_3 = param_3 - 8) {
        uVar1 = *param_5;
        uVar4 = param_5[1];
        FUN_0001059e(param_1,param_5,param_6);
        iVar2 = 0;
        do {
          *(byte *)((int)param_6 + iVar2) =
               *(byte *)((int)param_6 + iVar2) ^ *(byte *)((int)param_4 + iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 8);
        *param_4 = uVar1;
        param_6 = param_6 + 2;
        param_4[1] = uVar4;
        param_5 = param_5 + 2;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}




undefined4 FUN_00010800(uint *param_1,ushort *param_2,undefined *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar5 = ((*param_2 & 0xff) << 8 | (uint)(*param_2 >> 8)) << 0x10 |
          (uint)*(byte *)(param_2 + 1) << 8 | (uint)*(byte *)((int)param_2 + 3);
  uVar4 = ((param_2[2] & 0xff) << 8 | (uint)(param_2[2] >> 8)) << 0x10 |
          (uint)*(byte *)(param_2 + 3) << 8 | (uint)*(byte *)((int)param_2 + 7);
  uVar3 = (uVar4 ^ uVar5 >> 4) & 0xf0f0f0f;
  uVar4 = uVar4 ^ uVar3;
  uVar5 = uVar5 ^ uVar3 << 4;
  uVar3 = (uVar4 ^ uVar5 >> 0x10) & 0xffff;
  uVar4 = uVar4 ^ uVar3;
  uVar5 = uVar5 ^ uVar3 << 0x10;
  uVar3 = (uVar5 ^ uVar4 >> 2) & 0x33333333;
  uVar5 = uVar5 ^ uVar3;
  uVar4 = uVar4 ^ uVar3 << 2;
  uVar3 = (uVar5 ^ uVar4 >> 8) & 0xff00ff;
  uVar5 = uVar5 ^ uVar3;
  uVar4 = uVar4 ^ uVar3 << 8;
  uVar3 = uVar4 >> 0x1f | uVar4 << 1;
  uVar4 = (uVar5 ^ uVar3) & 0xaaaaaaaa;
  uVar3 = uVar3 ^ uVar4;
  uVar5 = uVar5 ^ uVar4;
  uVar4 = uVar5 >> 0x1f | uVar5 << 1;
  iVar7 = 0;
  do {
    iVar7 = iVar7 + 1;
    uVar5 = *param_1 ^ uVar3;
    uVar6 = param_1[1] ^ (uVar3 >> 4 | uVar3 << 0x1c);
    puVar1 = param_1 + 4;
    uVar4 = *(uint *)(DAT_00010a08 + -0x100 + (uVar6 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a0c + ((uVar6 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a10 + ((uVar6 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a14 + ((uVar6 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + (uVar5 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a18 + ((uVar5 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a1c + ((uVar5 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + -0x600 + ((uVar5 << 2) >> 0x1a) * 4) ^ uVar4;
    uVar5 = param_1[2] ^ uVar4;
    uVar6 = param_1[3] ^ (uVar4 >> 4 | uVar4 << 0x1c);
    uVar3 = *(uint *)(DAT_00010a08 + -0x100 + (uVar6 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a0c + ((uVar6 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a10 + ((uVar6 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a14 + ((uVar6 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + (uVar5 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a18 + ((uVar5 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a1c + ((uVar5 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + -0x600 + ((uVar5 << 2) >> 0x1a) * 4) ^ uVar3;
    param_1 = puVar1;
  } while (iVar7 < 8);
  iVar7 = 0;
  do {
    uVar5 = *puVar1 ^ uVar4;
    iVar8 = DAT_00010a18 + 0x100;
    uVar6 = puVar1[1] ^ (uVar4 >> 4 | uVar4 << 0x1c);
    puVar2 = puVar1 + 4;
    uVar3 = *(uint *)(iVar8 + (uVar6 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a0c + ((uVar6 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a10 + ((uVar6 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a14 + ((uVar6 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + (uVar5 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a18 + ((uVar5 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a1c + ((uVar5 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a18 + -0x400 + ((uVar5 << 2) >> 0x1a) * 4) ^ uVar3;
    uVar5 = puVar1[2] ^ uVar3;
    iVar7 = iVar7 + 1;
    uVar6 = puVar1[3] ^ (uVar3 >> 4 | uVar3 << 0x1c);
    uVar4 = *(uint *)(iVar8 + (uVar6 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a0c + ((uVar6 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a10 + ((uVar6 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a0c + -0x400 + ((uVar6 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a08 + (uVar5 & 0x3f) * 4) ^
            *(uint *)(DAT_00010a18 + ((uVar5 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a1c + ((uVar5 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a0c + -0x300 + ((uVar5 << 2) >> 0x1a) * 4) ^ uVar4;
    puVar1 = puVar2;
  } while (iVar7 < 8);
  iVar7 = 0;
  do {
    uVar5 = *puVar2 ^ uVar3;
    iVar7 = iVar7 + 1;
    uVar6 = puVar2[1] ^ (uVar3 >> 4 | uVar3 << 0x1c);
    uVar4 = *(uint *)(iVar8 + (uVar6 & 0x3f) * 4) ^
            *(uint *)(DAT_00010e6c + -0x300 + ((uVar6 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + -0x500 + ((uVar6 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + -0x700 + ((uVar6 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + (uVar5 & 0x3f) * 4) ^
            *(uint *)(DAT_00010e6c + -0x200 + ((uVar5 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a0c + -0x100 + ((uVar5 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + -0x600 + ((uVar5 << 2) >> 0x1a) * 4) ^ uVar4;
    uVar5 = puVar2[2] ^ uVar4;
    uVar6 = puVar2[3] ^ (uVar4 >> 4 | uVar4 << 0x1c);
    uVar3 = *(uint *)(iVar8 + (uVar6 & 0x3f) * 4) ^
            *(uint *)(DAT_00010e6c + -0x300 + ((uVar6 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + -0x500 + ((uVar6 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + -0x700 + ((uVar6 << 2) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + (uVar5 & 0x3f) * 4) ^
            *(uint *)(DAT_00010e6c + -0x200 + ((uVar5 << 0x12) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010a0c + -0x100 + ((uVar5 << 10) >> 0x1a) * 4) ^
            *(uint *)(DAT_00010e6c + -0x600 + ((uVar5 << 2) >> 0x1a) * 4) ^ uVar3;
    puVar2 = puVar2 + 4;
  } while (iVar7 < 8);
  uVar3 = uVar3 >> 1 | uVar3 << 0x1f;
  uVar5 = (uVar3 ^ uVar4) & 0xaaaaaaaa;
  uVar3 = uVar3 ^ uVar5;
  uVar4 = (uVar4 ^ uVar5) >> 1 | uVar4 << 0x1f;
  uVar5 = (uVar3 ^ uVar4 >> 8) & 0xff00ff;
  uVar3 = uVar3 ^ uVar5;
  uVar4 = uVar4 ^ uVar5 << 8;
  uVar5 = (uVar3 ^ uVar4 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar5;
  uVar4 = uVar4 ^ uVar5 << 2;
  uVar5 = (uVar4 ^ uVar3 >> 0x10) & 0xffff;
  uVar4 = uVar4 ^ uVar5;
  uVar3 = uVar3 ^ uVar5 << 0x10;
  uVar5 = (uVar4 ^ uVar3 >> 4) & 0xf0f0f0f;
  uVar4 = uVar4 ^ uVar5;
  uVar3 = uVar3 ^ uVar5 << 4;
  *param_3 = (char)(uVar3 >> 0x18);
  param_3[1] = (char)(uVar3 >> 0x10);
  param_3[2] = (char)(uVar3 >> 8);
  param_3[3] = (char)uVar3;
  param_3[4] = (char)(uVar4 >> 0x18);
  param_3[5] = (char)(uVar4 >> 0x10);
  param_3[6] = (char)(uVar4 >> 8);
  param_3[7] = (char)uVar4;
  return 0;
}




undefined4
FUN_00010bd2(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if ((param_3 & 7) == 0) {
    if (param_2 == 1) {
      for (; param_3 != 0; param_3 = param_3 - 8) {
        iVar2 = 0;
        do {
          *(byte *)((int)param_6 + iVar2) =
               *(byte *)((int)param_5 + iVar2) ^ *(byte *)((int)param_4 + iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 8);
        FUN_00010800(param_1,param_6);
        puVar3 = param_6 + 1;
        *param_4 = *param_6;
        param_6 = param_6 + 2;
        param_4[1] = *puVar3;
        param_5 = param_5 + 2;
      }
    }
    else {
      for (; param_3 != 0; param_3 = param_3 - 8) {
        uVar1 = *param_5;
        uVar4 = param_5[1];
        FUN_00010800(param_1,param_5,param_6);
        iVar2 = 0;
        do {
          *(byte *)((int)param_6 + iVar2) =
               *(byte *)((int)param_6 + iVar2) ^ *(byte *)((int)param_4 + iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 8);
        *param_4 = uVar1;
        param_6 = param_6 + 2;
        param_4[1] = uVar4;
        param_5 = param_5 + 2;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}




uint FUN_00010c58(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined auStack_a0 [128];
  
  FUN_000103f0(auStack_a0,param_4);
  iVar1 = param_3 << 0x1d;
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  uVar4 = (iVar1 + (param_3 >> 3)) * 8;
  if (uVar4 - param_3 == 0) {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 8) {
      FUN_0001059e(auStack_a0,param_2 + uVar2,param_1 + uVar2);
    }
    if (param_3 <= uVar4 && uVar4 - param_3 != 0) {
      iVar1 = thunk_FUN_0001d084(uVar4);
      iVar3 = uVar2 - 8;
      FUN_000237a0(iVar1,param_2 + iVar3,param_3 - iVar3);
      FUN_00023912((param_3 & 7) + iVar1,-param_3 & 7,0);
      FUN_0001059e(auStack_a0,iVar1,param_1 + iVar3);
      thunk_FUN_0001d330(iVar1);
    }
    FUN_000100b6(auStack_a0);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}




undefined4 FUN_00010ce6(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined auStack_98 [132];
  
  if ((param_3 & 7) == 0) {
    FUN_000103fa(auStack_98,param_4);
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 8) {
      FUN_0001059e(auStack_98,param_2 + uVar2,param_1 + uVar2);
    }
    FUN_000100b6(auStack_98);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}




undefined4
FUN_00010d20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined auStack_a0 [128];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if (param_5 == (undefined4 *)0x0) {
    param_5 = &local_20;
  }
  FUN_000103f0(auStack_a0,param_4);
  FUN_00010778(auStack_a0,1,param_3,param_5,param_2,param_1);
  FUN_000100b6(auStack_a0);
  return param_3;
}




undefined4
FUN_00010d5a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined auStack_a0 [128];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if (param_5 == (undefined4 *)0x0) {
    param_5 = &local_20;
  }
  FUN_000103fa(auStack_a0,param_4);
  FUN_00010778(auStack_a0,0,param_3,param_5,param_2,param_1);
  FUN_000100b6(auStack_a0);
  return 0;
}




uint FUN_00010d92(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined auStack_1a0 [384];
  
  if (param_5 == 0x10) {
    FUN_000104ae(auStack_1a0,param_4);
  }
  else if (param_5 == 0x18) {
    FUN_00010568(auStack_1a0,param_4);
  }
  iVar1 = param_3 << 0x1d;
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  uVar4 = (iVar1 + (param_3 >> 3)) * 8;
  if (uVar4 - param_3 == 0) {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 8) {
      FUN_00010800(auStack_1a0,param_2 + uVar2,param_1 + uVar2);
    }
    if (param_3 <= uVar4 && uVar4 - param_3 != 0) {
      iVar1 = thunk_FUN_0001d084(uVar4);
      iVar3 = uVar2 - 8;
      FUN_000237a0(iVar1,param_2 + iVar3,param_3 - iVar3);
      FUN_00023912((param_3 & 7) + iVar1,-param_3 & 7,0);
      FUN_00010800(auStack_1a0,iVar1,param_1 + iVar3);
      thunk_FUN_0001d330(iVar1);
    }
    FUN_000100ca(auStack_1a0);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}




undefined4 FUN_00010e36(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  uint uVar2;
  undefined auStack_198 [388];
  
  if ((param_3 & 7) == 0) {
    if (param_5 == 0x10) {
      FUN_000104d0(auStack_198,param_4);
    }
    else if (param_5 == 0x18) {
      FUN_00010582(auStack_198,param_4);
    }
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 8) {
      FUN_00010800(auStack_198,param_2 + uVar2,param_1 + uVar2);
    }
    FUN_000100ca(auStack_198);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}




uint FUN_00010e8a(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,int param_5,
                 undefined4 *param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined auStack_1a8 [384];
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = 0;
  local_24 = 0;
  if (param_6 == (undefined4 *)0x0) {
    param_6 = &local_28;
  }
  if (param_5 == 0x10) {
    FUN_000104ae(auStack_1a8,param_4);
  }
  else if (param_5 == 0x18) {
    FUN_00010568(auStack_1a8,param_4);
  }
  if ((param_3 & 7) == 0) {
    FUN_00010bd2(auStack_1a8,1,param_3,param_6,param_2,param_1);
  }
  else {
    iVar2 = (param_3 - (param_3 & 7)) + 8;
    uVar1 = thunk_FUN_0001d316(1,iVar2);
    FUN_000237a0(uVar1,param_2,param_3);
    FUN_00010bd2(auStack_1a8,1,iVar2,param_6,uVar1,param_1);
    thunk_FUN_0001d330(uVar1);
  }
  FUN_000100ca(auStack_1a8);
  return param_3;
}




undefined4
FUN_00010f14(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,int param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  undefined auStack_1a0 [384];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if ((param_3 & 7) == 0) {
    if (param_6 == (undefined4 *)0x0) {
      param_6 = &local_20;
    }
    if (param_5 == 0x10) {
      FUN_000104d0(auStack_1a0,param_4);
    }
    else if (param_5 == 0x18) {
      FUN_00010582(auStack_1a0,param_4);
    }
    FUN_00010bd2(auStack_1a0,0,param_3,param_6,param_2,param_1);
    FUN_000100ca(auStack_1a0);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}




void FUN_00010f6c(void)

{
  int iVar1;
  char *pcVar2;
  undefined auStack_7c [32];
  undefined auStack_5c [32];
  undefined auStack_3c [32];
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  FUN_000238ae(auStack_5c,&DAT_00010ff4,0x20);
  local_1c = DAT_00011014;
  uStack_18 = DAT_00011018;
  uStack_14 = DAT_0001101c;
  uStack_10 = DAT_00011020;
  FUN_000238ae(auStack_3c,&DAT_00011024,0x20);
  FUN_000232a8(s_DES_Algorithm_Test_00011044);
  FUN_00010d92(auStack_7c,auStack_5c,0x20,&local_1c,0x10);
  iVar1 = FUN_00023614(auStack_7c,auStack_3c,0x20);
  if (iVar1 == 0) {
    pcVar2 = s_ecb_enc_model_passed_00011070;
  }
  else {
    pcVar2 = s_ecb_enc_model_failed_00011058;
  }
  FUN_000232a8(pcVar2);
  FUN_00010e36(auStack_7c,auStack_3c,0x20,&local_1c,0x10);
  iVar1 = FUN_00023614(auStack_7c,auStack_5c,0x20);
  if (iVar1 == 0) {
    pcVar2 = s_ecb_enc_model_passed_00011070;
  }
  else {
    pcVar2 = s_ecb_enc_model_failed_00011058;
  }
  FUN_000232a8(pcVar2);
  return;
}




void FUN_00010fe4(undefined *param_1,int param_2)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}




void FUN_00011088(uint param_1,undefined *param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_1; uVar1 = uVar1 + 1 & 0xffff) {
    FUN_0001cd4c(s__02x_00011494,*param_2);
    if ((uVar1 & 7) == 7) {
      FUN_0001cd4c(&DAT_0001149c);
    }
    param_2 = param_2 + 1;
  }
  FUN_0001cd4c(&DAT_0001149c);
  return;
}




undefined4 FUN_000110be(void)

{
  FUN_0000a5fc();
  return 0x10;
}




undefined4 FUN_000110c8(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_000114a0[1];
  uVar2 = DAT_000114a0[2];
  *param_1 = *DAT_000114a0;
  param_1[1] = uVar1 & uVar2;
  return 8;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000110e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = param_3;
  uStack_c = param_4;
  FUN_0001fb24(0x603);
  FUN_0001fb24(0x604);
  FUN_0001fb24(0x605);
  puVar1 = _DAT_000114a4;
  FUN_00015b9c(*_DAT_000114a4,0);
  FUN_00015b9c(puVar1[1],0);
  FUN_00015bc4(*puVar1,1);
  FUN_00015bc4(puVar1[1],1);
  FUN_000110c8(&uStack_10);
  FUN_0001cd4c(s_mcu_uid___000114a7 + 1);
  FUN_00011088(8,&uStack_10);
  FUN_0001cd4c(s_device_init_000114b4);
  if (*(char *)((int)puVar1 + -0xb) == '\0') {
    *(undefined *)((int)puVar1 + -0xb) = 1;
    FUN_0001ab02(_DAT_000114c8,&DAT_000114c4,1);
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011150(void)

{
  undefined4 *puVar1;
  
  puVar1 = _DAT_000114a4;
  FUN_00015bc4(_DAT_000114a4[1],0);
  FUN_00015bc4(*puVar1,1);
  FUN_000175d2(5);
  FUN_00015bc4(puVar1[1],1);
  FUN_000175d2(5);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001117c(uint param_1,char *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  FUN_00012892();
  puVar1 = _DAT_000114a4;
  FUN_00015bc4(*_DAT_000114a4,0);
  uVar3 = 0;
  do {
    FUN_00015bc4(*puVar1,0);
    FUN_000175d2(5);
    FUN_00015bc4(puVar1[1],(int)(param_1 << 0x18) < 0);
    param_1 = (param_1 << 0x19) >> 0x18;
    FUN_00015bc4(*puVar1,1);
    FUN_000175d2(5);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  FUN_00015bc4(*puVar1,0);
  FUN_0001289c();
  FUN_000175d2(5);
  FUN_00015bc4(*puVar1,1);
  iVar4 = 500;
  do {
    iVar2 = FUN_00015bec(puVar1[1]);
    *param_2 = (char)iVar2;
    if (iVar2 == 0) break;
    FUN_000175d2(1);
    bVar5 = iVar4 != 0;
    iVar4 = iVar4 + -1;
  } while (bVar5);
  FUN_000175d2(5);
  FUN_00015bc4(*puVar1,0);
  FUN_00012892();
  FUN_000175d2(5);
  if (*param_2 != '\0') {
    *param_2 = '\f';
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011222(void)

{
  undefined4 *puVar1;
  
  puVar1 = _DAT_000114a4;
  FUN_00015bc4(_DAT_000114a4[1],1);
  FUN_00015bc4(*puVar1,1);
  FUN_000175d2(5);
  FUN_00015bc4(puVar1[1],0);
  FUN_000175d2(5);
  return;
}




uint FUN_0001124e(void)

{
  uint in_r3;
  byte bVar1;
  uint local_10;
  
  local_10 = in_r3;
  FUN_000110e0();
  bVar1 = 0;
  do {
    FUN_00011222();
    FUN_0001117c(0xe2,&local_10);
    FUN_00011150();
    if ((char)local_10 == '\0') break;
    FUN_0001eb00(10);
    FUN_0001cd4c(s_retry__d_000114cb + 1,bVar1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 3);
  FUN_0001cd4c(s__s_ret__d_000114dc,DAT_000114d8,(int)(char)local_10);
  return local_10 & 0xff;
}




void FUN_00011296(void)

{
  int iVar1;
  undefined uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = FUN_0001124e();
  iVar1 = DAT_000114e8;
  uVar3 = 0;
  do {
    iVar4 = iVar1 + uVar3;
    uVar3 = uVar3 + 1 & 0xff;
    *(undefined *)(iVar4 + 4) = uVar2;
  } while (uVar3 < 2);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000112ae(undefined *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = _DAT_000114a4;
  uVar4 = 0;
  FUN_00015bc4(*_DAT_000114a4,0);
  FUN_0001289c();
  uVar3 = 0;
  do {
    FUN_00015bc4(*puVar1,0);
    FUN_000175d2(5);
    FUN_00015bc4(*puVar1,1);
    uVar2 = FUN_00015bec(puVar1[1]);
    uVar2 = uVar2 | uVar4 << 1;
    uVar4 = uVar2 & 0xff;
    FUN_000175d2(5);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  *param_1 = (char)uVar2;
  FUN_00015bc4(*puVar1,0);
  FUN_00012892();
  FUN_00015bc4(puVar1[1],0);
  FUN_000175d2(5);
  FUN_00015bc4(*puVar1,1);
  FUN_000175d2(5);
  FUN_00015bc4(*puVar1,0);
  FUN_000175d2(5);
  return;
}




undefined * FUN_00011330(undefined *param_1,undefined *param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  
  if (((param_1 != (undefined *)0x0) && (param_2 != (undefined *)0x0)) && (param_3 != 0)) {
    puVar1 = param_1;
    if ((param_2 < param_1) && (puVar2 = param_2 + param_3, param_1 < puVar2)) {
      puVar1 = param_1 + param_3;
      while( true ) {
        puVar2 = puVar2 + -1;
        puVar1 = puVar1 + -1;
        bVar3 = param_3 == 0;
        param_3 = param_3 + -1;
        if (bVar3) break;
        *puVar1 = *puVar2;
      }
      return param_1;
    }
    while (bVar3 = param_3 != 0, param_3 = param_3 + -1, bVar3) {
      *puVar1 = *param_2;
      param_2 = param_2 + 1;
      puVar1 = puVar1 + 1;
    }
    return param_1;
  }
  return (undefined *)0x0;
}




void FUN_00011372(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined *param_6)

{
  int iVar1;
  undefined auStack_44 [32];
  undefined4 local_24;
  undefined4 uStack_20;
  
  local_24 = DAT_000114ec;
  uStack_20 = DAT_000114f0;
  iVar1 = 8 - (param_2 & 7);
  if (iVar1 != 0) {
    FUN_00011330(param_5,param_1,param_2);
    FUN_00011330(param_5 + param_2,&local_24,iVar1);
  }
  *param_6 = (char)(param_2 + iVar1);
  FUN_00010d92(auStack_44,param_5,param_2 + iVar1 & 0xff,param_3,param_4);
  FUN_00011330(param_5,auStack_44,*param_6);
  return;
}




void FUN_000113ce(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined2 *param_6)

{
  bool bVar1;
  char acStack_34 [36];
  
  if (param_2 == 0) {
    *param_6 = 0;
  }
  else {
    FUN_00010e36(acStack_34,param_1,param_2,param_3,0x10);
    do {
      bVar1 = param_2 == 0;
      param_2 = param_2 - 1 & 0xff;
      if (bVar1) break;
    } while (acStack_34[param_2] != -0x80);
    FUN_00011330(param_5,acStack_34,param_2);
    *param_6 = (short)param_2;
  }
  return;
}




undefined4 FUN_00011410(int param_1)

{
  if (param_1 == 0xc) {
    return 0xffe2;
  }
  if (param_1 < 0xd) {
    if (param_1 == 1) {
      return 0xffe6;
    }
    if (param_1 == 2) {
      return 0xffe7;
    }
    if (param_1 == 0xb) {
      return 0xffe1;
    }
  }
  else {
    if (param_1 == 0xd) {
      return 0xffe3;
    }
    if (param_1 == 0xe) {
      return 0xffe4;
    }
  }
  return 0xffe5;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00011456(undefined param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined4 local_20;
  uint local_1c;
  
  local_20 = CONCAT13(param_1,(uint3)(ushort)((short)param_3 + 3));
  local_1c = param_4;
  FUN_0001b018(_DAT_000114c8,0xffffffff);
  FUN_00011222();
  FUN_0001117c(0xe2,&local_1c);
  if ((char)local_1c == '\0') {
    iVar1 = 0;
    do {
      FUN_0001117c(*(undefined *)((int)&local_20 + iVar1),&local_1c);
      if ((char)local_1c != '\0') goto LAB_0001154a;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
    bVar3 = (byte)local_20 ^ local_20._1_1_ ^ local_20._2_1_ ^ local_20._3_1_;
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
      FUN_0001117c(*(undefined *)(param_2 + uVar2),&local_1c);
      bVar3 = bVar3 ^ *(byte *)(param_2 + uVar2);
      if ((char)local_1c != '\0') goto LAB_0001154a;
    }
    FUN_0001117c(bVar3,&local_1c);
    FUN_00011150();
  }
LAB_0001154a:
  FUN_0001b02a(DAT_00011934);
  FUN_0001eb00(5);
  return local_1c & 0xff;
}




uint FUN_0001155e(int param_1,ushort *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_20;
  uint local_1c;
  
  *param_2 = 0;
  local_20 = param_3;
  local_1c = param_4;
  FUN_0001b018(DAT_00011934,0xffffffff);
  FUN_00011222();
  FUN_0001117c(0xe3,&local_1c);
  if ((local_1c & 0xff) == 0) {
    FUN_000112ae(&local_20);
    FUN_000112ae((int)&local_20 + 1);
    uVar1 = ((local_20 & 0xff) + (local_20 >> 8 & 0xff) * 0x100 & 0xffff) - 3;
    if (uVar1 < 0x1e) {
      FUN_000112ae((int)&local_20 + 2);
      FUN_000112ae((int)&local_20 + 3);
      *param_2 = (ushort)uVar1;
      uVar2 = (uint)(byte)((byte)local_20 ^ local_20._1_1_ ^ local_20._2_1_ ^ local_20._3_1_);
      for (uVar1 = 0; uVar1 < *param_2; uVar1 = uVar1 + 1 & 0xffff) {
        FUN_000112ae(param_1 + uVar1);
        uVar2 = uVar2 ^ *(byte *)(param_1 + uVar1);
      }
      uVar1 = FUN_000128a6();
      FUN_00011150();
      FUN_0001b02a(DAT_00011934);
      if (uVar1 == uVar2) {
        FUN_0001eb00(5);
        local_1c = local_20 >> 0x18;
      }
      else {
        *param_2 = 0;
        local_1c = 0xe;
      }
    }
    else {
      *param_2 = 0;
      FUN_0001b02a(DAT_00011934);
      local_1c = 0xd;
    }
  }
  else {
    FUN_00011150();
    FUN_0001b02a(DAT_00011934);
    local_1c = local_1c & 0xff;
  }
  return local_1c;
}




int FUN_0001162a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
                int param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  
  *param_4 = 0;
  iVar1 = FUN_00011456(2,param_1,param_2);
  if (iVar1 == 0) {
    for (uVar2 = 0; uVar2 < param_6; uVar2 = uVar2 + 1) {
      iVar1 = FUN_0001155e(param_3,param_4);
      if (iVar1 == 0xc) {
        FUN_0001eb00(param_5);
        uVar2 = uVar2 + param_5;
        FUN_0001eb00(1);
      }
      else if (iVar1 != 4) {
        return iVar1;
      }
    }
  }
  return iVar1;
}




int FUN_0001167a(undefined4 param_1,undefined2 *param_2)

{
  undefined uVar1;
  uint uVar2;
  int iVar3;
  undefined auStack_74 [8];
  undefined auStack_6c [28];
  undefined local_50 [16];
  undefined auStack_40 [20];
  undefined auStack_2c [8];
  undefined auStack_24 [8];
  undefined auStack_1c [4];
  
  iVar3 = DAT_00011938;
  *param_2 = 0;
  FUN_000235c4(*(undefined4 *)(iVar3 + 8));
  uVar2 = *(uint *)(iVar3 + 8);
  *(uint *)(iVar3 + 8) = uVar2 + 1;
  if (0x7fffffff < uVar2) {
    *(undefined4 *)(iVar3 + 8) = 0;
  }
  uVar2 = 0;
  do {
    uVar1 = FUN_00000274();
    local_50[uVar2] = uVar1;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x10);
  FUN_000110c8(local_50);
  iVar3 = FUN_00012924(0x10,local_50,auStack_74,auStack_1c);
  if (iVar3 == 0x9000) {
    FUN_0000a5fc(auStack_40);
    FUN_00010e36(param_1,auStack_74,8,auStack_40,0x10);
    iVar3 = FUN_00023614(param_1,local_50 + 8,8);
    if (iVar3 == 0) {
      FUN_00011330(auStack_2c,auStack_74,8);
      FUN_00010d92(auStack_24,auStack_6c,8,auStack_40,0x10);
      iVar3 = FUN_00012984(8,auStack_24,auStack_74,auStack_1c);
      if (iVar3 == 0x9000) {
        FUN_00010d92(param_1,auStack_2c,0x10,auStack_40,0x10);
        *param_2 = 0x10;
      }
    }
    else {
      iVar3 = 0xffce;
    }
  }
  return iVar3;
}




uint FUN_00011736(undefined4 param_1,undefined param_2,undefined2 *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined *puVar3;
  undefined uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  
  puVar3 = DAT_0001193c;
  *DAT_0001193c = 0x80;
  puVar3[1] = 0x77;
  puVar3[2] = (char)((uint)param_1 >> 8);
  puVar3[3] = (char)param_1;
  puVar3[4] = 1;
  puVar3[5] = param_2;
  FUN_00011372(puVar3 + 5,1,puVar3 + 0x145,0x10,puVar3 + 5,puVar3 + 4);
  iVar5 = FUN_0001162a(puVar3,(byte)puVar3[4] + 5,puVar3 + 0x105,DAT_00011938 + 4,1,100);
  iVar2 = DAT_00011938;
  if (iVar5 == 0) {
    uVar1 = *(ushort *)(DAT_00011934 + (uint)*(ushort *)(DAT_00011938 + 4) + -0x55);
    uVar6 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar6 = FUN_00011410();
  }
  puVar3 = DAT_0001193c;
  if (uVar6 == 0x9000) {
    puVar7 = (undefined2 *)(DAT_0001193c + -0x40);
    FUN_000113ce(DAT_0001193c + 0x105,*(char *)(iVar2 + 4) + -2,DAT_0001193c + 0x145,0x10,puVar7,
                 DAT_00011938 + 2);
    if (param_3 != (undefined2 *)0x0) {
      if (((*(char *)puVar7 == '\x04') && (puVar3[-0x3f] == '\0')) && (puVar3[-0x3a] == '\b')) {
        FUN_00011088(4,puVar3 + -0x3e);
        *param_3 = *puVar7;
        *(undefined4 *)(param_3 + 1) = *(undefined4 *)(puVar3 + -0x3e);
        *(undefined *)(param_3 + 7) = puVar3[-0x3a];
        uVar4 = 4;
      }
      else {
        FUN_00011088(7,puVar3 + -0x3e);
        *param_3 = *puVar7;
        *(undefined4 *)(param_3 + 1) = *(undefined4 *)(puVar3 + -0x3e);
        param_3[3] = *(undefined2 *)(puVar3 + -0x3a);
        *(undefined *)(param_3 + 4) = puVar3[-0x38];
        *(undefined *)(param_3 + 7) = puVar3[-0x37];
        uVar4 = 7;
      }
      *(undefined *)((int)param_3 + 0xf) = uVar4;
    }
  }
  return uVar6;
}




uint FUN_0001181a(undefined4 param_1,undefined4 param_2,undefined param_3)

{
  ushort uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = DAT_0001193c;
  *DAT_0001193c = 0x80;
  puVar3[1] = 0x75;
  puVar3[2] = (char)((uint)param_2 >> 8);
  puVar3[3] = (char)param_2;
  puVar3[4] = 1;
  puVar3[5] = param_3;
  FUN_00011372(puVar3 + 5,1,puVar3 + 0x145,0x10,puVar3 + 5,puVar3 + 4);
  iVar4 = FUN_0001162a(puVar3,(byte)puVar3[4] + 5,puVar3 + 0x105,DAT_00011938 + 4,1,2000);
  iVar2 = DAT_00011938;
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(DAT_00011934 + (uint)*(ushort *)(DAT_00011938 + 4) + -0x55);
    uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar5 = FUN_00011410();
  }
  if (uVar5 == 0x9000) {
    FUN_000113ce(DAT_00011934 + -0x53,*(char *)(iVar2 + 4) + -2,DAT_00011934 + -0x13,0x10,
                 DAT_0001193c + -0x40,DAT_00011938 + 2);
  }
  return uVar5;
}




uint FUN_000118a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = DAT_0001193c;
  *DAT_0001193c = 0x80;
  puVar1[1] = 0x7f;
  puVar1[2] = (char)((uint)param_1 >> 8);
  puVar1[3] = (char)param_1;
  puVar1[4] = (char)param_2;
  FUN_00011330(puVar1 + 5,param_3,param_2,param_3,param_3,param_4);
  FUN_00011372(puVar1 + 5,puVar1[4],puVar1 + 0x145,0x10,puVar1 + 5,puVar1 + 4);
  uVar4 = 1;
  uVar5 = 2000;
  uVar3 = FUN_0001162a(puVar1,(byte)puVar1[4] + 5,puVar1 + -0x40,DAT_00011938 + 2);
  if ((int)uVar3 != 0) {
    uVar2 = FUN_00011410((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar4,uVar5);
    return uVar2;
  }
  return (*(ushort *)(DAT_0001193c + (*(ushort *)(DAT_00011938 + 2) - 0x42)) & 0xff) << 8 |
         (uint)(*(ushort *)(DAT_0001193c + (*(ushort *)(DAT_00011938 + 2) - 0x42)) >> 8);
}




uint FUN_00011914(int param_1,undefined param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = DAT_00011d24;
  if (param_1 << 0x18 < 0) {
    *DAT_00011d24 = 0x80;
    puVar2[1] = 0x75;
    puVar2[2] = (char)((uint)param_1 >> 8);
    puVar2[3] = (char)param_1;
    puVar2[4] = 8;
    FUN_00011330(puVar2 + 5,param_5,7,param_4,param_3,param_4);
    puVar2[0xc] = param_2;
    FUN_00011372(puVar2 + 5,puVar2[4],puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
    iVar5 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,puVar2 + 0x105,DAT_00011d28,1,2000);
    puVar3 = DAT_00011d28;
    if (iVar5 == 0) {
      uVar1 = *(ushort *)(DAT_00011d2c + (uint)*DAT_00011d28 + -2);
      uVar4 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
    }
    else {
      uVar4 = FUN_00011410();
    }
    if (uVar4 == 0x9000) {
      FUN_000113ce(DAT_00011d2c,*(char *)puVar3 + -2,DAT_00011d2c + 0x40,0x10,param_3,param_4);
    }
  }
  else {
    uVar4 = 0xffe8;
  }
  return uVar4;
}




uint FUN_000119c8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined param_5)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_00011d24;
  if (((int)(param_1 << 0x18) < 0) && (param_1 >> 8 != 0)) {
    *DAT_00011d24 = 0x80;
    puVar2[1] = 0x79;
    puVar2[2] = (char)(param_1 >> 8);
    puVar2[3] = (char)param_1;
    puVar2[4] = 8;
    puVar2[0xc] = param_5;
    FUN_00011330(puVar2 + 5,param_4,7,param_4,param_3,param_4);
    FUN_00011372(puVar2 + 5,puVar2[4],puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
    iVar4 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,DAT_00011d2c,DAT_00011d28,1,2000);
    puVar3 = DAT_00011d28;
    if (iVar4 == 0) {
      uVar1 = *(ushort *)(DAT_00011d2c + (uint)*DAT_00011d28 + -2);
      uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
    }
    else {
      uVar5 = FUN_00011410();
    }
    if (uVar5 == 0x9000) {
      FUN_000113ce(DAT_00011d2c,*(char *)puVar3 + -2,DAT_00011d2c + 0x40,0x10,param_2,param_3);
    }
  }
  else {
    uVar5 = 0xffe8;
  }
  return uVar5;
}




uint FUN_00011a6a(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  ushort uVar1;
  char cVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar3 = DAT_00011d24;
  if (((int)(param_1 << 0x18) < 0) && (param_1 >> 8 != 0)) {
    *DAT_00011d24 = 0x80;
    puVar3[1] = 0x7f;
    puVar3[2] = (char)(param_1 >> 8);
    puVar3[3] = (char)param_1;
    cVar2 = (char)param_2;
    puVar3[4] = cVar2;
    if (param_7 == 0) {
      puVar3[4] = cVar2 + '\a';
    }
    else {
      puVar3[4] = cVar2 + '\b';
      puVar3[param_2 + 0xc] = (char)param_7;
    }
    FUN_00011330(puVar3 + 5,param_3,param_2,param_3,param_3,param_4);
    FUN_00011330(puVar3 + param_2 + 5,param_6,7);
    FUN_00011372(puVar3 + 5,puVar3[4],DAT_00011d24 + 0x145,0x10,DAT_00011d24 + 5,DAT_00011d24 + 4);
    uVar6 = 1;
    uVar7 = 2000;
    uVar5 = FUN_0001162a(DAT_00011d24,(byte)puVar3[4] + 5,DAT_00011d2c,DAT_00011d28);
    if ((int)uVar5 != 0) {
      uVar4 = FUN_00011410((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),uVar6,uVar7);
      return uVar4;
    }
    uVar1 = *(ushort *)(DAT_00011d2c + (uint)*DAT_00011d28 + -2);
    uVar4 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar4 = 0xffe8;
  }
  return uVar4;
}




uint FUN_00011b06(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  
  puVar2 = DAT_00011d24;
  *DAT_00011d24 = 0;
  puVar2[1] = 0xa4;
  puVar2[2] = 4;
  puVar2[3] = 0;
  puVar5 = DAT_00011d30;
  puVar2[4] = 0xc;
  *(undefined4 *)(puVar2 + 5) = *puVar5;
  *(undefined4 *)(puVar2 + 9) = puVar5[1];
  *(undefined4 *)(puVar2 + 0xd) = puVar5[2];
  iVar6 = FUN_0001162a(puVar2,0x11,DAT_00011d2c,DAT_00011d28,1,2000);
  iVar4 = DAT_00011d2c;
  puVar3 = DAT_00011d28;
  if (iVar6 == 0) {
    uVar1 = *(ushort *)((uint)*DAT_00011d28 + DAT_00011d2c + -2);
    uVar7 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar7 = FUN_00011410();
  }
  if (uVar7 == 0x9000) {
    *puVar2 = 0x80;
    puVar2[1] = 0xca;
    puVar2[2] = 0;
    puVar2[3] = 0xf1;
    puVar2[4] = 10;
    iVar6 = FUN_0001162a(DAT_00011d24,5,DAT_00011d2c,DAT_00011d28,1,2000);
    if (iVar6 == 0) {
      uVar1 = *(ushort *)((uint)*puVar3 + iVar4 + -2);
      uVar7 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
    }
    else {
      uVar7 = FUN_00011410();
    }
    iVar6 = DAT_00011d2c;
    if (uVar7 == 0x9000) {
      uVar1 = *puVar3;
      *param_2 = uVar1;
      FUN_000237a0(param_1,iVar6,uVar1 - 2);
      *puVar2 = 0;
      puVar2[1] = 0xa4;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      iVar6 = FUN_0001162a(DAT_00011d24,5,DAT_00011d2c,DAT_00011d28,1,2000);
      if (iVar6 != 0) {
        uVar7 = FUN_00011410();
        return uVar7;
      }
      uVar1 = *(ushort *)((uint)*puVar3 + iVar4 + -2);
      uVar7 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
    }
  }
  return uVar7;
}




uint FUN_00011c14(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_00011d24;
  *DAT_00011d24 = 0x80;
  puVar2[1] = 0x85;
  puVar2[2] = (char)((uint)param_1 >> 8);
  puVar2[3] = (char)param_1;
  puVar2[4] = 7;
  puVar2[0xb] = (char)param_4;
  FUN_00011330(puVar2 + 5,param_5,6,param_4,param_3,param_4);
  FUN_00011372(puVar2 + 5,puVar2[4],puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
  iVar4 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,DAT_00011d2c,DAT_00011d28,1,2000);
  puVar3 = DAT_00011d28;
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(DAT_00011d2c + (uint)*DAT_00011d28 + -2);
    uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar5 = FUN_00011410();
  }
  if (uVar5 == 0x9000) {
    FUN_000113ce(DAT_00011d2c,*(char *)puVar3 + -2,DAT_00011d2c + 0x40,0x10,param_2,param_3);
  }
  return uVar5;
}




uint FUN_00011ca8(undefined param_1,undefined param_2,int param_3,undefined4 param_4,
                 undefined param_5,undefined param_6,undefined4 param_7,undefined4 param_8)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_00011d24;
  *DAT_00011d24 = 0x80;
  puVar2[1] = 0x70;
  puVar2[2] = param_1;
  puVar2[3] = param_2;
  puVar2[4] = (char)param_3 + '\x02';
  FUN_00011330(puVar2 + 5,param_4,param_3,param_4,param_3,param_4);
  puVar2[param_3 + 5] = param_5;
  puVar2[param_3 + 6] = param_6;
  FUN_00011372(puVar2 + 5,puVar2[4],puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
  iVar4 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,DAT_00011d2c,DAT_00011d28,1,2000);
  puVar3 = DAT_00011d28;
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(DAT_0001211c + (uint)*DAT_00011d28 + -2);
    uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar5 = FUN_00011410();
  }
  if (uVar5 == 0x9000) {
    FUN_000113ce(DAT_0001211c,*(char *)puVar3 + -2,DAT_0001211c + 0x40,0x10,param_7,param_8);
  }
  return uVar5;
}




uint FUN_00011d5a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_00012120;
  *DAT_00012120 = 0x80;
  puVar2[1] = 0x85;
  puVar2[2] = (char)((uint)param_1 >> 8);
  puVar2[3] = (char)param_1;
  puVar2[4] = 0xb;
  puVar2[0xf] = (char)param_4;
  FUN_00011330(puVar2 + 5,param_5,6,param_4,param_3,param_4);
  FUN_00011330(puVar2 + 0xb,param_6,4);
  FUN_00011372(puVar2 + 5,puVar2[4],puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
  iVar4 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,DAT_0001211c,DAT_00012124,1,2000);
  puVar3 = DAT_00012124;
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(DAT_0001211c + (uint)*DAT_00012124 + -2);
    uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar5 = FUN_00011410();
  }
  if (uVar5 == 0x9000) {
    FUN_000113ce(DAT_0001211c,*(char *)puVar3 + -2,DAT_0001211c + 0x40,0x10,param_2,param_3);
  }
  return uVar5;
}




uint FUN_00011dfc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_00012120;
  *DAT_00012120 = 0x80;
  puVar2[1] = 0x79;
  puVar2[2] = (char)((uint)param_1 >> 8);
  puVar2[3] = (char)param_1;
  puVar2[4] = 0;
  FUN_00011372(puVar2 + 5,0,puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
  iVar4 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,DAT_0001211c,DAT_00012124,1,2000);
  puVar3 = DAT_00012124;
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(DAT_0001211c + (uint)*DAT_00012124 + -2);
    uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar5 = FUN_00011410();
  }
  if (uVar5 == 0x9000) {
    FUN_000113ce(DAT_0001211c,*(char *)puVar3 + -2,DAT_0001211c + 0x40,0x10,param_2,param_3);
  }
  return uVar5;
}




uint FUN_00011e80(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_00012120;
  *DAT_00012120 = 0x80;
  puVar2[1] = 0x7b;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  FUN_00011372(puVar2 + 5,0,puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
  iVar4 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,DAT_0001211c,DAT_00012124,1,2000);
  puVar3 = DAT_00012124;
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(DAT_0001211c + (uint)*DAT_00012124 + -2);
    uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar5 = FUN_00011410();
  }
  if (uVar5 == 0x9000) {
    FUN_000113ce(DAT_0001211c,*(char *)puVar3 + -2,DAT_0001211c + 0x40,0x10,param_1,param_2);
  }
  return uVar5;
}




uint FUN_00011f04(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = DAT_00012120;
  *DAT_00012120 = 0x80;
  puVar2[1] = 0x7d;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = (char)param_1;
  FUN_00011330(puVar2 + 5,param_2,param_1,param_4,param_3,param_4);
  FUN_00011372(puVar2 + 5,puVar2[4],puVar2 + 0x145,0x10,puVar2 + 5,puVar2 + 4);
  iVar4 = FUN_0001162a(puVar2,(byte)puVar2[4] + 5,DAT_0001211c,DAT_00012124,1,2000);
  puVar3 = DAT_00012124;
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(DAT_0001211c + (uint)*DAT_00012124 + -2);
    uVar5 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
  }
  else {
    uVar5 = FUN_00011410();
  }
  if (uVar5 == 0x9000) {
    FUN_000113ce(DAT_0001211c,*(char *)puVar3 + -2,DAT_0001211c + 0x40,0x10,param_3,param_4);
  }
  return uVar5;
}




int FUN_00011f90(void)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined auStack_40 [32];
  undefined auStack_20 [8];
  
  iVar4 = DAT_00012120 + -0x40;
  iVar3 = DAT_00012124 + -2;
  iVar1 = FUN_00011456(0x30,0);
  if (iVar1 == 0) {
    uVar2 = 0;
    do {
      iVar1 = FUN_0001155e(iVar4,iVar3);
      if (iVar1 == 0) {
        iVar1 = FUN_00011b06(auStack_40,auStack_20);
        if (iVar1 != 0x9000) {
          FUN_0001cd4c(&DAT_00012128);
          FUN_0001cd4c(s_get_chip_ver_sw_failed_sw__x__00012160,iVar1);
          FUN_0001cd4c(&DAT_00012158);
          return 2;
        }
        iVar1 = FUN_0001167a(DAT_00012120 + -0x40,DAT_00012124 + -2);
        if (iVar1 != 0x9000) {
          return 0xfb;
        }
        if (*(short *)(DAT_00012124 + -2) != 0x10) {
          return 3;
        }
        FUN_000237a0(DAT_00012120 + 0x145,DAT_00012120 + -0x40,0x10);
        iVar1 = FUN_00011ca8(0,0,0xf,DAT_00012124 + 0x10,0x28,0,auStack_40,auStack_20);
        if (iVar1 != 0x9000) {
          FUN_0001cd4c(&DAT_00012128);
          FUN_0001cd4c(s_set_tag_reader_0x_x_error_ret_____00012180,0x28,iVar1);
          FUN_0001cd4c(&DAT_00012158);
        }
        iVar1 = FUN_00011ca8(0,0,0xf,DAT_00012124 + 0x10,0x29,0,auStack_40,auStack_20);
        if (iVar1 != 0x9000) {
          FUN_0001cd4c(&DAT_00012128);
          FUN_0001cd4c(s_set_tag_reader_0x_x_error_ret_____00012180,0x29,iVar1);
          FUN_0001cd4c(&DAT_00012158);
        }
        return 0;
      }
      FUN_0001eb00(1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2000);
  }
  FUN_0001cd4c(&DAT_00012128);
  FUN_0001cd4c(s_rfid_mcu_power_on_failed__d__00012138,iVar1);
  FUN_0001cd4c(&DAT_00012158);
  return iVar1;
}




void FUN_000120bc(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  if ((param_1 == 0x6985) || (param_1 == 0x6a88)) {
    FUN_0001cd4c(&DAT_00012128);
    FUN_0001cd4c(s__s_sw__x_error___000121a8,DAT_000121a4,param_1);
    FUN_0001cd4c(&DAT_00012158);
    puVar1 = DAT_000121bc;
    puVar3 = (undefined *)(DAT_00012124 + -4);
    *puVar3 = 0;
    *puVar1 = 0;
    FUN_00011296();
    iVar2 = FUN_00011f90();
    if (iVar2 == 0) {
      *puVar3 = 1;
    }
  }
  return;
}




undefined4 FUN_00012104(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  uVar3 = 1;
  pcVar4 = (char *)(DAT_00012124 + -4);
  uVar1 = *param_1;
  if (*pcVar4 == '\0') {
    FUN_0001cd4c(&DAT_00012598);
    FUN_0001cd4c(s__s_re_auth_000125ac,DAT_000125a8);
    FUN_0001cd4c(&DAT_00012158);
    iVar2 = FUN_00011f90();
    if (iVar2 == 0) {
      *pcVar4 = '\x01';
    }
  }
  iVar2 = FUN_00011736(0xff00,(char)uVar1,param_1 + 0x1e);
  if (iVar2 == 0x9000) {
    uVar3 = 0;
  }
  else if (iVar2 == 0x9ef5) {
    uVar3 = 2;
  }
  else {
    FUN_000120bc();
  }
  return uVar3;
}




undefined4 FUN_0001220a(ushort *param_1)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  char cVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  byte local_58 [24];
  undefined4 local_40;
  undefined4 local_3c;
  undefined auStack_30 [4];
  undefined auStack_2c [8];
  
  uVar1 = *param_1;
  puVar8 = param_1 + 10;
  uVar10 = 0;
  if (((param_1 + 0x1e == (ushort *)0x0) || (puVar8 == (ushort *)0x0)) ||
     ((int *)(param_1 + 2) == (int *)0x0)) {
    FUN_0001cd4c(&DAT_00012128);
    FUN_0001cd4c(s_The_dev_has_not_been_initialized_000125b8);
    FUN_0001cd4c(&DAT_00012158);
LAB_000122b6:
    uVar4 = 1;
  }
  else {
    if (((*(char *)(param_1 + 0x1e) == '\x04') && (*(char *)((int)param_1 + 0x3d) == '\0')) &&
       (*(char *)(param_1 + 0x25) == '\b')) {
      FUN_00022d7e(param_1 + 0x1f,auStack_2c);
      puVar7 = param_1 + 0x1f;
      iVar3 = FUN_00011d5a(0xff84,local_58,auStack_30,uVar1 & 0xff,auStack_2c,puVar7);
      if (iVar3 != 0x9000) {
        FUN_000120bc();
        goto LAB_000122b6;
      }
      FUN_00022e0e(local_58,&local_40);
      FUN_000237a0(puVar8,&local_40,0x10);
      iVar3 = FUN_00011d5a(0xff85,local_58,auStack_30,uVar1 & 0xff,auStack_2c,puVar7);
      if (iVar3 != 0x9000) {
        FUN_000120bc();
        return 2;
      }
      FUN_00022e0e(local_58,&local_40);
      FUN_000237a0(param_1 + 0x12,&local_40,0x10);
      iVar3 = FUN_00011d5a(0xff86,local_58,auStack_30,uVar1 & 0xff,auStack_2c,puVar7);
      if (iVar3 == 0x9000) {
        FUN_00022e0e(local_58,&local_40);
        *(undefined4 *)(param_1 + 0x1a) = local_40;
        *(undefined4 *)(param_1 + 0x1c) = local_3c;
        return 0;
      }
      FUN_000120bc();
    }
    else {
      uVar9 = 0;
      do {
        iVar3 = FUN_000119c8(uVar9 | 0xff80,local_58 + uVar10,auStack_30,param_1 + 0x1f,uVar1 & 0xff
                            );
        if (iVar3 != 0x9000) {
          FUN_000120bc();
          return 0x10;
        }
        uVar9 = uVar9 + 1 & 0xff;
        uVar10 = uVar10 + 4 & 0xffff;
      } while (uVar9 < 5);
      uVar10 = 0;
      do {
        bVar2 = local_58[uVar10] >> 4;
        bVar5 = local_58[uVar10] & 0xf;
        if (bVar2 < 10) {
          cVar6 = '0';
        }
        else {
          cVar6 = '7';
        }
        *(byte *)(puVar8 + uVar10) = bVar2 + cVar6;
        if (bVar5 < 10) {
          cVar6 = bVar5 + 0x30;
        }
        else {
          cVar6 = bVar5 + 0x37;
        }
        iVar3 = uVar10 * 2;
        uVar10 = uVar10 + 1 & 0xff;
        *(char *)((int)puVar8 + iVar3 + 1) = cVar6;
      } while (uVar10 < 0x14);
      iVar3 = FUN_00011914(0xff81,uVar1 & 0xff,local_58,auStack_30,param_1 + 0x1f);
      if (iVar3 != 0x9000) {
        FUN_000120bc();
        return 6;
      }
      iVar3 = FUN_00011dfc(0x10,local_58,auStack_30);
      if (iVar3 == 0x9000) {
        FUN_00011088(4,local_58);
        *(uint *)(param_1 + 2) =
             ((local_58[3] & 0xf) +
             DAT_000125dc * (uint)(local_58[0] >> 4) + (short)(local_58[0] & 0xf) * 1000000 +
             (short)(ushort)(local_58[1] >> 4) * 100000 + (short)(local_58[1] & 0xf) * 10000 +
             (uint)(local_58[2] >> 4) * 1000 + (local_58[2] & 0xf) * 100 +
             (uint)(local_58[3] >> 4) * 10) * 1000;
        iVar3 = FUN_00011dfc(0x11,local_58,auStack_30);
        if (iVar3 == 0x9000) {
          *(uint *)(param_1 + 4) =
               (local_58[3] & 0xf) +
               DAT_000125dc * (uint)(local_58[0] >> 4) + (short)(local_58[0] & 0xf) * 1000000 +
               (short)(ushort)(local_58[1] >> 4) * 100000 + (short)(local_58[1] & 0xf) * 10000 +
               (uint)(local_58[2] >> 4) * 1000 + (local_58[2] & 0xf) * 100 +
               (uint)(local_58[3] >> 4) * 10;
          iVar3 = FUN_00011dfc(0x12,local_58,auStack_30);
          if (iVar3 == 0x9000) {
            FUN_00011088(4,local_58);
            *(uint *)(param_1 + 6) =
                 (local_58[3] & 0xf) +
                 DAT_000125dc * (uint)(local_58[0] >> 4) + (short)(local_58[0] & 0xf) * 1000000 +
                 (short)(ushort)(local_58[1] >> 4) * 100000 + (short)(local_58[1] & 0xf) * 10000 +
                 (uint)(local_58[2] >> 4) * 1000 + (local_58[2] & 0xf) * 100 +
                 (uint)(local_58[3] >> 4) * 10;
            iVar3 = FUN_00011e80(local_58,auStack_30);
            if (iVar3 == 0x9000) {
              FUN_00011088(4,local_58);
              *(uint *)(param_1 + 8) =
                   (uint)local_58[3] + (uint)local_58[0] * 0x1000000 +
                   (uint)local_58[1] * 0x10000 + (uint)local_58[2] * 0x100;
              return 0;
            }
          }
        }
      }
    }
    uVar4 = 3;
  }
  return uVar4;
}




undefined4 FUN_00012570(undefined *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_2c;
  char local_2b;
  char local_2a;
  char local_29;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d;
  short local_14 [2];
  short local_10 [4];
  
  iVar1 = FUN_00011914(0xff81,*param_1,&local_20,local_14,param_1 + 0x3e);
  if (iVar1 == 0x9000) {
    iVar1 = FUN_00011e80(&local_2c,local_10);
    if (iVar1 == 0x9000) {
      if (local_10[0] == 4) {
        if ((((local_2c != '\0') || (local_2b != '\0')) || (local_2a != '\0')) || (local_29 != '\0')
           ) {
          iVar1 = FUN_00011f04(4,&local_2c,&local_20,local_14);
          if (iVar1 != 0x9000) {
            return 0x22;
          }
          if (local_14[0] != 4) {
            return 0x23;
          }
          if (((local_20 != '\0') || (local_1f != '\0')) ||
             ((local_1e != '\0' || (local_1d != '\0')))) {
            return 0x24;
          }
        }
        uVar2 = 0;
      }
      else {
        uVar2 = 0x13;
      }
    }
    else {
      uVar2 = 0x12;
    }
  }
  else {
    uVar2 = 0x11;
  }
  return uVar2;
}




undefined4 FUN_00012652(undefined *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_1c;
  char local_1b;
  char local_1a;
  char local_19;
  short local_10 [2];
  
  iVar1 = FUN_00011914(0xff81,*param_1,&local_1c,local_10,param_1 + 0x3e);
  if (iVar1 == 0x9000) {
    iVar1 = FUN_00011e80(&local_1c,local_10);
    FUN_0001cd4c(s_www_get_tag_life_count_0x_x_000129e4,iVar1);
    if (iVar1 == 0x9000) {
      if (local_10[0] == 4) {
        if ((((local_1c == '\0') && (local_1b == '\0')) && (local_1a == '\0')) && (local_19 == '\0')
           ) {
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x13;
      }
    }
    else {
      uVar2 = 0x12;
    }
  }
  else {
    uVar2 = 0x11;
  }
  return uVar2;
}




void FUN_000126c0(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = 0;
  local_14 = 0;
  local_10 = 0;
  do {
    uVar3 = param_2 / 10;
    cVar1 = (char)param_2;
    param_2 = param_2 / 10;
    *(char *)((int)&local_14 + iVar2) = cVar1 + (char)uVar3 * -10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  *param_1 = local_10._2_1_ + local_10._3_1_ * '\x10';
  param_1[1] = (char)local_10 + local_10._1_1_ * '\x10';
  param_1[2] = local_14._2_1_ + local_14._3_1_ * '\x10';
  param_1[3] = (char)local_14 + local_14._1_1_ * '\x10';
  return;
}




undefined4 FUN_0001271a(undefined *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char local_44;
  char local_43;
  char local_42;
  char local_41;
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  ushort local_2c [2];
  short local_28 [4];
  
  iVar1 = FUN_00011914(0xff81,*param_1,&local_38,local_28,param_1 + 0x3e);
  if (iVar1 != 0x9000) {
    FUN_000120bc();
    return 6;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    return 5;
  }
  uVar2 = (uint)(iVar1 * 0x67) / 100;
  if (param_2 < uVar2) {
    uVar2 = ((uVar2 - param_2) * 100) / uVar2;
  }
  else {
    uVar2 = 0;
  }
  if (*(uint *)(param_1 + 0xc) == param_2) {
LAB_0001279e:
    if (*(uint *)(param_1 + 8) != uVar2) {
      FUN_000126c0(&local_44,uVar2);
      uVar3 = FUN_000118a8(0x11,4,&local_44);
      if (uVar3 != 0x9000) {
        FUN_0001cd4c(&DAT_00012598);
        pcVar4 = s_write_unused_sw__x_00012a18;
        goto LAB_000127c8;
      }
      *(uint *)(param_1 + 8) = uVar2;
    }
    if ((param_2 <= (uint)(iVar1 * 0x6e) / 100) || (*(int *)(param_1 + 0x10) == 0)) {
      return 0;
    }
    uVar3 = FUN_00011e80(&local_44,local_2c);
    if (uVar3 == 0x9000) {
      if (local_2c[0] == 4) {
        if ((((local_44 == '\0') && (local_43 == '\0')) && (local_42 == '\0')) && (local_41 == '\0')
           ) {
          return 0;
        }
        uVar3 = FUN_00011f04(4,&local_44,&local_38,local_28);
        if (uVar3 != 0x9000) {
          FUN_0001cd4c(&DAT_00012598);
          pcVar4 = s_dec_life_sw__x_00012a3c;
          goto LAB_000127c8;
        }
        if (local_28[0] == 4) {
          if (((local_38 == '\0') && (local_37 == '\0')) &&
             ((local_36 == '\0' && (local_35 == '\0')))) {
            *(undefined4 *)(param_1 + 0x10) = 0;
            return 0;
          }
          FUN_0001cd4c(&DAT_00012128);
          FUN_0001cd4c(s_get_life_error_count_Non_zero_00012a64);
          goto LAB_0001287e;
        }
      }
      FUN_0001cd4c(&DAT_00012128);
      uVar3 = (uint)local_2c[0];
      pcVar4 = s_get_life_error_dlen__d_00012a4c;
    }
    else {
      FUN_0001cd4c(&DAT_00012598);
      pcVar4 = s_get_life_sw__x_00012a2c;
    }
  }
  else {
    FUN_000126c0(&local_44,param_2);
    uVar3 = FUN_000118a8(0x12,4,&local_44);
    if (uVar3 == 0x9000) {
      *(uint *)(param_1 + 0xc) = param_2;
      goto LAB_0001279e;
    }
    FUN_0001cd4c(&DAT_00012598);
    pcVar4 = s_write_used_sw__x_00012a04;
  }
LAB_000127c8:
  FUN_0001cd4c(pcVar4,uVar3);
LAB_0001287e:
  FUN_0001cd4c(&DAT_00012158);
  return 3;
}




void FUN_00012892(void)

{
  FUN_00015b9c(*(undefined4 *)(DAT_00012a84 + 4),0);
  return;
}




void FUN_0001289c(void)

{
  FUN_00015b9c(*(undefined4 *)(DAT_00012a84 + 4),1);
  return;
}




uint FUN_000128a6(void)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  puVar1 = DAT_00012a84;
  uVar4 = 0;
  FUN_00015bc4(*DAT_00012a84,0);
  FUN_0001289c();
  bVar3 = 0;
  do {
    FUN_00015bc4(*puVar1,0);
    FUN_000175d2(5);
    FUN_00015bc4(*puVar1,1);
    uVar2 = FUN_00015bec(puVar1[1]);
    uVar4 = (uVar2 | uVar4 << 1) & 0xff;
    FUN_000175d2(5);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 8);
  FUN_00015bc4(*puVar1,0);
  FUN_00012892();
  FUN_00015bc4(*puVar1,1);
  FUN_000175d2(5);
  FUN_00015bc4(*puVar1,1);
  FUN_000175d2(5);
  FUN_00015bc4(*puVar1,0);
  FUN_000175d2(5);
  return uVar4;
}




uint FUN_00012924(int param_1,undefined4 param_2,int param_3,ushort *param_4)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar2 = DAT_00012a88;
  puVar3 = DAT_00012a88 + 1;
  *DAT_00012a88 = 0x80;
  *puVar3 = 0x71;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0x10;
  FUN_00011330(puVar2 + 5,param_2,param_1,param_4,param_3,param_4);
  uVar6 = 1;
  uVar7 = 2000;
  uVar5 = FUN_0001162a(DAT_00012a88,param_1 + 5U & 0xffff,param_3,param_4);
  if ((int)uVar5 != 0) {
    uVar4 = FUN_00011410((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),uVar6,uVar7);
    return uVar4;
  }
  uVar1 = *(ushort *)((uint)*param_4 + param_3 + -2);
  return (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
}




uint FUN_00012984(int param_1,undefined4 param_2,int param_3,ushort *param_4)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar2 = DAT_00012a88;
  puVar3 = DAT_00012a88 + 1;
  *DAT_00012a88 = 0x84;
  *puVar3 = 0x73;
  puVar2[2] = 1;
  puVar2[3] = 0;
  puVar2[4] = 8;
  FUN_00011330(puVar2 + 5,param_2,param_1,param_4,param_3,param_4);
  uVar6 = 1;
  uVar7 = 2000;
  uVar5 = FUN_0001162a(DAT_00012a88,param_1 + 5U & 0xffff,param_3,param_4);
  if ((int)uVar5 != 0) {
    uVar4 = FUN_00011410((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),uVar6,uVar7);
    return uVar4;
  }
  uVar1 = *(ushort *)(param_3 + -2 + (uint)*param_4);
  return (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
}




undefined4 thunk_FUN_0001d084(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = FUN_0001d462();
  iVar1 = DAT_0001d130;
  uVar3 = FUN_0001d61e(*(undefined4 *)(DAT_0001d130 + 0x14),param_1);
  FUN_0001d43c(uVar2);
  if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
    (**(code **)(iVar1 + 0xc))(uVar3,param_1);
  }
  return uVar3;
}




int thunk_FUN_0001d316(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0001d084();
  if (iVar1 != 0) {
    FUN_0001ce98(iVar1,0,param_2 * param_1);
  }
  return iVar1;
}




void thunk_FUN_0001d330(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_0001d47c + 0x10) != (code *)0x0) {
    (**(code **)(DAT_0001d47c + 0x10))(param_1);
  }
  if (param_1 != 0) {
    uVar1 = FUN_0001d462();
    FUN_0001d76a(param_1);
    FUN_0001d43c(uVar1);
    return;
  }
  return;
}




int FUN_00012a9c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00023a0c(param_1,DAT_00012c14);
  if (iVar1 != 0) {
    iVar1 = FUN_00023a0c(param_1,DAT_00012c14 + 6);
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = FUN_00023a0c(param_1,DAT_00012c14 + 0xd);
    if (iVar1 == 0) {
      return 2;
    }
    FUN_0001cd4c(&DAT_00012c18);
    FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x1b,s_Please_enable_RT_USING_POSIX_FS_00012c34);
    FUN_0001cd4c(&DAT_00012c5c);
    iVar1 = -1;
  }
  return iVar1;
}




undefined4 FUN_00012ae8(void)

{
  FUN_0001cd4c(&DAT_00012c18);
  FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x25,s_Please_enable_RT_USING_POSIX_FS_00012c34);
  FUN_0001cd4c(&DAT_00012c5c);
  return 0;
}




undefined4 FUN_00012b06(void)

{
  FUN_0001cd4c(&DAT_00012c18);
  FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x30,s_Please_enable_RT_USING_POSIX_FS_00012c34);
  FUN_0001cd4c(&DAT_00012c5c);
  return 0;
}




undefined4 FUN_00012b24(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_1 == 1) || (param_1 == 2)) {
    iVar1 = FUN_0001d250();
    if (iVar1 != 0) {
      FUN_00013708(iVar1,0xffffffff,param_2,param_3);
    }
  }
  else {
    if (param_1 == 0) {
      return 0xffffffff;
    }
    FUN_0001cd4c(&DAT_00012c18);
    FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x3a,s_Please_enable_RT_USING_POSIX_FS_00012c34);
    FUN_0001cd4c(&DAT_00012c5c);
  }
  return 0;
}




undefined4 FUN_00012b6a(void)

{
  FUN_0001cd4c(&DAT_00012c18);
  FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x45,s_Please_enable_RT_USING_POSIX_FS_00012c34);
  FUN_0001cd4c(&DAT_00012c5c);
  return 0;
}




undefined4 FUN_00012b88(void)

{
  FUN_0001cd4c(&DAT_00012c18);
  FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x51,s_Please_enable_RT_USING_POSIX_FS_00012c34);
  FUN_0001cd4c(&DAT_00012c5c);
  return 0;
}




undefined4 FUN_00012ba6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0001d100(param_1,param_3,s_tem_03d_00012c64,param_2);
  return 1;
}




void FUN_00012bbc(undefined param_1)

{
  FUN_0001cd4c(&LAB_00012c6c,param_1);
  return;
}




void FUN_00012bc4(void)

{
  FUN_00012c70();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




undefined4 FUN_00012bcc(void)

{
  FUN_0001cd4c(&DAT_00012c18);
  FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x5b,s_Please_enable_RT_USING_POSIX_FS_00012c34);
  FUN_0001cd4c(&DAT_00012c5c);
  return 0;
}




undefined4 FUN_00012bea(uint param_1)

{
  if (param_1 < 3) {
    return 1;
  }
  return 0;
}




undefined4 FUN_00012bf6(void)

{
  FUN_0001cd4c(&DAT_00012c18);
  FUN_0001cd4c(s__s___s_00012c54,DAT_00012c14 + 0x14,s_Please_enable_RT_USING_POSIX_FS_00012c34);
  FUN_0001cd4c(&DAT_00012c5c);
  return 0;
}




void FUN_00012c70(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0001e356();
  if (iVar1 != 0) {
    FUN_0001cd4c(&DAT_00012d84);
    FUN_0001cd4c(s_thread__s_exit__d__00012d98,iVar1,param_1);
    FUN_0001cd4c(&DAT_00012dac);
    FUN_0001eb0c(iVar1,1,0);
    return;
  }
  return;
}




undefined4 FUN_00012db4(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  return uVar2;
}




void FUN_00012dbc(uint param_1)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_1 & 1) == 1);
  }
  return;
}




void FUN_00012dc2(undefined4 param_1,undefined4 param_2)

{
  if (*DAT_00012ed4 != 1) {
    *DAT_00012ed4 = 1;
    *DAT_00012ed8 = param_1;
  }
  *DAT_00012edc = param_2;
  *DAT_00012ee0 = 0x10000000;
  return;
}




undefined4 FUN_00012e4e(undefined4 param_1)

{
  char cVar1;
  bool bVar2;
  
  *DAT_00012edc = param_1;
  cVar1 = isThreadModePrivileged();
  isUsingMainStack();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(cVar1 == '\x01');
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar1 = isUsingMainStack();
      setStackMode(cVar1 == '\x01');
    }
  }
  *DAT_00012ed8 = 0;
  *DAT_00012ed4 = 1;
  *DAT_00012ee4 = DAT_00012ee8 | *DAT_00012ee4;
  *DAT_00012ee0 = 0x10000000;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setMainStackPointer(*(undefined4 *)*DAT_00012eec);
  }
  enableFIQinterrupts();
  enableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return *(undefined4 *)*DAT_00012eec;
}




void FUN_00012ef0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = DAT_00013180;
  uVar2 = param_3 + 4U & 0xfffffff8;
  uVar3 = 0;
  do {
    ((undefined4 *)(uVar2 - 0x44))[uVar3] = uVar1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x11);
  *(undefined4 *)(uVar2 - 0x20) = param_2;
  *(undefined4 *)(uVar2 - 0x1c) = 0;
  *(undefined4 *)(uVar2 - 0x18) = 0;
  *(undefined4 *)(uVar2 - 0x14) = 0;
  *(undefined4 *)(uVar2 - 0x10) = 0;
  *(undefined4 *)(uVar2 - 0xc) = param_4;
  *(undefined4 *)(uVar2 - 8) = param_1;
  *(undefined4 *)(uVar2 - 4) = 0x1000000;
  *(undefined4 *)(uVar2 - 0x44) = 0;
  return;
}




void FUN_00012f2c(void)

{
  byte *pbVar1;
  
  FUN_0001cd4c(s_bus_fault__00013187 + 1);
  pbVar1 = DAT_00013194;
  FUN_0001cd4c(s_SCB_CFSR_BFSR_0x_02X_00013198,*DAT_00013194);
  if ((*pbVar1 & 1) != 0) {
    FUN_0001cd4c(s_IBUSERR_000131b0);
  }
  if ((int)((uint)*pbVar1 << 0x1e) < 0) {
    FUN_0001cd4c(s_PRECISERR_000131bc);
  }
  if ((int)((uint)*pbVar1 << 0x1d) < 0) {
    FUN_0001cd4c(s_IMPRECISERR_000131c8);
  }
  if ((int)((uint)*pbVar1 << 0x1c) < 0) {
    FUN_0001cd4c(s_UNSTKERR_000131d8);
  }
  if ((int)((uint)*pbVar1 << 0x1b) < 0) {
    FUN_0001cd4c(s_STKERR_000131e4);
  }
  if ((int)((uint)*pbVar1 << 0x18) < 0) {
    FUN_0001cd4c(s_SCB_>BFAR__08X_000131ec,*(undefined4 *)(DAT_00013194 + 0xf));
    return;
  }
  FUN_0001cd4c(&DAT_000131fc);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012f9a(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*_DAT_00013184 != (code *)0x0) && (iVar1 = (**_DAT_00013184)(param_1 + 0x28), iVar1 == 0)) {
    return;
  }
  FUN_0001cd4c(s_psr__0x_08x_00013200,*(undefined4 *)(param_1 + 0x44));
  FUN_0001cd4c(s_r00__0x_08x_00013210,*(undefined4 *)(param_1 + 0x28));
  FUN_0001cd4c(s_r01__0x_08x_00013220,*(undefined4 *)(param_1 + 0x2c));
  FUN_0001cd4c(s_r02__0x_08x_00013230,*(undefined4 *)(param_1 + 0x30));
  FUN_0001cd4c(s_r03__0x_08x_00013240,*(undefined4 *)(param_1 + 0x34));
  FUN_0001cd4c(s_r04__0x_08x_00013250,*(undefined4 *)(param_1 + 8));
  FUN_0001cd4c(s_r05__0x_08x_00013260,*(undefined4 *)(param_1 + 0xc));
  FUN_0001cd4c(s_r06__0x_08x_00013270,*(undefined4 *)(param_1 + 0x10));
  FUN_0001cd4c(s_r07__0x_08x_00013280,*(undefined4 *)(param_1 + 0x14));
  FUN_0001cd4c(s_r08__0x_08x_00013290,*(undefined4 *)(param_1 + 0x18));
  FUN_0001cd4c(s_r09__0x_08x_000132a0,*(undefined4 *)(param_1 + 0x1c));
  FUN_0001cd4c(s_r10__0x_08x_000132b0,*(undefined4 *)(param_1 + 0x20));
  FUN_0001cd4c(s_r11__0x_08x_000132c0,*(undefined4 *)(param_1 + 0x24));
  FUN_0001cd4c(s_r12__0x_08x_000132d0,*(undefined4 *)(param_1 + 0x38));
  FUN_0001cd4c(s_lr__0x_08x_000132e0,*(undefined4 *)(param_1 + 0x3c));
  FUN_0001cd4c(s_pc__0x_08x_000132f0,*(undefined4 *)(param_1 + 0x40));
  if ((int)((uint)*param_1 << 0x1d) < 0) {
    uVar2 = FUN_0001e356();
    FUN_0001cd4c(s_hard_fault_on_thread___s_00013300,uVar2);
    FUN_000195dc();
  }
  else {
    FUN_0001cd4c(s_hard_fault_on_handler_00013320);
  }
  if (-1 < (int)((uint)*param_1 << 0x1b)) {
    FUN_0001cd4c(s_FPU_active__0001333c);
  }
  FUN_0001306a();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




void FUN_00013060(void)

{
  *(undefined4 *)(DAT_00013194 + -0x1d) = DAT_0001334c;
  return;
}




void FUN_0001306a(void)

{
  int *piVar1;
  
  piVar1 = (int *)(DAT_00013194 + 3);
  if (*piVar1 << 0x1e < 0) {
    FUN_0001cd4c(s_failed_vector_fetch_00013350);
  }
  if (*piVar1 << 1 < 0) {
    if (*DAT_00013194 != '\0') {
      FUN_00012f2c();
    }
    if (DAT_00013194[-1] != '\0') {
      FUN_0001311c();
    }
    if (*(short *)(DAT_00013194 + 1) != 0) {
      FUN_000130b6();
    }
  }
  if (*piVar1 < 0) {
    FUN_0001cd4c(s_debug_event_00013368);
    return;
  }
  return;
}




void FUN_000130b6(void)

{
  ushort *puVar1;
  
  FUN_0001cd4c(s_usage_fault__00013378);
  puVar1 = (ushort *)(DAT_00013194 + 1);
  FUN_0001cd4c(s_SCB_CFSR_UFSR_0x_02X_00013388,*puVar1);
  if ((*puVar1 & 1) != 0) {
    FUN_0001cd4c(s_UNDEFINSTR_000133a0);
  }
  if ((int)((uint)*puVar1 << 0x1e) < 0) {
    FUN_0001cd4c(s_INVSTATE_000133ac);
  }
  if ((int)((uint)*puVar1 << 0x1d) < 0) {
    FUN_0001cd4c(s_INVPC_000133b8);
  }
  if ((int)((uint)*puVar1 << 0x1c) < 0) {
    FUN_0001cd4c(s_NOCP_000133c0);
  }
  if ((int)((uint)*puVar1 << 0x17) < 0) {
    FUN_0001cd4c(s_UNALIGNED_000133c8);
  }
  if ((int)((uint)*puVar1 << 0x16) < 0) {
    FUN_0001cd4c(s_DIVBYZERO_000133d4);
  }
  FUN_0001cd4c(s_usage_fault__00013378 + 0xc);
  return;
}




void FUN_0001311c(void)

{
  byte *pbVar1;
  
  FUN_0001cd4c(s_mem_manage_fault__000133e0);
  pbVar1 = (byte *)(DAT_00013194 + -1);
  FUN_0001cd4c(s_SCB_CFSR_MFSR_0x_02X_000133f4,*pbVar1);
  if ((*pbVar1 & 1) != 0) {
    FUN_0001cd4c(s_IACCVIOL_0001340c);
  }
  if ((int)((uint)*pbVar1 << 0x1e) < 0) {
    FUN_0001cd4c(s_DACCVIOL_00013418);
  }
  if ((int)((uint)*pbVar1 << 0x1c) < 0) {
    FUN_0001cd4c(s_MUNSTKERR_00013424);
  }
  if ((int)((uint)*pbVar1 << 0x1b) < 0) {
    FUN_0001cd4c(s_MSTKERR_00013430);
  }
  if ((int)((uint)*pbVar1 << 0x18) < 0) {
    FUN_0001cd4c(s_SCB_>MMAR__08X_0001343c,*(undefined4 *)(DAT_00013194 + 0xb));
    return;
  }
  FUN_0001cd4c(s_usage_fault__00013378 + 0xc);
  return;
}




undefined4 * FUN_0001344c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_0001dc1a(9);
  if ((param_1 != 0) && (iVar1 != 0)) {
    uVar2 = FUN_00012db4();
    iVar3 = FUN_0001c8d4();
    if (iVar3 != 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001dfb8,DAT_0001df78 + 0x71);
      FUN_0001cdc6(&LAB_0001dfe0,DAT_0001df78 + 0x71,0x266);
    }
    FUN_00012dbc(uVar2);
    FUN_0001e1fe();
    for (puVar4 = *(undefined4 **)(undefined4 *)(iVar1 + 4); puVar4 != (undefined4 *)(iVar1 + 4);
        puVar4 = (undefined4 *)*puVar4) {
      iVar3 = FUN_0001d038(puVar4 + -3,param_1,8);
      if (iVar3 == 0) {
        FUN_0001e214();
        return puVar4 + -3;
      }
    }
    FUN_0001e214();
  }
  return (undefined4 *)0x0;
}




undefined4 FUN_00013452(int param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffff01;
  if ((param_1 != 0) && (iVar1 = FUN_0001344c(param_2), iVar1 == 0)) {
    FUN_0001dcae(param_1,9,param_2);
    *(undefined2 *)(param_1 + 0x16) = param_3;
    uVar2 = 0;
    *(undefined *)(param_1 + 0x1a) = 0;
    *(undefined2 *)(param_1 + 0x18) = 0;
  }
  return uVar2;
}




int FUN_00013532(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 0x27,0xb4);
  }
  if ((*(code **)(param_1 + 0x24) != (code *)0x0) &&
     (-1 < (int)((uint)*(byte *)(param_1 + 0x16) << 0x1b))) {
    iVar1 = (**(code **)(param_1 + 0x24))(param_1);
    if (iVar1 == 0) {
      *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) | 0x10;
    }
    else {
      FUN_0001cd4c(&DAT_000138c4);
      FUN_0001cd4c(s_To_initialize_device__s_failed__T_000138dc,param_1,iVar1);
      FUN_0001cd4c(&DAT_00013914);
    }
  }
  return iVar1;
}




int FUN_0001357e(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 0x36,0xd9);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 9) {
    FUN_0001cdc6(s_rt_object_get_type__dev_>parent__0001382c,DAT_00013818 + 0x36,0xda);
  }
  if (-1 < (int)((uint)*(byte *)(param_1 + 0x16) << 0x1b)) {
    if ((*(code **)(param_1 + 0x24) != (code *)0x0) &&
       (iVar3 = (**(code **)(param_1 + 0x24))(param_1), iVar3 != 0)) {
      FUN_0001cd4c(&DAT_000138c4);
      FUN_0001cd4c(s_To_initialize_device__s_failed__T_000138dc,param_1,iVar3);
      FUN_0001cd4c(&DAT_00013914);
      return iVar3;
    }
    *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) | 0x10;
  }
  if ((int)((uint)*(byte *)(param_1 + 0x16) << 0x1c) < 0) {
    if ((int)((uint)*(byte *)(param_1 + 0x18) << 0x1c) < 0) {
      return -0x17;
    }
  }
  else if (((int)((uint)*(ushort *)(param_1 + 0x18) << 0x1c) < 0) &&
          ((*(ushort *)(param_1 + 0x18) & 0xf0f) == (param_2 & 0xf0f))) goto LAB_0001361e;
  if (*(code **)(param_1 + 0x28) == (code *)0x0) {
    *(short *)(param_1 + 0x18) = (short)(param_2 & 0xf0f);
  }
  else {
    iVar3 = (**(code **)(param_1 + 0x28))(param_1,param_2);
    if ((iVar3 != 0) && (iVar3 != -0x2d)) {
      return iVar3;
    }
  }
LAB_0001361e:
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 8;
  cVar1 = *(char *)(param_1 + 0x1a);
  *(char *)(param_1 + 0x1a) = cVar1 + '\x01';
  if (cVar1 == -1) {
    FUN_0001cdc6(s_dev_>ref_count____0_0001391c,DAT_00013818 + 0x36,0x10c);
  }
  return iVar3;
}




int FUN_00013644(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 0x45,0x11f);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 9) {
    FUN_0001cdc6(s_rt_object_get_type__dev_>parent__0001382c,DAT_00013818 + 0x45,0x120);
  }
  cVar1 = *(char *)(param_1 + 0x1a);
  if (cVar1 != '\0') {
    *(char *)(param_1 + 0x1a) = cVar1 + -1;
    if (cVar1 != '\x01') {
      return 0;
    }
    if (((*(code **)(param_1 + 0x2c) == (code *)0x0) ||
        (iVar3 = (**(code **)(param_1 + 0x2c))(param_1), iVar3 == 0)) || (iVar3 == -0x2d)) {
      *(undefined2 *)(param_1 + 0x18) = 0;
    }
    return iVar3;
  }
  return -0xff;
}




undefined4 FUN_000136a6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 0x55,0x14d);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 9) {
    FUN_0001cdc6(s_rt_object_get_type__dev_>parent__0001382c,DAT_00013818 + 0x55,0x14e);
  }
  if (*(char *)(param_1 + 0x1a) == '\0') {
    uVar2 = 0xffffff01;
  }
  else {
    if (*(code **)(param_1 + 0x30) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000136f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(param_1 + 0x30))(param_1,param_2,param_3,param_4);
      return uVar2;
    }
    uVar2 = 0xffffffd3;
  }
  FUN_0001ce66(uVar2);
  return 0;
}




undefined4 FUN_00013708(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 100,0x178);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 9) {
    FUN_0001cdc6(s_rt_object_get_type__dev_>parent__0001382c,DAT_00013818 + 100,0x179);
  }
  if (*(char *)(param_1 + 0x1a) == '\0') {
    uVar2 = 0xffffff01;
  }
  else {
    if (*(code **)(param_1 + 0x34) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00013756. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(param_1 + 0x34))(param_1,param_2,param_3,param_4);
      return uVar2;
    }
    uVar2 = 0xffffffd3;
  }
  FUN_0001ce66(uVar2);
  return 0;
}




undefined4 FUN_0001376a(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 0x74,0x19c);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 9) {
    FUN_0001cdc6(s_rt_object_get_type__dev_>parent__0001382c,DAT_00013818 + 0x74,0x19d);
  }
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000137a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(param_1 + 0x38))(param_1,param_2,param_3);
    return uVar2;
  }
  return 0xffffffd3;
}




undefined4 FUN_000137b0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 0x86,0x1b8);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 9) {
    FUN_0001cdc6(s_rt_object_get_type__dev_>parent__0001382c,DAT_00013818 + 0x86,0x1b9);
  }
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return 0;
}




undefined4 FUN_000137e4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_dev____RT_NULL_0001381c,DAT_00013818 + 0xa0,0x1d0);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 9) {
    FUN_0001cdc6(s_rt_object_get_type__dev_>parent__0001382c,DAT_00013818 + 0xa0,0x1d1);
  }
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return 0;
}




undefined4 FUN_00013930(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = (*(int **)(param_1 + 0x44))[1];
  if ((**(int **)(param_1 + 0x44) < DAT_00013d2c) || (DAT_00013d2c < iVar1)) {
    *(int *)(param_1 + 0x48) = iVar1;
  }
  else {
    *(int *)(param_1 + 0x48) = DAT_00013d2c;
  }
  *(undefined *)(param_1 + 0x5c) = 1;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if (**(code ***)(param_1 + 0x40) == (code *)0x0) {
    uVar2 = 0xffffffd3;
  }
  else {
    (***(code ***)(param_1 + 0x40))(param_1,1);
  }
  return uVar2;
}




undefined4 FUN_0001396a(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  pcVar1 = *(code **)(*(int *)(param_1 + 0x40) + 0x10);
  if (pcVar1 == (code *)0x0) {
    uVar2 = 0xffffffd3;
  }
  else {
    (*pcVar1)(param_1,0x1301,param_1 + 0x48);
  }
  return uVar2;
}




undefined4 FUN_00013988(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (**(code ***)(param_1 + 0x40) == (code *)0x0) {
    uVar1 = 0xffffffd3;
  }
  else {
    (***(code ***)(param_1 + 0x40))(param_1,0);
  }
  *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) & 0xffef;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return uVar1;
}




uint FUN_000139ae(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint in_fpscr;
  float fVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  int local_28;
  uint local_24;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x40) + 0xc);
  if (uVar1 != 0) {
    local_28 = param_3;
    local_24 = param_4;
    uVar2 = FUN_00012db4();
    iVar3 = (**(code **)(*(int *)(param_1 + 0x40) + 0xc))(param_1);
    uVar4 = *(undefined4 *)(param_1 + 0x4c);
    FUN_00012dbc(uVar2);
    if (*(char *)(*(int *)(param_1 + 0x44) + 0xc) == '\x02') {
      fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x48),
                                         (byte)(in_fpscr >> 0x15) & 3);
      iVar6 = VectorFloatToUnsigned(fVar5 * *(float *)(param_1 + 0x50),3);
      iVar3 = iVar6 - iVar3;
    }
    if (*(char *)(param_1 + 0x5c) == '\x01') {
      uVar4 = 0;
    }
    fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x48),(byte)(in_fpscr >> 0x15) & 3)
    ;
    fVar8 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x15) & 3);
    fVar7 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x15) & 3);
    fVar5 = fVar8 / fVar5 + fVar7 * *(float *)(param_1 + 0x50);
    local_28 = (int)fVar5;
    fVar7 = (float)VectorSignedToFloat(local_28,(byte)(in_fpscr >> 0x15) & 3);
    local_24 = (uint)((fVar5 - fVar7) * DAT_00013d30);
    uVar1 = param_4;
    if (8 < param_4) {
      uVar1 = 8;
    }
    FUN_0001ceee(param_3,&local_28,uVar1);
  }
  return uVar1;
}




undefined4 FUN_00013a5e(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  uVar4 = 2;
  if (((*(int *)(*(int *)(param_1 + 0x40) + 4) == 0) ||
      (pcVar3 = *(code **)(*(int *)(param_1 + 0x40) + 8), pcVar3 == (code *)0x0)) || (param_4 != 8))
  {
    uVar4 = 0;
  }
  else {
    (*pcVar3)(param_1);
    FUN_00012db4();
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_00012dbc();
    uVar1 = FUN_00013c40(param_1,param_3);
    if ((*(int *)(param_1 + 0x54) < 2) && (*(char *)(param_1 + 0x5c) == '\x01')) {
      uVar4 = 1;
    }
    iVar2 = (**(code **)(*(int *)(param_1 + 0x40) + 4))(param_1,uVar1,uVar4);
    uVar4 = 8;
    if (iVar2 != 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}




int FUN_00013aba(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == 0x1301) {
    if (param_3 == (int *)0x0) {
      return -0x44;
    }
    if ((**(int **)(param_1 + 0x44) < *param_3) || (*param_3 < (*(int **)(param_1 + 0x44))[1])) {
      FUN_0001cd4c(&DAT_00013d34);
      FUN_0001cd4c(s_frequency_setting_out_of_range__I_00013d48,*(undefined4 *)(param_1 + 0x48));
      FUN_0001cd4c(&LAB_00013d84);
      return -5;
    }
    pcVar2 = *(code **)(*(int *)(param_1 + 0x40) + 0x10);
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)(param_1);
      if (iVar3 != 0) {
        return iVar3;
      }
      FUN_00012db4();
      *(int *)(param_1 + 0x48) = *param_3;
LAB_00013b6a:
      FUN_00012dbc();
      return 0;
    }
  }
  else if (param_2 == 0x1302) {
    pcVar2 = *(code **)(*(int *)(param_1 + 0x40) + 8);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1);
      return 0;
    }
  }
  else {
    if (param_2 == 0x1303) {
      if (param_3 == (int *)0x0) {
        return -0x44;
      }
      piVar1 = *(int **)(param_1 + 0x44);
      iVar3 = piVar1[1];
      iVar4 = piVar1[2];
      iVar5 = piVar1[3];
      *param_3 = *piVar1;
      param_3[1] = iVar3;
      param_3[2] = iVar4;
      param_3[3] = iVar5;
      return 0;
    }
    if (param_2 == 0x1304) {
      if (param_3 == (int *)0x0) {
        return -0x44;
      }
      if ((*(char *)param_3 != '\x01') && (*(char *)param_3 != '\x02')) {
        return -0xff;
      }
      FUN_00012db4();
      *(char *)(param_1 + 0x5c) = *(char *)param_3;
      goto LAB_00013b6a;
    }
  }
  return -0x2d;
}




undefined4 FUN_00013c40(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  uint uVar4;
  float fVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  float fVar13;
  float fVar14;
  
  fVar5 = 1.0;
  iVar3 = 0;
  fVar7 = (float)VectorUnsignedToFloat
                           (*(undefined4 *)(*(int *)(param_1 + 0x44) + 8),
                            (byte)(in_fpscr >> 0x15) & 3);
  uVar6 = *(undefined4 *)(param_1 + 0x48);
  fVar10 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x15) & 3);
  fVar8 = (float)VectorSignedToFloat(param_2[1],(byte)(in_fpscr >> 0x15) & 3);
  fVar9 = (float)VectorSignedToFloat(*param_2,(byte)(in_fpscr >> 0x15) & 3);
  fVar9 = fVar8 / DAT_00013d30 + fVar9;
  fVar8 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x15) & 3);
  fVar8 = 1.0 / fVar8;
  uVar4 = in_fpscr & 0xfffffff | (uint)(fVar8 < fVar9) << 0x1f;
  if (fVar8 == fVar9 || SUB41(uVar4 >> 0x1f,0) != (NAN(fVar8) || NAN(fVar9))) {
    iVar2 = 1;
    do {
      fVar8 = (float)VectorSignedToFloat(iVar2,(byte)(uVar4 >> 0x15) & 3);
      fVar8 = fVar9 / fVar8;
      uVar4 = uVar4 & 0xfffffff;
      if (fVar8 <= fVar7 / fVar10) {
        fVar11 = (float)VectorSignedToFloat(uVar6,(byte)(uVar4 >> 0x15) & 3);
        fVar13 = (float)VectorSignedToFloat(uVar6,(byte)(uVar4 >> 0x15) & 3);
        uVar12 = VectorFloatToUnsigned(fVar11 * fVar8,3);
        fVar11 = (float)VectorUnsignedToFloat(uVar12,(byte)(uVar4 >> 0x15) & 3);
        fVar14 = (float)VectorSignedToFloat(iVar2,(byte)(uVar4 >> 0x15) & 3);
        fVar11 = fVar9 - (fVar11 / fVar13) * fVar14;
        uVar1 = uVar4 | (uint)(fVar11 < fVar5) << 0x1f;
        if (fVar11 != fVar5 && SUB41(uVar1 >> 0x1f,0) == (NAN(fVar11) || NAN(fVar5))) {
          fVar8 = (float)VectorSignedToFloat(iVar3,(byte)(uVar1 >> 0x15) & 3);
          fVar8 = fVar9 / fVar8;
          iVar2 = iVar3;
          uVar4 = uVar1;
          break;
        }
        if (fVar11 == 0.0) break;
        if (fVar11 < fVar5) {
          iVar3 = iVar2;
          fVar5 = fVar11;
        }
      }
      iVar2 = iVar2 + 1;
    } while (0 < iVar2);
  }
  else {
    fVar8 = (float)VectorSignedToFloat(uVar6,(byte)(uVar4 >> 0x15) & 3);
    fVar8 = 1.0 / fVar8;
    iVar2 = 0;
  }
  fVar5 = (float)VectorSignedToFloat(uVar6,(byte)(uVar4 >> 0x15) & 3);
  *(int *)(param_1 + 0x54) = iVar2;
  *(int *)(param_1 + 0x58) = iVar2;
  *(float *)(param_1 + 0x50) = fVar8;
  uVar6 = VectorFloatToUnsigned(fVar5 * fVar8,3);
  return uVar6;
}




undefined4 FUN_00013dec(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  (*(code *)param_1[2])(*param_1,1);
  if (param_1[4] != 0) {
    iVar1 = FUN_0001a1aa();
    while (iVar2 = (*(code *)param_1[4])(*param_1), iVar2 == 0) {
      iVar2 = FUN_0001a1aa();
      if ((uint)param_1[7] < (uint)(iVar2 - iVar1)) {
        return 0xffffff8b;
      }
      FUN_0001417c(param_1);
    }
  }
  FUN_0001417c(param_1);
  return 0;
}




void FUN_00013e30(undefined4 *param_1)

{
  (*(code *)param_1[1])(*param_1,1);
  FUN_00013dec(param_1);
  FUN_0001417c(param_1);
  (*(code *)param_1[1])(*param_1,0);
  FUN_0001417c(param_1);
                    /* WARNING: Could not recover jumptable at 0x00013e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[2])(*param_1,0);
  return;
}




void FUN_00013e62(undefined4 *param_1)

{
  (*(code *)param_1[1])(*param_1,0);
  FUN_0001417c(param_1);
  FUN_00013dec(param_1);
  FUN_0001417c(param_1);
  (*(code *)param_1[1])(*param_1,1);
                    /* WARNING: Could not recover jumptable at 0x00013e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[5])(param_1[6]);
  return;
}




uint FUN_00013e92(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = *(undefined4 **)(param_1 + 0x7c);
  uVar3 = 7;
  uVar4 = 0xffffff8b;
  do {
    (*(code *)puVar2[2])(*puVar2,0);
    (*(code *)puVar2[1])(*puVar2,param_2 >> (uVar3 & 0xff) & 1);
    FUN_0001417c(puVar2);
    iVar1 = FUN_00013dec(puVar2);
    if (iVar1 < 0) {
      return 0xffffff8b;
    }
    uVar3 = uVar3 - 1;
  } while (-1 < (int)uVar3);
  (*(code *)puVar2[2])(*puVar2,0);
  FUN_0001417c(puVar2);
  (*(code *)puVar2[1])(*puVar2,1);
  FUN_0001417c(puVar2);
  iVar1 = FUN_00013dec(puVar2);
  if (iVar1 < 0) {
    FUN_0001cd4c(&DAT_000141fc);
    FUN_0001cd4c(s_wait_ack_timeout_0001420c);
    FUN_0001cd4c(&DAT_00014220);
  }
  else {
    iVar1 = (*(code *)puVar2[3])(*puVar2);
    uVar4 = (uint)(iVar1 == 0);
    (*(code *)puVar2[2])(*puVar2,0);
  }
  return uVar4;
}




int FUN_00013f24(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  
  uVar5 = (uint)*(ushort *)(param_2 + 4);
  uVar1 = *(ushort *)(param_2 + 2);
  iVar9 = 0;
  puVar8 = *(undefined **)(param_2 + 8);
  while( true ) {
    do {
      if ((int)uVar5 < 1) {
        return iVar9;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x7c);
      uVar4 = 0;
      (*(code *)puVar3[1])(*puVar3,1);
      FUN_0001417c(puVar3);
      bVar6 = 0;
      do {
        uVar4 = (uVar4 << 0x19) >> 0x18;
        iVar2 = FUN_00013dec(puVar3);
        if (iVar2 < 0) {
          return iVar9;
        }
        iVar2 = (*(code *)puVar3[3])(*puVar3);
        if (iVar2 != 0) {
          uVar4 = uVar4 | 1;
        }
        (*(code *)puVar3[2])(*puVar3,0);
        (*(code *)puVar3[5])(puVar3[6]);
        bVar6 = bVar6 + 1;
      } while (bVar6 < 8);
      puVar7 = puVar8 + 1;
      *puVar8 = (char)uVar4;
      uVar5 = uVar5 - 1;
      iVar9 = iVar9 + 1;
      puVar8 = puVar7;
    } while ((int)((uint)uVar1 << 0x19) < 0);
    puVar3 = *(undefined4 **)(param_1 + 0x7c);
    if (uVar5 != 0) {
      (*(code *)puVar3[1])(*puVar3,0);
    }
    FUN_0001417c(puVar3);
    iVar2 = FUN_00013dec(puVar3);
    if (iVar2 < 0) break;
    (*(code *)puVar3[2])(*puVar3,0);
  }
  FUN_0001cd4c(&DAT_00014228);
  FUN_0001cd4c(s_ACK_or_NACK_timeout__00014238);
  FUN_0001cd4c(&DAT_00014220);
  return -0x75;
}




int FUN_00013fde(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 0x7c);
  for (iVar1 = 0;
      ((iVar1 <= param_3 && (iVar2 = FUN_00013e92(param_1,param_2), iVar2 != 1)) &&
      (iVar1 != param_3)); iVar1 = iVar1 + 1) {
    FUN_00013e62(iVar3);
    (**(code **)(iVar3 + 0x14))(*(undefined4 *)(iVar3 + 0x18));
    FUN_00014188(iVar3);
  }
  return iVar2;
}




undefined4 FUN_00014020(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  ushort uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar1 = param_2[1];
  uVar8 = *(undefined4 *)(param_1 + 0x7c);
  if ((uVar1 & 0x20) == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x78);
  }
  else {
    uVar3 = 0;
  }
  uVar2 = *param_2;
  if (-1 < (int)((uint)uVar1 << 0x1d)) {
    uVar7 = ((uint)uVar2 << 0x19) >> 0x18;
    if ((uVar1 & 1) != 0) {
      uVar7 = uVar7 | 1;
    }
    iVar4 = FUN_00013fde(param_1,uVar7,uVar3);
    if (iVar4 == 1) {
      return 0;
    }
    if ((uVar1 & 0x20) != 0) {
      return 0;
    }
    return 0xfffffff4;
  }
  uVar6 = uVar2 >> 7 & 6;
  iVar4 = FUN_00013fde(param_1,uVar6 | 0xf0,uVar3);
  if ((iVar4 == 1) || ((uVar1 & 0x20) != 0)) {
    iVar4 = FUN_00013e92(param_1,uVar2 & 0xff);
    if ((iVar4 == 1) || ((uVar1 & 0x20) != 0)) {
      if ((uVar1 & 1) != 0) {
        FUN_00013e30(uVar8);
        iVar4 = FUN_00013fde(param_1,uVar6 | 0xf1,uVar3);
        if ((iVar4 != 1) && ((uVar1 & 0x20) == 0)) {
          FUN_0001cd4c(&DAT_00014228);
          pcVar5 = s_NACK__sending_repeated_addr_00014288;
          goto LAB_000140a0;
        }
      }
      return 0;
    }
    FUN_0001cd4c(&DAT_000141fc);
    pcVar5 = s_NACK__sending_second_addr_0001426c;
  }
  else {
    FUN_0001cd4c(&DAT_000141fc);
    pcVar5 = s_NACK__sending_first_addr_00014250;
  }
LAB_000140a0:
  FUN_0001cd4c(pcVar5);
  FUN_0001cd4c(&DAT_00014220);
  return 0xfffffff4;
}




uint FUN_000140da(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int unaff_r6;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(param_1 + 0x7c);
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    for (uVar3 = 0; uVar2 = uVar3, uVar3 < param_3; uVar3 = uVar3 + 1) {
      unaff_r6 = param_2 + uVar3 * 0xc;
      bVar1 = *(byte *)(unaff_r6 + 2);
      if (-1 < (int)((uint)bVar1 << 0x1b)) {
        if (uVar3 == 0) {
          FUN_00014188(uVar4);
        }
        else {
          FUN_00013e30();
        }
        uVar2 = FUN_00014020(param_1,unaff_r6);
        if ((uVar2 != 0) && ((bVar1 & 0x20) == 0)) break;
      }
      if ((*(byte *)(unaff_r6 + 2) & 1) == 0) {
        uVar2 = FUN_000141a6(param_1,unaff_r6);
        if ((int)uVar2 < (int)(uint)*(ushort *)(unaff_r6 + 4)) {
          if (-1 < (int)uVar2) {
            uVar2 = 0xffffff01;
          }
          break;
        }
      }
      else {
        uVar2 = FUN_00013f24();
        if ((int)uVar2 < (int)(uint)*(ushort *)(unaff_r6 + 4)) {
          if (-1 < (int)uVar2) {
            uVar2 = 0xfffffff4;
          }
          break;
        }
      }
    }
    if (-1 < (int)((uint)*(byte *)(unaff_r6 + 2) << 0x18)) {
      FUN_00013e62(uVar4);
    }
  }
  return uVar2;
}




void FUN_0001417c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014186. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x14))(*(int *)(param_1 + 0x18) + 1U >> 1);
  return;
}




void FUN_00014188(undefined4 *param_1)

{
  (*(code *)param_1[1])(*param_1,0);
  FUN_0001417c(param_1);
                    /* WARNING: Could not recover jumptable at 0x000141a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[2])(*param_1,0);
  return;
}




int FUN_000141a6(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  
  bVar1 = *(byte *)(param_2 + 2);
  iVar5 = 0;
  uVar3 = (uint)*(ushort *)(param_2 + 4);
  puVar4 = *(undefined **)(param_2 + 8);
  do {
    if ((int)uVar3 < 1) {
      return iVar5;
    }
    iVar2 = FUN_00013e92(param_1,*puVar4);
    if (iVar2 < 1) {
      if ((bVar1 & 0x20) == 0) {
        if (iVar2 == 0) {
          return 0;
        }
LAB_000141de:
        FUN_0001cd4c(&DAT_00014228);
        FUN_0001cd4c(s_send_bytes__error__d_000142a8,iVar2);
        FUN_0001cd4c(&DAT_00014220);
        return iVar2;
      }
      if (iVar2 != 0) goto LAB_000141de;
    }
    uVar3 = uVar3 - 1;
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + 1;
  } while( true );
}




int FUN_00014328(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (**(int **)(param_1 + 0x40) == 0) {
    FUN_0001cd4c(&DAT_0001444c);
    FUN_0001cd4c(s_I2C_bus_operation_not_supported_00014474);
    FUN_0001cd4c(&DAT_00014444);
    iVar1 = -5;
  }
  else {
    iVar1 = FUN_0001b018(param_1 + 0x48,0xffffffff);
    if (iVar1 == 0) {
      iVar2 = (***(code ***)(param_1 + 0x40))(param_1,param_2,param_3);
      iVar1 = FUN_0001b02a(param_1 + 0x48);
      if (iVar1 == 0) {
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}




undefined4 FUN_00014380(int param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0x40) + 8);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001438c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  FUN_0001cd4c(&DAT_0001444c);
  FUN_0001cd4c(s_I2C_bus_operation_not_supported_00014474);
  FUN_0001cd4c(&DAT_00014444);
  return 0xfffffffb;
}




undefined8
FUN_000143a6(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = CONCAT22((short)param_3,param_2);
  local_14 = CONCAT22((short)((uint)param_3 >> 0x10),(short)param_5);
  local_10 = param_4;
  iVar1 = FUN_00014328(param_1,&local_18,1);
  if (iVar1 == 1) {
    iVar1 = param_5;
  }
  return CONCAT44(local_18,iVar1);
}




undefined8 FUN_000143c8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = param_3;
  if (param_1 == 0) {
    local_28 = param_2;
    local_20 = param_4;
    FUN_0001cdc6(s_bus____RT_NULL_00014498,DAT_00014494,0x88);
  }
  local_28 = CONCAT22((short)param_3,(short)param_2) | 0x10000;
  local_24 = CONCAT22(local_24._2_2_,(short)param_5);
  local_20 = param_4;
  iVar1 = FUN_00014328(param_1,&local_28,1);
  if (iVar1 == 1) {
    iVar1 = param_5;
  }
  return CONCAT44(local_28,iVar1);
}




undefined4 FUN_00014604(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_1c;
  
  local_1c = param_2;
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_completion____RT_NULL_000147b8,DAT_000147b4 + 0x13,0x39,param_4,0);
  }
  if (local_1c != 0) {
    iVar1 = FUN_0001c8e6();
    uVar2 = FUN_00012db4();
    iVar3 = FUN_0001e246();
    if (iVar3 != 0) {
      FUN_0001cd4c(s_Function__s___scheduler_is_not_a_000147d0,DAT_000147b4 + 0x13);
      FUN_0001cdc6(&DAT_000147fc,DAT_000147b4 + 0x13,0x3c);
    }
    if (iVar1 == 1) {
      FUN_0001cd4c(s_Function__s___interrupt_is_disab_00014800,DAT_000147b4 + 0x13);
      FUN_0001cdc6(&DAT_000147fc,DAT_000147b4 + 0x13,0x3c);
    }
    uVar4 = FUN_00012db4();
    iVar1 = FUN_0001e356();
    if (iVar1 == 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_b_00014828,DAT_000147b4 + 0x13);
      FUN_0001cdc6(&DAT_000147fc,DAT_000147b4 + 0x13,0x3c);
    }
    uVar5 = FUN_00012db4();
    iVar1 = FUN_0001c8d4();
    if (iVar1 != 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_i_00014860,DAT_000147b4 + 0x13);
      FUN_0001cdc6(&DAT_000147fc,DAT_000147b4 + 0x13,0x3c);
    }
    FUN_00012dbc(uVar5);
    FUN_00012dbc(uVar4);
    FUN_00012dbc(uVar2);
  }
  uVar4 = 0;
  iVar1 = FUN_0001e356();
  uVar2 = FUN_00012db4();
  if (*param_1 != 1) {
    if ((int *)param_1[1] != param_1 + 1) {
      FUN_0001cdc6(s_rt_list_isempty___completion_>su_00014888,DAT_000147b4 + 0x13,0x45);
    }
    if (local_1c == 0) {
      uVar4 = 0xffffff8b;
      goto LAB_00014758;
    }
    *(undefined4 *)(iVar1 + 0x30) = 0;
    FUN_0001e860(iVar1,2);
    *(int *)param_1[2] = iVar1 + 0x14;
    *(int *)(iVar1 + 0x18) = param_1[2];
    param_1[2] = iVar1 + 0x14;
    *(int **)(iVar1 + 0x14) = param_1 + 1;
    uVar4 = FUN_00012db4();
    iVar3 = FUN_0001c8d4();
    if (iVar3 != 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_i_00014860,DAT_000147b4 + 0x13);
      FUN_0001cdc6(&DAT_000147fc,DAT_000147b4 + 0x13,0x58);
    }
    FUN_00012dbc(uVar4);
    if (0 < local_1c) {
      FUN_0001efae(iVar1 + 0x58,0,&local_1c);
      FUN_0001ee68(iVar1 + 0x58);
    }
    FUN_00012dbc(uVar2);
    FUN_0001e128();
    uVar4 = *(undefined4 *)(iVar1 + 0x30);
    uVar2 = FUN_00012db4();
  }
  *param_1 = 0;
LAB_00014758:
  FUN_00012dbc(uVar2);
  return uVar4;
}




short FUN_00014ae2(int *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  short sVar3;
  uint uVar4;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_queue____RT_NULL_00014c9c,DAT_00014c98 + 0x74,0x1d9);
  }
  if (*param_1 != DAT_00014cbc) {
    FUN_0001cdc6(s_queue_>magic____DATAQUEUE_MAGIC_00014cc0,DAT_00014c98 + 0x74,0x1da);
  }
  if ((int)((uint)*(ushort *)(param_1 + 2) << 0x10) < 0) {
    return 0;
  }
  uVar2 = FUN_00012db4();
  uVar4 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  sVar3 = (short)uVar4;
  uVar1 = *(ushort *)(param_1 + 2);
  if (uVar4 <= (uVar1 & 0x7fff)) {
    sVar3 = sVar3 + *(short *)(param_1 + 1);
  }
  FUN_00012dbc(uVar2);
  return sVar3 - (ushort)(((uint)uVar1 << 0x11) >> 0x11);
}




int FUN_00014b3e(int *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  int local_28;
  
  local_28 = param_4;
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_queue____RT_NULL_00014c9c,DAT_00014c98 + 0x26,0xd6);
  }
  if (*param_1 != DAT_00014cbc) {
    FUN_0001cdc6(s_queue_>magic____DATAQUEUE_MAGIC_00014cc0,DAT_00014c98 + 0x26,0xd7);
  }
  if (param_2 == (undefined4 *)0x0) {
    FUN_0001cdc6(s_data_ptr____RT_NULL_00014d98,DAT_00014c98 + 0x26,0xd8);
  }
  if (param_3 == (undefined4 *)0x0) {
    FUN_0001cdc6(s_size____RT_NULL_00014dac,DAT_00014c98 + 0x26,0xd9);
  }
  if (local_28 != 0) {
    iVar2 = FUN_0001c8e6();
    uVar3 = FUN_00012db4();
    iVar4 = FUN_0001e246();
    if (iVar4 != 0) {
      FUN_0001cd4c(s_Function__s___scheduler_is_not_a_00014ce0,DAT_00014c98 + 0x26);
      FUN_0001cdc6(&DAT_00014d0c,DAT_00014c98 + 0x26,0xdc);
    }
    if (iVar2 == 1) {
      FUN_0001cd4c(s_Function__s___interrupt_is_disab_00014d10,DAT_00014c98 + 0x26);
      FUN_0001cdc6(&DAT_00014d0c,DAT_00014c98 + 0x26,0xdc);
    }
    uVar5 = FUN_00012db4();
    iVar2 = FUN_0001e356();
    if (iVar2 == 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_b_00014d38,DAT_00014c98 + 0x26);
      FUN_0001cdc6(&DAT_00014d0c,DAT_00014c98 + 0x26,0xdc);
    }
    uVar6 = FUN_00012db4();
    iVar2 = FUN_0001c8d4();
    if (iVar2 != 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_i_00014d70,DAT_00014c98 + 0x26);
      FUN_0001cdc6(&DAT_00014d0c,DAT_00014c98 + 0x26,0xdc);
    }
    FUN_00012dbc(uVar6);
    FUN_00012dbc(uVar5);
    FUN_00012dbc(uVar3);
  }
  iVar4 = 0;
  iVar2 = FUN_0001e356();
  uVar3 = FUN_00012db4();
  while( true ) {
    if (-1 < (int)((uint)*(ushort *)(param_1 + 2) << 0x10)) {
      *param_2 = *(undefined4 *)(param_1[3] + (*(ushort *)(param_1 + 2) & 0x7fff) * 8);
      *param_3 = *(undefined4 *)(param_1[3] + (*(ushort *)(param_1 + 2) & 0x7fff) * 8 + 4);
      uVar1 = *(ushort *)(param_1 + 2) >> 0xf;
      uVar7 = ((uint)uVar1 | (uint)*(ushort *)(param_1 + 2) << 0x11) + 0x20000;
      uVar1 = uVar1 << 0xf;
      *(ushort *)(param_1 + 2) = (ushort)(uVar7 >> 0x11) | uVar1;
      if (uVar7 >> 0x11 == (uint)*(ushort *)(param_1 + 1)) {
        *(ushort *)(param_1 + 2) = uVar1;
      }
      uVar1 = *(ushort *)((int)param_1 + 10) & 0x7fff;
      *(ushort *)((int)param_1 + 10) = uVar1;
      if (uVar1 == (*(ushort *)(param_1 + 2) & 0x7fff)) {
        *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | 0x8000;
      }
      uVar7 = FUN_00014ae2(param_1);
      if (*(ushort *)((int)param_1 + 6) < uVar7) {
        FUN_00012dbc(uVar3);
        pcVar8 = (code *)param_1[8];
        if (pcVar8 == (code *)0x0) {
          return iVar4;
        }
        uVar3 = 1;
      }
      else {
        if ((int *)param_1[4] == param_1 + 4) {
          FUN_00012dbc(uVar3);
        }
        else {
          FUN_0001e4e2((int *)param_1[4] + -5);
          FUN_00012dbc(uVar3);
          FUN_0001e128();
        }
        pcVar8 = (code *)param_1[8];
        if (pcVar8 == (code *)0x0) {
          return iVar4;
        }
        uVar3 = 3;
      }
      (*pcVar8)(param_1,uVar3);
      return iVar4;
    }
    if (local_28 == 0) break;
    *(undefined4 *)(iVar2 + 0x30) = 0;
    FUN_0001e860(iVar2,2);
    FUN_00014fd0(param_1 + 6,iVar2 + 0x14);
    if (0 < local_28) {
      FUN_0001efae(iVar2 + 0x58,0,&local_28);
      FUN_0001ee68(iVar2 + 0x58);
    }
    FUN_00012dbc(uVar3);
    FUN_0001e128();
    iVar4 = *(int *)(iVar2 + 0x30);
    uVar3 = FUN_00012db4();
    if (iVar4 != 0) {
LAB_00014dc2:
      FUN_00012dbc(uVar3);
      return iVar4;
    }
  }
  iVar4 = -0x75;
  goto LAB_00014dc2;
}




undefined4 FUN_00014e78(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_queue____RT_NULL_00014c9c,DAT_00014fe0,0x14e);
  }
  if (*param_1 != DAT_00014fe4) {
    FUN_0001cdc6(s_queue_>magic____DATAQUEUE_MAGIC_00014cc0,DAT_00014fe0,0x14f);
  }
  if ((int)((uint)*(ushort *)(param_1 + 2) << 0x10) < 0) {
    return 0xffffffbc;
  }
  FUN_00012db4();
  *param_2 = *(undefined4 *)(param_1[3] + (*(ushort *)(param_1 + 2) & 0x7fff) * 8);
  *param_3 = *(undefined4 *)(param_1[3] + (*(ushort *)(param_1 + 2) & 0x7fff) * 8 + 4);
  FUN_00012dbc();
  return 0;
}




void FUN_00014ede(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_queue____RT_NULL_00014c9c,DAT_00014fe0 + 0x13,0x16e);
  }
  if (*param_1 != DAT_00014fe4) {
    FUN_0001cdc6(s_queue_>magic____DATAQUEUE_MAGIC_00014cc0,DAT_00014fe0 + 0x13,0x16f);
  }
  uVar1 = FUN_00012db4();
  *(undefined2 *)(param_1 + 2) = 0x8000;
  *(undefined2 *)((int)param_1 + 10) = 0;
  FUN_00012dbc(uVar1);
  FUN_0001e1fe();
  while ((int *)param_1[6] != param_1 + 6) {
    uVar1 = FUN_00012db4();
    iVar2 = param_1[6];
    *(undefined4 *)(iVar2 + 0x1c) = 0xffffff01;
    FUN_0001e4e2(iVar2 + -0x14);
    FUN_00012dbc(uVar1);
  }
  while ((int *)param_1[4] != param_1 + 4) {
    uVar1 = FUN_00012db4();
    iVar2 = param_1[4];
    *(undefined4 *)(iVar2 + 0x1c) = 0xffffff01;
    FUN_0001e4e2(iVar2 + -0x14);
    FUN_00012dbc(uVar1);
  }
  FUN_0001e214();
  FUN_0001e128();
  return;
}




undefined4 FUN_00014f86(int *param_1)

{
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_queue____RT_NULL_00014c9c,DAT_00014fe0 + 0x27,0x1bd);
  }
  if (*param_1 != DAT_00014fe4) {
    FUN_0001cdc6(s_queue_>magic____DATAQUEUE_MAGIC_00014cc0,DAT_00014fe0 + 0x27,0x1be);
  }
  FUN_00014ede(param_1);
  FUN_00012db4();
  *param_1 = 0;
  FUN_00012dbc();
  FUN_0001d330(param_1[3]);
  return 0;
}




void FUN_00014fd0(int param_1,int *param_2)

{
  **(int ***)(param_1 + 4) = param_2;
  param_2[1] = *(int *)(param_1 + 4);
  *(int **)(param_1 + 4) = param_2;
  *param_2 = param_1;
  return;
}




void FUN_00014fe8(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  if (param_1 == (undefined4 *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0,0x29);
  }
  if ((int)param_3 < 1) {
    FUN_0001cdc6(s_size_>_0_000153e4,DAT_000153d0,0x2a);
  }
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = param_3 & 0xfffffff8;
  return;
}




int FUN_0001502e(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_000153b4();
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      return *(int *)(param_1 + 0xc);
    }
    uVar3 = *(uint *)(param_1 + 8) >> 1;
    uVar2 = *(uint *)(param_1 + 4) >> 1;
    if (uVar3 <= uVar2) {
      return *(int *)(param_1 + 0xc) - (uVar2 - uVar3);
    }
    iVar1 = uVar3 - uVar2;
  }
  return iVar1;
}




uint FUN_0001505a(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0x13,0x45);
  }
  iVar2 = FUN_0001502e(param_1);
  uVar3 = param_1[3] - iVar2;
  if (uVar3 != 0) {
    if (uVar3 < param_3) {
      param_3 = uVar3;
    }
    uVar3 = param_3;
    iVar2 = *param_1 + ((uint)param_1[2] >> 1);
    if (uVar3 < param_1[3] - ((uint)param_1[2] >> 1)) {
      FUN_0001ceee(iVar2,param_2,uVar3);
      uVar4 = param_1[2];
      uVar1 = uVar4 >> 1;
    }
    else {
      FUN_0001ceee(iVar2,param_2);
      iVar2 = param_1[3] - ((uint)param_1[2] >> 1);
      FUN_0001ceee(*param_1,iVar2 + param_2,uVar3 - iVar2);
      uVar4 = param_1[2] ^ 1;
      uVar1 = -(param_1[3] - ((uint)param_1[2] >> 1));
    }
    param_1[2] = uVar4 & 1 | (uVar3 + uVar1) * 2;
  }
  return uVar3;
}




uint FUN_000150d2(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0x25,0x7a);
  }
  iVar1 = FUN_0001502e(param_1);
  uVar2 = param_1[3];
  if (uVar2 < param_3) {
    param_2 = param_2 + (param_3 - uVar2);
    param_3 = uVar2;
  }
  iVar3 = *param_1 + ((uint)param_1[2] >> 1);
  if (param_3 < uVar2 - ((uint)param_1[2] >> 1)) {
    FUN_0001ceee(iVar3,param_2,param_3);
    uVar4 = param_3 + ((uint)param_1[2] >> 1);
    param_1[2] = param_1[2] & 1U | uVar4 * 2;
    if (param_3 <= uVar2 - iVar1) {
      return param_3;
    }
    uVar4 = uVar4 & 0x7fffffff;
    uVar2 = param_1[1];
  }
  else {
    FUN_0001ceee(iVar3,param_2);
    iVar3 = param_1[3] - ((uint)param_1[2] >> 1);
    FUN_0001ceee(*param_1,iVar3 + param_2,param_3 - iVar3);
    uVar4 = param_3 - (param_1[3] - ((uint)param_1[2] >> 1));
    param_1[2] = (param_1[2] ^ 1U) & 1 | uVar4 * 2;
    if (param_3 <= uVar2 - iVar1) {
      return param_3;
    }
    uVar4 = uVar4 & 0x7fffffff;
    uVar2 = param_1[1];
    if (uVar4 <= uVar2 >> 1) {
      uVar2 = uVar2 ^ 1;
      param_1[1] = uVar2;
    }
  }
  param_1[1] = uVar2 & 1 | uVar4 << 1;
  return param_3;
}




uint FUN_0001517a(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0x3d,0xb7);
  }
  uVar2 = FUN_0001502e(param_1);
  if (uVar2 != 0) {
    if (uVar2 < param_3) {
      param_3 = uVar2;
    }
    uVar2 = param_3;
    iVar4 = *param_1 + ((uint)param_1[1] >> 1);
    if (uVar2 < param_1[3] - ((uint)param_1[1] >> 1)) {
      FUN_0001ceee(param_2,iVar4,uVar2);
      uVar3 = param_1[1];
      uVar1 = uVar3 >> 1;
    }
    else {
      FUN_0001ceee(param_2,iVar4);
      iVar4 = param_1[3] - ((uint)param_1[1] >> 1);
      FUN_0001ceee(iVar4 + param_2,*param_1,uVar2 - iVar4);
      uVar3 = param_1[1] ^ 1;
      uVar1 = -(param_1[3] - ((uint)param_1[1] >> 1));
    }
    param_1[1] = uVar3 & 1 | (uVar2 + uVar1) * 2;
  }
  return uVar2;
}




uint FUN_000151f2(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0x4f,0xeb);
  }
  *param_2 = 0;
  uVar1 = FUN_0001502e(param_1);
  uVar3 = uVar1;
  if (uVar1 != 0) {
    *param_2 = *param_1 + ((uint)param_1[1] >> 1);
    uVar2 = param_1[1];
    uVar3 = param_1[3] - (uVar2 >> 1);
    if (uVar1 < uVar3) {
      uVar2 = uVar2 & 1 | (uVar1 + (uVar2 >> 1)) * 2;
      uVar3 = uVar1;
    }
    else {
      uVar2 = ~uVar2 & 1;
    }
    param_1[1] = uVar2;
  }
  return uVar3;
}




undefined4 FUN_00015240(int *param_1,undefined param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0x62,0x112);
  }
  iVar1 = FUN_0001502e(param_1);
  if (iVar1 == param_1[3]) {
    return 0;
  }
  *(undefined *)(*param_1 + ((uint)param_1[2] >> 1)) = param_2;
  uVar2 = param_1[2];
  if (param_1[3] - 1U == uVar2 >> 1) {
    uVar2 = ~uVar2 & 1;
  }
  else {
    uVar2 = uVar2 + 2;
  }
  param_1[2] = uVar2;
  return 1;
}




undefined4 FUN_0001528c(int *param_1,undefined param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0x78,0x135);
  }
  iVar1 = FUN_000153b4(param_1);
  *(undefined *)(*param_1 + ((uint)param_1[2] >> 1)) = param_2;
  uVar3 = param_1[2];
  if (param_1[3] - 1U == uVar3 >> 1) {
    param_1[2] = ~uVar3 & 1;
    if (iVar1 != 1) {
      return 1;
    }
    uVar3 = 0;
    uVar2 = param_1[1] ^ 1;
  }
  else {
    param_1[2] = uVar3 + 2;
    if (iVar1 != 1) {
      return 1;
    }
    uVar2 = param_1[1];
    uVar3 = uVar3 + 2 >> 1;
  }
  param_1[1] = uVar2 & 1 | uVar3 << 1;
  return 1;
}




int FUN_000152ea(int *param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_rb____RT_NULL_000153d4,DAT_000153d0 + 0x94,0x15c);
  }
  iVar1 = FUN_0001502e(param_1);
  if (iVar1 != 0) {
    *param_2 = *(undefined *)(*param_1 + ((uint)param_1[1] >> 1));
    uVar2 = param_1[1];
    if (param_1[3] - 1U == uVar2 >> 1) {
      uVar2 = ~uVar2 & 1;
    }
    else {
      uVar2 = uVar2 + 2;
    }
    param_1[1] = uVar2;
    iVar1 = 1;
  }
  return iVar1;
}




int FUN_0001534e(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_size_>_0_000153e4,DAT_000153d0 + 0xbe,0x1ae);
  }
  iVar1 = FUN_0001d084(0x10);
  if (iVar1 != 0) {
    iVar2 = FUN_0001d084(param_1 & 0xfffffff8);
    if (iVar2 == 0) {
      FUN_0001d330(iVar1);
      iVar1 = 0;
    }
    else {
      FUN_00014fe8(iVar1,iVar2,param_1 & 0xfffffff8);
    }
  }
  return iVar1;
}




undefined4 FUN_000153b4(int param_1)

{
  undefined4 uVar1;
  
  if (*(uint *)(param_1 + 4) >> 1 == *(uint *)(param_1 + 8) >> 1) {
    if (*(uint *)(param_1 + 4) * -0x80000000 + *(uint *)(param_1 + 8) * -0x80000000 == 0) {
      return 0;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}




uint FUN_000153f4(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (param_4 <= uVar2) {
      return uVar2;
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 0x40) + 4))(param_1,param_2 + uVar2,param_3);
    if (iVar1 != 0) break;
    uVar2 = uVar2 + 4;
    param_3 = param_3 + 4;
  }
  return 0;
}




undefined4 FUN_00015426(int param_1,char *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if (param_2 == s_pull_back_odometer_timeout_00001af0 + 0x11) {
    pcVar3 = **(code ***)(param_1 + 0x40);
    if (pcVar3 == (code *)0x0) {
      return 0xfffffffb;
    }
    uVar2 = 1;
LAB_00015454:
    uVar2 = (*pcVar3)(param_1,param_3,uVar2);
  }
  else {
    if (param_2 == s_pull_back_odometer_timeout_00001af0 + 0x12) {
      pcVar3 = **(code ***)(param_1 + 0x40);
      if (pcVar3 != (code *)0x0) {
        uVar2 = 0;
        goto LAB_00015454;
      }
LAB_00015470:
      if (param_2 != s_pull_back_odometer_timeout_00001af0 + 0x14) {
        return 0xfffffffb;
      }
      pcVar3 = *(code **)(*(int *)(param_1 + 0x40) + 0xc);
      if (pcVar3 == (code *)0x0) {
        return 0xfffffffb;
      }
      if (param_3 == (undefined2 *)0x0) {
        return 0xfffffffb;
      }
      iVar1 = (*pcVar3)();
      if (iVar1 == 0) {
        return 0xfffffffb;
      }
      *param_3 = (short)iVar1;
    }
    else {
      if (param_2 != s_pull_back_odometer_timeout_00001af0 + 0x13) goto LAB_00015470;
      pcVar3 = *(code **)(*(int *)(param_1 + 0x40) + 8);
      if (pcVar3 == (code *)0x0) {
        return 0xfffffffb;
      }
      if (param_3 == (undefined2 *)0x0) {
        return 0xfffffffb;
      }
      iVar1 = (*pcVar3)();
      if (iVar1 == 0) {
        return 0xfffffffb;
      }
      *(char *)param_3 = (char)iVar1;
    }
    uVar2 = 0;
  }
  return uVar2;
}




void FUN_00015488(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == 0) || (*(int *)(param_3 + 4) == 0)) {
    FUN_0001cdc6(s_ops____RT_NULL____ops_>convert___00015720,DAT_0001571c,0x5e);
  }
  *(undefined *)(param_1 + 0x14) = 0x1a;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  uVar1 = DAT_0001574c;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  *(undefined4 *)(param_1 + 0x34) = 0;
  uVar1 = DAT_00015750;
  *(int *)(param_1 + 0x40) = param_3;
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  *(undefined4 *)(param_1 + 0x3c) = param_4;
  FUN_00013452(param_1,param_2,3);
  return;
}




undefined4 FUN_000154d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  
  local_10 = param_4;
  if (param_1 == 0) {
    FUN_0001cdc6(&LAB_00015754,DAT_0001571c + 0x13,0x7a);
  }
  (**(code **)(*(int *)(param_1 + 0x40) + 4))(param_1,param_2,&local_10);
  return local_10;
}




undefined4 FUN_000154f4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(&LAB_00015754,DAT_0001571c + 0x1f,0x85);
  }
  if (**(code ***)(param_1 + 0x40) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00015518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (***(code ***)(param_1 + 0x40))(param_1,param_2,1);
    return uVar1;
  }
  return 0xffffffd3;
}




undefined4 FUN_00015520(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(&LAB_00015754,DAT_0001571c + 0x2d,0x97);
  }
  if (**(code ***)(param_1 + 0x40) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00015544. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (***(code ***)(param_1 + 0x40))(param_1,param_2,0);
    return uVar1;
  }
  return 0xffffffd3;
}




undefined8 FUN_0001554c(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int local_20;
  uint local_1c;
  uint local_18;
  
  local_20 = 0;
  local_1c = param_3 & 0xffff0000;
  iVar2 = 0;
  local_18 = param_4 & 0xffffff00;
  if (param_1 == 0) {
    FUN_0001cdc6(&LAB_00015754,DAT_0001571c + 0x3c,0xab);
  }
  iVar1 = FUN_00015426(param_1,s_pull_back_odometer_timeout_00001af0 + 0x13,&local_18);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_00015426(param_1,s_pull_back_odometer_timeout_00001af0 + 0x14,&local_1c),
     iVar1 == 0)) {
    (**(code **)(*(int *)(param_1 + 0x40) + 4))(param_1,param_2,&local_20);
    iVar2 = (int)(short)((uint)((short)local_1c * local_20) / (uint)(1 << (sbyte)local_18));
  }
  return CONCAT44(local_20,iVar2);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000155b2(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  if (param_1 < 2) {
    FUN_0001cd4c(&LAB_00015970);
    FUN_0001cd4c(&LAB_0001597c);
    FUN_0001cd4c(&LAB_000159ac);
    FUN_0001cd4c(&LAB_000159e8);
    puVar4 = &LAB_00015a18;
  }
  else {
    iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&LAB_00015758,param_3,param_4,param_4);
    piVar1 = _LAB_00015760;
    if (iVar3 == 0) {
      if (param_1 == 3) {
        iVar3 = FUN_0001344c(*(undefined4 *)(param_2 + 8));
        *piVar1 = iVar3;
        if (iVar3 == 0) {
          puVar4 = &LAB_000157fc;
        }
        else {
          puVar4 = &LAB_000157e4;
        }
        FUN_0001cd4c(&LAB_000157ec,*(undefined4 *)(param_2 + 8),puVar4);
        return 0;
      }
      puVar4 = &LAB_000157b4;
    }
    else {
      if (*_LAB_00015760 == 0) {
        FUN_0001cd4c(&LAB_00015804);
        return 0xffffff01;
      }
      iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&LAB_00015764);
      if (iVar3 == 0) {
        if (param_1 == 3) {
          cVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
          iVar3 = FUN_000154f4(*piVar1,(int)cVar2);
          if (iVar3 == 0) {
            puVar4 = &LAB_000157e4;
          }
          else {
            puVar4 = &LAB_000157fc;
          }
          uVar6 = FUN_00023590(*(undefined4 *)(param_2 + 8));
          puVar5 = &LAB_00015864;
          iVar3 = *piVar1;
LAB_000156b0:
          FUN_0001cd4c(puVar5,iVar3,uVar6,puVar4);
          return 0;
        }
        puVar4 = &LAB_00015834;
      }
      else {
        iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&LAB_0001576c);
        if (iVar3 == 0) {
          if (param_1 == 3) {
            cVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
            puVar4 = (undefined *)FUN_000154d0(*piVar1,(int)cVar2);
            uVar6 = FUN_00023590(*(undefined4 *)(param_2 + 8));
            puVar5 = &LAB_000158b8;
            iVar3 = *piVar1;
            goto LAB_000156b0;
          }
          puVar4 = &LAB_00015880;
        }
        else {
          iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&LAB_00015774);
          if (iVar3 == 0) {
            if (param_1 == 3) {
              cVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
              iVar3 = FUN_00015520(*piVar1,(int)cVar2);
              if (iVar3 == 0) {
                puVar4 = &LAB_000157e4;
              }
              else {
                puVar4 = &LAB_000157fc;
              }
              uVar6 = FUN_00023590(*(undefined4 *)(param_2 + 8));
              puVar5 = &LAB_00015910;
              iVar3 = *piVar1;
              goto LAB_000156b0;
            }
            puVar4 = &LAB_000158e0;
          }
          else {
            iVar3 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&LAB_0001577c);
            if (iVar3 == 0) {
              if (param_1 == 3) {
                cVar2 = FUN_00023590(*(undefined4 *)(param_2 + 8));
                iVar3 = FUN_0001554c(*piVar1,(int)cVar2);
                uVar6 = FUN_00023590(*(undefined4 *)(param_2 + 8));
                FUN_0001cd4c(&LAB_0001594c,*piVar1,uVar6,iVar3 / 1000,iVar3 % 1000);
                return 0;
              }
              puVar4 = &LAB_0001592c;
            }
            else {
              puVar4 = &LAB_00015784;
            }
          }
        }
      }
    }
  }
  FUN_0001cd4c(puVar4);
  return 0;
}




undefined4 FUN_00015a76(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_pin____RT_NULL_00015e34,DAT_00015e30 + 10,0x26);
  }
  if ((param_3 != (undefined4 *)0x0) && (param_4 == 8)) {
    (**(code **)(*(int *)(param_1 + 0x40) + 4))(param_1,*param_3,*(undefined *)(param_3 + 1));
    return 8;
  }
  return 0;
}




undefined4 FUN_00015aa6(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_pin____RT_NULL_00015e34,DAT_00015e30 + 0x15,0x37);
  }
  if (param_3 != (undefined4 *)0x0) {
    (***(code ***)(param_1 + 0x40))(param_1,*param_3,*(undefined *)(param_3 + 1));
    return 0;
  }
  return 0xffffff01;
}




undefined4 FUN_00015ad2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00015e44;
  *(undefined *)(DAT_00015e44 + 0x14) = 0x19;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = DAT_00015e48;
  *(undefined4 *)(iVar1 + 0x34) = DAT_00015e4c;
  uVar2 = DAT_00015e50;
  *(undefined4 *)(iVar1 + 0x40) = param_2;
  *(undefined4 *)(iVar1 + 0x38) = uVar2;
  *(undefined4 *)(iVar1 + 0x3c) = param_3;
  FUN_00013452(DAT_00015e44,param_1,3);
  return 0;
}




undefined4 FUN_00015b06(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 0x22,0x6b,param_4,param_4);
  }
  pcVar3 = *(code **)(*(int *)(iVar1 + 0x40) + 0xc);
  if (pcVar3 == (code *)0x0) {
    uVar2 = 0xffffffd3;
  }
  else {
    uVar2 = (*pcVar3)(DAT_00015e44,param_1,param_2,param_3,param_4);
  }
  return uVar2;
}




undefined4 FUN_00015b40(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 0x34,0x75);
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 0x40) + 0x10);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00015b64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(DAT_00015e44,param_1);
    return uVar2;
  }
  return 0xffffffd3;
}




undefined4 FUN_00015b6c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 0x46,0x7f);
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 0x40) + 0x14);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00015b94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(DAT_00015e44,param_1,param_2);
    return uVar2;
  }
  return 0xffffffd3;
}




void FUN_00015b9c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 0x58,0x8a);
  }
                    /* WARNING: Could not recover jumptable at 0x00015bc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (***(code ***)(iVar1 + 0x40))(DAT_00015e44,param_1,param_2);
  return;
}




void FUN_00015bc4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 100,0x90);
  }
                    /* WARNING: Could not recover jumptable at 0x00015bea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(iVar1 + 0x40) + 4))(DAT_00015e44,param_1,param_2);
  return;
}




void FUN_00015bec(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 0x71,0x96);
  }
                    /* WARNING: Could not recover jumptable at 0x00015c0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(iVar1 + 0x40) + 8))(DAT_00015e44,param_1);
  return;
}




undefined4 FUN_00015c10(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 0x7d,0x9d);
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 0x40) + 0x18);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00015c32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(param_1);
    return uVar2;
  }
  return 0xffffffd3;
}




void FUN_00015c3a(void)

{
  FUN_0001cd4c(s_pin__option__GPIO_00015e6c);
  FUN_0001cd4c(s_num__get_pin_number_from_hardwar_00015e80);
  FUN_0001cd4c(DAT_00015eb4);
  FUN_0001cd4c(s_e_g__MSH_>pin_mode_GPIO_output_00015eb8);
  FUN_0001cd4c(s_read__read_pin_level_of_hardware_00015ee8);
  FUN_0001cd4c(s_e_g__MSH_>pin_read_GPIO_00015f18);
  FUN_0001cd4c(DAT_00015f40);
  FUN_0001cd4c(s_e_g__MSH_>pin_write_GPIO_high_00015f44);
  FUN_0001cd4c(s_help__this_help_list_00015f74);
  FUN_0001cd4c(s_GPIO_e_g___00015f94);
  FUN_00015c10(&LAB_00015fa0);
  return;
}




void FUN_00015c80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (3 < param_1) {
    iVar1 = FUN_000194be(*(undefined4 *)(param_2 + 8));
    if (iVar1 == 0) {
      iVar1 = thunk_FUN_00015c10(*(undefined4 *)(param_2 + 8));
      if (iVar1 < 0) {
        FUN_0001cd4c(&LAB_00015fe0,*(undefined4 *)(param_2 + 8));
        goto LAB_00015ce0;
      }
    }
    else {
      iVar1 = FUN_00023590();
    }
    iVar2 = thunk_FUN_0001d05e(&LAB_00015fa4,*(undefined4 *)(param_2 + 0xc));
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      iVar2 = thunk_FUN_0001d05e(&LAB_00015fac,*(undefined4 *)(param_2 + 0xc));
      if (iVar2 == 0) {
        uVar3 = 1;
      }
      else {
        iVar2 = thunk_FUN_0001d05e(&LAB_00015fb4,*(undefined4 *)(param_2 + 0xc));
        if (iVar2 == 0) {
          uVar3 = 2;
        }
        else {
          iVar2 = thunk_FUN_0001d05e(&LAB_00015fc4,*(undefined4 *)(param_2 + 0xc));
          if (iVar2 == 0) {
            uVar3 = 3;
          }
          else {
            iVar2 = thunk_FUN_0001d05e(&LAB_00015fd4,*(undefined4 *)(param_2 + 0xc));
            if (iVar2 != 0) goto LAB_00015ce0;
            uVar3 = 4;
          }
        }
      }
    }
    FUN_00015b9c(iVar1,uVar3);
    return;
  }
LAB_00015ce0:
  FUN_00015c3a();
  return;
}




void FUN_00015d00(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (2 < param_1) {
    iVar1 = thunk_FUN_0001d05e(&LAB_00015ffc,*(undefined4 *)(param_2 + 4));
    if (iVar1 == 0) {
      iVar1 = thunk_FUN_00015c10(*(undefined4 *)(param_2 + 8));
      if (-1 < iVar1) {
        FUN_0001cd4c(&LAB_00016034,*(undefined4 *)(param_2 + 8));
        return;
      }
      FUN_0001cd4c(&LAB_00016018,*(undefined4 *)(param_2 + 8));
    }
    else {
      iVar1 = thunk_FUN_0001d05e(&LAB_00016000,*(undefined4 *)(param_2 + 4));
      if (iVar1 == 0) {
        FUN_00015c80(param_1,param_2);
        return;
      }
      iVar1 = thunk_FUN_0001d05e(&LAB_00016008,*(undefined4 *)(param_2 + 4));
      if (iVar1 == 0) {
        FUN_00015d7a(param_1,param_2);
        return;
      }
      iVar1 = thunk_FUN_0001d05e(&LAB_00016010,*(undefined4 *)(param_2 + 4));
      if (iVar1 == 0) {
        if (3 < param_1) {
          iVar1 = FUN_000194be(*(undefined4 *)(param_2 + 8));
          if (iVar1 == 0) {
            iVar1 = thunk_FUN_00015c10(*(undefined4 *)(param_2 + 8));
            if (iVar1 < 0) {
              FUN_0001cd4c(&LAB_00016018,*(undefined4 *)(param_2 + 8));
              goto LAB_00015e1c;
            }
          }
          else {
            iVar1 = FUN_00023590();
          }
          iVar2 = thunk_FUN_0001d05e(&LAB_00016060,*(undefined4 *)(param_2 + 0xc));
          if ((iVar2 == 0) ||
             (iVar2 = thunk_FUN_0001d05e(&LAB_00016068,*(undefined4 *)(param_2 + 0xc)), iVar2 == 0))
          {
            uVar3 = 1;
          }
          else {
            iVar2 = thunk_FUN_0001d05e(&LAB_0001606c,*(undefined4 *)(param_2 + 0xc));
            if ((iVar2 != 0) &&
               (iVar2 = thunk_FUN_0001d05e(&LAB_00016070,*(undefined4 *)(param_2 + 0xc)), iVar2 != 0
               )) goto LAB_00015e1c;
            uVar3 = 0;
          }
          FUN_00015bc4(iVar1,uVar3);
          return;
        }
LAB_00015e1c:
        FUN_00015c3a();
        return;
      }
    }
  }
  FUN_00015c3a();
  return;
}




undefined4 thunk_FUN_00015c10(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = DAT_00015e44;
  if (*(int *)(DAT_00015e44 + 0x40) == 0) {
    FUN_0001cdc6(s__hw_pin_ops____RT_NULL_00015e54,DAT_00015e30 + 0x7d,0x9d);
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 0x40) + 0x18);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00015c32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(param_1);
    return uVar2;
  }
  return 0xffffffd3;
}




void FUN_00015d7a(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  
  if (param_1 < 3) {
LAB_00015d82:
    FUN_00015c3a();
    return;
  }
  iVar2 = FUN_000194be(*(undefined4 *)(param_2 + 8));
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_00015c10(*(undefined4 *)(param_2 + 8));
    if (iVar2 < 0) {
      FUN_0001cd4c(&LAB_00016018,*(undefined4 *)(param_2 + 8));
      goto LAB_00015d82;
    }
  }
  else {
    iVar2 = FUN_00023590();
  }
  cVar1 = FUN_00015bec();
  if (cVar1 == '\x01') {
    puVar3 = &LAB_00016050;
  }
  else {
    puVar3 = &LAB_00016040;
  }
  FUN_0001cd4c(puVar3,iVar2);
  return;
}




undefined4 FUN_0001609c(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  int local_30 [2];
  undefined4 local_28;
  
  FUN_00023966(local_30,0x18);
  if (param_2 < 1) {
    param_2 = -param_2;
  }
  if (**(code ***)(param_1 + 0x40) != (code *)0x0) {
    local_30[0] = param_2;
    iVar1 = (***(code ***)(param_1 + 0x40))(param_1,0x1e03,local_30);
    if (iVar1 == 0) {
      *param_3 = local_28;
    }
    else {
      param_4 = 0;
    }
  }
  return param_4;
}




undefined4 FUN_000160d8(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  int local_30 [2];
  undefined4 local_28;
  
  FUN_00023966(local_30,0x18);
  if (param_2 < 1) {
    param_2 = -param_2;
  }
  if (**(code ***)(param_1 + 0x40) != (code *)0x0) {
    local_30[0] = param_2;
    iVar1 = (***(code ***)(param_1 + 0x40))(param_1,0x1e03,local_30);
    if (iVar1 == 0) {
      local_28 = *param_3;
      iVar1 = (***(code ***)(param_1 + 0x40))(param_1,0x1e02,local_30);
      if (iVar1 == 0) {
        return param_4;
      }
    }
    param_4 = 0;
  }
  return param_4;
}




void FUN_00016122(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0001ce98(param_1,0,0x44);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = DAT_00016538;
  *(undefined4 *)(param_1 + 0x34) = DAT_0001653c;
  *(undefined4 *)(param_1 + 0x38) = DAT_00016540;
  *(undefined *)(param_1 + 0x14) = 0x1d;
  *(undefined4 *)(param_1 + 0x3c) = param_4;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  FUN_00013452(param_1,param_2,3);
  return;
}




undefined4 FUN_00016160(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_28 [7];
  
  FUN_00023966(local_28,0x18);
  if (param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (param_2 < 1) {
      local_28[0] = -param_2;
      uVar1 = 0x1e04;
    }
    else {
      uVar1 = 0x1e05;
      local_28[0] = param_2;
    }
    FUN_0001376a(param_1,uVar1,local_28);
    uVar1 = FUN_0001376a(param_1,0x1e00,local_28);
  }
  return uVar1;
}




undefined4 FUN_000161a8(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_28 [7];
  
  FUN_00023966(local_28,0x18);
  if (param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (param_2 < 1) {
      local_28[0] = -param_2;
      uVar1 = 0x1e04;
    }
    else {
      uVar1 = 0x1e05;
      local_28[0] = param_2;
    }
    FUN_0001376a(param_1,uVar1,local_28);
    uVar1 = FUN_0001376a(param_1,0x1e01,local_28);
  }
  return uVar1;
}




undefined4 FUN_000161ee(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  
  FUN_00023966(&local_30,0x18);
  if (param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    local_30 = param_2;
    uStack_2c = param_3;
    local_28 = param_4;
    uVar1 = FUN_0001376a(param_1,0x1e02,&local_30);
  }
  return uVar1;
}




undefined4 FUN_00016224(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_28;
  undefined4 uStack_24;
  
  FUN_00023966(&local_28,0x18);
  if (param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    local_28 = param_2;
    uStack_24 = param_3;
    uVar1 = FUN_0001376a(param_1,0x1e06,&local_28);
  }
  return uVar1;
}




undefined4 FUN_00016258(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_28 [2];
  undefined4 local_20;
  
  FUN_00023966(local_28,0x18);
  if (param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    local_28[0] = param_2;
    local_20 = param_3;
    uVar1 = FUN_0001376a(param_1,0x1e07,local_28);
  }
  return uVar1;
}




undefined4 FUN_0001628a(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_28 [3];
  undefined4 local_1c;
  
  FUN_00023966(local_28,0x18);
  if (param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    local_28[0] = param_2;
    local_1c = param_3;
    uVar1 = FUN_0001376a(param_1,0x1e08,local_28);
  }
  return uVar1;
}




undefined4 FUN_000162bc(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_28 [4];
  undefined4 local_18;
  
  FUN_00023966(local_28,0x18);
  if (param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    local_28[0] = param_2;
    local_18 = param_3;
    uVar1 = FUN_0001376a(param_1,0x1e09,local_28);
  }
  return uVar1;
}




undefined4 FUN_000162ee(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_0001376a(param_1,0x1e03,param_2);
    return uVar1;
  }
  return 0xfffffff4;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00016300(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  FUN_00023966(&local_38,0x18);
  if (param_1 < 2) {
    FUN_0001cd4c(s_Usage__0001657c);
    FUN_0001cd4c(s_pwm_probe_<device_name>___probe_p_000168bc);
    FUN_0001cd4c(DAT_000168fc);
    FUN_0001cd4c(DAT_00016900);
    FUN_0001cd4c(DAT_00016904);
    FUN_0001cd4c(DAT_00016908);
    FUN_0001cd4c(s_pwm_phase_<channel>_<phase>___se_0001690c);
    pcVar6 = s_pwm_dead_time_<channel>_<dead_ti_00016948;
  }
  else {
    iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_probe_00016544);
    piVar1 = _DAT_0001654c;
    if (iVar2 == 0) {
      if (param_1 == 3) {
        iVar2 = FUN_0001344c(*(undefined4 *)(param_2 + 8));
        *piVar1 = iVar2;
        if (iVar2 == 0) {
          pcVar6 = s_failure_00016638;
        }
        else {
          pcVar6 = s_success_00016620;
        }
        pcVar7 = s_probe__s__s_00016628;
        iVar2 = *(int *)(param_2 + 8);
        goto LAB_00016882;
      }
      pcVar6 = s_pwm_probe_<device_name>___probe_p_000165e0;
    }
    else {
      if (*_DAT_0001654c == 0) {
        FUN_0001cd4c(s_Please_using__pwm_probe_<device_n_00016640);
        return 0xffffff01;
      }
      iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_enable_0001654f + 1);
      if (iVar2 == 0) {
        if (param_1 == 3) {
          uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 8));
          iVar2 = FUN_00016160(*piVar1,uVar4);
          if (iVar2 == 0) {
            pcVar6 = s_success_00016620;
          }
          else {
            pcVar6 = s_failure_00016638;
          }
          uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 8));
          FUN_0001cd4c(s__s_channel__d_is_enabled__s_000166f0,*piVar1,uVar4,pcVar6);
          return 0;
        }
        FUN_0001cd4c(s_pwm_enable_<channel>___enable_pw_00016670);
        FUN_0001cd4c(s_e_g__MSH_>pwm_enable_1___PWM_CH1_000166b0);
        pcVar6 = DAT_000166ec;
      }
      else {
        iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_disable_00016558);
        if (iVar2 != 0) {
          iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_00016560);
          if (iVar2 == 0) {
            local_38 = FUN_00023590(*(undefined4 *)(param_2 + 8));
            iVar2 = FUN_000162ee(*piVar1,&local_38);
            if (iVar2 == 0) {
              uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 8));
              FUN_0001cd4c(s_Info_of_device___s__channel___d__00016774,*piVar1,uVar4);
              FUN_0001cd4c(s_period____d_00016798,local_34);
              FUN_0001cd4c(s_pulse____d_000167ac,local_30);
              uVar8 = FUN_00026048(local_34);
              uVar9 = FUN_00026048(local_30);
              uVar8 = FUN_00025c38((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar8,
                                   (int)((ulonglong)uVar8 >> 0x20));
              FUN_000260e8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)_DAT_000167c0,
                           (int)((ulonglong)_DAT_000167c0 >> 0x20));
              iVar2 = FUN_00025f60();
              pcVar6 = s_Y_Duty_cycle____d___000167c6 + 2;
            }
            else {
              pcVar6 = s_Get_info_of_device____s__error__00016750;
              iVar2 = *piVar1;
            }
            FUN_0001cd4c(pcVar6,iVar2);
            return 0;
          }
          iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),&DAT_00016564);
          if (iVar2 == 0) {
            if (param_1 != 5) {
              FUN_0001cd4c(s_Set_info_of_device____s__error_000167dc,*piVar1);
              pcVar6 = s_Usage__pwm_set_<channel>_<period_000167fc;
              goto LAB_000163a4;
            }
            uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 0x10));
            uVar5 = FUN_00023590(*(undefined4 *)(param_2 + 0xc));
            uVar3 = FUN_00023590(*(undefined4 *)(param_2 + 8));
            FUN_000161ee(*piVar1,uVar3,uVar5,uVar4);
            pcVar6 = (char *)FUN_00023590(*(undefined4 *)(param_2 + 8));
            pcVar7 = s_pwm_info_set_on__s_at_channel__d_00016828;
            iVar2 = *piVar1;
          }
          else {
            iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_phase_00016568);
            if (iVar2 == 0) {
              if (param_1 != 4) {
                return 0;
              }
              uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 0xc));
              uVar5 = FUN_00023590(*(undefined4 *)(param_2 + 8));
              FUN_000162bc(*piVar1,uVar5,uVar4);
              pcVar6 = (char *)FUN_00023590(*(undefined4 *)(param_2 + 0xc));
              pcVar7 = s__s_phase_is_set__d_0001684c;
              iVar2 = *piVar1;
            }
            else {
              iVar2 = FUN_00023a0c(*(undefined4 *)(param_2 + 4),s_dead_time_00016570);
              if (iVar2 != 0) {
                FUN_0001cd4c(s_Usage__0001657c);
                FUN_0001cd4c(DAT_00016588);
                FUN_0001cd4c(DAT_0001658c);
                FUN_0001cd4c(DAT_00016590);
                FUN_0001cd4c(DAT_00016594);
                FUN_0001cd4c(DAT_00016598);
                FUN_0001cd4c(s_pwm_phase_<channel>_<phase>___se_0001659c);
                pcVar6 = DAT_000165dc;
                goto LAB_000163a4;
              }
              if (param_1 != 4) {
                return 0;
              }
              uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 0xc));
              uVar5 = FUN_00023590(*(undefined4 *)(param_2 + 8));
              FUN_0001628a(*piVar1,uVar5,uVar4);
              pcVar6 = (char *)FUN_00023590(*(undefined4 *)(param_2 + 0xc));
              pcVar7 = s__s_dead_time_is_set__d_00016864;
              iVar2 = *piVar1;
            }
          }
LAB_00016882:
          FUN_0001cd4c(pcVar7,iVar2,pcVar6);
          return 0;
        }
        if (param_1 == 3) {
          uVar4 = FUN_00023590(*(undefined4 *)(param_2 + 8));
          FUN_000161a8(*piVar1,uVar4);
          return 0;
        }
        pcVar6 = s_pwm_disable_<channel>___disable_p_00016710;
      }
    }
  }
LAB_000163a4:
  FUN_0001cd4c(pcVar6);
  return 0;
}




void FUN_00016988(void)

{
  int *piVar1;
  
  piVar1 = DAT_00016d68;
  if (*DAT_00016d68 == 0) {
    FUN_0001cd4c(&DAT_00016d6c);
    FUN_0001cd4c(DAT_00016d7c);
    FUN_0001cd4c(&DAT_00016d80);
    *piVar1 = 1;
  }
  return;
}




uint FUN_000169aa(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4c);
  if (iVar3 == 0) {
    FUN_0001cdc6(s_rx_fifo____RT_NULL_00016d8c,DAT_00016d88,0x193);
  }
  uVar2 = (uint)*(ushort *)(iVar3 + 4);
  uVar1 = (uint)*(ushort *)(iVar3 + 6);
  if (uVar2 == uVar1) {
    uVar1 = *(uint *)(iVar3 + 8);
    if (uVar1 != 0) {
      uVar1 = (uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10;
    }
    return uVar1;
  }
  if (uVar2 <= uVar1) {
    uVar1 = uVar1 - uVar2;
    uVar2 = (uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10;
  }
  return uVar2 - uVar1;
}




int FUN_000169e6(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_0001cdc6(s__serial____RT_NULL______data____R_00016da0,DAT_00016d88 + 0x57,0x201);
  }
  uVar1 = FUN_00012db4();
  if ((*(uint *)(param_1 + 0x48) & DAT_00016dcc) == 0) {
    piVar6 = *(int **)(param_1 + 0x4c);
    if (piVar6 == (int *)0x0) {
      FUN_0001cdc6(s_rx_dma____RT_NULL_00016dd0,DAT_00016d88 + 0x57,0x20b);
    }
    if (*piVar6 == 1) {
      FUN_00012dbc(uVar1);
      FUN_0001ce66(0xffffffe9);
      param_3 = 0;
    }
    else {
      *piVar6 = 1;
      if (*(int *)(*(int *)(param_1 + 0x40) + 0x10) == 0) {
        FUN_0001cdc6(s_serial_>ops_>dma_transmit____RT__00016de4,DAT_00016d88 + 0x57,0x210);
      }
      (**(code **)(*(int *)(param_1 + 0x40) + 0x10))(param_1,param_2,param_3,1);
      FUN_00012dbc(uVar1);
    }
  }
  else {
    piVar6 = *(int **)(param_1 + 0x4c);
    iVar2 = FUN_000169aa(param_1);
    if (piVar6 == (int *)0x0) {
      FUN_0001cdc6(s_rx_fifo____RT_NULL_00016d8c,DAT_00016d88 + 0x57,0x220);
    }
    if (param_3 < iVar2) {
      iVar2 = param_3;
    }
    param_3 = iVar2;
    uVar3 = (uint)*(ushort *)((int)piVar6 + 6);
    uVar4 = (uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10;
    if (uVar3 + param_3 < uVar4) {
      iVar5 = *piVar6 + uVar3;
      iVar2 = param_3;
    }
    else {
      FUN_0001ceee(param_2,*piVar6 + uVar3,uVar4 - uVar3);
      uVar3 = (uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10;
      iVar2 = ((uint)*(ushort *)((int)piVar6 + 6) + param_3) - uVar3;
      param_2 = (uVar3 + param_2) - (uint)*(ushort *)((int)piVar6 + 6);
      iVar5 = *piVar6;
    }
    FUN_0001ceee(param_2,iVar5,iVar2);
    FUN_00017426(param_1,param_3);
    FUN_00012dbc(uVar1);
  }
  return param_3;
}




void FUN_00017118(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_serial____RT_NULL_0001726c,DAT_00017268 + 0x41,0x512);
  }
  *(undefined *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = DAT_00017280;
  *(undefined4 *)(param_1 + 0x28) = DAT_00017284;
  *(undefined4 *)(param_1 + 0x2c) = DAT_00017288;
  *(undefined4 *)(param_1 + 0x30) = DAT_0001728c;
  *(undefined4 *)(param_1 + 0x34) = DAT_00017290;
  *(undefined4 *)(param_1 + 0x38) = DAT_00017294;
  *(undefined4 *)(param_1 + 0x3c) = param_4;
  FUN_00013452(param_1,param_2,param_3);
  return;
}




void FUN_00017164(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  ushort uVar2;
  int **ppiVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint extraout_r1;
  uint uVar9;
  undefined4 *puVar10;
  uint local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  
  local_28 = param_2;
  uStack_24 = param_3;
  local_20 = param_4;
  switch(param_2 & 0xff) {
  case 1:
    piVar5 = *(int **)(param_1 + 0x4c);
    if (piVar5 == (int *)0x0) {
      FUN_0001cdc6(s_rx_fifo____RT_NULL_00016d8c,DAT_00017268 + 0x57,0x53e);
    }
    while (iVar6 = (**(code **)(*(int *)(param_1 + 0x40) + 0xc))(param_1), iVar6 != -1) {
      uVar7 = FUN_00012db4();
      *(char *)(*piVar5 + (uint)*(ushort *)(piVar5 + 1)) = (char)iVar6;
      sVar1 = *(short *)(piVar5 + 1);
      *(ushort *)(piVar5 + 1) = sVar1 + 1U;
      if ((uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10 <= (uint)(ushort)(sVar1 + 1U)) {
        *(undefined2 *)(piVar5 + 1) = 0;
      }
      if (*(short *)(piVar5 + 1) == *(short *)((int)piVar5 + 6)) {
        uVar2 = *(short *)((int)piVar5 + 6) + 1;
        *(ushort *)((int)piVar5 + 6) = uVar2;
        piVar5[2] = 1;
        if ((uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10 <= (uint)uVar2) {
          *(undefined2 *)((int)piVar5 + 6) = 0;
        }
        FUN_00016988();
      }
      FUN_00012dbc(uVar7);
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      uVar7 = FUN_00012db4();
      uVar4 = (uint)*(ushort *)(piVar5 + 1);
      uVar9 = (uint)*(ushort *)((int)piVar5 + 6);
      if (uVar4 < uVar9) {
        iVar6 = ((uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10) - (uVar9 - uVar4);
      }
      else {
        iVar6 = uVar4 - uVar9;
      }
      FUN_00012dbc(uVar7);
      if (iVar6 != 0) {
        (**(code **)(param_1 + 0x1c))(param_1,iVar6);
      }
    }
    if (*(code **)(param_1 + 0x54) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001722a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(param_1 + 0x54))(*(undefined4 *)(param_1 + 0x58));
      return;
    }
    break;
  case 2:
    piVar5 = *(int **)(param_1 + 0x50);
    if (piVar5 == (int *)0x0) {
      FUN_0001cdc6(s_completion____RT_NULL_000147b8,DAT_000147b4 + 0x26,0x81,param_4);
      param_2 = extraout_r1;
    }
    if (*piVar5 != 1) {
      uVar7 = FUN_00012db4(*piVar5,param_2);
      *piVar5 = 1;
      ppiVar3 = (int **)piVar5[1];
      if (ppiVar3 != (int **)(piVar5 + 1)) {
        FUN_0001e4e2(ppiVar3 + -5);
        FUN_00012dbc(uVar7);
        FUN_0001e128();
        return;
      }
      FUN_00012dbc(uVar7);
      return;
    }
    return;
  case 3:
    if ((*(uint *)(param_1 + 0x48) & DAT_000174f4) == 0) {
      puVar10 = *(undefined4 **)(param_1 + 0x4c);
      if (puVar10 == (undefined4 *)0x0) {
        FUN_0001cdc6(s_rx_dma____RT_NULL_00016dd0,DAT_000174f8,0x5a4);
      }
      if (*(int *)(param_1 + 0x1c) == 0) {
        FUN_0001cdc6(s_serial_>parent_rx_indicate____RT_000174fc,DAT_000174f8,0x5a6);
      }
      (**(code **)(param_1 + 0x1c))(param_1,(int)param_2 >> 8);
      *puVar10 = 0;
    }
    else {
      uVar7 = FUN_00012db4();
      FUN_00017480(param_1,(int)param_2 >> 8);
      uVar8 = FUN_000169aa(param_1);
      FUN_00012dbc(uVar7);
      if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000172e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(param_1 + 0x1c))(param_1,uVar8);
        return;
      }
    }
    break;
  case 4:
    puVar10 = *(undefined4 **)(param_1 + 0x50);
    FUN_00014b3e(puVar10 + 1,&local_20,&local_28,0);
    iVar6 = FUN_00014e78(puVar10 + 1,&uStack_24,&local_28);
    if (iVar6 == 0) {
      *puVar10 = 1;
      (**(code **)(*(int *)(param_1 + 0x40) + 0x10))(param_1,uStack_24,local_28,2);
    }
    else {
      *puVar10 = 0;
    }
    if (*(code **)(param_1 + 0x20) != (code *)0x0) {
      (**(code **)(param_1 + 0x20))(param_1,local_20);
    }
  }
  return;
}




int FUN_00017314(int param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_serial____RT_NULL_0001726c,DAT_000174f8 + -0xf9,0x130);
  }
  piVar4 = *(int **)(param_1 + 0x4c);
  iVar5 = param_3;
  if (piVar4 == (int *)0x0) {
    FUN_0001cdc6(s_rx_fifo____RT_NULL_00016d8c,DAT_000174f8 + -0xf9,0x134);
  }
  do {
    if (iVar5 == 0) {
LAB_0001739c:
      return param_3 - iVar5;
    }
    uVar2 = FUN_00012db4();
    uVar3 = (uint)*(ushort *)((int)piVar4 + 6);
    if ((uVar3 == *(ushort *)(piVar4 + 1)) && (piVar4[2] == 0)) {
      FUN_00012dbc(uVar2);
      goto LAB_0001739c;
    }
    uVar1 = *(undefined *)(*piVar4 + uVar3);
    *(short *)((int)piVar4 + 6) = (short)(uVar3 + 1);
    if ((uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10 <= (uVar3 + 1 & 0xffff)) {
      *(undefined2 *)((int)piVar4 + 6) = 0;
    }
    if (piVar4[2] == 1) {
      piVar4[2] = 0;
    }
    FUN_00012dbc(uVar2);
    *param_2 = uVar1;
    iVar5 = iVar5 + -1;
    param_2 = param_2 + 1;
  } while( true );
}




int FUN_000173a4(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_serial____RT_NULL_0001726c,DAT_000174f8 + -0xea,0x160);
  }
  iVar3 = *(int *)(param_1 + 0x50);
  iVar2 = param_3;
  if (iVar3 == 0) {
    FUN_0001cdc6(s_tx____RT_NULL_00017524,DAT_000174f8 + -0xea,0x164);
  }
  while (iVar2 != 0) {
    if (((*param_2 == '\n') && ((int)((uint)*(byte *)(param_1 + 0x18) << 0x19) < 0)) &&
       (iVar1 = (**(code **)(*(int *)(param_1 + 0x40) + 8))(param_1,0xd), iVar1 == -1)) {
      FUN_00014604(iVar3,0xffffffff);
    }
    else {
      while (iVar1 = (**(code **)(*(int *)(param_1 + 0x40) + 8))(param_1,*param_2), iVar1 == -1) {
        FUN_00014604(iVar3,0xffffffff);
      }
      iVar2 = iVar2 + -1;
      param_2 = param_2 + 1;
    }
  }
  return param_3;
}




void FUN_00017426(int param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x4c);
  if (iVar5 == 0) {
    FUN_0001cdc6(s_rx_fifo____RT_NULL_00016d8c,DAT_000174f8 + -0xbe,0x1be);
  }
  uVar2 = FUN_000169aa(param_1);
  if (uVar2 < param_2) {
    FUN_0001cdc6(s_len_<__rt_dma_calc_recved_len(se_00017534,DAT_000174f8 + -0xbe,0x1bf);
  }
  if ((*(int *)(iVar5 + 8) != 0) && (param_2 != 0)) {
    *(undefined4 *)(iVar5 + 8) = 0;
  }
  param_2 = *(ushort *)(iVar5 + 6) + param_2;
  uVar4 = param_2 & 0xffff;
  sVar1 = (short)param_2;
  *(short *)(iVar5 + 6) = sVar1;
  uVar2 = *(int *)(param_1 + 0x48) << 6;
  uVar3 = uVar2 >> 0x10;
  if (uVar3 <= uVar4) {
    *(short *)(iVar5 + 6) = sVar1 - (short)(uVar2 >> 0x10) * (short)(uVar4 / uVar3);
  }
  return;
}




void FUN_00017480(int param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x4c);
  if (iVar5 == 0) {
    FUN_0001cdc6(s_rx_fifo____RT_NULL_00016d8c,DAT_000174f8 + -0xa1,0x1d4);
  }
  uVar4 = (uint)*(ushort *)(iVar5 + 6);
  uVar2 = (uint)*(ushort *)(iVar5 + 4) + param_2;
  sVar1 = (short)uVar2;
  if (*(ushort *)(iVar5 + 4) < uVar4) {
    uVar2 = uVar2 & 0xffff;
    *(short *)(iVar5 + 4) = sVar1;
    if (uVar4 <= uVar2) {
      uVar4 = *(int *)(param_1 + 0x48) << 6;
      uVar3 = uVar4 >> 0x10;
      if (uVar3 <= uVar2) {
        *(short *)(iVar5 + 4) = sVar1 - (short)(uVar4 >> 0x10) * (short)(uVar2 / uVar3);
      }
      goto LAB_000174c2;
    }
  }
  else {
    uVar2 = uVar2 & 0xffff;
    *(short *)(iVar5 + 4) = sVar1;
    uVar3 = (uint)(*(int *)(param_1 + 0x48) << 6) >> 0x10;
    if ((uVar3 <= uVar2) &&
       (uVar2 = uVar2 - uVar3 * (uVar2 / uVar3), *(short *)(iVar5 + 4) = (short)uVar2,
       uVar4 <= uVar2)) {
LAB_000174c2:
      *(undefined4 *)(iVar5 + 8) = 1;
      goto LAB_000174ea;
    }
  }
  if (*(int *)(iVar5 + 8) != 1) {
    return;
  }
LAB_000174ea:
  FUN_00016988();
  *(undefined2 *)(iVar5 + 6) = *(undefined2 *)(iVar5 + 4);
  return;
}




/* WARNING: Removing unreachable block (ram,0x000175f0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000175d2(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 * (*DAT_0001761c / DAT_0001763c);
  do {
  } while (_DAT_e000e014 <= uVar1 && uVar1 - _DAT_e000e014 != 0);
  return;
}




short * FUN_00017810(uint param_1)

{
  short *psVar1;
  
  if ((0x6f < param_1) || (psVar1 = (short *)(DAT_00017b2c + param_1 * 0x10), *psVar1 == -1)) {
    psVar1 = (short *)0x0;
  }
  return psVar1;
}




void FUN_00017826(undefined4 param_1,undefined param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00017810(param_2);
  if (iVar1 != 0) {
    FUN_0001fb24(*(undefined2 *)(iVar1 + 2));
    uVar2 = 0x10;
    switch(param_3) {
    case 1:
      uVar2 = 4;
      break;
    case 2:
      uVar2 = 0x48;
      break;
    case 3:
      uVar2 = 0x28;
      break;
    case 4:
      uVar2 = 0x14;
    }
    FUN_00020448(*(undefined4 *)(iVar1 + 4),uVar2,3,*(undefined4 *)(iVar1 + 8));
    return;
  }
  return;
}




void FUN_00017868(undefined4 param_1,undefined param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_00017810(param_2);
  if (iVar1 == 0) {
    return;
  }
  if (param_3 != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 4) + 0x10) = *(undefined4 *)(iVar1 + 8);
    return;
  }
  *(undefined4 *)(*(int *)(iVar1 + 4) + 0x14) = *(undefined4 *)(iVar1 + 8);
  return;
}




int FUN_00017882(undefined4 param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = FUN_00017810(param_2 & 0xff,param_2,0);
  if (iVar2 != 0) {
    cVar1 = FUN_00020504(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 8));
    return (int)cVar1;
  }
  return iVar3;
}




undefined4 FUN_0001789e(undefined4 param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_00017810(param_2 & 0xff);
  uVar4 = 0xfffffffb;
  if (((iVar1 != 0) && (uVar2 = FUN_00017b0e(*(undefined4 *)(iVar1 + 8)), -1 < (int)uVar2)) &&
     (uVar2 < 0x10)) {
    uVar4 = FUN_00012db4();
    puVar3 = (uint *)(DAT_00017b30 + uVar2 * 0x10);
    if (((*puVar3 != param_2) || (puVar3[2] != param_4)) ||
       ((*(byte *)(puVar3 + 1) != param_3 || (puVar3[3] != param_5)))) {
      if (*puVar3 != 0xffffffff) {
        FUN_00012dbc(uVar4);
        return 0xffffffdd;
      }
      puVar3[2] = param_4;
      *puVar3 = param_2;
      *(char *)(puVar3 + 1) = (char)param_3;
      puVar3[3] = param_5;
    }
    FUN_00012dbc(uVar4);
    uVar4 = 0;
  }
  return uVar4;
}




uint FUN_00017b0e(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (1 << uVar1 == param_1) {
      return uVar1;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x20);
  return 0xffffffff;
}




undefined4 FUN_00017d2c(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = DAT_00018108;
  uVar4 = 0;
  iVar6 = DAT_00018108 + -0x1e0;
  while( true ) {
    uVar2 = 0;
    while (*(int *)(iVar1 + uVar2 * 4) != 0) {
      uVar2 = (uint)(short)((short)uVar2 + 1);
      if (6 < uVar2) goto LAB_00017d50;
    }
    if (6 < uVar2) break;
    iVar5 = iVar6 + uVar4 * 0x60;
    for (uVar3 = 0;
        ((int)uVar3 < (int)uVar2 && (*(int *)(iVar5 + 0x48) != *(int *)(iVar1 + uVar3 * 4)));
        uVar3 = (uint)(short)((short)uVar3 + 1)) {
    }
    if (uVar3 == uVar2) {
      *(undefined4 *)(iVar1 + uVar2 * 4) = *(undefined4 *)(iVar5 + 0x48);
    }
    uVar4 = (uint)(short)((short)uVar4 + 1);
    if (4 < uVar4) {
LAB_00017d94:
      uVar4 = 0;
      while( true ) {
        uVar2 = 0;
        while (*(char *)(iVar1 + uVar2 + 0x1c) != -1) {
          uVar2 = (uint)(short)((short)uVar2 + 1);
          if (0xd < uVar2) goto LAB_00017db0;
        }
        if (0xd < uVar2) break;
        iVar5 = iVar6 + uVar4 * 0x60;
        for (uVar3 = 0;
            ((int)uVar3 < (int)uVar2 && (*(char *)(iVar5 + 0x44) != *(char *)(iVar1 + uVar3 + 0x1c))
            ); uVar3 = (uint)(short)((short)uVar3 + 1)) {
        }
        if (uVar3 == uVar2) {
          *(undefined *)(uVar2 + iVar1 + 0x1c) = *(undefined *)(iVar5 + 0x44);
        }
        uVar4 = (uint)(short)((short)uVar4 + 1);
        if (4 < uVar4) {
          return 0;
        }
      }
LAB_00017db0:
      FUN_0001cd4c(&DAT_0001810c);
      FUN_0001cd4c(s_Can_not_find__1_of_gd32_periph_l_0001815c);
      FUN_0001cd4c(&DAT_00018154);
      return 0;
    }
  }
LAB_00017d50:
  FUN_0001cd4c(&DAT_0001810c);
  FUN_0001cd4c(s_Can_not_find__1_of_gd32_periph_l_0001811c);
  FUN_0001cd4c(&DAT_00018154);
  goto LAB_00017d94;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00017e00(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0001819c;
  switch(param_1) {
  case 0:
    break;
  case 1:
    return 0x40000000;
  case 2:
    return DAT_000181a0;
  case 3:
    return DAT_000181a4;
  case 4:
    return DAT_000181a8;
  case 5:
    return DAT_000181ac;
  case 6:
    return DAT_000181b0;
  case 7:
    return DAT_000181b4;
  case 8:
    return DAT_000181b8;
  case 9:
    return DAT_000181bc;
  case 10:
    return DAT_000181c0;
  case 0xb:
    return DAT_000181c4;
  case 0xc:
    return DAT_000181c8;
  case 0xd:
    return _DAT_000181cc;
  default:
    FUN_0001cd4c(&DAT_0001810c);
    FUN_0001cd4c(s__Unsport_timer_periph__000181cf + 1);
    FUN_0001cd4c(&DAT_00018154);
  }
  return uVar1;
}




void FUN_00017e6a(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = DAT_000181e8;
  uVar4 = 0;
  do {
    iVar3 = iVar1 + uVar4 * 0x60;
    uVar2 = FUN_00017e00((int)*(char *)(iVar3 + 0x44));
    FUN_00020a04(uVar2,*(undefined2 *)(iVar3 + 0x50),param_1);
    FUN_00020c3a(uVar2,*(undefined2 *)(iVar3 + 0x50),7999);
    FUN_00020bec(uVar2,*(undefined2 *)(iVar3 + 0x50),0x60);
    FUN_00020c58(uVar2,*(undefined2 *)(iVar3 + 0x50),0);
    FUN_00020dca(uVar2,*(undefined2 *)(iVar3 + 0x50),0);
    iVar3 = DAT_00018108;
    uVar4 = (uint)(short)((short)uVar4 + 1);
  } while (uVar4 < 5);
  uVar4 = 0;
  do {
    if (*(char *)(iVar3 + uVar4 + 0x1c) != -1) {
      FUN_00017e00();
      FUN_00020824();
    }
    uVar4 = (uint)(short)((short)uVar4 + 1);
  } while (uVar4 < 0xe);
  return;
}




undefined4 FUN_00017ee4(char *param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = (int)*param_1;
  if (param_3 == 0) {
    uVar3 = FUN_00017e00(iVar2);
    FUN_00020dca(uVar3,*param_2,0);
    uVar3 = FUN_00017e00((int)*param_1);
    FUN_00020e18(uVar3,*param_2,0);
  }
  else {
    if (*(int *)(param_1 + 0x14) == 0) {
      uVar3 = FUN_00017e00(iVar2);
      FUN_00020dca(uVar3,*param_2,1);
      uVar3 = FUN_00017e00((int)*param_1);
      uVar1 = *param_2;
      uVar4 = 0;
    }
    else {
      uVar3 = FUN_00017e00(iVar2);
      FUN_00020dca(uVar3,*param_2,0);
      uVar3 = FUN_00017e00((int)*param_1);
      uVar1 = *param_2;
      uVar4 = 4;
    }
    FUN_00020e18(uVar3,uVar1,uVar4);
    uVar3 = FUN_00017e00((int)*param_1);
    FUN_000209b4(uVar3,1);
  }
  return 0;
}




undefined4 FUN_00017f66(char *param_1,undefined2 *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  
  FUN_00020448(*(undefined4 *)(param_1 + 4),0x18,3,*(undefined4 *)(param_1 + 8));
  if (param_1[0x18] == '\x01') {
    uVar2 = 0x1000;
  }
  else {
    uVar2 = DAT_000181ec;
    if (param_1[0x18] != '\x02') goto LAB_00017f94;
  }
  FUN_00020524(uVar2,1);
LAB_00017f94:
  uVar2 = FUN_0001fe1a(0);
  uVar7 = FUN_000231a0(uVar2,0,DAT_000181f0,0);
  iVar5 = (int)(uVar7 >> 0x20);
  lVar1 = (ulonglong)*(uint *)(param_2 + 2) * (uVar7 & 0xffffffff);
  uVar3 = FUN_000231a0((int)lVar1,*(uint *)(param_2 + 2) * iVar5 + (int)((ulonglong)lVar1 >> 0x20),
                       1000,0);
  iVar6 = uVar3 / 0xffff + 1;
  uVar4 = FUN_000231a0(uVar3,0,iVar6,0);
  uVar2 = FUN_00017e00((int)*param_1);
  FUN_00020884(uVar2,uVar3 / 0xffff & 0xffff,0);
  if (uVar4 < 3) {
    uVar4 = 3;
  }
  uVar2 = FUN_00017e00((int)*param_1);
  FUN_00020898(uVar2,uVar4 - 1 & 0xffff);
  lVar1 = (ulonglong)*(uint *)(param_2 + 4) * (uVar7 & 0xffffffff);
  uVar8 = FUN_000231a0((int)lVar1,*(uint *)(param_2 + 4) * iVar5 + (int)((ulonglong)lVar1 >> 0x20),
                       iVar6,0);
  uVar3 = FUN_000231a0((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
  if (uVar3 < 2) {
    uVar3 = 2;
  }
  else if (uVar4 < uVar3) {
    uVar3 = uVar4;
  }
  uVar2 = FUN_00017e00((int)*param_1);
  FUN_00020c3a(uVar2,*param_2,uVar3);
  uVar2 = FUN_00017e00((int)*param_1);
  FUN_0002089c(uVar2,0);
  uVar2 = FUN_00017e00((int)*param_1);
  FUN_00020952(uVar2,1);
  return 0;
}




void FUN_00018208(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_0001842c;
  uVar2 = 0;
  do {
    if (*(int *)(iVar1 + uVar2 * 4) == 0) break;
    FUN_0001835c();
    uVar2 = (uint)(short)((short)uVar2 + 1);
  } while (uVar2 < 7);
  FUN_0001fb24(0x600);
  uVar2 = 0;
  do {
    iVar3 = iVar1 + uVar2;
    if (*(char *)(iVar3 + 0x1c) == -1) {
      return;
    }
    FUN_000183ce();
    FUN_00017e00((int)*(char *)(iVar3 + 0x1c));
    FUN_00020728();
    uVar2 = (uint)(short)((short)uVar2 + 1);
  } while (uVar2 < 0xe);
  return;
}




void FUN_00018250(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  undefined local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  
  iVar1 = DAT_0001842c;
  local_30 = 0x77;
  local_2c = 0;
  local_2e = 0;
  local_28 = 15999;
  local_2a = 0;
  local_24 = 0;
  uVar3 = 0;
  do {
    if (*(char *)(iVar1 + uVar3 + 0x1c) != -1) {
      uVar2 = FUN_00017e00();
      FUN_000207aa(uVar2,&local_30);
    }
    uVar3 = (uint)(short)((short)uVar3 + 1);
  } while (uVar3 < 0xe);
  local_20 = 1;
  local_1c = 0;
  local_18 = 0;
  local_1e = 0;
  local_1a = 0;
  local_16 = 0;
  FUN_00017e6a(&local_20);
  return;
}




undefined4 FUN_000182b8(char *param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  
  uVar1 = FUN_0001fe1a(0);
  FUN_00017e00((int)*param_1);
  iVar2 = FUN_000208a4();
  if (iVar2 == 0x100) {
    uVar1 = uVar1 >> 1;
  }
  else if (iVar2 == 0x200) {
    uVar1 = uVar1 >> 2;
  }
  uVar3 = FUN_00017e00((int)*param_1);
  iVar4 = FUN_00020fd8(uVar3,*param_2);
  uVar7 = FUN_000231a0(uVar1,0,DAT_00018430,0);
  uVar6 = (undefined4)((ulonglong)uVar7 >> 0x20);
  iVar5 = FUN_00017e00((int)*param_1);
  uVar3 = FUN_000231a0((iVar2 + 1) * (*(int *)(iVar5 + 0x2c) + 1) * 1000,0,(int)uVar7,uVar6);
  *(undefined4 *)(param_2 + 2) = uVar3;
  uVar3 = FUN_000231a0((iVar2 + 1) * (iVar4 + 1) * 1000,0,(int)uVar7,uVar6);
  *(undefined4 *)(param_2 + 4) = uVar3;
  return 0;
}




void FUN_0001835c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00018434 >> 0x14;
  iVar2 = param_1 - DAT_00018434;
  if (param_1 == DAT_00018434) {
    uVar1 = 0x605;
  }
  else if (param_1 == DAT_00018434 || param_1 < DAT_00018434) {
    param_1 = param_1 + DAT_00018438;
    if (param_1 == 0) {
      uVar1 = 0x602;
    }
    else if (param_1 == iVar3) {
      uVar1 = 0x603;
    }
    else {
      if (param_1 != iVar3 * 2) {
LAB_0001838e:
        FUN_0001cd4c(&DAT_0001843c);
        FUN_0001cd4c(s_Unsport_gpio_port__0001844c);
        FUN_0001cd4c(&LAB_00018460);
        return;
      }
      uVar1 = 0x604;
    }
  }
  else if (iVar2 == iVar3) {
    uVar1 = 0x606;
  }
  else if (iVar2 == iVar3 * 2) {
    uVar1 = 0x607;
  }
  else {
    if (iVar2 != 0xc00) goto LAB_0001838e;
    uVar1 = 0x608;
  }
  FUN_0001fb24(uVar1);
  return;
}




void FUN_000183ce(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 0x60b;
    break;
  case 1:
    uVar1 = 0x700;
    break;
  case 2:
    uVar1 = 0x701;
    break;
  case 3:
    uVar1 = 0x702;
    break;
  case 4:
    uVar1 = 0x703;
    break;
  case 5:
    uVar1 = 0x704;
    break;
  case 6:
    uVar1 = 0x705;
    break;
  case 7:
    uVar1 = 0x60d;
    break;
  default:
    FUN_0001cd4c(&DAT_0001843c);
    FUN_0001cd4c(&LAB_00018468);
    FUN_0001cd4c(&LAB_00018460);
    return;
  }
  FUN_0001fb24(uVar1);
  return;
}




void FUN_00018584(int param_1)

{
  int iVar1;
  uint **ppuVar2;
  
  ppuVar2 = *(uint ***)(param_1 + 0x3c);
  if (ppuVar2 == (uint **)0x0) {
    FUN_0001cdc6(s_uart____RT_NULL_0001886c,DAT_00018868,0x1da);
  }
  iVar1 = FUN_00020280(*ppuVar2,DAT_0001887c);
  if ((iVar1 != 0) && (iVar1 = FUN_0002022e(*ppuVar2,5), iVar1 != 0)) {
    FUN_00017164(param_1,1);
    **ppuVar2 = **ppuVar2 & 0xffffffdf;
    return;
  }
  return;
}




void FUN_000185c6(void)

{
  char *pcVar1;
  undefined4 uVar2;
  
  FUN_0001c894();
  FUN_00018584(DAT_00018880);
  uVar2 = FUN_00012db4();
  pcVar1 = DAT_0001c8ec;
  if (*(code **)(DAT_0001c8ec + 8) != (code *)0x0) {
    (**(code **)(DAT_0001c8ec + 8))();
  }
  *pcVar1 = *pcVar1 + -1;
  FUN_00012dbc(uVar2);
  return;
}




void FUN_000185da(void)

{
  char *pcVar1;
  undefined4 uVar2;
  
  FUN_0001c894();
  FUN_00018584(DAT_00018880 + 0x5c);
  uVar2 = FUN_00012db4();
  pcVar1 = DAT_0001c8ec;
  if (*(code **)(DAT_0001c8ec + 8) != (code *)0x0) {
    (**(code **)(DAT_0001c8ec + 8))();
  }
  *pcVar1 = *pcVar1 + -1;
  FUN_00012dbc(uVar2);
  return;
}




void FUN_000185f0(void)

{
  char *pcVar1;
  undefined4 uVar2;
  
  FUN_0001c894();
  FUN_00018584(DAT_00018880 + 0xb8);
  uVar2 = FUN_00012db4();
  pcVar1 = DAT_0001c8ec;
  if (*(code **)(DAT_0001c8ec + 8) != (code *)0x0) {
    (**(code **)(DAT_0001c8ec + 8))();
  }
  *pcVar1 = *pcVar1 + -1;
  FUN_00012dbc(uVar2);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018606(void)

{
  char *pcVar1;
  undefined4 uVar2;
  
  FUN_0001c894();
  FUN_00018584(_DAT_00018884);
  uVar2 = FUN_00012db4();
  pcVar1 = DAT_0001c8ec;
  if (*(code **)(DAT_0001c8ec + 8) != (code *)0x0) {
    (**(code **)(DAT_0001c8ec + 8))();
  }
  *pcVar1 = *pcVar1 + -1;
  FUN_00012dbc(uVar2);
  return;
}




void FUN_0001861a(int param_1)

{
  uint uVar1;
  
  FUN_0001fb24(*(undefined2 *)(param_1 + 8));
  FUN_0001fb24(*(undefined2 *)(param_1 + 10));
  FUN_0001fb24(*(undefined2 *)(param_1 + 6));
  FUN_00020448(*(undefined4 *)(param_1 + 0xc),0x18,3,*(undefined2 *)(param_1 + 0x10));
  FUN_00020448(*(undefined4 *)(param_1 + 0x14),4,3,*(undefined2 *)(param_1 + 0x18));
  uVar1 = (uint)*(char *)(param_1 + 4);
  if ((int)uVar1 < 0) {
    *(undefined *)((uVar1 & 0xf) + 0xe000ed14) = 0;
  }
  else {
    *(undefined *)(uVar1 + 0xe000e400) = 0;
  }
  FUN_00018852((int)*(char *)(param_1 + 4));
  return;
}




undefined4 FUN_00018674(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_serial____RT_NULL_00018887 + 1,DAT_00018868 + -0x44,0x15a);
  }
  if (param_2 == (undefined4 *)0x0) {
    FUN_0001cdc6(s_cfg____RT_NULL_0001889c,DAT_00018868 + -0x44,0x15b);
  }
  puVar4 = *(undefined4 **)(param_1 + 0x3c);
  FUN_0001861a(puVar4);
  FUN_0001ff68(*puVar4,*param_2);
  if ((*(byte *)(param_2 + 1) & 0xf) == 9) {
    uVar2 = 0x1000;
  }
  else {
    uVar2 = 0;
  }
  FUN_0001ffc6(*puVar4,uVar2);
  if (((uint)*(byte *)(param_2 + 1) << 0x1a) >> 0x1e == 1) {
    uVar2 = 0x2000;
  }
  else {
    uVar2 = 0;
  }
  FUN_0001ffd6(*puVar4,uVar2);
  uVar1 = ((uint)*(byte *)(param_2 + 1) << 0x18) >> 0x1e;
  if (uVar1 == 1) {
    uVar3 = 0x600;
    uVar2 = *puVar4;
  }
  else {
    uVar2 = *puVar4;
    if (uVar1 == 2) {
      uVar3 = 0x400;
    }
    else {
      uVar3 = 0;
    }
  }
  FUN_0001ffb6(uVar2,uVar3);
  FUN_00020006(*puVar4,4);
  FUN_0001fffa(*puVar4,8);
  FUN_0001ffe6(*puVar4);
  return 0;
}




undefined4 FUN_00018718(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_serial____RT_NULL_00018887 + 1,DAT_00018868 + -0x30,0x195);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x3c);
  if (param_2 == 6) {
    FUN_00018852((int)*(char *)(puVar1 + 1));
    FUN_00020258(*puVar1,0x305);
  }
  else if (param_2 == 7) {
    *(int *)(((uint)(int)*(char *)(puVar1 + 1) >> 5) * 4 + -0x1fff1e80) =
         1 << ((int)*(char *)(puVar1 + 1) & 0x1fU);
    FUN_0002026c(*puVar1,0x305);
  }
  return 0;
}




undefined4 FUN_00018772(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_serial____RT_NULL_00018887 + 1,DAT_00018868 + -0x1e,0x1b5);
  }
  puVar2 = *(undefined4 **)(param_1 + 0x3c);
  FUN_0002009a(*puVar2,param_2);
  do {
    iVar1 = FUN_0002022e(*puVar2,7);
  } while (iVar1 == 0);
  return 0;
}




undefined4 FUN_000187a2(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_serial____RT_NULL_00018887 + 1,DAT_00018868 + -0xf,0x1c8);
  }
  puVar2 = *(undefined4 **)(param_1 + 0x3c);
  uVar3 = 0xffffffff;
  iVar1 = FUN_0002022e(*puVar2,5);
  if (iVar1 != 0) {
    uVar3 = FUN_000200a2(*puVar2);
  }
  return uVar3;
}




int FUN_000187d2(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  
  uVar7 = 0;
  uVar10 = *(undefined4 *)(DAT_00018868 + -0xf8);
  uVar4 = *(undefined4 *)(DAT_00018868 + -0xf4);
  uVar8 = *(undefined4 *)(DAT_00018868 + -0xf0);
  uVar9 = *(undefined4 *)(DAT_00018868 + -0xec);
  iVar11 = DAT_00018868 + -0xe8;
  iVar12 = DAT_00018868 + -0x58;
  do {
    iVar6 = iVar11 + uVar7 * 0x24;
    iVar1 = FUN_00023a0c(*(undefined4 *)(iVar6 + 0x20),s_uart1_000188ac);
    if (iVar1 == 0) {
      uVar5 = 0x600;
      uVar2 = uVar8;
      uVar3 = uVar9;
    }
    else {
      uVar5 = 0x500;
      uVar2 = uVar10;
      uVar3 = uVar4;
    }
    *(int *)(*(int *)(iVar6 + 0x1c) + 0x40) = iVar12;
    iVar1 = *(int *)(iVar6 + 0x1c);
    *(undefined4 *)(iVar1 + 0x44) = uVar2;
    *(undefined4 *)(iVar1 + 0x48) = uVar3;
    iVar1 = FUN_00017118(*(undefined4 *)(iVar6 + 0x1c),*(undefined4 *)(iVar6 + 0x20),uVar5 | 0x403,
                         iVar6);
    if (iVar1 != 0) {
      FUN_0001cdc6(s_result____RT_EOK_000188b4,DAT_00018868 + 0x15,0x212);
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 4);
  return iVar1;
}




void FUN_00018852(uint param_1)

{
  *(int *)((param_1 >> 5) * 4 + -0x1fff1f00) = 1 << (param_1 & 0x1f);
  return;
}




undefined4 FUN_000188c8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 8) != 0) {
    FUN_0001d330();
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  if (param_1 != 0) {
    iVar2 = FUN_000236b4(param_1);
    iVar2 = FUN_0001d084(iVar2 + 1);
    *(int *)(iVar1 + 8) = iVar2;
    if (iVar2 != 0) {
      FUN_0002366c(iVar2,param_1);
    }
  }
  return 0;
}




undefined * FUN_000188f6(void)

{
  if ((int)((uint)*(byte *)(*(int *)(DAT_00018cc4 + 0xc) + 0x21) << 0x1e) < 0) {
    if (*(int *)(DAT_00018cc4 + 8) == 0) {
      FUN_0002366c(DAT_00018cc8,&DAT_00018ccc);
    }
    else {
      FUN_000239b4(DAT_00018cc8,*(int *)(DAT_00018cc4 + 8),0x400);
    }
    FUN_00023788(DAT_00018cc8,&DAT_00018cd4);
  }
  else {
    *DAT_00018cc8 = 0;
  }
  return DAT_00018cc8;
}




uint FUN_00018930(void)

{
  int iVar1;
  
  iVar1 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8,0x81);
  }
  return ((uint)*(byte *)(*(int *)(iVar1 + 0xc) + 0x21) << 0x1e) >> 0x1f;
}




void FUN_0001894e(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8 + 0x16,0x90);
  }
  pbVar1 = (byte *)(*(int *)(iVar2 + 0xc) + 0x21);
  *pbVar1 = *pbVar1 & 0xfd | (byte)((param_1 & 1) << 1);
  return;
}




uint FUN_00018972(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_r3;
  uint local_18;
  
  iVar2 = DAT_00018cc4;
  local_18 = in_r3 & 0xffffff00;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8 + 0x2c,0xa4);
  }
  iVar3 = *(int *)(*(int *)(iVar2 + 0xc) + 0x20c);
  do {
    iVar1 = iVar3;
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    do {
      iVar3 = FUN_000136a6(iVar1,0xffffffff,&local_18,1);
      if (iVar3 == 1) {
        return local_18 & 0xff;
      }
      FUN_0001a7da(*(undefined4 *)(iVar2 + 0xc),0xffffffff);
      iVar3 = *(int *)(*(int *)(iVar2 + 0xc) + 0x20c);
    } while (iVar3 == iVar1);
  } while( true );
}




undefined4 FUN_000189cc(void)

{
  int iVar1;
  
  iVar1 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8 + 0x3a,0xc3);
  }
  FUN_0001a7ec(*(undefined4 *)(iVar1 + 0xc));
  return 0;
}




void FUN_000189ea(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8 + 0x47,0xd6);
  }
  iVar1 = FUN_0001344c(param_1);
  if (iVar1 != 0) {
    if ((*(int *)(*(int *)(iVar3 + 0xc) + 0x20c) != iVar1) &&
       (iVar2 = FUN_0001357e(iVar1,0x143), iVar2 == 0)) {
      if (*(int *)(*(int *)(iVar3 + 0xc) + 0x20c) != 0) {
        FUN_00013644();
        FUN_000137b0(*(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x20c),0);
      }
      FUN_0001ce98(*(int *)(iVar3 + 0xc) + 0x1b6,0,0x51);
      iVar3 = *(int *)(iVar3 + 0xc);
      *(undefined2 *)(iVar3 + 0x208) = 0;
      *(undefined2 *)(iVar3 + 0x20a) = 0;
      *(int *)(iVar3 + 0x20c) = iVar1;
      FUN_000137b0(iVar1,DAT_00018cf0);
      return;
    }
    return;
  }
  FUN_0001cd4c(s_finsh__can_not_find_device___s_00018cf4,param_1);
  return;
}




undefined4 FUN_00018a72(void)

{
  int iVar1;
  
  iVar1 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8 + 0x58,0xfd);
  }
  return *(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x20c);
}




void FUN_00018a8e(byte param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8 + 0x69,0x10d);
  }
  pbVar1 = (byte *)(*(int *)(iVar2 + 0xc) + 0x21);
  *pbVar1 = *pbVar1 & 0xfe | param_1 & 1;
  return;
}




byte FUN_00018ab4(void)

{
  int iVar1;
  
  iVar1 = DAT_00018cc4;
  if (*(int *)(DAT_00018cc4 + 0xc) == 0) {
    FUN_0001cdc6(s_shell____RT_NULL_00018cdc,DAT_00018cd8 + 0x78,0x11a);
  }
  return *(byte *)(*(int *)(iVar1 + 0xc) + 0x21) & 1;
}




void FUN_00018ad6(int param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(short *)(param_1 + 0x208) != 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x24);
    iVar5 = param_1 + 0x1b6;
    if (uVar2 < 5) {
      if ((uVar2 != 0) &&
         (iVar3 = FUN_00023614(param_1 + uVar2 * 0x50 + -0x2a,iVar5,0x50), iVar3 == 0))
      goto LAB_00018b86;
      *(ushort *)(param_1 + 0x22) = *(ushort *)(param_1 + 0x24);
      FUN_0001ce98(param_1 + (uint)*(ushort *)(param_1 + 0x24) * 0x50 + 0x26,0,0x50);
      FUN_0001ceee(param_1 + (uint)*(ushort *)(param_1 + 0x24) * 0x50 + 0x26,iVar5,
                   *(undefined2 *)(param_1 + 0x208));
      sVar1 = *(short *)(param_1 + 0x24) + 1;
    }
    else {
      iVar3 = FUN_00023614(param_1 + 0x166,iVar5,0x50);
      if (iVar3 == 0) goto LAB_00018b86;
      iVar3 = 0;
      do {
        iVar4 = param_1 + iVar3 * 0x50;
        FUN_0001ceee(iVar4 + 0x26,iVar4 + 0x76,0x50);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      iVar3 = param_1 + iVar3 * 0x50 + 0x26;
      FUN_0001ce98(iVar3,0,0x50);
      FUN_0001ceee(iVar3,iVar5,*(undefined2 *)(param_1 + 0x208));
      sVar1 = 5;
    }
    *(short *)(param_1 + 0x24) = sVar1;
  }
LAB_00018b86:
  *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(param_1 + 0x24);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0001911a(int param_1)

{
  int **ppiVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = FUN_00023600(param_1,0x20);
  if (iVar2 == 0) {
    iVar2 = FUN_000236b4(param_1);
  }
  else {
    iVar2 = iVar2 - param_1;
  }
  ppiVar1 = _DAT_00019398;
  piVar4 = *DAT_00019394;
  while( true ) {
    if (*ppiVar1 <= piVar4) {
      return 0;
    }
    iVar3 = FUN_000236f2(*piVar4,param_1,iVar2);
    if ((iVar3 == 0) && (*(char *)(*piVar4 + iVar2) == '\0')) break;
    piVar4 = piVar4 + 4;
  }
  return piVar4[2];
}




undefined4 FUN_000194be(byte *param_1)

{
  byte bVar1;
  int *piVar2;
  
  if ((param_1 != (byte *)0x0) && (bVar1 = *param_1, bVar1 != 0)) {
    if ((bVar1 != 0x2b) && (bVar1 != 0x2d)) goto LAB_000194d6;
    do {
      param_1 = param_1 + 1;
      if (*param_1 == 0) {
        return 1;
      }
LAB_000194d6:
      piVar2 = (int *)FUN_0002318c();
    } while (*(char *)(*piVar2 + (uint)*param_1) == ' ');
  }
  return 0;
}




undefined4 FUN_000194ec(char *param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  
  if ((((param_1 != (char *)0x0) && (*param_1 != '\0')) && (*param_1 == '0')) &&
     (pcVar1 = param_1 + 2, param_1[1] == 'x')) {
    while( true ) {
      if (*pcVar1 == '\0') {
        return 1;
      }
      iVar2 = FUN_0002328e();
      piVar3 = (int *)FUN_0002318c();
      if (-1 < (int)(((uint)*(byte *)(*piVar3 + iVar2) ^ (uint)*(byte *)(*piVar3 + iVar2) << 2) <<
                    0x18)) break;
      pcVar1 = pcVar1 + 1;
    }
  }
  return 0;
}




int FUN_0001952c(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  
  iVar1 = 0;
  for (pcVar4 = (char *)(param_1 + 2); *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
    uVar2 = FUN_0002328e(*pcVar4);
    uVar2 = uVar2 & 0xff;
    piVar3 = (int *)FUN_0002318c();
    if (*(char *)(*piVar3 + uVar2) == ' ') {
      iVar5 = uVar2 - 0x30;
    }
    else {
      iVar5 = uVar2 - 0x57;
    }
    iVar1 = iVar5 + iVar1 * 0x10;
  }
  return iVar1;
}




int * FUN_00019576(int *param_1,int **param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  param_2[4] = (int *)0x0;
  if ((param_2[3] == (int *)0x0) || (*(char *)(param_2 + 2) == '\0')) {
LAB_000195aa:
    param_1 = (int *)0x0;
  }
  else {
    piVar3 = *param_2;
    if (param_1 == (int *)0x0) {
      uVar1 = FUN_00012db4();
      param_1 = piVar3;
    }
    else {
      uVar1 = FUN_00012db4();
      if ((*(byte *)(param_1 + -1) & 0x7f) != *(byte *)(param_2 + 2)) {
        FUN_00012dbc(uVar1);
        goto LAB_000195aa;
      }
    }
    piVar2 = param_2[1];
    piVar4 = (int *)0x0;
    do {
      param_1 = (int *)*param_1;
      if (param_1 == piVar3) {
        param_1 = (int *)0x0;
        break;
      }
      *piVar2 = (int)param_1;
      piVar2 = piVar2 + 1;
      piVar4 = (int *)((int)piVar4 + 1);
    } while (param_2[3] != piVar4);
    FUN_00012dbc(uVar1);
    param_2[4] = piVar4;
  }
  return param_1;
}




undefined4 FUN_000195dc(void)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined auStack_e0 [8];
  byte local_d8;
  int local_d0;
  undefined auStack_cc [144];
  int local_3c [9];
  
  iVar7 = 0;
  FUN_00019ef2(auStack_e0,1,local_3c,8);
  FUN_0001cd4c(s______s_00019960,10,10,s_rt_thread_t_00019954);
  FUN_0001cd4c(DAT_00019968,8,8,s_thread_0001994c);
  FUN_00019ee0(10);
  FUN_0001cd4c(&DAT_0001996c);
  FUN_00019ee0(8);
  FUN_0001cd4c(s__________________________________00019970);
  do {
    iVar7 = FUN_00019576(iVar7,auStack_e0);
    for (iVar6 = 0; iVar6 < local_d0; iVar6 = iVar6 + 1) {
      iVar4 = local_3c[iVar6];
      iVar5 = iVar4 + -0xc;
      uVar1 = FUN_00012db4();
      if ((*(byte *)(iVar4 + -4) & 0x7f) == local_d8) {
        FUN_0001ceee(auStack_cc,iVar5,0x8c);
        FUN_00012dbc(uVar1);
        FUN_0001cd4c(&DAT_000199b0,iVar5);
        FUN_0001cd4c(s______s__3d_000199b4,8,8,iVar5,*(undefined *)(iVar4 + 0x29));
        uVar2 = *(byte *)(iVar4 + 0x28) & 7;
        if (uVar2 == 2) {
          pcVar3 = s_ready_000199cc;
LAB_000196b0:
          FUN_0001cd4c(pcVar3);
        }
        else {
          if ((int)(uVar2 << 0x1d) < 0) {
            pcVar3 = s_suspend_000199c0;
            goto LAB_000196b0;
          }
          if ((*(byte *)(iVar4 + 0x28) & 7) == 0) {
            pcVar3 = s_init_000199d8;
            goto LAB_000196b0;
          }
          if (uVar2 == 1) {
            pcVar3 = s_close_000199e4;
            goto LAB_000196b0;
          }
          if (uVar2 == 3) {
            pcVar3 = s_running_000199f0;
            goto LAB_000196b0;
          }
        }
        for (pcVar3 = *(char **)(iVar4 + 0x1c); *pcVar3 == '#'; pcVar3 = pcVar3 + 1) {
        }
        uVar1 = FUN_0001ce26(*(undefined4 *)(iVar4 + 0x24));
        uVar2 = *(uint *)(iVar4 + 0x20);
        FUN_0001cd4c(s_0x_08x_0x_08x__02d___0x_08x__s_000199fc,
                     (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x10)) + uVar2,uVar2,
                     ((uVar2 - ((int)pcVar3 - *(int *)(iVar4 + 0x1c))) * 100) / uVar2,
                     *(undefined4 *)(iVar4 + 0x48),uVar1);
      }
      else {
        FUN_00012dbc(uVar1);
      }
    }
    if (iVar7 == 0) {
      return 0;
    }
  } while( true );
}




undefined4 FUN_000196fa(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined auStack_54 [8];
  byte local_4c;
  int local_44;
  int local_3c [9];
  
  iVar4 = 0;
  FUN_00019ef2(auStack_54,2,local_3c,8);
  FUN_0001cd4c(s______s_v_suspend_thread_00019a30,8,8,s_semaphore_00019a24);
  FUN_00019ee0(8);
  FUN_0001cd4c(s____________________00019a4c);
  do {
    iVar4 = FUN_00019576(iVar4,auStack_54);
    for (iVar3 = 0; iVar3 < local_44; iVar3 = iVar3 + 1) {
      iVar2 = local_3c[iVar3];
      FUN_00012db4();
      if ((*(byte *)(iVar2 + -4) & 0x7f) == local_4c) {
        FUN_00012dbc();
        iVar5 = iVar2 + 8;
        if (*(int *)(iVar2 + 8) == iVar5) {
          uVar1 = FUN_00019ece(iVar5);
          FUN_0001cd4c(s______s__03d__d_00019a74,8,8,iVar2 + -0xc,*(undefined2 *)(iVar2 + 0x10),
                       uVar1);
        }
        else {
          uVar1 = FUN_00019ece(iVar5);
          FUN_0001cd4c(s______s__03d__d__00019a64,8,8,iVar2 + -0xc,*(undefined2 *)(iVar2 + 0x10),
                       uVar1);
          FUN_00019f16(iVar5);
          FUN_0001cd4c(s_0x_08x_0x_08x__02d___0x_08x__s_000199fc + 0x24);
        }
      }
      else {
        FUN_00012dbc();
      }
    }
  } while (iVar4 != 0);
  return 0;
}




undefined4 FUN_000197b6(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined auStack_54 [8];
  byte local_4c;
  int local_44;
  int local_3c [9];
  
  iVar5 = 0;
  FUN_00019ef2(auStack_54,4,local_3c,8);
  FUN_0001cd4c(s______s_set_suspend_thread_00019a8c,8,8,s_event_00019a84);
  FUN_00019ee0(8);
  FUN_0001cd4c(s___________________________00019ab0);
  do {
    iVar5 = FUN_00019576(iVar5,auStack_54);
    for (iVar4 = 0; iVar4 < local_44; iVar4 = iVar4 + 1) {
      iVar3 = local_3c[iVar4];
      FUN_00012db4();
      if ((*(byte *)(iVar3 + -4) & 0x7f) == local_4c) {
        FUN_00012dbc();
        iVar1 = iVar3 + 8;
        if (*(int *)(iVar3 + 8) == iVar1) {
          FUN_0001cd4c(s______s_0x_08x_0_00019ae8,8,8,iVar3 + -0xc,*(undefined4 *)(iVar3 + 0x10));
        }
        else {
          uVar2 = FUN_00019ece(iVar1);
          FUN_0001cd4c(s______s_0x_08x__03d__00019ad0,8,8,iVar3 + -0xc,*(undefined4 *)(iVar3 + 0x10)
                       ,uVar2);
          FUN_00019f16(iVar1);
          FUN_0001cd4c(s_0x_08x_0x_08x__02d___0x_08x__s_000199fc + 0x24);
        }
      }
      else {
        FUN_00012dbc();
      }
    }
  } while (iVar5 != 0);
  return 0;
}




undefined4 FUN_0001986c(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined auStack_58 [8];
  byte local_50;
  int local_48;
  int local_40 [9];
  
  iVar4 = 0;
  FUN_00019ef2(auStack_58,3,local_40,8);
  FUN_0001cd4c(s______s_owner_hold_priority_suspe_00019b04,8,8,s_mutex_00019afc);
  FUN_00019ee0(8);
  FUN_0001cd4c(s__________________________________00019b34);
  do {
    iVar4 = FUN_00019576(iVar4,auStack_58);
    for (iVar3 = 0; iVar3 < local_48; iVar3 = iVar3 + 1) {
      iVar2 = local_40[iVar3];
      FUN_00012db4();
      if ((*(byte *)(iVar2 + -4) & 0x7f) == local_50) {
        FUN_00012dbc();
        if (*(int *)(iVar2 + 8) == iVar2 + 8) {
          uVar1 = FUN_00019ece();
          FUN_0001cd4c(s______s___8__s__04d__8d__04d_00019b7c,8,8,iVar2 + -0xc,8,
                       *(undefined4 *)(iVar2 + 0x14),*(undefined *)(iVar2 + 0x12),
                       *(undefined *)(iVar2 + 0x11),uVar1);
        }
        else {
          uVar1 = FUN_00019ece();
          FUN_0001cd4c(s______s___8__s__04d__8d__04d_00019b5c,8,8,iVar2 + -0xc,8,
                       *(undefined4 *)(iVar2 + 0x14),*(undefined *)(iVar2 + 0x12),
                       *(undefined *)(iVar2 + 0x11),uVar1);
          FUN_00019f16(iVar2 + 8);
          FUN_0001cd4c(s_0x_08x_0x_08x__02d___0x_08x__s_000199fc + 0x24);
        }
      }
      else {
        FUN_00012dbc();
      }
    }
  } while (iVar4 != 0);
  return 0;
}




int FUN_00019ece(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = param_1;
  while (piVar1 = (int *)*piVar1, piVar1 != param_1) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}




void FUN_00019ee0(int param_1)

{
  bool bVar1;
  
  while (bVar1 = param_1 != 0, param_1 = param_1 + -1, bVar1) {
    FUN_0001cd4c(&DAT_0001a194);
  }
  return;
}




void FUN_00019ef2(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_0001dc1a(param_2);
  *param_1 = iVar1 + 4;
  *(char *)(param_1 + 2) = (char)param_2;
  param_1[1] = param_3;
  param_1[3] = param_4;
  param_1[4] = 0;
  return;
}




void FUN_00019f16(int **param_1)

{
  int **ppiVar1;
  
  for (ppiVar1 = (int **)*param_1; ppiVar1 != param_1; ppiVar1 = (int **)*ppiVar1) {
    FUN_0001cd4c(&DAT_0001a198,8,ppiVar1 + -5);
    if ((int **)*ppiVar1 != param_1) {
      FUN_0001cd4c(&LAB_0001a1a0);
    }
  }
  return;
}




undefined4 FUN_0001a1aa(void)

{
  return *DAT_0001a248;
}




void FUN_0001a1b0(undefined4 param_1)

{
  FUN_00012db4();
  *DAT_0001a248 = param_1;
  FUN_00012dbc();
  return;
}




void FUN_0001a1c4(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_0001a248;
  if ((code *)DAT_0001a248[1] != (code *)0x0) {
    (*(code *)DAT_0001a248[1])();
  }
  uVar2 = FUN_00012db4();
  *piVar1 = *piVar1 + 1;
  iVar3 = FUN_0001e356();
  iVar4 = *(int *)(iVar3 + 0x54) + -1;
  *(int *)(iVar3 + 0x54) = iVar4;
  if (iVar4 == 0) {
    *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(iVar3 + 0x50);
    *(byte *)(iVar3 + 0x34) = *(byte *)(iVar3 + 0x34) | 8;
    FUN_00012dbc(uVar2);
    FUN_0001e128();
  }
  else {
    FUN_00012dbc(uVar2);
  }
  FUN_0001f056();
  return;
}




int FUN_0001a20e(int param_1)

{
  if (param_1 < 0) {
    return -1;
  }
  return ((param_1 % 1000) * 1000 + 999) / 1000 + (param_1 / 1000) * 1000;
}




undefined4 FUN_0001a240(void)

{
  return *DAT_0001a248;
}




undefined4 FUN_0001a320(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffdd;
  uVar1 = FUN_00012db4();
  uVar2 = 0;
  do {
    if (*(int *)(DAT_0001a448 + uVar2 * 4) == 0) {
      *(undefined4 *)(DAT_0001a448 + uVar2 * 4) = param_1;
      uVar3 = 0;
      break;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  FUN_00012dbc(uVar1);
  return uVar3;
}




undefined4 FUN_0001a352(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffd3;
  uVar1 = FUN_00012db4();
  uVar2 = 0;
  do {
    if (*(int *)(DAT_0001a448 + uVar2 * 4) == param_1) {
      *(undefined4 *)(DAT_0001a448 + uVar2 * 4) = 0;
      uVar3 = 0;
      break;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  FUN_00012dbc(uVar1);
  return uVar3;
}




void FUN_0001a386(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = DAT_0001a44c;
  piVar2 = (int *)(param_1 + 0x14);
  *(int **)(*DAT_0001a44c + 4) = piVar2;
  *piVar2 = *piVar1;
  *piVar1 = (int)piVar2;
  *(int **)(param_1 + 0x18) = piVar1;
  return;
}




int ** FUN_0001a398(void)

{
  int **ppiVar1;
  int **ppiVar2;
  
  ppiVar2 = (int **)0x0;
  ppiVar1 = (int **)*DAT_0001a44c;
  if (ppiVar1 != DAT_0001a44c) {
    ppiVar2 = ppiVar1 + -5;
    FUN_00012db4();
    (*ppiVar1)[1] = (int)ppiVar1[1];
    *ppiVar1[1] = (int)*ppiVar1;
    ppiVar1[1] = (int *)ppiVar1;
    *ppiVar1 = (int *)ppiVar1;
    FUN_00012dbc();
  }
  return ppiVar2;
}




int FUN_0001a460(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((-1 < (int)((uint)*(byte *)(param_2 + 0x34) << 0x1d)) &&
     (iVar1 = FUN_0001e860(param_2,param_4), iVar1 != 0)) {
    return iVar1;
  }
  if (param_3 != 0) {
    if (param_3 != 1) {
      FUN_0001cdc6(&DAT_0001a86c,DAT_0001a868,0xb6);
      return 0;
    }
    for (puVar2 = (undefined4 *)*param_1; puVar2 != param_1; puVar2 = (undefined4 *)*puVar2) {
      if (*(byte *)(param_2 + 0x35) < *(byte *)((int)puVar2 + 0x21)) {
        FUN_0001c812(puVar2,param_2 + 0x14);
        break;
      }
    }
    if (puVar2 != param_1) {
      return 0;
    }
  }
  FUN_0001c812(param_1,param_2 + 0x14);
  return 0;
}




undefined4 FUN_0001a4ca(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_sem____RT_NULL_0001a870,DAT_0001a868 + 0x12,0x13f);
  }
  if (0xffff < param_3) {
    FUN_0001cdc6(s_value_<_0x10000U_0001a880,DAT_0001a868 + 0x12,0x140);
  }
  if ((param_4 != 0) && (param_4 != 1)) {
    FUN_0001cdc6(s__flag____RT_IPC_FLAG_FIFO______f_0001a894,DAT_0001a868 + 0x12,0x141);
  }
  FUN_0001dcae(param_1,2,param_2);
  *(int *)(param_1 + 0x18) = param_1 + 0x14;
  *(int *)(param_1 + 0x14) = param_1 + 0x14;
  *(short *)(param_1 + 0x1c) = (short)param_3;
  *(char *)(param_1 + 9) = (char)param_4;
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001a7da(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_24;
  undefined4 uStack_20;
  
  uStack_20 = 2;
  local_24 = param_2;
  if (param_1 == 0) {
    FUN_0001cdc6(s_sem____RT_NULL_0001a870,DAT_0001a868 + 0x48,0x1fd);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 2) {
    FUN_0001cdc6(DAT_0001a8d0,DAT_0001a868 + 0x48,0x1fe);
  }
  if (*_DAT_0001a968 != (code *)0x0) {
    (**_DAT_0001a968)(param_1);
  }
  if ((*(short *)(param_1 + 0x1c) == 0) && (local_24 != 0)) {
    iVar1 = FUN_0001c8e6();
    uVar2 = FUN_00012db4();
    iVar3 = FUN_0001e246();
    if (iVar3 != 0) {
      FUN_0001cd4c(s_Function__s___scheduler_is_not_a_0001a96b + 1,DAT_0001a868 + 0x48);
      FUN_0001cdc6(&DAT_0001a86c,DAT_0001a868 + 0x48,0x203);
    }
    if (iVar1 == 1) {
      FUN_0001cd4c(s_Function__s___interrupt_is_disab_0001a998,DAT_0001a868 + 0x48);
      FUN_0001cdc6(&DAT_0001a86c,DAT_0001a868 + 0x48,0x203);
    }
    uVar4 = FUN_00012db4();
    iVar1 = FUN_0001e356();
    if (iVar1 == 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_b_0001a9c0,DAT_0001a868 + 0x48);
      FUN_0001cdc6(&DAT_0001a86c,DAT_0001a868 + 0x48,0x203);
    }
    uVar5 = FUN_00012db4();
    iVar1 = FUN_0001c8d4();
    if (iVar1 != 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001a904,DAT_0001a868 + 0x48);
      FUN_0001cdc6(&DAT_0001a86c,DAT_0001a868 + 0x48,0x203);
    }
    FUN_00012dbc(uVar5);
    FUN_00012dbc(uVar4);
    FUN_00012dbc(uVar2);
  }
  uVar2 = FUN_00012db4();
  if (*(short *)(param_1 + 0x1c) == 0) {
    if (local_24 == 0) {
      FUN_00012dbc(uVar2);
      iVar1 = -0x75;
      goto LAB_0001a792;
    }
    iVar3 = FUN_0001e356();
    *(undefined4 *)(iVar3 + 0x30) = 0xfffffff5;
    iVar1 = FUN_0001a460(param_1 + 0x14,iVar3,*(undefined *)(param_1 + 9),2);
    if (iVar1 != 0) {
      FUN_00012dbc(uVar2);
      goto LAB_0001a792;
    }
    if (0 < local_24) {
      FUN_0001efae(iVar3 + 0x58,0,&local_24);
      FUN_0001ee68(iVar3 + 0x58);
    }
    FUN_00012dbc(uVar2);
    FUN_0001e128();
    iVar1 = *(int *)(iVar3 + 0x30);
    if (iVar1 != 0) goto LAB_0001a792;
  }
  else {
    *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + -1;
    FUN_00012dbc(uVar2);
  }
  if (*DAT_0001a9f8 != (code *)0x0) {
    (**DAT_0001a9f8)(param_1);
  }
  iVar1 = 0;
LAB_0001a792:
  return CONCAT44(param_1,iVar1);
}




undefined4 FUN_0001a7ec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_sem____RT_NULL_0001a870,DAT_0001a868 + 0x55,0x28b);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 2) {
    FUN_0001cdc6(DAT_0001a8d0,DAT_0001a868 + 0x55,0x28c);
  }
  if (*DAT_0001a9fc != (code *)0x0) {
    (**DAT_0001a9fc)(param_1);
  }
  uVar2 = FUN_00012db4();
  if (*(int *)(param_1 + 0x14) == param_1 + 0x14) {
    if (0xfffe < *(ushort *)(param_1 + 0x1c)) {
      FUN_00012dbc(uVar2);
      return 0xffffffdd;
    }
    *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) + 1;
    FUN_00012dbc(uVar2);
  }
  else {
    FUN_0001c84c();
    FUN_00012dbc(uVar2);
    FUN_0001e128();
  }
  return 0;
}




undefined4 FUN_0001aa00(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_sem____RT_NULL_0001a870,DAT_0001ae04,0x2cc);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 2) {
    FUN_0001cdc6(DAT_0001ae08,DAT_0001ae04,0x2cd);
  }
  if (param_2 != 1) {
    return 0xffffff01;
  }
  uVar2 = FUN_00012db4();
  FUN_0001c85e(param_1 + 0x14);
  *(undefined2 *)(param_1 + 0x1c) = param_3;
  FUN_00012dbc(uVar2);
  FUN_0001e128();
  return 0;
}




void FUN_0001aa56(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  
  bVar2 = *(byte *)(param_1 + 0x36);
  for (puVar3 = *(undefined4 **)(undefined4 *)(param_1 + 0x3c);
      puVar3 != (undefined4 *)(param_1 + 0x3c); puVar3 = (undefined4 *)*puVar3) {
    bVar1 = *(byte *)((int)puVar3 + -7);
    if (*(byte *)(puVar3 + -2) <= *(byte *)((int)puVar3 + -7)) {
      bVar1 = *(byte *)(puVar3 + -2);
    }
    if (bVar1 < bVar2) {
      bVar2 = bVar1;
    }
  }
  return;
}




void FUN_0001aa80(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined local_28 [8];
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  iVar1 = FUN_0001eb0c(param_1,2,&uStack_1c);
  while( true ) {
    if ((((iVar1 != 0) || (-1 < (int)((uint)*(byte *)(param_1 + 0x34) << 0x1d))) ||
        (iVar1 = *(int *)(param_1 + 0x44), iVar1 == 0)) || (iVar2 = FUN_0001de70(iVar1), iVar2 != 3)
       ) {
      return;
    }
    local_28[0] = 0xff;
    FUN_0001c820(param_1 + 0x14);
    iVar2 = FUN_0001a460(iVar1 + 0x14,param_1,*(undefined *)(iVar1 + 9),param_3);
    if (iVar2 != 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x14) == iVar1 + 0x14) {
      *(undefined *)(iVar1 + 0x1d) = 0xff;
    }
    else {
      *(undefined *)(iVar1 + 0x1d) = *(undefined *)(*(int *)(iVar1 + 0x14) + 0x21);
    }
    uVar3 = FUN_0001aa56(*(undefined4 *)(iVar1 + 0x20));
    local_28[0] = (undefined)uVar3;
    param_1 = *(int *)(iVar1 + 0x20);
    if (*(byte *)(param_1 + 0x35) == uVar3) break;
    iVar1 = FUN_0001eb0c(param_1,2,local_28);
  }
  return;
}




undefined4 FUN_0001ab02(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_mutex____RT_NULL_0001ae0c,DAT_0001ae04 + 0xf,0x371);
  }
  FUN_0001dcae(param_1,3,param_2);
  *(int *)(param_1 + 0x18) = param_1 + 0x14;
  *(int *)(param_1 + 0x14) = param_1 + 0x14;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined *)(param_1 + 0x1d) = 0xff;
  *(undefined *)(param_1 + 0x1e) = 0;
  *(undefined *)(param_1 + 0x1c) = 0xff;
  *(int *)(param_1 + 0x28) = param_1 + 0x24;
  *(int *)(param_1 + 0x24) = param_1 + 0x24;
  *(undefined *)(param_1 + 9) = 1;
  return 0;
}




undefined4 FUN_0001ab46(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_mutex____RT_NULL_0001ae0c,DAT_0001ae04 + 0x1d,0x39e);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 3) {
    FUN_0001cdc6(DAT_0001ae20,DAT_0001ae04 + 0x1d,0x39f);
  }
  iVar1 = FUN_0001de4e(param_1);
  if (iVar1 == 0) {
    FUN_0001cdc6(s_rt_object_is_systemobject__mutex_0001ae24,DAT_0001ae04 + 0x1d,0x3a0);
  }
  uVar2 = FUN_00012db4();
  FUN_0001c85e(param_1 + 0x14);
  FUN_0001c820(param_1 + 0x24);
  FUN_00012dbc(uVar2);
  FUN_0001dd2c(param_1);
  return 0;
}




void FUN_0001abae(int param_1,int param_2)

{
  bool bVar1;
  undefined uVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = false;
  FUN_0001c820(param_2 + 0x14);
  iVar4 = *(int *)(param_1 + 0x20);
  if ((iVar4 != 0) && (*(char *)(iVar4 + 0x35) == *(char *)(param_2 + 0x35))) {
    bVar1 = true;
  }
  if (*(int *)(param_1 + 0x14) == param_1 + 0x14) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = *(undefined *)(*(int *)(param_1 + 0x14) + 0x21);
  }
  *(undefined *)(param_1 + 0x1d) = uVar2;
  if (bVar1) {
    uVar3 = FUN_0001aa56(iVar4);
    if (*(byte *)(*(int *)(param_1 + 0x20) + 0x35) != uVar3) {
      FUN_0001aa80(*(int *)(param_1 + 0x20),uVar3,2);
      return;
    }
  }
  return;
}




undefined FUN_0001ac04(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined uVar3;
  
  uVar3 = 0xff;
  if ((param_1 == 0) || (0x1f < param_2)) {
    FUN_0001ce66(0xfffffffb);
  }
  else {
    uVar1 = FUN_00012db4();
    uVar3 = *(undefined *)(param_1 + 0x1c);
    *(char *)(param_1 + 0x1c) = (char)param_2;
    if (*(int *)(param_1 + 0x20) != 0) {
      uVar2 = FUN_0001aa56();
      if (*(byte *)(*(int *)(param_1 + 0x20) + 0x35) != uVar2) {
        FUN_0001aa80(*(int *)(param_1 + 0x20),uVar2,2);
      }
    }
    FUN_00012dbc(uVar1);
  }
  return uVar3;
}




void FUN_0001ac58(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00012db4();
  iVar2 = FUN_0001c8d4();
  if (iVar2 != 0) {
    FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001a904,DAT_0001ae04 + 0x2d);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001ae04 + 0x2d,0x43b);
  }
  FUN_00012dbc(uVar1);
  iVar2 = FUN_0001dd66(3,param_1);
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x18) = iVar2 + 0x14;
    *(int *)(iVar2 + 0x14) = iVar2 + 0x14;
    *(undefined4 *)(iVar2 + 0x20) = 0;
    *(undefined *)(iVar2 + 0x1d) = 0xff;
    *(undefined *)(iVar2 + 0x1e) = 0;
    *(undefined *)(iVar2 + 0x1c) = 0xff;
    *(int *)(iVar2 + 0x28) = iVar2 + 0x24;
    *(int *)(iVar2 + 0x24) = iVar2 + 0x24;
    *(undefined *)(iVar2 + 9) = 1;
  }
  return;
}




undefined4 FUN_0001acb8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_mutex____RT_NULL_0001ae0c,DAT_0001ae04 + 0x3d,0x46a);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 3) {
    FUN_0001cdc6(DAT_0001ae20,DAT_0001ae04 + 0x3d,0x46b);
  }
  iVar1 = FUN_0001de4e(param_1);
  if (iVar1 != 0) {
    FUN_0001cdc6(s_rt_object_is_systemobject__mutex_0001ae58,DAT_0001ae04 + 0x3d,0x46c);
  }
  uVar2 = FUN_00012db4();
  iVar1 = FUN_0001c8d4();
  if (iVar1 != 0) {
    FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001a904,DAT_0001ae04 + 0x3d);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001ae04 + 0x3d,0x46e);
  }
  FUN_00012dbc(uVar2);
  uVar2 = FUN_00012db4();
  FUN_0001c85e(param_1 + 0x14);
  FUN_0001c820(param_1 + 0x24);
  FUN_00012dbc(uVar2);
  FUN_0001ddfa(param_1);
  return 0;
}




undefined8 FUN_0001b018(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  bool bVar8;
  int local_2c;
  undefined4 uStack_28;
  
  uStack_28 = 2;
  local_2c = param_2;
  iVar2 = FUN_0001c8e6();
  uVar3 = FUN_00012db4();
  iVar4 = FUN_0001e246();
  if (iVar4 != 0) {
    FUN_0001cd4c(s_Function__s___scheduler_is_not_a_0001a96b + 1,DAT_0001ae04 + 0x4d);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001ae04 + 0x4d,0x49f);
  }
  if (iVar2 == 1) {
    FUN_0001cd4c(s_Function__s___interrupt_is_disab_0001a998,DAT_0001ae04 + 0x4d);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001ae04 + 0x4d,0x49f);
  }
  uVar5 = FUN_00012db4();
  iVar2 = FUN_0001e356();
  if (iVar2 == 0) {
    FUN_0001cd4c(s_Function__s__shall_not_be_used_b_0001a9c0,DAT_0001ae04 + 0x4d);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001ae04 + 0x4d,0x49f);
  }
  uVar6 = FUN_00012db4();
  iVar2 = FUN_0001c8d4();
  if (iVar2 != 0) {
    FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001a904,DAT_0001ae04 + 0x4d);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001ae04 + 0x4d,0x49f);
  }
  FUN_00012dbc(uVar6);
  FUN_00012dbc(uVar5);
  FUN_00012dbc(uVar3);
  if (param_1 == 0) {
    FUN_0001cdc6(s_mutex____RT_NULL_0001ae0c,DAT_0001b24c,0x4a2);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 3) {
    FUN_0001cdc6(DAT_0001b250,DAT_0001b24c,0x4a3);
  }
  iVar2 = FUN_0001e356();
  uVar3 = FUN_00012db4();
  if (*DAT_0001b254 != (code *)0x0) {
    (**DAT_0001b254)(param_1);
  }
  *(undefined4 *)(iVar2 + 0x30) = 0;
  if (*(int *)(param_1 + 0x20) == iVar2) {
    if (0xfe < *(byte *)(param_1 + 0x1e)) {
      FUN_00012dbc(uVar3);
      iVar4 = -0x23;
      goto LAB_0001aef8;
    }
    *(byte *)(param_1 + 0x1e) = *(byte *)(param_1 + 0x1e) + 1;
  }
  else if (*(int *)(param_1 + 0x20) == 0) {
    *(int *)(param_1 + 0x20) = iVar2;
    *(undefined *)(param_1 + 0x1d) = 0xff;
    *(undefined *)(param_1 + 0x1e) = 1;
    bVar1 = *(byte *)(param_1 + 0x1c);
    if ((bVar1 != 0xff) && (bVar1 < *(byte *)(iVar2 + 0x35))) {
      FUN_0001aa80(iVar2,bVar1,2);
    }
    FUN_0001c804(iVar2 + 0x3c,param_1 + 0x24);
  }
  else {
    if (local_2c == 0) {
      iVar4 = -0x75;
      *(undefined4 *)(iVar2 + 0x30) = 0xffffff8b;
      FUN_00012dbc(uVar3);
      goto LAB_0001aef8;
    }
    bVar1 = *(byte *)(iVar2 + 0x35);
    iVar4 = FUN_0001a460(param_1 + 0x14,iVar2,*(undefined *)(param_1 + 9),2);
    if (iVar4 != 0) {
      FUN_00012dbc(uVar3);
      goto LAB_0001aef8;
    }
    *(int *)(iVar2 + 0x44) = param_1;
    if (bVar1 < *(byte *)(param_1 + 0x1d)) {
      *(byte *)(param_1 + 0x1d) = bVar1;
      if (bVar1 < *(byte *)(*(int *)(param_1 + 0x20) + 0x35)) {
        FUN_0001aa80(*(int *)(param_1 + 0x20),bVar1,2);
      }
    }
    if (0 < local_2c) {
      FUN_0001efae(iVar2 + 0x58,0,&local_2c);
      FUN_0001ee68(iVar2 + 0x58);
    }
    FUN_00012dbc(uVar3);
    FUN_0001e128();
    uVar3 = FUN_00012db4();
    if (*(int *)(iVar2 + 0x30) != 0) {
      iVar4 = *(int *)(param_1 + 0x20);
      bVar8 = false;
      if ((iVar4 != 0) && (*(char *)(iVar4 + 0x35) == *(char *)(iVar2 + 0x35))) {
        bVar8 = true;
      }
      if (*(int *)(param_1 + 0x14) == param_1 + 0x14) {
        *(undefined *)(param_1 + 0x1d) = 0xff;
      }
      else {
        *(undefined *)(param_1 + 0x1d) = *(undefined *)(*(int *)(param_1 + 0x14) + 0x21);
      }
      if (bVar8) {
        uVar7 = FUN_0001aa56(iVar4);
        if (*(byte *)(*(int *)(param_1 + 0x20) + 0x35) != uVar7) {
          FUN_0001aa80(*(int *)(param_1 + 0x20),uVar7,2);
        }
      }
      FUN_00012dbc(uVar3);
      *(undefined4 *)(iVar2 + 0x44) = 0;
      iVar4 = *(int *)(iVar2 + 0x30);
      if (0 < iVar4) {
        iVar4 = -iVar4;
      }
      goto LAB_0001aef8;
    }
  }
  FUN_00012dbc(uVar3);
  if (*DAT_0001b258 != (code *)0x0) {
    (**DAT_0001b258)(param_1);
  }
  iVar4 = 0;
LAB_0001aef8:
  return CONCAT44(param_1,iVar4);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0001b02a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  undefined uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_28;
  
  local_28 = param_4;
  if (param_1 == 0) {
    FUN_0001cdc6(s_mutex____RT_NULL_0001ae0c,DAT_0001b24c + 0xf,0x599);
  }
  iVar4 = FUN_0001de70(param_1);
  if (iVar4 != 3) {
    FUN_0001cdc6(DAT_0001b250,DAT_0001b24c + 0xf,0x59a);
  }
  bVar2 = false;
  uVar5 = FUN_00012db4();
  iVar4 = FUN_0001e356();
  if (iVar4 == 0) {
    FUN_0001cd4c(s_Function__s__shall_not_be_used_b_0001a9c0,DAT_0001b24c + 0xf);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001b24c + 0xf,0x59f);
  }
  uVar6 = FUN_00012db4();
  iVar4 = FUN_0001c8d4();
  if (iVar4 != 0) {
    FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001a904,DAT_0001b24c + 0xf);
    FUN_0001cdc6(&DAT_0001a86c,DAT_0001b24c + 0xf,0x59f);
  }
  FUN_00012dbc(uVar6);
  FUN_00012dbc(uVar5);
  iVar4 = FUN_0001e356();
  uVar5 = FUN_00012db4();
  if (*_DAT_0001b25c != (code *)0x0) {
    (**_DAT_0001b25c)(param_1);
  }
  if (*(int *)(param_1 + 0x20) == iVar4) {
    cVar1 = *(char *)(param_1 + 0x1e);
    *(char *)(param_1 + 0x1e) = cVar1 + -1;
    if (cVar1 == '\x01') {
      FUN_0001c820();
      if ((*(char *)(param_1 + 0x1c) != -1) ||
         (*(char *)(iVar4 + 0x35) == *(char *)(param_1 + 0x1d))) {
        local_28._0_1_ = 0xff;
        uVar3 = FUN_0001aa56(iVar4);
        local_28 = CONCAT31(local_28._1_3_,uVar3);
        FUN_0001eb0c(iVar4,2,&local_28);
        bVar2 = true;
      }
      iVar4 = *(int *)(param_1 + 0x14);
      if (iVar4 == param_1 + 0x14) {
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined *)(param_1 + 0x1d) = 0xff;
        FUN_00012dbc(uVar5);
        if (!bVar2) {
          return 0;
        }
      }
      else {
        FUN_0001c820(iVar4);
        *(int *)(param_1 + 0x20) = iVar4 + -0x14;
        *(undefined *)(param_1 + 0x1e) = 1;
        FUN_0001c804(iVar4 + 0x28,param_1 + 0x24);
        *(undefined4 *)(iVar4 + 0x30) = 0;
        FUN_0001e4e2(iVar4 + -0x14);
        if (*(int *)(param_1 + 0x14) == param_1 + 0x14) {
          *(undefined *)(param_1 + 0x1d) = 0xff;
        }
        else {
          *(undefined *)(param_1 + 0x1d) = *(undefined *)(*(int *)(param_1 + 0x14) + 0x21);
        }
        FUN_00012dbc(uVar5);
      }
      FUN_0001e128();
    }
    else {
      FUN_00012dbc(uVar5);
    }
    return 0;
  }
  *(undefined4 *)(iVar4 + 0x30) = 0xffffff01;
  FUN_00012dbc(uVar5);
  return 0xffffff01;
}




void FUN_0001c804(int *param_1,int *param_2)

{
  *(int **)(*param_1 + 4) = param_2;
  *param_2 = *param_1;
  *param_1 = (int)param_2;
  param_2[1] = (int)param_1;
  return;
}




void FUN_0001c812(int param_1,int *param_2)

{
  **(int ***)(param_1 + 4) = param_2;
  param_2[1] = *(int *)(param_1 + 4);
  *(int **)(param_1 + 4) = param_2;
  *param_2 = param_1;
  return;
}




void FUN_0001c820(int *param_1)

{
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  return;
}




undefined4 FUN_0001c84c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  FUN_0001e4e2(iVar1 + -0x14);
  return 0;
}




undefined4 FUN_0001c85e(int **param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  while ((int **)*param_1 != param_1) {
    uVar1 = FUN_00012db4();
    iVar2 = (int)*param_1;
    *(undefined4 *)(iVar2 + 0x1c) = 0xffffff01;
    FUN_0001e4e2(iVar2 + -0x14);
    FUN_00012dbc(uVar1);
  }
  return 0;
}




void FUN_0001c894(void)

{
  char *pcVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_00012db4();
  pcVar1 = DAT_0001c8ec;
  *DAT_0001c8ec = *DAT_0001c8ec + '\x01';
  if (*(code **)(pcVar1 + 4) != (code *)0x0) {
    (**(code **)(pcVar1 + 4))();
  }
  FUN_00012dbc(uVar2);
  return;
}




undefined FUN_0001c8d4(void)

{
  undefined uVar1;
  
  FUN_00012db4();
  uVar1 = *DAT_0001c8ec;
  FUN_00012dbc();
  return uVar1;
}




undefined4 FUN_0001c8e6(void)

{
  return 0;
}




void FUN_0001c8f0(void)

{
  return;
}




char * FUN_0001c8f2(char *param_1,char *param_2,uint param_3,uint param_4,int param_5,int param_6,
                   int param_7,uint param_8)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  char acStack_51 [33];
  undefined4 local_30;
  int local_2c;
  
  cVar4 = '\0';
  FUN_00023966(acStack_51 + 1,0x20);
  iVar1 = 0;
  local_2c = param_7;
  iVar2 = DAT_0001cd1c;
  if (-1 < (int)(param_8 << 0x19)) {
    iVar2 = DAT_0001cd1c + -0x11;
  }
  if ((int)(param_8 << 0x1b) < 0) {
    param_8 = param_8 & 0xfffffffe;
  }
  if ((param_8 & 1) == 0) {
    local_30 = 0x20;
  }
  else {
    local_30 = 0x30;
  }
  if ((int)(param_8 << 0x1e) < 0) {
    if ((param_5 == 0x4c) || (param_5 != 0x68)) {
      if (-1 < (int)param_3) goto LAB_0001c968;
      cVar4 = '-';
      param_3 = -param_3;
    }
    else if ((short)param_3 < 0) {
      cVar4 = '-';
      param_3 = -param_3 & 0xffff;
    }
    else {
LAB_0001c968:
      if ((int)(param_8 << 0x1d) < 0) {
        cVar4 = '+';
      }
      else if ((int)(param_8 << 0x1c) < 0) {
        cVar4 = ' ';
      }
    }
  }
  if ((int)(param_8 << 0x1a) < 0) {
    if ((param_4 == 2) || (param_4 == 0x10)) {
      param_6 = param_6 + -2;
    }
    else if (param_4 == 8) {
      param_6 = param_6 + -1;
    }
  }
  if (param_3 == 0) {
    acStack_51[1] = 0x30;
    iVar1 = 1;
  }
  else {
    do {
      iVar5 = param_3 - param_4 * (param_3 / param_4);
      param_3 = param_3 / param_4;
      acStack_51[iVar1 + 1] = *(char *)(iVar2 + iVar5);
      iVar1 = iVar1 + 1;
    } while (param_3 != 0);
  }
  if (param_7 < iVar1) {
    param_7 = iVar1;
  }
  param_6 = param_6 - param_7;
  if ((param_8 & 0x11) == 0) {
    iVar2 = param_6;
    if ((cVar4 != '\0') && (0 < param_6)) {
      iVar2 = param_6 + -1;
    }
    while (param_6 = iVar2 + -1, 0 < iVar2) {
      if (param_1 < param_2) {
        *param_1 = ' ';
      }
      param_1 = param_1 + 1;
      iVar2 = param_6;
    }
  }
  if (cVar4 != '\0') {
    if (param_1 < param_2) {
      *param_1 = cVar4;
    }
    param_6 = param_6 + -1;
    param_1 = param_1 + 1;
  }
  if (-1 < (int)(param_8 << 0x1a)) goto LAB_0001ca5a;
  if (param_4 == 2) {
    if (param_1 < param_2) {
      *param_1 = '0';
    }
    pcVar3 = param_1 + 1;
    if (pcVar3 < param_2) {
      cVar4 = 'b';
LAB_0001ca56:
      param_1[1] = cVar4;
      pcVar3 = param_1 + 1;
    }
  }
  else if (param_4 == 8) {
    pcVar3 = param_1;
    if (param_1 < param_2) {
      *param_1 = '0';
    }
  }
  else {
    if (param_4 != 0x10) goto LAB_0001ca5a;
    if (param_1 < param_2) {
      *param_1 = '0';
    }
    pcVar3 = param_1 + 1;
    if (param_1 + 1 < param_2) {
      if ((int)(param_8 << 0x19) < 0) {
        cVar4 = 'X';
      }
      else {
        cVar4 = 'x';
      }
      goto LAB_0001ca56;
    }
  }
  param_1 = pcVar3 + 1;
LAB_0001ca5a:
  iVar2 = param_6;
  if (-1 < (int)(param_8 << 0x1b)) {
    while (param_6 = iVar2 + -1, 0 < iVar2) {
      if (param_1 < param_2) {
        *param_1 = (char)local_30;
      }
      param_1 = param_1 + 1;
      iVar2 = param_6;
    }
  }
  while (iVar1 < param_7) {
    if (param_1 < param_2) {
      *param_1 = '0';
    }
    param_1 = param_1 + 1;
    param_7 = param_7 + -1;
  }
  while ((0 < iVar1 && (local_2c != 0))) {
    if (param_1 < param_2) {
      *param_1 = acStack_51[iVar1];
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  }
  while (0 < param_6) {
    if (param_1 < param_2) {
      *param_1 = ' ';
    }
    param_1 = param_1 + 1;
    param_6 = param_6 + -1;
  }
  return param_1;
}




int FUN_0001caba(byte *param_1,int param_2,byte *param_3,byte **param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte **ppbVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  byte *local_2c;
  byte **local_28;
  
  pbVar12 = param_1 + param_2;
  pbVar9 = param_1;
  local_2c = param_3;
  local_28 = param_4;
  if (pbVar12 < param_1) {
    pbVar12 = (byte *)0xffffffff;
    param_2 = -1 - (int)param_1;
  }
  do {
    bVar2 = *local_2c;
    if (bVar2 == 0) {
      if (param_2 != 0) {
        if (pbVar9 < pbVar12) {
          *pbVar9 = 0;
        }
        else {
          pbVar12[-1] = 0;
        }
      }
      return (int)pbVar9 - (int)param_1;
    }
    if (bVar2 != 0x25) {
      if (pbVar9 < pbVar12) {
LAB_0001cae6:
        *pbVar9 = bVar2;
      }
LAB_0001cbf4:
      pbVar9 = pbVar9 + 1;
      goto LAB_0001ccfc;
    }
    uVar11 = 0;
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              pbVar4 = local_2c + 1;
              bVar2 = *pbVar4;
              if (bVar2 != 0x2d) break;
              uVar11 = uVar11 | 0x10;
              local_2c = pbVar4;
            }
            if (bVar2 != 0x2b) break;
            uVar11 = uVar11 | 4;
            local_2c = pbVar4;
          }
          if (bVar2 != 0x20) break;
          uVar11 = uVar11 | 8;
          local_2c = pbVar4;
        }
        if (bVar2 != 0x23) break;
        uVar11 = uVar11 | 0x20;
        local_2c = pbVar4;
      }
      if (bVar2 != 0x30) break;
      uVar11 = uVar11 | 1;
      local_2c = pbVar4;
    }
    pbVar10 = (byte *)0xffffffff;
    if (*pbVar4 - 0x30 < 10) {
      local_2c = pbVar4;
      pbVar10 = (byte *)FUN_0001d414(&local_2c);
      pbVar4 = local_2c;
    }
    else if (bVar2 == 0x2a) {
      pbVar10 = *local_28;
      local_28 = local_28 + 1;
      pbVar4 = local_2c + 2;
      if ((int)pbVar10 < 0) {
        pbVar10 = (byte *)-(int)pbVar10;
        uVar11 = uVar11 | 0x10;
      }
    }
    local_2c = pbVar4;
    pbVar4 = (byte *)0xffffffff;
    if (*local_2c == 0x2e) {
      pbVar3 = local_2c + 1;
      if (*pbVar3 - 0x30 < 10) {
        local_2c = pbVar3;
        pbVar4 = (byte *)FUN_0001d414(&local_2c);
LAB_0001cb84:
        pbVar3 = local_2c;
        if (-1 < (int)pbVar4) goto LAB_0001cb8e;
      }
      else if (*pbVar3 == 0x2a) {
        local_2c = local_2c + 2;
        pbVar4 = *local_28;
        local_28 = local_28 + 1;
        goto LAB_0001cb84;
      }
      local_2c = pbVar3;
      pbVar4 = (byte *)0x0;
    }
LAB_0001cb8e:
    bVar2 = *local_2c;
    if ((bVar2 == 0x68) || (bVar1 = 0, bVar2 == 0x6c)) {
      local_2c = local_2c + 1;
      bVar1 = bVar2;
    }
    bVar2 = *local_2c;
    uVar8 = 10;
    if (bVar2 == 0x69) {
LAB_0001ccda:
      uVar11 = uVar11 | 2;
LAB_0001ccde:
      if ((bVar1 == 0x6c) || (bVar1 != 0x68)) {
        pbVar3 = *local_28;
      }
      else {
        pbVar3 = (byte *)(uint)*(ushort *)local_28;
        if ((int)(uVar11 << 0x1e) < 0) {
          pbVar3 = (byte *)(int)(short)*(ushort *)local_28;
        }
      }
LAB_0001ccf4:
      local_28 = local_28 + 1;
      pbVar9 = (byte *)FUN_0001c8f2(pbVar9,pbVar12,pbVar3,uVar8,bVar1,pbVar10,pbVar4,uVar11);
    }
    else {
      if (bVar2 < 0x6a) {
        if (bVar2 != 0x62) {
          if (bVar2 < 99) {
            if (bVar2 == 0x25) {
              if (pbVar9 < pbVar12) {
                bVar2 = 0x25;
                goto LAB_0001cae6;
              }
              goto LAB_0001cbf4;
            }
            if (bVar2 == 0x58) {
              uVar11 = uVar11 | 0x40;
LAB_0001ccd6:
              uVar8 = 0x10;
              goto LAB_0001ccde;
            }
          }
          else {
            if (bVar2 == 99) {
              if (-1 < (int)(uVar11 << 0x1b)) {
                while (pbVar10 = pbVar10 + -1, 0 < (int)pbVar10) {
                  if (pbVar9 < pbVar12) {
                    *pbVar9 = 0x20;
                  }
                  pbVar9 = pbVar9 + 1;
                }
              }
              ppbVar5 = local_28 + 1;
              if (pbVar9 < pbVar12) {
                *pbVar9 = *(byte *)local_28;
              }
              while( true ) {
                pbVar9 = pbVar9 + 1;
                pbVar10 = pbVar10 + -1;
                local_28 = ppbVar5;
                if ((int)pbVar10 < 1) break;
                if (pbVar9 < pbVar12) {
                  *pbVar9 = 0x20;
                }
              }
              goto LAB_0001ccfc;
            }
            if (bVar2 == 100) goto LAB_0001ccda;
          }
          goto LAB_0001cbde;
        }
        uVar8 = 2;
        goto LAB_0001ccde;
      }
      if (bVar2 != 0x73) {
        if (0x73 < bVar2) {
          if (bVar2 == 0x75) goto LAB_0001ccde;
          if (bVar2 == 0x78) goto LAB_0001ccd6;
LAB_0001cbde:
          if (pbVar9 < pbVar12) {
            *pbVar9 = 0x25;
          }
          pbVar9 = pbVar9 + 1;
          if (*local_2c != 0) {
            if (pbVar9 < pbVar12) {
              *pbVar9 = *local_2c;
            }
            goto LAB_0001cbf4;
          }
          local_2c = local_2c + -1;
          goto LAB_0001ccfc;
        }
        if (bVar2 == 0x6f) {
          uVar8 = 8;
          goto LAB_0001ccde;
        }
        if (bVar2 != 0x70) goto LAB_0001cbde;
        if (pbVar10 == (byte *)0xffffffff) {
          pbVar10 = (byte *)((int)&NMI + 2);
          uVar11 = uVar11 | 0x21;
        }
        uVar8 = 0x10;
        pbVar3 = *local_28;
        goto LAB_0001ccf4;
      }
      pcVar6 = (char *)*local_28;
      local_28 = local_28 + 1;
      if ((byte *)pcVar6 == (byte *)0x0) {
        pcVar6 = s__NULL__0001cd20;
      }
      for (pbVar3 = (byte *)0x0; (pbVar3 != pbVar10 && (((byte *)pcVar6)[(int)pbVar3] != 0));
          pbVar3 = pbVar3 + 1) {
      }
      if ((0 < (int)pbVar4) && ((int)pbVar4 < (int)pbVar3)) {
        pbVar3 = pbVar4;
      }
      pbVar4 = pbVar10;
      if (-1 < (int)(uVar11 << 0x1b)) {
        while (pbVar10 = pbVar4 + -1, (int)pbVar3 < (int)pbVar4) {
          if (pbVar9 < pbVar12) {
            *pbVar9 = 0x20;
          }
          pbVar9 = pbVar9 + 1;
          pbVar4 = pbVar10;
        }
      }
      for (iVar7 = 0; iVar7 < (int)pbVar3; iVar7 = iVar7 + 1) {
        if (pbVar9 < pbVar12) {
          *pbVar9 = *pcVar6;
        }
        pcVar6 = (char *)((byte *)pcVar6 + 1);
        pbVar9 = pbVar9 + 1;
      }
      while ((int)pbVar3 < (int)pbVar10) {
        if (pbVar9 < pbVar12) {
          *pbVar9 = 0x20;
        }
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + -1;
      }
    }
LAB_0001ccfc:
    local_2c = local_2c + 1;
  } while( true );
}




uint FUN_0001cd4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = DAT_0001d130;
  if (DAT_0001d130[1] == 0) {
    DAT_0001d130[1] = 1;
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    uVar2 = FUN_0001caba(DAT_0001d134,0x3ff,param_1,&uStack_c);
    if (0x3ff < uVar2) {
      uVar2 = 0x3ff;
    }
    iVar3 = *piVar1;
    if (iVar3 == 0) {
      FUN_0001c8f0(DAT_0001d134);
    }
    else {
      FUN_00013708(iVar3,0,DAT_0001d134,uVar2);
    }
    piVar1[1] = 0;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* WARNING: Removing unreachable block (ram,0x0001cdf4) */

void FUN_0001cdc6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(code **)(DAT_0001d130 + 0x18) == (code *)0x0) {
    FUN_0001cd4c(s___s__assertion_failed_at_functio_0001d160,param_1,param_2,param_3);
    do {
    } while( true );
  }
                    /* WARNING: Could not recover jumptable at 0x0001cddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_0001d130 + 0x18))();
  return;
}




void FUN_0001cdf6(void)

{
  int iVar1;
  
  FUN_0001cd4c(&DAT_0001d138);
  FUN_0001cd4c(DAT_0001d198);
  FUN_0001cd4c(&DAT_0001d154);
  iVar1 = FUN_00012db4();
  while (iVar1 != 0) {
    FUN_0001cdc6(s_RT_NULL_0001d1a0,DAT_0001d19c,0x59);
  }
  return;
}




char * FUN_0001ce26(int param_1)

{
  uint uVar1;
  
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  uVar1 = 0;
  do {
    if (*(int *)(DAT_0001d130 + 0x1c + uVar1 * 8) == param_1) {
      return *(char **)(DAT_0001d130 + 0x1c + uVar1 * 8 + 4);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0xf);
  return s_EUNKNOW_0001d1b0;
}




undefined4 FUN_0001ce4e(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0001c8d4();
  iVar1 = DAT_0001d130;
  if ((iVar2 == 0) && (iVar2 = FUN_0001e356(), iVar2 != 0)) {
    return *(undefined4 *)(iVar2 + 0x30);
  }
  return *(undefined4 *)(iVar1 + 8);
}




void FUN_0001ce66(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0001c8d4();
  iVar1 = DAT_0001d130;
  if ((iVar2 == 0) && (iVar2 = FUN_0001e356(), iVar2 != 0)) {
    *(undefined4 *)(iVar2 + 0x30) = param_1;
    return;
  }
  *(undefined4 *)(iVar1 + 8) = param_1;
  return;
}




int FUN_0001ce80(void)

{
  int iVar1;
  
  iVar1 = FUN_0001c8d4();
  if ((iVar1 == 0) && (iVar1 = FUN_0001e356(), iVar1 != 0)) {
    return iVar1 + 0x30;
  }
  return DAT_0001d130 + 8;
}




void FUN_0001ce98(undefined4 *param_1,undefined param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  undefined4 local_10;
  
  uVar1 = 0;
  local_10 = 0;
  if ((3 < param_3) && (((uint)param_1 & 3) == 0)) {
    do {
      *(undefined *)((int)&local_10 + uVar1) = param_2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 4);
    for (; 0xf < param_3; param_3 = param_3 - 0x10) {
      *param_1 = local_10;
      param_1[1] = local_10;
      param_1[2] = local_10;
      param_1[3] = local_10;
      param_1 = param_1 + 4;
    }
    for (; 3 < param_3; param_3 = param_3 - 4) {
      *param_1 = local_10;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined *)param_1 = param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}




void FUN_0001ceee(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  
  if ((0xf < param_3) &&
     (puVar1 = param_2, puVar2 = param_1, (((uint)param_2 | (uint)param_1) & 3) == 0)) {
    do {
      param_3 = param_3 - 0x10;
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      param_2 = puVar1 + 4;
      param_1 = puVar2 + 4;
      puVar2[2] = puVar1[2];
      puVar2[3] = puVar1[3];
      puVar1 = param_2;
      puVar2 = param_1;
    } while (0xf < param_3);
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar3;
      param_1 = param_1 + 1;
    }
  }
  while (bVar4 = param_3 != 0, param_3 = param_3 - 1, bVar4) {
    *(undefined *)param_1 = *(undefined *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}




void FUN_0001cf3a(undefined *param_1,undefined *param_2,int param_3)

{
  undefined *puVar1;
  bool bVar2;
  
  if ((param_2 < param_1) && (puVar1 = param_2 + param_3, param_1 < puVar1)) {
    param_1 = param_1 + param_3;
    while (bVar2 = param_3 != 0, param_3 = param_3 + -1, bVar2) {
      puVar1 = puVar1 + -1;
      param_1 = param_1 + -1;
      *param_1 = *puVar1;
    }
    return;
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 + -1, bVar2) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}




int FUN_0001cf6a(byte *param_1,byte *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (param_3 != 0 && (iVar1 = (uint)*param_1 - (uint)*param_2, iVar1 == 0));
      param_1 = param_1 + 1) {
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  }
  return iVar1;
}




int FUN_0001cf86(char *param_1)

{
  char *pcVar1;
  
  for (pcVar1 = param_1; *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
  }
  return (int)pcVar1 - (int)param_1;
}




int FUN_0001cf96(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0001cf86(param_2);
  if (iVar1 != 0) {
    iVar2 = FUN_0001cf86(param_1);
    while( true ) {
      if (iVar2 < iVar1) {
        return 0;
      }
      iVar2 = iVar2 + -1;
      iVar3 = FUN_0001cf6a(param_1,param_2,iVar1);
      if (iVar3 == 0) break;
      param_1 = param_1 + 1;
    }
  }
  return param_1;
}




int FUN_0001cfcc(byte *param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  
  do {
    uVar1 = (uint)*param_1;
    uVar2 = (uint)*param_2;
    if (uVar1 - 0x41 < 0x1a) {
      uVar1 = uVar1 + 0x20;
    }
    if (uVar2 - 0x41 < 0x1a) {
      uVar2 = uVar2 + 0x20;
    }
  } while ((uVar1 == uVar2) && (param_1 = param_1 + 1, param_2 = param_2 + 1, uVar1 != 0));
  return uVar1 - uVar2;
}




void FUN_0001cff8(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  
  if (param_3 != 0) {
    do {
      cVar1 = *param_2;
      pcVar2 = param_1 + 1;
      *param_1 = cVar1;
      if (cVar1 == '\0') {
        while (param_3 = param_3 + -1, param_3 != 0) {
          *pcVar2 = '\0';
          pcVar2 = pcVar2 + 1;
        }
        return;
      }
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
      param_1 = pcVar2;
    } while (param_3 != 0);
  }
  return;
}




int FUN_0001d038(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    cVar1 = *param_1;
    iVar2 = (int)(char)(cVar1 - *param_2);
    if (iVar2 != 0) break;
    param_1 = param_1 + 1;
    if (cVar1 == '\0') {
      return 0;
    }
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  }
  return iVar2;
}




int thunk_FUN_0001d05e(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  while( true ) {
    bVar1 = *param_1;
    if ((bVar1 == 0) || (bVar1 != *param_2)) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return (uint)bVar1 - (uint)*param_2;
}




int FUN_0001d05e(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  while( true ) {
    bVar1 = *param_1;
    if ((bVar1 == 0) || (bVar1 != *param_2)) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return (uint)bVar1 - (uint)*param_2;
}




undefined4 FUN_0001d084(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = FUN_0001d462();
  iVar1 = DAT_0001d130;
  uVar3 = FUN_0001d61e(*(undefined4 *)(DAT_0001d130 + 0x14),param_1);
  FUN_0001d43c(uVar2);
  if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
    (**(code **)(iVar1 + 0xc))(uVar3,param_1);
  }
  return uVar3;
}




int FUN_0001d0b2(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0001cf86();
  iVar2 = FUN_0001d084();
  if (iVar2 != 0) {
    FUN_0001ceee(iVar2,param_1,iVar1 + 1);
    return iVar2;
  }
  return 0;
}




void FUN_0001d0d6(void)

{
  FUN_0001cd4c(s_______0001d1b8);
  FUN_0001cd4c(s___RT___Thread_Operating_System_0001d1c4);
  FUN_0001cd4c(s________d__d__d_build__s__s_0001d200,5,0,2,s_Apr_16_2026_0001d1f4,
               s_11_37_35_0001d1e8);
  FUN_0001cd4c(s_2006___2022_Copyright_by_RT_Thre_0001d224);
  return;
}




void FUN_0001d100(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  FUN_0001caba(param_1,param_2,param_3,&uStack_4);
  return;
}




void FUN_0001d112(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0001caba(param_1,0xffffffff,param_2,param_3);
  return;
}




void FUN_0001d122(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0001d112(param_1,param_2,&uStack_8);
  return;
}




undefined4 FUN_0001d250(void)

{
  return *DAT_0001d47c;
}




int FUN_0001d256(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_0001d47c;
  iVar3 = *DAT_0001d47c;
  iVar2 = FUN_0001344c();
  if (iVar2 == iVar3) {
    return 0;
  }
  if (iVar2 != 0) {
    if (*piVar1 != 0) {
      FUN_00013644();
    }
    FUN_0001357e(iVar2,0x43);
    *piVar1 = iVar2;
  }
  return iVar3;
}




void FUN_0001d282(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_0001d47c;
  if (param_1 != 0) {
    if (*DAT_0001d47c != 0) {
      uVar2 = FUN_0001cf86();
      FUN_00013708(*piVar1,0,param_1,uVar2);
      return;
    }
    FUN_0001c8f0(param_1);
  }
  return;
}




void FUN_0001d2b8(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 7U & 0xfffffff8;
  if ((param_2 & 0xfffffff8) <= uVar2) {
    FUN_0001cdc6(s_end_align_>_begin_align_0001d484,DAT_0001d480,0x6af);
  }
  uVar1 = FUN_0001d544(&DAT_0001d49c,param_1,(param_2 & 0xfffffff8) - uVar2);
  *(undefined4 *)(DAT_0001d47c + 0x14) = uVar1;
  FUN_0001ab02(DAT_0001d4ac,&DAT_0001d4a4,1);
  return;
}




undefined4 FUN_0001d2f2(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0001d462();
  uVar2 = FUN_0001d83c(*(undefined4 *)(DAT_0001d47c + 0x14),param_1,param_2);
  FUN_0001d43c(uVar1);
  return uVar2;
}




int FUN_0001d316(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0001d084();
  if (iVar1 != 0) {
    FUN_0001ce98(iVar1,0,param_2 * param_1);
  }
  return iVar1;
}




void FUN_0001d330(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_0001d47c + 0x10) != (code *)0x0) {
    (**(code **)(DAT_0001d47c + 0x10))(param_1);
  }
  if (param_1 != 0) {
    uVar1 = FUN_0001d462();
    FUN_0001d76a(param_1);
    FUN_0001d43c(uVar1);
    return;
  }
  return;
}




void FUN_0001d35a(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_0001d462();
  iVar1 = DAT_0001d47c;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(*(int *)(DAT_0001d47c + 0x14) + 0x1c);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x20);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x24);
  }
  FUN_0001d43c(uVar2);
  return;
}




uint FUN_0001d38c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 + 3U & 0xfffffffc;
  uVar1 = FUN_0001d084((param_1 + 3U & 0xfffffffc) + uVar3);
  uVar2 = uVar1;
  if (uVar1 != 0) {
    if ((uVar1 & uVar3 - 1) == 0) {
      uVar2 = uVar1 + uVar3;
    }
    else {
      uVar2 = (uVar1 + uVar3) - 1 & ~(uVar3 - 1);
    }
    *(uint *)(uVar2 - 4) = uVar1;
  }
  return uVar2;
}




void FUN_0001d3be(int param_1)

{
  if (param_1 != 0) {
    FUN_0001d330(*(undefined4 *)(param_1 + -4));
  }
  return;
}




uint FUN_0001d3ce(uint param_1)

{
  if (param_1 != 0) {
    if ((param_1 & 0xff) == 0) {
      if ((param_1 & 0xff00) != 0) {
        return *(byte *)(DAT_0001d4b0 + ((param_1 << 0x10) >> 0x18)) + 9;
      }
      if ((param_1 & 0xff0000) != 0) {
        return *(byte *)(DAT_0001d4b0 + ((param_1 << 8) >> 0x18)) + 0x11;
      }
      return *(byte *)(DAT_0001d4b0 + (param_1 >> 0x18)) + 0x19;
    }
    param_1 = *(byte *)(DAT_0001d4b0 + (param_1 & 0xff)) + 1;
  }
  return param_1;
}




int FUN_0001d414(byte **param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  while (pbVar2 = *param_1, *pbVar2 - 0x30 < 10) {
    *param_1 = pbVar2 + 1;
    iVar1 = iVar1 * 10 + -0x30 + (uint)*pbVar2;
  }
  return iVar1;
}




void FUN_0001d43c(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_0001cdc6(s_level____RT_EOK_0001d4b4,DAT_0001d480 + -0xd,0x64e);
  }
  iVar1 = FUN_0001e356();
  if (iVar1 != 0) {
    FUN_0001b02a(DAT_0001d4ac);
    return;
  }
  return;
}




void FUN_0001d462(void)

{
  int iVar1;
  
  iVar1 = FUN_0001e356();
  if (iVar1 != 0) {
    FUN_0001b018(DAT_0001d4ac,0xffffffff);
    return;
  }
  return;
}




void FUN_0001d4c4(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (param_2 < *(undefined4 **)(param_1 + 0x28)) {
    FUN_0001cdc6(s__rt_uint8_t___mem_>__m_>heap_ptr_0001d8bc,DAT_0001d8b8,0x85);
  }
  if (*(undefined4 **)(param_1 + 0x2c) <= param_2) {
    FUN_0001cdc6(s__rt_uint8_t___mem_<_(rt_uint8_t_*_0001d8e0,DAT_0001d8b8,0x86);
  }
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x28) + param_2[1]);
  if (((param_2 != puVar1) && ((*(byte *)puVar1 & 1) == 0)) &&
     (*(undefined4 **)(param_1 + 0x2c) != puVar1)) {
    if (*(undefined4 **)(param_1 + 0x30) == puVar1) {
      *(undefined4 **)(param_1 + 0x30) = param_2;
    }
    *puVar1 = 0;
    param_2[1] = puVar1[1];
    *(int *)(puVar1[1] + *(int *)(param_1 + 0x28) + 8) = (int)param_2 - *(int *)(param_1 + 0x28);
  }
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x28) + param_2[2]);
  if ((puVar1 != param_2) && ((*(byte *)puVar1 & 1) == 0)) {
    if (*(undefined4 **)(param_1 + 0x30) == param_2) {
      *(undefined4 **)(param_1 + 0x30) = puVar1;
    }
    *param_2 = 0;
    puVar1[1] = param_2[1];
    *(int *)(*(int *)(param_1 + 0x28) + param_2[1] + 8) = (int)puVar1 - *(int *)(param_1 + 0x28);
  }
  return;
}




uint FUN_0001d544(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  uVar2 = param_2 + 7U & 0xfffffff8;
  puVar3 = (uint *)(uVar2 + 0x38);
  uVar1 = param_3 + param_2 & 0xfffffff8;
  if ((uVar1 < 0x21) || (uVar1 - 0x20 < uVar2 + 0x38)) {
    FUN_0001cd4c(s_mem_init__error_begin_address_0x_0001d918,param_2,param_3 + param_2);
    uVar2 = 0;
  }
  else {
    iVar4 = (uVar1 - (int)puVar3) + -0x20;
    FUN_0001ce98(uVar2,0,0x38);
    FUN_0001dcae(uVar2,0xc,param_1);
    *(char **)(uVar2 + 0x14) = s_small_0001d910;
    *(uint **)(uVar2 + 0x18) = puVar3;
    *(int *)(uVar2 + 0x1c) = iVar4;
    *(int *)(uVar2 + 0x34) = iVar4;
    *(uint **)(uVar2 + 0x28) = puVar3;
    *puVar3 = uVar2;
    *(int *)(uVar2 + 0x3c) = *(int *)(uVar2 + 0x34) + 0x10;
    *(undefined4 *)(uVar2 + 0x40) = 0;
    puVar3 = (uint *)(*(int *)(uVar2 + 0x28) + *(int *)(uVar2 + 0x3c));
    *(uint **)(uVar2 + 0x2c) = puVar3;
    *puVar3 = uVar2 | 1;
    *(int *)(*(int *)(uVar2 + 0x2c) + 4) = *(int *)(uVar2 + 0x34) + 0x10;
    *(int *)(*(int *)(uVar2 + 0x2c) + 8) = *(int *)(uVar2 + 0x34) + 0x10;
    *(undefined4 *)(uVar2 + 0x30) = *(undefined4 *)(uVar2 + 0x28);
  }
  return uVar2;
}




uint * FUN_0001d61e(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  if (param_2 != 0) {
    if (param_1 == 0) {
      FUN_0001cdc6(s_m____RT_NULL_0001d954,DAT_0001d8b8 + 0x1a,0x121);
    }
    iVar1 = FUN_0001de70(param_1);
    if (iVar1 != 0xc) {
      FUN_0001cdc6(s_rt_object_get_type__m_>parent____0001d964,DAT_0001d8b8 + 0x1a,0x122);
    }
    iVar1 = FUN_0001de4e(param_1);
    if (iVar1 == 0) {
      FUN_0001cdc6(s_rt_object_is_systemobject__m_>pa_0001d9a0,DAT_0001d8b8 + 0x1a,0x123);
    }
    uVar6 = param_2 + 7U & 0xfffffff8;
    if (uVar6 < 0x10) {
      uVar6 = 0x10;
    }
    if (uVar6 <= *(uint *)(param_1 + 0x34)) {
      iVar1 = *(int *)(param_1 + 0x28);
      for (uVar2 = *(int *)(param_1 + 0x30) - iVar1; uVar2 <= *(uint *)(param_1 + 0x34) - uVar6;
          uVar2 = *(uint *)(iVar1 + uVar2 + 4)) {
        puVar5 = (uint *)(iVar1 + uVar2);
        if (((*(byte *)puVar5 & 1) == 0) && (uVar6 <= (puVar5[1] - uVar2) - 0x10)) {
          if ((puVar5[1] - uVar2) - 0x10 < uVar6 + 0x20) {
            uVar2 = (puVar5[1] - ((int)puVar5 - iVar1)) + *(int *)(param_1 + 0x20);
          }
          else {
            uVar3 = uVar2 + uVar6 + 0x10;
            puVar4 = (uint *)(iVar1 + uVar3);
            *puVar4 = param_1 & 0xfffffffe;
            puVar4[1] = puVar5[1];
            puVar4[2] = uVar2;
            puVar5[1] = uVar3;
            if (puVar4[1] != *(int *)(param_1 + 0x34) + 0x10U) {
              *(uint *)(puVar4[1] + *(int *)(param_1 + 0x28) + 8) = uVar3;
            }
            uVar2 = uVar6 + 0x10 + *(int *)(param_1 + 0x20);
          }
          *(uint *)(param_1 + 0x20) = uVar2;
          if (*(uint *)(param_1 + 0x24) < uVar2) {
            *(uint *)(param_1 + 0x24) = uVar2;
          }
          *puVar5 = param_1 | 1;
          puVar4 = *(uint **)(param_1 + 0x30);
          if (puVar4 == puVar5) {
            while (((*(byte *)puVar4 & 1) != 0 && (puVar4 != *(uint **)(param_1 + 0x2c)))) {
              puVar4 = (uint *)(puVar4[1] + *(int *)(param_1 + 0x28));
              *(uint **)(param_1 + 0x30) = puVar4;
            }
            if ((puVar4 != *(uint **)(param_1 + 0x2c)) && ((*(byte *)puVar4 & 1) != 0)) {
              FUN_0001cdc6(DAT_0001d9c8,DAT_0001d8b8 + 0x1a,0x188);
            }
          }
          if (*(byte **)(param_1 + 0x2c) < (byte *)((int)puVar5 + uVar6 + 0x10)) {
            FUN_0001cdc6(DAT_0001d9cc,DAT_0001d8b8 + 0x1a,0x18a);
          }
          if (((uint)puVar5 & 7) != 0) {
            FUN_0001cdc6(DAT_0001d9d0,DAT_0001d8b8 + 0x1a,0x18b);
            FUN_0001cdc6(s____rt_ubase_t_mem_____RT_ALIGN_S_0001d9d4,DAT_0001d8b8 + 0x1a,0x18c);
          }
          return puVar5 + 4;
        }
      }
    }
  }
  return (uint *)0x0;
}




void FUN_0001d76a(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_1 != 0) {
    if ((param_1 & 7) != 0) {
      FUN_0001cdc6(s____rt_ubase_t_rmem_____RT_ALIGN__0001da04,DAT_0001d8b8 + 0x38,0x20c);
    }
    puVar4 = (uint *)(param_1 - 0x10);
    uVar1 = *puVar4;
    uVar3 = uVar1 & 0xfffffffe;
    if (uVar3 == 0) {
      FUN_0001cdc6(s_small_mem____RT_NULL_0001da34,DAT_0001d8b8 + 0x38,0x212);
    }
    if ((*(byte *)puVar4 & 1) == 0) {
      FUN_0001cdc6(s_MEM_ISUSED_mem__0001da4c,DAT_0001d8b8 + 0x38,0x213);
    }
    iVar2 = FUN_0001de70(uVar3);
    if (iVar2 != 0xc) {
      FUN_0001cdc6(DAT_0001da5c,DAT_0001d8b8 + 0x38,0x214);
    }
    iVar2 = FUN_0001de4e(uVar3);
    if (iVar2 == 0) {
      FUN_0001cdc6(s_rt_object_is_systemobject__small_0001da60,DAT_0001d8b8 + 0x38,0x215);
    }
    if ((param_1 < *(uint *)(uVar3 + 0x28)) || (*(uint *)(uVar3 + 0x2c) <= param_1)) {
      FUN_0001cdc6(DAT_0001da98,DAT_0001d8b8 + 0x38,0x216);
    }
    if ((*(uint *)(*(int *)(uVar3 + 0x28) + *(int *)(param_1 - 0xc)) & 0xfffffffe) != uVar3) {
      FUN_0001cdc6(s_MEM_POOL__small_mem_>heap_ptr_me_0001da9c,DAT_0001d8b8 + 0x38,0x218);
    }
    *puVar4 = uVar1 & 0xfffffffe;
    if (puVar4 < *(uint **)(uVar3 + 0x30)) {
      *(uint **)(uVar3 + 0x30) = puVar4;
    }
    *(int *)(uVar3 + 0x20) =
         *(int *)(uVar3 + 0x20) - (*(int *)(param_1 - 0xc) - ((int)puVar4 - *(int *)(uVar3 + 0x28)))
    ;
    FUN_0001d4c4(uVar3,puVar4);
    return;
  }
  return;
}




uint FUN_0001d83c(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_m____RT_NULL_0001d954,DAT_0001d8b8 + 0x28,0x1ae);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 0xc) {
    FUN_0001cdc6(s_rt_object_get_type__m_>parent____0001d964,DAT_0001d8b8 + 0x28,0x1af);
  }
  iVar1 = FUN_0001de4e(param_1);
  if (iVar1 == 0) {
    FUN_0001cdc6(s_rt_object_is_systemobject__m_>pa_0001d9a0,DAT_0001d8b8 + 0x28,0x1b0);
  }
  uVar4 = param_3 + 7U & 0xfffffff8;
  if (uVar4 <= *(uint *)(param_1 + 0x34)) {
    if (uVar4 != 0) {
      if (param_2 == 0) {
        uVar4 = FUN_0001d61e(param_1,uVar4);
        return uVar4;
      }
      if ((param_2 & 7) != 0) {
        FUN_0001cdc6(s____rt_ubase_t_rmem_____RT_ALIGN__0001da04,DAT_0001d8b8 + 0x28,0x1c5);
      }
      if (param_2 < *(uint *)(param_1 + 0x28)) {
        FUN_0001cdc6(s__rt_uint8_t___rmem_>___rt_uint8__0001db8c,DAT_0001db88,0x1c6);
      }
      if (*(uint *)(param_1 + 0x2c) <= param_2) {
        FUN_0001cdc6(s__rt_uint8_t___rmem_<_(rt_uint8_t_0001dbc4,DAT_0001db88,0x1c7);
      }
      uVar3 = (param_2 - 0x10) - *(int *)(param_1 + 0x28);
      uVar5 = (*(int *)(param_2 - 0xc) - uVar3) - 0x10;
      if (uVar5 == uVar4) {
        return param_2;
      }
      if (uVar4 + 0x1c < uVar5) {
        *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - (uVar5 - uVar4);
        iVar1 = uVar3 + uVar4 + 0x10;
        puVar2 = (uint *)(*(int *)(param_1 + 0x28) + iVar1);
        *puVar2 = param_1 & 0xfffffffe;
        puVar2[1] = *(uint *)(param_2 - 0xc);
        puVar2[2] = uVar3;
        *(int *)(param_2 - 0xc) = iVar1;
        if (puVar2[1] != *(int *)(param_1 + 0x34) + 0x10U) {
          *(int *)(puVar2[1] + *(int *)(param_1 + 0x28) + 8) = iVar1;
        }
        if (puVar2 < *(uint **)(param_1 + 0x30)) {
          *(uint **)(param_1 + 0x30) = puVar2;
        }
        FUN_0001d4c4(param_1);
        return param_2;
      }
      uVar3 = FUN_0001d61e(param_1,uVar4);
      if (uVar3 == 0) {
        return 0;
      }
      if (uVar5 < uVar4) {
        uVar4 = uVar5;
      }
      FUN_0001ceee(uVar3,param_2,uVar4);
      FUN_0001d76a(param_2);
      return uVar3;
    }
    FUN_0001d76a(param_2);
  }
  return 0;
}




int FUN_0001dc1a(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(byte *)(DAT_0001df74 + 0x14 + iVar1 * 0x10) == param_1) {
      return DAT_0001df74 + 0x14 + iVar1 * 0x10;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  return 0;
}




int FUN_0001dc3a(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = FUN_0001dc1a();
  if (iVar1 != 0) {
    uVar2 = FUN_00012db4();
    for (puVar3 = *(undefined4 **)(undefined4 *)(iVar1 + 4); puVar3 != (undefined4 *)(iVar1 + 4);
        puVar3 = (undefined4 *)*puVar3) {
      iVar4 = iVar4 + 1;
    }
    FUN_00012dbc(uVar2);
    return iVar4;
  }
  return 0;
}




int FUN_0001dc68(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_3 < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0001dc1a();
    if (iVar2 != 0) {
      uVar3 = FUN_00012db4();
      puVar1 = (undefined4 *)(iVar2 + 4);
      iVar2 = 0;
      for (puVar4 = (undefined4 *)*puVar1; puVar4 != puVar1; puVar4 = (undefined4 *)*puVar4) {
        *(undefined4 **)(param_2 + iVar2 * 4) = puVar4 + -3;
        iVar2 = iVar2 + 1;
        if (param_3 <= iVar2) break;
      }
      FUN_00012dbc(uVar3);
    }
  }
  return iVar2;
}




void FUN_0001dcae(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_0001dc1a(param_2);
  if (iVar1 == 0) {
    FUN_0001cdc6(s_information____RT_NULL_0001df7c,DAT_0001df78,0x16e);
  }
  FUN_0001e1fe();
  for (puVar3 = *(undefined4 **)(iVar1 + 4); puVar3 != (undefined4 *)(iVar1 + 4);
      puVar3 = (undefined4 *)*puVar3) {
    if (puVar3 + -3 == param_1) {
      FUN_0001cdc6(s_obj____object_0001df94,DAT_0001df78,0x17d);
    }
  }
  FUN_0001e214();
  *(byte *)(param_1 + 2) = (byte)param_2 | 0x80;
  FUN_0001cff8(param_1,param_3,8);
  if (*DAT_0001df74 != (code *)0x0) {
    (**DAT_0001df74)(param_1);
  }
  uVar2 = FUN_00012db4();
  FUN_0001df54(iVar1 + 4,param_1 + 3);
  FUN_00012dbc(uVar2);
  return;
}




void FUN_0001dd2c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_object____RT_NULL_0001dfa4,DAT_0001df78 + 0xf,0x1ad);
  }
  if (*(code **)(DAT_0001df74 + 4) != (code *)0x0) {
    (**(code **)(DAT_0001df74 + 4))(param_1);
  }
  *(undefined *)(param_1 + 8) = 0;
  uVar1 = FUN_00012db4();
  FUN_0001df62(param_1 + 0xc);
  FUN_00012dbc(uVar1);
  return;
}




int FUN_0001dd66(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_00012db4();
  iVar2 = FUN_0001c8d4();
  if (iVar2 != 0) {
    FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001dfb8,DAT_0001df78 + 0x20);
    FUN_0001cdc6(&LAB_0001dfe0,DAT_0001df78 + 0x20,0x1d1);
  }
  FUN_00012dbc(uVar1);
  iVar2 = FUN_0001dc1a(param_1);
  if (iVar2 == 0) {
    FUN_0001cdc6(s_information____RT_NULL_0001df7c,DAT_0001df78 + 0x20,0x1d5);
  }
  iVar3 = FUN_0001d084(*(undefined4 *)(iVar2 + 0xc));
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    FUN_0001ce98(iVar3,0,*(undefined4 *)(iVar2 + 0xc));
    *(char *)(iVar3 + 8) = (char)param_1;
    *(undefined *)(iVar3 + 9) = 0;
    FUN_0001cff8(iVar3,param_2,8);
    if (*DAT_0001df74 != (code *)0x0) {
      (**DAT_0001df74)(iVar3);
    }
    uVar1 = FUN_00012db4();
    FUN_0001df54(iVar2 + 4,iVar3 + 0xc);
    FUN_00012dbc(uVar1);
  }
  return iVar3;
}




void FUN_0001ddfa(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_object____RT_NULL_0001dfa4,DAT_0001df78 + 0x33,0x212);
  }
  if ((int)((uint)*(byte *)(param_1 + 8) << 0x18) < 0) {
    FUN_0001cdc6(&LAB_0001dfe4,DAT_0001df78 + 0x33,0x213);
  }
  if (*(code **)(DAT_0001df74 + 4) != (code *)0x0) {
    (**(code **)(DAT_0001df74 + 4))(param_1);
  }
  *(undefined *)(param_1 + 8) = 0;
  uVar1 = FUN_00012db4();
  FUN_0001df62(param_1 + 0xc);
  FUN_00012dbc(uVar1);
  FUN_0001d330(param_1);
  return;
}




undefined4 FUN_0001de4e(int param_1)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_object____RT_NULL_0001dfa4,DAT_0001df78 + 0x44,0x235);
  }
  if ((int)((uint)*(byte *)(param_1 + 8) << 0x18) < 0) {
    return 1;
  }
  return 0;
}




byte FUN_0001de70(int param_1)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_object____RT_NULL_0001dfa4,DAT_0001df78 + 0x5e,0x248);
  }
  return *(byte *)(param_1 + 8) & 0x7f;
}




undefined4 FUN_0001defc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xfffffffb;
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    FUN_0001cff8(param_2,param_1);
    uVar1 = 0;
  }
  return uVar1;
}




void FUN_0001df18(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_0001dd66(0xe,param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x14) = param_3;
    *(undefined4 *)(iVar1 + 0x18) = param_2;
  }
  return;
}




undefined4 FUN_0001df30(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (*(char *)(param_1 + 8) == '\x0e')) {
    if (*(code **)(param_1 + 0x14) != (code *)0x0) {
      uVar1 = (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x18));
    }
    FUN_0001ddfa(param_1);
  }
  return uVar1;
}




void FUN_0001df54(int *param_1,int *param_2)

{
  *(int **)(*param_1 + 4) = param_2;
  *param_2 = *param_1;
  *param_1 = (int)param_2;
  param_2[1] = (int)param_1;
  return;
}




void FUN_0001df62(int *param_1)

{
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  return;
}




void FUN_0001e03a(int param_1)

{
  int *piVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e2c4,DAT_0001e2c0,0x19f);
  }
  FUN_00012db4();
  piVar1 = (int *)(param_1 + 0x14);
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x18);
  **(int **)(param_1 + 0x18) = *piVar1;
  *(int **)(param_1 + 0x18) = piVar1;
  *(int **)(param_1 + 0x14) = piVar1;
  if (*(int *)(DAT_0001e2bc + (uint)*(byte *)(param_1 + 0x35) * 8) ==
      DAT_0001e2bc + (uint)*(byte *)(param_1 + 0x35) * 8) {
    *(uint *)(DAT_0001e2b8 + 8) = *(uint *)(DAT_0001e2b8 + 8) & ~*(uint *)(param_1 + 0x38);
  }
  FUN_00012dbc();
  return;
}




void FUN_0001e088(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 uStack_10;
  
  uStack_10 = in_r3;
  iVar1 = FUN_0001e29a(&uStack_10);
  *(int *)(DAT_0001e2b8 + 4) = iVar1;
  FUN_0001e03a(iVar1);
  *(undefined *)(iVar1 + 0x34) = 3;
  FUN_00012e4e(iVar1 + 0x1c);
  return;
}




void FUN_0001e0ac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int **ppiVar4;
  int **ppiVar5;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e2c4,DAT_0001e2c0 + -0x1a,0x16b);
  }
  uVar2 = FUN_00012db4();
  iVar1 = DAT_0001e2b8;
  if (param_1 == *(int *)(DAT_0001e2b8 + 4)) {
    *(byte *)(param_1 + 0x34) = (*(byte *)(param_1 + 0x34) & 0xf8) + 3;
  }
  else {
    ppiVar5 = (int **)(param_1 + 0x14);
    iVar3 = (*(byte *)(param_1 + 0x34) & 0xfffffff8) + 2;
    *(char *)(param_1 + 0x34) = (char)iVar3;
    ppiVar4 = (int **)(DAT_0001e2bc + (uint)*(byte *)(param_1 + 0x35) * 8);
    if (iVar3 * 0x10000000 < 0) {
      *ppiVar4[1] = (int)ppiVar5;
      *(int **)(param_1 + 0x18) = ppiVar4[1];
      ppiVar4[1] = (int *)ppiVar5;
      *ppiVar5 = (int *)ppiVar4;
    }
    else {
      (*ppiVar4)[1] = (int)ppiVar5;
      *ppiVar5 = *ppiVar4;
      *ppiVar4 = (int *)ppiVar5;
      *(int ***)(param_1 + 0x18) = ppiVar4;
    }
    *(uint *)(iVar1 + 8) = *(uint *)(param_1 + 0x38) | *(uint *)(iVar1 + 8);
  }
  FUN_00012dbc(uVar2);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e128(void)

{
  byte bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint in_r3;
  int iVar7;
  uint local_20;
  
  local_20 = in_r3;
  uVar4 = FUN_00012db4();
  puVar3 = DAT_0001e2b8;
  if ((*(short *)(DAT_0001e2b8 + 2) == 0) && (*(int *)(DAT_0001e2b8 + 8) != 0)) {
    bVar2 = false;
    iVar5 = FUN_0001e29a(&local_20);
    iVar6 = *(int *)(puVar3 + 4);
    bVar1 = *(byte *)(iVar6 + 0x34);
    iVar7 = iVar5;
    if ((bVar1 & 7) == 3) {
      iVar7 = iVar6;
      if ((local_20 <= *(byte *)(iVar6 + 0x35)) &&
         ((*(byte *)(iVar6 + 0x35) != local_20 || ((int)((uint)bVar1 << 0x1c) < 0)))) {
        bVar2 = true;
        iVar7 = iVar5;
      }
      *(byte *)(iVar6 + 0x34) = bVar1 & 0xf7;
    }
    if (iVar7 == iVar6) {
      FUN_0001e03a();
      *(byte *)(*(int *)(puVar3 + 4) + 0x34) = (*(byte *)(*(int *)(puVar3 + 4) + 0x34) & 0xf8) + 3;
    }
    else {
      *puVar3 = (char)local_20;
      *(int *)(puVar3 + 4) = iVar7;
      if (*(code **)(puVar3 + 0xc) != (code *)0x0) {
        (**(code **)(puVar3 + 0xc))(iVar6,iVar7);
      }
      if (bVar2) {
        FUN_0001e0ac(iVar6);
      }
      FUN_0001e03a(iVar7);
      *(byte *)(iVar7 + 0x34) = (*(byte *)(iVar7 + 0x34) & 0xf8) + 3;
      FUN_0001e24e(iVar7);
      if (*_DAT_0001e2d8 == '\0') {
        if (*(code **)(puVar3 + 0x10) != (code *)0x0) {
          (**(code **)(puVar3 + 0x10))(iVar6);
        }
        FUN_00012dc2(iVar6 + 0x1c,iVar7 + 0x1c);
        FUN_00012dbc(uVar4);
        return;
      }
      FUN_00012dc2(iVar6 + 0x1c,iVar7 + 0x1c,iVar6,iVar7);
    }
  }
  FUN_00012dbc(uVar4);
  return;
}




void FUN_0001e1fe(void)

{
  FUN_00012db4();
  *(short *)(DAT_0001e2b8 + 2) = *(short *)(DAT_0001e2b8 + 2) + 1;
  FUN_00012dbc();
  return;
}




void FUN_0001e214(void)

{
  short sVar1;
  int iVar2;
  
  FUN_00012db4();
  iVar2 = DAT_0001e2b8;
  sVar1 = *(short *)(DAT_0001e2b8 + 2) + -1;
  *(short *)(DAT_0001e2b8 + 2) = sVar1;
  if (0 < sVar1) {
    FUN_00012dbc();
    return;
  }
  *(undefined2 *)(iVar2 + 2) = 0;
  FUN_00012dbc();
  if (*(int *)(iVar2 + 4) != 0) {
    FUN_0001e128();
    return;
  }
  return;
}




undefined2 FUN_0001e246(void)

{
  return *(undefined2 *)(DAT_0001e2b8 + 2);
}




void FUN_0001e24e(int param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e2db + 1,DAT_0001e2c0 + -0x31,0x62);
  }
  pcVar1 = *(char **)(param_1 + 0x28);
  if (((*pcVar1 == '#') && (pcVar3 = *(char **)(param_1 + 0x1c), pcVar1 < pcVar3)) &&
     (pcVar3 <= pcVar1 + *(int *)(param_1 + 0x2c))) {
    if (pcVar3 <= pcVar1 + 0x20) {
      FUN_0001cd4c(s_warning___s_stack_is_close_to_en_0001e30c,param_1);
      return;
    }
  }
  else {
    FUN_0001cd4c(s_thread__s_stack_overflow_0001e2f0,param_1);
    iVar2 = FUN_00012db4();
    do {
    } while (iVar2 != 0);
  }
  return;
}




int FUN_0001e29a(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0001d3ce(*(undefined4 *)(DAT_0001e2b8 + 8));
  iVar2 = *(int *)(DAT_0001e2bc + (iVar1 + -1) * 8);
  *param_1 = iVar1 + -1;
  return iVar2 + -0x14;
}




undefined4 FUN_0001e356(void)

{
  return *DAT_0001e730;
}




void FUN_0001e35c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_0001e730;
  uVar1 = FUN_00012db4();
  FUN_0001e03a(iVar2);
  FUN_0001ed48(iVar2 + 0x58);
  *(undefined *)(iVar2 + 0x34) = 1;
  FUN_0001a386(iVar2);
  FUN_00012dbc(uVar1);
  FUN_0001e128();
  return;
}




void FUN_0001e390(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e738,DAT_0001e734,0x8b);
  }
  if (-1 < (int)((uint)*(byte *)(param_1 + 0x34) << 0x1d)) {
    FUN_0001cdc6(DAT_0001e74c,DAT_0001e734,0x8c);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 1) {
    FUN_0001cdc6(DAT_0001e750,DAT_0001e734,0x8d);
  }
  uVar2 = FUN_00012db4();
  *(undefined4 *)(param_1 + 0x30) = 0xffffff8b;
  FUN_0001ebc6(param_1 + 0x14);
  FUN_0001e0ac(param_1);
  FUN_00012dbc(uVar2);
  FUN_0001e128();
  return;
}




undefined4
FUN_0001e3ee(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,uint param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 + 0x14;
  *(int *)(param_1 + 0x18) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  *(undefined4 *)(param_1 + 0x24) = param_4;
  *(undefined4 *)(param_1 + 0x28) = param_5;
  *(undefined4 *)(param_1 + 0x2c) = param_6;
  FUN_0001ce98(param_5,0x23,param_6,param_5,param_3,param_4);
  uVar2 = FUN_00012ef0(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                       *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c) + -4,DAT_0001e754);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  if (0x1f < param_7) {
    FUN_0001cdc6(s_priority_<_RT_THREAD_PRIORITY_MA_0001e758,DAT_0001e734 + 0x10,0xc6);
  }
  *(char *)(param_1 + 0x36) = (char)param_7;
  *(char *)(param_1 + 0x35) = (char)param_7;
  *(int *)(param_1 + 0x40) = param_1 + 0x3c;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(int *)(param_1 + 0x3c) = param_1 + 0x3c;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = param_8;
  *(undefined4 *)(param_1 + 0x54) = param_8;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  FUN_0001ecec(param_1 + 0x58,param_1,DAT_0001e77c,param_1,0,0);
  if (*(code **)(DAT_0001e72c + 8) != (code *)0x0) {
    (**(code **)(DAT_0001e72c + 8))(param_1);
  }
  return 0;
}




void FUN_0001e48a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e738,DAT_0001e734 + 0x1d,0x14a,param_4,0,param_2,param_3,
                 param_4);
  }
  if (param_5 == 0) {
    FUN_0001cdc6(s_stack_start____RT_NULL_0001e780,DAT_0001e734 + 0x1d,0x14b);
  }
  FUN_0001dcae(param_1,1,param_2);
  FUN_0001e3ee(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}




undefined4 FUN_0001e4e2(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e738,DAT_0001e734 + 0xd0,0x41b);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 1) {
    FUN_0001cdc6(DAT_0001e750,DAT_0001e734 + 0xd0,0x41c);
  }
  if (-1 < (int)((uint)*(byte *)(param_1 + 0x34) << 0x1d)) {
    return 0xffffff01;
  }
  uVar2 = FUN_00012db4();
  FUN_0001ebc6(param_1 + 0x14);
  FUN_0001ef48(param_1 + 0x58);
  FUN_00012dbc(uVar2);
  FUN_0001e0ac(param_1);
  if (*(code **)(DAT_0001e72c + 4) != (code *)0x0) {
    (**(code **)(DAT_0001e72c + 4))(param_1);
  }
  return 0;
}




undefined4 FUN_0001e54c(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e738,DAT_0001e734 + 0x2c,0x17d);
  }
  if ((*(byte *)(param_1 + 0x34) & 7) != 0) {
    FUN_0001cdc6(s__thread_>stat___RT_THREAD_STAT_M_0001e798,DAT_0001e734 + 0x2c,0x17e);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 1) {
    FUN_0001cdc6(DAT_0001e750,DAT_0001e734 + 0x2c,0x17f);
  }
  *(int *)(param_1 + 0x38) = 1 << (uint)*(byte *)(param_1 + 0x35);
  *(undefined *)(param_1 + 0x34) = 4;
  FUN_0001e4e2(param_1);
  if (*DAT_0001e730 != 0) {
    FUN_0001e128();
  }
  return 0;
}




undefined4 FUN_0001e5b2(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e738,DAT_0001e734 + 0x3e,0x1a8);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 1) {
    FUN_0001cdc6(DAT_0001e750,DAT_0001e734 + 0x3e,0x1a9);
  }
  iVar1 = FUN_0001de4e(param_1);
  if (iVar1 == 0) {
    FUN_0001cdc6(s_rt_object_is_systemobject__rt_ob_0001e7d0,DAT_0001e734 + 0x3e,0x1aa);
  }
  if ((*(byte *)(param_1 + 0x34) & 7) != 1) {
    if ((*(byte *)(param_1 + 0x34) & 7) != 0) {
      FUN_0001e03a(param_1);
    }
    uVar2 = FUN_00012db4();
    FUN_0001ed48(param_1 + 0x58);
    *(undefined *)(param_1 + 0x34) = 1;
    if ((*(int *)(param_1 + 0x44) != 0) && (iVar1 = FUN_0001de70(), iVar1 == 3)) {
      FUN_0001abae(*(undefined4 *)(param_1 + 0x44),param_1);
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    FUN_0001a386(param_1);
    FUN_00012dbc(uVar2);
  }
  return 0;
}




int FUN_0001e64a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0001dd66(1,param_1,param_3,param_4,param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    iVar2 = FUN_0001d084(param_4);
    if (iVar2 == 0) {
      FUN_0001ddfa(iVar1);
      iVar1 = 0;
    }
    else {
      FUN_0001e3ee(iVar1,param_1,param_2,param_3,iVar2,param_4,param_5,param_6);
    }
  }
  return iVar1;
}




undefined4 FUN_0001e692(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e738,DAT_0001e734 + 0x4f,0x219);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 1) {
    FUN_0001cdc6(DAT_0001e750,DAT_0001e734 + 0x4f,0x21a);
  }
  iVar1 = FUN_0001de4e(param_1);
  if (iVar1 != 0) {
    FUN_0001cdc6(s_rt_object_is_systemobject__rt_ob_0001e800,DAT_0001e734 + 0x4f,0x21b);
  }
  if ((*(byte *)(param_1 + 0x34) & 7) != 1) {
    if ((*(byte *)(param_1 + 0x34) & 7) != 0) {
      FUN_0001e03a(param_1);
    }
    uVar2 = FUN_00012db4();
    FUN_0001ed48(param_1 + 0x58);
    *(undefined *)(param_1 + 0x34) = 1;
    if ((*(int *)(param_1 + 0x44) != 0) && (iVar1 = FUN_0001de70(), iVar1 == 3)) {
      FUN_0001abae(*(undefined4 *)(param_1 + 0x44),param_1);
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    FUN_0001a386(param_1);
    FUN_00012dbc(uVar2);
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0001e860(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001e738,DAT_0001ebdc,0x3dc);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 1) {
    FUN_0001cdc6(DAT_0001ebe0,DAT_0001ebdc,0x3dd);
  }
  piVar1 = DAT_0001ebd8;
  if (param_1 != *DAT_0001ebd8) {
    FUN_0001cdc6(s_thread____rt_thread_self___0001ebe4,DAT_0001ebdc,0x3de);
  }
  bVar4 = *(byte *)(param_1 + 0x34) & 7;
  if ((bVar4 == 2) || (bVar4 == 3)) {
    uVar3 = FUN_00012db4();
    if ((bVar4 == 3) && (param_1 != *piVar1)) {
      FUN_0001cdc6(s_thread____rt_thread_self___0001ebe4,DAT_0001ebdc,0x3ee);
    }
    FUN_0001e03a(param_1);
    bVar4 = 7;
    if (param_1 == 0) {
      FUN_0001cdc6(s_thread____RT_NULL_0001ec00,DAT_0001ebdc + -0x1c,0x3b3);
    }
    if (param_2 == 0) {
      bVar4 = 4;
    }
    else if (param_2 == 1) {
      bVar4 = 6;
    }
    else if (param_2 != 2) {
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x1c,0x3c0);
    }
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xf8 | bVar4;
    FUN_0001ef48(param_1 + 0x58);
    FUN_00012dbc(uVar3);
    if (*_DAT_0001ec18 != (code *)0x0) {
      (**_DAT_0001ec18)(param_1);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffff01;
  }
  return uVar3;
}




int FUN_0001ea5e(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iStack_20;
  
  piVar1 = DAT_0001ebd8;
  if (param_1 == 0) {
    iVar2 = -5;
  }
  else {
    iVar7 = *DAT_0001ebd8;
    iStack_20 = param_1;
    if (iVar7 == 0) {
      FUN_0001cdc6(s_thread____RT_NULL_0001ec00,DAT_0001ebdc + -0x54,0x272);
    }
    iVar2 = FUN_0001de70(iVar7);
    if (iVar2 != 1) {
      FUN_0001cdc6(DAT_0001ebe0,DAT_0001ebdc + -0x54,0x273);
    }
    iVar2 = FUN_0001c8e6();
    uVar3 = FUN_00012db4();
    iVar4 = FUN_0001e246();
    if (iVar4 != 0) {
      FUN_0001cd4c(s_Function__s___scheduler_is_not_a_0001ec1b + 1,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    if (iVar2 == 1) {
      FUN_0001cd4c(s_Function__s___interrupt_is_disab_0001ec48,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    uVar5 = FUN_00012db4();
    if (*piVar1 == 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_b_0001ec70,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    uVar6 = FUN_00012db4();
    iVar2 = FUN_0001c8d4();
    if (iVar2 != 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001eca8,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    FUN_00012dbc(uVar6);
    FUN_00012dbc(uVar5);
    FUN_00012dbc(uVar3);
    uVar3 = FUN_00012db4();
    *(undefined4 *)(iVar7 + 0x30) = 0;
    iVar2 = FUN_0001e860(iVar7,0);
    if (iVar2 == 0) {
      FUN_0001efae(iVar7 + 0x58,0,&iStack_20);
      FUN_0001ee68(iVar7 + 0x58);
      FUN_00012dbc(uVar3);
      *(undefined4 *)(iVar7 + 0x30) = 0xfffffff5;
      FUN_0001e128();
      if (*(int *)(iVar7 + 0x30) == -0x75) {
        *(undefined4 *)(iVar7 + 0x30) = 0;
      }
    }
    else {
      FUN_00012dbc(uVar3);
    }
  }
  return iVar2;
}




undefined4 FUN_0001ea60(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  
  local_20 = param_4;
  if (param_1 == (int *)0x0) {
    FUN_0001cdc6(s_tick____RT_NULL_0001ecd0,DAT_0001ebdc + -0x44,0x2b8);
  }
  iVar3 = *DAT_0001ebd8;
  if (iVar3 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001ec00,DAT_0001ebdc + -0x44,700);
  }
  iVar1 = FUN_0001de70(iVar3);
  if (iVar1 != 1) {
    FUN_0001cdc6(DAT_0001ebe0,DAT_0001ebdc + -0x44,0x2bd);
  }
  uVar2 = FUN_00012db4();
  *(undefined4 *)(iVar3 + 0x30) = 0;
  iVar1 = FUN_0001a1aa();
  if ((uint)(iVar1 - *param_1) < param_2) {
    local_20 = (*param_1 + param_2) - iVar1;
    *param_1 = *param_1 + param_2;
    FUN_0001e860(iVar3,2);
    FUN_0001efae(iVar3 + 0x58,0,&local_20);
    FUN_0001ee68(iVar3 + 0x58);
    FUN_00012dbc(uVar2);
    FUN_0001e128();
    if (*(int *)(iVar3 + 0x30) == -0x75) {
      *(undefined4 *)(iVar3 + 0x30) = 0;
    }
  }
  else {
    *param_1 = iVar1;
    FUN_00012dbc(uVar2);
  }
  return *(undefined4 *)(iVar3 + 0x30);
}




int FUN_0001eb00(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int aiStack_20 [2];
  
  aiStack_20[0] = FUN_0001a20e();
  piVar1 = DAT_0001ebd8;
  if (aiStack_20[0] == 0) {
    iVar2 = -5;
  }
  else {
    iVar7 = *DAT_0001ebd8;
    if (iVar7 == 0) {
      FUN_0001cdc6(s_thread____RT_NULL_0001ec00,DAT_0001ebdc + -0x54,0x272);
    }
    iVar2 = FUN_0001de70(iVar7);
    if (iVar2 != 1) {
      FUN_0001cdc6(DAT_0001ebe0,DAT_0001ebdc + -0x54,0x273);
    }
    iVar2 = FUN_0001c8e6();
    uVar3 = FUN_00012db4();
    iVar4 = FUN_0001e246();
    if (iVar4 != 0) {
      FUN_0001cd4c(s_Function__s___scheduler_is_not_a_0001ec1b + 1,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    if (iVar2 == 1) {
      FUN_0001cd4c(s_Function__s___interrupt_is_disab_0001ec48,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    uVar5 = FUN_00012db4();
    if (*piVar1 == 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_b_0001ec70,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    uVar6 = FUN_00012db4();
    iVar2 = FUN_0001c8d4();
    if (iVar2 != 0) {
      FUN_0001cd4c(s_Function__s__shall_not_be_used_i_0001eca8,DAT_0001ebdc + -0x54);
      FUN_0001cdc6(&DAT_0001ec14,DAT_0001ebdc + -0x54,0x276);
    }
    FUN_00012dbc(uVar6);
    FUN_00012dbc(uVar5);
    FUN_00012dbc(uVar3);
    uVar3 = FUN_00012db4();
    *(undefined4 *)(iVar7 + 0x30) = 0;
    iVar2 = FUN_0001e860(iVar7,0);
    if (iVar2 == 0) {
      FUN_0001efae(iVar7 + 0x58,0,aiStack_20);
      FUN_0001ee68(iVar7 + 0x58);
      FUN_00012dbc(uVar3);
      *(undefined4 *)(iVar7 + 0x30) = 0xfffffff5;
      FUN_0001e128();
      if (*(int *)(iVar7 + 0x30) == -0x75) {
        *(undefined4 *)(iVar7 + 0x30) = 0;
      }
    }
    else {
      FUN_00012dbc(uVar3);
    }
  }
  return iVar2;
}




undefined4 FUN_0001eb0c(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_thread____RT_NULL_0001ec00,DAT_0001ebdc + -0x2e,0x350);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 1) {
    FUN_0001cdc6(DAT_0001ebe0,DAT_0001ebdc + -0x2e,0x351);
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      iVar2 = FUN_0001de4e(param_1);
      if (iVar2 == 1) {
        uVar3 = FUN_0001e5b2(param_1);
      }
      else {
        uVar3 = FUN_0001e692();
      }
      FUN_0001e128();
    }
    else {
      if (param_2 == 2) {
        uVar3 = FUN_00012db4();
        if ((*(byte *)(param_1 + 0x34) & 7) == 2) {
          FUN_0001e03a(param_1);
          bVar1 = *param_3;
          *(byte *)(param_1 + 0x35) = bVar1;
          *(int *)(param_1 + 0x38) = 1 << (uint)bVar1;
          FUN_0001e0ac(param_1);
        }
        else {
          bVar1 = *param_3;
          *(byte *)(param_1 + 0x35) = bVar1;
          *(int *)(param_1 + 0x38) = 1 << (uint)bVar1;
        }
        FUN_00012dbc(uVar3);
      }
      uVar3 = 0;
    }
    return uVar3;
  }
  uVar3 = FUN_0001e54c(param_1);
  return uVar3;
}




void FUN_0001ebc6(int *param_1)

{
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  return;
}




void FUN_0001ecec(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6)

{
  if (param_1 == 0) {
    FUN_0001cdc6(s_timer____RT_NULL_0001f0e4,DAT_0001f0e0,0x114,param_4,param_4);
  }
  if (param_3 == 0) {
    FUN_0001cdc6(s_timeout____RT_NULL_0001f0f8,DAT_0001f0e0,0x115);
  }
  if (0x7ffffffe < param_5) {
    FUN_0001cdc6(s_time_<_RT_TICK_MAX___2_0001f10c,DAT_0001f0e0,0x116);
  }
  FUN_0001dcae(param_1,10,param_2);
  FUN_0001f36a(param_1,param_3,param_4,param_5,param_6);
  return;
}




undefined4 FUN_0001ed48(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_timer____RT_NULL_0001f0e4,DAT_0001f0e0 + 0xe,299);
  }
  iVar1 = FUN_0001de70(param_1);
  if (iVar1 != 10) {
    FUN_0001cdc6(s_rt_object_get_type__timer_>paren_0001f124,DAT_0001f0e0 + 0xe,300);
  }
  iVar1 = FUN_0001de4e(param_1);
  if (iVar1 == 0) {
    FUN_0001cdc6(s_rt_object_is_systemobject__timer_0001f160,DAT_0001f0e0 + 0xe,0x12d);
  }
  uVar2 = FUN_00012db4();
  FUN_0001f3ac(param_1);
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xfe;
  FUN_00012dbc(uVar2);
  FUN_0001dd2c(param_1);
  return 0;
}




int FUN_0001edae(undefined4 param_1,int param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  
  if (param_2 == 0) {
    FUN_0001cdc6(s_timeout____RT_NULL_0001f0f8,DAT_0001f0e0 + 0x1e,0x163,param_4,param_4);
  }
  if (0x7ffffffe < param_4) {
    FUN_0001cdc6(s_time_<_RT_TICK_MAX___2_0001f10c,DAT_0001f0e0 + 0x1e,0x164);
  }
  iVar1 = FUN_0001dd66(10,param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    FUN_0001f36a(iVar1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}




undefined4 FUN_0001ee68(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char **ppcVar5;
  char **ppcVar6;
  char **ppcVar7;
  char *pcVar8;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_timer____RT_NULL_0001f0e4,DAT_0001f0e0 + 0x3e,0x1a6,param_4,param_4);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 10) {
    FUN_0001cdc6(s_rt_object_get_type__timer_>paren_0001f124,DAT_0001f0e0 + 0x3e,0x1a7);
  }
  uVar3 = FUN_00012db4();
  FUN_0001f3ac(param_1);
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xfe;
  if (*DAT_0001f1c4 != (code *)0x0) {
    (**DAT_0001f1c4)(param_1);
  }
  iVar2 = FUN_0001a1aa();
  pcVar8 = (char *)(iVar2 + *(int *)(param_1 + 0x24));
  *(char **)(param_1 + 0x28) = pcVar8;
  pcVar1 = DAT_0001f0dc;
  if ((int)((uint)*(byte *)(param_1 + 9) << 0x1d) < 0) {
    ppcVar5 = (char **)(DAT_0001f0dc + 0x18);
  }
  else {
    ppcVar5 = (char **)(DAT_0001f0dc + 0x10);
  }
  ppcVar6 = ppcVar5;
  do {
    ppcVar7 = ppcVar6;
    if (ppcVar7 == (char **)ppcVar5[1]) break;
    ppcVar6 = (char **)*ppcVar7;
  } while ((ppcVar6[5] == pcVar8) || (0x7ffffffe < (uint)((int)ppcVar6[5] - (int)pcVar8)));
  *(int *)(DAT_0001f0dc + 4) = *(int *)(DAT_0001f0dc + 4) + 1;
  FUN_0001f34a(ppcVar7,param_1 + 0x14);
  uVar4 = *(byte *)(param_1 + 9) | 1;
  *(char *)(param_1 + 9) = (char)uVar4;
  if (((int)(uVar4 << 0x1d) < 0) &&
     ((*pcVar1 == '\x01' && ((int)((uint)*(byte *)(DAT_0001f1c8 + 0x34) << 0x1d) < 0)))) {
    FUN_0001e4e2(DAT_0001f1c8);
    FUN_00012dbc(uVar3);
    FUN_0001e128();
  }
  else {
    FUN_00012dbc(uVar3);
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0001ef48(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00012db4();
  if (param_1 == 0) {
    FUN_0001cdc6(s_timer____RT_NULL_0001f0e4,DAT_0001f0e0 + 0x4d,0x221);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 10) {
    FUN_0001cdc6(s_rt_object_get_type__timer_>paren_0001f124,DAT_0001f0e0 + 0x4d,0x222);
  }
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    if (*_DAT_0001f1cc != (code *)0x0) {
      (**_DAT_0001f1cc)(param_1);
    }
    FUN_0001f3ac(param_1);
    *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xfe;
    FUN_00012dbc(uVar1);
    return 0;
  }
  FUN_00012dbc(uVar1);
  return 0xffffff01;
}




undefined4 FUN_0001efae(int param_1,undefined4 param_2,uint *param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    FUN_0001cdc6(s_timer____RT_NULL_0001f0e4,DAT_0001f0e0 + 0x5b,0x245);
  }
  iVar2 = FUN_0001de70(param_1);
  if (iVar2 != 10) {
    FUN_0001cdc6(s_rt_object_get_type__timer_>paren_0001f124,DAT_0001f0e0 + 0x5b,0x246);
  }
  uVar3 = FUN_00012db4();
  switch(param_2) {
  case 0:
    if (0x7ffffffe < *param_3) {
      FUN_0001cdc6(s____rt_tick_t___arg__<_RT_TICK_MA_0001f1cf + 1,DAT_0001f0e0 + 0x5b,0x250);
    }
    *(uint *)(param_1 + 0x24) = *param_3;
    goto switchD_0001efea_caseD_a;
  case 1:
    uVar4 = *(uint *)(param_1 + 0x24);
    break;
  case 2:
    bVar1 = *(byte *)(param_1 + 9) & 0xfd;
    goto LAB_0001f028;
  case 3:
    bVar1 = *(byte *)(param_1 + 9) | 2;
LAB_0001f028:
    *(byte *)(param_1 + 9) = bVar1;
    goto switchD_0001efea_caseD_a;
  case 4:
    uVar4 = (uint)*(byte *)(param_1 + 9) << 0x1f;
    if (uVar4 != 0) {
      uVar4 = 1;
    }
    break;
  case 5:
    uVar4 = *(uint *)(param_1 + 0x28);
    break;
  case 6:
    uVar4 = *(uint *)(param_1 + 0x1c);
    break;
  case 7:
    *(uint **)(param_1 + 0x1c) = param_3;
    goto switchD_0001efea_caseD_a;
  case 8:
    uVar4 = *(uint *)(param_1 + 0x20);
    break;
  case 9:
    *(uint **)(param_1 + 0x20) = param_3;
  default:
    goto switchD_0001efea_caseD_a;
  }
  *param_3 = uVar4;
switchD_0001efea_caseD_a:
  FUN_00012dbc(uVar3);
  return 0;
}




void FUN_0001f056(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 ****local_28;
  undefined4 ****local_24;
  
  local_28 = &local_28;
  local_24 = &local_28;
  iVar3 = FUN_0001a1aa();
  uVar4 = FUN_00012db4();
  iVar2 = DAT_0001f0dc;
  piVar8 = (int *)(DAT_0001f0dc + 0x10);
  while ((piVar7 = (int *)*piVar8, piVar7 != piVar8 &&
         (iVar6 = (int)(piVar7 + -5), (uint)(iVar3 - piVar7[5]) < 0x7fffffff))) {
    pcVar5 = *(code **)(iVar2 + 8);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(iVar6);
    }
    FUN_0001f3ac(iVar6);
    if (-1 < (int)((uint)*(byte *)((int)piVar7 + -0xb) << 0x1e)) {
      *(byte *)((int)piVar7 + -0xb) = *(byte *)((int)piVar7 + -0xb) & 0xfe;
    }
    FUN_0001f34a(&local_28);
    (*(code *)piVar7[2])(piVar7[3]);
    iVar3 = FUN_0001a1aa();
    pcVar5 = *(code **)(iVar2 + 0xc);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(iVar6);
    }
    if ((undefined4 *****)local_28 != &local_28) {
      FUN_0001f358(piVar7);
      bVar1 = *(byte *)((int)piVar7 + -0xb);
      if (((int)((uint)bVar1 << 0x1e) < 0) && ((bVar1 & 1) != 0)) {
        *(byte *)((int)piVar7 + -0xb) = bVar1 & 0xfe;
        FUN_0001ee68(iVar6);
      }
    }
  }
  FUN_00012dbc(uVar4);
  return;
}




undefined4 FUN_0001f218(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0xffffffff;
  FUN_0001f386(DAT_0001f3b0,local_8);
  return local_8[0];
}




void FUN_0001f22c(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  undefined *puVar8;
  int *piVar9;
  undefined4 ***local_20;
  undefined4 ***local_1c;
  
  local_20 = &local_20;
  local_1c = &local_20;
  uVar3 = FUN_00012db4();
  iVar2 = DAT_0001f3b0;
  puVar8 = (undefined *)(DAT_0001f3b0 + -0x10);
  piVar9 = (int *)(DAT_0001f3b0 + 8);
  while (piVar7 = (int *)*piVar9, piVar7 != piVar9) {
    iVar6 = (int)(piVar7 + -5);
    iVar4 = FUN_0001a1aa();
    if (0x7ffffffe < (uint)(iVar4 - piVar7[5])) break;
    pcVar5 = *(code **)(iVar2 + -8);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(iVar6);
    }
    FUN_0001f3ac(iVar6);
    if (-1 < (int)((uint)*(byte *)((int)piVar7 + -0xb) << 0x1e)) {
      *(byte *)((int)piVar7 + -0xb) = *(byte *)((int)piVar7 + -0xb) & 0xfe;
    }
    FUN_0001f34a(&local_20);
    *puVar8 = 0;
    FUN_00012dbc(uVar3);
    (*(code *)piVar7[2])(piVar7[3]);
    pcVar5 = *(code **)(iVar2 + -4);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(iVar6);
    }
    uVar3 = FUN_00012db4();
    *puVar8 = 1;
    if ((undefined4 ****)local_20 != &local_20) {
      FUN_0001f358(piVar7);
      bVar1 = *(byte *)((int)piVar7 + -0xb);
      if (((int)((uint)bVar1 << 0x1e) < 0) && ((bVar1 & 1) != 0)) {
        *(byte *)((int)piVar7 + -0xb) = bVar1 & 0xfe;
        FUN_0001ee68(iVar6);
      }
    }
  }
  FUN_00012dbc(uVar3);
  return;
}




void FUN_0001f2d6(void)

{
  int iVar1;
  undefined4 uVar2;
  uint in_r3;
  uint local_8 [2];
  
  local_8[0] = in_r3;
  do {
    iVar1 = FUN_0001f386(DAT_0001f3b0 + 8,local_8);
    if (iVar1 == 0) {
      iVar1 = FUN_0001a1aa();
      if (local_8[0] - iVar1 < 0x7fffffff) {
        local_8[0] = local_8[0] - iVar1;
        FUN_0001ea5e();
      }
    }
    else {
      uVar2 = FUN_0001e356();
      FUN_0001e860(uVar2,2);
      FUN_0001e128();
    }
    FUN_0001f22c();
  } while( true );
}




void FUN_0001f34a(int *param_1,int *param_2)

{
  *(int **)(*param_1 + 4) = param_2;
  *param_2 = *param_1;
  *param_1 = (int)param_2;
  param_2[1] = (int)param_1;
  return;
}




void FUN_0001f358(int *param_1)

{
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  return;
}




void FUN_0001f36a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,byte param_5)

{
  int iVar1;
  
  *(byte *)(param_1 + 9) = param_5 & 0xfe;
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  *(undefined4 *)(param_1 + 0x24) = param_4;
  *(undefined4 *)(param_1 + 0x28) = 0;
  iVar1 = param_1 + 0x14;
  *(int *)(param_1 + 0x18) = iVar1;
  *(int *)iVar1 = iVar1;
  return;
}




undefined4 FUN_0001f386(int *param_1,undefined4 *param_2)

{
  FUN_00012db4();
  if ((int *)*param_1 != param_1) {
    *param_2 = ((int *)*param_1)[5];
    FUN_00012dbc();
    return 0;
  }
  FUN_00012dbc();
  return 0xffffff01;
}




void FUN_0001f3ac(int param_1)

{
  FUN_0001f358(param_1 + 0x14);
  return;
}




void FUN_0001fb24(uint param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(DAT_0001fde4 + (param_1 >> 6));
  *puVar1 = *puVar1 | 1 << (param_1 & 0x1f);
  return;
}




void FUN_0001fb7c(uint param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(DAT_0001fde4 + (param_1 >> 6));
  *puVar1 = *puVar1 | 1 << (param_1 & 0x1f);
  return;
}




void FUN_0001fc10(uint param_1,uint param_2)

{
  *(uint *)(DAT_0001fde4 + 4) = param_1 | param_2 | *(uint *)(DAT_0001fde4 + 4) & DAT_0001fdf4;
  return;
}




void FUN_0001fc44(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_0001fde4;
  uVar2 = *(uint *)(DAT_0001fde4 + 4) & DAT_0001fdf8;
  uVar3 = *(uint *)(DAT_0001fde4 + 0x2c) & 0xdfffffff;
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
    uVar2 = uVar2 | param_1 << 0xe;
    break;
  case 5:
  case 7:
    uVar2 = uVar2 | (param_1 & 0xfffffffb) << 0xe | 0x10000000;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    uVar2 = uVar2 | (param_1 & 0xfffffff3) << 0xe;
    uVar3 = uVar3 | 0x20000000;
  }
  *(uint *)(DAT_0001fde4 + 4) = uVar2;
  *(uint *)(iVar1 + 0x2c) = uVar3;
  return;
}




uint FUN_0001fe1a(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_30 = DAT_0001fefc;
  uStack_2c = DAT_0001ff00;
  uStack_28 = DAT_0001ff04;
  uStack_24 = DAT_0001ff08;
  local_20 = DAT_0001ff00;
  uStack_1c = DAT_0001ff04;
  local_18 = DAT_0001ff00;
  uStack_14 = DAT_0001ff04;
  uVar2 = (uint)(*(int *)(DAT_0001fef8 + 4) << 0x1c) >> 0x1e;
  uVar1 = DAT_0001ff0c;
  if (((uVar2 == 0) || (uVar2 == 1)) || (uVar2 != 2)) goto LAB_0001feae;
  if ((*(uint *)(DAT_0001fef8 + 4) & 0x10000) == 0x10000) {
    if ((*(uint *)(DAT_0001fef8 + 0x2c) & 0x40000000) != 0) {
      uVar1 = DAT_0001ff14;
    }
    if ((*(uint *)(DAT_0001fef8 + 4) & 0x20000) == 0x20000) goto LAB_0001fe7a;
  }
  else {
LAB_0001fe7a:
    uVar1 = DAT_0001ff10;
  }
  uVar2 = (uint)(*(int *)(DAT_0001fef8 + 4) << 10) >> 0x1c;
  if (*(int *)(DAT_0001fef8 + 4) << 4 < 0) {
    uVar2 = uVar2 | 0x10;
  }
  if (*(int *)(DAT_0001fef8 + 4) << 1 < 0) {
    uVar2 = uVar2 | 0x20;
  }
  if (uVar2 < 0xf) {
    iVar3 = uVar2 + 2;
  }
  else if (uVar2 - 0xf < 0x30) {
    iVar3 = uVar2 + 1;
  }
  else {
    iVar3 = 0x3f;
  }
  uVar1 = uVar1 * iVar3;
LAB_0001feae:
  uVar2 = uVar1 >> *(sbyte *)((int)&local_30 + ((uint)(*(int *)(DAT_0001fef8 + 4) << 0x18) >> 0x1c))
  ;
  if (((param_1 != 0) && (uVar1 = uVar2, param_1 != 1)) &&
     ((uVar1 = uVar2 >> *(sbyte *)((int)&local_20 +
                                  ((uint)(*(int *)(DAT_0001fef8 + 4) << 0x15) >> 0x1d)),
      param_1 != 2 && (uVar1 = 0, param_1 == 3)))) {
    uVar1 = uVar2 >> *(sbyte *)((int)&local_18 +
                               ((uint)(*(int *)(DAT_0001fef8 + 4) << 0x12) >> 0x1d));
  }
  return uVar1;
}




void FUN_0001ff68(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if (param_1 == DAT_000202c4) {
LAB_0001ffb2:
    uVar2 = 2;
  }
  else {
    if (param_1 <= DAT_000202c4) {
      if (((char *)(param_1 + DAT_000202c8) != (char *)0x0) &&
         ((char *)(param_1 + DAT_000202c8) != (char *)(DAT_000202c4 >> 0x14))) goto LAB_0001ff98;
      goto LAB_0001ffb2;
    }
    if ((char *)(param_1 - DAT_000202c4) == (char *)(DAT_000202c4 >> 0x14)) goto LAB_0001ffb2;
    if ((char *)(param_1 - DAT_000202c4) != s_database_checksum_error__load_de_0000ebfc + 4)
    goto LAB_0001ff98;
    uVar2 = 3;
  }
  iVar1 = FUN_0001fe1a(uVar2);
LAB_0001ff98:
  *(uint *)(param_1 + 8) = (iVar1 + (param_2 >> 1)) / param_2 & 0xffff;
  return;
}




void FUN_0001ffb6(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffff9ff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | param_2;
  return;
}




void FUN_0001ffc6(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffefff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | param_2;
  return;
}




void FUN_0001ffd6(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffcfff;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | param_2;
  return;
}




void FUN_0001ffe6(int param_1)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x2000;
  return;
}




void FUN_0001fffa(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffff7 | param_2;
  return;
}




void FUN_00020006(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffb | param_2;
  return;
}




void FUN_0002009a(int param_1,uint param_2)

{
  *(uint *)(param_1 + 4) = param_2 & 0x1ff;
  return;
}




uint FUN_000200a2(int param_1)

{
  return *(uint *)(param_1 + 4) & 0x1ff;
}




uint FUN_0002022e(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + (param_2 >> 6)) & 1 << (param_2 & 0x1f);
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  return uVar1;
}




void FUN_00020258(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + (param_2 >> 6));
  *puVar1 = *puVar1 | 1 << (param_2 & 0x1f);
  return;
}




void FUN_0002026c(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + (param_2 >> 6));
  *puVar1 = *puVar1 & ~(1 << (param_2 & 0x1f));
  return;
}




undefined4 FUN_00020280(int param_1,uint param_2)

{
  if (((*(uint *)(param_1 + (param_2 >> 0x16)) & 1 << ((param_2 << 0xb) >> 0x1b)) != 0) &&
     ((*(uint *)(param_1 + ((param_2 << 0x10) >> 0x16)) & 1 << (param_2 & 0x1f)) != 0)) {
    return 1;
  }
  return 0;
}




void FUN_00020448(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_2 & 0xf;
  if ((int)(param_2 << 0x1b) < 0) {
    if (param_3 == 4) {
      uVar1 = uVar1 | 3;
      param_1[0xf] = param_1[0xf] | param_4;
    }
    else {
      uVar1 = uVar1 | param_3;
    }
  }
  uVar2 = 0;
  do {
    uVar3 = 1 << (uVar2 & 0xff) & param_4;
    if (uVar3 != 0) {
      if (param_2 == 0x28) {
        param_1[5] = uVar3;
      }
      else if (param_2 == 0x48) {
        param_1[4] = uVar3;
      }
      *param_1 = uVar1 << (uVar2 << 2 & 0xff) | *param_1 & ~(0xf << (uVar2 << 2 & 0xff));
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 8);
  uVar2 = 8;
  do {
    uVar3 = 1 << (uVar2 & 0xff) & param_4;
    if (uVar3 != 0) {
      uVar4 = uVar2 * 4 - 0x20;
      if (param_2 == 0x28) {
        param_1[5] = uVar3;
      }
      else if (param_2 == 0x48) {
        param_1[4] = uVar3;
      }
      param_1[1] = uVar1 << (uVar4 & 0xff) | param_1[1] & ~(0xf << (uVar4 & 0xff));
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0x10);
  return;
}




uint FUN_00020504(int param_1,uint param_2)

{
  param_2 = *(uint *)(param_1 + 8) & param_2;
  if (param_2 != 0) {
    param_2 = 1;
  }
  return param_2;
}




void FUN_00020524(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = DAT_00020628;
  if ((int)param_1 < 0) {
    uVar3 = *(uint *)(DAT_00020628 + 0x1c);
  }
  else {
    uVar3 = *(uint *)(DAT_00020628 + 4);
  }
  uVar4 = (param_1 & 0xffff) << ((param_1 >> 0x15 & 0xf) << 4);
  if ((param_1 << 10) >> 0x1e == 3) {
    uVar3 = uVar3 & 0xf8ffffff;
    *(uint *)(DAT_00020628 + 4) = *(uint *)(DAT_00020628 + 4) & 0xf8ffffff;
  }
  else {
    uVar1 = uVar4;
    if ((int)(param_1 << 0xb) < 0) {
      uVar1 = 3 << ((param_1 << 0xc) >> 0x1c);
    }
    uVar3 = uVar3 & ~uVar1 | 0x7000000;
  }
  if (param_2 != 0) {
    uVar3 = uVar3 | uVar4;
  }
  if (-1 < (int)param_1) {
    *(uint *)(iVar2 + 4) = uVar3;
    return;
  }
  *(uint *)(iVar2 + 0x1c) = uVar3;
  return;
}




void FUN_00020576(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_00020628;
  uVar3 = (param_2 << 0x1e) >> 0x1c;
  uVar2 = 0xf << uVar3;
  uVar3 = param_1 << uVar3;
  if (param_2 < 4) {
    *(uint *)(DAT_00020628 + 8) = *(uint *)(DAT_00020628 + 8) & ~uVar2;
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | uVar3;
    return;
  }
  if (param_2 < 8) {
    *(uint *)(DAT_00020628 + 0xc) = *(uint *)(DAT_00020628 + 0xc) & ~uVar2;
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | uVar3;
    return;
  }
  if (param_2 < 0xc) {
    *(uint *)(DAT_00020628 + 0x10) = *(uint *)(DAT_00020628 + 0x10) & ~uVar2;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | uVar3;
    return;
  }
  *(uint *)(DAT_00020628 + 0x14) = *(uint *)(DAT_00020628 + 0x14) & ~uVar2;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | uVar3;
  return;
}




void FUN_00020728(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 - DAT_00020b24;
  uVar3 = DAT_00020b24 >> 0x14;
  if (param_1 == DAT_00020b24) {
    uVar3 = 0x404;
  }
  else if (param_1 == DAT_00020b24 || param_1 < DAT_00020b24) {
    if (param_1 != 0x40000000) {
      uVar2 = param_1 + DAT_00020b28;
      if (uVar2 == 0) {
        uVar3 = 0x401;
      }
      else if (uVar2 == uVar3) {
        uVar3 = 0x402;
      }
      else {
        if (uVar2 != 0x800) {
          return;
        }
        uVar3 = 0x403;
      }
    }
  }
  else if (uVar2 == uVar3) {
    uVar3 = 0x405;
  }
  else if (uVar2 == 0x11c00) {
    uVar3 = 0x30b;
  }
  else {
    if (uVar2 != 0x12400) {
      return;
    }
    uVar3 = 0x30d;
  }
  FUN_0001fb7c(uVar3);
  puVar1 = (uint *)(DAT_0001fde4 + (uVar3 >> 6));
  *puVar1 = *puVar1 & ~(1 << (uVar3 & 0x1f));
  return;
}




void FUN_000207aa(uint *param_1,ushort *param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  param_1[10] = (uint)*param_2;
  puVar2 = DAT_00020b30;
  puVar1 = DAT_00020b2c;
  if ((((param_1 == DAT_00020b2c) || (param_1 == (uint *)0x40000000)) ||
      (param_1 == (uint *)-DAT_00020b28)) ||
     (((param_1 == DAT_00020b34 || (param_1 == DAT_00020b38)) || (param_1 == DAT_00020b30)))) {
    *param_1 = *param_1 & 0xffffff8f;
    *param_1 = *param_1 | (uint)param_2[1];
    *param_1 = *param_1 | (uint)param_2[2];
  }
  param_1[0xb] = *(uint *)(param_2 + 4);
  if (param_1 == DAT_00020b24) {
LAB_00020812:
    if (param_1 != puVar2) goto LAB_0002081a;
  }
  else {
    if (param_1 == DAT_00020b3c) goto LAB_0002081a;
    *param_1 = *param_1 & 0xfffffcff;
    *param_1 = *param_1 | (uint)param_2[3];
    if (param_1 != puVar1) goto LAB_00020812;
  }
  param_1[0xc] = (uint)*(byte *)(param_2 + 6);
LAB_0002081a:
  param_1[5] = param_1[5] | 1;
  return;
}




void FUN_00020824(uint *param_1)

{
  *param_1 = *param_1 | 1;
  return;
}




void FUN_00020884(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  if (param_3 == 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 1;
  }
  return;
}




void FUN_00020898(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  return;
}




void FUN_0002089c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}




uint FUN_000208a4(int param_1)

{
  return *(uint *)(param_1 + 0x28) & 0xffff;
}




void FUN_00020952(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | param_2;
  return;
}




void FUN_000209b4(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = *(uint *)(param_1 + 0x44) | 0x8000;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x44) & 0xffff7fff;
  }
  *(uint *)(param_1 + 0x44) = uVar1;
  return;
}




void FUN_00020a04(int param_1,int param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_00020b30;
  iVar1 = DAT_00020b2c;
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffc;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)*param_3;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffd;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[2];
    if ((param_1 != iVar1) && (param_1 != iVar2)) {
      return;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffb;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[1];
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffff7;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[3];
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffeff;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | (uint)param_3[4];
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffdff;
    uVar3 = *(uint *)(param_1 + 4) | (uint)param_3[5];
  }
  else if (param_2 == 1) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffcff;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)*param_3 << 4;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffdf;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[2] << 4;
    if ((param_1 != iVar1) && (param_1 != iVar2)) {
      return;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffbf;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[1] << 4;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff7f;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[3] << 4;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffbff;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | (uint)param_3[4] << 2;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffff7ff;
    uVar3 = *(uint *)(param_1 + 4) | (uint)param_3[5] << 2;
  }
  else if (param_2 == 2) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffffc;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)*param_3 << 8;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffdff;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[2] << 8;
    if ((param_1 != iVar1) && (param_1 != iVar2)) {
      return;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffbff;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[1] << 8;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffff7ff;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[3] << 8;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffefff;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | (uint)param_3[4] << 4;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffdfff;
    uVar3 = *(uint *)(param_1 + 4) | (uint)param_3[5] << 4;
  }
  else {
    if (param_2 != 3) {
      return;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffefff;
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffcff;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)*param_3 << 0xc;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffdfff;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)param_3[2] << 0xc;
    if ((param_1 != iVar1) && (param_1 != iVar2)) {
      return;
    }
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffbfff;
    uVar3 = *(uint *)(param_1 + 4) | (uint)param_3[4] << 6;
  }
  *(uint *)(param_1 + 4) = uVar3;
  return;
}




void FUN_00020bec(int param_1,int param_2,uint param_3)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffff8f;
    param_3 = *(uint *)(param_1 + 0x18) | param_3;
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 2) {
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xffffff8f;
        param_3 = *(uint *)(param_1 + 0x1c) | param_3;
      }
      else {
        if (param_2 != 3) {
          return;
        }
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xffff8fff;
        param_3 = *(uint *)(param_1 + 0x1c) | param_3 << 8;
      }
      *(uint *)(param_1 + 0x1c) = param_3;
      return;
    }
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffff8fff;
    param_3 = *(uint *)(param_1 + 0x18) | param_3 << 8;
  }
  *(uint *)(param_1 + 0x18) = param_3;
  return;
}




void FUN_00020c3a(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x34) = param_3;
    return;
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      if (param_2 == 3) {
        *(undefined4 *)(param_1 + 0x40) = param_3;
      }
      return;
    }
    *(undefined4 *)(param_1 + 0x3c) = param_3;
    return;
  }
  *(undefined4 *)(param_1 + 0x38) = param_3;
  return;
}




void FUN_00020c58(int param_1,int param_2,uint param_3)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
    param_3 = *(uint *)(param_1 + 0x18) | param_3;
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 2) {
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffff7;
        param_3 = *(uint *)(param_1 + 0x1c) | param_3;
      }
      else {
        if (param_2 != 3) {
          return;
        }
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffff7ff;
        param_3 = *(uint *)(param_1 + 0x1c) | param_3 << 8;
      }
      *(uint *)(param_1 + 0x1c) = param_3;
      return;
    }
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffff7ff;
    param_3 = *(uint *)(param_1 + 0x18) | param_3 << 8;
  }
  *(uint *)(param_1 + 0x18) = param_3;
  return;
}




void FUN_00020dca(int param_1,int param_2,uint param_3)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    param_3 = *(uint *)(param_1 + 0x20) | param_3;
  }
  else if (param_2 == 1) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
    param_3 = *(uint *)(param_1 + 0x20) | param_3 << 4;
  }
  else if (param_2 == 2) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
    param_3 = *(uint *)(param_1 + 0x20) | param_3 << 8;
  }
  else {
    if (param_2 != 3) {
      return;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffefff;
    param_3 = *(uint *)(param_1 + 0x20) | param_3 << 0xc;
  }
  *(uint *)(param_1 + 0x20) = param_3;
  return;
}




void FUN_00020e18(int param_1,int param_2,uint param_3)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffb;
    param_3 = *(uint *)(param_1 + 0x20) | param_3;
  }
  else if (param_2 == 1) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffbf;
    param_3 = *(uint *)(param_1 + 0x20) | param_3 << 4;
  }
  else {
    if (param_2 != 2) {
      return;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffbff;
    param_3 = *(uint *)(param_1 + 0x20) | param_3 << 8;
  }
  *(uint *)(param_1 + 0x20) = param_3;
  return;
}




void FUN_00020e60(int param_1,int param_2,uint param_3)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff3;
    param_3 = *(uint *)(param_1 + 0x18) | param_3;
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 2) {
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffff3;
        param_3 = *(uint *)(param_1 + 0x1c) | param_3;
      }
      else {
        if (param_2 != 3) {
          return;
        }
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffff3ff;
        param_3 = *(uint *)(param_1 + 0x1c) | param_3 << 8;
      }
      *(uint *)(param_1 + 0x1c) = param_3;
      return;
    }
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffff3ff;
    param_3 = *(uint *)(param_1 + 0x18) | param_3 << 8;
  }
  *(uint *)(param_1 + 0x18) = param_3;
  return;
}




undefined4 FUN_00020fd8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 0) {
    return *(undefined4 *)(param_1 + 0x34);
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      if (param_2 == 3) {
        uVar1 = *(undefined4 *)(param_1 + 0x40);
      }
      return uVar1;
    }
    return *(undefined4 *)(param_1 + 0x3c);
  }
  return *(undefined4 *)(param_1 + 0x38);
}




void FUN_00020ffa(int param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*param_3 == 0) {
    uVar3 = 2;
  }
  if (param_3[1] == 1) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffff5;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)*param_3;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffc;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | (uint)param_3[1];
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffff0f;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | (uint)param_3[3] << 4;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 1;
    FUN_00020e60(param_1,0,param_3[2]);
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff5f;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | uVar3 << 4;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffcff;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | uVar2 << 8;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffff0fff;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | (uint)param_3[3] << 0xc;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10;
    uVar1 = param_3[2];
  }
  else {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff5f;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | (uint)*param_3 << 4;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffcff;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | (uint)param_3[1] << 8;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffff0fff;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | (uint)param_3[3] << 0xc;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10;
    FUN_00020e60(param_1,1,param_3[2]);
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffff5;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | uVar3;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffc;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | uVar2;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffff0f;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | (uint)param_3[3] << 4;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 1;
    uVar1 = param_3[2];
  }
  FUN_00020e60(param_1,param_2 == 0,uVar1);
  return;
}




void FUN_0002115e(int param_1,uint param_2)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffff8f;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | param_2;
  return;
}




void FUN_000211a6(int param_1,uint param_2,uint param_3,int param_4)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffff40ff;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | param_2 | param_3;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | param_4 << 8;
  return;
}




void FUN_000211c2(int param_1,uint param_2,uint param_3,int param_4)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffff8;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | param_2;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffcfc;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x101;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffff5;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff5f;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | param_3 | param_4 << 4;
  return;
}




void FUN_0002120c(int param_1)

{
  FUN_0002115e();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffff8;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 7;
  return;
}




void FUN_00021226(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  if (param_2 == 0x60) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff5f;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | param_3 << 4;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffcff;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x100;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffff0fff;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | param_4 << 0xc;
    uVar1 = *(uint *)(param_1 + 0x20) | 0x10;
  }
  else {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffff5;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | param_3;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffc;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffff0f;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | param_4 << 4;
    uVar1 = *(uint *)(param_1 + 0x20) | 1;
  }
  *(uint *)(param_1 + 0x20) = uVar1;
  FUN_0002115e(param_1);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffff8;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 7;
  return;
}




void FUN_000212c2(int param_1)

{
  FUN_000211a6();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffff88;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x77;
  return;
}




void FUN_000212dc(int param_1)

{
  FUN_000211a6();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x4000;
  return;
}




void FUN_00021342(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_00021738;
  uVar2 = DAT_00021734;
  iVar1 = DAT_00021730;
  if (*(int *)(DAT_00021730 + 0x10) << 0x18 < 0) {
    *(undefined4 *)(DAT_00021730 + 4) = DAT_00021734;
    *(undefined4 *)(iVar1 + 4) = uVar3;
  }
  if ((0x200 < *DAT_0002173c) && (*(int *)(iVar1 + 0x50) << 0x18 < 0)) {
    *(undefined4 *)(iVar1 + 0x44) = uVar2;
    *(undefined4 *)(iVar1 + 0x44) = uVar3;
  }
  return;
}




undefined4 FUN_000213c2(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(DAT_00021730 + 0xc) & 1) != 0) {
    return 1;
  }
  if (*(int *)(DAT_00021730 + 0xc) << 0x1b < 0) {
    uVar1 = 3;
  }
  else if (*(int *)(DAT_00021730 + 0xc) << 0x1d < 0) {
    return 2;
  }
  return uVar1;
}




int FUN_000213e4(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = FUN_000213c2();
    param_1 = param_1 + -1;
    if (iVar1 != 1) {
      return iVar1;
    }
  } while (param_1 != 0);
  return 4;
}




undefined4 FUN_000213fa(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(DAT_00021730 + 0x4c) & 1) != 0) {
    return 1;
  }
  if (*(int *)(DAT_00021730 + 0x4c) << 0x1b < 0) {
    uVar1 = 3;
  }
  else if (*(int *)(DAT_00021730 + 0x4c) << 0x1d < 0) {
    return 2;
  }
  return uVar1;
}




int FUN_0002141c(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = FUN_000213fa();
    param_1 = param_1 + -1;
    if (iVar1 != 1) {
      return iVar1;
    }
  } while (param_1 != 0);
  return 4;
}




void FUN_00021432(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_00021740;
  iVar1 = DAT_00021730;
  if ((*DAT_0002173c < 0x201) || (param_1 < DAT_00021744)) {
    iVar3 = FUN_000213e4(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 2;
      *(uint *)(iVar1 + 0x14) = param_1;
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
      FUN_000213e4(uVar2);
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffd;
    }
  }
  else {
    iVar3 = FUN_0002141c(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 2;
      *(uint *)(iVar1 + 0x54) = param_1;
      if (*(int *)(iVar1 + 0x1c) << 0x1e < 0) {
        *(uint *)(iVar1 + 0x14) = param_1;
      }
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 0x40;
      FUN_0002141c(uVar2);
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xfffffffd;
      return;
    }
  }
  return;
}




void FUN_000214aa(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_00021740;
  iVar1 = DAT_00021730;
  if (*DAT_0002173c < 0x201) {
    iVar3 = FUN_000213e4(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 4;
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
      FUN_000213e4(uVar2);
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffb;
      return;
    }
  }
  else {
    iVar3 = FUN_000213e4(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 4;
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
      iVar3 = FUN_000213e4(uVar2);
      if (iVar3 != 0) {
        return;
      }
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffb;
    }
    iVar3 = FUN_0002141c(uVar2);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 4;
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 0x40;
      FUN_0002141c(uVar2);
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xfffffffb;
    }
  }
  return;
}




void FUN_00021536(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_00021740;
  iVar3 = FUN_000213e4(DAT_00021740);
  iVar1 = DAT_00021730;
  if (iVar3 == 0) {
    *(uint *)(DAT_00021730 + 0x10) = *(uint *)(DAT_00021730 + 0x10) | 4;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
    FUN_000213e4(uVar2);
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffb;
  }
  return;
}




void FUN_00021566(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_00021740;
  iVar3 = FUN_0002141c(DAT_00021740);
  iVar1 = DAT_00021730;
  if (iVar3 == 0) {
    *(uint *)(DAT_00021730 + 0x50) = *(uint *)(DAT_00021730 + 0x50) | 4;
    *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 0x40;
    FUN_0002141c(uVar2);
    *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xfffffffb;
  }
  return;
}




void FUN_00021596(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_00021740;
  iVar1 = DAT_00021730;
  if ((*DAT_0002173c < 0x201) || (param_1 < DAT_00021744)) {
    iVar3 = FUN_000213e4(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
      *param_1 = param_2;
      FUN_000213e4(uVar2);
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffe;
    }
  }
  else {
    iVar3 = FUN_0002141c(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 1;
      *param_1 = param_2;
      FUN_0002141c(uVar2);
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xfffffffe;
      return;
    }
  }
  return;
}




void FUN_000215f8(undefined2 *param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_00021740;
  iVar1 = DAT_00021730;
  if ((*DAT_0002173c < 0x201) || (param_1 < DAT_00021744)) {
    iVar3 = FUN_000213e4(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
      *param_1 = param_2;
      FUN_000213e4(uVar2);
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffe;
    }
  }
  else {
    iVar3 = FUN_0002141c(DAT_00021740);
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 1;
      *param_1 = param_2;
      FUN_0002141c(uVar2);
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xfffffffe;
      return;
    }
  }
  return;
}




void FUN_0002165a(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_00021740;
  iVar1 = DAT_00021730;
  if ((*DAT_0002173c < 0x201) || (param_1 < DAT_00021744)) {
    iVar3 = FUN_000213e4(DAT_00021740);
    *(uint *)(iVar1 + 0xfc) = *(uint *)(iVar1 + 0xfc) | 2;
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
      *param_1 = param_2;
      FUN_000213e4(uVar2);
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffe;
    }
  }
  else {
    iVar3 = FUN_0002141c(DAT_00021740);
    *(uint *)(iVar1 + 0xfc) = *(uint *)(iVar1 + 0xfc) | 2;
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) | 1;
      *param_1 = param_2;
      FUN_0002141c(uVar2);
      *(uint *)(iVar1 + 0x50) = *(uint *)(iVar1 + 0x50) & 0xfffffffe;
      return;
    }
  }
  return;
}




void FUN_00021938(uint param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(DAT_000219ac + (param_1 >> 6));
  *puVar1 = *puVar1 | 1 << (param_1 & 0x1f);
  return;
}




undefined4 FUN_0002194e(uint param_1)

{
  uint uVar1;
  
  if (param_1 >> 0xc == 0xc) {
    uVar1 = *(uint *)(DAT_000219ac + 0x10);
  }
  else {
    uVar1 = *(uint *)(DAT_000219ac + 0x50);
  }
  if (((*(uint *)(DAT_000219ac + (param_1 >> 0xc)) & 1 << ((param_1 << 0x15) >> 0x1b) & 0xffU) != 0)
     && ((uVar1 & 1 << (param_1 & 0x1f) & 0xffU) != 0)) {
    return 1;
  }
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00021a9c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = _DAT_00021e84;
  FUN_00023966(_DAT_00021e84,0xa8);
  *(undefined4 *)(iVar1 + 0x10) = 3;
  *(undefined4 *)(iVar1 + 0x14) = 3;
  *(char **)(iVar1 + 0x18) = s_Terminal_00021e87 + 1;
  *(int *)(iVar1 + 0x1c) = iVar1 + 0xa8;
  *(undefined4 *)(iVar1 + 0x20) = 0x400;
  uVar3 = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(char **)(iVar1 + 0x60) = s_Terminal_00021e87 + 1;
  *(int *)(iVar1 + 100) = iVar1 + 0x4a8;
  *(undefined4 *)(iVar1 + 0x68) = 0x20;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  *(undefined4 *)(iVar1 + 0x6c) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  iVar2 = DAT_00021e94;
  do {
    *(undefined *)(iVar1 + uVar3) = *(undefined *)(iVar2 + (0xf - uVar3));
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  return;
}




int FUN_00021aec(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  iVar5 = 0;
  do {
    uVar1 = *(uint *)(param_1 + 0x10);
    if (uVar3 < uVar1) {
      iVar4 = uVar1 - uVar3;
    }
    else {
      iVar4 = *(int *)(param_1 + 8) - (uVar3 - uVar1);
    }
    uVar2 = *(int *)(param_1 + 8) - uVar3;
    uVar1 = iVar4 - 1U;
    if (uVar2 <= iVar4 - 1U) {
      uVar1 = uVar2;
    }
    if (param_3 <= uVar1) {
      uVar1 = param_3;
    }
    FUN_000237a0(*(int *)(param_1 + 4) + uVar3,param_2,uVar1);
    param_3 = param_3 - uVar1;
    uVar3 = uVar3 + uVar1;
    iVar5 = iVar5 + uVar1;
    param_2 = param_2 + uVar1;
    if (*(uint *)(param_1 + 8) == uVar3) {
      uVar3 = 0;
    }
    *(uint *)(param_1 + 0xc) = uVar3;
  } while (param_3 != 0);
  return iVar5;
}




int FUN_00021b46(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar6 = *(uint *)(param_1 + 0xc);
  iVar7 = 0;
  iVar8 = 0x1000;
  do {
    iVar1 = DAT_00021e98;
    uVar2 = *(uint *)(param_1 + 0x10);
    if (uVar6 < uVar2) {
      iVar5 = uVar2 - uVar6;
    }
    else {
      iVar5 = *(int *)(param_1 + 8) - (uVar6 - uVar2);
    }
    uVar4 = *(uint *)(param_1 + 8);
    uVar2 = uVar4 - uVar6;
    uVar3 = iVar5 - 1U;
    if (uVar2 <= iVar5 - 1U) {
      uVar3 = uVar2;
    }
    if (param_3 <= uVar3) {
      uVar3 = param_3;
    }
    if (uVar3 == 0) {
      iVar5 = 0x1000;
      iVar9 = *(int *)(DAT_00021e98 + 8);
      if (iVar9 != 0x1000) {
        *(undefined4 *)(DAT_00021e98 + 8) = 0x1000;
        iVar8 = iVar9;
      }
      if ((iVar8 == 0) || (*(int *)(iVar1 + 4) == 0)) {
        if (*(int *)(iVar1 + 4) != 0) {
          *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + -1;
        }
        if (param_3 < uVar2) {
          uVar2 = param_3;
        }
        uVar3 = *(int *)(param_1 + 0x10) + uVar2;
        *(uint *)(param_1 + 0x10) = uVar3 - uVar4 * (uVar3 / uVar4);
      }
      else {
        iVar5 = iVar8 + -1;
        uVar2 = uVar3;
      }
    }
    else {
      iVar5 = 0x1000;
      *(undefined4 *)(DAT_00021e98 + 4) = 8;
      uVar2 = uVar3;
    }
    FUN_000237a0(*(int *)(param_1 + 4) + uVar6,param_2,uVar2);
    param_3 = param_3 - uVar2;
    uVar6 = uVar6 + uVar2;
    iVar7 = iVar7 + uVar2;
    param_2 = param_2 + uVar2;
    if (*(uint *)(param_1 + 8) == uVar6) {
      uVar6 = 0;
    }
    *(uint *)(param_1 + 0xc) = uVar6;
    iVar8 = iVar5;
  } while (param_3 != 0);
  return iVar7;
}




void FUN_00021bfa(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  uVar2 = *(int *)(param_1 + 8) - iVar3;
  iVar1 = *(int *)(param_1 + 4) + *(int *)(param_1 + 0xc);
  if (param_3 < uVar2) {
    FUN_000237a0(iVar1,param_2);
    *(uint *)(param_1 + 0xc) = iVar3 + param_3;
  }
  else {
    FUN_000237a0(iVar1,param_2,uVar2);
    FUN_000237a0(*(undefined4 *)(param_1 + 4),param_2 + uVar2,param_3 - uVar2);
    *(uint *)(param_1 + 0xc) = param_3 - uVar2;
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00021c3c(int param_1,int param_2,uint param_3)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*_DAT_00021e84 != 'S') {
    FUN_00021a9c();
  }
  pcVar1 = _DAT_00021e84;
  uVar3 = *(uint *)(_DAT_00021e84 + param_1 * 0x18 + 0x28);
  uVar4 = *(uint *)(_DAT_00021e84 + param_1 * 0x18 + 0x24);
  uVar2 = 0;
  if (uVar4 < uVar3) {
    uVar2 = *(int *)(_DAT_00021e84 + param_1 * 0x18 + 0x20) - uVar3;
    if (param_3 <= *(int *)(_DAT_00021e84 + param_1 * 0x18 + 0x20) - uVar3) {
      uVar2 = param_3;
    }
    FUN_000237a0(param_2,*(int *)(_DAT_00021e84 + param_1 * 0x18 + 0x1c) + uVar3,uVar2);
    param_3 = param_3 - uVar2;
    uVar3 = uVar3 + uVar2;
    param_2 = param_2 + uVar2;
    if (*(uint *)(pcVar1 + param_1 * 0x18 + 0x20) == uVar3) {
      uVar3 = 0;
    }
  }
  uVar4 = uVar4 - uVar3;
  if (uVar4 < param_3) {
    param_3 = uVar4;
  }
  if (param_3 != 0) {
    FUN_000237a0(param_2,*(int *)(pcVar1 + param_1 * 0x18 + 0x1c) + uVar3,param_3);
    uVar2 = uVar2 + param_3;
    uVar3 = uVar3 + param_3;
  }
  if (uVar2 != 0) {
    *(uint *)(pcVar1 + param_1 * 0x18 + 0x28) = uVar3;
  }
  return uVar2;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00021cb4(int param_1,int param_2,uint param_3)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*_DAT_00021e84 != 'S') {
    FUN_00021a9c();
  }
  pcVar1 = _DAT_00021e84;
  uVar4 = *(uint *)(_DAT_00021e84 + param_1 * 0x18 + 0x6c);
  uVar3 = *(uint *)(_DAT_00021e84 + param_1 * 0x18 + 0x70);
  uVar2 = 0;
  if (uVar4 < uVar3) {
    uVar2 = *(int *)(_DAT_00021e84 + param_1 * 0x18 + 0x68) - uVar3;
    if (param_3 <= *(int *)(_DAT_00021e84 + param_1 * 0x18 + 0x68) - uVar3) {
      uVar2 = param_3;
    }
    FUN_000237a0(param_2,*(int *)(_DAT_00021e84 + param_1 * 0x18 + 100) + uVar3,uVar2);
    param_3 = param_3 - uVar2;
    uVar3 = uVar3 + uVar2;
    param_2 = param_2 + uVar2;
    if (*(uint *)(pcVar1 + param_1 * 0x18 + 0x68) == uVar3) {
      uVar3 = 0;
    }
  }
  uVar4 = uVar4 - uVar3;
  if (uVar4 < param_3) {
    param_3 = uVar4;
  }
  if (param_3 != 0) {
    FUN_000237a0(param_2,*(int *)(pcVar1 + param_1 * 0x18 + 100) + uVar3,param_3);
    uVar2 = uVar2 + param_3;
    uVar3 = uVar3 + param_3;
  }
  if (uVar2 != 0) {
    *(uint *)(pcVar1 + param_1 * 0x18 + 0x70) = uVar3;
  }
  return uVar2;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00021e52(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = _DAT_00021e84 + param_1 * 0x18;
  iVar1 = *(int *)(iVar3 + 0x74);
  iVar3 = iVar3 + 0x60;
  if (iVar1 == 0) {
    uVar2 = FUN_00022538(iVar3);
    if (uVar2 < param_3) {
      return 0;
    }
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        uVar2 = FUN_00021aec(iVar3,param_2);
        return uVar2;
      }
      if (iVar1 != 4) {
        return 0;
      }
      uVar2 = FUN_00021b46(iVar3,param_2);
      return uVar2;
    }
    uVar2 = FUN_00022538(iVar3);
    if (uVar2 < param_3) {
      param_3 = uVar2;
    }
  }
  FUN_00021bfa(iVar3,param_2,param_3);
  return param_3;
}




uint FUN_00021ece(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = DAT_000222b8 + param_1 * 0x18;
  iVar1 = *(int *)(iVar3 + 0x2c);
  iVar3 = iVar3 + 0x18;
  if (iVar1 == 0) {
    uVar2 = FUN_00022538(iVar3);
    if (uVar2 < param_3) {
      return 0;
    }
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        uVar2 = FUN_00021aec(iVar3,param_2);
        return uVar2;
      }
      if (iVar1 != 4) {
        return 0;
      }
      uVar2 = FUN_00021b46(iVar3,param_2);
      return uVar2;
    }
    uVar2 = FUN_00022538(iVar3);
    if (uVar2 < param_3) {
      param_3 = uVar2;
    }
  }
  FUN_00021bfa(iVar3,param_2,param_3);
  return param_3;
}




void FUN_00021f32(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (*DAT_000222b8 != 'S') {
    FUN_00021a9c();
  }
  bVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
    bVar2 = (byte)uVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  FUN_00021e52(param_1,param_2,param_3);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority((uint)bVar2);
  }
  return;
}




void FUN_00021f64(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (*DAT_000222b8 != 'S') {
    FUN_00021a9c();
  }
  bVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
    bVar2 = (byte)uVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  FUN_00021ece(param_1,param_2,param_3);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority((uint)bVar2);
  }
  return;
}




void FUN_00021f96(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000236b4(param_2);
  FUN_00021f64(param_1,param_2,uVar1);
  return;
}




ulonglong FUN_0002210a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  
  if (*DAT_000222b8 != 'S') {
    FUN_00021a9c();
  }
  pcVar2 = DAT_000222b8;
  bVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
    bVar4 = (byte)uVar5;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  iVar3 = 0;
  do {
    if (*(int *)(DAT_000222b8 + iVar3 * 0x18 + 100) == 0) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < *(int *)(DAT_000222b8 + 0x14));
  if (iVar3 < *(int *)(DAT_000222b8 + 0x14)) {
    *(undefined4 *)(DAT_000222b8 + iVar3 * 0x18 + 0x60) = param_1;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 100) = param_2;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x68) = param_3;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x70) = 0;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x6c) = 0;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x74) = param_4;
  }
  else {
    iVar3 = -1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority((uint)bVar4);
  }
  return (ulonglong)CONCAT14(bVar4,iVar3);
}




ulonglong FUN_0002216e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  
  if (*DAT_000222b8 != 'S') {
    FUN_00021a9c();
  }
  pcVar2 = DAT_000222b8;
  bVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
    bVar4 = (byte)uVar5;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  iVar3 = 0;
  do {
    if (*(int *)(DAT_000222b8 + iVar3 * 0x18 + 0x1c) == 0) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < *(int *)(DAT_000222b8 + 0x10));
  if (iVar3 < *(int *)(DAT_000222b8 + 0x10)) {
    *(undefined4 *)(DAT_000222b8 + iVar3 * 0x18 + 0x18) = param_1;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x1c) = param_2;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x20) = param_3;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x28) = 0;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x24) = 0;
    *(undefined4 *)(pcVar2 + iVar3 * 0x18 + 0x2c) = param_4;
  }
  else {
    iVar3 = -1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority((uint)bVar4);
  }
  return (ulonglong)CONCAT14(bVar4,iVar3);
}




undefined4
FUN_000221d2(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  bool bVar1;
  char *pcVar2;
  byte bVar3;
  undefined4 uVar4;
  
  if (*DAT_000222b8 != 'S') {
    FUN_00021a9c();
  }
  pcVar2 = DAT_000222b8;
  if (param_1 < 3) {
    bVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
      bVar3 = (byte)uVar4;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x20);
    }
    if (param_1 != 0) {
      *(undefined4 *)(DAT_000222b8 + param_1 * 0x18 + 0x18) = param_2;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x1c) = param_3;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x20) = param_4;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x28) = 0;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x24) = 0;
    }
    *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x2c) = param_5;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority((uint)bVar3);
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}




undefined4
FUN_0002222a(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  bool bVar1;
  char *pcVar2;
  byte bVar3;
  undefined4 uVar4;
  
  if (*DAT_000222b8 != 'S') {
    FUN_00021a9c();
  }
  pcVar2 = DAT_000222b8;
  if (param_1 < 3) {
    bVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
      bVar3 = (byte)uVar4;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x20);
    }
    if (param_1 != 0) {
      *(undefined4 *)(DAT_000222b8 + param_1 * 0x18 + 0x60) = param_2;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 100) = param_3;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x68) = param_4;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x70) = 0;
      *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x6c) = 0;
    }
    *(undefined4 *)(pcVar2 + param_1 * 0x18 + 0x74) = param_5;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority((uint)bVar3);
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}




undefined4 FUN_00022282(uint param_1,undefined4 param_2)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (*DAT_000222b8 != 'S') {
    FUN_00021a9c();
  }
  if (param_1 < 3) {
    bVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = getBasePriority();
      bVar2 = (byte)uVar3;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x20);
    }
    *(undefined4 *)(DAT_000222b8 + param_1 * 0x18 + 0x18) = param_2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority((uint)bVar2);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}




undefined4 FUN_000222c2(uint param_1,undefined4 param_2)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (*DAT_00022550 != 'S') {
    FUN_00021a9c();
  }
  if (param_1 < 3) {
    bVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = getBasePriority();
      bVar2 = (byte)uVar3;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x20);
    }
    *(undefined4 *)(DAT_00022550 + param_1 * 0x18 + 0x60) = param_2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority((uint)bVar2);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}




undefined4 FUN_000222fe(uint param_1,undefined4 param_2)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (*DAT_00022550 != 'S') {
    FUN_00021a9c();
  }
  if (param_1 < 3) {
    bVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = getBasePriority();
      bVar2 = (byte)uVar3;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x20);
    }
    *(undefined4 *)(DAT_00022550 + param_1 * 0x18 + 0x2c) = param_2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority((uint)bVar2);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}




undefined4 FUN_0002233a(uint param_1,undefined4 param_2)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (*DAT_00022550 != 'S') {
    FUN_00021a9c();
  }
  if (param_1 < 3) {
    bVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = getBasePriority();
      bVar2 = (byte)uVar3;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x20);
    }
    *(undefined4 *)(DAT_00022550 + param_1 * 0x18 + 0x74) = param_2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority((uint)bVar2);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}




undefined4 FUN_0002240a(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 local_28;
  
  local_28 = param_4;
  if (*DAT_00022550 != 'S') {
    FUN_00021a9c();
  }
  pcVar2 = DAT_00022550;
  if (0xf < param_1) {
    return 0xffffffff;
  }
  pcVar10 = DAT_00022550 + 0x18;
  uVar6 = FUN_000236b4(param_2);
  uVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar9 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  uVar7 = FUN_00022538(pcVar10);
  pbVar4 = DAT_00022558;
  iVar3 = DAT_00022554;
  bVar5 = pcVar2[0x2c] & 7;
  if ((pcVar2[0x2c] & 7U) == 0) {
    if (uVar7 < uVar6 + 4) {
      uVar8 = 0;
      goto LAB_000224de;
    }
LAB_0002249c:
    FUN_0002251e(pcVar10,param_1);
LAB_00022486:
    uVar8 = FUN_00021aec(pcVar10,param_2,uVar6);
    FUN_0002251e(pcVar10,*pbVar4);
  }
  else {
    if (bVar5 == 1) {
      if (3 < uVar7) {
        FUN_0002251e(pcVar10,param_1);
        if (uVar7 - 4 <= uVar6) {
          uVar6 = uVar7 - 4;
        }
        goto LAB_00022486;
      }
    }
    else {
      if (bVar5 == 2) goto LAB_0002249c;
      if (bVar5 == 4) {
        local_28._0_2_ = CONCAT11(*(undefined *)(DAT_00022554 + param_1),0xff);
        FUN_00021b46(pcVar10,&local_28,2);
        uVar8 = FUN_00021b46(pcVar10,param_2,uVar6);
        local_28._0_2_ = CONCAT11(*(undefined *)(iVar3 + (uint)*pbVar4),(undefined)local_28);
        FUN_00021b46(pcVar10,&local_28,2);
        goto LAB_000224de;
      }
    }
    uVar8 = 0xffffffff;
  }
LAB_000224de:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar9 & 0xff);
  }
  return uVar8;
}




void FUN_0002251e(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_8;
  
  FUN_00021aec(param_1,&local_8,2);
  return;
}




int FUN_00022538(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar2 < *(uint *)(param_1 + 0x10)) {
    iVar1 = -uVar2;
  }
  else {
    iVar1 = *(int *)(param_1 + 8) - uVar2;
  }
  return iVar1 + *(uint *)(param_1 + 0x10) + -1;
}




void FUN_0002255c(int *param_1,undefined param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[2] + 1;
  if (uVar2 <= (uint)param_1[1]) {
    *(undefined *)(*param_1 + param_1[2]) = param_2;
    param_1[2] = uVar2;
    param_1[3] = param_1[3] + 1;
  }
  if (param_1[2] == param_1[1]) {
    iVar1 = FUN_00021f64(param_1[4],*param_1);
    if (iVar1 == param_1[2]) {
      param_1[2] = 0;
      return;
    }
    param_1[3] = -1;
  }
  return;
}




void FUN_0002259a(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 1;
  uVar5 = 1;
  for (uVar3 = param_2; param_3 <= uVar3; uVar3 = uVar3 / param_3) {
    uVar5 = uVar5 + 1;
  }
  if (uVar5 < param_4) {
    uVar5 = param_4;
  }
  if (((param_6 & 1) == 0) && (param_5 != 0)) {
    if (((int)(param_6 << 0x1e) < 0) && (param_4 == 0)) {
      uVar2 = 0x30;
    }
    else {
      uVar2 = 0x20;
    }
    do {
      if (param_5 <= uVar5) break;
      param_5 = param_5 - 1;
      FUN_0002255c(param_1,uVar2);
      if (*(int *)(param_1 + 0xc) < 0) {
        return;
      }
    } while (param_5 != 0);
  }
  iVar1 = DAT_000228e4;
  if (*(int *)(param_1 + 0xc) < 0) {
    return;
  }
  do {
    if (param_4 < 2) {
      if (param_2 / uVar4 < param_3) break;
    }
    else {
      param_4 = param_4 - 1;
    }
    uVar4 = uVar4 * param_3;
  } while( true );
  while (uVar4 = uVar4 / param_3, uVar4 != 0) {
    uVar3 = param_2 / uVar4;
    param_2 = param_2 - uVar3 * uVar4;
    FUN_0002255c(param_1,*(undefined *)(iVar1 + uVar3));
    if (*(int *)(param_1 + 0xc) < 0) break;
  }
  if ((param_6 & 1) != 0) {
    do {
      if (param_5 == 0) {
        return;
      }
      if (param_5 <= uVar5) {
        return;
      }
      param_5 = param_5 - 1;
      FUN_0002255c(param_1,0x20);
    } while (-1 < *(int *)(param_1 + 0xc));
  }
  return;
}




void FUN_0002266a(undefined4 param_1,byte *param_2,byte **param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  char **ppcVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  byte *pbVar11;
  char *pcVar12;
  undefined *local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  undefined4 uStack_60;
  undefined auStack_5c [68];
  
  local_70 = auStack_5c;
  local_6c = 0x40;
  local_68 = 0;
  local_64 = 0;
  uStack_60 = param_1;
LAB_00022688:
  pbVar11 = param_2 + 1;
  if (*param_2 == 0) {
    if (local_64 < 1) {
      return;
    }
    if (local_68 == 0) {
      return;
    }
    FUN_00021f64(param_1,auStack_5c,local_68);
    return;
  }
  if (*param_2 == 0x25) {
    uVar2 = 0;
    do {
      bVar1 = *pbVar11;
      if (bVar1 == 0x23) {
        uVar2 = uVar2 | 8;
      }
      else if (bVar1 == 0x2b) {
        uVar2 = uVar2 | 4;
      }
      else if (bVar1 == 0x2d) {
        uVar2 = uVar2 | 1;
      }
      else {
        if (bVar1 != 0x30) goto LAB_000226ce;
        uVar2 = uVar2 | 2;
      }
      pbVar11 = pbVar11 + 1;
    } while( true );
  }
  FUN_0002255c(&local_70);
  goto LAB_0002269a;
LAB_000226ce:
  iVar8 = 0;
  while( true ) {
    uVar5 = (uint)*pbVar11;
    if (9 < uVar5 - 0x30) break;
    iVar8 = uVar5 + iVar8 * 10 + -0x30;
    pbVar11 = pbVar11 + 1;
  }
  iVar10 = 0;
  if (*pbVar11 == 0x2e) {
    while( true ) {
      pbVar11 = pbVar11 + 1;
      uVar5 = (uint)*pbVar11;
      if (9 < uVar5 - 0x30) break;
      iVar10 = uVar5 + iVar10 * 10 + -0x30;
    }
  }
  while ((uVar5 == 0x6c || (uVar5 == 0x68))) {
    pbVar11 = pbVar11 + 1;
    uVar5 = (uint)*pbVar11;
  }
  if (uVar5 == 0x70) {
    puVar6 = (undefined4 *)*param_3;
    *param_3 = (byte *)(puVar6 + 1);
    uVar7 = *puVar6;
    iVar10 = 8;
    iVar8 = 8;
    uVar2 = 0;
    uVar9 = 0x10;
  }
  else {
    if (uVar5 < 0x71) {
      if (uVar5 != 0x25) {
        if (uVar5 == 0x58) goto LAB_0002278e;
        if (uVar5 != 99) {
          if (uVar5 == 100) {
            puVar6 = (undefined4 *)*param_3;
            *param_3 = (byte *)(puVar6 + 1);
            FUN_0002281c(&local_70,*puVar6,10,iVar10,iVar8,uVar2);
          }
          goto LAB_0002275a;
        }
        pbVar3 = *param_3;
        *param_3 = pbVar3 + 4;
        uVar5 = (uint)*pbVar3;
      }
      FUN_0002255c(&local_70,uVar5);
      goto LAB_0002275a;
    }
    if (uVar5 == 0x73) {
      ppcVar4 = (char **)*param_3;
      *param_3 = (byte *)(ppcVar4 + 1);
      pcVar12 = *ppcVar4;
      if (pcVar12 == (char *)0x0) {
        pcVar12 = &DAT_000228e8;
      }
      do {
        if (*pcVar12 == '\0') break;
        FUN_0002255c(&local_70);
        pcVar12 = pcVar12 + 1;
      } while (-1 < local_64);
      goto LAB_0002275a;
    }
    if (uVar5 == 0x75) {
      puVar6 = (undefined4 *)*param_3;
      *param_3 = (byte *)(puVar6 + 1);
      uVar7 = *puVar6;
      uVar9 = 10;
    }
    else {
      if (uVar5 != 0x78) goto LAB_0002275a;
LAB_0002278e:
      puVar6 = (undefined4 *)*param_3;
      *param_3 = (byte *)(puVar6 + 1);
      uVar7 = *puVar6;
      uVar9 = 0x10;
    }
  }
  FUN_0002259a(&local_70,uVar7,uVar9,iVar10,iVar8,uVar2);
LAB_0002275a:
  pbVar11 = pbVar11 + 1;
LAB_0002269a:
  param_2 = pbVar11;
  if (local_64 < 0) {
    return;
  }
  goto LAB_00022688;
}




void FUN_0002281c(int param_1,int param_2,int param_3,uint param_4,uint param_5,uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = -param_2;
  if (-1 < param_2) {
    iVar1 = param_2;
  }
  uVar3 = 1;
  for (; param_3 <= iVar1; iVar1 = iVar1 / param_3) {
    uVar3 = uVar3 + 1;
  }
  if (uVar3 < param_4) {
    uVar3 = param_4;
  }
  if ((param_5 != 0) && ((param_2 < 0 || ((int)(param_6 << 0x1d) < 0)))) {
    param_5 = param_5 - 1;
  }
  if (((-1 < (int)(param_6 << 0x1e)) || (param_4 != 0)) && ((param_6 & 1) == 0)) {
    while ((param_5 != 0 && (uVar3 < param_5))) {
      param_5 = param_5 - 1;
      FUN_0002255c(param_1,0x20);
      if (*(int *)(param_1 + 0xc) < 0) {
        return;
      }
    }
  }
  if (*(int *)(param_1 + 0xc) < 0) {
    return;
  }
  if (param_2 < 0) {
    uVar2 = 0x2d;
    param_2 = -param_2;
  }
  else {
    if (-1 < (int)(param_6 << 0x1d)) goto LAB_000228a8;
    uVar2 = 0x2b;
  }
  FUN_0002255c(param_1,uVar2);
  if (*(int *)(param_1 + 0xc) < 0) {
    return;
  }
LAB_000228a8:
  if (((param_6 & 3) == 2) && (param_4 == 0)) {
    do {
      if ((param_5 == 0) || (param_5 <= uVar3)) goto LAB_000228d0;
      param_5 = param_5 - 1;
      FUN_0002255c(param_1,0x30);
    } while (-1 < *(int *)(param_1 + 0xc));
  }
  else {
LAB_000228d0:
    FUN_0002259a(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}




char FUN_000228f0(int param_1)

{
  char cVar1;
  uint uVar2;
  
  if ((*(char *)(param_1 + 1) != **DAT_00022bf8) || (*(char *)(param_1 + 4) != '\x10')) {
    return '\0';
  }
  uVar2 = FUN_0000b7f0(param_1 + 2,6);
  if (uVar2 == *(byte *)(param_1 + 8)) {
    cVar1 = *(char *)(param_1 + 6);
    if ((cVar1 != '\x05') && (cVar1 != '\x06')) {
      return '\0';
    }
  }
  else {
    cVar1 = -1;
  }
  return cVar1;
}




undefined4 FUN_00022926(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  float local_28;
  undefined auStack_24 [8];
  
  uVar8 = 0;
  FUN_0000df30(*(undefined *)(*(int *)(DAT_00022bf8 + 4) + 3));
  fVar9 = (float)FUN_0000840a();
  uVar7 = 0;
  fVar10 = fVar9;
  do {
    FUN_0001eb00(0x14);
    local_28 = (float)FUN_0000840a();
    iVar1 = FUN_00022b8a();
    if (iVar1 == 5) {
      uVar2 = 0;
      puVar5 = auStack_24;
      do {
        iVar1 = uVar2 - 4;
        iVar4 = 3 - uVar2;
        uVar2 = uVar2 + 1 & 0xff;
        puVar5[iVar4] = auStack_24[iVar1];
      } while (uVar2 < 4);
      uVar6 = 4;
      uVar3 = 0;
LAB_00022990:
      FUN_0000b8f6(0x10,uVar3,puVar5,uVar6);
    }
    else {
      if (iVar1 == 6) break;
      if (iVar1 == 0xff) {
        uVar6 = 0;
        puVar5 = (undefined *)0x0;
        uVar3 = 2;
        goto LAB_00022990;
      }
    }
    if (DAT_00022bfc < (int)(fVar9 - local_28)) {
      FUN_0000df64();
      return 0xb;
    }
    if ((int)(fVar10 - local_28) < DAT_00022c00) {
      uVar8 = uVar8 + 1;
      if (0x18 < uVar8) {
        FUN_0001cd4c(&DAT_00022c04);
        FUN_0001cd4c(s_feeding_500ms_timeout__odometer_n_00022c14);
        FUN_0001cd4c(&DAT_00022c40);
        FUN_0000df64();
        return 0xc;
      }
    }
    else {
      uVar8 = 0;
    }
    uVar7 = uVar7 + 1;
    fVar10 = local_28;
  } while (uVar7 < 0x4e2);
  if (uVar7 == 0x4e2) {
    FUN_0001cd4c(&DAT_00022c04);
    FUN_0001cd4c(s_feeding_25s_timeout_00022c48);
    FUN_0001cd4c(&DAT_00022c40);
    FUN_0000df64();
    uVar3 = 10;
  }
  else {
    FUN_0001cd4c(&DAT_00022c04);
    FUN_0001cd4c(s_stage_7__enter_buffer_check_00022c60);
    FUN_0001cd4c(&DAT_00022c40);
    iVar1 = FUN_0000e46c(1,3000);
    FUN_0000df64();
    if (iVar1 == 0) {
      FUN_0001cd4c(&DAT_00022c04);
      FUN_0001cd4c(s_feeding_stop__buffer_full_00022cb4);
      FUN_0001cd4c(&DAT_00022c40);
      uVar3 = 0;
    }
    else {
      FUN_0001cd4c(&DAT_00022c80);
      FUN_0001cd4c(s_feeding_timeout__buffer_not_full_00022c90);
      FUN_0001cd4c(&DAT_00022c40);
      uVar3 = 0xd;
    }
    FUN_00000e60(uVar3);
    FUN_0000b8f6(0x10,uVar3,0);
    uVar3 = 0;
  }
  return uVar3;
}




undefined4 FUN_00022a6e(void)

{
  int iVar1;
  
  iVar1 = FUN_0000e46c(1,0xf);
  if (iVar1 != 0) {
    FUN_0000df30(*(undefined *)(*(int *)(DAT_00022bf8 + 4) + 2));
    iVar1 = FUN_0000e46c(1,3000);
    FUN_0000df64();
    if (iVar1 != 0) {
      FUN_0001cd4c(&DAT_00022c80);
      FUN_0001cd4c(s_feeding_timeout__buffer_not_full_00022c90);
      FUN_0001cd4c(&DAT_00022c40);
      return 0xd;
    }
  }
  FUN_0001cd4c(&DAT_00022c04);
  FUN_0001cd4c(s_feeding_stop__buffer_full_00022cb4);
  FUN_0001cd4c(&DAT_00022c40);
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00022ac2(undefined4 param_1)

{
  uint uVar1;
  byte bVar2;
  float fVar3;
  undefined4 uVar4;
  byte bVar5;
  char cVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  bVar5 = 0;
  fVar7 = (float)FUN_0000840a();
  FUN_0000df30(*(undefined *)(*(int *)(DAT_00022bf8 + 4) + 4));
  fVar3 = _DAT_00022cd0;
  do {
    FUN_0001eb00(0x14);
    fVar8 = (float)FUN_0000840a();
    iVar9 = (int)(fVar8 * fVar3);
    if (iVar9 < 0) {
      iVar9 = -iVar9;
    }
    FUN_0001cd4c(s_Bstage8___d__02dmm_00022cd3 + 1,(int)fVar8,iVar9 % 100);
    fVar11 = fVar7 - fVar8;
    fVar10 = (float)VectorUnsignedToFloat(param_1,(byte)(in_fpscr >> 0x15) & 3);
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar11 < fVar10) << 0x1f |
            (uint)(fVar11 == fVar10) << 0x1e;
    in_fpscr = uVar1 | (uint)(NAN(fVar11) || NAN(fVar10)) << 0x1c;
    bVar2 = (byte)(uVar1 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) goto LAB_00022b82;
    bVar5 = bVar5 + 1;
    cVar6 = 0xe < bVar5;
  } while (!(bool)cVar6);
  uVar12 = FUN_00026048(param_1);
  uVar12 = FUN_00026350((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)_DAT_00022ce8,
                        (int)((ulonglong)_DAT_00022ce8 >> 0x20));
  uVar13 = FUN_00026524(fVar7 - fVar8);
  FUN_00026070((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,
               (int)((ulonglong)uVar12 >> 0x20));
  if (cVar6 == '\0') {
    FUN_0001cd4c(&DAT_00022c04);
    FUN_0001cd4c(s__feeding_stop__feed_extruder_tim_00022cef + 1);
    FUN_0001cd4c(&DAT_00022c40);
    FUN_0000df64();
    uVar4 = 0xe;
  }
  else {
LAB_00022b82:
    FUN_0000df64();
    uVar4 = 0;
  }
  return uVar4;
}




undefined4 FUN_00022b8a(void)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  char local_90;
  undefined auStack_8f [131];
  
  puVar1 = DAT_00022d18;
  cVar2 = FUN_000136a6(*DAT_00022d18,0,&local_90,1);
  if (cVar2 == '\0') {
    return 0;
  }
  if (local_90 == -9) {
    FUN_0001eb00(2);
    cVar2 = FUN_000136a6(*puVar1,0,auStack_8f,8);
    if (cVar2 != '\b') {
      return 0;
    }
    iVar4 = FUN_000228f0(&local_90);
    if (iVar4 == 5) {
      return 5;
    }
    if (iVar4 == 6) {
      return 6;
    }
  }
  bVar5 = 0;
  do {
    bVar3 = FUN_000136a6(*puVar1,0,&local_90,0x80);
    if (bVar3 < 0x80) {
      return 0;
    }
    bVar5 = bVar5 + 1;
  } while (bVar5 < 3);
  return 0;
}




void FUN_00022d56(int param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined *)(param_2 + 6) = 0xff;
  *(undefined *)(param_2 + 7) = 7;
  *(undefined *)(param_2 + 8) = 0x80;
  *(undefined *)(param_2 + 9) = 0x69;
  uVar2 = 0;
  do {
    iVar3 = param_2 + uVar2;
    *(undefined *)(param_2 + uVar2) = *(undefined *)(param_1 + uVar2);
    puVar1 = (undefined *)(param_1 + uVar2);
    uVar2 = uVar2 + 1 & 0xff;
    *(undefined *)(iVar3 + 10) = *puVar1;
  } while (uVar2 < 6);
  return;
}




void FUN_00022d7e(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_30 [4];
  undefined4 local_20;
  undefined2 local_1c;
  undefined local_18 [4];
  undefined local_14 [4];
  
  uVar2 = 0;
  do {
    puVar4 = local_30 + uVar2;
    iVar1 = uVar2 * 0xc;
    uVar2 = uVar2 + 1 & 0xff;
    *puVar4 = *(undefined4 *)(DAT_00022e94 + iVar1);
  } while (uVar2 < 4);
  uVar2 = 0;
  do {
    *(undefined *)((int)&local_20 + uVar2) = *(undefined *)(param_1 + uVar2);
    *(undefined *)((int)&local_1c + uVar2) = *(undefined *)(param_1 + uVar2);
    local_18[uVar2] = *(undefined *)(param_1 + uVar2);
    uVar3 = uVar2 + 1 & 0xff;
    local_14[uVar2] = *(undefined *)(param_1 + uVar2);
    uVar2 = uVar3;
  } while (uVar3 < 4);
  FUN_00023072(&local_20,local_30);
  *param_2 = local_20;
  *(undefined2 *)(param_2 + 1) = local_1c;
  return;
}




void FUN_00022dda(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = param_3;
  uStack_c = param_4;
  FUN_00022d7e(param_1,&uStack_10);
  FUN_00022d56(&uStack_10,param_2);
  return;
}




undefined8 FUN_00022dee(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  FUN_00022e2e(&uStack_20);
  FUN_000237a0(param_2,param_1,0x10);
  FUN_00023072(param_2,&uStack_20);
  return CONCAT44(uStack_1c,uStack_20);
}




undefined8 FUN_00022e0e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  FUN_00022e2e(&uStack_20);
  FUN_000237a0(param_2,param_1,0x10);
  FUN_000230d0(param_2,&uStack_20);
  return CONCAT44(uStack_1c,uStack_20);
}




void FUN_00022e2e(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_00022e94;
  uVar4 = 0;
  do {
    iVar1 = uVar4 * 4;
    iVar2 = uVar4 * 0xc;
    uVar4 = uVar4 + 1 & 0xff;
    *(undefined4 *)(param_1 + iVar1) = *(undefined4 *)(iVar3 + iVar2 + 4);
  } while (uVar4 < 4);
  return;
}




void FUN_00022e98(int param_1)

{
  int iVar1;
  undefined uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  byte bVar6;
  undefined4 local_10;
  
  iVar1 = DAT_0002317c;
  local_10 = DAT_00023178;
  uVar4 = 0;
  do {
    *(undefined *)(iVar1 + uVar4) = *(undefined *)(param_1 + uVar4);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x10);
  puVar5 = (undefined *)(DAT_0002317c + 0x10);
  bVar6 = 4;
  do {
    uVar4 = 0;
    do {
      uVar3 = uVar4 + 1 & 0xff;
      puVar5[uVar4] = puVar5[uVar4 - 4];
      uVar4 = uVar3;
    } while (uVar3 < 4);
    if ((bVar6 & 3) == 0) {
      uVar2 = *puVar5;
      *puVar5 = puVar5[1];
      puVar5[1] = puVar5[2];
      puVar5[2] = puVar5[3];
      puVar5[3] = uVar2;
      iVar1 = DAT_00023180;
      uVar4 = 0;
      do {
        puVar5[uVar4] = *(undefined *)(iVar1 + (uint)(byte)puVar5[uVar4]);
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 4);
      FUN_00023140(puVar5,&local_10,4);
      uVar2 = FUN_00023130(local_10 & 0xff);
      local_10 = CONCAT31(local_10._1_3_,uVar2);
    }
    FUN_00023140(puVar5,puVar5 + -0x10,4);
    bVar6 = bVar6 + 1;
    puVar5 = puVar5 + 4;
  } while (bVar6 < 0x2c);
  return;
}




void FUN_00022f1e(int param_1,int param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  undefined uVar9;
  undefined uVar10;
  
  uVar7 = *(undefined *)(param_1 + 1);
  uVar8 = *(undefined *)(param_1 + 0xd);
  uVar1 = *(undefined *)(param_1 + 2);
  uVar9 = *(undefined *)(param_1 + 6);
  uVar10 = *(undefined *)(param_1 + 10);
  uVar2 = *(undefined *)(param_1 + 0xe);
  uVar3 = *(undefined *)(param_1 + 3);
  uVar4 = *(undefined *)(param_1 + 7);
  uVar5 = *(undefined *)(param_1 + 0xb);
  uVar6 = *(undefined *)(param_1 + 0xf);
  if (param_2 == 0) {
    *(undefined *)(param_1 + 1) = *(undefined *)(param_1 + 5);
    *(undefined *)(param_1 + 5) = *(undefined *)(param_1 + 9);
    *(undefined *)(param_1 + 9) = uVar8;
    *(undefined *)(param_1 + 0xd) = uVar7;
    *(undefined *)(param_1 + 2) = uVar10;
    *(undefined *)(param_1 + 6) = uVar2;
    *(undefined *)(param_1 + 10) = uVar1;
    *(undefined *)(param_1 + 0xe) = uVar9;
    *(undefined *)(param_1 + 3) = uVar6;
    *(undefined *)(param_1 + 7) = uVar3;
    *(undefined *)(param_1 + 0xb) = uVar4;
    *(undefined *)(param_1 + 0xf) = uVar5;
  }
  else {
    *(undefined *)(param_1 + 0xd) = *(undefined *)(param_1 + 9);
    *(undefined *)(param_1 + 9) = *(undefined *)(param_1 + 5);
    *(undefined *)(param_1 + 5) = uVar7;
    *(undefined *)(param_1 + 1) = uVar8;
    *(undefined *)(param_1 + 0xe) = uVar9;
    *(undefined *)(param_1 + 10) = uVar1;
    *(undefined *)(param_1 + 6) = uVar2;
    *(undefined *)(param_1 + 2) = uVar10;
    *(undefined *)(param_1 + 0xf) = uVar3;
    *(undefined *)(param_1 + 0xb) = uVar6;
    *(undefined *)(param_1 + 7) = uVar5;
    *(undefined *)(param_1 + 3) = uVar4;
  }
  return;
}




void FUN_00022f96(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  
  bVar9 = 0;
  do {
    uVar8 = (uint)(byte)(param_1[1] ^ *param_1 ^ param_1[2] ^ param_1[3]);
    uVar2 = FUN_00023130();
    bVar1 = *param_1;
    uVar3 = FUN_00023130(param_1[1] ^ param_1[2]);
    uVar3 = (uVar3 ^ uVar8 ^ (uint)param_1[1]) & 0xff;
    uVar4 = FUN_00023130(param_1[2] ^ param_1[3]);
    uVar4 = (uVar4 ^ uVar8 ^ (uint)param_1[2]) & 0xff;
    uVar5 = FUN_00023130(param_1[3] ^ *param_1);
    uVar5 = uVar5 ^ uVar8 ^ (uint)param_1[3];
    uVar2 = (uVar2 ^ uVar8 ^ (uint)bVar1) & 0xff | uVar3 << 8 | uVar4 << 0x10 | uVar5 << 0x18;
    if (param_2 == 1) {
      FUN_00023130(*param_1 ^ param_1[2]);
      uVar8 = FUN_00023130();
      FUN_00023130(param_1[1] ^ param_1[3]);
      uVar6 = FUN_00023130();
      uVar7 = FUN_00023130(uVar8 ^ uVar6);
      uVar2 = (uVar2 ^ uVar7 ^ uVar8) & 0xff | ((uVar7 ^ uVar6 ^ uVar3) & 0xff) << 8 |
              ((uVar7 ^ uVar8 ^ uVar4) & 0xff) << 0x10 | (uVar7 ^ uVar6 ^ uVar5 & 0xff) << 0x18;
    }
    *param_1 = (byte)uVar2;
    param_1[1] = (byte)(uVar2 >> 8);
    param_1[2] = (byte)(uVar2 >> 0x10);
    bVar9 = bVar9 + 1;
    param_1[3] = (byte)(uVar2 >> 0x18);
    param_1 = param_1 + 4;
  } while (bVar9 < 4);
  return;
}




void FUN_00023072(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  FUN_00022e98(param_2);
  FUN_00023172(param_1,DAT_0002317c);
  iVar1 = DAT_0002317c;
  uVar2 = 1;
  do {
    FUN_00023158(param_1,0);
    FUN_00022f1e(param_1,0);
    FUN_00022f96(param_1,0);
    FUN_00023172(param_1,iVar1 + uVar2 * 0x10);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 10);
  FUN_00023158(param_1,0);
  FUN_00022f1e(param_1,0);
  FUN_00023172(param_1,DAT_0002317c + 0xa0);
  return;
}




void FUN_000230d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  FUN_00022e98(param_2);
  FUN_00023172(param_1,DAT_0002317c + 0xa0);
  iVar1 = DAT_0002317c;
  uVar2 = 10;
  do {
    FUN_00022f1e(param_1,1);
    FUN_00023158(param_1,1);
    FUN_00023172(param_1,iVar1 + uVar2 * 0x10 + -0x10);
    FUN_00022f96(param_1,1);
    uVar2 = uVar2 - 1 & 0xff;
  } while (1 < uVar2);
  FUN_00022f1e(param_1,1);
  FUN_00023158(param_1,1);
  FUN_00023172(param_1,DAT_0002317c);
  return;
}




uint FUN_00023130(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 << 0x19) >> 0x18;
  if (0x7f < param_1) {
    uVar1 = uVar1 ^ 0x1b;
  }
  return uVar1;
}




void FUN_00023140(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    *(byte *)(param_1 + uVar1) = *(byte *)(param_1 + uVar1) ^ *(byte *)(param_2 + uVar1);
  }
  return;
}




void FUN_00023158(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_00023180;
  if (param_2 != 0) {
    iVar2 = DAT_00023184;
  }
  uVar1 = 0;
  do {
    *(undefined *)(param_1 + uVar1) = *(undefined *)(iVar2 + (uint)*(byte *)(param_1 + uVar1));
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x10);
  return;
}




void FUN_00023172(undefined4 param_1,undefined4 param_2)

{
  FUN_00023140(param_1,param_2,0x10);
  return;
}




int FUN_0002318c(void)

{
  int iVar1;
  
  iVar1 = FUN_00023a94();
  return iVar1 + 4;
}




undefined8 FUN_000231a0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  if ((param_4 | param_3) == 0) {
    return 0;
  }
  uVar5 = 0;
  if (param_4 != 0) {
    iVar3 = LZCOUNT(param_4);
    uVar1 = param_4 << iVar3;
    uVar5 = uVar1 >> iVar3 ^ param_4 | param_3;
  }
  else {
    iVar3 = LZCOUNT(param_3);
    uVar1 = param_3 << iVar3;
  }
  uVar4 = -iVar3 + 0x20;
  if (param_4 != 0) {
    uVar1 = uVar1 | param_3 >> (uVar4 & 0xff);
    uVar4 = -iVar3 + 0x40;
  }
  uVar2 = uVar1 >> 0x10;
  if ((uVar5 | uVar1 << 0x10) != 0) {
    uVar2 = uVar2 + 1;
  }
  iVar3 = 0;
  uVar5 = 0;
  for (; param_4 < param_2 || param_2 - param_4 < (uint)(param_3 <= param_1);
      param_2 = (param_2 -
                (uVar1 * param_4 +
                uVar7 * param_3 + (int)((ulonglong)uVar1 * (ulonglong)param_3 >> 0x20))) -
                (uint)bVar11) {
    if (param_2 != 0) {
      iVar8 = LZCOUNT(param_2);
      uVar1 = param_2 << iVar8;
    }
    else {
      iVar8 = LZCOUNT(param_1);
      uVar1 = param_1 << iVar8;
    }
    uVar9 = -iVar8 + 0x20;
    if (param_2 != 0) {
      uVar1 = uVar1 | param_1 >> (uVar9 & 0xff);
      uVar9 = -iVar8 + 0x40;
    }
    uVar10 = (uVar9 - uVar4) - 0x10;
    uVar6 = uVar1 / uVar2 >> (0x20 - (uVar10 & 0x1f) & 0xff);
    uVar7 = uVar6;
    uVar1 = uVar1 / uVar2 << (uVar10 & 0x1f);
    if ((int)uVar10 < 0) {
      uVar7 = 0;
      uVar1 = uVar6;
    }
    if (0x1f < (int)uVar10) {
      uVar7 = uVar1;
    }
    if ((int)((uVar9 - uVar4) + -0x30) < 0 == SBORROW4(uVar10,0x20)) {
      uVar1 = 0;
    }
    if ((uVar1 | uVar7) == 0) {
      uVar1 = 1;
    }
    bVar11 = CARRY4(uVar5,uVar1);
    uVar5 = uVar5 + uVar1;
    uVar9 = (uint)((ulonglong)uVar1 * (ulonglong)param_3);
    iVar3 = iVar3 + uVar7 + bVar11;
    bVar11 = param_1 < uVar9;
    param_1 = param_1 - uVar9;
  }
  return CONCAT44(iVar3,uVar5);
}




int FUN_0002328e(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0002318c();
  if ((int)((uint)*(byte *)(*piVar1 + param_1) << 0x1b) < 0) {
    return param_1 + 0x20;
  }
  return param_1;
}




void FUN_000232a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_00023bd4(param_1,DAT_000232bc,&uStack_c);
  return;
}




void FUN_000232c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20 = param_1;
  uStack_1c = param_4;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_00023b76(param_2,&local_20,&uStack_8,DAT_000232e4 + 0x232cc);
  FUN_00023b9c(0,&local_20);
  return;
}




void FUN_000232e8(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[6];
  if ((int)(*param_1 << 0x1b) < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if ((*param_1 & 1) != 0) {
    return;
  }
  while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
    (*(code *)param_1[1])(uVar2,param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  return;
}




void FUN_00023314(byte *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((*param_1 & 1) == 0) {
    return;
  }
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(param_1 + 4))(0x20,*(undefined4 *)(param_1 + 8));
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  return;
}




void FUN_00023336(byte *param_1,undefined *param_2,uint param_3)

{
  uint uVar1;
  undefined *puVar2;
  
  if (param_3 == 1) {
    uVar1 = 1;
  }
  else {
    if ((int)((uint)*param_1 << 0x1a) < 0) {
      param_3 = *(uint *)(param_1 + 0x1c);
    }
    for (uVar1 = 0; (uVar1 < param_3 && (param_2[uVar1] != '\0')); uVar1 = uVar1 + 1) {
    }
  }
  puVar2 = param_2 + uVar1;
  *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar1;
  *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar1;
  FUN_000232e8(param_1);
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    (**(code **)(param_1 + 4))(*param_2,*(undefined4 *)(param_1 + 8));
  }
  FUN_00023314(param_1);
  return;
}




uint FUN_00023458(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar1 = DAT_0002358c;
  param_1[8] = 0;
  while (uVar2 = (*(code *)param_1[3])(param_1), uVar2 != 0) {
    if (uVar2 == 0x25) {
      uVar5 = 0;
      while (((uVar2 = (*(code *)param_1[3])(param_1), 0x1f < (int)uVar2 && (uVar2 < 0x31)) &&
             (uVar3 = (uint)*(byte *)(iVar1 + uVar2 + 0x2344c), uVar3 != 0))) {
        uVar5 = uVar5 | uVar3;
      }
      if ((int)(uVar5 << 0x1e) < 0) {
        uVar5 = uVar5 & 0xfffffffb;
      }
      param_1[7] = 0;
      iVar6 = 0;
      param_1[6] = 0;
      puVar7 = param_2;
      do {
        if (uVar2 == 0x2a) {
          param_2 = puVar7 + 1;
          param_1[iVar6 + 6] = *puVar7;
          uVar2 = (*(code *)param_1[3])(param_1);
          if (iVar6 == 1) {
            if ((int)param_1[7] < 0) {
              uVar5 = uVar5 & 0xffffffdf;
            }
            break;
          }
        }
        else {
          iVar4 = FUN_00025966(uVar2);
          if (iVar4 != 0) {
            param_1[iVar6 + 6] = uVar2 - 0x30;
            while( true ) {
              uVar2 = (*(code *)param_1[3])(param_1);
              iVar4 = FUN_00025966();
              if (iVar4 == 0) break;
              param_1[iVar6 + 6] = (uVar2 + param_1[iVar6 + 6] * 10) - 0x30;
            }
          }
          param_2 = puVar7;
          if (iVar6 == 1) break;
        }
        if (uVar2 != 0x2e) break;
        uVar2 = (*(code *)param_1[3])(param_1);
        iVar6 = iVar6 + 1;
        uVar5 = uVar5 | 0x20;
        puVar7 = param_2;
      } while (iVar6 < 2);
      if ((int)param_1[6] < 0) {
        uVar5 = uVar5 | 1;
        param_1[6] = -param_1[6];
      }
      if ((uVar5 & 1) != 0) {
        uVar5 = uVar5 & 0xffffffef;
      }
      if (uVar2 == 0) break;
      if (uVar2 - 0x41 < 0x1a) {
        uVar2 = uVar2 + 0x20;
        uVar5 = uVar5 | 0x800;
      }
      *param_1 = uVar5;
      iVar6 = FUN_000001e4(param_1,uVar2,param_2);
      if (iVar6 == 0) goto LAB_0002347c;
      if (iVar6 == 1) {
        param_2 = param_2 + 1;
      }
      else {
        param_2 = (uint *)(((int)param_2 + 7U & 0xfffffff8) + 8);
      }
    }
    else {
LAB_0002347c:
      (*(code *)param_1[1])(uVar2,param_1[2]);
      param_1[8] = param_1[8] + 1;
    }
  }
  return param_1[8];
}




void FUN_00023590(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_00023a9c();
  uVar2 = *puVar1;
  FUN_00023c9c(param_1,0,10);
  *puVar1 = uVar2;
  return;
}




void FUN_000235aa(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_00023a9c();
  uVar2 = *puVar1;
  FUN_00023c9c(param_1,0,10);
  *puVar1 = uVar2;
  return;
}




void FUN_000235c4(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_000235f8;
  iVar2 = DAT_000235f4;
  iVar3 = DAT_000235f4 + -0x7c;
  *(int *)(DAT_000235f4 + 0x60) = DAT_000235f4;
  *(int *)(iVar2 + 100) = iVar3;
  iVar2 = 0x37;
  while (0 < iVar2) {
    *(uint *)(iVar3 + (iVar2 + -1) * 4) = param_1 + (param_1 >> 0x10);
    param_1 = param_1 * DAT_000235fc + iVar1;
    iVar2 = iVar2 + -1;
  }
  return;
}




char * FUN_00023600(int param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 + -1);
  do {
    pcVar1 = pcVar1 + 1;
    if (param_2 == *pcVar1) {
      return pcVar1;
    }
  } while (*pcVar1 != '\0');
  return (char *)0x0;
}




int FUN_00023614(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      uVar4 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      if (uVar4 != uVar3) {
        if ((uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
            uVar4 >> 0x18) <=
            (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18)) {
          return -1;
        }
        return 1;
      }
    }
  }
  if (param_3 != 0) {
    if ((param_3 & 1) == 0) goto LAB_0002364c;
    param_3 = param_3 + 1;
    puVar1 = param_1;
    puVar2 = param_2;
    while( true ) {
      param_1 = (uint *)((int)puVar1 + 1);
      param_2 = (uint *)((int)puVar2 + 1);
      if ((uint)*(byte *)puVar1 - (uint)*(byte *)puVar2 != 0) {
        return (uint)*(byte *)puVar1 - (uint)*(byte *)puVar2;
      }
      param_3 = param_3 - 2;
      if (param_3 == 0) break;
LAB_0002364c:
      puVar1 = (uint *)((int)param_1 + 1);
      puVar2 = (uint *)((int)param_2 + 1);
      if ((uint)*(byte *)param_1 - (uint)*(byte *)param_2 != 0) {
        return (uint)*(byte *)param_1 - (uint)*(byte *)param_2;
      }
    }
    return 0;
  }
  return 0;
}




void FUN_0002366c(uint *param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while( true ) {
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) break;
      *param_1 = uVar4;
      param_1 = param_1 + 1;
    }
    while( true ) {
      *(char *)param_1 = (char)uVar4;
      if ((uVar4 & 0xff) == 0) break;
      uVar4 = uVar4 >> 8;
      param_1 = (uint *)((int)param_1 + 1);
    }
  }
  else {
    do {
      pcVar2 = (char *)((int)param_2 + 1);
      cVar1 = *(char *)param_2;
      pcVar3 = (char *)((int)param_1 + 1);
      *(char *)param_1 = cVar1;
      if (cVar1 == '\0') {
        return;
      }
      param_2 = (uint *)((int)param_2 + 2);
      cVar1 = *pcVar2;
      param_1 = (uint *)((int)param_1 + 2);
      *pcVar3 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}




int FUN_000236b4(uint *param_1)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = param_1;
  while (((uint)puVar3 & 3) != 0) {
    puVar2 = (uint *)((int)puVar3 + 1);
    cVar1 = *(char *)puVar3;
    puVar3 = puVar2;
    if (cVar1 == '\0') {
      return (int)puVar2 - (int)(char *)((int)param_1 + 1);
    }
  }
  do {
    uVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    uVar5 = uVar5 + 0xfefefeff & ~uVar5;
  } while ((uVar5 & 0x80808080) == 0);
  iVar4 = (int)puVar3 - (int)(char *)((int)param_1 + 1);
  if ((uVar5 & 0x80) == 0) {
    if ((uVar5 & 0x8080) == 0) {
      if ((uVar5 & 0x808080) != 0) {
        return iVar4 + -1;
      }
    }
    else {
      iVar4 = iVar4 + -2;
    }
    return iVar4;
  }
  return iVar4 + -3;
}




uint FUN_000236f2(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      uVar4 = *param_1;
      param_1 = param_1 + 1;
      uVar5 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      uVar6 = uVar4 + 0xfefefeff & ~uVar4 & 0x80808080;
      if (uVar6 != 0) {
        uVar1 = (uVar4 & 0xff) - (uVar5 & 0xff);
        if ((((uVar1 | uVar6 << 0x18) == 0) &&
            (uVar1 = (uVar4 & 0xffff) - (uVar5 & 0xffff), (uVar1 | uVar6 << 0x10) == 0)) &&
           (uVar1 = (uVar4 & 0xffffff) - (uVar5 & 0xffffff), (uVar1 | uVar6 << 8) == 0)) {
          uVar1 = (uVar4 >> 0x18) - (uVar5 >> 0x18);
        }
        return uVar1;
      }
      if (uVar4 != uVar5) {
        if ((uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
            uVar4 >> 0x18) <=
            (uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18)) {
          return 0xffffffff;
        }
        return 1;
      }
    }
  }
  if (param_3 == 0) {
    return 0;
  }
  while( true ) {
    pbVar2 = (byte *)((int)param_1 + 1);
    uVar4 = (uint)*(byte *)param_1;
    pbVar3 = (byte *)((int)param_2 + 1);
    uVar5 = (uint)*(byte *)param_2;
    if (((uVar4 == 0) || (uVar4 != uVar5)) || (param_3 == 1)) break;
    param_1 = (uint *)((int)param_1 + 2);
    uVar4 = (uint)*pbVar2;
    param_2 = (uint *)((int)param_2 + 2);
    uVar5 = (uint)*pbVar3;
    if (((uVar4 == 0) || (uVar4 != uVar5)) || (param_3 = param_3 - 2, param_3 == 0)) break;
  }
  return uVar4 - uVar5;
}




void FUN_00023788(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + -1);
  do {
    pcVar2 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  do {
    cVar1 = *param_2;
    *pcVar2 = cVar1;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return;
}




undefined8 FUN_000237a0(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  byte *pbVar5;
  byte bVar6;
  undefined2 uVar7;
  byte in_r12;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  puVar4 = param_2;
  if (3 < param_3) {
    uVar8 = (uint)param_1 & 3;
    puVar2 = param_1;
    uVar9 = uVar8;
    if (uVar8 != 0) {
      bVar6 = *(byte *)param_2;
      puVar4 = (uint *)((int)param_2 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_2 + 2);
        uVar9 = (uint)*(byte *)(uint *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar6;
      param_2 = puVar4;
      if (uVar8 < 2) {
        param_2 = (uint *)((int)puVar4 + 1);
        bVar6 = *(byte *)puVar4;
      }
      param_3 = (param_3 + uVar8) - 4;
      puVar4 = (uint *)((int)param_1 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_1 + 2);
        *(byte *)(uint *)((int)param_1 + 1) = (byte)uVar9;
      }
      puVar2 = puVar4;
      if (uVar8 < 2) {
        puVar2 = (uint *)((int)puVar4 + 1);
        *(byte *)puVar4 = bVar6;
      }
    }
    param_4 = (uint)param_2 & 3;
    if (param_4 == 0) {
      uVar9 = 0;
      while (uVar8 = param_3 - 0x20, 0x1f < param_3) {
        uVar9 = param_2[1];
        uVar10 = param_2[2];
        uVar11 = param_2[3];
        *puVar2 = *param_2;
        puVar2[1] = uVar9;
        puVar2[2] = uVar10;
        puVar2[3] = uVar11;
        uVar9 = param_2[4];
        uVar10 = param_2[5];
        uVar11 = param_2[6];
        uVar12 = param_2[7];
        param_2 = param_2 + 8;
        puVar2[4] = uVar9;
        puVar2[5] = uVar10;
        puVar2[6] = uVar11;
        puVar2[7] = uVar12;
        puVar2 = puVar2 + 8;
        param_3 = uVar8;
      }
      if ((uVar8 & 0x10) != 0) {
        uVar9 = *param_2;
        uVar10 = param_2[1];
        uVar11 = param_2[2];
        uVar12 = param_2[3];
        param_2 = param_2 + 4;
        *puVar2 = uVar9;
        puVar2[1] = uVar10;
        puVar2[2] = uVar11;
        puVar2[3] = uVar12;
        puVar2 = puVar2 + 4;
      }
      if ((int)(param_3 << 0x1c) < 0) {
        uVar9 = *param_2;
        uVar10 = param_2[1];
        param_2 = param_2 + 2;
        *puVar2 = uVar9;
        puVar2[1] = uVar10;
        puVar2 = puVar2 + 2;
      }
      puVar3 = puVar2;
      puVar4 = param_2;
      if ((uVar8 & 4) != 0) {
        puVar4 = param_2 + 1;
        uVar9 = *param_2;
        puVar3 = puVar2 + 1;
        *puVar2 = uVar9;
      }
      uVar7 = (undefined2)uVar9;
      if ((uVar8 & 3) != 0) {
        bVar1 = (uVar8 & 2) != 0;
        param_3 = param_3 << 0x1f;
        bVar13 = (int)param_3 < 0;
        puVar2 = puVar4;
        if (bVar1) {
          puVar2 = (uint *)((int)puVar4 + 2);
          uVar7 = *(undefined2 *)puVar4;
        }
        puVar4 = puVar2;
        if (bVar13) {
          puVar4 = (uint *)((int)puVar2 + 1);
          param_3 = (uint)*(byte *)puVar2;
        }
        puVar2 = puVar3;
        if (bVar1) {
          puVar2 = (uint *)((int)puVar3 + 2);
          *(undefined2 *)puVar3 = uVar7;
        }
        puVar3 = puVar2;
        if (bVar13) {
          puVar3 = (uint *)((int)puVar2 + 1);
          *(byte *)puVar2 = (byte)param_3;
        }
        return CONCAT44(puVar4,puVar3);
      }
      return CONCAT44(puVar4,puVar3);
    }
    while( true ) {
      in_r12 = (byte)uVar9;
      if (param_3 < 8) break;
      puVar4 = param_2 + 1;
      param_4 = *param_2;
      param_2 = param_2 + 2;
      uVar9 = *puVar4;
      *puVar2 = param_4;
      puVar2[1] = uVar9;
      puVar2 = puVar2 + 2;
      param_3 = param_3 - 8;
    }
    param_3 = param_3 - 4;
    param_1 = puVar2;
    puVar4 = param_2;
    if (-1 < (int)param_3) {
      puVar4 = param_2 + 1;
      param_4 = *param_2;
      param_1 = puVar2 + 1;
      *puVar2 = param_4;
    }
  }
  bVar6 = (byte)param_4;
  bVar1 = (param_3 & 2) != 0;
  param_3 = param_3 << 0x1f;
  bVar13 = (int)param_3 < 0;
  if (bVar1) {
    pbVar5 = (byte *)((int)puVar4 + 1);
    bVar6 = *(byte *)puVar4;
    puVar4 = (uint *)((int)puVar4 + 2);
    in_r12 = *pbVar5;
  }
  puVar2 = puVar4;
  if (bVar13) {
    puVar2 = (uint *)((int)puVar4 + 1);
    param_3 = (uint)*(byte *)puVar4;
  }
  if (bVar1) {
    pbVar5 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = bVar6;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar5 = in_r12;
  }
  puVar4 = param_1;
  if (bVar13) {
    puVar4 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  return CONCAT44(puVar2,puVar4);
}




undefined8 FUN_0002382a(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint in_r12;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  
  bVar5 = (byte)in_r12;
  uVar8 = (int)param_1 - (int)param_2;
  bVar14 = uVar8 == 0;
  if (param_2 <= param_1) {
    bVar14 = param_3 == uVar8;
  }
  if ((param_2 <= param_1 && uVar8 <= param_3) && !bVar14) {
    param_1 = (uint *)((int)param_1 + param_3);
    param_2 = (uint *)((int)param_2 + param_3);
    if (3 < param_3) {
      bVar14 = ((uint)param_1 & 3) == 0;
      do {
        if (!bVar14) {
          param_2 = (uint *)((int)param_2 + -1);
          param_3 = param_3 - 1;
          param_1 = (uint *)((int)param_1 + -1);
          *(byte *)param_1 = *(byte *)param_2;
        }
        bVar14 = ((uint)param_1 & 3) == 0;
      } while (!bVar14);
      uVar8 = (uint)param_2 & 3;
      if (uVar8 == 0) {
        while (uVar8 = param_3 - 0x10, 0xf < param_3) {
          puVar3 = param_2 + -1;
          uVar11 = param_2[-2];
          uVar10 = param_2[-3];
          param_2 = param_2 + -4;
          uVar9 = *param_2;
          param_1[-1] = *puVar3;
          param_1[-2] = uVar11;
          param_1[-3] = uVar10;
          param_1 = param_1 + -4;
          *param_1 = uVar9;
          param_3 = uVar8;
        }
        uVar9 = param_3 << 0x1d;
        bVar14 = (int)uVar9 < 0;
        if ((uVar8 & 8) != 0) {
          puVar3 = param_2 + -1;
          param_2 = param_2 + -2;
          uVar9 = *param_2;
          param_1[-1] = *puVar3;
          param_1 = param_1 + -2;
          *param_1 = uVar9;
        }
        if (bVar14) {
          param_2 = param_2 + -1;
          uVar9 = *param_2;
          param_1 = param_1 + -1;
          *param_1 = uVar9;
        }
        uVar7 = (undefined2)uVar9;
        if ((uVar8 & 3) != 0) {
          bVar14 = (uVar8 & 2) != 0;
          param_3 = param_3 << 0x1f;
          bVar13 = (int)param_3 < 0;
          if (bVar14) {
            param_2 = (uint *)((int)param_2 + -2);
            uVar7 = *(undefined2 *)param_2;
          }
          if (bVar13) {
            param_3 = (uint)*(byte *)((int)param_2 + -1);
          }
          if (bVar14) {
            param_1 = (uint *)((int)param_1 + -2);
            *(undefined2 *)param_1 = uVar7;
          }
          if (bVar13) {
            *(byte *)((int)param_1 + -1) = (byte)param_3;
          }
          return CONCAT44(param_2,param_1);
        }
        return CONCAT44(param_2,param_1);
      }
      while( true ) {
        bVar5 = (byte)in_r12;
        if (param_3 < 8) break;
        uVar8 = param_2[-1];
        param_2 = param_2 + -2;
        in_r12 = *param_2;
        param_1[-1] = uVar8;
        param_1 = param_1 + -2;
        *param_1 = in_r12;
        param_3 = param_3 - 8;
      }
      param_3 = param_3 - 4;
      if (-1 < (int)param_3) {
        param_2 = param_2 + -1;
        uVar8 = *param_2;
        param_1 = param_1 + -1;
        *param_1 = uVar8;
      }
    }
    bVar6 = (byte)uVar8;
    bVar14 = (param_3 & 2) != 0;
    param_3 = param_3 << 0x1f;
    bVar13 = (int)param_3 < 0;
    if (bVar14) {
      bVar6 = *(byte *)((int)param_2 + -1);
      param_2 = (uint *)((int)param_2 + -2);
      bVar5 = *(byte *)param_2;
    }
    if (bVar13) {
      param_3 = (uint)*(byte *)((int)param_2 + -1);
    }
    if (bVar14) {
      *(byte *)((int)param_1 + -1) = bVar6;
      param_1 = (uint *)((int)param_1 + -2);
      *(byte *)param_1 = bVar5;
    }
    if (bVar13) {
      *(byte *)((int)param_1 + -1) = (byte)param_3;
    }
    return CONCAT44(param_2,param_1);
  }
  puVar3 = param_2;
  if (3 < param_3) {
    uVar8 = (uint)param_1 & 3;
    puVar1 = param_1;
    uVar9 = uVar8;
    if (uVar8 != 0) {
      bVar5 = *(byte *)param_2;
      puVar3 = (uint *)((int)param_2 + 1);
      if (uVar8 < 3) {
        puVar3 = (uint *)((int)param_2 + 2);
        uVar9 = (uint)*(byte *)(uint *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar5;
      param_2 = puVar3;
      if (uVar8 < 2) {
        param_2 = (uint *)((int)puVar3 + 1);
        bVar5 = *(byte *)puVar3;
      }
      param_3 = (param_3 + uVar8) - 4;
      puVar3 = (uint *)((int)param_1 + 1);
      if (uVar8 < 3) {
        puVar3 = (uint *)((int)param_1 + 2);
        *(byte *)(uint *)((int)param_1 + 1) = (byte)uVar9;
      }
      puVar1 = puVar3;
      if (uVar8 < 2) {
        puVar1 = (uint *)((int)puVar3 + 1);
        *(byte *)puVar3 = bVar5;
      }
    }
    uVar8 = (uint)param_2 & 3;
    if (uVar8 == 0) {
      uVar8 = 0;
      while (uVar9 = param_3 - 0x20, 0x1f < param_3) {
        uVar8 = param_2[1];
        uVar10 = param_2[2];
        uVar11 = param_2[3];
        *puVar1 = *param_2;
        puVar1[1] = uVar8;
        puVar1[2] = uVar10;
        puVar1[3] = uVar11;
        uVar8 = param_2[4];
        uVar10 = param_2[5];
        uVar11 = param_2[6];
        uVar12 = param_2[7];
        param_2 = param_2 + 8;
        puVar1[4] = uVar8;
        puVar1[5] = uVar10;
        puVar1[6] = uVar11;
        puVar1[7] = uVar12;
        puVar1 = puVar1 + 8;
        param_3 = uVar9;
      }
      if ((uVar9 & 0x10) != 0) {
        uVar8 = *param_2;
        uVar10 = param_2[1];
        uVar11 = param_2[2];
        uVar12 = param_2[3];
        param_2 = param_2 + 4;
        *puVar1 = uVar8;
        puVar1[1] = uVar10;
        puVar1[2] = uVar11;
        puVar1[3] = uVar12;
        puVar1 = puVar1 + 4;
      }
      if ((int)(param_3 << 0x1c) < 0) {
        uVar8 = *param_2;
        uVar10 = param_2[1];
        param_2 = param_2 + 2;
        *puVar1 = uVar8;
        puVar1[1] = uVar10;
        puVar1 = puVar1 + 2;
      }
      puVar2 = puVar1;
      puVar3 = param_2;
      if ((uVar9 & 4) != 0) {
        puVar3 = param_2 + 1;
        uVar8 = *param_2;
        puVar2 = puVar1 + 1;
        *puVar1 = uVar8;
      }
      uVar7 = (undefined2)uVar8;
      if ((uVar9 & 3) != 0) {
        bVar14 = (uVar9 & 2) != 0;
        param_3 = param_3 << 0x1f;
        bVar13 = (int)param_3 < 0;
        puVar1 = puVar3;
        if (bVar14) {
          puVar1 = (uint *)((int)puVar3 + 2);
          uVar7 = *(undefined2 *)puVar3;
        }
        puVar3 = puVar1;
        if (bVar13) {
          puVar3 = (uint *)((int)puVar1 + 1);
          param_3 = (uint)*(byte *)puVar1;
        }
        puVar1 = puVar2;
        if (bVar14) {
          puVar1 = (uint *)((int)puVar2 + 2);
          *(undefined2 *)puVar2 = uVar7;
        }
        puVar2 = puVar1;
        if (bVar13) {
          puVar2 = (uint *)((int)puVar1 + 1);
          *(byte *)puVar1 = (byte)param_3;
        }
        return CONCAT44(puVar3,puVar2);
      }
      return CONCAT44(puVar3,puVar2);
    }
    while( true ) {
      bVar5 = (byte)uVar9;
      if (param_3 < 8) break;
      puVar3 = param_2 + 1;
      uVar8 = *param_2;
      param_2 = param_2 + 2;
      uVar9 = *puVar3;
      *puVar1 = uVar8;
      puVar1[1] = uVar9;
      puVar1 = puVar1 + 2;
      param_3 = param_3 - 8;
    }
    param_3 = param_3 - 4;
    param_1 = puVar1;
    puVar3 = param_2;
    if (-1 < (int)param_3) {
      puVar3 = param_2 + 1;
      uVar8 = *param_2;
      param_1 = puVar1 + 1;
      *puVar1 = uVar8;
    }
  }
  bVar6 = (byte)uVar8;
  bVar14 = (param_3 & 2) != 0;
  param_3 = param_3 << 0x1f;
  bVar13 = (int)param_3 < 0;
  if (bVar14) {
    pbVar4 = (byte *)((int)puVar3 + 1);
    bVar6 = *(byte *)puVar3;
    puVar3 = (uint *)((int)puVar3 + 2);
    bVar5 = *pbVar4;
  }
  puVar1 = puVar3;
  if (bVar13) {
    puVar1 = (uint *)((int)puVar3 + 1);
    param_3 = (uint)*(byte *)puVar3;
  }
  if (bVar14) {
    pbVar4 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = bVar6;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar4 = bVar5;
  }
  puVar3 = param_1;
  if (bVar13) {
    puVar3 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  return CONCAT44(puVar1,puVar3);
}




undefined8 FUN_000238ae(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  
  uVar4 = param_3 - 0x20;
  if (0x1f < param_3) {
    do {
      uVar6 = param_2[1];
      uVar7 = param_2[2];
      uVar8 = param_2[3];
      bVar10 = 0x1f < uVar4;
      uVar4 = uVar4 - 0x20;
      *param_1 = *param_2;
      param_1[1] = uVar6;
      param_1[2] = uVar7;
      param_1[3] = uVar8;
      param_4 = param_2[4];
      uVar6 = param_2[5];
      uVar7 = param_2[6];
      uVar8 = param_2[7];
      param_2 = param_2 + 8;
      param_1[4] = param_4;
      param_1[5] = uVar6;
      param_1[6] = uVar7;
      param_1[7] = uVar8;
      param_1 = param_1 + 8;
    } while (bVar10);
  }
  if ((uVar4 & 0x10) != 0) {
    param_4 = *param_2;
    uVar6 = param_2[1];
    uVar7 = param_2[2];
    uVar8 = param_2[3];
    param_2 = param_2 + 4;
    *param_1 = param_4;
    param_1[1] = uVar6;
    param_1[2] = uVar7;
    param_1[3] = uVar8;
    param_1 = param_1 + 4;
  }
  if ((int)(uVar4 << 0x1c) < 0) {
    param_4 = *param_2;
    uVar6 = param_2[1];
    param_2 = param_2 + 2;
    *param_1 = param_4;
    param_1[1] = uVar6;
    param_1 = param_1 + 2;
  }
  puVar1 = param_1;
  puVar3 = param_2;
  if ((uVar4 & 4) != 0) {
    puVar3 = param_2 + 1;
    param_4 = *param_2;
    puVar1 = param_1 + 1;
    *param_1 = param_4;
  }
  uVar5 = (undefined2)param_4;
  if ((uVar4 & 3) != 0) {
    bVar10 = (uVar4 & 2) != 0;
    uVar4 = uVar4 << 0x1f;
    bVar9 = (int)uVar4 < 0;
    puVar2 = puVar3;
    if (bVar10) {
      puVar2 = (undefined4 *)((int)puVar3 + 2);
      uVar5 = *(undefined2 *)puVar3;
    }
    puVar3 = puVar2;
    if (bVar9) {
      puVar3 = (undefined4 *)((int)puVar2 + 1);
      uVar4 = (uint)*(byte *)puVar2;
    }
    puVar2 = puVar1;
    if (bVar10) {
      puVar2 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = uVar5;
    }
    puVar1 = puVar2;
    if (bVar9) {
      puVar1 = (undefined4 *)((int)puVar2 + 1);
      *(char *)puVar2 = (char)uVar4;
    }
    return CONCAT44(puVar3,puVar1);
  }
  return CONCAT44(puVar3,puVar1);
}




undefined4 * FUN_00023912(undefined4 *param_1,uint param_2,undefined param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  uVar1 = CONCAT11(param_3,param_3);
  uVar6 = CONCAT22(uVar1,uVar1);
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar3 = (undefined *)((int)param_1 + 1);
      *(undefined *)param_1 = param_3;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar3 = param_3;
    }
    puVar2 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = param_3;
    }
    return puVar2;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar7 = 4 - ((uint)param_1 & 3);
    puVar2 = param_1;
    if (iVar7 != 2) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = param_3;
    }
    param_1 = puVar2;
    if (1 < iVar7) {
      param_1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
    }
    param_2 = param_2 - iVar7;
  }
  bVar8 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar8) {
      *param_1 = uVar6;
      param_1[1] = uVar6;
      param_1[2] = uVar6;
      param_1[3] = uVar6;
      param_1[4] = uVar6;
      param_1[5] = uVar6;
      param_1[6] = uVar6;
      param_1[7] = uVar6;
      param_1 = param_1 + 8;
      bVar8 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar8);
  if ((param_2 & 0x10) != 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1[2] = uVar6;
    param_1[3] = uVar6;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1 = param_1 + 2;
  }
  uVar5 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = uVar6;
  }
  if (uVar5 != 0) {
    puVar4 = puVar2;
    if ((int)uVar5 < 0) {
      puVar4 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
    }
    puVar2 = puVar4;
    if ((uVar5 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar4 + 1);
      *(undefined *)puVar4 = param_3;
    }
    return puVar2;
  }
  return puVar2;
}




undefined4 * FUN_00023922(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar2 = (undefined *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar2 = 0;
    }
    puVar1 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
    }
    return puVar1;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar5 = 4 - ((uint)param_1 & 3);
    puVar1 = param_1;
    if (iVar5 != 2) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
    }
    param_1 = puVar1;
    if (1 < iVar5) {
      param_1 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    param_2 = param_2 - iVar5;
  }
  bVar6 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar6) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar6 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar6);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar4 = param_2 << 0x1e;
  puVar1 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar1 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar4 != 0) {
    puVar3 = puVar1;
    if ((int)uVar4 < 0) {
      puVar3 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    puVar1 = puVar3;
    if ((uVar4 & 0x40000000) != 0) {
      puVar1 = (undefined4 *)((int)puVar3 + 1);
      *(undefined *)puVar3 = 0;
    }
    return puVar1;
  }
  return puVar1;
}




undefined4 * FUN_00023966(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar4) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar4 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar4);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar3 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar3 != 0) {
    puVar1 = puVar2;
    if ((int)uVar3 < 0) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = 0;
    }
    puVar2 = puVar1;
    if ((uVar3 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(undefined *)puVar1 = 0;
    }
    return puVar2;
  }
  return puVar2;
}




uint * FUN_000239b4(uint *param_1,uint *param_2,int param_3)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  bVar6 = ((uint)param_1 & 3) == 0;
  if (bVar6) {
    bVar6 = ((uint)param_2 & 3) == 0;
  }
  puVar2 = param_1;
  if (bVar6) {
    while (3 < param_3) {
      uVar5 = *param_2;
      if ((uVar5 + 0xfefefeff & ~uVar5 & 0x80808080) != 0) break;
      *puVar2 = uVar5;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -4;
    }
  }
  do {
    iVar4 = param_3 + -1;
    if (param_3 < 1) {
      return param_1;
    }
    cVar1 = *(char *)param_2;
    puVar3 = (uint *)((int)puVar2 + 1);
    *(char *)puVar2 = cVar1;
    puVar2 = puVar3;
    param_2 = (uint *)((int)param_2 + 1);
    param_3 = iVar4;
  } while (cVar1 != '\0');
  FUN_00023922(puVar3,iVar4);
  return param_1;
}




int FUN_00023a0c(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  while( true ) {
    uVar4 = *param_1;
    uVar5 = *param_2;
    if (uVar4 != uVar5) break;
    if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
      return 0;
    }
    puVar1 = param_1 + 2;
    uVar4 = param_1[1];
    puVar3 = param_2 + 2;
    uVar5 = param_2[1];
    if (uVar4 != uVar5) break;
    if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
      return 0;
    }
    param_1 = param_1 + 3;
    uVar4 = *puVar1;
    param_2 = param_2 + 3;
    uVar5 = *puVar3;
    if (uVar4 != uVar5) break;
    if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
      return 0;
    }
  }
  uVar2 = uVar4 - uVar5;
  uVar2 = LZCOUNT(uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                  uVar2 >> 0x18) & 0x18;
  uVar6 = 0x1010101 >> (0x20 - uVar2 & 0xff);
  if ((uVar4 - uVar6 & ~uVar4 & uVar6 << 7) != 0) {
    return 0;
  }
  return (uVar4 >> uVar2 & 0xff) - (uVar5 >> uVar2 & 0xff);
}




undefined4 FUN_00023a94(void)

{
  return DAT_00023a98;
}




undefined4 FUN_00023a9c(void)

{
  return DAT_00023aa0;
}




undefined4 FUN_00023aa4(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00023a9c();
  return *puVar1;
}




void FUN_00023aae(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00023a9c();
  *puVar1 = param_1;
  return;
}




void FUN_00023b76(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined auStack_40 [4];
  undefined4 local_3c;
  undefined4 uStack_38;
  int local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  
  local_2c = 0;
  local_34 = DAT_00023b98 + 0x23b88;
  local_3c = param_4;
  uStack_38 = param_2;
  uStack_30 = param_1;
  FUN_00023458(auStack_40,param_3);
  return;
}




void FUN_00023b9c(undefined param_1,undefined4 *param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)*param_2;
  *puVar1 = param_1;
  *param_2 = puVar1 + 1;
  return;
}




undefined4 FUN_00023bd4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00023b76();
  iVar2 = FUN_00023e80(param_2);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  return uVar1;
}




void FUN_00023bf8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 uStack_10;
  int local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_38 = &uStack_8;
  *(undefined4 *)(param_2 + 0xc) = 0;
  local_20 = DAT_00023c90 + 0x23c0e;
  local_1c = DAT_00023c94 + 0x23c14;
  local_34 = 4;
  uStack_30 = 0x7fffffff;
  local_18 = DAT_00023c98 + 0x23c24;
  uStack_10 = param_1;
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  thunk_FUN_00024274(0,param_2,param_1,&local_38);
  return;
}




void FUN_00023c34(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  int iStack_20;
  int local_18 [2];
  
  local_24 = 0xffffffff;
  local_18[0] = 0;
  local_28 = param_2;
  iStack_20 = param_2;
  iVar1 = FUN_00023bf8(local_18,&local_28,param_1);
  local_24 = param_2 + local_18[0];
  if (param_3 != (int *)0x0) {
    iVar2 = param_2;
    if (local_18[0] != 0) {
      iVar2 = local_24;
    }
    *param_3 = iVar2;
  }
  if ((local_18[0] != 0) && ((iVar1 < 1 || (local_28 != local_24)))) {
    local_24 = local_24 - param_2;
    local_28 = param_2;
    iStack_20 = param_2;
    FUN_00023bf8(local_18,&local_28,param_1);
  }
  return;
}




int FUN_00023c9c(byte *param_1,byte **param_2,undefined4 param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar6;
  
  iVar9 = 0;
  pbVar5 = param_1;
  do {
    pbVar6 = pbVar5;
    pbVar5 = pbVar6 + 1;
    uVar8 = (uint)*pbVar6;
    if (uVar8 == 0) break;
    piVar2 = (int *)FUN_0002318c();
  } while ((*(byte *)(*piVar2 + uVar8) & 1) != 0);
  pbVar7 = pbVar5;
  if ((uVar8 != 0x2b) && (pbVar7 = pbVar6, uVar8 == 0x2d)) {
    iVar9 = 0x400;
    pbVar7 = pbVar5;
  }
  iVar3 = FUN_00023de2(pbVar7,param_2,param_3);
  if ((param_2 != (byte **)0x0) && (*param_2 == pbVar7)) {
    *param_2 = param_1;
  }
  if (iVar9 << 0x15 < 0) {
    bVar1 = iVar3 < 0;
    iVar3 = -iVar3;
    if (bVar1) {
      puVar4 = (undefined4 *)FUN_00023a9c();
      *puVar4 = 2;
      iVar3 = -0x80000000;
    }
  }
  else if (iVar3 < 0) {
    puVar4 = (undefined4 *)FUN_00023a9c();
    *puVar4 = 2;
    iVar3 = 0x7fffffff;
  }
  return iVar3;
}




uint FUN_00023de2(char *param_1,char **param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  
  bVar1 = false;
  pcVar7 = param_1 + 1;
  bVar2 = false;
  cVar3 = *param_1;
  if (cVar3 == '0') {
    pcVar8 = param_1 + 2;
    cVar3 = *pcVar7;
    bVar1 = true;
    pcVar7 = pcVar8;
    if ((cVar3 == 'x') || (cVar3 == 'X')) {
      if ((param_3 == 0) || (param_3 == 0x10)) {
        bVar1 = false;
        cVar3 = *pcVar8;
        param_3 = 0x10;
        pcVar7 = param_1 + 3;
      }
    }
    else if (param_3 == 0) {
      param_3 = 8;
    }
  }
  else if (param_3 == 0) {
    param_3 = 10;
  }
  uVar9 = 0;
  uVar10 = 0;
  while (iVar5 = FUN_0002400a(cVar3,param_3), -1 < iVar5) {
    uVar4 = param_3 * uVar10 + iVar5;
    bVar1 = true;
    uVar10 = uVar4 & 0xffff;
    uVar9 = param_3 * uVar9 + (uVar4 >> 0x10);
    if (0xffff < uVar9) {
      bVar2 = true;
    }
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  }
  if (param_2 != (char **)0x0) {
    if (bVar1) {
      param_1 = pcVar7 + -1;
    }
    *param_2 = param_1;
  }
  if (bVar2) {
    puVar6 = (undefined4 *)FUN_00023a9c();
    *puVar6 = 2;
    uVar10 = 0xffffffff;
  }
  else {
    uVar10 = uVar10 | uVar9 << 0x10;
  }
  return uVar10;
}




byte FUN_00023e80(int param_1)

{
  return *(byte *)(param_1 + 0xc) & 0x80;
}




void FUN_00023e88(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  FUN_00023966(DAT_00023f94,0x54);
  FUN_00023966(DAT_00023f98,0x54);
  FUN_00023966(DAT_00023f9c,0x54);
  piVar3 = DAT_00023fa8;
  iVar1 = DAT_00023f98;
  iVar4 = DAT_00023f94;
  *DAT_00023fa0 = DAT_00023f94;
  *DAT_00023fa4 = iVar1;
  iVar2 = DAT_00023f9c;
  *piVar3 = DAT_00023f9c;
  *(int *)(iVar4 + 0x50) = iVar1 + 1;
  *(int *)(iVar1 + 0x50) = iVar2 + 1;
  *(undefined4 *)(iVar2 + 0x50) = 1;
  iVar4 = FUN_00024568(DAT_00023fb0 + 0x23eca,&DAT_00023fac,DAT_00023f94);
  if (iVar4 == 0) {
    FUN_000246b2(DAT_00023fb0 + 0x23eca);
  }
  iVar4 = FUN_00024568(DAT_00023fb8 + 0x23ee2,&DAT_00023fb4,DAT_00023f98);
  if (iVar4 == 0) {
    FUN_000246b2(DAT_00023fb8 + 0x23ee2);
  }
  iVar4 = FUN_00024568(DAT_00023fbc + 0x23efa,&DAT_00023fb4,DAT_00023f9c);
  if (iVar4 == 0) {
    FUN_000246b2(DAT_00023fbc + 0x23efa);
  }
  iVar4 = FUN_00024520(DAT_00023f94,0,0x200);
  if (iVar4 != 0) {
    FUN_000246b2(DAT_00023fb0 + 0x23eca);
  }
  iVar4 = FUN_00024520(DAT_00023f98,0,0x200,0x40);
  if (iVar4 != 0) {
    FUN_000246b2(DAT_00023fb8 + 0x23ee2);
  }
  iVar4 = FUN_00024520(DAT_00023f9c,0,0x200,0x10);
  if (iVar4 != 0) {
    FUN_000246b2(DAT_00023fbc + 0x23efa);
    return;
  }
  return;
}




void FUN_00023f5a(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(DAT_00023f9c + 0x50);
  FUN_00024654(DAT_00023f94);
  FUN_00024654(DAT_00023f98);
  FUN_00024654(DAT_00023f9c);
  while (uVar2 = uVar1 & 0xfffffffe, uVar2 != 0) {
    uVar1 = *(uint *)(uVar2 + 0x50);
    FUN_00024654(uVar2);
    thunk_FUN_0001d330(uVar2);
  }
  return;
}




uint FUN_0002400a(uint param_1,uint param_2)

{
  if (param_1 < 0x3a) {
    param_1 = param_1 - 0x30;
  }
  if (0x40 < (param_1 & 0xffffffdf)) {
    param_1 = (param_1 & 0xffffffdf) - 0x37;
  }
  if (param_2 <= param_1) {
    param_1 = 0xffffffff;
  }
  return param_1;
}




/* WARNING: Removing unreachable block (ram,0x000240c4) */
/* WARNING: Removing unreachable block (ram,0x000240e8) */
/* WARNING: Removing unreachable block (ram,0x00024116) */

longlong FUN_00024028(uint *param_1,char *param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  undefined8 uVar12;
  int local_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint local_3c;
  uint *puStack_34;
  char *pcStack_30;
  byte *pbStack_2c;
  uint local_28;
  
  if (*param_2 == -1) {
    iVar10 = 0;
  }
  else {
    iVar10 = 0;
    for (pbVar4 = (byte *)(param_2 + 1); *pbVar4 != 0xff; pbVar4 = pbVar4 + 1) {
      iVar10 = (uint)*pbVar4 + iVar10 * 10;
    }
    if (*param_2 == '-') {
      iVar10 = -iVar10;
    }
  }
  bVar1 = *param_3;
  uVar2 = 0;
  bVar11 = false;
  if ((bVar1 == 0x2d) || (pbVar4 = param_3, bVar1 == 0x2b)) {
    pbVar4 = param_3 + 1;
    bVar11 = bVar1 == 0x2d;
  }
  while( true ) {
    iVar8 = (int)(uVar2 >> 0x20);
    if (*pbVar4 == 0xff) break;
    uVar2 = (uVar2 & 0xffffffff) * 10 + CONCAT44(iVar8 * 10,(uint)*pbVar4);
    pbVar4 = pbVar4 + 1;
  }
  iVar10 = iVar10 + param_4;
  if (uVar2 != 0) {
    puStack_34 = param_1;
    pcStack_30 = param_2;
    pbStack_2c = param_3;
    local_28 = param_4;
    if (iVar10 + 500 < 0 == SCARRY4(iVar10,500)) {
      if (iVar10 < 0x1f5) {
        local_3c = 0;
        iVar6 = iVar10;
        if (iVar10 < 0) {
          iVar6 = -iVar10;
        }
        FUN_000246c0(&local_48,iVar6,0);
        local_54 = local_48;
        uStack_50 = uStack_44;
        uStack_4c = uStack_40;
        local_60 = 0x403e;
        if (iVar8 == 0) {
          uVar2 = uVar2 << 0x20;
          local_60 = 0x401e;
        }
        if ((uVar2 & 0xffff000000000000) == 0) {
          uVar2 = uVar2 << 0x10;
          local_60 = local_60 + -0x10;
        }
        if ((uVar2 & 0xff00000000000000) == 0) {
          uVar2 = uVar2 << 8;
          local_60 = local_60 + -8;
        }
        if ((uVar2 & 0xf000000000000000) == 0) {
          uVar2 = uVar2 << 4;
          local_60 = local_60 + -4;
        }
        if ((uVar2 & 0xc000000000000000) == 0) {
          uVar2 = uVar2 << 2;
          local_60 = local_60 + -2;
        }
        uVar5 = (uint)uVar2;
        if ((uVar2 & 0x8000000000000000) == 0) {
          uVar2 = CONCAT44((int)(uVar2 >> 0x20) * 2 + (uint)CARRY4(uVar5,uVar5),uVar5 * 2);
          local_60 = local_60 + -1;
        }
        local_5c = (undefined4)(uVar2 >> 0x20);
        uStack_58 = (undefined4)uVar2;
        if (iVar10 < 1) {
          uVar12 = FUN_0002537e(&local_60,&local_54,0,1);
        }
        else {
          uVar12 = FUN_000253d2();
        }
        uVar7 = (uint)((ulonglong)uVar12 >> 0x20);
        uVar9 = (uint)uVar12;
        if (bVar11) {
          uVar9 = uVar9 ^ 0x80000000;
        }
        if ((((local_3c & 0xc) != 0) || ((uVar9 & 0x7fffffff | uVar7) == 0)) ||
           (uVar5 = (uVar9 << 1) >> 0x15, param_4 = local_3c, uVar5 == 0x7ff)) {
          uVar12 = FUN_00023a9c();
          param_4 = (uint)((ulonglong)uVar12 >> 0x20);
          *(undefined4 *)uVar12 = 2;
          uVar5 = (uVar9 << 1) >> 0x15;
          if (uVar5 == 0x7ff) {
            uVar5 = *(uint *)(DAT_000244fc + 0x24262);
            *param_1 = *(uint *)(DAT_000244fc + 0x2425e);
            param_1[1] = uVar5;
            param_4 = uVar9 & 0x80000000;
            uVar5 = uVar5 | param_4;
            param_1[1] = uVar5;
            goto LAB_000240f4;
          }
        }
        *param_1 = uVar7;
        param_1[1] = uVar9;
        goto LAB_000240f4;
      }
      uVar5 = *(uint *)(DAT_000244f8 + 0x24126);
      *param_1 = *(uint *)(DAT_000244f8 + 0x24122);
      param_1[1] = uVar5;
      param_1[1] = uVar5 | (uint)bVar11 << 0x1f;
      puVar3 = (undefined4 *)FUN_00023a9c();
      *puVar3 = 2;
      uVar5 = 0x14;
    }
    else {
      param_1[1] = (uint)bVar11 << 0x1f;
      *param_1 = 0;
      puVar3 = (undefined4 *)FUN_00023a9c();
      *puVar3 = 2;
      uVar5 = 0x18;
    }
    return (ulonglong)uVar5 << 0x20;
  }
  uVar5 = (uint)bVar11 << 0x1f;
  *param_1 = 0;
  param_1[1] = uVar5;
LAB_000240f4:
  return CONCAT44(param_4,uVar5);
}




undefined * FUN_00024274(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int **param_4)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  int *piVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  undefined *local_78;
  uint local_74;
  int *local_70;
  uint uStack_6c;
  undefined local_68;
  char local_67 [23];
  undefined4 local_50;
  undefined4 local_4c;
  undefined local_48 [12];
  int local_3c;
  uint local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 *local_2c;
  int **ppiStack_28;
  
  iVar13 = 0;
  piVar6 = param_4[1];
  piVar10 = param_4[2];
  local_3c = 0;
  uStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  ppiStack_28 = param_4;
  iVar1 = FUN_00023a94();
  local_38 = (uint)*(byte *)((int)*(int **)(iVar1 + 0xc) + **(int **)(iVar1 + 0xc));
  puVar9 = (undefined *)0xffffffff;
  do {
    puVar12 = puVar9;
    puVar9 = puVar12 + 1;
    uVar2 = (*(code *)param_4[6])(local_30);
    iVar1 = (*(code *)param_4[8])();
  } while (iVar1 != 0);
  if (uVar2 == 0xffffffff) {
    return (undefined *)0xffffffff;
  }
  uVar7 = (uint)piVar6 & 0xfffff97f;
  if (0 < (int)piVar10) {
    if (uVar2 != 0x2b) {
      if (uVar2 != 0x2d) goto LAB_000242de;
      uVar7 = uVar7 | 0x400;
    }
    puVar9 = puVar12 + 2;
    uVar2 = (*(code *)param_4[6])(local_30);
    piVar10 = (int *)((int)piVar10 + -1);
  }
LAB_000242de:
  if ((int)(uVar7 << 0x15) < 0) {
    local_68 = 0x2d;
  }
  else {
    local_68 = 0x2b;
  }
  pcVar15 = local_67;
  puVar12 = local_48;
  if (0 < (int)piVar10) {
    if (((((uVar2 == 0x69) || (uVar2 == 0x49)) || (uVar2 == 0x6e)) || (uVar2 == 0x4e)) &&
       (local_78 = puVar9, local_74 = uVar7, local_70 = piVar10, uStack_6c = uVar2,
       puVar3 = (undefined *)thunk_FUN_00024cec(0xfffffffd,local_30,local_2c,param_4),
       puVar3 != (undefined *)0xfffffffd)) {
      return puVar3;
    }
    do {
      if (uVar2 != 0x30) {
        if (((uVar2 == 0x78) || (uVar2 == 0x58)) &&
           ((local_3c == 1 &&
            (local_78 = puVar9, local_74 = uVar7, local_70 = piVar10,
            puVar3 = (undefined *)thunk_FUN_000249cc(0xfffffffd,local_30,local_2c,param_4),
            puVar3 != (undefined *)0xfffffffd)))) {
          return puVar3;
        }
        break;
      }
      puVar9 = puVar9 + 1;
      uVar2 = (*(code *)param_4[6])(local_30);
      piVar10 = (int *)((int)piVar10 + -1);
      uVar7 = uVar7 | 0x200;
      *local_2c = puVar9;
      local_3c = local_3c + 1;
    } while (0 < (int)piVar10);
  }
  if (uVar2 == local_38) {
    uVar7 = uVar7 | 0x80;
    puVar3 = puVar9;
    while( true ) {
      puVar9 = puVar3 + 1;
      piVar10 = (int *)((int)piVar10 + -1);
      uVar2 = (*(code *)param_4[6])(local_30);
      if (uVar2 != 0x30) break;
      iVar13 = iVar13 + -1;
      uVar7 = uVar7 | 0x200;
      *local_2c = puVar3 + 2;
      puVar3 = puVar9;
    }
  }
  do {
    if ((int)piVar10 < 1) {
LAB_000244ac:
      (*(code *)param_4[7])(local_30);
      *pcVar15 = -1;
      *puVar12 = 0xff;
      local_50 = 0;
      local_4c = 0;
      FUN_00024028(&local_50,local_48,&local_68,iVar13);
      if (-1 < (int)(uVar7 << 0x16)) {
        return (undefined *)0xfffffffe;
      }
      if ((uVar7 & 0x24) != 0) {
        if ((uVar7 & 1) != 0) {
          return puVar9;
        }
        piVar6 = *param_4;
        *param_4 = piVar6 + 1;
        puVar5 = (undefined4 *)*piVar6;
        *puVar5 = local_50;
        puVar5[1] = local_4c;
        return puVar9;
      }
      FUN_00025940(&local_78,&local_50);
      if ((uVar7 & 1) != 0) {
        return puVar9;
      }
      piVar6 = *param_4;
      *param_4 = piVar6 + 1;
      *(undefined **)*piVar6 = local_78;
      return puVar9;
    }
    if ((uVar2 == local_38) && (-1 < (int)(uVar7 << 0x18))) {
      uVar8 = uVar7 | 0x80;
    }
    else {
      iVar1 = FUN_00025966(uVar2);
      if (iVar1 == 0) {
        if ((0 < (int)piVar10) &&
           (((uVar2 == 0x65 || (uVar2 == 0x45)) && ((int)(uVar7 << 0x16) < 0)))) {
          iVar11 = (int)piVar10 + -1;
          uVar7 = uVar7 & 0xfffffcff;
          iVar1 = (*(code *)param_4[6])(local_30);
          puVar12 = puVar9 + 1;
          if (0 < iVar11) {
            if (iVar1 != 0x2b) {
              if (iVar1 != 0x2d) goto LAB_00024446;
              uVar7 = uVar7 | 0x100;
            }
            iVar1 = (*(code *)param_4[6])(local_30);
            iVar11 = (int)piVar10 + -2;
            puVar12 = puVar9 + 2;
          }
LAB_00024446:
          puVar9 = puVar12;
          if ((int)(uVar7 << 0x17) < 0) {
            local_48[0] = 0x2d;
          }
          else {
            local_48[0] = 0x2b;
          }
          puVar12 = local_48 + 1;
          local_78 = puVar12;
          while ((0 < iVar11 && (iVar4 = FUN_00025966(iVar1), iVar4 != 0))) {
            iVar11 = iVar11 + -1;
            if (puVar12 < local_48 + 9) {
              *puVar12 = (char)(iVar1 - 0x30U);
              if (((iVar1 - 0x30U & 0xff) != 0) || (local_78 < puVar12)) {
                puVar12 = puVar12 + 1;
              }
            }
            else {
              iVar13 = DAT_00024500;
              if (-1 < (int)(uVar7 << 0x17)) {
                iVar13 = 9999;
              }
            }
            puVar9 = puVar9 + 1;
            iVar1 = (*(code *)param_4[6])(local_30);
            *local_2c = puVar9;
            uVar7 = uVar7 | 0x200;
          }
        }
        goto LAB_000244ac;
      }
      uVar8 = uVar7 | 0x200;
      if (pcVar15 < local_67 + 0x12) {
        pcVar14 = pcVar15 + 1;
        *pcVar15 = (char)uVar2 + -0x30;
        pcVar15 = pcVar14;
        if ((int)(uVar7 << 0x18) < 0) {
          iVar13 = iVar13 + -1;
        }
      }
      else if (-1 < (int)(uVar7 << 0x18)) {
        iVar13 = iVar13 + 1;
      }
    }
    piVar10 = (int *)((int)piVar10 + -1);
    if ((int)(uVar8 << 0x16) < 0) {
      *local_2c = puVar9 + 1;
    }
    puVar9 = puVar9 + 1;
    uVar2 = (*(code *)param_4[6])(local_30);
    uVar7 = uVar8;
  } while( true );
}




undefined4 FUN_00024520(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if (((uVar1 & 3) != 0) && (-1 < (int)(uVar1 << 9))) {
    if ((param_3 == 0x100) || (param_3 == 0x200)) {
      if (0xfffffe < param_4 - 1U) {
        return 1;
      }
    }
    else {
      if (param_3 != 0x400) {
        return 1;
      }
      param_4 = 1;
      param_2 = param_1 + 0x24;
    }
    *(int *)(param_1 + 0x10) = param_2;
    *(int *)(param_1 + 0x1c) = param_4;
    *(int *)(param_1 + 4) = param_2;
    *(uint *)(param_1 + 0xc) = uVar1 & 0xfffff0ff | param_3;
    return 0;
  }
  return 1;
}




int FUN_00024568(undefined4 param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_00024654(param_3);
  cVar1 = *param_2;
  param_2 = param_2 + 1;
  if (cVar1 == 'a') {
    uVar3 = 8;
    uVar4 = 0x8002;
  }
  else if (cVar1 == 'r') {
    uVar4 = 1;
    uVar3 = 0;
  }
  else {
    if (cVar1 != 'w') {
      return 0;
    }
    uVar4 = 2;
    uVar3 = 4;
  }
  while( true ) {
    while( true ) {
      if (*param_2 != '+') break;
      uVar4 = uVar4 | 3;
      uVar3 = uVar3 | 2;
      param_2 = param_2 + 1;
    }
    if (*param_2 != 'b') break;
    uVar4 = uVar4 | 4;
    uVar3 = uVar3 | 1;
    param_2 = param_2 + 1;
  }
  if (*param_2 == 't') {
    uVar3 = uVar3 | 0x10;
  }
  iVar2 = FUN_00012a9c(param_1,uVar3);
  if (iVar2 == -1) {
    return 0;
  }
  *(undefined4 *)(param_3 + 0x10) = 0;
  *(undefined4 *)(param_3 + 4) = 0;
  *(uint *)(param_3 + 0xc) = uVar4;
  *(undefined4 *)(param_3 + 0x1c) = 0x200;
  *(int *)(param_3 + 0x14) = iVar2;
  if ((int)(uVar3 << 0x1c) < 0) {
    FUN_000247a4(param_3,0,2);
  }
  *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 1;
  return param_3;
}




undefined4 FUN_00024606(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = DAT_00024650;
  do {
    uVar1 = *(uint *)(uVar3 + 0x50);
    if ((uVar1 & 1) == 0) {
LAB_00024642:
      uVar2 = FUN_00024568(param_1,param_2,uVar3);
      return uVar2;
    }
    if (uVar1 >> 1 == 0) {
      uVar1 = thunk_FUN_0001d084(0x54);
      if (uVar1 == 0) {
        return 0;
      }
      *(uint *)(uVar3 + 0x50) = *(uint *)(uVar3 + 0x50) | uVar1 | 1;
      FUN_00023966(uVar1,0x54);
      uVar3 = uVar1;
      goto LAB_00024642;
    }
    uVar3 = uVar1 & 0xfffffffe;
  } while( true );
}




undefined4 FUN_00024654(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  uVar3 = *(undefined4 *)(param_1 + 0x14);
  if ((uVar2 & 3) != 0) {
    FUN_00024904(param_1);
    iVar1 = FUN_00012ae8(uVar3);
    if (-1 < iVar1) {
      if ((int)(uVar2 << 0x14) < 0) {
        thunk_FUN_0001d330(uVar4);
      }
      FUN_00023966(param_1,0x4c);
      *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xfffffffe;
      return 0;
    }
  }
  return 0xffffffff;
}




uint FUN_000246a0(undefined4 param_1,undefined4 param_2)

{
  int **ppiVar1;
  uint uVar2;
  uint *puVar3;
  int **ppiVar4;
  int **ppiVar5;
  
  FUN_0000024c();
  FUN_00012bc4(param_1,param_2);
  ppiVar1 = DAT_000002a4;
  puVar3 = (uint *)DAT_000002a4[1];
  ppiVar5 = (int **)(*DAT_000002a4 + 1);
  uVar2 = *puVar3 + **DAT_000002a4;
  ppiVar4 = (int **)(puVar3 + 1);
  *puVar3 = uVar2;
  if (ppiVar1 <= ppiVar5) {
    ppiVar5 = ppiVar1 + -0x37;
  }
  if (ppiVar1 <= ppiVar4) {
    ppiVar4 = ppiVar1 + -0x37;
  }
  *ppiVar1 = (int *)ppiVar5;
  ppiVar1[1] = (int *)ppiVar4;
  return uVar2 & 0x7fffffff;
}




void FUN_000246b2(void)

{
  int iVar1;
  
  iVar1 = FUN_00024998();
  if (iVar1 != 0) {
    FUN_00012bc4();
    return;
  }
  return;
}




void FUN_000246c0(undefined8 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 local_48;
  int iStack_40;
  undefined8 local_3c;
  int iStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  
  iVar4 = DAT_000247a0;
  uVar9 = *(undefined8 *)(DAT_000247a0 + 0x246d0);
  iStack_40 = *(int *)(DAT_000247a0 + 0x246d8);
  local_3c._0_4_ = *(undefined4 *)(DAT_000247a0 + 0x246dc);
  local_3c._4_4_ = *(undefined4 *)(DAT_000247a0 + 0x246e0);
  iStack_34 = *(int *)(DAT_000247a0 + 0x246e4);
  uVar5 = (param_2 + 0x1b9b) / 0x37 - 0x80;
  uVar3 = (param_2 + 0x1b9b) % 0x37 - 0x1b;
  bVar7 = -1 < (int)uVar3;
  if (!bVar7) {
    uVar3 = -uVar3;
  }
  iVar6 = 0;
  for (; uVar8 = CONCAT44(local_3c._4_4_,(undefined4)local_3c), uVar3 != 0; uVar3 = (int)uVar3 >> 1)
  {
    if ((uVar3 & 1) != 0) {
      iVar2 = param_3;
      local_48 = uVar9;
      uVar9 = FUN_000253a8(&local_48,FUN_00024654 + iVar6 * 0xc + iVar4,param_3,1);
      iStack_40 = iVar2;
    }
    iVar6 = iVar6 + 1;
  }
  iVar6 = DAT_000247a0 + 0x24690;
  iVar4 = 0;
  for (; local_48 = uVar9, local_3c = uVar8, uVar5 != 0; uVar5 = (int)uVar5 >> 1) {
    if ((uVar5 & 1) != 0) {
      puVar1 = (undefined4 *)(iVar6 + iVar4 * 0x10);
      local_30 = *puVar1;
      uStack_2c = puVar1[1];
      local_28 = puVar1[2];
      if (puVar1[3] + param_3 == 0) {
        local_28 = local_28 + param_3;
      }
      iVar2 = param_3;
      uVar8 = FUN_000253a8(&local_3c,&local_30,param_3,1);
      iStack_34 = iVar2;
      uVar9 = local_48;
    }
    iVar4 = iVar4 + 1;
  }
  if (bVar7) {
    uVar9 = FUN_000253a8(&local_3c,&local_48,param_3,1);
  }
  else {
    uVar9 = FUN_00025354();
  }
  *param_1 = uVar9;
  *(int *)(param_1 + 1) = param_3;
  return;
}




undefined4 FUN_000247a4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_1[5];
  if (((*(byte *)(param_1 + 3) & 3) == 0) || (iVar1 = FUN_00012bea(iVar7), iVar1 != 0)) {
    return 2;
  }
  if (param_3 != 0) {
    if (param_3 == 1) {
      iVar7 = FUN_00024e20(param_1);
      param_2 = param_2 + iVar7;
    }
    else {
      if (param_3 != 2) {
        return 2;
      }
      iVar7 = FUN_00012bcc(iVar7);
      uVar2 = param_1[3];
      param_1[3] = uVar2 | 0x10;
      if (iVar7 < 0) {
        FUN_0002489c(param_1);
        return 1;
      }
      if ((int)((uVar2 | 0x10) << 0xf) < 0) {
        uVar2 = param_1[0xb];
        if ((uint)param_1[0xb] <= (uint)param_1[1]) {
          uVar2 = param_1[1];
        }
        iVar1 = (uVar2 + param_1[6]) - param_1[4];
        if (iVar7 < iVar1) {
          iVar7 = iVar1;
        }
      }
      param_2 = param_2 + iVar7;
    }
  }
  if (param_2 < 0) {
    return 2;
  }
  uVar2 = param_1[1];
  uVar4 = param_1[3];
  if (((uint)param_1[0xb] < uVar2) && (param_1[0xb] = uVar2, (int)(uVar4 << 0xe) < 0)) {
    uVar4 = uVar4 & 0xfffdffff | 0x10;
  }
  iVar7 = param_1[6];
  if (iVar7 <= param_2) {
    uVar3 = param_1[0xb];
    uVar5 = uVar2;
    if (uVar2 < uVar3) {
      uVar5 = uVar3;
    }
    uVar6 = param_1[4];
    if (param_2 < (int)((uVar5 + iVar7) - uVar6)) {
      uVar5 = uVar2;
      if (uVar2 < uVar3) {
        uVar5 = uVar3;
      }
      if (uVar5 != uVar6) {
        param_2 = param_2 - iVar7;
        param_1[2] = param_2 - param_1[7];
        if (uVar2 < uVar3) {
          uVar2 = uVar3;
        }
        *param_1 = param_2 - (uVar2 - uVar6);
        param_1[1] = uVar6 + param_2;
        uVar4 = uVar4 & 0xffffffdf;
        goto LAB_00024888;
      }
    }
  }
  param_1[2] = 0;
  *param_1 = 0;
  uVar4 = uVar4 | 0x20;
  param_1[10] = param_2;
LAB_00024888:
  param_1[3] = uVar4 & DAT_00024898;
  *(undefined *)(param_1 + 0x12) = 0;
  return 0;
}




void FUN_0002489c(undefined4 *param_1)

{
  param_1[3] = param_1[3] & 0xffdfffff | 0x80;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}




undefined4 FUN_000248b0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_3 + 0xc);
  uVar3 = *(undefined4 *)(param_3 + 0x14);
  if ((uVar2 & DAT_00024988) != 0) {
    iVar1 = FUN_00012b88(uVar3,*(undefined4 *)(param_3 + 0x18));
    if (iVar1 < 0) goto LAB_000248f8;
    uVar2 = uVar2 & ~DAT_00024988;
    *(uint *)(param_3 + 0xc) = uVar2;
  }
  uVar2 = FUN_00012b24(uVar3,param_1,param_2,uVar2);
  *(uint *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + (param_2 - (uVar2 & 0x7fffffff));
  if (uVar2 == 0) {
    return 0;
  }
LAB_000248f8:
  FUN_0002489c(param_3);
  return 0xffffffff;
}




undefined4 FUN_00024904(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x2c);
  if (*(uint *)(param_1 + 0x2c) <= *(uint *)(param_1 + 4)) {
    uVar1 = *(uint *)(param_1 + 4);
  }
  uVar3 = *(uint *)(param_1 + 0xc) & 0xffd7ffff;
  *(uint *)(param_1 + 0xc) = uVar3;
  if ((int)(uVar3 << 0xf) < 0) {
    if ((uVar1 != uVar4) && (iVar2 = FUN_000248b0(uVar4,uVar1 - uVar4,param_1), iVar2 != 0)) {
      return 0xffffffff;
    }
    *(uint *)(param_1 + 0x2c) = uVar4;
    *(uint *)(param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 8) = 0;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffeffff;
  }
  return 0;
}




void FUN_0002494a(int param_1)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffdf;
  if (*(int *)(param_1 + 0x18) != *(int *)(param_1 + 0x28)) {
    FUN_00024904(param_1);
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffcfff | 0x10;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x10);
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffbfbf;
  return;
}




undefined4 FUN_00024998(undefined4 param_1)

{
  FUN_00024e62(s_SIGRTRED__Redirect__can_t_open__000249a8,param_1);
  return 1;
}




/* WARNING: Removing unreachable block (ram,0x00024bf2) */

int FUN_000249cc(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,
                uint param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint **ppuVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  undefined8 uVar14;
  longlong lVar15;
  longlong lVar16;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  undefined4 uStack_34;
  undefined4 local_30;
  int *local_2c;
  int *piStack_28;
  
  iVar10 = 0x3c;
  param_5 = param_5 + 1;
  local_44 = (param_6 & 0x400) << 0x15;
  local_3c = 0;
  bVar13 = false;
  uVar8 = 0;
  uVar7 = 0;
  local_40 = 0;
  iVar9 = -1;
  uStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  piStack_28 = param_4;
  local_48 = (*(code *)param_4[6])(param_2);
  param_7 = param_7 + -1;
  while (0 < param_7) {
    if (local_48 == 0x2e) {
      local_40 = 1;
    }
    else {
      uVar2 = FUN_0002400a(local_48,0x10);
      if ((int)uVar2 < 0) {
        if ((local_48 == 0x70) || (local_48 == 0x50)) {
          local_48 = 0;
          local_40 = 1;
          if (!bVar13) goto LAB_00024ab6;
          iVar10 = (*(code *)param_4[6])(local_30);
          iVar11 = param_7 + -1;
          if (iVar11 < 1) goto LAB_00024ab6;
          if (iVar10 == 0x2b) {
LAB_00024ad4:
            iVar10 = (*(code *)param_4[6])(local_30);
            iVar11 = param_7 + -2;
            iVar1 = param_5 + 2;
            if (iVar11 < 1) goto LAB_00024ab6;
          }
          else {
            iVar1 = param_5 + 1;
            if (iVar10 == 0x2d) {
              local_40 = -1;
              goto LAB_00024ad4;
            }
          }
          param_5 = iVar1;
          if ((iVar10 == -1) || (iVar10 = FUN_0002400a(iVar10,10), iVar10 < 0)) {
LAB_00024ab6:
            (*(code *)param_4[7])(local_30);
            return -2;
          }
          goto LAB_00024af6;
        }
        break;
      }
      bVar13 = true;
      if ((local_3c | uVar2) == 0) {
        if (local_40 != 0) {
          iVar9 = iVar9 + -4;
        }
      }
      else {
        if (iVar10 < 0) {
          if (uVar2 != 0) {
            uVar8 = uVar8 | 1;
          }
        }
        else {
          uVar14 = FUN_00024e94(uVar2,(int)uVar2 >> 0x1f,iVar10);
          uVar8 = uVar8 | (uint)uVar14;
          uVar7 = uVar7 | (uint)((ulonglong)uVar14 >> 0x20);
          iVar10 = iVar10 + -4;
        }
        local_3c = 1;
        if (local_40 == 0) {
          iVar9 = iVar9 + 4;
        }
      }
    }
    param_5 = param_5 + 1;
    local_48 = (*(code *)param_4[6])(local_30);
    param_7 = param_7 + -1;
    if (bVar13) {
      *local_2c = param_5;
    }
  }
  (*(code *)param_4[7])(local_30);
  if (!bVar13) {
    return -2;
  }
  goto LAB_00024b34;
  while (-1 < iVar10) {
LAB_00024af6:
    param_5 = param_5 + 1;
    local_48 = iVar10 + local_48 * 10;
    uVar3 = (*(code *)param_4[6])(local_30);
    iVar10 = FUN_0002400a(uVar3,10);
    iVar11 = iVar11 + -1;
    *local_2c = param_5;
    if (iVar11 < 1) break;
  }
  (*(code *)param_4[7])(local_30);
  iVar9 = local_48 * local_40 + iVar9;
LAB_00024b34:
  local_4c = local_44;
  if ((uVar8 | uVar7) != 0) {
    if ((uVar7 & 0xc0000000) == 0) {
      uVar7 = uVar7 << 2 | uVar8 >> 0x1e;
      uVar8 = uVar8 << 2;
      iVar9 = iVar9 + -2;
    }
    if ((uVar7 & 0x80000000) == 0) {
      bVar13 = CARRY4(uVar8,uVar8);
      uVar8 = uVar8 * 2;
      uVar7 = uVar7 * 2 + (uint)bVar13;
      iVar9 = iVar9 + -1;
    }
    if ((param_6 & 0x24) == 0) {
      iVar11 = 0x28;
      iVar10 = -0x7e;
    }
    else {
      iVar11 = 0xb;
      iVar10 = DAT_00024ce0;
    }
    if ((iVar9 < iVar10) && (iVar11 = iVar11 + (iVar10 - iVar9), 0x41 < iVar11)) {
      iVar11 = 0x41;
    }
    lVar15 = FUN_00024e94(1,0,iVar11 + -1);
    bVar13 = ((uint)lVar15 & uVar8 | (uint)((ulonglong)lVar15 >> 0x20) & uVar7) != 0;
    local_48 = (uint)bVar13;
    bVar12 = ((uint)(lVar15 + -1) & uVar8 | (uint)((ulonglong)(lVar15 + -1) >> 0x20) & uVar7) != 0;
    if (((bVar13 || bVar12) && (local_48 != 0)) &&
       ((bVar12 ||
        (uVar14 = FUN_00024e94(1,0,iVar11),
        ((uint)uVar14 & uVar8 | (uint)((ulonglong)uVar14 >> 0x20) & uVar7) != 0)))) {
      lVar16 = FUN_00024e94(1,0,iVar11);
      lVar15 = lVar16 + CONCAT44(uVar7,uVar8);
      uVar2 = (uint)lVar15;
      uVar6 = (uint)((ulonglong)lVar15 >> 0x20);
      if (uVar6 < uVar7 || uVar7 - uVar6 < (uint)(uVar2 <= uVar8)) {
        if (iVar11 < 0x41) {
          iVar9 = iVar9 + 1;
        }
        else if ((param_6 & 0x24) == 0) {
          iVar9 = iVar10 + -0x17;
        }
        else {
          iVar9 = iVar10 + -0x34;
        }
        uVar8 = 0;
        uVar7 = 0;
      }
      else {
        uVar8 = uVar2 & ~(uint)(lVar16 + -1);
        uVar7 = uVar6 & ~(uint)((ulonglong)(lVar16 + -1) >> 0x20);
      }
    }
    if (iVar9 <= 1 - iVar10) {
      local_50 = uVar8 >> 0xb | uVar7 << 0x15;
      local_4c = local_44 | (uVar7 << 1) >> 0xc | DAT_00024ce8;
      FUN_00025952(&local_50,iVar9);
      goto LAB_00024ca0;
    }
    local_4c = local_44 | DAT_00024ce4;
  }
  local_50 = 0;
LAB_00024ca0:
  if ((param_6 & 0x24) == 0) {
    FUN_00025940(&local_48,&local_50);
    if ((param_6 & 1) == 0) {
      ppuVar4 = (uint **)*param_4;
      *param_4 = (int)(ppuVar4 + 1);
      **ppuVar4 = local_48;
    }
  }
  else if ((param_6 & 1) == 0) {
    ppuVar4 = (uint **)*param_4;
    *param_4 = (int)(ppuVar4 + 1);
    puVar5 = *ppuVar4;
    *puVar5 = local_50;
    puVar5[1] = local_4c;
  }
  return param_5;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00024cec(undefined4 param_1,undefined4 param_2,int *param_3,int **param_4,int param_5,
                uint param_6,int param_7,uint param_8)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint **ppuVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  int *piStack_2c;
  int **ppiStack_28;
  
  iVar7 = param_7 + -1;
  uVar1 = (param_6 & 0x400) << 0x15;
  uVar9 = uVar1 | 0x7f800000;
  uVar8 = uVar1 | DAT_00024e10;
  local_38 = 0;
  uStack_34 = param_1;
  local_30 = param_2;
  piStack_2c = param_3;
  ppiStack_28 = param_4;
  if ((param_8 & 0xffffffdf) == 0x49) {
    iVar6 = 1;
    local_48 = s_INFINITY_00024e14._0_4_;
    uStack_44 = s_INFINITY_00024e14._4_4_;
    uStack_40 = ram0x00024e1c;
    while( true ) {
      iVar5 = param_5;
      param_5 = iVar5 + 1;
      uVar1 = (*(code *)param_4[6])(local_30);
      iVar7 = iVar7 + -1;
      if (((iVar7 < 0) || (*(byte *)((int)&local_48 + iVar6) == 0)) ||
         ((uVar1 & 0xffffffdf) != (uint)*(byte *)((int)&local_48 + iVar6))) break;
      iVar6 = iVar6 + 1;
      if ((iVar6 == 3) || (iVar6 == 8)) {
        *param_3 = iVar5 + 2;
      }
    }
    (*(code *)param_4[7])(local_30);
    if ((iVar6 != 3) && (iVar6 != 8)) {
      return -2;
    }
  }
  else if ((param_8 & 0xffffffdf) == 0x4e) {
    uVar9 = (*(code *)param_4[6])(param_2);
    if ((((param_7 + -2 < 0) || ((uVar9 & 0xffffffdf) != 0x41)) ||
        (uVar9 = (*(code *)param_4[6])(local_30), param_7 + -3 < 0)) ||
       ((uVar9 & 0xffffffdf) != 0x4e)) {
LAB_00024dd6:
      (*(code *)param_4[7])(local_30);
      return -2;
    }
    param_5 = param_5 + 3;
    iVar7 = (*(code *)param_4[6])(local_30);
    param_7 = param_7 + -4;
    uVar8 = uVar8 | 0x80000;
    uVar9 = uVar1 | 0x7fc00000;
    *param_3 = param_5;
    if ((param_7 < 0) || (iVar7 != 0x28)) {
      (*(code *)param_4[7])(local_30);
    }
    else {
      do {
        iVar6 = param_5;
        iVar7 = (*(code *)param_4[6])(local_30);
        param_7 = param_7 + -1;
        if ((param_7 < 0) || (iVar7 < 0)) goto LAB_00024dd6;
        param_5 = iVar6 + 1;
      } while (iVar7 != 0x29);
      param_5 = iVar6 + 2;
      *param_3 = param_5;
    }
  }
  if ((param_6 & 1) == 0) {
    if ((param_6 & 0x24) == 0) {
      ppuVar4 = (uint **)*param_4;
      *param_4 = (int *)(ppuVar4 + 1);
      **ppuVar4 = uVar9;
    }
    else {
      piVar2 = *param_4;
      *param_4 = piVar2 + 1;
      puVar3 = (undefined4 *)*piVar2;
      *puVar3 = local_38;
      puVar3[1] = uVar8;
    }
  }
  return param_5;
}




int FUN_00024e20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  if ((uVar3 & 3) == 0) {
    puVar2 = (undefined4 *)FUN_00023a9c();
    *puVar2 = 1;
    return -1;
  }
  if ((int)(uVar3 << 0x1a) < 0) {
    iVar1 = *(int *)(param_1 + 0x28);
  }
  else {
    iVar1 = (*(int *)(param_1 + 4) + *(int *)(param_1 + 0x18)) - *(int *)(param_1 + 0x10);
  }
  if (*(char *)(param_1 + 0x48) == '\0') {
    if (((int)(uVar3 << 0xc) < 0) && (0 < iVar1)) {
      return iVar1 + -1;
    }
  }
  else {
    iVar1 = iVar1 - (uint)*(byte *)(param_1 + 0x49);
  }
  return iVar1;
}




void FUN_00024e62(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = '\n';
  for (; (FUN_00012bbc(cVar1), param_1 != (char *)0x0 && (cVar1 = *param_1, cVar1 != '\0'));
      param_1 = param_1 + 1) {
  }
  for (; (param_2 != (char *)0x0 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    FUN_00012bbc();
  }
  FUN_00012bbc(10);
  return;
}




longlong FUN_00024e94(uint param_1,int param_2,uint param_3)

{
  if ((int)(param_3 - 0x20) < 0) {
    return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                    param_1 << (param_3 & 0xff));
  }
  return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
}




ulonglong FUN_00024eba(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  
  param_1 = param_1 ^ param_4;
  uVar2 = param_1 & 0x80000000;
  uVar17 = unaff_r5 >> 0x10;
  uVar8 = unaff_r4 >> 0x10;
  uVar22 = unaff_r5 & ~(uVar17 << 0x10);
  uVar16 = unaff_r4 & ~(uVar8 << 0x10);
  uVar10 = (uint)*(byte *)((unaff_r4 >> 0x18) + 0x250f4);
  uVar3 = (uint)((param_2 & 1) != 0) << 0x1f | param_3 >> 1;
  iVar11 = ((0x800000 - (uVar8 * uVar10 + uVar10)) * uVar10 >> 0x13) + 2;
  uVar18 = 0x20000000 - ((unaff_r4 >> 0xd) * iVar11 + iVar11);
  uVar10 = uVar18 >> 0x10;
  uVar10 = uVar10 * iVar11 + ((uVar18 & ~(uVar10 << 0x10)) * iVar11 >> 0x10) >> 6;
  if ((param_3 & 1) == 0) {
    uVar2 = 0;
  }
  if ((param_3 & 1) != 0) {
    uVar2 = 0x80000000;
  }
  uVar19 = uVar10 * (param_2 >> 0x10) >> 0x10;
  uVar4 = uVar3 - uVar19 * uVar17;
  uVar18 = uVar19 * uVar22;
  bVar23 = uVar18 * 0x10000 <= uVar2;
  uVar2 = uVar2 + uVar18 * -0x10000;
  uVar18 = uVar18 >> 0x10;
  bVar28 = uVar4 - uVar18 < (uint)bVar23;
  bVar24 = uVar18 < uVar4 || bVar28;
  uVar5 = (uVar4 - uVar18) - (uint)!bVar23;
  uVar12 = uVar19 * uVar16;
  if (uVar18 < uVar4 || bVar28) {
    bVar24 = uVar12 * 0x10000 <= uVar5;
  }
  uVar5 = uVar5 + uVar12 * -0x10000;
  uVar18 = ((((param_2 >> 1) - uVar8 * uVar19) - (uint)(uVar3 < uVar19 * uVar17)) - (uVar12 >> 0x10)
           ) - (uint)!bVar24;
  uVar20 = uVar10 * (uVar18 >> 2) >> 0x10;
  uVar3 = uVar20 * uVar17;
  bVar23 = uVar3 * 0x80000 <= uVar2;
  uVar2 = uVar2 + uVar3 * -0x80000;
  uVar3 = uVar3 >> 0xd;
  bVar28 = uVar5 - uVar3 < (uint)bVar23;
  bVar24 = uVar3 < uVar5 || bVar28;
  uVar4 = (uVar5 - uVar3) - (uint)!bVar23;
  uVar12 = uVar8 * uVar20;
  if (uVar3 < uVar5 || bVar28) {
    bVar24 = uVar12 * 0x80000 <= uVar4;
  }
  uVar4 = uVar4 + uVar12 * -0x80000;
  uVar5 = uVar20 * uVar22;
  bVar25 = uVar5 * 8 <= uVar2;
  uVar3 = uVar5 >> 0x1d;
  bVar28 = uVar4 - uVar3 < (uint)bVar25;
  bVar23 = uVar3 < uVar4 || bVar28;
  uVar6 = (uVar4 - uVar3) - (uint)!bVar25;
  uVar13 = uVar20 * uVar16;
  if (uVar3 < uVar4 || bVar28) {
    bVar23 = uVar13 * 8 <= uVar6;
  }
  uVar6 = uVar6 + uVar13 * -8;
  uVar3 = ((((uVar18 - (uVar12 >> 0xd)) - (uint)!bVar24) - (uVar13 >> 0x1d)) - (uint)!bVar23) *
          0x4000000 | uVar6 >> 6;
  uVar13 = uVar10 * (uVar3 >> 0xf);
  uVar18 = uVar6 * 0x4000000 | uVar2 + uVar5 * -8 >> 6;
  uVar5 = uVar5 * -0x20000000;
  uVar21 = uVar13 >> 0x10;
  uVar4 = uVar18 - uVar21 * uVar17;
  uVar2 = uVar21 * uVar22;
  bVar23 = uVar2 * 0x10000 <= uVar5;
  uVar5 = uVar5 + uVar2 * -0x10000;
  uVar2 = uVar2 >> 0x10;
  bVar28 = uVar4 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar4 || bVar28;
  uVar12 = (uVar4 - uVar2) - (uint)!bVar23;
  uVar6 = uVar21 * uVar16;
  if (uVar2 < uVar4 || bVar28) {
    bVar24 = uVar6 * 0x10000 <= uVar12;
  }
  uVar12 = uVar12 + uVar6 * -0x10000;
  uVar3 = (((uVar3 - uVar8 * uVar21) - (uint)(uVar18 < uVar21 * uVar17)) - (uVar6 >> 0x10)) -
          (uint)!bVar24;
  uVar6 = uVar10 * (uVar3 >> 2) >> 0x10;
  uVar2 = uVar6 * uVar17;
  bVar23 = uVar2 * 0x80000 <= uVar5;
  uVar5 = uVar5 + uVar2 * -0x80000;
  uVar2 = uVar2 >> 0xd;
  bVar28 = uVar12 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar12 || bVar28;
  uVar18 = (uVar12 - uVar2) - (uint)!bVar23;
  uVar4 = uVar8 * uVar6;
  if (uVar2 < uVar12 || bVar28) {
    bVar24 = uVar4 * 0x80000 <= uVar18;
  }
  uVar18 = uVar18 + uVar4 * -0x80000;
  uVar12 = uVar6 * uVar22;
  bVar25 = uVar12 * 8 <= uVar5;
  uVar2 = uVar12 >> 0x1d;
  bVar28 = uVar18 - uVar2 < (uint)bVar25;
  bVar23 = uVar2 < uVar18 || bVar28;
  uVar7 = (uVar18 - uVar2) - (uint)!bVar25;
  uVar14 = uVar6 * uVar16;
  if (uVar2 < uVar18 || bVar28) {
    bVar23 = uVar14 * 8 <= uVar7;
  }
  uVar7 = uVar7 + uVar14 * -8;
  uVar9 = uVar21 * 0x400000 + uVar6 * 0x200;
  uVar3 = ((((uVar3 - (uVar4 >> 0xd)) - (uint)!bVar24) - (uVar14 >> 0x1d)) - (uint)!bVar23) *
          0x4000000 | uVar7 >> 6;
  uVar18 = uVar7 * 0x4000000 | uVar5 + uVar12 * -8 >> 6;
  uVar10 = uVar10 * (uVar3 >> 0xf);
  uVar12 = uVar12 * -0x20000000;
  uVar7 = uVar10 >> 0x10;
  uVar4 = uVar18 - uVar7 * uVar17;
  uVar14 = uVar7 * uVar22;
  bVar23 = uVar14 * 0x10000 <= uVar12;
  uVar2 = uVar14 >> 0x10;
  bVar28 = uVar4 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar4 || bVar28;
  uVar5 = (uVar4 - uVar2) - (uint)!bVar23;
  uVar15 = uVar7 * uVar16;
  if (uVar2 < uVar4 || bVar28) {
    bVar24 = uVar15 * 0x10000 <= uVar5;
  }
  uVar5 = uVar5 + uVar15 * -0x10000;
  uVar10 = uVar10 >> 0x14;
  uVar4 = uVar9 + uVar10;
  uVar18 = ((((uVar3 - uVar8 * uVar7) - (uint)(uVar18 < uVar7 * uVar17)) - (uVar15 >> 0x10)) -
           (uint)!bVar24) * 0x4000 | uVar5 >> 0x12;
  uVar2 = uVar5 * 0x4000 | uVar12 + uVar14 * -0x10000 >> 0x12;
  uVar7 = uVar7 << 0x1c;
  uVar16 = uVar16 | uVar8 << 0x10;
  uVar22 = uVar22 | uVar17 << 0x10;
  bVar28 = uVar18 - uVar16 < (uint)(uVar22 <= uVar2);
  uVar3 = uVar18;
  if (uVar16 < uVar18 || bVar28) {
    uVar3 = (uVar18 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  bVar24 = CARRY4(uVar14 * -0x40000000,uVar14 * -0x40000000);
  bVar25 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar24);
  uVar2 = uVar2 * 2 + (uint)bVar24;
  bVar24 = CARRY4(uVar3,uVar3);
  bVar23 = CARRY4(uVar3 * 2,(uint)bVar25);
  uVar3 = uVar3 * 2 + (uint)bVar25;
  bVar25 = (bVar24 || bVar23) < (uVar16 < uVar3 || uVar3 - uVar16 < (uint)(uVar22 <= uVar2));
  if ((bVar24 || bVar23) || bVar25) {
    uVar3 = (uVar3 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  bVar26 = CARRY4(uVar14 * -0x80000000,uVar14 * -0x80000000);
  bVar27 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar26);
  uVar2 = uVar2 * 2 + (uint)bVar26;
  bVar26 = CARRY4(uVar3,uVar3);
  bVar1 = CARRY4(uVar3 * 2,(uint)bVar27);
  uVar3 = uVar3 * 2 + (uint)bVar27;
  bVar27 = (bVar26 || bVar1) < (uVar16 < uVar3 || uVar3 - uVar16 < (uint)(uVar22 <= uVar2));
  if ((bVar26 || bVar1) || bVar27) {
    uVar3 = (uVar3 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  if ((uVar3 | uVar2) != 0) {
    uVar7 = uVar7 | 1;
  }
  uVar2 = (((uint)(uVar16 < uVar18 || bVar28) * 2 + (uint)((bVar24 || bVar23) || bVar25)) * 2 +
          (uint)((bVar26 || bVar1) || bVar27)) * 0x10000000;
  bVar28 = CARRY4(uVar7,uVar2);
  uVar7 = uVar7 + uVar2;
  uVar2 = uVar4 + bVar28;
  iVar11 = uVar19 * 0x10000 + uVar20 * 8 + (uVar13 >> 0x1a) +
           (uint)CARRY4(uVar21 * 0x400000,uVar6 * 0x200) + (uint)CARRY4(uVar9,uVar10) +
           (uint)CARRY4(uVar4,(uint)bVar28);
  if (-1 < iVar11) {
    return CONCAT44(iVar11 * 2 +
                    (uint)(CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)CARRY4(uVar7,uVar7))),
                    param_1) & 0xffffffff80000000;
  }
  return CONCAT44(iVar11,param_1) & 0xffffffff80000000;
}




undefined8 FUN_000251f4(undefined4 param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_r11;
  undefined8 uVar5;
  
  uVar4 = param_3 >> 0xb | param_2 << 0x15;
  uVar5 = FUN_00025278(param_1,param_2 >> 0xb);
  uVar2 = (uint)uVar5 & 0x7fffffff;
  if (0x7ff < uVar2 + 2) {
    if (unaff_r11 < 1) {
      uVar3 = 0xffffffff;
      uVar1 = DAT_00025270;
    }
    else {
      uVar3 = 0;
      uVar1 = DAT_00025274;
    }
    return CONCAT44(uVar3,uVar1);
  }
  return CONCAT44(uVar4,(int)((ulonglong)uVar5 >> 0x20) + uVar2 * 0x100000);
}




undefined8 FUN_00025278(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint unaff_r6;
  int unaff_r11;
  bool bVar3;
  
  if ((int)param_4 < 0) {
    bVar3 = (int)(param_4 + 0x40) < 0;
    unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
    if (param_4 == 0xffffffc0 || bVar3 != SCARRY4(param_4,0x40)) {
      unaff_r6 = (unaff_r6 | param_3 | (unaff_r6 | param_3) << 0x10) >> 0x10 | param_2;
      if (bVar3 != SCARRY4(param_4,0x40)) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
      }
      param_4 = 0;
      param_3 = 0;
      param_2 = 0;
    }
    else {
      uVar2 = param_4;
      if (param_4 == 0xffffffe0 || (int)(param_4 + 0x20) < 0 != SCARRY4(param_4,0x20)) {
        unaff_r6 = unaff_r6 | param_3;
        uVar2 = param_4 + 0x20;
        param_3 = param_2;
        param_2 = 0;
      }
      param_4 = -uVar2;
      if (param_4 != 0) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10 | param_3 << (uVar2 + 0x20 & 0xff);
        uVar1 = param_4 & 0xff;
        uVar2 = param_2 << (uVar2 + 0x20 & 0xff);
        param_2 = param_2 >> (param_4 & 0xff);
        param_4 = 0;
        param_3 = param_3 >> uVar1 | uVar2;
      }
    }
  }
  if (((unaff_r6 & 0x7fffffff) != 0) || ((unaff_r6 & 0x80000000) != 0)) {
    bVar3 = unaff_r11 != -1 && 0xfffffffe < param_3;
    if (unaff_r11 != -1 && 0xfffffffe < param_3) {
      bVar3 = 0xfffffffe < param_2;
      param_2 = param_2 + 1;
    }
    if (bVar3 != false) {
      param_2 = 0x80000000;
    }
    param_4 = param_4 + bVar3;
  }
  return CONCAT44(param_2,param_4 | param_1 & 0x80000000);
}




void FUN_00025354(int *param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = (param_1[1] & ~(*param_1 << 1)) < 0;
  if (bVar1) {
    bVar1 = (param_2[1] & ~(*param_2 << 1)) < 0;
  }
  if (bVar1) {
    FUN_00024eba(*param_1,param_1[1],param_1[2]);
    FUN_00025278();
  }
  return;
}




void FUN_0002537e(int *param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = (param_1[1] & ~(*param_1 << 1)) < 0;
  if (bVar1) {
    bVar1 = (param_2[1] & ~(*param_2 << 1)) < 0;
  }
  if (bVar1) {
    FUN_00024eba(*param_1,param_1[1],param_1[2]);
    FUN_000251f4();
  }
  return;
}




void FUN_000253a8(uint *param_1,uint *param_2)

{
  bool bVar1;
  
  bVar1 = (*param_1 & 0x40000000) == 0;
  if (bVar1) {
    bVar1 = (*param_2 & 0x40000000) == 0;
  }
  if (bVar1) {
    FUN_000253fc(*param_1,param_1[1],param_1[2]);
    FUN_00025278();
  }
  return;
}




void FUN_000253d2(uint *param_1,uint *param_2)

{
  bool bVar1;
  
  bVar1 = (*param_1 & 0x40000000) == 0;
  if (bVar1) {
    bVar1 = (*param_2 & 0x40000000) == 0;
  }
  if (bVar1) {
    FUN_000253fc(*param_1,param_1[1],param_1[2]);
    FUN_000251f4();
  }
  return;
}




ulonglong FUN_000253fc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  bool bVar19;
  
  param_1 = param_1 ^ param_4;
  if (param_3 == 0) {
    if (unaff_r5 == 0) {
      uVar5 = unaff_r4 >> 0x10;
      uVar6 = param_2 >> 0x10;
      uVar14 = unaff_r4 & ~(uVar5 << 0x10);
      param_2 = param_2 & ~(uVar6 << 0x10);
      uVar7 = uVar14 * uVar6;
      uVar14 = param_2 * uVar14;
      param_2 = uVar5 * param_2;
      uVar3 = uVar7 * 0x10000;
      uVar1 = uVar14 + uVar3;
      uVar2 = param_2 * 0x10000;
      uVar4 = uVar1 + uVar2;
      iVar8 = uVar5 * uVar6 + (uVar7 >> 0x10) + (uint)CARRY4(uVar14,uVar3) +
              (param_2 >> 0x10) + (uint)CARRY4(uVar1,uVar2);
      if (-1 < iVar8) {
        return CONCAT44(iVar8 * 2 + (uint)CARRY4(uVar4,uVar4),param_1) & 0xffffffff80000000;
      }
      return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
    }
    uVar4 = param_2 >> 0x10;
    uVar12 = unaff_r4 >> 0x10;
    param_2 = param_2 & ~(uVar4 << 0x10);
    uVar15 = unaff_r4 & ~(uVar12 << 0x10);
    uVar5 = uVar15 * param_2;
    uVar15 = uVar4 * uVar15;
    uVar3 = param_2 * uVar12 * 0x10000;
    uVar6 = uVar5 + uVar3;
    uVar13 = unaff_r5 >> 0x10;
    uVar2 = uVar15 * 0x10000;
    uVar7 = uVar6 + uVar2;
    uVar16 = unaff_r5 & ~(uVar13 << 0x10);
    uVar9 = uVar16 * param_2;
    uVar16 = uVar4 * uVar16;
    uVar14 = param_2 * uVar13 * 0x10000;
    uVar10 = uVar9 + uVar14;
    uVar1 = uVar16 * 0x10000;
    uVar11 = uVar10 + uVar1;
    uVar14 = uVar4 * uVar13 + (param_2 * uVar13 >> 0x10) + (uint)CARRY4(uVar9,uVar14) +
             (uVar16 >> 0x10) + (uint)CARRY4(uVar10,uVar1);
    uVar1 = uVar14 + uVar7;
    iVar8 = uVar4 * uVar12 + (param_2 * uVar12 >> 0x10) + (uint)CARRY4(uVar5,uVar3) +
            (uVar15 >> 0x10) + (uint)CARRY4(uVar6,uVar2) + (uint)CARRY4(uVar14,uVar7);
    if (-1 < iVar8) {
      return CONCAT44(iVar8 * 2 +
                      (uint)(CARRY4(uVar1,uVar1) || CARRY4(uVar1 * 2,(uint)CARRY4(uVar11,uVar11))),
                      param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
  }
  if (unaff_r5 == 0) {
    uVar7 = unaff_r4 >> 0x10;
    uVar13 = param_2 >> 0x10;
    uVar9 = unaff_r4 & ~(uVar7 << 0x10);
    param_2 = param_2 & ~(uVar13 << 0x10);
    uVar4 = param_2 * uVar9;
    param_2 = uVar7 * param_2;
    uVar3 = uVar9 * uVar13 * 0x10000;
    uVar5 = uVar4 + uVar3;
    uVar15 = param_3 >> 0x10;
    uVar2 = param_2 * 0x10000;
    uVar6 = uVar5 + uVar2;
    param_3 = param_3 & ~(uVar15 << 0x10);
    uVar10 = param_3 * uVar9;
    param_3 = uVar7 * param_3;
    uVar14 = uVar9 * uVar15 * 0x10000;
    uVar11 = uVar10 + uVar14;
    uVar1 = param_3 * 0x10000;
    uVar12 = uVar11 + uVar1;
    uVar1 = uVar7 * uVar15 + (uVar9 * uVar15 >> 0x10) + (uint)CARRY4(uVar10,uVar14) +
            (param_3 >> 0x10) + (uint)CARRY4(uVar11,uVar1);
    uVar14 = uVar1 + uVar6;
    iVar8 = uVar7 * uVar13 + (uVar9 * uVar13 >> 0x10) + (uint)CARRY4(uVar4,uVar3) +
            (param_2 >> 0x10) + (uint)CARRY4(uVar5,uVar2) + (uint)CARRY4(uVar1,uVar6);
    if (-1 < iVar8) {
      return CONCAT44(iVar8 * 2 +
                      (uint)(CARRY4(uVar14,uVar14) || CARRY4(uVar14 * 2,(uint)CARRY4(uVar12,uVar12))
                            ),param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
  }
  uVar1 = param_2 >> 0x10;
  uVar4 = unaff_r4 >> 0x10;
  uVar11 = param_2 & ~(uVar1 << 0x10);
  uVar9 = unaff_r4 & ~(uVar4 << 0x10);
  uVar5 = uVar11 * uVar4;
  uVar11 = uVar9 * uVar11;
  uVar9 = uVar1 * uVar9;
  uVar3 = uVar5 * 0x10000;
  uVar12 = uVar11 + uVar3;
  uVar15 = param_3 >> 0x10;
  uVar2 = uVar9 * 0x10000;
  uVar13 = uVar12 + uVar2;
  uVar6 = unaff_r5 >> 0x10;
  uVar16 = param_3 & ~(uVar15 << 0x10);
  uVar10 = unaff_r5 & ~(uVar6 << 0x10);
  uVar7 = uVar16 * uVar6;
  uVar16 = uVar10 * uVar16;
  uVar10 = uVar15 * uVar10;
  uVar14 = uVar7 * 0x10000;
  uVar17 = uVar16 + uVar14;
  uVar7 = uVar15 * uVar6 + (uVar7 >> 0x10) + (uint)CARRY4(uVar16,uVar14);
  iVar8 = 0;
  uVar14 = uVar10 * 0x10000;
  uVar15 = uVar17 + uVar14;
  uVar6 = uVar7 + (uVar10 >> 0x10) + (uint)CARRY4(uVar17,uVar14);
  uVar14 = uVar13 + uVar6;
  uVar2 = uVar1 * uVar4 + (uVar5 >> 0x10) + (uint)CARRY4(uVar11,uVar3) +
          (uVar9 >> 0x10) + (uint)CARRY4(uVar12,uVar2) + (uint)CARRY4(uVar13,uVar6);
  uVar1 = uVar14 + uVar2 + CARRY4(uVar14,uVar15);
  bVar19 = param_3 <= param_2;
  param_2 = param_2 - param_3;
  bVar18 = param_2 == 0;
  uVar3 = 0;
  if (!bVar19) {
    uVar3 = 0xffffffff;
    iVar8 = unaff_r4 - unaff_r5;
  }
  if (!bVar18) {
    bVar19 = unaff_r4 <= unaff_r5;
    uVar7 = unaff_r5 - unaff_r4;
    bVar18 = uVar7 == 0;
  }
  if (bVar18) {
    uVar3 = 0;
  }
  if (!bVar19) {
    uVar3 = ~uVar3;
    iVar8 = iVar8 - param_2;
  }
  uVar6 = param_2 >> 0x10;
  param_2 = param_2 & ~(uVar6 << 0x10);
  uVar11 = uVar7 >> 0x10;
  uVar7 = uVar7 & ~(uVar11 << 0x10);
  uVar12 = param_2 * uVar11;
  param_2 = uVar7 * param_2;
  uVar7 = uVar6 * uVar7;
  uVar4 = uVar12 * 0x10000;
  uVar9 = param_2 + uVar4;
  uVar5 = uVar7 * 0x10000;
  uVar10 = uVar9 + uVar5;
  uVar4 = uVar6 * uVar11 + iVar8 + (uVar12 >> 0x10) + (uint)CARRY4(param_2,uVar4) +
          (uVar7 >> 0x10) + (uint)CARRY4(uVar9,uVar5);
  bVar18 = CARRY4(uVar14 + uVar15,uVar10);
  uVar5 = uVar1 + uVar4 + bVar18;
  iVar8 = uVar3 + uVar2 + (CARRY4(uVar14,uVar2) ||
                          CARRY4(uVar14 + uVar2,(uint)CARRY4(uVar14,uVar15))) +
          (uint)(CARRY4(uVar1,uVar4) || CARRY4(uVar1 + uVar4,(uint)bVar18));
  uVar3 = uVar14 + uVar15 + uVar10 | (uVar15 | uVar15 * 4) >> 2;
  if (-1 < iVar8) {
    return CONCAT44(iVar8 * 2 +
                    (uint)(CARRY4(uVar5,uVar5) || CARRY4(uVar5 * 2,(uint)CARRY4(uVar3,uVar3))),
                    param_1) & 0xffffffff80000000;
  }
  return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
}




/* WARNING: Removing unreachable block (ram,0x000256dc) */
/* WARNING: Removing unreachable block (ram,0x000256e0) */
/* WARNING: Removing unreachable block (ram,0x000256e4) */
/* WARNING: Removing unreachable block (ram,0x000256e8) */
/* WARNING: Removing unreachable block (ram,0x000256ec) */

undefined4 FUN_00025640(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  uint local_20;
  
  FUN_00025978(param_1,param_2,&local_20);
  local_20 = local_20 + 0x7e;
  cVar3 = local_20 == 0;
  uVar6 = (undefined4)DAT_00025728;
  uVar2 = (undefined4)((ulonglong)DAT_00025728 >> 0x20);
  if (((int)local_20 < 1) && (FUN_00025ee8(param_1,param_2,uVar6,uVar2), cVar3 == '\0')) {
    fVar1 = (float)FUN_00025a5c(param_1,param_2);
    uVar2 = 0;
    if (fVar1 == 0.0) {
      uVar2 = FUN_00023aae(2,0);
    }
  }
  else {
    bVar5 = 0xfe < local_20;
    if ((int)local_20 < 0xff) {
      uVar2 = FUN_00025a5c(param_1,param_2);
      return uVar2;
    }
    bVar4 = true;
    FUN_000262e4(param_1,param_2,uVar6,uVar2);
    FUN_00023aae(2);
    uVar2 = 0;
    if (bVar5 && !bVar4) {
      return uVar2;
    }
  }
  return uVar2;
}




undefined8 FUN_00025738(undefined4 param_1)

{
  undefined4 uVar1;
  undefined8 local_18;
  
  uVar1 = FUN_00023aa4();
  local_18 = DAT_00025768;
  FUN_00023c34(&local_18,param_1,0);
  FUN_00023aae(uVar1);
  return local_18;
}




float FUN_00025770(uint param_1,uint param_2)

{
  float fVar1;
  bool bVar2;
  
  if ((-1 < (int)(0x7f800000 - (param_1 & 0x7fffffff))) &&
     (-1 < (int)(0x7f800000 - (param_2 & 0x7fffffff)))) {
    bVar2 = (param_1 & 0x7fffffff) == 0x7f800000;
    if (!bVar2) {
      bVar2 = (param_2 & 0x7fffffff) == 0;
    }
    if (bVar2) {
      FUN_00023aae(1);
      return DAT_0002593c / DAT_0002593c;
    }
  }
  fVar1 = (float)FUN_00026610(param_1,param_2);
  if ((~((uint)fVar1 >> 0x17) & 0xff) == 0) {
    return fVar1;
  }
  if ((param_1 & 0x80000000) != ((uint)fVar1 & 0x80000000)) {
    return fVar1 - (float)((uint)fVar1 & 0x80000000 | param_2 & 0x7fffffff);
  }
  return fVar1;
}




undefined8 FUN_00025820(void)

{
  ulonglong uVar1;
  uint uVar2;
  char cVar3;
  undefined8 in_d0;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 local_28;
  
  cVar3 = (~(uint)((ulonglong)in_d0 >> 0x34) & 0x7ff) == 0;
  if (!(bool)cVar3) {
    uVar1 = (ulonglong)DAT_000258e8 >> 0x20;
    uVar5 = (undefined4)DAT_000258e8;
    FUN_00025ee8();
    if (cVar3 == '\0') {
      in_d0 = FUN_00026778();
      uVar2 = (uint)((ulonglong)in_d0 >> 0x20);
      cVar3 = (~(uVar2 >> 0x14) & 0x7ff) == 0;
      if ((bool)cVar3) {
        FUN_00023aae(2);
        uVar4 = FUN_000258f0();
        local_28._0_4_ = (undefined4)uVar4;
        local_28 = CONCAT44(uVar2 & 0x80000000 | (uint)((ulonglong)uVar4 >> 0x20) & 0x7fffffff,
                            (undefined4)local_28);
        return local_28;
      }
      FUN_00025ee8((int)in_d0,uVar2,uVar5,(int)uVar1,in_d0);
      if (cVar3 != '\0') {
        FUN_00023aae(2);
        uVar4 = FUN_00025910();
        local_28._0_4_ = (undefined4)uVar4;
        local_28 = CONCAT44(uVar2 & 0x80000000 | (uint)((ulonglong)uVar4 >> 0x20) & 0x7fffffff,
                            (undefined4)local_28);
        return local_28;
      }
    }
  }
  return in_d0;
}




undefined8 FUN_000258f0(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = (undefined4)((ulonglong)DAT_00025908 >> 0x20);
  uVar2 = FUN_000260e8((int)DAT_00025908,uVar1,(int)DAT_00025908,uVar1);
  return uVar2;
}




undefined8 FUN_00025910(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = (undefined4)((ulonglong)DAT_00025928 >> 0x20);
  uVar2 = FUN_000260e8((int)DAT_00025928,uVar1,(int)DAT_00025928,uVar1);
  return uVar2;
}




void FUN_00025940(undefined4 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00025640((int)*param_2);
  *param_1 = uVar1;
  return;
}




void FUN_00025952(undefined8 *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00025820((int)*param_1,param_2);
  *param_1 = uVar1;
  return;
}




undefined4 FUN_00025966(int param_1)

{
  if (param_1 - 0x30U < 10) {
    return 1;
  }
  return 0;
}




ulonglong FUN_00025978(uint param_1,uint param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = CONCAT44(param_2,param_1);
  *param_3 = 0;
  uVar1 = param_2 & 0x7fffffff;
  if (((int)uVar1 < DAT_000259f0) && ((param_1 | uVar1) != 0)) {
    if (uVar1 < 0x100000) {
      uVar3 = FUN_000260e8(param_1,param_2,(int)DAT_000259f8,(int)((ulonglong)DAT_000259f8 >> 0x20))
      ;
      iVar2 = -0x36;
      uVar1 = (uint)(uVar3 >> 0x20) & 0x7fffffff;
      *param_3 = -0x36;
    }
    else {
      iVar2 = *param_3;
    }
    *param_3 = DAT_00025a00 + ((int)uVar1 >> 0x14) + iVar2;
    uVar3 = uVar3 & 0x800fffffffffffff | 0x3fe0000000000000;
  }
  else {
    uVar3 = CONCAT44(param_2,param_1);
  }
  return uVar3;
}




uint FUN_00025a5c(uint param_1,uint param_2)

{
  uint extraout_r1;
  uint uVar1;
  bool bVar2;
  
  uVar1 = (param_2 & 0x7fffffff) + 0xc8000000;
  bVar2 = uVar1 == 0x100000;
  if (0xfffff < uVar1) {
    bVar2 = uVar1 == 0xff00000;
  }
  if ((0xfffff < uVar1 && uVar1 < 0xff00001) && !bVar2) {
    bVar2 = (param_1 & 0x10000000) != 0;
    uVar1 = (param_2 & 0x80000000 | uVar1 * 8) + (param_1 >> 0x1d) + (uint)bVar2;
    if ((param_1 & 0xfffffff) != 0) {
      return uVar1;
    }
    if (bVar2) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    return uVar1;
  }
  if ((int)uVar1 < 0x100000) {
    param_1 = param_2 & 0x80000000;
  }
  if ((int)((param_2 & 0x7fffffff) + 0xc7f00000) < 0 != SBORROW4(uVar1,0x100000)) {
    return param_1;
  }
  if (0xffdfffff < param_2 << 1) {
    FUN_0002623c(param_1);
    param_2 = extraout_r1;
  }
  return (param_2 >> 0x17 | 0xff) << 0x17;
}




longlong FUN_00025c38(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  
  bVar13 = (DAT_00025ee0 & ~(param_2 >> 4)) == 0;
  if (!bVar13) {
    bVar13 = (DAT_00025ee0 & ~(param_4 >> 4)) == 0;
  }
  if (bVar13) {
    FUN_0002623c();
  }
  else {
    uVar7 = param_2 ^ param_4;
    uVar4 = DAT_00025ee0 & param_2 >> 4;
    bVar13 = uVar4 == 0;
    uVar6 = uVar7 >> 0x1f;
    if (!bVar13) {
      uVar7 = DAT_00025ee0 & param_4 >> 4;
      bVar13 = uVar7 == 0;
    }
    if (bVar13) {
      if ((param_2 & DAT_00025ee0 << 4) == 0) {
        if ((param_4 & DAT_00025ee0 << 4) == 0) {
          return (ulonglong)DAT_00025ee4 << 0x20;
        }
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
      param_4 = param_2 ^ param_4;
    }
    else {
      iVar5 = (uVar4 | uVar6) - uVar7;
      uVar7 = param_4 << 0xb | 0x80000000;
      uVar4 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
      uVar3 = uVar7 | param_3 >> 0x15;
      uVar6 = iVar5 + 0x3fe0000;
      if (uVar4 == uVar3 && param_1 * 0x800 == param_3 * 0x800) {
        uVar3 = 0x100000;
        uVar4 = 0;
      }
      else {
        uVar9 = (uint)*(byte *)((uVar7 >> 0x18) + 0x25de0);
        uVar9 = uVar9 * (0x1000000 - uVar9 * (uVar7 >> 0x10)) >> 0xf;
        iVar10 = (int)((ulonglong)uVar9 * (ulonglong)uVar3);
        iVar8 = -(int)((ulonglong)uVar9 * (ulonglong)uVar3 >> 0x20);
        iVar11 = iVar8 + 0x10000;
        if (iVar10 != 0) {
          iVar11 = iVar8 + 0xffff;
        }
        uVar9 = uVar9 * iVar11 + (int)((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        lVar1 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(param_3 * 0x800) >> 0x20);
        iVar10 = (int)lVar1;
        iVar8 = -(int)((ulonglong)lVar1 >> 0x20);
        uVar3 = iVar8 + 0x80000000;
        if (iVar10 != 0) {
          uVar3 = iVar8 + 0x7fffffff;
        }
        uVar2 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        uVar9 = (uint)(uVar2 >> 0x20);
        uVar3 = (uint)((ulonglong)uVar4 * (uVar2 & 0xffffffff) >> 0x20);
        uVar12 = (uint)((ulonglong)(param_1 * 0x800) * (ulonglong)uVar9 >> 0x20);
        uVar2 = (ulonglong)uVar4 * (ulonglong)uVar9 +
                (ulonglong)CONCAT14(CARRY4(uVar3,uVar12),uVar3 + uVar12);
        iVar8 = (int)(uVar2 >> 0x20);
        if (SCARRY4(iVar8,0x70000000) == false) {
          uVar6 = iVar5 + 0x3fd0000;
          uVar2 = CONCAT44(iVar8 * 2 + (uint)((uVar2 & 0x80000000) != 0),(int)uVar2 << 1);
        }
        uVar3 = (uint)(uVar2 + 0x80 >> 0x20);
        uVar4 = (uint)(uVar2 + 0x80) >> 8 | uVar3 * 0x1000000;
        uVar3 = uVar3 >> 8;
        if ((int)uVar2 * 0x1000000 + 0x91000000U < 0x10000001) {
          uVar9 = param_3 & 0x1fffff | (param_3 >> 0x15) << 0x15;
          iVar5 = uVar3 * uVar9 +
                  uVar4 * (uVar7 >> 0xb) + (int)((ulonglong)uVar4 * (ulonglong)uVar9 >> 0x20);
          if (-1 < iVar8 + 0x70000000) {
            iVar5 = iVar5 + (param_1 & 0x1fffff) * -0x100000;
          }
          if ((int)(iVar5 + (param_1 & 0x1fffff) * -0x100000 +
                   (uVar7 >> 0xc) +
                   (uint)CARRY4((uint)((ulonglong)uVar4 * (ulonglong)uVar9),
                                uVar9 >> 1 | (uVar7 >> 0xb) << 0x1f)) < 0) {
            bVar13 = 0xfffffffe < uVar4;
            uVar4 = uVar4 + 1;
            uVar3 = uVar3 + bVar13;
          }
        }
      }
      iVar5 = uVar3 + uVar6 * -0x80000000 + (uVar6 & 0xfffffffe) * 0x10;
      if ((uVar6 & 0xfffffffe) < 0x7f00001) {
        return CONCAT44(iVar5,uVar4);
      }
      bVar13 = (int)uVar6 < 0;
      if (!bVar13) {
        bVar13 = (int)(iVar5 + 0x100000U ^ uVar6 << 0x1f) < 0;
      }
      if (!bVar13) {
        return CONCAT44(iVar5,uVar4);
      }
      if ((int)uVar6 < 0) {
        return (ulonglong)(iVar5 + 0x60000000U & 0x80000000) << 0x20;
      }
      param_4 = iVar5 + 0xa0000000;
    }
  }
  return (ulonglong)((uint)((int)param_4 < 0) << 0x1f | 0x7ff00000) << 0x20;
}




void FUN_00025ee8(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar2;
  bool bVar3;
  byte in_Q;
  
  uVar1 = param_2 | param_4;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x100000) < 0) {
      if (-1 < (int)(uVar1 - 0x100000)) {
        return;
      }
      if (param_4 != param_2) {
        return;
      }
      return;
    }
    bVar2 = 0xffdfffff < param_2 << 1;
    if (!bVar2) {
      bVar2 = 0xffdfffff < param_4 << 1;
    }
    if (!bVar2) {
      return;
    }
  }
  else {
    bVar3 = SCARRY4(uVar1,0x100000);
    bVar2 = (int)(uVar1 + 0x100000) < 0;
    if (!bVar2) {
      bVar3 = SBORROW4(uVar1,0x100000);
      bVar2 = (int)(uVar1 - 0x100000) < 0;
    }
    if (!bVar2) {
      if (param_2 != param_4) {
        return;
      }
      return;
    }
    if (bVar3 == false) {
      return;
    }
    bVar2 = (int)(param_2 + 0x100000) < 0;
    if (!bVar2) {
      bVar2 = (int)(param_4 + 0x100000) < 0;
    }
    if (!bVar2) {
      return;
    }
  }
  UNRECOVERED_JUMPTABLE = (code *)0x25f50;
  FUN_0002623c();
                    /* WARNING: Could not recover jumptable at 0x00025c36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((uint)(in_Q | 4) << 0x1b);
  return;
}




uint FUN_00025f60(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 *unaff_r4;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar5;
  bool bVar6;
  
  iVar2 = ((uint)(param_2 << 1) >> 0x15) - 0x400;
  bVar6 = SBORROW4(0x1e,iVar2);
  iVar1 = -iVar2;
  uVar3 = iVar1 + 0x1e;
  bVar5 = uVar3 == 0;
  uVar4 = uVar3;
  if (!bVar5 && iVar2 < 0x1f) {
    bVar6 = SBORROW4(0x21,uVar3);
    uVar4 = 0x21 - uVar3;
    bVar5 = uVar3 == 0x21;
  }
  if (!bVar5 && (int)uVar4 < 0 == bVar6) {
    return ((param_2 << 0xb | 0x80000000U | param_1 >> 0x15) >> (uVar3 & 0xff) ^ param_2 >> 0x1f) -
           (param_2 >> 0x1f);
  }
  if (0x10 < (int)uVar3) {
    param_1 = 0;
  }
  if (uVar3 != 0x10 && iVar1 + 0xe < 0 == SBORROW4(uVar3,0x10)) {
    return param_1;
  }
  if (iVar1 != -0x3ff) {
    return param_2 >> 0x20 ^ 0x7fffffff;
  }
  UNRECOVERED_JUMPTABLE = (code *)0x25fb4;
  FUN_0002623c(param_1);
  *unaff_r4 = (short)unaff_r4;
                    /* WARNING: Could not recover jumptable at 0x00025fba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(0);
  return uVar4;
}




uint FUN_00025fc0(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 *unaff_r4;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar5;
  
  iVar2 = (param_2 >> 0x14) - 0x400;
  bVar5 = SBORROW4(0x1e,iVar2);
  iVar1 = -iVar2;
  uVar3 = iVar1 + 0x1e;
  uVar4 = uVar3;
  if (iVar2 < 0x1f) {
    bVar5 = SBORROW4(0x20,uVar3);
    uVar4 = 0x20 - uVar3;
  }
  if ((int)uVar4 < 0 == bVar5) {
    return (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
  }
  if ((int)param_2 < 0) {
    return 0;
  }
  if (0x10 < (int)uVar3) {
    param_1 = 0;
  }
  if (uVar3 != 0x10 && iVar1 + 0xe < 0 == SBORROW4(uVar3,0x10)) {
    return param_1;
  }
  if (iVar1 != -0x3ff) {
    return 0xffffffff;
  }
  UNRECOVERED_JUMPTABLE = (code *)0x2600e;
  FUN_0002623c(param_1);
  *unaff_r4 = (short)unaff_r4;
                    /* WARNING: Could not recover jumptable at 0x00026016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(0);
  return uVar4;
}




undefined8 FUN_0002601a(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    return CONCAT44(uVar2 + (0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
  }
  return 0;
}




undefined8 FUN_00026048(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    return CONCAT44((0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
  }
  return 0;
}




void FUN_00026070(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar2;
  bool bVar3;
  byte in_Q;
  
  uVar1 = param_2 | param_4;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x100000) < 0) {
      if (-1 < (int)(uVar1 - 0x100000)) {
        return;
      }
      if (param_4 != param_2) {
        return;
      }
      return;
    }
    bVar2 = 0xffdfffff < param_2 << 1;
    if (!bVar2) {
      bVar2 = 0xffdfffff < param_4 << 1;
    }
    if (!bVar2) {
      return;
    }
  }
  else {
    bVar3 = SCARRY4(uVar1,0x100000);
    bVar2 = (int)(uVar1 + 0x100000) < 0;
    if (!bVar2) {
      bVar3 = SBORROW4(uVar1,0x100000);
      bVar2 = (int)(uVar1 - 0x100000) < 0;
    }
    if (!bVar2) {
      if (param_2 != param_4) {
        return;
      }
      return;
    }
    if (bVar3 == false) {
      return;
    }
    bVar2 = (int)(param_2 + 0x100000) < 0;
    if (!bVar2) {
      bVar2 = (int)(param_4 + 0x100000) < 0;
    }
    if (!bVar2) {
      return;
    }
  }
  UNRECOVERED_JUMPTABLE = (code *)0x260d8;
  FUN_0002623c();
                    /* WARNING: Could not recover jumptable at 0x00025c36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((uint)(in_Q | 4) << 0x1b);
  return;
}




longlong FUN_000260e8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  int extraout_r1;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  
  uVar13 = DAT_00026234 & param_2 >> 4;
  bVar16 = uVar13 == 0;
  if (!bVar16) {
    unaff_r5 = DAT_00026234 & param_4 >> 4;
    bVar16 = unaff_r5 == 0;
  }
  if (!bVar16) {
    bVar16 = uVar13 == DAT_00026234;
  }
  if (!bVar16) {
    bVar16 = unaff_r5 == DAT_00026234;
  }
  if (bVar16) {
    if (uVar13 != DAT_00026234 && (DAT_00026234 & param_4 >> 4) != DAT_00026234) {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    FUN_0002623c();
    param_4 = extraout_r1 << 2 ^ param_4;
  }
  else {
    uVar6 = param_2 & ~(DAT_00026234 << 5) | 0x100000;
    uVar8 = param_4 & ~(DAT_00026234 << 5) | 0x100000;
    iVar14 = (uVar13 | (param_2 ^ param_4) >> 0x1f) + unaff_r5;
    lVar1 = (ulonglong)uVar6 * (ulonglong)param_3;
    uVar11 = (uint)((ulonglong)lVar1 >> 0x20);
    lVar2 = (ulonglong)param_1 * (ulonglong)uVar8;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    iVar15 = iVar14 + -0x3fc0000;
    lVar4 = lVar1 + lVar2;
    uVar10 = (uint)((ulonglong)lVar4 >> 0x20);
    lVar3 = (ulonglong)uVar6 * (ulonglong)uVar8;
    uVar13 = (uint)lVar3;
    uVar12 = (uint)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
    lVar5 = lVar4 + CONCAT44(uVar13,uVar12);
    uVar8 = (uint)lVar5;
    uVar6 = (uint)((ulonglong)lVar5 >> 0x20);
    uVar13 = (int)((ulonglong)lVar3 >> 0x20) +
             (uint)(CARRY4(uVar9,uVar11) ||
                   CARRY4(uVar9 + uVar11,(uint)CARRY4((uint)lVar2,(uint)lVar1))) +
             (uint)(CARRY4(uVar10,uVar13) ||
                   CARRY4(uVar10 + uVar13,(uint)CARRY4((uint)lVar4,uVar12)));
    if ((int)((ulonglong)param_1 * (ulonglong)param_3) != 0) {
      uVar8 = uVar8 | 1;
    }
    if ((uVar13 & 0x200) == 0) {
      uVar10 = uVar8 << 0xc;
      uVar9 = uVar13 * 0x1000 | uVar6 >> 0x14;
      uVar13 = uVar6 << 0xc | uVar8 >> 0x14;
      iVar7 = -4;
    }
    else {
      uVar10 = uVar8 << 0xb;
      uVar9 = uVar13 * 0x800 | uVar6 >> 0x15;
      uVar13 = uVar6 << 0xb | uVar8 >> 0x15;
      iVar7 = -3;
    }
    uVar6 = iVar7 + (iVar15 >> 0x10);
    param_4 = uVar9 + uVar6 * 0x100000 ^ iVar14 * -0x80000000;
    if (uVar10 != 0) {
      bVar16 = (uVar10 & 0x80000000) != 0;
      if ((uVar10 & 0x7fffffff) != 0) {
        uVar10 = 0;
      }
      param_4 = param_4 + CARRY4(uVar13,(uint)bVar16);
      uVar13 = uVar13 + bVar16 & ~(uVar10 >> 0x1f);
    }
    if (uVar6 < 0x7fe) {
      return CONCAT44(param_4,uVar13);
    }
    if (0x3ffffff < iVar15) {
      param_4 = param_4 + 0xa0000000;
    }
    if (iVar14 + -0x7fc0000 < 0 != SBORROW4(iVar15,0x4000000)) {
      return (ulonglong)(param_4 + 0x60000000 & 0x80000000) << 0x20;
    }
  }
  return (ulonglong)((uint)((int)param_4 < 0) << 0x1f | 0x7ff00000) << 0x20;
}




int FUN_0002623c(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r5;
  uint uVar2;
  uint uVar3;
  int in_lr;
  uint *puVar4;
  bool bVar5;
  
  puVar4 = (uint *)(in_lr + 2U & 0xfffffffc);
  uVar2 = *puVar4;
  if ((((int)uVar2 < 0) || (unaff_r5 = param_4 * 2 + (uint)(param_3 != 0), unaff_r5 < 0xffe00001))
     && (uVar3 = param_2 * 2 + (uint)(param_1 != 0), uVar3 < 0xffe00001)) {
    if (uVar3 == 0xffe00000) {
      uVar3 = ((int)param_2 >> 0x1f) * -3 + 2;
      if (unaff_r5 == 0xffe00000) {
        uVar3 = uVar3 + ((uint)(0xffdfffff < unaff_r5) - ((int)param_4 >> 0x1f));
      }
    }
    else {
      uVar3 = param_4 >> 0x1f;
    }
  }
  else {
    uVar3 = 8;
  }
  uVar2 = uVar2 >> (uVar3 * 3 & 0xff) & 7;
  switch(uVar2) {
  case 4:
    param_1 = param_3;
    param_2 = param_4;
switchD_000262a8_caseD_5:
    bVar5 = CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)(param_1 != 0));
    uVar2 = param_2 * 2 + (uint)(param_1 != 0);
    if (uVar2 != 0) {
      bVar5 = uVar2 < 0x200001;
    }
    if (bVar5 && (uVar2 != 0 && uVar2 != 0x200000)) {
      param_1 = 0;
    }
    return param_1;
  case 5:
    goto switchD_000262a8_caseD_5;
  case 6:
  case 7:
    return 0;
  default:
                    /* WARNING: Could not recover jumptable at 0x000262a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(puVar4 + uVar2 + 1))();
    return iVar1;
  }
}




void FUN_000262e4(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar2;
  bool bVar3;
  byte in_Q;
  
  uVar1 = param_4 | param_2;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x100000) < 0) {
      if (-1 < (int)(uVar1 - 0x100000)) {
        return;
      }
      if (param_2 != param_4) {
        return;
      }
      return;
    }
    bVar2 = 0xffdfffff < param_4 << 1;
    if (!bVar2) {
      bVar2 = 0xffdfffff < param_2 << 1;
    }
    if (!bVar2) {
      return;
    }
  }
  else {
    bVar3 = SCARRY4(uVar1,0x100000);
    bVar2 = (int)(uVar1 + 0x100000) < 0;
    if (!bVar2) {
      bVar3 = SBORROW4(uVar1,0x100000);
      bVar2 = (int)(uVar1 - 0x100000) < 0;
    }
    if (!bVar2) {
      if (param_4 != param_2) {
        return;
      }
      return;
    }
    if (bVar3 == false) {
      return;
    }
    bVar2 = (int)(param_4 + 0x100000) < 0;
    if (!bVar2) {
      bVar2 = (int)(param_2 + 0x100000) < 0;
    }
    if (!bVar2) {
      return;
    }
  }
  UNRECOVERED_JUMPTABLE = (code *)0x260d8;
  FUN_0002623c(param_3,param_4,param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x00025c36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((uint)(in_Q | 4) << 0x1b);
  return;
}




/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_00026350(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  ulonglong uVar14;
  
  if (-1 < (int)(param_2 ^ param_4)) {
    bVar11 = param_3 <= param_1;
    uVar8 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar8);
      param_3 = param_3 + uVar8;
      uVar9 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar9 + bVar12;
      bVar11 = param_1 < uVar8;
      param_1 = param_1 - uVar8;
      param_2 = (param_2 - uVar9) - (uint)bVar11;
    }
    uVar9 = param_2 >> 0x14;
    uVar8 = uVar9 - (param_4 >> 0x14);
    bVar11 = (DAT_00026520 & param_4 << 1) == 0;
    if (!bVar11) {
      bVar11 = DAT_00026520 == uVar9 << 0x15;
    }
    if (bVar11) {
      if (DAT_00026520 != uVar9 << 0x15) {
        if ((param_2 & DAT_00026520 >> 1) == 0) {
          param_2 = 0;
          param_1 = 0;
        }
        return CONCAT44(param_2,param_1);
      }
      UNRECOVERED_JUMPTABLE = (code *)0x26512;
      FUN_0002623c();
      software_interrupt(0x40);
                    /* WARNING: Could not recover jumptable at 0x0002651e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar14 = (*UNRECOVERED_JUMPTABLE)(param_3,param_4 ^ 0x80000000);
      return uVar14;
    }
    uVar6 = -param_3;
    uVar3 = param_2 & ~(uVar9 << 0x14);
    iVar7 = ((int)DAT_00026520 >> 1) - (param_4 & ~((int)DAT_00026520 >> 1));
    if (param_3 != 0) {
      iVar7 = iVar7 + -1;
    }
    if (uVar8 < 0x21) {
      uVar10 = uVar6 >> (uVar8 & 0xff);
      uVar1 = param_1 + uVar10;
      uVar3 = uVar3 + (iVar7 >> (uVar8 & 0xff)) + (uint)CARRY4(param_1,uVar10);
      uVar10 = iVar7 << (0x20 - uVar8 & 0xff);
      bVar12 = CARRY4(uVar1,uVar10);
      uVar1 = uVar1 + uVar10;
      bVar11 = CARRY4(uVar3,(uint)bVar12);
      iVar7 = uVar3 + bVar12;
      uVar8 = 0x20 - uVar8;
    }
    else {
      param_3 = param_3 * -2;
      if (param_3 != 0) {
        param_3 = 1;
      }
      uVar6 = param_3 | (iVar7 * 2 + (uint)CARRY4(uVar6,uVar6)) * 2;
      uVar8 = uVar8 - 0x20;
      if (0x1d < uVar8) {
        return CONCAT44(uVar3 + uVar9 * 0x100000,param_1);
      }
      uVar1 = iVar7 >> (uVar8 & 0xff);
      bVar12 = CARRY4(param_1,uVar1);
      uVar1 = param_1 + uVar1;
      bVar11 = uVar3 != 0 || CARRY4(uVar3 - 1,(uint)bVar12);
      iVar7 = (uVar3 - 1) + (uint)bVar12;
      uVar8 = 0x1e - uVar8;
    }
    if (-1 < iVar7) {
      iVar5 = uVar6 << (uVar8 & 0xff);
      iVar7 = iVar7 + uVar9 * 0x100000;
      if (-1 < iVar5) {
        return CONCAT44(iVar7,uVar1);
      }
      uVar1 = uVar1 + 1;
      if (uVar1 != 0 && iVar5 != -0x80000000) {
        return CONCAT44(iVar7,uVar1);
      }
      if (uVar1 == 0) {
        iVar7 = iVar7 + 1;
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 & 0xfffffffe;
      }
      return CONCAT44(iVar7,uVar1);
    }
    uVar3 = uVar8 + 1 & 0xff;
    bVar11 = uVar3 == 0 && bVar11 || uVar3 != 0 && (uVar6 << uVar3 - 1 & 0x80000000) != 0;
    uVar10 = uVar1 * 2 + (uint)bVar11;
    uVar8 = iVar7 * 2 + (uint)(CARRY4(uVar1,uVar1) || CARRY4(uVar1 * 2,(uint)bVar11));
    uVar1 = uVar8 + uVar9 * 0x200000;
    bVar11 = (uVar1 >> 0x14 & 1) != 0;
    if (bVar11 && uVar1 >> 0x15 != 0) {
      uVar1 = -((int)(uVar6 << uVar3) >> 0x1f);
      uVar2 = uVar10 + uVar1;
      bVar11 = uVar2 == 0;
      iVar7 = uVar8 + uVar9 * 0x100000;
      if (CARRY4(uVar10,uVar1) == false) {
        bVar11 = uVar6 << uVar3 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar7,uVar2);
      }
      if (uVar2 == 0) {
        iVar7 = iVar7 + 1;
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return CONCAT44(iVar7,uVar2);
    }
    if (!bVar11) {
      iVar7 = uVar8 + 0x200000;
      if (iVar7 == 0) {
        uVar8 = uVar10 << LZCOUNT(uVar10);
        if (uVar8 == 0) {
          return (ulonglong)uVar10;
        }
        iVar5 = ((uVar9 & 0xfffff7ff) - LZCOUNT(uVar10)) + -0x17;
        iVar7 = uVar8 << 0x15;
        uVar8 = uVar8 >> 0xb;
      }
      else {
        uVar6 = LZCOUNT(iVar7) - 0xb;
        iVar5 = ((uVar9 & 0xfffff7ff) - uVar6) + -2;
        uVar8 = iVar7 << (uVar6 & 0xff) | uVar10 >> (0x20 - uVar6 & 0xff);
        iVar7 = uVar10 << (uVar6 & 0xff);
      }
      iVar4 = uVar8 + (param_2 & 0x80000000) + iVar5 * 0x100000;
      if (-1 < iVar5) {
        return CONCAT44(iVar4,iVar7);
      }
      return (ulonglong)(iVar4 + 0x60000000U & 0x80000000) << 0x20;
    }
    uVar9 = ((int)uVar8 >> 1) + uVar9 * 0x100000;
    uVar8 = (uint)((uVar8 & 1) != 0) << 0x1f | uVar10 >> 1;
    if (uVar9 * 2 == 0 && uVar8 == 0) {
      return (ulonglong)uVar8;
    }
    if (0x1fffff < uVar9 * 2) {
      return CONCAT44(uVar9,uVar8);
    }
    return (ulonglong)(uVar9 & 0x80000000) << 0x20;
  }
  param_4 = param_4 ^ 0x80000000;
  uVar8 = param_1 - param_3;
  iVar7 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar8);
    param_3 = param_3 + uVar8;
    param_4 = param_4 + iVar7 + (uint)bVar11;
    bVar11 = param_1 < uVar8;
    param_1 = param_1 - uVar8;
    param_2 = (param_2 - iVar7) - (uint)bVar11;
  }
  uVar9 = param_2 >> 0x14;
  uVar8 = uVar9 - (param_4 >> 0x14);
  bVar11 = (DAT_00025c0c & param_4 << 1) == 0;
  if (!bVar11) {
    bVar11 = DAT_00025c0c == uVar9 << 0x15;
  }
  if (bVar11) {
    if (DAT_00025c0c != uVar9 << 0x15) {
      if ((param_2 & DAT_00025c0c >> 1) == 0) {
        param_2 = param_2 & 0x80000000;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    FUN_0002623c();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_2 = param_2 & ~(uVar9 << 0x14);
  uVar6 = param_4 & ~DAT_00025c0c | 0x100000;
  if (uVar8 < 0x21) {
    uVar10 = param_3 >> (uVar8 & 0xff);
    uVar3 = param_1 + uVar10;
    uVar2 = uVar6 << (0x20 - uVar8 & 0xff);
    uVar1 = uVar3 + uVar2;
    param_2 = param_2 + (uVar6 >> (uVar8 & 0xff)) + (uint)CARRY4(param_1,uVar10) +
              (uint)CARRY4(uVar3,uVar2);
    uVar8 = 0x20 - uVar8;
    if (param_2 < 0x100000) {
      param_2 = param_2 + uVar9 * 0x100000;
      goto LAB_00025b3c;
    }
LAB_00025b9e:
    bVar13 = (byte)uVar1 & 1;
    uVar6 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar1 >> 1;
    param_2 = (param_2 + 0x100000 >> 1) + uVar9 * 0x100000;
    if ((uVar1 & 1) == 0) {
LAB_00025bcc:
      if (param_2 * 2 < 0xffe00000) {
        return CONCAT44(param_2,uVar6);
      }
      goto LAB_000262d8;
    }
    bVar11 = CARRY4(uVar6,(uint)bVar13);
    uVar6 = uVar6 + bVar13;
    uVar9 = uVar6;
    if (!bVar11) {
      uVar9 = param_3 << (uVar8 & 0xff);
    }
    if (uVar9 != 0) goto LAB_00025bcc;
  }
  else {
    param_3 = uVar6 * 2 + (uint)(param_3 != 0);
    uVar3 = uVar8 - 0x20;
    uVar8 = 0x1f - uVar3;
    if (uVar3 < 0x20) {
      uVar6 = uVar6 >> (uVar3 & 0xff);
      uVar1 = param_1 + uVar6;
    }
    else {
      uVar8 = 0;
      uVar1 = param_1;
    }
    param_2 = param_2 + uVar9 * 0x100000 + (uint)(uVar3 < 0x20 && CARRY4(param_1,uVar6));
    if (uVar9 != param_2 >> 0x14) {
      param_2 = param_2 + uVar9 * -0x100000;
      goto LAB_00025b9e;
    }
LAB_00025b3c:
    param_3 = param_3 << (uVar8 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(param_2,uVar1);
    }
    uVar6 = uVar1 + 1;
    uVar8 = uVar6;
    if (uVar1 != 0xffffffff) {
      uVar8 = param_3 & 0x7fffffff;
    }
    if (uVar8 != 0) {
      return CONCAT44(param_2,uVar6);
    }
  }
  if (uVar6 == 0) {
    param_2 = param_2 + 1;
    uVar6 = 0;
  }
  else {
    uVar6 = uVar6 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar6);
  }
LAB_000262d8:
  return (ulonglong)((uint)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}




longlong FUN_00026524(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f;
  uVar2 = (param_1 << 1) >> 4;
  uVar4 = param_1 << 1 ^ param_1;
  bVar5 = uVar4 == 0;
  if (!bVar5) {
    param_1 = param_1 << 0x1d;
    param_2 = (uVar1 | uVar2) + 0x38000000;
    bVar5 = (uVar4 & 0x7f000000) == 0;
  }
  if (bVar5) {
    if ((uVar2 & 0x8000000) != 0) {
      iVar3 = FUN_0002657a(uVar1 | param_1 >> 0x1d | uVar2 << 3,param_2);
      return (ulonglong)((uint)(iVar3 < 0) << 0x1f | 0x7ff00000) << 0x20;
    }
    return (ulonglong)uVar1 << 0x20;
  }
  return CONCAT44(param_2,param_1);
}




uint FUN_0002657a(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int in_lr;
  uint *puVar3;
  bool bVar4;
  
  puVar3 = (uint *)(in_lr + 2U & 0xfffffffc);
  uVar1 = *puVar3;
  if ((((int)uVar1 < 0) || (param_3 = param_2 * 2, param_3 < 0xff000001)) &&
     (param_1 * 2 < 0xff000001)) {
    if (param_1 * 2 == 0xff000000) {
      uVar2 = ((int)param_1 >> 0x1f) * -3 + 2;
      if (param_3 == 0xff000000) {
        uVar2 = uVar2 + ((uint)(0xfeffffff < param_3) - ((int)param_2 >> 0x1f));
      }
    }
    else {
      uVar2 = param_2 >> 0x1f;
    }
  }
  else {
    uVar2 = 8;
  }
  uVar1 = uVar1 >> (uVar2 * 3 & 0xff) & 7;
  switch(uVar1) {
  case 4:
    param_1 = param_2;
switchD_000265e2_caseD_5:
    bVar4 = (param_1 & 0x80000000) != 0;
    uVar1 = param_1 * 2;
    if (uVar1 != 0) {
      bVar4 = uVar1 < 0x1000001;
    }
    if (bVar4 && (uVar1 != 0 && uVar1 != 0x1000000)) {
      param_1 = param_1 & 0x80000000;
    }
    return param_1;
  case 5:
    goto switchD_000265e2_caseD_5;
  case 6:
  case 7:
    return 0x7fc00000;
  default:
                    /* WARNING: Could not recover jumptable at 0x000265e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(puVar3 + uVar1 + 1))();
    return uVar1;
  }
}




/* WARNING: Control flow encountered bad instruction data */

uint FUN_00026610(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  bVar7 = (~(param_2 << 1) & 0xff000000) == 0;
  if (!bVar7) {
    bVar7 = (~(param_1 << 1) & 0xff000000) == 0;
  }
  if (bVar7) {
    FUN_0002657a();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar5 = param_2 >> 7 & 0xff0000;
  if ((param_1 & 0x80000000) != 0) {
    uVar5 = uVar5 | 5;
  }
  uVar4 = param_1 >> 7 & 0xff0000;
  bVar7 = uVar4 == 0;
  if (!bVar7) {
    bVar7 = (uVar5 & 0xff0000) == 0;
  }
  if (bVar7) {
    if ((param_2 >> 7 & 0xff0000) != 0) {
      return param_1 & 0x80000000;
    }
    return DAT_00026700;
  }
  uVar1 = param_1 << 8 | 0x80000000;
  uVar3 = param_2 << 8 | 0x80000000;
  uVar5 = uVar5 - 0x10000;
  for (; (int)uVar5 < (int)uVar4; uVar4 = uVar4 - 0x10000) {
    uVar5 = uVar5 & 0xfffffffd;
    uVar2 = uVar1;
    if (0x7fffffff < uVar1) {
      uVar2 = uVar1 - uVar3;
      uVar5 = uVar5 | 2;
      if ((int)uVar1 < (int)uVar3) {
        uVar2 = -uVar2;
        uVar5 = uVar5 ^ 1;
      }
    }
    uVar1 = uVar2 << 1;
  }
  if ((((int)uVar5 >> 0x10 <= (int)uVar4 >> 0x10) && (uVar3 <= uVar1)) &&
     ((uVar1 != uVar3 || ((uVar5 & 2) != 0)))) {
    uVar1 = -(uVar1 + param_2 * -0x200);
    uVar5 = uVar5 ^ 1;
  }
  uVar2 = uVar1 << 1;
  uVar3 = uVar4;
  if ((uVar1 & 0x80000000) == 0) {
    if ((int)uVar2 < 0) {
      uVar3 = uVar4 - 0x10000;
      uVar2 = uVar1 << 2;
      if (uVar3 != 0 && 0xffff < (int)uVar4) goto LAB_000266d4;
    }
    else {
      if (uVar2 == 0) {
        return (uVar5 & 4) << 0x1d;
      }
      iVar6 = LZCOUNT(uVar2);
      uVar2 = uVar2 << iVar6 + 1;
      uVar3 = uVar4 + (iVar6 + 1) * -0x10000;
    }
  }
  else {
LAB_000266d4:
    if (0 < (int)uVar3) goto LAB_000266d8;
  }
  if ((int)uVar3 < 1) {
    return uVar5 << 0x1f;
  }
LAB_000266d8:
  return uVar3 << 7 | uVar2 >> 9 | uVar5 << 0x1f;
}




/* WARNING: Removing unreachable block (ram,0x000267e6) */
/* WARNING: Removing unreachable block (ram,0x000267f4) */
/* WARNING: Removing unreachable block (ram,0x00026744) */
/* WARNING: Removing unreachable block (ram,0x000267ec) */
/* WARNING: Removing unreachable block (ram,0x0002672e) */
/* WARNING: Removing unreachable block (ram,0x00026762) */
/* WARNING: Removing unreachable block (ram,0x00026750) */
/* WARNING: Removing unreachable block (ram,0x0002672c) */
/* WARNING: Removing unreachable block (ram,0x00026734) */
/* WARNING: Removing unreachable block (ram,0x0002673e) */
/* WARNING: Removing unreachable block (ram,0x0002671c) */

longlong FUN_00026778(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  char in_OV;
  bool bVar3;
  bool bVar4;
  
  uVar2 = 0x7ff;
  uVar1 = param_2 >> 0x14 & 0x7ff;
  bVar4 = uVar1 == 0;
  if (!bVar4) {
    uVar2 = uVar1 ^ 0x7ff;
    bVar4 = uVar2 == 0;
  }
  bVar3 = false;
  if (!bVar4) {
    in_OV = SBORROW4(uVar2,param_3);
    bVar3 = (int)(uVar2 - param_3) < 0;
    bVar4 = uVar2 == param_3;
  }
  if (!bVar4 && bVar3 == (bool)in_OV) {
    in_OV = SCARRY4(param_3,uVar1);
    bVar3 = (int)(param_3 + uVar1) < 0;
    bVar4 = param_3 + uVar1 == 0;
  }
  if (!bVar4 && bVar3 == (bool)in_OV) {
    return CONCAT44(param_2 + param_3 * 0x100000,param_1);
  }
  if (uVar1 == 0) {
    return (ulonglong)(param_2 & 0x80000000) << 0x20;
  }
  if (uVar2 == 0) {
    if ((param_1 | param_2 << 0xc) != 0) {
      return (ulonglong)DAT_00025c1c << 0x20;
    }
    return CONCAT44(param_2,param_1);
  }
  param_2 = param_2 & 0x80000000;
  if (-1 < (int)param_3) {
    param_2 = param_2 | 0x7ff00000;
  }
  return (ulonglong)param_2 << 0x20;
}




undefined *
thunk_FUN_00024274(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int **param_4)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  int *piVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  undefined *puStack_78;
  uint uStack_74;
  int *piStack_70;
  uint uStack_6c;
  undefined uStack_68;
  char acStack_67 [23];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined auStack_48 [12];
  int iStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 *puStack_2c;
  int **ppiStack_28;
  
  iVar13 = 0;
  piVar6 = param_4[1];
  piVar10 = param_4[2];
  iStack_3c = 0;
  uStack_34 = param_1;
  uStack_30 = param_2;
  puStack_2c = param_3;
  ppiStack_28 = param_4;
  iVar1 = FUN_00023a94();
  uStack_38 = (uint)*(byte *)((int)*(int **)(iVar1 + 0xc) + **(int **)(iVar1 + 0xc));
  puVar9 = (undefined *)0xffffffff;
  do {
    puVar12 = puVar9;
    puVar9 = puVar12 + 1;
    uVar2 = (*(code *)param_4[6])(uStack_30);
    iVar1 = (*(code *)param_4[8])();
  } while (iVar1 != 0);
  if (uVar2 == 0xffffffff) {
    return (undefined *)0xffffffff;
  }
  uVar7 = (uint)piVar6 & 0xfffff97f;
  if (0 < (int)piVar10) {
    if (uVar2 != 0x2b) {
      if (uVar2 != 0x2d) goto LAB_000242de;
      uVar7 = uVar7 | 0x400;
    }
    puVar9 = puVar12 + 2;
    uVar2 = (*(code *)param_4[6])(uStack_30);
    piVar10 = (int *)((int)piVar10 + -1);
  }
LAB_000242de:
  if ((int)(uVar7 << 0x15) < 0) {
    uStack_68 = 0x2d;
  }
  else {
    uStack_68 = 0x2b;
  }
  pcVar15 = acStack_67;
  puVar12 = auStack_48;
  if (0 < (int)piVar10) {
    if (((((uVar2 == 0x69) || (uVar2 == 0x49)) || (uVar2 == 0x6e)) || (uVar2 == 0x4e)) &&
       (puStack_78 = puVar9, uStack_74 = uVar7, piStack_70 = piVar10, uStack_6c = uVar2,
       puVar3 = (undefined *)thunk_FUN_00024cec(0xfffffffd,uStack_30,puStack_2c,param_4),
       puVar3 != (undefined *)0xfffffffd)) {
      return puVar3;
    }
    do {
      if (uVar2 != 0x30) {
        if (((uVar2 == 0x78) || (uVar2 == 0x58)) &&
           ((iStack_3c == 1 &&
            (puStack_78 = puVar9, uStack_74 = uVar7, piStack_70 = piVar10,
            puVar3 = (undefined *)thunk_FUN_000249cc(0xfffffffd,uStack_30,puStack_2c,param_4),
            puVar3 != (undefined *)0xfffffffd)))) {
          return puVar3;
        }
        break;
      }
      puVar9 = puVar9 + 1;
      uVar2 = (*(code *)param_4[6])(uStack_30);
      piVar10 = (int *)((int)piVar10 + -1);
      uVar7 = uVar7 | 0x200;
      *puStack_2c = puVar9;
      iStack_3c = iStack_3c + 1;
    } while (0 < (int)piVar10);
  }
  if (uVar2 == uStack_38) {
    uVar7 = uVar7 | 0x80;
    puVar3 = puVar9;
    while( true ) {
      puVar9 = puVar3 + 1;
      piVar10 = (int *)((int)piVar10 + -1);
      uVar2 = (*(code *)param_4[6])(uStack_30);
      if (uVar2 != 0x30) break;
      iVar13 = iVar13 + -1;
      uVar7 = uVar7 | 0x200;
      *puStack_2c = puVar3 + 2;
      puVar3 = puVar9;
    }
  }
  do {
    if ((int)piVar10 < 1) {
LAB_000244ac:
      (*(code *)param_4[7])(uStack_30);
      *pcVar15 = -1;
      *puVar12 = 0xff;
      uStack_50 = 0;
      uStack_4c = 0;
      FUN_00024028(&uStack_50,auStack_48,&uStack_68,iVar13);
      if (-1 < (int)(uVar7 << 0x16)) {
        return (undefined *)0xfffffffe;
      }
      if ((uVar7 & 0x24) != 0) {
        if ((uVar7 & 1) != 0) {
          return puVar9;
        }
        piVar6 = *param_4;
        *param_4 = piVar6 + 1;
        puVar5 = (undefined4 *)*piVar6;
        *puVar5 = uStack_50;
        puVar5[1] = uStack_4c;
        return puVar9;
      }
      FUN_00025940(&puStack_78,&uStack_50);
      if ((uVar7 & 1) != 0) {
        return puVar9;
      }
      piVar6 = *param_4;
      *param_4 = piVar6 + 1;
      *(undefined **)*piVar6 = puStack_78;
      return puVar9;
    }
    if ((uVar2 == uStack_38) && (-1 < (int)(uVar7 << 0x18))) {
      uVar8 = uVar7 | 0x80;
    }
    else {
      iVar1 = FUN_00025966(uVar2);
      if (iVar1 == 0) {
        if ((0 < (int)piVar10) &&
           (((uVar2 == 0x65 || (uVar2 == 0x45)) && ((int)(uVar7 << 0x16) < 0)))) {
          iVar11 = (int)piVar10 + -1;
          uVar7 = uVar7 & 0xfffffcff;
          iVar1 = (*(code *)param_4[6])(uStack_30);
          puVar12 = puVar9 + 1;
          if (0 < iVar11) {
            if (iVar1 != 0x2b) {
              if (iVar1 != 0x2d) goto LAB_00024446;
              uVar7 = uVar7 | 0x100;
            }
            iVar1 = (*(code *)param_4[6])(uStack_30);
            iVar11 = (int)piVar10 + -2;
            puVar12 = puVar9 + 2;
          }
LAB_00024446:
          puVar9 = puVar12;
          if ((int)(uVar7 << 0x17) < 0) {
            auStack_48[0] = 0x2d;
          }
          else {
            auStack_48[0] = 0x2b;
          }
          puVar12 = auStack_48 + 1;
          puStack_78 = puVar12;
          while ((0 < iVar11 && (iVar4 = FUN_00025966(iVar1), iVar4 != 0))) {
            iVar11 = iVar11 + -1;
            if (puVar12 < auStack_48 + 9) {
              *puVar12 = (char)(iVar1 - 0x30U);
              if (((iVar1 - 0x30U & 0xff) != 0) || (puStack_78 < puVar12)) {
                puVar12 = puVar12 + 1;
              }
            }
            else {
              iVar13 = DAT_00024500;
              if (-1 < (int)(uVar7 << 0x17)) {
                iVar13 = 9999;
              }
            }
            puVar9 = puVar9 + 1;
            iVar1 = (*(code *)param_4[6])(uStack_30);
            *puStack_2c = puVar9;
            uVar7 = uVar7 | 0x200;
          }
        }
        goto LAB_000244ac;
      }
      uVar8 = uVar7 | 0x200;
      if (pcVar15 < acStack_67 + 0x12) {
        pcVar14 = pcVar15 + 1;
        *pcVar15 = (char)uVar2 + -0x30;
        pcVar15 = pcVar14;
        if ((int)(uVar7 << 0x18) < 0) {
          iVar13 = iVar13 + -1;
        }
      }
      else if (-1 < (int)(uVar7 << 0x18)) {
        iVar13 = iVar13 + 1;
      }
    }
    piVar10 = (int *)((int)piVar10 + -1);
    if ((int)(uVar8 << 0x16) < 0) {
      *puStack_2c = puVar9 + 1;
    }
    puVar9 = puVar9 + 1;
    uVar2 = (*(code *)param_4[6])(uStack_30);
    uVar7 = uVar8;
  } while( true );
}




/* WARNING: Removing unreachable block (ram,0x00024bf2) */

int thunk_FUN_000249cc(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,
                      uint param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint **ppuVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  undefined8 uVar14;
  longlong lVar15;
  longlong lVar16;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  int iStack_40;
  uint uStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int *piStack_2c;
  int *piStack_28;
  
  iVar10 = 0x3c;
  param_5 = param_5 + 1;
  uStack_44 = (param_6 & 0x400) << 0x15;
  uStack_3c = 0;
  bVar13 = false;
  uVar8 = 0;
  uVar7 = 0;
  iStack_40 = 0;
  iVar9 = -1;
  uStack_34 = param_1;
  uStack_30 = param_2;
  piStack_2c = param_3;
  piStack_28 = param_4;
  uStack_48 = (*(code *)param_4[6])(param_2);
  param_7 = param_7 + -1;
  while (0 < param_7) {
    if (uStack_48 == 0x2e) {
      iStack_40 = 1;
    }
    else {
      uVar2 = FUN_0002400a(uStack_48,0x10);
      if ((int)uVar2 < 0) {
        if ((uStack_48 == 0x70) || (uStack_48 == 0x50)) {
          uStack_48 = 0;
          iStack_40 = 1;
          if (!bVar13) goto LAB_00024ab6;
          iVar10 = (*(code *)param_4[6])(uStack_30);
          iVar11 = param_7 + -1;
          if (iVar11 < 1) goto LAB_00024ab6;
          if (iVar10 == 0x2b) {
LAB_00024ad4:
            iVar10 = (*(code *)param_4[6])(uStack_30);
            iVar11 = param_7 + -2;
            iVar1 = param_5 + 2;
            if (iVar11 < 1) goto LAB_00024ab6;
          }
          else {
            iVar1 = param_5 + 1;
            if (iVar10 == 0x2d) {
              iStack_40 = -1;
              goto LAB_00024ad4;
            }
          }
          param_5 = iVar1;
          if ((iVar10 == -1) || (iVar10 = FUN_0002400a(iVar10,10), iVar10 < 0)) {
LAB_00024ab6:
            (*(code *)param_4[7])(uStack_30);
            return -2;
          }
          goto LAB_00024af6;
        }
        break;
      }
      bVar13 = true;
      if ((uStack_3c | uVar2) == 0) {
        if (iStack_40 != 0) {
          iVar9 = iVar9 + -4;
        }
      }
      else {
        if (iVar10 < 0) {
          if (uVar2 != 0) {
            uVar8 = uVar8 | 1;
          }
        }
        else {
          uVar14 = FUN_00024e94(uVar2,(int)uVar2 >> 0x1f,iVar10);
          uVar8 = uVar8 | (uint)uVar14;
          uVar7 = uVar7 | (uint)((ulonglong)uVar14 >> 0x20);
          iVar10 = iVar10 + -4;
        }
        uStack_3c = 1;
        if (iStack_40 == 0) {
          iVar9 = iVar9 + 4;
        }
      }
    }
    param_5 = param_5 + 1;
    uStack_48 = (*(code *)param_4[6])(uStack_30);
    param_7 = param_7 + -1;
    if (bVar13) {
      *piStack_2c = param_5;
    }
  }
  (*(code *)param_4[7])(uStack_30);
  if (!bVar13) {
    return -2;
  }
  goto LAB_00024b34;
  while (-1 < iVar10) {
LAB_00024af6:
    param_5 = param_5 + 1;
    uStack_48 = iVar10 + uStack_48 * 10;
    uVar3 = (*(code *)param_4[6])(uStack_30);
    iVar10 = FUN_0002400a(uVar3,10);
    iVar11 = iVar11 + -1;
    *piStack_2c = param_5;
    if (iVar11 < 1) break;
  }
  (*(code *)param_4[7])(uStack_30);
  iVar9 = uStack_48 * iStack_40 + iVar9;
LAB_00024b34:
  uStack_4c = uStack_44;
  if ((uVar8 | uVar7) != 0) {
    if ((uVar7 & 0xc0000000) == 0) {
      uVar7 = uVar7 << 2 | uVar8 >> 0x1e;
      uVar8 = uVar8 << 2;
      iVar9 = iVar9 + -2;
    }
    if ((uVar7 & 0x80000000) == 0) {
      bVar13 = CARRY4(uVar8,uVar8);
      uVar8 = uVar8 * 2;
      uVar7 = uVar7 * 2 + (uint)bVar13;
      iVar9 = iVar9 + -1;
    }
    if ((param_6 & 0x24) == 0) {
      iVar11 = 0x28;
      iVar10 = -0x7e;
    }
    else {
      iVar11 = 0xb;
      iVar10 = DAT_00024ce0;
    }
    if ((iVar9 < iVar10) && (iVar11 = iVar11 + (iVar10 - iVar9), 0x41 < iVar11)) {
      iVar11 = 0x41;
    }
    lVar15 = FUN_00024e94(1,0,iVar11 + -1);
    bVar13 = ((uint)lVar15 & uVar8 | (uint)((ulonglong)lVar15 >> 0x20) & uVar7) != 0;
    uStack_48 = (uint)bVar13;
    bVar12 = ((uint)(lVar15 + -1) & uVar8 | (uint)((ulonglong)(lVar15 + -1) >> 0x20) & uVar7) != 0;
    if (((bVar13 || bVar12) && (uStack_48 != 0)) &&
       ((bVar12 ||
        (uVar14 = FUN_00024e94(1,0,iVar11),
        ((uint)uVar14 & uVar8 | (uint)((ulonglong)uVar14 >> 0x20) & uVar7) != 0)))) {
      lVar16 = FUN_00024e94(1,0,iVar11);
      lVar15 = lVar16 + CONCAT44(uVar7,uVar8);
      uVar2 = (uint)lVar15;
      uVar6 = (uint)((ulonglong)lVar15 >> 0x20);
      if (uVar6 < uVar7 || uVar7 - uVar6 < (uint)(uVar2 <= uVar8)) {
        if (iVar11 < 0x41) {
          iVar9 = iVar9 + 1;
        }
        else if ((param_6 & 0x24) == 0) {
          iVar9 = iVar10 + -0x17;
        }
        else {
          iVar9 = iVar10 + -0x34;
        }
        uVar8 = 0;
        uVar7 = 0;
      }
      else {
        uVar8 = uVar2 & ~(uint)(lVar16 + -1);
        uVar7 = uVar6 & ~(uint)((ulonglong)(lVar16 + -1) >> 0x20);
      }
    }
    if (iVar9 <= 1 - iVar10) {
      uStack_50 = uVar8 >> 0xb | uVar7 << 0x15;
      uStack_4c = uStack_44 | (uVar7 << 1) >> 0xc | DAT_00024ce8;
      FUN_00025952(&uStack_50,iVar9);
      goto LAB_00024ca0;
    }
    uStack_4c = uStack_44 | DAT_00024ce4;
  }
  uStack_50 = 0;
LAB_00024ca0:
  if ((param_6 & 0x24) == 0) {
    FUN_00025940(&uStack_48,&uStack_50);
    if ((param_6 & 1) == 0) {
      ppuVar4 = (uint **)*param_4;
      *param_4 = (int)(ppuVar4 + 1);
      **ppuVar4 = uStack_48;
    }
  }
  else if ((param_6 & 1) == 0) {
    ppuVar4 = (uint **)*param_4;
    *param_4 = (int)(ppuVar4 + 1);
    puVar5 = *ppuVar4;
    *puVar5 = uStack_50;
    puVar5[1] = uStack_4c;
  }
  return param_5;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int thunk_FUN_00024cec(undefined4 param_1,undefined4 param_2,int *param_3,int **param_4,int param_5,
                      uint param_6,int param_7,uint param_8)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint **ppuVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int *piStack_2c;
  int **ppiStack_28;
  
  iVar7 = param_7 + -1;
  uVar1 = (param_6 & 0x400) << 0x15;
  uVar9 = uVar1 | 0x7f800000;
  uVar8 = uVar1 | DAT_00024e10;
  uStack_38 = 0;
  uStack_34 = param_1;
  uStack_30 = param_2;
  piStack_2c = param_3;
  ppiStack_28 = param_4;
  if ((param_8 & 0xffffffdf) == 0x49) {
    iVar6 = 1;
    uStack_48 = s_INFINITY_00024e14._0_4_;
    uStack_44 = s_INFINITY_00024e14._4_4_;
    uStack_40 = ram0x00024e1c;
    while( true ) {
      iVar5 = param_5;
      param_5 = iVar5 + 1;
      uVar1 = (*(code *)param_4[6])(uStack_30);
      iVar7 = iVar7 + -1;
      if (((iVar7 < 0) || (*(byte *)((int)&uStack_48 + iVar6) == 0)) ||
         ((uVar1 & 0xffffffdf) != (uint)*(byte *)((int)&uStack_48 + iVar6))) break;
      iVar6 = iVar6 + 1;
      if ((iVar6 == 3) || (iVar6 == 8)) {
        *param_3 = iVar5 + 2;
      }
    }
    (*(code *)param_4[7])(uStack_30);
    if ((iVar6 != 3) && (iVar6 != 8)) {
      return -2;
    }
  }
  else if ((param_8 & 0xffffffdf) == 0x4e) {
    uVar9 = (*(code *)param_4[6])(param_2);
    if ((((param_7 + -2 < 0) || ((uVar9 & 0xffffffdf) != 0x41)) ||
        (uVar9 = (*(code *)param_4[6])(uStack_30), param_7 + -3 < 0)) ||
       ((uVar9 & 0xffffffdf) != 0x4e)) {
LAB_00024dd6:
      (*(code *)param_4[7])(uStack_30);
      return -2;
    }
    param_5 = param_5 + 3;
    iVar7 = (*(code *)param_4[6])(uStack_30);
    param_7 = param_7 + -4;
    uVar8 = uVar8 | 0x80000;
    uVar9 = uVar1 | 0x7fc00000;
    *param_3 = param_5;
    if ((param_7 < 0) || (iVar7 != 0x28)) {
      (*(code *)param_4[7])(uStack_30);
    }
    else {
      do {
        iVar6 = param_5;
        iVar7 = (*(code *)param_4[6])(uStack_30);
        param_7 = param_7 + -1;
        if ((param_7 < 0) || (iVar7 < 0)) goto LAB_00024dd6;
        param_5 = iVar6 + 1;
      } while (iVar7 != 0x29);
      param_5 = iVar6 + 2;
      *param_3 = param_5;
    }
  }
  if ((param_6 & 1) == 0) {
    if ((param_6 & 0x24) == 0) {
      ppuVar4 = (uint **)*param_4;
      *param_4 = (int *)(ppuVar4 + 1);
      **ppuVar4 = uVar9;
    }
    else {
      piVar2 = *param_4;
      *param_4 = piVar2 + 1;
      puVar3 = (undefined4 *)*piVar2;
      *puVar3 = uStack_38;
      puVar3[1] = uVar8;
    }
  }
  return param_5;
}



