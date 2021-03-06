
// CryptToolDlg.h: 头文件
//

#pragma once
#include "afxdtctl.h"
#include "afxwin.h"
#include "m_CEdit.h"

// CCryptToolDlg 对话框
class CCryptToolDlg : public CDialog
{
// 构造
public:
	CCryptToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CRYPTTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 年份
	DWORD nyear;
	DWORD nMonth;
	DWORD nDay;
	// 时间日期
	CDateTimeCtrl m_dateCtrl;
	afx_msg void OnBnClickedButton2();
	// 到期日期
	CDateTimeCtrl m_data_for_end;
	// 使用次数编辑控件
	m_CEdit m_edit;
	m_CEdit use_count;
	std::shared_ptr<rjFileInfo> encryptInfo;
	int WINAPI CompressFile(const char* comSavewhere, const char* needCom);
	int UncompreFile(const char* uncomTowhere, const char* needUncom);
	CString GetWorkDir();
	char desktop_path[255] = { 0 };
	char  Filebuffer[250] = { 0 };


};
