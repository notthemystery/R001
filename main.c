#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#if defined(_WIN32)
    #include <windows.h>
    int win = 1;
    int linux_os = 0;
#elif defined(__linux__)
    #include <spawn.h>
    extern char **environ;
    int win = 0;
    int linux_os = 1;
#else
    int win = 0;
    int linux_os = 0;
    int android = 0;
#endif

int showexploits() {
    int choice = 0;

    if (win == 1) {
        printf("1.MiniPlasma Exploit (Windows 10/11)\n");
        printf("2.GreenPlasma Exploit (Windows 10/11)\n");
        printf("3.RedSun Exploit (Windows 10/11)\n");
        printf("4.CallbackHell Exploit (Windows 8/8.1)\n");
        printf("For these to work your defender must be prior to version 4.18.26040.7\n");
        printf("\n");
        printf("Enter Choice : ");
        scanf("%d", &choice); 
        return choice;    
    } else if (linux_os == 1) {
        printf("1.CopyFail Exploit\n");
        printf("2.DirtyFrag Exploit\n");
        printf("3.DirtyFrag2 Exploit\n");
        printf("These all work in kernel 4.14 up to 6.19.12 (except 6.12.85, 6.6.137, 6.1.170, 5.15.204, 5.10.254 and musl OSes.)\n");
        printf("\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        return choice;
    }
    return 0;
}

int main() {
#ifndef _WIN32
    pid_t pid;
    int status;
#endif

    printf("########::::'#####:::::'#####::::::'##:::\n");
    printf("##.... ##::'##.. ##:::'##.. ##:::'####:::\n");
    printf("##:::: ##:'##:::: ##:'##:::: ##::.. ##:::\n");
    printf("########:: ##:::: ##: ##:::: ##:::: ##:::\n");
    printf("##.. ##::: ##:::: ##: ##:::: ##:::: ##:::\n");
    printf("##::. ##::. ##:: ##::. ##:: ##::::: ##:::\n");
    printf("##:::. ##::. #####::::. #####::::'######:\n");
    printf("..:::::..::::.....::::::.....:::::......::\n");
    printf("\n");
    printf("Advanced Security and Recovery Tool");
    printf("By The Mystery (notthemystery)");
    printf("\n");
    
    int choice = showexploits();
    
    if (choice == 0) {
        return 0;
    } 
    
#if defined(_WIN32)
    if (choice == 1) {
        STARTUPINFOA si = { 0 };
        PROCESS_INFORMATION pi = { 0 };
        si.cb = sizeof(si);
        if (CreateProcessA("Exploits/Windows/MiniPlasma.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    } else if (choice == 2) {
        STARTUPINFOA si = { 0 };
        PROCESS_INFORMATION pi = { 0 };
        si.cb = sizeof(si);
        if (CreateProcessA("Exploits/Windows/GreenPlasma.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    } else if (choice == 3) {
        STARTUPINFOA si = { 0 };
        PROCESS_INFORMATION pi = { 0 };
        si.cb = sizeof(si);
        if (CreateProcessA("Exploits/Windows/RedSun.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    } else if (choice == 4) {
        STARTUPINFOA si = { 0 };
        PROCESS_INFORMATION pi = { 0 };
        si.cb = sizeof(si);
        if (CreateProcessA("Exploits/Windows/CallbackHell.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    }
#elif defined(__linux__)
    if (choice == 1) {
        char *argv[] = { "Exploits/Linux/CopyFail", NULL };
        if (posix_spawn(&pid, "Exploits/Linux/CopyFail", NULL, NULL, argv, environ) == 0) {
            waitpid(pid, &status, 0);
        }
    } else if (choice == 2) {
        char *argv[] = { "Exploits/Linux/DirtyFrag", NULL };
        if (posix_spawn(&pid, "Exploits/Linux/DirtyFrag", NULL, NULL, argv, environ) == 0) {
            waitpid(pid, &status, 0);
        }
    } else if (choice == 3) {
        char *argv[] = { "Exploits/Linux/DirtyFrag2", NULL };
        if (posix_spawn(&pid, "Exploits/Linux/DirtyFrag2", NULL, NULL, argv, environ) == 0) {
            waitpid(pid, &status, 0);
        }
    }
#endif

    return 0;
}
