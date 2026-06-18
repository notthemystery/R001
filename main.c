#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#if defined(_WIN32)
    #include <windows.h>
    int win = 1;
    int linux_os = 0;
    int android = 0;
#elif defined(__ANDROID__)
    #define ANDROID 1
    #include <spawn.h>
    extern char **environ;
    int win = 0;
    int linux_os = 0;
    int android = 1; 
#elif defined(__linux__)
    #include <spawn.h>
    extern char **environ;
    int win = 0;
    int linux_os = 1;
    int android = 0;
#else
    int win = 0;
    int linux_os = 0;
    int android = 0;
#endif

int showexploits() {
    int choice = 0;

    if (win == 1) {
        printf("1.RoguePlanet Exploit\n");
        printf("\n");
        printf("Enter Choice : ");
        scanf("%d", &choice); 
        return choice;    
    } else if (linux_os == 1) {
        printf("2.CopyFail Exploit\n");
        printf("3.DirtyFrag Exploit\n");
        printf("4.DirtyFrag2 Exploit\n");
        printf("\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        return choice;
    } else if (android == 1) {
        printf("5.MTK-SU Exploit\n");
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
    
    int choice = showexploits();
    
    if (choice == 0) {
        return 0;
    } 
    
#if defined(_WIN32)
    if (choice == 1) {
        STARTUPINFOA si = { 0 };
        PROCESS_INFORMATION pi = { 0 };
        si.cb = sizeof(si);
        if (CreateProcessA("Exploits/Windows/RoguePlanet.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    }
#elif defined(__ANDROID__)
    if (choice == 5) {
        char *argv[] = { "Exploits/Android/MTK-SU", NULL };
        if (posix_spawn(&pid, "Exploits/Android/MTK-SU", NULL, NULL, argv, environ) == 0) {
            waitpid(pid, &status, 0);
        }
    }
#elif defined(__linux__)
    if (choice == 2) {
        char *argv[] = { "Exploits/Linux/CopyFail", NULL };
        if (posix_spawn(&pid, "Exploits/Linux/CopyFail", NULL, NULL, argv, environ) == 0) {
            waitpid(pid, &status, 0);
        }
    } else if (choice == 3) {
        char *argv[] = { "Exploits/Linux/DirtyFrag", NULL };
        if (posix_spawn(&pid, "Exploits/Linux/DirtyFrag", NULL, NULL, argv, environ) == 0) {
            waitpid(pid, &status, 0);
        }
    } else if (choice == 4) {
        char *argv[] = { "Exploits/Linux/DirtyFrag2", NULL };
        if (posix_spawn(&pid, "Exploits/Linux/DirtyFrag2", NULL, NULL, argv, environ) == 0) {
            waitpid(pid, &status, 0);
        }
    }
#endif

    return 0;
}