#ifndef SDTJSON__h
#define SDTJSON__h

#ifdef _MSC_VER
#if _MSC_VER==1200
#define _JSON_VC6_
#endif
#endif

#ifdef _JSON_VC6_
#define __FUNCTION__  "???"
#endif

#define JSONCTXMAGIC "JSON"
#define JSONARRAYCTXMAGIC "ARRA"
#define MAXJSONSTRLEN 64
#define INDEX_RETURN_NULL 1

#define ERR_SDTJSON_PARSEERROR	0x01
#define ERR_SDTJSON_INVALIDPARA	0x0f
#define ERR_SDTJSON_BUILDERROR	0x4
#define ERR_SDTJSON_BASED64		0x5
#define ERR_SDTJSON_MEMORY		0x6
#define ERR_SDTJSON_BYTE2HEX	0x7
#define ERR_SDTJSON_NODEEXIST	0x8

/* cJSON Types: */
#define cJSON_False 0
#define cJSON_True 1
#define cJSON_NULL 2
#define cJSON_Number 3
#define cJSON_String 4
#define cJSON_Array 5
#define cJSON_Object 6

#define cJSON_IsReference 256

/* The cJSON structure: */
typedef struct cJSON {
	struct cJSON *next, *prev;	/* next/prev allow you to walk array/object chains. Alternatively, use GetArraySize/GetArrayItem/GetObjectItem */
	struct cJSON *child;		/* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */

	int type;					/* The type of the item, as above. */

	char *valuestring;			/* The item's string, if type==cJSON_String */
	int valueint;				/* The item's number, if type==cJSON_Number */
	double valuedouble;			/* The item's number, if type==cJSON_Number */

	char *string;				/* The item's name string, if this item is the child of, or is in the list of subitems of an object. */

} cJSON;


typedef struct cJSON_Hooks {
	void *(*malloc_fn)(unsigned int sz);
	void(*free_fn)(void *ptr);
} cJSON_Hooks;

typedef struct SDTJSONBUF_t {
	struct SDTJSONBUF_t *next;
	unsigned char callocstr[0];	
}SDTJSONBUF;

typedef struct SDTJSONCTX_t {
	unsigned char magicchar[4];
	cJSON *node;
	int mode;//1解析0封装
	SDTJSONBUF *callocstruct;
	int IsReturnNull;
	int IsRootNode;
} SDTJSONCTX;

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef WIN32
	#define JSON_API __declspec(dllexport)
#else
	#define JSON_API __attribute__((visibility("default")))
#endif

	//初始化
	int JSON_API SDTJSON_GetStr(char *str);

#ifdef __cplusplus
}
#endif

#endif
