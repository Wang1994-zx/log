/*******************************************************************************
 * Copyleft (c) 2020 将狼才鲸
 *
 * \file    print_ctrl.h
 * \brief   调试输出级别控制模块
 * \author  将狼才鲸
 * \version 1.0.0
 * \date    2020-05-02
 * \license MulanPSL-1.0
 *
 * -----------------------------------------------------------------------------
 * 备注：利用宏定义函数# ## ... __VA_ARGS__等技巧实现
 *
 * -----------------------------------------------------------------------------
 * 文件修改历史：
 * <时间>       | <版本>    | <作者>    | <描述>
 * 2020-05-02   | v1.0.0    | 将狼才鲸  | 创建文件
 * -----------------------------------------------------------------------------
 ******************************************************************************/

#ifndef _PRINT_CTRL__H
#define _PRINT_CTRL__H

#include <stdio.h>
#include "publicdef.h"

/*!
 * \brief 调试输出级别
 */
#define NONE    0
#define ERROR   1
#define WARN    2
#define INFO    3
#define ENTRY   4
#define DEBUG   5

/* 在publicdef中去定义 */
//#define PRINT_LEVEL     INFO    /**< 默认调试级别 */

/*!
 * \brief   将变量名转成字符串的宏定义函数
 *          #是宏定义中转换字符串的用法
 */
#define name2str(name) (#name)

/*!
 * \brief   必须定义PRINT_LEVEL宏定义，否则编译阶段就直接报错退出
 */
#ifndef PRINT_LEVEL
#   error MUST Define PRINT_LEVEL!
#endif

/*!
 * \brief   带调试级别的，补全级别信息和时间信息、自动换行的打印输出宏函数
 *
 *          ...作为宏函数的可变变量，使用时用__VA_ARGS__
 *          或者##_VA_ARGS__(这里的##意思是即使参数为空也正常执行)。
 *          另一种不同的用法是宏定义中##可以拼接两个变量名，将其变成一个字符串。
 *          printf的第一个参数可以用多个字符串拼起来，不加逗号，
 *          如printf("Th""is"" is"" a"" string");
 */
int pr(int tag, char *tagstr, char *fmt, ...);
#if 0
#define pr(tag, ...)    do {                                        \
            if (tag <= PRINT_LEVEL) {                               \
                printf("[" #tag "]" "{" __DATE__ " " __TIME__ "} "__VA_ARGS__); \
                printf("\n");                                       \
            }                                                       \
        } while(0);
#define pr_err(fmt, ...)            pr(ERROR, fmt, ##__VA_ARGS__);
#define pr_warn(fmt, ...)           pr(WARN, fmt, ##__VA_ARGS__);
#define pr_info(fmt, ...)           pr(INFO, fmt, ##__VA_ARGS__);
#define pr_entry(inout)             pr(ENTRY, "%s() %s", __func__, #inout);
#define pr_debug(fmt, ...)          pr(DEBUG, fmt, ##__VA_ARGS__);
#endif

/*!
 * \brief 带调试级别，但是不带任何额外输出信息的打印输出宏函数
 *        用于在循环中输出缓存等数据
 */
#define pr_pure(tag, ...)    do {                                   \
            if (tag <= PRINT_LEVEL)                                 \
                printf(__VA_ARGS__);                                \
        } while(0);
#define pr_err_pure(fmt, ...)            pr_pure(ERROR, fmt, ##__VA_ARGS__);
#define pr_warn_pure(fmt, ...)           pr_pure(WARN, fmt, ##__VA_ARGS__);
#define pr_info_pure(fmt, ...)           pr_pure(INFO, fmt, ##__VA_ARGS__);
#define pr_debug_pure(fmt, ...)          pr_pure(DEBUG, fmt, ##__VA_ARGS__);

/** TODO: 一种从元素地址倒推数据结构首地址的方法: offsetof typeof */

#ifdef PRINT_CTRL_MODULE_UNITEST
int print_ctrl_unitest();
#endif

#endif /* _PRINT_CTRL__H */
