#ifndef CREATEWINPROCESS_H
#define CREATEWINPROCESS_H

#include "WinInternal.h"

typedef struct _LXSS_MESSAGE_PORT_RECEIVE_OBJECT LXSS_MESSAGE_PORT_RECEIVE_OBJECT, *PLXSS_MESSAGE_PORT_RECEIVE_OBJECT;

typedef struct _LX_CREATE_PROCESS_RESULT {
    PROCESS_INFORMATION ProcInfo;
    ULONG LastError;
    BOOLEAN IsSubsystemGUI;
    HPCON hpCon;
} LX_CREATE_PROCESS_RESULT, *PLX_CREATE_PROCESS_RESULT;

NTSTATUS OpenAnonymousPipe(
    PHANDLE ReadPipeHandle,
    PHANDLE WritePipeHandle);

BOOL CreateWinProcess(
    PLXSS_MESSAGE_PORT_RECEIVE_OBJECT LxReceiveMsg,
    PLX_CREATE_PROCESS_RESULT ProcResult);

#endif //CREATEWINPROCESS_H