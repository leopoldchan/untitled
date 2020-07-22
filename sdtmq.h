#ifndef __SDTMQ_H__
#define __SDTMQ_H__

#ifdef WIN32

#ifdef SDTMQ_ADAPTER_C_EXPORTS
    #define SDTMQ_API __declspec(dllexport)
#else
    #define SDTMQ_API __declspec(dllimport)
#endif

#else
    #define SDTMQ_API
#endif

#define QUEUE_EXCLUSIVE		(0)
#define QUEUE_SHARED		(1)

typedef void * SDTMQ_SESSION;

typedef struct SDTMQ_MESSAGE_ST {
	/** 结构版本 */
	int version;
	/** 消息分类号（类型） */
	int type;
	/** 消息参数 */
	int param;
	/** 消息数据 */
	void *data;
	/** 消息数据长度 */
	unsigned int length;
	/** 消息生存周期（毫秒） */
	int lifetime;
	/** 消息回复队列名 */
	char *queue;
	/** 消息唯一标识 */
	int uid;
} SDTMQ_MESSAGE;

#ifdef __cplusplus
extern "C"
{
#endif

/**
* 获取前一次调用SDTMQ接口的错误原因字符串
*
* @return 返回错误原因字符串的指针
*/
char SDTMQ_API *SDTMQ_GetLastErrorText(void);

/**
 * 创建一个会话
 * 
 * @param[in]	ctx		预留，用于传递会话设置的相关信息
 * @return 成功时返回会话句柄，失败时返回NULL
 */
SDTMQ_SESSION SDTMQ_API SDTMQ_OpenSession(void *ctx);

/**
 * 关闭一个会话
 * 
 * @param[in]	session	会话句柄
 * @return		0       操作执行成功
 */
int SDTMQ_API SDTMQ_CloseSession(SDTMQ_SESSION session);


/**
 * 在会话中声明一个自己的队列 
 *
 * @param[in]	session	会话句柄
 * @param[in]	queue	消息队列名称
 * @param[in]	flag	队列属性标识
 *					QUEUE_EXCLUSIVE		独占队列，只有声明该队列的会话可以消费该队列的消息
 *					QUEUE_SHARED		共享队列，任何会话都可以消费该队列的消息
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Declare(SDTMQ_SESSION session, const char *queue, int flag);

/**
 * 在会话中弃用一个自己的或者与别人共享的队列
 * 注意：当所有声明者都弃用了某共享队列时，该队列将被彻底删除，否则，仅更新引用计数。
 * 
 * @param[in]	session	会话句柄
 * @param[in]	queue	消息队列名称
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Free(SDTMQ_SESSION session, const char *queue);

/**
 * 向某队列发布一条消息
 * 
 * @param[in]	session	会话句柄
 * @param[in]	queue	消息队列名称
 * @param[in]	message	待发布的消息
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Push(SDTMQ_SESSION session, const char *queue, SDTMQ_MESSAGE *message);

/**
 * 向全系统发布一条广播消息
 * 消息将推送到所有已被声明的队列中
 * 
 * @param[in]	session	会话句柄
 * @param[in]	message	待广播的消息
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Broadcast(SDTMQ_SESSION session, SDTMQ_MESSAGE *message);

/**
 * 从某消息队列中消费最早一条消息
 * △阻塞方法
 * 
 * @param[in]	session	会话句柄
 * @param[in]	queue	消息队列名称（需要先queueDeclare）
 * @param[out]	message	获取的消息
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Poll(SDTMQ_SESSION session, const char *queue, SDTMQ_MESSAGE *message);

/**
 * 从某消息队列中取出最早一条消息（不删除队列中消息实体）
 * △阻塞方法
 * 
 * @param[in]	session	会话句柄
 * @param[in]	queue	消息队列名称（需要先queueDeclare）
 * @param[out]	message	获取的消息
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Peek(SDTMQ_SESSION session, const char *queue, SDTMQ_MESSAGE *message);

/**
 * 向某队列发布一条消息，并等待应答
 * △阻塞方法
 * 
 * @param[in]	session	会话句柄
 * @param[in]	queue	消息队列名称（需要先queueDeclare）
 * @param[in]	message	待发布的消息
 * @param[out]	reply	消息接收方应答的整型值
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Send(SDTMQ_SESSION session, const char *queue, SDTMQ_MESSAGE *message, int *reply);

/**
 * 向消息的生产者应答一个数值。
 * 注意：必须在成功调用Poll或Peek接口后才能调用该接口
 *
 * @param[in]	session	会话句柄
 * @param[in]	message	需要应答的消息
 * @param[in]	reply	待应答的数值
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_Reply(SDTMQ_SESSION session, SDTMQ_MESSAGE *message, int reply);

/**
 * 销毁消息体的内容
 *
 * @param [in]	message	通过SDTMQ_Poll或SDTMQ_Peek获取的消息
 * @return		0		操作执行成功
 */
int SDTMQ_API SDTMQ_DestroyMessage(SDTMQ_MESSAGE *message);

/**
 * 关闭一个会话
 * 
 * @param[in]	session	会话句柄
 * @return		0       操作执行成功
 */
int SDTMQ_API SDTMQ_CloseSession(SDTMQ_SESSION session);

/**
* 初始化SDTMQ的环境状态
*
*/
void SDTMQ_API SDTMQ_Init(void);

/**
* 向某队列发布一条消息，并等待应答
* △阻塞方法
*
* @param[in]		session	会话句柄
* @param[in]		queue	消息队列名称（需要先queueDeclare）
* @param[in]		message	待发布的消息
* @param[out]		buf	    返回缓冲区数据指针
* @param[in,out]	b_m_len	返回的缓冲区长度,输入时为外部送入的缓冲区最大长度
* @return			0		操作执行成功
*/
int SDTMQ_API SDTMQ_Send_Buf(SDTMQ_SESSION session, const char *queue, SDTMQ_MESSAGE *message, unsigned char *buf, int *b_m_len);

/**
* 向消息的生产者应答一个数值。
* 注意：必须在成功调用Poll或Peek接口后才能调用该接口
*
* @param[in]		session	会话句柄
* @param[in]		message	需要应答的消息
* @param[in]		buf	    输入的缓冲区数据指针
* @param[in]		b_m_len	输入的缓冲区长度
* @return			0		操作执行成功
*/
int SDTMQ_API SDTMQ_Reply_Buf(SDTMQ_SESSION session, SDTMQ_MESSAGE *message, unsigned char *buf, int b_m_len);

/**
* 清理指定队列。
*
* @param[in]		session	会话句柄
* @param[in]		queue	消息队列名称
* @return			0		操作执行成功
*/
int SDTMQ_API SDTMQ_Cleanup(SDTMQ_SESSION session, const char *queue);


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/*
以下是新接口，老接口是用新接口封的，全面兼容老接口
*/
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


typedef struct SDTMQX_MESSAGE_st
{
	int type;
	int param;
	unsigned char *data;
	int len;
}SDTMQX_MESSAGE;

typedef int (*CBONMESSAGE)(void *handle,SDTMQX_MESSAGE *msg);
typedef int (*CBONRPCMESSAGE)(void *handle,SDTMQX_MESSAGE *msg,int ticket);

/**
* 打开消息队列会话。
*
* @param[in]		position	会话位置(暂时没有用处)
* @param[in]		app			队列名称
* @param[out]		handle		会话句柄
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Open(const char *position,const char *app,void **handle);

/**
* 关闭消息队列会话。
*
* @param[in]		handle		会话句柄
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Close(void *handle);

/**
* 监听指定队列。
*
* @param[in]		handle		会话句柄
* @param[in]		cb			接到消息的回调
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Listen(void *handle,CBONMESSAGE cb);

/**
* RPC监听指定队列。
*
* @param[in]		handle		会话句柄
* @param[in]		cb			接到消息的回调
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_RPC_Listen(void *handle,CBONRPCMESSAGE cb);

/**
* 获取普通消息。
*
* @param[in]		handle		会话句柄
* @param[in]		timeout		获取超时，毫秒，0代表无限
* @param[out]		msg			接到的消息(处理完成后需要通过SDTMQX_Release释放)
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Get(void *handle,int timeout,SDTMQX_MESSAGE **msg);

/**
* 发送普通消息。
*
* @param[in]		handle		会话句柄
* @param[in]		type		消息内容
* @param[in]		param		消息内容
* @param[in]		data		消息内容
* @param[in]		len			消息内容
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Post(void *handle,int type,int param,unsigned char *data,int len);

/**
* 获取消息(普通消息和rpc消息)。
*
* @param[in]		handle		会话句柄
* @param[in]		timeout		获取超时，毫秒，0代表无限
* @param[out]		msg			接到的消息(处理完成后需要通过SDTMQX_Release释放)
* @param[out]		ticket		接到消息的ticket，如果不为0，意味着是rpc消息，需要回复
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_GetEx(void *handle,int timeout,SDTMQX_MESSAGE **msg,int *ticket);

/**
* 发送rpc消息并等待回复。
*
* @param[in]		handle		会话句柄
* @param[in]		type		消息内容
* @param[in]		param		消息内容
* @param[in]		data		消息内容
* @param[in]		len			消息内容
* @param[in]		timeout		获取超时，毫秒，0代表无限
* @param[out]		msg			接到的消息(处理完成后需要通过SDTMQX_Release释放)
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_RPC_Send(void *handle,int type,int param,unsigned char *data,int len,int timeout,SDTMQX_MESSAGE **msg);

/**
* 获取rpc消息。
*
* @param[in]		handle		会话句柄
* @param[in]		timeout		获取超时，毫秒，0代表无限
* @param[out]		msg			接到的消息(处理完成后需要通过SDTMQX_Release释放)
* @param[out]		ticket		接到消息的ticket，回复时需要
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_RPC_Get(void *handle,int timeout,SDTMQX_MESSAGE **msg,int *ticket);

/**
* 回复rpc消息。
*
* @param[in]		handle		会话句柄
* @param[in]		ticket		接到消息的ticket
* @param[in]		type		消息内容
* @param[in]		param		消息内容
* @param[in]		data		消息内容
* @param[in]		len			消息内容
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_RPC_Reply(void *handle,unsigned int ticket,int type,int param,unsigned char *data,int len);

/**
* 释放消息。
*
* @param[in]		msg			接到的消息(处理完成后需要通过SDTMQX_Release释放)
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Release(SDTMQX_MESSAGE *msg);

/**
* 发送广播消息。
*
* @param[in]		position	会话位置(暂时没有用处)
* @param[in]		ticket		接到消息的ticket
* @param[in]		type		消息内容
* @param[in]		param		消息内容
* @param[in]		data		消息内容
* @param[in]		len			消息内容
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Broadcast(const char *position,int type,int param,unsigned char *data,int len);

/**
* 清空指定队列的普通消息(不清空rpc消息)。
*
* @param[in]		handle		会话句柄
* @return			0			操作执行成功
*/
int SDTMQ_API SDTMQX_Cleanup(void *handle);



#ifdef __cplusplus
}
#endif

#endif


