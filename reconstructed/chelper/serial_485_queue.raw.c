/* Ghidra decompilation of serial_485_queue.o */


void FUN_00010000(void)

{
  calloc(0x20c,1);
  return;
}




undefined4 background_thread(undefined4 *param_1)

{
  nice(-0x14);
  pollreactor_run(*param_1);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x408));
  if (param_1[0x41a] != 0) {
    param_1[0x41a] = 0;
    pthread_cond_signal((pthread_cond_t *)(param_1 + 0x40e));
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x408));
  return 0;
}




void kick_event(undefined4 *param_1)

{
  ssize_t sVar1;
  undefined auStack_1008 [4096];
  
  sVar1 = read(param_1[3],auStack_1008,0x1000);
  if (sVar1 < 0) {
    report_errno("pipe read");
  }
  pollreactor_update_timer(0,*param_1,0);
  return;
}




undefined8 command_event(int param_1)

{
  undefined uVar1;
  ssize_t sVar2;
  pthread_mutex_t *__mutex;
  size_t *__ptr;
  size_t __n;
  size_t sVar3;
  undefined local_218;
  undefined auStack_217 [511];
  
  __mutex = (pthread_mutex_t *)(param_1 + 0x1020);
  pthread_mutex_lock(__mutex);
  memset(&local_218,0,0x200);
  __ptr = *(size_t **)(param_1 + 0x106c);
  if (__ptr != (size_t *)0x0) {
    local_218 = 0xf7;
    memcpy(auStack_217,__ptr + 1,*__ptr);
    sVar3 = *__ptr;
    free(__ptr);
    *(undefined4 *)(param_1 + 0x106c) = 0;
    __n = sVar3 + 2;
    uVar1 = msgblock_485_crc8(auStack_217 + 1,auStack_217[1]);
    auStack_217[sVar3] = uVar1;
    if (__n != 0) {
      sVar2 = write(*(int *)(param_1 + 4),&local_218,__n);
      if (sVar2 < 0) {
        report_errno("write");
      }
      *(size_t *)(param_1 + 0x1084) = *(int *)(param_1 + 0x1084) + __n;
      pthread_mutex_unlock(__mutex);
      return DAT_000101a0;
    }
  }
  pthread_mutex_unlock(__mutex);
  return DAT_000101a0;
}




void FUN_000101a8(int param_1)

{
  ssize_t sVar1;
  
  sVar1 = write(param_1,&_LC2,1);
  if (-1 < sVar1) {
    return;
  }
  report_errno("pipe write");
  return;
}




void input_event(undefined4 *param_1)

{
  ssize_t sVar1;
  size_t *psVar2;
  size_t __n;
  size_t __n_00;
  int iVar3;
  pthread_mutex_t *__mutex;
  undefined4 *__src;
  
  sVar1 = read(param_1[1],(void *)((int)param_1 + param_1[0x406] + 0x14),0x1000 - param_1[0x406]);
  if (0 < sVar1) {
    __src = param_1 + 5;
    __n_00 = sVar1 + param_1[0x406];
    param_1[0x406] = __n_00;
    __mutex = (pthread_mutex_t *)(param_1 + 0x408);
    while (__n = msgblock_485_check(param_1 + 0x405,__src,__n_00), __n != 0) {
      if ((int)__n < 1) {
        pthread_mutex_lock(__mutex);
        param_1[0x423] = param_1[0x423] - __n;
        pthread_mutex_unlock(__mutex);
        __n = -__n;
      }
      else {
        pthread_mutex_lock(__mutex);
        param_1[0x422] = param_1[0x422] + __n;
        psVar2 = (size_t *)FUN_00010000();
        memcpy(psVar2 + 1,__src,__n);
        iVar3 = param_1[0x41a];
        *psVar2 = __n;
        param_1[0x41c] = psVar2;
        if (iVar3 != 0) {
          param_1[0x41a] = 0;
          pthread_cond_signal((pthread_cond_t *)(param_1 + 0x40e));
        }
        pthread_mutex_unlock(__mutex);
      }
      __n_00 = param_1[0x406] - __n;
      param_1[0x406] = __n_00;
      if (__n_00 != 0) {
        memmove(__src,(void *)((int)param_1 + __n + 0x14),__n_00);
        __n_00 = param_1[0x406];
      }
    }
    return;
  }
  if (sVar1 != 0) {
    report_errno(&_LC4);
    pollreactor_do_exit(*param_1);
    return;
  }
  errorf("Got EOF when reading from device");
  pollreactor_do_exit(*param_1);
  return;
}




undefined4 * serial_485_queue_alloc(undefined4 param_1,int param_2)

{
  undefined4 *__arg;
  int iVar1;
  undefined4 uVar2;
  
  __arg = (undefined4 *)calloc(0x1090,1);
  __arg[1] = param_1;
  __arg[2] = param_2;
  iVar1 = pipe(__arg + 3);
  if (iVar1 == 0) {
    uVar2 = pollreactor_alloc(2,1,__arg);
    *__arg = uVar2;
    pollreactor_add_fd(uVar2,0,param_1,input_event,param_2 == 0x66);
    pollreactor_add_fd(*__arg,1,__arg[3],kick_event,0);
    pollreactor_add_timer(*__arg,0,command_event);
    fd_set_non_blocking(param_1);
    fd_set_non_blocking(__arg[3]);
    fd_set_non_blocking(__arg[4]);
    iVar1 = pthread_mutex_init((pthread_mutex_t *)(__arg + 0x408),(pthread_mutexattr_t *)0x0);
    if (((iVar1 == 0) &&
        (iVar1 = pthread_cond_init((pthread_cond_t *)(__arg + 0x40e),(pthread_condattr_t *)0x0),
        iVar1 == 0)) &&
       (iVar1 = pthread_create(__arg + 0x407,(pthread_attr_t *)0x0,background_thread,__arg),
       iVar1 == 0)) {
      return __arg;
    }
  }
  report_errno(&_LC6,iVar1);
  return (undefined4 *)0x0;
}




void serial_485_queue_exit(undefined4 *param_1)

{
  int iVar1;
  
  pollreactor_do_exit(*param_1);
  FUN_000101a8(param_1[4]);
  iVar1 = pthread_join(param_1[0x407],(void **)0x0);
  if (iVar1 == 0) {
    return;
  }
  report_errno("pthread_join");
  return;
}




void serial_485_queue_free(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  iVar1 = pollreactor_is_exit(*param_1);
  if (iVar1 == 0) {
    serial_485_queue_exit(param_1);
  }
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x408));
  if ((void *)param_1[0x41b] != (void *)0x0) {
    free((void *)param_1[0x41b]);
    param_1[0x41b] = 0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x408));
  pollreactor_free(*param_1);
  free(param_1);
  return;
}




void serial_485_queue_send(int param_1,void *param_2,size_t param_3)

{
  size_t *psVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1020));
  psVar1 = (size_t *)FUN_00010000();
  memcpy(psVar1 + 1,param_2,param_3);
  *psVar1 = param_3;
  *(size_t **)(param_1 + 0x106c) = psVar1;
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1020));
  FUN_000101a8(*(undefined4 *)(param_1 + 0x10));
  return;
}




void serial_485_queue_pull(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *__ptr;
  size_t *psVar2;
  pthread_mutex_t *__mutex;
  
  __mutex = (pthread_mutex_t *)(param_1 + 0x408);
  pthread_mutex_lock(__mutex);
  while( true ) {
    psVar2 = (size_t *)param_1[0x41c];
    if (psVar2 != (size_t *)0x0) {
      memcpy(param_2 + 1,psVar2 + 1,*psVar2);
      __ptr = (undefined4 *)param_1[0x41c];
      *param_2 = *__ptr;
      free(__ptr);
      param_1[0x41c] = 0;
      pthread_mutex_unlock(__mutex);
      return;
    }
    iVar1 = pollreactor_is_exit(*param_1);
    if (iVar1 != 0) break;
    param_1[0x41a] = 1;
    iVar1 = pthread_cond_wait((pthread_cond_t *)(param_1 + 0x40e),__mutex);
    if (iVar1 != 0) {
      report_errno("pthread_cond_wait");
    }
  }
  *param_2 = 0xffffffff;
  pthread_mutex_unlock(__mutex);
  return;
}




void serial_485_queue_get_stats(void *param_1,char *param_2,size_t param_3)

{
  undefined auStack_10a8 [4228];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  pthread_mutex_lock((pthread_mutex_t *)((int)param_1 + 0x1020));
  memcpy(auStack_10a8,param_1,0x1090);
  pthread_mutex_unlock((pthread_mutex_t *)((int)param_1 + 0x1020));
  snprintf(param_2,param_3,"bytes_write=%u bytes_read=%u bytes_invalid=%u",local_24,local_20,
           local_1c);
  return;
}




int serial_485_queue_extract_old(int param_1,int param_2,int **param_3,int param_4)

{
  int iVar1;
  int ***pppiVar2;
  int *****pppppiVar3;
  int ****ppppiVar4;
  int iVar5;
  int ****ppppiVar6;
  int *****__ptr;
  int **ppiVar7;
  int ***local_30;
  int ***local_2c;
  int *****local_28;
  int *****local_24;
  
  local_2c = (int ***)&local_30;
  if (param_2 == 0) {
    ppppiVar6 = (int ****)(param_1 + 0x107c);
  }
  else {
    ppppiVar6 = (int ****)(param_1 + 0x1074);
  }
  iVar5 = 100;
  local_30 = (int ***)&local_30;
  do {
    iVar1 = FUN_00010000();
    iVar5 = iVar5 + -1;
    pppiVar2 = (int ***)(iVar1 + 0x204);
    local_30[1] = (int **)pppiVar2;
    *(int ****)(iVar1 + 0x204) = local_30;
    *(int *****)(iVar1 + 0x208) = &local_30;
    local_30 = pppiVar2;
  } while (iVar5 != 0);
  local_28 = (int *****)&local_28;
  local_24 = (int *****)&local_28;
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1020));
  ppppiVar4 = (int ****)*ppppiVar6;
  if (ppppiVar6 != ppppiVar4) {
    pppppiVar3 = (int *****)ppppiVar6[1];
    ppppiVar4[1] = (int ***)local_24;
    *local_24 = ppppiVar4;
    *pppppiVar3 = (int ****)&local_28;
    local_24 = pppppiVar3;
  }
  pppiVar2 = local_2c;
  *ppppiVar6 = (int ***)ppppiVar6;
  iVar5 = 0;
  ppppiVar6[1] = (int ***)ppppiVar6;
  if ((int ****)local_30 != &local_30) {
    local_30[1] = (int **)ppppiVar6;
    *ppppiVar6 = local_30;
    *local_2c = (int **)ppppiVar6;
    ppppiVar6[1] = pppiVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1020));
  do {
    ppiVar7 = param_3;
    if ((int ******)local_28 == &local_28) {
      return iVar5;
    }
    while( true ) {
      pppppiVar3 = local_28;
      __ptr = local_28 + -0x81;
      ppppiVar4 = local_28[-0x81];
      ppppiVar6 = ppppiVar4;
      if (ppppiVar4 != (int ****)0x0) {
        ppppiVar6 = (int ****)(iVar5 - param_4);
      }
      param_3 = ppiVar7;
      if ((int)ppppiVar6 < 0 != (ppppiVar4 != (int ****)0x0 && SBORROW4(iVar5,param_4))) {
        iVar5 = iVar5 + 1;
        memcpy(ppiVar7 + 1,local_28 + -0x80,(size_t)ppppiVar4);
        param_3 = ppiVar7 + 0x81;
        *ppiVar7 = (int *)pppppiVar3[-0x81];
      }
      ppppiVar6 = *pppppiVar3;
      ppppiVar4 = pppppiVar3[1];
      ppppiVar6[1] = (int ***)ppppiVar4;
      *ppppiVar4 = (int ***)ppppiVar6;
      if (__ptr == (int *****)0x0) break;
      free(__ptr);
      ppiVar7 = param_3;
      if ((int ******)local_28 == &local_28) {
        return iVar5;
      }
    }
  } while( true );
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int nice(int __inc)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_run(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_signal(pthread_cond_t *__cond)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_update_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void report_errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void msgblock_485_crc8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void msgblock_485_check(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void errorf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_do_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pipe(int *__pipedes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_add_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_add_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void fd_set_non_blocking(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_init(pthread_cond_t *__cond,pthread_condattr_t *__cond_attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_is_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */

void pollreactor_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



