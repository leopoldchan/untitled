#ifndef __SDTMESSAGE_H__
#define __SDTMESSAGE_H__

//魔力数
#define SDTMSG_MAGICNUMBER 0x94039734

//消息号（注：0x01-0x400为预留消息号，0x401开始为用户自定义消息号）
#define SDTMSGNO_USBCHANGE_IN       (0x01)    //usb设备插入
#define SDTMSGNO_USBCHANGE_OUT      (0x02)    //usb设备拔出
#define SDTMSGNO_LOGIN_SUCCESS      (0x03)    //设备登录成功
#define SDTMSGNO_LOGOUT_SUCCESS     (0x04)    //设备登出成功
#define SDTMSGNO_EXIT               (0x05)    //进程退出
#define SDTMSGNO_DEVAVAILABLE       (0x06)    //设备可用
#define SDTMSGNO_DEVNOTAVAILABLE    (0x07)    //设备不可用
#define SDTMSGNO_CONNECTDEVNUM      (0x08)    //已连接的设备数量
#define SDTMSGNO_DEVAPPTYPE         (0x09)    //设备应用类型
#define SDTMSGNO_PROGRESSWIN        (0x0a)    //进度指示窗口
#define SDTMSGNO_ERRORINFO          (0x0b)    //错误通知
#define SDTMSGNO_REPLY              (0x0c)    //执行回复
#define SDTMSGNO_QUERYUSBKEYINFO    (0x0d)    //查询usbkey信息 
#define SDTMSGNO_USBCHANGE_IN_EX    (0x0e)    //usb设备插入(扩展)
#define SDTMSGNO_APPNOTICE          (0x0f)    //应用系统通知消息
#define SDTMSGNO_APPREGISTER        (0x10)    //应用注册消息
#define SDTMSGNO_APPEXIT            (0x11)    //应用进程退出之前的通知
#define SDTMSGNO_APPCMD             (0x12)    //应用接收的命令
#define SDTMSGNO_APPSTATE           (0x13)    //应用当前状态

#define SDTMSGNO_DISKINFO             (0x401)   //加密磁盘信息
#define SDTMSGNO_HIDEWINDOW           (0x402)   //隐藏窗口
#define SDTMSGNO_SETIPPORT            (0x403)   //设置服务端ip和port
#define SDTMSGNO_GETIPPORT            (0x404)   //获取服务端ip和port
#define SDTMSGNO_CLEARDISKINFO        (0x405)   //清空加密磁盘信息展示
#define SDTMSGNO_GETDISKINFO          (0x406)   //获取所有加密磁盘信息
#define SDTMSGNO_SETUSERPIN           (0x407)   //设置用户PIN码
#define SDTMSGNO_USERLOGIN            (0x408)   //用户登录
#define SDTMSGNO_SETTOKENID           (0x409)   //设置重新绑定用票据
#define SDTMSGNO_FORCELOGIN           (0x40a)   //强制登录
#define SDTMSGNO_SETCONFIGINFO        (0x40b)   //设置配置信息
#define SDTMSGNO_GETCONFIGINFO        (0x40c)   //获取配置信息
#define SDTMSGNO_CONFIGINFO           (0x40d)   //配置信息
#define SDTMSGNO_SHOWWINDOW           (0x40e)   //显示窗口
#define SDTMSGNO_SHOWINFO             (0x40f)   //显示信息
#define SDTMSGNO_INITJOBNAME          (0x410)   //初始化job名称
#define SDTMSGNO_SETJOBSTATUS         (0x411)   //设置job的状态
#define SDTMSGNO_SETAUTHSTATUS        (0x412)   //设置认证登录状态
#define SDTMSGNO_AUTHLOGIN            (0x413)   //认证登录
#define SDTMSGNO_AUTHLOGOUT           (0x414)   //认证登出
#define SDTMSGNO_UICHOICE             (0x415)   //ui反馈的选择项
#define SDTMSGNO_REQUESTASTICKET      (0x416)   //AS票据-请求
#define SDTMSGNO_RESPONDASTICKET      (0x417)   //AS票据-响应
#define SDTMSGNO_ASAG_STATUS_QUERY    (0x418)   //查询AS、AG状态
#define SDTMSGNO_ASAG_STATUS_NOTICE   (0x419)   //返回AS、AG状态
#define SDTMSGNO_ASAG_LOGIN           (0x41a)   //AS、AG登录
#define SDTMSGNO_ASAG_LOGOUT          (0x41b)   //AS、AG登出
#define SDTMSGNO_AG_LOGIN             (0x41c)   //AG登录
#define SDTMSGNO_AG_LOGOUT            (0x41d)   //AG登出
#define SDTMSGNO_CONFIG_MANAGE        (0x41e)   //配置管理
#define SDTMSGNO_SOFTWARE_MANAGE      (0x41f)   //软件管理
#define SDTMSGNO_KEY_MANAGE           (0x420)   //密钥管理
#define SDTMSGNO_DEVICE_LOGIN         (0x421)   //设备登录
#define SDTMSGNO_CHANGE_PIN           (0x422)   //修改密码
#define SDTMSGNO_SYSTEM_INFO          (0x423)   //系统信息
#define SDTMSGNO_SETCONFLOADADDR      (0x424)   //设置在线配置地址信息
#define SDTMSGNO_GETCONFLOADADDR      (0x425)   //获取在线配置地址信息
#define SDTMSGNO_ACCESSNET_OK         (0x426)   //网络接入成功
#define SDTMSGNO_BREAKNET_OK          (0x427)   //网络断开成功
#define SDTMSGNO_ACCESSNET            (0x428)   //网络接入
#define SDTMSGNO_ASSIGN_KEY_TO_AUTH   (0x429)   //指定设备进行身份认证
#define SDTMSGNO_START_ACCESS         (0x42a)   //开始进行准入
#define SDTMSGNO_ACCESS_STATE         (0x42b)   //准入状态
#define SDTMSGNO_AG_LOGIN_OK          (0x42c)   //AG登录成功
#define SDTMSGNO_AG_LOGOUT_OK         (0x42d)   //AG登出成功
#define SDTMSGNO_STOP_ACCESS          (0x42e)   //结束准入
#define SDTMSGNO_AS_URL               (0x42f)   //AS返回的URL
#define SDTMSGNO_DIAG_REQUESTTESTINFO (0x430)  //故障诊断请求测试列表消息
#define SDTMSGNO_DIAG_TESTINFO        (0x431)  //故障诊断测试信息消息
#define SDTMSGNO_DIAG_REQUESTTEST     (0x432)  //故障诊断请求测试消息
#define SDTMSGNO_DIAG_TESTRESULT      (0x433)  //故障诊断测试结果消息
#define SDTMSGNO_DIAG_ERRORINFO       (0x434)  //故障诊断错误信息消息
#define SDTMSGNO_DIAG_TESTDETAIL      (0x435)  //故障诊断测试详情消息
#define SDTMSGNO_RUN_SELF             (0x436)  //非融合版客户端
#define SDTMSGNO_RUN_WITH_WH          (0x437)  //WH融合版客户端


//设备类型
#define SDTMSG_DEVTYPE_NET     (0x00)    //网络设备
#define SDTMSG_DEVTYPE_PCI     (0x01)    //PCI设备
#define SDTMSG_DEVTYPE_USB     (0x02)    //USB设备

//应用类型
#define SDTMSG_APPTYPE_ENC     (0x00)    //加密
#define SDTMSG_APPTYPE_AUTH    (0x01)    //认证
#define SDTMSG_APPTYPE_SEAL    (0x02)    //签章
#define SDTMSG_USBTYPE_UNKNOW  (0xff)    //未知类型

//usbkey信息索引
#define INFOINDEX_PIN       (0)    //pin码
#define INFOINDEX_SIGNCERT  (1)    //签名证书
#define INFOINDEX_ROOTCERT  (2)    //根证书

//usb设备插拔消息
typedef struct SDTMSG_USBCHANGE_st {
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    int application;          //应用类型，参见应用类型宏定义
    int devType;              //设备类型，参见设备类型宏定义
    char deviceID[256];       //设备标识
    char dllName[128];        //设备对应的动态库名称
    char appendInfo[128];     //附加信息（USBKEY设备时为guid，其余为空）
} SDTMSG_USBCHANGE;

//usb设备插拔消息（扩展）
typedef struct SDTMSG_USBCHANGEEX_st {
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    int version;              //结构体版本（当前为0）
    int application;          //应用类型，参见应用类型宏定义
    int devType;              //设备类型，参见设备类型宏定义
    int isShowLoginWindow;    //是否弹出usbkey登录窗口 0-不弹出 1-弹出
    char deviceID[256];       //设备标识
    char dllName[128];        //设备对应的动态库名称
    char appendInfo[128];     //附加信息（USBKEY设备时为guid，其余为空）
} SDTMSG_USBCHANGEEX;

//usb设备登录成功消息
typedef struct SDTMSG_USBLOGIN_st {
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    int application;          //应用类型，参见应用类型宏定义
    char deviceID[256];       //设备标识
    char userPIN[32];         //usb设备用户PIN码
} SDTMSG_USBLOGIN;

//usb设备登出成功消息
typedef struct SDTMSG_USBLOGOUT_st {
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    char deviceID[256];       //设备标识
} SDTMSG_USBLOGOUT;

//进程退出消息
typedef struct SDTMSG_EXIT_st {
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    int exitValue;            //进程退出值（发送者自定义）
} SDTMSG_EXIT;

//设备状态改变消息
typedef struct SDTMSG_DEVSTATECHANGE_st{
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    int deviceType;           //设备类型，参见设备类型宏定义
    int application;          //应用类型，参见应用类型宏定义
    char deviceID[256];       //设备标识
} SDTMSG_DEVSTATECHANGE;

//已连接设备数量
typedef struct SDTMSG_CONNECTDEVNUM_st{
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    int deviceNum;            //已连接的设备数量
} SDTMSG_CONNECTDEVNUM;

//进程窗口消息
typedef struct SDTMSG_PROGRESSWINDOW_st {
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    int winNO;                //窗口号
    int msgType;              //消息类型：0-创建 1-回复 2-修改 3-销毁
    int hasProgressBar;       //是否显示进度条：0-不显示  1-显示
    int available;            //0-进度条有效 1-显示信息有效 2-进度条、显示信息均有效
    int percentage;           //进度条百分比
    char title[64];           //标题栏
    char info[256];           //显示信息
} SDTMSG_PROGRESSWINDOW;

//错误通知
typedef struct SDTMSG_ERRORINFO_st {
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    char errorInfo[256];      //错误信息
} SDTMSG_ERRORINFO;

//执行回复
typedef struct SDTMSG_REPLY_st {
    int magicNumber;         //魔力数（SDTMSG_MAGICNUMBER）
    int replyValue;          //执行结果 0-成功 非0-失败
} SDTMSG_REPLY;

//磁盘信息
typedef struct SDTMSG_DISKINFO_st {
    int magicNumber;         //魔力数（SDTMSG_MAGICNUMBER）
    char diskName[32];       //名称
    char createTime[32];     //磁盘创建时间
    char diskVolume[16];     //磁盘容量
} SDTMSG_DISKINFO;

//设置ip和端口
typedef struct SDTMSG_IPPORT_st {
    int magicNumber;         //魔力数（SDTMSG_MAGICNUMBER）
    char ip[32];             //ip地址
    int port;                //端口号
} SDTMSG_IPPORT;

//用户PIN码
typedef struct SDTMSG_USERPIN_st {
        int magicNumber;         //魔力数
        char userPIN[32];        //用户PIN码
} SDTMSG_USERPIN;

//票据信息
typedef struct SDTMSG_TOKENID_st {
        int magicNumber;         //魔力数
        char tokenID[32];        //票据
} SDTMSG_TOKENID;

typedef struct SDTMSG_DIAG_TESTINFO_st
{
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    char softName[32];        //应用名称
    char softDesc[32];        //应用名称中文描述
    char testItemCH[1024];    //测试项名称列表
    char testItemEn[1024];    //测试项名称列表
} SDTMSG_DIAG_TESTINFO;

//测试结果消息
typedef struct SDTMSG_DIAG_TESTRESULT_st
{
    int magicNumber;          //魔力数（SDTMSG_MAGICNUMBER）
    char softName[32];        //应用名称
    char testItemName[32];    //测试项名称
    int retCode;              //测试返回值，0正确，非0错误
    char uuid[32+1];          //索引
    char description[256];    //测试结果描述
} SDTMSG_DIAG_TESTRESULT;

//测试详情消息
typedef struct SDTMSG_DIAG_TESTDETAIL_st
{
    int magicNumber;             //魔力数（SDTMSG_MAGICNUMBER）
    char softName[32];           //应用名称
    char testItemName[32];       //测试项名称
    unsigned char uuid[32+1];    //索引
    char detail[0];              //测试详情
} SDTMSG_DIAG_TESTDETAIL;

//错误通知
typedef struct SDTMSG_DIAG_ERRORINFO_st {
    int magicNumber;      //魔力数（SDTMSG_MAGICNUMBER）
    char softName[32];    //应用名称
    int retCode;          //测试错误返回值
    char errStr[256];     //错误信息
} SDTMSG_DIAG_ERRORINFO;

#endif  //__SDTMESSAGE_H__
