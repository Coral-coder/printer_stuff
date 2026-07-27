/* Ghidra decompilation of bed0_100_G21-bed0_004_000.bin */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000002d0(byte param_1)

{
  int iVar1;
  uint uVar2;
  
  if (_DAT_40012400 << 0x1b < 0) {
    iVar1 = ((_DAT_40012400 << 0x1e) >> 0x1f & DAT_00000368) + 0x5a0;
  }
  else {
    uVar2 = (uint)param_1;
    _DAT_40012434 = _DAT_40012434 & 0xffffffe0 | uVar2;
    if (param_1 < 10) {
      _DAT_40012410 = 1 << (uVar2 * 3 & 0xff) | _DAT_40012410 & ~(7 << (uVar2 * 3 & 0xff));
    }
    else if (param_1 < 0x13) {
      uVar2 = uVar2 * 3 - 0x1e;
      _DAT_4001240c = 1 << (uVar2 & 0xff) | _DAT_4001240c & ~(7 << (uVar2 & 0xff));
    }
    _DAT_40012408 = _DAT_40012408 | 0x400000;
    iVar1 = 0x5a0;
  }
  return iVar1;
}




void FUN_0000038c(uint param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *(int *)(*(int *)((param_1 >> 4) * 4 + 0x800c2c4) + 0x2c) = 1 << (param_1 & 0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00000944(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = _DAT_40000424;
  uVar1 = _DAT_2000078c;
  _DAT_20000028 = 1;
  _DAT_20000030 = 0x8006345;
  FUN_00006644(_DAT_20000040,0x4c895440);
  _DAT_20000034 = FUN_00006338();
  _DAT_20000034 = _DAT_20000034 + (uVar2 ^ uVar1) + (uVar1 & 0xffff);
  FUN_000061fc(0x2000002c);
  return;
}




void FUN_00000bc8(int param_1,undefined4 param_2)

{
  FUN_00003fec(0x800c12c,param_2,*(undefined2 *)(param_1 + 0x14),*(undefined *)(param_1 + 0x19),
               param_1 + 0x1a);
  *(undefined *)(param_1 + 0x19) = 0;
  *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + 1;
  return;
}




void FUN_00000bf4(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_00003fec(0x800c104,*(undefined *)param_1,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],
               param_1[5]);
  iVar1 = FUN_00003e00(*(undefined *)param_1,0x8003bf5,0x84);
  *(undefined4 *)(iVar1 + 0xc) = *param_1;
  uVar2 = param_1[1];
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(uint *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  if (uVar2 < 5) {
    *(undefined4 *)(iVar1 + 4) = 0x8004611;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00003764(0x1e);
}




void FUN_00000de8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 1 << (param_1 & 0xf);
  iVar4 = *(int *)((param_1 >> 4) * 4 + 0x800c2c4);
  *(uint *)(iVar4 + 4) = *(uint *)(iVar4 + 4) & ~uVar2;
  uVar3 = 0;
  uVar1 = *(uint *)(iVar4 + 8);
  do {
    if ((uVar2 & 1 << (uVar3 & 0xff)) != 0) {
      uVar1 = uVar1 | 3 << ((uVar3 & 0x7f) << 1);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 0x10);
  *(uint *)(iVar4 + 8) = uVar1;
  return;
}




bool FUN_00000f18(byte param_1)

{
  return (*(uint *)(*(int *)((uint)(param_1 >> 4) * 4 + 0x800c2c4) + 0x10) & 1 << (param_1 & 0xf))
         != 0;
}




undefined4 FUN_00000f3c(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)*(byte *)(param_1 + 0x1e);
  if (uVar8 != 0) {
    uVar8 = 0;
    uVar7 = 1;
    uVar6 = 0;
    do {
      iVar4 = FUN_00000f18(*(undefined *)(param_1 + uVar6 + 0x1f));
      if (iVar4 != 0) {
        uVar8 = uVar8 | uVar7;
      }
      uVar6 = uVar6 + 1 & 0xff;
      uVar7 = (uVar7 & 0x7f) << 1;
    } while (uVar6 < *(byte *)(param_1 + 0x1e));
  }
  bVar1 = *(byte *)(param_1 + 0x10);
  bVar2 = (byte)uVar8;
  if (bVar1 != uVar8) {
    uVar6 = ~(*(byte *)(param_1 + 0x11) ^ uVar8);
    if (((bVar1 ^ uVar8) & uVar6 & 0xff) != 0) {
      bVar3 = (byte)uVar6;
      bVar3 = bVar3 & bVar2 | bVar1 & ~bVar3;
      bVar1 = *(byte *)(param_1 + 0x12);
      *(byte *)(param_1 + 0x10) = bVar3;
      if (bVar1 < 8) {
        *(byte *)(param_1 + 0x12) = bVar1 + 1;
        *(byte *)(param_1 + (uint)bVar1 + 0x13) = bVar3;
        FUN_0000618c(0x200001f0);
        *(byte *)(param_1 + 0x11) = bVar2;
        *(undefined *)(param_1 + 0x1c) = 0xff;
        goto LAB_00000f90;
      }
    }
  }
  *(byte *)(param_1 + 0x11) = bVar2;
  if (-1 < *(char *)(param_1 + 0x1c)) {
    cVar5 = *(char *)(param_1 + 0x1c) + -1;
    if (cVar5 == -1) {
      FUN_0000618c(0x200001f0);
    }
    *(char *)(param_1 + 0x1c) = cVar5;
  }
LAB_00000f90:
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_1 + 0xc);
  return 1;
}




void FUN_00001060(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 1 << (param_1 & 0xf);
  if (param_2 == 0) {
    *(int *)(*(int *)((param_1 >> 4) * 4 + 0x800c2c4) + 0x28) = iVar1;
  }
  else {
    *(int *)(*(int *)((param_1 >> 4) * 4 + 0x800c2c4) + 0x18) = iVar1;
  }
  return;
}




void FUN_00001188(uint param_1)

{
  *(int *)(*(int *)((param_1 >> 4) * 4 + 0x800c2c4) + 0x2c) = 1 << (param_1 & 0xf);
  return;
}




void FUN_00001a28(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = (param_1 >> 4) * 4;
  uVar6 = *(uint *)(iVar1 + 0x800c2ac);
  puVar3 = (uint *)((uVar6 >> 6) + 0x40021000);
  *puVar3 = 1 << (uVar6 & 0x1f) | *puVar3;
  puVar3 = *(uint **)(iVar1 + 0x800c2c4);
  uVar5 = *puVar3;
  uVar6 = puVar3[3];
  uVar2 = 0;
  do {
    if ((1 << (param_1 & 0xf) & 1 << (uVar2 & 0xff)) != 0) {
      uVar7 = uVar2 << 1;
      uVar4 = 3 << (uVar7 & 0xff);
      uVar5 = uVar5 & ~uVar4 | param_2 << (uVar7 & 0xff);
      uVar6 = uVar6 & ~uVar4 | param_3 << (uVar7 & 0xff);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x10);
  *puVar3 = uVar5;
  puVar3[3] = uVar6;
  return;
}




uint FUN_00001bf8(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 < 0x60) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_00001a28(param_1,0,(param_2 == 0) + '\x01');
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00003764(0x2a);
}




void FUN_00001cd0(uint param_1,int param_2)

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
  FUN_00001a28(param_1,1,0);
  FUN_00000de8(param_1);
  iVar2 = *(int *)((param_1 >> 4) * 4 + 0x800c2c4);
  if (param_2 == 0) {
    *(int *)(iVar2 + 0x28) = iVar3;
  }
  else {
    *(int *)(iVar2 + 0x18) = iVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}




uint FUN_00001d18(uint param_1)

{
  if (param_1 < 0x60) {
    FUN_00001cd0();
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00003764(0x2b);
}




uint FUN_000020a0(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    uVar2 = 0xffff;
  }
  else {
    pbVar3 = param_1 + param_2;
    uVar2 = 0xffff;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar4 = (bVar1 ^ uVar2 ^ ((bVar1 ^ uVar2) & 0xff) << 4) & 0xff;
      uVar2 = uVar4 >> 4 ^ uVar4 << 3 ^ (uVar4 << 8 | uVar2 >> 8);
    } while (pbVar3 != param_1);
  }
  return uVar2;
}




void FUN_00002244(int param_1,undefined4 param_2,uint param_3,int param_4,undefined param_5)

{
  byte bVar1;
  
  FUN_00003fec(0x800c11c,param_5,param_2,param_3,param_4);
  if ((param_4 == 0) && (*(uint *)(param_1 + 0x10) <= param_3)) {
    if (param_3 <= *(uint *)(param_1 + 0x14)) goto LAB_0000228c;
    bVar1 = *(char *)(param_1 + 0x1d) + 1;
    *(byte *)(param_1 + 0x1d) = bVar1;
    if (bVar1 < *(byte *)(param_1 + 0x1c)) {
      return;
    }
  }
  else {
    bVar1 = *(char *)(param_1 + 0x1d) + 1;
    *(byte *)(param_1 + 0x1d) = bVar1;
    if (bVar1 < *(byte *)(param_1 + 0x1c)) {
      return;
    }
  }
  if (cRam20000009 == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_00003764(0x21);
  }
LAB_0000228c:
  *(undefined *)(param_1 + 0x1d) = 0;
  return;
}




void FUN_000022b0(int *param_1,int param_2,int param_3,byte *param_4)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  
  bVar1 = *(byte *)(param_1 + 4);
  if ((bVar1 & 6) == 0) {
    return;
  }
  if ((bVar1 & 2) == 0) {
    if (-1 < (int)((uint)bVar1 << 0x1f)) {
      return;
    }
    FUN_00001060(param_1[3],'\x01' - ((bVar1 & 8) == 0));
  }
  else {
    FUN_00001060(*(undefined4 *)(*param_1 + 8),*(byte *)(*param_1 + 0xc) & 2);
    if ((bVar1 & 1) == 0) {
      puVar7 = (undefined *)*param_1;
      if (param_3 == 0) {
        return;
      }
    }
    else {
      FUN_00001060(param_1[3],bVar1 >> 3 & 1);
      puVar7 = (undefined *)*param_1;
      if (param_3 == 0) goto LAB_000023be;
    }
    pbVar3 = param_4 + param_3;
    do {
      iVar8 = 8;
      uVar5 = 0;
      uVar6 = (uint)*param_4;
      do {
        while ((puVar7[0xc] & 1) == 0) {
          FUN_00001060(*(undefined4 *)(puVar7 + 4),uVar6 & 0xffffff80);
          FUN_0000038c(*(undefined4 *)(puVar7 + 8));
          uVar2 = FUN_00000f18(*puVar7);
          FUN_0000038c(*(undefined4 *)(puVar7 + 8));
          iVar8 = iVar8 + -1;
          uVar6 = (uVar6 & 0x7f) << 1;
          uVar5 = (uVar5 & 0x7f) << 1 | uVar2 & 0xff;
          bVar4 = (byte)uVar5;
          if (iVar8 == 0) goto LAB_00002384;
        }
        FUN_0000038c(*(undefined4 *)(puVar7 + 8));
        FUN_00001060(*(undefined4 *)(puVar7 + 4),uVar6 & 0xffffff80);
        FUN_0000038c(*(undefined4 *)(puVar7 + 8));
        uVar2 = FUN_00000f18(*puVar7);
        iVar8 = iVar8 + -1;
        uVar6 = (uVar6 & 0x7f) << 1;
        uVar5 = (uVar5 & 0x7f) << 1 | uVar2 & 0xff;
        bVar4 = (byte)uVar5;
      } while (iVar8 != 0);
LAB_00002384:
      if (param_2 != 0) {
        *param_4 = bVar4;
      }
      param_4 = param_4 + 1;
    } while (((uint)param_4 & 0xff) != ((uint)pbVar3 & 0xff));
    if ((bVar1 & 1) == 0) {
      return;
    }
  }
LAB_000023be:
  FUN_00001060(param_1[3],(bVar1 & 8) == 0);
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000023ec(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 local_24;
  
  iVar1 = FUN_00003938(*(undefined *)param_1,0x80037c5);
  local_24 = 0xb9;
  iVar2 = (_DAT_40000424 ^ _DAT_2000078c) + (_DAT_2000078c & 0xffff);
  FUN_000022b0(*(undefined4 *)(iVar1 + 0x10),1,2,&local_24);
  FUN_00003fec(0x800c124,*param_1,iVar2,
               ((_DAT_40000424 ^ _DAT_2000078c) + (_DAT_2000078c & 0xffff)) - iVar2,
               *(undefined2 *)(iVar1 + 0x14),*(undefined *)(iVar1 + 0x19),local_24._1_1_,
               *(undefined2 *)(iVar1 + 0x16));
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00002478(int param_1,undefined4 param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_2c;
  undefined4 local_28;
  byte local_24;
  
  local_2c = _DAT_0800c0c4;
  local_28 = _DAT_0800c0c8;
  local_24 = DAT_0800c0cc;
  FUN_000022b0(*(undefined4 *)(param_1 + 0x10),1,9,&local_2c);
  uVar1 = (uint)*(byte *)(param_1 + 0x19);
  iVar3 = param_1 + uVar1 + 0x1a;
  if ((((local_2c & 0xf00000) == 0) || ((local_2c._2_1_ & 0xf0) == 0xf0)) &&
     (((local_28 & 0xf0) == 0 || ((local_28 & 0xf0) == 0xf0)))) {
    if (((((local_28 & 0xf00000) == 0) || ((local_28._2_1_ & 0xfffffff0) == 0xf0)) &&
        (local_28._3_1_ == -0x70)) && (uVar4 = local_24 & 0xffffff7f, uVar4 < 0x21)) {
      *(undefined *)(param_1 + uVar1 + 0x1a) = local_2c._1_1_;
      *(undefined *)(iVar3 + 1) = local_2c._3_1_;
      *(undefined *)(iVar3 + 2) = local_28._1_1_;
      *(byte *)(iVar3 + 3) = local_2c._2_1_ & 0x1f | local_28._2_1_ << 5;
      *(byte *)(iVar3 + 4) = (byte)((local_28._2_1_ & 0x18) << 2) | (byte)local_28 & 0x1f;
      bVar2 = *(char *)(param_1 + 0x19) + 5;
      *(byte *)(param_1 + 0x19) = bVar2;
      if (0x2d < bVar2) {
        FUN_00000bc8(param_1,param_2);
      }
      if (0x1e < uVar4) {
        *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + 1;
LAB_00002562:
        FUN_0000618c(0x20000068);
        return;
      }
      if (uVar4 - 2 < 0x1f) goto LAB_00002562;
      goto LAB_000024e0;
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
    FUN_00000bc8(param_1,param_2);
  }
LAB_000024e0:
  if ((int)((uint)*(byte *)(param_1 + 0x18) << 0x1e) < 0) {
    FUN_000061a0(param_1);
    *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) & 0xfb;
    disableIRQinterrupts();
    *(uint *)(param_1 + 8) =
         (_DAT_40000424 ^ _DAT_2000078c) + (_DAT_2000078c & 0xffff) + *(int *)(param_1 + 0xc);
    FUN_000061fc(param_1);
    enableIRQinterrupts();
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000025cc(uint *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 local_2c;
  
  uVar3 = *param_1;
  uVar7 = uVar3 & 0xff;
  iVar1 = FUN_00003938(uVar7,0x80037c5);
  if (param_1[2] == 0) {
    FUN_000061a0();
    local_2c = 0x2d;
    *(undefined *)(iVar1 + 0x18) = 0;
    iVar8 = (_DAT_40000424 ^ _DAT_2000078c) + (_DAT_2000078c & 0xffff);
    FUN_000022b0(*(undefined4 *)(iVar1 + 0x10),0,2,&local_2c);
    uVar5 = _DAT_2000078c & 0xffff;
    uVar4 = _DAT_40000424 ^ _DAT_2000078c;
    iVar6 = 0x21;
    do {
      while( true ) {
        local_2c = 0xb9;
        FUN_000022b0(*(undefined4 *)(iVar1 + 0x10),1,2,&local_2c);
        if ((local_2c & 0x7f00) == 0) goto LAB_000026a4;
        if (0x20 < (local_2c._1_1_ & 0x7f)) break;
        iVar6 = iVar6 + -1;
        FUN_00002478(iVar1,uVar7);
        if (iVar6 == 0) goto LAB_000026a4;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
LAB_000026a4:
    cVar2 = *(char *)(iVar1 + 0x19);
    if (cVar2 != '\0') {
      FUN_00000bc8(iVar1,uVar7);
      cVar2 = *(char *)(iVar1 + 0x19);
    }
    FUN_00003fec(0x800c124,uVar3 & 0xff,iVar8,(uVar4 + uVar5) - iVar8,*(undefined2 *)(iVar1 + 0x14),
                 cVar2,local_2c._1_1_,*(undefined2 *)(iVar1 + 0x16));
  }
  else {
    FUN_000061a0();
    *(uint *)(iVar1 + 8) = param_1[1];
    *(uint *)(iVar1 + 0xc) = param_1[2];
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined2 *)(iVar1 + 0x18) = 1;
    FUN_000061fc(iVar1);
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000273c(void)

{
  FUN_000061a0(0x2000002c);
  _DAT_20000028 = 0;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00002754(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  FUN_00004260();
  FUN_00001060(_DAT_20000780,0);
  if (*(int *)(param_1 + 0x10) == 0) {
    _DAT_200004f6 = 0;
    uVar1 = 0;
    if (_DAT_20000028 == 1) {
      FUN_0000273c();
      uVar1 = _DAT_200004f6;
    }
  }
  else {
    if (_DAT_20000028 == 0) {
      FUN_00000944();
    }
    puVar3 = (undefined4 *)&DAT_2000024c;
    _DAT_20000248 = (-(uint)(*(int *)(param_1 + 4) == 0) & 0xffffffe1) + 0x1f;
    FUN_00008fe8(&DAT_2000024c,0,0x80);
    FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
    uVar2 = FUN_00006368();
    do {
      *puVar3 = uVar2;
      puVar3 = puVar3 + 1;
    } while (puVar3 != (undefined4 *)&DAT_200002cc);
    if (_DAT_20000220 != 0) {
      iVar4 = 0;
      piVar5 = (int *)&DAT_200002cc;
      do {
        *piVar5 = (-(uint)(*(int *)(param_1 + 4) == 0) & 0xffffffe1) + 0x1f;
        FUN_00008fe8(piVar5 + 1,0,0x80);
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 0x21;
      } while (iVar4 < (int)(uint)_DAT_20000220);
    }
    _DAT_200004ec = (undefined2)*(undefined4 *)(param_1 + 4);
    _DAT_200004f4 = (undefined2)*(undefined4 *)(param_1 + 0xc);
    _DAT_20000500 = (undefined2)*(undefined4 *)(param_1 + 0x10);
    uVar2 = FUN_00006ce4(*(undefined4 *)(param_1 + 0x14));
    _DAT_200004f8 = FUN_0000642c(uVar2,0x447a0000);
    uVar2 = FUN_00006ce4(*(undefined4 *)(param_1 + 0x18));
    _DAT_200004fc = FUN_0000642c(uVar2,0x447a0000);
    _DAT_20000504 = *(undefined4 *)(param_1 + 0x1c);
    _DAT_20000508 = *(undefined4 *)(param_1 + 0x20);
    _DAT_200004e0 = 0;
    _DAT_200004dc = 0;
    uVar1 = (short)*(undefined4 *)(param_1 + 8);
  }
  _DAT_200004f6 = uVar1;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00002890(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar4 = *(int *)(param_1 + 8);
  if (iVar4 == 0) {
    _DAT_200004e8 = 0;
    uVar3 = 0;
    if (_DAT_20000028 == 1) {
      FUN_0000273c();
      uVar3 = _DAT_200004e8;
    }
  }
  else {
    if (_DAT_20000028 == 0) {
      FUN_00000944();
      iVar4 = *(int *)(param_1 + 8);
    }
    uVar2 = _DAT_2000003c;
    uVar1 = _DAT_20000038;
    _DAT_200004e4 = (undefined2)*(undefined4 *)(param_1 + 4);
    _DAT_200004e8 = (undefined2)iVar4;
    _DAT_200004e6 = 0;
    _DAT_20000218 = _DAT_20000038;
    _DAT_2000021c = _DAT_2000003c;
    uVar5 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000210,_DAT_20000214,param_4);
    iVar4 = FUN_000062e8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0);
    if (iVar4 == 0) {
      _DAT_20000210 = uVar1;
      _DAT_20000214 = uVar2;
    }
    FUN_00004260(param_1);
    uVar3 = _DAT_200004e8;
  }
  _DAT_200004e8 = uVar3;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00002918(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 8) == 0) {
    _DAT_20000762 = 1;
    FUN_00004260();
    if (_DAT_20000028 == 1) {
      FUN_0000273c();
    }
  }
  else {
    if (_DAT_20000028 == 0) {
      FUN_00000944();
    }
    puVar2 = (undefined4 *)&DAT_200006e0;
    _DAT_200006dc = 0;
    _DAT_20000658 = 0;
    FUN_00008fe8(&DAT_200006e0,0,0x80,0,param_4);
    FUN_00008fe8(&DAT_2000065c,0,0x80);
    FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
    uVar1 = FUN_00006368();
    do {
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)&DAT_20000760);
    FUN_0000368c(*(undefined4 *)(param_1 + 4),1);
    _DAT_20000760 = (undefined2)*(undefined4 *)(param_1 + 4);
    _DAT_20000656 = (undefined2)*(undefined4 *)(param_1 + 8);
    _DAT_20000764 = *(int *)(param_1 + 0xc) << 1;
    _DAT_20000768 = _DAT_20000764;
    uVar3 = FUN_00008a10(*(undefined4 *)(param_1 + 0x10));
    uVar3 = FUN_00007480((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x412e8480);
    FUN_00007cfc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x41912a88);
    _DAT_2000076c = FUN_00006368();
    _DAT_2000076c = _DAT_2000076c >> 1;
    _DAT_20000770 = *(int *)(param_1 + 0x14) << 1;
    _DAT_20000650 = 0;
    _DAT_20000654 = 0;
    _DAT_20000774 = (undefined2)*(uint *)(param_1 + 0x18);
    _DAT_20000776 = (undefined2)*(undefined4 *)(param_1 + 0x1c);
    _DAT_20000778 = (undefined2)*(undefined4 *)(param_1 + 0x20);
    _DAT_200005f8 = 0x800470d;
    _DAT_200005fc =
         ((*(uint *)(param_1 + 0x18) & 0xffff) + 1) * _DAT_2000076c +
         (_DAT_40000424 ^ _DAT_2000078c) + (_DAT_2000078c & 0xffff);
    _DAT_20000762 = 0;
    FUN_000061fc(0x200005f4);
    FUN_00004260(param_1);
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00002a78(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined8 *puVar7;
  int *piVar8;
  undefined8 *puVar9;
  int *piVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  int *local_30;
  
  piVar10 = (int *)&DAT_20000070;
  FUN_00008fe8(&DAT_20000070,0,0x80);
  FUN_00008fe8(&DAT_200000f0,0,0x100);
  iVar3 = *(int *)(&DAT_200002cc + param_1 * 0x84);
  piVar8 = piVar10;
  do {
    iVar5 = iVar3 % 0x20;
    iVar3 = iVar3 + 1;
    *piVar8 = *(int *)(&DAT_20000210 + (param_1 * 0x21 + iVar5 + 0x30) * 4);
    sVar1 = _DAT_20000222;
    piVar8 = piVar8 + 1;
  } while (piVar8 != (int *)&DAT_200000f0);
  piVar8 = DAT_00002e94;
  iVar3 = _DAT_20000070;
  if (_DAT_200000ec < _DAT_20000070) {
    piVar6 = (int *)&DAT_20000070;
    while( true ) {
      iVar5 = -iVar3;
      if (sVar1 != 0) {
        iVar5 = 0x1000 - iVar3;
      }
      *piVar6 = iVar5;
      piVar6 = piVar6 + 1;
      piVar8 = DAT_00002e94;
      iVar3 = _DAT_20000070;
      if (piVar6 == (int *)&DAT_200000f0) break;
      iVar3 = *piVar6;
    }
  }
  DAT_00002e94 = piVar8;
  _DAT_20000070 = iVar3;
  if (sVar1 == 0) {
    if (param_2 == 0) {
      local_30 = (int *)&DAT_20000070;
      while( true ) {
        uVar13 = FUN_000089ac(iVar3);
        uVar14 = FUN_000089ac(piVar10[1]);
        uVar11 = (uint)((ulonglong)uVar13 >> 0x20) & 0x7fffffff;
        iVar3 = FUN_000062e8((int)uVar13,uVar11,(int)uVar14);
        if (iVar3 == 0) {
          uVar11 = (uint)((ulonglong)uVar14 >> 0x20) & 0x7fffffff;
          uVar13 = uVar14;
        }
        iVar5 = piVar10[2];
        uVar14 = FUN_000089ac(iVar5);
        iVar3 = FUN_00006310((int)uVar14,(uint)((ulonglong)uVar14 >> 0x20) & 0x7fffffff,(int)uVar13,
                             uVar11);
        if (iVar3 != 0) {
          iVar5 = FUN_00008948((int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
        }
        piVar8 = DAT_00002e98;
        *piVar10 = iVar5;
        piVar10 = piVar10 + 1;
        if (piVar8 == piVar10) break;
        iVar3 = *piVar10;
      }
      FUN_0000642c(0x3e22f984,_DAT_200004f8);
      uVar13 = FUN_00008a60();
      uVar4 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar2 = FUN_00006c58(_DAT_200004f6);
      uVar2 = FUN_0000642c(0x447a0000,uVar2);
      FUN_0000642c(0x3f800000,uVar2);
      uVar14 = FUN_00008a60();
      uVar14 = FUN_00006d5c((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar13,uVar4);
      uVar14 = FUN_00007480((int)uVar13,uVar4,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
      puVar9 = DAT_00002e9c;
      puVar7 = DAT_00002e9c + 0x1e;
      uVar13 = 0;
      puVar12 = DAT_00002e9c;
      while( true ) {
        piVar8 = local_30 + 1;
        iVar3 = *local_30;
        local_30 = local_30 + 1;
        uVar15 = FUN_000089ac(*piVar8 - iVar3);
        uVar13 = FUN_00006d5c((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar13,
                              (int)((ulonglong)uVar13 >> 0x20));
        uVar13 = FUN_00007cfc((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
                              (int)((ulonglong)uVar14 >> 0x20));
        *puVar12 = uVar13;
        uVar2 = _DAT_200004fc;
        if (puVar7 == puVar12) break;
        puVar12 = puVar12 + 1;
      }
      uVar14 = FUN_00008a60(_DAT_200004fc);
      FUN_00006884(0x3f800000,uVar2);
      uVar15 = FUN_00008a60();
      uVar13 = 0;
      while( true ) {
        uVar16 = FUN_00007cfc((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),*(undefined4 *)puVar9,
                              *(undefined4 *)((int)puVar9 + 4));
        uVar13 = FUN_00007cfc((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar13,
                              (int)((ulonglong)uVar13 >> 0x20));
        uVar13 = FUN_00006d5c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar13,
                              (int)((ulonglong)uVar13 >> 0x20));
        *puVar9 = uVar13;
        if (puVar9 == puVar12) break;
        puVar9 = puVar9 + 1;
      }
    }
    else {
      iVar5 = 0;
      while( true ) {
        *(int *)(param_1 * 0x84 + 0x200002d0 + iVar5) = iVar3;
        if (iVar5 + 4 == 0x80) break;
        iVar3 = *(int *)(&DAT_20000074 + iVar5);
        iVar5 = iVar5 + 4;
      }
      *(undefined4 *)(&DAT_200002cc + param_1 * 0x84) = 0;
      if (_DAT_20000220 - 1 == param_1) {
        _DAT_2000050c = _DAT_20000248;
        do {
          iVar3 = _DAT_20000248 % 0x20;
          _DAT_20000248 = _DAT_20000248 + 1;
          *piVar10 = *(int *)(&DAT_2000024c + iVar3 * 4);
          iVar3 = DAT_00002ea0;
          piVar10 = piVar10 + 1;
        } while (piVar10 != (int *)&DAT_200000f0);
        iVar5 = 0;
        do {
          *(undefined4 *)(iVar3 + iVar5) = *(undefined4 *)(&DAT_20000070 + iVar5);
          iVar5 = iVar5 + 4;
        } while (iVar5 != 0x80);
        _DAT_20000248 = 0;
      }
    }
  }
  else if (param_2 == 0) {
    puVar9 = (undefined8 *)&DAT_200000f0;
    while( true ) {
      uVar13 = FUN_000089ac(iVar3);
      *puVar9 = uVar13;
      uVar2 = _DAT_200004fc;
      puVar9 = puVar9 + 1;
      if (puVar9 == (undefined8 *)0x200001f0) break;
      iVar3 = *piVar8;
      piVar8 = piVar8 + 1;
    }
    uVar13 = FUN_00008a60(_DAT_200004fc);
    FUN_00006884(0x3f800000,uVar2);
    uVar14 = FUN_00008a60();
    puVar9 = (undefined8 *)&DAT_200000f0;
    do {
      uVar15 = FUN_00007cfc((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),*(undefined4 *)(puVar9 + 1)
                            ,*(undefined4 *)((int)puVar9 + 0xc));
      uVar16 = FUN_00007cfc((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),*(undefined4 *)puVar9,
                            *(undefined4 *)((int)puVar9 + 4));
      uVar15 = FUN_00006d5c((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar16,
                            (int)((ulonglong)uVar16 >> 0x20));
      puVar12 = puVar9 + 1;
      puVar9[1] = uVar15;
      puVar9 = puVar12;
    } while (puVar12 != (undefined8 *)0x200001e8);
  }
  else {
    *(undefined4 *)(&DAT_200002cc + param_1 * 0x84) = 0;
    iVar5 = 0;
    while( true ) {
      *(int *)(param_1 * 0x84 + 0x200002d0 + iVar5) = iVar3;
      if (iVar5 + 4 == 0x80) break;
      iVar3 = *(int *)(&DAT_20000074 + iVar5);
      iVar5 = iVar5 + 4;
    }
    if (_DAT_20000220 - 1 == param_1) {
      do {
        iVar3 = _DAT_20000248 % 0x20;
        _DAT_20000248 = _DAT_20000248 + 1;
        *piVar10 = *(int *)(&DAT_2000024c + iVar3 * 4);
        iVar3 = DAT_00002ea0;
        piVar10 = piVar10 + 1;
      } while (piVar10 != (int *)&DAT_200000f0);
      iVar5 = 0;
      _DAT_20000248 = 0;
      do {
        *(undefined4 *)(iVar3 + iVar5) = *(undefined4 *)(&DAT_20000070 + iVar5);
        iVar5 = iVar5 + 4;
      } while (iVar5 != 0x80);
    }
  }
  return &DAT_200000f0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00002ea4(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined8 uVar11;
  
  if (_DAT_20000222 == 0) {
    if (_DAT_20000220 != 0) {
      uVar9 = 0;
      uVar8 = 0;
      do {
        iVar10 = FUN_00000f18(*(undefined *)(uVar8 + 0x20000244));
        uVar1 = uVar8 & 0xff;
        uVar6 = (uint)_DAT_20000220;
        uVar8 = uVar8 + 1;
        uVar9 = uVar9 | iVar10 << uVar1;
      } while ((int)uVar8 < (int)uVar6);
      if (uVar9 != 0) {
        uVar11 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000200,_DAT_20000204);
        iVar10 = FUN_00006324((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0x9999999a,0x3f999999);
        if (iVar10 == 0) {
          return 0;
        }
      }
      iVar10 = 0;
      if (uVar6 != 0) {
        do {
          FUN_00001060(*(undefined4 *)((iVar10 + 10) * 4 + 0x2000020c),0);
          uVar8 = (uint)_DAT_20000220;
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)uVar8);
        iVar10 = 0x18;
        do {
          if (uVar8 == 0) goto LAB_0000314e;
          iVar5 = 0;
          do {
            FUN_00001060(*(undefined4 *)((iVar5 + 10) * 4 + 0x2000020c),1);
            uVar8 = (uint)_DAT_20000220;
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)uVar8);
          if (uVar8 == 0) goto LAB_0000314e;
          puVar7 = param_1;
          do {
            *puVar7 = *puVar7 << 1;
            puVar7 = puVar7 + 1;
          } while (puVar7 != param_1 + uVar8);
          iVar5 = 0;
          do {
            FUN_00001060(*(undefined4 *)((iVar5 + 10) * 4 + 0x2000020c),0);
            uVar8 = (uint)_DAT_20000220;
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)uVar8);
          if (uVar8 != 0) {
            iVar5 = 0;
            puVar7 = param_1;
            do {
              iVar4 = FUN_00000f18(*(undefined *)(iVar5 + 0x20000244));
              iVar5 = iVar5 + 1;
              *puVar7 = (uint)(iVar4 != 0) + *puVar7;
              puVar7 = puVar7 + 1;
              uVar8 = (uint)_DAT_20000220;
            } while (iVar5 < (int)uVar8);
          }
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        iVar10 = 0;
        if (uVar8 != 0) {
          do {
            FUN_00001060(*(undefined4 *)((iVar10 + 10) * 4 + 0x2000020c),1);
            uVar8 = (uint)_DAT_20000220;
            iVar10 = iVar10 + 1;
          } while (iVar10 < (int)uVar8);
          if (uVar8 != 0) {
            puVar7 = param_1;
            do {
              uVar9 = *puVar7;
              if ((uVar9 & 0x800000) != 0) {
                uVar9 = uVar9 | 0xff000000;
              }
              *puVar7 = uVar9;
              puVar7 = puVar7 + 1;
            } while (puVar7 != param_1 + uVar8);
            iVar10 = 0;
            do {
              FUN_00001060(*(undefined4 *)((iVar10 + 10) * 4 + 0x2000020c),0);
              iVar5 = DAT_00003160;
              uVar8 = (uint)_DAT_20000220;
              iVar10 = iVar10 + 1;
            } while (iVar10 < (int)uVar8);
            _DAT_20000200 = _DAT_20000038;
            _DAT_20000204 = _DAT_2000003c;
            if (uVar8 == 0) {
              _DAT_20000200 = _DAT_20000038;
              _DAT_20000204 = _DAT_2000003c;
              return 1;
            }
            iVar10 = 0;
            do {
              *(int *)((int)param_1 + iVar10) =
                   *(int *)((int)param_1 + iVar10) - *(int *)(iVar5 + iVar10);
              iVar10 = iVar10 + 4;
            } while (uVar8 * 4 - iVar10 != 0);
            return 1;
          }
        }
      }
    }
LAB_0000314e:
    _DAT_20000204 = _DAT_2000003c;
    _DAT_20000200 = _DAT_20000038;
  }
  else if (_DAT_20000220 != 0) {
    iVar10 = 0;
    do {
      uVar3 = _DAT_2000003c;
      uVar2 = _DAT_20000038;
      do {
        iVar5 = FUN_000002d0(*(undefined4 *)((iVar10 + 6) * 4 + 0x2000020c));
        if (iVar5 == 0) break;
        uVar11 = FUN_00008208(_DAT_20000038,_DAT_2000003c,uVar2,uVar3);
        iVar5 = FUN_000062e8((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0xd2f1a9fc,0x3f60624d);
      } while (iVar5 != 0);
      _DAT_40012400 = _DAT_40012400 & 0xffffffed;
      param_1[iVar10] = _DAT_4001244c & 0xffff;
      iVar10 = iVar10 + 1;
      if ((int)(uint)_DAT_20000220 <= iVar10) {
        return 1;
      }
    } while( true );
  }
  return 1;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003164(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint *puVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined2 *puVar13;
  undefined4 uVar14;
  uint *puVar15;
  int *piVar16;
  int *piVar17;
  int iVar18;
  undefined4 local_38 [5];
  
  FUN_00004260();
  iVar18 = _DAT_20000028;
  if (_DAT_20000028 == 0) {
    FUN_00000944();
  }
  piVar16 = DAT_00003338;
  puVar13 = (undefined2 *)(DAT_0000333c + (int)DAT_00003338);
  FUN_00008fe8(DAT_00003338,0,0x10);
  if ((puVar13[0xd] == 0) && (iVar7 = *(int *)(param_1 + 4), iVar7 != 0)) {
    if (puVar13[0xc] != 0) {
      iVar7 = 0;
      puVar8 = (undefined4 *)(DAT_00003340 + (int)piVar16);
      do {
        *puVar8 = 0;
        FUN_00008fe8(puVar8 + 1,0,0x80);
        iVar7 = iVar7 + 1;
        puVar8 = puVar8 + 0x21;
      } while (iVar7 < (int)(uint)(ushort)puVar13[0xc]);
      iVar7 = *(int *)(param_1 + 4);
    }
    iVar11 = 0x20;
    if ((iVar7 < 0x21) && (iVar11 = iVar7, iVar7 < 8)) {
      iVar11 = 8;
    }
    iVar7 = 0;
    do {
      FUN_00008fe8(local_38,0,0x10);
      do {
        iVar2 = FUN_00002ea4(local_38);
      } while (iVar2 == 0);
      uVar12 = (uint)(ushort)puVar13[0xc];
      if (uVar12 != 0) {
        iVar2 = 0;
        puVar8 = local_38;
        piVar4 = (int *)(puVar13 + 0x62);
        do {
          iVar5 = *piVar4;
          iVar1 = iVar2 * 0x21;
          uVar14 = *puVar8;
          puVar8 = puVar8 + 1;
          iVar2 = iVar2 + 1;
          *(undefined4 *)(&DAT_20000210 + (iVar1 + iVar5 % 0x20 + 0x30) * 4) = uVar14;
          *piVar4 = iVar5 + 1;
          piVar4 = piVar4 + 0x21;
        } while (iVar2 < (int)uVar12);
      }
      iVar7 = iVar7 + 1;
    } while (iVar11 != iVar7);
    if (uVar12 != 0) {
      iVar18 = uVar12 * 0x21;
      iVar7 = 0;
      puVar15 = (uint *)(puVar13 + iVar11 * 2 + 100);
      do {
        iVar2 = 0;
        puVar3 = puVar15 + -iVar11;
        do {
          puVar9 = puVar3;
          if (iVar2 < iVar11) {
            do {
              uVar6 = *puVar3;
              if (*puVar9 < uVar6) {
                *puVar3 = *puVar9;
                *puVar9 = uVar6;
              }
              puVar9 = puVar9 + 1;
            } while (puVar9 != puVar15);
          }
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar11 != iVar2);
        iVar7 = iVar7 + 0x21;
        puVar15 = puVar15 + 0x21;
      } while (iVar7 != iVar18);
      piVar4 = (int *)(puVar13 + iVar11 * 2 + 0x60);
      piVar17 = piVar16 + uVar12;
      do {
        iVar7 = *piVar16;
        piVar10 = piVar4 + (4 - iVar11);
        do {
          iVar2 = *piVar10;
          piVar10 = piVar10 + 1;
          iVar7 = iVar7 + iVar2;
        } while (piVar10 != piVar4);
        *piVar16 = iVar7 / (iVar11 + -4);
        piVar16 = piVar16 + 1;
        piVar4 = piVar4 + 0x21;
      } while (piVar16 != piVar17);
    }
  }
  if (_DAT_20000028 == 1) {
    FUN_0000273c();
  }
  FUN_00003fec(0x800c1d4,*puVar13,*(undefined4 *)(puVar13 + 0x186),*(undefined4 *)(puVar13 + 0x188),
               *(undefined4 *)(puVar13 + 0x18a),*(undefined4 *)(puVar13 + 0x18c),iVar18);
  return;
}




uint FUN_000033a4(uint *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)param_1[1];
  uVar3 = param_1[2];
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((*param_1 & 0xff) == 1) {
    *(short *)puVar4 = (short)uVar3;
  }
  else if ((*param_1 & 0xff) == 2) {
    *puVar4 = uVar3;
  }
  else {
    *(char *)puVar4 = (char)uVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  return uVar2;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000033d4(byte *param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  
  bVar2 = *param_1 + 1;
  piVar1 = (int *)(_DAT_20000a9c + (uint)bVar2 * 8);
  while( true ) {
    if (DAT_20000a98 <= bVar2) {
      return 0;
    }
    if (*piVar1 == param_2) break;
    bVar2 = bVar2 + 1;
    piVar1 = piVar1 + 2;
  }
  *param_1 = bVar2;
  return piVar1[1];
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003418(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1;
  *param_1 = _DAT_20000a8c;
  _DAT_20000a8c = puVar1;
  _DAT_20000b24 = _DAT_20000b24 + -1;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000368c(uint param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = &DAT_200005f0;
  if (_DAT_20000610 != 0) {
    iVar3 = 0;
    do {
      if (param_2 == 1) {
        uVar2 = FUN_00000f18(*(undefined *)(iVar3 + 0x2000064c));
        *(undefined2 *)(puVar4 + 0x22) = uVar2;
        cVar1 = '\x01' - (*(ushort *)(puVar4 + 0x2a) == param_1);
      }
      else {
        cVar1 = (char)*(undefined2 *)(puVar4 + 0x22);
      }
      FUN_00001060(*(undefined4 *)((iVar3 + 0xe) * 4 + 0x200005f4),cVar1);
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 2;
    } while (iVar3 < (int)(uint)_DAT_20000610);
  }
  return;
}




undefined4 FUN_000036f8(int param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x2c);
  if (puVar5 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x2c) = *puVar5;
    sVar2 = *(short *)(puVar5 + 2);
    iVar3 = puVar5[1];
    *(short *)(param_1 + 0x10) = sVar2;
    *(int *)(param_1 + 0xc) = sVar2 + iVar3;
    if ((int)((uint)*(byte *)(param_1 + 0x3c) << 0x1b) < 0) {
      *(int *)(param_1 + 8) = iVar3 + *(int *)(param_1 + 8);
      uVar4 = (uint)*(ushort *)((int)puVar5 + 10);
      *(uint *)(param_1 + 0x14) = uVar4;
      bVar1 = *(byte *)(puVar5 + 3);
    }
    else {
      iVar3 = iVar3 + *(int *)(param_1 + 0x18);
      *(int *)(param_1 + 0x18) = iVar3;
      *(int *)(param_1 + 8) = iVar3;
      uVar4 = (uint)*(ushort *)((int)puVar5 + 10);
      *(uint *)(param_1 + 0x14) = uVar4 << 1;
      bVar1 = *(byte *)(puVar5 + 3);
    }
    if ((int)((uint)bVar1 << 0x1f) < 0) {
      *(uint *)(param_1 + 0x28) = uVar4 - *(int *)(param_1 + 0x28);
      FUN_00001188(*(undefined4 *)(param_1 + 0x24));
    }
    else {
      *(uint *)(param_1 + 0x28) = uVar4 + *(int *)(param_1 + 0x28);
    }
    FUN_00003418(puVar5);
    return 1;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return 0;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003764(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  disableIRQinterrupts();
  UNRECOVERED_JUMPTABLE = (code *)0x3777;
  iVar1 = FUN_000090a8(0x20000ab0,param_1);
  FUN_00001188(*(undefined4 *)(iVar1 + 0x20));
  iVar4 = (_DAT_40000424 ^ _DAT_2000078c) + (_DAT_2000078c & 0xffff) + *(int *)(iVar1 + 0x1c);
  iVar2 = *(int *)(iVar1 + 0x14) + -1;
  *(int *)(iVar1 + 0x14) = iVar2;
  if (-1 < iVar2 * -0x80000000) {
    if (iVar2 == 0) {
      iVar2 = FUN_000036f8(iVar1);
      if ((iVar2 == 0) || (iVar3 = *(int *)(iVar1 + 8) - iVar4, -1 < iVar3)) goto LAB_000037b4;
      if (iVar3 < -72000) {
                    /* WARNING: Subroutine does not return */
        FUN_00003764(0x19);
      }
    }
    else {
      iVar3 = *(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 0x18);
      *(int *)(iVar1 + 0xc) = (int)*(short *)(iVar1 + 0x10) + *(int *)(iVar1 + 0xc);
      *(int *)(iVar1 + 0x18) = iVar3;
      if (-1 < iVar3 - iVar4) {
        iVar2 = 1;
        *(int *)(iVar1 + 8) = iVar3;
        goto LAB_000037b4;
      }
    }
  }
  iVar2 = 1;
  *(int *)(iVar1 + 8) = iVar4;
LAB_000037b4:
                    /* WARNING: Could not recover jumptable at 0x000037b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar2);
  return;
}




void FUN_00003908(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_00003764(0xd);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00003938(uint param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 < DAT_20000a98) {
    piVar1 = (int *)(_DAT_20000a9c + param_1 * 8);
    if (*piVar1 == param_2) {
      return piVar1[1];
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00003764(0xb);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00003d9c(int param_1)

{
  int iVar1;
  
  iVar1 = _DAT_20000800;
  if ((uint)(_DAT_20000800 + param_1) < 0x20001e01) {
    _DAT_20000800 = _DAT_20000800 + (param_1 + 3U & 0xfffffffc);
    FUN_00008fe8(iVar1,0);
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00003764(0x10);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003e00(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 < DAT_20000a98) {
    piVar2 = (int *)(_DAT_20000a9c + param_1 * 8);
    if ((*piVar2 == 0) && (_DAT_20000a88 == 0)) {
      *piVar2 = param_2;
      iVar1 = FUN_00003d9c(param_3);
      piVar2[1] = iVar1;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00003764(10);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003f18(undefined *param_1)

{
  undefined uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = FUN_00001d18(param_1[4],'\x01' - (*(int *)(param_1 + 8) == 0));
  iVar3 = FUN_00003e00(*param_1,0x8006f19,0x30);
  *(undefined4 *)(iVar3 + 0x18) = uVar2;
  bVar7 = 1 - (*(int *)(param_1 + 8) == 0);
  if (*(int *)(param_1 + 0xc) != 0) {
    bVar7 = bVar7 | 0x10;
  }
  *(byte *)(iVar3 + 0x2c) = bVar7;
  *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(iVar3 + 0x28) = 0;
  *(undefined4 *)(iVar3 + 0x24) = 0;
  if (_DAT_20000a88 == 0) {
    if (DAT_20000a90 < 0xc) {
      DAT_20000a90 = 0xc;
    }
    return;
  }
  UNRECOVERED_JUMPTABLE = (code *)0x3f81;
  puVar4 = (undefined *)FUN_00003908();
  iVar3 = FUN_00003e00(*puVar4,0x8006f81,0x20);
  uVar5 = *(uint *)(puVar4 + 4);
  *(undefined4 *)(iVar3 + 4) = 0x8006571;
  if (uVar5 < 6) {
    uVar8 = 1;
    if (uVar5 != 0) {
      do {
        uVar1 = FUN_00001bf8(puVar4[uVar8 * 8],'\x01' - (*(int *)(puVar4 + uVar8 * 8 + 4) == 0));
        iVar6 = *(int *)(puVar4 + 4);
        iVar9 = iVar3 + uVar8;
        uVar8 = uVar8 + 1 & 0xff;
        *(undefined *)(iVar9 + 0xb) = uVar1;
      } while (uVar8 < iVar6 + 1U);
    }
    *(undefined **)(iVar3 + 0x18) = &LAB_000057e4;
    *(undefined2 *)(iVar3 + 0x1c) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0x20000810;
                    /* WARNING: Could not recover jumptable at 0x00003fe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00003764(0x12);
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003fec(undefined *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte **ppbVar1;
  undefined2 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte **ppbVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  bVar5 = DAT_20000a7c;
  uStack_4 = param_4;
  local_8 = param_3;
  local_c = param_2;
  if (DAT_20000a7c == 0) {
    DAT_20000a7c = 1;
    ppbVar9 = &local_c;
    uVar6 = (uint)DAT_200007f9;
    uVar12 = (uint)DAT_200007f8;
    if (uVar12 <= uVar6) {
      DAT_200007f8 = bVar5;
      uVar12 = 0;
      DAT_200007f9 = bVar5;
      uVar6 = 0;
    }
    pbVar13 = (byte *)(uint)(byte)param_1[1];
    if ((byte *)0x60 < pbVar13 + uVar12) {
      if (0x60 < (int)(pbVar13 + uVar12) - uVar6) {
        DAT_20000a7c = 0;
        return;
      }
      DAT_200007f8 = 0;
      uVar12 = uVar12 - DAT_200007f9;
      FUN_00008f30(0x20000798,DAT_200007f9 + 0x20000798,uVar12);
      DAT_200007f9 = 0;
      DAT_200007f8 = (byte)uVar12;
      _DAT_40013800 = _DAT_40013800 | 0x80;
      pbVar13 = (byte *)(uint)(byte)param_1[1];
    }
    iVar10 = uVar12 + 0x20000798;
    pbVar11 = pbVar13;
    if ((byte *)0x5 < pbVar13) {
      pbVar3 = *(byte **)(param_1 + 4);
      bVar5 = param_1[2];
      pbVar13 = pbVar13 + uVar12 + 0x20000795;
      pbVar11 = (byte *)(uVar12 + 0x2000079b);
      *(undefined *)(uVar12 + 0x2000079a) = *param_1;
      if (bVar5 != 0) {
        if (pbVar11 <= pbVar13) {
          pbVar7 = pbVar3 + (bVar5 - 1);
          do {
            uVar6 = (uint)*pbVar3;
            if (uVar6 == 5) {
              pbVar14 = *ppbVar9;
              pbVar8 = pbVar11 + 1;
              bVar5 = *pbVar14;
              if (bVar5 != 0) {
                if (pbVar8 < pbVar13) {
                  do {
                    pbVar4 = pbVar8 + 1;
                    pbVar14 = pbVar14 + 1;
                    *pbVar8 = bVar5;
                    bVar5 = *pbVar14;
                    pbVar8 = pbVar4;
                    if (bVar5 == 0) {
                      bVar5 = ((char)pbVar4 - (char)pbVar11) - 1;
                      goto LAB_0000423a;
                    }
                  } while (pbVar13 != pbVar4);
                  bVar5 = ((char)pbVar13 - (char)pbVar11) - 1;
                  pbVar8 = pbVar13;
                }
                else {
                  bVar5 = 0;
                }
              }
LAB_0000423a:
              *pbVar11 = bVar5;
LAB_00004170:
              ppbVar9 = ppbVar9 + 1;
              pbVar11 = pbVar8;
            }
            else {
              if (uVar6 < 6) {
                pbVar8 = *ppbVar9;
                if ((byte *)0x7f < pbVar8 + 0x20) {
                  pbVar14 = pbVar11;
                  if ((byte *)0x3fff < pbVar8 + 0x1000) {
                    if ((byte *)0x1fffff < pbVar8 + 0x80000) {
                      if ((byte *)0xfffffff < pbVar8 + 0x4000000) {
                        *pbVar11 = (byte)((uint)pbVar8 >> 0x1c) | 0x80;
                        pbVar14 = pbVar11 + 1;
                      }
                      pbVar11 = pbVar14 + 1;
                      *pbVar14 = (byte)((uint)pbVar8 >> 0x15) | 0x80;
                    }
                    *pbVar11 = (byte)((uint)pbVar8 >> 0xe) | 0x80;
                    pbVar14 = pbVar11 + 1;
                  }
                  pbVar11 = pbVar14 + 1;
                  *pbVar14 = (byte)((uint)pbVar8 >> 7) | 0x80;
                }
                *pbVar11 = (byte)pbVar8 & 0x7f;
                pbVar8 = pbVar11 + 1;
                goto LAB_00004170;
              }
              if (1 < uVar6 - 6) break;
              pbVar8 = pbVar13 + -(int)pbVar11;
              if (*ppbVar9 < pbVar13 + -(int)pbVar11) {
                pbVar8 = *ppbVar9;
              }
              *pbVar11 = (byte)pbVar8;
              ppbVar1 = ppbVar9 + 1;
              ppbVar9 = ppbVar9 + 2;
              FUN_00008e8c(pbVar11 + 1,*ppbVar1,pbVar8);
              pbVar11 = pbVar11 + 1 + (int)pbVar8;
            }
            if (pbVar7 == pbVar3) goto LAB_000041b4;
            pbVar3 = pbVar3 + 1;
          } while (pbVar11 <= pbVar13);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00003764(5);
      }
LAB_000041b4:
      pbVar11 = pbVar11 + (3 - iVar10);
      pbVar13 = (byte *)((uint)pbVar11 & 0xff);
    }
    *(char *)(uVar12 + 0x20000798) = (char)pbVar13;
    *(undefined *)(uVar12 + 0x20000799) = DAT_20000054;
    uVar2 = FUN_000020a0(iVar10,pbVar11 + -3);
    (pbVar11 + -3)[iVar10] = (byte)((ushort)uVar2 >> 8);
    pbVar11[uVar12 + 0x20000796] = (byte)uVar2;
    DAT_200007f8 = (char)pbVar13 + (char)uVar12;
    pbVar11[uVar12 + 0x20000797] = 0x7e;
    _DAT_40013800 = _DAT_40013800 | 0x80;
    DAT_20000a7c = 0;
  }
  return;
}




void FUN_00004260(undefined4 *param_1)

{
  FUN_00003fec(0x800c0e4,*(undefined *)param_1,0x133,*param_1,param_1[1],param_1[2],param_1[3],
               param_1[4],param_1[5]);
  return;
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004652(void)

{
  undefined uVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined uVar5;
  int iVar6;
  int iVar7;
  char extraout_r1;
  char cVar8;
  uint uVar9;
  uint extraout_r1_00;
  int extraout_r1_01;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int *piVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  undefined *puVar22;
  uint uVar23;
  uint uVar24;
  int *piVar25;
  int unaff_r7;
  bool bVar26;
  undefined8 uVar27;
  longlong lVar28;
  
  if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_000050d6();
  }
  uVar13 = **(uint **)(unaff_r7 + 0x40);
  *(uint *)(unaff_r7 + 0x18) = _DAT_40000424 ^ uVar13;
  *(uint *)(unaff_r7 + 0x14) = uVar13 & 0xffff;
  disableIRQinterrupts();
  if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
    FUN_000051ec();
  }
  enableIRQinterrupts();
  *(uint *)(unaff_r7 + 0x28) =
       *(int *)(unaff_r7 + 0x34) +
       ((((_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff))
        - *(int *)(unaff_r7 + 0x18)) - *(int *)(unaff_r7 + 0x14));
  *(undefined *)(*(int *)(unaff_r7 + 0x38) + 8) = 1;
  *(undefined *)(unaff_r7 + 0x60) = 0;
  iVar6 = FUN_0000617c(0x2000080c);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_000046dc:
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006f81), iVar6 != 0) {
      if (0x77 < *(byte *)(iVar6 + 0x1c)) {
        uVar13 = *(byte *)(iVar6 + 0x1d) & 0xfffffffe;
        *(uint *)(unaff_r7 + 0x50) = uVar13;
        *(char *)(iVar6 + 0x1d) = (char)uVar13;
        pbVar11 = *(byte **)(iVar6 + 0x14);
        *(byte **)(unaff_r7 + 0x3c) = pbVar11;
        *(int *)(unaff_r7 + 0x34) = iVar6;
        uVar13 = 1;
LAB_00004754:
        uVar21 = uVar13;
        uVar23 = *(int *)(unaff_r7 + 0x50) >> (uVar21 & 0xff);
        uVar13 = uVar23 & 1;
        if ((uVar23 & 1) != 0) {
          iVar6 = 1;
          do {
            bVar3 = pbVar11[iVar6];
            iVar20 = (int)(char)iVar6;
            if ((uint)bVar3 != (uint)*pbVar11) {
              if (iVar20 != 0x77) {
                uVar13 = 0x76;
                goto LAB_00004800;
              }
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 != 0x78);
LAB_000048d0:
          uVar13 = 0;
        }
        goto LAB_00004762;
      }
      iVar20 = 0;
      uVar13 = 0;
      do {
        uVar23 = uVar13 + 1;
        bVar26 = false;
        if (((int)(uint)*(byte *)(iVar6 + 0x1d) >> (uVar23 & 0xff) & 1U) != 0) {
          iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0xc));
          bVar26 = iVar7 != 0;
        }
        bVar3 = *(byte *)(iVar6 + 0x1c);
        *(bool *)(*(int *)(iVar6 + 0x14) + (uint)bVar3 + iVar20) = bVar26;
        iVar20 = iVar20 + 0x7c;
        uVar13 = uVar23;
      } while (uVar23 != 5);
      *(byte *)(iVar6 + 0x1c) = bVar3 + 1;
    }
  }
  iVar6 = FUN_0000617c(0x20000b20);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006e45), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 4) != 0) {
        disableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x20);
        *(byte *)(iVar6 + 0x20) = bVar3 & 0xfb;
        enableIRQinterrupts();
        FUN_00003fec(0x800c1b4,*(undefined *)(unaff_r7 + 0x60),bVar3 & 1,
                     *(undefined *)(iVar6 + 0x21));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001fc);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    do {
      puVar17 = *(uint **)(unaff_r7 + 0x40);
      do {
        iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x8003c55);
        if (((iVar6 == 0) || ((*(byte *)(iVar6 + 0x14) & 1) == 0)) || (*(int *)(iVar6 + 0x1c) < 1))
        goto LAB_00004bba;
        FUN_00008fe8(unaff_r7 + 0x60,0,0x10);
        uVar13 = 0;
        if (*(int *)(iVar6 + 0x18) != 0) {
          uVar23 = 0;
          do {
            iVar20 = FUN_00000f18(*(undefined *)(iVar6 + uVar23 + 0x30));
            uVar13 = uVar13 | iVar20 << (uVar23 & 0xff);
            uVar23 = uVar23 + 1;
          } while (uVar23 < *(uint *)(iVar6 + 0x18));
        }
        *(uint *)(unaff_r7 + 0x48) = (_DAT_40000424 ^ *puVar17) + (*puVar17 & 0xffff);
        *(undefined4 *)(unaff_r7 + 0x4c) = 0;
        iVar20 = iRam20000a84;
        uVar23 = uRam20000a80;
        *(uint *)(unaff_r7 + 0x50) = uRam20000a80;
        *(int *)(unaff_r7 + 0x54) = iVar20;
        if ((iVar20 != 0) || (*(uint *)(unaff_r7 + 0x48) < uVar23)) {
          iVar20 = *(int *)(unaff_r7 + 0x48);
          *(int *)(unaff_r7 + 0x48) = iVar20 + -1;
          *(uint *)(unaff_r7 + 0x4c) = *(int *)(unaff_r7 + 0x4c) + (uint)(iVar20 != 0);
        }
      } while (uVar13 != 0);
      if (*(int *)(iVar6 + 0x18) != 0) {
        uVar13 = 0;
        do {
          FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
          uVar23 = *(uint *)(iVar6 + 0x18);
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar23);
        iVar20 = 0x18;
        do {
          if (uVar23 == 0) goto LAB_00004b2c;
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 == 0) goto LAB_00004b2c;
          piVar18 = (int *)(unaff_r7 + 0x60);
          piVar25 = piVar18 + uVar23;
          do {
            *piVar18 = *piVar18 << 1;
            piVar18 = piVar18 + 1;
          } while (piVar25 != piVar18);
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            uVar13 = 0;
            piVar25 = (int *)(unaff_r7 + 0x60);
            do {
              iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0x30));
              uVar13 = uVar13 + 1;
              uVar23 = *(uint *)(iVar6 + 0x18);
              *piVar25 = (uint)(iVar7 != 0) + *piVar25;
              piVar25 = piVar25 + 1;
            } while (uVar13 < uVar23);
          }
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        uVar13 = 0;
        if (uVar23 != 0) {
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            puVar19 = (uint *)(unaff_r7 + 0x60);
            puVar17 = puVar19 + uVar23;
            do {
              uVar13 = *puVar19;
              if ((uVar13 & 0x800000) != 0) {
                uVar13 = uVar13 | 0xff000000;
              }
              *puVar19 = uVar13;
              puVar19 = puVar19 + 1;
            } while (puVar17 != puVar19);
            uVar13 = 0;
            do {
              FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
              uVar13 = uVar13 + 1;
            } while (uVar13 < *(uint *)(iVar6 + 0x18));
          }
        }
      }
LAB_00004b2c:
      uRam20000a80 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                     (**(uint **)(unaff_r7 + 0x40) & 0xffff);
      iRam20000a84 = 0;
      uVar12 = FUN_000063e4(*(uint *)(unaff_r7 + 0x48) - *(uint *)(unaff_r7 + 0x50),
                            (*(int *)(unaff_r7 + 0x4c) - *(int *)(unaff_r7 + 0x54)) -
                            (uint)(*(uint *)(unaff_r7 + 0x48) < *(uint *)(unaff_r7 + 0x50)));
      uVar12 = FUN_00006644(uVar12,0x447a0000);
      FUN_0000642c(uVar12,0x4c895440);
      uVar5 = FUN_000063a4();
      uVar1 = *(undefined *)(iVar6 + 0xc);
      *(undefined4 *)(unaff_r7 + 0x50) = *(undefined4 *)(unaff_r7 + 0x60);
      FUN_00003fec(0x800c0f4,uVar1,0,uVar5);
      iVar20 = *(int *)(iVar6 + 0x1c) + -1;
      *(int *)(iVar6 + 0x1c) = iVar20;
      if (iVar20 == 0) {
        *(byte *)(iVar6 + 0x14) = *(byte *)(iVar6 + 0x14) & 0xfe;
      }
    } while( true );
  }
LAB_00004bba:
  iVar6 = FUN_0000617c(0x200001f8);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while ((iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003bf5), iVar6 != 0 &&
           (*(int *)(iVar6 + 0x78) != 0))) {
      FUN_00003fec(0x800c0fc,*(undefined *)(iVar6 + 0xc),*(uint *)(iVar6 + 0x7c) & 0xffff,
                   *(undefined4 *)(iVar6 + 0x80));
      *(undefined4 *)(iVar6 + 0x78) = 0;
    }
  }
  iVar6 = FUN_0000617c(0x2000006c);
  if (iVar6 == 0) goto LAB_00004c56;
  puVar22 = (undefined *)0x26;
  *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_00004c28:
  iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
  if (iVar6 != 0) goto code_r0x00004c3e;
LAB_00004c56:
  iVar6 = FUN_0000617c(0x20000788);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    while (iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x1f) & 1) != 0) {
        disableIRQinterrupts();
        uVar12 = *(undefined4 *)(iVar6 + 8);
        *(byte *)(iVar6 + 0x1f) = *(byte *)(iVar6 + 0x1f) & 0xfe;
        enableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x1e);
        if (bVar3 == 2) {
          *(undefined4 *)(unaff_r7 + 0x60) = 1;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,3,unaff_r7 + 0x60);
          uVar13 = *(uint *)(unaff_r7 + 0x60);
          *(undefined2 *)(unaff_r7 + 0x60) = 7;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (((uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
          FUN_00002244(iVar6,uVar12,uVar13,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar13 & 1);
        }
        else if (bVar3 < 3) {
          if (bVar3 == 0) {
            *(undefined4 *)(unaff_r7 + 0x60) = 0;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                         (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18,uVar13 >> 0x18 & 7);
          }
          else {
            *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         (uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8 |
                         uVar13 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
          }
        }
        else if (bVar3 == 3) {
          *(undefined2 *)(unaff_r7 + 0x60) = 0;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
          FUN_00002244(iVar6,uVar12,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar13,uVar13 & 6);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000068);
  if (iVar6 != 0) {
    puVar22 = (undefined *)(unaff_r7 + 0x5f);
    *puVar22 = 0xff;
    while (iVar6 = FUN_000033d4(puVar22,0x80037c5), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x18) & 4) != 0) {
        if ((int)((uint)*(byte *)(iVar6 + 0x18) << 0x1f) < 0) {
          FUN_000061a0(iVar6);
          *(undefined *)(iVar6 + 0x18) = 2;
          *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x10),0,2,unaff_r7 + 0x60);
          disableIRQinterrupts();
          *(uint *)(iVar6 + 8) =
               (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
               (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar6 + 0xc);
          FUN_000061fc(iVar6);
          enableIRQinterrupts();
        }
        else {
          FUN_00002478(iVar6,*puVar22);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000794);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x11) & 8) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) & 0xf7;
        enableIRQinterrupts();
        FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar6 + 0x13) >> 3,
                     iVar6 + 0x20);
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f4);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 1) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x20) = *(byte *)(iVar6 + 0x20) & 0xfe;
        enableIRQinterrupts();
        FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar6 + 8),
                     *(undefined4 *)(iVar6 + 0x18));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f0);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar6 != 0) {
      if (*(char *)(iVar6 + 0x1c) == -1) {
        disableIRQinterrupts();
        if (*(char *)(iVar6 + 0x12) == '\0') {
          enableIRQinterrupts();
        }
        else {
          *(undefined *)(iVar6 + 0x1c) = *(undefined *)(iVar6 + 0x1d);
          enableIRQinterrupts();
          FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar6 + 0x1b));
        }
      }
    }
  }
  uRam40003000 = 0xaaaa;
  iVar20 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  disableIRQinterrupts();
  iVar6 = **(int **)(unaff_r7 + 4);
  *(int *)(unaff_r7 + 0x50) = iVar6;
  if (iVar6 - iVar20 < 0) {
    **(int **)(unaff_r7 + 4) = iVar20;
  }
  enableIRQinterrupts();
  uVar13 = (uint)**(byte **)(unaff_r7 + 0x2c);
  if (uVar13 != 0) {
    uVar23 = (uint)**(byte **)(unaff_r7 + 0x30);
    if (-1 < (int)(uVar23 << 0x1f)) {
      if (uVar13 < 5) goto LAB_00005012;
      pbVar11 = *(byte **)(unaff_r7 + 0x1c);
      uVar21 = (uint)*pbVar11;
      if ((uVar21 - 5 < 0x3c) && ((pbVar11[1] & 0xf0) == 0x10)) {
        if (uVar13 < uVar21) goto LAB_00005012;
        if (pbVar11[uVar21 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
          FUN_000059f2();
        }
      }
      if (uVar21 == 0x7e) {
                    /* WARNING: Subroutine does not return */
        FUN_00004fce();
      }
      uVar23 = uVar23 | 1;
      **(undefined **)(unaff_r7 + 0x30) = (char)uVar23;
    }
    iVar6 = FUN_00008e08(0x20000528,0x7e,uVar13);
    if (iVar6 == 0) {
      iVar6 = FUN_000059aa();
    }
    bVar3 = (byte)(uVar23 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar3;
    uVar13 = (iVar6 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar23 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar3 | 2;
    FUN_00003fec(0x800d4cc);
    lVar28 = (ulonglong)extraout_r1_00 << 0x20;
    bVar3 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar3 != uVar13) {
      lVar28 = FUN_00005980(0);
    }
    uVar23 = 0;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      uVar23 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar3 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar28,(int)((ulonglong)lVar28 >> 0x20),uVar23);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar3 - (char)uVar13;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      enableIRQinterrupts((uVar23 & 1) == 1);
    }
  }
LAB_00005012:
  iVar6 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  *(int *)(unaff_r7 + 0x34) = iVar6;
  uVar23 = _DAT_20000b0c;
  uVar13 = iVar6 - *(int *)(unaff_r7 + 0x28);
  iVar6 = _DAT_20000808 + 1;
  iVar20 = _DAT_20000b14 + uVar13;
  if (uVar13 < 0x10000) {
    uVar13 = uVar13 * uVar13 + 0xff >> 8;
LAB_0000506c:
    uVar13 = uVar13 + _DAT_20000b18;
    if (uVar13 < _DAT_20000b18) {
      uVar13 = 0xffffffff;
    }
  }
  else {
    if (uVar13 < 0x100000) {
      uVar13 = (uVar13 + 0xff >> 8) * uVar13;
      goto LAB_0000506c;
    }
    uVar13 = 0xffffffff;
  }
  puVar22 = &DAT_20000b18;
  _DAT_20000808 = iVar6;
  _DAT_20000b14 = iVar20;
  _DAT_20000b18 = uVar13;
  if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
    FUN_00004652();
    iVar6 = extraout_r1_01;
  }
  FUN_00003fec(0x800c16c,iVar6,iVar20);
  if (*(uint *)(unaff_r7 + 0x34) < uVar23) {
    _DAT_20000b10 = _DAT_20000b10 + 1;
  }
  _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
  _DAT_20000b18 = 0;
  _DAT_20000b14 = 0;
  _DAT_20000808 = 0;
  if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_00004660();
  }
  *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
  iVar6 = FUN_000046b4();
  cVar8 = extraout_r1;
  goto LAB_000050de;
LAB_00004800:
  if ((uint)pbVar11[uVar13] == (uint)pbVar11[0x77]) goto LAB_000047fa;
  uVar23 = uVar13 & 0xff;
  if ((char)uVar13 == '\x01') goto LAB_000048d0;
  bVar2 = pbVar11[iVar6];
  if ((uint)bVar2 == (uint)pbVar11[uVar13]) {
                    /* WARNING: Subroutine does not return */
    FUN_000050fc();
  }
  if ((int)uVar23 <= iVar6 + 3) goto LAB_000048d0;
  iVar6 = (uVar23 - iVar6) + 1;
  uVar13 = iVar6 >> 2 & 0xff;
  if ((int)uVar23 < iVar20) {
    uVar23 = 0;
    if (uVar13 != 0) goto LAB_000048d0;
    goto LAB_0000488e;
  }
  *(uint *)(unaff_r7 + 0x44) = uVar23;
  uVar24 = 0;
  uVar15 = 0;
  uVar23 = (uint)bVar3;
  uVar16 = (uint)bVar2;
  while( true ) {
    uVar9 = uVar23;
    uVar24 = uVar9 + uVar24 & 0xff;
    if (uVar9 != uVar16) {
      uVar15 = uVar15 + 1 & 0xff;
    }
    iVar20 = (int)(char)((char)iVar20 + '\x01');
    if (*(int *)(unaff_r7 + 0x44) < iVar20) break;
    uVar23 = (uint)pbVar11[iVar20];
    uVar16 = uVar9;
  }
  if (uVar24 < uVar13) goto LAB_000048d0;
  uVar13 = 0;
  if ((uVar24 <= (iVar6 * 3 >> 2 & 0xffU)) &&
     (uVar16 = (int)(uVar15 + 1) >> 1, uVar23 = uVar24 / uVar16, uVar16 <= uVar24)) {
LAB_0000488e:
    uVar27 = FUN_000089ac(uVar23 * 0x57e4);
    uVar27 = FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x40100000);
    uVar27 = FUN_00007480(0,0x41912a88,(int)uVar27,(int)((ulonglong)uVar27 >> 0x20));
    FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x404e0000);
    uVar13 = FUN_00006368();
  }
LAB_00004762:
  *(uint *)(pbVar11 + 0x78) = uVar13;
  pbVar11 = pbVar11 + 0x7c;
  uVar13 = uVar21 + 1;
  if (uVar21 + 1 == 6) goto code_r0x0000476c;
  goto LAB_00004754;
LAB_000047fa:
  uVar13 = uVar13 - 1;
  if (uVar13 == 0) goto LAB_00004762;
  goto LAB_00004800;
code_r0x0000476c:
  iVar6 = *(int *)(unaff_r7 + 0x34);
  FUN_00003fec(0x800c19c,*(undefined *)(unaff_r7 + 0x60),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x78),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0xf4));
  uVar13 = 1;
  uVar23 = (uint)*(byte *)(iVar6 + 0x1d);
  puVar10 = (undefined4 *)(*(int *)(iVar6 + 0x14) + 0x78);
  do {
    puVar14 = puVar10 + -0x1e;
    do {
      *(undefined *)puVar14 = 0;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    } while (puVar10 != puVar14);
    uVar16 = uVar13 & 0xff;
    uVar13 = uVar13 + 1;
    *puVar10 = 0;
    uVar23 = uVar23 & ~(uVar21 - 4 << uVar16);
    puVar10 = puVar10 + 0x1f;
  } while (uVar13 != 6);
  *(char *)(iVar6 + 0x1d) = (char)uVar23;
  *(undefined *)(iVar6 + 0x1c) = 0;
  goto LAB_000046dc;
code_r0x00004c3e:
  if (puVar22[iVar6] == *(char *)(iVar6 + 0x27)) {
    disableIRQinterrupts();
    cVar8 = *(char *)(iVar6 + 0x27);
    if (cVar8 == puVar22[iVar6]) {
LAB_000050de:
      uVar4 = *(undefined2 *)(iVar6 + 0x18);
      uVar12 = *(undefined4 *)(iVar6 + 0x14);
      puVar22[iVar6] = cVar8 + '\x01';
      enableIRQinterrupts();
      FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar12,uVar4);
    }
    else {
      enableIRQinterrupts();
    }
  }
  goto LAB_00004c28;
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004660(undefined4 param_1,int param_2)

{
  undefined uVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined uVar5;
  int iVar6;
  int iVar7;
  char extraout_r1;
  char cVar8;
  uint uVar9;
  uint extraout_r1_00;
  int extraout_r1_01;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int *piVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  undefined *puVar22;
  uint uVar23;
  uint uVar24;
  int *piVar25;
  int unaff_r7;
  bool bVar26;
  undefined8 uVar27;
  longlong lVar28;
  
  uVar13 = **(uint **)(unaff_r7 + 0x40);
  *(uint *)(unaff_r7 + 0x18) = _DAT_40000424 ^ uVar13;
  *(uint *)(unaff_r7 + 0x14) = uVar13 & 0xffff;
  disableIRQinterrupts();
  if (*(char *)(param_2 + 8) != '\0') {
    FUN_000051ec();
  }
  enableIRQinterrupts();
  *(uint *)(unaff_r7 + 0x28) =
       *(int *)(unaff_r7 + 0x34) +
       ((((_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff))
        - *(int *)(unaff_r7 + 0x18)) - *(int *)(unaff_r7 + 0x14));
  *(undefined *)(*(int *)(unaff_r7 + 0x38) + 8) = 1;
  *(undefined *)(unaff_r7 + 0x60) = 0;
  iVar6 = FUN_0000617c(0x2000080c);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_000046dc:
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006f81), iVar6 != 0) {
      if (0x77 < *(byte *)(iVar6 + 0x1c)) {
        uVar13 = *(byte *)(iVar6 + 0x1d) & 0xfffffffe;
        *(uint *)(unaff_r7 + 0x50) = uVar13;
        *(char *)(iVar6 + 0x1d) = (char)uVar13;
        pbVar11 = *(byte **)(iVar6 + 0x14);
        *(byte **)(unaff_r7 + 0x3c) = pbVar11;
        *(int *)(unaff_r7 + 0x34) = iVar6;
        uVar13 = 1;
LAB_00004754:
        uVar21 = uVar13;
        uVar23 = *(int *)(unaff_r7 + 0x50) >> (uVar21 & 0xff);
        uVar13 = uVar23 & 1;
        if ((uVar23 & 1) != 0) {
          iVar6 = 1;
          do {
            bVar3 = pbVar11[iVar6];
            iVar20 = (int)(char)iVar6;
            if ((uint)bVar3 != (uint)*pbVar11) {
              if (iVar20 != 0x77) {
                uVar13 = 0x76;
                goto LAB_00004800;
              }
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 != 0x78);
LAB_000048d0:
          uVar13 = 0;
        }
        goto LAB_00004762;
      }
      iVar20 = 0;
      uVar13 = 0;
      do {
        uVar23 = uVar13 + 1;
        bVar26 = false;
        if (((int)(uint)*(byte *)(iVar6 + 0x1d) >> (uVar23 & 0xff) & 1U) != 0) {
          iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0xc));
          bVar26 = iVar7 != 0;
        }
        bVar3 = *(byte *)(iVar6 + 0x1c);
        *(bool *)(*(int *)(iVar6 + 0x14) + (uint)bVar3 + iVar20) = bVar26;
        iVar20 = iVar20 + 0x7c;
        uVar13 = uVar23;
      } while (uVar23 != 5);
      *(byte *)(iVar6 + 0x1c) = bVar3 + 1;
    }
  }
  iVar6 = FUN_0000617c(0x20000b20);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006e45), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 4) != 0) {
        disableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x20);
        *(byte *)(iVar6 + 0x20) = bVar3 & 0xfb;
        enableIRQinterrupts();
        FUN_00003fec(0x800c1b4,*(undefined *)(unaff_r7 + 0x60),bVar3 & 1,
                     *(undefined *)(iVar6 + 0x21));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001fc);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    do {
      puVar17 = *(uint **)(unaff_r7 + 0x40);
      do {
        iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x8003c55);
        if (((iVar6 == 0) || ((*(byte *)(iVar6 + 0x14) & 1) == 0)) || (*(int *)(iVar6 + 0x1c) < 1))
        goto LAB_00004bba;
        FUN_00008fe8(unaff_r7 + 0x60,0,0x10);
        uVar13 = 0;
        if (*(int *)(iVar6 + 0x18) != 0) {
          uVar23 = 0;
          do {
            iVar20 = FUN_00000f18(*(undefined *)(iVar6 + uVar23 + 0x30));
            uVar13 = uVar13 | iVar20 << (uVar23 & 0xff);
            uVar23 = uVar23 + 1;
          } while (uVar23 < *(uint *)(iVar6 + 0x18));
        }
        *(uint *)(unaff_r7 + 0x48) = (_DAT_40000424 ^ *puVar17) + (*puVar17 & 0xffff);
        *(undefined4 *)(unaff_r7 + 0x4c) = 0;
        iVar20 = iRam20000a84;
        uVar23 = uRam20000a80;
        *(uint *)(unaff_r7 + 0x50) = uRam20000a80;
        *(int *)(unaff_r7 + 0x54) = iVar20;
        if ((iVar20 != 0) || (*(uint *)(unaff_r7 + 0x48) < uVar23)) {
          iVar20 = *(int *)(unaff_r7 + 0x48);
          *(int *)(unaff_r7 + 0x48) = iVar20 + -1;
          *(uint *)(unaff_r7 + 0x4c) = *(int *)(unaff_r7 + 0x4c) + (uint)(iVar20 != 0);
        }
      } while (uVar13 != 0);
      if (*(int *)(iVar6 + 0x18) != 0) {
        uVar13 = 0;
        do {
          FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
          uVar23 = *(uint *)(iVar6 + 0x18);
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar23);
        iVar20 = 0x18;
        do {
          if (uVar23 == 0) goto LAB_00004b2c;
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 == 0) goto LAB_00004b2c;
          piVar18 = (int *)(unaff_r7 + 0x60);
          piVar25 = piVar18 + uVar23;
          do {
            *piVar18 = *piVar18 << 1;
            piVar18 = piVar18 + 1;
          } while (piVar25 != piVar18);
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            uVar13 = 0;
            piVar25 = (int *)(unaff_r7 + 0x60);
            do {
              iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0x30));
              uVar13 = uVar13 + 1;
              uVar23 = *(uint *)(iVar6 + 0x18);
              *piVar25 = (uint)(iVar7 != 0) + *piVar25;
              piVar25 = piVar25 + 1;
            } while (uVar13 < uVar23);
          }
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        uVar13 = 0;
        if (uVar23 != 0) {
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            puVar19 = (uint *)(unaff_r7 + 0x60);
            puVar17 = puVar19 + uVar23;
            do {
              uVar13 = *puVar19;
              if ((uVar13 & 0x800000) != 0) {
                uVar13 = uVar13 | 0xff000000;
              }
              *puVar19 = uVar13;
              puVar19 = puVar19 + 1;
            } while (puVar17 != puVar19);
            uVar13 = 0;
            do {
              FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
              uVar13 = uVar13 + 1;
            } while (uVar13 < *(uint *)(iVar6 + 0x18));
          }
        }
      }
LAB_00004b2c:
      uRam20000a80 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                     (**(uint **)(unaff_r7 + 0x40) & 0xffff);
      iRam20000a84 = 0;
      uVar12 = FUN_000063e4(*(uint *)(unaff_r7 + 0x48) - *(uint *)(unaff_r7 + 0x50),
                            (*(int *)(unaff_r7 + 0x4c) - *(int *)(unaff_r7 + 0x54)) -
                            (uint)(*(uint *)(unaff_r7 + 0x48) < *(uint *)(unaff_r7 + 0x50)));
      uVar12 = FUN_00006644(uVar12,0x447a0000);
      FUN_0000642c(uVar12,0x4c895440);
      uVar5 = FUN_000063a4();
      uVar1 = *(undefined *)(iVar6 + 0xc);
      *(undefined4 *)(unaff_r7 + 0x50) = *(undefined4 *)(unaff_r7 + 0x60);
      FUN_00003fec(0x800c0f4,uVar1,0,uVar5);
      iVar20 = *(int *)(iVar6 + 0x1c) + -1;
      *(int *)(iVar6 + 0x1c) = iVar20;
      if (iVar20 == 0) {
        *(byte *)(iVar6 + 0x14) = *(byte *)(iVar6 + 0x14) & 0xfe;
      }
    } while( true );
  }
LAB_00004bba:
  iVar6 = FUN_0000617c(0x200001f8);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while ((iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003bf5), iVar6 != 0 &&
           (*(int *)(iVar6 + 0x78) != 0))) {
      FUN_00003fec(0x800c0fc,*(undefined *)(iVar6 + 0xc),*(uint *)(iVar6 + 0x7c) & 0xffff,
                   *(undefined4 *)(iVar6 + 0x80));
      *(undefined4 *)(iVar6 + 0x78) = 0;
    }
  }
  iVar6 = FUN_0000617c(0x2000006c);
  if (iVar6 == 0) goto LAB_00004c56;
  puVar22 = (undefined *)0x26;
  *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_00004c28:
  iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
  if (iVar6 != 0) goto code_r0x00004c3e;
LAB_00004c56:
  iVar6 = FUN_0000617c(0x20000788);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    while (iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x1f) & 1) != 0) {
        disableIRQinterrupts();
        uVar12 = *(undefined4 *)(iVar6 + 8);
        *(byte *)(iVar6 + 0x1f) = *(byte *)(iVar6 + 0x1f) & 0xfe;
        enableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x1e);
        if (bVar3 == 2) {
          *(undefined4 *)(unaff_r7 + 0x60) = 1;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,3,unaff_r7 + 0x60);
          uVar13 = *(uint *)(unaff_r7 + 0x60);
          *(undefined2 *)(unaff_r7 + 0x60) = 7;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (((uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
          FUN_00002244(iVar6,uVar12,uVar13,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar13 & 1);
        }
        else if (bVar3 < 3) {
          if (bVar3 == 0) {
            *(undefined4 *)(unaff_r7 + 0x60) = 0;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                         (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18,uVar13 >> 0x18 & 7);
          }
          else {
            *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         (uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8 |
                         uVar13 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
          }
        }
        else if (bVar3 == 3) {
          *(undefined2 *)(unaff_r7 + 0x60) = 0;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
          FUN_00002244(iVar6,uVar12,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar13,uVar13 & 6);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000068);
  if (iVar6 != 0) {
    puVar22 = (undefined *)(unaff_r7 + 0x5f);
    *puVar22 = 0xff;
    while (iVar6 = FUN_000033d4(puVar22,0x80037c5), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x18) & 4) != 0) {
        if ((int)((uint)*(byte *)(iVar6 + 0x18) << 0x1f) < 0) {
          FUN_000061a0(iVar6);
          *(undefined *)(iVar6 + 0x18) = 2;
          *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x10),0,2,unaff_r7 + 0x60);
          disableIRQinterrupts();
          *(uint *)(iVar6 + 8) =
               (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
               (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar6 + 0xc);
          FUN_000061fc(iVar6);
          enableIRQinterrupts();
        }
        else {
          FUN_00002478(iVar6,*puVar22);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000794);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x11) & 8) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) & 0xf7;
        enableIRQinterrupts();
        FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar6 + 0x13) >> 3,
                     iVar6 + 0x20);
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f4);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 1) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x20) = *(byte *)(iVar6 + 0x20) & 0xfe;
        enableIRQinterrupts();
        FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar6 + 8),
                     *(undefined4 *)(iVar6 + 0x18));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f0);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar6 != 0) {
      if (*(char *)(iVar6 + 0x1c) == -1) {
        disableIRQinterrupts();
        if (*(char *)(iVar6 + 0x12) == '\0') {
          enableIRQinterrupts();
        }
        else {
          *(undefined *)(iVar6 + 0x1c) = *(undefined *)(iVar6 + 0x1d);
          enableIRQinterrupts();
          FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar6 + 0x1b));
        }
      }
    }
  }
  uRam40003000 = 0xaaaa;
  iVar20 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  disableIRQinterrupts();
  iVar6 = **(int **)(unaff_r7 + 4);
  *(int *)(unaff_r7 + 0x50) = iVar6;
  if (iVar6 - iVar20 < 0) {
    **(int **)(unaff_r7 + 4) = iVar20;
  }
  enableIRQinterrupts();
  uVar13 = (uint)**(byte **)(unaff_r7 + 0x2c);
  if (uVar13 != 0) {
    uVar23 = (uint)**(byte **)(unaff_r7 + 0x30);
    if (-1 < (int)(uVar23 << 0x1f)) {
      if (uVar13 < 5) goto LAB_00005012;
      pbVar11 = *(byte **)(unaff_r7 + 0x1c);
      uVar21 = (uint)*pbVar11;
      if ((uVar21 - 5 < 0x3c) && ((pbVar11[1] & 0xf0) == 0x10)) {
        if (uVar13 < uVar21) goto LAB_00005012;
        if (pbVar11[uVar21 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
          FUN_000059f2();
        }
      }
      if (uVar21 == 0x7e) {
                    /* WARNING: Subroutine does not return */
        FUN_00004fce();
      }
      uVar23 = uVar23 | 1;
      **(undefined **)(unaff_r7 + 0x30) = (char)uVar23;
    }
    iVar6 = FUN_00008e08(0x20000528,0x7e,uVar13);
    if (iVar6 == 0) {
      iVar6 = FUN_000059aa();
    }
    bVar3 = (byte)(uVar23 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar3;
    uVar13 = (iVar6 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar23 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar3 | 2;
    FUN_00003fec(0x800d4cc);
    lVar28 = (ulonglong)extraout_r1_00 << 0x20;
    bVar3 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar3 != uVar13) {
      lVar28 = FUN_00005980(0);
    }
    uVar23 = 0;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      uVar23 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar3 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar28,(int)((ulonglong)lVar28 >> 0x20),uVar23);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar3 - (char)uVar13;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      enableIRQinterrupts((uVar23 & 1) == 1);
    }
  }
LAB_00005012:
  iVar6 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  *(int *)(unaff_r7 + 0x34) = iVar6;
  uVar23 = _DAT_20000b0c;
  uVar13 = iVar6 - *(int *)(unaff_r7 + 0x28);
  iVar6 = _DAT_20000808 + 1;
  iVar20 = _DAT_20000b14 + uVar13;
  if (uVar13 < 0x10000) {
    uVar13 = uVar13 * uVar13 + 0xff >> 8;
LAB_0000506c:
    uVar13 = uVar13 + _DAT_20000b18;
    if (uVar13 < _DAT_20000b18) {
      uVar13 = 0xffffffff;
    }
  }
  else {
    if (uVar13 < 0x100000) {
      uVar13 = (uVar13 + 0xff >> 8) * uVar13;
      goto LAB_0000506c;
    }
    uVar13 = 0xffffffff;
  }
  puVar22 = &DAT_20000b18;
  _DAT_20000808 = iVar6;
  _DAT_20000b14 = iVar20;
  _DAT_20000b18 = uVar13;
  if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
    FUN_00004652();
    iVar6 = extraout_r1_01;
  }
  FUN_00003fec(0x800c16c,iVar6,iVar20);
  if (*(uint *)(unaff_r7 + 0x34) < uVar23) {
    _DAT_20000b10 = _DAT_20000b10 + 1;
  }
  _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
  _DAT_20000b18 = 0;
  _DAT_20000b14 = 0;
  _DAT_20000808 = 0;
  if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_00004660();
  }
  *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
  iVar6 = FUN_000046b4();
  cVar8 = extraout_r1;
  goto LAB_000050de;
LAB_00004800:
  if ((uint)pbVar11[uVar13] == (uint)pbVar11[0x77]) goto LAB_000047fa;
  uVar23 = uVar13 & 0xff;
  if ((char)uVar13 == '\x01') goto LAB_000048d0;
  bVar2 = pbVar11[iVar6];
  if ((uint)bVar2 == (uint)pbVar11[uVar13]) {
                    /* WARNING: Subroutine does not return */
    FUN_000050fc();
  }
  if ((int)uVar23 <= iVar6 + 3) goto LAB_000048d0;
  iVar6 = (uVar23 - iVar6) + 1;
  uVar13 = iVar6 >> 2 & 0xff;
  if ((int)uVar23 < iVar20) {
    uVar23 = 0;
    if (uVar13 != 0) goto LAB_000048d0;
    goto LAB_0000488e;
  }
  *(uint *)(unaff_r7 + 0x44) = uVar23;
  uVar24 = 0;
  uVar15 = 0;
  uVar23 = (uint)bVar3;
  uVar16 = (uint)bVar2;
  while( true ) {
    uVar9 = uVar23;
    uVar24 = uVar9 + uVar24 & 0xff;
    if (uVar9 != uVar16) {
      uVar15 = uVar15 + 1 & 0xff;
    }
    iVar20 = (int)(char)((char)iVar20 + '\x01');
    if (*(int *)(unaff_r7 + 0x44) < iVar20) break;
    uVar23 = (uint)pbVar11[iVar20];
    uVar16 = uVar9;
  }
  if (uVar24 < uVar13) goto LAB_000048d0;
  uVar13 = 0;
  if ((uVar24 <= (iVar6 * 3 >> 2 & 0xffU)) &&
     (uVar16 = (int)(uVar15 + 1) >> 1, uVar23 = uVar24 / uVar16, uVar16 <= uVar24)) {
LAB_0000488e:
    uVar27 = FUN_000089ac(uVar23 * 0x57e4);
    uVar27 = FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x40100000);
    uVar27 = FUN_00007480(0,0x41912a88,(int)uVar27,(int)((ulonglong)uVar27 >> 0x20));
    FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x404e0000);
    uVar13 = FUN_00006368();
  }
LAB_00004762:
  *(uint *)(pbVar11 + 0x78) = uVar13;
  pbVar11 = pbVar11 + 0x7c;
  uVar13 = uVar21 + 1;
  if (uVar21 + 1 == 6) goto code_r0x0000476c;
  goto LAB_00004754;
LAB_000047fa:
  uVar13 = uVar13 - 1;
  if (uVar13 == 0) goto LAB_00004762;
  goto LAB_00004800;
code_r0x0000476c:
  iVar6 = *(int *)(unaff_r7 + 0x34);
  FUN_00003fec(0x800c19c,*(undefined *)(unaff_r7 + 0x60),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x78),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0xf4));
  uVar13 = 1;
  uVar23 = (uint)*(byte *)(iVar6 + 0x1d);
  puVar10 = (undefined4 *)(*(int *)(iVar6 + 0x14) + 0x78);
  do {
    puVar14 = puVar10 + -0x1e;
    do {
      *(undefined *)puVar14 = 0;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    } while (puVar10 != puVar14);
    uVar16 = uVar13 & 0xff;
    uVar13 = uVar13 + 1;
    *puVar10 = 0;
    uVar23 = uVar23 & ~(uVar21 - 4 << uVar16);
    puVar10 = puVar10 + 0x1f;
  } while (uVar13 != 6);
  *(char *)(iVar6 + 0x1d) = (char)uVar23;
  *(undefined *)(iVar6 + 0x1c) = 0;
  goto LAB_000046dc;
code_r0x00004c3e:
  if (puVar22[iVar6] == *(char *)(iVar6 + 0x27)) {
    disableIRQinterrupts();
    cVar8 = *(char *)(iVar6 + 0x27);
    if (cVar8 == puVar22[iVar6]) {
LAB_000050de:
      uVar4 = *(undefined2 *)(iVar6 + 0x18);
      uVar12 = *(undefined4 *)(iVar6 + 0x14);
      puVar22[iVar6] = cVar8 + '\x01';
      enableIRQinterrupts();
      FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar12,uVar4);
    }
    else {
      enableIRQinterrupts();
    }
  }
  goto LAB_00004c28;
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004688(void)

{
  undefined uVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined uVar5;
  int iVar6;
  int iVar7;
  char extraout_r1;
  char cVar8;
  uint uVar9;
  uint extraout_r1_00;
  int extraout_r1_01;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int *piVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  undefined *puVar22;
  uint uVar23;
  uint uVar24;
  int *piVar25;
  int unaff_r7;
  bool bVar26;
  undefined8 uVar27;
  longlong lVar28;
  
  enableIRQinterrupts();
  *(uint *)(unaff_r7 + 0x28) =
       *(int *)(unaff_r7 + 0x34) +
       ((((_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff))
        - *(int *)(unaff_r7 + 0x18)) - *(int *)(unaff_r7 + 0x14));
  *(undefined *)(*(int *)(unaff_r7 + 0x38) + 8) = 1;
  *(undefined *)(unaff_r7 + 0x60) = 0;
  iVar6 = FUN_0000617c(0x2000080c);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_000046dc:
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006f81), iVar6 != 0) {
      if (0x77 < *(byte *)(iVar6 + 0x1c)) {
        uVar13 = *(byte *)(iVar6 + 0x1d) & 0xfffffffe;
        *(uint *)(unaff_r7 + 0x50) = uVar13;
        *(char *)(iVar6 + 0x1d) = (char)uVar13;
        pbVar11 = *(byte **)(iVar6 + 0x14);
        *(byte **)(unaff_r7 + 0x3c) = pbVar11;
        *(int *)(unaff_r7 + 0x34) = iVar6;
        uVar13 = 1;
LAB_00004754:
        uVar21 = uVar13;
        uVar23 = *(int *)(unaff_r7 + 0x50) >> (uVar21 & 0xff);
        uVar13 = uVar23 & 1;
        if ((uVar23 & 1) != 0) {
          iVar6 = 1;
          do {
            bVar3 = pbVar11[iVar6];
            iVar20 = (int)(char)iVar6;
            if ((uint)bVar3 != (uint)*pbVar11) {
              if (iVar20 != 0x77) {
                uVar13 = 0x76;
                goto LAB_00004800;
              }
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 != 0x78);
LAB_000048d0:
          uVar13 = 0;
        }
        goto LAB_00004762;
      }
      iVar20 = 0;
      uVar13 = 0;
      do {
        uVar23 = uVar13 + 1;
        bVar26 = false;
        if (((int)(uint)*(byte *)(iVar6 + 0x1d) >> (uVar23 & 0xff) & 1U) != 0) {
          iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0xc));
          bVar26 = iVar7 != 0;
        }
        bVar3 = *(byte *)(iVar6 + 0x1c);
        *(bool *)(*(int *)(iVar6 + 0x14) + (uint)bVar3 + iVar20) = bVar26;
        iVar20 = iVar20 + 0x7c;
        uVar13 = uVar23;
      } while (uVar23 != 5);
      *(byte *)(iVar6 + 0x1c) = bVar3 + 1;
    }
  }
  iVar6 = FUN_0000617c(0x20000b20);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006e45), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 4) != 0) {
        disableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x20);
        *(byte *)(iVar6 + 0x20) = bVar3 & 0xfb;
        enableIRQinterrupts();
        FUN_00003fec(0x800c1b4,*(undefined *)(unaff_r7 + 0x60),bVar3 & 1,
                     *(undefined *)(iVar6 + 0x21));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001fc);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    do {
      puVar17 = *(uint **)(unaff_r7 + 0x40);
      do {
        iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x8003c55);
        if (((iVar6 == 0) || ((*(byte *)(iVar6 + 0x14) & 1) == 0)) || (*(int *)(iVar6 + 0x1c) < 1))
        goto LAB_00004bba;
        FUN_00008fe8(unaff_r7 + 0x60,0,0x10);
        uVar13 = 0;
        if (*(int *)(iVar6 + 0x18) != 0) {
          uVar23 = 0;
          do {
            iVar20 = FUN_00000f18(*(undefined *)(iVar6 + uVar23 + 0x30));
            uVar13 = uVar13 | iVar20 << (uVar23 & 0xff);
            uVar23 = uVar23 + 1;
          } while (uVar23 < *(uint *)(iVar6 + 0x18));
        }
        *(uint *)(unaff_r7 + 0x48) = (_DAT_40000424 ^ *puVar17) + (*puVar17 & 0xffff);
        *(undefined4 *)(unaff_r7 + 0x4c) = 0;
        iVar20 = iRam20000a84;
        uVar23 = uRam20000a80;
        *(uint *)(unaff_r7 + 0x50) = uRam20000a80;
        *(int *)(unaff_r7 + 0x54) = iVar20;
        if ((iVar20 != 0) || (*(uint *)(unaff_r7 + 0x48) < uVar23)) {
          iVar20 = *(int *)(unaff_r7 + 0x48);
          *(int *)(unaff_r7 + 0x48) = iVar20 + -1;
          *(uint *)(unaff_r7 + 0x4c) = *(int *)(unaff_r7 + 0x4c) + (uint)(iVar20 != 0);
        }
      } while (uVar13 != 0);
      if (*(int *)(iVar6 + 0x18) != 0) {
        uVar13 = 0;
        do {
          FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
          uVar23 = *(uint *)(iVar6 + 0x18);
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar23);
        iVar20 = 0x18;
        do {
          if (uVar23 == 0) goto LAB_00004b2c;
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 == 0) goto LAB_00004b2c;
          piVar18 = (int *)(unaff_r7 + 0x60);
          piVar25 = piVar18 + uVar23;
          do {
            *piVar18 = *piVar18 << 1;
            piVar18 = piVar18 + 1;
          } while (piVar25 != piVar18);
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            uVar13 = 0;
            piVar25 = (int *)(unaff_r7 + 0x60);
            do {
              iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0x30));
              uVar13 = uVar13 + 1;
              uVar23 = *(uint *)(iVar6 + 0x18);
              *piVar25 = (uint)(iVar7 != 0) + *piVar25;
              piVar25 = piVar25 + 1;
            } while (uVar13 < uVar23);
          }
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        uVar13 = 0;
        if (uVar23 != 0) {
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            puVar19 = (uint *)(unaff_r7 + 0x60);
            puVar17 = puVar19 + uVar23;
            do {
              uVar13 = *puVar19;
              if ((uVar13 & 0x800000) != 0) {
                uVar13 = uVar13 | 0xff000000;
              }
              *puVar19 = uVar13;
              puVar19 = puVar19 + 1;
            } while (puVar17 != puVar19);
            uVar13 = 0;
            do {
              FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
              uVar13 = uVar13 + 1;
            } while (uVar13 < *(uint *)(iVar6 + 0x18));
          }
        }
      }
LAB_00004b2c:
      uRam20000a80 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                     (**(uint **)(unaff_r7 + 0x40) & 0xffff);
      iRam20000a84 = 0;
      uVar12 = FUN_000063e4(*(uint *)(unaff_r7 + 0x48) - *(uint *)(unaff_r7 + 0x50),
                            (*(int *)(unaff_r7 + 0x4c) - *(int *)(unaff_r7 + 0x54)) -
                            (uint)(*(uint *)(unaff_r7 + 0x48) < *(uint *)(unaff_r7 + 0x50)));
      uVar12 = FUN_00006644(uVar12,0x447a0000);
      FUN_0000642c(uVar12,0x4c895440);
      uVar5 = FUN_000063a4();
      uVar1 = *(undefined *)(iVar6 + 0xc);
      *(undefined4 *)(unaff_r7 + 0x50) = *(undefined4 *)(unaff_r7 + 0x60);
      FUN_00003fec(0x800c0f4,uVar1,0,uVar5);
      iVar20 = *(int *)(iVar6 + 0x1c) + -1;
      *(int *)(iVar6 + 0x1c) = iVar20;
      if (iVar20 == 0) {
        *(byte *)(iVar6 + 0x14) = *(byte *)(iVar6 + 0x14) & 0xfe;
      }
    } while( true );
  }
LAB_00004bba:
  iVar6 = FUN_0000617c(0x200001f8);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while ((iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003bf5), iVar6 != 0 &&
           (*(int *)(iVar6 + 0x78) != 0))) {
      FUN_00003fec(0x800c0fc,*(undefined *)(iVar6 + 0xc),*(uint *)(iVar6 + 0x7c) & 0xffff,
                   *(undefined4 *)(iVar6 + 0x80));
      *(undefined4 *)(iVar6 + 0x78) = 0;
    }
  }
  iVar6 = FUN_0000617c(0x2000006c);
  if (iVar6 == 0) goto LAB_00004c56;
  puVar22 = (undefined *)0x26;
  *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_00004c28:
  iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
  if (iVar6 != 0) goto code_r0x00004c3e;
LAB_00004c56:
  iVar6 = FUN_0000617c(0x20000788);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    while (iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x1f) & 1) != 0) {
        disableIRQinterrupts();
        uVar12 = *(undefined4 *)(iVar6 + 8);
        *(byte *)(iVar6 + 0x1f) = *(byte *)(iVar6 + 0x1f) & 0xfe;
        enableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x1e);
        if (bVar3 == 2) {
          *(undefined4 *)(unaff_r7 + 0x60) = 1;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,3,unaff_r7 + 0x60);
          uVar13 = *(uint *)(unaff_r7 + 0x60);
          *(undefined2 *)(unaff_r7 + 0x60) = 7;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (((uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
          FUN_00002244(iVar6,uVar12,uVar13,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar13 & 1);
        }
        else if (bVar3 < 3) {
          if (bVar3 == 0) {
            *(undefined4 *)(unaff_r7 + 0x60) = 0;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                         (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18,uVar13 >> 0x18 & 7);
          }
          else {
            *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         (uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8 |
                         uVar13 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
          }
        }
        else if (bVar3 == 3) {
          *(undefined2 *)(unaff_r7 + 0x60) = 0;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
          FUN_00002244(iVar6,uVar12,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar13,uVar13 & 6);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000068);
  if (iVar6 != 0) {
    puVar22 = (undefined *)(unaff_r7 + 0x5f);
    *puVar22 = 0xff;
    while (iVar6 = FUN_000033d4(puVar22,0x80037c5), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x18) & 4) != 0) {
        if ((int)((uint)*(byte *)(iVar6 + 0x18) << 0x1f) < 0) {
          FUN_000061a0(iVar6);
          *(undefined *)(iVar6 + 0x18) = 2;
          *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x10),0,2,unaff_r7 + 0x60);
          disableIRQinterrupts();
          *(uint *)(iVar6 + 8) =
               (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
               (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar6 + 0xc);
          FUN_000061fc(iVar6);
          enableIRQinterrupts();
        }
        else {
          FUN_00002478(iVar6,*puVar22);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000794);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x11) & 8) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) & 0xf7;
        enableIRQinterrupts();
        FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar6 + 0x13) >> 3,
                     iVar6 + 0x20);
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f4);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 1) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x20) = *(byte *)(iVar6 + 0x20) & 0xfe;
        enableIRQinterrupts();
        FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar6 + 8),
                     *(undefined4 *)(iVar6 + 0x18));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f0);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar6 != 0) {
      if (*(char *)(iVar6 + 0x1c) == -1) {
        disableIRQinterrupts();
        if (*(char *)(iVar6 + 0x12) == '\0') {
          enableIRQinterrupts();
        }
        else {
          *(undefined *)(iVar6 + 0x1c) = *(undefined *)(iVar6 + 0x1d);
          enableIRQinterrupts();
          FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar6 + 0x1b));
        }
      }
    }
  }
  uRam40003000 = 0xaaaa;
  iVar20 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  disableIRQinterrupts();
  iVar6 = **(int **)(unaff_r7 + 4);
  *(int *)(unaff_r7 + 0x50) = iVar6;
  if (iVar6 - iVar20 < 0) {
    **(int **)(unaff_r7 + 4) = iVar20;
  }
  enableIRQinterrupts();
  uVar13 = (uint)**(byte **)(unaff_r7 + 0x2c);
  if (uVar13 != 0) {
    uVar23 = (uint)**(byte **)(unaff_r7 + 0x30);
    if (-1 < (int)(uVar23 << 0x1f)) {
      if (uVar13 < 5) goto LAB_00005012;
      pbVar11 = *(byte **)(unaff_r7 + 0x1c);
      uVar21 = (uint)*pbVar11;
      if ((uVar21 - 5 < 0x3c) && ((pbVar11[1] & 0xf0) == 0x10)) {
        if (uVar13 < uVar21) goto LAB_00005012;
        if (pbVar11[uVar21 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
          FUN_000059f2();
        }
      }
      if (uVar21 == 0x7e) {
                    /* WARNING: Subroutine does not return */
        FUN_00004fce();
      }
      uVar23 = uVar23 | 1;
      **(undefined **)(unaff_r7 + 0x30) = (char)uVar23;
    }
    iVar6 = FUN_00008e08(0x20000528,0x7e,uVar13);
    if (iVar6 == 0) {
      iVar6 = FUN_000059aa();
    }
    bVar3 = (byte)(uVar23 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar3;
    uVar13 = (iVar6 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar23 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar3 | 2;
    FUN_00003fec(0x800d4cc);
    lVar28 = (ulonglong)extraout_r1_00 << 0x20;
    bVar3 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar3 != uVar13) {
      lVar28 = FUN_00005980(0);
    }
    uVar23 = 0;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      uVar23 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar3 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar28,(int)((ulonglong)lVar28 >> 0x20),uVar23);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar3 - (char)uVar13;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      enableIRQinterrupts((uVar23 & 1) == 1);
    }
  }
LAB_00005012:
  iVar6 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  *(int *)(unaff_r7 + 0x34) = iVar6;
  uVar23 = _DAT_20000b0c;
  uVar13 = iVar6 - *(int *)(unaff_r7 + 0x28);
  iVar6 = _DAT_20000808 + 1;
  iVar20 = _DAT_20000b14 + uVar13;
  if (uVar13 < 0x10000) {
    uVar13 = uVar13 * uVar13 + 0xff >> 8;
LAB_0000506c:
    uVar13 = uVar13 + _DAT_20000b18;
    if (uVar13 < _DAT_20000b18) {
      uVar13 = 0xffffffff;
    }
  }
  else {
    if (uVar13 < 0x100000) {
      uVar13 = (uVar13 + 0xff >> 8) * uVar13;
      goto LAB_0000506c;
    }
    uVar13 = 0xffffffff;
  }
  puVar22 = &DAT_20000b18;
  _DAT_20000808 = iVar6;
  _DAT_20000b14 = iVar20;
  _DAT_20000b18 = uVar13;
  if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
    FUN_00004652();
    iVar6 = extraout_r1_01;
  }
  FUN_00003fec(0x800c16c,iVar6,iVar20);
  if (*(uint *)(unaff_r7 + 0x34) < uVar23) {
    _DAT_20000b10 = _DAT_20000b10 + 1;
  }
  _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
  _DAT_20000b18 = 0;
  _DAT_20000b14 = 0;
  _DAT_20000808 = 0;
  if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_00004660();
  }
  *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
  iVar6 = FUN_000046b4();
  cVar8 = extraout_r1;
  goto LAB_000050de;
LAB_00004800:
  if ((uint)pbVar11[uVar13] == (uint)pbVar11[0x77]) goto LAB_000047fa;
  uVar23 = uVar13 & 0xff;
  if ((char)uVar13 == '\x01') goto LAB_000048d0;
  bVar2 = pbVar11[iVar6];
  if ((uint)bVar2 == (uint)pbVar11[uVar13]) {
                    /* WARNING: Subroutine does not return */
    FUN_000050fc();
  }
  if ((int)uVar23 <= iVar6 + 3) goto LAB_000048d0;
  iVar6 = (uVar23 - iVar6) + 1;
  uVar13 = iVar6 >> 2 & 0xff;
  if ((int)uVar23 < iVar20) {
    uVar23 = 0;
    if (uVar13 != 0) goto LAB_000048d0;
    goto LAB_0000488e;
  }
  *(uint *)(unaff_r7 + 0x44) = uVar23;
  uVar24 = 0;
  uVar15 = 0;
  uVar23 = (uint)bVar3;
  uVar16 = (uint)bVar2;
  while( true ) {
    uVar9 = uVar23;
    uVar24 = uVar9 + uVar24 & 0xff;
    if (uVar9 != uVar16) {
      uVar15 = uVar15 + 1 & 0xff;
    }
    iVar20 = (int)(char)((char)iVar20 + '\x01');
    if (*(int *)(unaff_r7 + 0x44) < iVar20) break;
    uVar23 = (uint)pbVar11[iVar20];
    uVar16 = uVar9;
  }
  if (uVar24 < uVar13) goto LAB_000048d0;
  uVar13 = 0;
  if ((uVar24 <= (iVar6 * 3 >> 2 & 0xffU)) &&
     (uVar16 = (int)(uVar15 + 1) >> 1, uVar23 = uVar24 / uVar16, uVar16 <= uVar24)) {
LAB_0000488e:
    uVar27 = FUN_000089ac(uVar23 * 0x57e4);
    uVar27 = FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x40100000);
    uVar27 = FUN_00007480(0,0x41912a88,(int)uVar27,(int)((ulonglong)uVar27 >> 0x20));
    FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x404e0000);
    uVar13 = FUN_00006368();
  }
LAB_00004762:
  *(uint *)(pbVar11 + 0x78) = uVar13;
  pbVar11 = pbVar11 + 0x7c;
  uVar13 = uVar21 + 1;
  if (uVar21 + 1 == 6) goto code_r0x0000476c;
  goto LAB_00004754;
LAB_000047fa:
  uVar13 = uVar13 - 1;
  if (uVar13 == 0) goto LAB_00004762;
  goto LAB_00004800;
code_r0x0000476c:
  iVar6 = *(int *)(unaff_r7 + 0x34);
  FUN_00003fec(0x800c19c,*(undefined *)(unaff_r7 + 0x60),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x78),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0xf4));
  uVar13 = 1;
  uVar23 = (uint)*(byte *)(iVar6 + 0x1d);
  puVar10 = (undefined4 *)(*(int *)(iVar6 + 0x14) + 0x78);
  do {
    puVar14 = puVar10 + -0x1e;
    do {
      *(undefined *)puVar14 = 0;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    } while (puVar10 != puVar14);
    uVar16 = uVar13 & 0xff;
    uVar13 = uVar13 + 1;
    *puVar10 = 0;
    uVar23 = uVar23 & ~(uVar21 - 4 << uVar16);
    puVar10 = puVar10 + 0x1f;
  } while (uVar13 != 6);
  *(char *)(iVar6 + 0x1d) = (char)uVar23;
  *(undefined *)(iVar6 + 0x1c) = 0;
  goto LAB_000046dc;
code_r0x00004c3e:
  if (puVar22[iVar6] == *(char *)(iVar6 + 0x27)) {
    disableIRQinterrupts();
    cVar8 = *(char *)(iVar6 + 0x27);
    if (cVar8 == puVar22[iVar6]) {
LAB_000050de:
      uVar4 = *(undefined2 *)(iVar6 + 0x18);
      uVar12 = *(undefined4 *)(iVar6 + 0x14);
      puVar22[iVar6] = cVar8 + '\x01';
      enableIRQinterrupts();
      FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar12,uVar4);
    }
    else {
      enableIRQinterrupts();
    }
  }
  goto LAB_00004c28;
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000046b4(void)

{
  undefined uVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined uVar5;
  int iVar6;
  int iVar7;
  char extraout_r1;
  char cVar8;
  uint uVar9;
  uint extraout_r1_00;
  int extraout_r1_01;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int *piVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  undefined *puVar22;
  uint uVar23;
  uint uVar24;
  int *piVar25;
  int unaff_r7;
  bool bVar26;
  undefined8 uVar27;
  longlong lVar28;
  
  *(undefined *)(*(int *)(unaff_r7 + 0x38) + 8) = 1;
  *(undefined *)(unaff_r7 + 0x60) = 0;
  iVar6 = FUN_0000617c(0x2000080c);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_000046dc:
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006f81), iVar6 != 0) {
      if (0x77 < *(byte *)(iVar6 + 0x1c)) {
        uVar13 = *(byte *)(iVar6 + 0x1d) & 0xfffffffe;
        *(uint *)(unaff_r7 + 0x50) = uVar13;
        *(char *)(iVar6 + 0x1d) = (char)uVar13;
        pbVar11 = *(byte **)(iVar6 + 0x14);
        *(byte **)(unaff_r7 + 0x3c) = pbVar11;
        *(int *)(unaff_r7 + 0x34) = iVar6;
        uVar13 = 1;
LAB_00004754:
        uVar21 = uVar13;
        uVar23 = *(int *)(unaff_r7 + 0x50) >> (uVar21 & 0xff);
        uVar13 = uVar23 & 1;
        if ((uVar23 & 1) != 0) {
          iVar6 = 1;
          do {
            bVar3 = pbVar11[iVar6];
            iVar20 = (int)(char)iVar6;
            if ((uint)bVar3 != (uint)*pbVar11) {
              if (iVar20 != 0x77) {
                uVar13 = 0x76;
                goto LAB_00004800;
              }
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 != 0x78);
LAB_000048d0:
          uVar13 = 0;
        }
        goto LAB_00004762;
      }
      iVar20 = 0;
      uVar13 = 0;
      do {
        uVar23 = uVar13 + 1;
        bVar26 = false;
        if (((int)(uint)*(byte *)(iVar6 + 0x1d) >> (uVar23 & 0xff) & 1U) != 0) {
          iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0xc));
          bVar26 = iVar7 != 0;
        }
        bVar3 = *(byte *)(iVar6 + 0x1c);
        *(bool *)(*(int *)(iVar6 + 0x14) + (uint)bVar3 + iVar20) = bVar26;
        iVar20 = iVar20 + 0x7c;
        uVar13 = uVar23;
      } while (uVar23 != 5);
      *(byte *)(iVar6 + 0x1c) = bVar3 + 1;
    }
  }
  iVar6 = FUN_0000617c(0x20000b20);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8006e45), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 4) != 0) {
        disableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x20);
        *(byte *)(iVar6 + 0x20) = bVar3 & 0xfb;
        enableIRQinterrupts();
        FUN_00003fec(0x800c1b4,*(undefined *)(unaff_r7 + 0x60),bVar3 & 1,
                     *(undefined *)(iVar6 + 0x21));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001fc);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    do {
      puVar17 = *(uint **)(unaff_r7 + 0x40);
      do {
        iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x8003c55);
        if (((iVar6 == 0) || ((*(byte *)(iVar6 + 0x14) & 1) == 0)) || (*(int *)(iVar6 + 0x1c) < 1))
        goto LAB_00004bba;
        FUN_00008fe8(unaff_r7 + 0x60,0,0x10);
        uVar13 = 0;
        if (*(int *)(iVar6 + 0x18) != 0) {
          uVar23 = 0;
          do {
            iVar20 = FUN_00000f18(*(undefined *)(iVar6 + uVar23 + 0x30));
            uVar13 = uVar13 | iVar20 << (uVar23 & 0xff);
            uVar23 = uVar23 + 1;
          } while (uVar23 < *(uint *)(iVar6 + 0x18));
        }
        *(uint *)(unaff_r7 + 0x48) = (_DAT_40000424 ^ *puVar17) + (*puVar17 & 0xffff);
        *(undefined4 *)(unaff_r7 + 0x4c) = 0;
        iVar20 = iRam20000a84;
        uVar23 = uRam20000a80;
        *(uint *)(unaff_r7 + 0x50) = uRam20000a80;
        *(int *)(unaff_r7 + 0x54) = iVar20;
        if ((iVar20 != 0) || (*(uint *)(unaff_r7 + 0x48) < uVar23)) {
          iVar20 = *(int *)(unaff_r7 + 0x48);
          *(int *)(unaff_r7 + 0x48) = iVar20 + -1;
          *(uint *)(unaff_r7 + 0x4c) = *(int *)(unaff_r7 + 0x4c) + (uint)(iVar20 != 0);
        }
      } while (uVar13 != 0);
      if (*(int *)(iVar6 + 0x18) != 0) {
        uVar13 = 0;
        do {
          FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
          uVar23 = *(uint *)(iVar6 + 0x18);
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar23);
        iVar20 = 0x18;
        do {
          if (uVar23 == 0) goto LAB_00004b2c;
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 == 0) goto LAB_00004b2c;
          piVar18 = (int *)(unaff_r7 + 0x60);
          piVar25 = piVar18 + uVar23;
          do {
            *piVar18 = *piVar18 << 1;
            piVar18 = piVar18 + 1;
          } while (piVar25 != piVar18);
          uVar13 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            uVar13 = 0;
            piVar25 = (int *)(unaff_r7 + 0x60);
            do {
              iVar7 = FUN_00000f18(*(undefined *)(iVar6 + uVar13 + 0x30));
              uVar13 = uVar13 + 1;
              uVar23 = *(uint *)(iVar6 + 0x18);
              *piVar25 = (uint)(iVar7 != 0) + *piVar25;
              piVar25 = piVar25 + 1;
            } while (uVar13 < uVar23);
          }
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        uVar13 = 0;
        if (uVar23 != 0) {
          do {
            FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),1);
            uVar23 = *(uint *)(iVar6 + 0x18);
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar23);
          if (uVar23 != 0) {
            puVar19 = (uint *)(unaff_r7 + 0x60);
            puVar17 = puVar19 + uVar23;
            do {
              uVar13 = *puVar19;
              if ((uVar13 & 0x800000) != 0) {
                uVar13 = uVar13 | 0xff000000;
              }
              *puVar19 = uVar13;
              puVar19 = puVar19 + 1;
            } while (puVar17 != puVar19);
            uVar13 = 0;
            do {
              FUN_00001060(*(undefined4 *)((uVar13 + 8) * 4 + iVar6),0);
              uVar13 = uVar13 + 1;
            } while (uVar13 < *(uint *)(iVar6 + 0x18));
          }
        }
      }
LAB_00004b2c:
      uRam20000a80 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                     (**(uint **)(unaff_r7 + 0x40) & 0xffff);
      iRam20000a84 = 0;
      uVar12 = FUN_000063e4(*(uint *)(unaff_r7 + 0x48) - *(uint *)(unaff_r7 + 0x50),
                            (*(int *)(unaff_r7 + 0x4c) - *(int *)(unaff_r7 + 0x54)) -
                            (uint)(*(uint *)(unaff_r7 + 0x48) < *(uint *)(unaff_r7 + 0x50)));
      uVar12 = FUN_00006644(uVar12,0x447a0000);
      FUN_0000642c(uVar12,0x4c895440);
      uVar5 = FUN_000063a4();
      uVar1 = *(undefined *)(iVar6 + 0xc);
      *(undefined4 *)(unaff_r7 + 0x50) = *(undefined4 *)(unaff_r7 + 0x60);
      FUN_00003fec(0x800c0f4,uVar1,0,uVar5);
      iVar20 = *(int *)(iVar6 + 0x1c) + -1;
      *(int *)(iVar6 + 0x1c) = iVar20;
      if (iVar20 == 0) {
        *(byte *)(iVar6 + 0x14) = *(byte *)(iVar6 + 0x14) & 0xfe;
      }
    } while( true );
  }
LAB_00004bba:
  iVar6 = FUN_0000617c(0x200001f8);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while ((iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003bf5), iVar6 != 0 &&
           (*(int *)(iVar6 + 0x78) != 0))) {
      FUN_00003fec(0x800c0fc,*(undefined *)(iVar6 + 0xc),*(uint *)(iVar6 + 0x7c) & 0xffff,
                   *(undefined4 *)(iVar6 + 0x80));
      *(undefined4 *)(iVar6 + 0x78) = 0;
    }
  }
  iVar6 = FUN_0000617c(0x2000006c);
  if (iVar6 == 0) goto LAB_00004c56;
  puVar22 = (undefined *)0x26;
  *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_00004c28:
  iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
  if (iVar6 != 0) goto code_r0x00004c3e;
LAB_00004c56:
  iVar6 = FUN_0000617c(0x20000788);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    while (iVar6 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x1f) & 1) != 0) {
        disableIRQinterrupts();
        uVar12 = *(undefined4 *)(iVar6 + 8);
        *(byte *)(iVar6 + 0x1f) = *(byte *)(iVar6 + 0x1f) & 0xfe;
        enableIRQinterrupts();
        bVar3 = *(byte *)(iVar6 + 0x1e);
        if (bVar3 == 2) {
          *(undefined4 *)(unaff_r7 + 0x60) = 1;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,3,unaff_r7 + 0x60);
          uVar13 = *(uint *)(unaff_r7 + 0x60);
          *(undefined2 *)(unaff_r7 + 0x60) = 7;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (((uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
          FUN_00002244(iVar6,uVar12,uVar13,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar13 & 1);
        }
        else if (bVar3 < 3) {
          if (bVar3 == 0) {
            *(undefined4 *)(unaff_r7 + 0x60) = 0;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                         (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18,uVar13 >> 0x18 & 7);
          }
          else {
            *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,4,unaff_r7 + 0x60);
            uVar13 = *(uint *)(unaff_r7 + 0x60);
            *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
            FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
            FUN_00002244(iVar6,uVar12,
                         (uVar13 >> 8 & 0xff) << 0x10 | (uVar13 >> 0x10 & 0xff) << 8 |
                         uVar13 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
          }
        }
        else if (bVar3 == 3) {
          *(undefined2 *)(unaff_r7 + 0x60) = 0;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x18),1,2,unaff_r7 + 0x60);
          uVar13 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
          FUN_00002244(iVar6,uVar12,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar13,uVar13 & 6);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000068);
  if (iVar6 != 0) {
    puVar22 = (undefined *)(unaff_r7 + 0x5f);
    *puVar22 = 0xff;
    while (iVar6 = FUN_000033d4(puVar22,0x80037c5), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x18) & 4) != 0) {
        if ((int)((uint)*(byte *)(iVar6 + 0x18) << 0x1f) < 0) {
          FUN_000061a0(iVar6);
          *(undefined *)(iVar6 + 0x18) = 2;
          *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
          FUN_000022b0(*(undefined4 *)(iVar6 + 0x10),0,2,unaff_r7 + 0x60);
          disableIRQinterrupts();
          *(uint *)(iVar6 + 8) =
               (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
               (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar6 + 0xc);
          FUN_000061fc(iVar6);
          enableIRQinterrupts();
        }
        else {
          FUN_00002478(iVar6,*puVar22);
        }
      }
    }
  }
  iVar6 = FUN_0000617c(0x20000794);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x11) & 8) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) & 0xf7;
        enableIRQinterrupts();
        FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar6 + 0x13) >> 3,
                     iVar6 + 0x20);
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f4);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar6 != 0) {
      if ((*(byte *)(iVar6 + 0x20) & 1) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar6 + 0x20) = *(byte *)(iVar6 + 0x20) & 0xfe;
        enableIRQinterrupts();
        FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar6 + 8),
                     *(undefined4 *)(iVar6 + 0x18));
      }
    }
  }
  iVar6 = FUN_0000617c(0x200001f0);
  if (iVar6 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar6 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar6 != 0) {
      if (*(char *)(iVar6 + 0x1c) == -1) {
        disableIRQinterrupts();
        if (*(char *)(iVar6 + 0x12) == '\0') {
          enableIRQinterrupts();
        }
        else {
          *(undefined *)(iVar6 + 0x1c) = *(undefined *)(iVar6 + 0x1d);
          enableIRQinterrupts();
          FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar6 + 0x1b));
        }
      }
    }
  }
  uRam40003000 = 0xaaaa;
  iVar20 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  disableIRQinterrupts();
  iVar6 = **(int **)(unaff_r7 + 4);
  *(int *)(unaff_r7 + 0x50) = iVar6;
  if (iVar6 - iVar20 < 0) {
    **(int **)(unaff_r7 + 4) = iVar20;
  }
  enableIRQinterrupts();
  uVar13 = (uint)**(byte **)(unaff_r7 + 0x2c);
  if (uVar13 != 0) {
    uVar23 = (uint)**(byte **)(unaff_r7 + 0x30);
    if (-1 < (int)(uVar23 << 0x1f)) {
      if (uVar13 < 5) goto LAB_00005012;
      pbVar11 = *(byte **)(unaff_r7 + 0x1c);
      uVar21 = (uint)*pbVar11;
      if ((uVar21 - 5 < 0x3c) && ((pbVar11[1] & 0xf0) == 0x10)) {
        if (uVar13 < uVar21) goto LAB_00005012;
        if (pbVar11[uVar21 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
          FUN_000059f2();
        }
      }
      if (uVar21 == 0x7e) {
                    /* WARNING: Subroutine does not return */
        FUN_00004fce();
      }
      uVar23 = uVar23 | 1;
      **(undefined **)(unaff_r7 + 0x30) = (char)uVar23;
    }
    iVar6 = FUN_00008e08(0x20000528,0x7e,uVar13);
    if (iVar6 == 0) {
      iVar6 = FUN_000059aa();
    }
    bVar3 = (byte)(uVar23 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar3;
    uVar13 = (iVar6 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar23 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar3 | 2;
    FUN_00003fec(0x800d4cc);
    lVar28 = (ulonglong)extraout_r1_00 << 0x20;
    bVar3 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar3 != uVar13) {
      lVar28 = FUN_00005980(0);
    }
    uVar23 = 0;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      uVar23 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar3 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar28,(int)((ulonglong)lVar28 >> 0x20),uVar23);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar3 - (char)uVar13;
    bVar26 = (bool)isCurrentModePrivileged();
    if (bVar26) {
      enableIRQinterrupts((uVar23 & 1) == 1);
    }
  }
LAB_00005012:
  iVar6 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  *(int *)(unaff_r7 + 0x34) = iVar6;
  uVar23 = _DAT_20000b0c;
  uVar13 = iVar6 - *(int *)(unaff_r7 + 0x28);
  iVar6 = _DAT_20000808 + 1;
  iVar20 = _DAT_20000b14 + uVar13;
  if (uVar13 < 0x10000) {
    uVar13 = uVar13 * uVar13 + 0xff >> 8;
LAB_0000506c:
    uVar13 = uVar13 + _DAT_20000b18;
    if (uVar13 < _DAT_20000b18) {
      uVar13 = 0xffffffff;
    }
  }
  else {
    if (uVar13 < 0x100000) {
      uVar13 = (uVar13 + 0xff >> 8) * uVar13;
      goto LAB_0000506c;
    }
    uVar13 = 0xffffffff;
  }
  puVar22 = &DAT_20000b18;
  _DAT_20000808 = iVar6;
  _DAT_20000b14 = iVar20;
  _DAT_20000b18 = uVar13;
  if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
    FUN_00004652();
    iVar6 = extraout_r1_01;
  }
  FUN_00003fec(0x800c16c,iVar6,iVar20);
  if (*(uint *)(unaff_r7 + 0x34) < uVar23) {
    _DAT_20000b10 = _DAT_20000b10 + 1;
  }
  _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
  _DAT_20000b18 = 0;
  _DAT_20000b14 = 0;
  _DAT_20000808 = 0;
  if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_00004660();
  }
  *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
  iVar6 = FUN_000046b4();
  cVar8 = extraout_r1;
  goto LAB_000050de;
LAB_00004800:
  if ((uint)pbVar11[uVar13] == (uint)pbVar11[0x77]) goto LAB_000047fa;
  uVar23 = uVar13 & 0xff;
  if ((char)uVar13 == '\x01') goto LAB_000048d0;
  bVar2 = pbVar11[iVar6];
  if ((uint)bVar2 == (uint)pbVar11[uVar13]) {
                    /* WARNING: Subroutine does not return */
    FUN_000050fc();
  }
  if ((int)uVar23 <= iVar6 + 3) goto LAB_000048d0;
  iVar6 = (uVar23 - iVar6) + 1;
  uVar13 = iVar6 >> 2 & 0xff;
  if ((int)uVar23 < iVar20) {
    uVar23 = 0;
    if (uVar13 != 0) goto LAB_000048d0;
    goto LAB_0000488e;
  }
  *(uint *)(unaff_r7 + 0x44) = uVar23;
  uVar24 = 0;
  uVar15 = 0;
  uVar23 = (uint)bVar3;
  uVar16 = (uint)bVar2;
  while( true ) {
    uVar9 = uVar23;
    uVar24 = uVar9 + uVar24 & 0xff;
    if (uVar9 != uVar16) {
      uVar15 = uVar15 + 1 & 0xff;
    }
    iVar20 = (int)(char)((char)iVar20 + '\x01');
    if (*(int *)(unaff_r7 + 0x44) < iVar20) break;
    uVar23 = (uint)pbVar11[iVar20];
    uVar16 = uVar9;
  }
  if (uVar24 < uVar13) goto LAB_000048d0;
  uVar13 = 0;
  if ((uVar24 <= (iVar6 * 3 >> 2 & 0xffU)) &&
     (uVar16 = (int)(uVar15 + 1) >> 1, uVar23 = uVar24 / uVar16, uVar16 <= uVar24)) {
LAB_0000488e:
    uVar27 = FUN_000089ac(uVar23 * 0x57e4);
    uVar27 = FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x40100000);
    uVar27 = FUN_00007480(0,0x41912a88,(int)uVar27,(int)((ulonglong)uVar27 >> 0x20));
    FUN_00007cfc((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0,0x404e0000);
    uVar13 = FUN_00006368();
  }
LAB_00004762:
  *(uint *)(pbVar11 + 0x78) = uVar13;
  pbVar11 = pbVar11 + 0x7c;
  uVar13 = uVar21 + 1;
  if (uVar21 + 1 == 6) goto code_r0x0000476c;
  goto LAB_00004754;
LAB_000047fa:
  uVar13 = uVar13 - 1;
  if (uVar13 == 0) goto LAB_00004762;
  goto LAB_00004800;
code_r0x0000476c:
  iVar6 = *(int *)(unaff_r7 + 0x34);
  FUN_00003fec(0x800c19c,*(undefined *)(unaff_r7 + 0x60),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x78),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0xf4));
  uVar13 = 1;
  uVar23 = (uint)*(byte *)(iVar6 + 0x1d);
  puVar10 = (undefined4 *)(*(int *)(iVar6 + 0x14) + 0x78);
  do {
    puVar14 = puVar10 + -0x1e;
    do {
      *(undefined *)puVar14 = 0;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    } while (puVar10 != puVar14);
    uVar16 = uVar13 & 0xff;
    uVar13 = uVar13 + 1;
    *puVar10 = 0;
    uVar23 = uVar23 & ~(uVar21 - 4 << uVar16);
    puVar10 = puVar10 + 0x1f;
  } while (uVar13 != 6);
  *(char *)(iVar6 + 0x1d) = (char)uVar23;
  *(undefined *)(iVar6 + 0x1c) = 0;
  goto LAB_000046dc;
code_r0x00004c3e:
  if (puVar22[iVar6] == *(char *)(iVar6 + 0x27)) {
    disableIRQinterrupts();
    cVar8 = *(char *)(iVar6 + 0x27);
    if (cVar8 == puVar22[iVar6]) {
LAB_000050de:
      uVar4 = *(undefined2 *)(iVar6 + 0x18);
      uVar12 = *(undefined4 *)(iVar6 + 0x14);
      puVar22[iVar6] = cVar8 + '\x01';
      enableIRQinterrupts();
      FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar12,uVar4);
    }
    else {
      enableIRQinterrupts();
    }
  }
  goto LAB_00004c28;
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004820(int param_1,uint param_2,uint param_3,int param_4)

{
  undefined uVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined uVar4;
  int iVar5;
  char extraout_r1;
  char cVar6;
  uint extraout_r1_00;
  int extraout_r1_01;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  int *piVar16;
  uint *puVar17;
  int iVar18;
  byte *unaff_r4;
  undefined *puVar19;
  uint uVar20;
  uint uVar21;
  uint unaff_r6;
  int *piVar22;
  int unaff_r7;
  uint unaff_r8;
  uint unaff_r9;
  bool bVar23;
  undefined8 uVar24;
  longlong lVar25;
  
code_r0x00004820:
  if ((int)param_3 <= param_4 + 3) goto LAB_000048d0;
  iVar12 = (param_3 - param_4) + 1;
  uVar20 = iVar12 >> 2 & 0xff;
  uVar10 = unaff_r6;
  if ((int)param_3 < param_1) {
    uVar13 = 0;
    if (uVar20 != 0) goto LAB_000048d0;
LAB_0000488e:
    uVar24 = FUN_000089ac(uVar13 * 0x57e4);
    uVar24 = FUN_00007cfc((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),0,0x40100000);
    uVar24 = FUN_00007480(0,0x41912a88,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
    FUN_00007cfc((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),0,0x404e0000);
    uVar20 = FUN_00006368();
  }
  else {
    *(uint *)(unaff_r7 + 0x44) = param_3;
    uVar21 = 0;
    uVar13 = 0;
    while( true ) {
      uVar14 = param_2;
      uVar21 = uVar14 + uVar21 & 0xff;
      if (uVar14 != unaff_r9) {
        uVar13 = uVar13 + 1 & 0xff;
      }
      param_1 = (int)(char)((char)param_1 + '\x01');
      if (*(int *)(unaff_r7 + 0x44) < param_1) break;
      param_2 = (uint)unaff_r4[param_1];
      unaff_r9 = uVar14;
    }
    if (uVar21 < uVar20) goto LAB_000048d0;
    uVar20 = 0;
    if ((uVar21 <= (iVar12 * 3 >> 2 & 0xffU)) &&
       (uVar14 = (int)(uVar13 + 1) >> 1, uVar13 = uVar21 / uVar14, uVar14 <= uVar21))
    goto LAB_0000488e;
  }
LAB_00004762:
  unaff_r6 = uVar10 + 1;
  *(uint *)(unaff_r4 + 0x78) = uVar20;
  unaff_r4 = unaff_r4 + 0x7c;
  if (unaff_r6 != 6) goto LAB_00004754;
  iVar12 = *(int *)(unaff_r7 + 0x34);
  FUN_00003fec(0x800c19c,*(undefined *)(unaff_r7 + 0x60),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x78),
               *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0xf4));
  uVar20 = 1;
  uVar13 = (uint)*(byte *)(iVar12 + 0x1d);
  puVar7 = (undefined4 *)(*(int *)(iVar12 + 0x14) + 0x78);
  do {
    puVar11 = puVar7 + -0x1e;
    do {
      *(undefined *)puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    } while (puVar7 != puVar11);
    uVar21 = uVar20 & 0xff;
    uVar20 = uVar20 + 1;
    *puVar7 = 0;
    uVar13 = uVar13 & ~(uVar10 - 4 << uVar21);
    puVar7 = puVar7 + 0x1f;
  } while (uVar20 != 6);
  *(char *)(iVar12 + 0x1d) = (char)uVar13;
  *(undefined *)(iVar12 + 0x1c) = 0;
  while (iVar12 = FUN_000033d4(unaff_r7 + 0x60,0x8006f81), iVar12 != 0) {
    if (0x77 < *(byte *)(iVar12 + 0x1c)) goto LAB_0000473c;
    iVar18 = 0;
    uVar10 = 0;
    do {
      uVar20 = uVar10 + 1;
      bVar23 = false;
      if (((int)(uint)*(byte *)(iVar12 + 0x1d) >> (uVar20 & 0xff) & 1U) != 0) {
        iVar5 = FUN_00000f18(*(undefined *)(iVar12 + uVar10 + 0xc));
        bVar23 = iVar5 != 0;
      }
      bVar2 = *(byte *)(iVar12 + 0x1c);
      *(bool *)(*(int *)(iVar12 + 0x14) + (uint)bVar2 + iVar18) = bVar23;
      iVar18 = iVar18 + 0x7c;
      uVar10 = uVar20;
    } while (uVar20 != 5);
    *(byte *)(iVar12 + 0x1c) = bVar2 + 1;
  }
  iVar12 = FUN_0000617c(0x20000b20);
  if (iVar12 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar12 = FUN_000033d4(unaff_r7 + 0x60,0x8006e45), iVar12 != 0) {
      if ((*(byte *)(iVar12 + 0x20) & 4) != 0) {
        disableIRQinterrupts();
        bVar2 = *(byte *)(iVar12 + 0x20);
        *(byte *)(iVar12 + 0x20) = bVar2 & 0xfb;
        enableIRQinterrupts();
        FUN_00003fec(0x800c1b4,*(undefined *)(unaff_r7 + 0x60),bVar2 & 1,
                     *(undefined *)(iVar12 + 0x21));
      }
    }
  }
  iVar12 = FUN_0000617c(0x200001fc);
  if (iVar12 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    do {
      puVar15 = *(uint **)(unaff_r7 + 0x40);
      do {
        iVar12 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x8003c55);
        if (((iVar12 == 0) || ((*(byte *)(iVar12 + 0x14) & 1) == 0)) ||
           (*(int *)(iVar12 + 0x1c) < 1)) goto LAB_00004bba;
        FUN_00008fe8(unaff_r7 + 0x60,0,0x10);
        uVar10 = 0;
        if (*(int *)(iVar12 + 0x18) != 0) {
          uVar20 = 0;
          do {
            iVar18 = FUN_00000f18(*(undefined *)(iVar12 + uVar20 + 0x30));
            uVar10 = uVar10 | iVar18 << (uVar20 & 0xff);
            uVar20 = uVar20 + 1;
          } while (uVar20 < *(uint *)(iVar12 + 0x18));
        }
        *(uint *)(unaff_r7 + 0x48) = (_DAT_40000424 ^ *puVar15) + (*puVar15 & 0xffff);
        *(undefined4 *)(unaff_r7 + 0x4c) = 0;
        iVar18 = iRam20000a84;
        uVar20 = uRam20000a80;
        *(uint *)(unaff_r7 + 0x50) = uRam20000a80;
        *(int *)(unaff_r7 + 0x54) = iVar18;
        if ((iVar18 != 0) || (*(uint *)(unaff_r7 + 0x48) < uVar20)) {
          iVar18 = *(int *)(unaff_r7 + 0x48);
          *(int *)(unaff_r7 + 0x48) = iVar18 + -1;
          *(uint *)(unaff_r7 + 0x4c) = *(int *)(unaff_r7 + 0x4c) + (uint)(iVar18 != 0);
        }
      } while (uVar10 != 0);
      if (*(int *)(iVar12 + 0x18) != 0) {
        uVar10 = 0;
        do {
          FUN_00001060(*(undefined4 *)((uVar10 + 8) * 4 + iVar12),0);
          uVar20 = *(uint *)(iVar12 + 0x18);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar20);
        iVar18 = 0x18;
        do {
          if (uVar20 == 0) goto LAB_00004b2c;
          uVar10 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar10 + 8) * 4 + iVar12),1);
            uVar20 = *(uint *)(iVar12 + 0x18);
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar20);
          if (uVar20 == 0) goto LAB_00004b2c;
          piVar16 = (int *)(unaff_r7 + 0x60);
          piVar22 = piVar16 + uVar20;
          do {
            *piVar16 = *piVar16 << 1;
            piVar16 = piVar16 + 1;
          } while (piVar22 != piVar16);
          uVar10 = 0;
          do {
            FUN_00001060(*(undefined4 *)((uVar10 + 8) * 4 + iVar12),0);
            uVar20 = *(uint *)(iVar12 + 0x18);
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar20);
          if (uVar20 != 0) {
            uVar10 = 0;
            piVar22 = (int *)(unaff_r7 + 0x60);
            do {
              iVar5 = FUN_00000f18(*(undefined *)(iVar12 + uVar10 + 0x30));
              uVar10 = uVar10 + 1;
              uVar20 = *(uint *)(iVar12 + 0x18);
              *piVar22 = (uint)(iVar5 != 0) + *piVar22;
              piVar22 = piVar22 + 1;
            } while (uVar10 < uVar20);
          }
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
        uVar10 = 0;
        if (uVar20 != 0) {
          do {
            FUN_00001060(*(undefined4 *)((uVar10 + 8) * 4 + iVar12),1);
            uVar20 = *(uint *)(iVar12 + 0x18);
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar20);
          if (uVar20 != 0) {
            puVar17 = (uint *)(unaff_r7 + 0x60);
            puVar15 = puVar17 + uVar20;
            do {
              uVar10 = *puVar17;
              if ((uVar10 & 0x800000) != 0) {
                uVar10 = uVar10 | 0xff000000;
              }
              *puVar17 = uVar10;
              puVar17 = puVar17 + 1;
            } while (puVar15 != puVar17);
            uVar10 = 0;
            do {
              FUN_00001060(*(undefined4 *)((uVar10 + 8) * 4 + iVar12),0);
              uVar10 = uVar10 + 1;
            } while (uVar10 < *(uint *)(iVar12 + 0x18));
          }
        }
      }
LAB_00004b2c:
      uRam20000a80 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                     (**(uint **)(unaff_r7 + 0x40) & 0xffff);
      iRam20000a84 = 0;
      uVar9 = FUN_000063e4(*(uint *)(unaff_r7 + 0x48) - *(uint *)(unaff_r7 + 0x50),
                           (*(int *)(unaff_r7 + 0x4c) - *(int *)(unaff_r7 + 0x54)) -
                           (uint)(*(uint *)(unaff_r7 + 0x48) < *(uint *)(unaff_r7 + 0x50)));
      uVar9 = FUN_00006644(uVar9,0x447a0000);
      FUN_0000642c(uVar9,0x4c895440);
      uVar4 = FUN_000063a4();
      uVar1 = *(undefined *)(iVar12 + 0xc);
      *(undefined4 *)(unaff_r7 + 0x50) = *(undefined4 *)(unaff_r7 + 0x60);
      FUN_00003fec(0x800c0f4,uVar1,0,uVar4);
      iVar18 = *(int *)(iVar12 + 0x1c) + -1;
      *(int *)(iVar12 + 0x1c) = iVar18;
      if (iVar18 == 0) {
        *(byte *)(iVar12 + 0x14) = *(byte *)(iVar12 + 0x14) & 0xfe;
      }
    } while( true );
  }
LAB_00004bba:
  iVar12 = FUN_0000617c(0x200001f8);
  if (iVar12 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while ((iVar12 = FUN_000033d4(unaff_r7 + 0x60,0x8003bf5), iVar12 != 0 &&
           (*(int *)(iVar12 + 0x78) != 0))) {
      FUN_00003fec(0x800c0fc,*(undefined *)(iVar12 + 0xc),*(uint *)(iVar12 + 0x7c) & 0xffff,
                   *(undefined4 *)(iVar12 + 0x80));
      *(undefined4 *)(iVar12 + 0x78) = 0;
    }
  }
  iVar12 = FUN_0000617c(0x2000006c);
  if (iVar12 == 0) goto LAB_00004c56;
  puVar19 = (undefined *)0x26;
  *(undefined *)(unaff_r7 + 0x60) = 0xff;
LAB_00004c28:
  iVar12 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
  if (iVar12 != 0) goto code_r0x00004c3e;
LAB_00004c56:
  iVar12 = FUN_0000617c(0x20000788);
  if (iVar12 != 0) {
    *(undefined *)(unaff_r7 + 0x5f) = 0xff;
    while (iVar12 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar12 != 0) {
      if ((*(byte *)(iVar12 + 0x1f) & 1) != 0) {
        disableIRQinterrupts();
        uVar9 = *(undefined4 *)(iVar12 + 8);
        *(byte *)(iVar12 + 0x1f) = *(byte *)(iVar12 + 0x1f) & 0xfe;
        enableIRQinterrupts();
        bVar2 = *(byte *)(iVar12 + 0x1e);
        if (bVar2 == 2) {
          *(undefined4 *)(unaff_r7 + 0x60) = 1;
          FUN_000022b0(*(undefined4 *)(iVar12 + 0x18),1,3,unaff_r7 + 0x60);
          uVar10 = *(uint *)(unaff_r7 + 0x60);
          *(undefined2 *)(unaff_r7 + 0x60) = 7;
          FUN_000022b0(*(undefined4 *)(iVar12 + 0x18),1,2,unaff_r7 + 0x60);
          uVar10 = (((uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
          FUN_00002244(iVar12,uVar9,uVar10,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar10 & 1);
        }
        else if (bVar2 < 3) {
          if (bVar2 == 0) {
            *(undefined4 *)(unaff_r7 + 0x60) = 0;
            FUN_000022b0(*(undefined4 *)(iVar12 + 0x18),1,4,unaff_r7 + 0x60);
            uVar10 = *(uint *)(unaff_r7 + 0x60);
            FUN_00002244(iVar12,uVar9,
                         uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 |
                         (uVar10 >> 0x10 & 0xff) << 8 | uVar10 >> 0x18,uVar10 >> 0x18 & 7);
          }
          else {
            *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
            FUN_000022b0(*(undefined4 *)(iVar12 + 0x18),1,4,unaff_r7 + 0x60);
            uVar10 = *(uint *)(unaff_r7 + 0x60);
            *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
            FUN_000022b0(*(undefined4 *)(iVar12 + 0x18),1,2,unaff_r7 + 0x60);
            FUN_00002244(iVar12,uVar9,
                         (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                         uVar10 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
          }
        }
        else if (bVar2 == 3) {
          *(undefined2 *)(unaff_r7 + 0x60) = 0;
          FUN_000022b0(*(undefined4 *)(iVar12 + 0x18),1,2,unaff_r7 + 0x60);
          uVar10 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
          FUN_00002244(iVar12,uVar9,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar10,uVar10 & 6);
        }
      }
    }
  }
  iVar12 = FUN_0000617c(0x20000068);
  if (iVar12 != 0) {
    puVar19 = (undefined *)(unaff_r7 + 0x5f);
    *puVar19 = 0xff;
    while (iVar12 = FUN_000033d4(puVar19,0x80037c5), iVar12 != 0) {
      if ((*(byte *)(iVar12 + 0x18) & 4) != 0) {
        if ((int)((uint)*(byte *)(iVar12 + 0x18) << 0x1f) < 0) {
          FUN_000061a0(iVar12);
          *(undefined *)(iVar12 + 0x18) = 2;
          *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
          FUN_000022b0(*(undefined4 *)(iVar12 + 0x10),0,2,unaff_r7 + 0x60);
          disableIRQinterrupts();
          *(uint *)(iVar12 + 8) =
               (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
               (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar12 + 0xc);
          FUN_000061fc(iVar12);
          enableIRQinterrupts();
        }
        else {
          FUN_00002478(iVar12,*puVar19);
        }
      }
    }
  }
  iVar12 = FUN_0000617c(0x20000794);
  if (iVar12 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar12 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar12 != 0) {
      if ((*(byte *)(iVar12 + 0x11) & 8) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar12 + 0x11) = *(byte *)(iVar12 + 0x11) & 0xf7;
        enableIRQinterrupts();
        FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar12 + 0x13) >> 3,
                     iVar12 + 0x20);
      }
    }
  }
  iVar12 = FUN_0000617c(0x200001f4);
  if (iVar12 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar12 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar12 != 0) {
      if ((*(byte *)(iVar12 + 0x20) & 1) != 0) {
        disableIRQinterrupts();
        *(byte *)(iVar12 + 0x20) = *(byte *)(iVar12 + 0x20) & 0xfe;
        enableIRQinterrupts();
        FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar12 + 8),
                     *(undefined4 *)(iVar12 + 0x18));
      }
    }
  }
  iVar12 = FUN_0000617c(0x200001f0);
  if (iVar12 != 0) {
    *(undefined *)(unaff_r7 + 0x60) = 0xff;
    while (iVar12 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar12 != 0) {
      if (*(char *)(iVar12 + 0x1c) == -1) {
        disableIRQinterrupts();
        if (*(char *)(iVar12 + 0x12) == '\0') {
          enableIRQinterrupts();
        }
        else {
          *(undefined *)(iVar12 + 0x1c) = *(undefined *)(iVar12 + 0x1d);
          enableIRQinterrupts();
          FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar12 + 0x1b));
        }
      }
    }
  }
  uRam40003000 = 0xaaaa;
  iVar18 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  disableIRQinterrupts();
  iVar12 = **(int **)(unaff_r7 + 4);
  *(int *)(unaff_r7 + 0x50) = iVar12;
  if (iVar12 - iVar18 < 0) {
    **(int **)(unaff_r7 + 4) = iVar18;
  }
  enableIRQinterrupts();
  uVar10 = (uint)**(byte **)(unaff_r7 + 0x2c);
  if (uVar10 != 0) {
    uVar20 = (uint)**(byte **)(unaff_r7 + 0x30);
    if (-1 < (int)(uVar20 << 0x1f)) {
      if (uVar10 < 5) goto LAB_00005012;
      pbVar8 = *(byte **)(unaff_r7 + 0x1c);
      uVar13 = (uint)*pbVar8;
      if ((uVar13 - 5 < 0x3c) && ((pbVar8[1] & 0xf0) == 0x10)) {
        if (uVar10 < uVar13) goto LAB_00005012;
        if (pbVar8[uVar13 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
          FUN_000059f2();
        }
      }
      if (uVar13 == 0x7e) {
                    /* WARNING: Subroutine does not return */
        FUN_00004fce();
      }
      uVar20 = uVar20 | 1;
      **(undefined **)(unaff_r7 + 0x30) = (char)uVar20;
    }
    iVar12 = FUN_00008e08(0x20000528,0x7e,uVar10);
    if (iVar12 == 0) {
      iVar12 = FUN_000059aa();
    }
    bVar2 = (byte)(uVar20 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar2;
    uVar10 = (iVar12 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar20 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar2 | 2;
    FUN_00003fec(0x800d4cc);
    lVar25 = (ulonglong)extraout_r1_00 << 0x20;
    bVar2 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar2 != uVar10) {
      lVar25 = FUN_00005980(0);
    }
    uVar20 = 0;
    bVar23 = (bool)isCurrentModePrivileged();
    if (bVar23) {
      uVar20 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar2 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar25,(int)((ulonglong)lVar25 >> 0x20),uVar20);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar2 - (char)uVar10;
    bVar23 = (bool)isCurrentModePrivileged();
    if (bVar23) {
      enableIRQinterrupts((uVar20 & 1) == 1);
    }
  }
LAB_00005012:
  iVar12 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff);
  *(int *)(unaff_r7 + 0x34) = iVar12;
  uVar20 = _DAT_20000b0c;
  uVar10 = iVar12 - *(int *)(unaff_r7 + 0x28);
  iVar12 = _DAT_20000808 + 1;
  iVar18 = _DAT_20000b14 + uVar10;
  if (uVar10 < 0x10000) {
    uVar10 = uVar10 * uVar10 + 0xff >> 8;
LAB_0000506c:
    uVar10 = uVar10 + _DAT_20000b18;
    if (uVar10 < _DAT_20000b18) {
      uVar10 = 0xffffffff;
    }
  }
  else {
    if (uVar10 < 0x100000) {
      uVar10 = (uVar10 + 0xff >> 8) * uVar10;
      goto LAB_0000506c;
    }
    uVar10 = 0xffffffff;
  }
  puVar19 = &DAT_20000b18;
  _DAT_20000808 = iVar12;
  _DAT_20000b14 = iVar18;
  _DAT_20000b18 = uVar10;
  if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
    FUN_00004652();
    iVar12 = extraout_r1_01;
  }
  FUN_00003fec(0x800c16c,iVar12,iVar18);
  if (*(uint *)(unaff_r7 + 0x34) < uVar20) {
    _DAT_20000b10 = _DAT_20000b10 + 1;
  }
  _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
  _DAT_20000b18 = 0;
  _DAT_20000b14 = 0;
  _DAT_20000808 = 0;
  if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_00004660();
  }
  *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
  iVar12 = FUN_000046b4();
  cVar6 = extraout_r1;
  goto LAB_000050de;
code_r0x00004c3e:
  if (puVar19[iVar12] == *(char *)(iVar12 + 0x27)) {
    disableIRQinterrupts();
    cVar6 = *(char *)(iVar12 + 0x27);
    if (cVar6 == puVar19[iVar12]) {
LAB_000050de:
      uVar3 = *(undefined2 *)(iVar12 + 0x18);
      uVar9 = *(undefined4 *)(iVar12 + 0x14);
      puVar19[iVar12] = cVar6 + '\x01';
      enableIRQinterrupts();
      FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar9,uVar3);
    }
    else {
      enableIRQinterrupts();
    }
  }
  goto LAB_00004c28;
LAB_0000473c:
  unaff_r6 = 1;
  uVar10 = *(byte *)(iVar12 + 0x1d) & 0xfffffffe;
  *(uint *)(unaff_r7 + 0x50) = uVar10;
  *(char *)(iVar12 + 0x1d) = (char)uVar10;
  unaff_r4 = *(byte **)(iVar12 + 0x14);
  unaff_r8 = 1;
  *(byte **)(unaff_r7 + 0x3c) = unaff_r4;
  *(int *)(unaff_r7 + 0x34) = iVar12;
LAB_00004754:
  uVar13 = *(int *)(unaff_r7 + 0x50) >> (unaff_r6 & 0xff);
  uVar20 = unaff_r8 & uVar13;
  uVar10 = unaff_r6;
  if ((unaff_r8 & uVar13) != 0) {
    param_4 = 1;
    do {
      param_2 = (uint)unaff_r4[param_4];
      param_1 = (int)(char)param_4;
      if (param_2 != *unaff_r4) {
        if (param_1 != 0x77) {
          uVar20 = 0x76;
          goto LAB_00004800;
        }
        break;
      }
      param_4 = param_4 + 1;
    } while (param_4 != 0x78);
LAB_000048d0:
    uVar20 = 0;
    uVar10 = unaff_r6;
  }
  goto LAB_00004762;
  while (uVar20 = uVar20 - 1, uVar20 != 0) {
LAB_00004800:
    if ((uint)unaff_r4[uVar20] != (uint)unaff_r4[0x77]) {
      param_3 = uVar20 & 0xff;
      if ((char)uVar20 == '\x01') goto LAB_000048d0;
      unaff_r9 = (uint)unaff_r4[param_4];
      if (unaff_r9 == unaff_r4[uVar20]) {
                    /* WARNING: Subroutine does not return */
        FUN_000050fc();
      }
      goto code_r0x00004820;
    }
  }
  goto LAB_00004762;
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004f76(void)

{
  undefined2 uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  uint extraout_r1;
  int extraout_r1_00;
  byte *pbVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined *puVar8;
  uint uVar9;
  uint unaff_r4;
  int unaff_r7;
  uint unaff_r8;
  uint unaff_r10;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  
code_r0x00004f76:
  if (unaff_r10 == 0x7e) {
                    /* WARNING: Subroutine does not return */
    FUN_00004fce();
  }
  unaff_r4 = unaff_r4 | 1;
  **(undefined **)(unaff_r7 + 0x30) = (char)unaff_r4;
  do {
    iVar4 = FUN_00008e08(0x20000528,0x7e,unaff_r8);
    if (iVar4 == 0) {
      iVar4 = FUN_000059aa();
    }
    bVar3 = (byte)(unaff_r4 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar3;
    uVar9 = (iVar4 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((unaff_r4 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar3 | 2;
    FUN_00003fec(0x800d4cc);
    lVar11 = (ulonglong)extraout_r1 << 0x20;
    bVar3 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar3 != uVar9) {
      lVar11 = FUN_00005980(0);
    }
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar3 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar11,(int)((ulonglong)lVar11 >> 0x20),uVar6);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar3 - (char)uVar9;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      enableIRQinterrupts((uVar6 & 1) == 1);
    }
LAB_00005012:
    do {
      iVar4 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
              (**(uint **)(unaff_r7 + 0x40) & 0xffff);
      *(int *)(unaff_r7 + 0x34) = iVar4;
      uVar6 = _DAT_20000b0c;
      uVar9 = iVar4 - *(int *)(unaff_r7 + 0x28);
      iVar4 = _DAT_20000808 + 1;
      iVar10 = _DAT_20000b14 + uVar9;
      if (uVar9 < 0x10000) {
        uVar9 = uVar9 * uVar9 + 0xff >> 8;
LAB_0000506c:
        uVar9 = uVar9 + _DAT_20000b18;
        if (uVar9 < _DAT_20000b18) {
          uVar9 = 0xffffffff;
        }
      }
      else {
        if (uVar9 < 0x100000) {
          uVar9 = (uVar9 + 0xff >> 8) * uVar9;
          goto LAB_0000506c;
        }
        uVar9 = 0xffffffff;
      }
      _DAT_20000808 = iVar4;
      _DAT_20000b14 = iVar10;
      _DAT_20000b18 = uVar9;
      if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
        FUN_00004652();
        iVar4 = extraout_r1_00;
      }
      FUN_00003fec(0x800c16c,iVar4,iVar10);
      if (*(uint *)(unaff_r7 + 0x34) < uVar6) {
        _DAT_20000b10 = _DAT_20000b10 + 1;
      }
      _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
      _DAT_20000b18 = 0;
      _DAT_20000b14 = 0;
      _DAT_20000808 = 0;
      if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
        FUN_00004660();
      }
      *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
      uVar12 = FUN_000046b4();
LAB_000050de:
      iVar4 = (int)uVar12;
      uVar1 = *(undefined2 *)(iVar4 + 0x18);
      uVar7 = *(undefined4 *)(iVar4 + 0x14);
      (&DAT_20000b18)[iVar4] = (char)(uVar12 >> 0x20) + '\x01';
      enableIRQinterrupts();
      FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar7,uVar1);
LAB_00004c28:
      iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
      if (iVar4 != 0) {
        if ((&DAT_20000b18)[iVar4] == *(char *)(iVar4 + 0x27)) {
          disableIRQinterrupts();
          uVar12 = (ulonglong)CONCAT14(*(char *)(iVar4 + 0x27),iVar4);
          if (*(char *)(iVar4 + 0x27) != (&DAT_20000b18)[iVar4]) {
            enableIRQinterrupts();
            goto LAB_00004c28;
          }
          goto LAB_000050de;
        }
        goto LAB_00004c28;
      }
      iVar4 = FUN_0000617c(0x20000788);
      if (iVar4 != 0) {
        *(undefined *)(unaff_r7 + 0x5f) = 0xff;
        while (iVar4 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar4 != 0) {
          if ((*(byte *)(iVar4 + 0x1f) & 1) != 0) {
            disableIRQinterrupts();
            uVar7 = *(undefined4 *)(iVar4 + 8);
            *(byte *)(iVar4 + 0x1f) = *(byte *)(iVar4 + 0x1f) & 0xfe;
            enableIRQinterrupts();
            bVar3 = *(byte *)(iVar4 + 0x1e);
            if (bVar3 == 2) {
              *(undefined4 *)(unaff_r7 + 0x60) = 1;
              FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,3,unaff_r7 + 0x60);
              uVar9 = *(uint *)(unaff_r7 + 0x60);
              *(undefined2 *)(unaff_r7 + 0x60) = 7;
              FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,2,unaff_r7 + 0x60);
              uVar9 = (((uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
              FUN_00002244(iVar4,uVar7,uVar9,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar9 & 1);
            }
            else if (bVar3 < 3) {
              if (bVar3 == 0) {
                *(undefined4 *)(unaff_r7 + 0x60) = 0;
                FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,4,unaff_r7 + 0x60);
                uVar9 = *(uint *)(unaff_r7 + 0x60);
                FUN_00002244(iVar4,uVar7,
                             uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 |
                             (uVar9 >> 0x10 & 0xff) << 8 | uVar9 >> 0x18,uVar9 >> 0x18 & 7);
              }
              else {
                *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
                FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,4,unaff_r7 + 0x60);
                uVar9 = *(uint *)(unaff_r7 + 0x60);
                *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
                FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,2,unaff_r7 + 0x60);
                FUN_00002244(iVar4,uVar7,
                             (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
                             uVar9 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
              }
            }
            else if (bVar3 == 3) {
              *(undefined2 *)(unaff_r7 + 0x60) = 0;
              FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,2,unaff_r7 + 0x60);
              uVar9 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
              FUN_00002244(iVar4,uVar7,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar9,uVar9 & 6)
              ;
            }
          }
        }
      }
      iVar4 = FUN_0000617c(0x20000068);
      if (iVar4 != 0) {
        puVar8 = (undefined *)(unaff_r7 + 0x5f);
        *puVar8 = 0xff;
        while (iVar4 = FUN_000033d4(puVar8,0x80037c5), iVar4 != 0) {
          if ((*(byte *)(iVar4 + 0x18) & 4) != 0) {
            if ((int)((uint)*(byte *)(iVar4 + 0x18) << 0x1f) < 0) {
              FUN_000061a0(iVar4);
              *(undefined *)(iVar4 + 0x18) = 2;
              *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
              FUN_000022b0(*(undefined4 *)(iVar4 + 0x10),0,2,unaff_r7 + 0x60);
              disableIRQinterrupts();
              *(uint *)(iVar4 + 8) =
                   (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                   (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar4 + 0xc);
              FUN_000061fc(iVar4);
              enableIRQinterrupts();
            }
            else {
              FUN_00002478(iVar4,*puVar8);
            }
          }
        }
      }
      iVar4 = FUN_0000617c(0x20000794);
      if (iVar4 != 0) {
        *(undefined *)(unaff_r7 + 0x60) = 0xff;
        while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar4 != 0) {
          if ((*(byte *)(iVar4 + 0x11) & 8) != 0) {
            disableIRQinterrupts();
            *(byte *)(iVar4 + 0x11) = *(byte *)(iVar4 + 0x11) & 0xf7;
            enableIRQinterrupts();
            FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar4 + 0x13) >> 3,
                         iVar4 + 0x20);
          }
        }
      }
      iVar4 = FUN_0000617c(0x200001f4);
      if (iVar4 != 0) {
        *(undefined *)(unaff_r7 + 0x60) = 0xff;
        while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar4 != 0) {
          if ((*(byte *)(iVar4 + 0x20) & 1) != 0) {
            disableIRQinterrupts();
            *(byte *)(iVar4 + 0x20) = *(byte *)(iVar4 + 0x20) & 0xfe;
            enableIRQinterrupts();
            FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar4 + 8),
                         *(undefined4 *)(iVar4 + 0x18));
          }
        }
      }
      iVar4 = FUN_0000617c(0x200001f0);
      if (iVar4 != 0) {
        *(undefined *)(unaff_r7 + 0x60) = 0xff;
        while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar4 != 0) {
          if (*(char *)(iVar4 + 0x1c) == -1) {
            disableIRQinterrupts();
            if (*(char *)(iVar4 + 0x12) == '\0') {
              enableIRQinterrupts();
            }
            else {
              *(undefined *)(iVar4 + 0x1c) = *(undefined *)(iVar4 + 0x1d);
              enableIRQinterrupts();
              FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar4 + 0x1b));
            }
          }
        }
      }
      uRam40003000 = 0xaaaa;
      iVar10 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
               (**(uint **)(unaff_r7 + 0x40) & 0xffff);
      disableIRQinterrupts();
      iVar4 = **(int **)(unaff_r7 + 4);
      *(int *)(unaff_r7 + 0x50) = iVar4;
      if (iVar4 - iVar10 < 0) {
        **(int **)(unaff_r7 + 4) = iVar10;
      }
      enableIRQinterrupts();
      unaff_r8 = (uint)**(byte **)(unaff_r7 + 0x2c);
    } while (unaff_r8 == 0);
    unaff_r4 = (uint)**(byte **)(unaff_r7 + 0x30);
  } while ((int)(unaff_r4 << 0x1f) < 0);
  if (4 < unaff_r8) {
    pbVar5 = *(byte **)(unaff_r7 + 0x1c);
    unaff_r10 = (uint)*pbVar5;
    if ((0x3b < unaff_r10 - 5) || ((pbVar5[1] & 0xf0) != 0x10)) goto code_r0x00004f76;
    if (unaff_r10 <= unaff_r8) {
      if (pbVar5[unaff_r10 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
        FUN_000059f2();
      }
      goto code_r0x00004f76;
    }
  }
  goto LAB_00005012;
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004fae(void)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  uint extraout_r1;
  int extraout_r1_00;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint unaff_r4;
  int unaff_r7;
  uint unaff_r10;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  
  do {
    if ((int)(unaff_r4 << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = (byte)unaff_r4 | 2;
    FUN_00003fec(0x800d4cc);
    lVar12 = (ulonglong)extraout_r1 << 0x20;
    bVar1 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar1 != unaff_r10) {
      lVar12 = FUN_00005980(0);
    }
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar1 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),uVar5);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar1 - (char)unaff_r10;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    do {
      do {
        do {
          iVar9 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                  (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          *(int *)(unaff_r7 + 0x34) = iVar9;
          uVar10 = _DAT_20000b0c;
          uVar5 = iVar9 - *(int *)(unaff_r7 + 0x28);
          iVar9 = _DAT_20000808 + 1;
          iVar11 = _DAT_20000b14 + uVar5;
          if (uVar5 < 0x10000) {
            uVar5 = uVar5 * uVar5 + 0xff >> 8;
LAB_0000506c:
            uVar5 = uVar5 + _DAT_20000b18;
            if (uVar5 < _DAT_20000b18) {
              uVar5 = 0xffffffff;
            }
          }
          else {
            if (uVar5 < 0x100000) {
              uVar5 = (uVar5 + 0xff >> 8) * uVar5;
              goto LAB_0000506c;
            }
            uVar5 = 0xffffffff;
          }
          _DAT_20000808 = iVar9;
          _DAT_20000b14 = iVar11;
          _DAT_20000b18 = uVar5;
          if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
            FUN_00004652();
            iVar9 = extraout_r1_00;
          }
          FUN_00003fec(0x800c16c,iVar9,iVar11);
          if (*(uint *)(unaff_r7 + 0x34) < uVar10) {
            _DAT_20000b10 = _DAT_20000b10 + 1;
          }
          _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
          _DAT_20000b18 = 0;
          _DAT_20000b14 = 0;
          _DAT_20000808 = 0;
          if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
            FUN_00004660();
          }
          *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
          uVar13 = FUN_000046b4();
LAB_000050de:
          iVar9 = (int)uVar13;
          uVar2 = *(undefined2 *)(iVar9 + 0x18);
          uVar6 = *(undefined4 *)(iVar9 + 0x14);
          (&DAT_20000b18)[iVar9] = (char)(uVar13 >> 0x20) + '\x01';
          enableIRQinterrupts();
          FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar6,uVar2);
LAB_00004c28:
          iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
          if (iVar9 != 0) {
            if ((&DAT_20000b18)[iVar9] == *(char *)(iVar9 + 0x27)) {
              disableIRQinterrupts();
              uVar13 = (ulonglong)CONCAT14(*(char *)(iVar9 + 0x27),iVar9);
              if (*(char *)(iVar9 + 0x27) != (&DAT_20000b18)[iVar9]) {
                enableIRQinterrupts();
                goto LAB_00004c28;
              }
              goto LAB_000050de;
            }
            goto LAB_00004c28;
          }
          iVar9 = FUN_0000617c(0x20000788);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x5f) = 0xff;
            while (iVar9 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x1f) & 1) != 0) {
                disableIRQinterrupts();
                uVar6 = *(undefined4 *)(iVar9 + 8);
                *(byte *)(iVar9 + 0x1f) = *(byte *)(iVar9 + 0x1f) & 0xfe;
                enableIRQinterrupts();
                bVar1 = *(byte *)(iVar9 + 0x1e);
                if (bVar1 == 2) {
                  *(undefined4 *)(unaff_r7 + 0x60) = 1;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,3,unaff_r7 + 0x60);
                  uVar5 = *(uint *)(unaff_r7 + 0x60);
                  *(undefined2 *)(unaff_r7 + 0x60) = 7;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (((uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8) << 8) >> 0x10
                  ;
                  FUN_00002244(iVar9,uVar6,uVar5,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar5 & 1
                              );
                }
                else if (bVar1 < 3) {
                  if (bVar1 == 0) {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 |
                                 (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18,uVar5 >> 0x18 & 7);
                  }
                  else {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                                 uVar5 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
                  }
                }
                else if (bVar1 == 3) {
                  *(undefined2 *)(unaff_r7 + 0x60) = 0;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
                  FUN_00002244(iVar9,uVar6,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar5,
                               uVar5 & 6);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000068);
          if (iVar9 != 0) {
            puVar7 = (undefined *)(unaff_r7 + 0x5f);
            *puVar7 = 0xff;
            while (iVar9 = FUN_000033d4(puVar7,0x80037c5), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x18) & 4) != 0) {
                if ((int)((uint)*(byte *)(iVar9 + 0x18) << 0x1f) < 0) {
                  FUN_000061a0(iVar9);
                  *(undefined *)(iVar9 + 0x18) = 2;
                  *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x10),0,2,unaff_r7 + 0x60);
                  disableIRQinterrupts();
                  *(uint *)(iVar9 + 8) =
                       (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                       (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar9 + 0xc);
                  FUN_000061fc(iVar9);
                  enableIRQinterrupts();
                }
                else {
                  FUN_00002478(iVar9,*puVar7);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000794);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x11) & 8) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x11) = *(byte *)(iVar9 + 0x11) & 0xf7;
                enableIRQinterrupts();
                FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar9 + 0x13) >> 3,
                             iVar9 + 0x20);
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f4);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x20) & 1) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x20) = *(byte *)(iVar9 + 0x20) & 0xfe;
                enableIRQinterrupts();
                FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar9 + 8),
                             *(undefined4 *)(iVar9 + 0x18));
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f0);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar9 != 0) {
              if (*(char *)(iVar9 + 0x1c) == -1) {
                disableIRQinterrupts();
                if (*(char *)(iVar9 + 0x12) == '\0') {
                  enableIRQinterrupts();
                }
                else {
                  *(undefined *)(iVar9 + 0x1c) = *(undefined *)(iVar9 + 0x1d);
                  enableIRQinterrupts();
                  FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),
                               *(undefined *)(iVar9 + 0x1b));
                }
              }
            }
          }
          uRam40003000 = 0xaaaa;
          iVar11 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                   (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          disableIRQinterrupts();
          iVar9 = **(int **)(unaff_r7 + 4);
          *(int *)(unaff_r7 + 0x50) = iVar9;
          if (iVar9 - iVar11 < 0) {
            **(int **)(unaff_r7 + 4) = iVar11;
          }
          enableIRQinterrupts();
          uVar5 = (uint)**(byte **)(unaff_r7 + 0x2c);
        } while (uVar5 == 0);
        uVar10 = (uint)**(byte **)(unaff_r7 + 0x30);
        if ((int)(uVar10 << 0x1f) < 0) goto LAB_00004f86;
      } while (uVar5 < 5);
      pbVar4 = *(byte **)(unaff_r7 + 0x1c);
      uVar8 = (uint)*pbVar4;
      if ((0x3b < uVar8 - 5) || ((pbVar4[1] & 0xf0) != 0x10)) goto FUN_00004f76;
    } while (uVar5 < uVar8);
    if (pbVar4[uVar8 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_000059f2();
    }
FUN_00004f76:
    if (uVar8 == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_00004fce();
    }
    uVar10 = uVar10 | 1;
    **(undefined **)(unaff_r7 + 0x30) = (char)uVar10;
LAB_00004f86:
    iVar9 = FUN_00008e08(0x20000528,0x7e,uVar5);
    if (iVar9 == 0) {
      iVar9 = FUN_000059aa();
    }
    unaff_r4 = uVar10 & 0xfffffffe;
    **(undefined **)(unaff_r7 + 0x30) = (char)unaff_r4;
    unaff_r10 = (iVar9 - *(int *)(unaff_r7 + 0x1c)) + 1;
  } while( true );
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004fbe(void)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  uint extraout_r1;
  int extraout_r1_00;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int unaff_r7;
  uint unaff_r10;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  
  do {
    FUN_00003fec(0x800d4cc);
    lVar12 = (ulonglong)extraout_r1 << 0x20;
    bVar1 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar1 != unaff_r10) {
      lVar12 = FUN_00005980(0);
    }
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar1 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),uVar5);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar1 - (char)unaff_r10;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    do {
      do {
        do {
          iVar9 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                  (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          *(int *)(unaff_r7 + 0x34) = iVar9;
          uVar10 = _DAT_20000b0c;
          uVar5 = iVar9 - *(int *)(unaff_r7 + 0x28);
          iVar9 = _DAT_20000808 + 1;
          iVar11 = _DAT_20000b14 + uVar5;
          if (uVar5 < 0x10000) {
            uVar5 = uVar5 * uVar5 + 0xff >> 8;
LAB_0000506c:
            uVar5 = uVar5 + _DAT_20000b18;
            if (uVar5 < _DAT_20000b18) {
              uVar5 = 0xffffffff;
            }
          }
          else {
            if (uVar5 < 0x100000) {
              uVar5 = (uVar5 + 0xff >> 8) * uVar5;
              goto LAB_0000506c;
            }
            uVar5 = 0xffffffff;
          }
          _DAT_20000808 = iVar9;
          _DAT_20000b14 = iVar11;
          _DAT_20000b18 = uVar5;
          if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
            FUN_00004652();
            iVar9 = extraout_r1_00;
          }
          FUN_00003fec(0x800c16c,iVar9,iVar11);
          if (*(uint *)(unaff_r7 + 0x34) < uVar10) {
            _DAT_20000b10 = _DAT_20000b10 + 1;
          }
          _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
          _DAT_20000b18 = 0;
          _DAT_20000b14 = 0;
          _DAT_20000808 = 0;
          if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
            FUN_00004660();
          }
          *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
          uVar13 = FUN_000046b4();
LAB_000050de:
          iVar9 = (int)uVar13;
          uVar2 = *(undefined2 *)(iVar9 + 0x18);
          uVar6 = *(undefined4 *)(iVar9 + 0x14);
          (&DAT_20000b18)[iVar9] = (char)(uVar13 >> 0x20) + '\x01';
          enableIRQinterrupts();
          FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar6,uVar2);
LAB_00004c28:
          iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
          if (iVar9 != 0) {
            if ((&DAT_20000b18)[iVar9] == *(char *)(iVar9 + 0x27)) {
              disableIRQinterrupts();
              uVar13 = (ulonglong)CONCAT14(*(char *)(iVar9 + 0x27),iVar9);
              if (*(char *)(iVar9 + 0x27) != (&DAT_20000b18)[iVar9]) {
                enableIRQinterrupts();
                goto LAB_00004c28;
              }
              goto LAB_000050de;
            }
            goto LAB_00004c28;
          }
          iVar9 = FUN_0000617c(0x20000788);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x5f) = 0xff;
            while (iVar9 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x1f) & 1) != 0) {
                disableIRQinterrupts();
                uVar6 = *(undefined4 *)(iVar9 + 8);
                *(byte *)(iVar9 + 0x1f) = *(byte *)(iVar9 + 0x1f) & 0xfe;
                enableIRQinterrupts();
                bVar1 = *(byte *)(iVar9 + 0x1e);
                if (bVar1 == 2) {
                  *(undefined4 *)(unaff_r7 + 0x60) = 1;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,3,unaff_r7 + 0x60);
                  uVar5 = *(uint *)(unaff_r7 + 0x60);
                  *(undefined2 *)(unaff_r7 + 0x60) = 7;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (((uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8) << 8) >> 0x10
                  ;
                  FUN_00002244(iVar9,uVar6,uVar5,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar5 & 1
                              );
                }
                else if (bVar1 < 3) {
                  if (bVar1 == 0) {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 |
                                 (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18,uVar5 >> 0x18 & 7);
                  }
                  else {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                                 uVar5 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
                  }
                }
                else if (bVar1 == 3) {
                  *(undefined2 *)(unaff_r7 + 0x60) = 0;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
                  FUN_00002244(iVar9,uVar6,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar5,
                               uVar5 & 6);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000068);
          if (iVar9 != 0) {
            puVar7 = (undefined *)(unaff_r7 + 0x5f);
            *puVar7 = 0xff;
            while (iVar9 = FUN_000033d4(puVar7,0x80037c5), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x18) & 4) != 0) {
                if ((int)((uint)*(byte *)(iVar9 + 0x18) << 0x1f) < 0) {
                  FUN_000061a0(iVar9);
                  *(undefined *)(iVar9 + 0x18) = 2;
                  *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x10),0,2,unaff_r7 + 0x60);
                  disableIRQinterrupts();
                  *(uint *)(iVar9 + 8) =
                       (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                       (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar9 + 0xc);
                  FUN_000061fc(iVar9);
                  enableIRQinterrupts();
                }
                else {
                  FUN_00002478(iVar9,*puVar7);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000794);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x11) & 8) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x11) = *(byte *)(iVar9 + 0x11) & 0xf7;
                enableIRQinterrupts();
                FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar9 + 0x13) >> 3,
                             iVar9 + 0x20);
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f4);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x20) & 1) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x20) = *(byte *)(iVar9 + 0x20) & 0xfe;
                enableIRQinterrupts();
                FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar9 + 8),
                             *(undefined4 *)(iVar9 + 0x18));
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f0);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar9 != 0) {
              if (*(char *)(iVar9 + 0x1c) == -1) {
                disableIRQinterrupts();
                if (*(char *)(iVar9 + 0x12) == '\0') {
                  enableIRQinterrupts();
                }
                else {
                  *(undefined *)(iVar9 + 0x1c) = *(undefined *)(iVar9 + 0x1d);
                  enableIRQinterrupts();
                  FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),
                               *(undefined *)(iVar9 + 0x1b));
                }
              }
            }
          }
          uRam40003000 = 0xaaaa;
          iVar11 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                   (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          disableIRQinterrupts();
          iVar9 = **(int **)(unaff_r7 + 4);
          *(int *)(unaff_r7 + 0x50) = iVar9;
          if (iVar9 - iVar11 < 0) {
            **(int **)(unaff_r7 + 4) = iVar11;
          }
          enableIRQinterrupts();
          uVar5 = (uint)**(byte **)(unaff_r7 + 0x2c);
        } while (uVar5 == 0);
        uVar10 = (uint)**(byte **)(unaff_r7 + 0x30);
        if ((int)(uVar10 << 0x1f) < 0) goto LAB_00004f86;
      } while (uVar5 < 5);
      pbVar4 = *(byte **)(unaff_r7 + 0x1c);
      uVar8 = (uint)*pbVar4;
      if ((0x3b < uVar8 - 5) || ((pbVar4[1] & 0xf0) != 0x10)) goto FUN_00004f76;
    } while (uVar5 < uVar8);
    if (pbVar4[uVar8 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_000059f2();
    }
FUN_00004f76:
    if (uVar8 == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_00004fce();
    }
    uVar10 = uVar10 | 1;
    **(undefined **)(unaff_r7 + 0x30) = (char)uVar10;
LAB_00004f86:
    iVar9 = FUN_00008e08(0x20000528,0x7e,uVar5);
    if (iVar9 == 0) {
      iVar9 = FUN_000059aa();
    }
    bVar1 = (byte)(uVar10 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar1;
    unaff_r10 = (iVar9 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar10 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar1 | 2;
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004fce(undefined4 param_1,uint param_2)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  uint extraout_r1;
  int extraout_r1_00;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int unaff_r4;
  int unaff_r7;
  uint unaff_r10;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  
  do {
    lVar12 = (ulonglong)param_2 << 0x20;
    bVar1 = **(byte **)(unaff_r7 + 0x2c);
    if (bVar1 != unaff_r10) {
      lVar12 = FUN_00005980(0);
    }
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if ((uint)bVar1 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),uVar5);
    }
    **(char **)(unaff_r7 + 0x2c) = bVar1 - (char)unaff_r10;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    if (unaff_r4 == 1) {
      FUN_00003fec(0x800d4cc);
    }
    do {
      do {
        do {
          iVar9 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                  (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          *(int *)(unaff_r7 + 0x34) = iVar9;
          uVar10 = _DAT_20000b0c;
          uVar5 = iVar9 - *(int *)(unaff_r7 + 0x28);
          iVar9 = _DAT_20000808 + 1;
          iVar11 = _DAT_20000b14 + uVar5;
          if (uVar5 < 0x10000) {
            uVar5 = uVar5 * uVar5 + 0xff >> 8;
LAB_0000506c:
            uVar5 = uVar5 + _DAT_20000b18;
            if (uVar5 < _DAT_20000b18) {
              uVar5 = 0xffffffff;
            }
          }
          else {
            if (uVar5 < 0x100000) {
              uVar5 = (uVar5 + 0xff >> 8) * uVar5;
              goto LAB_0000506c;
            }
            uVar5 = 0xffffffff;
          }
          _DAT_20000808 = iVar9;
          _DAT_20000b14 = iVar11;
          _DAT_20000b18 = uVar5;
          if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
            FUN_00004652();
            iVar9 = extraout_r1_00;
          }
          FUN_00003fec(0x800c16c,iVar9,iVar11);
          if (*(uint *)(unaff_r7 + 0x34) < uVar10) {
            _DAT_20000b10 = _DAT_20000b10 + 1;
          }
          _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
          _DAT_20000b18 = 0;
          _DAT_20000b14 = 0;
          _DAT_20000808 = 0;
          if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
            FUN_00004660();
          }
          *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
          uVar13 = FUN_000046b4();
LAB_000050de:
          iVar9 = (int)uVar13;
          uVar2 = *(undefined2 *)(iVar9 + 0x18);
          uVar6 = *(undefined4 *)(iVar9 + 0x14);
          (&DAT_20000b18)[iVar9] = (char)(uVar13 >> 0x20) + '\x01';
          enableIRQinterrupts();
          FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar6,uVar2);
LAB_00004c28:
          iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
          if (iVar9 != 0) {
            if ((&DAT_20000b18)[iVar9] == *(char *)(iVar9 + 0x27)) {
              disableIRQinterrupts();
              uVar13 = (ulonglong)CONCAT14(*(char *)(iVar9 + 0x27),iVar9);
              if (*(char *)(iVar9 + 0x27) != (&DAT_20000b18)[iVar9]) {
                enableIRQinterrupts();
                goto LAB_00004c28;
              }
              goto LAB_000050de;
            }
            goto LAB_00004c28;
          }
          iVar9 = FUN_0000617c(0x20000788);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x5f) = 0xff;
            while (iVar9 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x1f) & 1) != 0) {
                disableIRQinterrupts();
                uVar6 = *(undefined4 *)(iVar9 + 8);
                *(byte *)(iVar9 + 0x1f) = *(byte *)(iVar9 + 0x1f) & 0xfe;
                enableIRQinterrupts();
                bVar1 = *(byte *)(iVar9 + 0x1e);
                if (bVar1 == 2) {
                  *(undefined4 *)(unaff_r7 + 0x60) = 1;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,3,unaff_r7 + 0x60);
                  uVar5 = *(uint *)(unaff_r7 + 0x60);
                  *(undefined2 *)(unaff_r7 + 0x60) = 7;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (((uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8) << 8) >> 0x10
                  ;
                  FUN_00002244(iVar9,uVar6,uVar5,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar5 & 1
                              );
                }
                else if (bVar1 < 3) {
                  if (bVar1 == 0) {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 |
                                 (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18,uVar5 >> 0x18 & 7);
                  }
                  else {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                                 uVar5 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
                  }
                }
                else if (bVar1 == 3) {
                  *(undefined2 *)(unaff_r7 + 0x60) = 0;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
                  FUN_00002244(iVar9,uVar6,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar5,
                               uVar5 & 6);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000068);
          if (iVar9 != 0) {
            puVar7 = (undefined *)(unaff_r7 + 0x5f);
            *puVar7 = 0xff;
            while (iVar9 = FUN_000033d4(puVar7,0x80037c5), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x18) & 4) != 0) {
                if ((int)((uint)*(byte *)(iVar9 + 0x18) << 0x1f) < 0) {
                  FUN_000061a0(iVar9);
                  *(undefined *)(iVar9 + 0x18) = 2;
                  *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x10),0,2,unaff_r7 + 0x60);
                  disableIRQinterrupts();
                  *(uint *)(iVar9 + 8) =
                       (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                       (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar9 + 0xc);
                  FUN_000061fc(iVar9);
                  enableIRQinterrupts();
                }
                else {
                  FUN_00002478(iVar9,*puVar7);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000794);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x11) & 8) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x11) = *(byte *)(iVar9 + 0x11) & 0xf7;
                enableIRQinterrupts();
                FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar9 + 0x13) >> 3,
                             iVar9 + 0x20);
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f4);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x20) & 1) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x20) = *(byte *)(iVar9 + 0x20) & 0xfe;
                enableIRQinterrupts();
                FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar9 + 8),
                             *(undefined4 *)(iVar9 + 0x18));
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f0);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar9 != 0) {
              if (*(char *)(iVar9 + 0x1c) == -1) {
                disableIRQinterrupts();
                if (*(char *)(iVar9 + 0x12) == '\0') {
                  enableIRQinterrupts();
                }
                else {
                  *(undefined *)(iVar9 + 0x1c) = *(undefined *)(iVar9 + 0x1d);
                  enableIRQinterrupts();
                  FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),
                               *(undefined *)(iVar9 + 0x1b));
                }
              }
            }
          }
          uRam40003000 = 0xaaaa;
          iVar11 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                   (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          disableIRQinterrupts();
          iVar9 = **(int **)(unaff_r7 + 4);
          *(int *)(unaff_r7 + 0x50) = iVar9;
          if (iVar9 - iVar11 < 0) {
            **(int **)(unaff_r7 + 4) = iVar11;
          }
          enableIRQinterrupts();
          uVar5 = (uint)**(byte **)(unaff_r7 + 0x2c);
        } while (uVar5 == 0);
        uVar10 = (uint)**(byte **)(unaff_r7 + 0x30);
        if ((int)(uVar10 << 0x1f) < 0) goto LAB_00004f86;
      } while (uVar5 < 5);
      pbVar4 = *(byte **)(unaff_r7 + 0x1c);
      uVar8 = (uint)*pbVar4;
      if ((0x3b < uVar8 - 5) || ((pbVar4[1] & 0xf0) != 0x10)) goto FUN_00004f76;
    } while (uVar5 < uVar8);
    if (pbVar4[uVar8 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_000059f2();
    }
FUN_00004f76:
    if (uVar8 == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_00004fce();
    }
    uVar10 = uVar10 | 1;
    **(undefined **)(unaff_r7 + 0x30) = (char)uVar10;
LAB_00004f86:
    iVar9 = FUN_00008e08(0x20000528,0x7e,uVar5);
    if (iVar9 == 0) {
      iVar9 = FUN_000059aa();
    }
    bVar1 = (byte)(uVar10 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar1;
    unaff_r10 = (iVar9 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar10 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar1 | 2;
    FUN_00003fec(0x800d4cc);
    unaff_r4 = -1;
    param_2 = extraout_r1;
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004fe6(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  uint extraout_r1;
  int extraout_r1_00;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int unaff_r4;
  uint unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  
  lVar12 = CONCAT44(param_2,param_1);
  do {
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    if (unaff_r5 != **(byte **)(unaff_r7 + 0x2c)) {
      FUN_0000596a((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),uVar5);
    }
    **(undefined **)(unaff_r7 + 0x2c) = (char)unaff_r6;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    if (unaff_r4 == 1) {
      FUN_00003fec(0x800d4cc);
    }
    do {
      do {
        do {
          iVar9 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                  (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          *(int *)(unaff_r7 + 0x34) = iVar9;
          uVar10 = _DAT_20000b0c;
          uVar5 = iVar9 - *(int *)(unaff_r7 + 0x28);
          iVar9 = _DAT_20000808 + 1;
          iVar11 = _DAT_20000b14 + uVar5;
          if (uVar5 < 0x10000) {
            uVar5 = uVar5 * uVar5 + 0xff >> 8;
LAB_0000506c:
            uVar5 = uVar5 + _DAT_20000b18;
            if (uVar5 < _DAT_20000b18) {
              uVar5 = 0xffffffff;
            }
          }
          else {
            if (uVar5 < 0x100000) {
              uVar5 = (uVar5 + 0xff >> 8) * uVar5;
              goto LAB_0000506c;
            }
            uVar5 = 0xffffffff;
          }
          _DAT_20000808 = iVar9;
          _DAT_20000b14 = iVar11;
          _DAT_20000b18 = uVar5;
          if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
            FUN_00004652();
            iVar9 = extraout_r1_00;
          }
          FUN_00003fec(0x800c16c,iVar9,iVar11);
          if (*(uint *)(unaff_r7 + 0x34) < uVar10) {
            _DAT_20000b10 = _DAT_20000b10 + 1;
          }
          _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
          _DAT_20000b18 = 0;
          _DAT_20000b14 = 0;
          _DAT_20000808 = 0;
          if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
            FUN_00004660();
          }
          *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
          uVar13 = FUN_000046b4();
LAB_000050de:
          iVar9 = (int)uVar13;
          uVar2 = *(undefined2 *)(iVar9 + 0x18);
          uVar6 = *(undefined4 *)(iVar9 + 0x14);
          (&DAT_20000b18)[iVar9] = (char)(uVar13 >> 0x20) + '\x01';
          enableIRQinterrupts();
          FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar6,uVar2);
LAB_00004c28:
          iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
          if (iVar9 != 0) {
            if ((&DAT_20000b18)[iVar9] == *(char *)(iVar9 + 0x27)) {
              disableIRQinterrupts();
              uVar13 = (ulonglong)CONCAT14(*(char *)(iVar9 + 0x27),iVar9);
              if (*(char *)(iVar9 + 0x27) != (&DAT_20000b18)[iVar9]) {
                enableIRQinterrupts();
                goto LAB_00004c28;
              }
              goto LAB_000050de;
            }
            goto LAB_00004c28;
          }
          iVar9 = FUN_0000617c(0x20000788);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x5f) = 0xff;
            while (iVar9 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x1f) & 1) != 0) {
                disableIRQinterrupts();
                uVar6 = *(undefined4 *)(iVar9 + 8);
                *(byte *)(iVar9 + 0x1f) = *(byte *)(iVar9 + 0x1f) & 0xfe;
                enableIRQinterrupts();
                bVar1 = *(byte *)(iVar9 + 0x1e);
                if (bVar1 == 2) {
                  *(undefined4 *)(unaff_r7 + 0x60) = 1;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,3,unaff_r7 + 0x60);
                  uVar5 = *(uint *)(unaff_r7 + 0x60);
                  *(undefined2 *)(unaff_r7 + 0x60) = 7;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (((uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8) << 8) >> 0x10
                  ;
                  FUN_00002244(iVar9,uVar6,uVar5,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar5 & 1
                              );
                }
                else if (bVar1 < 3) {
                  if (bVar1 == 0) {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 |
                                 (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18,uVar5 >> 0x18 & 7);
                  }
                  else {
                    *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,4,unaff_r7 + 0x60);
                    uVar5 = *(uint *)(unaff_r7 + 0x60);
                    *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
                    FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                    FUN_00002244(iVar9,uVar6,
                                 (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                                 uVar5 >> 0x18,*(undefined *)(unaff_r7 + 0x61));
                  }
                }
                else if (bVar1 == 3) {
                  *(undefined2 *)(unaff_r7 + 0x60) = 0;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x18),1,2,unaff_r7 + 0x60);
                  uVar5 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
                  FUN_00002244(iVar9,uVar6,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar5,
                               uVar5 & 6);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000068);
          if (iVar9 != 0) {
            puVar7 = (undefined *)(unaff_r7 + 0x5f);
            *puVar7 = 0xff;
            while (iVar9 = FUN_000033d4(puVar7,0x80037c5), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x18) & 4) != 0) {
                if ((int)((uint)*(byte *)(iVar9 + 0x18) << 0x1f) < 0) {
                  FUN_000061a0(iVar9);
                  *(undefined *)(iVar9 + 0x18) = 2;
                  *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
                  FUN_000022b0(*(undefined4 *)(iVar9 + 0x10),0,2,unaff_r7 + 0x60);
                  disableIRQinterrupts();
                  *(uint *)(iVar9 + 8) =
                       (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                       (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar9 + 0xc);
                  FUN_000061fc(iVar9);
                  enableIRQinterrupts();
                }
                else {
                  FUN_00002478(iVar9,*puVar7);
                }
              }
            }
          }
          iVar9 = FUN_0000617c(0x20000794);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x11) & 8) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x11) = *(byte *)(iVar9 + 0x11) & 0xf7;
                enableIRQinterrupts();
                FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar9 + 0x13) >> 3,
                             iVar9 + 0x20);
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f4);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar9 != 0) {
              if ((*(byte *)(iVar9 + 0x20) & 1) != 0) {
                disableIRQinterrupts();
                *(byte *)(iVar9 + 0x20) = *(byte *)(iVar9 + 0x20) & 0xfe;
                enableIRQinterrupts();
                FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar9 + 8),
                             *(undefined4 *)(iVar9 + 0x18));
              }
            }
          }
          iVar9 = FUN_0000617c(0x200001f0);
          if (iVar9 != 0) {
            *(undefined *)(unaff_r7 + 0x60) = 0xff;
            while (iVar9 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar9 != 0) {
              if (*(char *)(iVar9 + 0x1c) == -1) {
                disableIRQinterrupts();
                if (*(char *)(iVar9 + 0x12) == '\0') {
                  enableIRQinterrupts();
                }
                else {
                  *(undefined *)(iVar9 + 0x1c) = *(undefined *)(iVar9 + 0x1d);
                  enableIRQinterrupts();
                  FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),
                               *(undefined *)(iVar9 + 0x1b));
                }
              }
            }
          }
          uRam40003000 = 0xaaaa;
          iVar11 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                   (**(uint **)(unaff_r7 + 0x40) & 0xffff);
          disableIRQinterrupts();
          iVar9 = **(int **)(unaff_r7 + 4);
          *(int *)(unaff_r7 + 0x50) = iVar9;
          if (iVar9 - iVar11 < 0) {
            **(int **)(unaff_r7 + 4) = iVar11;
          }
          enableIRQinterrupts();
          uVar5 = (uint)**(byte **)(unaff_r7 + 0x2c);
        } while (uVar5 == 0);
        uVar10 = (uint)**(byte **)(unaff_r7 + 0x30);
        if ((int)(uVar10 << 0x1f) < 0) goto LAB_00004f86;
      } while (uVar5 < 5);
      pbVar4 = *(byte **)(unaff_r7 + 0x1c);
      uVar8 = (uint)*pbVar4;
      if ((0x3b < uVar8 - 5) || ((pbVar4[1] & 0xf0) != 0x10)) goto FUN_00004f76;
    } while (uVar5 < uVar8);
    if (pbVar4[uVar8 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_000059f2();
    }
FUN_00004f76:
    if (uVar8 == 0x7e) {
                    /* WARNING: Subroutine does not return */
      FUN_00004fce();
    }
    uVar10 = uVar10 | 1;
    **(undefined **)(unaff_r7 + 0x30) = (char)uVar10;
LAB_00004f86:
    iVar9 = FUN_00008e08(0x20000528,0x7e,uVar5);
    if (iVar9 == 0) {
      iVar9 = FUN_000059aa();
    }
    bVar1 = (byte)(uVar10 & 0xfffffffe);
    **(byte **)(unaff_r7 + 0x30) = bVar1;
    uVar5 = (iVar9 - *(int *)(unaff_r7 + 0x1c)) + 1;
    if ((int)((uVar10 & 0xfffffffe) << 0x1e) < 0) {
      FUN_000059a2();
    }
    **(byte **)(unaff_r7 + 0x30) = bVar1 | 2;
    FUN_00003fec(0x800d4cc);
    unaff_r4 = -1;
    lVar12 = (ulonglong)extraout_r1 << 0x20;
    unaff_r5 = (uint)**(byte **)(unaff_r7 + 0x2c);
    unaff_r6 = unaff_r5 - uVar5;
    if (unaff_r5 != uVar5) {
      lVar12 = FUN_00005980();
    }
  } while( true );
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000050d6(void)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  uint extraout_r1;
  int extraout_r1_00;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined *unaff_r4;
  int unaff_r7;
  longlong lVar12;
  ulonglong uVar13;
  
  do {
    *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
    uVar13 = FUN_000046b4();
LAB_000050de:
    iVar4 = (int)uVar13;
    uVar2 = *(undefined2 *)(iVar4 + 0x18);
    uVar6 = *(undefined4 *)(iVar4 + 0x14);
    unaff_r4[iVar4] = (char)(uVar13 >> 0x20) + '\x01';
    enableIRQinterrupts();
    FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar6,uVar2);
LAB_00004c28:
    iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
    if (iVar4 != 0) {
      if (unaff_r4[iVar4] == *(char *)(iVar4 + 0x27)) {
        disableIRQinterrupts();
        uVar13 = (ulonglong)CONCAT14(*(char *)(iVar4 + 0x27),iVar4);
        if (*(char *)(iVar4 + 0x27) != unaff_r4[iVar4]) {
          enableIRQinterrupts();
          goto LAB_00004c28;
        }
        goto LAB_000050de;
      }
      goto LAB_00004c28;
    }
    iVar4 = FUN_0000617c(0x20000788);
    if (iVar4 != 0) {
      *(undefined *)(unaff_r7 + 0x5f) = 0xff;
      while (iVar4 = FUN_000033d4((undefined *)(unaff_r7 + 0x5f),0x80037f9), iVar4 != 0) {
        if ((*(byte *)(iVar4 + 0x1f) & 1) != 0) {
          disableIRQinterrupts();
          uVar6 = *(undefined4 *)(iVar4 + 8);
          *(byte *)(iVar4 + 0x1f) = *(byte *)(iVar4 + 0x1f) & 0xfe;
          enableIRQinterrupts();
          bVar1 = *(byte *)(iVar4 + 0x1e);
          if (bVar1 == 2) {
            *(undefined4 *)(unaff_r7 + 0x60) = 1;
            FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,3,unaff_r7 + 0x60);
            uVar7 = *(uint *)(unaff_r7 + 0x60);
            *(undefined2 *)(unaff_r7 + 0x60) = 7;
            FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,2,unaff_r7 + 0x60);
            uVar7 = (((uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
            FUN_00002244(iVar4,uVar6,uVar7,*(byte *)(unaff_r7 + 0x61) & 0xfffffffc | uVar7 & 1);
          }
          else if (bVar1 < 3) {
            if (bVar1 == 0) {
              *(undefined4 *)(unaff_r7 + 0x60) = 0;
              FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,4,unaff_r7 + 0x60);
              uVar7 = *(uint *)(unaff_r7 + 0x60);
              FUN_00002244(iVar4,uVar6,
                           uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8
                           | uVar7 >> 0x18,uVar7 >> 0x18 & 7);
            }
            else {
              *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
              FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,4,unaff_r7 + 0x60);
              uVar7 = *(uint *)(unaff_r7 + 0x60);
              *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
              FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,2,unaff_r7 + 0x60);
              FUN_00002244(iVar4,uVar6,
                           (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18
                           ,*(undefined *)(unaff_r7 + 0x61));
            }
          }
          else if (bVar1 == 3) {
            *(undefined2 *)(unaff_r7 + 0x60) = 0;
            FUN_000022b0(*(undefined4 *)(iVar4 + 0x18),1,2,unaff_r7 + 0x60);
            uVar7 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
            FUN_00002244(iVar4,uVar6,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar7,uVar7 & 6);
          }
        }
      }
    }
    iVar4 = FUN_0000617c(0x20000068);
    if (iVar4 != 0) {
      puVar8 = (undefined *)(unaff_r7 + 0x5f);
      *puVar8 = 0xff;
      while (iVar4 = FUN_000033d4(puVar8,0x80037c5), iVar4 != 0) {
        if ((*(byte *)(iVar4 + 0x18) & 4) != 0) {
          if ((int)((uint)*(byte *)(iVar4 + 0x18) << 0x1f) < 0) {
            FUN_000061a0(iVar4);
            *(undefined *)(iVar4 + 0x18) = 2;
            *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
            FUN_000022b0(*(undefined4 *)(iVar4 + 0x10),0,2,unaff_r7 + 0x60);
            disableIRQinterrupts();
            *(uint *)(iVar4 + 8) =
                 (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                 (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar4 + 0xc);
            FUN_000061fc(iVar4);
            enableIRQinterrupts();
          }
          else {
            FUN_00002478(iVar4,*puVar8);
          }
        }
      }
    }
    iVar4 = FUN_0000617c(0x20000794);
    if (iVar4 != 0) {
      *(undefined *)(unaff_r7 + 0x60) = 0xff;
      while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar4 != 0) {
        if ((*(byte *)(iVar4 + 0x11) & 8) != 0) {
          disableIRQinterrupts();
          *(byte *)(iVar4 + 0x11) = *(byte *)(iVar4 + 0x11) & 0xf7;
          enableIRQinterrupts();
          FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar4 + 0x13) >> 3,
                       iVar4 + 0x20);
        }
      }
    }
    iVar4 = FUN_0000617c(0x200001f4);
    if (iVar4 != 0) {
      *(undefined *)(unaff_r7 + 0x60) = 0xff;
      while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar4 != 0) {
        if ((*(byte *)(iVar4 + 0x20) & 1) != 0) {
          disableIRQinterrupts();
          *(byte *)(iVar4 + 0x20) = *(byte *)(iVar4 + 0x20) & 0xfe;
          enableIRQinterrupts();
          FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar4 + 8),
                       *(undefined4 *)(iVar4 + 0x18));
        }
      }
    }
    iVar4 = FUN_0000617c(0x200001f0);
    if (iVar4 != 0) {
      *(undefined *)(unaff_r7 + 0x60) = 0xff;
      while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar4 != 0) {
        if (*(char *)(iVar4 + 0x1c) == -1) {
          disableIRQinterrupts();
          if (*(char *)(iVar4 + 0x12) == '\0') {
            enableIRQinterrupts();
          }
          else {
            *(undefined *)(iVar4 + 0x1c) = *(undefined *)(iVar4 + 0x1d);
            enableIRQinterrupts();
            FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar4 + 0x1b));
          }
        }
      }
    }
    uRam40003000 = 0xaaaa;
    iVar9 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff)
    ;
    disableIRQinterrupts();
    iVar4 = **(int **)(unaff_r7 + 4);
    *(int *)(unaff_r7 + 0x50) = iVar4;
    if (iVar4 - iVar9 < 0) {
      **(int **)(unaff_r7 + 4) = iVar9;
    }
    enableIRQinterrupts();
    uVar7 = (uint)**(byte **)(unaff_r7 + 0x2c);
    if (uVar7 != 0) {
      uVar11 = (uint)**(byte **)(unaff_r7 + 0x30);
      if (-1 < (int)(uVar11 << 0x1f)) {
        if (uVar7 < 5) goto LAB_00005012;
        pbVar5 = *(byte **)(unaff_r7 + 0x1c);
        uVar10 = (uint)*pbVar5;
        if ((uVar10 - 5 < 0x3c) && ((pbVar5[1] & 0xf0) == 0x10)) {
          if (uVar7 < uVar10) goto LAB_00005012;
          if (pbVar5[uVar10 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
            FUN_000059f2();
          }
        }
        if (uVar10 == 0x7e) {
                    /* WARNING: Subroutine does not return */
          FUN_00004fce();
        }
        uVar11 = uVar11 | 1;
        **(undefined **)(unaff_r7 + 0x30) = (char)uVar11;
      }
      iVar4 = FUN_00008e08(0x20000528,0x7e,uVar7);
      if (iVar4 == 0) {
        iVar4 = FUN_000059aa();
      }
      bVar1 = (byte)(uVar11 & 0xfffffffe);
      **(byte **)(unaff_r7 + 0x30) = bVar1;
      uVar7 = (iVar4 - *(int *)(unaff_r7 + 0x1c)) + 1;
      if ((int)((uVar11 & 0xfffffffe) << 0x1e) < 0) {
        FUN_000059a2();
      }
      **(byte **)(unaff_r7 + 0x30) = bVar1 | 2;
      FUN_00003fec(0x800d4cc);
      lVar12 = (ulonglong)extraout_r1 << 0x20;
      bVar1 = **(byte **)(unaff_r7 + 0x2c);
      if (bVar1 != uVar7) {
        lVar12 = FUN_00005980(0);
      }
      uVar11 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar11 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      if ((uint)bVar1 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
        FUN_0000596a((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),uVar11);
      }
      **(char **)(unaff_r7 + 0x2c) = bVar1 - (char)uVar7;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar11 & 1) == 1);
      }
    }
LAB_00005012:
    iVar4 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) + (**(uint **)(unaff_r7 + 0x40) & 0xffff)
    ;
    *(int *)(unaff_r7 + 0x34) = iVar4;
    uVar11 = _DAT_20000b0c;
    uVar7 = iVar4 - *(int *)(unaff_r7 + 0x28);
    iVar4 = _DAT_20000808 + 1;
    iVar9 = _DAT_20000b14 + uVar7;
    if (uVar7 < 0x10000) {
      uVar7 = uVar7 * uVar7 + 0xff >> 8;
LAB_0000506c:
      uVar7 = uVar7 + _DAT_20000b18;
      if (uVar7 < _DAT_20000b18) {
        uVar7 = 0xffffffff;
      }
    }
    else {
      if (uVar7 < 0x100000) {
        uVar7 = (uVar7 + 0xff >> 8) * uVar7;
        goto LAB_0000506c;
      }
      uVar7 = 0xffffffff;
    }
    unaff_r4 = &DAT_20000b18;
    _DAT_20000808 = iVar4;
    _DAT_20000b14 = iVar9;
    _DAT_20000b18 = uVar7;
    if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
      FUN_00004652();
      iVar4 = extraout_r1_00;
    }
    FUN_00003fec(0x800c16c,iVar4,iVar9);
    if (*(uint *)(unaff_r7 + 0x34) < uVar11) {
      _DAT_20000b10 = _DAT_20000b10 + 1;
    }
    _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
    _DAT_20000b18 = 0;
    _DAT_20000b14 = 0;
    _DAT_20000808 = 0;
    if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_00004660();
    }
  } while( true );
}




/* WARNING: Removing unreachable block (ram,0x00005006) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000050fc(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  uint extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  byte *pbVar5;
  undefined4 uVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int unaff_r4;
  undefined4 *puVar12;
  undefined *unaff_r6;
  int unaff_r7;
  undefined4 unaff_r8;
  undefined4 *unaff_r9;
  uint in_r12;
  longlong lVar13;
  ulonglong uVar14;
  
  puVar12 = (undefined4 *)(param_3 - 1U & 0xff);
  do {
    if (*(byte *)(unaff_r4 + (int)puVar12) != in_r12) {
      FUN_00004820(param_1,param_2,(uint)puVar12 & 0xff,param_4);
      iVar4 = extraout_r1_01;
      goto LAB_000051d4;
    }
    puVar12 = (undefined4 *)((int)puVar12 + -1);
  } while ('\0' < (char)puVar12);
  uVar10 = param_4;
  FUN_00004820(param_1,param_2,param_3);
  do {
    *(uint *)(unaff_r7 + 0x60) = uVar10;
    FUN_000022b0(*(undefined4 *)(unaff_r4 + 0x18),1,4,unaff_r7 + 0x60);
    uVar10 = *(uint *)(unaff_r7 + 0x60);
    FUN_00002244(unaff_r4,unaff_r8,
                 uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                 uVar10 >> 0x18,uVar10 >> 0x18 & 7);
LAB_00004c7c:
    do {
      unaff_r4 = FUN_000033d4(unaff_r6,0x80037f9);
      if (unaff_r4 == 0) {
LAB_00004d48:
        iVar4 = FUN_0000617c(0x20000068);
        if (iVar4 != 0) {
          puVar7 = (undefined *)(unaff_r7 + 0x5f);
          *puVar7 = 0xff;
          while (iVar4 = FUN_000033d4(puVar7,0x80037c5), iVar4 != 0) {
            if ((*(byte *)(iVar4 + 0x18) & 4) != 0) {
              if ((int)((uint)*(byte *)(iVar4 + 0x18) << 0x1f) < 0) {
                FUN_000061a0(iVar4);
                *(undefined *)(iVar4 + 0x18) = 2;
                *(undefined2 *)(unaff_r7 + 0x60) = 0x82d;
                FUN_000022b0(*(undefined4 *)(iVar4 + 0x10),0,2,unaff_r7 + 0x60);
                disableIRQinterrupts();
                *(uint *)(iVar4 + 8) =
                     (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                     (**(uint **)(unaff_r7 + 0x40) & 0xffff) + *(int *)(iVar4 + 0xc);
                FUN_000061fc(iVar4);
                enableIRQinterrupts();
              }
              else {
                FUN_00002478(iVar4,*puVar7);
              }
            }
          }
        }
        iVar4 = FUN_0000617c(0x20000794);
        if (iVar4 != 0) {
          *(undefined *)(unaff_r7 + 0x60) = 0xff;
          while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004d71), iVar4 != 0) {
            if ((*(byte *)(iVar4 + 0x11) & 8) != 0) {
              disableIRQinterrupts();
              *(byte *)(iVar4 + 0x11) = *(byte *)(iVar4 + 0x11) & 0xf7;
              enableIRQinterrupts();
              FUN_00003fec(0x800c134,*(undefined *)(unaff_r7 + 0x60),*(byte *)(iVar4 + 0x13) >> 3,
                           iVar4 + 0x20);
            }
          }
        }
        iVar4 = FUN_0000617c(0x200001f4);
        if (iVar4 != 0) {
          *(undefined *)(unaff_r7 + 0x60) = 0xff;
          while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004c55), iVar4 != 0) {
            if ((*(byte *)(iVar4 + 0x20) & 1) != 0) {
              disableIRQinterrupts();
              *(byte *)(iVar4 + 0x20) = *(byte *)(iVar4 + 0x20) & 0xfe;
              enableIRQinterrupts();
              FUN_00003fec(0x800c144,*(undefined *)(unaff_r7 + 0x60),*(undefined4 *)(iVar4 + 8),
                           *(undefined4 *)(iVar4 + 0x18));
            }
          }
        }
        iVar4 = FUN_0000617c(0x200001f0);
        if (iVar4 != 0) {
          *(undefined *)(unaff_r7 + 0x60) = 0xff;
          while (iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8003795), iVar4 != 0) {
            if (*(char *)(iVar4 + 0x1c) == -1) {
              disableIRQinterrupts();
              if (*(char *)(iVar4 + 0x12) == '\0') {
                enableIRQinterrupts();
              }
              else {
                *(undefined *)(iVar4 + 0x1c) = *(undefined *)(iVar4 + 0x1d);
                enableIRQinterrupts();
                FUN_00003fec(0x800c14c,*(undefined *)(unaff_r7 + 0x60),*(undefined *)(iVar4 + 0x1b))
                ;
              }
            }
          }
        }
        uRam40003000 = 0xaaaa;
        iVar8 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                (**(uint **)(unaff_r7 + 0x40) & 0xffff);
        disableIRQinterrupts();
        iVar4 = **(int **)(unaff_r7 + 4);
        *(int *)(unaff_r7 + 0x50) = iVar4;
        if (iVar4 - iVar8 < 0) {
          **(int **)(unaff_r7 + 4) = iVar8;
        }
        enableIRQinterrupts();
        uVar10 = (uint)**(byte **)(unaff_r7 + 0x2c);
        if (uVar10 != 0) {
          uVar11 = (uint)**(byte **)(unaff_r7 + 0x30);
          if (-1 < (int)(uVar11 << 0x1f)) {
            if (uVar10 < 5) goto LAB_00005012;
            pbVar5 = *(byte **)(unaff_r7 + 0x1c);
            uVar9 = (uint)*pbVar5;
            if ((uVar9 - 5 < 0x3c) && ((pbVar5[1] & 0xf0) == 0x10)) {
              if (uVar10 < uVar9) goto LAB_00005012;
              if (pbVar5[uVar9 - 1] == 0x7e) {
                    /* WARNING: Subroutine does not return */
                FUN_000059f2();
              }
            }
            if (uVar9 == 0x7e) {
                    /* WARNING: Subroutine does not return */
              FUN_00004fce();
            }
            uVar11 = uVar11 | 1;
            **(undefined **)(unaff_r7 + 0x30) = (char)uVar11;
          }
          iVar4 = FUN_00008e08(0x20000528,0x7e,uVar10);
          if (iVar4 == 0) {
            iVar4 = FUN_000059aa();
          }
          bVar1 = (byte)(uVar11 & 0xfffffffe);
          **(byte **)(unaff_r7 + 0x30) = bVar1;
          uVar10 = (iVar4 - *(int *)(unaff_r7 + 0x1c)) + 1;
          if ((int)((uVar11 & 0xfffffffe) << 0x1e) < 0) {
            FUN_000059a2();
          }
          **(byte **)(unaff_r7 + 0x30) = bVar1 | 2;
          FUN_00003fec(0x800d4cc);
          lVar13 = (ulonglong)extraout_r1 << 0x20;
          bVar1 = **(byte **)(unaff_r7 + 0x2c);
          if (bVar1 != uVar10) {
            lVar13 = FUN_00005980(0);
          }
          uVar11 = 0;
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            uVar11 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          if ((uint)bVar1 != (uint)**(byte **)(unaff_r7 + 0x2c)) {
            FUN_0000596a((int)lVar13,(int)((ulonglong)lVar13 >> 0x20),uVar11);
          }
          **(char **)(unaff_r7 + 0x2c) = bVar1 - (char)uVar10;
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            enableIRQinterrupts((uVar11 & 1) == 1);
          }
        }
LAB_00005012:
        unaff_r9 = (undefined4 *)&DAT_20000808;
        iVar4 = (_DAT_40000424 ^ **(uint **)(unaff_r7 + 0x40)) +
                (**(uint **)(unaff_r7 + 0x40) & 0xffff);
        *(int *)(unaff_r7 + 0x34) = iVar4;
        uVar10 = iVar4 - *(int *)(unaff_r7 + 0x28);
        iVar4 = _DAT_20000808 + 1;
        puVar12 = (undefined4 *)&DAT_20000b14;
        param_3 = _DAT_20000b14 + uVar10;
        _DAT_20000808 = iVar4;
        _DAT_20000b14 = param_3;
        if (uVar10 < 0x10000) {
          uVar10 = uVar10 * uVar10 + 0xff >> 8;
        }
        else {
          if (0xfffff < uVar10) {
LAB_000051d4:
            uVar10 = 0xffffffff;
            goto LAB_00005074;
          }
          uVar10 = (uVar10 + 0xff >> 8) * uVar10;
        }
        uVar10 = uVar10 + _DAT_20000b18;
        if (uVar10 < _DAT_20000b18) {
          uVar10 = 0xffffffff;
        }
LAB_00005074:
        uVar11 = _DAT_20000b0c;
        _DAT_20000b18 = uVar10;
        if ((int)((*(int *)(unaff_r7 + 0x34) - _DAT_20000b0c) + -360000000) < 0) {
          FUN_00004652();
          iVar4 = extraout_r1_00;
        }
        FUN_00003fec(0x800c16c,iVar4,param_3);
        if (*(uint *)(unaff_r7 + 0x34) < uVar11) {
          _DAT_20000b10 = _DAT_20000b10 + 1;
        }
        _DAT_20000b0c = *(uint *)(unaff_r7 + 0x34);
        _DAT_20000b18 = 0;
        *puVar12 = 0;
        *unaff_r9 = 0;
        if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') {
                    /* WARNING: Subroutine does not return */
          FUN_00004660();
        }
        *(undefined4 *)(unaff_r7 + 0x28) = *(undefined4 *)(unaff_r7 + 0x34);
        uVar14 = FUN_000046b4();
        do {
          iVar4 = (int)uVar14;
          uVar2 = *(undefined2 *)(iVar4 + 0x18);
          uVar6 = *(undefined4 *)(iVar4 + 0x14);
          (&DAT_20000b18)[iVar4] = (char)(uVar14 >> 0x20) + '\x01';
          enableIRQinterrupts();
          FUN_00003fec(0x800c10c,*(undefined *)(unaff_r7 + 0x60),uVar6,uVar2);
          while( true ) {
            do {
              iVar4 = FUN_000033d4(unaff_r7 + 0x60,0x8004bc9);
              if (iVar4 == 0) {
                iVar4 = FUN_0000617c(0x20000788);
                if (iVar4 == 0) goto LAB_00004d48;
                unaff_r6 = (undefined *)(unaff_r7 + 0x5f);
                unaff_r9 = (undefined4 *)0x1;
                param_4 = 1;
                *unaff_r6 = 0xff;
                goto LAB_00004c7c;
              }
            } while ((&DAT_20000b18)[iVar4] != *(char *)(iVar4 + 0x27));
            disableIRQinterrupts();
            uVar14 = (ulonglong)CONCAT14(*(char *)(iVar4 + 0x27),iVar4);
            if (*(char *)(iVar4 + 0x27) == (&DAT_20000b18)[iVar4]) break;
            enableIRQinterrupts();
          }
        } while( true );
      }
    } while (((uint)unaff_r9 & (uint)*(byte *)(unaff_r4 + 0x1f)) == 0);
    disableIRQinterrupts();
    unaff_r8 = *(undefined4 *)(unaff_r4 + 8);
    *(byte *)(unaff_r4 + 0x1f) = *(byte *)(unaff_r4 + 0x1f) & 0xfe;
    enableIRQinterrupts();
    bVar1 = *(byte *)(unaff_r4 + 0x1e);
    if (bVar1 == 2) {
      *(uint *)(unaff_r7 + 0x60) = param_4;
      FUN_000022b0(*(undefined4 *)(unaff_r4 + 0x18),1,3,unaff_r7 + 0x60);
      uVar10 = *(uint *)(unaff_r7 + 0x60);
      *(undefined2 *)(unaff_r7 + 0x60) = 7;
      FUN_000022b0(*(undefined4 *)(unaff_r4 + 0x18),1,2,unaff_r7 + 0x60);
      uVar10 = (((uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8) << 8) >> 0x10;
      FUN_00002244(unaff_r4,unaff_r8,uVar10,
                   *(byte *)(unaff_r7 + 0x61) & 0xfffffffc | param_4 & uVar10);
      goto LAB_00004c7c;
    }
    if (2 < bVar1) {
      if (bVar1 == 3) {
        *(undefined2 *)(unaff_r7 + 0x60) = 0;
        FUN_000022b0(*(undefined4 *)(unaff_r4 + 0x18),1,2,unaff_r7 + 0x60);
        uVar10 = (uint)(*(ushort *)(unaff_r7 + 0x60) >> 8);
        FUN_00002244(unaff_r4,unaff_r8,(*(ushort *)(unaff_r7 + 0x60) & 0xff) << 8 | uVar10,
                     uVar10 & 6);
      }
      goto LAB_00004c7c;
    }
    if (bVar1 != 0) {
      *(undefined4 *)(unaff_r7 + 0x60) = 0xc;
      FUN_000022b0(*(undefined4 *)(unaff_r4 + 0x18),1,4,unaff_r7 + 0x60);
      uVar10 = *(uint *)(unaff_r7 + 0x60);
      *(undefined2 *)(unaff_r7 + 0x60) = 0xf;
      FUN_000022b0(*(undefined4 *)(unaff_r4 + 0x18),1,2,unaff_r7 + 0x60);
      FUN_00002244(unaff_r4,unaff_r8,
                   (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 | uVar10 >> 0x18,
                   *(undefined *)(unaff_r7 + 0x61));
      goto LAB_00004c7c;
    }
    uVar10 = 0;
  } while( true );
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000051ec(void)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined *puVar12;
  undefined4 *puVar13;
  ushort uVar14;
  int iVar15;
  undefined4 *puVar16;
  uint uVar17;
  undefined4 uVar18;
  int unaff_r7;
  undefined8 uVar19;
  
  *(undefined *)(*(int *)(unaff_r7 + 0x38) + 8) = 0xff;
  *(undefined **)(unaff_r7 + 0x3c) = &DAT_200005f0;
LAB_00005208:
  enableIRQinterrupts();
  FUN_00008fe8(unaff_r7 + 0x60,0,0x10);
  sVar1 = _DAT_200004f6;
  uVar18 = _DAT_2000003c;
  uVar7 = _DAT_20000038;
  if (_DAT_200004f6 == 0) goto LAB_00005706;
  if (_DAT_20000222 != 0) {
    _DAT_20000218 = _DAT_20000038;
    _DAT_2000021c = _DAT_2000003c;
    uVar19 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000210,_DAT_20000214);
    *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
    uVar8 = FUN_00006ce4(sVar1);
    FUN_0000642c(uVar8,0x447a0000);
    uVar19 = FUN_00008a60();
    iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                         (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    if (iVar9 != 0) goto LAB_00005536;
    _DAT_20000210 = uVar7;
    _DAT_20000214 = uVar18;
  }
  iVar15 = FUN_00002ea4(unaff_r7 + 0x60);
  iVar9 = _DAT_20000248;
  if (iVar15 == 0) goto LAB_00005536;
  iVar15 = _DAT_20000248 % 0x20;
  FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
  uVar7 = FUN_00006368();
  *(undefined4 *)(&DAT_2000024c + iVar15 * 4) = uVar7;
  _DAT_200004ea = _DAT_20000220;
  uVar17 = (uint)_DAT_20000220;
  _DAT_20000248 = iVar9 + 1;
  if (uVar17 == 0) {
    if (_DAT_20000222 != 0) goto LAB_00005536;
    _DAT_200004ea = _DAT_20000222;
    goto LAB_00005536;
  }
  puVar11 = (undefined4 *)(unaff_r7 + 0x60);
  iVar9 = 0;
  piVar4 = (int *)&DAT_200002cc;
  do {
    iVar10 = *piVar4;
    iVar15 = iVar9 * 0x21;
    uVar7 = *puVar11;
    puVar11 = puVar11 + 1;
    iVar9 = iVar9 + 1;
    *(undefined4 *)(&DAT_20000210 + (iVar15 + iVar10 % 0x20 + 0x30) * 4) = uVar7;
    *piVar4 = iVar10 + 1;
    piVar4 = piVar4 + 0x21;
  } while (iVar9 < (int)uVar17);
  if (_DAT_20000222 == 0) {
    _DAT_200004ea = _DAT_20000222;
    uVar17 = 0;
    *(undefined4 *)(unaff_r7 + 0x44) = 0;
LAB_00005824:
    do {
      puVar11 = (undefined4 *)FUN_00002a78(uVar17,0);
      uVar7 = puVar11[0x3f];
      *(undefined4 *)(unaff_r7 + 0x50) = puVar11[0x3e];
      *(undefined4 *)(unaff_r7 + 0x54) = uVar7;
      uVar3 = _DAT_20000508;
      uVar19 = FUN_00008a10(_DAT_20000508);
      iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                           (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      if (iVar9 == 0) {
LAB_0000588e:
        iVar9 = _DAT_200002cc;
        *(int *)(unaff_r7 + 0x28) = _DAT_200002cc;
        if (0x1f < iVar9) {
          uVar7 = puVar11[0x3c];
          uVar18 = puVar11[0x3d];
          *(undefined4 *)(unaff_r7 + 0x20) = uVar7;
          *(undefined4 *)(unaff_r7 + 0x24) = uVar18;
          iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                               uVar7,uVar18);
          if (iVar9 != 0) {
            puVar6 = puVar11 + 0x3a;
            uVar8 = puVar11[0x3b];
            *(undefined4 *)(unaff_r7 + 8) = *puVar6;
            *(undefined4 *)(unaff_r7 + 0xc) = uVar8;
            iVar9 = FUN_00006310(uVar7,uVar18);
            if (iVar9 != 0) {
              *(undefined4 *)(unaff_r7 + 0x28) = 0;
              do {
                uVar7 = *puVar11;
                uVar18 = puVar11[1];
                iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x50),
                                     *(undefined4 *)(unaff_r7 + 0x54),uVar7,uVar18);
                if ((iVar9 != 0) &&
                   (iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x20),
                                         *(undefined4 *)(unaff_r7 + 0x24),uVar7,uVar18), iVar9 != 0)
                   ) {
                  iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 8),*(undefined4 *)(unaff_r7 + 0xc)
                                       ,uVar7,uVar18);
                  *(uint *)(unaff_r7 + 0x28) = *(int *)(unaff_r7 + 0x28) + (uint)(iVar9 != 0);
                }
                puVar11 = puVar11 + 2;
              } while (puVar6 != puVar11);
              if (*(int *)(unaff_r7 + 0x28) == 0x1d) {
                uVar19 = FUN_00008a10(_DAT_20000504);
                iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),
                                     *(undefined4 *)(unaff_r7 + 0x54),(int)uVar19,
                                     (int)((ulonglong)uVar19 >> 0x20));
                if (iVar9 == 0) {
                  _DAT_200004ea = _DAT_200004ea | (ushort)(1 << (uVar17 & 0xff));
                  uVar17 = uVar17 + 1;
                  *(int *)(unaff_r7 + 0x44) = *(int *)(unaff_r7 + 0x44) + 1;
                  if ((int)(uint)_DAT_20000220 <= (int)uVar17) break;
                  goto LAB_00005824;
                }
              }
            }
          }
        }
      }
      else {
        uVar19 = FUN_00008a10(uVar3 >> 1);
        iVar9 = FUN_00006310(puVar11[0x3c],puVar11[0x3d],(int)uVar19,
                             (int)((ulonglong)uVar19 >> 0x20));
        if (iVar9 == 0) goto LAB_0000588e;
        uVar19 = FUN_00008a10(uVar3 / 3);
        iVar9 = FUN_00006310(puVar11[0x3a],puVar11[0x3b],(int)uVar19,
                             (int)((ulonglong)uVar19 >> 0x20));
        if (iVar9 == 0) goto LAB_0000588e;
        *(int *)(unaff_r7 + 0x44) = *(int *)(unaff_r7 + 0x44) + 1;
        _DAT_200004ea = _DAT_200004ea | (ushort)(1 << (uVar17 & 0xff));
      }
      uVar17 = uVar17 + 1;
    } while ((int)uVar17 < (int)(uint)_DAT_20000220);
  }
  else {
    _DAT_200004ea = 0;
    *(undefined4 *)(unaff_r7 + 0x44) = 0;
    *(undefined4 *)(unaff_r7 + 0x50) = 0;
    do {
      iVar15 = FUN_00002a78(*(undefined4 *)(unaff_r7 + 0x50),0);
      iVar9 = _DAT_20000504;
      *(int *)(unaff_r7 + 0x28) = _DAT_20000504;
      if (iVar9 == 0) {
LAB_000057e8:
        *(int *)(unaff_r7 + 0x44) = *(int *)(unaff_r7 + 0x44) + 1;
        _DAT_200004ea = (ushort)(1 << (*(uint *)(unaff_r7 + 0x50) & 0xff)) | _DAT_200004ea;
      }
      else {
        uVar19 = FUN_00008a10(_DAT_20000508);
        iVar9 = *(int *)(unaff_r7 + 0x28);
        iVar10 = 0;
        puVar11 = (undefined4 *)(iVar15 + 0xf8);
        do {
          iVar5 = FUN_00006324(*puVar11,puVar11[1],(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
          puVar11 = puVar11 + -2;
          iVar10 = iVar10 + (uint)(iVar5 != 0);
        } while ((undefined4 *)(iVar15 + iVar9 * -8 + 0xf8) != puVar11);
        if (iVar10 == *(int *)(unaff_r7 + 0x28)) goto LAB_000057e8;
      }
      iVar9 = *(int *)(unaff_r7 + 0x50) + 1;
      *(int *)(unaff_r7 + 0x50) = iVar9;
    } while (iVar9 < (int)(uint)_DAT_20000220);
  }
  if (*(int *)(unaff_r7 + 0x44) < (int)(uint)_DAT_20000500) goto LAB_00005536;
  if (_DAT_200004ea == 0) goto LAB_00005536;
  _DAT_200004f6 = 0;
  FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
  _DAT_200004e0 = FUN_00006368();
  FUN_00001060(_DAT_20000780,1);
  iVar9 = 0;
  if (_DAT_20000220 != 0) {
    do {
      FUN_00002a78(iVar9,1);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)_DAT_20000220);
  }
  _DAT_200004dc = 0x10;
  do {
    iVar9 = _DAT_200004dc;
    uVar7 = FUN_00006ce4(_DAT_200004f4);
    uVar8 = FUN_0000642c(uVar7,0x447a0000);
    uVar18 = _DAT_2000003c;
    uVar7 = _DAT_20000038;
    _DAT_20000aa8 = _DAT_20000038;
    _DAT_20000aac = _DAT_2000003c;
    uVar19 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000aa0,_DAT_20000aa4);
    *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
    uVar19 = FUN_00008a60(uVar8);
    iVar15 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                          (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    if (iVar15 == 0) {
      _DAT_20000aa0 = uVar7;
      _DAT_20000aa4 = uVar18;
      _DAT_200004dc = iVar9 + -1;
      FUN_00003fec(0x800c1bc,DAT_20000208,(0xf - _DAT_200004dc) * 2,_DAT_200004e0);
    }
LAB_00005536:
    do {
      sVar1 = *(short *)(*(int *)(unaff_r7 + 0x3c) + 100);
      if (sVar1 != 0) {
        uVar7 = FUN_00006ce4(*(undefined2 *)(*(int *)(unaff_r7 + 0x3c) + 0x66));
        uVar8 = FUN_0000642c(uVar7,0x447a0000);
        uVar18 = _DAT_2000003c;
        uVar7 = _DAT_20000038;
        _DAT_20000aa8 = _DAT_20000038;
        _DAT_20000aac = _DAT_2000003c;
        uVar19 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000aa0,_DAT_20000aa4);
        *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
        uVar19 = FUN_00008a60(uVar8);
        iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                             (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        if (iVar9 == 0) {
          _DAT_20000aa0 = uVar7;
          _DAT_20000aa4 = uVar18;
          iVar9 = *(int *)(*(int *)(unaff_r7 + 0x3c) + 0xec);
          if (iVar9 != 0) {
            FUN_00008fe8(unaff_r7 + 0x60,0,0x80);
            puVar6 = (undefined4 *)(unaff_r7 + 0x60);
            puVar13 = (undefined4 *)(unaff_r7 + 0xe0);
            puVar11 = puVar6;
            do {
              iVar15 = iVar9 % 0x20;
              iVar9 = iVar9 + 1;
              *puVar11 = *(undefined4 *)(&DAT_200006e0 + iVar15 * 4);
              puVar11 = puVar11 + 1;
            } while (puVar13 != puVar11);
            puVar11 = (undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0xf0);
            puVar16 = (undefined4 *)(unaff_r7 + 0x60);
            do {
              uVar7 = *puVar16;
              puVar16 = puVar16 + 1;
              *puVar11 = uVar7;
              puVar11 = puVar11 + 1;
            } while (puVar13 != puVar16);
            iVar9 = *(int *)(unaff_r7 + 0x3c);
            *(undefined4 *)(iVar9 + 0xec) = 0;
            iVar9 = *(int *)(iVar9 + 0x68);
            puVar11 = (undefined4 *)(unaff_r7 + 0x60);
            do {
              iVar15 = iVar9 % 0x20;
              iVar9 = iVar9 + 1;
              *puVar11 = *(undefined4 *)(&DAT_2000065c + iVar15 * 4);
              puVar11 = puVar11 + 1;
            } while (puVar11 != puVar13);
            puVar11 = (undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x6c);
            do {
              uVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              *puVar11 = uVar7;
              puVar11 = puVar11 + 1;
            } while (puVar6 != puVar13);
            *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x68) = 0;
          }
          puVar12 = *(undefined **)(unaff_r7 + 0x3c);
          uVar14 = sVar1 - 1;
          *(ushort *)(puVar12 + 100) = uVar14;
          FUN_00003fec(0x800c1e4,*puVar12,(7 - (uint)uVar14) * 4,*(undefined4 *)(puVar12 + 0x60));
        }
      }
      if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) != '\0') goto LAB_00005208;
      FUN_00004688();
LAB_00005706:
      if (_DAT_200004e8 != 0) {
        if (_DAT_20000222 != 0) {
          uVar7 = FUN_00006ce4(_DAT_200004e4);
          uVar8 = FUN_0000642c(uVar7,0x447a0000);
          uVar18 = _DAT_2000003c;
          uVar7 = _DAT_20000038;
          _DAT_20000218 = _DAT_20000038;
          _DAT_2000021c = _DAT_2000003c;
          uVar19 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000210,_DAT_20000214);
          *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
          uVar19 = FUN_00008a60(uVar8);
          iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                               (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
          if (iVar9 != 0) goto LAB_00005536;
          _DAT_20000210 = uVar7;
          _DAT_20000214 = uVar18;
        }
        iVar9 = FUN_00002ea4(unaff_r7 + 0x60);
        if (iVar9 == 0) goto LAB_00005536;
        FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
        uVar7 = FUN_00006368();
        uVar2 = _DAT_20000208;
        *(undefined4 *)(unaff_r7 + 0x50) = *(undefined4 *)(unaff_r7 + 100);
        FUN_00003fec(0x800c1c4,uVar2,uVar7,*(undefined4 *)(unaff_r7 + 0x60));
        _DAT_200004e6 = _DAT_200004e6 + 1;
        if ((_DAT_200004e8 == _DAT_200004e6) && (_DAT_200004e8 = 0, _DAT_20000028 == 1)) {
          FUN_0000273c();
        }
      }
    } while (_DAT_200004dc == 0);
  } while( true );
}




void FUN_0000596a(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int unaff_r7;
  undefined unaff_r8;
  uint unaff_r10;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_3 & 1) == 1);
  }
  iVar2 = **(byte **)(unaff_r7 + 0x2c) - unaff_r10;
  if (**(byte **)(unaff_r7 + 0x2c) == unaff_r10) {
                    /* WARNING: Subroutine does not return */
    FUN_00004fe6();
  }
  FUN_00008f30(param_1 + 0x20000528,param_1 + unaff_r10 + 0x20000528,iVar2 - param_1);
  *(undefined *)(*(int *)(unaff_r7 + 0x38) + 8) = unaff_r8;
                    /* WARNING: Subroutine does not return */
  FUN_00004fe6(iVar2);
}




void FUN_00005980(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r6;
  int unaff_r7;
  undefined unaff_r8;
  
  FUN_00008f30(param_1 + 0x20000528,param_1 + param_4 + 0x20000528,unaff_r6 - param_1);
  *(undefined *)(*(int *)(unaff_r7 + 0x38) + 8) = unaff_r8;
                    /* WARNING: Subroutine does not return */
  FUN_00004fe6();
}




void FUN_000059a2(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_00004fce();
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000059aa(void)

{
  undefined2 uVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  undefined4 *puVar12;
  ushort uVar13;
  undefined4 *puVar14;
  undefined2 unaff_r4;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined2 *unaff_r6;
  int unaff_r7;
  uint uVar18;
  undefined8 uVar19;
  
  FUN_00004fae();
  do {
    if (unaff_r6[0xd] == 0) {
      unaff_r6[0x171] = 0;
    }
    else {
      unaff_r6[0x171] = unaff_r4;
    }
LAB_00005536:
    sVar2 = *(short *)(*(int *)(unaff_r7 + 0x3c) + 100);
    if (sVar2 != 0) {
      uVar7 = FUN_00006ce4(*(undefined2 *)(*(int *)(unaff_r7 + 0x3c) + 0x66));
      uVar8 = FUN_0000642c(uVar7,0x447a0000);
      uVar17 = _DAT_2000003c;
      uVar7 = _DAT_20000038;
      _DAT_20000aa8 = _DAT_20000038;
      _DAT_20000aac = _DAT_2000003c;
      uVar19 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000aa0,_DAT_20000aa4);
      *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
      uVar19 = FUN_00008a60(uVar8);
      iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                           (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      if (iVar9 == 0) {
        _DAT_20000aa0 = uVar7;
        _DAT_20000aa4 = uVar17;
        iVar9 = *(int *)(*(int *)(unaff_r7 + 0x3c) + 0xec);
        if (iVar9 != 0) {
          FUN_00008fe8(unaff_r7 + 0x60,0,0x80);
          puVar6 = (undefined4 *)(unaff_r7 + 0x60);
          puVar12 = (undefined4 *)(unaff_r7 + 0xe0);
          puVar16 = puVar6;
          do {
            iVar5 = iVar9 % 0x20;
            iVar9 = iVar9 + 1;
            *puVar16 = *(undefined4 *)(&DAT_200006e0 + iVar5 * 4);
            puVar16 = puVar16 + 1;
          } while (puVar12 != puVar16);
          puVar16 = (undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0xf0);
          puVar14 = (undefined4 *)(unaff_r7 + 0x60);
          do {
            uVar7 = *puVar14;
            puVar14 = puVar14 + 1;
            *puVar16 = uVar7;
            puVar16 = puVar16 + 1;
          } while (puVar12 != puVar14);
          iVar9 = *(int *)(unaff_r7 + 0x3c);
          *(undefined4 *)(iVar9 + 0xec) = 0;
          iVar9 = *(int *)(iVar9 + 0x68);
          puVar16 = (undefined4 *)(unaff_r7 + 0x60);
          do {
            iVar5 = iVar9 % 0x20;
            iVar9 = iVar9 + 1;
            *puVar16 = *(undefined4 *)(&DAT_2000065c + iVar5 * 4);
            puVar16 = puVar16 + 1;
          } while (puVar16 != puVar12);
          puVar16 = (undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x6c);
          do {
            uVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            *puVar16 = uVar7;
            puVar16 = puVar16 + 1;
          } while (puVar6 != puVar12);
          *(undefined4 *)(*(int *)(unaff_r7 + 0x3c) + 0x68) = 0;
        }
        puVar11 = *(undefined **)(unaff_r7 + 0x3c);
        uVar13 = sVar2 - 1;
        *(ushort *)(puVar11 + 100) = uVar13;
        FUN_00003fec(0x800c1e4,*puVar11,(7 - (uint)uVar13) * 4,*(undefined4 *)(puVar11 + 0x60));
      }
    }
    if (*(char *)(*(int *)(unaff_r7 + 0x38) + 8) == '\0') {
      FUN_00004688();
LAB_00005706:
      if (unaff_r6[0x170] != 0) {
        if (unaff_r6[0xd] != 0) break;
        goto LAB_00005768;
      }
      goto LAB_000057d0;
    }
    enableIRQinterrupts();
    FUN_00008fe8(unaff_r7 + 0x60,0,0x10);
    uVar17 = _DAT_2000003c;
    uVar7 = _DAT_20000038;
    sVar2 = unaff_r6[0x177];
    if (sVar2 == 0) goto LAB_00005706;
    if (unaff_r6[0xd] != 0) {
      *(undefined4 *)(unaff_r6 + 8) = _DAT_20000038;
      *(undefined4 *)(unaff_r6 + 10) = uVar17;
      uVar19 = FUN_00008208(uVar7,uVar17,*(undefined4 *)(unaff_r6 + 4),*(undefined4 *)(unaff_r6 + 6)
                           );
      *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
      uVar8 = FUN_00006ce4(sVar2);
      FUN_0000642c(uVar8,0x447a0000);
      uVar19 = FUN_00008a60();
      iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                           (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      if (iVar9 != 0) goto LAB_00005536;
      *(undefined4 *)(unaff_r6 + 4) = uVar7;
      *(undefined4 *)(unaff_r6 + 6) = uVar17;
    }
    iVar9 = FUN_00002ea4(unaff_r7 + 0x60);
    if (iVar9 == 0) goto LAB_00005536;
    iVar9 = *(int *)(unaff_r6 + 0x20);
    FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
    uVar7 = FUN_00006368();
    *(undefined4 *)(&DAT_2000024c + (iVar9 % 0x20) * 4) = uVar7;
    uVar13 = unaff_r6[0xc];
    *(int *)(unaff_r6 + 0x20) = iVar9 + 1;
    if (uVar13 != 0) {
      puVar16 = (undefined4 *)(unaff_r7 + 0x60);
      iVar9 = 0;
      piVar3 = (int *)(unaff_r6 + 0x62);
      do {
        iVar10 = *piVar3;
        iVar5 = iVar9 * 0x21;
        uVar7 = *puVar16;
        puVar16 = puVar16 + 1;
        iVar9 = iVar9 + 1;
        *(undefined4 *)(&DAT_20000210 + (iVar5 + iVar10 % 0x20 + 0x30) * 4) = uVar7;
        *piVar3 = iVar10 + 1;
        piVar3 = piVar3 + 0x21;
      } while (iVar9 < (int)(uint)uVar13);
      if (unaff_r6[0xd] == 0) {
        unaff_r6[0x171] = 0;
        uVar18 = 0;
        *(undefined4 *)(unaff_r7 + 0x44) = 0;
        do {
          while( true ) {
            puVar16 = (undefined4 *)FUN_00002a78(uVar18,0);
            uVar7 = puVar16[0x3f];
            *(undefined4 *)(unaff_r7 + 0x50) = puVar16[0x3e];
            *(undefined4 *)(unaff_r7 + 0x54) = uVar7;
            uVar15 = *(uint *)(unaff_r6 + 0x180);
            uVar19 = FUN_00008a10(uVar15);
            iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                                 (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
            if (iVar9 == 0) break;
            uVar19 = FUN_00008a10(uVar15 >> 1);
            iVar9 = FUN_00006310(puVar16[0x3c],puVar16[0x3d],(int)uVar19,
                                 (int)((ulonglong)uVar19 >> 0x20));
            if (iVar9 == 0) break;
            uVar19 = FUN_00008a10(uVar15 / 3);
            iVar9 = FUN_00006310(puVar16[0x3a],puVar16[0x3b],(int)uVar19,
                                 (int)((ulonglong)uVar19 >> 0x20));
            if (iVar9 == 0) break;
            *(int *)(unaff_r7 + 0x44) = *(int *)(unaff_r7 + 0x44) + 1;
            unaff_r6[0x171] = unaff_r6[0x171] | (ushort)(1 << (uVar18 & 0xff));
LAB_00005814:
            uVar18 = uVar18 + 1;
            if ((int)(uint)(ushort)unaff_r6[0xc] <= (int)uVar18) goto LAB_000053b8;
          }
          iVar9 = *(int *)(unaff_r6 + 0x62);
          *(int *)(unaff_r7 + 0x28) = iVar9;
          if (iVar9 < 0x20) goto LAB_00005814;
          uVar7 = puVar16[0x3c];
          uVar17 = puVar16[0x3d];
          *(undefined4 *)(unaff_r7 + 0x20) = uVar7;
          *(undefined4 *)(unaff_r7 + 0x24) = uVar17;
          iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                               uVar7,uVar17);
          if (iVar9 == 0) goto LAB_00005814;
          puVar6 = puVar16 + 0x3a;
          uVar8 = puVar16[0x3b];
          *(undefined4 *)(unaff_r7 + 8) = *puVar6;
          *(undefined4 *)(unaff_r7 + 0xc) = uVar8;
          iVar9 = FUN_00006310(uVar7,uVar17);
          if (iVar9 == 0) goto LAB_00005814;
          *(undefined4 *)(unaff_r7 + 0x28) = 0;
          do {
            uVar7 = *puVar16;
            uVar17 = puVar16[1];
            iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                                 uVar7,uVar17);
            if ((iVar9 != 0) &&
               (iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 0x20),
                                     *(undefined4 *)(unaff_r7 + 0x24),uVar7,uVar17), iVar9 != 0)) {
              iVar9 = FUN_00006310(*(undefined4 *)(unaff_r7 + 8),*(undefined4 *)(unaff_r7 + 0xc),
                                   uVar7,uVar17);
              *(uint *)(unaff_r7 + 0x28) = *(int *)(unaff_r7 + 0x28) + (uint)(iVar9 != 0);
            }
            puVar16 = puVar16 + 2;
          } while (puVar6 != puVar16);
          if (*(int *)(unaff_r7 + 0x28) != 0x1d) goto LAB_00005814;
          uVar19 = FUN_00008a10(*(undefined4 *)(unaff_r6 + 0x17e));
          iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                               (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
          if (iVar9 != 0) goto LAB_00005814;
          unaff_r6[0x171] = unaff_r6[0x171] | (ushort)(1 << (uVar18 & 0xff));
          uVar18 = uVar18 + 1;
          *(int *)(unaff_r7 + 0x44) = *(int *)(unaff_r7 + 0x44) + 1;
        } while ((int)uVar18 < (int)(uint)(ushort)unaff_r6[0xc]);
      }
      else {
        unaff_r6[0x171] = 0;
        *(undefined4 *)(unaff_r7 + 0x44) = 0;
        *(undefined4 *)(unaff_r7 + 0x50) = 0;
        do {
          iVar9 = FUN_00002a78(*(undefined4 *)(unaff_r7 + 0x50),0);
          iVar5 = *(int *)(unaff_r6 + 0x17e);
          *(int *)(unaff_r7 + 0x28) = iVar5;
          if (iVar5 == 0) {
LAB_000057e8:
            *(int *)(unaff_r7 + 0x44) = *(int *)(unaff_r7 + 0x44) + 1;
            uVar13 = (ushort)(1 << (*(uint *)(unaff_r7 + 0x50) & 0xff)) | unaff_r6[0x171];
          }
          else {
            uVar19 = FUN_00008a10(*(undefined4 *)(unaff_r6 + 0x180));
            iVar5 = *(int *)(unaff_r7 + 0x28);
            iVar10 = 0;
            puVar16 = (undefined4 *)(iVar9 + 0xf8);
            do {
              iVar4 = FUN_00006324(*puVar16,puVar16[1],(int)uVar19,(int)((ulonglong)uVar19 >> 0x20))
              ;
              puVar16 = puVar16 + -2;
              iVar10 = iVar10 + (uint)(iVar4 != 0);
            } while ((undefined4 *)(iVar9 + iVar5 * -8 + 0xf8) != puVar16);
            if (iVar10 == *(int *)(unaff_r7 + 0x28)) goto LAB_000057e8;
            uVar13 = unaff_r6[0x171];
          }
          unaff_r6[0x171] = uVar13;
          iVar9 = *(int *)(unaff_r7 + 0x50) + 1;
          *(int *)(unaff_r7 + 0x50) = iVar9;
        } while (iVar9 < (int)(uint)(ushort)unaff_r6[0xc]);
      }
LAB_000053b8:
      if (((int)(uint)(ushort)unaff_r6[0x17c] <= *(int *)(unaff_r7 + 0x44)) &&
         (unaff_r6[0x171] != 0)) {
        unaff_r6[0x177] = 0;
        FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
        uVar7 = FUN_00006368();
        *(undefined4 *)(unaff_r6 + 0x16c) = uVar7;
        FUN_00001060(_DAT_20000780,1);
        iVar9 = 0;
        if (unaff_r6[0xc] != 0) {
          do {
            FUN_00002a78(iVar9,1);
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)(ushort)unaff_r6[0xc]);
        }
        iVar9 = 0x10;
        *(undefined4 *)(unaff_r6 + 0x16a) = 0x10;
        goto LAB_0000542a;
      }
      goto LAB_00005536;
    }
    unaff_r4 = 0;
  } while( true );
  uVar7 = FUN_00006ce4(unaff_r6[0x16e]);
  uVar8 = FUN_0000642c(uVar7,0x447a0000);
  uVar17 = _DAT_2000003c;
  uVar7 = _DAT_20000038;
  *(undefined4 *)(unaff_r6 + 8) = _DAT_20000038;
  *(undefined4 *)(unaff_r6 + 10) = uVar17;
  uVar19 = FUN_00008208(uVar7,uVar17,*(undefined4 *)(unaff_r6 + 4),*(undefined4 *)(unaff_r6 + 6));
  *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
  uVar19 = FUN_00008a60(uVar8);
  iVar9 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),(int)uVar19
                       ,(int)((ulonglong)uVar19 >> 0x20));
  if (iVar9 == 0) {
    *(undefined4 *)(unaff_r6 + 4) = uVar7;
    *(undefined4 *)(unaff_r6 + 6) = uVar17;
LAB_00005768:
    iVar9 = FUN_00002ea4(unaff_r7 + 0x60);
    if (iVar9 != 0) {
      FUN_00007cfc(_DAT_20000038,_DAT_2000003c,0,0x40c38800);
      uVar7 = FUN_00006368();
      uVar1 = *unaff_r6;
      *(undefined4 *)(unaff_r7 + 0x50) = *(undefined4 *)(unaff_r7 + 100);
      FUN_00003fec(0x800c1c4,uVar1,uVar7,*(undefined4 *)(unaff_r7 + 0x60));
      sVar2 = unaff_r6[0x16f];
      unaff_r6[0x16f] = sVar2 + 1;
      if ((unaff_r6[0x170] == (short)(sVar2 + 1)) && (unaff_r6[0x170] = 0, _DAT_20000028 == 1)) {
        FUN_0000273c();
      }
LAB_000057d0:
      iVar9 = *(int *)(unaff_r6 + 0x16a);
      if (iVar9 != 0) {
LAB_0000542a:
        uVar7 = FUN_00006ce4(unaff_r6[0x176]);
        uVar8 = FUN_0000642c(uVar7,0x447a0000);
        uVar17 = _DAT_2000003c;
        uVar7 = _DAT_20000038;
        _DAT_20000aa8 = _DAT_20000038;
        _DAT_20000aac = _DAT_2000003c;
        uVar19 = FUN_00008208(_DAT_20000038,_DAT_2000003c,_DAT_20000aa0,_DAT_20000aa4);
        *(undefined8 *)(unaff_r7 + 0x50) = uVar19;
        uVar19 = FUN_00008a60(uVar8);
        iVar5 = FUN_000062e8(*(undefined4 *)(unaff_r7 + 0x50),*(undefined4 *)(unaff_r7 + 0x54),
                             (int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        if (iVar5 == 0) {
          _DAT_20000aa0 = uVar7;
          _DAT_20000aa4 = uVar17;
          *(int *)(unaff_r6 + 0x16a) = iVar9 + -1;
          FUN_00003fec(0x800c1bc,*(undefined *)unaff_r6,(0xf - (iVar9 + -1)) * 2,
                       *(undefined4 *)(unaff_r6 + 0x16c));
        }
      }
    }
  }
  goto LAB_00005536;
}




void FUN_000059f2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  byte *pbVar2;
  undefined *puVar3;
  undefined *extraout_r1;
  uint *puVar4;
  byte bVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  byte unaff_r4;
  byte *pbVar9;
  int unaff_r5;
  uint unaff_r6;
  int unaff_r7;
  int unaff_r10;
  undefined8 uVar10;
  
  *(int *)(unaff_r7 + 0x44) = unaff_r10 + 0x20000525;
  uVar1 = FUN_000020a0(param_3);
  puVar3 = *(undefined **)(unaff_r7 + 0x44);
  if (CONCAT11(*puVar3,*(undefined *)(DAT_00005ba8 + unaff_r10)) != uVar1) {
    FUN_00004f76();
    puVar3 = extraout_r1;
  }
  pbVar2 = *(byte **)(unaff_r7 + 0x10);
  uVar10 = CONCAT44(puVar3,pbVar2);
  **(byte **)(unaff_r7 + 0x30) = unaff_r4 & 0xfd;
  bVar5 = *pbVar2;
  uVar1 = (uint)bVar5;
  if (uVar1 != unaff_r6) {
    uVar10 = FUN_00004fbe();
    bVar5 = (byte)uVar1;
  }
  pbVar2 = DAT_00005bac;
  *(byte *)uVar10 = bVar5 + 1 & (byte)unaff_r5 | 0x10;
  if (pbVar2 < (byte *)((ulonglong)uVar10 >> 0x20)) {
    *(int *)(unaff_r7 + 0x14) = unaff_r10;
    do {
      pbVar9 = pbVar2 + 1;
      bVar5 = *pbVar2;
      *(uint *)(unaff_r7 + 0x3c) = (uint)bVar5;
      if (0x4b < bVar5 - 1) {
                    /* WARNING: Subroutine does not return */
        FUN_00003764(4);
      }
      *(int *)(unaff_r7 + 0x34) = *(int *)(unaff_r7 + 0x3c) * 2;
      iVar7 = *(int *)(unaff_r7 + 0x3c) * 0xc;
      bVar5 = *(byte *)(iVar7 + 0x800d09f);
      puVar4 = (uint *)((int)register0x00000054 +
                       (0x30 - ((uint)*(byte *)(iVar7 + 0x800d09d) * 4 + 7 & 0xfffffff8)));
      pbVar2 = *(byte **)(iVar7 + 0x800d0a0);
      *(uint **)(unaff_r7 + 0x18) = puVar4;
      if (bVar5 != 0) {
        pbVar6 = *(byte **)(unaff_r7 + 0x44);
        if (pbVar6 < pbVar9) {
LAB_00005b96:
                    /* WARNING: Subroutine does not return */
          FUN_00003764(6);
        }
        *(uint *)(unaff_r7 + 0x50) = bVar5 - 2;
        bVar5 = *pbVar2;
        *(BADSPACEBASE **)(unaff_r7 + 0x20) = register0x00000054;
        pbVar2 = pbVar2 + 1;
        if (4 < bVar5) goto LAB_00005b0c;
        while( true ) {
          bVar5 = *pbVar9;
          uVar1 = unaff_r5 + 0x70U & (uint)bVar5;
          if ((bVar5 & 0x60) == 0x60) {
            uVar1 = uVar1 | 0xffffffe0;
          }
          while (pbVar9 = pbVar9 + 1, (char)bVar5 < '\0') {
            bVar5 = *pbVar9;
            uVar1 = uVar1 << 7 | unaff_r5 + 0x70U & (uint)bVar5;
          }
          iVar7 = *(int *)(unaff_r7 + 0x50);
          *puVar4 = uVar1;
          if (iVar7 == -1) break;
          puVar4 = puVar4 + 1;
          if (pbVar6 < pbVar9) goto LAB_00005b96;
          while( true ) {
            *(int *)(unaff_r7 + 0x50) = *(int *)(unaff_r7 + 0x50) + -1;
            bVar5 = *pbVar2;
            pbVar2 = pbVar2 + 1;
            if (bVar5 < 5) break;
LAB_00005b0c:
            if (bVar5 != 7) goto LAB_00005b96;
            bVar5 = *pbVar9;
            pbVar8 = pbVar9 + 1;
            pbVar9 = pbVar8 + bVar5;
            if (pbVar6 < pbVar9) goto LAB_00005b96;
            puVar4[1] = (uint)pbVar8;
            iVar7 = *(int *)(unaff_r7 + 0x50);
            *puVar4 = (uint)bVar5;
            puVar4 = puVar4 + 2;
            if (iVar7 == -1) goto LAB_00005b2a;
          }
        }
LAB_00005b2a:
        register0x00000054 = *(BADSPACEBASE **)(unaff_r7 + 0x20);
      }
      if ((*(char *)(*(int *)(unaff_r7 + 0x38) + 9) == '\0') ||
         ((int)((uint)*(byte *)((*(int *)(unaff_r7 + 0x34) + *(int *)(unaff_r7 + 0x3c)) * 4 +
                               0x800d09e) << 0x1f) < 0)) {
        (**(code **)((*(int *)(unaff_r7 + 0x34) + *(int *)(unaff_r7 + 0x3c)) * 4 + 0x800d0a4))
                  (*(undefined4 *)(unaff_r7 + 0x18));
      }
      else {
        FUN_00003fec(0x800c15c,*(undefined *)(*(int *)(unaff_r7 + 0x38) + 10));
      }
      pbVar2 = pbVar9;
    } while (pbVar9 < *(byte **)(unaff_r7 + 0x44));
  }
                    /* WARNING: Subroutine does not return */
  FUN_00004fce();
}




char FUN_0000617c(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 != '\0') {
    cVar1 = '\x01';
    *param_1 = '\0';
  }
  return cVar1;
}




void FUN_0000618c(undefined *param_1)

{
  uRam20000008 = 0;
  *param_1 = 1;
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000061a0(undefined4 *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar3 = puRam20000000;
  if (puRam20000000 == param_1) {
    _DAT_20000050 = param_1[2];
    _DAT_20000048 = *param_1;
    puRam20000000 = (undefined4 *)&DAT_20000048;
LAB_000061c4:
    if (puRam20000004 != param_1) goto LAB_000061ca;
  }
  else {
    do {
      puVar2 = puVar3;
      puVar3 = (undefined4 *)*puVar2;
      if (puVar3 == (undefined4 *)0x0) goto LAB_000061c4;
    } while (puVar3 != param_1);
    *puVar2 = *param_1;
    if (puRam20000004 != param_1) goto LAB_000061ca;
  }
  puRam20000004 = (undefined4 *)0x2000000c;
LAB_000061ca:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}




/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_000061fc(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  bool bVar6;
  
  iVar2 = param_1[2];
  uVar5 = 0;
  bVar6 = (bool)isCurrentModePrivileged();
  if (bVar6) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar4 = puRam20000000;
  if (iVar2 - puRam20000000[2] < 0) {
    bVar6 = (int)(iVar2 - ((_DAT_2000078c & 0xffff) + (_DAT_40000424 ^ _DAT_2000078c))) < 0;
    if (bVar6) {
      iVar2 = (_DAT_40000424 ^ _DAT_2000078c) + (_DAT_2000078c & 0xffff) + 0x90;
      param_1[2] = iVar2;
    }
    if (puRam20000000 == (undefined4 *)&DAT_20000048) {
      puRam20000000 = _DAT_20000048;
    }
    *param_1 = puRam20000000;
    puRam20000000 = (undefined4 *)&DAT_20000048;
    _DAT_4000042c = _DAT_40000424 + 0x32;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    _DAT_20000048 = param_1;
    _DAT_20000050 = iVar2;
    if (bVar6) {
      FUN_00003fec(0x800c4dc);
    }
  }
  else {
    do {
      puVar3 = puVar4;
      puVar4 = (undefined4 *)*puVar3;
    } while (-1 < iVar2 - puVar4[2]);
    *param_1 = puVar4;
    *puVar3 = param_1;
    bVar6 = (bool)isCurrentModePrivileged();
    if (bVar6) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  return;
}




undefined4 FUN_000062e8(void)

{
  int iVar1;
  
  iVar1 = FUN_00007c24();
  if (-1 < iVar1) {
    return 0;
  }
  return 1;
}




undefined4 FUN_00006310(void)

{
  int iVar1;
  
  iVar1 = FUN_00007b44();
  if (iVar1 < 1) {
    return 0;
  }
  return 1;
}




undefined4 FUN_00006324(void)

{
  int iVar1;
  
  iVar1 = FUN_00007b44();
  if (iVar1 < 0) {
    return 0;
  }
  return 1;
}




int FUN_00006338(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00008c58(param_1,0x4f000000);
  if (iVar1 == 0) {
    iVar1 = FUN_00006c18(param_1);
  }
  else {
    FUN_00006884(param_1,0x4f000000);
    iVar1 = FUN_00006c18();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}




int FUN_00006368(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00006324(param_1,param_2,0,0x41e00000);
  if (iVar1 == 0) {
    iVar1 = FUN_00008948(param_1,param_2);
  }
  else {
    FUN_00008208(param_1,param_2,0,0x41e00000);
    iVar1 = FUN_00008948();
    iVar1 = iVar1 + -0x80000000;
  }
  return iVar1;
}




void FUN_000063a4(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = FUN_00008a60();
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  FUN_00007cfc((int)uVar2,uVar1,0,0x3df00000);
  FUN_00006368();
  uVar3 = FUN_00008a10();
  uVar3 = FUN_00007cfc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x41f00000);
  FUN_00008208((int)uVar2,uVar1,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  FUN_00006368();
  return;
}




void FUN_000063e4(uint param_1,uint param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if ((0x1fffff < param_2) && ((param_1 & 0x7ff) != 0)) {
    param_1 = param_1 & 0xfffff800 | 0x800;
  }
  uVar1 = FUN_00008a10(param_2);
  uVar1 = FUN_00007cfc((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x41f00000);
  uVar2 = FUN_00008a10(param_1);
  FUN_00006d5c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar1,(int)((ulonglong)uVar1 >> 0x20)
              );
  FUN_00008ae8();
  return;
}




void FUN_0000642c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_1 << 1) >> 0x18;
  param_1 = param_1 & 0x7fffff;
  if (uVar3 == 0) {
    if (param_1 == 0) {
      uVar3 = 4;
    }
    else {
      FUN_00008c6c(param_1);
      uVar3 = 0;
    }
  }
  else if (uVar3 == 0xff) {
    if (param_1 == 0) {
      uVar3 = 8;
    }
    else {
      uVar3 = 0xc;
    }
  }
  else {
    uVar3 = 0;
  }
  uVar2 = param_2 & 0x7fffff;
  uVar1 = (param_2 << 1) >> 0x18;
  if (uVar1 == 0) {
    if (uVar2 == 0) {
      uVar1 = 1;
LAB_00006502:
                    /* WARNING: Could not recover jumptable at 0x00006512. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(DAT_00006640 + (uVar3 | uVar1) * 4))();
      return;
    }
    FUN_00008c6c(uVar2);
    uVar1 = 0;
  }
  else if (uVar1 == 0xff) {
    if (uVar2 == 0) {
      uVar1 = 2;
      goto LAB_00006502;
    }
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00006490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_00006638 + (uVar3 | uVar1) * 4))();
  return;
}




uint FUN_00006644(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar5 = (param_1 << 1) >> 0x18;
  uVar4 = param_1 & 0x7fffff;
  if (uVar5 == 0) {
    if (uVar4 == 0) {
      uVar8 = 4;
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_00008c6c(uVar4);
      uVar4 = uVar4 << (iVar6 - 5U & 0xff);
      uVar8 = 0;
      iVar6 = -0x76 - iVar6;
    }
  }
  else if (uVar5 == 0xff) {
    if (uVar4 == 0) {
      uVar8 = 8;
      iVar6 = 0xff;
    }
    else {
      uVar8 = 0xc;
      iVar6 = 0xff;
    }
  }
  else {
    uVar8 = 0;
    uVar4 = uVar4 << 3 | 0x4000000;
    iVar6 = uVar5 - 0x7f;
  }
  uVar2 = param_2 & 0x7fffff;
  uVar5 = (param_2 << 1) >> 0x18;
  if (uVar5 == 0) {
    if (uVar2 == 0) {
      uVar8 = uVar8 | 1;
      uVar1 = 1;
    }
    else {
      iVar7 = FUN_00008c6c(uVar2);
      uVar2 = uVar2 << (iVar7 - 5U & 0xff);
      uVar1 = 0;
      iVar6 = (iVar6 - iVar7) + -0x76;
    }
  }
  else if (uVar5 == 0xff) {
    iVar6 = iVar6 + 0xff;
    if (uVar2 == 0) {
      uVar8 = uVar8 | 2;
      uVar1 = 2;
    }
    else {
      uVar8 = uVar8 | 3;
      uVar1 = 3;
    }
  }
  else {
    uVar2 = uVar2 << 3 | 0x4000000;
    uVar1 = 0;
    iVar6 = iVar6 + (uVar5 - 0x7f);
  }
  if (0xf < uVar8) {
    uVar5 = (uVar4 >> 0x10) * (uVar2 & 0xffff);
    uVar8 = (uVar4 & 0xffff) * (uVar2 & 0xffff);
    uVar3 = (uVar8 >> 0x10) + (uVar2 >> 0x10) * (uVar4 & 0xffff) + uVar5;
    iVar7 = (uVar2 >> 0x10) * (uVar4 >> 0x10);
    if (uVar3 <= uVar5 && uVar5 - uVar3 != 0) {
      iVar7 = iVar7 + 0x10000;
    }
    uVar5 = uVar3 * 0x10000 + (uVar8 & 0xffff);
    uVar4 = (uint)((uVar5 & 0x3ffffff) != 0);
    uVar5 = uVar5 >> 0x1a;
    iVar7 = (uVar3 >> 0x10) + iVar7;
    uVar8 = uVar4 | uVar5 | iVar7 * 0x40;
    if (iVar7 * 0x400 < 0) {
      uVar8 = uVar4 | uVar5 & 1 | uVar8 >> 1;
      iVar6 = iVar6 + 1;
    }
    uVar4 = iVar6 + 0x7f;
    if ((int)uVar4 < 1) {
      if ((int)(1 - uVar4) < 0x1c) {
        uVar5 = uVar8 >> (1 - uVar4 & 0xff);
        uVar4 = (uint)(uVar8 << (iVar6 + 0x9eU & 0xff) != 0);
        uVar8 = uVar4 | uVar5;
        if (((uVar4 | uVar5 & 7) != 0) && ((uVar4 | uVar5 & 0xf) != 4)) {
          uVar8 = uVar8 + 4;
        }
        if ((int)(uVar8 << 5) < 0) {
          uVar4 = 1;
          uVar5 = 0;
        }
        else {
          uVar4 = 0;
          uVar5 = (uVar8 << 6) >> 9;
        }
      }
      else {
        uVar4 = 0;
        uVar5 = 0;
      }
    }
    else {
      if (((uVar8 & 7) != 0) && ((uVar8 & 0xf) != 4)) {
        uVar8 = uVar8 + 4;
      }
      if ((int)(uVar8 << 4) < 0) {
        uVar4 = iVar6 + 0x80;
        uVar8 = uVar8 & DAT_00006880;
      }
      if ((int)uVar4 < 0xff) {
        uVar5 = (uVar8 << 6) >> 9;
        uVar4 = uVar4 & 0xff;
      }
      else {
        uVar4 = 0xff;
        uVar5 = 0;
      }
    }
    return uVar4 << 0x17 | uVar5 | (param_2 ^ param_1) & 0x80000000;
  }
                    /* WARNING: Could not recover jumptable at 0x000066b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (**(code **)(DAT_0000687c + uVar8 * 4))(uVar1);
  return uVar4;
}




uint FUN_00006884(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar7 = param_1 & 0x7fffff;
  uVar5 = uVar7 * 8;
  uVar10 = param_2 & 0x7fffff;
  uVar8 = (param_1 << 1) >> 0x18;
  uVar6 = (param_2 << 9) >> 6;
  uVar9 = -((int)param_1 >> 0x1f);
  uVar11 = (param_2 << 1) >> 0x18;
  uVar3 = -((int)param_2 >> 0x1f);
  uVar2 = uVar7;
  if (uVar11 == 0xff) {
    if (uVar6 == 0) {
      uVar4 = uVar3 ^ 1;
      if (uVar4 != uVar9) goto LAB_000068c4;
LAB_00006a32:
      uVar3 = uVar8 - 0xff;
LAB_00006a3a:
      if (uVar3 == 0) {
        uVar2 = uVar8 + 1;
        if ((uVar2 & 0xfe) == 0) {
          if (uVar8 != 0) {
            uVar2 = uVar10;
            if (uVar7 != 0) goto LAB_00006bc0;
            goto LAB_000069f2;
          }
          if ((uVar7 == 0) || (uVar10 = uVar7, uVar6 == 0)) goto LAB_00006956;
          uVar10 = uVar6 + uVar5;
          uVar8 = 0;
          if ((int)(uVar10 * 0x20) < 0) {
            uVar10 = uVar10 & DAT_00006c14;
            uVar8 = 1;
          }
        }
        else {
          if (uVar2 == 0xff) goto LAB_00006b0a;
          uVar10 = uVar6 + uVar5 >> 1;
          uVar8 = uVar2;
        }
LAB_00006af4:
        if ((uVar10 & 7) != 0) {
LAB_00006938:
          if ((uVar10 & 0xf) != 4) {
            uVar10 = uVar10 + 4;
          }
LAB_00006942:
          if ((int)(uVar10 << 5) < 0) {
            if (uVar8 != 0xfe) {
              uVar8 = uVar8 + 1 & 0xff;
              uVar10 = (uVar10 << 6) >> 9;
              goto LAB_00006956;
            }
            goto LAB_00006b0a;
          }
        }
        uVar10 = uVar10 >> 3;
        uVar11 = uVar8;
        uVar4 = uVar9;
        goto LAB_00006afc;
      }
      uVar3 = uVar11 - uVar8;
      if (uVar8 == 0) {
        uVar4 = uVar9;
        if (uVar7 == 0) goto LAB_00006afc;
        uVar3 = uVar3 - 1;
        if (uVar3 == 0) {
          uVar10 = uVar6 + uVar5;
          uVar8 = uVar11;
          goto LAB_000069a0;
        }
        uVar2 = uVar10;
        if (uVar11 != 0xff) goto LAB_00006a58;
      }
      else {
        uVar2 = uVar10;
        if (uVar11 != 0xff) {
          uVar5 = uVar5 | 0x4000000;
LAB_00006a58:
          uVar10 = 1;
          if ((int)uVar3 < 0x1c) {
            uVar10 = uVar5 >> (uVar3 & 0xff) | (uint)(uVar5 << (0x20 - uVar3 & 0xff) != 0);
          }
          uVar10 = uVar10 + uVar6;
          uVar8 = uVar11;
          goto LAB_000069a0;
        }
      }
    }
    else {
      uVar4 = uVar3;
      if (uVar9 == uVar3) goto LAB_00006a32;
      uVar3 = uVar8 - 0xff;
LAB_000069ca:
      if (uVar3 == 0) {
        if ((uVar8 + 1 & 0xfe) != 0) {
          uVar10 = uVar5 - uVar6;
          if ((int)(uVar10 * 0x20) < 0) {
            uVar10 = uVar6 + uVar7 * -8;
            uVar9 = uVar4;
          }
          else if (uVar10 == 0) {
            uVar8 = 0;
            uVar9 = 0;
            uVar10 = 0;
            goto LAB_00006956;
          }
LAB_0000690c:
          iVar1 = FUN_00008c6c(uVar10);
          uVar2 = iVar1 - 5;
          uVar10 = uVar10 << (uVar2 & 0xff);
          if ((int)uVar2 < (int)uVar8) {
            uVar8 = uVar8 - uVar2;
            uVar10 = DAT_00006c14 & uVar10;
          }
          else {
            uVar2 = (uVar2 - uVar8) + 1;
            uVar8 = 0;
            uVar10 = (uint)(uVar10 << (0x20 - uVar2 & 0xff) != 0) | uVar10 >> (uVar2 & 0xff);
          }
          goto LAB_00006934;
        }
        if (uVar8 == 0) {
          if (uVar7 == 0) {
            uVar9 = uVar4;
            if (uVar6 != 0) goto LAB_00006956;
LAB_00006bfc:
            uVar9 = 0;
            uVar10 = 0;
            goto LAB_00006956;
          }
          uVar10 = uVar7;
          if (uVar6 == 0) goto LAB_00006956;
          uVar10 = uVar5 - uVar6;
          if (-1 < (int)(uVar10 * 0x20)) {
            if (uVar10 == 0) goto LAB_00006bfc;
            goto LAB_00006af4;
          }
          uVar10 = uVar6 + uVar7 * -8;
          uVar9 = uVar4;
          goto LAB_00006934;
        }
        if (uVar7 == 0) {
          if (uVar6 == 0) {
            uVar8 = 0xff;
            uVar9 = 0;
            uVar10 = 0x400000;
            goto LAB_00006956;
          }
          goto LAB_000069ee;
        }
LAB_00006bc0:
        uVar2 = uVar7;
        if (((uVar6 == 0) || ((param_1 & 0x400000) == 0)) || ((param_2 & 0x400000) != 0))
        goto LAB_000069f2;
      }
      else {
        uVar2 = uVar11 - uVar8;
        if (uVar8 == 0) {
          if (uVar7 == 0) goto LAB_00006afc;
          uVar2 = uVar2 - 1;
          if (uVar2 == 0) {
            uVar10 = uVar6 + uVar7 * -8;
            uVar8 = uVar11;
            uVar9 = uVar4;
            goto LAB_00006902;
          }
          if (uVar11 != 0xff) goto LAB_00006b28;
        }
        else if (uVar11 != 0xff) {
          uVar5 = uVar5 | 0x4000000;
LAB_00006b28:
          uVar10 = 1;
          if ((int)uVar2 < 0x1c) {
            uVar10 = uVar5 >> (uVar2 & 0xff) | (uint)(uVar5 << (0x20 - uVar2 & 0xff) != 0);
          }
          uVar10 = uVar6 - uVar10;
          uVar8 = uVar11;
          uVar9 = uVar4;
          goto LAB_00006902;
        }
      }
LAB_000069ee:
      uVar2 = uVar10;
      uVar9 = uVar4;
    }
LAB_000069f2:
    if (uVar2 != 0) {
      uVar8 = 0xff;
      uVar10 = uVar2 & 0x7fffff | 0x400000;
      goto LAB_00006956;
    }
  }
  else {
    uVar4 = uVar3 ^ 1;
    if (uVar9 != uVar4) {
LAB_000068c4:
      uVar4 = uVar3 ^ 1;
      uVar3 = uVar8 - uVar11;
      if ((int)uVar3 < 1) goto LAB_000069ca;
      if (uVar11 != 0) {
        if (uVar8 == 0xff) goto LAB_000069f2;
        uVar6 = uVar6 | 0x4000000;
LAB_000068e4:
        uVar10 = 1;
        if ((int)uVar3 < 0x1c) {
          uVar10 = uVar6 >> (uVar3 & 0xff) | (uint)(uVar6 << (0x20 - uVar3 & 0xff) != 0);
        }
        uVar10 = uVar5 - uVar10;
LAB_00006902:
        if ((int)(uVar10 << 5) < 0) {
          uVar10 = uVar10 & 0x3ffffff;
          goto LAB_0000690c;
        }
        goto LAB_00006af4;
      }
      uVar10 = uVar7;
      uVar11 = uVar8;
      uVar4 = uVar9;
      if (uVar6 != 0) {
        uVar3 = uVar3 - 1;
        if (uVar3 == 0) {
          uVar10 = uVar5 - uVar6;
          goto LAB_00006902;
        }
        if (uVar8 != 0xff) goto LAB_000068e4;
        goto LAB_000069f2;
      }
LAB_00006afc:
      uVar2 = uVar10;
      uVar9 = uVar4;
      if (uVar11 != 0xff) {
        uVar8 = uVar11 & 0xff;
        uVar10 = uVar10 & 0x7fffff;
        goto LAB_00006956;
      }
      goto LAB_000069f2;
    }
    uVar3 = uVar8 - uVar11;
    if ((int)uVar3 < 1) goto LAB_00006a3a;
    if (uVar11 == 0) {
      uVar10 = uVar7;
      uVar11 = uVar8;
      uVar4 = uVar9;
      if (uVar6 == 0) goto LAB_00006afc;
      uVar3 = uVar3 - 1;
      if (uVar3 == 0) {
        uVar10 = uVar6 + uVar5;
        goto LAB_000069a0;
      }
      if (uVar8 != 0xff) goto LAB_00006984;
      goto LAB_000069f2;
    }
    if (uVar8 == 0xff) goto LAB_000069f2;
    uVar6 = uVar6 | 0x4000000;
LAB_00006984:
    uVar10 = 1;
    if ((int)uVar3 < 0x1c) {
      uVar10 = uVar6 >> (uVar3 & 0xff) | (uint)(uVar6 << (0x20 - uVar3 & 0xff) != 0);
    }
    uVar10 = uVar10 + uVar5;
LAB_000069a0:
    if (-1 < (int)(uVar10 << 5)) goto LAB_00006af4;
    uVar8 = uVar8 + 1;
    if (uVar8 != 0xff) {
      uVar10 = uVar10 >> 1 & DAT_00006c10 | uVar10 & 1;
LAB_00006934:
      if ((uVar10 & 7) != 0) goto LAB_00006938;
      goto LAB_00006942;
    }
  }
LAB_00006b0a:
  uVar8 = 0xff;
  uVar10 = 0;
LAB_00006956:
  return uVar8 << 0x17 | uVar10 | uVar9 << 0x1f;
}




uint FUN_00006c18(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_1 << 1) >> 0x18;
  uVar1 = 0;
  if (0x7e < uVar3) {
    if (uVar3 < 0x9e) {
      uVar2 = param_1 & 0x7fffff | 0x800000;
      if (uVar3 < 0x96) {
        uVar2 = uVar2 >> (0x96 - uVar3 & 0xff);
      }
      else {
        uVar2 = uVar2 << (uVar3 - 0x96 & 0xff);
      }
      uVar1 = -uVar2;
      if (-1 < (int)param_1) {
        uVar1 = uVar2;
      }
    }
    else {
      uVar1 = DAT_00006c54 - ((int)param_1 >> 0x1f);
    }
  }
  return uVar1;
}




uint FUN_00006c58(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar3 = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = FUN_00008c6c(uVar4);
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      if (8 < iVar1) {
        uVar4 = uVar4 << (iVar1 - 8U & 0xff);
      }
      uVar4 = uVar4 & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if (0x99 < (int)uVar3) {
        uVar4 = uVar4 >> (5U - iVar1 & 0xff) | (uint)(uVar4 << (iVar1 + 0x1bU & 0xff) != 0);
      }
      if (5 < iVar1) {
        uVar4 = uVar4 << (iVar1 - 5U & 0xff);
      }
      uVar2 = uVar4 & DAT_00006ce0;
      if ((((uVar4 & 7) != 0) && ((uVar4 & 0xf) != 4)) &&
         (uVar2 = uVar2 + 4, (int)(uVar2 * 0x20) < 0)) {
        uVar2 = uVar2 & DAT_00006ce0;
        uVar3 = 0x9f - iVar1;
      }
      uVar4 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar3 << 0x17 | uVar4 | param_1 << 0x1f;
}




uint FUN_00006ce4(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0;
    param_1 = 0;
  }
  else {
    iVar1 = FUN_00008c6c();
    uVar3 = 0x9e - iVar1;
    if ((int)uVar3 < 0x97) {
      if (8 < iVar1) {
        param_1 = param_1 << (iVar1 - 8U & 0xff);
      }
      param_1 = param_1 & 0x7fffff;
      uVar3 = uVar3 & 0xff;
    }
    else {
      if (0x99 < (int)uVar3) {
        param_1 = param_1 >> (5U - iVar1 & 0xff) | (uint)(param_1 << (iVar1 + 0x1bU & 0xff) != 0);
      }
      if (5 < iVar1) {
        param_1 = param_1 << (iVar1 - 5U & 0xff);
      }
      uVar2 = param_1 & DAT_00006d58;
      if ((((param_1 & 7) != 0) && ((param_1 & 0xf) != 4)) &&
         (uVar2 = uVar2 + 4, (int)(uVar2 * 0x20) < 0)) {
        uVar2 = uVar2 & DAT_00006d58;
        uVar3 = 0x9f - iVar1;
      }
      param_1 = (uVar2 << 6) >> 9;
      uVar3 = uVar3 & 0xff;
    }
  }
  return uVar3 << 0x17 | param_1;
}




undefined8 FUN_00006d5c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar7 = param_1 >> 0x1d;
  iVar10 = -((int)param_2 >> 0x1f);
  uVar8 = uVar7 | (param_2 << 0xc) >> 9;
  uVar5 = param_1 * 8;
  uVar2 = param_3 >> 0x1d;
  uVar11 = (param_4 << 0xc) >> 9;
  uVar3 = uVar2 | uVar11;
  uVar12 = (param_2 << 1) >> 0x15;
  uVar6 = (param_4 << 1) >> 0x15;
  uVar4 = uVar12 - uVar6;
  iVar1 = -((int)param_4 >> 0x1f);
  uVar13 = param_3 * 8;
  if (iVar10 == iVar1) {
    if ((int)uVar4 < 1) {
      if (uVar4 == 0) {
        uVar6 = uVar12 + 1;
        if ((uVar6 & 0x7fe) == 0) {
          if (uVar12 != 0) {
            if ((uVar5 | uVar8) == 0) {
              uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
              uVar9 = param_4 & 0xfffff;
            }
            else {
              if ((uVar3 | uVar13) == 0) goto LAB_00007100;
              uVar3 = uVar7 << 0x1d | param_1 & 0x1fffffff;
              uVar9 = param_2 & 0xfffff;
              if (((param_2 & 0x80000) != 0) && ((uVar11 & 0x400000) == 0)) {
                uVar3 = uVar2 << 0x1d | param_3 & 0x1fffffff;
                uVar9 = param_4 & 0xfffff;
              }
            }
            goto LAB_0000704c;
          }
          if ((uVar5 | uVar8) == 0) {
            uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
            uVar9 = param_4 & 0xfffff;
          }
          else {
            if ((uVar3 | uVar13) != 0) {
              uVar7 = uVar13 + uVar5;
              uVar9 = uVar8 + uVar3 + (uint)(uVar7 < uVar5);
              if ((int)(uVar9 * 0x100) < 0) {
                uVar12 = 1;
                uVar9 = uVar9 & DAT_0000747c;
              }
              goto LAB_00006fbc;
            }
            uVar3 = param_1 & 0x1fffffff | uVar7 << 0x1d;
            uVar9 = param_2 & 0xfffff;
          }
          goto LAB_00006fd6;
        }
        if (uVar6 != 0x7ff) {
          uVar3 = uVar8 + uVar3 + (uint)(uVar13 + uVar5 < uVar5);
          uVar9 = uVar3 >> 1;
          uVar7 = uVar3 * -0x80000000 | uVar13 + uVar5 >> 1;
          uVar12 = uVar6;
          goto LAB_00006fbc;
        }
        goto LAB_0000700c;
      }
      uVar4 = uVar6 - uVar12;
      if (uVar12 == 0) {
        if ((uVar5 | uVar8) == 0) {
          uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
          uVar9 = param_4 & 0xfffff;
          iVar1 = iVar10;
          goto LAB_00006fce;
        }
        uVar12 = uVar4 - 1;
        if (uVar4 == 1) {
          uVar9 = uVar8 + uVar3 + (uint)(uVar5 + uVar13 < uVar13);
          goto LAB_00006fb0;
        }
        if (uVar4 != 0x7ff) goto LAB_00007084;
      }
      else if (uVar6 != 0x7ff) {
        uVar8 = uVar8 | 0x800000;
        uVar12 = uVar4;
LAB_00007084:
        if ((int)uVar12 < 0x39) {
          if ((int)uVar12 < 0x20) {
            uVar3 = uVar3 + (uVar8 >> (uVar12 & 0xff));
            uVar7 = uVar8 << (0x20 - uVar12 & 0xff) | uVar5 >> (uVar12 & 0xff) |
                    (uint)(uVar5 << (0x20 - uVar12 & 0xff) != 0);
          }
          else {
            if (uVar12 != 0x20) {
              uVar5 = uVar5 | uVar8 << (0x40 - uVar12 & 0xff);
            }
            uVar7 = uVar8 >> (uVar12 - 0x20 & 0xff) | (uint)(uVar5 != 0);
          }
        }
        else {
          uVar7 = (uint)((uVar8 | uVar5) != 0);
        }
        uVar7 = uVar7 + uVar13;
        uVar9 = (uVar7 < uVar13) + uVar3;
        uVar12 = uVar6;
        goto LAB_00006ffa;
      }
      uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
      uVar9 = param_4 & 0xfffff;
    }
    else {
      if (uVar6 != 0) {
        if (uVar12 == 0x7ff) {
LAB_00007100:
          uVar3 = param_1 & 0x1fffffff | uVar7 << 0x1d;
          uVar9 = param_2 & 0xfffff;
          goto LAB_0000704c;
        }
        uVar3 = uVar3 | 0x800000;
        uVar2 = uVar4;
LAB_00006efe:
        if ((int)uVar2 < 0x39) {
          if ((int)uVar2 < 0x20) {
            uVar7 = uVar3 << (0x20 - uVar2 & 0xff) | uVar13 >> (uVar2 & 0xff) |
                    (uint)(uVar13 << (0x20 - uVar2 & 0xff) != 0);
            uVar8 = uVar8 + (uVar3 >> (uVar2 & 0xff));
          }
          else {
            if (uVar2 != 0x20) {
              uVar13 = uVar13 | uVar3 << (0x40 - uVar2 & 0xff);
            }
            uVar7 = uVar3 >> (uVar2 - 0x20 & 0xff) | (uint)(uVar13 != 0);
          }
        }
        else {
          uVar7 = (uint)((uVar3 | uVar13) != 0);
        }
        uVar7 = uVar7 + uVar5;
        uVar9 = (uVar7 < uVar5) + uVar8;
LAB_00006ffa:
        if ((int)(uVar9 << 8) < 0) {
          uVar12 = uVar12 + 1;
          if (uVar12 == 0x7ff) goto LAB_0000700c;
          goto LAB_000071a6;
        }
LAB_00006fbc:
        uVar4 = uVar7;
        if ((uVar7 & 7) != 0) goto LAB_00006e5c;
        goto LAB_00006fc2;
      }
      if ((uVar3 | uVar13) != 0) {
        uVar2 = uVar4 - 1;
        if (uVar4 != 1) {
          if (uVar4 == 0x7ff) {
LAB_000072c6:
            uVar3 = param_1 & 0x1fffffff | uVar7 << 0x1d;
            uVar9 = param_2 & 0xfffff;
            goto LAB_0000704c;
          }
          goto LAB_00006efe;
        }
        uVar9 = uVar8 + uVar3 + (uint)(uVar13 + uVar5 < uVar5);
LAB_00006fb0:
        uVar7 = uVar5 + uVar13;
        uVar12 = 2;
        if (-1 < (int)(uVar9 << 8)) {
          uVar12 = 1;
          goto LAB_00006fbc;
        }
LAB_000071a6:
        uVar3 = uVar9 & DAT_000071c0;
        uVar9 = uVar3 >> 1;
        uVar4 = uVar7 & 1 | uVar7 >> 1 | uVar3 << 0x1f;
        iVar1 = iVar10;
        goto LAB_00006e58;
      }
LAB_000070f4:
      uVar3 = param_1 & 0x1fffffff | uVar7 << 0x1d;
      uVar9 = param_2 & 0xfffff;
      iVar1 = iVar10;
LAB_00006fce:
      iVar10 = iVar1;
      if (uVar4 != 0x7ff) {
LAB_00006fd6:
        uVar4 = uVar4 & 0x7ff;
        uVar2 = uVar9 & 0xfffff;
        goto LAB_00006e98;
      }
    }
LAB_0000704c:
    if ((uVar3 | uVar9) == 0) {
      uVar3 = 0;
      uVar4 = 0x7ff;
      uVar2 = uVar3;
      goto LAB_00006e98;
    }
  }
  else {
    if (0 < (int)uVar4) {
      if (uVar6 == 0) {
        if ((uVar3 | uVar13) == 0) goto LAB_000070f4;
        uVar2 = uVar4 - 1;
        if (uVar4 == 1) {
          uVar7 = uVar5 + param_3 * -8;
          uVar9 = (uVar8 - uVar3) - (uint)(uVar5 < uVar7);
          uVar12 = 1;
          goto LAB_00006dfa;
        }
        if (uVar4 == 0x7ff) goto LAB_000072c6;
      }
      else {
        if (uVar12 == 0x7ff) goto LAB_00007100;
        uVar3 = uVar3 | 0x800000;
        uVar2 = uVar4;
      }
      if ((int)uVar2 < 0x39) {
        if ((int)uVar2 < 0x20) {
          uVar7 = (uint)(uVar13 << (0x20 - uVar2 & 0xff) != 0) |
                  uVar3 << (0x20 - uVar2 & 0xff) | uVar13 >> (uVar2 & 0xff);
          uVar8 = uVar8 - (uVar3 >> (uVar2 & 0xff));
        }
        else {
          if (uVar2 != 0x20) {
            uVar13 = uVar13 | uVar3 << (0x40 - uVar2 & 0xff);
          }
          uVar7 = (uint)(uVar13 != 0) | uVar3 >> (uVar2 - 0x20 & 0xff);
        }
      }
      else {
        uVar7 = (uint)((uVar3 | uVar13) != 0);
      }
      uVar7 = uVar5 - uVar7;
      uVar9 = uVar8 - (uVar5 < uVar7);
LAB_00006dfa:
      if (-1 < (int)(uVar9 << 8)) goto LAB_00006fbc;
      uVar9 = uVar9 & 0x7fffff;
      iVar1 = iVar10;
LAB_00006e0a:
      if (uVar9 == 0) {
        iVar10 = FUN_00008c6c(uVar7);
        uVar3 = iVar10 + 0x18;
        if ((int)uVar3 < 0x20) goto LAB_00006e1c;
        uVar7 = uVar7 << (iVar10 - 8U & 0xff);
        uVar4 = 0;
      }
      else {
        iVar10 = FUN_00008c6c(uVar9);
        uVar3 = iVar10 - 8;
LAB_00006e1c:
        uVar4 = uVar7 << (uVar3 & 0xff);
        uVar7 = uVar9 << (uVar3 & 0xff) | uVar7 >> (0x20 - uVar3 & 0xff);
      }
      if ((int)uVar3 < (int)uVar12) {
        uVar12 = uVar12 - uVar3;
        uVar9 = uVar7 & DAT_000071c0;
      }
      else {
        iVar10 = uVar3 - uVar12;
        uVar3 = iVar10 + 1;
        if (0x1f < (int)uVar3) {
          if (uVar3 != 0x20) {
            uVar4 = uVar4 | uVar7 << (0x40 - uVar3 & 0xff);
          }
          uVar9 = 0;
          uVar12 = 0;
          uVar7 = (uint)(uVar4 != 0) | uVar7 >> (iVar10 - 0x1fU & 0xff);
          iVar10 = iVar1;
          goto LAB_00006fbc;
        }
        uVar9 = uVar7 >> (uVar3 & 0xff);
        uVar12 = 0;
        uVar4 = (uint)(uVar4 << (0x20 - uVar3 & 0xff) != 0) |
                uVar7 << (0x20 - uVar3 & 0xff) | uVar4 >> (uVar3 & 0xff);
      }
LAB_00006e58:
      iVar10 = iVar1;
      uVar7 = uVar4;
      if ((uVar4 & 7) != 0) {
LAB_00006e5c:
        uVar7 = uVar4;
        if ((uVar4 & 0xf) != 4) {
          uVar7 = uVar4 + 4;
          uVar9 = uVar9 + (uVar7 < uVar4);
        }
      }
      if ((int)(uVar9 << 8) < 0) {
        if (uVar12 + 1 != 0x7ff) {
          uVar3 = (uVar9 & DAT_000071c0) << 0x1d | uVar7 >> 3;
          uVar2 = ((uVar9 & DAT_000071c0) << 9) >> 0xc;
          uVar4 = uVar12 + 1 & 0x7ff;
          goto LAB_00006e98;
        }
LAB_0000700c:
        uVar4 = 0x7ff;
        uVar2 = 0;
        uVar3 = 0;
        goto LAB_00006e98;
      }
LAB_00006fc2:
      uVar3 = uVar7 >> 3 | uVar9 << 0x1d;
      uVar9 = uVar9 >> 3;
      iVar1 = iVar10;
      uVar4 = uVar12;
      goto LAB_00006fce;
    }
    if (uVar4 != 0) {
      uVar4 = uVar6 - uVar12;
      if (uVar12 == 0) {
        if ((uVar5 | uVar8) == 0) {
          uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
          uVar9 = param_4 & 0xfffff;
          goto LAB_00006fce;
        }
        uVar12 = uVar4 - 1;
        if (uVar4 == 1) {
          uVar7 = uVar13 + param_1 * -8;
          uVar9 = (uVar3 - uVar8) - (uint)(uVar13 < uVar7);
          uVar12 = 1;
          iVar10 = iVar1;
          goto LAB_00006dfa;
        }
        if (uVar4 == 0x7ff) {
          uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
          uVar9 = param_4 & 0xfffff;
          iVar10 = iVar1;
          goto LAB_0000704c;
        }
      }
      else {
        if (uVar6 == 0x7ff) {
LAB_000072e8:
          uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
          uVar9 = param_4 & 0xfffff;
          iVar10 = iVar1;
          goto LAB_0000704c;
        }
        uVar8 = uVar8 | 0x800000;
        uVar12 = uVar4;
      }
      if ((int)uVar12 < 0x39) {
        if ((int)uVar12 < 0x20) {
          uVar3 = uVar3 - (uVar8 >> (uVar12 & 0xff));
          uVar7 = (uint)(uVar5 << (0x20 - uVar12 & 0xff) != 0) |
                  uVar8 << (0x20 - uVar12 & 0xff) | uVar5 >> (uVar12 & 0xff);
        }
        else {
          if (uVar12 != 0x20) {
            uVar5 = uVar5 | uVar8 << (0x40 - uVar12 & 0xff);
          }
          uVar7 = (uint)(uVar5 != 0) | uVar8 >> (uVar12 - 0x20 & 0xff);
        }
      }
      else {
        uVar7 = (uint)((uVar8 | uVar5) != 0);
      }
      uVar7 = uVar13 - uVar7;
      uVar9 = uVar3 - (uVar13 < uVar7);
      iVar10 = iVar1;
      uVar12 = uVar6;
      goto LAB_00006dfa;
    }
    if ((uVar12 + 1 & 0x7fe) != 0) {
      uVar7 = uVar5 + param_3 * -8;
      uVar9 = (uVar8 - uVar3) - (uint)(uVar5 < uVar7);
      if ((int)(uVar9 * 0x100) < 0) {
        uVar7 = uVar13 + param_1 * -8;
        uVar9 = (uVar3 - uVar8) - (uint)(uVar13 < uVar7);
      }
      else {
        iVar1 = iVar10;
        if ((uVar9 | uVar7) == 0) {
          uVar9 = 0;
          uVar3 = 0;
          iVar10 = 0;
          goto LAB_00006fd6;
        }
      }
      goto LAB_00006e0a;
    }
    if (uVar12 == 0) {
      if ((uVar5 | uVar8) == 0) {
        uVar3 = uVar3 | uVar13;
        if (uVar3 == 0) {
LAB_000073f2:
          uVar9 = 0;
          iVar10 = 0;
          uVar4 = uVar3;
        }
        else {
          uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
          uVar9 = param_4 & 0xfffff;
          iVar10 = iVar1;
        }
      }
      else {
        if ((uVar3 | uVar13) != 0) {
          uVar7 = uVar5 + param_3 * -8;
          uVar9 = (uVar8 - uVar3) - (uint)(uVar5 < uVar7);
          if (-1 < (int)(uVar9 * 0x100)) {
            uVar3 = uVar9 | uVar7;
            if (uVar3 != 0) goto LAB_00006fbc;
            goto LAB_000073f2;
          }
          uVar4 = uVar13 + param_1 * -8;
          uVar9 = (uVar3 - uVar8) - (uint)(uVar13 < uVar4);
          goto LAB_00006e58;
        }
        uVar3 = param_1 & 0x1fffffff | uVar7 << 0x1d;
        uVar9 = param_2 & 0xfffff;
      }
      goto LAB_00006fd6;
    }
    if ((uVar5 | uVar8) != 0) {
      if ((uVar3 | uVar13) != 0) {
        uVar3 = param_1 & 0x1fffffff | uVar7 << 0x1d;
        uVar9 = param_2 & 0xfffff;
        if (((param_2 & 0x80000) != 0) && ((uVar11 & 0x400000) == 0)) {
          uVar3 = param_3 & 0x1fffffff | uVar2 << 0x1d;
          uVar9 = param_4 & 0xfffff;
          iVar10 = iVar1;
        }
        goto LAB_0000704c;
      }
      goto LAB_00007100;
    }
    if ((uVar3 | uVar13) != 0) goto LAB_000072e8;
    iVar10 = 0;
    uVar9 = 0x80000;
    uVar3 = 0;
  }
  uVar4 = 0x7ff;
  uVar2 = uVar9 & 0xfffff | 0x80000;
LAB_00006e98:
  return CONCAT44(uVar2 | uVar4 << 0x14 | iVar10 << 0x1f,uVar3);
}




undefined8 FUN_00007480(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined8 uVar19;
  int local_3c;
  
  uVar1 = (param_2 << 1) >> 0x15;
  uVar9 = param_2 & 0xfffff;
  if (uVar1 == 0) {
    if ((param_1 | uVar9) == 0) {
      param_1 = 0;
      uVar17 = 4;
      local_3c = 0;
      uVar9 = 0;
      goto LAB_000074d0;
    }
    if (uVar9 == 0) {
      iVar6 = FUN_00008c6c(param_1);
      iVar13 = iVar6 + 0x15;
      local_3c = iVar6 + 0x20;
      if (iVar13 < 0x1d) goto LAB_00007586;
      uVar9 = param_1 << (iVar6 - 8U & 0xff);
      param_1 = 0;
    }
    else {
      local_3c = FUN_00008c6c(uVar9);
      iVar13 = local_3c + -0xb;
LAB_00007586:
      uVar9 = param_1 >> (0x1dU - iVar13 & 0xff) | uVar9 << (local_3c - 8U & 0xff);
      param_1 = param_1 << (local_3c - 8U & 0xff);
    }
    local_3c = DAT_00007708 - local_3c;
    uVar1 = (param_4 << 1) >> 0x15;
    uVar17 = 0;
    if (uVar1 != 0) goto LAB_000074e0;
LAB_000075bc:
    uVar10 = param_4 & 0xfffff;
    if ((param_3 | uVar10) == 0) {
      uVar17 = uVar17 | 1;
      uVar10 = 0;
      uVar2 = 1;
      uVar1 = 0;
    }
    else {
      if (uVar10 == 0) {
        iVar3 = FUN_00008c6c();
        iVar6 = iVar3 + 0x15;
        iVar13 = iVar3 + 0x20;
        if (iVar6 < 0x1d) goto LAB_000075d4;
        uVar1 = 0;
        uVar10 = param_3 << (iVar3 - 8U & 0xff);
      }
      else {
        iVar13 = FUN_00008c6c(uVar10);
        iVar6 = iVar13 + -0xb;
LAB_000075d4:
        uVar1 = param_3 << (iVar13 - 8U & 0xff);
        uVar10 = uVar10 << (iVar13 - 8U & 0xff) | param_3 >> (0x1dU - iVar6 & 0xff);
      }
      local_3c = iVar13 + local_3c + 0x3f3;
      uVar2 = 0;
    }
  }
  else {
    if (uVar1 == 0x7ff) {
      if ((param_1 | uVar9) == 0) {
        param_1 = 0;
        uVar17 = 8;
        local_3c = 0x7ff;
        uVar9 = 0;
      }
      else {
        uVar17 = 0xc;
        local_3c = 0x7ff;
      }
    }
    else {
      uVar9 = uVar9 << 3 | param_1 >> 0x1d | 0x800000;
      uVar17 = 0;
      local_3c = uVar1 + DAT_000076fc;
      param_1 = param_1 << 3;
    }
LAB_000074d0:
    uVar1 = (param_4 << 1) >> 0x15;
    if (uVar1 == 0) goto LAB_000075bc;
LAB_000074e0:
    uVar10 = param_4 & 0xfffff;
    if (uVar1 == 0x7ff) {
      local_3c = local_3c + DAT_00007704;
      if ((param_3 | uVar10) == 0) {
        uVar17 = uVar17 | 2;
        uVar10 = 0;
        uVar2 = 2;
        uVar1 = 0;
      }
      else {
        uVar17 = uVar17 | 3;
        uVar2 = 3;
        uVar1 = param_3;
      }
    }
    else {
      uVar10 = uVar10 << 3 | param_3 >> 0x1d | 0x800000;
      uVar2 = 0;
      local_3c = local_3c - (uVar1 + DAT_000076fc);
      uVar1 = param_3 << 3;
    }
  }
  if (uVar17 < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x00007518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar19 = (**(code **)(DAT_00007700 + uVar17 * 4))(uVar2);
    return uVar19;
  }
  if ((uVar10 < uVar9) || ((uVar10 == uVar9 && (uVar1 <= param_1)))) {
    uVar15 = uVar9 << 0x1f;
    uVar9 = uVar9 >> 1;
    uVar17 = param_1 << 0x1f;
    param_1 = uVar15 | param_1 >> 1;
  }
  else {
    uVar17 = 0;
    local_3c = local_3c + -1;
  }
  uVar10 = uVar10 << 8;
  uVar14 = uVar10 >> 0x10;
  uVar16 = uVar1 >> 0x18 | uVar10;
  uVar11 = uVar9 / uVar14;
  uVar15 = uVar1 * 0x100;
  uVar4 = uVar1 >> 0x18 | uVar10 & 0xffff;
  uVar5 = uVar11 * uVar4;
  uVar10 = param_1 >> 0x10 | (uVar9 - uVar11 * uVar14) * 0x10000;
  uVar9 = uVar11;
  if (uVar10 <= uVar5 && uVar5 - uVar10 != 0) {
    uVar9 = uVar11 - 1;
    uVar10 = uVar10 + uVar16;
    if ((uVar16 <= uVar10) && (uVar10 <= uVar5 && uVar5 - uVar10 != 0)) {
      uVar9 = uVar11 - 2;
      uVar10 = uVar10 + uVar16;
    }
  }
  uVar18 = (uVar10 - uVar5) / uVar14;
  uVar11 = uVar4 * uVar18;
  uVar5 = ((uVar10 - uVar5) - uVar14 * uVar18) * 0x10000 | param_1 & 0xffff;
  uVar10 = uVar18;
  if (uVar5 <= uVar11 && uVar11 - uVar5 != 0) {
    uVar10 = uVar18 - 1;
    uVar5 = uVar5 + uVar16;
    if ((uVar16 <= uVar5) && (uVar5 <= uVar11 && uVar11 - uVar5 != 0)) {
      uVar5 = uVar5 + uVar16;
      uVar10 = uVar18 - 2;
    }
  }
  uVar18 = uVar10 | uVar9 << 0x10;
  uVar7 = uVar15 >> 0x10;
  uVar5 = uVar5 - uVar11;
  uVar11 = uVar15 & 0xffff;
  uVar12 = (uVar10 & 0xffff) * uVar11;
  uVar8 = (uVar18 >> 0x10) * uVar11;
  iVar13 = uVar7 * (uVar18 >> 0x10);
  uVar9 = uVar7 * (uVar10 & 0xffff) + uVar8 + (uVar12 >> 0x10);
  if (uVar9 <= uVar8 && uVar8 - uVar9 != 0) {
    iVar13 = iVar13 + 0x10000;
  }
  uVar10 = iVar13 + (uVar9 >> 0x10);
  uVar9 = uVar9 * 0x10000 + (uVar12 & 0xffff);
  if ((uVar5 < uVar10) || ((uVar8 = uVar18, uVar5 == uVar10 && (uVar17 < uVar9)))) {
    uVar8 = uVar18 - 1;
    uVar17 = uVar17 + uVar15;
    uVar5 = uVar5 + (uVar17 < uVar15) + uVar16;
    if (((uVar16 < uVar5) || ((uVar16 == uVar5 && (uVar15 < uVar17 || uVar15 - uVar17 == 0)))) &&
       ((uVar5 <= uVar10 && uVar10 != uVar5 || ((uVar10 == uVar5 && (uVar17 < uVar9)))))) {
      uVar17 = uVar17 + uVar15;
      uVar5 = uVar5 + (uVar17 < uVar15) + uVar16;
      uVar8 = uVar18 - 2;
    }
  }
  uVar9 = uVar17 - uVar9;
  uVar17 = (uVar5 - uVar10) - (uint)(uVar17 < uVar9);
  if (uVar16 == uVar17) {
    if (0 < local_3c + 0x3ff) {
      uVar9 = 0;
      uVar8 = uVar8 + 1;
LAB_00007644:
      uVar1 = local_3c + 0x3ff;
      if ((int)(uVar8 << 7) < 0) {
        uVar8 = uVar8 & DAT_0000770c;
        uVar1 = local_3c + 0x400;
      }
      if ((int)uVar1 < 0x7ff) {
        uVar9 = uVar9 | uVar8 << 0x1d;
        uVar17 = (uVar8 << 9) >> 0xc;
        uVar1 = uVar1 & 0x7ff;
      }
      else {
        uVar1 = 0x7ff;
        uVar17 = 0;
        uVar9 = 0;
      }
      goto LAB_00007542;
    }
    uVar17 = 0xffffffff;
  }
  else {
    uVar18 = uVar17 / uVar14;
    uVar10 = uVar18 * uVar4;
    uVar5 = (uVar17 - uVar18 * uVar14) * 0x10000 | uVar9 >> 0x10;
    uVar17 = uVar18;
    if (uVar5 <= uVar10 && uVar10 - uVar5 != 0) {
      uVar17 = uVar18 - 1;
      uVar5 = uVar5 + uVar16;
      if ((uVar16 <= uVar5) && (uVar5 <= uVar10 && uVar10 - uVar5 != 0)) {
        uVar17 = uVar18 - 2;
        uVar5 = uVar5 + uVar16;
      }
    }
    uVar18 = (uVar5 - uVar10) / uVar14;
    uVar4 = uVar18 * uVar4;
    uVar10 = uVar9 & 0xffff | ((uVar5 - uVar10) - uVar18 * uVar14) * 0x10000;
    uVar9 = uVar18;
    if (uVar10 <= uVar4 && uVar4 - uVar10 != 0) {
      uVar10 = uVar10 + uVar16;
      uVar9 = uVar18 - 1;
      if ((uVar16 <= uVar10) && (uVar10 <= uVar4 && uVar4 - uVar10 != 0)) {
        uVar9 = uVar18 - 2;
        uVar10 = uVar10 + uVar16;
      }
    }
    uVar17 = uVar17 << 0x10 | uVar9;
    uVar10 = uVar10 - uVar4;
    uVar4 = (uVar17 >> 0x10) * uVar11;
    uVar11 = (uVar9 & 0xffff) * uVar11;
    uVar9 = (uVar11 >> 0x10) + uVar7 * (uVar9 & 0xffff) + uVar4;
    iVar13 = uVar7 * (uVar17 >> 0x10);
    if (uVar9 <= uVar4 && uVar4 - uVar9 != 0) {
      iVar13 = iVar13 + 0x10000;
    }
    uVar4 = (uVar9 >> 0x10) + iVar13;
    uVar9 = uVar9 * 0x10000 + (uVar11 & 0xffff);
    if (uVar10 < uVar4) {
LAB_000078d4:
      uVar10 = uVar16 + uVar10;
      uVar5 = uVar17 - 1;
      if (uVar10 < uVar16) {
LAB_00007a4a:
        if (uVar10 != uVar4) goto LAB_000078c8;
      }
      else {
        if (uVar10 < uVar4) {
LAB_00007aa0:
          uVar5 = uVar17 - 2;
          uVar10 = uVar10 + (uVar1 << 9 < uVar15) + uVar16;
          uVar15 = uVar1 << 9;
          goto LAB_00007a4a;
        }
        if (uVar10 != uVar4) goto LAB_000078c8;
        if (uVar15 < uVar9) goto LAB_00007aa0;
      }
      uVar17 = uVar5;
      if (uVar9 != uVar15) {
LAB_000078c8:
        uVar17 = uVar5 | 1;
      }
    }
    else {
      uVar5 = uVar17;
      if (uVar10 != uVar4) goto LAB_000078c8;
      if (uVar9 != 0) goto LAB_000078d4;
    }
    if (0 < local_3c + 0x3ff) {
      if (((uVar17 & 7) == 0) || ((uVar17 & 0xf) == 4)) {
        uVar9 = uVar17 >> 3;
      }
      else {
        uVar9 = uVar17 + 4 >> 3;
        uVar8 = uVar8 + (0xfffffffb < uVar17);
      }
      goto LAB_00007644;
    }
  }
  uVar9 = 1 - (local_3c + 0x3ff);
  if (0x38 < (int)uVar9) {
    uVar1 = 0;
    uVar17 = 0;
    uVar9 = 0;
    goto LAB_00007542;
  }
  if ((int)uVar9 < 0x20) {
    uVar1 = (uint)(uVar17 << (local_3c + 0x41eU & 0xff) != 0);
    uVar17 = uVar8 << (local_3c + 0x41eU & 0xff) | uVar17 >> (uVar9 & 0xff);
    uVar15 = uVar17 | uVar1;
    uVar8 = uVar8 >> (uVar9 & 0xff);
    if (((uVar17 & 7 | uVar1) != 0) && (uVar9 = uVar15, (uVar17 & 0xf | uVar1) != 4)) {
LAB_0000793e:
      uVar15 = uVar9 + 4;
      uVar8 = uVar8 + (uVar15 < uVar9);
    }
    if ((int)(uVar8 << 8) < 0) {
      uVar1 = 1;
      uVar17 = 0;
      uVar9 = 0;
      goto LAB_00007542;
    }
LAB_00007a92:
    uVar9 = uVar8 << 0x1d;
    uVar17 = (uVar8 << 9) >> 0xc;
  }
  else {
    uVar1 = uVar8 >> (-(local_3c + 0x3ff) - 0x1fU & 0xff);
    if (uVar9 != 0x20) {
      uVar17 = uVar17 | uVar8 << (local_3c + 0x43eU & 0xff);
    }
    uVar10 = (uint)(uVar17 != 0);
    uVar15 = uVar1 | uVar10;
    uVar17 = 0;
    uVar9 = uVar1 & 7 | uVar10;
    if ((uVar1 & 7 | uVar10) != 0) {
      uVar8 = 0;
      uVar9 = uVar15;
      if ((uVar1 & 0xf | uVar10) != 4) goto LAB_0000793e;
      goto LAB_00007a92;
    }
  }
  uVar9 = uVar9 | uVar15 >> 3;
  uVar1 = 0;
LAB_00007542:
  return CONCAT44(uVar1 << 0x14 | uVar17 | (param_2 ^ param_4) & 0x80000000,uVar9);
}




bool FUN_00007ac8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = param_2 & 0xfffff;
  uVar2 = (param_2 << 1) >> 0x15;
  uVar1 = (param_4 << 1) >> 0x15;
  if (uVar2 == 0x7ff) {
    if ((uVar3 | param_1) != 0) {
      return true;
    }
    if (uVar1 != 0x7ff) {
      return true;
    }
    if ((param_4 & 0xfffff | param_3) != 0) {
      return true;
    }
  }
  else {
    if (uVar1 == 0x7ff) {
      return true;
    }
    if (uVar2 != uVar1) {
      return true;
    }
    if (uVar3 != (param_4 & 0xfffff)) {
      return true;
    }
  }
  bVar4 = true;
  if (param_1 == param_3) {
    if (-((int)param_2 >> 0x1f) == -((int)param_4 >> 0x1f)) {
      bVar4 = false;
    }
    else if (uVar2 == 0) {
      bVar4 = (param_1 | uVar3) != 0;
    }
  }
  return bVar4;
}




int FUN_00007b44(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = param_4 & 0xfffff;
  uVar6 = param_2 & 0xfffff;
  uVar3 = (param_2 << 1) >> 0x15;
  iVar2 = -((int)param_2 >> 0x1f);
  uVar5 = (param_4 << 1) >> 0x15;
  iVar1 = -((int)param_4 >> 0x1f);
  if (uVar3 == 0x7ff) {
    if ((uVar6 | param_1) != 0) {
      return -2;
    }
    if (uVar5 == 0x7ff) goto LAB_00007bb2;
LAB_00007bd0:
    if ((uVar5 == 0) && ((param_3 | uVar4) == 0)) goto LAB_00007b94;
  }
  else {
    if (uVar5 == 0x7ff) {
LAB_00007bb2:
      if ((param_3 | uVar4) != 0) {
        return -2;
      }
      if (uVar3 != 0) goto LAB_00007b90;
    }
    else {
      if (uVar3 != 0) goto LAB_00007bd0;
      if ((uVar5 == 0) && ((param_3 | uVar4) == 0)) {
        if ((param_1 | uVar6) == 0) {
          return 0;
        }
        goto LAB_00007b94;
      }
    }
    if ((param_1 | uVar6) == 0) goto LAB_00007bc6;
  }
LAB_00007b90:
  if (iVar2 == iVar1) {
    if (uVar5 < uVar3) {
      return (-(uint)(iVar1 == 0) & 2) - 1;
    }
    if (uVar3 < uVar5) {
LAB_00007bc6:
      if (-1 < (int)param_4) {
        return -1;
      }
      return iVar1;
    }
    if (uVar6 <= uVar4) {
      if (uVar6 == uVar4) {
        if (param_3 < param_1) goto LAB_00007b94;
        if (param_3 <= param_1) {
          return 0;
        }
      }
      else if (uVar4 <= uVar6) {
        return 0;
      }
      if (iVar2 == 0) {
        return -1;
      }
      return iVar2;
    }
  }
LAB_00007b94:
  return (iVar2 - 1U & 2) - 1;
}




int FUN_00007c24(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar4 = param_4 & 0xfffff;
  uVar6 = param_2 & 0xfffff;
  uVar3 = (param_2 << 1) >> 0x15;
  iVar2 = -((int)param_2 >> 0x1f);
  uVar5 = (param_4 << 1) >> 0x15;
  iVar1 = -((int)param_4 >> 0x1f);
  if (uVar3 == 0x7ff) {
    if ((uVar6 | param_1) != 0) {
      return 2;
    }
    if (uVar5 == 0x7ff) goto LAB_00007c80;
LAB_00007cb6:
    if ((uVar5 == 0) && ((param_3 | uVar4) == 0)) goto LAB_00007c94;
  }
  else {
    if (uVar5 == 0x7ff) {
LAB_00007c80:
      if ((param_3 | uVar4) != 0) {
        return 2;
      }
      if (uVar3 != 0) goto LAB_00007c90;
      bVar7 = (param_1 | uVar6) == 0;
    }
    else {
      if (uVar3 != 0) goto LAB_00007cb6;
      bVar7 = (param_1 | uVar6) == 0;
      if ((uVar5 == 0) && ((param_3 | uVar4) == 0)) {
        if ((param_1 | uVar6) == 0) {
          return 0;
        }
        goto LAB_00007c94;
      }
    }
    if (bVar7) goto LAB_00007cac;
  }
LAB_00007c90:
  if (iVar2 == iVar1) {
    if (uVar5 < uVar3) {
      return (-(uint)(iVar1 == 0) & 2) - 1;
    }
    if (uVar3 < uVar5) {
LAB_00007cac:
      if (-1 < (int)param_4) {
        return -1;
      }
      return iVar1;
    }
    if (uVar6 <= uVar4) {
      if (uVar6 == uVar4) {
        if (param_3 < param_1) goto LAB_00007c94;
        if (param_3 <= param_1) {
          return 0;
        }
      }
      else if (uVar4 <= uVar6) {
        return 0;
      }
      if (iVar2 == 0) {
        return -1;
      }
      return iVar2;
    }
  }
LAB_00007c94:
  return (iVar2 - 1U & 2) - 1;
}




undefined8 FUN_00007cfc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  int local_40;
  int local_3c;
  int local_38;
  
  uVar6 = (param_2 << 1) >> 0x15;
  uVar7 = param_2 & 0xfffff;
  if (uVar6 == 0) {
    if ((uVar7 | param_1) == 0) {
      uVar7 = 0;
      uVar12 = 4;
      local_40 = 0;
      param_1 = 0;
    }
    else {
      if (uVar7 == 0) {
        iVar5 = FUN_00008c6c();
        iVar11 = iVar5 + 0x15;
        local_40 = iVar5 + 0x20;
        if (iVar11 < 0x1d) goto LAB_00007e1e;
        uVar6 = 0;
        uVar7 = param_1 << (iVar5 - 8U & 0xff);
      }
      else {
        local_40 = FUN_00008c6c(uVar7);
        iVar11 = local_40 + -0xb;
LAB_00007e1e:
        uVar6 = param_1 << (local_40 - 8U & 0xff);
        uVar7 = uVar7 << (local_40 - 8U & 0xff) | param_1 >> (0x1dU - iVar11 & 0xff);
      }
      uVar12 = 0;
      local_40 = DAT_000080c4 - local_40;
      param_1 = uVar6;
    }
  }
  else if (uVar6 == 0x7ff) {
    if ((param_1 | uVar7) == 0) {
      uVar7 = 0;
      uVar12 = 8;
      local_40 = 0x7ff;
      param_1 = 0;
    }
    else {
      uVar12 = 0xc;
      local_40 = 0x7ff;
    }
  }
  else {
    uVar7 = uVar7 << 3 | param_1 >> 0x1d | 0x800000;
    uVar12 = 0;
    local_40 = uVar6 + DAT_000080bc;
    param_1 = param_1 << 3;
  }
  uVar6 = (param_4 << 1) >> 0x15;
  uVar8 = param_4 & 0xfffff;
  if (uVar6 == 0) {
    if ((param_3 | uVar8) == 0) {
      uVar12 = uVar12 | 1;
      uVar8 = 0;
      param_3 = 0;
    }
    else {
      if (uVar8 == 0) {
        iVar1 = FUN_00008c6c(param_3);
        iVar5 = iVar1 + 0x15;
        iVar11 = iVar1 + 0x20;
        if (iVar5 < 0x1d) goto LAB_00007e7a;
        uVar6 = 0;
        uVar8 = param_3 << (iVar1 - 8U & 0xff);
      }
      else {
        iVar11 = FUN_00008c6c(uVar8);
        iVar5 = iVar11 + -0xb;
LAB_00007e7a:
        uVar8 = uVar8 << (iVar11 - 8U & 0xff) | param_3 >> (0x1dU - iVar5 & 0xff);
        uVar6 = param_3 << (iVar11 - 8U & 0xff);
      }
      local_40 = (local_40 - iVar11) + DAT_000080c4;
      param_3 = uVar6;
    }
  }
  else if (uVar6 == 0x7ff) {
    local_40 = local_40 + 0x7ff;
    if ((param_3 | uVar8) == 0) {
      uVar12 = uVar12 | 2;
      uVar8 = 0;
      param_3 = 0;
    }
    else {
      uVar12 = uVar12 | 3;
    }
  }
  else {
    uVar8 = uVar8 << 3 | param_3 >> 0x1d | 0x800000;
    param_3 = param_3 << 3;
    local_40 = local_40 + uVar6 + DAT_000080bc;
  }
  local_3c = local_40 + 1;
  if (uVar12 < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x00007da2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar16 = (**(code **)(DAT_000080c0 + uVar12 * 4))();
    return uVar16;
  }
  uVar10 = param_1 >> 0x10;
  param_1 = param_1 & 0xffff;
  uVar12 = param_3 >> 0x10;
  param_3 = param_3 & 0xffff;
  uVar6 = uVar10 * param_3;
  local_38 = uVar10 * uVar12;
  uVar15 = uVar12 * param_1 + uVar6 + (param_3 * param_1 >> 0x10);
  if (uVar15 <= uVar6 && uVar6 - uVar15 != 0) {
    local_38 = local_38 + 0x10000;
  }
  uVar2 = uVar8 >> 0x10;
  uVar8 = uVar8 & 0xffff;
  uVar6 = uVar10 * uVar8;
  iVar11 = uVar2 * uVar10;
  uVar10 = uVar2 * param_1 + uVar6 + (uVar8 * param_1 >> 0x10);
  if (uVar10 <= uVar6 && uVar6 - uVar10 != 0) {
    iVar11 = iVar11 + 0x10000;
  }
  uVar3 = iVar11 + (uVar10 >> 0x10);
  uVar4 = uVar7 >> 0x10;
  uVar7 = uVar7 & 0xffff;
  uVar6 = param_3 * uVar4;
  uVar10 = uVar10 * 0x10000 + (uVar8 * param_1 & 0xffff);
  iVar11 = uVar12 * uVar4;
  uVar12 = uVar7 * uVar12 + uVar6 + (param_3 * uVar7 >> 0x10);
  if (uVar12 <= uVar6 && uVar6 - uVar12 != 0) {
    iVar11 = iVar11 + 0x10000;
  }
  uVar6 = iVar11 + (uVar12 >> 0x10);
  uVar13 = uVar12 * 0x10000 + (param_3 * uVar7 & 0xffff);
  uVar9 = uVar4 * uVar8;
  iVar11 = uVar2 * uVar4;
  uVar12 = uVar2 * uVar7 + uVar9 + (uVar8 * uVar7 >> 0x10);
  if (uVar12 <= uVar9 && uVar9 - uVar12 != 0) {
    iVar11 = iVar11 + 0x10000;
  }
  uVar2 = local_38 + (uVar15 >> 0x10) + uVar10;
  uVar10 = (uint)(uVar2 < uVar10);
  uVar9 = (uVar8 * uVar7 & 0xffff) + uVar12 * 0x10000 + uVar3;
  uVar4 = uVar9 + uVar10;
  uVar2 = uVar2 + uVar13;
  uVar7 = (uint)(uVar2 < uVar13);
  uVar14 = uVar6 + uVar4;
  uVar13 = uVar7 + uVar14;
  uVar8 = (uint)((uVar2 * 0x200 | uVar15 * 0x10000 + (param_3 * param_1 & 0xffff)) != 0);
  iVar11 = (uint)(uVar9 < uVar3 || uVar4 < uVar10) + (uVar12 >> 0x10) +
           (uint)(uVar14 < uVar6 || uVar13 < uVar7) + iVar11;
  uVar7 = uVar13 >> 0x17 | iVar11 * 0x200;
  uVar6 = uVar8 | uVar2 >> 0x17 | uVar13 * 0x200;
  if (iVar11 * 0x10000 < 0) {
    uVar6 = uVar8 | uVar2 >> 0x17 & 1 | uVar6 >> 1 | (uVar13 >> 0x17) << 0x1f;
    uVar7 = uVar7 >> 1;
  }
  else {
    local_3c = local_40;
  }
  uVar12 = local_3c + 0x3ff;
  if (0 < (int)uVar12) {
    uVar8 = uVar6;
    if (((uVar6 & 7) != 0) && ((uVar6 & 0xf) != 4)) {
      uVar8 = uVar6 + 4;
      uVar7 = uVar7 + (uVar8 < uVar6);
    }
    if ((int)(uVar7 << 7) < 0) {
      uVar7 = uVar7 & DAT_000080c8;
      uVar12 = local_3c + 0x400;
    }
    if ((int)uVar12 < 0x7ff) {
      uVar6 = uVar8 >> 3 | uVar7 << 0x1d;
      uVar7 = (uVar7 << 9) >> 0xc;
      uVar12 = uVar12 & 0x7ff;
    }
    else {
      uVar12 = 0x7ff;
      uVar7 = 0;
      uVar6 = 0;
    }
    goto LAB_00007de8;
  }
  uVar8 = 1 - uVar12;
  if (0x38 < (int)uVar8) {
    uVar12 = 0;
    uVar7 = 0;
    uVar6 = 0;
    goto LAB_00007de8;
  }
  if ((int)uVar8 < 0x20) {
    uVar6 = (uint)(uVar6 << (local_3c + 0x41eU & 0xff) != 0);
    uVar10 = uVar7 << (local_3c + 0x41eU & 0xff) | uVar6 >> (uVar8 & 0xff);
    uVar12 = uVar10 | uVar6;
    uVar7 = uVar7 >> (uVar8 & 0xff);
    if (((uVar10 & 7 | uVar6) != 0) && ((uVar10 & 0xf | uVar6) != 4)) {
LAB_00008142:
      uVar7 = uVar7 + (uVar12 + 4 < uVar12);
      uVar12 = uVar12 + 4;
    }
    if ((int)(uVar7 << 8) < 0) {
      uVar12 = 1;
      uVar7 = 0;
      uVar6 = 0;
      goto LAB_00007de8;
    }
LAB_000081ee:
    uVar6 = uVar7 << 0x1d;
    uVar7 = (uVar7 << 9) >> 0xc;
  }
  else {
    uVar10 = uVar7 >> (-uVar12 - 0x1f & 0xff);
    if (uVar8 != 0x20) {
      uVar6 = uVar6 | uVar7 << (local_3c + 0x43eU & 0xff);
    }
    uVar8 = (uint)(uVar6 != 0);
    uVar12 = uVar10 | uVar8;
    uVar7 = 0;
    uVar6 = uVar10 & 7 | uVar8;
    if ((uVar10 & 7 | uVar8) != 0) {
      uVar7 = 0;
      if ((uVar10 & 0xf | uVar8) != 4) goto LAB_00008142;
      goto LAB_000081ee;
    }
  }
  uVar6 = uVar6 | uVar12 >> 3;
  uVar12 = 0;
LAB_00007de8:
  return CONCAT44(uVar12 << 0x14 | uVar7 | (param_4 ^ param_2) & 0x80000000,uVar6);
}




undefined8 FUN_00008208(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_2c;
  
  uVar5 = param_1 >> 0x1d;
  local_2c = param_1 * 8;
  uVar7 = (param_4 << 1) >> 0x15;
  uVar6 = uVar5 | (param_2 << 0xc) >> 9;
  uVar1 = (param_4 << 0xc) >> 9;
  uVar8 = param_3 >> 0x1d;
  uVar9 = uVar8 | uVar1;
  uVar12 = param_3 * 8;
  uVar11 = (param_2 << 1) >> 0x15;
  uVar10 = -((int)param_2 >> 0x1f);
  uVar3 = -((int)param_4 >> 0x1f);
  if (uVar7 == 0x7ff) {
    if ((uVar9 | uVar12) == 0) {
      uVar4 = uVar3 ^ 1;
      if (uVar10 != uVar4) goto LAB_00008260;
LAB_0000843e:
      uVar13 = DAT_00008684 + uVar11;
LAB_00008444:
      if (uVar13 == 0) {
        uVar3 = uVar11 + 1;
        if ((uVar3 & 0x7fe) == 0) {
          if (uVar11 == 0) {
            uVar13 = 0;
            if ((uVar6 | local_2c) == 0) {
              uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
              uVar5 = param_4 & 0xfffff;
            }
            else {
              if ((uVar9 | uVar12) != 0) {
                uVar8 = local_2c + uVar12;
                uVar5 = uVar6 + uVar9 + (uint)(uVar8 < local_2c);
                if ((int)(uVar5 * 0x100) < 0) {
                  uVar11 = 1;
                  uVar5 = uVar5 & DAT_00008944;
                }
                goto LAB_00008504;
              }
              uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
              uVar5 = param_2 & 0xfffff;
            }
            goto LAB_0000851c;
          }
          if ((uVar6 | local_2c) == 0) goto LAB_00008842;
          if ((uVar9 | uVar12) == 0) goto LAB_00008694;
          uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
          uVar5 = param_2 & 0xfffff;
          if (((param_2 & 0x80000) != 0) && ((uVar1 & 0x400000) == 0)) {
            uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
            uVar5 = param_4 & 0xfffff;
            uVar10 = uVar4;
          }
          goto LAB_00008598;
        }
        if (uVar3 != 0x7ff) {
          uVar5 = uVar6 + uVar9 + (uint)(local_2c + uVar12 < local_2c);
          uVar8 = uVar5 * -0x80000000 | local_2c + uVar12 >> 1;
          uVar5 = uVar5 >> 1;
          uVar11 = uVar3;
          goto LAB_00008504;
        }
      }
      else {
        uVar13 = uVar7 - uVar11;
        if (uVar11 == 0) {
          if ((uVar6 | local_2c) == 0) {
            uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
            uVar5 = param_4 & 0xfffff;
            goto LAB_00008514;
          }
          uVar11 = uVar13 - 1;
          if (uVar13 == 1) {
            uVar5 = uVar6 + uVar9 + (uint)(local_2c + uVar12 < uVar12);
            goto LAB_000084fa;
          }
          if (uVar13 == 0x7ff) {
            uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
            uVar5 = param_4 & 0xfffff;
            goto LAB_00008598;
          }
        }
        else {
          if (uVar7 == 0x7ff) {
LAB_00008842:
            uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
            uVar5 = param_4 & 0xfffff;
            goto LAB_00008598;
          }
          uVar6 = uVar6 | 0x800000;
          uVar11 = uVar13;
        }
        if ((int)uVar11 < 0x39) {
          if ((int)uVar11 < 0x20) {
            uVar8 = uVar6 << (0x20 - uVar11 & 0xff) | local_2c >> (uVar11 & 0xff) |
                    (uint)(local_2c << (0x20 - uVar11 & 0xff) != 0);
            uVar9 = uVar9 + (uVar6 >> (uVar11 & 0xff));
          }
          else {
            if (uVar11 != 0x20) {
              local_2c = local_2c | uVar6 << (0x40 - uVar11 & 0xff);
            }
            uVar8 = (uint)(local_2c != 0) | uVar6 >> (uVar11 - 0x20 & 0xff);
          }
        }
        else {
          uVar8 = (uint)((local_2c | uVar6) != 0);
        }
        uVar8 = uVar8 + uVar12;
        uVar5 = (uVar8 < uVar12) + uVar9;
        uVar11 = uVar7;
LAB_0000853e:
        if (-1 < (int)(uVar5 << 8)) {
LAB_00008504:
          uVar1 = uVar8;
          if ((uVar8 & 7) != 0) goto LAB_00008324;
          goto LAB_0000850a;
        }
        uVar11 = uVar11 + 1;
        if (uVar11 != 0x7ff) goto LAB_0000869c;
      }
LAB_0000854e:
      uVar13 = 0x7ff;
      uVar5 = 0;
      uVar12 = 0;
      goto LAB_0000835a;
    }
    uVar4 = uVar3;
    if (uVar10 == uVar3) goto LAB_0000843e;
    uVar13 = DAT_00008684 + uVar11;
LAB_000083d8:
    if (uVar13 != 0) {
      uVar13 = uVar7 - uVar11;
      if (uVar11 == 0) {
        if ((uVar6 | local_2c) == 0) {
          uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
          uVar5 = param_4 & 0xfffff;
          uVar10 = uVar3;
          goto LAB_00008514;
        }
        uVar10 = uVar13 - 1;
        if (uVar13 == 1) {
          uVar8 = uVar12 + param_1 * -8;
          uVar11 = 1;
          uVar5 = (uVar9 - uVar6) - (uint)(uVar12 < uVar8);
          uVar10 = uVar3;
          goto LAB_000082c6;
        }
        if (uVar13 == 0x7ff) goto LAB_00008804;
      }
      else {
        if (uVar7 == 0x7ff) {
          uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
          uVar5 = param_4 & 0xfffff;
          uVar10 = uVar3;
          goto LAB_00008598;
        }
        uVar6 = uVar6 | 0x800000;
        uVar10 = uVar13;
      }
      if ((int)uVar10 < 0x39) {
        if ((int)uVar10 < 0x20) {
          uVar9 = uVar9 - (uVar6 >> (uVar10 & 0xff));
          uVar8 = (uint)(local_2c << (0x20 - uVar10 & 0xff) != 0) |
                  uVar6 << (0x20 - uVar10 & 0xff) | local_2c >> (uVar10 & 0xff);
        }
        else {
          if (uVar10 != 0x20) {
            local_2c = local_2c | uVar6 << (0x40 - uVar10 & 0xff);
          }
          uVar8 = (uint)(local_2c != 0) | uVar6 >> (uVar10 - 0x20 & 0xff);
        }
      }
      else {
        uVar8 = (uint)((local_2c | uVar6) != 0);
      }
      uVar8 = uVar12 - uVar8;
      uVar5 = uVar9 - (uVar12 < uVar8);
      uVar10 = uVar3;
      uVar11 = uVar7;
LAB_000082c6:
      if ((int)(uVar5 << 8) < 0) {
        uVar5 = uVar5 & 0x7fffff;
        goto LAB_000082d2;
      }
      goto LAB_00008504;
    }
    uVar13 = 0;
    if ((uVar11 + 1 & 0x7fe) != 0) {
      uVar8 = local_2c + param_3 * -8;
      uVar5 = (uVar6 - uVar9) - (uint)(local_2c < uVar8);
      if ((int)(uVar5 * 0x100) < 0) {
        uVar8 = uVar12 + param_1 * -8;
        uVar5 = (uVar9 - uVar6) - (uint)(uVar12 < uVar8);
        uVar10 = uVar3;
      }
      else {
        uVar12 = uVar5 | uVar8;
        if (uVar12 == 0) goto LAB_00008678;
      }
LAB_000082d2:
      if (uVar5 == 0) {
        iVar2 = FUN_00008c6c(uVar8);
        uVar1 = iVar2 + 0x18;
        if ((int)uVar1 < 0x20) goto LAB_000082e4;
        uVar12 = uVar8 << (iVar2 - 8U & 0xff);
        uVar8 = 0;
      }
      else {
        iVar2 = FUN_00008c6c(uVar5);
        uVar1 = iVar2 - 8;
LAB_000082e4:
        uVar12 = uVar8 >> (0x20 - uVar1 & 0xff);
        uVar8 = uVar8 << (uVar1 & 0xff);
        uVar12 = uVar5 << (uVar1 & 0xff) | uVar12;
      }
      if ((int)uVar1 < (int)uVar11) {
        uVar11 = uVar11 - uVar1;
        uVar5 = DAT_00008680 & uVar12;
      }
      else {
        uVar3 = (uVar1 - uVar11) + 1;
        if (0x1f < (int)uVar3) {
          if (uVar3 != 0x20) {
            uVar8 = uVar8 | uVar12 << (0x40 - uVar3 & 0xff);
          }
          uVar5 = 0;
          uVar8 = (uint)(uVar8 != 0) | uVar12 >> ((uVar1 - uVar11) - 0x1f & 0xff);
          uVar11 = 0;
          goto LAB_00008504;
        }
        uVar5 = uVar12 >> (uVar3 & 0xff);
        uVar8 = (uint)(uVar8 << (0x20 - uVar3 & 0xff) != 0) |
                uVar12 << (0x20 - uVar3 & 0xff) | uVar8 >> (uVar3 & 0xff);
        uVar11 = 0;
      }
      goto LAB_00008320;
    }
    if (uVar11 == 0) {
      if ((uVar6 | local_2c) != 0) {
        if ((uVar9 | uVar12) == 0) {
          uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
          uVar5 = param_2 & 0xfffff;
          goto LAB_0000851c;
        }
        uVar8 = local_2c + param_3 * -8;
        uVar5 = (uVar6 - uVar9) - (uint)(local_2c < uVar8);
        if (-1 < (int)(uVar5 * 0x100)) {
          if ((uVar8 | uVar5) == 0) {
            uVar12 = 0;
            goto LAB_00008678;
          }
          goto LAB_00008504;
        }
        uVar8 = uVar12 + param_1 * -8;
        uVar5 = (uVar9 - uVar6) - (uint)(uVar12 < uVar8);
        uVar10 = uVar3;
        goto LAB_00008320;
      }
      if ((uVar9 | uVar12) == 0) {
        uVar12 = 0;
LAB_00008678:
        uVar5 = 0;
        uVar10 = 0;
      }
      else {
        uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
        uVar5 = param_4 & 0xfffff;
        uVar10 = uVar3;
      }
      goto LAB_0000851c;
    }
    if ((uVar6 | local_2c) != 0) {
      if ((uVar9 | uVar12) == 0) goto LAB_000087b4;
      uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
      uVar5 = param_2 & 0xfffff;
      if (((param_2 & 0x80000) != 0) && ((uVar1 & 0x400000) == 0)) {
        uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
        uVar5 = param_4 & 0xfffff;
        uVar10 = uVar3;
      }
      goto LAB_00008598;
    }
    if ((uVar9 | uVar12) != 0) {
LAB_00008804:
      uVar12 = param_3 & 0x1fffffff | uVar8 << 0x1d;
      uVar5 = param_4 & 0xfffff;
      uVar10 = uVar3;
      goto LAB_00008598;
    }
    uVar10 = 0;
    uVar5 = 0x80000;
    uVar12 = 0;
  }
  else {
    uVar4 = uVar3 ^ 1;
    if (uVar10 == uVar4) {
      uVar13 = uVar11 - uVar7;
      if ((int)uVar13 < 1) goto LAB_00008444;
      if (uVar7 != 0) {
        if (uVar11 == 0x7ff) {
LAB_00008694:
          uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
          uVar5 = param_2 & 0xfffff;
          goto LAB_00008598;
        }
        uVar9 = uVar9 | 0x800000;
        uVar1 = uVar13;
LAB_00008394:
        if ((int)uVar1 < 0x39) {
          if ((int)uVar1 < 0x20) {
            uVar8 = uVar9 << (0x20 - uVar1 & 0xff) | uVar12 >> (uVar1 & 0xff) |
                    (uint)(uVar12 << (0x20 - uVar1 & 0xff) != 0);
            uVar6 = uVar6 + (uVar9 >> (uVar1 & 0xff));
          }
          else {
            if (uVar1 != 0x20) {
              uVar12 = uVar9 << (0x40 - uVar1 & 0xff) | uVar12;
            }
            uVar8 = (uint)(uVar12 != 0) | uVar9 >> (uVar1 - 0x20 & 0xff);
          }
        }
        else {
          uVar8 = (uint)((uVar9 | uVar12) != 0);
        }
        uVar8 = uVar8 + local_2c;
        uVar5 = (uVar8 < local_2c) + uVar6;
        goto LAB_0000853e;
      }
      if ((uVar9 | uVar12) == 0) {
        uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
        uVar5 = param_2 & 0xfffff;
        goto LAB_00008514;
      }
      uVar1 = uVar13 - 1;
      if (uVar13 != 1) {
        if (uVar13 != 0x7ff) goto LAB_00008394;
        goto LAB_00008694;
      }
      uVar5 = uVar6 + uVar9 + (uint)(local_2c + uVar12 < local_2c);
LAB_000084fa:
      uVar8 = local_2c + uVar12;
      uVar11 = 2;
      if (-1 < (int)(uVar5 << 8)) {
        uVar11 = 1;
        goto LAB_00008504;
      }
LAB_0000869c:
      uVar8 = uVar8 & 1 | uVar8 >> 1 | (uVar5 & DAT_00008944) << 0x1f;
      uVar5 = (uVar5 & DAT_00008944) >> 1;
LAB_00008320:
      uVar1 = uVar8;
      if ((uVar8 & 7) != 0) {
LAB_00008324:
        uVar8 = uVar1;
        if ((uVar1 & 0xf) != 4) {
          uVar8 = uVar1 + 4;
          uVar5 = uVar5 + (uVar8 < uVar1);
        }
      }
      if ((int)(uVar5 << 8) < 0) {
        if (uVar11 + 1 != 0x7ff) {
          uVar12 = (DAT_00008680 & uVar5) << 0x1d | uVar8 >> 3;
          uVar5 = ((DAT_00008680 & uVar5) << 9) >> 0xc;
          uVar13 = uVar11 + 1 & 0x7ff;
          goto LAB_0000835a;
        }
        goto LAB_0000854e;
      }
LAB_0000850a:
      uVar12 = uVar8 >> 3 | uVar5 << 0x1d;
      uVar5 = uVar5 >> 3;
      uVar13 = uVar11;
    }
    else {
LAB_00008260:
      uVar3 = uVar3 ^ 1;
      uVar13 = uVar11 - uVar7;
      if ((int)uVar13 < 1) goto LAB_000083d8;
      if (uVar7 != 0) {
        if (uVar11 == 0x7ff) {
LAB_000087b4:
          uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
          uVar5 = param_2 & 0xfffff;
          goto LAB_00008598;
        }
        uVar9 = uVar9 | 0x800000;
        uVar1 = uVar13;
LAB_00008288:
        if ((int)uVar1 < 0x39) {
          if ((int)uVar1 < 0x20) {
            uVar8 = uVar9 << (0x20 - uVar1 & 0xff) | uVar12 >> (uVar1 & 0xff) |
                    (uint)(uVar12 << (0x20 - uVar1 & 0xff) != 0);
            uVar6 = uVar6 - (uVar9 >> (uVar1 & 0xff));
          }
          else {
            if (uVar1 != 0x20) {
              uVar12 = uVar9 << (0x40 - uVar1 & 0xff) | uVar12;
            }
            uVar8 = (uint)(uVar12 != 0) | uVar9 >> (uVar1 - 0x20 & 0xff);
          }
        }
        else {
          uVar8 = (uint)((uVar9 | uVar12) != 0);
        }
        uVar8 = local_2c - uVar8;
        uVar5 = uVar6 - (local_2c < uVar8);
        goto LAB_000082c6;
      }
      if ((uVar9 | uVar12) != 0) {
        uVar1 = uVar13 - 1;
        if (uVar13 == 1) {
          uVar8 = local_2c + param_3 * -8;
          uVar11 = 1;
          uVar5 = (uVar6 - uVar9) - (uint)(local_2c < uVar8);
          goto LAB_000082c6;
        }
        if (uVar13 == 0x7ff) goto LAB_00008694;
        goto LAB_00008288;
      }
      uVar12 = param_1 & 0x1fffffff | uVar5 << 0x1d;
      uVar5 = param_2 & 0xfffff;
    }
LAB_00008514:
    if (uVar13 != 0x7ff) {
LAB_0000851c:
      uVar5 = uVar5 & 0xfffff;
      uVar13 = uVar13 & 0x7ff;
      goto LAB_0000835a;
    }
LAB_00008598:
    if ((uVar12 | uVar5) == 0) {
      uVar12 = 0;
      uVar13 = 0x7ff;
      uVar5 = uVar12;
      goto LAB_0000835a;
    }
  }
  uVar13 = 0x7ff;
  uVar5 = uVar5 & 0xfffff | 0x80000;
LAB_0000835a:
  return CONCAT44(uVar13 << 0x14 | uVar5 | uVar10 << 0x1f,uVar12);
}




uint FUN_00008948(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 << 1) >> 0x15;
  uVar1 = 0;
  if (0x3fe < uVar3) {
    if (uVar3 < 0x41e) {
      uVar2 = param_2 & 0xfffff | 0x100000;
      if ((int)(0x433 - uVar3) < 0x20) {
        uVar2 = uVar2 << (uVar3 + DAT_000089a8 & 0xff) | param_1 >> (0x433 - uVar3 & 0xff);
      }
      else {
        uVar2 = uVar2 >> (0x413 - uVar3 & 0xff);
      }
      uVar1 = -uVar2;
      if (-1 < (int)param_2) {
        uVar1 = uVar2;
      }
    }
    else {
      uVar1 = DAT_000089a4 - ((int)param_2 >> 0x1f);
    }
  }
  return uVar1;
}




undefined8 FUN_000089ac(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    param_1 = 0;
    uVar2 = 0;
    uVar3 = 0;
    iVar4 = 0;
  }
  else {
    uVar3 = param_1 + ((int)param_1 >> 0x1f) ^ (int)param_1 >> 0x1f;
    param_1 = param_1 >> 0x1f;
    iVar1 = FUN_00008c6c(uVar3);
    if (iVar1 < 0xb) {
      iVar4 = uVar3 << (iVar1 + 0x15U & 0xff);
      uVar3 = uVar3 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar2 = 0x41eU - iVar1 & 0x7ff;
    }
    else {
      iVar4 = 0;
      uVar3 = uVar3 << (iVar1 - 0xbU & 0xff) & 0xfffff;
      uVar2 = 0x41eU - iVar1 & 0x7ff;
    }
  }
  return CONCAT44(uVar2 << 0x14 | uVar3 | param_1 << 0x1f,iVar4);
}




undefined8 FUN_00008a10(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    uVar3 = 0;
    uVar2 = 0;
    iVar4 = 0;
  }
  else {
    iVar1 = FUN_00008c6c();
    if (iVar1 < 0xb) {
      iVar4 = param_1 << (iVar1 + 0x15U & 0xff);
      uVar2 = param_1 >> (0xbU - iVar1 & 0xff) & 0xfffff;
      uVar3 = 0x41eU - iVar1 & 0x7ff;
    }
    else {
      iVar4 = 0;
      uVar2 = param_1 << (iVar1 - 0xbU & 0xff) & 0xfffff;
      uVar3 = 0x41eU - iVar1 & 0x7ff;
    }
  }
  return CONCAT44(uVar3 << 0x14 | uVar2,iVar4);
}




undefined8 FUN_00008a60(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (param_1 << 1) >> 0x18;
  uVar4 = param_1 & 0x7fffff;
  if ((uVar3 + 1 & 0xfe) == 0) {
    if (uVar3 == 0) {
      if (uVar4 == 0) {
        uVar3 = 0;
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_00008c6c(uVar4);
        if (iVar1 < 0xb) {
          uVar2 = uVar4 >> (0xbU - iVar1 & 0xff);
          uVar4 = uVar4 << (iVar1 + 0x15U & 0xff);
        }
        else {
          uVar2 = uVar4 << (iVar1 - 0xbU & 0xff);
          uVar4 = 0;
        }
        uVar2 = uVar2 & 0xfffff;
        uVar3 = 0x389U - iVar1 & 0x7ff;
      }
    }
    else if (uVar4 == 0) {
      uVar3 = 0x7ff;
      uVar2 = 0;
    }
    else {
      uVar2 = (param_1 << 9) >> 0xc | 0x80000;
      uVar4 = uVar4 << 0x1d;
      uVar3 = 0x7ff;
    }
  }
  else {
    uVar4 = uVar4 << 0x1d;
    uVar2 = (param_1 << 9) >> 0xc;
    uVar3 = uVar3 + 0x380;
  }
  return CONCAT44(uVar3 << 0x14 | uVar2 | param_1 & 0x80000000,uVar4);
}




uint FUN_00008ae8(uint param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  
  uVar4 = (param_2 << 1) >> 0x15;
  uVar1 = (param_2 << 0xc) >> 9 | param_1 >> 0x1d;
  uVar5 = param_1 << 3;
  if ((uVar4 + 1 & 0x7fe) == 0) {
    if (uVar4 == 0) {
      if ((uVar1 | uVar5) == 0) {
        uVar4 = 0;
        uVar1 = 0;
        goto LAB_00008b12;
      }
LAB_00008b22:
      bVar6 = 0;
      uVar1 = 0;
      goto LAB_00008b24;
    }
    if ((uVar5 | uVar1) != 0) {
      uVar4 = 0xff;
      uVar1 = uVar1 | 0x400000;
      goto LAB_00008b12;
    }
  }
  else {
    iVar7 = uVar4 + DAT_00008bec;
    if (iVar7 < 0xff) {
      if (iVar7 < 1) {
        if (iVar7 + 0x17 < 0 != SCARRY4(iVar7,0x17)) goto LAB_00008b22;
        uVar1 = uVar1 | 0x800000;
        uVar3 = 0x1e - iVar7;
        if ((int)uVar3 < 0x20) {
          uVar1 = (uint)(uVar5 << (uVar4 + DAT_00008bf4 & 0xff) != 0) |
                  uVar1 << (uVar4 + DAT_00008bf4 & 0xff) | uVar5 >> (uVar3 & 0xff);
        }
        else {
          if (uVar3 != 0x20) {
            uVar5 = uVar5 | uVar1 << (uVar4 + DAT_00008bf0 & 0xff);
          }
          uVar1 = (uint)(uVar5 != 0) | uVar1 >> (-iVar7 - 2U & 0xff);
        }
        iVar7 = 0;
        if ((uVar1 & 7) != 0) goto LAB_00008b54;
        bVar2 = 1;
        bVar6 = 0;
        if ((uVar1 & 0x4000000) == 0) goto LAB_00008b24;
LAB_00008b6c:
        uVar1 = (uVar1 << 6) >> 9;
        uVar4 = (uint)bVar2;
        goto LAB_00008b12;
      }
      uVar4 = (uint)((param_1 & 0x3ffffff) != 0);
      uVar1 = uVar4 | uVar1 << 3 | uVar5 >> 0x1d;
      if ((uVar4 | uVar5 >> 0x1d) != 0) {
LAB_00008b54:
        if ((uVar1 & 0xf) != 4) {
          uVar1 = uVar1 + 4;
        }
        if ((uVar1 & 0x4000000) != 0) {
          bVar2 = (char)iVar7 + 1;
          if (iVar7 == 0xfe) goto LAB_00008b0e;
          goto LAB_00008b6c;
        }
      }
      bVar6 = (byte)iVar7;
LAB_00008b24:
      uVar1 = (uVar1 << 6) >> 9;
      uVar4 = (uint)bVar6;
      goto LAB_00008b12;
    }
  }
LAB_00008b0e:
  uVar4 = 0xff;
  uVar1 = 0;
LAB_00008b12:
  return param_2 & 0x80000000 | uVar4 << 0x17 | uVar1;
}




undefined4 FUN_00008c58(void)

{
  int iVar1;
  
  iVar1 = FUN_00008cf8();
  if (iVar1 < 0) {
    return 0;
  }
  return 1;
}




int FUN_00008c6c(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x1c;
  if (0xffff < param_1) {
    param_1 = param_1 >> 0x10;
    iVar1 = 0xc;
  }
  if (0xff < param_1) {
    param_1 = param_1 >> 8;
    iVar1 = iVar1 + -8;
  }
  if (0xf < param_1) {
    param_1 = param_1 >> 4;
    iVar1 = iVar1 + -4;
  }
  return (uint)(byte)(&LAB_00008c98)[param_1] + iVar1;
}




int FUN_00008cf8(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 & 0x7fffff;
  uVar2 = (param_1 << 1) >> 0x18;
  uVar4 = param_2 & 0x7fffff;
  uVar3 = (param_2 << 1) >> 0x18;
  iVar1 = -((int)param_2 >> 0x1f);
  if (uVar2 == 0xff) {
    if (uVar5 != 0) {
      return -2;
    }
    if (uVar3 == 0xff) goto LAB_00008d36;
LAB_00008d4e:
    if ((uVar3 == 0) && (uVar4 == 0)) goto LAB_00008d26;
  }
  else {
    if (uVar3 == 0xff) {
LAB_00008d36:
      if (uVar4 != 0) {
        return -2;
      }
      if (uVar2 != 0) goto LAB_00008d22;
    }
    else {
      if (uVar2 != 0) goto LAB_00008d4e;
      if ((uVar3 == 0) && (uVar4 == 0)) {
        if (uVar5 == 0) {
          return 0;
        }
        goto LAB_00008d26;
      }
    }
    if (uVar5 == 0) goto LAB_00008d44;
  }
LAB_00008d22:
  if (-((int)param_1 >> 0x1f) != iVar1) {
LAB_00008d26:
    return (-((int)param_1 >> 0x1f) - 1U & 2) - 1;
  }
  if (uVar3 < uVar2) {
LAB_00008d70:
    return (-(uint)(iVar1 == 0) & 2) - 1;
  }
  if (uVar3 <= uVar2) {
    if (uVar4 < uVar5) goto LAB_00008d70;
    if (uVar4 <= uVar5) {
      return 0;
    }
  }
LAB_00008d44:
  if (-1 < (int)param_2) {
    return -1;
  }
  return iVar1;
}




uint * FUN_00008e08(uint *param_1,char param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  bool bVar4;
  
  if (((uint)param_1 & 3) != 0) {
    if (param_3 == 0) {
      return (uint *)0x0;
    }
    cVar1 = *(char *)param_1;
    param_3 = param_3 - 1;
    while( true ) {
      if (cVar1 == param_2) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if (((uint)param_1 & 3) == 0) break;
      bVar4 = param_3 == 0;
      param_3 = param_3 - 1;
      if (bVar4) {
        return (uint *)0x0;
      }
      cVar1 = *(char *)param_1;
    }
  }
  if (3 < param_3) {
    do {
      uVar2 = *param_1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      if ((uVar2 + 0xfefefeff & ~uVar2 & 0x80808080) != 0) goto LAB_00008e34;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
    } while (3 < param_3);
  }
  if (param_3 != 0) {
LAB_00008e34:
    if (*(char *)param_1 == param_2) {
      return param_1;
    }
    puVar3 = (uint *)((int)param_1 + param_3);
    while (param_1 = (uint *)((int)param_1 + 1), puVar3 != param_1) {
      if (*(char *)param_1 == param_2) {
        return param_1;
      }
    }
  }
  return (uint *)0x0;
}




void FUN_00008e8c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  
  uVar4 = param_3;
  if (0xf < param_3) {
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar6 = param_3 - 1;
      goto LAB_00008f06;
    }
    uVar4 = param_3 - 0x10 >> 4;
    puVar1 = param_1;
    puVar3 = param_2;
    do {
      uVar5 = *puVar3;
      puVar1[1] = puVar3[1];
      uVar7 = puVar3[3];
      *puVar1 = uVar5;
      puVar1[3] = uVar7;
      puVar1[2] = puVar3[2];
      puVar3 = puVar3 + 4;
      bVar8 = puVar1 != param_1 + uVar4 * 4;
      puVar1 = puVar1 + 4;
    } while (bVar8);
    iVar6 = uVar4 + 1;
    param_2 = param_2 + iVar6 * 4;
    uVar4 = param_3 & 0xf;
    param_1 = param_1 + iVar6 * 4;
    iVar6 = 0;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + iVar6) = *(undefined4 *)((int)param_2 + iVar6);
        iVar6 = iVar6 + 4;
      } while (3 < uVar4 - iVar6);
      iVar6 = (uVar4 - 4 >> 2) + 1;
      param_1 = param_1 + iVar6;
      param_2 = param_2 + iVar6;
      uVar4 = param_3 & 3;
    }
  }
  iVar6 = uVar4 - 1;
  if (uVar4 == 0) {
    return;
  }
LAB_00008f06:
  iVar2 = 0;
  do {
    *(undefined *)((int)param_1 + iVar2) = *(undefined *)((int)param_2 + iVar2);
    bVar8 = iVar6 != iVar2;
    iVar2 = iVar2 + 1;
  } while (bVar8);
  return;
}




void FUN_00008f30(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  bool bVar7;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)((int)param_2 + param_3))) {
    iVar2 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
    do {
      *(undefined *)((int)param_1 + iVar2) = *(undefined *)((int)param_2 + iVar2);
      bVar7 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar7);
    return;
  }
  uVar6 = param_3;
  if (0xf < param_3) {
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
      iVar2 = param_3 - 1;
      goto LAB_00008f5e;
    }
    uVar6 = param_3 - 0x10 >> 4;
    puVar4 = param_1;
    puVar5 = param_2;
    do {
      *puVar4 = *puVar5;
      puVar4[1] = puVar5[1];
      puVar4[2] = puVar5[2];
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 4;
      puVar4[3] = *puVar1;
      bVar7 = puVar4 != param_1 + uVar6 * 4;
      puVar4 = puVar4 + 4;
    } while (bVar7);
    iVar2 = uVar6 + 1;
    param_2 = param_2 + iVar2 * 4;
    uVar6 = param_3 & 0xf;
    param_1 = param_1 + iVar2 * 4;
    iVar2 = 0;
    if ((param_3 & 0xc) != 0) {
      do {
        *(undefined4 *)((int)param_1 + iVar2) = *(undefined4 *)((int)param_2 + iVar2);
        iVar2 = iVar2 + 4;
      } while (3 < uVar6 - iVar2);
      iVar2 = (uVar6 - 4 >> 2) + 1;
      param_1 = param_1 + iVar2;
      param_2 = param_2 + iVar2;
      uVar6 = param_3 & 3;
    }
  }
  iVar2 = uVar6 - 1;
  if (uVar6 == 0) {
    return;
  }
LAB_00008f5e:
  iVar3 = 0;
  do {
    *(undefined *)((int)param_1 + iVar3) = *(undefined *)((int)param_2 + iVar3);
    bVar7 = iVar2 != iVar3;
    iVar3 = iVar3 + 1;
  } while (bVar7);
  return;
}




void FUN_00008fe8(undefined4 *param_1,undefined param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  if (((uint)param_1 & 3) != 0) {
    uVar1 = param_3 - 1;
    puVar2 = param_1;
    if (param_3 == 0) {
      return;
    }
    while( true ) {
      param_1 = (undefined4 *)((int)puVar2 + 1);
      *(undefined *)puVar2 = param_2;
      param_3 = uVar1;
      if (((uint)param_1 & 3) == 0) break;
      bVar5 = uVar1 == 0;
      uVar1 = uVar1 - 1;
      puVar2 = param_1;
      if (bVar5) {
        return;
      }
    }
  }
  uVar1 = param_3;
  if (3 < param_3) {
    uVar3 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    if (0xf < param_3) {
      uVar4 = param_3 - 0x10 >> 4;
      puVar2 = param_1;
      do {
        *puVar2 = uVar3;
        puVar2[1] = uVar3;
        puVar2[2] = uVar3;
        puVar2[3] = uVar3;
        puVar2 = puVar2 + 4;
      } while (puVar2 != param_1 + uVar4 * 4 + 4);
      uVar1 = param_3 & 0xf;
      param_1 = param_1 + (uVar4 + 1) * 4;
      uVar4 = param_3 & 0xc;
      param_3 = uVar1;
      if (uVar4 == 0) goto joined_r0x0000906e;
    }
    uVar1 = param_3 - 4 >> 2;
    puVar2 = param_1;
    do {
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    } while (puVar2 != param_1 + uVar1 + 1);
    param_1 = param_1 + uVar1 + 1;
    uVar1 = param_3 & 3;
  }
joined_r0x0000906e:
  if (uVar1 != 0) {
    puVar2 = (undefined4 *)((int)param_1 + uVar1);
    do {
      *(undefined *)param_1 = param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
    } while (puVar2 != param_1);
  }
  return;
}




void FUN_000090a8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_2 == 0) {
    iVar1 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000090c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x24))(iVar1,param_2,*(undefined4 *)(param_1 + 0x10));
  return;
}



