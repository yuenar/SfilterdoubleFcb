/*++

Copyright (c) 1989-1999  Microsoft Corporation

Module Name:

filespy.h

Abstract:

Header file which contains the structures, type definitions,
and constants that are shared between the kernel mode driver,
filespy.sys, and the user mode executable, filespy.exe.

Environment:

Kernel mode

--*/
#pragma once

#ifndef __FILESPY_H__
#define __FILESPY_H__

#include <winioctl.h>
#include "namelookupdef.h"

//
//  Enable these warnings in the code.
//

#pragma warning(error:4100)   // Unreferenced formal parameter
#pragma warning(error:4101)   // Unreferenced local variable

//重置
#define FILESPY_Reset              (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x00, METHOD_BUFFERED, FILE_WRITE_ACCESS )
//开始登陆设备
#define FILESPY_StartLoggingDevice (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x01, METHOD_BUFFERED, FILE_READ_ACCESS )
//停止登陆设备
#define FILESPY_StopLoggingDevice  (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x02, METHOD_BUFFERED, FILE_READ_ACCESS )
//获取日志
#define FILESPY_GetLog             (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x03, METHOD_BUFFERED, FILE_READ_ACCESS )
//获取版本
#define FILESPY_GetVer             (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x04, METHOD_BUFFERED, FILE_READ_ACCESS )
//列表设备
#define FILESPY_ListDevices        (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x05, METHOD_BUFFERED, FILE_READ_ACCESS )
//获取统计
#define FILESPY_GetStats           (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x06, METHOD_BUFFERED, FILE_READ_ACCESS )
//添加程序
#define PFPCOMMAND_AddPrograms     (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x07, METHOD_BUFFERED, FILE_WRITE_ACCESS )//used by config app to add program
//删除程序
#define PFPCOMMAND_DeletePrograms  (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x08, METHOD_BUFFERED, FILE_READ_ACCESS )//used by config app to delete program
//获取程序
#define PFPCOMMAND_GetPrograms	   (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x09, METHOD_BUFFERED, FILE_READ_ACCESS|FILE_WRITE_ACCESS )//used by app to get all programs to show users.
//保存配置文件的信息
#define PFPCOMMAND_SaveConfigInformation	    (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x0A, METHOD_BUFFERED, FILE_WRITE_DATA )//used by app to get all programs to show users.
//清理所有配置文件信息
#define PFPCOMMAND_ClearAllConfigInformation	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x0B, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//加载配置文件信息
#define PFPCOMMAND_LoadConfigInformation		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x0C, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//开启驱动
#define PFPCOMMAND_StartDriver					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x0D, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//关闭驱动
#define PFPCOMMAND_StopDriver					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x0E, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//遍历统计
#define PFPCOMMAND_QueryState					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x0F, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置备份目录
#define PFPCOMMAND_SETBACKUPDIR					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x10, METHOD_BUFFERED, FILE_WRITE_DATA  )//used by app to get all programs to show users.
//获取备份目录
#define PFPCOMMAND_GETBACKUPDIR					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x11, METHOD_BUFFERED, FILE_READ_ACCESS  )//used by app to get all programs to show users.

//获取程序长度
#define PFPCOMMAND_GetProgramsLen					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x12, METHOD_BUFFERED, FILE_READ_ACCESS  )//used by app to get all programs to show users.
//添加文件
#define CDO_ADD_FILE						(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x13, METHOD_BUFFERED, FILE_WRITE_ACCESS )//used by app to get all programs to show users.
//添加目录
#define CDO_ADD_DIRECTORY					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x14, METHOD_BUFFERED, FILE_WRITE_ACCESS )//used by app to get all programs to show users.
//移除文件
#define CDO_REMOVE_FILE						(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x15, METHOD_BUFFERED, FILE_WRITE_ACCESS )//used by app to get all programs to show users.
//移除目录
#define CDO_REMOVE_DIRECTORY				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x16, METHOD_BUFFERED, FILE_WRITE_ACCESS )//used by app to get all programs to show users.

//获取文件
#define CDO_GET_FILES						(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x17, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取文件长度
#define CDO_GET_FILES_LEN					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x18, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取目录
#define CDO_GET_DIRECTORYS					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x19, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取目录长度
#define CDO_GET_DIRECTORYS_LEN				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x1a, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//根据进程文件类型设置备份文件
#define CDO_SETBACKUP_FOR_PROCESS_FILETYPE	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x1b, METHOD_BUFFERED, FILE_WRITE_ACCESS )//used by app to get all programs to show users.
//根据进程文件类型获取备份文件
#define CDO_GETBACKUP_FOR_PROCESS_FILETYPE	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x1c, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.


//开启日志
#define PFPCOMMAND_DOLOGON					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x20, METHOD_BUFFERED, FILE_WRITE_DATA )//used by app to get all programs to show users.
//判定密钥文件
#define PFPCOMMAND_VIERIFYKEYFILE			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x21, METHOD_BUFFERED, FILE_WRITE_DATA )//used by app to get all programs to show users.
//获取密钥文件信息
#define PFPCOMMAND_GENKEYFILE				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x22, METHOD_BUFFERED, FILE_WRITE_DATA )//used by app to get all programs to show users.
//拿日志
#define PFPCOMMAND_HASLOGGEDON				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x23, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//
#define PFPCOMMAND_ENADNDEBUFFER			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x24, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//能够停止驱动
#define PFPCOMMAND_CANStopDriver			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x25, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//枚举备份
#define PFPCOMMAND_QueryBACKUP				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x30, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//枚举隐藏
#define PFPCOMMAND_QueryHIDE				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x31, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.

//设置备份
#define PFPCOMMAND_SETBACKUP				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x32, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置隐藏
#define PFPCOMMAND_SETHIDE					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x33, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//是否文件夹保护
#define PFPCOMMAND_ISFOLDERPROTECTED		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x34, METHOD_BUFFERED, FILE_READ_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//文件夹保护
#define PFPCOMMAND_FOLDERPROTECTED			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x35, METHOD_BUFFERED, FILE_READ_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//枚举文件夹保护长度
#define PFPCOMMAND_QUERYFOLDERPROTECTEDLEN	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x36, METHOD_BUFFERED, FILE_READ_ACCESS)//used by app to get all programs to show users.
//获取文件夹所有保护
#define PFPCOMMAND_QUERY_ALL_FOLDERPROTECTED (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x37, METHOD_BUFFERED, FILE_READ_ACCESS)//used by app to get all programs to show users.
//锁定和解锁文件夹
#define PFPCOMMAND_LOCK_AND_UNLOCK_FOLDER	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x38, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//枚举文件夹
#define PFPCOMMAND_QueryFOLDER				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x39, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//枚举隐藏长度
#define PFPCOMMAND_QUERYHIDERLEN			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x3A, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取隐藏
#define PFPCOMMAND_GETHIDDER			    (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x3B, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//锁定文件夹
#define PFPCOMMAND_LOCKFOLDERS			    (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x40, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//解锁文件夹
#define PFPCOMMAND_UNLOCKFOLDERS			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x41, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//
#define PFPCOMMAND_ModifyPSW				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x42, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS|FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.

//设置系统保护
#define PFPCOMMAND_SETSYSProtect			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x43, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//枚举系统保护
#define PFPCOMMAND_QUERYSYSProtect			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x44, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置U盘加密
#define PFPCOMMAND_SETUDISKENCRYPT			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x45, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//枚举U盘加密
#define PFPCOMMAND_QUERYUDISKENCRYPT		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x46, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.


//发送回收路径
#define PFPCOMMAND_SendReCyclePath			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x47, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//授予进程备份
#define PFPCOMMAND_ENABLE_PROCESS_BACKUP	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x71, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA |FILE_READ_DATA|FILE_READ_ACCESS)//used by app to get all programs to show users.
//授予进程加密
#define PFPCOMMAND_ENABLE_PROCESS_ENCRYPT	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x72, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//授予进程继承？
#define PFPCOMMAND_ENABLE_PROCESS_INHER		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x73, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//删除程序
#define PFPCOMMAND_DeleteProgram			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x60, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA |FILE_READ_DATA|FILE_READ_ACCESS)//used by app to get all programs to show users.
//读日志
#define PFPCOMMAND_READ_LOG					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x74, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

//日志事件句柄
#define PFPCOMMAND_LOGEVENT_HANDLE			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x75, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

//设置日志方法
#define	PFPCOMMAND_SETLogEnable				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x76, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取日志状态
#define	PFPCOMMAND_QUERYLogStatus			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x77, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置强行加密
#define	PFPCOMMAND_SetForceEncryption			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x78, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.


//在加密文件夹枚举文件类型
#define	PFPCOMMAND_QueryFileTypeOfFolderEncryption	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x79, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//在文件夹枚举文件类型长度
#define	PFPCOMMAND_QueryFileTypeLenForFolder		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x7A, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//在加密文件夹设置文件类型
#define	PFPCOMMAND_SetFileTypeForFolderEncryption	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x7B, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.


//获取进程数
#define	PFPCOMMAND_GetProgNum	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x80, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取进程Hash值
#define	PFPCOMMAND_GetProgHashValues	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x81, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取进程文件类型
#define	PFPCOMMAND_GetProgFileTypes	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x82, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取进程文件类型种类
#define	PFPCOMMAND_GetFileTypeNumForProg	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x83, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取进程
#define	PFPCOMMAND_GetProgInfoForProtection	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x84, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置所有的文件类型
#define	PFPCOMMAND_SetFileTypesByArray	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x85, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置加密文件夹
#define	PFPCOMMAND_SetFolderEncrypt	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x86, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置备份文件夹
#define	PFPCOMMAND_SetFolderBackup	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x87, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置文件夹锁定声明
#define	PFPCOMMAND_SetFolderLockState	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x88, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置文件夹保护类型
#define	PFPCOMMAND_SetFolderProtectType	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x89, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置文件夹加密类型
#define	PFPCOMMAND_SetFolderEncryptType	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x90, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置文件夹锁
#define	PFPCOMMAND_IsFolerLocked	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x91, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置文件夹显示名称
#define	PFPCOMMAND_SetDispalyNameForFolder	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x92, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取文件夹显示名称
#define	PFPCOMMAND_GetDispalyNameForFolder	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x93, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//添加文件夹保护信息
#define	PFPCOMMAND_AddFolderProtectionInfo (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x94, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取文件夹保护数
#define	PFPCOMMAND_GetNumOfProtectedFolder (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x95, METHOD_BUFFERED,  FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取保护文件夹所有信息
#define	PFPCOMMAND_GetProtectedFoldersIntoArray (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x96, METHOD_BUFFERED,  FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

//获取保护文件夹的文件类型个数
#define	PFPCOMMAND_GetNumOfFileTypesForProtectedFolder	 (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x97, METHOD_BUFFERED,  FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取保护文件夹所有文件类型
#define	PFPCOMMAND_GetFileTypesbyArrayForProtectedFolder (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x98, METHOD_BUFFERED,  FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取隐藏数
#define	PFPCOMMAND_GetNumOfHidder				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0x99, METHOD_BUFFERED,  FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取总隐藏？
#define	PFPCOMMAND_GetHidderByArray				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA0, METHOD_BUFFERED,  FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//添加隐藏数
#define	PFPCOMMAND_AddHidderItem				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA1, METHOD_BUFFERED,  FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置U盘设备加密模块
#define	PFPCOMMAND_SetUsbDeviceEncryptMode		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA2, METHOD_BUFFERED,  FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//获取U盘设备加密模块
#define	PFPCOMMAND_GetUsbDeviceEncryptMode		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA3, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS)//used by app to get all programs to show users.
//设置USB设备文件类型
#define	PFPCOMMAND_SetFileTypesForUsbDevice		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA4, METHOD_BUFFERED,  FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置USB设备获取文件类型
#define	PFPCOMMAND_GetFileTypesForUsbDevice		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA5, METHOD_BUFFERED,  FILE_READ_DATA|FILE_READ_ACCESS)//used by app to get all programs to show users.
//获取USB设备文件类型
#define	PFPCOMMAND_GetFileTypesNumForUsbDevice		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA6, METHOD_BUFFERED,  FILE_READ_DATA|FILE_READ_ACCESS)//used by app to get all programs to show users.
//添加程序（新）
#define	PFPCOMMAND_AddPrograms_New		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA7, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA)//used by app to get all programs to show users.
//设置文件类型
#define	PFPCOMMAND_SetFileTypesForFolder		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA8, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA)//used by app to get all programs to show users.
//获取文件夹保护信息
#define	PFPCOMMAND_GetFolderProtectInfo			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xA9, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS|FILE_WRITE_ACCESS|FILE_WRITE_DATA)//used by app to get all programs to show users.
//读取日志（新）
#define PFPCOMMAND_READ_LOG_NEW					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xB0, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置文件夹保护信息
#define PFPCOMMAND_SetFolderProtectInfo			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xB1, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//删除文件夹保护
#define PFPCOMMAND_DeleteProtectorFolder		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xB2, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

//是否进程可以停止
#define PFPCOMMAND_IsProcessCanStop			    (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xB3, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

//获取浏览器数
#define PFPCOMMAND_GetBrowserCount			    (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC0, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取浏览器的Hash值
#define PFPCOMMAND_GetBrowserHashValues			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC1, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置浏览器创建exe文件
#define PFPCOMMAND_SetBrowserCreateExeFile		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC2, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//获取浏览器加密类型的值
#define PFPCOMMAND_GetBrowserEncryptTypeValue	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC3, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS|FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//获取浏览器加密类型
#define PFPCOMMAND_GetBrowserEncryptTypes    	(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC4, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS|FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//获取浏览器加密类型数目	
#define PFPCOMMAND_GetBrowserEncryptTypesNum    (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC5, METHOD_BUFFERED, FILE_READ_DATA|FILE_READ_ACCESS|FILE_WRITE_ACCESS|FILE_WRITE_DATA )//used by app to get all programs to show users.
//设置所有浏览文件类型
#define PFPCOMMAND_SetBrowserFileTypesByArray   (ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC6, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )
//添加浏览器保护
#define PFPCOMMAND_AddBrowserProtection			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC7, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )
//获取浏览器保护
#define PFPCOMMAND_GetBrowserProtection			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC8, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )
//设置浏览器加密类型值
#define PFPCOMMAND_SetBrowserEncryptTypeValue		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xC9, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )
//设置窗口列出元件开启
#define PFPCOMMAND_SetDiaplyFramONWindow			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD0, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )
//枚举窗口列出元件开启
#define PFPCOMMAND_QueryDispalyFramOnWindow			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD1, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA| FILE_READ_DATA|FILE_READ_ACCESS )

//枚举USB设备数目
#define PFPCOMMAND_QueryUsbDeviceNum				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD2, METHOD_BUFFERED,FILE_READ_DATA|FILE_READ_ACCESS )
//枚举USB所有的ID
#define PFPCOMMAND_QueryUsbAllIds					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD3, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )
//枚举USB源文件类型的长度
#define PFPCOMMAND_QueryUsbSecureFileTypsLen		(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD4, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )
//枚举Usb控制状态
#define PFPCOMMAND_QueryUsbControlStatus			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD5, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )
//设置USB控制状态
#define PFPCOMMAND_SetUsbControlStatus				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD6, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )
//设置usb加密类型
#define PFPCOMMAND_SetUsbEncryptType				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD7, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )
//设置USB加密文件类型
#define PFPCOMMAND_SetUsbEncryptFileTypes			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD8, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )
//删除USB保护
#define PFPCOMMAND_DeleteUsbSecure			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xD9, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA )
//枚举USB加密类型
#define PFPCOMMAND_QueryUsbEncryptType				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xDA, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )
//枚举USB加密文件类型
#define PFPCOMMAND_QueryUsbEncryptFileTypes				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xDB, METHOD_BUFFERED,FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )
//USB事件句柄
#define PFPCOMMAND_USBEVENT_HANDLE					(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xDC, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.



//
#define PFPCOMMAND_GetUsbDriverLetter				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xDD, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

#define PFPCOMMAND_GetUsbDriverDesrciption			(ULONG)	CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xDE, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

#define PFPCOMMAND_SetUsbDriverDescription			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xDF, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

#define PFPCOMMAND_IsUsbDriverConnected				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xE0, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.

#define PFPCOMMAND_IsBrowser				(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xE1, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置隐藏
#define PFPCOMMAND_SetHideItemState			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xE2, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//删除缓冲
#define PFPCOMMAND_DEBUFFER			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xE3, METHOD_BUFFERED, FILE_READ_ACCESS )//used by app to get all programs to show users.
//注册保护
#define PFPCOMMAND_RegisterProtect			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xE4, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
//设置密钥
#define PFPCOMMAND_SetEncryptKey			(ULONG) CTL_CODE( FILE_DEVICE_DISK_FILE_SYSTEM, 0xE5, METHOD_BUFFERED, FILE_WRITE_ACCESS|FILE_WRITE_DATA|FILE_READ_DATA|FILE_READ_ACCESS )//used by app to get all programs to show users.
#define FILESPY_DRIVER_NAME      L"PfpDrv.SYS"
#define FILESPY_DEVICE_NAME      L"PfpDrv"
#define FILESPY_W32_DEVICE_NAME  L"\\\\.\\PfpDrv"
#define FILESPY_DOSDEVICE_NAME   L"\\DosDevices\\PfpDrv"
#define FILESPY_FULLDEVICE_NAME1 L"\\FileSystem\\Filters\\PfpDrv"
#define FILESPY_FULLDEVICE_NAME2 L"\\FileSystem\\PfpDrvCDO"


#define FILESPY_MAJ_VERSION 1
#define FILESPY_MIN_VERSION 0

#ifndef ROUND_TO_SIZE
#define ROUND_TO_SIZE(_length, _alignment)    \
	(((_length) + ((_alignment)-1)) & ~((_alignment) - 1))
#endif

typedef struct _FILESPYVER 
{
	USHORT Major;
	USHORT Minor;
} FILESPYVER, *PFILESPYVER;

//
//  To allow passing up PFILE_OBJECT as a unique file identifier in user-mode.
//
typedef ULONG_PTR FILE_ID;

//
//  To allow passing up PDEVICE_OBJECT as a unique device identifier in
//  user-mode.
//

typedef ULONG_PTR DEVICE_ID;

//
//  To allow passing up PKTRANSACTION as a unique object identifier in 
//  user-mode.

typedef ULONG_PTR TX_ID;

//
//  To allow status values to be passed up to user-mode.
//

typedef LONG NTSTATUS;



//
//  An array of these structures are returned when the attached device list is
//  returned.
//

typedef struct _ATTACHED_DEVICE 
{

	BOOLEAN LoggingOn;
	WCHAR DeviceNames[DEVICE_NAME_SZ];

} ATTACHED_DEVICE, *PATTACHED_DEVICE;

#define MAX_BUFFERS     100

//
//  Attach modes for the filespy kernel driver
//

#define FILESPY_ATTACH_ON_DEMAND    1
//  Filespy will only attach to a volume when a user asks to start logging
//  that volume.

#define FILESPY_ATTACH_ALL_VOLUMES  2
//  VERSION NOTE:
//
//  On Windows 2000, Filespy will attach to all volumes in the system that
//  it sees mount but not turn on logging until requested to through the
//  filespy user application.  Therefore, if filespy is set to mount on
//  demand, it will miss the mounting of the local volumes at boot time.
//  If filespy is set to load at boot time, it will see all the local
//  volumes be mounted and attach.  This can be beneficial if you want
//  filespy to attach low in the device stack.
//
//  On Windows XP and later, Filespy will attach to all volumes in the
//  system when it is loaded and all volumes that mount after Filespy is
//  loaded.  Again, logging on these volumes will not be turned on until
//  the user asks it to be.
//


//
//  Size of the actual records with the name built in.
//

#define MAX_NAME_SPACE  (260 * sizeof( WCHAR ))
#define RECORD_SIZE     (SIZE_OF_RECORD_LIST + MAX_NAME_SPACE)

#endif /* __FILESPY_H__ */





