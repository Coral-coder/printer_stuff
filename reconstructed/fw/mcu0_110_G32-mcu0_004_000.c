/* Ghidra decompilation of mcu0_110_G32-mcu0_004_000.bin */


undefined4 FUN_000002b0(uint param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  
  if ((int)(*DAT_00000318 << 0x1b) < 0) {
    if ((*DAT_00000318 & 2) == 0) {
      uVar1 = 0x960;
    }
    else {
      uVar1 = 0;
    }
    return uVar1;
  }
  param_1 = param_1 & 0xff;
  *DAT_0000031c = *DAT_0000031c & 0xffffffe0 | param_1;
  if (param_1 < 10) {
    param_1 = param_1 * 3;
    puVar2 = DAT_00000328;
  }
  else {
    if (0x12 < param_1) goto LAB_000002fc;
    param_1 = param_1 * 3 - 0x1e;
    puVar2 = DAT_00000320;
  }
  *puVar2 = 1 << (param_1 & 0xff) | *puVar2 & ~(7 << (param_1 & 0xff));
LAB_000002fc:
  *DAT_00000324 = *DAT_00000324 | 0x400000;
  return 0x960;
}




void FUN_0000032c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar3 = *(int *)(DAT_00000358 + (param_1 >> 4) * 4);
  uVar1 = 1 << (param_1 & 0xf);
  bVar4 = (uVar1 & *(uint *)(iVar3 + 0xc)) != 0;
  if (bVar4) {
    *(uint *)(iVar3 + 0x14) = uVar1;
  }
  if (!bVar4) {
    *(uint *)(iVar3 + 0x10) = uVar1;
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  return;
}




void FUN_0000082c(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00000860;
  puVar1 = DAT_00000858;
  DAT_00000858[2] = DAT_0000085c;
  *puVar1 = 1;
  iVar3 = *(int *)(iVar2 + 4);
  FUN_00005fb0(puVar1[6],DAT_00000864);
  iVar2 = FUN_00006250();
  puVar1[3] = iVar3 + iVar2;
  FUN_000053c8(puVar1 + 1);
  return;
}




byte FUN_00000a5c(int param_1)

{
  FUN_00005368(DAT_00000a78);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10);
  return *(byte *)(param_1 + 0x14) & 1;
}




void FUN_00000a7c(int param_1,undefined4 param_2)

{
  FUN_000036b4(DAT_00000aa0,param_2,*(undefined2 *)(param_1 + 0x14),*(undefined *)(param_1 + 0x19),
               param_1 + 0x1a);
  *(undefined *)(param_1 + 0x19) = 0;
  *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + 1;
  return;
}




void FUN_00000aa4(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_000036b4(DAT_00000af0,*param_1 & 0xff,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],
               param_1[5]);
  iVar1 = FUN_000034dc(*(undefined *)param_1,DAT_00000af4,0x84);
  *(uint *)(iVar1 + 0xc) = *param_1;
  uVar2 = param_1[1];
  *(uint *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x78) = 0;
  if (uVar2 < 5) {
    *(undefined4 *)(iVar1 + 4) = DAT_00000af8;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0x1e);
}




void FUN_00000afc(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_000034dc(*(undefined *)param_1,DAT_00000b40,0x34);
  *(undefined4 *)(iVar1 + 0xc) = *param_1;
  uVar3 = param_1[1];
  *(uint *)(iVar1 + 0x18) = uVar3;
  uVar2 = DAT_00000b44;
  if (uVar3 < 5) {
    *(undefined *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
    uVar2 = *param_1;
    uVar4 = param_1[1];
    *(undefined4 *)(iVar1 + 4) = DAT_00000b48;
    FUN_000036b4(DAT_00000b4c,uVar2,uVar2,uVar4,0,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0x1c);
}




void FUN_00000b50(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  FUN_000036b4(DAT_00000bc8,*DAT_00000bc4,iVar1,*(undefined4 *)(DAT_00000bc4 + 0x2d8),
               DAT_00000bc4[0x2e2],*(undefined4 *)(DAT_00000bc4 + 0x304),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0x44),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 200),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0x14c),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0x1d0),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0x254),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0x48),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0xcc),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0x150),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 0x1d4),
               *(undefined4 *)(DAT_00000bc4 + iVar1 * 4 + 600));
  return;
}




void FUN_00000bcc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  FUN_000036b4(DAT_00000c28,*DAT_00000c24,iVar1,*(undefined4 *)(DAT_00000c24 + 0x60),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0xf0),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0xf4),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0xf8),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0xfc),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0x6c),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0x70),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0x74),
               *(undefined4 *)(DAT_00000c24 + iVar1 * 4 + 0x78));
  return;
}




void FUN_00000c2c(void)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = DAT_00000c54;
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((int)(*DAT_00000c54 << 0x1e) < 0) {
    *DAT_00000c54 = *DAT_00000c54 & 0xfffffffd;
    *puVar2 = *puVar2 & 0xffffffef;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}




bool FUN_00000cac(uint param_1)

{
  return (1 << (param_1 & 0xf) &
         *(uint *)(*(int *)(DAT_00000ccc + ((param_1 << 0x18) >> 0x1c) * 4) + 8)) != 0;
}




void FUN_00000dfc(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1 << (param_1 & 0xf);
  iVar1 = *(int *)(DAT_00000e18 + (param_1 >> 4) * 4);
  if (param_2 == 0) {
    *(int *)(iVar1 + 0x14) = iVar2;
    return;
  }
  *(int *)(iVar1 + 0x10) = iVar2;
  return;
}




void FUN_00000f00(uint param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *(int *)(DAT_00000f20 + (param_1 >> 4) * 4);
  uVar1 = 1 << (param_1 & 0xf);
  bVar3 = (*(uint *)(iVar2 + 0xc) & uVar1) != 0;
  if (bVar3) {
    *(uint *)(iVar2 + 0x14) = uVar1;
  }
  if (!bVar3) {
    *(uint *)(iVar2 + 0x10) = uVar1;
  }
  return;
}




void FUN_0000130c(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = *(uint *)(DAT_00001414 + (param_1 >> 4) * 4);
  puVar4 = *(uint **)(DAT_00001418 + (param_1 >> 4) * 4);
  *(uint *)(&DAT_40021000 + (uVar2 >> 6)) =
       1 << (uVar2 & 0x1f) | *(uint *)(&DAT_40021000 + (uVar2 >> 6));
  uVar2 = 1 << (param_1 & 0xf);
  if (param_2 == 0) {
    if (param_3 == 1) {
      iVar5 = 3;
      iVar6 = 0x10;
    }
    else {
      iVar5 = 7;
      iVar6 = 0x14;
    }
  }
  else if (param_2 == 1) {
    if (param_3 == 0) {
      iVar5 = 8;
      iVar6 = 0x28;
    }
    else if (param_3 == 1) {
      iVar5 = 8;
      iVar6 = 0x48;
    }
    else {
      iVar5 = 4;
      iVar6 = 4;
    }
  }
  else if (param_2 == 2) {
    iVar5 = 0;
    iVar6 = iVar5;
  }
  else if (param_3 == 0) {
    iVar5 = 0xf;
    iVar6 = 0x1c;
  }
  else {
    iVar5 = 0xb;
    iVar6 = 0x18;
  }
  uVar3 = 0;
  do {
    if ((int)((uVar2 >> (uVar3 & 0xff)) << 0x1f) < 0) {
      if (iVar6 == 0x28) {
        puVar4[5] = 1 << (uVar3 & 0xff) & uVar2;
      }
      else if (iVar6 == 0x48) {
        puVar4[4] = 1 << (uVar3 & 0xff) & uVar2;
      }
      *puVar4 = iVar5 << (uVar3 << 2 & 0xff) | *puVar4 & ~(0xf << (uVar3 << 2 & 0xff));
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 8);
  uVar3 = 8;
  do {
    uVar1 = uVar3 * 4 - 0x20;
    if ((int)((uVar2 >> (uVar3 & 0xff)) << 0x1f) < 0) {
      if (iVar6 == 0x28) {
        puVar4[5] = 1 << (uVar3 & 0xff) & uVar2;
      }
      else if (iVar6 == 0x48) {
        puVar4[4] = 1 << (uVar3 & 0xff) & uVar2;
      }
      puVar4[1] = iVar5 << (uVar1 & 0xff) | puVar4[1] & ~(0xf << (uVar1 & 0xff));
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 0x10);
  return;
}




uint FUN_00001524(uint param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 < 0x70) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_0000130c(param_1,1,(int)param_2,param_4,param_4);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0x2a);
}




void FUN_000015a8(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 1 << (param_1 & 0xf);
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_0000130c(param_1,0,1,param_4,param_4);
  iVar2 = *(int *)(DAT_000015dc + (param_1 >> 4) * 4);
  if (param_2 == 0) {
    *(int *)(iVar2 + 0x14) = iVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
    return;
  }
  *(int *)(iVar2 + 0x10) = iVar3;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}




uint FUN_000015e0(uint param_1)

{
  if (param_1 < 0x70) {
    FUN_000015a8();
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0x2b);
}




void FUN_000015f8(undefined *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar1 = FUN_000015e0(param_1[4],0);
  uVar3 = *(uint *)(param_1 + 8);
  if (-1 < (int)(uVar3 << 0x10)) {
    puVar2 = (undefined4 *)FUN_000034dc(*param_1,DAT_00001630,(uVar3 & 0xffff) + 0x14 & 0xffff);
    *puVar2 = uVar1;
    puVar2[1] = *(undefined4 *)(param_1 + 0xc);
    puVar2[3] = *(undefined4 *)(param_1 + 0x10);
    *(short *)(puVar2 + 4) = (short)uVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0x25);
}




void FUN_00001634(undefined *param_1)

{
  char cVar1;
  undefined uVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = FUN_000034dc(*param_1,DAT_00001684,0x2c);
  cVar1 = param_1[8];
  uVar8 = *(uint *)(param_1 + 4);
  uVar7 = *(uint *)(param_1 + 0xc);
  cVar5 = cVar1;
  if (cVar1 != '\0') {
    cVar5 = '\x01';
  }
  uVar2 = FUN_00001524(uVar8 & 0xff,cVar5);
  *(undefined *)(iVar3 + 0x10) = uVar2;
  uVar4 = FUN_000015e0(uVar7 & 0xff,1);
  *(undefined4 *)(iVar3 + 0xc) = uVar4;
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(iVar3 + 0x18) = uVar4;
  if (cVar1 == '\0') {
    uVar4 = 1;
  }
  bVar6 = (byte)uVar4;
  if (cVar1 != '\0') {
    bVar6 = 0x11;
  }
  if (uVar8 == uVar7) {
    bVar6 = bVar6 | 0x20;
  }
  *(byte *)(iVar3 + 0x11) = bVar6;
  return;
}




void FUN_00001688(undefined *param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  
  iVar1 = FUN_000034dc(*param_1,DAT_000016bc);
  iVar4 = *(int *)(param_1 + 8);
  uVar2 = FUN_000015e0(param_1[4],iVar4 == 0);
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  if (iVar4 == 0) {
    bVar3 = 1;
  }
  else {
    bVar3 = 9;
  }
  *(byte *)(iVar1 + 0x10) = *(byte *)(iVar1 + 0x10) | bVar3;
  return;
}




uint FUN_000018a8(byte *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (param_2 != 0) {
    uVar1 = 0xffff;
    pbVar4 = param_1;
    do {
      pbVar3 = pbVar4 + 1;
      uVar2 = (*pbVar4 ^ uVar1 ^ (*pbVar4 ^ uVar1) << 4) & 0xff;
      uVar1 = (uVar1 >> 8 | uVar2 << 8) ^ uVar2 << 3 ^ uVar2 >> 4;
      pbVar4 = pbVar3;
    } while (pbVar3 != param_1 + param_2);
    return uVar1;
  }
  return 0xffff;
}




void FUN_000018e0(undefined4 param_1,byte *param_2)

{
  if ((int)((uint)*param_2 << 0x1a) < 0) {
    FUN_000015a8();
    *param_2 = *param_2 & 0x30 | 1;
    return;
  }
  FUN_00000dfc(param_1,1);
  *param_2 = *param_2 & 0x30 | 1;
  return;
}




undefined4 FUN_00001914(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  
  iVar4 = FUN_00000cac(*(undefined *)(param_1 + 0x10));
  bVar1 = *(byte *)(param_1 + 0x12);
  iVar7 = param_1 + (uint)(bVar1 >> 3);
  bVar5 = *(byte *)(iVar7 + 0x20);
  bVar2 = (byte)(1 << (bVar1 & 7));
  if (iVar4 == 0) {
    bVar5 = bVar5 & ~bVar2;
  }
  else {
    bVar5 = bVar5 | bVar2;
  }
  *(byte *)(iVar7 + 0x20) = bVar5;
  uVar6 = bVar1 + 1;
  if ((uVar6 & 0xff) < (uint)*(byte *)(param_1 + 0x13)) {
    *(char *)(param_1 + 0x12) = (char)uVar6;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x1c);
    return 1;
  }
  FUN_000018e0(*(undefined4 *)(param_1 + 0xc),param_1 + 0x11);
  uVar3 = DAT_00001974;
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 8;
  FUN_00005368(uVar3);
  return 0;
}




void FUN_00001a40(int param_1,undefined4 param_2,uint param_3,int param_4,undefined param_5)

{
  byte bVar1;
  
  FUN_000036b4(DAT_00001a90,param_5,param_2,param_3,param_4);
  if (((param_4 != 0) || (param_3 < *(uint *)(param_1 + 0x10))) ||
     (*(uint *)(param_1 + 0x14) < param_3)) {
    bVar1 = *(char *)(param_1 + 0x1d) + 1;
    *(byte *)(param_1 + 0x1d) = bVar1;
    if (bVar1 < *(byte *)(param_1 + 0x1c)) {
      return;
    }
    if (*(char *)(DAT_00001a94 + 9) == '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_00002eb8(0x21);
    }
  }
  *(undefined *)(param_1 + 0x1d) = 0;
  return;
}




void FUN_00001a98(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  undefined8 uVar9;
  
  bVar1 = *(byte *)(param_1 + 4);
  uVar4 = (uint)bVar1;
  if ((bVar1 & 6) == 0) {
    return;
  }
  if ((int)(uVar4 << 0x1e) < 0) {
    FUN_00000dfc(*(undefined4 *)(*param_1 + 8),*(byte *)(*param_1 + 0xc) & 2);
    if ((bVar1 & 1) == 0) {
      puVar3 = (undefined *)*param_1;
      if (param_3 == 0) {
        return;
      }
    }
    else {
      FUN_00000dfc(param_1[3],(uVar4 << 0x1c) >> 0x1f);
      puVar3 = (undefined *)*param_1;
      if (param_3 == 0) goto LAB_00001b88;
    }
    pbVar8 = (byte *)(param_4 + -1);
    do {
      pbVar8 = pbVar8 + 1;
      uVar4 = (uint)*pbVar8;
      iVar5 = 8;
      uVar7 = 0;
      do {
        while ((int)((uint)(byte)puVar3[0xc] << 0x1f) < 0) {
          FUN_0000032c(*(undefined4 *)(puVar3 + 8),uVar4 & 0x80);
          FUN_00000dfc(*(undefined4 *)(puVar3 + 4),uVar4 & 0x80);
          FUN_0000032c(*(undefined4 *)(puVar3 + 8));
          uVar9 = FUN_00000cac(*puVar3,(uVar7 & 0x7f) << 1);
          uVar2 = (uint)((ulonglong)uVar9 >> 0x20) | (uint)uVar9;
          iVar5 = iVar5 + -1;
          uVar4 = (uVar4 & 0x7f) << 1;
          uVar7 = uVar2 & 0xff;
          bVar6 = (byte)uVar2;
          if (iVar5 == 0) goto LAB_00001b5c;
        }
        FUN_00000dfc(*(undefined4 *)(puVar3 + 4));
        FUN_0000032c(*(undefined4 *)(puVar3 + 8));
        uVar9 = FUN_00000cac(*puVar3,(uVar7 & 0x7f) << 1);
        uVar2 = (uint)((ulonglong)uVar9 >> 0x20) | (uint)uVar9;
        uVar7 = uVar2 & 0xff;
        bVar6 = (byte)uVar2;
        FUN_0000032c(*(undefined4 *)(puVar3 + 8));
        iVar5 = iVar5 + -1;
        uVar4 = (uVar4 & 0x7f) << 1;
      } while (iVar5 != 0);
LAB_00001b5c:
      if (param_2 != 0) {
        *pbVar8 = bVar6;
      }
    } while (pbVar8 != (byte *)(param_4 + (param_3 - 1U & 0xff)));
    if ((bVar1 & 1) == 0) {
      return;
    }
  }
  else {
    if (-1 < (int)(uVar4 << 0x1f)) {
      return;
    }
    FUN_00000dfc(param_1[3],(uVar4 << 0x1c) >> 0x1f);
  }
LAB_00001b88:
  FUN_00000dfc(param_1[3],(bVar1 & 8) == 0);
  return;
}




void FUN_00001bb8(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 local_1c;
  
  iVar1 = DAT_00001c08;
  iVar2 = FUN_0000306c(*(undefined *)param_1,DAT_00001c04);
  local_1c = 0xb9;
  iVar3 = *(int *)(iVar1 + 4);
  FUN_00001a98(*(undefined4 *)(iVar2 + 0x10),1,2,&local_1c);
  FUN_000036b4(DAT_00001c0c,*param_1,iVar3,*(int *)(iVar1 + 4) - iVar3,*(undefined2 *)(iVar2 + 0x14)
               ,*(undefined *)(iVar2 + 0x19),local_1c._1_1_,*(undefined2 *)(iVar2 + 0x16));
  return;
}




void FUN_00001c10(int param_1,undefined4 param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_24;
  undefined4 local_20;
  byte local_1c;
  
  local_24 = *DAT_00001d30;
  local_20 = DAT_00001d30[1];
  local_1c = (byte)DAT_00001d30[2];
  FUN_00001a98(*(undefined4 *)(param_1 + 0x10),1,9,&local_24);
  uVar1 = (uint)*(byte *)(param_1 + 0x19);
  iVar3 = uVar1 + 0x1a + param_1;
  if (((local_24 & 0xf00000) == 0) || ((local_24._2_1_ & 0xf0) == 0xf0)) {
    if (((local_20 & 0xf0) == 0) || ((local_20 & 0xf0) == 0xf0)) {
      if (((((local_20 & 0xf00000) == 0) || ((local_20._2_1_ & 0xf0) == 0xf0)) &&
          (local_20._3_1_ == -0x70)) && (uVar4 = local_1c & 0xffffff7f, uVar4 < 0x21)) {
        *(undefined *)(uVar1 + param_1 + 0x1a) = local_24._1_1_;
        *(byte *)(iVar3 + 4) = (local_20._2_1_ & 0x18) << 2 | (byte)local_20 & 0x1f;
        *(byte *)(iVar3 + 3) = local_24._2_1_ & 0x1f | local_20._2_1_ << 5;
        *(undefined *)(iVar3 + 1) = local_24._3_1_;
        *(undefined *)(iVar3 + 2) = local_20._1_1_;
        bVar2 = *(char *)(param_1 + 0x19) + 5;
        *(byte *)(param_1 + 0x19) = bVar2;
        if (0x2d < bVar2) {
          FUN_00000a7c(param_1,param_2);
        }
        if (0x1e < uVar4) {
          *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + 1;
LAB_00001ce6:
          FUN_00005368(DAT_00001d34);
          return;
        }
        if (uVar4 - 2 < 0x1f) goto LAB_00001ce6;
        goto LAB_00001c68;
      }
    }
  }
  *(undefined *)(iVar3 + 4) = 0xff;
  *(undefined *)(iVar3 + 3) = 0xff;
  *(undefined *)(iVar3 + 2) = 0xff;
  *(undefined *)(iVar3 + 1) = 0xff;
  *(undefined *)(param_1 + uVar1 + 0x1a) = 0xff;
  bVar2 = *(char *)(param_1 + 0x19) + 5;
  *(byte *)(param_1 + 0x19) = bVar2;
  if (0x2d < bVar2) {
    FUN_00000a7c(param_1,param_2);
  }
LAB_00001c68:
  if ((int)((uint)*(byte *)(param_1 + 0x18) << 0x1e) < 0) {
    FUN_00005378(param_1);
    *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) & 0xfb;
    disableIRQinterrupts();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + *(int *)(DAT_00001d38 + 4);
    FUN_000053c8(param_1);
    enableIRQinterrupts();
    return;
  }
  return;
}




void FUN_00001d3c(undefined *param_1)

{
  undefined uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 local_24;
  
  uVar1 = *param_1;
  iVar2 = FUN_0000306c(uVar1,DAT_00001e00);
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00005378();
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined2 *)(iVar2 + 0x18) = 1;
    FUN_000053c8(iVar2);
    return;
  }
  FUN_00005378();
  iVar4 = DAT_00001e04;
  *(undefined *)(iVar2 + 0x18) = 0;
  local_24 = 0x2d;
  iVar5 = *(int *)(iVar4 + 4);
  FUN_00001a98(*(undefined4 *)(iVar2 + 0x10),0,2,&local_24);
  iVar6 = *(int *)(iVar4 + 4);
  iVar4 = 0x21;
  do {
    while( true ) {
      local_24 = 0xb9;
      FUN_00001a98(*(undefined4 *)(iVar2 + 0x10),1,2,&local_24);
      if ((local_24 & 0x7f00) == 0) goto LAB_00001dca;
      if (0x20 < (local_24._1_1_ & 0x7f)) break;
      FUN_00001c10(iVar2,uVar1);
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) goto LAB_00001dca;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
LAB_00001dca:
  cVar3 = *(char *)(iVar2 + 0x19);
  if (cVar3 != '\0') {
    FUN_00000a7c(iVar2,uVar1);
    cVar3 = *(char *)(iVar2 + 0x19);
  }
  FUN_000036b4(DAT_00001e08,uVar1,iVar5,iVar6 - iVar5,*(undefined2 *)(iVar2 + 0x14),cVar3,
               local_24._1_1_,*(undefined2 *)(iVar2 + 0x16));
  return;
}




void FUN_00001e0c(undefined *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0000306c(*param_1,DAT_00001e28);
  FUN_00001a98(uVar1,0,param_1[4],*(undefined4 *)(param_1 + 8));
  return;
}




void FUN_00001e60(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00001e70;
  FUN_00005378(DAT_00001e70 + 1);
  *puVar1 = 0;
  return;
}




undefined8 * FUN_00002134(int param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  undefined8 *puVar14;
  int *piVar15;
  undefined8 *puVar16;
  int *piVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  
  piVar15 = DAT_0000241c;
  FUN_00006574(DAT_00002418,0,0x80);
  FUN_00006574(DAT_00002420,0,0x100);
  piVar9 = piVar15 + 1;
  uVar8 = *(uint *)(DAT_00002424 + param_1 * 0x84 + 0xc4);
  piVar17 = piVar15 + 0x20;
  piVar12 = piVar15;
  do {
    uVar10 = uVar8 & 0x1f;
    if ((int)uVar8 < 1) {
      uVar10 = -(-uVar8 & 0x1f);
    }
    uVar8 = uVar8 + 1;
    piVar12 = piVar12 + 1;
    *piVar12 = *(int *)(DAT_00002424 + (uVar10 + param_1 * 0x21) * 4 + 200);
    piVar3 = DAT_00002428;
  } while (piVar12 != piVar17);
  iVar4 = *piVar9;
  if (piVar15[0x20] < iVar4) {
    sVar1 = *(short *)(DAT_00002424 + 0x1a);
    piVar11 = DAT_00002428 + -0x20;
    while( true ) {
      if (sVar1 == 0) {
        *piVar11 = -iVar4;
        puVar6 = DAT_00002438;
        piVar12 = DAT_0000243c;
      }
      else {
        *piVar11 = 0x1000 - iVar4;
        puVar6 = DAT_00002438;
        piVar12 = DAT_0000243c;
      }
      piVar11 = piVar11 + 1;
      if (piVar11 == piVar3) break;
      iVar4 = *piVar11;
      DAT_00002438 = puVar6;
      DAT_0000243c = piVar12;
    }
    iVar4 = *piVar9;
  }
  else {
    sVar1 = *(short *)(DAT_00002424 + 0x1a);
    puVar6 = DAT_00002438;
    piVar12 = DAT_0000243c;
  }
  DAT_00002438 = puVar6;
  DAT_0000243c = piVar12;
  if (sVar1 == 0) {
    if (param_2 == 0) {
      piVar12 = DAT_0000242c + -0x1e;
      while( true ) {
        uVar18 = FUN_000056fc(iVar4);
        uVar19 = FUN_000056fc(piVar12[1]);
        uVar8 = (uint)((ulonglong)uVar18 >> 0x20) & 0x7fffffff;
        uVar10 = (uint)((ulonglong)uVar19 >> 0x20) & 0x7fffffff;
        iVar4 = FUN_00005cb4((int)uVar18,uVar8,(int)uVar19,uVar10);
        if (iVar4 == 0) {
          uVar8 = uVar10;
          uVar18 = uVar19;
        }
        iVar13 = piVar12[2];
        uVar19 = FUN_000056fc(iVar13);
        iVar4 = FUN_00005cf0((int)uVar19,(uint)((ulonglong)uVar19 >> 0x20) & 0x7fffffff,(int)uVar18,
                             uVar8);
        if (iVar4 != 0) {
          iVar13 = FUN_00005d04((int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
        }
        piVar15 = piVar12 + 1;
        *piVar12 = iVar13;
        iVar4 = DAT_00002424;
        puVar6 = DAT_00002420;
        if (piVar15 == DAT_0000242c) break;
        iVar4 = *piVar15;
        piVar12 = piVar15;
      }
      FUN_00006118(DAT_00002430,*(undefined4 *)(DAT_00002424 + 0x2f0));
      uVar18 = FUN_00005720();
      uVar7 = (undefined4)((ulonglong)uVar18 >> 0x20);
      uVar5 = FUN_00005f08(*(undefined2 *)(iVar4 + 0x2ee));
      uVar5 = FUN_00006118(DAT_00002434,uVar5);
      FUN_00006118(0x3f800000,uVar5);
      uVar19 = FUN_00005720();
      uVar19 = FUN_00005464((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar7);
      uVar19 = FUN_00005a24((int)uVar18,uVar7,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      uVar18 = 0;
      puVar14 = puVar6;
      do {
        uVar20 = FUN_000056fc(piVar9[1] - *piVar9);
        uVar18 = FUN_00005464((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar18,
                              (int)((ulonglong)uVar18 >> 0x20));
        uVar18 = FUN_000057d0((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                              (int)((ulonglong)uVar19 >> 0x20));
        piVar9 = piVar9 + 1;
        puVar14 = puVar14 + 1;
        *puVar14 = uVar18;
        puVar16 = DAT_00002440;
      } while (piVar9 != piVar17);
      uVar5 = *(undefined4 *)(DAT_00002424 + 0x2f4);
      uVar19 = FUN_00005720(uVar5);
      FUN_00005d9c(0x3f800000,uVar5);
      uVar20 = FUN_00005720();
      uVar18 = 0;
      do {
        puVar14 = puVar6 + 1;
        uVar21 = FUN_000057d0((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),*(undefined4 *)puVar14,
                              *(undefined4 *)((int)puVar6 + 0xc));
        uVar18 = FUN_000057d0((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar18,
                              (int)((ulonglong)uVar18 >> 0x20));
        uVar18 = FUN_00005464((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar18,
                              (int)((ulonglong)uVar18 >> 0x20));
        *puVar14 = uVar18;
        puVar6 = puVar14;
      } while (puVar16 != puVar14);
      return DAT_00002420;
    }
    piVar9 = (int *)(DAT_00002424 + param_1 * 0x84 + 0xc4);
    while( true ) {
      piVar9 = piVar9 + 1;
      *piVar9 = iVar4;
      if (piVar12 == piVar12 + 0x1f) break;
      iVar4 = *piVar12;
      piVar12 = piVar12 + 1;
    }
    uVar2 = *(ushort *)(DAT_00002424 + 0x18);
    *(undefined4 *)(DAT_00002424 + param_1 * 0x84 + 0xc4) = 0;
    if (uVar2 - 1 == param_1) {
      uVar8 = *(uint *)(DAT_000024e0 + 0x40);
      *(uint *)(DAT_000024e0 + 0x304) = uVar8;
      piVar12 = piVar15;
      do {
        iVar4 = DAT_000024e0;
        uVar10 = uVar8 & 0x1f;
        if ((int)uVar8 < 1) {
          uVar10 = -(-uVar8 & 0x1f);
        }
        uVar8 = uVar8 + 1;
        piVar12 = piVar12 + 1;
        *piVar12 = *(int *)(DAT_000024e0 + uVar10 * 4 + 0x44);
      } while (piVar12 != piVar17);
      piVar12 = (int *)(iVar4 + 0x40);
      do {
        piVar15 = piVar15 + 1;
        piVar12 = piVar12 + 1;
        *piVar12 = *piVar15;
      } while (piVar15 != piVar17);
      puVar6 = DAT_000024e4;
      *(undefined4 *)(DAT_000024e0 + 0x40) = 0;
      return puVar6;
    }
  }
  else {
    if (param_2 == 0) {
      puVar14 = puVar6 + 1;
      puVar16 = puVar6 + 0x20;
      while( true ) {
        uVar18 = FUN_000056fc(iVar4);
        puVar6 = puVar6 + 1;
        *puVar6 = uVar18;
        if (puVar16 == puVar6) break;
        piVar9 = piVar9 + 1;
        iVar4 = *piVar9;
      }
      uVar5 = *(undefined4 *)(DAT_00002424 + 0x2f4);
      uVar18 = FUN_00005720(uVar5);
      FUN_00005d9c(0x3f800000,uVar5);
      uVar19 = FUN_00005720();
      do {
        uVar20 = FUN_000057d0((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),
                              *(undefined4 *)(puVar14 + 1),*(undefined4 *)((int)puVar14 + 0xc));
        uVar21 = FUN_000057d0((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),*(undefined4 *)puVar14,
                              *(undefined4 *)((int)puVar14 + 4));
        uVar20 = FUN_00005464((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar21,
                              (int)((ulonglong)uVar21 >> 0x20));
        puVar14 = puVar14 + 1;
        *puVar14 = uVar20;
      } while (puVar16 != puVar14);
      return DAT_00002420;
    }
    iVar13 = DAT_00002424 + param_1 * 0x84;
    piVar9 = (int *)(iVar13 + 0xc4);
    *(undefined4 *)(iVar13 + 0xc4) = 0;
    while( true ) {
      piVar9 = piVar9 + 1;
      *piVar9 = iVar4;
      if (piVar12 + 0x1f == piVar12) break;
      iVar4 = *piVar12;
      piVar12 = piVar12 + 1;
    }
    if (*(ushort *)(DAT_000024e0 + 0x18) - 1 == param_1) {
      uVar8 = *(uint *)(DAT_000024e0 + 0x40);
      piVar12 = piVar15;
      do {
        iVar4 = DAT_000024e0;
        uVar10 = uVar8 & 0x1f;
        if ((int)uVar8 < 1) {
          uVar10 = -(-uVar8 & 0x1f);
        }
        uVar8 = uVar8 + 1;
        piVar12 = piVar12 + 1;
        *piVar12 = *(int *)(DAT_000024e0 + uVar10 * 4 + 0x44);
      } while (piVar12 != piVar17);
      piVar12 = (int *)(iVar4 + 0x40);
      *(undefined4 *)(iVar4 + 0x40) = 0;
      do {
        piVar15 = piVar15 + 1;
        piVar12 = piVar12 + 1;
        *piVar12 = *piVar15;
      } while (piVar15 != piVar17);
    }
  }
  return DAT_00002420;
}




undefined4 FUN_000024e8(uint *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined8 uVar16;
  uint *local_2c;
  
  iVar15 = DAT_000026f0;
  iVar3 = DAT_000026e0;
  uVar2 = DAT_000026dc;
  uVar9 = DAT_000026d8;
  if (*(short *)(DAT_000026e0 + 0x1a) == 0) {
    puVar14 = DAT_000026f4;
    if (*(short *)(DAT_000026e0 + 0x18) != 0) {
      iVar4 = 0;
      uVar12 = 0;
      do {
        uVar16 = FUN_00000cac(*(undefined *)(iVar3 + iVar4 + 0x3c));
        puVar14 = DAT_000026f4;
        iVar15 = DAT_000026f0;
        uVar5 = (uint)((ulonglong)uVar16 >> 0x20);
        uVar1 = *(ushort *)(iVar3 + 0x18);
        iVar4 = uVar5 + 1;
        uVar12 = uVar12 | (int)uVar16 << (uVar5 & 0xff);
      } while (iVar4 < (int)(uint)uVar1);
      if (uVar12 != 0) {
        uVar16 = FUN_00005460(*(undefined4 *)(DAT_000026f0 + 0x10),
                              *(undefined4 *)(DAT_000026f0 + 0x14),*DAT_000026f4,DAT_000026f4[1]);
        iVar4 = FUN_00005cdc((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_000026d0,DAT_000026d4)
        ;
        if (iVar4 == 0) {
          return 0;
        }
      }
      if (uVar1 != 0) {
        iVar4 = 0;
        do {
          FUN_00000dfc(*(undefined4 *)(iVar3 + iVar4 * 4 + 0x2c),0);
          uVar12 = (uint)*(ushort *)(iVar3 + 0x18);
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)uVar12);
        iVar4 = 0x18;
        do {
          if (uVar12 == 0) goto LAB_000026c4;
          iVar10 = 0;
          do {
            FUN_00000dfc(*(undefined4 *)(iVar3 + iVar10 * 4 + 0x2c),1);
            uVar12 = (uint)*(ushort *)(iVar3 + 0x18);
            iVar10 = iVar10 + 1;
          } while (iVar10 < (int)uVar12);
          if (uVar12 == 0) goto LAB_000026c4;
          puVar8 = param_1;
          do {
            puVar7 = puVar8 + 1;
            *puVar8 = *puVar8 << 1;
            puVar8 = puVar7;
          } while (param_1 + uVar12 != puVar7);
          iVar10 = 0;
          do {
            FUN_00000dfc(*(undefined4 *)(iVar3 + iVar10 * 4 + 0x2c),0);
            uVar12 = (uint)*(ushort *)(iVar3 + 0x18);
            iVar10 = iVar10 + 1;
          } while (iVar10 < (int)uVar12);
          if (uVar12 != 0) {
            puVar8 = param_1 + -1;
            iVar10 = 0;
            do {
              uVar16 = FUN_00000cac(*(undefined *)(iVar3 + iVar10 + 0x3c),iVar10 + 1);
              iVar10 = (int)((ulonglong)uVar16 >> 0x20);
              puVar8 = puVar8 + 1;
              uVar5 = *puVar8;
              uVar12 = (uint)*(ushort *)(iVar3 + 0x18);
              if ((int)uVar16 != 0) {
                uVar5 = uVar5 + 1;
              }
              *puVar8 = uVar5;
            } while (iVar10 < (int)uVar12);
          }
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar4 = 0;
        if (uVar12 != 0) {
          do {
            FUN_00000dfc(*(undefined4 *)(iVar3 + iVar4 * 4 + 0x2c),1);
            uVar12 = (uint)*(ushort *)(iVar3 + 0x18);
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)uVar12);
          if (uVar12 != 0) {
            puVar8 = param_1;
            do {
              puVar7 = puVar8 + 1;
              uVar5 = *puVar8;
              if ((int)(uVar5 << 8) < 0) {
                uVar5 = uVar5 | 0xff000000;
              }
              *puVar8 = uVar5;
              puVar8 = puVar7;
            } while (puVar7 != param_1 + uVar12);
            iVar4 = 0;
            do {
              FUN_00000dfc(*(undefined4 *)(iVar3 + iVar4 * 4 + 0x2c),0);
              uVar12 = (uint)*(ushort *)(iVar3 + 0x18);
              iVar4 = iVar4 + 1;
            } while (iVar4 < (int)uVar12);
            uVar9 = *(undefined4 *)(iVar15 + 0x14);
            *puVar14 = *(undefined4 *)(iVar15 + 0x10);
            puVar14[1] = uVar9;
            if (uVar12 == 0) {
              return 1;
            }
            piVar6 = DAT_000026e4;
            puVar8 = param_1;
            do {
              puVar7 = puVar8 + 1;
              *puVar8 = *puVar8 - *piVar6;
              piVar6 = piVar6 + 1;
              puVar8 = puVar7;
            } while (puVar7 != param_1 + uVar12);
            return 1;
          }
        }
      }
    }
LAB_000026c4:
    uVar9 = *(undefined4 *)(iVar15 + 0x14);
    *puVar14 = *(undefined4 *)(iVar15 + 0x10);
    puVar14[1] = uVar9;
  }
  else if (*(short *)(DAT_000026e0 + 0x18) != 0) {
    local_2c = param_1 + -1;
    iVar4 = 0;
    do {
      uVar11 = *(undefined4 *)(iVar15 + 0x10);
      uVar13 = *(undefined4 *)(iVar15 + 0x14);
      do {
        iVar10 = FUN_000002b0(*(undefined4 *)(iVar3 + (iVar4 + 6) * 4 + 4));
        if (iVar10 == 0) break;
        uVar16 = FUN_00005460(*(undefined4 *)(iVar15 + 0x10),*(undefined4 *)(iVar15 + 0x14),uVar11,
                              uVar13);
        iVar10 = FUN_00005cb4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar2);
      } while (iVar10 != 0);
      puVar8 = DAT_000026e8;
      uVar1 = *(ushort *)(iVar3 + 0x18);
      *DAT_000026e8 = *DAT_000026e8 & 0xfffffffd;
      *puVar8 = *puVar8 & 0xffffffef;
      local_2c = local_2c + 1;
      *local_2c = *DAT_000026ec & 0xffff;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)uVar1);
  }
  return 1;
}




void FUN_000026f8(int param_1)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  undefined2 *puVar9;
  uint uVar10;
  uint *puVar11;
  int *piVar12;
  uint *puVar13;
  int *piVar14;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  undefined4 *puVar20;
  undefined4 local_38 [5];
  int *piVar15;
  
  piVar3 = DAT_00002880;
  FUN_000038d4();
  if (*piVar3 == 0) {
    FUN_0000082c();
  }
  puVar4 = DAT_00002884;
  sVar1 = DAT_00002884[0xd];
  *(undefined4 *)(DAT_00002884 + 0x188) = 0;
  *(undefined4 *)(puVar4 + 0x18a) = 0;
  *(undefined4 *)(puVar4 + 0x18c) = 0;
  *(undefined4 *)(puVar4 + 0x186) = 0;
  if ((sVar1 == 0) && (iVar16 = *(int *)(param_1 + 4), iVar16 != 0)) {
    if (puVar4[0xc] != 0) {
      puVar9 = puVar4 + 100;
      iVar16 = 0;
      do {
        *(undefined4 *)(puVar9 + -2) = 0;
        iVar5 = FUN_00006574(puVar9,0,0x80);
        iVar16 = iVar16 + 1;
        puVar9 = (undefined2 *)(iVar5 + 0x84);
      } while (iVar16 < (int)(uint)(ushort)puVar4[0xc]);
      iVar16 = *(int *)(param_1 + 4);
    }
    if (0x1f < iVar16) {
      iVar16 = 0x20;
    }
    iVar5 = 0;
    if (iVar16 < 8) {
      iVar16 = 8;
    }
    do {
      local_38[0] = 0;
      local_38[1] = 0;
      local_38[2] = 0;
      local_38[3] = 0;
      do {
        iVar6 = FUN_000024e8(local_38);
      } while (iVar6 == 0);
      uVar18 = (uint)(ushort)puVar4[0xc];
      if (uVar18 != 0) {
        iVar6 = 0;
        puVar9 = DAT_00002884;
        puVar20 = local_38;
        do {
          uVar10 = *(uint *)(puVar9 + 0x62);
          uVar17 = uVar10 & 0x1f;
          if ((int)uVar10 < 1) {
            uVar17 = -(-uVar10 & 0x1f);
          }
          iVar2 = iVar6 * 0x21;
          iVar6 = iVar6 + 1;
          *(undefined4 *)(puVar4 + (iVar2 + uVar17) * 2 + 100) = *puVar20;
          *(uint *)(puVar9 + 0x62) = uVar10 + 1;
          puVar9 = puVar9 + 0x42;
          puVar20 = puVar20 + 1;
        } while (iVar6 < (int)uVar18);
      }
      iVar5 = iVar5 + 1;
    } while (iVar16 != iVar5);
    if (uVar18 != 0) {
      puVar13 = (uint *)(DAT_00002888 + iVar16 * 4);
      iVar5 = 0;
      do {
        puVar7 = puVar13 + -iVar16;
        iVar6 = 0;
        do {
          puVar11 = puVar7;
          if (iVar6 < iVar16) {
            do {
              puVar11 = puVar11 + 1;
              uVar17 = puVar7[1];
              if (*puVar11 < uVar17) {
                puVar7[1] = *puVar11;
                *puVar11 = uVar17;
              }
            } while (puVar11 != puVar13);
          }
          iVar6 = iVar6 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar16 != iVar6);
        iVar5 = iVar5 + 0x21;
        puVar13 = puVar13 + 0x21;
      } while (iVar5 != uVar18 * 0x21);
      piVar19 = DAT_0000288c + uVar18;
      piVar8 = DAT_0000288c + iVar16 + -0x94;
      piVar14 = DAT_0000288c;
      do {
        piVar15 = piVar14 + 1;
        iVar5 = *piVar14;
        piVar12 = piVar8 + (4 - iVar16);
        do {
          piVar12 = piVar12 + 1;
          iVar5 = iVar5 + *piVar12;
        } while (piVar12 != piVar8);
        piVar8 = piVar8 + 0x21;
        *piVar14 = iVar5 / (iVar16 + -4);
        piVar14 = piVar15;
      } while (piVar19 != piVar15);
    }
  }
  if (*piVar3 == 1) {
    FUN_00001e60();
  }
  FUN_000036b4(DAT_00002890,*puVar4,*(undefined4 *)(puVar4 + 0x186),*(undefined4 *)(puVar4 + 0x188),
               *(undefined4 *)(puVar4 + 0x18a),*(undefined4 *)(puVar4 + 0x18c));
  return;
}




undefined4 FUN_00002894(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar1 = DAT_000028c8;
  uVar3 = *(undefined4 *)(DAT_000028c8 + 0x18);
  iVar4 = *(int *)(DAT_000028cc + 4);
  FUN_00005fb0(uVar3,DAT_000028d0);
  iVar2 = FUN_00006250();
  *(int *)(iVar1 + 0xc) = iVar4 + iVar2;
  uVar5 = FUN_00005720(uVar3);
  uVar5 = FUN_00005464(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),(int)uVar5,
                       (int)((ulonglong)uVar5 >> 0x20));
  *(undefined8 *)(iVar1 + 0x10) = uVar5;
  return 1;
}




int FUN_00002914(byte *param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  
  bVar2 = *param_1 + 1;
  piVar1 = (int *)(*DAT_0000294c + (uint)bVar2 * 8);
  while( true ) {
    if (*DAT_00002950 <= bVar2) {
      return 0;
    }
    if (*piVar1 == param_2) break;
    bVar2 = bVar2 + 1;
    piVar1 = piVar1 + 2;
  }
  *param_1 = bVar2;
  return piVar1[1];
}




void FUN_00002954(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_00002970;
  piVar1 = DAT_0000296c;
  iVar3 = *DAT_0000296c;
  *param_1 = *DAT_00002970;
  *puVar2 = param_1;
  *piVar1 = iVar3 + -1;
  return;
}




void FUN_0000297c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_00005378();
  FUN_00005378(param_1 + 0xc);
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar2;
  }
  *(undefined2 *)(param_1 + 0x20) = 0;
  *(undefined *)(param_1 + 0x22) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}




undefined4 FUN_000029ac(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_00000f00(*(undefined4 *)(param_1 + 0x18));
  uVar2 = *(byte *)(param_1 + 0x2c) ^ 1;
  if ((int)(uVar2 << 0x1f) < 0) {
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  *(char *)(param_1 + 0x2c) = (char)uVar2;
  iVar1 = *(int *)(param_1 + 8) + iVar1;
  if (((int)(uVar2 << 0x1d) < 0) && (-1 < iVar1 - *(int *)(param_1 + 0x14))) {
    *(undefined4 *)(param_1 + 4) = DAT_000029ec;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 0x14);
    return 1;
  }
  *(int *)(param_1 + 8) = iVar1;
  return 1;
}




void FUN_000029f0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  FUN_00005378(param_1 + -0x34);
  *(undefined4 *)(param_1 + -0x2c) = 0;
  *(undefined4 *)(param_1 + -0x1c) = 0;
  uVar1 = *(uint *)(param_1 + -0x20);
  if (-1 < (int)((uint)*(byte *)(param_1 + 8) << 0x1b)) {
    uVar1 = uVar1 >> 1;
  }
  iVar2 = *(int *)(param_1 + -0xc) - uVar1;
  if (0 < iVar2) {
    iVar2 = -iVar2;
  }
  *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) & 0x14 | 8;
  *(undefined4 *)(param_1 + -0x20) = 0;
  *(int *)(param_1 + -0xc) = iVar2;
  FUN_00000dfc(*(undefined4 *)(param_1 + -0x10));
  if (-1 < (int)((uint)*(byte *)(param_1 + 8) << 0x1b)) {
    FUN_00000dfc(*(undefined4 *)(param_1 + -0x14),*(byte *)(param_1 + 8) & 4);
  }
  while (*(undefined4 **)(param_1 + -8) != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + -8) = **(undefined4 **)(param_1 + -8);
    FUN_00002954();
  }
  return;
}




void FUN_00002a64(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  while (puVar1 != (undefined4 *)0x0) {
    pcVar2 = (code *)puVar1[1];
    *(undefined4 *)(param_1 + 0x1c) = *puVar1;
    *puVar1 = 0;
    puVar1[1] = 0;
    (*pcVar2)(puVar1,param_2);
    puVar1 = *(undefined4 **)(param_1 + 0x1c);
  }
  FUN_00005368(DAT_00002a90);
  return;
}




void FUN_00002bbc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  
  iVar2 = DAT_00002c0c;
  if (*(short *)(DAT_00002c0c + 0x20) != 0) {
    puVar6 = (undefined2 *)(DAT_00002c0c + 0x22);
    iVar5 = 0;
    do {
      if (param_2 == 1) {
        uVar3 = FUN_00000cac(*(undefined *)(iVar2 + iVar5 + 0x5c));
        *puVar6 = uVar3;
        uVar4 = (uint)(ushort)puVar6[4] - param_1;
        if (uVar4 != 0) {
          uVar4 = 1;
        }
      }
      else {
        uVar4 = (uint)*(byte *)puVar6;
      }
      iVar1 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      FUN_00000dfc(*(undefined4 *)(iVar2 + iVar1 + 0x3c),uVar4);
      puVar6 = puVar6 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(iVar2 + 0x20));
  }
  return;
}




undefined4 FUN_00002c10(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  iVar2 = DAT_00002e30;
  if (*(short *)(DAT_00002e30 + 0x20) != 0) {
    iVar7 = 0;
    do {
      iVar5 = iVar7 * 4;
      iVar7 = iVar7 + 1;
      FUN_00000f00(*(undefined4 *)(iVar2 + iVar5 + 0x4c));
    } while (iVar7 < (int)(uint)*(ushort *)(iVar2 + 0x20));
  }
  iVar7 = *(int *)(iVar2 + 0x178) + -1;
  *(int *)(iVar2 + 0x178) = iVar7;
  if (*(int *)(iVar2 + 0x60) == 0) {
    iVar7 = FUN_00000cac(*(undefined *)(DAT_00002e48 + 4));
    if (iVar7 == 1) {
      FUN_000057d0(*(undefined4 *)(DAT_00002e34 + 0x10),*(undefined4 *)(DAT_00002e34 + 0x14),
                   DAT_00002e28,DAT_00002e2c);
      uVar3 = FUN_00005d54();
      iVar7 = *(int *)(iVar2 + 0x178);
      *(undefined4 *)(iVar2 + 0x60) = uVar3;
    }
    else {
      iVar7 = *(int *)(iVar2 + 0x178);
    }
  }
  if (iVar7 == 0) {
LAB_00002c50:
    uVar8 = *(uint *)(iVar2 + 0xec);
    uVar9 = uVar8 & 0x1f;
    if ((int)uVar8 < 1) {
      uVar9 = -(-uVar8 & 0x1f);
    }
    FUN_000057d0(*(undefined4 *)(DAT_00002e34 + 0x10),*(undefined4 *)(DAT_00002e34 + 0x14),
                 DAT_00002e28,DAT_00002e2c);
    uVar3 = FUN_00005d54();
    *(undefined4 *)(iVar2 + uVar9 * 4 + 0xf0) = uVar3;
    uVar6 = *(uint *)(iVar2 + 0x68);
    sVar1 = *(short *)(iVar2 + 0x188);
    *(uint *)(iVar2 + 0xec) = uVar8 + 1;
    uVar9 = uVar6 & 0x1f;
    if ((int)uVar6 < 1) {
      uVar9 = -(-uVar6 & 0x1f);
    }
    *(int *)(iVar2 + uVar9 * 4 + 0x6c) = *(int *)(iVar2 + 0x178) / 2;
    *(uint *)(iVar2 + 0x68) = uVar6 + 1;
    if (sVar1 != 1) {
      FUN_00005378(DAT_00002e44);
      FUN_00002bbc(0);
      *(undefined2 *)(iVar2 + 100) = 8;
      *(undefined2 *)(iVar2 + 0x172) = 0;
      *(undefined4 *)(iVar2 + 0x178) = 0;
      return 1;
    }
    *(undefined4 *)(iVar2 + 0x178) = *(undefined4 *)(iVar2 + 0x174);
    *(undefined2 *)(iVar2 + 0x188) = 0;
    FUN_00002bbc(0);
    FUN_00002bbc(*(short *)(iVar2 + 0x170) == 0,1);
    iVar7 = *(int *)(iVar2 + 0x178);
LAB_00002cdc:
    iVar4 = *(int *)(iVar2 + 0x180);
    iVar5 = *(int *)(iVar2 + 0x174) - iVar7;
    if (iVar5 < iVar4) goto LAB_00002cf4;
  }
  else {
    if (-1 < iVar7 << 0x1f) {
      if ((*(short *)(iVar2 + 0x172) == 1) ||
         (iVar7 = FUN_00000cac(*(undefined *)(DAT_00002e48 + 4)), iVar7 == 1)) goto LAB_00002c50;
      iVar7 = *(int *)(iVar2 + 0x178);
    }
    iVar5 = (uint)*(ushort *)(iVar2 + 0x186) * 2;
    if (iVar7 != iVar5 * (iVar7 / iVar5)) goto LAB_00002cdc;
    uVar8 = *(uint *)(iVar2 + 0xec);
    uVar9 = uVar8 & 0x1f;
    if ((int)uVar8 < 1) {
      uVar9 = -(-uVar8 & 0x1f);
    }
    FUN_000057d0(*(undefined4 *)(DAT_00002e34 + 0x10),*(undefined4 *)(DAT_00002e34 + 0x14),
                 DAT_00002e28,DAT_00002e2c);
    uVar3 = FUN_00005d54();
    *(undefined4 *)(iVar2 + uVar9 * 4 + 0xf0) = uVar3;
    uVar6 = *(uint *)(iVar2 + 0x68);
    *(uint *)(iVar2 + 0xec) = uVar8 + 1;
    uVar9 = uVar6 & 0x1f;
    if ((int)uVar6 < 1) {
      uVar9 = -(-uVar6 & 0x1f);
    }
    *(int *)(iVar2 + uVar9 * 4 + 0x6c) = *(int *)(iVar2 + 0x178) / 2;
    *(uint *)(iVar2 + 0x68) = uVar6 + 1;
    iVar7 = *(int *)(iVar2 + 0x178);
    iVar4 = *(int *)(iVar2 + 0x180);
    iVar5 = *(int *)(iVar2 + 0x174) - iVar7;
    if (iVar5 < iVar4) goto LAB_00002cf4;
  }
  iVar5 = iVar7;
  if (iVar4 <= iVar7) {
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0x17c) + *(int *)(DAT_00002e38 + 4);
    return 1;
  }
LAB_00002cf4:
  iVar5 = 0x100 - (iVar5 << 8) / iVar4;
  iVar7 = UnsignedSaturate(iVar5,8);
  UnsignedDoesSaturate(iVar5,8);
  iVar7 = (uint)*(ushort *)(DAT_00002e3c + iVar7 * 2) *
          *(int *)(iVar2 + 0x17c) * (uint)*(ushort *)(iVar2 + 0x184);
  *(int *)(iVar2 + 0xc) =
       ((int)((longlong)DAT_00002e40 * (longlong)iVar7 >> 0x26) - (iVar7 >> 0x1f)) +
       *(int *)(iVar2 + 0x17c) + *(int *)(DAT_00002e38 + 4);
  return 1;
}




undefined4 FUN_00002e4c(int param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x2c);
  if (puVar5 != (undefined4 *)0x0) {
    sVar2 = *(short *)(puVar5 + 2);
    iVar4 = puVar5[1];
    *(undefined4 *)(param_1 + 0x2c) = *puVar5;
    *(short *)(param_1 + 0x10) = sVar2;
    *(int *)(param_1 + 0xc) = sVar2 + iVar4;
    if ((int)((uint)*(byte *)(param_1 + 0x3c) << 0x1b) < 0) {
      uVar3 = (uint)*(ushort *)((int)puVar5 + 10);
      *(uint *)(param_1 + 0x14) = uVar3;
      *(int *)(param_1 + 8) = iVar4 + *(int *)(param_1 + 8);
      bVar1 = *(byte *)(puVar5 + 3);
      iVar4 = *(int *)(param_1 + 0x28);
    }
    else {
      uVar3 = (uint)*(ushort *)((int)puVar5 + 10);
      iVar4 = iVar4 + *(int *)(param_1 + 0x18);
      *(int *)(param_1 + 0x18) = iVar4;
      *(int *)(param_1 + 8) = iVar4;
      *(uint *)(param_1 + 0x14) = uVar3 << 1;
      bVar1 = *(byte *)(puVar5 + 3);
      iVar4 = *(int *)(param_1 + 0x28);
    }
    if ((bVar1 & 1) == 0) {
      *(uint *)(param_1 + 0x28) = uVar3 + iVar4;
    }
    else {
      *(uint *)(param_1 + 0x28) = uVar3 - iVar4;
      FUN_00000f00(*(undefined4 *)(param_1 + 0x24));
    }
    FUN_00002954(puVar5);
    return 1;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return 0;
}




void FUN_00002eb8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  code *UNRECOVERED_JUMPTABLE_00;
  
  disableIRQinterrupts();
  UNRECOVERED_JUMPTABLE_00 = (code *)0x2ec5;
  FUN_00006620(uRam00002ec4,param_1,param_3,param_4,param_4);
  FUN_00000f00(Reserved2);
  BusFault = BusFault + -1;
  puVar2 = Reserved1 + *(int *)(DAT_00002f24 + 4);
  if (-1 < (int)BusFault * -0x80000000) {
    if (BusFault == (undefined *)0x0) {
      iVar1 = FUN_00002e4c(0);
      if ((iVar1 == 0) || (-1 < (int)NMI - (int)puVar2)) goto LAB_00002ee8;
      if ((int)NMI - (int)puVar2 < DAT_00002f28) {
                    /* WARNING: Subroutine does not return */
        FUN_00002eb8(0x19);
      }
    }
    else {
      NMI = UsageFault + (int)HardFault;
      HardFault = HardFault + (short)MemManage;
      UsageFault = NMI;
      if (-1 < (int)NMI - (int)puVar2) {
                    /* WARNING: Could not recover jumptable at 0x00002f06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1,(int)NMI - (int)puVar2,HardFault,param_4);
        return;
      }
    }
  }
  iVar1 = 1;
  NMI = puVar2;
LAB_00002ee8:
                    /* WARNING: Could not recover jumptable at 0x00002ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(iVar1);
  return;
}




undefined4 FUN_0000306c(uint param_1,int param_2)

{
  if (param_1 < *DAT_00003090) {
    if (*(int *)(*DAT_00003094 + param_1 * 8) == param_2) {
      return *(undefined4 *)(*DAT_00003094 + param_1 * 8 + 4);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0xb);
}




void FUN_00003098(undefined *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0000306c(*param_1,DAT_000030cc);
  disableIRQinterrupts();
  if (-1 < (int)((uint)*(byte *)(iVar1 + 0x20) << 0x1f)) {
    enableIRQinterrupts();
    return;
  }
  FUN_00005378(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 4);
  FUN_000053c8(iVar1 + 0xc);
  enableIRQinterrupts();
  return;
}




int FUN_00003480(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_000034ac;
  if ((uint)(iVar2 + param_1) <= DAT_000034b0) {
    iVar1 = (param_1 + 3U & 0xfffffffc) + iVar2;
    *DAT_000034ac = iVar1;
    FUN_00006574(iVar2,0,param_1,iVar1,param_4);
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0x10);
}




void FUN_000034dc(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < *DAT_00003514) {
    iVar2 = *DAT_00003518;
    if ((*(int *)(iVar2 + (short)param_1 * 8) == 0) && (*DAT_0000351c == 0)) {
      *(undefined4 *)(iVar2 + (short)param_1 * 8) = param_2;
      uVar1 = FUN_00003480(param_3);
      *(undefined4 *)(iVar2 + param_1 * 8 + 4) = uVar1;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(10);
}




void FUN_000036b4(undefined *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  byte bVar2;
  uint *puVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte bVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte **ppbVar14;
  byte *pbVar15;
  uint uVar16;
  byte *pbVar17;
  byte *pbVar18;
  int iVar19;
  int local_48;
  byte *pbStack_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pbVar12 = DAT_000038cc;
  pcVar4 = DAT_000038c8;
  uStack_4 = param_4;
  local_8 = param_3;
  pbStack_c = param_2;
  if (*DAT_000038c8 != '\0') {
    return;
  }
  *DAT_000038c8 = '\x01';
  pbVar5 = DAT_000038d0;
  ppbVar14 = &pbStack_c;
  uVar8 = (uint)*pbVar12;
  uVar16 = (uint)*DAT_000038d0;
  if (uVar16 <= uVar8) {
    *DAT_000038d0 = 0;
    *pbVar12 = 0;
    uVar8 = 0;
    uVar16 = 0;
  }
  pbVar15 = (byte *)(uint)(byte)param_1[1];
  if (pbVar15 + uVar16 < (byte *)0x61) {
    local_48 = DAT_000038bc;
  }
  else {
    if (0x60 < (int)(pbVar15 + uVar16) - uVar8) {
      *pcVar4 = '\0';
      return;
    }
    *pbVar5 = 0;
    local_48 = DAT_000038bc;
    uVar16 = uVar16 - *pbVar12;
    FUN_000064a4(DAT_000038bc,(uint)*pbVar12 + DAT_000038bc,uVar16);
    *pbVar12 = 0;
    puVar3 = DAT_000038c0;
    *pbVar5 = (byte)uVar16;
    *puVar3 = *puVar3 | 0x80;
    pbVar15 = (byte *)(uint)(byte)param_1[1];
  }
  iVar19 = local_48 + uVar16;
  pbVar12 = pbVar15;
  if ((byte *)0x5 < pbVar15) {
    bVar2 = param_1[2];
    pbVar17 = *(byte **)(param_1 + 4);
    *(undefined *)(iVar19 + 2) = *param_1;
    pbVar15 = pbVar15 + iVar19 + -3;
    pbVar12 = (byte *)(iVar19 + 3);
    if (bVar2 != 0) {
      if (pbVar12 <= pbVar15) {
        pbVar18 = pbVar17;
        do {
          uVar8 = (uint)*pbVar18;
          if (uVar8 == 5) {
            pbVar9 = *ppbVar14;
            bVar11 = *pbVar9;
            pbVar13 = pbVar12 + 1;
            if (bVar11 != 0) {
              if (pbVar13 < pbVar15) {
                do {
                  pbVar10 = pbVar13 + 1;
                  *pbVar13 = bVar11;
                  pbVar9 = pbVar9 + 1;
                  bVar11 = *pbVar9;
                  pbVar13 = pbVar10;
                  if (bVar11 == 0) {
                    bVar11 = ((char)pbVar10 - (char)pbVar12) - 1;
                    goto LAB_0000389a;
                  }
                } while (pbVar15 != pbVar10);
                bVar11 = ((char)pbVar15 - (char)pbVar12) - 1;
                pbVar13 = pbVar15;
              }
              else {
                bVar11 = 0;
              }
            }
LAB_0000389a:
            *pbVar12 = bVar11;
LAB_000037ea:
            ppbVar14 = ppbVar14 + 1;
            pbVar12 = pbVar13;
          }
          else {
            if (uVar8 < 6) {
              pbVar9 = *ppbVar14;
              if ((byte *)0x7f < pbVar9 + 0x20) {
                pbVar13 = pbVar12;
                if ((byte *)0x3fff < pbVar9 + 0x1000) {
                  if ((byte *)0x1fffff < pbVar9 + 0x80000) {
                    if ((byte *)0xfffffff < pbVar9 + 0x4000000) {
                      pbVar13 = pbVar12 + 1;
                      *pbVar12 = (byte)((uint)pbVar9 >> 0x1c) | 0x80;
                    }
                    pbVar12 = pbVar13 + 1;
                    *pbVar13 = (byte)((uint)pbVar9 >> 0x15) | 0x80;
                  }
                  pbVar13 = pbVar12 + 1;
                  *pbVar12 = (byte)((uint)pbVar9 >> 0xe) | 0x80;
                }
                pbVar12 = pbVar13 + 1;
                *pbVar13 = (byte)((uint)pbVar9 >> 7) | 0x80;
              }
              pbVar13 = pbVar12 + 1;
              *pbVar12 = (byte)pbVar9 & 0x7f;
              goto LAB_000037ea;
            }
            if (1 < uVar8 - 6) break;
            pbVar9 = *ppbVar14;
            if (pbVar15 + -(int)pbVar12 <= *ppbVar14) {
              pbVar9 = pbVar15 + -(int)pbVar12;
            }
            *pbVar12 = (byte)pbVar9;
            iVar7 = FUN_00006370(pbVar12 + 1,ppbVar14[1],pbVar9);
            ppbVar14 = ppbVar14 + 2;
            pbVar12 = pbVar9 + iVar7;
          }
          if (pbVar18 + 1 == pbVar17 + bVar2) goto LAB_0000382a;
          pbVar18 = pbVar18 + 1;
        } while (pbVar12 <= pbVar15);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00002eb8(5);
    }
LAB_0000382a:
    pbVar12 = pbVar12 + (3 - iVar19);
    pbVar15 = (byte *)((uint)pbVar12 & 0xff);
  }
  uVar1 = *DAT_000038c4;
  *(char *)(local_48 + uVar16) = (char)pbVar15;
  *(undefined *)(iVar19 + 1) = uVar1;
  uVar6 = FUN_000018a8(iVar19,pbVar12 + -3);
  (pbVar12 + -3)[iVar19] = (byte)((ushort)uVar6 >> 8);
  pbVar12[iVar19 + -2] = (byte)uVar6;
  pbVar12[iVar19 + -1] = 0x7e;
  puVar3 = DAT_000038c0;
  *pbVar5 = (char)uVar16 + (char)pbVar15;
  *puVar3 = *puVar3 | 0x80;
  *pcVar4 = '\0';
  return;
}




void FUN_000038d4(uint *param_1)

{
  FUN_000036b4(DAT_00003900,*param_1 & 0xff,0x133,*param_1,param_1[1],param_1[2],param_1[3],
               param_1[4],param_1[5]);
  return;
}




void FUN_00003b90(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar3 = (uint)*DAT_00003bdc;
  if (uVar3 != 0) {
    if (uVar3 == 1) {
      puVar6 = (undefined4 *)*DAT_00003be0;
      puVar7 = puVar6;
    }
    else {
      puVar7 = (undefined4 *)*DAT_00003be0;
      bVar1 = *DAT_00003be4;
      iVar4 = 0;
      puVar6 = puVar7;
      do {
        iVar4 = iVar4 + 1;
        puVar5 = (undefined4 *)((int)puVar6 + (uint)bVar1);
        *puVar6 = puVar5;
        puVar6 = puVar5;
      } while (iVar4 != uVar3 - 1);
      puVar6 = (undefined4 *)(iVar4 * (uint)bVar1 + (int)puVar7);
    }
    puVar2 = DAT_00003bf0;
    puVar5 = DAT_00003bec;
    *DAT_00003be8 = puVar7;
    *puVar6 = 0;
    FUN_000036b4(DAT_00003bf4,*puVar2,*puVar5);
    return;
  }
  return;
}




void FUN_00003c78(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined2 *puVar10;
  int *extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int *extraout_r1_06;
  int extraout_r1_07;
  int *extraout_r1_08;
  int *extraout_r1_09;
  uint uVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined uVar16;
  byte bVar17;
  ushort uVar18;
  ushort uVar19;
  int *piVar21;
  uint *puVar22;
  uint *puVar23;
  int iVar24;
  undefined *puVar25;
  undefined4 *puVar26;
  uint uVar27;
  undefined4 *puVar28;
  byte *pbVar29;
  byte *pbVar30;
  uint uVar31;
  undefined4 uVar32;
  int *piVar33;
  undefined4 uVar34;
  byte *pbVar35;
  uint uVar36;
  undefined4 uVar37;
  uint uVar38;
  byte *pbVar39;
  bool bVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  undefined8 uVar43;
  uint local_c8 [4];
  int local_b8;
  int local_b4;
  undefined4 *local_b0;
  int *local_ac;
  uint local_a8;
  uint local_a4;
  undefined8 local_a0;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 auStack_14 [2];
  uint uVar20;
  
  local_a4 = *(uint *)(DAT_00003f60 + 4);
LAB_00003c86:
  iVar5 = DAT_00003f64;
  if (*(char *)(DAT_00003f64 + 8) == '\0') goto LAB_0000456a;
LAB_00003c92:
  puVar4 = DAT_00004a1c;
  local_b8 = *(int *)(DAT_00003f60 + 4);
  disableIRQinterrupts();
  if (*(char *)(iVar5 + 8) != '\0') {
    local_b0 = &local_90;
    *(undefined *)(DAT_00004a10 + 8) = 0xff;
    do {
      piVar33 = DAT_00004d3c;
      enableIRQinterrupts();
      sVar3 = puVar4[0x177];
      *local_b0 = 0;
      local_b0[1] = 0;
      local_b0[2] = 0;
      local_b0[3] = 0;
      if (sVar3 == 0) {
        if (puVar4[0x170] != 0) {
          if (puVar4[0xd] != 0) {
            uVar8 = FUN_00005f00(puVar4[0x16e],param_2);
            uVar8 = FUN_00006118(uVar8,DAT_00004d40);
            iVar5 = piVar33[4];
            iVar7 = piVar33[5];
            *(int *)(puVar4 + 8) = iVar5;
            *(int *)(puVar4 + 10) = iVar7;
            uVar41 = FUN_00005460(iVar5,iVar7,*(undefined4 *)(puVar4 + 4),
                                  *(undefined4 *)(puVar4 + 6));
            uVar42 = FUN_00005720(uVar8);
            uVar41 = FUN_00005cb4((int)uVar41,(int)((ulonglong)uVar41 >> 0x20),(int)uVar42,
                                  (int)((ulonglong)uVar42 >> 0x20));
            param_2 = (int)((ulonglong)uVar41 >> 0x20);
            if ((int)uVar41 != 0) goto LAB_0000499c;
            *(int *)(puVar4 + 4) = iVar5;
            *(int *)(puVar4 + 6) = iVar7;
          }
          uVar41 = FUN_000024e8(local_b0);
          param_2 = (int)((ulonglong)uVar41 >> 0x20);
          if ((int)uVar41 == 0) goto LAB_0000499c;
          local_ac = DAT_00004d3c;
          FUN_000057d0(DAT_00004d3c[4],DAT_00004d3c[5],DAT_00004d28,DAT_00004d2c);
          uVar8 = FUN_00005d54();
          FUN_000036b4(DAT_00004d44,*puVar4,uVar8,local_90,local_8c,local_88,local_84);
          sVar3 = puVar4[0x16f];
          puVar4[0x16f] = sVar3 + 1;
          param_2 = extraout_r1_05;
          if ((puVar4[0x170] == (short)(sVar3 + 1)) &&
             (iVar5 = *local_ac, puVar4[0x170] = 0, iVar5 == 1)) {
            FUN_00001e60();
            param_2 = extraout_r1_07;
          }
        }
        iVar5 = *(int *)(puVar4 + 0x16a);
        if (iVar5 != 0) {
          local_ac = DAT_00004d3c;
LAB_000048d8:
          piVar33 = DAT_00004a24;
          uVar8 = FUN_00005f00(puVar4[0x176],param_2);
          uVar8 = FUN_00006118(uVar8,DAT_00004a18);
          iVar7 = local_ac[4];
          iVar24 = local_ac[5];
          piVar33[2] = iVar7;
          piVar33[3] = iVar24;
          uVar41 = FUN_00005460(iVar7,iVar24,*piVar33,piVar33[1]);
          local_a0 = uVar41;
          uVar41 = FUN_00005720(uVar8);
          uVar41 = FUN_00005cb4((byte *)local_a0,local_a0._4_4_,(int)uVar41,
                                (int)((ulonglong)uVar41 >> 0x20));
          param_2 = (int)((ulonglong)uVar41 >> 0x20);
          if ((int)uVar41 == 0) {
            iVar14 = 0xf - (iVar5 + -1);
            *(int *)(puVar4 + 0x16a) = iVar5 + -1;
            uVar34 = *(undefined4 *)(puVar4 + iVar14 * 4 + 300);
            uVar16 = *(undefined *)puVar4;
            uVar8 = *(undefined4 *)(puVar4 + 0x16c);
            *piVar33 = iVar7;
            piVar33[1] = iVar24;
            FUN_000036b4(DAT_00004a28,uVar16,iVar14 * 2,uVar8,*(undefined *)(puVar4 + 0x171),
                         *(undefined4 *)(puVar4 + 0x182),*(undefined4 *)(puVar4 + iVar14 * 4 + 0x22)
                         ,*(undefined4 *)(puVar4 + iVar14 * 4 + 100),
                         *(undefined4 *)(puVar4 + iVar14 * 4 + 0xa6),
                         *(undefined4 *)(puVar4 + iVar14 * 4 + 0xe8),
                         *(undefined4 *)(puVar4 + iVar14 * 4 + 0x12a),
                         *(undefined4 *)(puVar4 + iVar14 * 4 + 0x24),
                         *(undefined4 *)(puVar4 + iVar14 * 4 + 0x66),
                         *(undefined4 *)(puVar4 + iVar14 * 4 + 0xa8),
                         *(undefined4 *)(puVar4 + iVar14 * 4 + 0xea),uVar34);
            param_2 = extraout_r1_03;
          }
        }
      }
      else {
        if (puVar4[0xd] != 0) {
          iVar5 = DAT_00004a14[4];
          iVar7 = DAT_00004a14[5];
          *(int *)(puVar4 + 8) = iVar5;
          *(int *)(puVar4 + 10) = iVar7;
          uVar41 = FUN_00005460(iVar5,iVar7,*(undefined4 *)(puVar4 + 4),*(undefined4 *)(puVar4 + 6))
          ;
          uVar8 = FUN_00005f00(sVar3);
          FUN_00006118(uVar8,DAT_00004a18);
          uVar42 = FUN_00005720();
          uVar41 = FUN_00005cb4((int)uVar41,(int)((ulonglong)uVar41 >> 0x20),(int)uVar42,
                                (int)((ulonglong)uVar42 >> 0x20));
          param_2 = (int)((ulonglong)uVar41 >> 0x20);
          if ((int)uVar41 != 0) goto LAB_0000499c;
          *(int *)(puVar4 + 4) = iVar5;
          *(int *)(puVar4 + 6) = iVar7;
        }
        puVar26 = local_b0;
        uVar41 = FUN_000024e8(local_b0);
        param_2 = (int)((ulonglong)uVar41 >> 0x20);
        if ((int)uVar41 != 0) {
          uVar36 = *(uint *)(puVar4 + 0x20);
          local_ac = DAT_00004a14;
          uVar6 = uVar36 & 0x1f;
          if ((int)uVar36 < 1) {
            uVar6 = -(-uVar36 & 0x1f);
          }
          FUN_000057d0(DAT_00004a14[4],DAT_00004a14[5],DAT_00004a08,DAT_00004a0c);
          uVar41 = FUN_00005d54();
          param_2 = (int)((ulonglong)uVar41 >> 0x20);
          uVar18 = puVar4[0xc];
          *(int *)(puVar4 + uVar6 * 2 + 0x22) = (int)uVar41;
          *(uint *)(puVar4 + 0x20) = uVar36 + 1;
          if (uVar18 == 0) {
            uVar19 = puVar4[0xd];
            if (puVar4[0xd] != 0) {
              uVar19 = uVar18;
            }
            puVar4[0x171] = uVar19;
          }
          else {
            iVar5 = 0;
            puVar10 = DAT_00004a1c;
            do {
              uVar36 = *(uint *)(puVar10 + 0x62);
              uVar6 = uVar36 & 0x1f;
              if ((int)uVar36 < 1) {
                uVar6 = -(-uVar36 & 0x1f);
              }
              iVar7 = iVar5 * 0x21;
              iVar5 = iVar5 + 1;
              *(undefined4 *)(puVar4 + (iVar7 + uVar6) * 2 + 100) = *puVar26;
              *(uint *)(puVar10 + 0x62) = uVar36 + 1;
              puVar10 = puVar10 + 0x42;
              puVar26 = puVar26 + 1;
            } while (iVar5 < (int)(uint)uVar18);
            if (puVar4[0xd] == 0) {
              puVar4[0x171] = 0;
              local_a8 = 0;
              local_a0._0_4_ = (byte *)0x0;
              do {
                iVar5 = FUN_00002134(local_a8,0);
                uVar6 = *(uint *)(puVar4 + 0x180);
                uVar8 = *(undefined4 *)(iVar5 + 0xf8);
                uVar34 = *(undefined4 *)(iVar5 + 0xfc);
                uVar41 = FUN_000056dc(uVar6);
                uVar41 = FUN_00005cf0(uVar8,uVar34,(int)uVar41,(int)((ulonglong)uVar41 >> 0x20));
                param_2 = (int)((ulonglong)uVar41 >> 0x20);
                if ((int)uVar41 == 0) {
LAB_00004c66:
                  if (0x1f < *(int *)(puVar4 + 0x62)) {
                    uVar37 = *(undefined4 *)(iVar5 + 0xf0);
                    uVar32 = *(undefined4 *)(iVar5 + 0xf4);
                    local_c8[2] = uVar37;
                    local_c8[3] = uVar32;
                    uVar41 = FUN_00005cf0(uVar8,uVar34,uVar37,uVar32);
                    param_2 = (int)((ulonglong)uVar41 >> 0x20);
                    if ((int)uVar41 != 0) {
                      local_c8[0] = *(uint *)(iVar5 + 0xe8);
                      local_c8[1] = *(undefined4 *)(iVar5 + 0xec);
                      uVar41 = FUN_00005cf0(uVar37,uVar32);
                      param_2 = (int)((ulonglong)uVar41 >> 0x20);
                      if ((int)uVar41 != 0) {
                        local_b4 = 0;
                        puVar26 = (undefined4 *)(iVar5 + -8);
                        do {
                          puVar28 = puVar26 + 2;
                          uVar37 = *puVar28;
                          uVar32 = puVar26[3];
                          uVar41 = FUN_00005cf0(uVar8,uVar34,uVar37,uVar32);
                          param_2 = (int)((ulonglong)uVar41 >> 0x20);
                          if ((int)uVar41 != 0) {
                            uVar41 = FUN_00005cf0(local_c8[2],local_c8[3],uVar37,uVar32);
                            param_2 = (int)((ulonglong)uVar41 >> 0x20);
                            if ((int)uVar41 != 0) {
                              uVar41 = FUN_00005cf0(local_c8[0],local_c8[1],uVar37,uVar32);
                              param_2 = (int)((ulonglong)uVar41 >> 0x20);
                              if ((int)uVar41 != 0) {
                                local_b4 = local_b4 + 1;
                              }
                            }
                          }
                          puVar26 = puVar28;
                        } while ((undefined4 *)(iVar5 + 0xe0) != puVar28);
                        if (local_b4 == 0x1d) {
                          uVar41 = FUN_000056dc(*(undefined4 *)(puVar4 + 0x17e));
                          uVar41 = FUN_00005cb4(uVar8,uVar34,(int)uVar41,
                                                (int)((ulonglong)uVar41 >> 0x20));
                          param_2 = (int)((ulonglong)uVar41 >> 0x20);
                          if ((int)uVar41 == 0) goto LAB_00004cfa;
                        }
                      }
                    }
                  }
                }
                else {
                  uVar41 = FUN_000056dc(uVar6 >> 1);
                  uVar41 = FUN_00005cf0(*(undefined4 *)(iVar5 + 0xf0),*(undefined4 *)(iVar5 + 0xf4),
                                        (int)uVar41,(int)((ulonglong)uVar41 >> 0x20));
                  param_2 = (int)((ulonglong)uVar41 >> 0x20);
                  if ((int)uVar41 == 0) goto LAB_00004c66;
                  uVar41 = FUN_000056dc((uint)((ulonglong)DAT_00004d48 * (ulonglong)uVar6 >> 0x21));
                  uVar41 = FUN_00005cf0(*(undefined4 *)(iVar5 + 0xe8),*(undefined4 *)(iVar5 + 0xec),
                                        (int)uVar41,(int)((ulonglong)uVar41 >> 0x20));
                  param_2 = (int)((ulonglong)uVar41 >> 0x20);
                  if ((int)uVar41 == 0) goto LAB_00004c66;
LAB_00004cfa:
                  param_2 = 1;
                  puVar4[0x171] = (ushort)(1 << (local_a8 & 0xff)) | puVar4[0x171];
                  local_a0._0_4_ = (byte *)((int)(byte *)local_a0 + 1);
                }
                local_a8 = local_a8 + 1;
              } while ((int)local_a8 < (int)(uint)(ushort)puVar4[0xc]);
            }
            else {
              uVar6 = 0;
              local_a0._0_4_ = (byte *)0x0;
              puVar4[0x171] = 0;
              do {
                uVar41 = FUN_00002134(uVar6,0);
                param_2 = (int)((ulonglong)uVar41 >> 0x20);
                uVar36 = *(uint *)(puVar4 + 0x17e);
                local_a8 = uVar36;
                if (uVar36 == 0) {
LAB_00004be0:
                  uVar18 = (ushort)(1 << (uVar6 & 0xff)) | puVar4[0x171];
                  local_a0._0_4_ = (byte *)((int)(byte *)local_a0 + 1);
                }
                else {
                  uVar42 = FUN_000056dc(*(undefined4 *)(puVar4 + 0x180));
                  uVar36 = 0;
                  puVar26 = (undefined4 *)((int)uVar41 + 0x100);
                  do {
                    puVar28 = puVar26 + -2;
                    uVar43 = FUN_00005cdc(*puVar28,puVar26[-1],(int)uVar42,
                                          (int)((ulonglong)uVar42 >> 0x20));
                    param_2 = (int)((ulonglong)uVar43 >> 0x20);
                    if ((int)uVar43 != 0) {
                      uVar36 = uVar36 + 1;
                    }
                    puVar26 = puVar28;
                  } while ((undefined4 *)(uVar36 * -8 + 0x100 + (int)uVar41) != puVar28);
                  if (uVar36 == local_a8) goto LAB_00004be0;
                  uVar18 = puVar4[0x171];
                }
                puVar4[0x171] = uVar18;
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 < (int)(uint)(ushort)puVar4[0xc]);
            }
            uVar34 = DAT_00004a0c;
            uVar8 = DAT_00004a08;
            local_a0 = CONCAT44(local_a0._4_4_,(byte *)local_a0);
            if (((int)(uint)(ushort)puVar4[0x17c] <= (int)(byte *)local_a0) &&
               (local_a0 = CONCAT44(local_a0._4_4_,(byte *)local_a0), puVar4[0x171] != 0)) {
              iVar24 = 0;
              iVar5 = local_ac[4];
              iVar7 = local_ac[5];
              puVar4[0x177] = 0;
              FUN_000057d0(iVar5,iVar7,uVar8,uVar34);
              uVar8 = FUN_00005d54();
              puVar26 = DAT_00004a20;
              *(undefined4 *)(puVar4 + 0x16c) = uVar8;
              FUN_00000dfc(*puVar26,1);
              param_2 = extraout_r1_01;
              if (puVar4[0xc] != 0) {
                do {
                  FUN_00002134(iVar24,1);
                  iVar24 = iVar24 + 1;
                  param_2 = extraout_r1_02;
                } while (iVar24 < (int)(uint)(ushort)puVar4[0xc]);
              }
              iVar5 = 0x10;
              *(undefined4 *)(puVar4 + 0x16a) = 0x10;
              goto LAB_000048d8;
            }
          }
        }
      }
LAB_0000499c:
      piVar33 = DAT_00004a14;
      sVar3 = *(short *)(DAT_00004a2c + 100);
      if (sVar3 != 0) {
        uVar8 = FUN_00005f00(*(undefined2 *)(DAT_00004a2c + 0x66),param_2);
        uVar8 = FUN_00006118(uVar8,DAT_00004a18);
        piVar21 = DAT_00004a24;
        iVar24 = piVar33[4];
        iVar14 = piVar33[5];
        iVar5 = *DAT_00004a24;
        iVar7 = DAT_00004a24[1];
        DAT_00004a24[2] = iVar24;
        piVar21[3] = iVar14;
        local_a0._0_4_ = (byte *)uVar8;
        uVar41 = FUN_00005460(iVar24,iVar14,iVar5,iVar7);
        uVar42 = FUN_00005720((byte *)local_a0);
        param_2 = FUN_00005cb4((int)uVar41,(int)((ulonglong)uVar41 >> 0x20),(int)uVar42,
                               (int)((ulonglong)uVar42 >> 0x20));
        piVar33 = DAT_00004a24;
        if (param_2 == 0) {
          uVar6 = *(uint *)(DAT_00004a2c + 0xec);
          *DAT_00004a24 = iVar24;
          piVar33[1] = iVar14;
          if (uVar6 != 0) {
            puVar28 = &uStack_94;
            FUN_00006574(local_b0,0,0x80);
            puVar26 = puVar28;
            do {
              uVar36 = uVar6 & 0x1f;
              if ((int)uVar6 < 1) {
                uVar36 = -(-uVar6 & 0x1f);
              }
              uVar6 = uVar6 + 1;
              puVar26 = puVar26 + 1;
              *puVar26 = *(undefined4 *)(DAT_00004d30 + uVar36 * 4 + 0xf0);
            } while (auStack_14 != puVar26);
            puVar15 = (undefined4 *)(DAT_00004d30 + 0xec);
            puVar26 = puVar28;
            do {
              puVar26 = puVar26 + 1;
              puVar15 = puVar15 + 1;
              *puVar15 = *puVar26;
            } while (auStack_14 != puVar26);
            uVar6 = *(uint *)(DAT_00004d30 + 0x68);
            *(undefined4 *)(DAT_00004d30 + 0xec) = 0;
            puVar26 = puVar28;
            do {
              uVar36 = uVar6 & 0x1f;
              if ((int)uVar6 < 1) {
                uVar36 = -(-uVar6 & 0x1f);
              }
              uVar6 = uVar6 + 1;
              puVar26 = puVar26 + 1;
              *puVar26 = *(undefined4 *)(DAT_00004d30 + uVar36 * 4 + 0x6c);
            } while (auStack_14 != puVar26);
            puVar26 = (undefined4 *)(DAT_00004d30 + 0x68);
            do {
              puVar28 = puVar28 + 1;
              puVar26 = puVar26 + 1;
              *puVar26 = *puVar28;
            } while (puVar28 != auStack_14);
            *(undefined4 *)(DAT_00004d30 + 0x68) = 0;
          }
          puVar12 = DAT_00004d30;
          uVar18 = sVar3 - 1;
          iVar5 = 7 - (uint)uVar18;
          uVar8 = *(undefined4 *)(DAT_00004d30 + iVar5 * 0x10 + 0x78);
          *(ushort *)(DAT_00004d30 + 100) = uVar18;
          FUN_000036b4(DAT_00004d34,*puVar12,iVar5 * 4,*(undefined4 *)(puVar12 + 0x60),
                       *(undefined4 *)(puVar12 + iVar5 * 0x10 + 0xf0),
                       *(undefined4 *)(puVar12 + iVar5 * 0x10 + 0xf4),
                       *(undefined4 *)(puVar12 + iVar5 * 0x10 + 0xf8),
                       *(undefined4 *)(puVar12 + iVar5 * 0x10 + 0xfc),
                       *(undefined4 *)(puVar12 + iVar5 * 0x10 + 0x6c),
                       *(undefined4 *)(puVar12 + iVar5 * 0x10 + 0x70),
                       *(undefined4 *)(puVar12 + iVar5 * 0x10 + 0x74),uVar8);
          param_2 = extraout_r1_04;
        }
      }
    } while (*(char *)(DAT_00004d38 + 8) != '\0');
  }
  enableIRQinterrupts();
  local_a8 = local_a4 + (*(int *)(DAT_00003f60 + 4) - local_b8);
  do {
    uVar8 = DAT_00003f68;
    *(undefined *)(DAT_00003f64 + 8) = 1;
    local_90 = local_90 & 0xffffff00;
    iVar5 = FUN_00005358(uVar8);
    if (iVar5 != 0) {
      local_90 = CONCAT31(local_90._1_3_,0xff);
LAB_00003cd2:
      uVar6 = FUN_00002914(&local_90,DAT_00003f6c);
      uVar41 = local_a0;
      if (uVar6 != 0) {
        while (local_a0._4_4_ = (undefined4)((ulonglong)uVar41 >> 0x20),
              *(byte *)(uVar6 + 0x1c) < 0x78) {
          iVar5 = 0;
          uVar36 = 0;
          do {
            uVar31 = uVar36 + 1;
            uVar20 = (int)(uint)*(byte *)(uVar6 + 0x1d) >> (uVar31 & 0xff) & 1;
            uVar16 = (undefined)uVar20;
            if (uVar20 != 0) {
              local_a0 = uVar41;
              iVar7 = FUN_00000cac(*(undefined *)(uVar36 + uVar6 + 0xc));
              if (iVar7 != 0) {
                iVar7 = 1;
              }
              uVar16 = (undefined)iVar7;
              uVar41 = local_a0;
            }
            bVar17 = *(byte *)(uVar6 + 0x1c);
            *(undefined *)(*(int *)(uVar6 + 0x14) + (uint)bVar17 + iVar5) = uVar16;
            iVar5 = iVar5 + 0x7c;
            uVar36 = uVar31;
          } while (uVar31 != 5);
          *(byte *)(uVar6 + 0x1c) = bVar17 + 1;
          local_a0 = uVar41;
          uVar6 = FUN_00002914(&local_90,DAT_00003f6c);
          uVar41 = local_a0;
          if (uVar6 == 0) goto LAB_00003d1c;
        }
        pbVar39 = *(byte **)(uVar6 + 0x14);
        uVar20 = *(byte *)(uVar6 + 0x1d) & 0xfe;
        *(char *)(uVar6 + 0x1d) = (char)uVar20;
        uVar36 = 1;
        local_a4 = uVar6;
        local_a0._0_4_ = pbVar39;
LAB_00003fb6:
        if (((int)uVar20 >> (uVar36 & 0xff) & 1U) != 0) {
          iVar5 = 1;
          pbVar35 = pbVar39;
          do {
            pbVar35 = pbVar35 + 1;
            iVar7 = (int)(char)iVar5;
            if ((uint)*pbVar35 != (uint)*pbVar39) {
              if (iVar7 != 0x77) {
                uVar6 = 0x76;
                pbVar29 = pbVar39 + 0x77;
                bVar17 = *pbVar29;
                goto LAB_0000404c;
              }
              break;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != 0x78);
          goto LAB_00004060;
        }
        *(undefined4 *)(pbVar39 + 0x78) = 0;
        goto LAB_00003fc2;
      }
    }
LAB_00003d1c:
    iVar7 = FUN_00005358(DAT_00003f70);
    uVar34 = DAT_00003f78;
    uVar8 = DAT_00003f74;
    iVar5 = DAT_00003f60;
    if (iVar7 != 0) {
      local_90 = CONCAT31(local_90._1_3_,0xff);
      do {
        iVar7 = FUN_00002914(&local_90,uVar8);
        while( true ) {
          if (iVar7 == 0) goto LAB_00003d7c;
          if (-1 < (int)((uint)*(byte *)(iVar7 + 0x20) << 0x1d)) break;
          uVar37 = *(undefined4 *)(iVar5 + 4);
          disableIRQinterrupts();
          bVar17 = *(byte *)(iVar7 + 0x20);
          *(byte *)(iVar7 + 0x20) = bVar17 & 0xfb;
          enableIRQinterrupts();
          FUN_000036b4(uVar34,local_90 & 0xff,bVar17 & 1,*(undefined *)(iVar7 + 0x21),uVar37);
          iVar7 = FUN_00002914(&local_90,uVar8);
        }
      } while( true );
    }
LAB_00003d7c:
    iVar5 = FUN_00005358(DAT_00003f7c);
    uVar41 = local_a0;
    if (iVar5 != 0) {
      local_a0._0_4_ = (byte *)((int)&uStack_94 + 3);
      uStack_94._3_1_ = 0xff;
LAB_00003d96:
      iVar5 = FUN_00002914((byte *)local_a0,DAT_00003f80);
      uVar41 = CONCAT44(local_a0._4_4_,(byte *)local_a0);
      if (((iVar5 != 0) &&
          (uVar41 = CONCAT44(local_a0._4_4_,(byte *)local_a0),
          (int)((uint)*(byte *)(iVar5 + 0x14) << 0x1f) < 0)) &&
         (uVar41 = CONCAT44(local_a0._4_4_,(byte *)local_a0), 0 < *(int *)(iVar5 + 0x1c))) {
        local_88 = 0;
        local_84 = 0;
        local_90 = 0;
        local_8c = 0;
        if (*(int *)(iVar5 + 0x18) != 0) goto code_r0x00003dcc;
        uVar20 = *(uint *)(DAT_0000423c + 4);
        uVar31 = *DAT_00004240;
        uVar11 = DAT_00004240[1];
        uVar36 = 0;
        bVar40 = uVar11 == 0;
        if (uVar11 == 0) {
          bVar40 = uVar31 <= uVar20;
        }
        piVar21 = (int *)0x0;
        if (bVar40) goto LAB_00003e0e;
        bVar40 = uVar20 != 0;
        uVar20 = uVar20 - 1;
        uVar8 = FUN_00005f24(uVar20 - uVar31,(bVar40 - uVar11) - (uint)(uVar20 < uVar31));
        uVar8 = FUN_00005fb0(uVar8,DAT_00004244);
        FUN_00006118(uVar8,DAT_00004248);
        local_a4 = FUN_00006290();
        goto LAB_00003f1a;
      }
    }
    local_a0 = uVar41;
    iVar5 = FUN_00005358(DAT_0000424c);
    uVar34 = DAT_00004268;
    uVar8 = DAT_00004250;
    if (iVar5 != 0) {
      local_90 = CONCAT31(local_90._1_3_,0xff);
      while( true ) {
        iVar5 = FUN_00002914(&local_90,uVar8);
        if ((iVar5 == 0) || (*(int *)(iVar5 + 0x78) == 0)) break;
        FUN_000036b4(uVar34,*(undefined *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 0x7c),
                     *(undefined4 *)(iVar5 + 0x80));
        *(undefined4 *)(iVar5 + 0x78) = 0;
      }
    }
    iVar5 = FUN_00005358(DAT_00004254);
    uVar34 = DAT_0000425c;
    uVar8 = DAT_00004258;
    if (iVar5 != 0) {
      local_90 = CONCAT31(local_90._1_3_,0xff);
LAB_0000419e:
      iVar5 = FUN_00002914(&local_90,uVar8);
      if (iVar5 != 0) {
        while (*(char *)(iVar5 + 0x26) == *(char *)(iVar5 + 0x27)) {
          disableIRQinterrupts();
          if (*(char *)(iVar5 + 0x27) == *(char *)(iVar5 + 0x26)) {
            *(char *)(iVar5 + 0x26) = *(char *)(iVar5 + 0x27) + '\x01';
            enableIRQinterrupts();
            FUN_000036b4(uVar34,local_90 & 0xff,*(undefined4 *)(iVar5 + 0x14),
                         *(undefined2 *)(iVar5 + 0x18));
            break;
          }
          enableIRQinterrupts();
          iVar5 = FUN_00002914(&local_90,uVar8);
          if (iVar5 == 0) goto LAB_000041d2;
        }
        goto LAB_0000419e;
      }
    }
LAB_000041d2:
    iVar5 = FUN_00005358(DAT_00004260);
    uVar8 = DAT_00004264;
    if (iVar5 != 0) {
      uStack_94._3_1_ = 0xff;
      uVar41 = local_a0;
switchD_00004216_caseD_4:
      local_a0 = uVar41;
      iVar5 = FUN_00002914((int)&uStack_94 + 3,uVar8);
      uVar41 = local_a0;
      if (iVar5 != 0) {
        while (bVar17 = uStack_94._3_1_, local_a0._4_4_ = (undefined4)((ulonglong)uVar41 >> 0x20),
              (int)((uint)*(byte *)(iVar5 + 0x1f) << 0x1f) < 0) {
          disableIRQinterrupts();
          uVar34 = *(undefined4 *)(iVar5 + 8);
          *(byte *)(iVar5 + 0x1f) = *(byte *)(iVar5 + 0x1f) & 0xfe;
          enableIRQinterrupts();
          local_a0 = uVar41;
          switch(*(undefined *)(iVar5 + 0x1e)) {
          case 0:
            local_90 = 0;
            FUN_00001a98(*(undefined4 *)(iVar5 + 0x18),1,4,&local_90);
            FUN_00001a40(iVar5,uVar34,
                         local_90 << 0x18 | (local_90 >> 8 & 0xff) << 0x10 |
                         (local_90 >> 0x10 & 0xff) << 8 | local_90 >> 0x18,local_90 >> 0x18 & 7,
                         bVar17);
            uVar41 = local_a0;
            goto switchD_00004216_caseD_4;
          case 1:
            local_90 = 0xc;
            FUN_00001a98(*(undefined4 *)(iVar5 + 0x18),1,4,&local_90);
            uVar6 = local_90;
            local_90 = CONCAT22(local_90._2_2_,0xf);
            FUN_00001a98(*(undefined4 *)(iVar5 + 0x18),1,2,&local_90);
            FUN_00001a40(iVar5,uVar34,
                         (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18,
                         local_90._1_1_,bVar17);
            uVar41 = local_a0;
            goto switchD_00004216_caseD_4;
          case 2:
            local_a0._0_4_ = (byte *)(uint)uStack_94._3_1_;
            local_90 = 1;
            FUN_00001a98(*(undefined4 *)(iVar5 + 0x18),1,3,&local_90);
            uVar36 = local_90;
            local_90 = CONCAT22(local_90._2_2_,7);
            FUN_00001a98(*(undefined4 *)(iVar5 + 0x18),1,2,&local_90);
            uVar6 = (uVar36 >> 0x10 & 0xff) << 8;
            FUN_00001a40(iVar5,uVar34,(((uVar36 >> 8 & 0xff) << 0x10 | uVar6) << 8) >> 0x10,
                         local_90 >> 8 & 0xfc | (uVar6 & 0x100) >> 8,(byte *)local_a0);
            uVar41 = CONCAT44(local_a0._4_4_,(byte *)local_a0);
            goto switchD_00004216_caseD_4;
          case 3:
            local_90 = local_90 & 0xffff0000;
            FUN_00001a98(*(undefined4 *)(iVar5 + 0x18),1,2,&local_90);
            FUN_00001a40(iVar5,uVar34,(local_90 & 0xff) << 8 | local_90 >> 8 & 0xff,
                         local_90 >> 8 & 6,bVar17);
            iVar5 = FUN_00002914((int)&uStack_94 + 3,uVar8);
            uVar41 = local_a0;
            if (iVar5 == 0) goto LAB_000042a4;
            break;
          default:
            goto switchD_00004216_caseD_4;
          }
        }
        goto switchD_00004216_caseD_4;
      }
    }
LAB_000042a4:
    iVar7 = FUN_00005358(DAT_00004574);
    iVar5 = DAT_000045a4;
    uVar8 = DAT_00004578;
    if (iVar7 != 0) {
      uStack_94._3_1_ = 0xff;
LAB_000042be:
      iVar7 = FUN_00002914((int)&uStack_94 + 3,uVar8);
      if (iVar7 != 0) {
        while ((int)((uint)*(byte *)(iVar7 + 0x18) << 0x1d) < 0) {
          if (-1 < (int)((uint)*(byte *)(iVar7 + 0x18) << 0x1f)) {
            FUN_00001c10(iVar7,uStack_94._3_1_);
            break;
          }
          FUN_00005378();
          *(undefined *)(iVar7 + 0x18) = 2;
          local_90 = CONCAT22(local_90._2_2_,0x82d);
          FUN_00001a98(*(undefined4 *)(iVar7 + 0x10),0,2,&local_90);
          disableIRQinterrupts();
          *(int *)(iVar7 + 8) = *(int *)(iVar7 + 0xc) + *(int *)(iVar5 + 4);
          FUN_000053c8(iVar7);
          enableIRQinterrupts();
          iVar7 = FUN_00002914((int)&uStack_94 + 3,uVar8);
          if (iVar7 == 0) goto LAB_00004312;
        }
        goto LAB_000042be;
      }
    }
LAB_00004312:
    iVar5 = FUN_00005358(DAT_0000457c);
    uVar34 = DAT_00004584;
    uVar8 = DAT_00004580;
    if (iVar5 != 0) {
      local_90 = CONCAT31(local_90._1_3_,0xff);
      do {
        iVar5 = FUN_00002914(&local_90,uVar8);
        while( true ) {
          if (iVar5 == 0) goto LAB_00004362;
          if (-1 < (int)((uint)*(byte *)(iVar5 + 0x11) << 0x1c)) break;
          disableIRQinterrupts();
          *(byte *)(iVar5 + 0x11) = *(byte *)(iVar5 + 0x11) & 0xf7;
          enableIRQinterrupts();
          FUN_000036b4(uVar34,local_90 & 0xff,*(byte *)(iVar5 + 0x13) >> 3,iVar5 + 0x20);
          iVar5 = FUN_00002914(&local_90,uVar8);
        }
      } while( true );
    }
LAB_00004362:
    iVar5 = FUN_00005358(DAT_00004588);
    uVar34 = DAT_00004590;
    uVar8 = DAT_0000458c;
    if (iVar5 != 0) {
      local_90 = CONCAT31(local_90._1_3_,0xff);
      do {
        iVar5 = FUN_00002914(&local_90,uVar8);
        while( true ) {
          if (iVar5 == 0) goto LAB_000043b8;
          if (-1 < (int)((uint)*(byte *)(iVar5 + 0x20) << 0x1f)) break;
          disableIRQinterrupts();
          *(byte *)(iVar5 + 0x20) = *(byte *)(iVar5 + 0x20) & 0xfe;
          enableIRQinterrupts();
          FUN_000036b4(uVar34,local_90 & 0xff,*(undefined4 *)(iVar5 + 8),
                       *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c));
          iVar5 = FUN_00002914(&local_90,uVar8);
        }
      } while( true );
    }
LAB_000043b8:
    iVar5 = FUN_00005358(DAT_00004594);
    uVar34 = DAT_0000459c;
    uVar8 = DAT_00004598;
    if (iVar5 != 0) {
      local_90 = CONCAT31(local_90._1_3_,0xff);
LAB_000043ce:
      iVar5 = FUN_00002914(&local_90,uVar8);
      if (iVar5 != 0) {
        while (*(char *)(iVar5 + 0x1c) == -1) {
          disableIRQinterrupts();
          if (*(char *)(iVar5 + 0x12) == '\0') {
            enableIRQinterrupts();
            break;
          }
          *(undefined *)(iVar5 + 0x1c) = *(undefined *)(iVar5 + 0x1d);
          enableIRQinterrupts();
          FUN_000036b4(uVar34,local_90 & 0xff,*(undefined *)(iVar5 + 0x1b),*(char *)(iVar5 + 0x12),
                       iVar5 + 0x13);
          iVar5 = FUN_00002914(&local_90,uVar8);
          if (iVar5 == 0) goto LAB_0000440a;
        }
        goto LAB_000043ce;
      }
    }
LAB_0000440a:
    iVar5 = DAT_000045a4;
    *DAT_000045a0 = 0xaaaa;
    piVar33 = DAT_000045a8;
    disableIRQinterrupts();
    if (*DAT_000045a8 - *(int *)(iVar5 + 4) < 0) {
      *DAT_000045a8 = *(int *)(iVar5 + 4);
    }
    enableIRQinterrupts();
    uVar6 = (uint)*DAT_000045ac;
    if (uVar6 != 0) {
      bVar17 = *DAT_000045b0;
      uVar36 = (uint)bVar17;
      if ((int)(uVar36 << 0x1f) < 0) {
LAB_00004474:
        uVar41 = FUN_000062d0(DAT_000045b4,0x7e,uVar6);
        piVar33 = (int *)((ulonglong)uVar41 >> 0x20);
        if ((int)uVar41 != 0) {
          iVar5 = (int)uVar41 - (int)DAT_000045b4;
          uVar36 = uVar36 & 0xfe;
          *DAT_000045b0 = (byte)uVar36;
          uVar6 = iVar5 + 1;
        }
        if ((int)(uVar36 << 0x1e) < 0) {
          iVar5 = -1;
          uVar41 = local_a0;
        }
        else {
          *DAT_000045b0 = (byte)uVar36 | 2;
LAB_000044a2:
          FUN_000036b4(DAT_000045b8);
          iVar5 = -1;
          piVar33 = extraout_r1;
          uVar41 = local_a0;
        }
      }
      else {
        if (uVar6 < (int)&Reset + 1U) goto LAB_000044e2;
        uVar20 = (uint)*DAT_000045b4;
        if (((int)&PendSV + 3U < uVar20 - 5) || (bVar1 = DAT_000045b4[1], (bVar1 & 0xf0) != 0x10))
        goto LAB_00004464;
        if (uVar6 < uVar20) goto LAB_000044e2;
        if ((DAT_000045b4 + -1)[uVar20] == 0x7e) {
          iVar5 = uVar20 - 3;
          uVar31 = FUN_000018a8(DAT_000045b4,iVar5);
          piVar21 = DAT_00004efc;
          pbVar39 = DAT_00004ef8;
          pbVar35 = (byte *)(iVar5 + (int)DAT_00004ef0);
          piVar33 = DAT_00004ef0;
          if (CONCAT11(*(byte *)((int)DAT_00004ef0 + iVar5),
                       ((byte *)((int)DAT_00004ef0 + -2))[uVar20]) != uVar31) goto LAB_00004464;
          bVar2 = *DAT_00004ef8;
          *(byte *)DAT_00004efc = bVar17 & 0xfd;
          uVar6 = uVar20;
          if (bVar2 != bVar1) goto LAB_000044a2;
          *pbVar39 = bVar2 + 1 & 0xf | 0x10;
          piVar33 = piVar21;
          pbVar39 = DAT_00004f00;
          uVar41 = local_a0;
          while (pbVar39 < pbVar35) {
            pbVar29 = pbVar39 + 1;
            uVar36 = (uint)*pbVar39;
            local_a0._0_4_ = (byte *)uVar6;
            if (0x4b < uVar36 - 1) {
                    /* WARNING: Subroutine does not return */
              FUN_00002eb8(4);
            }
            iVar5 = DAT_00004f04 + uVar36 * 0xc;
            puVar22 = (uint *)((int)local_c8 - ((uint)*(byte *)(iVar5 + 1) * 4 + 7 & 0x7f8));
            iVar7 = *(byte *)(iVar5 + 3) - 1;
            if (*(byte *)(iVar5 + 3) != 0) {
              if (pbVar35 < pbVar29) {
LAB_00004ee2:
                    /* WARNING: Subroutine does not return */
                FUN_00002eb8(6);
              }
              pbVar39 = *(byte **)(iVar5 + 4) + 1;
              bVar17 = **(byte **)(iVar5 + 4);
              if (4 < bVar17) goto LAB_00004e82;
              while( true ) {
                pbVar30 = pbVar29 + 1;
                uVar20 = (uint)*pbVar29;
                uVar6 = uVar20 & 0x7f;
                pbVar29 = pbVar30;
                if ((uVar20 & 0x60) == 0x60) {
                  uVar6 = uVar6 | 0xffffffe0;
                }
                while ((int)(uVar20 << 0x18) < 0) {
                  uVar20 = (uint)*pbVar29;
                  uVar6 = uVar20 & 0x7f | uVar6 << 7;
                  pbVar29 = pbVar29 + 1;
                }
                *puVar22 = uVar6;
                if (iVar7 == 0) break;
                puVar22 = puVar22 + 1;
                pbVar30 = pbVar39;
                if (pbVar35 < pbVar29) goto LAB_00004ee2;
                while( true ) {
                  pbVar39 = pbVar30 + 1;
                  bVar17 = *pbVar30;
                  iVar7 = iVar7 + -1;
                  if (bVar17 < 5) break;
LAB_00004e82:
                  if (bVar17 != 7) goto LAB_00004ee2;
                  pbVar30 = pbVar29 + 1;
                  bVar17 = *pbVar29;
                  pbVar29 = pbVar30 + bVar17;
                  if (pbVar35 < pbVar29) goto LAB_00004ee2;
                  *puVar22 = (uint)bVar17;
                  puVar22[1] = (uint)pbVar30;
                  puVar22 = puVar22 + 2;
                  pbVar30 = pbVar39;
                  if (iVar7 == 0) goto LAB_00004e9e;
                }
              }
            }
LAB_00004e9e:
            if ((*(char *)(DAT_00004ef4 + 9) == '\0') ||
               ((int)((uint)*(byte *)(DAT_00004f04 + uVar36 * 0xc + 2) << 0x1f) < 0)) {
              (**(code **)(DAT_00004f04 + uVar36 * 0xc + 8))();
              piVar33 = extraout_r1_08;
            }
            else {
              FUN_000036b4(DAT_00004f08,*(undefined *)(DAT_00004ef4 + 10));
              piVar33 = extraout_r1_09;
            }
            uVar41 = CONCAT44(local_a0._4_4_,(byte *)local_a0);
            uVar6 = (uint)(byte *)local_a0;
            pbVar39 = pbVar29;
          }
          iVar5 = 1;
        }
        else {
LAB_00004464:
          if (uVar20 != 0x7e) {
            uVar36 = uVar36 | 1;
            *DAT_000045b0 = (byte)uVar36;
            goto LAB_00004474;
          }
          uVar6 = 1;
          iVar5 = -1;
          uVar41 = local_a0;
        }
      }
      iVar7 = 0;
      local_a0 = uVar41;
      while( true ) {
        bVar17 = *DAT_000045ac;
        iVar24 = bVar17 - uVar6;
        if (iVar24 != 0) {
          FUN_000064a4((byte *)(iVar7 + (int)DAT_00004ef0),
                       (byte *)(uVar6 + iVar7 + (int)DAT_00004ef0),iVar24 - iVar7);
          *(undefined *)(DAT_00004ef4 + 8) = 0;
          iVar7 = iVar24;
          piVar33 = extraout_r1_06;
        }
        uVar36 = 0;
        bVar40 = (bool)isCurrentModePrivileged();
        if (bVar40) {
          uVar36 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        if ((uint)bVar17 == (uint)*DAT_000045ac) break;
        bVar40 = (bool)isCurrentModePrivileged();
        if (bVar40) {
          enableIRQinterrupts((uVar36 & 1) == 1);
        }
      }
      *DAT_000045ac = (byte)iVar24;
      bVar40 = (bool)isCurrentModePrivileged();
      if (bVar40) {
        enableIRQinterrupts((uVar36 & 1) == 1);
      }
      if (iVar5 == 1) {
        FUN_000036b4(DAT_000045b8,piVar33,uVar36);
      }
    }
LAB_000044e2:
    puVar22 = DAT_000045c4;
    piVar21 = DAT_000045c0;
    piVar33 = DAT_000045bc;
    local_a4 = *(uint *)(DAT_000045a4 + 4);
    iVar7 = *DAT_000045bc;
    uVar6 = local_a4 - local_a8;
    param_2 = *DAT_000045c0 + 1;
    *DAT_000045bc = iVar7 + uVar6;
    *piVar21 = param_2;
    puVar23 = DAT_000045d8;
    iVar5 = DAT_000045c8;
    if (uVar6 < 0x10000) {
      uVar20 = *puVar22;
      uVar36 = uVar20 + (uVar6 * uVar6 + 0xff >> 8);
LAB_00004518:
      if (uVar36 < uVar20) {
        uVar36 = 0xffffffff;
      }
    }
    else {
      if (uVar6 < 0x100000) {
        uVar20 = *puVar22;
        uVar36 = uVar6 * (uVar6 + 0xff >> 8) + uVar20;
        goto LAB_00004518;
      }
      uVar36 = 0xffffffff;
    }
    uVar20 = *DAT_000045d8;
    *puVar22 = uVar36;
    if ((int)((iVar5 + local_a4) - uVar20) < 0) goto LAB_00003c86;
    FUN_000036b4(DAT_000045cc,param_2,iVar7 + uVar6);
    if (local_a4 < uVar20) {
      *DAT_000045d0 = *DAT_000045d0 + 1;
    }
    *puVar23 = local_a4;
    iVar5 = DAT_000045d4;
    *puVar22 = 0;
    *piVar33 = 0;
    *piVar21 = 0;
    param_2 = extraout_r1_00;
    if (*(char *)(iVar5 + 8) != '\0') goto LAB_00003c92;
LAB_0000456a:
    local_a8 = local_a4;
  } while( true );
  while (uVar6 = uVar6 - 1, uVar6 != 0) {
LAB_0000404c:
    pbVar29 = pbVar29 + -1;
    if (*pbVar29 != bVar17) {
      uVar31 = uVar6 & 0xff;
      if ((char)uVar6 == '\x01') goto LAB_00004060;
      if ((uint)pbVar39[iVar5] != (uint)pbVar39[uVar6]) goto LAB_0000407c;
      uVar11 = uVar31 - 1 & 0xff;
      pbVar29 = pbVar39 + uVar11 + 1;
      goto LAB_000046e0;
    }
  }
  *(undefined4 *)(pbVar39 + 0x78) = 0;
  goto LAB_00003fc2;
  while (uVar11 = uVar11 - 1, '\0' < (char)uVar11) {
LAB_000046e0:
    pbVar29 = pbVar29 + -1;
    if ((uint)*pbVar29 != (uint)pbVar39[uVar6]) {
      uVar31 = uVar11 & 0xff;
      break;
    }
  }
LAB_0000407c:
  if (iVar5 + 3 < (int)uVar31) {
    iVar24 = (uVar31 - iVar5) + 1;
    uVar6 = (uint)(iVar24 * 0x400000) >> 0x18;
    if ((int)uVar31 < iVar7) {
      if (uVar6 == 0) {
        uVar6 = 0;
        goto LAB_000040d4;
      }
    }
    else {
      uVar9 = 0;
      uVar38 = 0;
      uVar11 = (uint)*pbVar35;
      uVar27 = (uint)pbVar39[iVar5];
      while( true ) {
        uVar13 = uVar11;
        if (uVar13 != uVar27) {
          uVar9 = uVar9 + 1;
        }
        iVar7 = (int)(char)((char)iVar7 + '\x01');
        if (uVar13 != uVar27) {
          uVar9 = uVar9 & 0xff;
        }
        uVar38 = uVar38 + uVar13 & 0xff;
        if ((int)uVar31 < iVar7) break;
        uVar11 = (uint)pbVar39[iVar7];
        uVar27 = uVar13;
      }
      if (((uVar6 <= uVar38) && (uVar38 <= (uint)(iVar24 * 0xc00000) >> 0x18)) &&
         (uVar31 = (uVar9 + 1) * 0x800000 >> 0x18, uVar6 = uVar38 / uVar31, uVar31 <= uVar38)) {
LAB_000040d4:
        uVar41 = FUN_000056fc(uVar6 * 0x927c);
        uVar41 = FUN_000057d0((int)uVar41,(int)((ulonglong)uVar41 >> 0x20),0,DAT_00004234);
        uVar41 = FUN_00005a24(DAT_00004228,DAT_0000422c,(int)uVar41,(int)((ulonglong)uVar41 >> 0x20)
                             );
        FUN_000057d0((int)uVar41,(int)((ulonglong)uVar41 >> 0x20),0,DAT_00004238);
        uVar8 = FUN_00005d54();
        *(undefined4 *)(pbVar39 + 0x78) = uVar8;
        goto LAB_00003fc2;
      }
    }
  }
LAB_00004060:
  *(undefined4 *)(pbVar39 + 0x78) = 0;
LAB_00003fc2:
  uVar6 = local_a4;
  uVar36 = uVar36 + 1;
  pbVar39 = pbVar39 + 0x7c;
  if (uVar36 == 6) goto code_r0x00003fcc;
  goto LAB_00003fb6;
code_r0x00003fcc:
  FUN_000036b4(DAT_00004230,local_90 & 0xff,*(undefined4 *)((byte *)local_a0 + 0x78),
               *(undefined4 *)((byte *)local_a0 + 0xf4),*(undefined4 *)((byte *)local_a0 + 0x170),
               *(undefined4 *)((byte *)local_a0 + 0x1ec),*(undefined4 *)((byte *)local_a0 + 0x268));
  uVar20 = (uint)*(byte *)(uVar6 + 0x1d);
  uVar36 = 1;
  puVar12 = (undefined *)(*(int *)(uVar6 + 0x14) + 0x77);
  do {
    puVar25 = puVar12 + -0x78;
    do {
      puVar25 = puVar25 + 1;
      *puVar25 = 0;
    } while (puVar12 != puVar25);
    uVar31 = uVar36 & 0xff;
    uVar36 = uVar36 + 1;
    *(undefined4 *)(puVar12 + 1) = 0;
    uVar20 = uVar20 & ~(1 << uVar31);
    puVar12 = puVar12 + 0x7c;
  } while (uVar36 != 6);
  *(char *)(uVar6 + 0x1d) = (char)uVar20;
  *(undefined *)(uVar6 + 0x1c) = 0;
  goto LAB_00003cd2;
code_r0x00003dcc:
  uVar6 = 0;
  piVar33 = (int *)0x0;
  do {
    iVar7 = FUN_00000cac(*(undefined *)((int)piVar33 + iVar5 + 0x30));
    piVar21 = *(int **)(iVar5 + 0x18);
    uVar36 = (uint)piVar33 & 0xff;
    piVar33 = (int *)((int)piVar33 + 1);
    uVar6 = uVar6 | iVar7 << uVar36;
  } while (piVar33 < piVar21);
  uVar20 = *(uint *)(DAT_00003f60 + 4);
  uVar31 = *DAT_00003f84;
  uVar11 = DAT_00003f84[1];
  uVar36 = 0;
  bVar40 = uVar11 == 0;
  if (uVar11 == 0) {
    bVar40 = uVar31 <= uVar20;
  }
  if (!bVar40) {
    bVar40 = uVar20 != 0;
    uVar20 = uVar20 - 1;
    uVar36 = (uint)bVar40;
  }
  if (uVar6 == 0) {
LAB_00003e0e:
    local_ac = piVar21;
    uVar8 = FUN_00005f24(uVar20 - uVar31,(uVar36 - uVar11) - (uint)(uVar20 < uVar31));
    uVar8 = FUN_00005fb0(uVar8,DAT_00003f88);
    FUN_00006118(uVar8,DAT_00003f8c);
    local_a4 = FUN_00006290();
    if (local_ac != (int *)0x0) {
      uVar6 = 0;
      do {
        FUN_00000dfc(*(undefined4 *)(iVar5 + (uVar6 + 8) * 4),0);
        uVar36 = *(uint *)(iVar5 + 0x18);
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar36);
      iVar7 = 0x18;
      do {
        if (uVar36 == 0) goto LAB_00003f1a;
        uVar6 = 0;
        do {
          FUN_00000dfc(*(undefined4 *)(iVar5 + (uVar6 + 8) * 4),1);
          uVar36 = *(uint *)(iVar5 + 0x18);
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar36);
        if (uVar36 == 0) goto LAB_00003f1a;
        puVar22 = &local_90;
        do {
          puVar23 = puVar22 + 1;
          *puVar22 = *puVar22 << 1;
          puVar22 = puVar23;
        } while (&local_90 + uVar36 != puVar23);
        uVar6 = 0;
        do {
          FUN_00000dfc(*(undefined4 *)(iVar5 + (uVar6 + 8) * 4),0);
          uVar36 = *(uint *)(iVar5 + 0x18);
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar36);
        if (uVar36 != 0) {
          uVar6 = 0;
          puVar22 = &local_90;
          do {
            iVar24 = iVar5 + uVar6;
            uVar6 = uVar6 + 1;
            iVar24 = FUN_00000cac(*(undefined *)(iVar24 + 0x30));
            uVar31 = *puVar22;
            uVar36 = *(uint *)(iVar5 + 0x18);
            if (iVar24 != 0) {
              uVar31 = uVar31 + 1;
            }
            *puVar22 = uVar31;
            puVar22 = puVar22 + 1;
          } while (uVar6 < uVar36);
        }
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      uVar6 = 0;
      if (uVar36 != 0) {
        do {
          FUN_00000dfc(*(undefined4 *)(iVar5 + (uVar6 + 8) * 4),1);
          uVar36 = *(uint *)(iVar5 + 0x18);
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar36);
        if (uVar36 != 0) {
          puVar22 = &local_90;
          do {
            puVar23 = puVar22 + 1;
            uVar6 = *puVar22;
            if ((int)(uVar6 << 8) < 0) {
              uVar6 = uVar6 | 0xff000000;
            }
            *puVar22 = uVar6;
            puVar22 = puVar23;
          } while (&local_90 + uVar36 != puVar23);
          uVar6 = 0;
          do {
            FUN_00000dfc(*(undefined4 *)(iVar5 + (uVar6 + 8) * 4),0);
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(iVar5 + 0x18));
        }
      }
    }
LAB_00003f1a:
    puVar22 = DAT_00003f84;
    *DAT_00003f84 = *(uint *)(DAT_00003f60 + 4);
    uVar8 = DAT_00003f90;
    puVar22[1] = 0;
    FUN_000036b4(uVar8,*(undefined *)(iVar5 + 0xc),0,local_a4 & 0xff,*(undefined2 *)(iVar5 + 0x1c),
                 uVar20,local_90,local_8c,local_88,local_84);
    iVar7 = *(int *)(iVar5 + 0x1c) + -1;
    *(int *)(iVar5 + 0x1c) = iVar7;
    if (iVar7 == 0) {
      *(byte *)(iVar5 + 0x14) = *(byte *)(iVar5 + 0x14) & 0xfe;
    }
  }
  goto LAB_00003d96;
}




void FUN_00004f0c(void)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  int **ppiVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  undefined4 uVar12;
  byte bVar13;
  uint uVar14;
  undefined *puVar15;
  uint uVar16;
  undefined8 uVar17;
  undefined local_11;
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  undefined local_b;
  undefined local_a;
  undefined local_9;
  
  *DAT_000051ac = DAT_000051a8 & 0xfffffffc;
  FUN_000015e0(0x27,1);
  FUN_000015e0(0x10,1);
  iVar9 = DAT_000051b8;
  puVar2 = DAT_000051b4;
  *DAT_000051b0 = 0x5555;
  iVar10 = DAT_000051b8;
  puVar3 = DAT_000051b4;
  uVar14 = *puVar2 & 1;
  do {
    if (uVar14 == 0) goto LAB_00004f4e;
    iVar9 = iVar9 + -1;
    uVar14 = *puVar2 & 1;
  } while (iVar9 != 0);
  if (uVar14 == 0) {
LAB_00004f4e:
    *DAT_000051bc = 1;
    puVar2 = DAT_000051c8;
    iVar9 = DAT_000051c4;
    puVar8 = DAT_000051b0;
    uVar14 = *puVar3 & 2;
    do {
      if (uVar14 == 0) goto LAB_00004f70;
      iVar10 = iVar10 + -1;
      uVar14 = *puVar3 & 2;
    } while (iVar10 != 0);
    if (uVar14 == 0) {
LAB_00004f70:
      *DAT_000051c0 = 0x9c4;
      *puVar8 = 0xaaaa;
      *puVar8 = 0xcccc;
      *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) | 0x1000000;
      *puVar2 = *puVar2 | 1;
      puVar2[1] = 0;
      puVar8 = DAT_000051d0;
      iVar9 = DAT_000051cc;
      uVar14 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar14 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      *(undefined *)(DAT_000051cc + 0x23) = 0x20;
      *puVar8 = 7;
      puVar8[1] = 0;
      puVar8[2] = 0;
      *(undefined4 *)(iVar9 + 4) = 0x4000000;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar14 & 1) == 1);
      }
      FUN_0000130c(3,1);
      FUN_0000130c(2,3,1);
      puVar8 = DAT_000051e0;
      puVar3 = DAT_000051dc;
      puVar2 = DAT_000051d8;
      *DAT_000051d4 = *DAT_000051d4 | 0x20000;
      iVar9 = DAT_000051e4;
      *puVar2 = *puVar2 & 0xffffdfff;
      *puVar2 = *puVar2 & 0xffffefff;
      *puVar2 = *puVar2;
      *puVar3 = *puVar3 & 0xffffcfff;
      *puVar3 = *puVar3;
      *puVar2 = *puVar2 & 0xfffff9ff;
      *puVar2 = *puVar2;
      *puVar8 = 0x104;
      *puVar2 = *puVar2 & 0xfffffffb;
      *puVar2 = *puVar2 | 4;
      *puVar2 = *puVar2 & 0xfffffff7;
      *puVar2 = *puVar2 | 8;
      *puVar2 = *puVar2 | 0x2000;
      *(undefined *)(iVar9 + 0x326) = 0;
      *(undefined4 *)(iVar9 + 4) = 0x40;
      uVar12 = DAT_000051e8;
      *puVar2 = *puVar2 | 0x20;
      FUN_000036b4(uVar12);
      disableIRQinterrupts();
      iVar9 = FUN_00006614(DAT_000051ec);
      if (iVar9 != 0) goto LAB_00005066;
      while( true ) {
        enableIRQinterrupts();
        iVar9 = FUN_00003c78();
LAB_00005066:
        disableIRQinterrupts();
        uVar14 = DAT_000051c8[1];
        if (*(char *)((int)DAT_000051f0 + 9) == '\0') {
          *(char *)((int)DAT_000051f0 + 10) = (char)iVar9;
        }
        piVar6 = DAT_000051f8;
        piVar5 = DAT_000051f4;
        ppiVar4 = DAT_000051f0;
        *DAT_000051f4 = DAT_000051fc;
        puVar8 = DAT_000051d0;
        iVar9 = DAT_000051cc;
        iVar10 = piVar5[2];
        *piVar6 = (int)piVar5;
        piVar6[2] = iVar10;
        *ppiVar4 = piVar6;
        ppiVar4[1] = piVar5;
        *(undefined *)((int)ppiVar4 + 9) = 2;
        puVar8[1] = 0;
        puVar8[2] = 0;
        *(undefined4 *)(iVar9 + 4) = 0x4000000;
        uVar7 = DAT_00005204;
        *DAT_00005200 = 0;
        FUN_00003b90();
        local_11 = 0xff;
        iVar9 = FUN_00002914(&local_11,uVar7);
        uVar12 = DAT_00005208;
        while (DAT_00005208 = uVar12, iVar9 != 0) {
          iVar10 = *(int *)(iVar9 + 0x14);
          *(undefined *)(iVar9 + 0x1c) = 0;
          puVar15 = (undefined *)(iVar10 + -1);
          *(undefined4 *)(iVar9 + 0x18) = 0;
          do {
            puVar11 = puVar15;
            do {
              puVar11 = puVar11 + 1;
              *puVar11 = 0;
            } while (puVar15 + 0x78 != puVar11);
            *(undefined4 *)(puVar15 + 0x79) = 0;
            puVar15 = puVar15 + 0x7c;
          } while (puVar15 != (undefined *)(iVar10 + 0x26b));
          *(undefined *)(iVar9 + 0x1d) = 0;
          iVar9 = FUN_00002914(&local_11,uVar7);
          uVar12 = DAT_00005208;
        }
        local_10 = 0xff;
        while (iVar9 = FUN_00002914(&local_10,uVar12), uVar7 = DAT_0000520c, iVar9 != 0) {
          FUN_00000dfc(*(undefined4 *)(iVar9 + 0x18),*(byte *)(iVar9 + 0x2c) & 0x10);
          *(undefined4 *)(iVar9 + 0x24) = 0;
          bVar13 = *(byte *)(iVar9 + 0x2c) & 0x10;
          if ((*(byte *)(iVar9 + 0x2c) & 0x10) != 0) {
            bVar13 = 0x11;
          }
          *(byte *)(iVar9 + 0x2c) = bVar13;
        }
        local_f = 0xff;
        while (iVar9 = FUN_00002914(&local_f,uVar7), uVar12 = DAT_00005210, iVar9 != 0) {
          *(undefined4 *)(iVar9 + 0x2c) = 0;
          FUN_000029f0(iVar9 + 0x34,0);
        }
        local_e = 0xff;
        while (iVar9 = FUN_00002914(&local_e,uVar12), iVar9 != 0) {
          FUN_0000297c();
        }
        local_d = 0xff;
        uVar12 = DAT_00005214;
        while (uVar17 = FUN_00002914(&local_d,uVar12),
              uVar12 = (undefined4)((ulonglong)uVar17 >> 0x20), iVar9 = (int)uVar17, iVar9 != 0) {
          *(undefined4 *)(iVar9 + 0x1c) = 0;
          *(byte *)(iVar9 + 0x14) = *(byte *)(iVar9 + 0x14) & 0xfe;
        }
        local_c = 0xff;
        uVar12 = DAT_00005218;
        while (uVar17 = FUN_00002914(&local_c,uVar12), uVar7 = DAT_0000521c,
              uVar12 = (undefined4)((ulonglong)uVar17 >> 0x20), (int)uVar17 != 0) {
          *(undefined4 *)((int)uVar17 + 0x78) = 0;
        }
        local_b = 0xff;
        while (iVar9 = FUN_00002914(&local_b,uVar7), uVar12 = DAT_00005304, iVar9 != 0) {
          FUN_00000c2c();
          if (*(char *)(iVar9 + 0x27) != '\0') {
            iVar10 = *(int *)(iVar9 + 0x14) + *(int *)(iVar9 + 0xc);
            *(char *)(iVar9 + 0x26) = *(char *)(iVar9 + 0x27) + '\x01';
            *(int *)(iVar9 + 0x14) = iVar10;
            *(int *)(iVar9 + 8) = iVar10;
            FUN_000053c8(iVar9);
          }
        }
        local_a = 0xff;
        while (iVar9 = FUN_00002914(&local_a,uVar12), uVar7 = DAT_00005308, iVar9 != 0) {
          if ((int)((uint)*(byte *)(iVar9 + 0x10) << 0x1f) < 0) {
            FUN_00000dfc(*(undefined4 *)(iVar9 + 0xc),
                         ((*(byte *)(iVar9 + 0x10) ^ 8) << 0x1c) >> 0x1f);
          }
        }
        local_a = 0xff;
        while (puVar8 = (undefined4 *)FUN_00002914(&local_a,uVar7), uVar12 = DAT_0000530c,
              puVar8 != (undefined4 *)0x0) {
          FUN_00001a98(*puVar8,0,*(undefined *)(puVar8 + 1),(int)puVar8 + 5);
        }
        local_9 = 0xff;
        while (iVar10 = FUN_00002914(&local_9,uVar12), iVar9 = DAT_00005310, iVar10 != 0) {
          FUN_000018e0(*(undefined4 *)(iVar10 + 0xc),iVar10 + 0x11);
        }
        uVar16 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar16 = getCurrentExceptionNumber();
          uVar16 = uVar16 & 0x1f;
        }
        if (uVar16 != 0) break;
        *(undefined *)(DAT_00005310 + 9) = 1;
        enableIRQinterrupts();
        FUN_000036b4(DAT_00005314,uVar14,*(undefined *)(iVar9 + 10));
      }
      (*(code *)0xfffffff9)();
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00002eb8(0x29);
}




char FUN_00005358(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 != '\0') {
    *param_1 = '\0';
    cVar1 = '\x01';
  }
  return cVar1;
}




void FUN_00005368(undefined *param_1)

{
  *(undefined *)(DAT_00005374 + 8) = 0;
  *param_1 = 1;
  return;
}




void FUN_00005378(undefined4 *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar5 = DAT_000053c4;
  piVar2 = DAT_000053bc;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar4 = (undefined4 *)*DAT_000053bc;
  if ((undefined4 *)*DAT_000053bc == param_1) {
    uVar3 = *param_1;
    DAT_000053c4[2] = param_1[2];
    *puVar5 = uVar3;
    *piVar2 = (int)puVar5;
  }
  else {
    do {
      puVar5 = puVar4;
      puVar4 = (undefined4 *)*puVar5;
      if (puVar4 == (undefined4 *)0x0) goto LAB_00005396;
    } while (puVar4 != param_1);
    *puVar5 = *param_1;
  }
LAB_00005396:
  puVar4 = (undefined4 *)piVar2[1];
  puVar5 = puVar4;
  if (puVar4 == param_1) {
    puVar5 = DAT_000053c0;
  }
  if (puVar4 == param_1) {
    piVar2[1] = (int)puVar5;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  return;
}




void FUN_000053c8(int **param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int **ppiVar6;
  int **ppiVar7;
  uint uVar8;
  bool bVar9;
  
  piVar2 = DAT_00005440;
  piVar5 = param_1[2];
  uVar8 = 0;
  bVar9 = (bool)isCurrentModePrivileged();
  if (bVar9) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  ppiVar6 = (int **)*DAT_00005440;
  if ((int)piVar5 - (int)ppiVar6[2] < 0) {
    bVar9 = (int)piVar5 - *(int *)(DAT_00005444 + 4) < 0;
    if (bVar9) {
      piVar5 = (int *)(*(int *)(DAT_00005444 + 4) + 0xf0);
      param_1[2] = piVar5;
    }
    iVar4 = DAT_00005454;
    iVar3 = DAT_0000544c;
    ppiVar7 = DAT_00005448;
    if (ppiVar6 == DAT_00005448) {
      ppiVar6 = (int **)*ppiVar6;
    }
    *param_1 = (int *)ppiVar6;
    *ppiVar7 = (int *)param_1;
    *piVar2 = (int)ppiVar7;
    ppiVar7[2] = piVar5;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar4 + 4) = 0x4000000;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar8 & 1) == 1);
    }
    if (bVar9) {
      FUN_000036b4(DAT_00005450);
      return;
    }
  }
  else {
    do {
      ppiVar7 = ppiVar6;
      ppiVar6 = (int **)*ppiVar7;
    } while (-1 < (int)piVar5 - (int)ppiVar6[2]);
    *param_1 = (int *)ppiVar6;
    *ppiVar7 = (int *)param_1;
    bVar9 = (bool)isCurrentModePrivileged();
    if (bVar9) {
      enableIRQinterrupts((uVar8 & 1) == 1);
    }
  }
  return;
}




ulonglong FUN_00005460(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  
  uVar6 = param_4 ^ 0x80000000;
  uVar9 = param_2 << 1;
  param_4 = param_4 << 1;
  bVar13 = ((param_2 ^ uVar6) & 0x7fffffff) == 0;
  bVar14 = bVar13 && param_1 == param_3;
  if (!bVar13 || param_1 != param_3) {
    bVar14 = (uVar9 | param_1) == 0;
  }
  if (!bVar14) {
    bVar14 = (param_4 | param_3) == 0;
  }
  iVar8 = (int)uVar9 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar8 == -1;
  }
  iVar1 = (int)param_4 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar1 == -1;
  }
  if (bVar14) {
    if (iVar8 == -1 || iVar1 == -1) {
      uVar9 = uVar6;
      uVar11 = param_3;
      if (iVar8 == -1) {
        uVar9 = param_2;
        uVar11 = param_1;
      }
      if (iVar8 != -1 || iVar1 != -1) {
        param_3 = uVar11;
        uVar6 = uVar9;
      }
      bVar14 = (uVar11 | uVar9 << 0xc) == 0;
      if (bVar14) {
        bVar14 = (param_3 | uVar6 << 0xc) == 0;
      }
      if (bVar14) {
        bVar14 = uVar9 == uVar6;
      }
      if (!bVar14) {
        uVar9 = uVar9 | 0x80000;
      }
      return CONCAT44(uVar9,uVar11);
    }
    if (((param_2 ^ uVar6) & 0x7fffffff) != 0 || param_1 != param_3) {
      if ((uVar9 | param_1) == 0) {
        param_1 = param_3;
        param_2 = uVar6;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != uVar6) {
      return 0;
    }
    if (uVar9 >> 0x15 == 0) {
      bVar14 = (param_1 & 0x80000000) != 0;
      uVar6 = param_2 * 2 + (uint)bVar14;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar14)) {
        uVar6 = uVar6 | 0x80000000;
      }
      return CONCAT44(uVar6,param_1 << 1);
    }
    if (uVar9 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_000056a4:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar9 = uVar9 >> 0x15;
  param_4 = param_4 >> 0x15;
  uVar11 = param_4 - uVar9;
  bVar14 = uVar11 != 0;
  if (param_4 < uVar9) {
    uVar11 = -uVar11;
  }
  uVar10 = param_1;
  uVar7 = param_2;
  if (bVar14 && uVar9 <= param_4) {
    uVar9 = uVar9 + uVar11;
    uVar10 = param_3;
    uVar7 = uVar6;
    param_3 = param_1;
    uVar6 = param_2;
  }
  if (0x36 < uVar11) {
    return CONCAT44(uVar7,uVar10);
  }
  uVar4 = uVar7 & 0xfffff | 0x100000;
  if ((uVar7 & 0x80000000) != 0) {
    bVar14 = uVar10 != 0;
    uVar10 = -uVar10;
    uVar4 = -uVar4 - (uint)bVar14;
  }
  uVar7 = uVar6 & 0xfffff | 0x100000;
  if ((uVar6 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar7 = -uVar7 - (uint)bVar14;
  }
  if (uVar9 == uVar11) {
    uVar7 = uVar7 ^ 0x100000;
    if (uVar9 == 0) {
      uVar4 = uVar4 ^ 0x100000;
      uVar9 = 1;
    }
    else {
      uVar11 = uVar11 - 1;
    }
  }
  uVar6 = -uVar11 + 0x20;
  if ((int)uVar11 < 0x21) {
    uVar12 = param_3 << (uVar6 & 0xff);
    param_3 = param_3 >> (uVar11 & 0xff);
    uVar3 = uVar10 + param_3;
    uVar5 = uVar7 << (uVar6 & 0xff);
    uVar6 = uVar3 + uVar5;
    uVar4 = uVar4 + CARRY4(uVar10,param_3) + ((int)uVar7 >> (uVar11 & 0xff)) +
            (uint)CARRY4(uVar3,uVar5);
  }
  else {
    uVar12 = uVar7 << (-uVar11 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar12 = uVar12 | 2;
    }
    uVar7 = (int)uVar7 >> (uVar11 - 0x20 & 0xff);
    uVar6 = uVar10 + uVar7;
    uVar4 = uVar4 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar10,uVar7);
  }
  param_2 = uVar4 & 0x80000000;
  uVar11 = uVar4;
  if ((int)uVar4 < 0) {
    bVar14 = uVar12 == 0;
    uVar12 = -uVar12;
    uVar11 = -uVar6;
    uVar6 = -(uint)!bVar14 - uVar6;
    uVar11 = -(uint)(bVar14 <= uVar11) - uVar4;
  }
  if (0xfffff < uVar11) {
    uVar10 = uVar9 - 1;
    if (0x1fffff < uVar11) {
      uVar10 = uVar11 & 1;
      uVar11 = uVar11 >> 1;
      bVar2 = (byte)uVar6;
      uVar6 = (uint)(uVar10 != 0) << 0x1f | uVar6 >> 1;
      uVar12 = (uint)(bVar2 & 1) << 0x1f | uVar12 >> 1;
      uVar10 = uVar9;
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_000056a4;
    }
LAB_00005570:
    bVar14 = 0x7fffffff < uVar12;
    if (uVar12 == 0x80000000) {
      bVar14 = (uVar6 & 1) != 0;
    }
    return CONCAT44(uVar11 + uVar10 * 0x100000 + (uint)CARRY4(uVar6,(uint)bVar14) | param_2,
                    uVar6 + bVar14);
  }
  bVar13 = (uVar12 & 0x80000000) != 0;
  uVar12 = uVar12 << 1;
  uVar10 = uVar6 * 2;
  bVar14 = CARRY4(uVar6,uVar6);
  uVar6 = uVar6 * 2 + (uint)bVar13;
  uVar11 = uVar11 * 2 + (uint)(bVar14 || CARRY4(uVar10,(uint)bVar13));
  uVar10 = uVar9 - 2;
  if (uVar9 - 1 != 0 && 0xfffff < uVar11) goto LAB_00005570;
  uVar7 = uVar6;
  uVar9 = uVar11;
  if (uVar11 == 0) {
    uVar7 = 0;
    uVar9 = uVar6;
  }
  iVar8 = LZCOUNT(uVar9);
  if (uVar11 == 0) {
    iVar8 = iVar8 + 0x20;
  }
  uVar11 = iVar8 - 0xb;
  bVar15 = SBORROW4(uVar11,0x20);
  uVar6 = iVar8 - 0x2b;
  bVar14 = (int)uVar6 < 0;
  bVar13 = uVar6 == 0;
  if ((int)uVar11 < 0x20) {
    bVar15 = SCARRY4(uVar6,0xc);
    iVar8 = iVar8 + -0x1f;
    bVar14 = iVar8 < 0;
    bVar13 = iVar8 == 0;
    uVar6 = uVar11;
    if (!bVar13 && bVar14 == bVar15) {
      uVar7 = uVar9 << (uVar11 & 0xff);
      uVar9 = uVar9 >> (0xcU - iVar8 & 0xff);
      goto LAB_000055e8;
    }
  }
  if (bVar13 || bVar14 != bVar15) {
    uVar12 = 0x20 - uVar6;
  }
  uVar9 = uVar9 << (uVar6 & 0xff);
  if (bVar13 || bVar14 != bVar15) {
    uVar9 = uVar9 | uVar7 >> (uVar12 & 0xff);
    uVar7 = uVar7 << (uVar6 & 0xff);
  }
LAB_000055e8:
  if ((int)uVar11 <= (int)uVar10) {
    return CONCAT44(uVar9 + (uVar10 - uVar11) * 0x100000 | param_2,uVar7);
  }
  uVar6 = ~(uVar10 - uVar11);
  if ((int)uVar6 < 0x1f) {
    iVar8 = uVar6 - 0x13;
    if (iVar8 != 0 && iVar8 < 0 == SCARRY4(uVar6 - 0x1f,0xc)) {
      return CONCAT44(uVar4,uVar7 >> (0x20 - (0xcU - iVar8) & 0xff) | uVar9 << (0xcU - iVar8 & 0xff)
                     ) & 0x80000000ffffffff;
    }
    uVar6 = uVar6 + 1;
    return CONCAT44(param_2 | uVar9 >> (uVar6 & 0xff),
                    uVar7 >> (uVar6 & 0xff) | uVar9 << (0x20 - uVar6 & 0xff));
  }
  return CONCAT44(uVar4,uVar9 >> (uVar6 - 0x1f & 0xff)) & 0x80000000ffffffff;
}




ulonglong FUN_00005464(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  
  uVar7 = param_2 << 1;
  uVar9 = param_4 << 1;
  bVar13 = ((param_2 ^ param_4) & 0x7fffffff) == 0;
  bVar14 = bVar13 && param_1 == param_3;
  if (!bVar13 || param_1 != param_3) {
    bVar14 = (uVar7 | param_1) == 0;
  }
  if (!bVar14) {
    bVar14 = (uVar9 | param_3) == 0;
  }
  iVar6 = (int)uVar7 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar6 == -1;
  }
  iVar1 = (int)uVar9 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar1 == -1;
  }
  if (bVar14) {
    if (iVar6 == -1 || iVar1 == -1) {
      uVar9 = param_4;
      uVar7 = param_3;
      if (iVar6 == -1) {
        uVar9 = param_2;
        uVar7 = param_1;
      }
      if (iVar6 != -1 || iVar1 != -1) {
        param_3 = uVar7;
        param_4 = uVar9;
      }
      bVar14 = (uVar7 | uVar9 << 0xc) == 0;
      if (bVar14) {
        bVar14 = (param_3 | param_4 << 0xc) == 0;
      }
      if (bVar14) {
        bVar14 = uVar9 == param_4;
      }
      if (!bVar14) {
        uVar9 = uVar9 | 0x80000;
      }
      return CONCAT44(uVar9,uVar7);
    }
    if (((param_2 ^ param_4) & 0x7fffffff) != 0 || param_1 != param_3) {
      if ((uVar7 | param_1) == 0) {
        param_1 = param_3;
        param_2 = param_4;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != param_4) {
      return 0;
    }
    if (uVar7 >> 0x15 == 0) {
      bVar14 = (param_1 & 0x80000000) != 0;
      uVar9 = param_2 * 2 + (uint)bVar14;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar14)) {
        uVar9 = uVar9 | 0x80000000;
      }
      return CONCAT44(uVar9,param_1 << 1);
    }
    if (uVar7 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_000056a4:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar7 = uVar7 >> 0x15;
  uVar9 = uVar9 >> 0x15;
  uVar10 = uVar9 - uVar7;
  bVar14 = uVar10 != 0;
  if (uVar9 < uVar7) {
    uVar10 = -uVar10;
  }
  uVar8 = param_1;
  uVar5 = param_2;
  if (bVar14 && uVar7 <= uVar9) {
    uVar7 = uVar7 + uVar10;
    uVar8 = param_3;
    uVar5 = param_4;
    param_3 = param_1;
    param_4 = param_2;
  }
  if (0x36 < uVar10) {
    return CONCAT44(uVar5,uVar8);
  }
  uVar9 = uVar5 & 0xfffff | 0x100000;
  if ((uVar5 & 0x80000000) != 0) {
    bVar14 = uVar8 != 0;
    uVar8 = -uVar8;
    uVar9 = -uVar9 - (uint)bVar14;
  }
  uVar5 = param_4 & 0xfffff | 0x100000;
  if ((param_4 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar5 = -uVar5 - (uint)bVar14;
  }
  if (uVar7 == uVar10) {
    uVar5 = uVar5 ^ 0x100000;
    if (uVar7 == 0) {
      uVar9 = uVar9 ^ 0x100000;
      uVar7 = 1;
    }
    else {
      uVar10 = uVar10 - 1;
    }
  }
  uVar12 = -uVar10 + 0x20;
  if ((int)uVar10 < 0x21) {
    uVar11 = param_3 << (uVar12 & 0xff);
    param_3 = param_3 >> (uVar10 & 0xff);
    uVar3 = uVar8 + param_3;
    uVar4 = uVar5 << (uVar12 & 0xff);
    uVar12 = uVar3 + uVar4;
    uVar9 = uVar9 + CARRY4(uVar8,param_3) + ((int)uVar5 >> (uVar10 & 0xff)) +
            (uint)CARRY4(uVar3,uVar4);
  }
  else {
    uVar11 = uVar5 << (-uVar10 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar11 = uVar11 | 2;
    }
    uVar5 = (int)uVar5 >> (uVar10 - 0x20 & 0xff);
    uVar12 = uVar8 + uVar5;
    uVar9 = uVar9 + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar8,uVar5);
  }
  param_2 = uVar9 & 0x80000000;
  uVar10 = uVar9;
  if ((int)uVar9 < 0) {
    bVar14 = uVar11 == 0;
    uVar11 = -uVar11;
    uVar10 = -uVar12;
    uVar12 = -(uint)!bVar14 - uVar12;
    uVar10 = -(uint)(bVar14 <= uVar10) - uVar9;
  }
  if (0xfffff < uVar10) {
    uVar8 = uVar7 - 1;
    if (0x1fffff < uVar10) {
      uVar9 = uVar10 & 1;
      uVar10 = uVar10 >> 1;
      bVar2 = (byte)uVar12;
      uVar12 = (uint)(uVar9 != 0) << 0x1f | uVar12 >> 1;
      uVar11 = (uint)(bVar2 & 1) << 0x1f | uVar11 >> 1;
      uVar8 = uVar7;
      if (0xffbfffff < uVar7 * 0x200000) goto LAB_000056a4;
    }
LAB_00005570:
    bVar14 = 0x7fffffff < uVar11;
    if (uVar11 == 0x80000000) {
      bVar14 = (uVar12 & 1) != 0;
    }
    return CONCAT44(uVar10 + uVar8 * 0x100000 + (uint)CARRY4(uVar12,(uint)bVar14) | param_2,
                    uVar12 + bVar14);
  }
  bVar13 = (uVar11 & 0x80000000) != 0;
  uVar11 = uVar11 << 1;
  uVar8 = uVar12 * 2;
  bVar14 = CARRY4(uVar12,uVar12);
  uVar12 = uVar12 * 2 + (uint)bVar13;
  uVar10 = uVar10 * 2 + (uint)(bVar14 || CARRY4(uVar8,(uint)bVar13));
  uVar8 = uVar7 - 2;
  if (uVar7 - 1 != 0 && 0xfffff < uVar10) goto LAB_00005570;
  uVar5 = uVar12;
  uVar7 = uVar10;
  if (uVar10 == 0) {
    uVar5 = 0;
    uVar7 = uVar12;
  }
  iVar6 = LZCOUNT(uVar7);
  if (uVar10 == 0) {
    iVar6 = iVar6 + 0x20;
  }
  uVar12 = iVar6 - 0xb;
  bVar15 = SBORROW4(uVar12,0x20);
  uVar10 = iVar6 - 0x2b;
  bVar14 = (int)uVar10 < 0;
  bVar13 = uVar10 == 0;
  if ((int)uVar12 < 0x20) {
    bVar15 = SCARRY4(uVar10,0xc);
    iVar6 = iVar6 + -0x1f;
    bVar14 = iVar6 < 0;
    bVar13 = iVar6 == 0;
    uVar10 = uVar12;
    if (!bVar13 && bVar14 == bVar15) {
      uVar5 = uVar7 << (uVar12 & 0xff);
      uVar7 = uVar7 >> (0xcU - iVar6 & 0xff);
      goto LAB_000055e8;
    }
  }
  if (bVar13 || bVar14 != bVar15) {
    uVar11 = 0x20 - uVar10;
  }
  uVar7 = uVar7 << (uVar10 & 0xff);
  if (bVar13 || bVar14 != bVar15) {
    uVar7 = uVar7 | uVar5 >> (uVar11 & 0xff);
    uVar5 = uVar5 << (uVar10 & 0xff);
  }
LAB_000055e8:
  if ((int)uVar12 <= (int)uVar8) {
    return CONCAT44(uVar7 + (uVar8 - uVar12) * 0x100000 | param_2,uVar5);
  }
  uVar10 = ~(uVar8 - uVar12);
  if ((int)uVar10 < 0x1f) {
    iVar6 = uVar10 - 0x13;
    if (iVar6 != 0 && iVar6 < 0 == SCARRY4(uVar10 - 0x1f,0xc)) {
      return CONCAT44(uVar9,uVar5 >> (0x20 - (0xcU - iVar6) & 0xff) | uVar7 << (0xcU - iVar6 & 0xff)
                     ) & 0x80000000ffffffff;
    }
    uVar10 = uVar10 + 1;
    return CONCAT44(param_2 | uVar7 >> (uVar10 & 0xff),
                    uVar5 >> (uVar10 & 0xff) | uVar7 << (0x20 - uVar10 & 0xff));
  }
  return CONCAT44(uVar9,uVar7 >> (uVar10 - 0x1f & 0xff)) & 0x80000000ffffffff;
}




ulonglong FUN_000056dc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint in_r12;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = 0;
  iVar3 = LZCOUNT(param_1);
  uVar4 = iVar3 + 0x15;
  bVar7 = SBORROW4(uVar4,0x20);
  uVar2 = iVar3 - 0xb;
  bVar5 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  if (uVar4 < 0x20) {
    bVar7 = SCARRY4(uVar2,0xc);
    bVar5 = false;
    bVar6 = iVar3 + 1 == 0;
    uVar2 = uVar4;
    if (!bVar6 && bVar7 == false) {
      uVar1 = param_1 << uVar4;
      param_1 = param_1 >> (0xcU - (iVar3 + 1) & 0xff);
      goto LAB_000055e8;
    }
  }
  if (bVar6 || bVar5 != bVar7) {
    in_r12 = 0x20 - uVar2;
  }
  param_1 = param_1 << (uVar2 & 0xff);
  if (bVar6 || bVar5 != bVar7) {
    param_1 = param_1 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar2 & 0xff);
  }
LAB_000055e8:
  if (uVar4 < 0x433) {
    return CONCAT44(param_1 + (0x432 - uVar4) * 0x100000,uVar1);
  }
  uVar2 = ~(0x432 - uVar4);
  if (0x1e < (int)uVar2) {
    return (ulonglong)(param_1 >> (uVar2 - 0x1f & 0xff));
  }
  iVar3 = uVar2 - 0x13;
  if (iVar3 == 0 || iVar3 < 0 != SCARRY4(uVar2 - 0x1f,0xc)) {
    uVar2 = uVar2 + 1;
    return CONCAT44(param_1 >> (uVar2 & 0xff),
                    uVar1 >> (uVar2 & 0xff) | param_1 << (0x20 - uVar2 & 0xff));
  }
  return (ulonglong)(uVar1 >> (0x20 - (0xcU - iVar3) & 0xff) | param_1 << (0xcU - iVar3 & 0xff));
}




ulonglong FUN_000056fc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint in_r12;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar6 = param_1 & 0x80000000;
  uVar2 = param_1;
  if ((int)uVar6 < 0) {
    uVar2 = -param_1;
  }
  uVar1 = 0;
  iVar4 = LZCOUNT(uVar2);
  uVar5 = iVar4 + 0x15;
  bVar9 = SBORROW4(uVar5,0x20);
  uVar3 = iVar4 - 0xb;
  bVar7 = (int)uVar3 < 0;
  bVar8 = uVar3 == 0;
  if (uVar5 < 0x20) {
    bVar9 = SCARRY4(uVar3,0xc);
    bVar7 = false;
    bVar8 = iVar4 + 1 == 0;
    uVar3 = uVar5;
    if (!bVar8 && bVar9 == false) {
      uVar1 = uVar2 << uVar5;
      uVar2 = uVar2 >> (0xcU - (iVar4 + 1) & 0xff);
      goto LAB_000055e8;
    }
  }
  if (bVar8 || bVar7 != bVar9) {
    in_r12 = 0x20 - uVar3;
  }
  uVar2 = uVar2 << (uVar3 & 0xff);
  if (bVar8 || bVar7 != bVar9) {
    uVar2 = uVar2 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar3 & 0xff);
  }
LAB_000055e8:
  if (uVar5 < 0x433) {
    return CONCAT44(uVar2 + (0x432 - uVar5) * 0x100000 | uVar6,uVar1);
  }
  uVar3 = ~(0x432 - uVar5);
  if (0x1e < (int)uVar3) {
    return CONCAT44(param_1,uVar2 >> (uVar3 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  iVar4 = uVar3 - 0x13;
  if (iVar4 == 0 || iVar4 < 0 != SCARRY4(uVar3 - 0x1f,0xc)) {
    uVar3 = uVar3 + 1;
    return CONCAT44(uVar6 | uVar2 >> (uVar3 & 0xff),
                    uVar1 >> (uVar3 & 0xff) | uVar2 << (0x20 - uVar3 & 0xff));
  }
  return CONCAT44(param_1,uVar1 >> (0x20 - (0xcU - iVar4) & 0xff) | uVar2 << (0xcU - iVar4 & 0xff))
         & 0x80000000ffffffff;
}




ulonglong FUN_00005720(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint in_r12;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  uVar5 = param_1 << 1;
  bVar9 = uVar5 == 0;
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f;
  uVar4 = (uint)((int)uVar5 >> 3) >> 1;
  uVar3 = uVar1 | uVar4;
  param_1 = param_1 << 0x1d;
  if (!bVar9) {
    param_4 = uVar5 & 0xff000000;
    bVar9 = param_4 == 0;
  }
  if (!bVar9) {
    bVar9 = param_4 == 0xff000000;
  }
  if (!bVar9) {
    return CONCAT44(uVar3,param_1) ^ 0x3800000000000000;
  }
  if ((uVar5 & 0xffffff) == 0) {
    return CONCAT44(uVar3,param_1);
  }
  if (param_4 == 0xff000000) {
    return CONCAT44(uVar3,param_1) | 0x8000000000000;
  }
  uVar2 = param_1;
  uVar5 = uVar4;
  if (uVar4 == 0) {
    uVar2 = 0;
    uVar5 = param_1;
  }
  iVar6 = LZCOUNT(uVar5);
  if (uVar4 == 0) {
    iVar6 = iVar6 + 0x20;
  }
  uVar7 = iVar6 - 0xb;
  bVar10 = SBORROW4(uVar7,0x20);
  uVar4 = iVar6 - 0x2b;
  bVar9 = (int)uVar4 < 0;
  bVar8 = uVar4 == 0;
  if ((int)uVar7 < 0x20) {
    bVar10 = SCARRY4(uVar4,0xc);
    iVar6 = iVar6 + -0x1f;
    bVar9 = iVar6 < 0;
    bVar8 = iVar6 == 0;
    uVar4 = uVar7;
    if (!bVar8 && bVar9 == bVar10) {
      uVar2 = uVar5 << (uVar7 & 0xff);
      uVar5 = uVar5 >> (0xcU - iVar6 & 0xff);
      goto LAB_000055e8;
    }
  }
  if (bVar8 || bVar9 != bVar10) {
    in_r12 = 0x20 - uVar4;
  }
  uVar5 = uVar5 << (uVar4 & 0xff);
  if (bVar8 || bVar9 != bVar10) {
    uVar5 = uVar5 | uVar2 >> (in_r12 & 0xff);
    uVar2 = uVar2 << (uVar4 & 0xff);
  }
LAB_000055e8:
  if ((int)uVar7 < 0x381) {
    return CONCAT44(uVar5 + (0x380 - uVar7) * 0x100000 | uVar1,uVar2);
  }
  uVar4 = ~(0x380 - uVar7);
  if (0x1e < (int)uVar4) {
    return CONCAT44(uVar3,uVar5 >> (uVar4 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  iVar6 = uVar4 - 0x13;
  if (iVar6 == 0 || iVar6 < 0 != SCARRY4(uVar4 - 0x1f,0xc)) {
    uVar4 = uVar4 + 1;
    return CONCAT44(uVar1 | uVar5 >> (uVar4 & 0xff),
                    uVar2 >> (uVar4 & 0xff) | uVar5 << (0x20 - uVar4 & 0xff));
  }
  return CONCAT44(uVar3,uVar2 >> (0x20 - (0xcU - iVar6) & 0xff) | uVar5 << (0xcU - iVar6 & 0xff)) &
         0x80000000ffffffff;
}




ulonglong FUN_000057d0(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint unaff_r5;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  ulonglong uVar12;
  
  uVar12 = CONCAT44(param_2,param_1);
  uVar7 = 0x7ff;
  uVar4 = param_2 >> 0x14 & 0x7ff;
  bVar9 = uVar4 == 0;
  if (!bVar9) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar9 = unaff_r5 == 0;
  }
  if (!bVar9) {
    bVar9 = uVar4 == 0x7ff;
  }
  if (!bVar9) {
    bVar9 = unaff_r5 == 0x7ff;
  }
  if (bVar9) {
    uVar12 = FUN_000059ac();
  }
  uVar3 = (uint)(uVar12 >> 0x20);
  iVar5 = uVar4 + unaff_r5;
  uVar4 = uVar3 ^ param_4;
  uVar3 = uVar3 & ~(uVar7 << 0x15);
  param_4 = param_4 & ~(uVar7 << 0x15);
  bVar9 = ((uint)uVar12 | uVar3 << 0xc) == 0;
  if (!bVar9) {
    bVar9 = (param_3 | param_4 << 0xc) == 0;
  }
  uVar3 = uVar3 | 0x100000;
  param_4 = param_4 | 0x100000;
  if (bVar9) {
    param_3 = (uint)uVar12 | param_3;
    param_4 = (uVar4 & 0x80000000 | uVar3) ^ param_4;
    uVar4 = uVar7 >> 1;
    bVar11 = SBORROW4(iVar5,uVar4);
    uVar6 = iVar5 - uVar4;
    bVar9 = uVar6 == 0;
    uVar3 = uVar6;
    if (!bVar9 && (int)uVar4 <= iVar5) {
      bVar11 = SBORROW4(uVar7,uVar6);
      uVar3 = uVar7 - uVar6;
      bVar9 = uVar7 == uVar6;
    }
    if (!bVar9 && (int)uVar3 < 0 == bVar11) {
      return CONCAT44(param_4 | uVar6 * 0x100000,param_3);
    }
    param_4 = param_4 | 0x100000;
    uVar7 = 0;
    bVar11 = SBORROW4(uVar6,1);
    uVar6 = uVar6 - 1;
    bVar9 = uVar6 == 0;
    uVar4 = uVar6;
  }
  else {
    uVar1 = (uVar12 & 0xffffffff) * (ulonglong)param_3;
    uVar12 = (uVar12 & 0xffffffff) * (ulonglong)param_4 +
             (ulonglong)uVar3 * (ulonglong)param_3 + (uVar1 >> 0x20);
    uVar8 = (uint)uVar12;
    lVar2 = (ulonglong)uVar3 * (ulonglong)param_4 + (uVar12 >> 0x20);
    uVar7 = (uint)lVar2;
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    if ((int)uVar1 != 0) {
      uVar8 = uVar8 | 1;
    }
    uVar6 = (iVar5 + -0x3ff) - (uint)(uVar3 < 0x200);
    if (uVar3 < 0x200) {
      bVar9 = (uVar8 & 0x80000000) != 0;
      uVar8 = uVar8 << 1;
      lVar2 = CONCAT44(uVar3 * 2 + (uint)(CARRY4(uVar7,uVar7) || CARRY4(uVar7 * 2,(uint)bVar9)),
                       uVar7 * 2 + (uint)bVar9);
    }
    param_4 = uVar4 & 0x80000000 | (int)((ulonglong)lVar2 >> 0x20) << 0xb | (uint)lVar2 >> 0x15;
    param_3 = (uint)lVar2 << 0xb | uVar8 >> 0x15;
    uVar7 = uVar8 * 0x800;
    bVar10 = 0xfc < uVar6;
    bVar11 = SBORROW4(uVar6,0xfd);
    uVar3 = uVar6 - 0xfd;
    bVar9 = uVar3 == 0;
    uVar4 = uVar3;
    if (bVar10 && !bVar9) {
      bVar10 = 0x6ff < uVar3;
      bVar11 = SBORROW4(uVar3,0x700);
      uVar4 = uVar6 - 0x7fd;
      bVar9 = uVar3 == 0x700;
    }
    if (!bVar10 || bVar9) {
      bVar9 = 0x7fffffff < uVar7;
      if (uVar7 == 0x80000000) {
        bVar9 = (uVar8 >> 0x15 & 1) != 0;
      }
      return CONCAT44(param_4 + uVar6 * 0x100000 + (uint)CARRY4(param_3,(uint)bVar9),param_3 + bVar9
                     );
    }
  }
  if (!bVar9 && (int)uVar4 < 0 == bVar11) {
    return (ulonglong)(param_4 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if (uVar6 != 0xffffffca && (int)(uVar6 + 0x36) < 0 == SCARRY4(uVar6,0x36)) {
    uVar4 = -uVar6;
    uVar3 = uVar4 - 0x20;
    if (0x1f < (int)uVar4) {
      uVar6 = param_3 >> (uVar3 & 0xff) | param_4 << (0x20 - uVar3 & 0xff);
      uVar4 = (param_4 >> (uVar3 & 0xff) & ~((param_4 & 0x80000000) >> (uVar3 & 0xff))) -
              ((int)uVar6 >> 0x1f);
      if ((uVar7 | param_3 << (0x20 - uVar3 & 0xff) | uVar6 << 1) == 0) {
        uVar4 = uVar4 & ~(uVar6 >> 0x1f);
      }
      return CONCAT44(param_4,uVar4) & 0x80000000ffffffff;
    }
    iVar5 = uVar4 - 0x14;
    if (iVar5 != 0 && iVar5 < 0 == SCARRY4(uVar3,0xc)) {
      uVar4 = 0xc - iVar5;
      uVar6 = param_3 << (uVar4 & 0xff);
      uVar4 = param_3 >> (0x20 - uVar4 & 0xff) | param_4 << (uVar4 & 0xff);
      uVar3 = uVar4 + -((int)uVar6 >> 0x1f);
      if ((uVar7 | uVar6 << 1) == 0) {
        uVar3 = uVar3 & ~(uVar6 >> 0x1f);
      }
      return CONCAT44((param_4 & 0x80000000) + (uint)CARRY4(uVar4,-((int)uVar6 >> 0x1f)),uVar3);
    }
    uVar8 = param_3 << (uVar6 + 0x20 & 0xff);
    uVar3 = param_3 >> (uVar4 & 0xff) | param_4 << (uVar6 + 0x20 & 0xff);
    uVar6 = uVar3 + -((int)uVar8 >> 0x1f);
    if ((uVar7 | uVar8 << 1) == 0) {
      uVar6 = uVar6 & ~(uVar8 >> 0x1f);
    }
    return CONCAT44((param_4 & 0x80000000) +
                    ((param_4 & 0x7fffffff) >> (uVar4 & 0xff)) +
                    (uint)CARRY4(uVar3,-((int)uVar8 >> 0x1f)),uVar6);
  }
  return (ulonglong)(param_4 & 0x80000000) << 0x20;
}




ulonglong FUN_000059ac(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint unaff_r4;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  bool bVar4;
  
  uVar2 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 != in_r12 && uVar2 != in_r12) {
    bVar4 = (param_1 | param_2 << 1) == 0;
    if (!bVar4) {
      bVar4 = (param_3 | param_4 << 1) == 0;
    }
    if (bVar4) {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    if (unaff_r4 == 0) {
      uVar3 = param_2 & 0x80000000;
      do {
        uVar1 = param_1 & 0x80000000;
        param_1 = param_1 << 1;
        param_2 = param_2 * 2 + (uint)(uVar1 != 0);
      } while ((param_2 & 0x100000) == 0);
      param_2 = param_2 | uVar3;
      if (uVar2 != 0) {
        return CONCAT44(param_2,param_1);
      }
    }
    do {
      uVar2 = param_3 & 0x80000000;
      param_3 = param_3 << 1;
      param_4 = param_4 * 2 + (uint)(uVar2 != 0);
    } while ((param_4 & 0x100000) == 0);
    return CONCAT44(param_2,param_1);
  }
  bVar4 = (param_1 | param_2 << 1) == 0;
  if (bVar4) {
    param_2 = param_4;
    param_1 = param_3;
  }
  if (!bVar4) {
    bVar4 = (param_3 | param_4 << 1) == 0;
  }
  uVar3 = param_2;
  if (((!bVar4) && ((unaff_r4 != in_r12 || ((param_1 | param_2 << 0xc) == 0)))) &&
     ((uVar2 != in_r12 || (param_1 = param_3, uVar3 = param_4, (param_3 | param_4 << 0xc) == 0)))) {
    return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}




ulonglong FUN_00005a24(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined8 uVar16;
  
  uVar16 = CONCAT44(param_2,param_1);
  uVar12 = 0x7ff;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar13 = uVar6 == 0;
  if (!bVar13) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar13 = unaff_r5 == 0;
  }
  if (!bVar13) {
    bVar13 = uVar6 == 0x7ff;
  }
  if (!bVar13) {
    bVar13 = unaff_r5 == 0x7ff;
  }
  if (bVar13) {
    uVar16 = FUN_00005b92();
  }
  uVar8 = (uint)((ulonglong)uVar16 >> 0x20);
  uVar10 = (uint)uVar16;
  iVar7 = uVar6 - unaff_r5;
  if ((param_3 | param_4 << 0xc) == 0) {
    uVar6 = (uVar8 ^ param_4) & 0x80000000 | uVar8 & 0xfffff;
    bVar15 = SCARRY4(iVar7,uVar12 >> 1);
    uVar8 = iVar7 + (uVar12 >> 1);
    bVar13 = (int)uVar8 < 0;
    bVar14 = uVar8 == 0;
    if (!bVar14 && bVar13 == bVar15) {
      bVar15 = SBORROW4(uVar12,uVar8);
      bVar13 = (int)(uVar12 - uVar8) < 0;
      bVar14 = uVar12 == uVar8;
    }
    if (!bVar14 && bVar13 == bVar15) {
      return CONCAT44(uVar6 | uVar8 * 0x100000,uVar10);
    }
    uVar6 = uVar6 | 0x100000;
    uVar12 = 0;
    bVar14 = SBORROW4(uVar8,1);
    uVar8 = uVar8 - 1;
    bVar13 = uVar8 == 0;
    uVar3 = uVar8;
  }
  else {
    uVar3 = (param_4 << 0xc) >> 4 | 0x10000000 | param_3 >> 0x18;
    uVar12 = param_3 << 8;
    uVar9 = (uVar8 << 0xc) >> 4 | 0x10000000 | uVar10 >> 0x18;
    uVar10 = uVar10 * 0x100;
    uVar6 = (uVar8 ^ param_4) & 0x80000000;
    bVar13 = uVar3 <= uVar9;
    if (uVar9 == uVar3) {
      bVar13 = uVar12 <= uVar10;
    }
    iVar7 = iVar7 + (uint)bVar13;
    uVar8 = iVar7 + 0x3fd;
    if (bVar13 == false) {
      uVar3 = uVar3 >> 1;
      uVar12 = (uint)((param_3 >> 0x18 & 1) != 0) << 0x1f | uVar12 >> 1;
    }
    uVar11 = uVar10 - uVar12;
    uVar9 = (uVar9 - uVar3) - (uint)(uVar10 < uVar12);
    uVar4 = uVar3 >> 1;
    uVar1 = (uint)((uVar3 & 1) != 0) << 0x1f | uVar12 >> 1;
    uVar10 = 0x100000;
    uVar3 = 0x80000;
    while( true ) {
      bVar13 = uVar1 <= uVar11;
      if (uVar4 < uVar9 || uVar9 - uVar4 < (uint)bVar13) {
        uVar11 = uVar11 - uVar1;
        uVar10 = uVar10 | uVar3;
        uVar9 = (uVar9 - uVar4) - (uint)!bVar13;
      }
      uVar5 = uVar4 >> 1;
      uVar1 = (uint)((uVar4 & 1) != 0) << 0x1f | uVar1 >> 1;
      bVar14 = uVar1 <= uVar11;
      bVar13 = uVar9 - uVar5 < (uint)bVar14;
      uVar12 = uVar9;
      if (uVar5 < uVar9 || bVar13) {
        uVar11 = uVar11 - uVar1;
        uVar12 = (uVar9 - uVar5) - (uint)!bVar14;
      }
      if (uVar5 < uVar9 || bVar13) {
        uVar10 = uVar10 | uVar3 >> 1;
      }
      uVar9 = uVar4 >> 2;
      uVar2 = (uint)((uVar5 & 1) != 0) << 0x1f | uVar1 >> 1;
      bVar14 = uVar2 <= uVar11;
      bVar13 = uVar12 - uVar9 < (uint)bVar14;
      uVar5 = uVar12;
      if (uVar9 < uVar12 || bVar13) {
        uVar11 = uVar11 - uVar2;
        uVar5 = (uVar12 - uVar9) - (uint)!bVar14;
      }
      if (uVar9 < uVar12 || bVar13) {
        uVar10 = uVar10 | uVar3 >> 2;
      }
      uVar4 = uVar4 >> 3;
      uVar1 = (uint)((uVar9 & 1) != 0) << 0x1f | uVar2 >> 1;
      bVar14 = uVar1 <= uVar11;
      bVar13 = uVar5 - uVar4 < (uint)bVar14;
      uVar9 = uVar5;
      if (uVar4 < uVar5 || bVar13) {
        uVar11 = uVar11 - uVar1;
        uVar9 = (uVar5 - uVar4) - (uint)!bVar14;
      }
      if (uVar4 < uVar5 || bVar13) {
        uVar10 = uVar10 | uVar3 >> 3;
      }
      uVar12 = uVar9 | uVar11;
      if (uVar12 == 0) break;
      uVar9 = uVar9 << 4 | uVar11 >> 0x1c;
      uVar11 = uVar11 << 4;
      uVar4 = uVar4 << 3 | uVar1 >> 0x1d;
      uVar1 = (uVar2 >> 1) << 3;
      uVar3 = uVar3 >> 4;
      if (uVar3 == 0) {
        if ((uVar6 & 0x100000) != 0) goto LAB_00005b42;
        uVar6 = uVar6 | uVar10;
        uVar10 = 0;
        uVar3 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar10;
      uVar10 = 0;
    }
LAB_00005b42:
    bVar15 = 0xfc < uVar8;
    bVar14 = SBORROW4(uVar8,0xfd);
    uVar5 = iVar7 + 0x300;
    bVar13 = uVar5 == 0;
    uVar3 = uVar5;
    if (bVar15 && !bVar13) {
      bVar15 = 0x6ff < uVar5;
      bVar14 = SBORROW4(uVar5,0x700);
      uVar3 = iVar7 - 0x400;
      bVar13 = uVar5 == 0x700;
    }
    if (!bVar15 || bVar13) {
      bVar13 = uVar4 <= uVar9;
      if (uVar9 == uVar4) {
        bVar13 = uVar1 <= uVar11;
      }
      if (uVar9 == uVar4 && uVar11 == uVar1) {
        bVar13 = (uVar10 & 1) != 0;
      }
      return CONCAT44(uVar6 + uVar8 * 0x100000 + (uint)CARRY4(uVar10,(uint)bVar13),uVar10 + bVar13);
    }
  }
  if (!bVar13 && (int)uVar3 < 0 == bVar14) {
    return (ulonglong)(uVar6 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if (uVar8 == 0xffffffca || (int)(uVar8 + 0x36) < 0 != SCARRY4(uVar8,0x36)) {
    return (ulonglong)(uVar6 & 0x80000000) << 0x20;
  }
  uVar3 = -uVar8;
  uVar9 = uVar3 - 0x20;
  if (0x1f < (int)uVar3) {
    uVar3 = uVar10 >> (uVar9 & 0xff) | uVar6 << (0x20 - uVar9 & 0xff);
    uVar8 = (uVar6 >> (uVar9 & 0xff) & ~((uVar6 & 0x80000000) >> (uVar9 & 0xff))) -
            ((int)uVar3 >> 0x1f);
    if ((uVar12 | uVar10 << (0x20 - uVar9 & 0xff) | uVar3 << 1) == 0) {
      uVar8 = uVar8 & ~(uVar3 >> 0x1f);
    }
    return CONCAT44(uVar6,uVar8) & 0x80000000ffffffff;
  }
  iVar7 = uVar3 - 0x14;
  if (iVar7 != 0 && iVar7 < 0 == SCARRY4(uVar9,0xc)) {
    uVar8 = 0xc - iVar7;
    uVar3 = uVar10 << (uVar8 & 0xff);
    uVar10 = uVar10 >> (0x20 - uVar8 & 0xff) | uVar6 << (uVar8 & 0xff);
    uVar8 = uVar10 + -((int)uVar3 >> 0x1f);
    if ((uVar12 | uVar3 << 1) == 0) {
      uVar8 = uVar8 & ~(uVar3 >> 0x1f);
    }
    return CONCAT44((uVar6 & 0x80000000) + (uint)CARRY4(uVar10,-((int)uVar3 >> 0x1f)),uVar8);
  }
  uVar9 = uVar10 << (uVar8 + 0x20 & 0xff);
  uVar10 = uVar10 >> (uVar3 & 0xff) | uVar6 << (uVar8 + 0x20 & 0xff);
  uVar8 = uVar10 + -((int)uVar9 >> 0x1f);
  if ((uVar12 | uVar9 << 1) == 0) {
    uVar8 = uVar8 & ~(uVar9 >> 0x1f);
  }
  return CONCAT44((uVar6 & 0x80000000) +
                  ((uVar6 & 0x7fffffff) >> (uVar3 & 0xff)) +
                  (uint)CARRY4(uVar10,-((int)uVar9 >> 0x1f)),uVar8);
}




ulonglong FUN_00005b92(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint unaff_r4;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  bool bVar4;
  
  uVar2 = in_r12 & param_4 >> 0x14;
  uVar3 = param_2;
  if (unaff_r4 != in_r12 || uVar2 != in_r12) {
    if (unaff_r4 == in_r12) {
      if (((param_1 | param_2 << 0xc) == 0) && (param_1 = param_3, uVar3 = param_4, uVar2 != in_r12)
         ) {
LAB_00005a04:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else if (uVar2 == in_r12) {
      param_1 = param_3;
      uVar3 = param_4;
      if ((param_3 | param_4 << 0xc) == 0) {
LAB_000059c8:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
    }
    else {
      bVar4 = (param_1 | param_2 << 1) == 0;
      if (!bVar4) {
        bVar4 = (param_3 | param_4 << 1) == 0;
      }
      if (!bVar4) {
        if (unaff_r4 == 0) {
          uVar3 = param_2 & 0x80000000;
          do {
            uVar1 = param_1 & 0x80000000;
            param_1 = param_1 << 1;
            param_2 = param_2 * 2 + (uint)(uVar1 != 0);
          } while ((param_2 & 0x100000) == 0);
          param_2 = param_2 | uVar3;
          if (uVar2 != 0) {
            return CONCAT44(param_2,param_1);
          }
        }
        do {
          uVar3 = param_3 & 0x80000000;
          param_3 = param_3 << 1;
          param_4 = param_4 * 2 + (uint)(uVar3 != 0);
        } while ((param_4 & 0x100000) == 0);
        return CONCAT44(param_2,param_1);
      }
      if ((param_1 | param_2 << 1) != 0) goto LAB_00005a04;
      if ((param_3 | param_4 << 1) != 0) goto LAB_000059c8;
    }
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}




uint FUN_00005c04(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (((int)(param_2 << 1) >> 0x15 == -1 || (int)(param_4 << 1) >> 0x15 == -1) &&
     ((((int)(param_2 << 1) >> 0x15 == -1 && ((param_1 | param_2 << 0xc) != 0)) ||
      (((int)(param_4 << 1) >> 0x15 == -1 && ((param_3 | param_4 << 0xc) != 0)))))) {
    return 1;
  }
  bVar2 = (param_1 | param_2 << 1) == 0;
  if (bVar2) {
    bVar2 = (param_3 | param_4 << 1) == 0;
  }
  if (!bVar2) {
    bVar2 = param_2 == param_4;
  }
  if (bVar2) {
    bVar2 = param_1 == param_3;
  }
  if (!bVar2) {
    uVar1 = param_2 ^ param_4;
    bVar2 = uVar1 == 0;
    if (-1 < (int)uVar1) {
      bVar2 = param_2 == param_4;
    }
    bVar3 = -1 < (int)uVar1 && param_4 <= param_2;
    if (bVar2) {
      bVar3 = param_3 <= param_1;
    }
    param_4 = (int)param_4 >> 0x1f;
    if (!bVar3) {
      param_4 = ~param_4;
    }
    return param_4 | 1;
  }
  return 0;
}




void FUN_00005c80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00005c90(param_3,param_4,param_1,param_2);
  return;
}




undefined4 FUN_00005c90(undefined4 param_1)

{
  FUN_00005c04();
  return param_1;
}




bool FUN_00005cb4(void)

{
  char in_CY;
  
  FUN_00005c90();
  return in_CY == '\0';
}




bool FUN_00005cdc(void)

{
  undefined in_ZR;
  undefined in_CY;
  
  FUN_00005c80();
  return !(bool)in_CY || (bool)in_ZR;
}




bool FUN_00005cf0(void)

{
  char in_CY;
  
  FUN_00005c80();
  return in_CY == '\0';
}




uint FUN_00005d04(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar2) {
      return 0;
    }
    uVar1 = iVar2 >> 0x15;
    uVar3 = -uVar1 - 0x3e1;
    if (uVar1 < 0xfffffc20 && uVar3 != 0) {
      uVar1 = (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
      if ((param_2 & 0x80000000) != 0) {
        uVar1 = -uVar1;
      }
      return uVar1;
    }
  }
  else if ((param_1 | param_2 << 0xc) != 0) {
    return 0;
  }
  param_2 = param_2 & 0x80000000;
  if (param_2 == 0) {
    param_2 = 0x7fffffff;
  }
  return param_2;
}




uint FUN_00005d54(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 & 0x80000000) != 0) {
    return 0;
  }
  iVar1 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar1) {
      return 0;
    }
    uVar2 = -(iVar1 >> 0x15) - 0x3e1;
    if (-1 < (int)uVar2) {
      return (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff);
    }
  }
  else if ((param_1 | param_2 << 0xc) != 0) {
    return 0;
  }
  return 0xffffffff;
}




uint FUN_00005d9c(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar3 = param_2 ^ 0x80000000;
  uVar5 = param_1 << 1;
  bVar8 = uVar5 == 0;
  if (!bVar8) {
    param_4 = param_2 << 1;
    bVar8 = param_4 == 0;
  }
  if (!bVar8) {
    bVar8 = uVar5 == param_4;
  }
  iVar1 = (int)uVar5 >> 0x18;
  if (!bVar8) {
    bVar8 = iVar1 == -1;
  }
  if (!bVar8) {
    bVar8 = (int)param_4 >> 0x18 == -1;
  }
  if (bVar8) {
    iVar2 = (int)(param_2 << 1) >> 0x18;
    if (iVar1 == -1 || iVar2 == -1) {
      uVar5 = uVar3;
      if (iVar1 == -1) {
        uVar5 = param_1;
      }
      if (iVar1 != -1 || iVar2 != -1) {
        uVar3 = uVar5;
      }
      bVar8 = (uVar5 & 0x7fffff) == 0;
      if (bVar8) {
        bVar8 = (uVar3 & 0x7fffff) == 0;
      }
      if (bVar8) {
        bVar8 = uVar5 == uVar3;
      }
      if (!bVar8) {
        uVar5 = uVar5 | 0x400000;
      }
      return uVar5;
    }
    if (((param_1 ^ uVar3) & 0x7fffffff) != 0) {
      if (uVar5 == 0) {
        param_1 = uVar3;
      }
      return param_1;
    }
    if (param_1 != uVar3) {
      return 0;
    }
    if ((uVar5 & 0xff000000) == 0) {
      uVar3 = param_1 << 1;
      if ((param_1 & 0x80000000) != 0) {
        uVar3 = uVar3 | 0x80000000;
      }
      return uVar3;
    }
    if (uVar5 < 0xfe000000) {
      return param_1 + 0x800000;
    }
    param_1 = param_1 & 0x80000000;
LAB_00005ed6:
    return param_1 | 0x7f800000;
  }
  uVar5 = uVar5 >> 0x18;
  param_4 = param_4 >> 0x18;
  uVar7 = param_4 - uVar5;
  uVar4 = uVar3;
  uVar6 = uVar5;
  if (uVar7 != 0 && uVar5 <= param_4) {
    uVar6 = uVar5 + uVar7;
    uVar4 = param_1;
    param_1 = uVar3;
  }
  if (param_4 < uVar5) {
    uVar7 = -uVar7;
  }
  if (0x19 < uVar7) {
    return param_1;
  }
  uVar3 = param_1 & 0xffffff | 0x800000;
  if ((param_1 & 0x80000000) != 0) {
    uVar3 = -uVar3;
  }
  uVar5 = uVar4 & 0xffffff | 0x800000;
  if ((uVar4 & 0x80000000) != 0) {
    uVar5 = -uVar5;
  }
  if (uVar6 == uVar7) {
    uVar5 = uVar5 ^ 0x800000;
    if (uVar6 == 0) {
      uVar3 = uVar3 ^ 0x800000;
      uVar6 = 1;
    }
    else {
      uVar7 = uVar7 - 1;
    }
  }
  uVar3 = uVar3 + ((int)uVar5 >> (uVar7 & 0xff));
  uVar5 = uVar5 << (0x20 - uVar7 & 0xff);
  param_1 = uVar3 & 0x80000000;
  if ((int)uVar3 < 0) {
    bVar8 = uVar5 != 0;
    uVar5 = -uVar5;
    uVar3 = -uVar3 - (uint)bVar8;
  }
  if (uVar3 < 0x800000) {
    uVar7 = uVar5 & 0x80000000;
    uVar5 = uVar5 << 1;
    uVar3 = uVar3 * 2 + (uint)(uVar7 != 0);
    uVar7 = uVar6 - 2;
    if (uVar6 - 1 == 0 || uVar3 < 0x800000) {
      uVar5 = LZCOUNT(uVar3) - 8;
      uVar3 = uVar3 << (uVar5 & 0xff);
      if ((int)uVar7 < (int)uVar5) {
        uVar3 = uVar3 >> (-(uVar7 - uVar5) & 0xff);
      }
      else {
        uVar3 = uVar3 + (uVar7 - uVar5) * 0x800000;
      }
      return uVar3 | param_1;
    }
  }
  else {
    uVar7 = uVar6 - 1;
    if (0xffffff < uVar3) {
      uVar7 = uVar3 & 1;
      uVar3 = uVar3 >> 1;
      uVar5 = (uint)(uVar7 != 0) << 0x1f | uVar5 >> 1;
      uVar7 = uVar6;
      if (0xfd < uVar6) goto LAB_00005ed6;
    }
  }
  uVar3 = uVar3 + uVar7 * 0x800000 + (uint)(0x7fffffff < uVar5);
  if (uVar5 == 0x80000000) {
    uVar3 = uVar3 & 0xfffffffe;
  }
  return uVar3 | param_1;
}




uint FUN_00005f00(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = LZCOUNT(param_1);
  uVar2 = uVar1 - 8;
  iVar3 = uVar2 * -0x800000 + 0x4a800000;
  if (7 < uVar1) {
    uVar4 = 0 << (uVar2 & 0xff);
    uVar1 = iVar3 + (param_1 << (uVar2 & 0xff)) +
            (0U >> (0x20 - uVar2 & 0xff)) + (uint)(0x7fffffff < uVar4);
    if (uVar4 == 0x80000000) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    return uVar1;
  }
  uVar2 = param_1 << uVar1 + 0x18;
  uVar1 = iVar3 + ((param_1 >> (0x20 - (uVar1 + 0x18) & 0xff)) - ((int)uVar2 >> 0x1f));
  if ((uVar2 & 0x7fffffff) == 0) {
    uVar1 = uVar1 & ~(uVar2 >> 0x1f);
  }
  return uVar1;
}




uint FUN_00005f08(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 & 0x80000000;
  if ((int)uVar3 < 0) {
    param_1 = -param_1;
  }
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = LZCOUNT(param_1);
  uVar2 = uVar1 - 8;
  iVar4 = ((uVar3 | 0x4b000000) - 0x800000) + uVar2 * -0x800000;
  if (7 < uVar1) {
    uVar1 = 0 << (uVar2 & 0xff);
    uVar3 = iVar4 + (param_1 << (uVar2 & 0xff)) +
            (0U >> (0x20 - uVar2 & 0xff)) + (uint)(0x7fffffff < uVar1);
    if (uVar1 == 0x80000000) {
      uVar3 = uVar3 & 0xfffffffe;
    }
    return uVar3;
  }
  uVar2 = param_1 << uVar1 + 0x18;
  uVar3 = iVar4 + ((param_1 >> (0x20 - (uVar1 + 0x18) & 0xff)) - ((int)uVar2 >> 0x1f));
  if ((uVar2 & 0x7fffffff) == 0) {
    uVar3 = uVar3 & ~(uVar2 >> 0x1f);
  }
  return uVar3;
}




uint FUN_00005f24(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_1 | param_2) == 0) {
    return param_1;
  }
  uVar1 = param_1;
  uVar2 = param_2;
  if (param_2 == 0) {
    uVar1 = 0;
    uVar2 = param_1;
  }
  iVar5 = 0x5b000000;
  if (param_2 == 0) {
    iVar5 = 0x4b000000;
  }
  uVar3 = LZCOUNT(uVar2);
  uVar4 = uVar3 - 8;
  iVar5 = iVar5 + -0x800000 + uVar4 * -0x800000;
  if (uVar3 < 8) {
    uVar4 = uVar2 << uVar3 + 0x18;
    uVar2 = iVar5 + ((uVar2 >> (0x20 - (uVar3 + 0x18) & 0xff)) - ((int)uVar4 >> 0x1f));
    if ((uVar1 | uVar4 << 1) == 0) {
      uVar2 = uVar2 & ~(uVar4 >> 0x1f);
    }
    return uVar2;
  }
  uVar3 = uVar1 << (uVar4 & 0xff);
  uVar2 = iVar5 + (uVar2 << (uVar4 & 0xff)) +
          (uVar1 >> (0x20 - uVar4 & 0xff)) + (uint)(0x7fffffff < uVar3);
  if (uVar3 == 0x80000000) {
    uVar2 = uVar2 & 0xfffffffe;
  }
  return uVar2;
}




uint FUN_00005fb0(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  
  uVar3 = param_1 >> 0x17 & 0xff;
  bVar9 = uVar3 == 0;
  if (!bVar9) {
    param_4 = param_2 >> 0x17 & 0xff;
    bVar9 = param_4 == 0;
  }
  if (!bVar9) {
    bVar9 = uVar3 == 0xff;
  }
  if (!bVar9) {
    bVar9 = param_4 == 0xff;
  }
  if (bVar9) {
    param_4 = param_2 >> 0x17 & 0xff;
    if (uVar3 == 0xff || param_4 == 0xff) {
      bVar9 = param_1 == 0 || param_1 == 0x80000000;
      uVar2 = param_2;
      if (param_1 != 0 && param_1 != 0x80000000) {
        bVar9 = param_2 == 0;
        uVar2 = param_1;
      }
      if (!bVar9) {
        bVar9 = param_2 == 0x80000000;
      }
      uVar8 = uVar2;
      if (((bVar9) || ((uVar3 == 0xff && ((uVar2 & 0x7fffff) != 0)))) ||
         ((param_4 == 0xff && (uVar8 = param_2, (param_2 & 0x7fffff) != 0)))) {
        return uVar8 | 0x7fc00000;
      }
      uVar2 = uVar2 ^ param_2;
      goto LAB_00006100;
    }
    bVar9 = (param_1 & 0x7fffffff) == 0;
    if (!bVar9) {
      bVar9 = (param_2 & 0x7fffffff) == 0;
    }
    if (bVar9) {
      return (param_1 ^ param_2) & 0x80000000;
    }
    bVar9 = uVar3 == 0;
    uVar2 = param_1 & 0x80000000;
    while( true ) {
      if (bVar9) {
        param_1 = param_1 << 1;
        bVar9 = (param_1 & 0x800000) == 0;
      }
      if (!bVar9) break;
      uVar3 = uVar3 - 1;
    }
    param_1 = param_1 | uVar2;
    bVar9 = param_4 == 0;
    uVar2 = param_2 & 0x80000000;
    while( true ) {
      if (bVar9) {
        param_2 = param_2 << 1;
        bVar9 = (param_2 & 0x800000) == 0;
      }
      if (!bVar9) break;
      param_4 = param_4 - 1;
    }
    param_2 = param_2 | uVar2;
  }
  iVar4 = uVar3 + param_4;
  uVar8 = param_1 ^ param_2;
  uVar3 = param_1 << 9;
  bVar9 = uVar3 == 0;
  if (!bVar9) {
    param_2 = param_2 << 9;
    bVar9 = param_2 == 0;
  }
  if (bVar9) {
    if (uVar3 == 0) {
      param_2 = param_2 << 9;
    }
    uVar2 = uVar8 & 0x80000000 | param_1 & 0x7fffff | param_2 >> 9;
    bVar10 = SBORROW4(iVar4,0x7f);
    iVar5 = iVar4 + -0x7f;
    bVar9 = iVar5 == 0;
    iVar7 = iVar5;
    if (!bVar9 && 0x7e < iVar4) {
      bVar10 = SBORROW4(0xff,iVar5);
      iVar7 = 0xff - iVar5;
      bVar9 = iVar5 == 0xff;
    }
    if (!bVar9 && iVar7 < 0 == bVar10) {
      return uVar2 | iVar5 * 0x800000;
    }
    uVar2 = uVar2 | 0x800000;
    uVar6 = 0;
    bVar10 = SBORROW4(iVar5,1);
    uVar8 = iVar4 - 0x80;
    bVar9 = uVar8 == 0;
    uVar3 = uVar8;
  }
  else {
    lVar1 = (ulonglong)(uVar3 >> 5 | 0x8000000) * (ulonglong)(param_2 >> 5 | 0x8000000);
    uVar6 = (uint)lVar1;
    uVar2 = (uint)((ulonglong)lVar1 >> 0x20);
    bVar9 = uVar2 < 0x800000;
    if (bVar9) {
      uVar2 = uVar2 << 1;
    }
    if (bVar9) {
      uVar2 = uVar2 | uVar6 >> 0x1f;
      uVar6 = uVar6 << 1;
    }
    uVar2 = uVar8 & 0x80000000 | uVar2;
    uVar8 = (iVar4 + -0x7f) - (uint)bVar9;
    bVar10 = SBORROW4(uVar8,0xfd);
    bVar9 = uVar8 == 0xfd;
    uVar3 = uVar8 - 0xfd;
    if (uVar8 < 0xfe) {
      uVar2 = uVar2 + uVar8 * 0x800000 + (uint)(0x7fffffff < uVar6);
      if (uVar6 == 0x80000000) {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return uVar2;
    }
  }
  if (bVar9 || (int)uVar3 < 0 != bVar10) {
    if (uVar8 != 0xffffffe7 && (int)(uVar8 + 0x19) < 0 == SCARRY4(uVar8,0x19)) {
      uVar3 = (uVar2 << 1) >> (-uVar8 & 0xff);
      uVar8 = uVar2 << (uVar8 + 0x20 & 0xff);
      uVar3 = ((uint)((uVar2 & 0x80000000) != 0) << 0x1f | uVar3 >> 1) + (uint)((byte)uVar3 & 1);
      if ((uVar6 | uVar8 << 1) == 0) {
        uVar3 = uVar3 & ~(uVar8 >> 0x1f);
      }
      return uVar3;
    }
    return uVar2 & 0x80000000;
  }
LAB_00006100:
  return uVar2 & 0x80000000 | 0x7f800000;
}




uint FUN_00006118(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  uVar2 = param_1 >> 0x17 & 0xff;
  bVar7 = uVar2 == 0;
  if (!bVar7) {
    param_4 = param_2 >> 0x17 & 0xff;
    bVar7 = param_4 == 0;
  }
  if (!bVar7) {
    bVar7 = uVar2 == 0xff;
  }
  if (!bVar7) {
    bVar7 = param_4 == 0xff;
  }
  if (bVar7) {
    param_4 = param_2 >> 0x17 & 0xff;
    uVar6 = param_1;
    if (uVar2 == 0xff) {
      if (((param_1 & 0x7fffff) != 0) || (uVar6 = param_2, param_4 == 0xff)) {
LAB_0000610e:
        return uVar6 | 0x7fc00000;
      }
    }
    else {
      if (param_4 == 0xff) {
        uVar6 = param_2;
        if ((param_2 & 0x7fffff) == 0) {
LAB_000060c4:
          return (param_1 ^ param_2) & 0x80000000;
        }
        goto LAB_0000610e;
      }
      bVar7 = (param_1 & 0x7fffffff) == 0;
      if (!bVar7) {
        bVar7 = (param_2 & 0x7fffffff) == 0;
      }
      if (!bVar7) {
        bVar7 = uVar2 == 0;
        uVar6 = param_1 & 0x80000000;
        while( true ) {
          if (bVar7) {
            param_1 = param_1 << 1;
            bVar7 = (param_1 & 0x800000) == 0;
          }
          if (!bVar7) break;
          uVar2 = uVar2 - 1;
        }
        param_1 = param_1 | uVar6;
        bVar7 = param_4 == 0;
        uVar6 = param_2 & 0x80000000;
        while( true ) {
          if (bVar7) {
            param_2 = param_2 << 1;
            bVar7 = (param_2 & 0x800000) == 0;
          }
          if (!bVar7) break;
          param_4 = param_4 - 1;
        }
        param_2 = param_2 | uVar6;
        goto LAB_00006130;
      }
      if ((param_1 & 0x7fffffff) == 0) {
        if ((param_2 & 0x7fffffff) != 0) goto LAB_000060c4;
        goto LAB_0000610e;
      }
    }
    param_1 = param_1 ^ param_2;
  }
  else {
LAB_00006130:
    iVar3 = uVar2 - param_4;
    if (param_2 << 9 == 0) {
      param_1 = (param_1 ^ param_2) & 0x80000000 | param_1 & 0x7fffff;
      bVar9 = SCARRY4(iVar3,0x7f);
      iVar5 = iVar3 + 0x7f;
      bVar7 = iVar5 < 0;
      bVar8 = iVar5 == 0;
      if (!bVar8 && bVar7 == bVar9) {
        bVar9 = SBORROW4(0xff,iVar5);
        bVar7 = 0xff - iVar5 < 0;
        bVar8 = iVar5 == 0xff;
      }
      if (!bVar8 && bVar7 == bVar9) {
        return param_1 | iVar5 * 0x800000;
      }
      param_1 = param_1 | 0x800000;
      uVar2 = 0;
      bVar8 = SBORROW4(iVar5,1);
      uVar4 = iVar3 + 0x7e;
      bVar7 = uVar4 == 0;
      uVar6 = uVar4;
    }
    else {
      uVar1 = (param_2 << 9) >> 4 | 0x10000000;
      uVar2 = (param_1 << 9) >> 4 | 0x10000000;
      param_1 = (param_1 ^ param_2) & 0x80000000;
      bVar7 = uVar1 <= uVar2;
      if (!bVar7) {
        uVar2 = uVar2 << 1;
      }
      uVar4 = iVar3 + 0x7d + (uint)bVar7;
      uVar6 = 0x800000;
      do {
        if (uVar1 <= uVar2) {
          uVar2 = uVar2 - uVar1;
          param_1 = param_1 | uVar6;
        }
        bVar7 = uVar1 >> 1 <= uVar2;
        if (bVar7) {
          uVar2 = uVar2 - (uVar1 >> 1);
        }
        if (bVar7) {
          param_1 = param_1 | uVar6 >> 1;
        }
        bVar7 = uVar1 >> 2 <= uVar2;
        if (bVar7) {
          uVar2 = uVar2 - (uVar1 >> 2);
        }
        if (bVar7) {
          param_1 = param_1 | uVar6 >> 2;
        }
        bVar7 = uVar1 >> 3 <= uVar2;
        if (bVar7) {
          uVar2 = uVar2 - (uVar1 >> 3);
        }
        if (bVar7) {
          param_1 = param_1 | uVar6 >> 3;
        }
        uVar2 = uVar2 * 0x10;
        bVar7 = uVar2 == 0;
        if (!bVar7) {
          uVar6 = uVar6 >> 4;
          bVar7 = uVar6 == 0;
        }
      } while (!bVar7);
      bVar8 = SBORROW4(uVar4,0xfd);
      bVar7 = uVar4 == 0xfd;
      uVar6 = uVar4 - 0xfd;
      if (uVar4 < 0xfe) {
        param_1 = param_1 + uVar4 * 0x800000 + (uint)(uVar1 <= uVar2);
        if (uVar2 - uVar1 == 0) {
          param_1 = param_1 & 0xfffffffe;
        }
        return param_1;
      }
    }
    if (bVar7 || (int)uVar6 < 0 != bVar8) {
      if (uVar4 == 0xffffffe7 || (int)(uVar4 + 0x19) < 0 != SCARRY4(uVar4,0x19)) {
        return param_1 & 0x80000000;
      }
      uVar6 = (param_1 << 1) >> (-uVar4 & 0xff);
      uVar4 = param_1 << (uVar4 + 0x20 & 0xff);
      uVar6 = ((uint)((param_1 & 0x80000000) != 0) << 0x1f | uVar6 >> 1) + (uint)((byte)uVar6 & 1);
      if ((uVar2 | uVar4 << 1) == 0) {
        uVar6 = uVar6 & ~(uVar4 >> 0x1f);
      }
      return uVar6;
    }
  }
  return param_1 & 0x80000000 | 0x7f800000;
}




uint FUN_00006250(uint param_1)

{
  uint uVar1;
  
  if (((param_1 & 0x80000000) != 0) || (param_1 << 1 < 0x7f000000)) {
    return 0;
  }
  uVar1 = 0x9e - ((param_1 << 1) >> 0x18);
  if (-1 < (int)uVar1) {
    return (param_1 << 8 | 0x80000000) >> (uVar1 & 0xff);
  }
  if ((uVar1 == 0xffffff9f) && ((param_1 & 0x7fffff) != 0)) {
    return 0;
  }
  return 0xffffffff;
}




void FUN_00006290(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = FUN_00005720();
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  FUN_000057d0((int)uVar2,uVar1,0,DAT_000062c8);
  FUN_00005d54();
  uVar3 = FUN_000056dc();
  uVar3 = FUN_000057d0((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_000062cc);
  FUN_00005460((int)uVar2,uVar1,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  FUN_00005d54();
  return;
}




byte * FUN_000062d0(uint *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte *pbVar6;
  uint *puVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  
  param_2 = param_2 & 0xff;
  if ((int)param_3 < 0x10) {
joined_r0x00006330:
    do {
      if (param_3 == 0) {
        return (byte *)0x0;
      }
      puVar7 = (uint *)((int)param_1 + 1);
      bVar1 = *(byte *)param_1;
      param_3 = param_3 - 1;
      param_1 = puVar7;
    } while (bVar1 != param_2);
  }
  else {
    uVar9 = (uint)param_1 & 7;
    while( true ) {
      if (uVar9 == 0) {
        uVar9 = param_2 | param_2 << 8;
        uVar9 = uVar9 | uVar9 << 0x10;
        uVar10 = param_3 & 0xfffffff8;
        do {
          puVar7 = param_1 + 2;
          uVar10 = uVar10 - 8;
          uVar11 = *param_1 ^ uVar9;
          uVar12 = param_1[1] ^ uVar9;
          cVar2 = -((char)uVar11 == '\0');
          cVar3 = -((char)(uVar11 >> 8) == '\0');
          cVar4 = -((char)(uVar11 >> 0x10) == '\0');
          cVar5 = -((char)(uVar11 >> 0x18) == '\0');
          uVar11 = CONCAT13(cVar5,CONCAT12(cVar4,CONCAT11(cVar3,cVar2)));
          bVar13 = (char)uVar12 != '\0';
          bVar14 = (char)(uVar12 >> 8) != '\0';
          bVar15 = (char)(uVar12 >> 0x10) != '\0';
          bVar16 = (char)(uVar12 >> 0x18) != '\0';
          uVar12 = CONCAT13(bVar16 * cVar5 - !bVar16,
                            CONCAT12(bVar15 * cVar4 - !bVar15,
                                     CONCAT11(bVar14 * cVar3 - !bVar14,bVar13 * cVar2 - !bVar13)));
          if (uVar12 != 0) {
            if (uVar11 == 0) {
              pbVar8 = (byte *)((int)param_1 + 5);
              uVar11 = uVar12;
            }
            else {
              pbVar8 = (byte *)((int)param_1 + 1);
            }
            if ((uVar11 & 1) == 0) {
              bVar13 = (uVar11 & 0x100) == 0;
              pbVar6 = pbVar8 + 1;
              if (bVar13) {
                bVar13 = (uVar11 & 0x18000) == 0;
                pbVar6 = pbVar8 + 2;
              }
              pbVar8 = pbVar6;
              if (bVar13) {
                pbVar8 = pbVar8 + 1;
              }
            }
            return pbVar8 + -1;
          }
          param_1 = puVar7;
        } while (uVar10 != 0);
        param_3 = param_3 & 7;
        goto joined_r0x00006330;
      }
      puVar7 = (uint *)((int)param_1 + 1);
      param_3 = param_3 - 1;
      if (*(byte *)param_1 == param_2) break;
      uVar9 = (uint)puVar7 & 7;
      param_1 = puVar7;
      if (param_3 == 0) {
        return (byte *)0x0;
      }
    }
  }
  return (byte *)((int)puVar7 + -1);
}




undefined4 * FUN_00006370(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  puVar2 = param_1;
  if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
    if (param_3 < 8) {
      uVar5 = param_3 - 4;
      if (3 < param_3) {
        do {
          puVar1 = param_2;
          puVar3 = puVar2;
          bVar6 = uVar5 != 0;
          uVar5 = uVar5 - 1;
          *(undefined *)puVar3 = *(undefined *)puVar1;
          puVar2 = (undefined4 *)((int)puVar3 + 1);
          param_2 = (undefined4 *)((int)puVar1 + 1);
        } while (bVar6);
        *(undefined *)(undefined4 *)((int)puVar3 + 1) =
             *(undefined *)(undefined4 *)((int)puVar1 + 1);
        *(undefined *)((int)puVar3 + 2) = *(undefined *)((int)puVar1 + 2);
        *(undefined *)((int)puVar3 + 3) = *(undefined *)((int)puVar1 + 3);
        return param_1;
      }
      goto LAB_0000643c;
    }
    if ((((uint)param_2 & 3) != 0) && (((uint)param_1 & 3) != 0)) {
      uVar5 = 4 - ((uint)param_1 & 3);
      param_3 = param_3 - uVar5;
      puVar1 = param_1;
      puVar3 = param_2;
      if (((uint)param_1 & 1) != 0) {
        puVar3 = (undefined4 *)((int)param_2 + 1);
        puVar1 = (undefined4 *)((int)param_1 + 1);
        *(undefined *)param_1 = *(undefined *)param_2;
      }
      puVar2 = puVar1;
      param_2 = puVar3;
      if ((uVar5 & 2) != 0) {
        param_2 = (undefined4 *)((int)puVar3 + 2);
        puVar2 = (undefined4 *)((int)puVar1 + 2);
        *(undefined2 *)puVar1 = *(undefined2 *)puVar3;
      }
    }
  }
  while (0x3f < param_3) {
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = param_2[2];
    puVar2[3] = param_2[3];
    puVar2[4] = param_2[4];
    puVar2[5] = param_2[5];
    puVar2[6] = param_2[6];
    puVar2[7] = param_2[7];
    puVar2[8] = param_2[8];
    puVar2[9] = param_2[9];
    puVar2[10] = param_2[10];
    puVar2[0xb] = param_2[0xb];
    puVar2[0xc] = param_2[0xc];
    puVar2[0xd] = param_2[0xd];
    puVar2[0xe] = param_2[0xe];
    puVar2[0xf] = param_2[0xf];
    puVar2 = puVar2 + 0x10;
    param_2 = param_2 + 0x10;
    param_3 = param_3 - 0x40;
  }
  uVar4 = param_3 - 0x10;
  if (0xffffffcf < param_3 - 0x40) {
    do {
      *puVar2 = *param_2;
      puVar2[1] = param_2[1];
      puVar1 = param_2 + 3;
      puVar3 = puVar2 + 3;
      puVar2[2] = param_2[2];
      param_2 = param_2 + 4;
      puVar2 = puVar2 + 4;
      *puVar3 = *puVar1;
      bVar6 = 0xf < uVar4;
      uVar4 = uVar4 - 0x10;
    } while (bVar6);
  }
  uVar5 = uVar4 + 0xc;
  puVar3 = puVar2;
  puVar1 = param_2;
  if (0xfffffff3 < uVar4) {
    do {
      param_2 = puVar1 + 1;
      *puVar3 = *puVar1;
      bVar6 = 3 < uVar5;
      uVar5 = uVar5 - 4;
      puVar2 = puVar3 + 1;
      puVar3 = puVar3 + 1;
      puVar1 = param_2;
    } while (bVar6);
  }
LAB_0000643c:
  if (uVar5 + 4 != 0) {
    puVar1 = puVar2;
    puVar3 = param_2;
    if ((uVar5 & 1) != 0) {
      puVar3 = (undefined4 *)((int)param_2 + 1);
      puVar1 = (undefined4 *)((int)puVar2 + 1);
      *(undefined *)puVar2 = *(undefined *)param_2;
    }
    if ((uVar5 + 4 & 2) != 0) {
      *(undefined2 *)puVar1 = *(undefined2 *)puVar3;
    }
  }
  return param_1;
}




void FUN_000064a4(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_2 < param_1) && (puVar2 = (undefined4 *)((int)param_2 + param_3), param_1 < puVar2)) {
    puVar3 = (undefined *)((int)param_1 + param_3);
    if (param_3 != 0) {
      do {
        puVar2 = (undefined4 *)((int)puVar2 + -1);
        puVar3 = puVar3 + -1;
        *puVar3 = *(undefined *)puVar2;
      } while (param_2 != puVar2);
    }
  }
  else {
    uVar5 = param_3;
    if (0xf < param_3) {
      if ((((uint)param_1 | (uint)param_2) & 3) != 0) {
        iVar4 = param_3 - 1;
        goto LAB_000064d2;
      }
      uVar5 = param_3 - 0x10 >> 4;
      puVar2 = param_2 + 4;
      puVar1 = param_1 + 4;
      do {
        puVar1[-4] = puVar2[-4];
        puVar1[-3] = puVar2[-3];
        puVar1[-2] = puVar2[-2];
        puVar1[-1] = puVar2[-1];
        puVar2 = puVar2 + 4;
        puVar1 = puVar1 + 4;
      } while (puVar2 != param_2 + uVar5 * 4 + 8);
      iVar4 = uVar5 + 1;
      param_2 = param_2 + iVar4 * 4;
      param_1 = param_1 + iVar4 * 4;
      uVar5 = param_3 & 0xf;
      if ((param_3 & 0xc) != 0) {
        uVar5 = (param_3 & 0xf) - 4 >> 2;
        puVar2 = param_1 + -1;
        puVar1 = param_2;
        do {
          puVar2 = puVar2 + 1;
          *puVar2 = *puVar1;
          puVar1 = puVar1 + 1;
        } while (puVar2 != param_1 + uVar5);
        iVar4 = uVar5 + 1;
        param_1 = param_1 + iVar4;
        param_2 = param_2 + iVar4;
        uVar5 = param_3 & 3;
      }
    }
    iVar4 = uVar5 - 1;
    if (uVar5 != 0) {
LAB_000064d2:
      puVar3 = (undefined *)((int)param_1 + -1);
      puVar2 = param_2;
      do {
        puVar1 = (undefined4 *)((int)puVar2 + 1);
        puVar3 = puVar3 + 1;
        *puVar3 = *(undefined *)puVar2;
        puVar2 = puVar1;
      } while (puVar1 != (undefined4 *)(iVar4 + 1 + (int)param_2));
      return;
    }
  }
  return;
}




void FUN_00006574(undefined4 *param_1,undefined param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  if (((uint)param_1 & 3) != 0) {
    uVar4 = param_3 - 1;
    puVar2 = param_1;
    if (param_3 == 0) {
      return;
    }
    while( true ) {
      param_1 = (undefined4 *)((int)puVar2 + 1);
      *(undefined *)puVar2 = param_2;
      param_3 = uVar4;
      if (((uint)param_1 & 3) == 0) break;
      bVar6 = uVar4 == 0;
      uVar4 = uVar4 - 1;
      puVar2 = param_1;
      if (bVar6) {
        return;
      }
    }
  }
  if (3 < param_3) {
    uVar5 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    if (0xf < param_3) {
      uVar4 = param_3 - 0x10 >> 4;
      puVar2 = param_1 + 4;
      do {
        puVar2[-4] = uVar5;
        puVar2[-3] = uVar5;
        puVar2[-2] = uVar5;
        puVar2[-1] = uVar5;
        puVar2 = puVar2 + 4;
      } while (puVar2 != param_1 + uVar4 * 4 + 8);
      uVar1 = param_3 & 0xc;
      param_1 = param_1 + (uVar4 + 1) * 4;
      param_3 = param_3 & 0xf;
      if (uVar1 == 0) goto joined_r0x000065ec;
    }
    puVar2 = (undefined4 *)((param_3 - 4 & 0xfffffffc) + 4 + (int)param_1);
    do {
      puVar3 = param_1 + 1;
      *param_1 = uVar5;
      param_1 = puVar3;
    } while (puVar2 != puVar3);
    param_3 = param_3 & 3;
    param_1 = puVar2;
  }
joined_r0x000065ec:
  if (param_3 != 0) {
    puVar2 = param_1;
    do {
      puVar3 = (undefined4 *)((int)puVar2 + 1);
      *(undefined *)puVar2 = param_2;
      puVar2 = puVar3;
    } while ((undefined4 *)(param_3 + (int)param_1) != puVar3);
  }
  return;
}




undefined4 FUN_00006614(undefined4 *param_1)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_lr;
  
  *param_1 = unaff_r4;
  param_1[1] = unaff_r5;
  param_1[2] = unaff_r6;
  param_1[3] = unaff_r7;
  param_1[4] = unaff_r8;
  param_1[5] = unaff_r9;
  param_1[6] = unaff_r10;
  param_1[7] = unaff_r11;
  param_1[8] = register0x00000054;
  param_1[9] = in_lr;
  return 0;
}




int FUN_00006620(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    param_2 = 1;
  }
  return param_2;
}



