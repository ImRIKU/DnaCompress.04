#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

extern int avgUsage;

int get_cpu_usage(int main_pid) {
    char cmd[128];
    char buffer[128];
    FILE* fp;
    char pid[16];

    sprintf(pid, "%d", main_pid);

    // Step 2: Find the CPU usage of the process using the PID
    snprintf(cmd, sizeof(cmd), "ps -p %s -o %%cpu", pid);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return 0;
    }
    
    // Skip the header line
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        printf("Failed to retrieve CPU usage\n");
        pclose(fp);
        return 0;
    }

    // Get the CPU usage
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        //printf("CPU usage of the process: %s%%\n", buffer);
        avgUsage = atoi(buffer);
        
    } 
    else {
        printf("Failed to retrieve CPU usage\n");
    }
    int usage = avgUsage;
    pclose(fp);
    return usage;
}