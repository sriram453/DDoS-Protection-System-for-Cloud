#include <stdio.h>
#include <string.h>
#define MAX_IPS 100
#define BLOCK_THRESHOLD 100
typedef struct {
    char ip[20];
    int request_count;
    int is_blocked;
} IPAddress;

int main() {
    int n;
    IPAddress ip_list[MAX_IPS];

    printf("Enter number of IPs accessing the server: ");
    scanf("%d", &n);

    if (n > MAX_IPS) {
        printf("Too many IPs. Max allowed is %d.\n", MAX_IPS);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nEnter IP address %d: ", i + 1);
        scanf("%s", ip_list[i].ip);
        printf("Enter number of requests from %s in last 1 minute: ", ip_list[i].ip);
        scanf("%d", &ip_list[i].request_count);

        if (ip_list[i].request_count > BLOCK_THRESHOLD) {
            ip_list[i].is_blocked = 1;
        } else {
            ip_list[i].is_blocked = 0;
        }
    }
    printf("\n--- DDoS Detection Report ---\n");
    for (int i = 0; i < n; i++) {
        printf("IP: %s | Requests: %d | Status: %s\n",
            ip_list[i].ip,
            ip_list[i].request_count,
            ip_list[i].is_blocked ? "⚠️ BLOCKED (DDoS Suspected)" : "✅ Normal");
    }
    return 0;
}
