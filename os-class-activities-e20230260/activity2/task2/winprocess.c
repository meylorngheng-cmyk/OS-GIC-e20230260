/* winprocess.c — Process creation on Windows using CreateProcess() */
#include <stdio.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent process (PID: %lu) — creating child...\n", GetCurrentProcessId());

    if (!CreateProcess(
            "C:\\Windows\\System32\\mspaint.exe",
            NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        fprintf(stderr, "CreateProcess failed (error %lu).\n", GetLastError());
        return 1;
    }

    printf("Child process created!\n");
    printf("  Child PID:       %lu\n", pi.dwProcessId);
    printf("  Child Thread ID: %lu\n", pi.dwThreadId);

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
