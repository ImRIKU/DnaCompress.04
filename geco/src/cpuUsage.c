#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>

extern int avgUsage;
extern volatile bool keep_running;

int arr[60];
int i,count=0;

void iniArr(){
    for(i=0;i<60;i++){
        arr[i]=0;
    }
}

void setUsage(){
    if(count == 0){
        avgUsage = 0;
        return;
    }
    int sum=0;
    for(i=0;i<60;i++){
        sum+=arr[i];
    }
    avgUsage = sum/count;
}

void get_cpu_usage(int main_pid) {
    char cmd[128];
    char buffer[128];
    FILE* fp;
    char pid[16];
    iniArr();

    sprintf(pid, "%d", main_pid);

    while(count < 60 && keep_running){
        // Step 2: Find the CPU usage of the process using the PID
        snprintf(cmd, sizeof(cmd), "ps -p %s -o %%cpu", pid);

        fp = popen(cmd, "r");
        if (fp == NULL) {
            perror("popen failed");
            return;
        }
        
        // Skip the header line
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
            printf("Failed to retrieve CPU usage\n");
            pclose(fp);
            return;
        }

        // Get the CPU usage
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            //printf("CPU usage of the process: %s%%\n", buffer);
            arr[count++] = atoi(buffer);
        } 
        else {
            printf("Failed to retrieve CPU usage\n");
        }
        pclose(fp);
    }
    setUsage();
    return;
}