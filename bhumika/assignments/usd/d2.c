#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct url {
    char *host; 
    char *domain; 
};

int isValidURL(char *url) {
    if (strstr(url, "http://") == url || strstr(url, "https://") == url) {
        return 1;  
    }
    return 0;  
}

char *gethost(char *url) {
    char *hostStart = strstr(url, "://");
    if (hostStart != NULL) {
        hostStart += 3;  
    } else {
        return NULL; 
    }

    if (hostEnd == NULL) {
        hostEnd = hostStart + strlen(hostStart); 
    }

    int hostLength = hostEnd - hostStart;
    char *host = (char *)malloc((hostLength + 1) * sizeof(char));
    if (host == NULL) {
        printf("Memory allocation failed for host name!\n");
        exit(1);
    }
    strncpy(host, hostStart, hostLength);
    host[hostLength] = '\0'; 

    return host;
}

char *getdomain(char *url) {
    char *host = gethost(url);
    if (host == NULL) {
        return NULL;
    }

    char *domainStart = strrchr(host, '.');
    if (domainStart == NULL) {
        free(host);  // Free memory if domain is not found
        return NULL;
    }

    char *domain = (char *)malloc((strlen(domainStart + 1) + 1) * sizeof(char));
    if (domain == NULL) {
        printf("Memory allocation failed for domain name!\n");
        exit(1);
    }
    strcpy(domain, domainStart + 1);  // Copy domain after the last dot

    free(host);  // Free the host memory as it's no longer needed

    return domain;
}

void display(struct url *obj) {
    if (obj != NULL) {
        printf("Host: %s\n", obj->host);
        printf("Domain: %s\n", obj->domain);
    }
}

void freeMemory(struct url obj) {
    free(obj.host);
    free(obj.domain);
}

int main() {
    struct url obj;
    char url[100];

    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';  // Remove the newline character from the input

    if (!isValidURL(url)) {
        printf("Invalid URL!\n");
        return 1;
    }

    obj.host = gethost(url);
    obj.domain = getdomain(url);

    display(&obj);

    freeMemory(obj);

    return 0;
}

