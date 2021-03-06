#ifndef JIOT_LOG_H
#define JIOT_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jiot_client.h"

#if defined(__cplusplus)
 extern "C" {
#endif

#define LOG_BUFF_LEN 512

extern int g_logLevl  ;


/***********************************************************
* 函数名称: jiot_log_out
* 描       述: 输出日志
* 输入参数:      int logLevl      日志级别 
                const char *fmt  日志格式
                ...              可变参数
* 输出参数:      
* 返 回  值: 无
************************************************************/
void jiot_log_out(int logLevl, const char *fmt, ...);


/***********************************************************
* 函数名称: ERROR_LOG
* 描       述: 错误日志输出宏
* 输入参数:      const char *fmt  日志格式
                ...              可变参数
* 输出参数:      
* 返 回  值: 无
************************************************************/
#define ERROR_LOG(format,...) \
{\
    if (g_logLevl >= ERROR_LOG_LEVL)\
    {\
        jiot_log_out(ERROR_LOG_LEVL, "%ld %s:%d %s()| "format ,(long int)time(NULL),__FILE__, __LINE__, __FUNCTION__,##__VA_ARGS__);\
    }\
}\

/***********************************************************
* 函数名称: INFO_LOG
* 描       述: 运行时日志输出宏
* 输入参数:      const char *fmt  日志格式
                ...              可变参数
* 输出参数:      
* 返 回  值: 无
************************************************************/
#define INFO_LOG(format, ...) \
{\
    if (g_logLevl >= INFO_LOG_LEVL)\
    {\
        jiot_log_out(INFO_LOG_LEVL, "%ld %s:%d %s()| "format ,(long int)time(NULL),__FILE__, __LINE__, __FUNCTION__,##__VA_ARGS__);\
    }\
}\

/***********************************************************
* 函数名称: DEBUG_LOG
* 描       述: 调试日志输出宏
* 输入参数:      const char *fmt  日志格式
                ...              可变参数
* 输出参数:      
* 返 回  值: 无
************************************************************/
#define DEBUG_LOG(format, ...) \
{\
    if (g_logLevl >= DEBUG_LOG_LEVL)\
    {\
        jiot_log_out(DEBUG_LOG_LEVL, "%ld %s:%d %s()| "format ,(long int)time(NULL),__FILE__, __LINE__, __FUNCTION__,##__VA_ARGS__);\
    }\
}\

#if defined(__cplusplus) /* If this is a C++ compiler, use C linkage */
}
#endif

#endif
