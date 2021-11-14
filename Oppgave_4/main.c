#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _MYHTTP
{
    int iHttpCode;
    int iContentLength;
    bool bIsSuccess;
    char szServer[16];
    char szContentType[16];
} MYHTTP;

MYHTTP *ProcessHttpHeader(char *pszHttp)
{
    char *pszPtr;
    MYHTTP *pHttp = (MYHTTP *)malloc(sizeof(MYHTTP));
    if (!pHttp)
        return NULL;
    memset(pHttp, 0, sizeof(MYHTTP));
    pHttp->iHttpCode = atoi(pszHttp + strlen("HTTP/1.x "));
    if (pHttp->iHttpCode = 200)
    {
        pHttp->bIsSuccess = true;
    }
    pszPtr = strstr(pszHttp, "Server");
    if (pszPtr)
    {
        pszPtr += 6;
        while (!isalpha(pszPtr[0]))
            pszPtr++;
        strchr(pszPtr, '\n')[0] = 0;
        strcpy(pHttp->szServer, pszPtr);
        pszPtr[strlen(pHttp->szServer)] = '\n';
    }
    pszPtr = strstr(pszHttp, "Content-Type");
    if (pszPtr)
    {
        pszPtr += 12;
        while (!isalpha(pszPtr[0]))
            pszPtr++;
        strchr(pszPtr, '\n')[0] = 0;
        strncpy(pHttp->szContentType, pszPtr, 15);
        pszPtr[strlen(pHttp->szContentType)] = '\n';
    }
    pszPtr = strstr(pszHttp, "Content-Length");
    if (pszPtr)
    {
        pszPtr += 14;
        while (!isdigit(pszPtr[0]))
            pszPtr++;
        pHttp->iContentLength = atoi(pszHttp);
    }
    return pHttp;
}

int main()
{
    MYHTTP(*funcPtr)
    (char *);

    funcPtr = &ProcessHttpHeader;

    MYHTTP res = (*funcPtr)("HTTP/1.1 200 OK");

    printf("Content Length: %d\n", res.iContentLength);
    printf("Http Code: %d\n", res.iHttpCode);
    printf("szServer: %s\n", res.szServer);
    printf("bIsSuccess: %d\n", res.bIsSuccess);
}
