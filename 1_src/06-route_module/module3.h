/*******************************************************************************
 * Copyleft (c) 2020 将狼才鲸
 *
 * \file    module3.h
 * \brief   用于路由单元测试的模块3
 * \author  将狼才鲸
 * \version 1.0.0
 * \date    2020-05-17
 * \license MulanPSL-1.0
 *
 * -----------------------------------------------------------------------------
 *
 * -----------------------------------------------------------------------------
 * 文件修改历史：
 * <时间>       | <版本>    | <作者>    | <描述>
 * 2020-05-17   | v1.0.0    | 将狼才鲸  | 创建文件
 * -----------------------------------------------------------------------------
 ******************************************************************************/

#ifndef _MODULE3__H
#define _MODULE3__H

/*================================= 接口函数 =================================*/
/*!
 * \brief 注册本模块的路由接口
 *
 * 如果本模块是一个通讯模块，那么可以注册两个接口，一个将数据从通讯口发送出去的，
 * 一个是本模块要使用的，如配置信息，控制信息等
 * \return    0处理正常，负数错误码
 */
int module3_init(void);

/*!
 * \brief 模块轮询接口
 *
 * 可以在这个函数里持续监测通讯链路上输入的数据，有数据则进行处理
 *
 * \return 0处理正常，负数错误码
 */
int module3_run(void);

/*!
 * \brief 模块注销
 *
 * \return 0处理正常，负数错误码
 */
int module3_exit(void);

#endif /* _MODULE3__H */
